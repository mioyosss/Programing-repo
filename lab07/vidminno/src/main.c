#include <stdarg.h>

// Задаємо розмір масиву
#define size 4
// Задаємо варіативну функцію, яка буде обчислювати 
int func(int num, ...) {
  // Змінна для роботи зі списком чисел
  va_list numbers;
  // Початок роботи зі списком
  va_start(numbers, num);
  // Змінна позначення кількості чисел, які менше за наступне
  int count = 0;
  // Задаємо массив, який заповнений нулями
  int mass[size] = {};
  // Цикл для заповнення массиву
  for (int j = 0; j < num; j++) {
    mass[j] = va_arg(numbers, int);
  }
  // Цикл для перебору масиву та визначення результату (count)
  for (int i = 0; i < num; i++) {
    if(mass[i] < mass[i+1]){
      count++;
    }
  }
  // Завершення роботи зі списком
  va_end(numbers);
  return count;
}

int main() {
  // Виклик функції
  func(size, 228,1337,8,668);

  return 0;
}
