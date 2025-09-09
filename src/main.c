#include <task1.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    unsigned char data[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size_t data_size = sizeof(data);

    // Создание и запись файла
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    size_t written = fwrite(data, 1, data_size, file);
    if (written != data_size) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    printf("File created successfully with data: ");
    for (size_t i = 0; i < data_size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    // Чтение файла с побайтовым выводом
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("Reading file byte by byte:\n");
    unsigned char byte;
    size_t position = 0;
    
    while (fread(&byte, 1, 1, file) == 1) {
        printf("Position: %zu, Byte: %d\n", position, byte);
        print_file_position(file);
        printf("EOF indicator: %d\n", feof(file));
        printf("Error indicator: %d\n", ferror(file));
        printf("\n");
        position++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    // Повторное открытие и использование fseek
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error reopening file");
        return 1;
    }

    // Перемещение на 3 байта от начала
    if (fseek(file, 3, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return 1;
    }

    printf("After fseek to position 3:\n");
    print_file_position(file);
    printf("\n");

    // Чтение 4 байтов
    unsigned char buffer[4];
    size_t bytes_read = fread(buffer, 1, 4, file);
    
    if (bytes_read != 4) {
        if (ferror(file)) {
            perror("Error reading from file");
        } else {
            printf("Could only read %zu bytes instead of 4\n", bytes_read);
        }
        fclose(file);
        return 1;
    }

    printf("After reading 4 bytes:\n");
    print_file_position(file);
    printf("Buffer contains: ");
    for (size_t i = 0; i < 4; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}