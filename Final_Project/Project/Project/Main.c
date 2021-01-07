#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


typedef struct character_value {
	char name[5];
	int max_hp;
	int hp;
	int atk;
	int def;
	int spd;
}Character_value;

int Opening_screen();
void Random_value(Character_value *p);
void Cutscenes(int *n);
void Battle_screen(int num, int *num1);
void Selection_screen(int number, int number1, int number2);


int main(void)
{
	int ch, number, number1 = 1;//number�����}�Y number1�O���ĴX��_�I�� 
	srand(time(NULL));
	number = Opening_screen();
	while (number)
	{
		Cutscenes(&number1);
		Battle_screen(number1, &number);
	}
	return 0;
}

int Opening_screen()
{
	int ch, number = 1, number1 = 1;
	while (number == 1)
	{
		system("CLS");
		printf("========================================\n");
		printf("\t\t�����j�_�I\n");
		printf("========================================\n\n");
		if (number1)
		{
			printf("\t�}�l�C����\t���}�C��");
		}
		else
		{
			printf("\t�}�l�C��\t���}�C����");
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

void Random_value(Character_value *p)
{
	p->hp = 50;
	p->atk = 10 + (rand() % 21);
	p->spd = 5 + (rand() % 11);
	p->def = 5 + (rand() % 11);
}

void Cutscenes(int *n)
{
	system("CLS");
	printf("�A�O�q�Ƥd�U�������U����@���_�I��\n�_�I��%d���A�}�l�A���_�I�a!\n", *n);
	*n = *n + 1;
	system("pause");
}
void Battle_screen(int num, int *num1)
{
	Character_value monster[3] = { {"�j��",5,5,20,10,15},{"�u�}",10,10,30,10,5},{"�L��",15,15,30,5,5} };
	Character_value villager = {"�_�I",50,50,10,5,5 };
	int i, number = 0, number1 = 0, number2 = 1, number3 = 0, number4 = 0,number6=0;//number�O�J��L��l number1�O�J�԰����� number2�O�J�@���԰�  number3�O�J���A number4�O�J�ͦ� number6�O�J�q��8��
	int ch, ch1, number5 = 1;//number5�O�JGG�e�� 
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
			printf("%s%d��\t%d/%d\n\n", "�_�I��", num - 1, villager.hp, villager.max_hp);
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
					printf("[%s%d���ϥΤF���m]\n", "�_�I��", num - 1);
					printf("[%s%d�����m���ɤF]\n", "�_�I��", num - 1);
					system("pause");
				}
				else if (number == 3)
				{
					printf("[%s%d�����M�k�]�F]\n", "�_�I��", num - 1);
					number2 = 0;
					number4 = 1;
					system("pause");
				}
				else if (monster[i].hp <= 0)
				{
					printf("[%s�����F]\n", monster[i].name);
					number2 = 0;
					system("pause");
				}
				else if (villager.hp <= 0)
				{
					printf("[%s%d�������F]\n", "�_�I��", num - 1);
					number2 = 0;
					number4 = 1;
					system("pause");
				}
				else if (((villager.spd < monster[i].spd) && (number1 == 1)) || ((villager.spd >= monster[i].spd) && (number1 == 2)) || ((number == 0) && (number1 == 2)))
				{
					printf("[%s�o�ʤF����]\n", monster[i].name);
					if (ch1 = (rand() % 5))
					{
						if (villager.def >= monster[i].atk)
						{
							printf("[��%s%d���y���F%d�I�ˮ`]\n", "�_�I��", num - 1, 1);
						}
						else
						{
						printf("[��%s%d���y���F%d�I�ˮ`]\n", "�_�I��", num - 1, monster[i].atk - villager.def);
						}
					}
					else
					{
						printf("[%s���M���n�F]\n", monster[i].name);
					}
					system("pause");
				}
				else if (((villager.spd >= monster[i].spd) && (number1 == 1)) || ((villager.spd < monster[i].spd) && (number1 == 2)))
				{
					if (number == 1)
					{
						printf("[%s%d���ϥΤF����]\n", "�_�I��", num - 1);
						if (ch1 = (rand() % 5))
						{
							printf("[��%s�y���F%d�I�ˮ`]\n", monster[i].name, villager.atk - monster[i].def);
						}
						else
						{
							printf("[%s%d�����M���n�F]\n", "�_�I��", num - 1);
						}
					}
					else if (number == 2)
					{
						printf("[%s%d���ϥΤF���إ���]\n", "�_�I��", num - 1);
						if (ch1 = (rand() % 2))
						{
							printf("[%s%d�������R��]\n", "�_�I��", num - 1);
							printf("[��%s�y���F%d�I�ˮ`]\n", monster[i].name, ((villager.atk) * 2) - monster[i].def);
						}
						else
						{
							printf("[%s%d�����M���n�F]\n", "�_�I��", num - 1);
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
					printf("\t�~��C����\t�����C��");
				}
				else
				{
					printf("\t�~��C��\t�����C����");
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
					printf("\t�~��C����\t�����C��");
				}
				else
				{
					printf("\t�~��C��\t�����C����");
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
void Selection_screen(int number, int number1, int number2)
{
	if (number2 == 0)
	{
		if (number == 0)
		{
			printf("[�j��X�{�F]\n");
			system("pause");
		}
		else if (number == 1)
		{
			printf("[�u�}�X�{�F]\n");
			system("pause");
		}
		else if (number == 2)
		{
			printf("[�L�ͥX�{�F]\n");
			system("pause");
		}
	}
	else if (number2 == 1)
	{
		if (number1 == 0)
		{
			printf("[��ܧޯ�]\n");
			printf("[1.���m��\t2.����\t3.���إ���(*0 or*2)\t4.�k�]]");
		}
		else if (number1 == 1)
		{
			printf("[��ܧޯ�]\n");
			printf("[1.���m\t2.�����\t3.���إ���(*0 or*2)\t4.�k�]]");
		}
		else if (number1 == 2)
		{
			printf("[��ܧޯ�]\n");
			printf("[1.���m\t2.����\t3.���إ���(*0 or*2)��\t4.�k�]]");
		}
		else if (number1 == 3)
		{
			printf("[��ܧޯ�]\n");
			printf("[1.���m\t2.����\t3.���إ���(*0 or*2)\t4.�k�]��]");
		}
	}
}
