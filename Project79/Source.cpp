#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h>

using namespace std;

enum Color {
	Black = 0, Blue, Green, Cyan, Red,
	Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan,
	LightRed, LightMagenta, Yellow, White
};

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, space = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(Color text, Color background) {
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y) {
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void showProb	(char **mas)
{
	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			mas[i][j] = ' '; 
		}
	}
}
	void show(char **mas, int x, int y)
{
	system("cls");
	for (size_t i = 0; i < 7; i++)
	{

		for (size_t j = 0; j < 7; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
			{
				SetColor(Blue, Blue);
			}
			else if (i == y && j == x)
			{
				SetColor(Black, Red);
			}
	

			cout << " " << mas[i][j];

			SetColor(White, Black);
		}

		cout << "\n";
	}

}
	void CompPlayer(char** mas)
	{
		int a;
		int b;
		bool  key1;
		key1 = true;
		do
		{
			a = (1 + rand() % 3) * 2 - 1;
			b = (1 + rand() % 3) * 2 - 1;
			if (mas[a][b] ==' ')
			{
				mas[a][b] = '0';
				key1 = false;
			}
		} while (key1!=false);
		
	}
	/*int ChekVictory(char **mas, int b)
	{

		int a;
		for (size_t i = 1; i < 3; i++)
		{
			a = (i * 2) - 1;
			if (mas[1][a] == mas[3][a] && mas[3][a] == mas[5][a]&&mas[1][a]!=' ')
			{
				b = 1;
			}
			else if (mas[a][1] == mas[a][3] && mas[a][1] == mas[a][5] && mas[1][a] != ' ')
			{
				b = 1;
			}
			else if (mas[1][1] == mas[3][3] && mas[1][1] == mas[5][5] && mas[1][a] != ' ')
			{
				b = 1;
			}
			else if (mas[1][5] == mas[3][3] && mas[1][5] == mas[5][1] && mas[1][a] != ' ')
			{
				b = 1;
			}
		}
		return b;
	}*/
	char Victory(char **mas,char c)
	{

		int a;
		for (size_t i = 1; i < 3; i++)
		{
			a = (i * 2) - 1;
			if (mas[1][a] == mas[3][a] && mas[3][a] == mas[5][a] && mas[1][a] != ' ')
			{
				c = mas[1][a];
			}
			else if (mas[a][1] == mas[a][3] && mas[a][1] == mas[a][5] && mas[1][a] != ' ')
			{
				c = mas[a][1];
			}
			else if (mas[1][1] == mas[3][3] && mas[1][1] == mas[5][5] && mas[1][a] != ' ')
			{
				c = mas[1][1];
			}
			else if (mas[1][5] == mas[3][3] && mas[1][5] == mas[5][1] && mas[1][a] != ' ')
			{
				c = mas[1][5];
			}
		}
		return c;
	}

int ActivPunct(char** mas, int x, int y)
{
	int key;
	int b=0;
	do
	{
		show(mas, x, y);
		cout << "\n\n\n\n" << x << "\t" << y;
		b = Victory(mas,b);
		if (b==1)
		{
			key = esc;

			break;
		}

		key = _getch();
		switch (key)
		{
		case Up:
			if (y > 2)
			{
				y -= 2;
			}
			else
			{
				y = 1;
			}
			break;
		case Down:
			if (y < 5)
			{
				y += 2;
			}
			else
			{
				y = 5;
			}
			break;
		case Right:
			if (x < 5)
			{
				x += 2;
			}
			else if (x<7)
			{
				x = 5;
			}
			break;
		case Left:
			if (x > 2)
			{
				x -= 2;
			}
			else if (x<2)
			{
				x = 1;
			}
			break;
		case Enter:
			if (mas[y][x]==' ')
			{
				mas[y][x] = 'X';
				CompPlayer(mas);
			}
			break;
			return(x, y);
		}
	} while (key != esc);
	return -1;
}
  
void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	char c=' ';
	const int row = 7, col = 7, x = 1, y = 1;
	char**mas = new char*[row];
	for (size_t i = 0; i < row; i++)
	{
		mas[i] = new char[col];
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{

			mas[i][j] = ' ';
		}
	}
	/*showProb(mas);*/
	show(mas, x, y);
	ActivPunct(mas, x, y);
	Victory(mas,c);
	cout << "Поздравляем победили - " << c<<mas;
}
