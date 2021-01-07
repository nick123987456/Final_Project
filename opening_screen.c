int Opening_screen()
{
	int ch, number = 1, number1 = 1;
	while (number == 1)
	{
		system("CLS");
		printf("========================================\n");
		printf("\t\t村民大冒險\n");
		printf("========================================\n\n");
		if (number1)
		{
			printf("\t開始遊戲←\t離開遊戲");
		}
		else
		{
			printf("\t開始遊戲\t離開遊戲←");
		}

		if ((ch = getch()) == 224)
		{
			if ((ch = getch()) == 77)
			{
				number1 = 0;
			}
			else if (ch == 75)
			{
				number1 = 1;
			}
		}
		else if (ch == 13)
		{
			number = 0;
		}
	}
	return number1;
}