#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "rlutil.h"
using namespace rlutil;
#include <string.h>
# include <cstdlib>
# include  <cstdio>
#include <ctime>
# include <iomanip>
using namespace std;
#include "prototipo.h"
#include  "menus.h"
#include "clientes.h"
#include "pedidos.h"
#include "platos.h"
#include "reportes_configuraciones.h"


int main()
{ int op;
    do{
    op=menuPrincipal();
    if (op)
    {
        switch(op)
        {
        case 1:opcion_plato();
            break;
        case 2:opcion_cliente();
            break;
        case 3:opccion_pedido();
            break;
        case 4:opccion_reporte();
            break;
        case 5:opccion_config();
            break;
        }
    }
   } while (op!=0);
    return 0;
}

