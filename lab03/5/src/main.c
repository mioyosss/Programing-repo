int main()
{
	int x = 123; // Введення числа 
	float z1 = x / 100; // Ділене
	float z2 = x % 100 % 10; // Дільник 
	float y = z1 / z2; // Частка
	int y1 = y * 100; // Округлення
	float result = y1 / 100.0f; // Результат округлення
	return 0;
}
