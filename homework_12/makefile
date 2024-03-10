all: sensor

sensor: main.o temp_api.o
	gcc -std=c99 -o sensor main.o temp_api.o

main.o: main.c temp_api.h
	gcc -std=c99 -c -o main.o main.c

temp_api.o: temp_api.c
	gcc -std=c99 -c -o temp_api.o temp_api.c

clean:
	del *.o sensor.exe  