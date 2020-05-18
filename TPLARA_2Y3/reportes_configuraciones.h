#ifndef REPORTES_CONFIGURACIONES_H_INCLUDED
#define REPORTES_CONFIGURACIONES_H_INCLUDED

using namespace std;
const char *PATH_BACKPLATO="backplato/plato.bkp";
const char *PATH_BACKCLIENTE="backcliente/cliente.bkp";
const char *PATH_BACKPEDIDO="backpedido/pedido.bkp";

void opccion_reporte()
{
    int opciones;

    do
    {

        opciones= menu_reportes();
        switch (opciones)
        {
        case 1:
            reporte_1();
            break;
        case 2:
            reporte_2();
            break;
        case 3 :
            reporte_3();
            break;
        }
    }
    while(opciones!=0);
}
void reporte_1()
{
    int cant;
    cliente reg;
    cant = cantidad_clientes();

    cout <<"\n ESTOS SON LOS CLIENTES QUE NO HICIERON PEDIDOS \n";
    campos_cliente();
    for(int i=0; i<cant; i++)
    {
        reg=leer_cliente(i);

        if (hizo_pedido(reg.id)==false)
        {
            listar_cliente(reg);
        }

    }

    fflush(stdin);
    cin.get();
    cls();
}

bool hizo_pedido(int id)
{
    int cant;
    cant = cantidad_pedidos();
    for (int i =0; i<cant; i++)
    {
        pedidos pedi= leer_pedidos(i);
        if (pedi.id_cliente==id)
        {
            return true;
        }
    }
    return false;
}


void reporte_2()
{
    int cant;
    cant =cantidad_platos();
    cout <<"\n ESTOS SON LOS PLATOS QUE NO SE VENDIERON \n";
    nombre_campos();
    for (int i=0; i<cant; i++)
    {
        platos plat=leer_platos(i);
        if (plato_vendido(plat.id)==false)
        {
            listar(plat);
        }
    }
    fflush(stdin);
    cin.get();
    cls();
}

bool plato_vendido(int id)
{
    int cant;

    cant = cantidad_pedidos();
    for (int i =0; i<cant; i++)
    {
        pedidos pedi= leer_pedidos(i);
        if (pedi.id_plato==id)
        {
            return true;
        }
    }
    return false;

}

void reporte_3()
{
    int cant ;
    cant =cantidad_pedidos();
    cout <<"\n ESTOS SON LOS PEDIDOS CON VALORACION 0\n";
     campos_pedido();
    for (int i=0; i<cant; i++)
    {
        pedidos pedi=leer_pedidos(i);
        if (pedi.valoracion==0)
        {
            listar_pedidos(pedi);
        }
    }
    fflush(stdin);
    cin.get();
    cls();
}


/////////////////////////////////////////7
void opccion_config()
{
    int op;
    do
    {
        op=menu_config();
        switch(op)
        {
        case 1:
            config_Platos();
            break;
        case 2:
            config_Clientes();
            break;
        case 3:
            config_Pedidos();
            break;
        case 0:return;
            break;
        }
    }
    while(op!=0);
}


void config_Platos()
{
    int op;
    do
    {    intro_plato();
        cout<<endl;
        cout<<right;
        cout<<setw(55)<<"USTED  ESTA EN CONFIGURACION DE PLATO "<<endl;

        op=menu_backup();
        switch(op)
        {
        case 1:
            if (menu_continuar("CREAR BACKUP DE PLATOS"))
               {
                backup_plato();
                setColor(YELLOW);
                cout <<"\n SE HAN COPIADO ESTOS DATOS"<<endl;
                cout <<endl;
                nombre_campos();
                lis_backplato();
               }

            break;
        case 2:   if (menu_continuar(" RESTAURAR EL BACKUP DE PLATOS"))
                   {

                   restaurar_plato();
                  cout <<"\ SE HA RESTAURADO LOS DATOS DEL BACKUP";
                  fflush(stdin);
                  cin.get();
                  cls();
                   }

            break;
        case 0:  return;
            break;
        }
    }
    while(op!=0);
}


void config_Clientes()
{
    int op;
    do
    {
        intro_cliente();
         cout<<endl;
        cout<<right;
        cout<<setw(55)<<"USTED  ESTA EN CONFIGURACION DE CLIENTE "<<endl;
        op=menu_backup();
        switch(op)
        {
        case 1:
            if (menu_continuar("CREAR BACKUP DE CLIENTES"))
            {
                backup_cliente();
                setColor(YELLOW);
                cout <<"\n SE HAN COPIADO ESTOS DATOS"<<endl;
                cout <<endl;
                campos_cliente();
                lis_backcliente();
            }

            break;
        case 2: if (menu_continuar("RESTAUAR BACKUP DE CLIENTES"""))
                {
               restaurar_cliente();
                  cout <<"\ SE HA RESTAURADO LOS DATOS DEL BACKUP";
                  fflush(stdin);
                  cin.get();
                  cls();
                 }

            break;
        case 0:
            return;
            break;
        }
    }
    while(op!=0);
}


void config_Pedidos()
{
int op;
    do
    {
        intro_pedido();
         cout<<endl;
        cout<<right;
        cout<<setw(55)<<"USTED  ESTA EN CONFIGURACION DE PEDIDO "<<endl;
        op=menu_backup();
        switch(op)
        {
        case 1:
            if (menu_continuar("CREAR BACKUP DE PEDIDOS"))
            {
                backup_pedido();
                setColor(YELLOW);
                cout <<"\n SE HAN COPIADO ESTOS DATOS"<<endl;
                cout <<endl;
                campos_pedido();
                lis_backpedido();
            }

            break;
        case 2: if (menu_continuar("RESTAURAR BACKUP DE PEDIDOS"))
                {
                restaurar_pedido();
                setColor(YELLOW);
                  cout <<"\ SE HA RESTAURADO LOS DATOS DEL BACKUP";
                  fflush(stdin);
                  cin.get();
                  cls();
                }

            break;
        case 0:
            return;
            break;
        }
    }
    while(op!=0);
}


void backup_plato()
{
    platos *vec;
    int cant;
    cant= cantidad_platos();
    vec=(platos*)malloc(cant*sizeof(platos));
    if(vec==NULL)
    {
        cout <<"no hay memoria";
        return;
    }
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {   free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    FILE *p2;
    p2=fopen(PATH_BACKPLATO,"wb");
    if (p2==NULL)
    {    free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fread(vec,sizeof(platos),cant,p);
    fwrite(vec,sizeof(platos),cant,p2);
    fclose(p);
    fclose(p2);
    free(vec);
    setColor(YELLOW);
    cout <<endl;

}

void backup_cliente()
{
   cliente *vec;
    int cant;
    cant= cantidad_clientes();
    vec=(cliente*)malloc(cant*sizeof(cliente));
    if(vec==NULL)
    {
        cout <<"no hay memoria";
        return;
    }
    FILE *p;
    p=fopen(PATH_CLIENTE,"rb");
    if (p==NULL)
    {   free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    FILE *p2;
    p2=fopen(PATH_BACKCLIENTE,"wb");
    if (p2==NULL)
    {    free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fread(vec,sizeof(cliente),cant,p);
    fwrite(vec,sizeof(cliente),cant,p2);
    fclose(p);
    fclose(p2);
    free(vec);
    setColor(YELLOW);
    cout<<endl;

}

void backup_pedido()
{   int cant;
    pedidos *vec;
    FILE *p,*p2;
     cant=cantidad_pedidos();
     vec=(pedidos*)malloc(cant*sizeof(cliente));
     if (vec==NULL)
     {
         cout <<"no hay memoria ";
         return;
     }
     p=fopen(PATH_PEDIDOS,"rb");
    if (p==NULL)
    {   free(vec);
        cout <<"no se pudo abrir archvo";
        return;
    }
    p2=fopen(PATH_BACKPEDIDO,"wb");
    if (p2==NULL)
    {  free(vec);
        cout <<"no se pudo abrir archvo";
        return;
    }
    fread(vec,sizeof(pedidos),cant,p);
    fwrite(vec,sizeof(pedidos),cant,p2);

    fclose(p2);
    fclose(p);
    setColor(YELLOW);
    cout <<endl;

}

void restaurar_plato()
{
    platos *vec;
    int cant;
    cant= cantidad_platos();
    vec=(platos*)malloc(cant*sizeof(platos));
    if(vec==NULL)
    {
        cout <<"no hay memoria";
        return;
    }
    FILE *p2;
    p2=fopen(PATH_BACKPLATO,"rb");
    if (p2==NULL)
    {   free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fread(vec,sizeof(platos),cant,p2);
    fclose(p2);
    FILE *p;
    p=fopen(PATH_PLATOS,"wb");
    if (p==NULL)
    {    free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fwrite(vec,sizeof(platos),cant,p);
    fclose(p);
    free(vec);

}

void restaurar_cliente()
 {
     cliente *vec;
    int cant;
    cant= cantidad_clientes();
    vec=(cliente*)malloc(cant*sizeof(cliente));
    if(vec==NULL)
    {
        cout <<"no hay memoria";
        return;
    }
    FILE *p2;
    p2=fopen(PATH_BACKCLIENTE,"rb");
    if (p2==NULL)
    {   free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fread(vec,sizeof(cliente),cant,p2);
    fclose(p2);
    FILE *p;
    p=fopen(PATH_CLIENTE,"wb");
    if (p==NULL)
    {    free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fwrite(vec,sizeof(cliente),cant,p);
    fclose(p);
    free(vec);

}

void restaurar_pedido()
{
    pedidos *vec;
    int cant;
    cant= cantidad_pedidos();
    vec=(pedidos*)malloc(cant*sizeof(pedidos));
    if(vec==NULL)
    {
        cout <<"no hay memoria";
        return;
    }
    FILE *p2;
    p2=fopen(PATH_BACKPEDIDO,"rb");
    if (p2==NULL)
    {   free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fread(vec,sizeof(pedidos),cant,p2);
    fclose(p2);
    FILE *p;
    p=fopen(PATH_PEDIDOS,"wb");
    if (p==NULL)
    {    free(vec);
        cout <<"no se encontro archivo ";
        return;
    }
    fwrite(vec,sizeof(pedidos),cant,p);
    fclose(p);
    free(vec);

}


void lis_backplato()       //lista los datod copiados en backup de platos
{
    platos plat;
    FILE *p;
    p=fopen(PATH_BACKPLATO,"rb");
    if (p==NULL)
    {
        cout <<"no se pudo abrir archvo";
        return;
    }
    while(fread(&plat,sizeof(platos),1,p))
    {
        listar(plat);
    }
    fclose(p);
    fflush(stdin);
    cin.get();
    cls();
}

void lis_backcliente()   // lista los datos copiados en backup de cliente
{
    cliente reg;
    FILE *p;
    p=fopen(PATH_BACKCLIENTE,"rb");
    if (p==NULL)
    {
        cout <<"no se pudo abrir archvo";
        return;
    }
    cout<<endl;
    while(fread(&reg,sizeof(cliente),1,p))
    {
        listar_cliente(reg);
    }
    fclose(p);
   fflush(stdin);
    cin.get();
    cls();
}

void lis_backpedido()    //lista los datos copiados en backup de pedidos
{
    pedidos reg;
    FILE *p;
    p=fopen(PATH_BACKPEDIDO,"rb");
    if (p==NULL)
    {
        cout <<"no se pudo abrir archvo";
        return;
    }
    while(fread(&reg,sizeof(pedidos),1,p))
    {
        listar_pedidos(reg);
    }
    fclose(p);
    fflush(stdin);
    cin.get();
    cls();
}

#endif // REPORTES_CONFIGURACIONES_H_INCLUDED
