CC=gcc
CFLAGS= -Wall -Wextra -Werror -Wnarrowing -Wconversion -Wwrite-strings -Wcast-qual -Wundef -Wstrict-prototypes -Wbad-function-cast  -Wreturn-type 

all: 1.0_stat/stat.exe


1.0_stat/stat.exe:
	$(CC) $(CFLAGS) 1.0_stat/stat.c -o $@
