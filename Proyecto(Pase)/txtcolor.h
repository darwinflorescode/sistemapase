void gotoxy (int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void color (int fondo, int letra)
{
	int x = fondo * 16 + letra;
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), x);
}
