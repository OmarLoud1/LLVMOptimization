# Optimization of Compiler

## Overview

This project focuses on optimizing a compiler using LLVM-based tools. It implements various compiler passes and demonstrates how to parse and manipulate Abstract Syntax Trees (AST) to generate optimized object code. The project includes a modified version of the Kaleidoscope language and allows the user to compile, parse, and execute C++ code with LLVM backend support.

## Requirements

To build and run the project, ensure you have the following tools installed:

- **clang 12/13**  
- **llvm 12/13**

### Installation:
To ensure LLVM is properly installed, run the following command:

```bash
$ llvm-config --version
```

This will confirm if the right version of LLVM is set up.

## Compile `toy.cpp`

`AST.h` contains class definitions for the **Abstract Syntax Tree (AST)** used by the project. `toy.cpp` includes the modified Kaleidoscope chapter 8 source code.

### To compile `toy.cpp`:

```bash
$ clang++ -g -O3 toy.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all` -o toy
```

This command compiles the `toy.cpp` file with LLVM optimizations enabled.

## Parse with `toy`

To parse Kaleidoscope code in a file (`file`), you can pipe the file contents into `toy`:

```bash
$ cat file | ./toy
```

This will:
1. Parse the Kaleidoscope code from `file`.
2. Output the corresponding object file (`output.o`).

### `parse.sh`

For convenience, the `parse.sh` script parses multiple Kaleidoscope input files. You can use it like this:

```bash
$ sh parse.sh file1 [file2 ...]
```

This will automatically:
- Parse the input files.
- Rename the output object files to `file1.o`, `file2.o`, etc.

To use these object files with `main.cpp`, include the object files when compiling `main.cpp`.

## Compiling with Object Code

If you have a `main.cpp` that uses functions defined in `output.o`, compile it as follows:

```bash
$ clang++ main.cpp output.o -o main
```

This will link the object code (`output.o`) with your `main.cpp`.

## Running the Code

After compiling `main.cpp`, run the executable:

```bash
$ ./main
```

## Using Object Code in `main.cpp`

To use a Kaleidoscope function `foo(a1, a2, ..., an)` from `file` (which is parsed into `output.o`) in `main.cpp`, you must declare the function with an `extern "C"` block:

```cpp
extern "C" {
    double foo(double, double, ..., double);
}
```

Here, `double` is repeated `n` times. After this declaration, you can call `foo` from `main.cpp` as follows:

```cpp
foo(-1, 3, ..., 93);
```

You can define as many functions as needed in the `extern "C"` block.

## Example Usage

### Example Files:
- `ops_test.txt` contains Kaleidoscope functions that test operators like `==`, `!=`, `<`, `>`, `<=`, `>=`, `!`, and `-`.  
- `ops_test.cpp` contains C++ code to run the functions in `ops_test.txt`.

### Steps:

1. Compile `toy.cpp`:
    ```bash
    $ clang++ -g -O3 toy.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all` -o toy
    ```

2. Parse the input file:
    ```bash
    $ cat ops_test.txt | ./toy
    ```
    Or, use the script:
    ```bash
    $ sh parse.sh ops_test.txt
    ```

3. Compile the `ops_test.cpp` with the output object file:
    ```bash
    $ clang++ ops_test.cpp output.o -o ops_test
    ```

4. Run the program:
    ```bash
    $ ./ops_test
    ```

Manually verify that the operation results are correct.

## Implementing Passes

In `toy.cpp`, there is a function called `MainLoop()`. This function parses `stdin` and produces an AST. This AST is stored in a global `ModuleAST` variable called `TheModuleAST`. The `ModuleAST` contains all extern
