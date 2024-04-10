#include "console/console.h"
#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
int main() {
  std::cout << "dsfsd";
  srand((unsigned int)time(nullptr));
  console::init();

  Game game;

  while (!game.shouldExit()) {
    console::clear();

    game.update();
    game.draw();

    // wait은 여기서만 호출되어야 한다.
    console::wait();
  }
}