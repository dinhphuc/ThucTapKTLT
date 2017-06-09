#pragma once
struct HoSo{
	char MaLop[25];
	char MaSV[25];
	char Hoten[50];
	char NgaySinh[25];
	float DiemTB;
};

struct HoTen
{
	char Ten[10],FullName[50];
};

struct Date
{
	char day[2], month[2], year[4];
};

struct TK_Class{
	int soluong = 1;
	char *MaLop;
};
struct TK_Point{
	int soluong = 1;
	float Point;
};
