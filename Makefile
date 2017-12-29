CC 	= gcc
CFLAGS 	= -O3

SRCS_LIB = ctimer.c

SRCS =	main.c

OBJS_LIB = $(SRCS_LIB:.c=.o)
OBJS = $(SRCS:.c=.o)

LIB = libctimer.a

all:  release

release: main $(LIB)

$(LIB): $(OBJS_LIB)
	ar -r $(LIB) $(OBJS_LIB)

debug:
	$(MAKE) $(MAKEFILE) DEBUG="-g -D DEBUG"

main: main.o $(LIB)
	gcc $(CFLAGS) $(DEBUG) -o main main.o -L. -lctimer

$(OBJS_LIB): $(SRCS_LIB)

$(OBJS): $(SRCS)

.c.o:
	gcc $(CFLAGS) $(DEBUG) -c $<

clean:
	rm -f *.o
	rm $(LIB)
	rm main
