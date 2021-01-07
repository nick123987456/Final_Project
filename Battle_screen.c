void Battle_screen(int num, int *num1)
{
	Character_value monster[3] = { {"蜘蛛",5,5,20,10,15},{"骷弓",10,10,30,10,5},{"殭屍",15,15,30,5,5} };
	Character_value villager = {"冒險",50,50,10,5,5 };
	int i, number = 0, number1 = 0, number2 = 1, number3 = 0, number4 = 0,number6=0;//number記入鍵盤位子 number1記入戰鬥先後 number2記入一場戰鬥  number3記入狀態 number4記入生死 number6記入通關8隻
	int ch, ch1, number5 = 1;//number5記入GG畫面 
	Random_value(&villager);
	while (*num1)
	{
		i = rand() % 3;
		monster[i].hp = monster[i].max_hp;
		number6 = number6 + 1;
		while (number2)
		{
			if (number3 == 2)
			{
				if ((number == 0) && (number1 == 2))
				{
					if (ch1)
					{
						if (villager.def >= monster[i].atk)
						{
							villager.hp = villager.hp - 1;
						}
						else
						{
							villager.hp = villager.hp - (monster[i].atk - villager.def);
						}
					}
					villager.def = villager.def / 2;
					number1 = number1 + 1;
				}
				if (number1 == 0)
				{
					number1 = number1 + 1;
				}
				else if ((number == 0) && (number1 == 1))
				{
					villager.def = villager.def * 2;
					number1 = number1 + 1;
				}
				else if (((villager.spd < monster[i].spd) && (number1 == 1)) || ((villager.spd > monster[i].spd) && (number1 == 2)))
				{
					if (ch1)
					{
						villager.hp = villager.hp - (monster[i].atk - villager.def);
					}
					number1 = number1 + 1;
				}
				else if (((villager.spd > monster[i].spd) && (number1 == 1)) || ((villager.spd < monster[i].spd) && (number1 == 2)))
				{
					if ((number == 1) && ch1)
					{
						monster[i].hp = monster[i].hp - (villager.atk - monster[i].def);
					}
					else if ((number == 2) && ch1)
					{
						monster[i].hp = monster[i].hp - (((villager.atk) * 2) - monster[i].def);
					}
					number1 = number1 + 1;
				}
			}
			system("CLS");
			printf("%s\t%d/%d\n\n", monster[i].name, monster[i].hp, monster[i].max_hp);
			printf("%s%d號\t%d/%d\n\n", "冒險者", num - 1, villager.hp, villager.max_hp);
			Selection_screen(i, number, number3);
			if (number3 == 1)
			{
				if ((ch = getch()) == 224)
				{
					if (((ch = getch()) == 77) && (number < 3))
					{
						number = number + 1;
					}
					else if ((ch == 75) && (number > 0))
					{
						number = number - 1;
					}
				}
				else if (ch == 13)
				{
					number3 = number3 + 1;
				}
			}
			if ((number3 == 0))
			{
				number3 = number3 + 1;
			}
			else if ((number3 == 2) && (number1 > 0))
			{
				if ((number == 0) && (number1 == 1))
				{
					printf("[%s%d號使用了防禦]\n", "冒險者", num - 1);
					printf("[%s%d號防禦提升了]\n", "冒險者", num - 1);
					system("pause");
				}
				else if (number == 3)
				{
					printf("[%s%d號竟然逃跑了]\n", "冒險者", num - 1);
					number2 = 0;
					number4 = 1;
					system("pause");
				}
				else if (monster[i].hp <= 0)
				{
					printf("[%s掛掉了]\n", monster[i].name);
					number2 = 0;
					system("pause");
				}
				else if (villager.hp <= 0)
				{
					printf("[%s%d號掛掉了]\n", "冒險者", num - 1);
					number2 = 0;
					number4 = 1;
					system("pause");
				}
				else if (((villager.spd < monster[i].spd) && (number1 == 1)) || ((villager.spd >= monster[i].spd) && (number1 == 2)) || ((number == 0) && (number1 == 2)))
				{
					printf("[%s發動了攻擊]\n", monster[i].name);
					if (ch1 = (rand() % 5))
					{
						if (villager.def >= monster[i].atk)
						{
							printf("[對%s%d號造成了%d點傷害]\n", "冒險者", num - 1, 1);
						}
						else
						{
						printf("[對%s%d號造成了%d點傷害]\n", "冒險者", num - 1, monster[i].atk - villager.def);
						}
					}
					else
					{
						printf("[%s竟然打歪了]\n", monster[i].name);
					}
					system("pause");
				}
				else if (((villager.spd >= monster[i].spd) && (number1 == 1)) || ((villager.spd < monster[i].spd) && (number1 == 2)))
				{
					if (number == 1)
					{
						printf("[%s%d號使用了普攻]\n", "冒險者", num - 1);
						if (ch1 = (rand() % 5))
						{
							printf("[對%s造成了%d點傷害]\n", monster[i].name, villager.atk - monster[i].def);
						}
						else
						{
							printf("[%s%d號竟然打歪了]\n", "冒險者", num - 1);
						}
					}
					else if (number == 2)
					{
						printf("[%s%d號使用了盲目打擊]\n", "冒險者", num - 1);
						if (ch1 = (rand() % 2))
						{
							printf("[%s%d號攻擊命中]\n", "冒險者", num - 1);
							printf("[對%s造成了%d點傷害]\n", monster[i].name, ((villager.atk) * 2) - monster[i].def);
						}
						else
						{
							printf("[%s%d號竟然打歪了]\n", "冒險者", num - 1);
						}
					}
					system("pause");
				}
				else if (number1 == 3)
				{
					number1 = 0;
					number3 = 1;
				}
			}
		}
		if (number4)
		{
			number = 1;
			number5 = 1;
			while (number5)
			{
				system("CLS");
				printf("========================================\n");
				printf("\t\tGAME OVER\n");
				printf("========================================\n\n");
				if (number)
				{
					printf("\t繼續遊戲←\t結束遊戲");
				}
				else
				{
					printf("\t繼續遊戲\t結束遊戲←");
				}

				if ((ch = getch()) == 224)
				{
					if ((ch = getch()) == 77)
					{
						number = 0;
					}
					else if (ch == 75)
					{
						number = 1;
					}
				}
				else if (ch == 13)
				{
					number5 = 0;
				}

			}
			if (number)
			{
				Cutscenes(&num);
				Random_value(&villager);
				number1 = 0;
				number2 = 1;
				number3 = 0;
				number4 = 0;
				number6 = 0;
			}
			else
			{
				*num1 = 0;
			}
		}
		else if (number6 == 5)
		{
			number = 1;
			number5 = 1;
			while (number5)
			{
				system("CLS");
				printf("========================================\n");
				printf("\t\tYOU WIN\n");
				printf("========================================\n\n");
				if (number)
				{
					printf("\t繼續遊戲←\t結束遊戲");
				}
				else
				{
					printf("\t繼續遊戲\t結束遊戲←");
				}

				if ((ch = getch()) == 224)
				{
					if ((ch = getch()) == 77)
					{
						number = 0;
					}
					else if (ch == 75)
					{
						number = 1;
					}
				}
				else if (ch == 13)
				{
					number5 = 0;
				}
			}
			if (number)
			{
				Cutscenes(&num);
				Random_value(&villager);
				number1 = 0;
				number2 = 1;
				number3 = 0;
				number4 = 0;
				number6 = 0;
			}
			else
			{
				*num1 = 0;
			}
		}
		else
		{
			number1 = 0;
			number2 = 1;
			number3 = 0;
		}
	}
}
