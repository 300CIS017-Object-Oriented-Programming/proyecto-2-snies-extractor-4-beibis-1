cmake_minimum_required(VERSION 3.29)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
    Consolidado.cpp
    Consolidado.h
    Gestor.h
    GestorCsv.cpp
    GestorCsv.h
    GestorJson.cpp
    GestorJson.h
    GestorTXT.cpp
    GestorTXT.h
    main.cpp
    ProgramaAcademico.cpp
    ProgramaAcademico.h
    Settings.cpp
    Settings.h
    SNIESController.cpp
    SNIESController.h
    View.cpp
    View.h)
