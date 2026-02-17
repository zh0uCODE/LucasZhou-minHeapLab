all: examheap 

examheap: heap.o examheap.o
	g++ heap.o examheap.o -o examheap
heap.o: heap.cpp heap.h
	g++ -c heap.cpp 
examheap.o: examheap.cpp heap.h
	g++ -c examheap.cpp
clean:
	rm *.o examheap


