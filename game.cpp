#include "game.h"
#include "console/console.h"
#include <iostream>
#include <cstdlib>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define LINES 40

#define DROP_DELAY 60


Tetromino Tetromino::I("I", 4, "XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O("O", 2, "XXXXXOOXXOOXXXXX");
Tetromino Tetromino::T("T", 4, "XOXXOOOXXXXXXXXX");
Tetromino Tetromino::S("S", 3, "XOOOOXXXX");
Tetromino Tetromino::Z("Z", 3, "OOXXOOXXX");
Tetromino Tetromino::J("J", 3, "OXXOOOXXX");
Tetromino Tetromino::L("L", 3, "XXOOOOXXX");


// board 3개를 그린다.
void Game::drawBoard(){
  console::drawBox(0,0,10,20); // board 칸을 그린다
  console::drawBox(12,0,16,5); // Next 칸을 그린다
  console::drawBox(17,0,21,5); // Hold 칸을 그린다
}
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

void Game::downTetro() {
  dropTimer--;
  if(dropTimer == 0){
    dropTimer = DROP_DELAY;
    curY++;
  }
}

void Game::handleTetroInput() {
  if(console::key(console::K_Z)){
    curT.rotatedCW();
  }
  if(console::key(console::K_X)){
    curT.rotatedCCW();
  }
  if(console::key(console::K_LEFT)){
    if(!leftWall) {curX--;}
  }
  if(console::key(console::K_RIGHT)){
    if(!rightWall){curX++;}
  }
}

void Game::hitWall(){ 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(curT.check(j, i) == true && curX == 1){
        leftWall = true;
        return;
      }
      else if(curT.check(j, i) == true && curX == 8){
        rightWall = true;
        return;
      }
    }
  }
  leftWall = false;
  rightWall = false;
}
  // 게임의 한 프레임을 처리한다.
void Game::update() {
  //if(cur_floor == true){
    //curT = nextT;
   // random();
  //}
  downTetro();
  drawBoard();
  hitWall();
  handleTetroInput();
  
}   
// 게임 화면을 그린다.
void Game::draw(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(curT.check(i, j)){
        curT.drawAt(BLOCK_STRING, curX + i, curY + j);
        std::cout << curX + i;
      }
    }
  }
}

// 게임 루프가 종료되어야 하는지 여부를 반환한다.
bool Game::shouldExit(){
  // ESC 키를 누르면 게임종료
  if(console::key(console::K_ESC)){
    return true;
  }
  if(count_line == 40){
    return true;
  }
  return false;
}

Game::Game() {
  for(int i = 0; i < BOARD_WIDTH; i++){
    for(int j = 0; j < BOARD_HEIGHT; j++){
      board_[i][j] = false;
    }
  }
  count_line = 0;   
  randNum = 0;
  firstRandom();
  random();
}

