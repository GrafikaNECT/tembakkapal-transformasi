bin/main: Makefile src/mprintchar.c src/printchar.c src/char.c bin
	gcc src/mprintchar.c src/printchar.c src/char.c -o bin/main
	cp src/cat_pixel.txt bin/cat_pixel.txt

bin:
	mkdir -p bin
