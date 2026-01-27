# Azin

Azin is an experimental programming language and compiler written in C++.  
The project is built from scratch with the goal of understanding how real-world compilers work at a low level.

This repository focuses on the complete compilation pipeline, including lexical analysis, parsing, AST construction, and basic code generation.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)

---

## Overview

Azin is primarily an educational project.  
It is designed to explore compiler internals rather than to be a production-ready language.

The compiler is implemented in modern C++ and follows a modular architecture, separating each compilation stage into its own component.

---

## Features

- Custom programming language syntax (`.az`)
- Lexer for tokenization
- Parser for syntax analysis
- Abstract Syntax Tree (AST)
- Basic code generation
- Modular and readable C++ codebase
- Simple command-line usage

---

## Project Structure

```text
Azin/
├── Lexer.cpp / Lexer.hpp
│   └── Lexical analysis (tokenization)
├── Parser.cpp / Parser.hpp
│   └── Syntax parsing
├── ast.cpp / ast.hpp
│   └── Abstract Syntax Tree definitions
├── codegen.cpp / codegen.hpp
│   └── Code generation logic
├── main.cpp
│   └── Compiler entry point
├── test.az
│   └── Example Azin source file
├── run.cmd
│   └── Windows build/run helper
└── README.md
```
