#include "Player.h"
#include "Hand.h"

namespace Mahjong { 

  class AIPlayer : public Player {
  public:
    AIPlayer();
    virtual ~AIPlayer();

    virtual void HandleDrawnTile(const Tile& new_tile) override;

    virtual void StartRound(Wind new_seat) override;

  private:
    
    std::vector<Hand> generate_potential_hands();

  };

}
