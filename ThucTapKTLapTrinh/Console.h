#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*----------library Default---------------*/
#include <Windows.h>
#include<string.h>
#include<ctype.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
using namespace std;
/*----------library User Define---------------*/
#include "Menu.h"
#include "console.h"
#include "Struct.h"
#include "console.h"
#include "Sort.h"
#include "AddNewHS.h"
#include "PrintfHS.h"
#include "Struct.h"
#include "FixErr.h"
#include "Thong_Ke.h"
#include "Search.h"
/*----------Funtion Console---------------*/
void Menu_batPhim(int Toado);
void HidePointer();
void ShowPointer();
void textcolor(int x);
void gotoxy(int x, int y);
void pain();
void FrameGioiThieu();
void GioiThieu();
void clrscr();
void Save();
void Khung_seach();
void END();