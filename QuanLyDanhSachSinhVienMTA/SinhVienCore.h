#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdlib.h> // thu vien cap phat bo nho
#include <fstream> // thu vien doc ghi file
#include <iostream>
#include <ctype.h>
#include <string.h>
#include "key.h"
#include "console.h"

#define MAUNEN 30
#define MAUCHU 3

#define FileBinary "QuanLyDanhSachSinhVien.dat"
#define FileText "QuanLyDanhSachSinhVien.txt"

using namespace std;
int STT = 1;

struct Name {
	char FirstName[20];
	char LastName[10];
};
struct SinhVien {
	char MaLop[20];
	char MSV[20];
	Name Ten;
	int day;
	int month;
	int year;
	float DiemTB;
};
struct Node {
	SinhVien sv;
	Node *Next;
	Node *Previous;
};
struct List {
	Node *head;
	Node *tail;
};

void Init(List &l); //khoi tao List
bool isEmpty(List l); // kiem tra List rong
Node *creatNode(SinhVien sv); // khoi tao node
Node *creatNode_Mid(Node *l, Node  *r); // khoi tai node tai vi tri giua 
void addHead(List &l, Node *p); // them dau
void addTail(List &l, Node *p); // them cuoi
int length(List l); // lay do dai list
void delete_k(List &l, int k); //xoa sinh vien tai vi tri k
// CAC HAM HO TRO
void chuanHoa_MaLop(char *s); // chuan hoa ma lop sinh vien
void chuanHoa_MaSinhVien(char *s); // chuan hoa ma sinh vien
void chuanHoa_HoTen(char *s); // chuan hoa ten sinh vien
int chuanHoa_Diem(float a); // chuan hoa diem sinh vien
int dinhDang_NgaySinh(SinhVien sv); // dinh dang ngay
// SAP XEP SINH VIEN
void sapXepQuicksort_MaLop(List &l);
void sapXepQuicksort_Ten(List &l);
void sapXepQuicksort_NgaySinh(List &l);
void sapXepQuicksort_Diem(List &l);

void sapXepNoiBot_MaLop(List &L);
void sapXepNoiBot_Ten(List &L);
void sapXepNoiBot_NgaySinh(List &L);
void sapXepNoiBot_Diem(List &L);

void sapXepChen_MaLop(List &L);
void sapXepChen_Ten(List &L);
void sapXepChen_NgaySinh(List &L);
void sapXepChen_Diem(List &L);
// TIM KIEM SINH VIEN
void timKiemTuanTu_MaLop(char malop[], List L);
void timKiemTuanTu_MaSinhVien(char masv[], List L);
void timKiemTuanTu_Ten(char ten[], List L);
void timKiemTuanTu_Day(int birthday, List L);
void timKiemTuanTu_Month(int birthmonth, List L);
void timKiemTuanTu_Year(int birthyear, List L);
void timKiemTuanTu_Diem(float diem, List L);

///////////////////////////////////////////////////////////
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void AnConTro() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void FrameTimKiemLoi() {
	TextColor(12);
	for (int j = 7; j<10; j++) {
		gotoxy(30, j + 3);
		printf("%c", 179);
	}
	for (int j = 7; j<10; j++) {
		gotoxy(90, j + 3);
		printf("%c", 179);
	}
	for (int j = 1; j<60; j++) {
		gotoxy(j + 30, 9);
		printf("%c", 205);
	}
	for (int j = 1; j<60; j++) {
		gotoxy(j + 30, 13);
		printf("%c", 205);
	}
	TextColor(14);
	gotoxy(50, 11);
	printf("Khong Tim Thay Sinh Vien!!!");
	AnConTro();
	_getch();
}

void Init(List &l) {
	l.head = l.tail = NULL;
}
bool isEmpty(List l) {
	if (l.head == NULL) {
		return 1;
	}
	return 0;
}
Node *creatNode(SinhVien sv) {
	Node *p = new Node();
	if (p == NULL)
		return NULL;
	else {
		p->sv = sv;
		p->Next = NULL;
		p->Previous = NULL;
	}
	return p;
}
Node *creatNode_Mid(Node *l, Node  *r) {
	if (r == l || l->Next == r)
		return l;
	int i = 0;
	int k = 0;
	Node *p = l;
	while (p != r) {
		p = p->Next;
		i++;
	}
	p = l;
	while (k <= (int)i/2){
		p = p->Next;
		k++;
	}
	return p;
}
void addHead(List &l, Node *p) {
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		l.head->Previous = p;
		p->Next = l.head;
		p->Previous = NULL;
		l.head = p;
	}
}
void addTail(List &l, Node *p) {
	if (l.head == NULL)
		l.tail = l.head = p;
	else {
		l.tail->Next = p;
		p->Previous = l.tail;
		p->Next = NULL;
		l.tail = p;
	}
}
int length(List l) {
	int count = 0;
	Node *P = l.head;
	while (P != NULL) {
		count++;
		P = P->Next;
	}
	return count;
}

// Ham ho tro
void chuanHoa_MaLop(char *s) {
	char *a;
	while (s[0] == ' ') {
		strcpy(&s[0], &s[1]);
	}
	while (s[strlen(s) - 1] == ' ') {
		s[strlen(s) - 1] = '\0';
	}
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] == ' ' && s[i + 1] != ' ') {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	for (int i = 0; i<strlen(s); i++) {
		s[i] = toupper(s[i]);
	}
}
void chuanHoa_MaSinhVien(char *s) {
	for (int i = 0; i<strlen(s); i++) {
		s[i] = toupper(s[i]);
	}
}
int kiemTranTrung_MaSinhVien(char masv[], List L) {
	Node *P = L.head;
	int i = 0;
	char *results;
	while (P != NULL) {
		results = strstr(P->sv.MSV, masv);
		if (results != NULL) {
			i++;
		}
		P = P->Next;
	}
	return i;
}///////////////////////////
void chuanHoa_HoTen(char *s) {
	while (s[0] == ' ') {
		strcpy(&s[0], &s[1]);
	}
	while (s[strlen(s) - 1] == ' ') {
		s[strlen(s) - 1] = '\0';
	}
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	s[0] = toupper(s[0]);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			s[i + 1] = toupper(s[i + 1]);
	}
}
int chuanHoa_Diem(float a) {
	if (a > 10 || a <0)
		return 0;
	else
		return 1;
}
int dinhDang_NgaySinh(SinhVien sv) {
	if (sv.year<1930 || sv.year>2017) {
		return 0;
	}
	else {
		if (sv.year % 4 != 0 || ((sv.year % 4 == 0) && (sv.year % 100 == 0))) {
			if (sv.month > 12 || sv.month <= 0) {
				return 0;
			}
			else {
				if (sv.month == 1 || sv.month == 3 || sv.month == 5 || sv.month == 7 || sv.month == 8 || sv.month == 10 || sv.month == 12) {
					if (sv.day > 31)
						return 0;
					else
						return 1;
				}
				else if (sv.month == 2) {
					if (sv.day > 28)
						return 0;
					else
						return 1;
				}
				else {
					if (sv.day > 30)
						return 0;
					else
						return 1;
				}
			}
		}
		else {
			if (sv.month > 12 || sv.month <= 0) {
				return 0;
			}
			else {
				if (sv.month == 1 || sv.month == 3 || sv.month == 5 || sv.month == 7 || sv.month == 8 || sv.month == 10 || sv.month == 12) {
					if (sv.day > 31)
						return 0;
					else
						return 1;
				}
				else if (sv.month == 2) {
					if (sv.day > 29)
						return 0;
					else
						return 1;
				}
				else {
					if (sv.day > 30)
						return 0;
					else
						return 1;
				}
			}
		}
	}
}
// Thuat toan sap xep quicksort
void sapXepQuicksort_MaLop(List &l) {
	List l1, l2;
	Node *tag, *p;
	if (l.head == l.tail)
		return;
	Init(l1);
	Init(l2);
	tag = l.head;
	l.head = l.head->Next;
	tag->Next = NULL;// co lap tag
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->Next;
		p->Next = NULL;
		int k = 0;
		while (1) {
			if (p->sv.MaLop[k] < tag->sv.MaLop[k]) {
				addHead(l1, p);
				break;
			}
			else if (p->sv.MaLop[k] == tag->sv.MaLop[k]) {
				k++;
			}
			else {
				addHead(l2, p);
				break;
			}
		}
	}
	sapXepQuicksort_MaLop(l1);
	sapXepQuicksort_MaLop(l2);
	if (l1.head != NULL) {
		l.head = l1.head;
		l1.tail->Next = tag;
	} // l1 rong 
	else l.head = tag;
	tag->Next = l2.head;
	if (l2.head != NULL) l.tail = l2.tail;
	else l.tail = tag;
}
void sapXepQuicksort_Ten(List &l) {
	List l1, l2;
	Node *tag, *p;
	if (l.head == l.tail)
		return;
	Init(l1);
	Init(l2);
	tag = l.head;
	l.head = l.head->Next;
	tag->Next = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->Next;
		p->Next = NULL;
		int k = 0;
		while (k<6) {
			if (p->sv.Ten.LastName[k] < tag->sv.Ten.LastName[k]) {
				addHead(l1, p);
				break;
			}
			if (p->sv.Ten.LastName[k] == tag->sv.Ten.LastName[k]) {
				k++;
			}
			else {
				addTail(l2, p);
				break;
			}
		}
		if (k == 6)
			addHead(l1, p);
	}
	sapXepQuicksort_Ten(l1);
	sapXepQuicksort_Ten(l2);
	if (l1.head != NULL) {
		l.head = l1.head;
		l1.tail->Next = tag;
	}
	else l.head = tag;
	tag->Next = l2.head;
	if (l2.head != NULL) {
		l.tail = l2.tail;
		l2.head->Previous = tag;
	}
	else l.tail = tag;
}
void sapXepQuicksort_NgaySinh(List &l)
{
	List l1, l2;
	Node *tag, *p;
	if (l.head == l.tail)
		return;
	Init(l1);
	Init(l2);
	tag = l.head;
	l.head = l.head->Next;
	tag->Next = NULL;// co lap tag
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->Next;
		p->Next = NULL;
		if (p->sv.year < tag->sv.year) {
			addTail(l2, p);
		}
		else if (p->sv.year == tag->sv.year) {
			if (p->sv.month < tag->sv.month) {
				addTail(l2, p);
			}
			else if (p->sv.month == tag->sv.month) {
				if (p->sv.day <= tag->sv.day) {
					addTail(l2, p);
				}
				else {
					addHead(l1, p);
				}
			}
			else {
				addHead(l1, p);
			}
		}
		else{
			addHead(l1, p);
		}
	}
	sapXepQuicksort_NgaySinh(l1);
	sapXepQuicksort_NgaySinh(l2);
	if (l1.head != NULL) {
		l.head = l1.head;
		l1.tail->Next = tag;
	} // l1 rong 
	else l.head = tag;
	tag->Next = l2.head;
	if (l2.head != NULL) l.tail = l2.tail;
	else l.tail = tag;
}
void sapXepQuicksort_Diem(List &l)
{
	List l1, l2;
	Node *tag, *p;
	if (l.head == l.tail)
		return;
	Init(l1);
	Init(l2);
	tag = l.head;
	l.head = l.head->Next;
	tag->Next = NULL;// co lap tag
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->Next;
		p->Next = NULL;
		if (p->sv.DiemTB >= tag->sv.DiemTB)
			addHead(l1, p);
		else addTail(l2, p);
	}
	sapXepQuicksort_Diem(l1);
	sapXepQuicksort_Diem(l2);
	if (l1.head != NULL) {
		l.head = l1.head;
		l1.tail->Next = tag;
	} // l1 rong 
	else l.head = tag;
	tag->Next = l2.head;
	if (l2.head != NULL) l.tail = l2.tail;
	else l.tail = tag;
}
// Thuat toan sap xep noi bot
void swap(SinhVien &sv1, SinhVien &sv2) {
	SinhVien sv = sv1;
	sv1 = sv2;
	sv2 = sv;
}
void sapXepNoiBot_MaLop(List &L) {
	for (Node *i = L.head; i != L.tail; i = i->Next) {
		for (Node *j = i->Next; j != NULL; j = j->Next) {
			int k = 0;
			while (k<6) {
				if (j->sv.MaLop[k] < i->sv.MaLop[k]) {
					swap(i->sv, j->sv);
					break;
				}
				if (i->sv.MaLop[k] == j->sv.MaLop[k]) {
					k++;
				}
				else
					break;
			}
		}
	}
}
void sapXepNoiBot_Ten(List &L) {
	for (Node *i = L.head; i != L.tail; i = i->Next) {
		for (Node *j = i->Next; j != NULL; j = j->Next) {
			int k = 0;
			while (k<6) {
				if (j->sv.Ten.LastName[k] < i->sv.Ten.LastName[k]) {
					swap(i->sv, j->sv);
					break;
				}
				if (i->sv.Ten.LastName[k] == j->sv.Ten.LastName[k]) {
					k++;
				}
				else
					break;
			}
		}
	}
}
void sapXepNoiBot_NgaySinh(List &L) {
	for (Node *i = L.head; i != L.tail; i = i->Next) {
		for (Node *j = i->Next; j != NULL; j = j->Next) {
			if (i->sv.year < j->sv.year) {
				swap(i->sv, j->sv);
			}
			else if (i->sv.year == j->sv.year) {
				if (i->sv.month < j->sv.month) {
					swap(i->sv, j->sv);
				}
				else if (i->sv.month == j->sv.month) {
					if (i->sv.day < j->sv.day) {
						swap(i->sv, j->sv);
					}
				}
			}
		}
	}
}
void sapXepNoiBot_Diem(List &L) {
	for (Node *i = L.head; i != L.tail; i = i->Next) {
		for (Node *j = i->Next; j != NULL; j = j->Next) {
			if (i->sv.DiemTB < j->sv.DiemTB) {
				swap(i->sv, j->sv);
			}
		}
	}
}
// Thuat toan sap xep chen
void sapXepChen_MaLop(List &L) {
	Node *min, *p, *q;
	p = L.head;
	while (p != NULL) {
		q = p->Next;
		min = p;
		while (q != NULL) {
			int k = 0;
			while (k<6) {
				if (q->sv.MaLop[k] < min->sv.MaLop[k]) {
					min = q;
					break;
				}
				if (q->sv.MaLop[k] == min->sv.MaLop[k]) {
					k++;
				}
				else
					break;
			}
			q = q->Next;
		}
		swap(min->sv, p->sv);
		p = p->Next;
	}
}
void sapXepChen_Ten(List &L) {
	Node *min, *p, *q;
	p = L.head;
	while (p != NULL) {
		q = p->Next;
		min = p;
		while (q != NULL) {
			int k = 0;
			while (k<6) {
				if (q->sv.Ten.LastName[k] < min->sv.Ten.LastName[k]) {
					min = q;
					break;
				}
				if (q->sv.Ten.LastName[k] == min->sv.Ten.LastName[k]) {
					k++;
				}
				else
					break;
			}
			q = q->Next;
		}
		swap(min->sv, p->sv);
		p = p->Next;
	}
}
void sapXepChen_NgaySinh(List &L) {
	Node *min, *p, *q;
	p = L.head;
	while (p != NULL) {
		q = p->Next;
		min = p;
		while (q != NULL) {
			if (min->sv.year < q->sv.year) {
				min = q;
			}
			if (min->sv.year == q->sv.year) {
				if (min->sv.month < q->sv.month) {
					min = q;
				}
				if (min->sv.month == q->sv.month) {
					if (min->sv.day < q->sv.day) {
						min = q;
					}
				}
			}
			q = q->Next;
		}
		swap(min->sv, p->sv);
		p = p->Next;
	}
}
void sapXepChen_Diem(List &L) {
	Node *min, *p, *q;
	p = L.head;
	while (p != NULL) {
		q = p->Next;
		min = p;
		while (q != NULL) {
			if (q->sv.DiemTB > min->sv.DiemTB)
				min = q;
			q = q->Next;
		}
		swap(min->sv, p->sv);
		p = p->Next;
	}
}
// Thuat toan tim kiem tuan tu
Node *Stop = NULL;
void FrameKetQua(List L, int n, int lan) {
	int count = 0;
	TextColor(13);
	gotoxy(47, 5);		printf("---DANH SACH SINH VIEN---");
	TextColor(10);
	int i = 0;
	int i1 = 0;
	gotoxy(22, 7);		printf("STT");
	gotoxy(32, 7);		printf("Ten Sinh Vien");
	gotoxy(53, 7);		printf("Ma lop");
	gotoxy(64, 7);		printf("MSV");
	gotoxy(75, 7);		printf("Ngay sinh");
	gotoxy(92, 7);		printf("Diem TB");
	while (i <= (n + 1)) {
		for (int j = 0; j < 80; j++) {
			TextColor(12);
			if (i1 == 0 || i1 == 2 * (n + 1) || i1 == 2) {
				gotoxy(j + 20, 6 + i1);
				printf("%c", 205);
			}
			else {
				gotoxy(j + 20, 6 + i1);
				printf("-");
			}
		}
		if (i<n) {
			TextColor(14);
			gotoxy(23, 9 + i1);
			printf("%d", STT);
			STT++;
		}
		i1 += 2;
		i++;
	}
	i1 = 0;
	TextColor(MAUCHU);
	if (lan == 1) {
		Stop = L.head;
	}
	for (Node *p = Stop; count <n; p = p->Next)
	{
		gotoxy(32, 9 + i1);
		printf("%s %s", p->sv.Ten.FirstName, p->sv.Ten.LastName);
		gotoxy(53, 9 + i1);
		printf("%s", p->sv.MaLop);
		gotoxy(62, 9 + i1);
		printf("%s", p->sv.MSV);
		gotoxy(74, 9 + i1);
		if (p->sv.day <10) {
			if (p->sv.month <10) {
				printf("0%d/0%d/%d", p->sv.day, p->sv.month, p->sv.year);
			}
			else {
				printf("0%d/%d/%d", p->sv.day, p->sv.month, p->sv.year);
			}
		}
		else {
			if (p->sv.month <10) {
				printf("%d/0%d/%d", p->sv.day, p->sv.month, p->sv.year);
			}
			else {
				printf("%d/%d/%d", p->sv.day, p->sv.month, p->sv.year);
			}
		}
		gotoxy(93, 9 + i1);
		printf("%1.1f", p->sv.DiemTB);
		i1 += 2;
		count++;
		Stop = p->Next;
	}
	int i2 = 0;
	TextColor(12);
	for (int j = 0; j <= n; j++) {
		gotoxy(51, i2 + 7);
		printf("|");
		i2 += 2;
	}
	i2 = 0;
	for (int j = 0; j <= n; j++) {
		gotoxy(60, i2 + 7);
		printf("|");
		i2 += 2;
	}

	i2 = 0;
	for (int j = 0; j <= n; j++) {
		gotoxy(26, i2 + 7);
		printf("|");
		i2 += 2;
	}

	i2 = 0;
	for (int j = 0; j <= n; j++) {
		gotoxy(72, i2 + 7);
		printf("|");
		i2 += 2;
	}

	i2 = 0;
	for (int j = 0; j <= n; j++) {
		gotoxy(90, i2 + 7);
		printf("|");
		i2 += 2;
	}

	for (int j = 0; j <= 2 * n + 2; j++) {
		gotoxy(19, j + 6);
		printf("%c\n", 179);
	}
	for (int j = 0; j <= 2 * n + 2; j++) {
		gotoxy(100, j + 6);
		printf("%c\n", 179);
	}
	gotoxy(100, 6);		printf("%c", 184);
	gotoxy(19, 6);		printf("%c\n", 213);
	gotoxy(100, 8);		printf("%c", 190);
	gotoxy(100, 2 * (n + 1) + 6);		printf("%c", 190);
	gotoxy(19, 8);		printf("%c", 212);
	gotoxy(19, 2 * (n + 1) + 6);		printf("%c", 212);
	AnConTro();
	_getch();
}
void timKiemTuanTu_MaLop(char malop[], List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	char *results = {};
	while (P != NULL) {
		results = strstr(P->sv.MaLop, malop);
		if (results != NULL) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_MaSinhVien(char masv[], List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	char *results = {};
	while (P != NULL) {
		results = strstr(P->sv.MSV, masv);
		if (results != NULL) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_Ten(char ten[], List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	char *results = "";
	char *results1 = "";
	while (P != NULL) {
		results = strstr(P->sv.Ten.FirstName, ten);
		results1 = strstr(P->sv.Ten.LastName, ten);
		if (results != NULL || results1 != NULL) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_Day(int birthday, List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	while (P != NULL) {
		if (birthday == P->sv.day) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_Month(int birthmonth, List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	while (P != NULL) {
		if (birthmonth == P->sv.month) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_Year(int birthyear, List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	while (P != NULL) {
		if (birthyear == P->sv.year) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
void timKiemTuanTu_Diem(float diemtb, List L) {
	Node *P = L.head;
	int i = 0;
	List listSearch;
	Init(listSearch);
	while (P != NULL) {
		if (diemtb == P->sv.DiemTB) {
			Node *result = creatNode(P->sv);
			addTail(listSearch, result);
			i++;
		}
		P = P->Next;
	}
	if (i == 0) {
		FrameTimKiemLoi();
	}
	if (i != 0) {
		FrameKetQua(listSearch, i, 1);
	}
}
