# Azin

Azin is a minimal statically typed programming language and compiler implemented from scratch in C++.

It includes:

- Lexer
- Recursive descent parser
- AST construction
- Scoped semantic analysis
- Static type system (int, bool, nore for functions)
- C backend code generation
- Native binary output via GCC

## Example

```az
int main()
{
    bool verified = false;
    int age = 21;

    if (age >= 18) {
        verified = true;
    } else {
        verified = false;
    }

    // can't return bools directly like C
    if (verified)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
```

## Build

Either grab a precompiled binary from releases for both windows and linux, or go to the project root and run build.bat for windows and build.sh for linux

## Why

Built to explore compiler architecture and language design from scratch.

## Documentation

Full documentation and change logs are available in /docs.
