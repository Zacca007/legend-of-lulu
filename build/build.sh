#!/usr/bin/env bash

# Compila specificando il percorso degli header con -I
g++ -I./lulu main.cpp src/*.cpp $(pkg-config --cflags --libs raylib) -o build/gioco

# Esegui solo se la compilazione è riuscita
if [ $? -eq 0 ]; then
    build/gioco
else
    echo "Compilation failed!"
    exit 1
fi