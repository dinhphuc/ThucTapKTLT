#include "Console.h"
#define  NULL 0
#define Console_Dai 120
#define Console_Rong 28
char unsigned  c = 205;  //ống Ngang
char unsigned d = 186;  // ống dọc
char unsigned c1 = 201; // góc trái trên
char unsigned c2 = 200; // góc trái dưới
char unsigned c3 = 187; // góc phải trên 
char unsigned c4 = 188; // góc phải dưới
char unsigned c5 = 202; // Ống căm lên
char unsigned c6 = 203; // ống cắm xuống
char unsigned c7 = 206; // ống Dấu cộng
void EditMenu(char *FileName, vector<HoSo> &HS, int &n, int &ToaDo, int &Trang);
void Edit(char *FileName, vector <HoSo> &HS, int LocaEdit, int STT, int ox, int oy);
double size = sizeof(HoSo);
/*IN KHUNG Thống KÊ */
void Khung_PrintfTK(char *s)
{
	for (int i = 50; i < 100; i++)
	{
		gotoxy(i, 26);printf("%c", c);
	}
	for (int i = 5; i < 26; i++)
	{
		gotoxy(50, i);printf("%c", d);
	}
	for (int i = 5; i < 26; i++)
	{
		gotoxy(100, i);printf("%c", d);
	}
	for (int i = 5; i < 26; i++)
	{
		gotoxy(80, i);printf("%c", d);
	}
	for (int i = 50; i < 100; i++)
	{
		for (int j = 4; j < 26; j = j + 2)
		{
			gotoxy(i, j);printf("%c", c);
			gotoxy(80, j); printf("%c", c7);
			gotoxy(50, j); printf("%c", 204);
			gotoxy(100, j); printf("%c", 185);
		}
	}
	gotoxy(80, 4); printf("%c", c6);gotoxy(80, 26); printf("%c", c5);
	/// Các Góc
	gotoxy(100, 4); printf("%c", c3);gotoxy(100, 26); printf("%c", c4);
	gotoxy(50, 4); printf("%c", c1);gotoxy(50, 26); printf("%c", c2);
	// Menu
	gotoxy(85, 5); printf("So Luong");gotoxy(63, 5); printf("%s", s);

}
/*IN KHUNG */
void Ong_NganCach(int OY)
{
	// Ống Ngăn Cách {
	int i;
	for (i = 38; i < Console_Dai - 3; i++)
	{
		gotoxy(i, OY);printf("%c", c);
		if (i == 38)
		{
			gotoxy(i, OY);printf("%c", 204);
		}
		// Các ống cắm xuống
		else if (i == 44)
		{
			gotoxy(i, OY);printf("%c", c7);
		}
		else if (i == 57)
		{
			gotoxy(i, OY);printf("%c", c7);
		}
		else if (i == 68)
		{
			gotoxy(i, OY);printf("%c", c7);
		}

		else if (i == 90)
		{
			gotoxy(i, OY);printf("%c", c7);
		}
		else if (i == 107)
		{
			gotoxy(i, OY);printf("%c", c7);
		}
		else if (i == 116)
		{
			gotoxy(i, 0);printf("%c", 185);break;
		}
	}
}
void Ong_DaiDuoi(int ChieuDai_duoi_min)
{
	// Ống Chiều dài dưới
	int i;
	//ChieuDai_duoi_min ;
	for (i = 38; i <= Console_Dai - 3; i++)
	{
		gotoxy(i, ChieuDai_duoi_min);printf("%c", c);
		if (i == 38)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c2);
		}
		else if (i == 44)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
		if (i == 117)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c4);break;
		}
		// Các ống cắm Lên
		if (i == 44)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
		else if (i == 57)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
		else if (i == 68)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
		else if (i == 90)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
		else if (i == 107)
		{
			gotoxy(i, ChieuDai_duoi_min);printf("%c", c5);
		}
	}
}
void Ong_ChieuRong(int Ong_RongMin)
{
	int i;Ong_RongMin += 7;
	for (i = 5; i < Ong_RongMin; i += 2)
	{
		gotoxy(117, i);printf("%c", d);
		gotoxy(38, i);printf("%c", d);
		gotoxy(44, i);printf("%c", d);
		gotoxy(57, i);printf("%c", d);
		gotoxy(68, i);printf("%c", d);
		gotoxy(90, i);printf("%c", d);
		gotoxy(107, i);printf("%c", d);
	}
}
void Khung_IN()
{
	// khung bên trong (khung con)
	gotoxy(0, 0);int i;
	//Ống Chiều dài trên
	for (i = 38; i < Console_Dai - 3; i++)
	{
		gotoxy(i, 4);printf("%c", c);
		if (i == 38)
		{
			gotoxy(i, 4);printf("%c", c1);
		}
		// Các ống cắm xuống
		else if (i == 44)
		{
			gotoxy(i, 4);printf("%c", c6);
		}
		else if (i == 57)
		{
			gotoxy(i, 4);printf("%c", c6);
		}
		else if (i == 68)
		{
			gotoxy(i, 4);printf("%c", c6);
		}
		else if (i == 90)
		{
			gotoxy(i, 4);printf("%c", c6);
		}
		else if (i == 107)
		{
			gotoxy(i, 4);printf("%c", c6);
		}
		else if (i == 116)
		{
			gotoxy(i, 0);printf("%c", c3);break;
		}
	}
	Ong_NganCach(6);
	gotoxy(69, 3);printf("Danh Sach Sinh Vien");
	gotoxy(40, 5);printf("STT");
	gotoxy(48, 5);printf("Ma Lop");
	gotoxy(61, 5);printf("Ma SV");
	gotoxy(75, 5);printf("Ho Va Ten");
	gotoxy(95, 5);printf("Ngay Sinh");
	gotoxy(109, 5);printf("Diem TB");
}
vector<HoSo>  input(char *FileName)
{
	vector<HoSo> HS;
	HoSo SV;
	FILE *fp;
	int a = 0;
	fp = fopen(FileName, "rb");
	if ((fp == NULL) || (feof(fp)))
	{
		return HS;
	}
	else
	{
		while (!feof(fp))
		{
			fread(&SV, sizeof(SV), 1, fp);
			if (!feof(fp))
				HS.push_back(SV);
		}
	}
	return HS;
}
void UpdateFile(char *FileName, vector <HoSo > HS)
{

	FILE *fp;
	fp = fopen(FileName, "wb");
	for (unsigned i = 0; i < HS.size(); i++)
	{
		fwrite(&HS[i], sizeof(HoSo), 1, fp);
	}
	fclose(fp);
}
void ChuyenMau(int x)
{
	// Đổi Màu Chữ
	switch (x)
	{
	case 70:
		textcolor(14);
		gotoxy(108, 28);printf("Next >>");
		textcolor(7);
		gotoxy(92, 28);printf(" << Preview");
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);printf("Add");
		textcolor(7);
		gotoxy(68, 28);printf("Edit");
		break;
	case 85:
		textcolor(14);
		gotoxy(92, 28);printf(" << Preview");
		textcolor(7);
		gotoxy(108, 28);printf("Next >>");
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);printf("Add");
		textcolor(7);
		gotoxy(68, 28);printf("Edit");
		break;
	case 100:
		textcolor(9);
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(108, 28);printf("Next >>");
		gotoxy(92, 28);printf(" << Preview");
		textcolor(7);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);printf("Add");
		textcolor(7);
		gotoxy(68, 28);printf("Edit");
		break;
	case 115:
		textcolor(9);
		gotoxy(68, 28);printf("Edit");
		textcolor(7);
		gotoxy(108, 28);printf("Next >>");
		gotoxy(92, 28);printf(" << Preview");
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);printf("Add");
		break;
	case 130:
		textcolor(9);
		gotoxy(57, 28);printf("Add");
		textcolor(7);
		gotoxy(108, 28);printf("Next >>");
		gotoxy(92, 28);printf(" << Preview");
		textcolor(7);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(68, 28);printf("Edit");
		break;
	case 145:
		textcolor(12);
		gotoxy(43, 28);printf("Cancel");
		textcolor(7);
		gotoxy(108, 28);printf("Next >>");
		gotoxy(92, 28);printf(" << Preview");
		gotoxy(80, 28);printf("Delete");
		textcolor(7);
		gotoxy(57, 28);printf("Add");
		textcolor(7);
		gotoxy(68, 28);printf("Edit");
		break;
	}
}
void Menu_In_Down()
{
	gotoxy(80, 28);printf("Delete");
	gotoxy(43, 28);printf("Cancel");
	gotoxy(57, 28);printf("Add");
	gotoxy(68, 28);printf("Edit");
	textcolor(14);
	gotoxy(108, 28);printf("Next >>");
	textcolor(7);
	gotoxy(105, 28);printf("|");
	textcolor(7);
	gotoxy(92, 28);printf(" << Preview");
}
void dialogNull()
{
	Khung_IN();
	gotoxy(40, 3);printf("Empty Data !!!!!!!!");
	Ong_ChieuRong(1);Ong_DaiDuoi(8);
	_getch();
	clrscr();
}
void Next_DS(int &x, int &Ong_Rong, int &Trang, int &b)
{
	clrscr();x += 10;Ong_Rong = 0;
	b = 7;
	gotoxy(39, 3);printf("Trang - %d >>", Trang);
	Menu_batPhim(6);
	Trang++;
}
void DeleteHS(char *FileName, vector<HoSo> &HS, int &n, int &ToaDo, int &Trang)
{
	int Oy;
	ChuyenControUpDown(&ToaDo, Trang - 1, (HS.size() / 10 + 1), &Oy);
	if (ToaDo == -1)
	{
		clrscr(); OutPut(HS, FileName, (Trang - 1) * 10, n);
		return;
	}
	if (ToaDo > n)
	{
		gotoxy(70, 26);textcolor(192);printf("Do not exist");
		textcolor(15);
		_getch(); clrscr(); OutPut(HS, FileName, (Trang - 1) * 10,n);
		return;
	}
	DeleteSV(HS, ToaDo);
	clrscr();
	UpdateFile(FileName, HS);
	OutPut(HS, FileName, (Trang - 1)*10,HS.size());
	clrscr();
}
void Prevew_DS(int &Next, int &Trang, int &i, int &b, int &stt, int &Ong_Rong)
{
	clrscr();
	Next = (Trang - 2) * 10;
	Ong_Rong = 0;
	stt = (Trang - 2) * 10;
	b = 7;
	i = ((Trang - 2) * 10) - 1;
	Trang--;
}
void OutPut(vector <HoSo> HS, char *FileName, int inF,int n)
{
	if (n == 0){ dialogNull(); }
	HidePointer();
	int ToaDo = 0, Err, Trang = (inF / 10) + 1, Next = inF; // Qua Trang;
	int TongSo_SV = n, b = 7, stt = inF, Ong_Rong = 0, i;
	for (i = inF; i < TongSo_SV; i++)
	{
		/*---------------------------------------------------------------------------*/
		gotoxy(39, 3);
		printf("Trang - %d >>", Trang);
		Khung_IN();
		Ong_NganCach(b - 1);
		textcolor(9);
		gotoxy(41, b);
		printf("%d", stt + 1);
		gotoxy(46, b); printf("%s", HS[i].MaLop);
		gotoxy(59, b); printf("%s", HS[i].MaSV);
		gotoxy(70, b); printf("%s", HS[i].Hoten);
		gotoxy(94, b); printf("%s", HS[i].NgaySinh);
		gotoxy(111, b); printf("%0.2f", HS[i].DiemTB);
		textcolor(7);
		/*--------------------------------------*/
		b += 2; stt++;
		Ong_Rong += 2; Ong_ChieuRong(Ong_Rong); Ong_DaiDuoi(b - 1);
		/*--------------------------------------*/
		gotoxy(100, 3); printf("Tong So (%d/%d)", stt, TongSo_SV);
		/*--------------------Quá 10 SV ----------------------*/
		if (stt == (10 + Next))
		{
			Next += 10;
			// Menu In ở dưới
			Menu_In_Down();
			// Phần Bắt Phím //
			/* Phải là 77 Trái là  75  delete 83 */
			int x = 70, Nhap;
			while (1)
			{
				//_getch();
				Nhap = _getch();
				switch (Nhap)
				{
				case 77:
					x -= 15; break;
				case 75:
					x += 15; break;
					/*--------------------Ấn Phím Delete ----------------------*/
				case 83:
					DeleteHS(FileName, HS, n, ToaDo, Trang);
					return;
				case 6:
					clrscr();
					MainSearch(HS, FileName, HS.size());
					clrscr();
					OutPut(HS, FileName, (Trang - 1) * 10, HS.size());
					return;
				case 27:
					checkExit(&Err, "Exit"); {if (Err == -1){
						return;
					}
					clrscr(); OutPut(HS, FileName, (Trang - 1)*10,n); return; }
					return;
				}
				/*--------------------Quá 10 SV && ấn Enter ----------------------*/
				if (Nhap == 13)
				{
					switch (x)
					{
					case 70: //next 
						Next_DS(x, Ong_Rong, Trang, b); break;
					case 85: // Prevew
						if (Trang >= 2)
						{
							Prevew_DS(Next, Trang, i, b, stt, Ong_Rong); break;
						}
						else{
							clrscr(); checkExit(&Err, "Exit"); {if (Err == -1)return;
							clrscr();
							OutPut(HS, FileName, (Trang - 1) * 10,n);
							return; }
						}
						/*--------------------Quá 10 SV && Delete ----------------------*/
					case 100:
						DeleteHS(FileName, HS, n, ToaDo, Trang); return;
						/*--------------------Quá 10 SV && Edit ----------------------*/
					case 115:
						EditMenu(FileName, HS, n, ToaDo, Trang); return;
						/*--------------------Quá 10 SV && ADD ----------------------*/
					case 130:
						clrscr();
						ThemMoi_Hs(FileName);
						HS = input(FileName);
						clrscr();
						OutPut(HS, FileName, HS.size() / 10 * 10, HS.size());
						return;
					case 145: // Thoát 
						checkExit(&Err, "Exit"); {if (Err == -1){ return; }
						clrscr();
						OutPut(HS, FileName,(Trang-1)*10, n);
						return; }
						return;
					}
				}
				if ((x > 145)) x = 70;
				if ((x < 70)) x = 145;
				ChuyenMau(x);
				if (Nhap == 13) break;
			}
		}
		/*------Trang Đầu SV <10 ||  Trang Cuối -----*/
		if ((stt == TongSo_SV))
		{
			gotoxy(100, 3);
			printf("Tong So (%d/%d)", stt, TongSo_SV);
			gotoxy(52, 3); textcolor(201); printf("[Het]"); textcolor(15);
			Menu_In_Down();
			// Phần Bắt Phím //
			/* Phải là 77 Trái là  75*/
			int x = 70, Nhap;
			while (1)
			{
				Nhap = _getch();
				switch (Nhap)
				{
				case 77:
					x -= 15;
					break;
				case 75:
					x += 15;
					break;
					/*------Trang Đầu SV <10 ||  Trang Cuối và Delete-----*/
				case 83:
					DeleteHS(FileName, HS, n, ToaDo, Trang);
					return;
				case 6:
					clrscr();
					MainSearch(HS, FileName, HS.size());
					clrscr();
					OutPut(HS, FileName, (Trang - 1) * 10, HS.size());
					return;
				case 27:
					checkExit(&Err, "Exit"); {if (Err == -1){ return; }
					clrscr();
					OutPut(HS, FileName,(Trang-1)*10, n);
					return; }
					return;
				}
				if (Nhap == 13)
				{
					switch (x)
					{
					case 70:	//next 
						if (TongSo_SV == stt){
							clrscr(); checkExit(&Err, "Exit"); {if (Err == -1){
								return;
							}
							clrscr();
							OutPut(HS, FileName, (Trang - 1) * 10, n);
							return; }
						}
					case 85: //lùi
						if (Trang >= 2)
						{
							Prevew_DS(Next, Trang, i, b, stt, Ong_Rong);
							break;
						}
						return;
						/*------Trang Đầu SV <10 ||  Trang Cuối và Delete-----*/
					case 100: // Delete
						DeleteHS(FileName, HS, n, ToaDo, Trang); return;
						/*------Trang Đầu SV <10 ||  Trang Cuối và Edit-----*/
					case 115:// edit
						EditMenu(FileName, HS, n, ToaDo, Trang); return;
						/*------Trang Đầu SV <10 ||  Trang Cuối và ADD-----*/
					case 130: // Thêm	
						clrscr();
						ThemMoi_Hs(FileName);
						HS = input(FileName);
						clrscr();
						OutPut(HS, FileName, HS.size()/10*10,HS.size());
						return;
					case 145: // Thoát 
						checkExit(&Err, "Exit"); {if (Err == -1){ return; }
						clrscr();
						OutPut(HS, FileName, (Trang - 1) * 10, n);
						return; }
						return;
					}
				}
				if ((x > 145)) x = 70;
				if ((x < 70)) x = 145;
				ChuyenMau(x);
				if (Nhap == 13) break;
			}
		}
	}
}
void InFile(vector <HoSo> HS, char *Filename)
{
	FILE *f1;
	int i = 1;
	f1 = fopen(Filename, "w");
	fprintf(f1, "          \t\t-----------DANH SÁCH SINH VIÊN-------------\n");
	fprintf(f1, "---------------------------------------------------------------------------------------------\n");
	fprintf(f1, "| stt  |     MALOP  |        MASV  |           HOTEN         |     NGAYSINH    |   DIEMTB   |\n");
	for (unsigned i = 0; i < HS.size(); i++)
	{
		fprintf(f1, "---------------------------------------------------------------------------------------------\n");
		fprintf(f1, "|%-5.03d | %-10s | %-12s | %-23s | %-15s | %-10.2f |\n", (i + 1), _strupr(HS[i].MaLop), HS[i].MaSV, HS[i].Hoten, HS[i].NgaySinh, HS[i].DiemTB);
	}
	fprintf(f1, "---------------------------------------------------------------------------------------------\n");
	fclose(f1);
}
void DeleteSV(vector <HoSo> &HS, int ToaDo)
{
	int n = HS.size();
	vector<HoSo> HStemp(HS);
	HS.clear();
	for (int i = 0; i < n; i++)
	{
		if (i != (ToaDo - 1)) HS.push_back(HStemp[i]);
	}
}
void EditMenu(char *FileName, vector<HoSo> &HS, int &n, int &ToaDo, int &Trang)
{
	int ox, oy, LocaEdit;
	ChuyenControUpDown(&ToaDo, Trang - 1, (HS.size() / 10 + 1), &oy);
	if (ToaDo == -1){ clrscr(); OutPut(HS, FileName, (Trang - 1) * 10,n); return; }
	if (ToaDo > n)
	{
		gotoxy(70, 26);textcolor(192);printf("Do not exist");textcolor(15);
		_getch();
		clrscr();
		OutPut(HS, FileName, (Trang - 1) * 10, n);
		return;
	}
	ChuyenControLeftRight(&LocaEdit, &ox, oy);
	Edit(FileName, HS, LocaEdit, ToaDo - 1, ox, oy);
}
void Edit(char *FileName, vector <HoSo> &HS, int LocaEdit, int STT, int ox, int oy)
{
	int err, t = 0, lengStr;
	char temp[10];
	switch (LocaEdit)
	{
	case 1:
		gotoxy(ox + 1, oy);
		printf("%s", HS[STT].MaLop);
		do{
			textcolor(14);
			lengStr = strlen(HS[STT].MaLop);
			EnterMaLop(HS[STT].MaLop, lengStr, t, ox + 1 + strlen(HS[STT].MaLop), oy, &err);
			if (err == -1){ return; }
			if ((strlen(HS[STT].MaLop) <= 0) || (strlen(HS[STT].MaLop) > 15))
			{
				textcolor(12);gotoxy(ox + 11, oy);printf("!");
			}
		} while ((strlen(HS[STT].MaLop) <= 0) || (strlen(HS[STT].MaLop) > 15));
		textcolor(7);
		UpdateFile(FileName, HS);
		clrscr();
		OutPut(HS, FileName, STT/10*10,HS.size());
		break;
	case 2:
	{
			  gotoxy(ox + 1, oy);printf("%s", HS[STT].MaSV);
			  vector <HoSo> HSTK;
			  vector<HoSo> HStemp;
			  HStemp = input(FileName);
			  do
			  {
				  textcolor(14);
				  lengStr = strlen(HS[STT].MaSV);
				  EnterMaSV(HS[STT].MaSV, lengStr, t, ox + 1 + strlen(HS[STT].MaSV), oy, &err);
				  if (err == -1){ return; }
				  // Xử lý Trùng
				  HSTK.clear();
				  TuanTu_MaSV(HStemp, HSTK, HS[STT].MaSV);
				  if (HSTK.size() >= 1){gotoxy(ox + 9, oy);textcolor(12);printf("!");}
				  if (strlen(HS[STT].MaSV) != 8){gotoxy(ox + 9, oy);textcolor(12);printf("!");}
			  } while ((strlen(HS[STT].MaSV) != 8) || HSTK.size() >= 1);
			  HStemp.~vector();
			  textcolor(7);
			  UpdateFile(FileName, HS);
			  clrscr();
			  OutPut(HS, FileName, STT / 10 * 10,HS.size());
	}
		break;
	case 3:
		gotoxy(ox + 1, oy);
		printf("%s", HS[STT].Hoten);
		do
		{
			textcolor(14);
			lengStr = strlen(HS[STT].Hoten);
			EnterHoTen(HS[STT].Hoten, lengStr, t, ox + 1 + strlen(HS[STT].Hoten), oy, &err);
			if (err == -1){ return; }
			if (strlen(HS[STT].Hoten) <= 0){gotoxy(ox + 20, oy);textcolor(12);printf("!");}
		} while (strlen(HS[STT].Hoten) <= 0);
		textcolor(7);
		UpdateFile(FileName, HS);
		clrscr();
		OutPut(HS, FileName, STT / 10 * 10,HS.size());
		break;
	case 4:
	{
			  gotoxy(ox + 1, oy);printf("%s", HS[STT].NgaySinh);
			  int day = 0, month = 0, year = 0;
			  do{
				  textcolor(14);
				  lengStr = strlen(HS[STT].NgaySinh);
				  EnterNgaySinh(HS[STT].NgaySinh, lengStr, t, ox + 1 + strlen(HS[STT].NgaySinh), oy, &err);
				  if (err == -1){ return; }
				  TachNgay(HS[STT].NgaySinh, &day, &month, &year);
				  if (KT_Date(day, month, year) == 0 || (strlen(HS[STT].NgaySinh) != 10))
				  {textcolor(12);gotoxy(ox + 13, oy);printf("!");}
			  } while ((KT_Date(day, month, year) == 0) || (strlen(HS[STT].NgaySinh) != 10));
			  textcolor(7);
			  UpdateFile(FileName, HS);
			  clrscr();
			  OutPut(HS, FileName, STT / 10 * 10, HS.size());
	}
		break;
	case 5:
		gotoxy(ox + 1, oy);
		printf("%0.2f", HS[STT].DiemTB);
		do
		{
			textcolor(14);
			ChangePSeach(HS[STT].DiemTB, temp);
			lengStr = strlen(temp);
			EnterDiem(temp, lengStr, t, ox + 1 + lengStr, oy, &err);
			if (err == -1){ return; }
			HS[STT].DiemTB = (float)atof(temp);
			if (HS[STT].DiemTB > 10.0 || HS[STT].DiemTB <0.0)
			{
				textcolor(12);gotoxy(ox + 6, oy);printf("!");textcolor(7);
			}
		} while (HS[STT].DiemTB >10.0 || HS[STT].DiemTB < 0.0);
		textcolor(7);
		UpdateFile(FileName, HS);
		clrscr();
		OutPut(HS, FileName, STT / 10 * 10,HS.size());
		break;
	}
}