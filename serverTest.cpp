#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "Respuesta.h"
#include "PaqueteDatagrama.h"

int puerto = 6666;

int main(void){

   Respuesta response = Respuesta(puerto);
   PaqueteDatagrama package;
   struct mensaje message;

   while(1) {

      message = response.getRequest(&package);
      printf("RESPONTDIENDO A %s EN %d\n",package.obtieneDireccion(),package.obtienePuerto() );
      //response.sendReply("HOLIWIIIIIIIIIS",package.obtieneDireccion(),package.obtienePuerto());
   }
}
