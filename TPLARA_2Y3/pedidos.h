#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
using namespace std;
struct pedidos
{
    int id ;
    int id_cliente;
    int id_plato;
    int cantidad;
    float precio_unitari;
    fecha fecha_pedido;
    float valoracion;
    int estado ;
};
const char *PATH_PEDIDOS="datos_pedido/pedido.dat";


void opccion_pedido()
{     int opciones;
     struct pedidos reg_pedido;
      do{
            opciones=menu_pedidos();
            switch(opciones)
            {
            case 1:
                if (registrar_pedidos(&reg_pedido))
                {
                    guardar_pedido(reg_pedido);
                }
                break;
            case 2:
                editar_pedido();
                break;
            case 3:
                listar_pedido_id();
                break;
            case 4:
                listar_todo_pedidos(reg_pedido);
                break;

            }
      }while(opciones!=0);

}

bool registrar_pedidos(struct pedidos *reg_p)
{  int id,pos;
    cliente reg_cli;
    platos plato;
    id=(cantidad_pedidos()+1);
    reg_p->id = id;
    do{
      id= validacion_negativo(" ID CLIENTE ");
      pos = buscar_ID_cliente(id);
       reg_cli =leer_cliente(pos);
    if (pos <0|| reg_cli.estado==false)
    {
        no_encontro_id();
        fflush(stdin);
        cin.get();
        cls();
    }
    }while(pos <0|| reg_cli.estado==false);

    reg_p->id_cliente=id;
        do{
    id = validacion_negativo(" ID PLATO ");
    pos = buscar_ID_plato(id);
      plato= leer_platos(pos);
    if (pos <0||plato.estado==false)
    {
        no_encontro_id();
        fflush(stdin);
        cin.get();
        cls();
    }
    }while(pos <0||plato.estado==false);

    reg_p->id_plato=id;

    reg_p->cantidad = validacion_negativo(" CANTIDAD");
    plato=leer_platos(pos);
    reg_p->precio_unitari= plato.valor;
    reg_p->fecha_pedido  = fecha_actual();

    do{
    cout <<"\n INGRESE VALORACION  ";
    cin>>reg_p->valoracion;
    if (reg_p->valoracion<0||reg_p->valoracion>10)
    {
     cout<<"\n el rango de valoracion es de 0 a 10 "<<endl;
    }
      fflush(stdin);
      cin.get();
      cls();
    }while(reg_p->valoracion<0||reg_p->valoracion>10);

     reg_p->estado=1;
  cout <<"\n EL PEDIDO SE GUARDO CORECTAMENTE";
  fflush(stdin);
  cin.get();
  cls();
 return true;
}


int cantidad_pedidos()
{
  int i;
    FILE *p;

    p=fopen(PATH_PEDIDOS,"ab");

      fseek(p,SEEK_SET,SEEK_END);

    i=(ftell(p)/sizeof(pedidos));

    fclose(p);
    return i;
}


 void guardar_pedido( pedidos reg)
 {
    FILE *p;
    p=fopen(PATH_PEDIDOS,"ab");
    if (p==NULL)
    {   cout <<"no se encontro archivo ";

        return ;
    }
    fwrite(&reg,sizeof(pedidos),1,p);
    fclose(p);
 }


 void editar_pedido()
 {
    int id,pos,op;
   pedidos reg;
   intro_pedido();
   pos =buscar_ID_pedido();
   reg = leer_pedidos(pos);
    if (pos>=0)
    {

        do
        {
            op = menu_edita_pedido(reg.id,reg.estado);
            switch(op)
            {
            case 1:
                    if (menu_continuar("CAMBIAR DE ESTADO"))
                    {
                       reg.estado =1;
                      cambiar_estado(reg,pos);
                      cout <<"\n EL ESTADO SE HA CAMBIADO A : "<<reg.estado;
                      fflush(stdin);
                      cin.get();
                      cls();
                    }
                break;
            case 2:
                    if (menu_continuar("CAMBIAR DE ESTADO"))
                    {
                       reg.estado =2;
                      cambiar_estado(reg,pos);
                      cout <<"\n EL ESTADO SE HA CAMBIADO A : "<<reg.estado;
                      fflush(stdin);
                      cin.get();
                      cls();
                    }
                break;
            case 3:
                    if (menu_continuar("CAMBIAR DE ESTADO"))
                    {
                       reg.estado =3;
                      cambiar_estado(reg,pos);
                      cout <<"\n EL ESTADO SE HA CAMBIADO A : "<<reg.estado;
                      fflush(stdin);
                      cin.get();
                      cls();
                    }
                 break;

                case 0:return;
                break;
            }
        }
        while (op!=0);
    }
    else
    {
        no_encontro_id();
    }
    fflush(stdin);
    cin.get();
    cls();
 }


 void listar_pedido_id()
 {
      int pos;
    pedidos reg_p;
    intro_pedido();
    pos = buscar_ID_pedido();

    if (pos>=0)
    {
       reg_p =leer_pedidos(pos);
       campos_pedido();
        listar_pedidos(reg_p);
        fflush(stdin);
        cin.get();
    }
    else {
        no_encontro_id();
        fflush(stdin);
        cin.get();
        cls();
    }
    cls();
 }

 void listar_pedidos(pedidos reg)
 {
    setColor(WHITE);
   cout<<left;
   cout<<"  "<<setw(8)<<reg.id;
   cout<<setw(13)<<reg.id_cliente;
   cout<<setw(10)<<reg.id_plato;
   cout<<setw(8)<<reg.cantidad;
   cout<<setw(1)<<"$ ";
   cout<<setw(7)<<reg.precio_unitari;
   cout<<reg.fecha_pedido.dia;
   cout<<"/"<<reg.fecha_pedido.mes<<"/";
   if (reg.fecha_pedido.dia<10&&reg.fecha_pedido.mes<10)
   {
       cout<<reg.fecha_pedido.anio<<setw(8)<<(" ");

   }
   else{
         if (reg.fecha_pedido.dia>10&&reg.fecha_pedido.mes>10)
         {
           cout<<reg.fecha_pedido.anio<<setw(6)<<(" ");

         }
        else{
   cout<<setw(11)<<reg.fecha_pedido.anio;}
   }
   cout<<setw(10)<<reg.valoracion;
   cout<<setw(10)<<reg.estado<<endl;

 }

 void listar_todo_pedidos(pedidos reg)
 {
     FILE *p;
     p=fopen(PATH_PEDIDOS,"rb");
     if (p==NULL)
     {
         cout <<"no se encontro archivo ";
         return;
     }
    campos_pedido();
     while(fread(&reg,sizeof(pedidos),1,p))
     {
         listar_pedidos(reg);
     }
     fclose(p);
     fflush(stdin);
     cin.get();
     cls();
 }


fecha  fecha_actual()
 {
     fecha hoy;
     time_t t;
     t=time(NULL);
     struct tm *f;
     f=localtime(&t);
     hoy.anio=f->tm_year+1900;
     hoy.dia=f->tm_mday;
     hoy.mes=f->tm_mon+1;
     return hoy;
 }

int buscar_ID_pedido()
{   int id;
   id = validacion_negativo(" ID ");
    pedidos reg_p;
    int i=0;
    FILE *p;
    p=fopen(PATH_PEDIDOS,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo";
        return -1;
    }
    while (fread(&reg_p, sizeof(pedidos),1,p))
    {
        if (id==reg_p.id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}


struct pedidos leer_pedidos(int pos)
{
    pedidos reg_p;
    FILE *p;
    p=fopen(PATH_PEDIDOS,"rb");
    if (p==NULL)
    {
        cout<<"no se encontro archivo\n";
        reg_p.id= -1;
        return reg_p;
    }
    fseek(p,pos*sizeof(pedidos),SEEK_SET);
    fread(&reg_p,sizeof(pedidos),1,p);
    fclose(p);
    return reg_p;
}

bool cambiar_estado(pedidos reg_pedido,int pos)
{
     bool escribio;
    FILE *p;
    p=fopen(PATH_PEDIDOS,"rb+");
    if (p==NULL)
   {
       cout <<" no se encontro archivo**** ";
       return false;
   }
   fseek(p,pos*sizeof(pedidos),SEEK_SET);
   escribio =fwrite(&reg_pedido,sizeof(pedidos),1,p);
   fclose(p);
   return escribio;
}

void campos_pedido()
{
     setColor(LIGHTMAGENTA);
    cout<<"-----------------------------------------";
    cout<<"-----------------------------------------"<<endl;
    setColor(WHITE);
   cout <<"  ID  "<<" ID CLIENTE  "<<" ID PLATO "<<" CANTIDAD ";
   cout<< "  PRECIO   "<<"  FECHA  "<< "   VALORACION "<< " ESTADO "<<endl;
    setColor(LIGHTMAGENTA);
        cout<<"-----------------------------------------";
    cout<<"-----------------------------------------"<<endl;
}
#endif // PEDIDOS_H_INCLUDED
