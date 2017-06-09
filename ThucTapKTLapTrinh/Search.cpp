#include "Console.h"

int compare_Search(char *xau,char *look)
{
	char *s = strstr(xau, look);
	if (s != NULL)
	{
		return 0;
	}
	return -1;
}
/*----------Search Nhị Phân---------------*/
void NhiPhan_Malop(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	int n = HS.size();
	SX_NoiBot_MaLop(HS, n);
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;	
		if (compare_Search(HS[mid].MaLop, look) == 0)
		{  	
			for (int i = mid + 1; i<HS.size() ; i++)
			{
				if(compare_Search(HS[i].MaLop, look) == 0)
				HSTK.push_back(HS[i]);
			}
			HSTK.push_back(HS[mid]);
			for (int i = mid - 1; (i > 0) ; i--)
			{
				if (compare_Search(HS[i].MaLop, look) == 0)
				HSTK.push_back(HS[i]);
			}	
			SX_NoiBot_MaLop(HSTK, HSTK.size());
			return ;
		}			
		else if (SoSanhChuoi(look, HS[mid].MaLop) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, HS[mid].MaLop)==1)
			left = mid + 1;	
	}
	return;
}
void NhiPhan_MaSV(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	int n = HS.size();
	SX_NoiBot_MaSV(HS, n);
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(HS[mid].MaSV, look) == 0)
		{
			for (int i = mid + 1; (i<HS.size()); i++)
			{
				if (compare_Search(HS[i].MaSV, look) == 0)
				HSTK.push_back(HS[i]);
			}
			HSTK.push_back(HS[mid]);
			for (int  i = mid - 1; (i >0) ; i--)
			{
				if (compare_Search(HS[i].MaSV, look) == 0)
				HSTK.push_back(HS[i]);
			}
			SX_NoiBot_MaSV(HSTK, HSTK.size());
			return;
		}
		else if (SoSanhChuoi(look, HS[mid].MaSV) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, HS[mid].MaSV) == 1)
			left = mid + 1;
	}
	return;
}
void NhiPhan_HoTen(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	char temp1[50], temp2[50];
	int n = HS.size();
	SX_NoiBot_HoTen(HS, n);
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		DaoChuoi(HS[mid].Hoten, temp2);
		DaoChuoi(look, temp1);
		if (compare_Search(HS[mid].Hoten, look) == 0)
		{
			for (int i = mid + 1; (i<HS.size()); i++)
			{
				if (compare_Search(HS[i].Hoten, look) == 0)
					HSTK.push_back(HS[i]);
			}
			HSTK.push_back(HS[mid]);
			for (int i = mid - 1; (i > 0); i--)
			{
				if (compare_Search(HS[i].Hoten, look) == 0)
					HSTK.push_back(HS[i]);
			}
			SX_NoiBot_HoTen(HSTK, HSTK.size());
			return;
		}
		else if (SoSanhChuoi(temp1, temp2) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(temp1, temp2) == 1)
			left = mid + 1;
	}
	return;
}
void NhiPhan_NgaySinh(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	int n = HS.size();
	SX_NoiBot_NgaySinh(HS, n);
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (compare_Search(HS[mid].NgaySinh, look) == 0)
		{
			for (int   i = mid + 1; (i<HS.size()) ; i++)
			{
				if (compare_Search(HS[i].NgaySinh, look) == 0)
				HSTK.push_back(HS[i]);
			}
			HSTK.push_back(HS[mid]);
			for (int i = mid - 1; (i > 0); i--)
			{
				if (compare_Search(HS[i].NgaySinh, look) == 0)
				HSTK.push_back(HS[i]);
			}
			SX_NoiBot_NgaySinh(HSTK, HSTK.size());
			return;
		}
		else if (SoSanhChuoi(look, HS[mid].NgaySinh) == -1)
			right = mid - 1;
		else if (SoSanhChuoi(look, HS[mid].NgaySinh) == 1)
			left = mid + 1;
	}
	return;
}
void NhiPhan_DTB(vector <HoSo> HS, vector <HoSo> &HSTK, float look)
{
	int n = HS.size();
	SX_NoiBot_DiemTB(HS, HS.size());
	int left = 0;
	int right = n - 1;
	int i = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (HS[mid].DiemTB==look)
		{
			for (int i = mid + 1; i<HS.size(); i++)
			{
				if (HS[i].DiemTB == look)
				HSTK.push_back(HS[i]);
			}
			HSTK.push_back(HS[mid]);
			for (int i = mid - 1; i >= 0; i--)
			{			
				if (HS[i].DiemTB== look)
				HSTK.push_back(HS[i]);
			}
			SX_NoiBot_DiemTB(HSTK, HSTK.size());
			return;
		}
		else if (HS[mid].DiemTB <look)
			right = mid - 1;
		else if (HS[mid].DiemTB >look)
			left = mid + 1;
	}
	return;
}
/*----------Search Tuần Tự---------------*/
void TuanTu_Malop(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	HSTK.clear();
	for (int   i = 0; i < HS.size(); i++)
	{
		char *s = strstr(HS[i].MaLop, look);
		if (s != NULL)
		{
			HSTK.push_back(HS[i]);
		}
	}
}
void TuanTu_MaSV(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	HSTK.clear();
	for (int   i = 0; i < HS.size(); i++)
	{
		char *s = strstr(HS[i].MaSV, look);
		if (s != NULL)
		{
			HSTK.push_back(HS[i]);
		}
	}
}
void TuanTu_HoTen(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	HSTK.clear();
	for (int   i = 0; i < HS.size(); i++)
	{
		char *s = strstr(HS[i].Hoten, look);
		if (s != NULL)
		{
			HSTK.push_back(HS[i]);
		}
	}
}
void TuanTu_NgaySinh(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	HSTK.clear();
	for (int   i = 0; i < HS.size(); i++)
	{
		char *s = strstr(HS[i].NgaySinh, look);
		if (s != NULL)
		{
			HSTK.push_back(HS[i]);
		}
	}
}
void TuanTu_DTB(vector <HoSo> HS, vector <HoSo> &HSTK, char look[])
{
	char Temp[10];
	HSTK.clear();
	for (int   i = 0; i < HS.size(); i++)
	{
		ChangePSeach(HS[i].DiemTB, Temp);
		char *s = strstr(Temp,look );
		if (s != NULL)
		{
			HSTK.push_back(HS[i]);
		}
	}
}
/*----------Main Search---------------*/
void menu1()
{
	int a = 45;
	gotoxy(a, 8);ChayChu("Tim Kiem Tuan Tu");
	gotoxy(a, 10);ChayChu("Tim Kiem Nhi Phan");
	gotoxy(a + 5, 12);printf("-Thoat-");
}
void Menu_Search_DoiMau1(int ToaDo)
{
	int a = 45;
	for (int i = 3; i < 30; i++)
	{
		gotoxy(75, i);printf("%c", 186);
	}
	char  unsigned c5 = 202; // Ống căm lên
	char  unsigned c6 = 203; // ống cắm xuống
	gotoxy(75, 2);printf("%c", 203);
	gotoxy(75, 30);printf("%c", 202);
	switch (ToaDo)
	{
	case 8:
		textcolor(14);
		gotoxy(a, 8);printf("Tim Kiem Tuan Tu");
		textcolor(7);
		gotoxy(a, 10);printf("Tim Kiem Nhi Phan");
		gotoxy(a + 5, 12);printf("-Thoat-");
		break;
	case 10:
		textcolor(7);
		gotoxy(a + 5, 12);printf("-Thoat-");
		gotoxy(a, 8);printf("Tim Kiem Tuan Tu");
		textcolor(14);
		gotoxy(a, 10);printf("Tim Kiem Nhi Phan");
		textcolor(7);
		break;
	case 12:
		textcolor(12);
		gotoxy(a + 5, 12);printf("-Thoat-");
		textcolor(7);
		gotoxy(a, 8);printf("Tim Kiem Tuan Tu");
		gotoxy(a, 10);printf("Tim Kiem Nhi Phan");
		break;
	}
}
void Menu_Search_DoiMau2(char *s, int ToaDo)
{
	int a = 85;
	gotoxy(a, 8);printf("Tim Kiem %s Theo Ma Lop", s);
	gotoxy(a, 10);printf("Tim Kiem %s Theo Ma SV", s);
	gotoxy(a, 12);printf("Tim Kiem %s Theo Ho Ten", s);
	gotoxy(a, 14);printf("Tim Kiem %s Theo Ngay Sinh", s);
	gotoxy(a, 16);printf("Tim Kiem %s Theo Diem TB", s);
	gotoxy(a + 5, 18);printf("-Thoat-");
	switch (ToaDo)
	{
	case 8:
		textcolor(14);gotoxy(a, 8);printf("Tim Kiem %s Theo Ma Lop", s);textcolor(7);break;
	case 10:
		textcolor(14);gotoxy(a, 10);printf("Tim Kiem %s Theo Ma SV", s);textcolor(7);break;
	case 12:
		textcolor(14);gotoxy(a, 12);printf("Tim Kiem %s Theo Ho Ten", s);textcolor(7);break;
	case 14:
		textcolor(14);gotoxy(a, 14);printf("Tim Kiem %s Theo Ngay Sinh", s);textcolor(7);break;
	case 16:
		textcolor(14);gotoxy(a, 16);printf("Tim Kiem %s Theo Diem TB", s);textcolor(7);break;
	case 18:
		textcolor(12);gotoxy(a + 5, 18);printf("-Thoat-");textcolor(7);break;
	}

}
void SaveFileSearch(vector <HoSo> HSTK, int z, char *FileTxt, char *FileWb)
{
	clrscr();
	OutPut(HSTK, FileWb, 0,HSTK.size());
	if (HSTK.size() == 0)
	{
		Menu_Search_DoiMau1(z);return;
	}	
	InFile(HSTK, FileTxt);
	int check;checkExit(&check, "Save");
	if (check == -1)
	{
		clrscr();
		XoaCheckExit();HidePointer();
		HSTK.clear();
		HSTK=input(FileWb);
		if (HSTK.size()>0)
		InFile(HSTK, FileTxt);
		Menu_Search_DoiMau1(z);
		HSTK.clear();
		UpdateFile(FileWb, HSTK);
		return;
	}
	HSTK.clear();
	clrscr();
	Menu_Search_DoiMau1(z);
	
	return;
}
void MenuConSearch1(vector <HoSo> HS, char *s, int z)
{
	int Err,t=0;
	vector <HoSo> HSTK;
	int x = 0, y = 0, c;
	x = 40, y = 8;
	Menu_batPhim(8);
	Menu_Search_DoiMau2(s, 8);
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
			int Err; checkExit(&Err, "Exit"); if (Err == -1){ pain(); clrscr(); return; }
			else{ clrscr(); pain(); Menu_Search_DoiMau1(8); break; }
		}
		if (c == 13)
		{
			switch (y)
			{
			case 8:
				/*Người Dùng Đang ấn vào Tìm Kiếm Ma Lớp*/
				clrscr();
				textcolor(12);gotoxy(67, 5); printf("Seach Ma Lop ");textcolor(7);
				pain();
				char NhapMaLop[20];
				Khung_seach();
				do{
					textcolor(9);
					EnterMaLop(NhapMaLop, 0, t, 60, 9, &Err);
					if (Err == -1)
					{
						clrscr();
						return;
					}
					if ((strlen(NhapMaLop) <= 0) || (strlen(NhapMaLop) > 15))
					{
						textcolor(14);gotoxy(60 + 43, 9);printf("ERRO ! Empty ");
					}
				} while ((strlen(NhapMaLop) <= 0) || (strlen(NhapMaLop) > 15));
				/*-----Tìm Kiếm Mã Lớp--------*/
				switch (z)
				{
				case 8:
					TuanTu_Malop(HS, HSTK, NhapMaLop);
					break;
				case 10:
					NhiPhan_Malop(HS, HSTK, NhapMaLop);		
					break;
				}
				/*In ra sau khi Tìm Kiếm*/
				clrscr();
				gotoxy(80, 2);textcolor(244);printf("Tim Kiem Ma Lop ");textcolor(241);
				printf("look: ");textcolor(252);printf("%s", NhapMaLop);
				textcolor(7);
				SX_Chon_MaLop(HSTK, HSTK.size());
				SaveFileSearch(HSTK, z, "searchNumberClass.txt","searchNumberClass.wb");
				HSTK.clear();
				break;
			case 10:
				/*Người Dùng Đang ấn vào Tìm Kiếm Ma SV*/
				clrscr();
				textcolor(12);gotoxy(64, 5); printf("Seach Ma Sinh Vien ");textcolor(7);
				pain();
				char NhapMaSV[20];
				Khung_seach();
				do{
					textcolor(9);
					EnterMaSV(NhapMaSV, 0, t, 60, 9, &Err);
					if (Err == -1)
					{
						clrscr();
						return;
					}
					if ((strlen(NhapMaSV) <= 0) || (strlen(NhapMaSV) > 15))
					{
						textcolor(14);
						gotoxy(60 + 43, 9);
						printf("ERRO  !!");
					}
				} while ((strlen(NhapMaSV) <= 0) || (strlen(NhapMaSV) > 15));

				/*-----Tìm Kiếm Mã SV--------*/
				switch (z)
				{
				case 8:
					TuanTu_MaSV(HS, HSTK, NhapMaSV);
					break;
				case 10:
					NhiPhan_MaSV(HS, HSTK, NhapMaSV);
					break;
				}
				/*In ra sau khi Tìm Kiếm*/
				clrscr();
				gotoxy(80, 2);textcolor(244);printf("Tim Kiem SV ");textcolor(241);
				printf("look: ");textcolor(252);printf("%s", NhapMaSV);textcolor(7);
				SX_Chon_MaSV(HSTK, HSTK.size());
				SaveFileSearch(HSTK, z,"searchNumberID.txt","searchNumberID.wb");
				HSTK.clear();
				break;
			case 12:
				/*Người Dùng Đang ấn vào tìm Kiếm Hoten*/
				clrscr();
				textcolor(12);
				gotoxy(66, 5); printf("Seach Ho Ten ");textcolor(7);
				pain();
				char NhapHoten[20];
				Khung_seach();
				do{
					textcolor(9);
					EnterHoTen(NhapHoten, 0, t, 60, 9, &Err);
					if (Err == -1)
					{
						clrscr();
						return;
					}
					if ((strlen(NhapHoten) <= 0) || (strlen(NhapHoten) > 15))
					{
						textcolor(14);gotoxy(60 + 43, 9);printf("ERRO  !!");
					}
				} while ((strlen(NhapHoten) <= 0) || (strlen(NhapHoten) > 15));
				/*-----Tìm Kiếm HoTen--------*/
				switch (z)
				{
				case 8:
					TuanTu_HoTen(HS, HSTK, NhapHoten);
					break;
				case 10:
					NhiPhan_HoTen(HS, HSTK, NhapHoten);
					break;
				}
				/*In ra sau khi Tìm Kiếm*/
				clrscr();
				gotoxy(80, 2);textcolor(244);printf("Tim Kiem Ho Ten ");textcolor(241);
				printf("look: ");textcolor(252);printf("%s", NhapHoten);textcolor(7);
				SX_Chon_HoTen(HSTK, HSTK.size());
				SaveFileSearch(HSTK, z, "searchName.txt", "searchName.wb");
				HSTK.clear();
				break;
			case 14:
				/*Người Dùng Đang ấn vào Tìm Kiếm Ngay Sinh*/
				clrscr();
				textcolor(12);gotoxy(65, 5); printf("Seach Ngay Sinh ");textcolor(7);
				pain();
				char NhapNgaySinh[20];
				Khung_seach();
				do{
					textcolor(9);
					EnterNgaySinh(NhapNgaySinh, 0, t, 60, 9, &Err);
					if (Err == -1)
					{
						clrscr();
						return;
					}
					if ((strlen(NhapNgaySinh) <= 0) || (strlen(NhapNgaySinh) > 15))
					{
						textcolor(14);
						gotoxy(60 + 43, 9);
						printf("ERRO  !!");
					}
				} while ((strlen(NhapNgaySinh) <= 0) || (strlen(NhapNgaySinh) > 15));
				/*-----Tìm Kiếm Ngay Sinh--------*/
				switch (z)
				{
				case 8:
					TuanTu_NgaySinh(HS, HSTK, NhapNgaySinh);
					break;
				case 10:
					NhiPhan_NgaySinh(HS, HSTK, NhapNgaySinh);
					break;
				}
				/*In ra sau khi Tìm Kiếm*/
				clrscr();
				gotoxy(80, 2);textcolor(244);printf("Search Birth Day ");textcolor(241);
				printf("look: ");textcolor(252);printf("%s", NhapNgaySinh);textcolor(7);
				SX_NoiBot_NgaySinh(HSTK, HSTK.size());
				SaveFileSearch(HSTK, z, "searchBirthDay.txt","searchBirthDay.wb" );
				HSTK.clear();
				break;
			case 16:
				/*Người Dùng Đang ấn vào Tìm Kiếm Diem TB*/
				clrscr();
				textcolor(12);
				gotoxy(66, 5); printf("Seach Diem TB ");
				textcolor(7);
				pain();
				char NhapDTB[20];
				Khung_seach();
				do{
					textcolor(9);
					EnterDiem(NhapDTB, 0, t, 60, 9, &Err);
					if (Err == -1)
					{
						clrscr();
						return;
					}
					if ((strlen(NhapDTB) <= 0) || (strlen(NhapDTB) > 15))
					{
						textcolor(14);
						gotoxy(60 + 43, 9);
						printf("ERRO  !!");
					}
				} while ((strlen(NhapDTB) <= 0) || (strlen(NhapDTB) > 15));

				/*-----Tìm Kiếm Mã DTB--------*/
				switch (z)
				{
				case 8:
					TuanTu_DTB(HS, HSTK, NhapDTB);
					break;
				case 10:
					
					NhiPhan_DTB(HS, HSTK, atof(NhapDTB));
					break;
				}
				/*In ra sau khi Tìm Kiếm*/
				clrscr();
				gotoxy(80, 2);
				textcolor(244);printf("Tim Kiem DiemTB ");textcolor(241);printf("look: ");textcolor(252);
				printf("%s", NhapDTB);textcolor(7);
				SX_NoiBot_DiemTB(HSTK, HSTK.size());
				SaveFileSearch(HSTK, z, "searchPoint.txt", "searchPoint.wb");
				HSTK.clear();
				break;
			case 18:
				clrscr();
				pain();
				return;
				break;
			}
		}
		if (y > 18)	y = 8;
		if (y < 8) y = 18;
		Menu_Search_DoiMau2(s, y);
		gotoxy(x, y);
	}
}
void MainSearch(vector <HoSo> HS, char *FileName, int n)
{
	HidePointer();
	if (HS.size() == 0)
	{
      dialogNull(); return;
	}
	{
		int x = 0, y = 0, c;
		x = 40, y = 8;
		Menu_batPhim(8);
		menu1();
		Menu_Search_DoiMau1(8);
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
				int Err; checkExit(&Err, "Exit"); if (Err == -1){ pain();clrscr(); return; }
				else{ clrscr(); pain(); break; }
			}
			if (c == 13)
			{
				switch (y)
				{
				case 8:
					MenuConSearch1(HS, "Tuan Tu", y);break;
				case 10:
					MenuConSearch1(HS, "Nhi Phan", y);break;
				case 12:
					clrscr();pain();
					return;
				}
			}
			if (y > 12)	y = 8;
			if (y < 8) y = 12;
			Menu_Search_DoiMau1(y);
			gotoxy(x, y);
		}
	}
}