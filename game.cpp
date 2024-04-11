#include "game.h"
#include "console/console.h"
#include <cstdlib>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define LINES 40

#define DROP_DELAY 60


Tetromino Tetromino::I("I", 4, "XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O("O", 2, "OOOO");
Tetromino Tetromino::T("T", 3, "XOXOOOXXX");
Tetromino Tetromino::S("S", 3, "XOOOOXXXX");
Tetromino Tetromino::Z("Z", 3, "OOXXOOXXX");
Tetromino Tetromino::J("J", 3, "OXXOOOXXX");
Tetromino Tetromino::L("L", 3, "XXOOOOXXX");

void Game::random() {
  randNum = (int)rand() % 7 + 1;
  switch(randNum){
    case 1:
      nextT = Tetromino("I", 4, "XXXXOOOOXXXXXXXX");
      break;
    case 2:
      nextT = Tetromino("O", 2, "OOOO");
      break;
    case 3:
      nextT = Tetromino("T", 3, "XOXOOOXXX");
      break;
    case 4:
      nextT = Tetromino("S", 3, "XOOOOXXXX");
      break;
    case 5:
      nextT = Tetromino("Z", 3, "OOXXOOXXX");
      break;
    case 6:
      nextT = Tetromino("J", 3, "OXXOOOXXX");
      break;
    case 7:
      nextT = Tetromino("L", 3, "XXOOOOXXX");
      break;
  }
}

void Game::firstRandom() {
  randNum = (int)rand() % 7 + 1;
  switch(randNum){
    case 1:
      curT = Tetromino("I", 4, "XXXXOOOOXXXXXXXX");
      break;
    case 2:
      curT = Tetromino("O", 2, "OOOO");
      break;
    case 3:
      curT = Tetromino("T", 3, "XOXOOOXXX");
      break;
    case 4:
      curT = Tetromino("S", 3, "XOOOOXXXX");
      break;
    case 5:
      curT = Tetromino("Z", 3, "OOXXOOXXX");
      break;
    case 6:
      curT = Tetromino("J", 3, "OXXOOOXXX");
      break;
    case 7:
      curT = Tetromino("L", 3, "XXOOOOXXX");
      break;
  }
}


  // 게임의 한 프레임을 처리한다.
void Game::update() {
  
  if(console::key(console::K_X)) {
    curT = curT.rotatedCW();
  }
  else if(console::key(console::K_Z)) {
    curT = curT.rotatedCCW();
  }
}
// 게임 화면을 그린다.
void Game::draw(){
  console::log("print test");
  console::drawBox(0, 0, BOARD_WIDTH, BOARD_HEIGHT);
  console::drawBox(28, 0, 31, 5);
}

// 게임 루프가 종료되어야 하는지 여부를 반환한다.
bool Game::shouldExit(){
  // ESC 키를 누르면 게임종료
  if(console::key(console::K_ESC)){
    return false;
  }
  else if(count_line == 40){
    return false;
  }
  return true;
}

Game::Game() {
  for(int i = 0; i < BOARD_WIDTH; i++){
    for(int j = 0; j < BOARD_HEIGHT; j++){
      board_[i][j] = false;
    }
  }
  count_line = 0;   
  randNum = 0;
}

