#ifndef __MAHJONG_MAGIC_H_
#define __MAHJONG_MAGIC_H_

#include <vector>
#include <string>
#include "Configuration.h"

namespace Mahjong {
  class Tile {
  public:
    // Typedefs
    using Value = unsigned int;
    
    enum class Type {
      SUITED,
      DRAGON,
      WIND
    };

    enum class Suit  {
      NO_SUIT,
	CHARACTER,
        DOTS,
	BAMBOO
    };

    enum class DragonValue {
        RED=1,
	GREEN,
	WHITE
    };

    enum class WindValue {
      NORTH=1, EAST, SOUTH, WEST
    };

    Tile(Type type, Suit suit, Value value, bool red5=false);

    
    /* This method returns the next tile up, looping back around at the ends
     * like for use in the Dora rule
     */
    Tile Dora() const; 
    bool IsHonor() const { return m_type == Type::DRAGON || m_type == Type::WIND; }

    /* Whether this tile is a 1 or 9 suited tiled */
    bool IsTerminal() const;

    /* Whether this tile is a "red" (automatic Dora) tile used in Riichi
     */
    bool IsRed() const { return m_red; }

    Type GetType() const { return m_type; }

    Suit GetSuit() const { return m_suit; }

    Value GetValue() const { return m_value; }

    char32_t GetUnicodeChar() const;

    bool operator == (const Tile& rhs) const;
    bool operator < (const Tile& other) const;
      
  private:
    Type m_type;
    Suit m_suit;
    Value m_value; /* for suited this is the number of pips, for honor it is which honor tile they are */
    bool m_red;
  };



  class TileSet 
  {
  public:
    TileSet();
    ~TileSet();

    typedef std::vector<Tile>::const_iterator const_iterator;
    
    void AddTile(const Tile& tile);
    void RemoveTile(const Tile& tile);
    void SetOpen();
    void SetDiscardingSeat(Wind seat);
    Wind GetDiscardingSeat() const;
    bool IsOpen() const;
    void sort();
    std::vector<Tile>::const_iterator begin() const;
    std::vector<Tile>::const_iterator end() const;
    
  private:
    std::vector<Tile> m_tiles;
    bool m_open;
    Wind m_discarding_seat;
  };


}


#endif
