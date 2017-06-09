#include "Console.h"
/*----------Dialog---------------*/
void KhungExit()
{
	char unsigned c = 205;  //ống Ngang
	char unsigned d = 186;  // ống dọc
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái dưới
	char unsigned c3 = 187; // góc phải trên 
	char unsigned c4 = 188; // góc phải dưới
	char unsigned c5 = 202; // Ống căm lên
	char unsigned c6 = 203; // ống cắm xuống
	int i; textcolor(240);
	//Ống Bên Chiều Dài Trên t
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 15); printf("%c", c);
	}
	gotoxy(55, 15); printf("%c", c1); gotoxy(90, 15); printf("%c", c3);
	//Ống Bên Chiều Dài Dưới 
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 21); printf("%c", c);
	}
	gotoxy(55, 15); printf("%c", c1); gotoxy(90, 15); printf("%c", c3);
	/// Ống Bên Chiều rộng
	for (i = 16; i < 21; i++)
	{
		gotoxy(55, i); printf("%c", d);
	}
	for (i = 16; i < 21; i++)
	{
		gotoxy(90, i); printf("%c", d);
	}
	gotoxy(55, 21); printf("%c", c2); gotoxy(90, 21); printf("%c", c4);
	for (int i = 56; i < 90; i++)
	{
		textcolor(255); gotoxy(i, 16); printf(" "); gotoxy(i, 18); printf(" "); gotoxy(i, 20); printf(" ");
	}
	gotoxy(56, 17); printf("        "); gotoxy(85, 17); printf("     ");
	gotoxy(56, 19); printf("             "); gotoxy(75, 19); printf("               ");
	gotoxy(74, 19); printf(" "); gotoxy(72, 19); printf(" ");
}
void ChangeColor(int x)
{
	switch (x)
	{
	case 69:
		textcolor(286); gotoxy(69, 19); printf("yes"); textcolor(244); gotoxy(75, 19); printf("No");
		break;
	case 75:
		textcolor(286); gotoxy(75, 19); printf("No"); textcolor(244); gotoxy(69, 19); printf("yes");
		break;
	}
}
void checkExit(int *Err1, char *look)
{
	KhungExit(); textcolor(244); HidePointer(); gotoxy(64, 17);
	printf("Do You Want To %s ?", look); gotoxy(69, 19);
	printf("yes"); gotoxy(73, 19); printf("|"); textcolor(286); gotoxy(75, 19); printf("No");
	int x = 75, Nhap = 0;
	while (1)
	{
		fflush(stdin); Nhap = _getch();
		switch (Nhap)
		{
		case 77:x -= 6; break;
		case 75:x += 6; break;
		}
		if (Nhap == 13)
		{
			switch (x)
			{
			case 75:*Err1 = 1; break;
			case 69:*Err1 = -1; break;
			}
		}
		if ((x > 75)) x = 69;
		if ((x < 69)) x = 75;
		// Chuyển màu
		ChangeColor(x);
		if (Nhap == 13) break;
	}
	textcolor(15);
}
void XoaCheckExit()
{
	HidePointer();
	for (int i = 15; i < 23; i++)
	{
		gotoxy(40, i); textcolor(256);
		printf("                                                     ");
		textcolor(7);
	}
	ShowPointer();
}
/*----------Nhập---------------*/
void EnterMaLop(char *xau, int i, int &y, int ox, int oy, int *Err)
{
	int temp = 0, Err1;
	ShowPointer(); gotoxy(ox, oy);
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1, "Exit");
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				XoaCheckExit(); ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
				continue;
			}
		}
		if (c == 77 && temp == -32){ continue; }
		if (c == 80 && temp == -32) { y++; break; }
		if (c == 72 && temp == -32) { y--; break; }
		if (i >= 0 && c == 75 && temp == -32){ continue; }
		temp = c;
		if (i > 0 && c == 8)
		{
			printf("\b \b");
			i--;
			continue;
		}
		if (c < 0 || i < 0)continue;
		if (i >= 0 && c != 27 && c != 8)
		{
			c = toupper(c);
			xau[i++] = c;
			printf("%c", c);
		}
	} while (c != 13);
	if (xau[i - 1] == ' ' || c == 13)
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
	HidePointer();
}
void EnterMaSV(char *xau, int i, int &y, int ox, int oy, int *Err)
{
	int temp = 0, Err1; ShowPointer(); gotoxy(ox, oy);
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1, "Exit");
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				XoaCheckExit(); ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
				continue;
			}
		}
		if (c == 77 && temp == -32){ continue; }
		if (c == 80 && temp == -32) { y++; break; }
		if (c == 72 && temp == -32) { y--; break; }
		if (i >= 1 && c == 75 && temp == -32){ continue; }
		temp = c;

		if (i > 0 && c == 8)
		{
			printf("\b \b");
			i--;
			continue;
		}
		if (c < 0 || i < 0)continue;
		if (i >= 0 && c != 27 && c != 8 && i < 8)
		{
			if (c >= '0'&&c <= '9')
			{
				xau[i++] = c;
				printf("%c", c);
			}
		}
	} while (c != 13);
	if (xau[i - 1] == ' ')
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
	HidePointer();
}
void EnterHoTen(char *xau, int i, int &y, int ox, int oy, int *Err)
{
	int temp = 0, Err1; ShowPointer(); gotoxy(ox, oy);
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1, "Exit");
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				XoaCheckExit(); ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
			}
		}
		if (c == 77 && temp == -32){ continue; }
		if (c == 80 && temp == -32) { y++; break; }
		if (c == 72 && temp == -32) { y--; break; }
		if (i >= 0 && c == 75 && temp == -32){
			continue;
		}
		temp = c;
		if (c == 8 && i > 0){ printf("\b \b"); i--; continue; }
		if (c <= 0 || i<0)
			continue;
		if (i > 0 && c == 32 && xau[i - 1] != ' ' && i != 0)
		{
			printf(" ");
			xau[i++] = c;
		}
		if (!isalpha(c))
			continue;
		if (i == 0 || xau[i - 1] == ' ')
			c = toupper(c);
		if (i != 0 && xau[i - 1] != ' ')
			c = tolower(c);
		xau[i++] = c;
		printf("%c", c);
	} while (c != 13);

	if (xau[i - 1] == ' ')
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
	HidePointer();
}
void EnterNgaySinh(char *xau, int i, int &y, int ox, int oy, int *Err)
{
	ShowPointer(); gotoxy(ox, oy);
	char c; int Err1, temp = 0;
	do
	{
		fflush(stdin);
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1, "Exit");
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				XoaCheckExit(); ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
				continue;
			}
		}
		if (c == 77 && temp == -32){ continue; }
		if (c == 80 && temp == -32) { y++; break; }
		if (c == 72 && temp == -32) { y--; break; }
		if (i >= 1 && c == 75 && temp == -32){ continue; }
		temp = c;
		if (c < 0 || i<0)continue;
		if (c == 8 && i > 0){ printf("\b \b"); i--; continue; }
		if (i >= 0 && c >= '0'&&c <= '9')
		{
			/* Chuẩn Hóa Ngày */
			if (i == 0)
			{
				if (c >= '0'&&c <= '3')
				{
					xau[i++] = c; printf("%c", c);
					continue;
				}
				// Ngày 4-9 cho thêm số 0 phía trước
				if (c >= '4'&&c <= '9')
				{
					char a = '0';
					xau[i++] = a; printf("0");
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i == 1)
			{
				//Nếu là ngày 3 thì cho nhập 0 và 1 ;
				if (xau[i - 1] == '3' && c >= '0'&&c <= '1')
				{
					xau[i++] = c; printf("%c", c);
					continue;
				}
				//Nếu là ngày 1 hoặc 2 thì cho nhập 0 - 9 ;
				if (((xau[i - 1] == '1') || (xau[i - 1] == '2')) && (c >= '0') && (c <= '9'))
				{
					xau[i++] = c; printf("%c", c);
				}
				//Nếu là ngày = 0  thì chỉ cho nhập 1 - 9 ;
				if ((xau[i - 1] == '0') && (c > '0') && (c <= '9'))
				{
					xau[i++] = c; printf("%c", c);
				}
			}
			// cho nhập năm
			if (i != 4 && i != 3 && i != 2 && i != 1)
			{
				if (i >= 0 && i < 10)
				{
					xau[i++] = c; printf("%c", c);
				}
				continue;
			}
			/* Chuẩn Hóa Tháng */
			if (i == 3)
			{
				if (c >= '0'&&c <= '1')
				{
					xau[i++] = c; printf("%c", c);
					continue;
				}
				//Thêm số 0 vào tháng 2-9
				if (c >= '2'&&c <= '9')
				{
					char a = '0';
					xau[i++] = a; printf("0");
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i == 4)
			{
				// Nếu tháng 1 hoặc nhập 0 thì cho nhập 0 và 2
				if (xau[i - 1] == '1' && c >= '0'&&c <= '2')
				{
					xau[i++] = c; printf("%c", c);
				}
				// Nếu c 0 thì cho nhập 1 - 9
				if (xau[i - 1] == '0' && c > '0'&&c <= '9')
				{
					xau[i++] = c; printf("%c", c);
				}
			}
			// In ra dấu "/"
			if (i == 2 || i == 5)
			{
				char a = '/'; xau[i++] = a; printf("/");
			}
		}
	} while (c != 13);
	if (xau[i - 1] == ' ')
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
}
void EnterDiem(char *xau, int i, int &y, int ox, int oy, int *Err)
{
	ShowPointer(); gotoxy(ox, oy);
	char c; int temp = 0, Err1;
	do
	{
		fflush(stdin);
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1, "Exit");
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				XoaCheckExit(); ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
				continue;
			}
		}
		if (c == 77 && temp == -32){ continue; }
		if (c == 80 && temp == -32) { y++; break; }
		if (c == 72 && temp == -32) { y--; break; }
		if (i >= 0 && c == 75 && temp == -32){
			 continue;
		}
		temp = c;
		if (c == 8 && i > 0){ printf("\b \b"); i--; continue; }
		if (c < 0 || i < 0)continue;
		if (c != 13 && i >= 0 && i <= 4 && c != 8)
		{
			xau[i++] = c; printf("%c", c);
		}
	} while (c != 13);
	if (xau[i - 1] == ' ')
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
}
//------------//
void EnterNameFile(char *xau, int i, int ox, int oy, int *Err)
{
	int temp = 0, Err1 = 0;
	ShowPointer(); gotoxy(ox, oy);
	char c;
	do
	{
		c = _getch();
		if (c == 27)
		{
			{
				HidePointer(); textcolor(12); gotoxy(ox, oy + 2);
				ChayChu("Press [Enter] to accept Exit");
				textcolor(14); gotoxy(ox + 5, oy + 3);
				ChayChu("OR [ESC] to Cancel");
				c = _getch();
				if (c == 13)Err1 = -1;
				textcolor(7); ShowPointer();
			}
			if (Err1 == -1){ *Err = -1; return; }
			else
			{
				gotoxy(ox, oy + 2); ChayChu("                            ");
				textcolor(14); gotoxy(ox + 5, oy + 3); ChayChu("                  ");
				ShowPointer(); gotoxy(ox + i, oy); textcolor(249);
				continue;
			}
		}
		if (c == 77 && temp == -32){ i++; ox++; gotoxy(ox, oy); continue; }
		if (i >= 1 && c == 75 && temp == -32){ ox--; i--; gotoxy(ox, oy); continue; }
		temp = c;
		if (i > 0 && c == 8)
		{
			printf("\b \b"); i--; continue;
		}
		if (c < 0 || i < 0)continue;
		/*   /\:*"<>|
		*   47 92 58 42 34 60 62 124
		*/
		if (c == 47 || c == 92 || c == 58 || c == 42 || c == 34 || c == 60 || c == 62 || c == 124)
			continue;
		if (i >= 0)
		{
			xau[i++] = c;
			printf("%c", c);
		}
	} while (c != 13);
	if (xau[i - 1] == ' ' || c == 13)
		i--;
	xau[i++] = '\0'; xau[i] = NULL;
	HidePointer();
}
/*----------Date---------------*/
void TachNgay(char *xau, int *day, int *mount, int *year)
{
	Date Nhap; int x = 0, j = 0, z = 0;
	for (unsigned i = 0; i < strlen(xau); i++)
	{
		if (i == 0 || i == 1)
		{
			Nhap.day[x] = xau[i]; x++;
			if (x == 2)*day = atoi(Nhap.day);
		}
		if (i == 3 || i == 4)
		{
			Nhap.month[j] = xau[i]; j++;
			if (j == 2)*mount = atoi(Nhap.month);
		}
		if (i >= 6 && i <= 9)
		{
			Nhap.year[z] = xau[i]; z++;
			if (z == 4) *year = atoi(Nhap.year);
		}
	}
}
int KT_Date(int &day, int &month, int &year)
{
	if (year < 0 || year >2017)return 0;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		switch (month)
		{
		case 1: case 3:	case 5: case 7:case 8: case 10: case 12:{break; }
		case 4: case 6: case 9: case 11:{if (day > 30)return 0; break; }
		case 2:{if (day > 29)return 0; break; }
		}
		return 1;
	}
	// Năm Không nhuận
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:{break; }
	case 4: case 6: case 9: case 11:{if (day > 30)return 0; break; }
	case 2:{if (day > 28)return 0; break; }
	}
	return 1;
}