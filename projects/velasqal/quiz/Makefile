CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	echo "\nResult for running testme unit tests:" > testmeresult.out
	gcc -o testme testme.c $(CFLAGS)
	./testme >> testmeresult.out
	gcov testme.c -b -f >> testmeresult.out
	cat testme.c.gcov >> testmeresult.out

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out	testme
