void Selection_screen(int number, int number1, int number2)
{
	if (number2 == 0)
	{
		if (number == 0)
		{
			printf("[蜘蛛出現了]\n");
			system("pause");
		}
		else if (number == 1)
		{
			printf("[骷弓出現了]\n");
			system("pause");
		}
		else if (number == 2)
		{
			printf("[殭屍出現了]\n");
			system("pause");
		}
	}
	else if (number2 == 1)
	{
		if (number1 == 0)
		{
			printf("[選擇技能]\n");
			printf("[1.防禦←\t2.普攻\t3.盲目打擊(*0 or*2)\t4.逃跑]");
		}
		else if (number1 == 1)
		{
			printf("[選擇技能]\n");
			printf("[1.防禦\t2.普攻←\t3.盲目打擊(*0 or*2)\t4.逃跑]");
		}
		else if (number1 == 2)
		{
			printf("[選擇技能]\n");
			printf("[1.防禦\t2.普攻\t3.盲目打擊(*0 or*2)←\t4.逃跑]");
		}
		else if (number1 == 3)
		{
			printf("[選擇技能]\n");
			printf("[1.防禦\t2.普攻\t3.盲目打擊(*0 or*2)\t4.逃跑←]");
		}
	}
}
