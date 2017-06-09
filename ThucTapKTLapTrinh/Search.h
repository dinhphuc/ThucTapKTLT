#pragma once
#include "Console.h"
/*----------Function Support---------------*/
void SaveFileSearch(vector <HoSo> HSTK, int z, char *FileTxt, char *FileWb);
int compare_Search(char *xau, char *look);
/*----------Search binary---------------*/
void NhiPhan_Malop(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void NhiPhan_MaSV(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void NhiPhan_HoTen(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void NhiPhan_NgaySinh(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void NhiPhan_DTB(vector <HoSo> HS, vector <HoSo> &HSTK, float look);

/*----------Search Tuần Tự---------------*/
void TuanTu_Malop(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void TuanTu_MaSV(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void TuanTu_HoTen(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void TuanTu_NgaySinh(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
void TuanTu_DTB(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);

/*----------Main Search---------------*/
void MainSearch(vector<HoSo> HS, char *FileName ,int n);
void TuanTu_MaSV(vector <HoSo> HS, vector <HoSo> &HSTK, char look[]);
