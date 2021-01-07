void Random_value(Character_value p)
{
	p-hp = 50;
	p-atk = 10 + (rand() % 21);
	p-spd = 5 + (rand() % 11);
	p-def = 5 + (rand() % 11);
}