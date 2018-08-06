#include "SinhVienController.h"
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")
extern int dem;
extern int STT;
extern int dong;
extern int ktMaTrung;
extern int ktMaTrung;
extern Node *Stop;

void moDau()
{
	AnConTro();
	char tru = 45;
	char S1[] = "THUC TAP KY THUAT LAP TRINH";
	char ENTER[] = "PRESS ENTER TO CONTINUE. ";
	TextColor(12);
	for (int y = 0; y < strlen(S1); y++)
	{
		gotoxy(45 + y, 8);
		printf("%c", S1[y]);
		Sleep(20);
	}
	TextColor(13);
	for (int y = 0; y < 37; y++)
	{
		gotoxy(40 + y, 9);
		printf("%c", tru);
		Sleep(20);
	}
	TextColor(14);
	char S2[] = "Le Van Dung";
	char S3[] = "KHMT 15-3";
	char S4[] = "16150013";

	gotoxy(43, 15);
	printf("Ho Va Ten:    ");
	gotoxy(43, 17);
	printf("Lop:          ");
	gotoxy(43, 19);
	printf("Ma Sinh Vien: ");
	gotoxy(64, 15);
	TextColor(14);
	for (int i = 0; i < strlen(S2); i++)
	{
		printf("%c", S2[i]);
		Sleep(45);
	}
	TextColor(14);
	gotoxy(64, 17);
	for (int i = 0; i < strlen(S3); i++)
	{
		printf("%c", S3[i]);
		Sleep(45);
	}
	gotoxy(64, 19);
	for (int i = 0; i < strlen(S4); i++)
	{
		printf("%c", S4[i]);
		Sleep(45);
	}
	int i1 = 0;
	TextColor(6);
	do
	{
		gotoxy(45 + i1, 25);
		printf("%c", ENTER[i1]);
		Sleep(20);
		i1++;
		if (i1 == strlen(ENTER)) i1 = 0;
		AnConTro();
	} while (!_kbhit());
	_getch();
	clrscr();
}
void FrameMenu()
{
	int i = 0;
	int i1 = 0;
	char cong = 43;
	char tru = 45;
	char S1[] = "QUAN LY DANH SACH SINH VIEN";
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
	for (int i = 0; i < 24; i++)
	{
		gotoxy(93, 9 + i);
		printf("%c", cong);
	}
	for (int i = 0; i < 68; i++)
	{
		gotoxy(94 - i, 33);
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
		gotoxy(25, 33 - i);
		printf("%c", cong);
	}
	TextColor(12);
	while (i <= 6)
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
int Menu(int n)
{
	AnConTro();
	int nambat;
	Trangthai trangthai;
	int tt = 0; // bien chi dang o thao tac thu nhat
	int *mau = new int[n];
	for (int i = 0; i < n; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	FrameMenu();
	char S3[] = "THEM MOI HO SO SINH VIEN";
	char S4[] = "IN DANH SACH SINH VIEN";
	char S5[] = "SAP XEP DANH SACH SINH VIEN";
	char S6[] = "TIM KIEM SINH VIEN";
	char S7[] = "THONG KE SINH VIEN";
	char S8[] = "THOAT CHUONG TRINH";
	while (1) // vong lap dung lai khi ham tra ve gia tri
	{
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			if (i == 0)
			{
				TextColor(mau[i]);
				gotoxy(50, 14);
				for (int i = 0; i < strlen(S3); i++)
				{
					printf("%c", S3[i]);
				}
			}
			if (i == 1)
			{
				TextColor(mau[i]);
				gotoxy(50, 17);
				for (int i = 0; i < strlen(S4); i++)
				{
					printf("%c", S4[i]);
				}
			}
			if (i == 2)
			{
				TextColor(mau[i]);
				gotoxy(50, 20);
				for (int i = 0; i < strlen(S5); i++)
				{
					printf("%c", S5[i]);
				}
			}
			if (i == 3)
			{
				TextColor(mau[i]);
				gotoxy(50, 23);
				for (int i = 0; i < strlen(S6); i++)
				{
					printf("%c", S6[i]);
				}
			}
			if (i == 4)
			{
				TextColor(mau[i]);
				gotoxy(50, 26);
				for (int i = 0; i < strlen(S7); i++)
				{
					printf("%c", S7[i]);
				}
			}
			if (i == 5)
			{
				TextColor(mau[i]);
				gotoxy(50, 29);
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
					   tt = n - 1;
				   }
				   else
				   {
					   tt--;
				   }
				   break;
		}
		case DOWN:
		{
					 if (tt == n - 1)
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
								NhapSinhVien();
								FrameMenu();
								break;
					  }
					  case 1:
					  {
								system("color 7");
								Indanhsach();
								STT = 1;
								FrameMenu();
								break;
					  }
					  case 2:
					  {
								system("color 7");
								SapXepDanhSach(4);
								clrscr();
								system("color 7");
								FrameMenu();
								break;
					  }
					  case 3:
					  {
								system("color 7");
								TimKiemTheoTuKhoa(8);
								clrscr();
								system("color 7");
								FrameMenu();
								break;
					  }
					  case 4:
					  {
								system("color 7");
								ThongKeBaoCao();
								clrscr();
								system("color 7");
								FrameMenu();
								break;
					  }
					  case 5:
					  {
								return tt;
								clrscr();
								system("color 7");
								break;
					  }
					  }
		}
		}
		for (int i = 0; i < n; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
}

void main()
{
	PlaySound(TEXT("Van nho - Tuan Hung.wav"), NULL, SND_ASYNC);
	moDau();	
	Menu(6);
}