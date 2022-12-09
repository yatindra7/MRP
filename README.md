# Execution Instructions

Generating `librsocket.a`, the library containing the MRP Protocol.
```
make -f makefile.librsocket
```

Then, create two user executables from `user1.c` and `user2.c`, to test
```
make -f makefile.user
```

To delete all binaries, run
```
make clean -f makefile.librsocket
make clean -f makefile.user
```
