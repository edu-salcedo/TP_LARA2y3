#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

const char *PATH_PLATOS = "datos/platos.dat";

void opcion_plato()
{
    struct platos plato;
    int opciones;
    do
    {
            intro();
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
    id =validacion_negativo(" ID");
    op=buscar_ID_plato(id);
    cls();
    if(op==-1)
    {
        plat->id= id;
        validar_campovacio(cad," NOMBRE ");
        strcpy(plat->nombre,cad);
        plat->costoPre=validacion_costo();                      //  validando las condicones mediante funciones con
        plat->valor=validacion_venta(plat->costoPre);           //  retorno.
        plat->tiempo_Pre=  validacion_negativo(" TIEMPO DE PREPARACION");
        plat->id_Restaurante=validacion_negativo(" ID DEL RESTAURANTE");
        plat->comision_Rest= validacion_comision();
        plat->id_categoria=validacion_negativo(" ID DE CATEGORIA");
        plat->estado=true;
        cls();
        cout <<"\n EL PLATO SE CARGO CORRECTAMENTE "<<endl;
        return true;
    }

    cout <<"  EL PLATO NO SE PUDO CARGAR "<<endl;
    cin.ignore();
    cin.get();
    cls();
    return false;
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


int listar(platos plat)
{
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
    id= validacion_negativo(" ID ");
    pos= buscar_ID_plato(id);
    if (pos>=0)

    {
        platos plat =leer_platos(pos);
        if (plat.estado==true)
        {
            setColor(WHITE);
            cout<<left;
            cout <<setw(10)<<"  ID"<<setw(22)<<"  NOMBRE"<<setw(9)<<"COSTO"<<setw(8)<<"VENTA";
            cout <<setw(12)<<"TIEMPO PRE"<<setw(9)<<"ID REST"<<setw(15)<<"COMICION RES"<<"ID CATEGORIA"<<endl;
            setColor(LIGHTMAGENTA);
            cout <<"------------------------------------------------------------------------------------------------"<<endl;
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

void listar_todo(platos plat)
{
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se pudo abrir archvo";
        return;
    }
    setColor(WHITE);
    cout<<left;
    cout <<setw(10)<<"  ID"<<setw(22)<<"  NOMBRE"<<setw(9)<<"COSTO"<<setw(8)<<"VENTA";
    cout <<setw(12)<<"TIEMPO PRE"<<setw(9)<<"ID REST"<<setw(15)<<"COMICION RES"<<"ID CATEGORIA"<<endl;
    setColor(LIGHTMAGENTA);
    cout <<"------------------------------------------------------------------------------------------------"<<endl;
    while(fread(&plat,sizeof(platos),1,p))
    {
        if (plat.estado==true)
        {
            listar(plat);
        }
    }
    fclose(p);
    cin.ignore();
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
            case 1:
                cin.ignore();
                cout<<" NUEVO NOMBRE  :";
                cin.getline(plato.nombre,50,'\n');
                sobreescribir(plato,pos);
                break;
            case 2:
                cout<<" NUEVO COSTO PREPARACION :";
                cin>>plato.costoPre;
                sobreescribir(plato,pos);
                break;
            case 3:
                cout<<" NUEVO VALOR VENTA   : ";
                cin>>plato.valor;
                sobreescribir(plato,pos);
                break;
            case 4:
                cout<<" NUEVO TIEMPO PREPARACION: ";
                cin>>plato.tiempo_Pre;
                sobreescribir(plato,pos);
                break;
            case 5:
                cout<<" NUEVO ID RESTAURANTE    :";
                cin>>plato.id_Restaurante;
                sobreescribir(plato,pos);
                break;
            case 6:
                cout<<" NUEVO COMICION RESTAURANTE:";
                cin>>plato.comision_Rest;
                sobreescribir(plato,pos);
                break;
            case 7:
                cout<<" NUEVO  ID CATEGORIA     : ";
                cin>>plato.id_categoria;
                sobreescribir(plato,pos);
                break;
            case 0:
                break;
            }
        }
        while (op!=0);
    }
    else
    {
        no_encontro_id();
    }
    cin.ignore();
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
    int id_resta,i=0;
    bool res =true;
    cout <<"ingrese ID del restaurante "<<endl;
    cin>>id_resta;
    FILE *p;
    p=fopen(PATH_PLATOS,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo" <<endl;
        return ;
    }

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
    }


    while (res);
    fclose(p);
    fflush(stdin);
    cin.get();
}


void baja_plato()
{
    int id,pos;
    pos= buscar_ID_plato(id);
    if (pos>=0)
    {
        platos plato=leer_platos(pos);
        plato.estado=false;
        sobreescribir(plato,pos);
    }
    else
    {
        no_encontro_id();
    }
}

void no_encontro_id()
{
    setColor(GREEN);
    cout <<" \n =============================="<<endl;
    setColor(LIGHTRED);
    cout <<"  no se encontro ID  "<<endl;
    setColor(GREEN);
    cout <<" =============================="<<endl;
    fflush(stdin);
    cin.get();
    cls();
}

int validacion_negativo(char *cade)
{
    int valor;
    do
    {
        cout <<"INGRESE "<<cade;
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
#endif // FUNCIONES_H_INCLUDED
