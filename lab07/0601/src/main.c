// Додаємо функцію
int func(char mass[], const int N) {
    // Кількість символів в імені
    int name = 0;
    int i = 0;
    while (mass[i] != '\0') {
        if (mass[i] != ' ') {
            name++;
        }
        i++;
    }

    // Задаємо заповнювач
    char zap = '_';
    // Визначаємо кількість пропусків в масиві
    int spaces = (N - 1) - name;
    // Якщо кількість символів в імені не парна, то програма закриваеться


    // Заповнення пробілів підкреслюваннями
    for (int i = 0; i < N; i++) {
        if (mass[i] == ' ') {
            mass[i] = zap;
        }
        // Зсув массиву 
    }
    for (int i = 0; i < spaces / 2; i++)

    {
        for (int j = N - 3; j >= 0; j--)
        {
            mass[j + 1] = mass[j];

        }
        // Вставка потрібних підкреслювать на початку масива
    }
    for (int i = 0; i < spaces / 2; i++)
    {
        mass[i] = zap;
    }
    printf("%s", mass);
    return 0;
}

int main()
{
    // Задаемо кількість елементів у масиві константою
#define N 12 
    // Задаємо масив
    char mass[] = "abcdefg    ";
    // Виклик фунції
    func(mass, N);

    return 0;
}