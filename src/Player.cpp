#include "Player.h"
#include "Tile.h"

using namespace Mahjong;

Player::Player(){
}

Player::~Player(){
}


// Reset hand and melds
void Player::StartRound(Wind new_seat){
  m_seat = new_seat;
}
