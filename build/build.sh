#!/usr/bin/env bash

# Compila specificando il percorso degli header con -I e flag di debug
g++ -g -I./lulu main.cpp src/*.cpp $(pkg-config --cflags --libs raylib) -o build/gioco

# Controlla se la compilazione è riuscita
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    build/gioco
else
    echo "Compilation failed!"
    exit 1
fi