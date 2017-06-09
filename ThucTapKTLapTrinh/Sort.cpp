#include "Console.h"

/*----------Function Support -----------------*/
void Swap_change(HoSo &Hs1, HoSo &Hs2)
{
	HoSo HsTemp;
	HsTemp = Hs1;
	Hs1 = Hs2;
	Hs2 = HsTemp;
}
int SoSanhChuoi(char *s1, char *s2)
{
	int x, y, size;
	x = strlen(s1);
	y = strlen(s2);
	(x >= y) ? (size = x) : (size = y);

	for (int i = 0; i < size; i++)
	{
		if (s1[i]>s2[i]){ return 1; }
		if (s1[i] < s2[i]){ return -1; }
	}
	if (x > y){ return 1; }
	if (x < y){ return -1; }
	return 0;
}
void DaoChuoi(char s[], char temp[])
{
	int x = strlen(s);
	if (s == NULL) return;
	int j = 0, i;
	for (i = x - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
			break;
	}
	int n = 0;
	int z;
	for (z = 0; z < x - i - 1; z++)
	{
		temp[z] = s[i + z + 1];// i đang ở dấu cách
	}
	temp[z++] = ' ';
	for (j = 0; j < i; j++, z++)
	{
		temp[z] = s[j];// i đang ở dấu cách
	}
	temp[z++] = '\0';
}
void swapDate(vector <HoSo> &HS)
{
	Date Nhap;
	for (unsigned h = 0; h < HS.size(); h++)
	{
		int x = 0, j = 0, z = 0;
		for (unsigned i = 0; i < strlen(HS[h].NgaySinh); i++)
		{
			if (i == 0 || i == 1)
			{
				Nhap.day[x] = HS[h].NgaySinh[i];
				x++;
			}
			if (i == 3 || i == 4)
			{
				Nhap.month[j] = HS[h].NgaySinh[i];
				j++;
			}
			if (i >= 6 && i <= 9)
			{
				Nhap.year[z] = HS[h].NgaySinh[i];
				z++;
			}
		}
		int cout = 0;
		for (int i = 0; i < z; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.year[i];
			cout++;
		}
		HS[h].NgaySinh[cout] = '/';
		cout++;
		for (int i = 0; i < j; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.month[i];
			cout++;
		}
		HS[h].NgaySinh[cout] = '/';
		cout++;
		for (int i = 0; i < j; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.day[i];
			cout++;
			if (i == j - 1)
			{
				HS[h].NgaySinh[cout] = '\0';
				cout++;
			}
		}
	}
}
void swapDate2(vector <HoSo> &HS)
{
	Date Nhap;
	for (int unsigned h = 0; h < HS.size(); h++)
	{
		int x = 0, j = 0, z = 0;
		for (int unsigned i = 0; i < strlen(HS[h].NgaySinh); i++)
		{
			if (i >= 0 && i <= 3)
			{
				Nhap.year[x] = HS[h].NgaySinh[i];
				x++;
			}
			if (i == 5 || i == 6)
			{
				Nhap.month[j] = HS[h].NgaySinh[i];
				j++;
			}
			if (i == 8 || i == 9)
			{
				Nhap.day[z] = HS[h].NgaySinh[i];
				z++;
			}
		}
		int cout = 0;
		for (int i = 0; i < z; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.day[i];
			cout++;
		}
		HS[h].NgaySinh[cout] = '/';
		cout++;
		for (int i = 0; i < j; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.month[i];
			cout++;
		}
		HS[h].NgaySinh[cout] = '/';
		cout++;
		for (int i = 0; i < x; i++)
		{
			HS[h].NgaySinh[cout] = Nhap.year[i];
			cout++;
			if (i == x - 1)
			{
				HS[h].NgaySinh[cout] = '\0';
				cout++;
			}
		}
	}
}
void ChangePoint(float x, char A[])
{
	char temp[10];
	_itoa(x * 100, temp, 10);
	int leng = (strlen(temp));
	int i = 0;
	for (int j = 0; j < 4; j++)
	{
		if ((j == 1) && leng <= 3)
		{
			A[i] = '.';
			i++;
		}
		if ((j == 2) && leng == 4)
		{
			A[i] = '.';
			i++;
		}
		if ((j == 0) && leng <= 3)
		{
			A[i] = '0';
			i++;
		}
		A[i] = temp[j];
		i++;
		temp[j] = NULL;
		if (j == leng - 1)
		{
			A[i] = '\0';
			i++;
		}
	}
}
void ChangePSeach(float x, char A[])
{
	if (x > 10.0)return;
	char temp[5];
	_itoa(x * 100, temp, 10);
	int i = 0;
	for (int j = 0; j < 4; j++)
	{
		if ((j == 1) && (strlen(temp) == 3))
		{
			A[i] = '.';
			i++;
		}
		if ((j == 2) && (strlen(temp) == 4))
		{
			A[i] = '.';
			i++;
		}
		A[i] = temp[j];
		i++;
		if (j == 4 || j == 3)
		{
			A[i] = '\0';
			i++;
		}
		//temp[j] = NULL;
	}
}
/*-------------SX Mã Lớp --------------------*/
void SX_Chon_MaLop(vector <HoSo> &HS, int n)
{
	if (HS.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(HS[i].MaLop, HS[j].MaLop) == 1)
			{
				Swap_change(HS[i], HS[j]);
			}
		}
	}
	return;
}
void SX_Chen_MaLop(vector <HoSo> &HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(HS[j].MaLop, HS[j - 1].MaLop) == -1)
			{
				Swap_change(HS[j], HS[j - 1]);
			}
		}
	}
	return;
}
void SX_NoiBot_MaLop(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(HS[j].MaLop, HS[j + 1].MaLop) == 1)
			{
				Swap_change(HS[j], HS[j + 1]);
			}
		}
	}
	return;
}
void SX_QuickSort_MaLop(vector<HoSo>&HS, int left, int right)
{
	if (HS.size() == 0){ return; }
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = HS[tg];
	while (i <= j)
	{
		while (SoSanhChuoi(HS[i].MaLop, hoso_tg.MaLop) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(HS[j].MaLop, hoso_tg.MaLop) == 1 && j >= left)
		{
			j--;
		}
		if (i <= j)
		{
			Swap_change(HS[i], HS[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		SX_QuickSort_MaLop(HS, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_MaLop(HS, i, right);
	}
	return;
}
/*-----------Sắp Xếp Mã SV---------------*/
void SX_Chon_MaSV(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(HS[i].MaSV, HS[j].MaSV) == 1)
			{
				Swap_change(HS[i], HS[j]);
			}
		}
	}
	return;
}
void SX_Chen_MaSV(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(HS[j].MaSV, HS[j - 1].MaSV) == -1)
			{
				Swap_change(HS[j], HS[j - 1]);
			}
		}
	}
	return;
}
void SX_NoiBot_MaSV(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(HS[j].MaSV, HS[j + 1].MaSV) == 1)
			{
				Swap_change(HS[j], HS[j + 1]);
			}
		}
	}
	return;
}
void SX_QuickSort_MaSV(vector <HoSo>&HS, int left, int right)
{
	if (HS.size() == 0){ return; }
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = HS[tg];

	while (i <= j)
	{
		while (SoSanhChuoi(HS[i].MaSV, hoso_tg.MaSV) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(HS[j].MaSV, hoso_tg.MaSV) == 1 && j >= left)
		{
			j--;
		}

		if (i <= j)
		{
			Swap_change(HS[i], HS[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		SX_QuickSort_MaSV(HS, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_MaSV(HS, i, right);
	}
	return;
}
/*-----------Sắp Xếp Họ tên---------------*/
void SX_Chon_HoTen(vector <HoSo> &HS, int n)
{
	char temp1[50], temp2[50];
	if (HS.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		DaoChuoi(HS[i].Hoten, temp1);
		for (int j = i + 1; j < n; j++)
		{
			DaoChuoi(HS[j].Hoten, temp2);
			if (SoSanhChuoi(temp1, temp2) == 1)
			{
				Swap_change(HS[i], HS[j]);
			}
		}
	}
	return;
}
void SX_Chen_HoTen(vector <HoSo>&HS, int n)
{
	char temp1[50], temp2[50];
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		DaoChuoi(HS[i].Hoten, temp1);
		for (j = i; j >0; j--)
		{
			DaoChuoi(HS[j - 1].Hoten, temp2);
			if (SoSanhChuoi(temp1, temp2) == -1)
			{
				Swap_change(HS[j], HS[j - 1]);
			}
		}
	}
	return;
}
void SX_NoiBot_HoTen(vector <HoSo>&HS, int n)
{
	char temp1[50], temp2[50];
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			DaoChuoi(HS[j].Hoten, temp1);
			DaoChuoi(HS[j + 1].Hoten, temp2);
			if (SoSanhChuoi(temp1, temp2) == 1)
			{
				Swap_change(HS[j], HS[j + 1]);
			}
		}
	}
	return;
}
void SX_QuickSort_HoTen(vector <HoSo>&HS, int left, int right)
{
	char temp1[50], temp2[50], temp3[50];
	if (HS.size() == 0){ return; }
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = HS[tg];
	DaoChuoi(hoso_tg.Hoten, temp3);
	while (i <= j)
	{
		DaoChuoi(HS[i].Hoten, temp1);
		while (SoSanhChuoi(temp1, temp3) == -1 && i <= right)
		{
			i++;
			DaoChuoi(HS[i].Hoten, temp1);
		}
		DaoChuoi(HS[j].Hoten, temp2);
		while (SoSanhChuoi(temp2, temp3) == 1 && j >= left)
		{
			j--;
			if (j > 0)
				DaoChuoi(HS[j].Hoten, temp2);
		}
		if (i <= j)
		{
			Swap_change(HS[i], HS[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		SX_QuickSort_HoTen(HS, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_HoTen(HS, i, right);
	}
	return;
}
/*-----------Sắp Xếp Ngày sinh---------------*/
void SX_Chon_NgaySinh(vector <HoSo> &HS, int n)
{

	if (HS.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(HS[i].NgaySinh, HS[j].NgaySinh) == 1)
			{
				Swap_change(HS[i], HS[j]);
			}
		}
	}
	return;
}
void SX_Chen_NgaySinh(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(HS[j].NgaySinh, HS[j - 1].NgaySinh) == -1)
			{
				Swap_change(HS[j], HS[j - 1]);
			}
		}
	}
	return;
}
void SX_NoiBot_NgaySinh(vector <HoSo>&HS, int n)
{
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(HS[j].NgaySinh, HS[j + 1].NgaySinh) == 1)
			{
				Swap_change(HS[j], HS[j + 1]);
			}
		}
	}
	return;
}
void SX_QuickSort_NgaySinh(vector <HoSo>&HS, int left, int right)
{
	if (HS.size() == 0){ return; }
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = HS[tg];
	while (i <= j)
	{
		while (SoSanhChuoi(HS[i].NgaySinh, hoso_tg.NgaySinh) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(HS[j].NgaySinh, hoso_tg.NgaySinh) == 1 && j >= left)
		{
			j--;
		}
		if (i <= j)
		{
			Swap_change(HS[i], HS[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		SX_QuickSort_NgaySinh(HS, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_NgaySinh(HS, i, right);
	}
	return;
}
/*-----------Sắp Xếp Điểm TB---------------*/
void SX_Chon_DiemTB(vector <HoSo> &HS, int n)
{
	char Temp1[10], Temp2[10];
	if (HS.size() == 0){ return; }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ChangePoint(HS[i].DiemTB, Temp1);
			ChangePoint(HS[j].DiemTB, Temp2);
			if (SoSanhChuoi(Temp1, Temp2) == -1)
			{
				Swap_change(HS[i], HS[j]);
			}
		}
	}
	return;
}
void SX_Chen_DiemTB(vector <HoSo>&HS, int n)
{
	char Temp1[10], Temp2[10];
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		ChangePoint(HS[i].DiemTB, Temp1);
		for (j = i; j >0; j--)
		{
			ChangePoint(HS[j - 1].DiemTB, Temp2);
			if (SoSanhChuoi(Temp1, Temp2) == 1)
			{
				Swap_change(HS[j], HS[j - 1]);
			}
		}
	}
	return;
}
void SX_NoiBot_DiemTB(vector <HoSo>&HS, int n)
{
	char Temp1[10], Temp2[10];
	if (HS.size() == 0){ return; }
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			ChangePoint(HS[j].DiemTB, Temp1);
			ChangePoint(HS[j + 1].DiemTB, Temp2);
			if (SoSanhChuoi(Temp1, Temp2) == -1)
			{
				Swap_change(HS[j], HS[j + 1]);
			}
		}
	}
	return;
}
void SX_QuickSort_DiemTB(vector <HoSo>&HS, int left, int right)
{
	char Temp1[10], Temp2[10], temp3[10];
	if (HS.size() == 0){ return; }
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = HS[tg];
	ChangePoint(hoso_tg.DiemTB, temp3);
	while (i <= j)
	{
		ChangePoint(HS[i].DiemTB, Temp1);
		while (SoSanhChuoi(Temp1, temp3) == 1 && i <= right)
		{
			i++;
			ChangePoint(HS[i].DiemTB, Temp1);
		}
		ChangePoint(HS[j].DiemTB, Temp2);
		while (SoSanhChuoi(Temp2, temp3) == -1 && j >= left)
		{
			j--;
			if (j > 0)
				ChangePoint(HS[j].DiemTB, Temp2);
		}
		if (i <= j)
		{
			Swap_change(HS[i], HS[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		SX_QuickSort_DiemTB(HS, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_DiemTB(HS, i, right);
	}
	return;
}
/*---------------Main------------------------*/
void Menu_sx_DoiMau1(int ToaDo)
{
	int a = 50;
	gotoxy(a, 7); printf("Sap Xep Chon");
	gotoxy(a, 9); printf("Sap Xep Chen");
	gotoxy(a, 11); printf("Sap Xep Noi Bot");
	gotoxy(a, 13); printf("Sap Xep Nhanh");
	gotoxy(a + 5, 15); printf("-Thoat-");
	//////////////////////////
	int i;
	for (i = 42; i < 73; i++)
	{
		gotoxy(i, 5); printf("%c", 178);
	}
	for (i = 6; i < 20; i++)
	{
		gotoxy(42, i); printf("%c", 178);

	}
	// dài dưới
	for (i = 42; i < 73; i++)
	{
		gotoxy(i, 19); printf("%c", 178);
	}

	// //RONG
	for (i = 6; i < 20; i++)
	{
		gotoxy(72, i); printf("%c", 178);
	}
	////////////////////////
	switch (ToaDo)
	{
	case 7:
		textcolor(14);
		gotoxy(a, 7); printf("Sap Xep Chon");
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9); printf("Sap Xep Chen");;
		textcolor(7);
		break;
	case 11:
		textcolor(14);
		gotoxy(a, 11); printf("Sap Xep Noi Bot");
		textcolor(7);
		break;
	case 13:
		textcolor(14);
		gotoxy(a, 13); printf("Sap Xep Nhanh");
		textcolor(7);
		break;
	case 15:
		textcolor(12);
		gotoxy(a + 5, 15);
		printf("-Thoat-");
		textcolor(7);
		break;
	}
}
void Menu_sx_DoiMau2(char *s, int ToaDo)
{
	int a = 85;
	gotoxy(a, 7); printf("Sap Xep %s Theo Ma Lop", s);
	gotoxy(a, 9); printf("Sap Xep %s Theo Ma SV", s);
	gotoxy(a, 11); printf("Sap Xep %s Theo Ho Ten", s);
	gotoxy(a, 13); printf("Sap Xep %s Theo Ngay Sinh", s);
	gotoxy(a, 15); printf("Sap Xep %s Theo Diem TB", s);
	gotoxy(a + 5, 17); printf("-Thoat-");

	////////////////////////////////////////////////////////////////
	int slep = 10;
	int i;
	for (i = 80; i < 117; i++)
	{
		gotoxy(i, 5); printf("%c", 178);
	}
	for (i = 6; i < 20; i++)
	{
		gotoxy(80, i); printf("%c", 178);
	}
	// dài dưới
	for (i = 80; i < 117; i++)
	{
		gotoxy(i, 19); printf("%c", 178);
	}

	// //RONG
	for (i = 6; i < 20; i++)
	{
		gotoxy(116, i); printf("%c", 178);
	}
	///////////////////////////////////////////////////////////////
	switch (ToaDo)
	{
	case 7:
		textcolor(14);
		gotoxy(a, 7); printf("Sap Xep %s Theo Ma Lop", s);
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9); printf("Sap Xep %s Theo Ma SV", s);
		textcolor(7);
		break;
	case 11:
		textcolor(14);
		gotoxy(a, 11); printf("Sap Xep %s Theo Ho Ten", s);
		textcolor(7);
		break;
	case 13:
		textcolor(14);
		gotoxy(a, 13); printf("Sap Xep %s Theo Ngay Sinh", s);
		textcolor(7);
		break;
	case 15:
		textcolor(14);
		gotoxy(a, 15); printf("Sap Xep %s Theo Diem TB", s);
		textcolor(7);
		break;
	case 17:
		textcolor(12);
		gotoxy(a + 5, 17); printf("-Thoat-");
		textcolor(7);
		break;
	}

}
void SaveFileSort(int z, char *FileName, char *s, vector <HoSo>HS)
{
	int check;
	checkExit(&check, "Save");
	if (check == -1)
	{
		clrscr();
		XoaCheckExit();
		HidePointer();
		UpdateFile(FileName, HS);
		Menu_sx_DoiMau1(z);
		Menu_sx_DoiMau2(s, 7);
		return;
	}
	clrscr();
	Menu_sx_DoiMau1(z);
	Menu_sx_DoiMau2(s, 7);
	return;
}
void MenuConSX1(vector <HoSo> &HS, char *FileName, char *s, int z)
{

	int n = HS.size();
	int x = 0, y = 0, c;
	x = 40, y = 7;
	Menu_batPhim(7);
	Menu_sx_DoiMau2(s, 7);
	while (1)
	{
		c = _getch();
		switch (c)
		{
		case 80:
			y += 2;break;
		case 72:
			y -= 2;break;
		case 27:
			int Err; checkExit(&Err, "Exit"); if (Err == -1){ clrscr(); return; }
			else{ clrscr(); Menu_sx_DoiMau2(s, y); Menu_sx_DoiMau1(z); break; }
		}
		if (c == 13)
		{
			switch (y)
			{
			case 7:
				/*Người Dùng Đang ấn vào Sắp xếp Ma Lop*/
				switch (z)
				{
				case 7:
					SX_Chon_MaLop(HS, HS.size()); break;
				case 9:
					SX_Chen_MaLop(HS, HS.size()); break;
				case 11:
					SX_NoiBot_MaLop(HS, HS.size()); break;
				case 13:
					SX_QuickSort_MaLop(HS, 0, HS.size() - 1); break;
				}
				/*In ra sau khi sắp xếp*/
				clrscr();
				OutPut(HS, FileName,0, n);
				SaveFileSort(z, FileName, s, HS);
				break;
			case 9:
				/*Người Dùng Đang ấn vào Sắp xếp Ma SV*/
				switch (z)
				{
				case 7:
					SX_Chon_MaSV(HS, HS.size()); break;
				case 9:
					SX_Chen_MaSV(HS, HS.size()); break;
				case 11:
					SX_NoiBot_MaSV(HS, HS.size()); break;
				case 13:
					SX_QuickSort_MaSV(HS, 0, HS.size() - 1); break;
				}
				/*In ra sau khi sắp xếp*/
				clrscr();
				OutPut(HS, FileName,0, n);
				SaveFileSort(z, FileName, s, HS);
				break;
			case 11:
				/*Người Dùng Đang ấn vào Sắp xếp Hoten*/
				switch (z)
				{
				case 7:
					SX_Chon_HoTen(HS, HS.size()); break;
				case 9:
					SX_Chen_HoTen(HS, HS.size()); break;
				case 11:
					SX_NoiBot_HoTen(HS, HS.size()); break;
				case 13:
					SX_Chen_HoTen(HS, HS.size()); break;
				}
				/*In ra sau khi sắp xếp*/
				clrscr();
				OutPut(HS, FileName,0, n);
				SaveFileSort(z, FileName, s, HS);
				break;
			case 13:
				/*Người Dùng Đang ấn vào Sắp xếp Ngay Sinh*/
				swapDate(HS);
				switch (z)
				{
				case 7:
					SX_Chon_NgaySinh(HS, HS.size()); break;
				case 9:
					SX_Chen_NgaySinh(HS, HS.size()); break;
				case 11:
					SX_NoiBot_NgaySinh(HS, HS.size()); break;
				case 13:
					SX_QuickSort_NgaySinh(HS, 0, HS.size() - 1); break;
				}
				/*In ra sau khi sắp xếp*/
				swapDate2(HS);
				clrscr();
				OutPut(HS, FileName, 0,n);
				SaveFileSort(z, FileName, s, HS);
				break;
			case 15:
				/*Người Dùng Đang ấn vào Sắp xếp Diem TB*/
				switch (z)
				{
				case 7:
					SX_Chon_DiemTB(HS, HS.size()); break;
				case 9:
					SX_Chen_DiemTB(HS, HS.size()); break;
				case 11:
					SX_NoiBot_DiemTB(HS, HS.size()); break;
				case 13:
					SX_QuickSort_DiemTB(HS, 0, HS.size() - 1); break;
				}
				/*In ra sau khi sắp xếp*/
				clrscr();
				OutPut(HS, FileName, 0,n);
				SaveFileSort(z, FileName, s, HS);
				break;
			case 17:
				clrscr();return;
			}
		}
		if (y > 17)	y = 7;
		if (y < 7) y = 17;
		Menu_sx_DoiMau2(s, y);
		gotoxy(x, y);
	}
}
void MainSapxep(vector <HoSo> &HS, char *FileName)
{
	int n = HS.size();
	if (n == 0){ dialogNull(); return; }
	int x = 0, y = 0, c;
	x = 40, y = 7;
	Menu_batPhim(7);
	Menu_sx_DoiMau1(7);
	while (1)
	{
		c = _getch();
		switch (c)
		{
		case 80:
			y += 2;break;
		case 72:
			y -= 2;break;
		case 27:
			int Err; checkExit(&Err, "Exit"); if (Err == -1){ clrscr(); return; }
			else{ clrscr(); Menu_sx_DoiMau1(y); break; }
		}
		if (c == 13)
		{
			switch (y)
			{
			case 7:
				MenuConSX1(HS, FileName, "Chon", y);break;
			case 9:
				MenuConSX1(HS, FileName, "Chen", y);break;
			case 11:
				MenuConSX1(HS, FileName, "Noi Bot", y);break;
			case 13:
				MenuConSX1(HS, FileName, "Nhanh", y);break;
			case 15:
				clrscr();
				pain();
				return;
			}
		}
		if (y > 15)	y = 7;
		if (y < 7) y = 15;
		Menu_sx_DoiMau1(y);
		gotoxy(x, y);
	}
}
