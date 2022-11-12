#LDFLAGS := -L/usr/lib/libdir.so
main : main_test.c libdirtest2.so 
	gcc -o main_test.c -L ./ -ldirtest2 -o main
#libdirtest.so : *.c	
#	gcc *.c -fPIC -shared 

clean:
	rm *.o
#	rm *.so
	rm *.a
