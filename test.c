#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int random();
void intro();
void menu();
void tutorial();
void play();
void myaccount();

int main(){
 while(1){
    intro();
    menu();
 }
}

void intro(){
 system("cls"); //�� �Լ� ������ �� cls ���� ������ �Ѵ�.
 printf("�������������������������������\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                      �� �� �� ��                       ��\n��                                                        ��\n��                BlueMarble Console Game                 ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                Press any key to start...               ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n��                                                        ��\n�������������������������������\n\n\n                                          ���� : 1617 �տ���");
// Sleep(4000);
 getche();
 system("cls");
}

void menu(){
 printf("�������������������������������\n��                                                        ��\n��                                                        ��\n��                      Ʃ �� �� ��                       ��\n��                                                        ��\n��                                                        ��\n�������������������������������");
 printf("\n\n");
 printf("�������������������������������\n��                                                        ��\n��                                                        ��\n��                      �� �� �� ��                       ��\n��                                                        ��\n��                                                        ��\n�������������������������������");
 printf("\n\n");
 printf("�������������������������������\n��                                                        ��\n��                                                        ��\n��                      �� �� �� ��                       ��\n��                                                        ��\n��                                                        ��\n�������������������������������");
 printf("\n\nƩ�丮���� ���Ͻø� T, ���ӽ����� ���Ͻø� G, ���Ǳ���� ���Ͻø� R�� �����ּ���.\n\n");
 char ins_int = _getch();
 if (ins_int == 'T' || ins_int == 't'){
    system("cls");
    printf("Ʃ�丮���� Ŭ���ϼ̽��ϴ�.\n\n\n");
 }
 else if (ins_int == 'G' || ins_int == 'g'){
    system("cls");
    printf("���� ���� �Լ� ���� ����\n\n\n");
 }
 else if (ins_int == 'R' || ins_int == 'r'){
    system("cls");
    printf("���Ǳ�� ��ȸ�� Ŭ���ϼ̽��ϴ�.\n\n\n");
 }
 else{
    printf("\n\n�߸��� ���ڸ� �Է��Ͽ����ϴ�. �ٽ� �õ��� �ּ���.\n\n\n");
 }
}


