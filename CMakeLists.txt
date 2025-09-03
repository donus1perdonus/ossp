cmake_minimum_required(VERSION 3.10)
project(OSSP_Project VERSION 1.0.0 LANGUAGES C)

# Установка стандарта C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Опции компилятора
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")

# Поиск исходных файлов
file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.h")

# Добавление исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Установка путей для заголовочных файлов
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Установка выходной директории
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Дополнительные настройки
# target_link_libraries(${PROJECT_NAME} m) # для математической библиотеки

# Информация о проекте
message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Source files: ${SOURCES}")
message(STATUS "Header files: ${HEADERS}")