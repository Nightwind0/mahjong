#include "Table.h"
using namespace Mahjong;

Table::Table(){
}

void Table::Discard(Player& player, const Tile& tile)
{
}

// For furiten rules in Riichi, we need to maintain a history of 
// All discarded Tiles, even wons that were called into open melds
const TileSet& Table::GetDiscardHistory()const{
}

const TileSet& Table::GetDiscardsThisRound()const{
}

void Table::AddWall(Wind side, const TileSet& tiles){
}

Tile Table::FlipWallTile(Wind side, int which_stack){
}

void Table::EndRound(){
}
