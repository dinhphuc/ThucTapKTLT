#include "console.h"

void ThongKe_MaLop(vector<HoSo> HS)
{
	Khung_PrintfTK("Ma Lop");
	int n = HS.size();
	SX_NoiBot_MaLop(HS, n);
	TK_Class a[100];
	int j = 0;
	a[j].MaLop = HS[0].MaLop;
	for (int i = 1; i < n; i++)
	{
		if (!strcmp(a[j].MaLop, HS[i].MaLop))
		{
			a[j].soluong++;
		}
		else
		{
			j++;
			a[j].MaLop = HS[i].MaLop;
		}
	}
	if (j == 0) (j = 1);
	int b = 7, next = 1;
	HidePointer();
	for (int i = 0; i <= j; i++)
	{
		gotoxy(60, b);
		printf("%s", a[i].MaLop);
		gotoxy(88, b);
		printf("%d", a[i].soluong);
		b += 2;
		if (i + 1 == 10 * next)
		{
			next++;
			_getch();
			clrscr();
			Khung_PrintfTK("Ma Lop");
			b = 7;
		}
		gotoxy(88, 28);
		printf("Next (Enter)");
		if (j == 1)break;
	}
}
void ThongKe_Point(vector<HoSo> HS)
{
	Khung_PrintfTK("Diem TB");
	int n = HS.size();
	SX_NoiBot_DiemTB(HS, n);
	TK_Point a[100];
	int j = 0;
	a[j].Point = HS[0].DiemTB;
	for (int i = 1; i < n; i++)
	{
		if (a[j].Point == HS[i].DiemTB)
		{
			a[j].soluong++;
		}
		else
		{
			j++;
			a[j].Point = HS[i].DiemTB;
		}
	}
	if (j == 0) (j = 1);
	int b = 7;
	int next = 1;
	HidePointer();
	for (int i = 0; i <= j; i++)
	{
		gotoxy(65, b);
		printf("%0.2f", a[i].Point);
		gotoxy(88, b);
		printf("%d", a[i].soluong);
		b += 2;
		if (i + 1 == 10 * next)
		{
			next++;
			_getch();
			clrscr();
			Khung_PrintfTK("Diem TB");
			b = 7;
		}
		gotoxy(88, 28);
		printf("Next (Enter)");
		if (j == 1)break;
	}
}
/*----------Đếm SV theo Điểm---------------*/
int SoSVGioi(vector <HoSo>HS, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (HS[i].DiemTB >= 8){ count++; }
	}return count;
}
int SoSVKha(vector <HoSo>HS, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((HS[i].DiemTB < 8) && ((HS[i].DiemTB >= 6.5))){ count++; }
	}return count;
}
int SoSVTB(vector <HoSo>HS, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((HS[i].DiemTB < 6.5) && ((HS[i].DiemTB >= 4))){ count++; }
	}
	return count;
}
int SoSVYeu(vector <HoSo>HS, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((HS[i].DiemTB < 4))	{ count++; }
	}return count;
}
void TK_Diem_color(int ToaDo)
{
	switch (ToaDo)
	{
	case 18:
		textcolor(14);
		gotoxy(50, 18);
		printf("Xem Bieu Do");
		textcolor(15);
		gotoxy(60, 20);
		printf("-Thoat-");
		break;
	case 20:
		textcolor(15);
		gotoxy(50, 18);
		printf("Xem Bieu Do");
		textcolor(12);
		gotoxy(60, 20);
		printf("-Thoat-");
		break;
	}
}
void TK_Diem(char *Loai, int loaiSV, vector <HoSo> HS, char *FileName, int n)
{
	int tongSv = n;
	int c; int y = 18; int x = 50;
	textcolor(480);
	gotoxy(45, 4);
	printf("Ti Le SV %s", Loai);
	textcolor(15);
	gotoxy(60, 6);
	printf("Tong So SV Trong Danh Sach: %d", tongSv);
	gotoxy(45, 12);
	printf("*So Luong SV %s : %d", Loai, loaiSV);
	gotoxy(45, 14);
	printf("*Chiem Ti Le : %3.2f  %%", (loaiSV / (float)tongSv) * 100);
	gotoxy(50, 18);
	printf("Xem Bieu Do");
	gotoxy(60, 20);
	printf("-Thoat-");
	TK_Diem_color(18);
	while (1)
	{
		c = _getch();
		switch (c)
		{
		case 80:
			y += 2;
			break;
		case 72:
			y -= 2;
			break;
		}
		if (c == 13)
		{
			switch (y)
			{
			case 18:
				clrscr();
				Khung_BieuDo(HS, n);
				_getch();
				clrscr();
				TK_Diem(Loai, loaiSV, HS, FileName, n);
				return;
				break;
			case 20:
				clrscr();
				return;
				break;
			}
		}
		if (y > 20)	y = 18;
		if (y < 18) y = 20;
		TK_Diem_color(y);
		gotoxy(x, y);
	}
}
/*----------main Thống Kê--------------*/
void menu1z()
{
	int a = 45;
	gotoxy(a, 8); ChayChu("1. Bao Cao So Luong SV Theo Lop");
	gotoxy(a, 10); ChayChu("2. Thong Ke Xep Loai SV");
	gotoxy(a, 12); ChayChu("3. Bao Cao So Luong SV Theo Diem");
	gotoxy(a + 5, 14); ChayChu("-Thoat-");
}
void Menu_ThongKe_DoiMau1(int ToaDo)
{
	int a = 45;
	switch (ToaDo)
	{

	case 8:
		textcolor(14);
		gotoxy(a, 8); printf("1. Bao Cao So Luong SV Theo Lop");
		textcolor(7);
		gotoxy(a, 12); printf("3. Bao Cao So Luong SV Theo Diem");
		gotoxy(a, 10); printf("2. Thong Ke Xep Loai SV");
		gotoxy(a + 5, 14); printf("-Thoat-");
		break;
	case 10:
		textcolor(14);
		gotoxy(a, 10); printf("2. Thong Ke Xep Loai SV");
		textcolor(7);
		gotoxy(a, 8); printf("1. Bao Cao So Luong SV Theo Lop");
		gotoxy(a, 12); printf("3. Bao Cao So Luong SV Theo Diem");
		gotoxy(a + 5, 14); printf("-Thoat-");
		break;
	case 12:
		textcolor(14);
		gotoxy(a, 12); printf("3. Bao Cao So Luong SV Theo Diem");
		textcolor(7);
		gotoxy(a + 5, 14); printf("-Thoat-");
		gotoxy(a, 10); printf("2. Thong Ke Xep Loai SV");
		gotoxy(a, 8); printf("1. Bao Cao So Luong SV Theo Lop");
		break;
	case 14:
		textcolor(12);
		gotoxy(a + 5, 14); printf("-Thoat-");
		textcolor(7);
		gotoxy(a, 8); printf("1. Bao Cao So Luong SV Theo Lop");
		gotoxy(a, 10); printf("2. Thong Ke Xep Loai SV");
		gotoxy(a, 12); printf("3. Bao Cao So Luong SV Theo Diem");
		break;
	}
}
void Menu_ThongKe_DoiMau2(int Toado)
{
	int a = 85;
	gotoxy(a, 8); printf("Thong Ke Ti Le SV Gioi");
	gotoxy(a, 10); printf("Thong Ke Ti Le SV Kha");
	gotoxy(a, 12); printf("Thong Ke Ti Le SV Trung Binh");
	gotoxy(a, 14); printf("Thong Ke Ti Le SV yeu");
	gotoxy(a + 5, 16); printf("-Thoat-");
	////////////////////////////////////////////////////////////////
	for (int i = 3; i < 30; i++)
	{
		gotoxy(80, i); printf("%c", 186);
	}
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	gotoxy(80, 2);
	printf("%c", 203);
	gotoxy(80, 30);
	printf("%c", 202);
	///////////////////////////////////////////////////////////////
	switch (Toado)
	{
	case 8:
		textcolor(14);
		gotoxy(a, 8); printf("Thong Ke Ti Le SV Gioi");
		textcolor(7);
		break;
	case 10:
		textcolor(14);
		gotoxy(a, 10); printf("Thong Ke Ti Le SV Kha");
		textcolor(7);
		break;
	case 12:
		textcolor(14);
		gotoxy(a, 12); printf("Thong Ke Ti Le SV Trung Binh");
		textcolor(7);
		break;
	case 14:
		textcolor(14);
		gotoxy(a, 14); printf("Thong Ke Ti Le SV yeu");
		textcolor(7);
		break;
	case 16:
		textcolor(14);
		gotoxy(a + 5, 16); printf("-Thoat-");
		textcolor(7);
		break;
	}
}
void Main_con_ThongKe(vector<HoSo> HS, char* FileName, int n)
{
	int x = 0, y = 0, c;
	x = 40, y = 8;
	Menu_batPhim(9);
	Menu_ThongKe_DoiMau2(8);
	while (1)
	{
		c = _getch();
		switch (c)
		{
		case 80:
			y += 2;
			break;
		case 72:
			y -= 2;
			break;
		case 27:
			int Err; checkExit(&Err, "Exit"); if (Err == -1){ clrscr(); return; }
			else{ clrscr(); Menu_ThongKe_DoiMau1(10); Menu_ThongKe_DoiMau2(y); break; }
		}
		if (c == 13)
		{
			switch (y)
			{
			case 8:
				clrscr();pain();
				TK_Diem("Gioi", SoSVGioi(HS, n), HS, FileName, n);
				Menu_ThongKe_DoiMau1(10);
				break;
			case 10:
				clrscr();pain();
				TK_Diem("Kha", SoSVKha(HS, n), HS, FileName, n);
				Menu_ThongKe_DoiMau1(10);
				break;
			case 12:
				clrscr();
				pain();
				TK_Diem("Trung Binh", SoSVTB(HS, n), HS, FileName, n);
				Menu_ThongKe_DoiMau1(10);
				break;
			case 14:
				clrscr();pain();
				TK_Diem("Yeu", SoSVYeu(HS, n), HS, FileName, n);
				Menu_ThongKe_DoiMau1(10);
				break;
			case 16:
				pain();clrscr();
				return;
			}
		}
		if (y > 16)	y = 8;
		if (y < 8) y = 16;
		Menu_ThongKe_DoiMau2(y);
		gotoxy(x, y);
	}
}
void Main_ThongKe(vector <HoSo> HS, char* FileName, int n)
{
	int tongSv = HS.size();
	if (tongSv == 0){dialogNull();return;}
	HidePointer();
	{
		int x = 0, y = 0, c;
		x = 40, y = 8;
		Menu_batPhim(9);menu1z();Menu_ThongKe_DoiMau1(8);
		while (1)
		{
			fflush(stdin);
			c = _getch();
			switch (c)
			{
			case 80:
				y += 2;
				break;
			case 72:
				y -= 2;
				break;
			case 27:
				int Err; checkExit(&Err, "Exit"); if (Err == -1){ clrscr(); return; }
				else{ clrscr(); pain(); Menu_ThongKe_DoiMau1(y); break; }
			}
			if (c == 13)
			{
				switch (y)
				{
				case 8:
					clrscr();
					ThongKe_MaLop(HS);
					_getch();
					clrscr();
					break;
				case 10:
					Main_con_ThongKe(HS, FileName, n);
					break;
				case 12:
					clrscr();
					ThongKe_Point(HS);
					_getch();
					clrscr();
					break;
				case 14:
					clrscr();
					pain();
					return;
					break;
				}
			}
			if (y > 14)	y = 8;
			if (y < 8) y = 14;
			Menu_ThongKe_DoiMau1(y);
			gotoxy(x, y);
		}
	}
}
/*----------Biểu đồ---------------*/
void xuly_BieuDo(vector <HoSo>HS, int n)
{
	float pt_gioi, pt_kha, pt_tb, pt_yeu;
	pt_gioi = ((float)SoSVGioi(HS, n) / n) * 100;
	pt_kha = ((float)SoSVKha(HS, n) / n) * 100;
	pt_tb = ((float)SoSVTB(HS, n) / n) * 100;
	pt_yeu = ((float)SoSVYeu(HS, n) / n) * 100;
	int Tang = 24;
	///Yeues
	textcolor(12);
	for (float j = 0; j < pt_yeu; (float)(j += 6))
	{
		gotoxy(59, Tang);printf("%c%c%c", 178, 178, 178);
		Tang -= 1;
	}
	textcolor(7);
	gotoxy(58, Tang);printf("%0.2f%%", pt_yeu);
	///Tb
	Tang = 24;
	textcolor(8);
	for (float j = 0; j < pt_tb; (float)(j += 5.5))
	{
		gotoxy(71, Tang);printf("%c%c%c", 178, 178, 178);
		Tang -= 1;
	}textcolor(7);
	gotoxy(70, Tang);printf("%0.2f%%", pt_tb);
	///Kha
	textcolor(14);
	Tang = 24;
	for (float j = 0; j < pt_kha; (float)(j += 5.5))
	{
		gotoxy(83, Tang);printf("%c%c%c", 178, 178, 178);
		Tang -= 1;
	}textcolor(7);
	gotoxy(82, Tang);printf("%0.2f%%", pt_kha);
	///Gioi
	textcolor(9);
	Tang = 24;
	for (float j = 0; j < pt_gioi; (float)(j += 5.5))
	{
		gotoxy(95, Tang);printf("%c%c%c", 178, 178, 178);
		Tang -= 1;
	}textcolor(7);
	gotoxy(94, Tang);printf("%0.2f%%", pt_gioi);
}
void Khung_BieuDo(vector <HoSo>HS, int n)
{
	pain();
	gotoxy(50, 4);printf("^");
	gotoxy(47, 3);printf("(%%)");
	gotoxy(50, 25);printf("%c", 192);
	for (int i = 51; i < 110; i++){
		gotoxy(i, 25);printf("%c", 196);
	}
	for (int i = 5; i < 25; i++){
		gotoxy(50, i);printf("%c", 179);
	}
	gotoxy(108, 26);printf("(Type)");
	gotoxy(110, 25);printf(">");
	for (int i = 60; i < 100; i = i + 12)
	{
		gotoxy(i, 25);
		printf("%c", 193);
		if (i == 60){
			gotoxy(i - 1, 26);printf("Yeu");
		}
		if (i == 72)
		{
			gotoxy(i, 26);printf("TB");
		}
		if (i == 84)
		{
			gotoxy(i - 1, 26);printf("Kha");
		}
		if (i == 96)
		{
			gotoxy(i - 1, 26);printf("Gioi");
		}
	}
	int PhanTram = 100;
	for (int i = 5; i < 25; i = i + 4)
	{
		gotoxy(50, i);printf("%c", 197);// ống Cộng
		gotoxy(46, i);printf("%d%%", PhanTram);
		PhanTram -= 20;
	}
	gotoxy(47, 25); printf("0%%");
	gotoxy(65, 28);printf("Bieu Do Thong Ke Hoc Luc SV");
	xuly_BieuDo(HS, n);
}