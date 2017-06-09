#include "Console.h"
#define Console_Dai 120
#define Console_Rong 28
void GetNameDefault(char *NameFile)
{
	FILE *f;
	f = fopen("keyFile.key", "r");
	if (f == NULL || feof(f))
	{
		strcpy(NameFile, "DSSV.kBz");
	}
	else
	{
		fgets(NameFile, 100, f);	fclose(f);
	}
}
void SettingDefaulNameFile(char *NameFile)
{
	FrameGioiThieu();
	gotoxy(35, 1); textcolor(9); ChayChu("---------------------------------------------------");
	gotoxy(46, 5); textcolor(14); ChayChu("CHUONG TRINH QUAN LY HOC VIEN");
	gotoxy(50, 14); textcolor(12); ChayChu("Setting default File Name");
	FILE *f;
	checkFile(NameFile);
	f = fopen("keyFile.key", "w");
	fprintf(f, "%s", NameFile);
	fclose(f);
}

void SetRunKey()
{
	ShowPointer();
	int n, err, t = 0;
	char Run[10];
	gotoxy(68, 11); printf("Enter value: ");
	EnterDiem(Run, 0, t, 85, 11, &err);
	if (err == -1)return;
	FILE *f;
	f = fopen("keyRun.key", "w");
	n = atoi(Run);
	fprintf(f, "%d", n);
	fclose(f);
	HidePointer();
}
void ChayChu(char *xau)
{
	int n;
	FILE *f;
	f = fopen("keyRun.key", "r");
	if (f == NULL){ n = 30; }
	else
	{
		char c = fgetc(f);
		if (feof(f))n = 30;
		else
		{
			rewind(f);
			fscanf(f, "%d", &n);
		}
		fclose(f);
	}
	for (int i = 0; i < strlen(xau); i++)
	{
		printf("%c", xau[i]);
		Sleep(n);
		if (_kbhit()) n = 0;
	}

}


void colorSetting(int toado)
{
	switch (toado)
	{
	case 11:
		gotoxy(48, 11); textcolor(14); printf("1. Set Run text");
		gotoxy(48, 13); textcolor(7); printf("2. set Name File Default");
		gotoxy(55, 15); textcolor(7); printf("Exit ");
		break;
	case 13:
		gotoxy(48, 11); textcolor(7); printf("1. Set Run text");
		gotoxy(48, 13); textcolor(14); printf("2. set Name File Default");
		gotoxy(55, 15); textcolor(7); printf("Exit ");
		break;
	case 15:
		gotoxy(48, 11); textcolor(7); printf("1. Set Run text");
		gotoxy(48, 13); textcolor(7); printf("2. set Name File Default");
		gotoxy(55, 15); textcolor(12); printf("Exit "); textcolor(7);
		break;
	}
}

void MenuSetting()
{
	gotoxy(55, 5); textcolor(14); ChayChu("Setting");
	gotoxy(52, 9); textcolor(12); ChayChu("Select Setting");
	gotoxy(48, 11); textcolor(14); ChayChu("1. Set Run text");
	gotoxy(48, 13); textcolor(7); ChayChu("2. set Name File Default");
	gotoxy(55, 15); textcolor(7); ChayChu("Exit ");
}
void setting(char *NameFile)
{
	HidePointer(); textcolor(7); MenuSetting();
	int x = 0, y = 0, c;
	y = 11;
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
			return;
		}
		if (c == 13)
		{
			switch (y)
			{
			case 11:
				SetRunKey();
				clrscr();
				return;
			case 13:
				system("cls");
				FrameGioiThieu();
				SettingDefaulNameFile(NameFile);
				system("cls");
				return;
			case 15:
				return;
			}
		}
		if (y > 15)	y = 11;
		if (y < 11) y = 15;
		colorSetting(y);
	}
	textcolor(7);
	ShowPointer();
}

// ẩn  con trỏ
void HidePointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// Hiện Con Trỏ
void ShowPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void textbackground(WORD color) // màu nền
{

	HANDLE hconsolerOutput;
	hconsolerOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hconsolerOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;
	SetConsoleTextAttribute(hconsolerOutput, wAttributes);

}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void pain()  // tạo khung chương trình
{
	textcolor(7);
	char unsigned c = 205;  //ống Ngang
	char unsigned d = 186;  // ống dọc
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái dưới
	char unsigned c3 = 187; // góc phải trên 
	char unsigned c4 = 188; // góc phải dưới
	char unsigned c5 = 202; // Ống căm lên
	char unsigned c6 = 203; // ống cắm xuống
	char unsigned c7 = 206; // ống Dấu cộng
	gotoxy(0, 0);
	int i;
	//Ống Bên Chiều Dài Trên 
	for (i = 2; i < Console_Dai; i++)
	{
		gotoxy(i, 2); printf("%c", c);
	}
	gotoxy(1, 2); printf("%c", c1);
	gotoxy(120, 2); printf("%c", c3);
	gotoxy(35, 2); printf("%c", c6);
	textcolor(14);
	gotoxy(50, 1); printf("CHUONG TRINH QUAN LY HOC VIEN");
	textcolor(7);
	//Ống bên Chiều dài dưới
	for (i = 2; i <= Console_Dai; i++)
	{
		gotoxy(i, 30); printf("%c", c);
		if (i == 35)
		{
			gotoxy(i, 30); printf("%c", c5);
		}
		else if (i == 120)
		{
			gotoxy(1, 30); printf("%c", c2);
			//break;
		}
		if (i == 120)
		{
			gotoxy(i, 30); printf("%c", c4); break;
		}
	}
	// Ống Bên Chiều rộng
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(1, i); printf("%c", 178);
	}
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(120, i); printf("%c", 178);
	}
	// Ống Giữa
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(35, i); printf("%c", d);
	}
	gotoxy(1, 1);
}
void FrameGioiThieu()
{
	// Ve Khung Gioi Thieu
	char unsigned c = 205;  //ống Ngang
	char unsigned d = 186;  // ống dọc
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái dưới
	char unsigned c3 = 187; // góc phải trên 
	char unsigned c4 = 188; // góc phải dưới
	char unsigned c5 = 202; // Ống căm lên
	char unsigned c6 = 203; // ống cắm xuống
	char unsigned c7 = 206; // ống Dấu cộng
	gotoxy(0, 0);
	int i;
	textbackground(0);
	//dài trên
	for (i = 0; i < Console_Dai - 2; i++)
	{
		if (i == 0)
		{
			gotoxy(i, 0); printf("%c", c1);
		}
		gotoxy(i, 0); printf("%c", c);
		if (i == 117)
		{
			gotoxy(i, 0); printf("%c", c3); break;
		}
	}
	// dài dưới
	for (i = 0; i <= Console_Dai; i++)
	{
		gotoxy(i, 30); printf("%c", c);
		if (i == 120)
		{
			gotoxy(1, 30); printf("%c", c2);
		}
		if (i == 120)
		{
			gotoxy(i, 30); printf("%c", c4); break;
		}
	}
	// RONG
	for (i = 2; i < Console_Rong + 2; i++)
	{
		gotoxy(1, i); printf("%c", d);
	}

	for (i = 2; i < Console_Rong + 2; i++)
	{
		gotoxy(120, i); printf("%c", d);
	}
	gotoxy(0, 0);
}
void GioiThieu()
{
	int i, slep = 20;
	FrameGioiThieu();
	gotoxy(1, 1);
	char s1[] = "THUC TAP KI THUAT LAP TRINH";
	int a = (Console_Dai - 2 - strlen(s1)) / 2;
	textcolor(14);
	gotoxy(a, 4);
	for (unsigned i = 0; i < strlen(s1); i++)
	{
		printf("%c", s1[i]);
		Sleep(slep);
	}
	textcolor(7); gotoxy(a - 10, 6);
	printf("**************************************************");
	char s2[] = "Full Name :	  NGO DINH PHUC";
	char s3[] = "Class:	  KTPM-K14";
	char s4[] = "Student code:  15150178";
	textcolor(7);

	for (i = 39; i < 80; i++)
	{
		gotoxy(i, 12); printf("%c", 178); Sleep(slep);
	}
	for (i = 13; i < 21; i++)
	{
		gotoxy(39, i); printf("%c", 178); gotoxy(40, i); printf("%c", 178); Sleep(slep);
	}
	// dài dưới
	for (i = 39; i < 80; i++)
	{
		gotoxy(i, 20); printf("%c", 178); Sleep(slep);
	}
	// //RONG
	for (i = 12; i < 21; i++)
	{
		gotoxy(79, i); printf("%c", 178); gotoxy(80, i); printf("%c", 178); Sleep(slep);
	}
	textcolor(12); gotoxy(44, 15);
	for (unsigned i = 0; i < strlen(s2); i++)
	{
		printf("%c", s2[i]); Sleep(100);
	}
	gotoxy(44, 16);
	for (unsigned i = 0; (i < strlen(s3)); i++)
	{
		printf("%c", s3[i]); Sleep(slep);
	}
	gotoxy(44, 17);
	for (unsigned i = 0; i < strlen(s4); i++)
	{
		printf("%c", s4[i]); Sleep(slep);
	}
	textcolor(7); gotoxy(43, 25);
	printf(">> Press any key to continue ........ >>");
}
void clrscr()
{
	for (int i = 3; i < 30; i++)
	{
		gotoxy(36, i);textcolor(256);
		printf("                                                                                    ");
		textcolor(7);
	}
}
void END()
{
	system("cls");gotoxy(60, 13);char s1[] = "END";
	for (int i = 0; i < 3; i++)
	{
		Sleep(200);printf("%c", s1[i]);
	}
}
void Khung_seach()
{
	char unsigned c = 205;  //ống Ngang
	char unsigned d = 186;  // ống dọc
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái dưới
	char unsigned c3 = 187; // góc phải trên 
	char unsigned c4 = 188; // góc phải dưới
	char unsigned c5 = 202; // Ống căm lên
	char unsigned c6 = 203; // ống cắm xuống
	gotoxy(0, 0);int i;
	gotoxy(60, 7); printf("Nhap Vao Tu Khoa Tim Kiem");
	//Ống Bên Chiều Dài Trên t
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 8); printf("%c", c);
	}
	gotoxy(55, 8); printf("%c", c1);gotoxy(90, 8); printf("%c", c3);
	//Ống Bên Chiều Dài Dưới 
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 10); printf("%c", c);
	}
	gotoxy(55, 8); printf("%c", c1);gotoxy(90, 8); printf("%c", c3);
	/// Ống Bên Chiều rộng
	for (i = 9; i < 10; i++)
	{
		gotoxy(55, i); printf("%c", d);
	}
	for (i = 9; i < 10; i++)
	{
		gotoxy(90, i); printf("%c", d);
	}
	gotoxy(55, 10); printf("%c", c2);gotoxy(90, 10); printf("%c", c4);
}
void HelpKey()
{
	int a = 55;
	gotoxy(a, 8); textcolor(7); ChayChu("Use key"); textcolor(12); printf(" [ UP    ] "); textcolor(14); ChayChu("to move up on");
	gotoxy(a, 10); textcolor(7); ChayChu("Use key"); textcolor(12); printf(" [ Down  ] "); textcolor(14); ChayChu("to Move Down");
	gotoxy(a, 12); textcolor(7); ChayChu("Use key"); textcolor(12); printf(" [ Left  ] "); textcolor(14); ChayChu("to Move Left");
	gotoxy(a, 14); textcolor(7); ChayChu("Use key"); textcolor(12); printf(" [ Right ] "); textcolor(14); ChayChu("to Move Right");
	gotoxy(a, 16); textcolor(7); ChayChu("Use key"); textcolor(12); printf(" [ Enter ] "); textcolor(14); ChayChu("to Select");
	_getch();
	clrscr();
}
void Help()
{
	vector <HoSo> demo;
	HidePointer();
	Menu();
	HelpKey();
	// Bắt Phím
	{
		int x = 0, y = 0, c;
		x = 5, y = 5;
		Menu_batPhim(5);
		while (1)
		{
			fflush(stdin);c = _getch();
			switch (c)
			{
			case 80:
				y++;break;
			case 72:
				y--;break;
			}
			if (c == 13)
			{
				switch (y)
				{
				case 5:
					Menu_ThemHS();_getch();clrscr();Menu();
					break;
				case 6:
					clrscr();Khung_IN();Ong_ChieuRong(1);Ong_DaiDuoi(8);Menu_In_Down();
					_getch();clrscr();break;
				case 7:
					Menu_sx_DoiMau1(7);_getch();Menu_sx_DoiMau2("Chon", 7);_getch();
					clrscr();break;
				case 8:
					menu1();Menu_Search_DoiMau1(8);Menu_Search_DoiMau2("Tuan Tu", 8);_getch();
					pain();clrscr();break;
				case 9:
					menu1z();_getch();Menu_ThongKe_DoiMau2(9);
					_getch();pain();clrscr();Khung_BieuDo(demo, demo.size());
					_getch();clrscr();break;
				case 10:
					int Err;
					checkExit(&Err, "Exit");
					if (Err == -1)
					{
						END();_getch();return;
					}
					else
					{
						XoaCheckExit();HidePointer();break;
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