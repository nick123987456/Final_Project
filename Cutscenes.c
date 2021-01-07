void Cutscenes(int *n)
{
	system("CLS");
	printf("你是從數千萬的村民萬中選一的冒險者\n冒險者%d號，開始你的冒險吧!\n", *n);
	*n = *n + 1;
	system("pause");
}