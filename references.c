//#pragma once
//
///* ▼▼▼▼▼ 헤더 선언 ▼▼▼▼▼ */
//#include <stdio.h>
//#include <windows.h>
//#include <stralign.h>
//#include <stdlib.h>
///* ▲▲▲▲▲ 헤더 선언 ▲▲▲▲▲ */
//
///* ▼▼▼▼▼ define 선언 ▼▼▼▼▼ */
//#define pause system("pause > nul")
//#define cls system("cls")    //이것 또한
///* ▲▲▲▲▲ define 선언 ▲▲▲▲▲ */
//
///* ▼▼▼▼▼ 함수 선언 ▼▼▼▼▼ */
//void SetColor(int color);
//void CursorView(char show);
//void gotoxy(int x, int y);
//
//#include "main.h"
//
//void SetColor(int color)
//{
//   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//
//}
//
//void CursorView(char show)
//{
//   HANDLE hConsole;
//   CONSOLE_CURSOR_INFO ConsoleCursor;
//
//   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//   ConsoleCursor.dwSize = mainPtr(CursorView);
//   void main(){}
//
//   ConsoleCursor.bVisible = show;
//   ConsoleCursor.dwSize = 1;
//
//   SetConsoleCursorInfo(hConsole, &ConsoleCursor);
//}
//
//void gotoxy(int x, int y) {
//
//   COORD pos = { x, y };
//   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//#include <main.h>
//
//void mainPtr(void);
//
//int main(void) {
//   CursorView(0);    //커서의 깜빡임을 숨겨준다.
//   system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
//   mainPtr();
//   pause;
//   return 0;
//}
//
//void mainPtr(void) {
//   system("mode con: cols=106 lines=9");   //참고로 cols 2단위가 특수문자 또는 한글 1글자다.
//   system("title 미로찾기 - 메인");
//   puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   puts("■                                                                                                      ■");
//   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
//   gotoxy(10, 4); printf("새로  하기");
//   gotoxy(35, 4); printf("이어  하기");
//   gotoxy(60, 4); printf("랭킹  보기");
//   gotoxy(85, 4); printf("게임  종료");
//   return;
//}
//#include <stdio.h>
//#include <string.h>
//
//void sspark(char* t, int s) {
//   int i;
//   char a;
//   int len = strlen(t);
//
//   for (i = 0; i < len; i++) {
//      a = t[i];
//      if (a >= 'A' && a <= 'Z') {
//         a = (a - 'A' - s + 26) % 26 + 'A';
//      }
//      else if (a >= 'a' && a <= 'z') {
//         a = (a - 'a' - s + 26) % 26 + 'a';
//      }
//      printf("%c", a);
//   }
//   printf("\n");
//}
//
//void main() {
//   char t[100];
//   int s;
//   fgets(t, sizeof(t), stdin);
//   t[strcspn(t, "\n")] = 0;
//   sspark(t, 3);
//}
//
///*#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <Windows.h>
//
//void GK_location(int x, int y) {
//   COORD Pos;
//   Pos.X = x;
//   Pos.Y = y;
//   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//}
//
//int main(void) {
//   printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                      ■\n■                                      ■\n■                                      ■\n■                                      ■\n■                                      ■\n");
//   GK_location(20, 3);
//   printf("O");
//   return 0;
//}*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#define MAP 16

int Dice();
void User_turn();
void Computer_turn();
void Local();

char local[MAP][30] = {"시작지점","한국","미국","일본","중국","영국","소련","독일","아르헨티나","그리스","프랑스","스웨덴","오스트레일리아","터키","스위스","이집트"};
int own_local[MAP] = {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int* p = &own_local[0];
char loc[15];
int dice1,dice2,temp;
int money = 1000;
int i=0,uj=0,cj=0;
int cho;
char cho2;

int main(void) {

 printf("** BlueMarble **\n\nPress Any Key to Game Start");
 getch();
 srand(time(NULL));

 while(1){
 dice1 = dice2 = 0;
 system("cls");

 User_turn();
 Computer_turn();

 } // end while


 return 0;
}

int Dice() {
 int a;
 a = rand()%6+1;
 return a;
}

void Local() {
 for(i=0; i != (uj+1) ;i++) {
  strcpy(loc,local[i]);
 }
}

void User_turn() {

 Local();
 printf(
  "[당신의 차례입니다.]\n\n"
  "현재 당신의 장소 : %s(%d)\n\n",
  loc,uj
  );

  dice1 = Dice();
  dice2 = Dice();
  printf("=주사위 결과=\n""[%d]+[%d] = [%d]\n\n",dice1,dice2,dice1+dice2);
  getch();
  temp = dice1+dice2;
  uj += temp;
  if( uj > MAP ) {
   for(uj-=temp ;uj < MAP ;temp--){
    uj += 1;
   }
   uj = 0;
   money += 500;
   puts("한바퀴를 돌아서 500원을 받습니다.\n");
   uj += temp;
  }

 Local();
ure :
 printf(
  "현재 당신의 돈 : %d원\n"
  "현재 당신의 장소 : %s(%d)\n"
  "%s의 토지가격 - %d원\n\n"
  "------------------\n"
  "1. 현재 영토 구입\n"
  "2. 내 영토 확인\n"
  "3. 턴 넘기기\n"
  "땅 소유 여부 : %d\n"
  "------------------\n"
  "  선택 : [ ]\b\b"
  ,money,loc,uj,loc,uj*100,p[uj]
  );
 scanf("%d",&cho);

 switch(cho){
 case 1:
  system("cls");
  if(money >= uj*100 && own_local[uj] == 0) {
   money -= uj*100;
   p[uj]=1;
   printf("%s을(를) 성공적으로 구입했습니다!\n남은 돈 : %d원\n",loc,money);
  } else if(money < uj*100) {
   printf("돈이 부족합니다!\n");
   Sleep(1500);
   system("cls");
   goto ure;
  } else {
   printf("%s은(는) 이미 소유권이 있는 영토입니다!\n",loc);
   Sleep(1500);
   system("cls");
   goto ure;
  }
  getch();
  break;
 case 2:
  system("cls");
  printf(
   "현재 당신의 소유 땅\n"
   "-----------------------\n"
   );
  for(i=0;i<MAP;i++) {
   if(p[i] == 1) {
    printf("%s(%d) - %d원\n",local[i],i,i*100);
   }
  }
  puts("-----------------------");
  puts("아무키나 누르면 돌아갑니다.");
  getch();
  system("cls");
  goto ure;
  break;
 case 3:
  system("cls");
  puts("턴을 마칩니다.");
  Sleep(1500);
  system("cls");
  break;
 }
}

void Computer_turn(){

}
