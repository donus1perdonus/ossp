#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"

void print_usage(const char *program_name) {
    printf("Использование: %s <номер_задания> [аргументы]\n", program_name);
    printf("Доступные задания: 1-8\n");
    printf("Примеры:\n");
    printf("  %s 1 -f test.bin           # Задание 1 с файлом test.bin\n", program_name);
    printf("  %s 2                       # Задание 2\n", program_name);
    printf("  %s 3 source.txt backup.txt # Задание 3 - копирование файлов\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    int task_number = atoi(argv[1]);
    
    if (task_number < 1 || task_number > 8) {
        fprintf(stderr, "Ошибка: номер задания должен быть от 1 до 8\n");
        print_usage(argv[0]);
        return 1;
    }

    printf("Запуск задания %d...\n\n", task_number);

    switch (task_number) {
        case 1:
            if (argc < 3) {
                fprintf(stderr, "Ошибка: для задания 1 требуется указать флаг -f и имя файла\n");
                printf("Использование: %s 1 -f <имя_файла>\n", argv[0]);
                return 1;
            }
            
            // Парсим аргументы для задания 1
            char *args_str = argv[2];
            char *flag = strtok(args_str, " ");
            char *filename = strtok(NULL, " ");
            
            if (flag == NULL || filename == NULL || strcmp(flag, "-f") != 0) {
                fprintf(stderr, "Ошибка: ожидается формат '-f <имя_файла>', получено: '%s'\n", args_str);
                printf("Использование: %s 1 -f <имя_файла>\n", argv[0]);
                return 1;
            }
            
            // Создаем новый argv для task1_main
            char *task1_argv[] = {"task1", "-f", filename, NULL};
            task1_main(3, task1_argv);
            break;
        case 2:
            task2_main();
            break;
        case 3:
            if (argc < 3) {
                fprintf(stderr, "Ошибка: для задания 3 требуется указать исходный и целевой файлы\n");
                printf("Использование: %s 3 <исходный_файл> <целевой_файл>\n", argv[0]);
                return 1;
            }
            
            // Парсим аргументы для задания 3
            char *task3_args_str = argv[2];
            char *source_file = strtok(task3_args_str, " ");
            char *dest_file = strtok(NULL, " ");
            
            if (source_file == NULL || dest_file == NULL) {
                fprintf(stderr, "Ошибка: ожидается формат '<исходный_файл> <целевой_файл>', получено: '%s'\n", task3_args_str);
                printf("Использование: %s 3 <исходный_файл> <целевой_файл>\n", argv[0]);
                return 1;
            }
            
            // Создаем новый argv для task3_main
            char *task3_argv[] = {"task3", source_file, dest_file, NULL};
            task3_main(3, task3_argv);
            break;
        case 4:
            task4_main();
            break;
        case 5:
            task5_main();
            break;
        case 6:
            task6_main();
            break;
        case 7:
            task7_main();
            break;
        case 8:
            task8_main();
            break;
        default:
            fprintf(stderr, "Ошибка: неизвестный номер задания\n");
            return 1;
    }

    return 0;
}