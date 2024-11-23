// 2024-11-23

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int random();
void intro();
void menu();
void tutorial();
void play();
void myaccount();

int main(){
 //여기에 while(1) 넣으면 intro()랑 menu() 사이에 무한루프 된다.
 intro();
 menu();
 char ins_int = _getch();
 if (ins_int == 'T' || ins_int == 't'){
  system("cls");
  printf("Loading...");
  Sleep(1000);
  tutorial();
 }
 else if (ins_int == 'G' || ins_int == 'g'){
  system("cls");
  printf("게임 시작 함수 구현 예정\n\n\n");
 }
 else if (ins_int == 'R' || ins_int == 'r'){
  system("cls");
  printf("나의기록 조회를 클릭하셨습니다.\n\n\n");
 }
 else{
  printf("\n\n잘못된 문자를 입력하였습니다. 다시 시도해 주세요.\n\n\n");
 }
}

void intro(){
 system("cls"); //매 함수 시작할 때 cls 먼저 깔아줘야 한다.
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                      부 루 마 불                       ■\n■                                                        ■\n■                BlueMarble Console Game                 ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                Press any key to start...               ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n                                          개발 : 1617 손우찬");
// Sleep(4000);
 getche();
 system("cls");
}

void menu(){
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                      튜 토 리 얼                       ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
 printf("\n\n");
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                      게 임 시 작                       ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
 printf("\n\n");
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                      나 의 기 록                       ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
 printf("\n\n튜토리얼을 원하시면 T, 게임시작을 원하시면 G, 나의기록을 원하시면 R을 눌러주세요.\n\n");
}

void tutorial(){
    system("cls");
 // 크레딧 텍스트 배열

}

