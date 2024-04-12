
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

  int dropTimer = DROP_DELAY;

  bool leftWall = false;
  bool rightWall = false;


  // 보드판을 그린다
  void drawBoard();

  // 게임이 실행될때 첫번째 테트로미노를 랜덤으로 생성
  void firstRandom();

  // 두번째부터 테트로미노를 랜덤으로 생성
  void random();

  // 테트로미노를 아래로 이동시킨다.
  void downTetro();

  // 키를 입력하여 테트로미노를 왼쪽,오른쪽으로 이동 또는 시계, 반시계 방향으로 회전시킨다
  void handleTetroInput();

  // 오른쪽 또는 왼쪽 벽에 닿아있는지 확인한다
  void hitWall();
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