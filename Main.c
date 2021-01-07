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
	int ch, number, number1 = 1;//number紀錄開頭 number1記錄第幾位冒險者 
	srand(time(NULL));
	number = Opening_screen();
	while (number)
	{
		Cutscenes(&number1);
		Battle_screen(number1, &number);
	}
	return 0;
}
