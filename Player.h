#ifndef _MAHJONG_PLAYER_H_
#define _MAHJONG_PLAYER_H_

#include "Hand.h"
#include "Configuration.h"
#include <array>

namespace Mahjong { 

  class Player { 
  public:
    Player();
    virtual ~Player();
    
    
    const Hand& GetHand() const { return m_hand; }

    Wind GetSeat() const; 


    // Reset hand and melds
    void ResetForRound();

    Score CurrentScore() const;

    // This call must result in a Game::EndTurn();
    // Or, Game::Win() in order to progress the game
    // In the case of EndTurn() this call must also Table::Discard()
    virtual void HandleDrawnTile(const Tile& new_tile)=0;

    virtual void StartRound(Wind new_seat)=0;

    
  protected:
    void ClearHand();
    void ClearMelds();
    void SetSeat(Wind new_seat);

  private:
    Wind m_seat;
    Hand m_hand;
    Score m_total_score;

  };

  using PlayerSet = std::array<Player,4>;
}

#endif
