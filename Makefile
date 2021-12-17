CC=gcc
CFLAGS= -Wall -Wextra -Werror -Wnarrowing -Wconversion -Wwrite-strings -Wcast-qual -Wundef -Wstrict-prototypes -Wbad-function-cast  -Wreturn-type 

all: 1.1_stat/stat.exe 2.1_write/write.exe 2.2_write/write.exe

1.1_stat/stat.exe:
	$(CC) $(CFLAGS) 1.1_stat/stat.c -o $@

2.1_write/write.exe:
	$(CC) $(CFLAGS) 2.1_write/write.c -o $@

2.2_write/write.exe:
	$(CC) $(CFLAGS) 2.2_write/write.c -o $@
