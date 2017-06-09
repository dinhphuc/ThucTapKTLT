#pragma once
#include "console.h"
/*----------Main Thống kê---------------*/
void Main_ThongKe(vector <HoSo> HS, char* FileName, int n);
/*----------Số Lượng SV theo Điểm---------------*/
int SoSVGioi(vector <HoSo>HS, int n);
int SoSVKha(vector <HoSo>HS, int n);
int SoSVTB(vector <HoSo>HS, int n);
int SoSVYeu(vector <HoSo>HS, int n);
/*----------Biểu đồ---------------*/
void xuly_BieuDo(vector <HoSo>HS, int n);
void Khung_BieuDo(vector <HoSo>HS, int n);
