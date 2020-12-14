// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

void drawBox()
{
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
	gotoxy(0, HEIGHT);
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << '|';
	}
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(WIDTH, i);
		cout << '|';
	}
}
bool isHitWall()
{
	return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == WIDTH || snake[0].y == HEIGHT;
}
bool isBiteItself()
{
	Point head = snake[0];
	for (size_t i = 1; i < snake.size(); i++)
		if (head.x == snake[i].x && head.y == snake[i].y)
			return true;
	return false;
}
void showEndMenu()
{
	system("cls");
	gotoxy(0, 0);
	cout << "KET THUC!" << endl;
	cout << "DIEM: " << score << endl;
	cout << "BAN CO MUON CHOI LAI ([y]/[n]): ";
	char option;
	cin >> option;
	option = tolower(option);
	if (option == 'y')
	{
		resetSnake();
		startGame();
	}
	else if (option == 'n')
		exit(1);
}
void showStartMenu()
{
	system("cls");
	cout << "snake game!" << endl;
	cout << "Options:" << endl;
	cout << "1. BAT DAU" << endl;
	cout << "2. THOAT" << endl;
	cout << "LUA CHON: ";
	int option;
	cin >> option;
	if (option == 1)
	{
		system("cls");
		cout << "CHON DO KHO (1 - 5): ";
		int t;
		cin >> t;
		speed = 600 - t * 100;
		system("cls");
		cout << "Tip: Trong luc choi ban co the bam T de thoat";
		gotoxy(0, 3);
		cout << "Ready!";
		Sleep(1000);
		for (size_t i = 3; i > 0; i--)
		{
			gotoxy(0, 3);
			cout << i << "         ";
			Sleep(1000);
		}
		gotoxy(0, 3);
		cout << "GO!";
		Sleep(1000);
		startGame();
	}
	else if (option == 2)
		exit(1);
}