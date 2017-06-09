#pragma once
#include "Console.h"

/*----------Frames---------------*/
void Khung_PrintfTK(char *s);
void Ong_NganCach(int OY);
void Ong_DaiDuoi(int ChieuDai_duoi_min);
void Ong_ChieuRong(int Ong_RongMin);
void Khung_IN();
void ChuyenMau(int x);
void Menu_In_Down();
void dialogNull();
/*----------File---------------*/
void InFile(vector <HoSo> HS, char *Filename);
void DeleteSV(vector <HoSo> &HS, int ToaDo);
vector<HoSo>  input(char *FileName);
void UpdateFile(char *FileName, vector <HoSo > HS);
/*------------------------*/
void OutPut(vector <HoSo> HS, char *FileName, int inF, int n);