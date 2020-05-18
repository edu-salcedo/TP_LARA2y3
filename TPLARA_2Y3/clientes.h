#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
using namespace std;
struct fecha
{
    int dia,mes,anio;
};
struct cliente
{
    int id ;
    char apellido[50],nombre[50],direccion[50],mail[50];
    int cp;
    fecha fecha_nac;
    bool estado;
};
const char *PATH_CLIENTE ="datocli/cliente.dat";

void opcion_cliente()
{
    struct cliente reg;
    int op;
    do
    {
        op = menu_cliente();
        switch(op)
        {
        case 1:
            if (registrar_cliente(&reg))
            {
                guardar_cliente(reg);
            }
            break;
        case 2:
            modificar_cliente();
            break;
        case 3:
            listar_cliente_id();
            break;
        case 4:
            listar_registros(reg);
            break;
        case 5:
            baja_cliente();
            break;
        case 0:
            return;
            break;
        }
    }
    while(op!=0);
}

bool registrar_cliente(cliente *reg)
{
    int id;
    id=(cantidad_clientes()+1);
    reg->id=id;
    validar_campovacio(cad,"NOMBRE ");
    strcpy(reg->nombre,cad);
    validar_campovacio(cad,"APELLIDO ");
    strcpy(reg->apellido,cad);
    validar_mail(reg);
    validar_campovacio(cad,"DIRECCION ");
    strcpy(reg->direccion,cad);
    do
    {
        cout << "INGRESE CP "<<endl;
        cin>>reg->cp;
        if (reg->cp<1000||reg->cp>9999)
        {
            cout <<"  el cp debe ser entre 1000 y 9999 "<<endl;
        fflush(stdin);
        cin.get();
        cls();
        }
        cls();
    }
    while(reg->cp<1000||reg->cp>9999);
    fecha_validada(reg);
    cout <<endl;
    setColor(YELLOW);
    cout<<" EL REGISTRIO SE GUARDO CORRECTAMENTE ";
    fflush(stdin);
    cin.get();
    cls();
    reg->estado=true;
    return true;
}

void guardar_cliente(cliente reg)
{
    FILE *p;
    p=fopen(PATH_CLIENTE,"ab");
    if (p==NULL)
    {
        cout <<" no se encontro archivo :";
        return;
    }
    fwrite(&reg,sizeof(cliente),1,p);
    fclose(p);

}

void modificar_cliente()
{
    int id,pos,op;
    intro_cliente();
    id= validacion_negativo(" ID ");
    pos=buscar_ID_cliente(id);
    cliente reg=leer_cliente(pos);
    if (pos>=0&&reg.estado==true)
    {

        do
        {
            op = menu_edita_cliente(reg.id);
            switch(op)
            {
            case 1:  cout<<"\n   EL APELLIDO ACTUAL ES "<<reg.apellido;
                     cout<<endl;
                if(menu_continuar("DE CAMBIAR EL APELLIDO "))
                {
                validar_campovacio(cad,"APELLIDO ");
                strcpy(reg.apellido,cad);
                sobreescribir_registro(reg,pos);
                cout <<"\n EL APELLIDO SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
                break;
            case 2: cout<<"\n   EL NOMBRE ACTUAL ES "<<reg.nombre;
                    cout<<endl;
                if(menu_continuar("DE CAMBIAR EL NOMBRE "))
                {
                validar_campovacio(cad,"NOMBRE ");
                strcpy(reg.nombre,cad);
                sobreescribir_registro(reg,pos);
                cout <<"\n EL  NOMBRE SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
                break;
            case 3:cout<<"\n   EL MAIL ACTUAL ES "<<reg.mail;
                  cout<<endl;
                if(menu_continuar("DE CAMBIAR EL MAIL "))
                {
                validar_mail(&reg);
                sobreescribir_registro(reg,pos);
                cout <<"\n EL  MAIL SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
                break;
            case 4:cout<<"\n   LA DIRECCION ACTUAL ES "<<reg.direccion;
                  cout<<endl;
                if(menu_continuar("DE CAMBIAR LA DIRECCION "))
                {
                validar_campovacio(cad,"DIRECCION ");
                strcpy(reg.direccion,cad);
                sobreescribir_registro(reg,pos);
                cout <<"\n LA DIRECCION SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
                break;
            case 5:
                 cout<<"\n   EL CP ACTUAL ES "<<reg.cp;
                 cout<<endl;
                if(menu_continuar("DE CAMBIAR EL CP "))
                {
                    do{
                    cout << "INGRESE CP "<<endl;
                    cin>>reg.cp;
                    if (reg.cp<1000||reg.cp>9999)
                    {
                        cout <<"  el cp debe ser entre 1000 y 9999 "<<endl;
                    }
                }
                while(reg.cp<1000||reg.cp>9999);

                sobreescribir_registro(reg,pos);
                cout <<"\n EL CP SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
                break;
            case 6:
                 cout<<"\n  LA FECHA DE NACIMIENTO  ACTUAL ES ";
                 cout<<reg.fecha_nac.dia<<"/"<<reg.fecha_nac.mes<<"/"<<reg.fecha_nac.anio;
                 cout<<endl;
                if(menu_continuar("DE CAMBIAR la FECHA "))
                {
                fecha_validada(&reg);
                sobreescribir_registro(reg,pos);
                cout <<"\n LA FECHA DE NACIMIENTO SE HA CAMBIADO";
                fflush(stdin);
                cin.get();
                cls();
                }
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
   fflush(stdin);
    cin.get();
    cls();
}

void listar_cliente_id()     //funcion que solo muestra el cliente del id ingresado
{
    int id,pos;
    intro_cliente();
    id=validacion_negativo("ID ");

    pos = buscar_ID_cliente(id);
    if (pos>=0)
    {
        cliente reg =leer_cliente(pos);
        if (reg.estado==true)
        {
         campos_cliente();
            listar_cliente(reg);
        }
        else
        {
            no_encontro_id();
            fflush(stdin);
             cin.get();
              cls();
        }
    }
    else
    {
        no_encontro_id();
    }
     fflush(stdin);
      cin.get();
       cls();
}


int buscar_ID_cliente(int id)
{

    cliente reg;
    int i=0;
    FILE *p;
    p=fopen(PATH_CLIENTE,"rb");
    if (p==NULL)
    {
        cout <<"no se encontro archivo";
        return -1;
    }
    while (fread(&reg, sizeof(cliente),1,p))
    {
        if (id==reg.id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

struct cliente leer_cliente(int pos)
{
    cliente reg;
    FILE *p;
    p=fopen(PATH_CLIENTE,"rb");
    if (p==NULL)
    {
        cout<<"no se encontro archivo\n";
        reg.id= -1;
        return reg;
    }
    fseek(p,pos*sizeof(cliente),SEEK_SET);
    fread(&reg,sizeof(cliente),1,p);
    fclose(p);
    return reg;
}

void listar_registros(cliente reg)  // Lista todos los registros existentes de los clientes
{   int cant;                         // por apellido
    cant= cantidad_clientes();
    cliente*vec;
   vec= (cliente*)malloc(cant*sizeof(cliente));
   if (vec==NULL)
   {
       cout <<"no hay memoria";
       return;
   }
    FILE *p;
    p=fopen(PATH_CLIENTE,"rb");
    if (p==NULL)
    {  free(vec);
        cout <<"no se pudo abrir archvo";
        return;
    }
    fread(vec,sizeof(cliente),cant,p);
    fclose(p);
    ordenar_cliente(vec,cant);
    campos_cliente();
     for (int i=0;i<cant;i++)
     {    if(vec[i].estado)
          {
          listar_cliente(vec[i]);
          }
     }
     fflush(stdin);
     cin.get();
     cls();
     free(vec);
}

int cantidad_clientes()
{
    int i;
    FILE *p;

    p=fopen(PATH_CLIENTE,"ab");

    fseek(p,SEEK_SET,SEEK_END);

    i=(ftell(p)/sizeof(cliente));

    fclose(p);
    return i;
}

void listar_cliente(cliente reg)
{
     setColor(WHITE);
    cout <<"   ";
    cout <<left;
    cout<<setw(5)<<reg.id;
    cout<<setw(15)<<reg.apellido;
    cout<<setw(20)<<reg.nombre;
    cout<<setw(25)<<reg.mail;
    cout<<setw(25)<<reg.direccion;
    cout<<setw(7)<<reg.cp;
    cout<<reg.fecha_nac.dia;
    cout<<"/"<<reg.fecha_nac.mes<<"/"<<reg.fecha_nac.anio<<endl;
}

// validaciones
// de campos a cargar

void validar_campovacio(char *cad,char *op)
{
    int i;

    do
    {
        cout <<endl;
        cout <<" INGRESE "<<op;
        fflush(stdin);
        cin.getline(cad,50,'\n');
        i=strlen(cad);
        if (i==0||cad[0]==32)
        {
            setColor(LIGHTRED);
            cout <<" ESTE CAMPO ES OBLOGATORIO ";
            cin.get();
            cls();
        }
    }
    while(i==0);
    cls();

}


void fecha_validada(cliente *reg)
{
    bool a=true;
    fecha hoy;
    hoy=fecha_actual();
    do
    {
        cout << " FECHA DE NACIMIENTO "<<endl;
        cout <<" DIA ";
        cin>>reg->fecha_nac.dia;
        cout <<" MES ";
        cin>>reg->fecha_nac.mes;
        cout <<" ANIO ";
        cin>>reg->fecha_nac.anio;
        if (reg->fecha_nac.dia<1||reg->fecha_nac.dia>30)
        {
            cout <<" el dia ingresado es invalido"<<endl;
            fflush(stdin);
            cin.get();
            cls();
            a=false;
        }
        if (reg->fecha_nac.mes<1||reg->fecha_nac.mes>12)
        {
            cout <<" ingrese mes solo entre 1 y 12"<<endl;
            fflush(stdin);
            cin.get();
            cls();
            a=false;
        }

        if (reg->fecha_nac.anio>hoy.anio)
        {
            cout <<" anio incorrecto  "<<endl;
            fflush(stdin);
            cin.get();
            cls();
            a=false;
        }
        else
        {
            if ((reg->fecha_nac.anio==hoy.anio) && (reg->fecha_nac.mes==hoy.mes) && (reg->fecha_nac.dia<hoy.dia))
            {
              a=true;
            }
            else
            {
                if (reg->fecha_nac.anio<hoy.anio)
                {
                    a=true;
                }
                else
                {
                    cout <<" anio incorrecto  "<<endl;
                    fflush(stdin);
                    cin.get();
                    cls();
                    a=false;

                }
            }

        }

    }
    while(a==false);

    cls();
}


void validar_mail(cliente * reg)
{
    char email[50];
    int vec[5]= {0};
    bool valido;
    int i=0 ;
    do
    {   cout <<endl;
        cout <<"  INGRESE EMAIL :" ;
        fflush(stdin);
        cin.getline(email,50,'\n');
        if (email[0]=='@'||email[0]=='.')
        {
            cout <<" el mail no puede iniciar con @ o punto  "<<endl;
            fflush(stdin);
            cin.get();
            cls();
            valido=false;
        }
        else
        {
            while(email[i]!='\0')
            {
                if (email[i]=='@')
                {
                    vec[0]++;
                }
                if (email[i]=='.'&&email[i-1]=='.')
                {
                    vec[1]++;
                }
                if (email[i]==32)
                {
                    vec[2]++;
                }
                i++;
            }
            if (vec[0]==1&&vec[1]==0&&vec[2]==0)
            {
                valido=true;
                strcpy(reg->mail,email);
            }
            else
            {
                cls();
                setColor(LIGHTRED);
                cout <<"\n   MAIL INVALIDO ";
                setColor(LIGHTGREEN);
                cout <<"\n el mail debe tener un espacios";
                cout <<"\n no puede tener mas de un @";
                cout <<"\n no puede tener dos puntos seguidos "<<endl;

                saveDefaultColor ();
                fflush(stdin);
                cin.get();
                cls();
                valido=false;
            }

        }
    }
    while(!valido);
    cls();
}

bool sobreescribir_registro(cliente reg,int pos)   // funcion que cambia los datos de registro cliente
{
    bool escribio;
    FILE * p;
    p=fopen(PATH_CLIENTE,"rb+");
    if(p==NULL)
    {
        cout <<"no se pudo abrir archivo\n";
        return false;
    }
    fseek(p,pos*sizeof(cliente),SEEK_SET);
    escribio=fwrite(&reg,sizeof(cliente),1,p);
    fclose(p);
    return escribio;
}

void baja_cliente()
{
    int id,pos;
    intro_cliente();
    id= validacion_negativo(" ID ");
    pos= buscar_ID_cliente(id);
    cliente reg=leer_cliente(pos);
    if (pos>=0&&reg.estado==true)
    {
        campos_cliente();
            listar_cliente(reg);
        cout <<endl;
        cout << "\n     ESTE ID CONTIENE ESTOS CAMPOS "<<endl;
        cout <<endl;
       int c= menu_continuar("ELIMINAR  ESTE CLIENTE ");
       if (c)
       {
        reg.estado=false;
        sobreescribir_registro(reg,pos);
        cout <<endl;
        cout <<right;
        cout <<setw(50)<<" ESTE CLIENTE SE HA DADO DE BAJA ";
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

void ordenar_cliente(cliente *vec,int tam)             //funcion ordena le registro de clientes por nombre
{
    int pos;
     cliente aux;
     for (int i=0;i<tam-1;i++)
    {   pos =i;
        for (int j=0;j<tam;j++)
        {
            if (vec[j].apellido<vec[pos].apellido)
            {
                pos=j;
            }
            aux=vec[i];
            vec[i]=vec[pos];
            vec[pos]=aux;
        }
    }
}

void campos_cliente()
{
    setColor(LIGHTMAGENTA);
    cout<<"---------------------------------------------------------";
    cout<<"---------------------------------------------------------"<<endl;
    setColor(WHITE);
    cout <<setw(5)<<"  ID"<<setw(13)<<"APELLIDO"<<setw(10);
    cout <<setw(13)<<"NOMBRE"<<setw(23)<<"MAIL";
    cout <<setw(25)<<"DOMICILIO"<<setw(17)<<"CP"<<setw(13)<<"FECHA NAC"<<endl;
    setColor(LIGHTMAGENTA);
    cout<<"---------------------------------------------------------";
    cout<<"---------------------------------------------------------"<<endl;
}

#endif // CLIENTES_H_INCLUDED
