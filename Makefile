ps = ./Parser/
tn = ./TreeNodes/
all: 

main: main.o Parser.o Addition.o Multiplication.o Negation.o Number.o Division.o
	g++ -o main main.o Parser.o Addition.o Multiplication.o Negation.o Number.o Division.o

main.o: main.cpp
	g++ -c main.cpp

Parser.o: $(ps)Parser.cpp $(ps)Parser.h $(tn)Addition.h $(tn)Multiplication.h $(tn)Negation.h $(tn)Number.h $(tn)TreeNode.h
	g++ -c $(ps)Parser.cpp

Multiplication.o: $(tn)Multiplication.cpp $(tn)Multiplication.h
	g++ -c $(tn)Multiplication.cpp

Addition.o:
	g++ -c $(tn)Addition.cpp

Negation.o:
	g++ -c $(tn)Negation.cpp

Number.o: 
	g++ -c $(tn)Number.cpp

Division.o:
	g++ -c $(tn)Division.cpp

clean: 
	rm *.o main debug
##debugging 
debug: maind.o Parserd.o Additiond.o Multiplicationd.o Negationd.o Numberd.o Divisiond.o
	g++ -g -o debug maind.o Parserd.o Additiond.o Multiplicationd.o Negationd.o Numberd.o Divisiond.o

maind.o: main.cpp
	g++ -g -c main.cpp -o maind.o

Parserd.o: $(ps)Parser.cpp $(ps)Parser.h $(tn)Addition.h $(tn)Multiplication.h $(tn)Negation.h $(tn)Number.h $(tn)TreeNode.h
	g++ -g -c $(ps)Parser.cpp -o Parserd.o

Multiplicationd.o: $(tn)Multiplication.cpp $(tn)Multiplication.h
	g++ -g -c $(tn)Multiplication.cpp -o Multiplicationd.o

Additiond.o:
	g++ -g -c $(tn)Addition.cpp -o Additiond.o

Negationd.o:
	g++ -g -c $(tn)Negation.cpp -o Negationd.o

Numberd.o: 
	g++ -g -c $(tn)Number.cpp -o Numberd.o

Divisiond.o:
	g++ -g -c $(tn)Division.cpp -o Divisiond.o