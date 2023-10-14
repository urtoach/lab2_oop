cmake_minimum_required(VERSION 3.16)

project(ooplab2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

# Создание библиотеки SignalState
add_library(SignalState SignalState.h SignalState.cpp)

# Включение библиотеки SignalState во все цели (таргеты)
link_libraries(SignalState)

# Добавление файлов BinarySignal.h и BinarySignal.cpp
add_library(BinarySignal BinarySignal.h BinarySignal.cpp)

# Включение библиотеки BinarySignal во все цели (таргеты)
link_libraries(BinarySignal)

# Добавление файла GetNum.h
add_library(GetNum GetNum.h)

# Включение библиотеки GetNum во все цели (таргеты)
link_libraries(GetNum)

# Создание исполняемого файла и его зависимость от библиотек
add_executable(lab2 main.cpp)
target_link_libraries(lab2 SignalState BinarySignal GetNum)


# для сборки из консоли:
#
# mkdir build   # создание директории для файлов сборки
# cd build      # переход в директорию сборки
# cmake ..      # генерация файлов сборки на основе CMakeLists.txt
# make          # сборка проекта
