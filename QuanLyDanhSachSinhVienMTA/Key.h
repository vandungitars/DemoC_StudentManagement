/* Ma ASCII:
enter: 13
phim len: 224 va 72
phim xuong: 224 va 80
phim trai: 75
phim phai: 77
*/
#include<stdio.h>
#include<conio.h>

enum Trangthai { UP, DOWN, LEFT, RIGHT, ENTER };
Trangthai Key(int z)
{
	if (z == 224)
	{
		char c;
		c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (z == 13)
		return ENTER;
}
