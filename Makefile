main:	main.cpp Tokenizer.o
	g++ main.cpp Tokenizer.o

Tokenizer:	Tokenizer.h Tokenizer.cpp
	g++ -c Tokenizer.cpp

clean: rm -f *o a.out
