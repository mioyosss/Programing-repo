/** 
* @mainpage
*# Загальне завдання
*1. **Завдання**
*	Перетворити число (максимальне значення якого - 9999) в рядок.
*
*# Опис програми
*2. **Призачення**
*	Програма призначена для перетворення числа в рядок
*3. **Логічна структура**
*	Програма складається з однієї функції, в якій виконується *перетворення числа в слово
*@author Steghniy B.
*@date 05-dec-2020
*/

/**
* @file main.c
* Програма призначена для перетворення числа в рядок
*@author Steghniy B.
*@return 0
*@version 0.1 
*@date 05-dec-2020
*/


/** @func Функція для перетворення числа в слово */
int func(int a) {
    // Змінні, які знадобляться при подальших розрахунках 
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    // Тривимірний массив, у який заносимо усі слова
    char arr[5][10][20] = {
        { " ", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" },
        { " ", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" },
        { " ", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" },
        { " ", "one thousand", "two thousand", "three thousand", "four thousand", "five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand" },
        { "ten", "eleven", "twenty", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }
    };

    // Перевірка числа на нуль
    if (a == 0) {
        printf("zero");
    }
    // Випадок для "особливих чисел"
    else if (a == 10 || a == 11 || a == 12 || a == 13 || a == 14 || a == 15 || a == 16 || a == 17 || a == 18 || a == 19) {
        printf("%s", arr[4][a - 10]);
    }
    // Випадок для розряду одиниць
    else if (a / 10 == 0) {
        printf("%s", arr[0][a]);
    }
    // Випадок для десятків
    else if (a / 100 == 0) {
        b = a / 10;
        c = a % 10;
        printf("%s", arr[1][b]);
        printf("%s", arr[0][0]);
        printf("%s", arr[0][c]);

    }
    // Випадок для тисяч з "особливими" числами
    else if (a / 10000 == 0 && a % 100 == 11 || a % 100 == 12 || a % 100 == 13 || a % 100 == 14 || a % 100 == 15 || a % 100 == 16 || a % 100 == 17 || a % 100 == 18 || a % 100 == 19) {
        b = a / 1000;
        c = (a % 1000) / 100;
        d = (a % 100);
        printf("%s", arr[3][b]);
        printf("%s", arr[0][0]);
        printf("%s", arr[2][c]);
        printf("%s", arr[0][0]);
        printf("%s", arr[4][d - 10]);

    }
    // Випадок для тисяч
    else if (a / 10000 == 0) {
        b = a / 1000;
        c = (a % 1000) / 100;
        d = (a % 100) / 10;
        e = a % 10;
        printf("%s", arr[3][b]);
        printf("%s", arr[0][0]);
        printf("%s", arr[2][c]);
        printf("%s", arr[0][0]);
        printf("%s", arr[1][d]);
        printf("%s", arr[0][0]);
        printf("%s", arr[0][e]);
    }
    // Випадок для сотен з "особливими" числами
    else if (a / 1000 == 0 && a % 100 == 11 || a % 100 == 12 || a % 100 == 13 || a % 100 == 14 || a % 100 == 15 || a % 100 == 16 || a % 100 == 17 || a % 100 == 18 || a % 100 == 19) {
        b = a / 100;
        c = (a % 100);
        printf("%s", arr[2][b]);
        printf("%s", arr[0][0]);
        printf("%s", arr[4][c - 10]);
    }
    // Випадок для сотен 
    else if (a / 1000 == 0) {
        b = a / 100;
        c = (a % 100) / 10;
        d = a % 10;
        printf("%s", arr[2][b]);
        printf("%s", arr[0][0]);
        printf("%s", arr[1][c]);
        printf("%s", arr[0][0]);
        printf("%s", arr[0][d]);
    }
    return a;
}
/** Основна фунція @main */
int main() {

    // Задаємо число цифрою, яке хочемо перетворити в запис словами
    int a = 8753;
    /** Звернення до фунції @func */
    func(a);

    return 0;
}
