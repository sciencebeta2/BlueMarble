//#pragma once
//
///* ������ ��� ���� ������ */
//#include <stdio.h>
//#include <windows.h>
//#include <stralign.h>
//#include <stdlib.h>
///* ������ ��� ���� ������ */
//
///* ������ define ���� ������ */
//#define pause system("pause > nul")
//#define cls system("cls")    //�̰� ����
///* ������ define ���� ������ */
//
///* ������ �Լ� ���� ������ */
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
//   CursorView(0);    //Ŀ���� �������� �����ش�.
//   system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
//   mainPtr();
//   pause;
//   return 0;
//}
//
//void mainPtr(void) {
//   system("mode con: cols=106 lines=9");   //����� cols 2������ Ư������ �Ǵ� �ѱ� 1���ڴ�.
//   system("title �̷�ã�� - ����");
//   puts("������������������������������������������������������");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   puts("��                                                                                                      ��");
//   printf("������������������������������������������������������");
//   gotoxy(10, 4); printf("����  �ϱ�");
//   gotoxy(35, 4); printf("�̾�  �ϱ�");
//   gotoxy(60, 4); printf("��ŷ  ����");
//   gotoxy(85, 4); printf("����  ����");
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
//   printf("�����������������������������������������\n��                                      ��\n��                                      ��\n��                                      ��\n��                                      ��\n��                                      ��\n");
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

char local[MAP][30] = {"��������","�ѱ�","�̱�","�Ϻ�","�߱�","����","�ҷ�","����","�Ƹ���Ƽ��","�׸���","������","������","����Ʈ���ϸ���","��Ű","������","����Ʈ"};
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
  "[����� �����Դϴ�.]\n\n"
  "���� ����� ��� : %s(%d)\n\n",
  loc,uj
  );

  dice1 = Dice();
  dice2 = Dice();
  printf("=�ֻ��� ���=\n""[%d]+[%d] = [%d]\n\n",dice1,dice2,dice1+dice2);
  getch();
  temp = dice1+dice2;
  uj += temp;
  if( uj > MAP ) {
   for(uj-=temp ;uj < MAP ;temp--){
    uj += 1;
   }
   uj = 0;
   money += 500;
   puts("�ѹ����� ���Ƽ� 500���� �޽��ϴ�.\n");
   uj += temp;
  }

 Local();
ure :
 printf(
  "���� ����� �� : %d��\n"
  "���� ����� ��� : %s(%d)\n"
  "%s�� �������� - %d��\n\n"
  "------------------\n"
  "1. ���� ���� ����\n"
  "2. �� ���� Ȯ��\n"
  "3. �� �ѱ��\n"
  "�� ���� ���� : %d\n"
  "------------------\n"
  "  ���� : [ ]\b\b"
  ,money,loc,uj,loc,uj*100,p[uj]
  );
 scanf("%d",&cho);

 switch(cho){
 case 1:
  system("cls");
  if(money >= uj*100 && own_local[uj] == 0) {
   money -= uj*100;
   p[uj]=1;
   printf("%s��(��) ���������� �����߽��ϴ�!\n���� �� : %d��\n",loc,money);
  } else if(money < uj*100) {
   printf("���� �����մϴ�!\n");
   Sleep(1500);
   system("cls");
   goto ure;
  } else {
   printf("%s��(��) �̹� �������� �ִ� �����Դϴ�!\n",loc);
   Sleep(1500);
   system("cls");
   goto ure;
  }
  getch();
  break;
 case 2:
  system("cls");
  printf(
   "���� ����� ���� ��\n"
   "-----------------------\n"
   );
  for(i=0;i<MAP;i++) {
   if(p[i] == 1) {
    printf("%s(%d) - %d��\n",local[i],i,i*100);
   }
  }
  puts("-----------------------");
  puts("�ƹ�Ű�� ������ ���ư��ϴ�.");
  getch();
  system("cls");
  goto ure;
  break;
 case 3:
  system("cls");
  puts("���� ��Ĩ�ϴ�.");
  Sleep(1500);
  system("cls");
  break;
 }
}

void Computer_turn(){

}
