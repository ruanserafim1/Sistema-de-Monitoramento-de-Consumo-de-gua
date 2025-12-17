cmake_minimum_required(VERSION 3.10)
project(SistemaMonitoramentoHidrometros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Listar todos os arquivos .cpp
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(SistemaMonitoramento ${SOURCES} ${HEADERS})

target_include_directories(SistemaMonitoramento PRIVATE include)

# Link com pthread se necessário (para Observer pattern com threads)
find_package(Threads REQUIRED)
target_link_libraries(SistemaMonitoramento Threads::Threads)

# Configurações de compilação
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(SistemaMonitoramento PRIVATE -Wall -Wextra -g -O0)
else()
    target_compile_options(SistemaMonitoramento PRIVATE -Wall -Wextra -O2)
endif()
