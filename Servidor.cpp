#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
   int veces = 0;
   char data[5]="Hola";
   //PaqueteDatagrama paquete(data, 5, "10.100.66.27", 0);
   PaqueteDatagrama paquete2(data, 5, "10.100.75.241", 7200);

   int *num;

   SocketDatagrama datagrama(paquete2.obtienePuerto());
   datagrama.recibe(paquete2);

   num = (int *)paquete2.obtieneDatos();

   int res = num[1] + num[0];

   PaqueteDatagrama p = PaqueteDatagrama((char*)&res, sizeof(res), paquete2.obtieneDireccion(), paquete2.obtienePuerto());

   datagrama.envia(p);
   
   return 0;
}