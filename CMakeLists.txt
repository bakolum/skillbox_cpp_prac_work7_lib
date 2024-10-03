cmake_minimum_required(VERSION 3.18)        # требуемая версия cmake
project(    
    Matrix                                 # название проекта                        
    VERSION 0.0.1                           # номер версии проекта
    DESCRIPTION "matrixlib"                 # описание           
    LANGUAGES CXX                           # язык программирования
)   
set(CMAKE_CXX_STANDARD 17)                  # устанавливаем требуемый стандарт языка (это значит, что в проекте буду использоваться фичи этоо стандарта)
set(CMAKE_CXX_STANDARD_REQUIRED ON)         # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                 # конфигурация сборки - Debug

set(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)

set(sources                                 # создаем cmake-переменную sources, которая содержит список файлов исходного когда (в данном случае main.cpp)
    src/matrix.h
    src/matrix.cpp

    src/c/c_api.h
    src/c/c_api.cpp
)

# Включение модуля для генерации экспортного заголовка
include(GenerateExportHeader)

# Создание динамической библиотеки из исходных файлов
add_library(shared-matrixlib SHARED ${sources})

# Установка директорий с заголовочными файлами для библиотеки
target_include_directories(shared-matrixlib
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# Определение макросов для компиляции
target_compile_definitions(
    shared-matrixlib
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

# Настройка свойств библиотеки (без префикса)
set_target_properties(shared-matrixlib PROPERTIES PREFIX "")

# Генерация заголовочного файла
generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)