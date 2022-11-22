all: heap stack

heap: heap.cpp
	g++ -g -no-pie -o heap heap.cpp

stack: stack.cpp
	g++ -g -fno-stack-protector -no-pie -o stack stack.cpp

clean:
	rm -f heap stack