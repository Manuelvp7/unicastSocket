#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include <stdio.h>
#include "mensaje.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	Solicitud sol1 =  Solicitud();
	sol1.doOperation("127.0.0.1",7200,0,"2,5");

	
	return 0;
}