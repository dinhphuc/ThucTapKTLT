#pragma once
#include "Struct.h"

/*----------Function Support---------------*/
void DaoChuoi(char s[], char temp[]);
void swapDate(vector <HoSo> &HS);
void swapDate2(vector <HoSo> &HS);
void ChangePoint(float x, char A[]);
int SoSanhChuoi(char *s1, char *s2);

/*----------Number Class---------------*/
void SX_Chon_MaLop(vector <HoSo>&HS, int n);
void SX_Chen_MaLop(vector <HoSo>&HS, int n);
void SX_NoiBot_MaLop(vector <HoSo>&HS, int n);
void SX_QuickSort_MaLop(vector <HoSo>&HS, int left, int right);
/*----------NumberID---------------*/
void SX_Chon_MaSV(vector <HoSo>&HS, int n);
void SX_Chen_MaSV(vector <HoSo>&HS, int n);
void SX_NoiBot_MaSV(vector <HoSo>&HS, int n);
void SX_QuickSort_MaSV(vector <HoSo>&HS, int left, int right);

/*----------Name---------------*/
void SX_Chon_HoTen(vector <HoSo>&HS, int n);
void SX_Chen_HoTen(vector <HoSo>&HS, int n);
void SX_NoiBot_HoTen(vector <HoSo>&HS, int n);
void SX_QuickSort_HoTen(vector <HoSo>&HS, int left, int right);
/*----------Birth Day---------------*/
void SX_Chon_NgaySinh(vector <HoSo>&HS, int n);
void SX_Chen_NgaySinh(vector <HoSo>&HS, int n);
void SX_NoiBot_NgaySinh(vector <HoSo>&HS, int n);
void SX_QuickSort_NgaySinh(vector <HoSo>&HS, int left, int right);
/*----------DTB---------------*/
void SX_Chon_DiemTB(vector <HoSo>&HS, int n);
void SX_Chen_DiemTB(vector <HoSo>&HS, int n);
void SX_NoiBot_DiemTB(vector <HoSo>&HS, int n);
void SX_QuickSort_DiemTB(vector <HoSo>&HS, int left, int right);
/*----------main Sort---------------*/
void MainSapxep(vector <HoSo> &HS, char *FileName);