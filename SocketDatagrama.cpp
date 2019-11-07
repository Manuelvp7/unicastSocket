#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include "SocketDatagrama.h"

using namespace std;

SocketDatagrama::SocketDatagrama(int port){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
    shutdown(s, SHUT_RDWR);
}

int SocketDatagrama::recibe(PaqueteDatagrama *p){
    char * respuesta = (char*)malloc(sizeof(char)*4000);
    unsigned int lData = sizeof(direccionForanea);
    int responseStatus = recvfrom(s, respuesta, 4000, 0, (struct sockaddr *)&direccionForanea, &lData);
    p->inicializaArgumentosMensaje(respuesta);
    char str[INET_ADDRSTRLEN];
    struct sockaddr_in* ip = (struct sockaddr_in*)&direccionForanea;
    struct in_addr ipAdd = ip->sin_addr;
    unsigned short ipPort = ip->sin_port;
    inet_ntop(AF_INET, &ipAdd, str, INET_ADDRSTRLEN);
    printf("IP: %s  \n", str);
    printf("Puerto: %d \n", (int) ntohs(ip->sin_port));
    printf(" %s\n",p->obtieneDatos() );
    p->inicializaIP(inet_ntoa(direccionForanea.sin_addr));
    p->inicializaPuerto(ntohs(direccionForanea.sin_port));
    return responseStatus;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    int enviado;
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    unsigned int lData = sizeof(direccionForanea);
    enviado = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, lData);
    return enviado;
}
