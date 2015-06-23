#ifndef __MAHJONG_CONFIGURATION_H_
#define __MAHJONG_CONFIGURATION_H_

#include <string>


using UnicodeChar = char32_t;
using Score = unsigned int;


enum class Wind {
  INVALID=0,
    NORTH=1,
    EAST,
    SOUTH,
    WEST
};

#endif
