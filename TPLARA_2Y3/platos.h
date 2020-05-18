#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

using namespace std;

const char *PATH_PLATOS = "datosplat/platos.dat";

void opcion_plato()
{
    struct platos plato;
    int opciones;
    do
    {

            opciones = menuPlato();
            switch(opciones)
            {
            case 1:
                if (cargar_plato(&plato))
                {
                    guardar_plato(plato);
                }

                break;
            case 2:
                editar_plato();
                break;
            case 3:
                listar_plato_id(plato);
                break;
            case 4:
                platos_restaurante(plato);
                break;
            case 5:
                listar_todo(plato);
                break;
            case 6:
                baja_plato();
                break;
            }
   } while(opciones!=0);
}


bool cargar_plato(platos *plat)
{
    int i,op,id;
    id =validacion_negativo(" ID ");
    op=buscar_ID_plato(id);
    cls();
    if(op==-1)
    {
        plat->id= id;
        validar_campovacio(cad," NOMBRE ");
        strcpy(plat->nombre,cad);
        plat->costoPre=validacion_costo();                      //  validando las condicones mediante funciones con
        plat->valor=validacion_venta(plat->costoPre);           //  retorno.
        plat->tiempo_Pre=  validacion_negativo(" TIEMPO DE PREPARACION  ");
        plat->id_Restaurante=validacion_negativo(" ID DEL RESTAURANTE  ");
        plat->comision_Rest= validacion_comision();
        plat->id_categoria=validacion_negativo(" ID DE CATEGORIA  ");
        plat->estado=true;
        cls();
        cout <<endl;
        setColor(YELLOW);
        cout << "************************************"<<endl;
        cout << "   EL PLATO SE CARGO CORRECTAMENTE  "<<endl;
        cout << "************************************"<<endl;
        fflush(stdin);
        cin.get();
        cls();
        return true;
    }
    else{
    cout <<endl;
    setColor(LIGHTRED);
    cout <<" ESTE ID YA EXISTE INTENTE CON OTRO ID"<<endl;
    fflush(stdin);
    cin.get();
    cls();
    return false;
    }
}


int buscar_ID_plato(int id)
{
    platos plat;
    int i=0;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo";
        return -1;
    }
    while (fread(&plat, sizeof(platos),1,p))
    {

        if (id==plat.id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}


void guardar_plato(platos plat)
{
    FILE *p;
    p=fopen(PATH_PLATOS,"ab");
    if (p==NULL)
    {
        cout <<" no se pudo abrir archivo";
    }
    fwrite(&plat,sizeof(platos),1,p);
    fclose(p);
}


int listar(platos plat)      // muestra los campos que tiene del plato
{
    fflush(stdin);
    setColor(WHITE);

    cout <<"  ";
    cout <<setw(7)<<plat.id;
    cout <<setw(22)<<plat.nombre;
    cout <<right;
    cout <<setw(1)<<"$";
    cout <<setw(4)<<plat.costoPre;
    cout <<setw(5)<<"$";
    cout <<setw(4)<<plat.valor;
    cout <<setw(8)<<plat.tiempo_Pre;
    cout <<setw(10)<<plat.id_Restaurante;
    cout <<setw(15)<<plat.comision_Rest<<" %";
    cout <<setw(10)<<plat.id_categoria;
    cout <<left;
    cout <<endl;
}


void listar_plato_id(platos plat)
{
    int id,pos;
    intro_plato();
    id= validacion_negativo(" ID  ");
    pos= buscar_ID_plato(id);
    if (pos>=0)

    {
        platos plat =leer_platos(pos);
        if (plat.estado==true)
        {
            nombre_campos();
            listar(plat);
        }
        else
        {
            no_encontro_id();
        }
    }
    else
    {
        no_encontro_id();
    }
    cin.ignore();
    cin.get();
    cls();
}

void listar_todo(platos plat)                    //lista todos los platos que estan registrados
{
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se pudo abrir archvo";
        return;
    }
     nombre_campos();
    while(fread(&plat,sizeof(platos),1,p))
    {
        if (plat.estado==true)
        {
            listar(plat);
        }
    }
    fclose(p);
    fflush(stdin);
    cin.get();
    cls();
}


struct platos leer_platos(int pos)
{
    platos plat;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout<<"no se encontro archivo\n";
        plat.id= -1;
        return plat;
    }
    fseek(p,pos*sizeof(platos),SEEK_SET);
    fread(&plat,sizeof(platos),1,p);
    fclose(p);
    return plat;
}


void editar_plato()
{
    int id,pos,op;
    platos plato;
      intro_plato();
    id =validacion_negativo(" ID PLATO ");
     cls();
    pos= buscar_ID_plato(id);
    plato=leer_platos(pos);
    if (pos>=0&&plato.estado==true)
    {
        do
        {
            op= menu_editar(id);
            switch(op)
            {
            case 1: if (menu_continuar("DE CAMBIAR EL NOMBRE DE PLATO"))
               {
               validar_campovacio(cad," NOMBRE DE PLATO ");
               strcpy(plato.nombre,cad);
                sobreescribir(plato,pos);
                cout <<"\n EL NOMBRE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 2:if(menu_continuar("DE CAMBIAR EL COSTO DE PREPARACION "))
               {
                plato.costoPre=validacion_costo();

                sobreescribir(plato,pos);
                cout <<"\n EL COSTO HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 3:if(menu_continuar("DE CAMBIAR EL VALOR DE VENTA "))
               {
                 plato.valor=validacion_venta(plato.costoPre);

                sobreescribir(plato,pos);
                cout <<"\n EL VALOR VENTA HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 4:
                if(menu_continuar("DE CAMBIAR ELTIEMPO DE PREPARACION "))
               {
                plato.tiempo_Pre=  validacion_negativo(" TIEMPO DE PREPARACION  ");
                sobreescribir(plato,pos);
                cout <<"\n EL TIEMPO  HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 5:if(menu_continuar("DE CAMBIAR EL ID RESTAURANTE "))
               {
               plato.id_Restaurante=validacion_negativo(" ID DEL RESTAURANTE  ");
                sobreescribir(plato,pos);
                cout <<"\n EL ID RESTAURANTE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 6:if(menu_continuar("DE CAMBIAR COMICION "))
               {
                 plato.comision_Rest= validacion_comision();
                sobreescribir(plato,pos);
                cout <<"\n LA COMICION HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 7:if(menu_continuar("DE CAMBIAR EL ID DE CATEGORIA "))
               {
                 plato.id_categoria=validacion_negativo(" ID DE CATEGORIA  ");
                sobreescribir(plato,pos);
                cout <<"\n EL ID DE CATEGORIA HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
               }
                break;
            case 0: return;
                break;
            }
        cls();
        }while (op!=0);

    }
    else
    {
        no_encontro_id();
    }
    fflush(stdin);
    cin.get();
    cls();
}

bool sobreescribir(platos plat,int pos)
{
    bool escribio;
    FILE * p;
    p=fopen(PATH_PLATOS,"rb+");
    if(p==NULL)
    {
        cout <<"no se pudo abrir archivo\n";
        return false;
    }
    fseek(p,pos*sizeof(platos),SEEK_SET);
    escribio=fwrite(&plat,sizeof(platos),1,p);
    fclose(p);
    return escribio;

}


void platos_restaurante(platos plat)     // lista platos por  id de restaurante
{
    int id_resta,i=0,id;
    bool res =true;
    intro_plato();
    id_resta=validacion_negativo(" ID RESTAURANTE ");
    id=buscar_ID_resta(id_resta);
    if(id_resta>=0&&id>=0)
    {
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo" <<endl;
        return ;
    }
       nombre_campos();
    do
    {
        fseek(p,i*sizeof(platos),SEEK_SET);
        res=fread(&plat,sizeof(platos),1,p);
        if (plat.id_Restaurante==id_resta)
        {
            platos plato =leer_platos(i);
            listar(plato);
        }
        i++;
    }while (res);
    fclose(p);
    fflush(stdin);
    cin.get();
    cls();
    }else{
        no_encontro_id();
        fflush(stdin);
        cin.get();
        cls();
    }
}


void baja_plato()
{
    int id,pos;
    intro_plato();
    id =validacion_negativo("ID PLATO ");
    pos= buscar_ID_plato(id);
    platos plato=leer_platos(pos);
    if (pos>=0&&plato.estado==true)
    {
          nombre_campos();
           listar(plato);
        cout <<endl;
        cout << "\n     ESTE ID CONTIENE ESTOS CAMPOS "<<endl;
        cout <<endl;
       int c= menu_continuar("ELIMINAR  ESTE PLATO ");
       if (c)
       {
        plato.estado=false;
        sobreescribir(plato,pos);
        cout<<endl;
        cout <<right;
        cout<<endl;
        cout <<setw(40)<<"ESTE PLATO SE HA DADO DE BAJA ";
           fflush(stdin);
           cin.get();
           cls();
       }
    }
    else
    {
        no_encontro_id();
        fflush(stdin);
        cin.get();
        cls();
    }
}

void no_encontro_id()                     // funcion que muestra un mensaje que no se necontro id
{
     cout <<endl;
    cout <<endl;
    setColor(LIGHTGREEN);
    cout <<setw(50)<<" =============================="<<endl;
    setColor(LIGHTRED);
    cout <<setw(50)<<"     NO SE ENCONTRO EL  ID  "<<endl;
    setColor(LIGHTGREEN);
    cout <<setw(50)<<" =============================="<<endl;
    setColor(WHITE);

}

int validacion_negativo(char *cade)
{
    int valor;
    do{
        cout<<endl;
        cout<<right;
        cout <<setw(30)<<"INGRESE  "<<cade;
        cin>>valor;
        if (valor<0)
        {
            setColor(RED);
            cout <<"\n no se puede ingresar valores negativos"<<endl;
            setColor(LIGHTCYAN);
            cout<<endl;
            fflush(stdin);
            cin.get();

        }
    }
    while(valor<0);
    cls();
    return valor;
}

int cantidad_platos()
{
     int i;
    FILE *p;

    p=fopen(PATH_PLATOS,"ab");

    fseek(p,SEEK_SET,SEEK_END);

    i=(ftell(p)/sizeof(platos));

    fclose(p);
    return i;
}

int buscar_ID_resta(int id)               //  funcion que busca el id de restaurante
{
    platos plat;
    int i=0;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo";
        return -1;
    }
    while (fread(&plat, sizeof(platos),1,p))
    {
        if (id==plat.id_Restaurante)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -2;
}


void nombre_campos()                  //nombre de los campos que contiene un registro
{
     setColor(WHITE);
            cout<<left;
            cout <<setw(10)<<"  ID"<<setw(22)<<"  NOMBRE"<<setw(9)<<"COSTO";
            cout<<setw(8)<<"VENTA"<<setw(12)<<"TIEMPO PRE"<<setw(9)<<"ID REST";
            cout<<setw(15)<<"COMICION RES"<<"ID CATEGORIA"<<endl;
            setColor(LIGHTMAGENTA);
            cout <<"------------------------------------------------";
            cout <<"------------------------------------------------"<<endl;
}

#endif // PLATOS_H_INCLUDED
