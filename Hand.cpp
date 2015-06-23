#include "Hand.h"
#include <algorithm>

using Mahjong::Hand;
using Mahjong::TileSet;

Hand::Hand(){
}

void Hand::Add(const Tile& tile)
{
  m_tiles.AddTile(tile);
}

 // Will remove a tile that matches this
void Hand::Remove(const Tile& tile)
{
  m_tiles.RemoveTile(tile);
}

    
// Get the unmelded Tiles
TileSet::const_iterator Hand::begin() const
{
  return m_tiles.begin();
}

TileSet::const_iterator Hand::end() const
{
  return m_tiles.end();
}

void Hand::SortTiles()
{
  m_tiles.sort();
}
