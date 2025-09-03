#include <stdio.h>
#include "example.h" // пример заголовочного файла

int main() {
    printf("Hello, World!\n");
    printf("C99+ проект успешно собран!\n");
    
    // Пример использования функции из другого файла
    int result = add_numbers(5, 3);
    printf("5 + 3 = %d\n", result);
    
    // Демонстрация возможностей C99
    #ifdef __STDC_VERSION__
    printf("C стандарт: %ld\n", __STDC_VERSION__);
    #endif
    
    // C99 feature: designated initializers
    struct Point {
        int x;
        int y;
    };
    
    struct Point p = { .x = 10, .y = 20 };
    printf("Point coordinates: x=%d, y=%d\n", p.x, p.y);
    
    // C99 feature: variable length arrays (VLA)
    int size = 5;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    return 0;
}