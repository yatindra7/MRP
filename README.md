# Execution Instructions

First, to generate the library `librsocket.a`, run
```
make -f makefile.librsocket
```

Then, to create the two executable files from `user1.c` and `user2.c`, run
```
make -f makefile.user
```
This will create two executables `user1` and `user2`.

First execute `user2` using
```
./user2
```
Then execute `user1` using
```
./user1
```

To delete all binaries, run
```
make clean -f makefile.librsocket
make clean -f makefile.user
```