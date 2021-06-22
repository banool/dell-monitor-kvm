Set up:
```
ln -s ../include/latest/headers/
```

Build:
```
clang -std=c17 -L../include/latest/libs -lDellMonitorSdkLib main.c -o main
```

Run:
```
./main
```
