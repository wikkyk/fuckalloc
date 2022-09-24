.POSIX:

default: libfuckalloc.a libfuckalloc.so

clean:
	rm -f *.a *.o *.so *.test

test: test.o libfuckalloc.a libfuckalloc.so
	$(CC) $(CFLAGS) $(LDFLAGS) -static -L. $< -lfuckalloc -o s.$@
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o d.$@
	./s.$@
	LD_PRELOAD=./libfuckalloc.so ./d.$@

libfuckalloc.a: libfuckalloc.a(fuckalloc.o)

libfuckalloc.so: fuckalloc.o
	$(CC) $(CFLAGS) -shared -o $@ $<
