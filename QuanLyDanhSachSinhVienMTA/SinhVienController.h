#define _CRT_SECURE_NO_WARNINGS
#include "sinhviencore.h"

int dem = 0;
int ktMaTrung = 0;

void ghiFileBinary(SinhVien sv)
{
	FILE *f = fopen(FileBinary, "a+b"); 
	if (f != NULL)
	{
		fwrite(&sv, sizeof(sv), 1, f);
		fclose(f);
	}
	else
	{
		printf("Khong the mo tap tin nay duoc\n");
	}
}
int docFileBinary(List &L)
{
	SinhVien sv;
	int i = 0;
	Init(L);
	FILE *f;
	f = fopen(FileBinary, "rb");
	if (f == NULL)
	{
		printf("FILE CHUA TON TAI !");
	}
	else
	{
		fread(&sv, sizeof(sv), 1, f);
		while (!feof(f))
		{
			Node *p = creatNode(sv);
			addTail(L, p);
			fread(&sv, sizeof(SinhVien), 1, f);
			i++;
		}
	}
	fclose(f);
	return i;
}
void ghiFileText(List L)
{
	Node *p = L.head;
	FILE *ftxt = fopen(FileText, "a+");  
	if (ftxt == NULL)					
	{									
		printf("\nKhong mo duoc file\n");
	}
	else
	{
		if (dem == 0)
		{
			fprintf(ftxt, "\n\t\t\tDANH SACH SINH VIEN\n");
			fprintf(ftxt, "\t+----------------------------+--------------------+---------------------------+-----------------------+-------------------+\n");
			fprintf(ftxt, "\t|          Ho Va Ten                 Ma Lop                Ma Sinh vien               Ngay Sinh                Diem TB    \n");
			fprintf(ftxt, "\t+----------------------------+--------------------+---------------------------+-----------------------+-------------------+\n");
			while (p != NULL)
			{
				if (p->sv.day < 10)
				{
					if (p->sv.month < 10)
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  0%d/0%d/%d            %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
					else
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  0%d/%d/%d             %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
				}
				else
				{
					if (p->sv.month < 10)
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  %d/0%d/%d             %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
					else
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  %d/%d/%d              %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
				}
				if (p != L.tail)
					fprintf(ftxt, "\t+----------------------------+--------------------+---------------------------+-----------------------+-------------------+\n");
				p = p->Next;
			}
		}
		else
		{
			while (p != NULL)
			{
				if (p->sv.day < 10)
				{
					if (p->sv.month < 10)
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  0%d/0%d/%d            %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
					else
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  0%d/%d/%d             %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
				}
				else
				{
					if (p->sv.month < 10)
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  %d/0%d/%d             %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
					else
					{
						fprintf(ftxt, "\t|     %s %s            %10s         %13s                  %d/%d/%d              %10.1f          \n", p->sv.Ten.FirstName, p->sv.Ten.LastName, p->sv.MaLop, p->sv.MSV, p->sv.day, p->sv.month, p->sv.year, p->sv.DiemTB);
					}
				}
				if (p != L.tail)
					fprintf(ftxt, "\t+----------------------------+--------------------+---------------------------+-----------------------+-------------------+\n");
				p = p->Next;
			}
		}
	}
	fprintf(ftxt, "\t+----------------------------+--------------------+---------------------------+-----------------------+-------------------+\n");
	fclose(ftxt);
	dem++;
}

void NhapSinhVien()
{
	system("color 7");
	clrscr();
	SinhVien sv;
	int n = 6;
	int nambat, kiemsoatphu;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[n];
	for (int i = 0; i < n; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "  NHAP THONG TIN SINH VIEN";
	TextColor(13);
	for (int x = 0; x < strlen(S1); x++)
	{
		gotoxy(52 + x, 2);
		printf("%c", S1[x]);
	}
	TextColor(10);
	for (int y = 0; y < 40; y++)
	{
		gotoxy(44 + y, 4);
		printf("%c", tru);
	}
	TextColor(12);
	for (int i = 0; i < 85; i++)
	{
		gotoxy(20 + i, 6);
		printf("%c", 254);
	}

	for (int i = 0; i < 19; i++)
	{
		gotoxy(105, 6 + i);
		printf("%c", 219);
	}

	for (int i = 0; i < 84; i++)
	{
		gotoxy(104 - i, 24);
		printf("%c", 254);
	}

	for (int i = 0; i < 19; i++)
	{
		gotoxy(20, 24 - i);
		printf("%c", 219);
	}
	while (i <= 4) {
		for (int j = 19; j < 103; j++)
		{
			gotoxy(j + 2, 9 + i1);
			printf("%c", 205);
		}
		i1 += 3;
		i++;
	}
	for (int j = 0; j <= 16; j++) {
		gotoxy(70, j + 7);
		printf("%c", 219);
	}
	char S3[] = "NHAP MA LOP";
	char S4[] = "NHAP MA SINH VIEN";
	char S5[] = "NHAP HO DEM";
	char S6[] = "NHAP TEN";
	char S7[] = "NHAP NGAY/THANG/NAM";
	char S8[] = "NHAP DIEM TRUNG BINH";
	char S9[] = "NHAP THONG TIN SINH VIEN THANH CONG. NHAN ENTER DE THOAT!!!";
	TextColor(10);
	gotoxy(26, 8);
	for (int i = 0; i < strlen(S3); i++)
	{
		printf("%c", S3[i]);
	}
	gotoxy(75, 8);
	fflush(stdin);
	gets_s(sv.MaLop);
	chuanHoa_MaLop(sv.MaLop);
	gotoxy(26, 8);
	printf("                               ");
	gotoxy(26, 8);
	printf("NHAP MA LOP");
	gotoxy(26 + strlen(S3), 8);
	gotoxy(75, 8);
	printf("%s", sv.MaLop);
	TextColor(10);
	gotoxy(26, 11);
	for (int i = 0; i < strlen(S4); i++)
	{
		printf("%c", S4[i]);
	}
	gotoxy(75, 11);
	fflush(stdin);
	char *s = gets_s(sv.MSV);
	if (ktMaTrung != 0)
	{
		List list2;
		Init(list2);
		docFileBinary(list2);
		int x0 = kiemTranTrung_MaSinhVien(s, list2);
		if (x0 != 0)
		{
			while (x0 != 0)
			{
				gotoxy(26, 11);
				printf("                                      ");
				gotoxy(75, 11);
				printf("                ");
				TextColor(13);
				gotoxy(26, 11);
				printf("MA SINH VIEN TON TAI. MOI BAN NHAP LAI");
				TextColor(10);
				gotoxy(75, 11);
				fflush(stdin);
				s = gets_s(sv.MSV);
				x0 = kiemTranTrung_MaSinhVien(s, list2);
			}
		}
	}
	ktMaTrung++;
	chuanHoa_MaSinhVien(sv.MSV);
	gotoxy(26, 11);
	printf("                                        ");
	gotoxy(75, 11);
	printf("                ");
	gotoxy(26, 11);
	printf("NHAP MA SINH VIEN");
	gotoxy(26 + strlen(S4), 11);
	gotoxy(75, 11);
	printf("%s", sv.MSV);
	TextColor(10);
	gotoxy(26, 14);
	for (int i = 0; i < strlen(S5); i++)
	{
		printf("%c", S5[i]);
	}
	gotoxy(75, 14);
	gotoxy(75, 14);
	fflush(stdin);
	gets_s(sv.Ten.FirstName);
	chuanHoa_HoTen(sv.Ten.FirstName);
	gotoxy(26, 14);
	printf("                      ");
	gotoxy(75, 14);
	printf("                      ");
	gotoxy(26, 14);
	printf("NHAP HO DEM");
	gotoxy(75, 14);
	printf("%s", sv.Ten.FirstName);
	TextColor(10);
	gotoxy(26, 17);
	for (int i = 0; i < strlen(S6); i++)
	{
		printf("%c", S6[i]);
	}
	gotoxy(75, 17);
	fflush(stdin);
	gets_s(sv.Ten.LastName);
	chuanHoa_HoTen(sv.Ten.LastName);
	gotoxy(26, 17);
	printf("                  ");
	gotoxy(75, 17);
	printf("             ");
	gotoxy(26, 17);
	printf("NHAP TEN");
	gotoxy(75, 17);
	printf("%s", sv.Ten.LastName);
	TextColor(10);
	gotoxy(26, 20);
	for (int i = 0; i < strlen(S7); i++)
	{
		printf("%c", S7[i]);
	}
	gotoxy(75, 20);
	fflush(stdin);
	scanf_s("%d", &sv.day);
	gotoxy(78, 20);
	printf("/");
	scanf_s("%d", &sv.month);
	gotoxy(81, 20);
	printf("/");
	scanf_s("%d", &sv.year);
	int x1 = dinhDang_NgaySinh(sv);
	while (x1 == 0)
	{
		if (x1 == 0)
		{
			gotoxy(26, 20);
			printf("                               ");
			gotoxy(75, 20);
			printf("                         ");
			TextColor(13);
			gotoxy(26, 20);
			printf("MOI BAN NHAP LAI NGAY/THANG/NAM");
			TextColor(10);
			gotoxy(75, 20);
			fflush(stdin);
			scanf_s("%d", &sv.day);
			gotoxy(78, 20);
			printf("/");
			scanf_s("%d", &sv.month);
			gotoxy(81, 20);
			printf("/");
			scanf_s("%d", &sv.year);
		}
		x1 = dinhDang_NgaySinh(sv);
	}
	TextColor(10);
	gotoxy(26, 23);
	for (int i = 0; i < strlen(S8); i++)
	{
		printf("%c", S8[i]);
	}
	gotoxy(75, 23);
	fflush(stdin);
	scanf_s("%f", &sv.DiemTB);
	int x2 = chuanHoa_Diem(sv.DiemTB);
	while (x2 == 0)
	{
		if (x2 == 0)
		{
			gotoxy(26, 23);
			printf("                      ");
			gotoxy(75, 23);
			printf("                      ");
			TextColor(13);
			gotoxy(26, 23);
			printf("MOI BAN NHAP LAI DIEM TRUNG BINH");
			TextColor(10);
			gotoxy(75, 23);
			fflush(stdin);
			scanf_s("%f", &sv.DiemTB);
		}
		x2 = chuanHoa_Diem(sv.DiemTB);
	}
	List list;
	Init(list);
	Node *p = creatNode(sv);
	addHead(list, p);
	ghiFileBinary(p->sv);//ghi vao file nhi phan
	ghiFileText(list);//ghi vao file van ban
	int j = 2;
	do
	{
		TextColor(j);
		Sleep(1);
		j++;
		if (j == 16) j = 2;
		for (int y = 0; y < strlen(S9); y++)
		{
			gotoxy(32 + y, 27);
			printf("%c", S9[y]);
		}
		AnConTro();
	} while (!_kbhit());
	_getch();
	clrscr();
	cin.ignore();

}
void Indanhsach()
{
	clrscr();
	char S[] = "NHAN ENTER DE XEM TIEP DANH SACH!!!";
	List list1;
	Init(list1);
	int x = docFileBinary(list1);
	if (x > 10)
	{
		while (x > 10)
		{
			FrameKetQua(list1, 10, 1);
			int j = 2;
			do
			{
				TextColor(j);
				j++;
				if (j == 16) j = 2;
				for (int y = 0; y < strlen(S); y++)
				{
					gotoxy(40 + y, 30);
					printf("%c", S[y]);
				}
				AnConTro();
			} while (!_kbhit());
			_getch();
			system("color 7");
			clrscr();
			x = x - 10;
			if (x <= 10){
				FrameKetQua(list1, x, 2);
			}
			
		}
	}
	else
	{
		FrameKetQua(list1, x, 1);
	}

	clrscr();
}

void FrameSapXepTheoTuKhoa()
{
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "CHON TU KHOA SAP XEP DANH SACH SINH VIEN";
	TextColor(13);
	for (int x = 0; x < strlen(S1); x++)
	{
		gotoxy(41 + x, 5);
		printf("%c", S1[x]);
	}
	TextColor(10);
	for (int y = 0; y < 45; y++)
	{
		gotoxy(38 + y, 7);
		printf("%c", tru);
	}
	TextColor(10);
	for (int i = 0; i < 66; i++)
	{
		gotoxy(26 + i, 9);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 22; i++)
	{
		gotoxy(93, 9 + i);
		printf("%c", cong);
	}
	for (int i = 0; i < 68; i++)
	{
		gotoxy(94 - i, 30);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 22; i++)
	{
		gotoxy(25, 30 - i);
		printf("%c", cong);
	}
	TextColor(12);
	while (i <= 5)
	{
		for (int j = 24; j < 91; j++)
		{
			gotoxy(j + 2, 12 + i1);
			printf("%c", 205);
		}
		i1 += 3;
		i++;
	}
}
int SapXepQuicksortDanhSachTheoTuKhoa(int sothaotac)
{
	clrscr();
	system("color 7");
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[sothaotac];
	for (int i = 0; i < sothaotac; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameSapXepTheoTuKhoa();
	char S2[] = "1. MA LOP SINH VIEN";
	char S3[] = "2. HO TEN SINH VIEN";
	char S4[] = "3. NGAY SINH SINH VIEN";
	char S5[] = "4. DIEM TRUNG BINH SINH VIEN";
	char S6[] = "5.THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < sothaotac; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S2); i++)
				{
					printf("%c", S2[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
			if (i == 4)
			{
				TextColor(mau[i]);
				gotoxy(50, 26);
				for (int i = 0; i < strlen(S6); i++)
				{
					printf("%c", S6[i]);
				}
			}
		}
		nambat = _getch();
		trangthai = Key(nambat);
		switch (trangthai)
		{
		case UP:
		{
				   if (tt == 0)
				   {
					   tt = sothaotac - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == sothaotac - 1)
					 {
						 tt = 0;
					 }
					 else
					 {
						 tt++;
					 }
					 break;
		}
		case ENTER:
		{
					  switch (tt)
					  {
					  case 0:
					  {
								system("color 7");
								List list2;
								Init(list2);
								int x = docFileBinary(list2);
								sapXepQuicksort_MaLop(list2);
								clrscr();
								FrameKetQua(list2, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								List list3;
								Init(list3);
								int x = docFileBinary(list3);
								sapXepQuicksort_Ten(list3);
								clrscr();
								FrameKetQua(list3, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								List list4;
								Init(list4);
								int x = docFileBinary(list4);
								sapXepQuicksort_NgaySinh(list4);
								clrscr();
								system("color 7");
								FrameKetQua(list4, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 3:
					  {
								system("color 7");
								List list5;
								Init(list5);
								int x = docFileBinary(list5);
								sapXepQuicksort_Diem(list5);
								clrscr();
								system("color 7");
								FrameKetQua(list5, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 4:
					  {
								return tt;
								clrscr();
								system("color 7");
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < sothaotac; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	clrscr();
}
int SapXepChenDanhSachTheoTuKhoa(int sothaotac)
{
	clrscr();
	system("color 7");
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[sothaotac];
	for (int i = 0; i < sothaotac; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameSapXepTheoTuKhoa();
	char S2[] = "1. MA LOP SINH VIEN";
	char S3[] = "2. HO TEN SINH VIEN";
	char S4[] = "3. NGAY SINH SINH VIEN";
	char S5[] = "4. DIEM TRUNG BINH SINH VIEN";
	char S6[] = "5.THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < sothaotac; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S2); i++)
				{
					printf("%c", S2[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
			if (i == 4)
			{
				TextColor(mau[i]);
				gotoxy(50, 26);
				for (int i = 0; i < strlen(S6); i++)
				{
					printf("%c", S6[i]);
				}
			}
		}
		nambat = _getch();
		trangthai = Key(nambat);
		switch (trangthai)
		{
		case UP:
		{
				   if (tt == 0)
				   {
					   tt = sothaotac - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == sothaotac - 1)
					 {
						 tt = 0;
					 }
					 else
					 {
						 tt++;
					 }
					 break;
		}
		case ENTER:
		{
					  switch (tt)
					  {
					  case 0:
					  {
								system("color 7");
								List list6;
								Init(list6);
								int x = docFileBinary(list6);
								sapXepChen_MaLop(list6);
								clrscr();
								FrameKetQua(list6, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								List list7;
								Init(list7);
								int x = docFileBinary(list7);
								sapXepChen_Ten(list7);
								clrscr();
								FrameKetQua(list7, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								List list8;
								Init(list8);
								int x = docFileBinary(list8);
								sapXepChen_NgaySinh(list8);
								clrscr();
								FrameKetQua(list8, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 3:
					  {
								system("color 7");
								List list9;
								Init(list9);
								int x = docFileBinary(list9);
								sapXepChen_Diem(list9);
								clrscr();
								FrameKetQua(list9, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 4:
					  {
								return tt;
								clrscr();
								system("color 7");
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < sothaotac; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	clrscr();
}
int SapXepNoiBotDanhSachTheoTuKhoa(int sothaotac)
{
	clrscr();
	system("color 7");
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[sothaotac];
	for (int i = 0; i < sothaotac; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameSapXepTheoTuKhoa();
	char S2[] = "1. MA LOP SINH VIEN";
	char S3[] = "2. HO TEN SINH VIEN";
	char S4[] = "3. NGAY SINH SINH VIEN";
	char S5[] = "4. DIEM TRUNG BINH SINH VIEN";
	char S6[] = "5.THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < sothaotac; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S2); i++)
				{
					printf("%c", S2[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
			if (i == 4)
			{
				TextColor(mau[i]);
				gotoxy(50, 26);
				for (int i = 0; i < strlen(S6); i++)
				{
					printf("%c", S6[i]);
				}
			}
		}
		nambat = _getch();
		trangthai = Key(nambat);
		switch (trangthai)
		{
		case UP:
		{
				   if (tt == 0)
				   {
					   tt = sothaotac - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == sothaotac - 1)
					 {
						 tt = 0;
					 }
					 else
					 {
						 tt++;
					 }
					 break;
		}
		case ENTER:
		{
					  switch (tt)
					  {
					  case 0:
					  {
								system("color 7");
								List list10;
								Init(list10);
								int x = docFileBinary(list10);
								sapXepNoiBot_MaLop(list10);
								clrscr();
								FrameKetQua(list10, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								List list11;
								Init(list11);
								int x = docFileBinary(list11);
								sapXepNoiBot_Ten(list11);
								clrscr();
								FrameKetQua(list11, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								List list12;
								Init(list12);
								int x = docFileBinary(list12);
								sapXepNoiBot_NgaySinh(list12);
								clrscr();
								FrameKetQua(list12, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 3:
					  {
								system("color 7");
								List list13;
								Init(list13);
								int x = docFileBinary(list13);
								sapXepNoiBot_Diem(list13);
								clrscr();
								FrameKetQua(list13, x, 1);
								clrscr();
								system("color 7");
								FrameSapXepTheoTuKhoa();
								break;
					  }
					  case 4:
					  {
								return tt;
								clrscr();
								system("color 7");
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < sothaotac; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	clrscr();
}
void FrameSapXep()
{
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "SAP XEP DANH SACH SINH VIEN";
	TextColor(13);
	for (int x = 0; x < strlen(S1); x++)
	{
		gotoxy(45 + x, 5);
		printf("%c", S1[x]);
	}
	TextColor(10);
	for (int y = 0; y < 37; y++)
	{
		gotoxy(40 + y, 7);
		printf("%c", tru);
	}
	TextColor(10);
	for (int i = 0; i < 66; i++)
	{
		gotoxy(26 + i, 9);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 18; i++)
	{
		gotoxy(93, 9 + i);
		printf("%c", cong);
	}
	for (int i = 0; i < 68; i++)
	{
		gotoxy(94 - i, 27);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 19; i++)
	{
		gotoxy(25, 27 - i);
		printf("%c", cong);
	}
	TextColor(12);
	while (i <= 4)
	{
		for (int j = 24; j < 91; j++)
		{
			gotoxy(j + 2, 12 + i1);
			printf("%c", 205);
		}
		i1 += 3;
		i++;
	}
}
int SapXepDanhSach(int sothaotac)
{
	clrscr();
	system("color 7");
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[sothaotac];
	for (int i = 0; i < sothaotac; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameSapXep();
	char S2[] = "1. THUAT TOAN SAP XEP QUICKSORT";
	char S3[] = "2. THUAT TOAN SAP XEP CHEN";
	char S4[] = "3. THUAT TOAN SAP XEP NOI BOT";
	char S5[] = "4.THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < sothaotac; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S2); i++)
				{
					printf("%c", S2[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
		}
		nambat = _getch();
		trangthai = Key(nambat);
		switch (trangthai)
		{
		case UP:
		{
				   if (tt == 0)
				   {
					   tt = sothaotac - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == sothaotac - 1)
					 {
						 tt = 0;
					 }
					 else
					 {
						 tt++;
					 }
					 break;
		}
		case ENTER:
		{
					  switch (tt)
					  {
					  case 0:
					  {
								system("color 7");
								SapXepQuicksortDanhSachTheoTuKhoa(5);
								clrscr();
								system("color 7");
								FrameSapXep();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								SapXepChenDanhSachTheoTuKhoa(5);
								clrscr();
								system("color 7");
								FrameSapXep();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								SapXepNoiBotDanhSachTheoTuKhoa(5);
								clrscr();
								system("color 7");
								FrameSapXep();
								break;
					  }
					  case 3:
					  {
								return tt;
								clrscr();
								system("color 7");
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < sothaotac; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	clrscr();
}

void FrameNhapTuKhoaTimKiem()
{
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "  Nhap tu khoa can tim kiem : ";
	TextColor(12);
	for (int i = 0; i < 66; i++)
	{
		gotoxy(26 + i, 1);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(93, 1 + i);
		printf("%c", cong);
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(25, 4 - i);
		printf("%c", cong);
	}
	for (int j = 24; j < 91; j++)
	{
		gotoxy(j + 2, 4);
		printf("%c", 205);
	}
	TextColor(10);
	gotoxy(26, 3);
	for (int i = 0; i < strlen(S1); i++)
	{
		printf("%c", S1[i]);
	}
}
void FrameTimKiemTheoTuKhoa()
{
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "CHON TU KHOA TIM KIEM SINH VIEN";
	TextColor(13);
	for (int x = 0; x < strlen(S1); x++)
	{
		gotoxy(45 + x, 5);
		printf("%c", S1[x]);
	}
	TextColor(10);
	for (int y = 0; y < 40; y++)
	{
		gotoxy(40 + y, 7);
		printf("%c", tru);
	}
	TextColor(10);
	for (int i = 0; i < 66; i++)
	{
		gotoxy(26 + i, 9);
		if (i % 2 == 1)
		{
			printf("%c", cong);
		}
		else
		{
			printf(" ");
		}
	}
	for (int i = 0; i < 25; i++)
	{
		gotoxy(93, 9 + i);
		printf("%c", cong);
	}
	for (int i = 0; i < 25; i++)
	{
		gotoxy(25, 33 - i);
		printf("%c", cong);
	}
	TextColor(12);
	while (i <= 7)
	{
		for (int j = 24; j < 91; j++)
		{
			gotoxy(j + 2, 12 + i1);
			printf("%c", 205);
		}
		i1 += 3;
		i++;
	}
}
int TimKiemTheoTuKhoa(int sothaotac)
{
	clrscr();
	system("color 7");
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[sothaotac];
	for (int i = 0; i < sothaotac; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameTimKiemTheoTuKhoa();
	char S1[] = "1. MA LOP SINH VIEN";
	char S2[] = "2. MA SINH VIEN";
	char S3[] = "3. HO TEN SINH VIEN";
	char S4[] = "4. NGAY SINH CUA SINH VIEN";
	char S5[] = "5. THANG SINH CUA SINH VIEN";
	char S6[] = "6. NAM SINH CUA SINH VIEN";
	char S7[] = "7. DIEM TRUNG BINH SINH VIEN";
	char S8[] = "8.THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < sothaotac; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 11);
				for (int i = 0; i < strlen(S1); i++)
				{
					printf("%c", S1[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S2); i++)
				{
					printf("%c", S2[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 4)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
			if (i == 5)
			{
				TextColor(mau[i]);
				gotoxy(50, 26);
				for (int i = 0; i < strlen(S6); i++)
				{
					printf("%c", S6[i]);
				}
			}
			if (i == 6)
			{
				TextColor(mau[i]);
				gotoxy(50, 29);
				for (int i = 0; i < strlen(S7); i++)
				{
					printf("%c", S7[i]);
				}
			}
			if (i == 7)
			{
				TextColor(mau[i]);
				gotoxy(50, 32);
				for (int i = 0; i < strlen(S8); i++)
				{
					printf("%c", S8[i]);
				}
			}
		}
		nambat = _getch();
		trangthai = Key(nambat);
		switch (trangthai)
		{
		case UP:
		{
				   if (tt == 0)
				   {
					   tt = sothaotac - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == sothaotac - 1)
					 {
						 tt = 0;
					 }
					 else
					 {
						 tt++;
					 }
					 break;
		}
		case ENTER:
		{
					  switch (tt)
					  {
					  case 0:
					  {
								system("color 7");
								clrscr();
								char malop[100];
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								gets_s(malop);
								chuanHoa_MaLop(malop);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_MaLop(malop, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								clrscr();
								char masv[100];
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								gets_s(masv);
								chuanHoa_MaSinhVien(masv);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_MaSinhVien(masv, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								clrscr();
								char ten[100];
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								gets_s(ten);
								chuanHoa_HoTen(ten);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_Ten(ten, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 3:
					  {
								system("color 7");
								clrscr();
								int birthday;
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								scanf_s("%d", &birthday);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_Day(birthday, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 4:
					  {
								system("color 7");
								clrscr();
								int birthmonth;
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								scanf_s("%d", &birthmonth);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_Month(birthmonth, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 5:
					  {
								system("color 7");
								clrscr();
								int birthyear;
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								scanf_s("%d", &birthyear);
								List list1;
								Init(list1);
								docFileBinary(list1);
								timKiemTuanTu_Year(birthyear, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 6:
					  {
								system("color 7");
								clrscr();
								float score;
								FrameNhapTuKhoaTimKiem();
								gotoxy(58, 3);
								scanf_s("%f", &score);
								List list1;
								Init(list1);
								docFileBinary(list1);
								chuanHoa_Diem(score);
								timKiemTuanTu_Diem(score, list1);
								clrscr();
								system("color 7");
								FrameTimKiemTheoTuKhoa();
								break;
					  }
					  case 7:
					  {
								return tt;
								system("color 7");
								clrscr();
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < sothaotac; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	clrscr();
}

void FrameThongKe()
{
	TextColor(12);
	gotoxy(48, 4);
	printf("BANG THONG KE HOC TAP");
	TextColor(11);
	for (int y = 0; y < 37; y++)
	{
		gotoxy(40 + y, 5);
		printf("%c", 45);
	}
	TextColor(10);
	for (int i = 13; i <= 105; i++)
	{
		gotoxy(i, 6);
		printf("%c", 45);
	}
	for (int i = 13; i <= 105; i++)
	{
		gotoxy(i, 35);
		printf("%c", 45);
	}

	for (int i = 6; i <= 38; i++)
	{
		gotoxy(13, i);
		printf("%c", 43);
	}

	for (int i = 6; i <= 38; i++)
	{
		gotoxy(105, i);
		printf("%c", 43);
	}
	for (int i = 13; i <= 105; i++)
	{
		gotoxy(i, 38);
		printf("%c", 45);
	}
	TextColor(12);
	gotoxy(22, 36); 	printf("Yeu");
	TextColor(11);
	gotoxy(37, 36); 	printf("TrungBinh");
	TextColor(14);
	gotoxy(59, 36);		printf("Kha");
	TextColor(13);
	gotoxy(75, 36);		printf("Gioi");
	TextColor(9);
	gotoxy(92, 36);		printf("XuatSac");
}
void ThongKeBaoCao()
{
	clrscr();
	system("color 7");
	AnConTro();
	List l;
	Init(l);
	int x = docFileBinary(l);
	int i;
	int XuatSac = 0;
	int Gioi = 0;
	int Kha = 0;
	int Yeu = 0;
	int TrungBinh = 0;
	float tileXuatSac;
	float tileGioi;
	float tileKha;
	float tileTrungBinh;
	float tileYeu;
	Node *P = l.head;
	while (P != NULL)
	{
		if (P->sv.DiemTB >= 9)
		{
			XuatSac++;
		}
		else if (P->sv.DiemTB >= 8)
		{
			Gioi++;
		}
		else if (P->sv.DiemTB >= 6.5)
		{
			Kha++;
		}
		else if (P->sv.DiemTB >= 4.5)
		{
			TrungBinh++;
		}
		else
		{
			Yeu++;
		}
		P = P->Next;
	}
	tileXuatSac = (float)XuatSac / x * 100;
	tileGioi = (float)Gioi / x * 100;
	tileKha = (float)Kha / x * 100;
	tileTrungBinh = (float)TrungBinh / x * 100;
	tileYeu = (float)Yeu / x * 100;
	FrameThongKe();
	TextColor(12);
	for (i = 0; i<tileYeu / 4.5; i++)
	{
		gotoxy(23, 33 - i);
		printf("%c%c%c", 219, 219, 219);
		Sleep(15);
	}
	gotoxy(23, 33 - i);
	printf("%0.1f%c", tileYeu, 37);
	TextColor(11);
	for (i = 0; i<tileTrungBinh / 4.5; i++)
	{
		gotoxy(40.5, 33 - i);
		printf("%c%c%c", 219, 219, 219);
		Sleep(15);
	}
	gotoxy(39, 33 - i);
	printf("%0.1f%c", tileTrungBinh, 37);
	TextColor(14);
	for (i = 0; i<tileKha / 4.5; i++)
	{
		gotoxy(59, 33 - i);
		printf("%c%c%c", 219, 219, 219);
		Sleep(15);
	}
	gotoxy(58, 33 - i);
	printf("%0.1f%c", tileKha, 37);
	TextColor(13);
	for (i = 0; i<tileGioi / 4.5; i++)
	{
		gotoxy(75, 33 - i);
		printf("%c%c%c", 219, 219, 219);
		Sleep(15);
	}
	gotoxy(75, 33 - i);
	printf("%0.1f%c", tileGioi, 37);
	TextColor(9);
	for (i = 0; i<tileXuatSac / 4.5; i++)
	{
		gotoxy(93, 33 - i);
		printf("%c%c%c", 219, 219, 219);
		Sleep(15);
	}
	gotoxy(93, 33 - i);
	printf("%0.1f%c", tileXuatSac, 37);
	_getch();
}
