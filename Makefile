.PHONY: all
all:
	make build
	make run


.PHONY: build
build:
	echo "########COMPILANDO O PROGRAMA########"
	g++ -Wall  -c epson/epson.cpp -o epson.o
	g++ -Wall cmd/main.cpp epson.o libInterfaceEpsonNF.a -o cmd/main

.PHONY: run
run:
	echo "########RODANDO O PROGRAMA########"
	./cmd/main
	

