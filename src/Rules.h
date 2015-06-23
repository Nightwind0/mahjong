#ifndef _MAHJONG_RULES_H_
#define _MAHJONG_RULES_H_

#include "Configuration.h"

namespace Mahjong { 

  class Player;
  class Hand;

  class Rules {
  public:
    Rules();
    virtual ~Rules();
    
    // This takes the whole Player in case
    // a rule requires more than just the hand,
    // for example some riichi yaku need additional state
    // The table is needed for things such as Dora
    // Its important that incomplete hands be handled properly,
    // and return a 0 score
    virtual Score ScoreHand(const Player& player, const Table& table)=0;

    virtual bool AllowDiscard(const Player& player, const Tile& tile)=0;

    virtual bool AllowMeld(const Player& player, const TileSet& meld)=0;

    virtual bool AllowPon(const Player& player, const Player& discarding_player, const Tile& tile)=0;

    virtual bool AllowChii(const Player& player, const Player& discarding_player, const Tile& tile)=0;

    virtual bool AllowKan(const Player& player, const Player& discarding_player, const Tile& tile)=0;

    // This lets Rules define a dead wall, etc
    virtual bool AllowDraw(const Table& table)=0;

    // This builds the wall, deals tiles, and so on
    virtual void OnStartRound(Table& table, PlayerSet& players)=0; 


    virtual void OnStartGame(Table& table, PlayerSet& players)=0;
    
    
  private:
  };

}


#endif
