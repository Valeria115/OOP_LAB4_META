cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(oop_dz_3)

# Установим стандарт C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем флаг для предупреждений
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Настройка Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Указываем, где находятся исходники вашего проекта
set(SOURCES
    src/figure.cpp
    src/rectangle.cpp
    src/square.cpp
    src/trapezoid.cpp
    src/point.cpp
    src/figureArray.cpp
)

# Добавляем директорию для заголовочных файлов
include_directories(${CMAKE_SOURCE_DIR}/include)

# Создаем библиотеку для проекта
add_library(geometry_lib ${SOURCES})

# Создаем исполняемый файл для тестов
add_executable(runTests
    test/tests.cpp  # Ваши тесты
)

# Линкуем тесты с библиотекой проекта и Google Test
target_link_libraries(runTests
    geometry_lib
    gtest_main
)

# Включаем поддержку тестов
enable_testing()

# Добавляем тесты в тестовый набор
add_test(NAME GeometryTests COMMAND runTests)

# Создаем исполняемый файл для основного приложения (main.cpp)
add_executable(mainApp main.cpp)

# Линкуем основное приложение с библиотекой проекта
target_link_libraries(mainApp geometry_lib)
