# STL library for c


## How to run make comands on windows

Go to `C:\Program Files\Git\mingw64\bin` <br>
Copy the file named `mingw32-make.exe` <br>
Rename it to `make.exe` <br>
Now run the make commands on the git bash. <br>
`make all ` <br>
`make clean` <br>
`make examples` <br>
Run example <br>
`.\examples\example_array.exe`

## Cmds to run and test the files

1. Compile source <br>
`gcc -Wall -Iinclude -c src/array.c -o src/array.o`

2. Create library <br>
`ar rcs libstl.a src/array.o`

3. Build example <br>
`gcc -Wall -Iinclude examples/example_array.c -L. -lstl -o examples/example_array.exe`

4. Run example <br>
`.\examples\example_array.exe`



