build:
	echo "########COMPILANDO O PROGRAMA########"
	g++ -Wall  -c epson/epson.cpp -o epson.o
	g++ -Wall cmd/main.cpp epson.o libInterfaceEpsonNF.a -o cmd/main

run: build
	echo "########RODANDO O PROGRAMA########"
	./cmd/main
	

