// 2024-12-04 (최종제출 후 컬러 추가 및 수정)

#define COLOR_NONE		"\033[0m"
#define COLOR_BLACK		"\033[0;30m"
#define COLOR_RED		"\033[0;31m"
#define COLOR_GREEN		"\033[0;32m"
#define COLOR_BROWN		"\033[0;33m"
#define COLOR_BLUE		"\033[0;34m"
#define COLOR_PURPLE	"\033[0;35m"
#define COLOR_CYAN		"\033[0;36m"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define log(x, str) printf(x str COLOR_NONE);

typedef struct _user{
 char userName[20];
 int position;
 char icon[3];
}User;

void first_cls(void);
void game_int();
void user_setting(User *u1, User *u2);
void menu();
void hwamyeon(User *u1, User *u2);
void gotoxy(int x, int y);
void figure(User u1, User u2);
int game_play(User *u1, User *u2);
void trap(User *u);
int conclusion(User *u);

void game_int(){
 system("cls");
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                      부 루 마 불                       ■\n■                                                        ■\n■                BlueMarble Console Game                 ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                Press any key to start...               ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n                                          개발 : 1617 손우찬");
 getche();
 system("cls");
}

void menu(){
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                      튜 토 리 얼                       ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
 printf("\n\n");
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n■                                                        ■\n■                                                        ■\n■                      게 임 시 작                       ■\n■                                                        ■\n■                                                        ■\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
 printf("\n\n");
 printf("\n\n튜토리얼을 원하시면 T, 게임시작을 원하시면 G을 눌러주세요.\n\n");
}

int main(void){
 game_int();
 menu();
 char ins_int = _getch();
 if (ins_int == 'T' || ins_int == 't'){
  system("cls");
  printf("Loading...");
  system("cls");
  first_cls();
 }
 else if (ins_int == 'G' || ins_int == 'g'){
  User u1, u2;
  system("cls");
  int end_game = 0;
  user_setting(&u1, &u2);
  srand((unsigned)time(NULL));
  while (!(end_game)){
   end_game = game_play(&u1, &u2);
  }
  gotoxy(1, 24);
  return 0;
  }
}

void gotoxy(int x, int y){
 COORD Pos = { x - 1, y - 1 };
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void user_setting(User *u1, User *u2){
 int number;
 printf("1st player's name: \n");
 scanf("%s", u1->userName);
 printf("2nd player's name: \n");
 scanf("%s", u2->userName);
 u1->position = u2->position = 1;
 number = rand() % 2;
 if (number){
  strcpy(u1->icon, "▣");
  strcpy(u2->icon, "◈");
  printf("\n%s, your figure is %s.\n", u1->userName, u1->icon);
  printf("\n%s, your figure is %s.\n", u2->userName, u2->icon);
 }
 else{
  strcpy(u1->icon, "◈");
  strcpy(u2->icon, "▣");
  printf("\n%s, your figure is %s.\n", u1->userName, u1->icon);
  printf("\n%s, your figure is %s.\n", u2->userName, u2->icon);
 }
 printf("\n\nPress any key to play...");
 getch();
 system("cls");
}

void first_cls(void){
 system("cls");
 printf("B L U E M A R B L E\n");
 printf("▣ is first.\n");
 printf("anyone who reaches first, You Win!\n");
 getch();
}

void hwamyeon(User *u1, User *u2){
 system("cls");
 log(COLOR_RED, "B ");
 log(COLOR_GREEN, "L ");
 log(COLOR_BLUE, "U ");
 log(COLOR_BROWN, "E ");
 log(COLOR_PURPLE, "M ");
 log(COLOR_RED, "A ");
 log(COLOR_GREEN, "R ");
 log(COLOR_BLUE, "B ");
 log(COLOR_BROWN, "L ");
 log(COLOR_PURPLE, "E ");
 printf("\n\nGame player sequence : ");
 printf("1st:%s(▣), 2nd:%s(◈)\n\n", u1->userName, u2->userName);
 printf("Trap shape : ■, Trap Location : 2 18 27\n\n");
 printf("START");
 for (int i = 0; i < 32; i++){
  printf("  ");
 }
  printf("END\n");
 for (int i = 0; i < 35; i++){
  if (i == 1 || i == 17 || i == 26){
   log(COLOR_RED, "■");
  }
  else{
   log(COLOR_CYAN, "□");
  }
 }
 figure(*u1, *u2);
}

void figure(User u1, User u2){
 if (u1.position >= 71){
  u1.position = 71;
 }
 if (u2.position >= 71){
  u2.position = 71;
 }
 gotoxy(u1.position, 8);
 printf("%s", u1.icon);
 if (u1.position == u2.position){
  gotoxy(u2.position, 9);
  printf("%s", u2.icon);
 }
 else{
  gotoxy(u2.position, 8);
  printf("%s", u2.icon);
 }
}

int game_play(User *u1, User *u2){
 int dice;
 system("cls");
 hwamyeon(u1, u2);
 gotoxy(1, 11);
 for (int i = 0; i < 2; i++){
  if (i == 0){
   gotoxy(1, 11);
   printf("%s, your turn. Press any key to continue:", u1->userName);
   getch();
   dice = rand() % 6 + 1;
   u1->position += dice * 2;
   gotoxy(1, 12);
   printf("The dice number is %d, so %s, your location is %d.", dice, u1->userName, u1->position / 2 + 1);
   trap(u1);
   Sleep(1000);
   hwamyeon(u1, u2);
   if (conclusion(u1)){
    gotoxy(1, 15);
    printf("%s WIN!!!", u1->userName);
    return 1;
   }
  }
  else{
   gotoxy(1, 11);
   printf("%s, your turn. Press any key to continue:", u2->userName);
   getch();
   dice = rand() % 6 + 1;
   u2->position += dice * 2;
   gotoxy(1, 12);
   printf("The dice number is %d, so %s, your location is %d.", dice, u2->userName, u2->position / 2 + 1);
   trap(u2);
   Sleep(1000);
   hwamyeon(u1, u2);
   if (conclusion(u2)){
    gotoxy(1, 15);
    printf("%s WIN!!!", u2->userName);
    return 2;
    }
   }
  }
  return 0;
}

void trap(User *u){
 if (u->position == 13 || u->position == 31 || u->position == 51){
  gotoxy(1, 13);
  printf("T R A P : goto 0..");
  u->position = 1;
  }
}

int conclusion(User *u){
 if (u->position >= 69){
  return 1;
 }
 return 0;
}
