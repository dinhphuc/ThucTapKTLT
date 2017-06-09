#pragma once
/*----------Frames---------------*/
void KhungExit();
void checkExit(int *Err1, char *look);
void XoaCheckExit();
/*----------Enter---------------*/
void EnterChuoi(char *xau, int i, int ox, int oy, int *Err);

void EnterMaLop(char *xau, int i,int &y, int ox, int oy, int *Err);
void EnterMaSV(char *xau, int i, int &y, int ox, int oy, int *Err);
void EnterHoTen(char *xau, int i, int &y, int ox, int oy, int *Err);
void EnterNgaySinh(char *xau, int i, int &y, int ox, int oy, int *Err);
void EnterDiem(char *xau, int i, int &y, int ox, int oy, int *Err);
void EnterNameFile(char *xau, int i, int ox, int oy, int *Err);
/*----------Function Support---------------*/
void TachNgay(char *xau, int *day, int *mount, int *year);
int KT_Date(int &day, int &month, int &year);
void ChangePSeach(float x, char A[]);