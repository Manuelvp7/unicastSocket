all:test

test: PaqueteDatagrama.o Solicitud.o SocketDatagrama.o main.o
	g++ Solicitud.o main.o SocketDatagrama.o PaqueteDatagrama.o -o main

main.o:main.cpp
	g++ main.cpp -c

PaqueteDatagrama.o:PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c	

Solicitud.o:Solicitud.cpp
	g++ Solicitud.cpp -c	

SocketDatagrama.o:SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c



	
