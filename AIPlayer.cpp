#include "AIPlayer.h"

// 4,250,305,029,168,215,600 mahjong hands possible. Thats a lot. Too many to try them all...

// If we decide on a pair, that gives 134C12 possibilities which is "only" 42,132,653,339,249,200 Or about a 100 times fewer options to consider...

using namespace Mahjong;

AIPlayer::AIPlayer(){
}

AIPlayer::~AIPlayer(){
}

void AIPlayer::HandleDrawnTile(const Tile& new_tile){
}

void AIPlayer::StartRound(Wind new_seat)
{
}

std::vector<Hand> AIPlayer::generate_potential_hands()
{
  const Hand& current_hand = GetHand();
  






}
