#define _CRT_SECURE_NO_WARNINGS
#include "Console.h"
#include <conio.h>

void Khung_checkFile(char *Xau)
{
	char unsigned c = 205;  //ống Ngang
	char unsigned d = 186;  // ống dọc
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái dưới
	char unsigned c3 = 187; // góc phải trên 
	char unsigned c4 = 188; // góc phải dưới
	char unsigned c5 = 202; // Ống căm lên
	char unsigned c6 = 203; // ống cắm xuống
	

	gotoxy(0, 0);
	int i,t=0;
	textcolor(14);
	gotoxy(52, 7);
	ChayChu("Nhap Vao "); printf("%s", Xau);
	textcolor(7);
	//Ống Bên Chiều Dài Trên t
	for (i = 35; i < 85; i++)
	{
		gotoxy(i, 8);
		printf("%c", c);

	}
	gotoxy(35, 8); printf("%c", c1);
	gotoxy(85, 8); printf("%c", c3);
	//Ống Bên Chiều Dài Dưới 
	for (i = 35; i < 85; i++)
	{
		gotoxy(i, 10);
		printf("%c", c);
	}
	gotoxy(35, 8); printf("%c", c1);
	gotoxy(85, 8); printf("%c", c3);
	/// Ống Bên Chiều rộng
	for (i = 9; i < 10; i++)
	{
		gotoxy(35, i);
		printf("%c", d);

	}
	for (i = 9; i < 10; i++)
	{
		gotoxy(85, i);
		printf("%c", d);
	}
	gotoxy(35, 10); printf("%c", c2);
	gotoxy(85, 10); printf("%c", c4);
}
int checkFile(char *Filename)
{
	int Err,t=0;
	Khung_checkFile("Ten File: ");
	do{
		EnterNameFile(Filename, 0, 50, 9, &Err);
		if (Err == -1)
		{
			HidePointer();
			textcolor(7);
			gotoxy(50, 15);
			printf("SET File Default DSSV.kBz");
			strcpy(Filename, "DSSV.kBz");
			_getch();
			ShowPointer();
			return 0;
		}
		if (strlen(Filename) <= 0)
		{
			textcolor(12);
			gotoxy(54, 11);
			ChayChu("ERRO ! Empty ");
		}
	} while (strlen(Filename) <= 0);
	textcolor(7);
	gotoxy(52, 11);
	printf("                        ");
	return 1;
}
void colorMain_Extra(int toado)
{
	switch (toado)
	{
	case 11:
		gotoxy(48, 11); textcolor(14); printf("1. Type DataBase Default");
		gotoxy(48, 13); textcolor(7); printf("2. DataBase Existing");
		gotoxy(48, 15); textcolor(7); printf("3. Create New DataBase");
		gotoxy(48, 17); textcolor(7); printf(" \tExit");
		break;
	case 13:
		gotoxy(48, 11); textcolor(7); printf("1. Type DataBase Default");
		gotoxy(48, 13); textcolor(14); printf("2. DataBase Existing");
		gotoxy(48, 15); textcolor(7); printf("3. Create New DataBase");
		gotoxy(48, 17); textcolor(7); printf(" \tExit");
		break;
	case 15:
		gotoxy(48, 11); textcolor(7); printf("1. Type DataBase Default");
		gotoxy(48, 13); textcolor(7); printf("2. DataBase Existing");
		gotoxy(48, 15); textcolor(14); printf("3. Create New DataBase");
		gotoxy(48, 17); textcolor(7); printf(" \tExit");
		break;
	case 17:
		gotoxy(48, 11); textcolor(7); printf("1. Type DataBase Default");
		gotoxy(48, 13); textcolor(7); printf("2. DataBase Existing");
		gotoxy(48, 15); textcolor(7); printf("3. Create New DataBase");
		gotoxy(48, 17); textcolor(12); printf(" \tExit");
		break;
	}
}
void MenuMainExTra()
{
	FrameGioiThieu();
	gotoxy(0, 0);
	gotoxy(37, 1); textcolor(9);
	ChayChu("---------------------------------------------------");
	gotoxy(46, 5); textcolor(14); ChayChu("CHUONG TRINH QUAN LY HOC VIEN");
	gotoxy(52, 9); textcolor(9); ChayChu("Select DataBase");
	gotoxy(48, 11); textcolor(7); ChayChu("1. Type DataBase Default");
	gotoxy(48, 13); textcolor(7); ChayChu("2. DataBase Existing");
	gotoxy(48, 15); textcolor(7); ChayChu("3. Create New DataBase");
	gotoxy(48, 17); textcolor(7); ChayChu(" \tExit");
	gotoxy(36, 20); textcolor(12); ChayChu("Ctrl+I :"); textcolor(7); ChayChu(" Setting ");
	gotoxy(55, 20); textcolor(12); ChayChu("Ctrl+H :"); textcolor(7); ChayChu(" Help ");
	gotoxy(70, 20); textcolor(12); ChayChu("Ctrl+A :"); textcolor(7); ChayChu(" About");
	textcolor(7);
}
void Main_Extra(char FileName[], int *type)
{
	HidePointer();
	MenuMainExTra();
	char defaultNameFile[30] ;
	/*------------------------------*/
	int x = 0, y = 0, c;
	 y = 11;
	 colorMain_Extra(11);
	while (1)
	{	
		fflush(stdin);
		c = _getch();
		switch (c)
		{
		case 80:
			y+=2;
			break;
		case 72: 
			y-=2;
			break;
		case 9: // setting
			textcolor(7);
			system("cls");
			FrameGioiThieu();
			setting(defaultNameFile);
			system("cls");
			MenuMainExTra();
			break;
		case 8:// help
			system("cls");
			FrameGioiThieu();
			Help();
			system("cls");
			MenuMainExTra();
			break;
		case 1:// about
			system("cls");
			GioiThieu();
			_getch();
			system("cls");
			MenuMainExTra();
			break;
		}
		if (c == 13)
		{
			switch (y)
			{
			case 11:			
				clrscr();
				GetNameDefault(defaultNameFile);
				strcpy(FileName,defaultNameFile);
				*type = 1;
				return;
			case 13:
				//system("WFN8_1.exe");
				clrscr();
				strcpy(FileName, FileName);
				checkFile(FileName);
				*type = 2;

				return;
			case 15:
				clrscr();
				strcpy(FileName, FileName);
				checkFile(FileName);	
				*type = 3;
				return;
			case 17:
				clrscr();
				*type = 4;
				return;
				break;
			}
		}
		if (y > 17)	y = 11;
		if (y < 11) y = 17;
		colorMain_Extra(y);
	}
	ShowPointer();
}
void Menu()
{
	int a = 5;
	system("cls");
	pain();
	gotoxy(a + 6, 3);
	textcolor(252);
	printf("***MENU***");
	textcolor(7);
	//	textcolor(14);
	gotoxy(a, 5);
	ChayChu("1. Them Moi Ho So");
	gotoxy(a, 6);
	ChayChu("2. In Danh Sach");
	gotoxy(a, 7);
	ChayChu("3. Sap Xep");
	gotoxy(a, 8);
	ChayChu("4. Tim Kiem");
	gotoxy(a, 9);
	ChayChu("5. Thong Ke");
	gotoxy(a, 10);
	ChayChu("6. Thoat");
	gotoxy(a, 5);
}
void Menu_batPhim(int Toado)
{
	int a = 5;
	//	XoaManHinh();
	//	pain();
	gotoxy(a + 6, 3);
	textcolor(415);
	printf("***MENU***");
	textcolor(7);
	gotoxy(a, 5);
	printf("1. Them Moi Ho So");
	gotoxy(a, 6);
	printf("2. In Danh Sach");
	gotoxy(a, 7);
	printf("3. Sap Xep");
	gotoxy(a, 8);
	printf("4. Tim Kiem");
	gotoxy(a, 9);
	printf("5. Thong Ke");
	gotoxy(a, 10);
	printf("6. Thoat");
	gotoxy(a, 5);

	switch (Toado)
	{
	case 5:
		textcolor(14);
		gotoxy(a, 5);
		printf("1. Them Moi Ho So");
		textcolor(7);
		break;
	case 6:
		textcolor(14);
		gotoxy(a, 6);
		printf("2. In Danh Sach");
		textcolor(7);
		break;
	case 7:

		textcolor(14);
		gotoxy(a, 7);
		printf("3. Sap Xep");
		textcolor(7);
		break;
	case 8:
		textcolor(14);
		gotoxy(a, 8);
		printf("4. Tim Kiem");
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9);
		printf("5. Thong Ke");
		textcolor(7);
		break;
	case 10:
		textcolor(12);
		gotoxy(a, 10);
		printf("6. Thoat");
		textcolor(7);
		break;
	}

}
/*------------------------*/
void ChuyenControUpDown(int *ToaDo, int Trang, int trangcuoi, int *Oy)
{
	int x, y, c;
	x = 36, y = 7;
	gotoxy(x, y);
	printf("=>");
	int i = 0;
	while (1)
	{

		fflush(stdin);
		c = _getch();
		switch (c)
		{
		case 80:
			if (y == 25)
			{
				y += 3;
				gotoxy(x, y - 3);
				printf("  ");
				textcolor(12);
				gotoxy(43, 28);
				printf("Cancel");
			}
			else
			{
				y += 2;
				gotoxy(x, y - 2);
				printf("  ");
				textcolor(7);
				gotoxy(43, 28);
				printf("Cancel");
			}

			break;
		case 72:
			if (y == 28)
			{
				y -= 3;
				gotoxy(x, y + 3);
				printf("  ");
				textcolor(7);
				gotoxy(43, 28);
				printf("Cancel");
			}
			else
			{
				if (y == 7)
				{
					textcolor(12);
					gotoxy(43, 28);
					printf("Cancel");
				}
				y -= 2;
				gotoxy(x, y + 2);
				printf("  ");
			}
		}
		if (c == 13)
		{
			switch (y)
			{
			case 7:
				*ToaDo = (10 * Trang + 1);
				*Oy = y;
				break;
			case 9:
				*ToaDo = (10 * Trang + 2);
				*Oy = y;
				break;
			case 11:
				*ToaDo = (10 * Trang + 3);
				*Oy = y;
				break;
			case 13:
				*ToaDo = (10 * Trang + 4);
				*Oy = y;
				break;
			case 15:
				*ToaDo = (10 * Trang + 5);
				*Oy = y;
				break;
			case 17:
				*ToaDo = (10 * Trang + 6);
				*Oy = y;
				break;
			case 19:
				*ToaDo = (10 * Trang + 7);
				*Oy = y;
				break;
			case 21:
				*ToaDo = (10 * Trang + 8);
				*Oy = y;
				break;
			case 23:
				*ToaDo = (10 * Trang + 9);
				*Oy = y;
				break;
			case 25:
				*ToaDo = (10 * Trang + 10);
				*Oy = y;
				break;
			case 28:
				*ToaDo = -1;
				break;
			}
		}
		//// trang cuối n/10+1
		if (y > 28)	y = 7;
		if (y < 7) y = 28;
		gotoxy(x, y);
		printf("=>");
		if (c == 13) break;

	}
}
void ChuyenControLeftRight(int *ToaDoOx, int *Ox, int Oy)
{
	//int *ToaDo, int Trang, int trangcuoi
	int x, y, c;
	x = 45, y = Oy;
	int i = 0;
	gotoxy(x, y);
	printf("*");
	while (1)
	{
		fflush(stdin);
		c = _getch();
		switch (c)
		{
		case 77:
			if (x == 58){ x += 11; gotoxy(x - 11, y); printf(" "); break; }
			if (x == 69){ x += 24; gotoxy(x - 24, y); printf(" "); break; }
			if (x == 93){ x += 17; gotoxy(x - 17, y); printf(" "); break; }
			{x += 13; gotoxy(x - 13, y); printf(" "); }
			break;
		case 75:
			if (x == 69){ x -= 11; gotoxy(x + 11, y); printf(" "); break; }
			if (x == 93){ x -= 24; gotoxy(x + 24, y); printf(" "); break; }
			if (x == 110){ x -= 17; gotoxy(x + 17, y); printf(" "); break; }
			{x -= 13; gotoxy(x + 13, y); printf(" "); }
			break;
		case 27:
		{
				   return;
		}
		}
		if (c == 13)
		{
			switch (x)
			{
			case 45:
				*ToaDoOx = 1;
				*Ox = x;
				break;
			case 58:
				*ToaDoOx = 2;
				*Ox = x;
				break;
			case 69:
				*ToaDoOx = 3;
				*Ox = x;
				break;
			case 93:
				*ToaDoOx = 4;
				*Ox = x;
				break;
			case 110:
				*ToaDoOx = 5;
				*Ox = x;
				break;
			}
		}
		if (x > 110) x = 45;
		if (x < 45) x = 110;
		gotoxy(x, y);
		printf("*");
		if (c == 13) break;

	}
}
/*--------MAIN---------*/
void main()
{
	vector <HoSo> HS;
	char FileName[50];
	int type, Err;
	Main_Extra(FileName, &type);
	if (type == 3)UpdateFile(FileName, HS);
	if (type == 4)
	{
		HidePointer();
		textcolor(12);
		gotoxy(50, 9 + 2);
		ChayChu("Press [Enter] to accept Exit");
		textcolor(14);
		gotoxy(50 + 5, 10 + 3);
		ChayChu("OR [ESC] to Cancel");
		char c = _getch();
		if (c == 13)Err = -1;
		textcolor(7);
		ShowPointer();
		if (Err == -1)
		{
			END();
			_getch();
			return;
		}
		if (c == 27)
		{
			system("cls");
			HidePointer();
			main();
		}
	}
	HS = input(FileName);
	int n = HS.size();
	HidePointer();
	Menu();
	// Bắt Phím
	{
		int x = 0, y = 0, c;
		x = 5, y = 5;
		Menu_batPhim(5);
		while (1)
		{
			fflush(stdin);
			c = _getch();
			switch (c)
			{
			case 80:
				y++;
				break;
			case 72:
				y--;
				break;
			case 27:
				int Err;
				checkExit(&Err, "Exit");
				if (Err == -1)
				{
					END();
					_getch();
					return;
				}
				else
				{
					XoaCheckExit();
					HidePointer();
					break;
				}
			}
			if (c == 13)
			{
				switch (y)
				{
				case 5:
					//themhs();
					ThemMoi_Hs(FileName);
					clrscr();
					break;
				case 6:
					clrscr();
					HS = input(FileName);
					OutPut(HS, FileName,0, HS.size());
					InFile(HS, "DanhSachSV.txt");
					clrscr();
					break;
				case 7:
					HS = input(FileName);
					MainSapxep(HS, FileName);
					break;
				case 8:
					HS = input(FileName);
					MainSearch(HS, FileName, HS.size());
					break;
				case 9:
					HS = input(FileName);
					Main_ThongKe(HS, FileName, HS.size());
					break;
				case 10:
					int Err;
					checkExit(&Err, "Exit");
					if (Err == -1)
					{
						END();
						_getch();
						return;
					}
					else
					{
						XoaCheckExit();
						HidePointer();
						break;
					}
				}
			}
			if (y > 10)	y = 5;
			if (y < 5) y = 10;
			Menu_batPhim(y);
			gotoxy(x, y);
		}
	}
}