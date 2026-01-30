#!/bin/bash
set -e

cd src

g++ -std=c++17 \
    main.cpp \
    ast.cpp \
    Parser.cpp \
    Lexer.cpp \
    asmgen.cpp \
    -o ../azc

echo "[OK] azc built"

