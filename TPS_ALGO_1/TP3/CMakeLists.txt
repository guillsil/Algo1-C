cmake_minimum_required(VERSION 3.22)
project(TP3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP3
        controlador.h
        controlador.o
        juego
        juego.c
        papeleo.c
        papeleo.h
        tp1.c
        tp1.h
        tp2.c
        tp2.h
        utiles.h
        utiles.o)
