#ifndef _MAHJONG_HAND_H_
#define _MAHJONG_HAND_H_

#include "Tile.h"

namespace Mahjong { 

  class Player;

  class Hand {
  public:
    Hand();

    void Add(const Tile& tile);
    
    void Remove(const Tile& tile); // Will remove a tile that matches this

    void AddOpenMeld(const TileSet& tiles, const Player& discarding_player);

    void AddClosedMeld(const TileSet& tiles);
    
    // Get the unmelded Tiles
    TileSet::const_iterator begin() const;
    TileSet::const_iterator end() const;

    TileSet::const_iterator beginOpenMelds() const;
    TileSet::const_iterator endOpenMelds() const;

    TileSet::const_iterator beginClosedMelds() const;
    TileSet::const_iterator endClosedMelds() const;

    void SortTiles();

  private:
    TileSet m_tiles;
    std::vector<TileSet> m_open_melds;
    std::vector<TileSet> m_closed_melds;
  };

}


#endif
