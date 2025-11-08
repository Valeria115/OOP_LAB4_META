# # # cmake_minimum_required(VERSION 3.10)

# # # # Имя проекта
# # # project(oop_dz_3)

# # # # Установим стандарт C++ 17
# # # set(CMAKE_CXX_STANDARD 17)
# # # set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # # # Добавляем флаг для предупреждений
# # # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# # # # Настройка Google Test
# # # include(FetchContent)
# # # FetchContent_Declare(
# # #     googletest
# # #     GIT_REPOSITORY https://github.com/google/googletest.git
# # #     GIT_TAG v1.15.0
# # #     TLS_VERIFY false
# # # )
# # # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# # # FetchContent_MakeAvailable(googletest)

# # # # Указываем, где находятся исходники вашего проекта
# # # set(SOURCES
# # #     src/figure.cpp
# # #     src/rectangle.cpp
# # #     src/square.cpp
# # #     src/trapezoid.cpp
# # #     src/point.cpp
# # #     src/figureArray.cpp
# # # )

# # # # Добавляем директорию для заголовочных файлов
# # # include_directories(${CMAKE_SOURCE_DIR}/include)

# # # # Создаем библиотеку для проекта
# # # add_library(geometry_lib ${SOURCES})

# # # # Создаем исполняемый файл для тестов
# # # add_executable(runTests
# # #     test/tests.cpp  # Ваши тесты
# # # )

# # # # Линкуем тесты с библиотекой проекта и Google Test
# # # target_link_libraries(runTests
# # #     geometry_lib
# # #     gtest_main
# # # )

# # # # Включаем поддержку тестов
# # # enable_testing()

# # # # Добавляем тесты в тестовый набор
# # # add_test(NAME GeometryTests COMMAND runTests)

# # # # Создаем исполняемый файл для основного приложения (main.cpp)
# # # add_executable(mainApp main.cpp)

# # # # Линкуем основное приложение с библиотекой проекта
# # # target_link_libraries(mainApp geometry_lib)


# # # cmake_minimum_required(VERSION 3.15)
# # # project(OOP_LAB4_META)

# # # set(CMAKE_CXX_STANDARD 20)         # используем C++20
# # # set(CMAKE_CXX_STANDARD_REQUIRED ON)
# # # set(CMAKE_CXX_EXTENSIONS OFF)

# # # # все исходники
# # # add_executable(program
# # #     src/main.cpp
# # #     src/array.cpp
# # #     src/point.cpp
# # #     src/square.cpp
# # #     src/rectangle.cpp
# # #     # добавь другие cpp файлы
# # # )

# # # # если нужны include директории
# # # target_include_directories(program PRIVATE include)

# # # export CC=clang
# # # export CXX=clang++
# # # cmake -B build
# # # cmake --build build


# # cmake_minimum_required(VERSION 3.15)

# # # Название проекта
# # project(OOP_LAB4_META LANGUAGES CXX)

# # # ======================= Настройки C++ =======================
# # set(CMAKE_CXX_STANDARD 20)        # используем C++20
# # set(CMAKE_CXX_STANDARD_REQUIRED ON)
# # set(CMAKE_CXX_EXTENSIONS OFF)

# # # Включаем предупреждения (можно добавить другие)
# # add_compile_options(-Wall -Wextra -Werror=maybe-uninitialized)

# # # ======================= Исходники =======================
# # set(SOURCES
# #     src/point.cpp
# #     src/figure.cpp
# #     src/array.cpp
# #     src/square.cpp
# #     src/rectangle.cpp
# #     src/trapezoid.cpp   # если есть
# # )

# # # ======================= Заголовочные файлы =======================
# # include_directories(${CMAKE_SOURCE_DIR}/include)

# # # ======================= Библиотека проекта =======================
# # add_library(geometry_lib ${SOURCES})

# # # ======================= Основное приложение =======================
# # add_executable(mainApp src/main.cpp)
# # target_link_libraries(mainApp PRIVATE geometry_lib)

# # # ======================= Настройка тестов =======================
# # include(FetchContent)

# # FetchContent_Declare(
# #     googletest
# #     GIT_REPOSITORY https://github.com/google/googletest.git
# #     GIT_TAG v1.15.0
# #     TLS_VERIFY OFF
# # )
# # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# # FetchContent_MakeAvailable(googletest)

# # add_executable(runTests test/tests.cpp)
# # target_link_libraries(runTests PRIVATE geometry_lib gtest_main)

# # enable_testing()
# # add_test(NAME GeometryTests COMMAND runTests)

# # # ======================= Определяем компилятор (если нужно) =======================
# # # Можно задать при запуске cmake, если Clang
# # # export CC=clang
# # # export CXX=clang++


# cmake_minimum_required(VERSION 3.15)

# # ======================= Название проекта =======================
# project(OOP_LAB4_META LANGUAGES CXX)

# # ======================= Настройки C++ =======================
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# # Включаем предупреждения
# add_compile_options(-Wall -Wextra -Werror=maybe-uninitialized)

# # ======================= Пути к исходникам =======================
# set(SOURCES
#     src/point.cpp
#     src/array.cpp
#     src/square.cpp
#     src/rectangle.cpp
#     src/trapezoid.cpp
#     # шаблонные классы реализованы в .h, поэтому .cpp не нужны
# )

# # ======================= Заголовочные файлы =======================
# include_directories(${CMAKE_SOURCE_DIR}/include)

# # ======================= Библиотека проекта =======================
# add_library(geometry_lib ${SOURCES})

# # ======================= Основное приложение =======================
# # main.cpp лежит в корне проекта
# add_executable(mainApp
#     main.cpp
# )
# target_link_libraries(mainApp PRIVATE geometry_lib)

# # ======================= Настройка Google Test =======================
# include(FetchContent)

# FetchContent_Declare(
#     googletest
#     GIT_REPOSITORY https://github.com/google/googletest.git
#     GIT_TAG v1.15.0
#     TLS_VERIFY OFF
# )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# # ======================= Тесты =======================
# add_executable(runTests
#     test/tests.cpp
# )
# target_link_libraries(runTests PRIVATE geometry_lib gtest_main)

# enable_testing()
# add_test(NAME GeometryTests COMMAND runTests)

# # ======================= Компилятор =======================
# # Если нужно указать Clang вручную:
# # export CC=clang
# # export CXX=clang++


cmake_minimum_required(VERSION 3.15)

# ======================= Название проекта =======================
project(OOP_LAB4_META LANGUAGES CXX)

# ======================= Настройки C++ =======================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем предупреждения
add_compile_options(-Wall -Wextra -Werror=maybe-uninitialized)

# ======================= Пути к исходникам =======================
set(SOURCES
    src/array.cpp
    src/point.cpp
    src/rectangle.cpp
    src/square.cpp
    src/trapezoid.cpp
)

# ======================= Заголовочные файлы =======================
include_directories(${CMAKE_SOURCE_DIR}/include)

# ======================= Библиотека проекта =======================
add_library(geometry_lib ${SOURCES})

# ======================= Основное приложение =======================
add_executable(mainApp
    main.cpp
)
target_link_libraries(mainApp PRIVATE geometry_lib)

# ======================= Настройка Google Test =======================
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY OFF
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ======================= Тесты =======================
add_executable(runTests
    test/tests.cpp
)
target_link_libraries(runTests PRIVATE geometry_lib gtest_main)

enable_testing()
add_test(NAME GeometryTests COMMAND runTests)

# ======================= Компилятор =======================
# Если нужно указать Clang вручную:
# export CC=clang
# export CXX=clang++