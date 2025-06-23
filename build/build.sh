#!/usr/bin/env bash
g++ legend-of-lulu.cpp src/*.cpp legend-of-lulu/*.hpp build/gioco $(pkg-config --cflags --libs raylib) -o build/gioco
build/gioco