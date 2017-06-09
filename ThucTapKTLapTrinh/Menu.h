#pragma once
#include "Console.h"
#include "Struct.h"
void ChuyenControUpDown(int *ToaDo, int Trang, int trangcuoi, int *Oy);
void ChuyenControLeftRight(int *ToaDoOx, int *Ox, int Oy);
void themhs();
void ChayChu(char *xau);
void Khung_checkFile(char *Xau);
void SettingDefaulNameFile(char *NameFile);
void Help();
int checkFile(char *Filename);
void GetNameDefault(char *NameFile);
void setting(char *NameFile);
void Menu();
void Menu_ThemHS();
void Menu_sx_DoiMau1(int ToaDo);
void Menu_sx_DoiMau2(char *s, int ToaDo);
void menu1();
void Menu_Search_DoiMau2(char *s, int ToaDo);
void Menu_Search_DoiMau1(int ToaDo);
/*----------main Thống Kê--------------*/
void menu1z();
void Menu_ThongKe_DoiMau2(int Toado);
