#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
   Solicitud sol1 =  Solicitud();
   sol1.doOperation("127.0.0.1",7200,0,"2,5");

   
   
   return 0;
}