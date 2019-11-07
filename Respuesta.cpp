#include "Respuesta.h"
#include "mensaje.h"

Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    struct mensaje msjx;
    msjx.messageType = 1;
    msjx.requestId = 1;
    msjx.operationId = 1;
    strcpy(msjx.arguments,respuesta);
    PaqueteDatagrama p(msjx, ipCliente,puertoCliente );
    socketlocal->envia(p);
}

struct mensaje Respuesta::getRequest(PaqueteDatagrama *p){

    struct  mensaje msj;
    char * args = (char*)malloc(sizeof(char)*4000);
    int i = socketlocal->recibe(p);

    msj.messageType = 0;
    msj.requestId = 1;
    msj.operationId = 1;
    strcpy(msj.arguments,args);


    return msj;
}

