cmake_minimum_required (VERSION 2.8.9)
project (mahjong)


set(mahjong_HEADERS
  src/Configuration.h
  src/Game.h
  src/Hand.h
  src/Player.h
  src/Rules.h
  src/Table.h
  src/Tile.h
  src/riichi/AIPlayer.h
)

set(mahjong_SOURCES 
  src/mahjong.cpp
  src/Hand.cpp
  src/Player.cpp
  src/Table.cpp
  src/Tile.cpp
  src/riichi/AIPlayer.cpp
)


include_directories(src src/riichi)

add_executable(mahjong ${mahjong_HEADERS} ${mahjong_SOURCES})

