#include <iostream>
#include <string>
#include "Tile.h"
#include <locale>

using namespace Mahjong;



//std::codecvt_utf8<char32_t> // converts between UTF-8 <-> UTF-32




int main(){
  //  std::wstring_convert<std::codecvt_utf8_utf32<char32_t>,char32_t> convert;

  Tile oneOfDots(Tile::Type::SUITED, Tile::Suit::DOTS, 1);

  // std::u32string str32;

  //str32 += oneOfDots.GetUnicodeChar();

  std::cout << oneOfDots.GetUnicodeChar() << std::endl;
}
