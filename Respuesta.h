#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "mensaje.h"

class Respuesta{
	public:
	    Respuesta(int pl);
	    struct mensaje getRequest(PaqueteDatagrama * p);
	    void sendReply(char *respuesta,char *ipCliente, int puertoCliente);
	private:
		SocketDatagrama *socketlocal;
	
};