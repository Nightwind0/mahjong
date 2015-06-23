#ifndef __MAHJONG_GAME_H_
#define __MAHJONG_GAME_H_

#include <functional>
#include <memory>
#include "Configuration.h"
#include "Player.h"

namespace Mahjong { 

  class Rules;

  class Game {
  public:
    static void SetRules(std::shared_ptr<Rules> rules);
    static const Rules& GetRules();
    static void Win(Player& winner);    
    static void EndTurn(Player& player);
    static Wind GetRoundWind();
    static Table& GetTable();
    static PlayerSet& GetPlayers();
  protected:
    Game();
    static Game* get_instance();
    std::shared_ptr<Rules> rules() const;
  private:
    static Game* m_instance;
    Table m_table;
    Wind m_round_wind;
    PlayerSet m_players;
    std::shared_ptr<Rules> m_rules;
  };


};

#endif
