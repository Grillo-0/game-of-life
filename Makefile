all: main.o cell.o
	g++ main.o cell.o -o main.out

main.o: main.cpp
	g++ -c main.cpp -o main.o

cell.o: cell.cpp
	g++ -c cell.cpp -o cell.o

clean:
	rm *.o *.out

run: all
	./main.out
