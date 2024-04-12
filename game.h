
#ifndef GAME_H
#define GAME_H

#include "tetromino.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define LINES 40

#define DROP_DELAY 60
class Game {
private: 
  // 게임 판을 나타내는 배열
  // board[x][y]가 true 인 경우 x, y 위치에 고정된 블록이 존재하는 것을 의미한다
  bool board_[BOARD_WIDTH][BOARD_HEIGHT];
  

  // 1줄을 꽉채워서 없앤 줄의 갯수
  int count_line;
  Tetromino curT = Tetromino::I;
  Tetromino nextT = Tetromino::I;
  Tetromino holdT = Tetromino::I;
  int randNum;
  int curX = BOARD_WIDTH/2 - 1;
  int curY = 0;
  bool cur_floor = false;
  int dropTimer = DROP_DELAY;

  void drawBoard();

  void random();

  void firstRandom();

  void downTetro();

  void handleTetroInput();
public:
  // 게임의 한 프레임을 처리한다.
  void update();

  // 게임 화면을 그린다.
  void draw();

  // 게임 루프가 종료되어야 하는지 여부를 반환한다.
  bool shouldExit();

  Game();
};
#endif