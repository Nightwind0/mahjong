#include "Tile.h"
#include <algorithm>
#include <locale>
//#include <codecvt>

using Mahjong::Tile;
using Mahjong::TileSet;

Tile::Tile(Type type, Suit suit, Value value, bool red5):m_type(type),m_suit(suit),m_value(value),m_red(red5){
  
}


bool Tile::IsTerminal() const {
  return m_type == Type::SUITED && (m_value == 1 || m_value == 9);
}

Tile Tile::Dora() const {
  Tile dora(*this);;

  if(dora.m_value > 9)
    dora.m_value = 1;

  dora.m_red = false; // Right? What does a red dora do? anything?

  return dora;
}



bool Tile::operator == (const Tile& rhs) const
{
  return this->m_type == rhs.m_type && 
    this->m_suit == rhs.m_suit && 
    this->m_value == rhs.m_value && 
    this->m_red == rhs.m_red;
}

bool Tile::operator < (const Tile& other) const
{
  if(this->GetType() < other.GetType()) return true;
  else if(this->GetSuit() < other.GetSuit()) return true;
  else if(this->GetValue() < other.GetValue()) return true;
  else return false;
}

char32_t Tile::GetUnicodeChar() const
{

  static const auto kDots = U"🀙🀚🀛🀜🀝🀞🀟🀠🀡";
  //std::codecvt_utf8<char32_t> convert;

  switch(m_type){
  case Type::SUITED:
    switch(m_suit){
    case Suit::DOTS: 
      return kDots[m_value-1];
      break;
    }
    break;
  }


  char32_t red_dragon = U'🀄"';
  return red_dragon;
}




TileSet::TileSet():m_open(false),m_discarding_seat(Wind::INVALID){
}

TileSet::~TileSet(){
}

void TileSet::AddTile(const Tile& tile){
  m_tiles.emplace_back(tile);
}

void TileSet::RemoveTile(const Tile& tile){
  auto it = std::find(std::begin(m_tiles),std::end(m_tiles),tile);
  if( it != m_tiles.end() )
    m_tiles.erase(it);
}

void TileSet::SetOpen(){
  m_open = true;
}

void TileSet::SetDiscardingSeat(Wind seat){
  m_discarding_seat = seat;
}

Wind TileSet::GetDiscardingSeat() const{
  return m_discarding_seat;
}

bool TileSet::IsOpen() const{
  return m_open;
}

std::vector<Tile>::const_iterator TileSet::begin() const{
  return m_tiles.begin();
}

std::vector<Tile>::const_iterator TileSet::end() const{
  return m_tiles.end();
}
    
void TileSet::sort() {
  std::sort(m_tiles.begin(),m_tiles.end());
}
