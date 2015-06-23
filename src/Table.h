#ifndef __MAHJONG_TABLE_H_
#define __MAHJONG_TABLE_H_

#include "Tile.h"
#include "Configuration.h"


namespace Mahjong {

  class Player;

  class Table {
  public:
    Table();    
    void Discard(Player& player, const Tile& tile);
    // For furiten rules in Riichi, we need to maintain a history of 
    // All discarded Tiles, even wons that were called into open melds
    const TileSet& GetDiscardHistory()const; 
    const TileSet& GetDiscardsThisRound()const;
    
    void AddWall(Wind side, const TileSet& tiles);
    Tile FlipWallTile(Wind side, int which_stack);
    
    void EndRound();
    
  private:
    TileSet m_discard_history;
    TileSet m_round_discards;
  };
}


#endif
