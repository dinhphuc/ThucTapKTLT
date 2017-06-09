#include "Console.h"
#include <stdio.h>
#include <conio.h>
long size = sizeof(HoSo);
int BatLoi(char *FileName, char *Malop, char *MaSV, char *HoTen, char *NgaySinh, char *DTB)
{
	int a = 50;
	/*Mã Lớp*/
	if ((strlen(Malop) <= 0) || (strlen(Malop) > 15))
	{
	
		if (strlen(Malop) <= 0){ textcolor(14); gotoxy(a + 43, 5); printf("ERRO ! Empty "); return -1; }
		if (strlen(Malop) >= 15){ textcolor(14); gotoxy(a + 43, 5); printf("ERRO ! Full "); return -1; }
		
	}
	textcolor(7); gotoxy(90, 5); printf("                             ");
	fflush(stdin);
	/*Mã  SV*/
	if (strlen(MaSV) <= 0){ textcolor(14); gotoxy(a + 43, 7); printf("ERRO ! Empty "); return -1; }
	vector <HoSo> HSTK; vector<HoSo> HStemp;
	HStemp = input(FileName);
	//Xử lý Trùng
	if (strlen(MaSV) != 8)
	{
		gotoxy(93, 7); textcolor(14); printf("ERRO ! Enter 8 number ");
		return -1;
	}
	HSTK.clear();
	TuanTu_MaSV(HStemp, HSTK, MaSV);
	if (HSTK.size() >= 1){
		textcolor(7); gotoxy(90, 7); printf("                             ");
		gotoxy(93, 7); textcolor(14); printf("ERRO ! Have exist ");
		return -1;
	}
	HStemp.~vector();
	textcolor(7); gotoxy(90, 7); printf("                             ");
	/*Họ Và Tên*/
	if (strlen(HoTen) <= 0 || strlen(HoTen) >= 30)
	{
		if (strlen(HoTen) <= 0){ textcolor(14); gotoxy(93, 9); printf("ERRO ! Empty "); return -1; }
		textcolor(7); gotoxy(90, 9); printf("                             ");
		if (strlen(HoTen) >= 30){ textcolor(14); gotoxy(93, 9); printf("ERRO ! Full "); return -1; }	
	}
	textcolor(7); gotoxy(90, 9); printf("                             ");
	/*Ngày Sinh*/
	int day = 0, month = 0, year = 0;
	TachNgay(NgaySinh, &day, &month, &year);
	if (strlen(NgaySinh) <= 0){ gotoxy(a + 45, 11); printf("ERRO ! Empty "); return -1; }
	if (KT_Date(day, month, year) == 0 || (strlen(NgaySinh) != 10))
	{
		textcolor(14);	gotoxy(a + 45, 11); printf("ERRO !");
		return -1;
	}
	textcolor(7); gotoxy(90, 11); printf("                             ");
	/*Điểm TB*/
	if (strlen(DTB) == 0)
	{
		textcolor(14); gotoxy(a + 45, 13); printf("ERRO ! Empty ");
		return -1;
	}
	textcolor(7); gotoxy(a + 45, 13); printf("                  ");
	float DTBz = (float)atof(DTB);
	if (DTBz > 10.0 || DTBz < 0.0)
	{
		textcolor(14); gotoxy(a + 45, 13); printf("ERRO !");
		return -1;
	}
	DTB[5] = NULL;
	HidePointer();
	textcolor(7); gotoxy(a + 45, 13); printf("                  ");
	return 1;
}
void Menu_ThemHS()
{
	int a = 50;
	/***************************************/
	/*Nhập Mã  Lớp*/
	textcolor(192);
	gotoxy(a, 5);
	ChayChu("    Ma Lop:     ");

	gotoxy(a + 17, 5);
	textcolor(255);
	printf("                       ");

	/*Nhập Mã  SV*/
	gotoxy(a, 7);
	textcolor(192);
	ChayChu("     MaSV:      ");

	gotoxy(a + 17, 7);
	textcolor(255);
	printf("                       ");

	/*Nhập Họ  Tên*/
	gotoxy(a, 9);
	textcolor(192);
	ChayChu("  Ho va Ten:    ");
	gotoxy(a + 17, 9);
	textcolor(255);
	printf("                       ");
	/*Nhập Ngày Sinh*/
	gotoxy(a, 11);
	textcolor(192);
	ChayChu("   Ngay Sinh:   ");
	gotoxy(a + 17, 11);
	textcolor(255);
	printf("                       ");
	/*Nhập Điểm TB*/
	gotoxy(a, 13);
	textcolor(192);
	ChayChu("Diem Trung Binh:");
	gotoxy(a + 17, 13);
	textcolor(255);
	printf("                       ");
	textcolor(7);
}
void ChuyenMauAddNew(int x)
{
	int a = 50;
	switch (x)
	{
	case 50:
		gotoxy(a, 20);
		textcolor(14);
		printf("Nhap Tiep (Enter)");
		gotoxy(a + 20, 20);
		textcolor(7);
		printf("Cancel(ESC)");
		break;
	case 65:
		gotoxy(a, 20);
		textcolor(7);
		printf("Nhap Tiep (Enter)");
		gotoxy(a+20, 20);
		textcolor(12);
		printf("Cancel(ESC)");
		break;
	}
}
void Ghifile(char *FileName, vector<HoSo> HS)
{
	FILE *fp;
	fp = fopen(FileName, "a+b");
	for (int unsigned i = 0; i < HS.size(); i++)
	{
		fwrite(&HS[i], sizeof(HoSo), 1, fp);
	}
	fclose(fp);
}
void EnterNumberClass()
{

}
/*----------Nhập---------------*/
void move(int &y, char &a)
{
	char c;
	c = _getch();
	if (c == 80) y++;
	if (c == 72) y--;
	if (c == 75) y = 6;
	if (c == 77) y = 7;
	if (c == 13 && y == 7) a = 27;
	if (c == 13 && y == 6) a = 13;
}
void  ThemMoi_Hs(char *FileName)
{
	vector<HoSo> HS;
	HoSo SV;
	int c, Nhap, x = 50, Dem = 1;
	do{
		int Err, Check = 0, a = 50, t = 0, y = 1;
		char b = 'a';
		char maLop[25] = "";
		char maSv[25] = "";
		char ten[50] = "";
		char NgaySinh[25] = "";
		char DTB[10] = "";

		gotoxy(55, 18); printf("Luu");
		gotoxy(70, 18); printf("Thoat");
		Menu_ThemHS();
		textcolor(7); gotoxy(a + 30, 3);
		printf("(Ban Dang Nhap Thong Tin HoSo: %d)", Dem);
		fflush(stdin);
		do
		{
			switch (y)
			{
			case 1:
				textcolor(249);
				EnterMaLop(maLop, strlen(maLop), y, a + 18 + strlen(maLop), 5, &Err);
				if (Err == -1)return;
				textcolor(7);
				break;
			case 2:
				textcolor(249);
				EnterMaSV(maSv, strlen(maSv), y, a + 18 + strlen(maSv), 7, &Err);
				if (Err == -1)return;
				textcolor(7);
				break;
			case 3:
				textcolor(249);
				EnterHoTen(ten, strlen(ten), y, a + 18 +strlen(ten), 9, &Err);
				if (Err == -1)return;
				textcolor(7);
				break;
			case 4:
				textcolor(249);
				EnterNgaySinh(NgaySinh, strlen(NgaySinh), y, a + 18 + strlen(NgaySinh), 11, &Err);
				if (Err == -1)return;
				textcolor(7);
				break;
			case 5:
				textcolor(249);
				EnterDiem(DTB, strlen(DTB), y, a + 18 + strlen(DTB), 13, &Err);
				if (Err == -1)return;
				textcolor(7);
				break;
			case 6:
				HidePointer();
				gotoxy(55, 18); textcolor(10); printf("Luu");
				move(y, b);
				gotoxy(55, 18); textcolor(15); printf("Luu");
				if (b == 13)
				{
					Check = BatLoi(FileName, maLop, maSv, ten, NgaySinh, DTB);
					if (Check == -1){ break; }
				}
				if (Check == 1){
					strcpy(SV.MaLop, maLop); strcpy(SV.MaSV, maSv); strcpy(SV.Hoten, ten);
					strcpy(SV.NgaySinh, NgaySinh); SV.DiemTB = (float)atof(DTB);
					HS.push_back(SV);
					Ghifile(FileName, HS);
					HS.clear();
					b = 27;
				}
				break;
			case 7:
				HidePointer();
				gotoxy(70, 18); textcolor(10); printf("Thoat");
				move(y, b);
				gotoxy(70, 18); textcolor(15); printf("Thoat");
				if (b == 27)
					return;
			}
			if (y > 7) y = 1;
			if (y < 1) y = 7;
			//////////
		} while (b != 27);
		gotoxy(a, 20);
		HidePointer();
		textcolor(14);
		printf("Nhap Tiep (Enter)");
		gotoxy(a + 20, 20);
		textcolor(7);
		printf("Cancel(ESC)");

		/* Phải là 77 Trái là  75  */
	
		while (1)
		{
			Nhap = _getch();
			switch (Nhap)
			{
			case 77:
				x -= 15; break;
			case 75:
				x += 15; break;
				/*--------------------Ấn Phím Delete ----------------------*/
			}
			if (Nhap == 13)
			{
				switch (x)
				{
				case 50:
					clrscr();
					Dem++;
					break;
				case 65:
					return;
				}
			}
			if ((x > 65)) x = 50;
			if ((x < 50)) x = 65;
			ChuyenMauAddNew(x);
			if (Nhap == 13) break;
		}
	} while (x == 50);
}