#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
using namespace std;
char cad[50];     //  declaro una variable global para usarla en diferentes funciones

struct platos
{
    int id ;
    char  nombre[50];
    float costoPre;
    float valor;
    float tiempo_Pre;
    int id_Restaurante;
    float comision_Rest;
    int id_categoria;
    bool estado;
};

void intro()
{
    setColor(LIGHTCYAN);
    cout <<"     ==============================================================================="<<endl;
    cout <<"     ==============================================================================="<<endl;
    setColor(WHITE);
    cout <<"               ###           @@@@         $$$$$$$$$$)        QQQQ                      "<<endl;
    cout <<"               ###          @@@@@@        $$$$$$$$$$))      QQQQQQ                     "<<endl;
    cout <<"               ###         @@@  @@@       $$$$     $$))    QQQ  QQQ                    "<<endl;
    cout <<"               ###        @@@    @@@      $$$$$$$$$$$)    QQQ    QQQ                   "<<endl;
    //setColor(BLUE);
    cout <<"               ###       @@@ @@@@ @@@     $$$$$$$$$$)    QQQ  QQQ QQQ                  "<<endl;
    cout <<"               ###      @@@        @@@    $$$$   $$$    QQQ        QQQ                 "<<endl;
    cout <<"               ######  @@@          @@@   $$$$    $$$  QQQ          QQQ                "<<endl;
    cout <<"               #######  @@@          @@@   $$$$    $$$  QQQ          QQQ                "<<endl;
    setColor(LIGHTCYAN);
    cout <<"     ==============================================================================="<<endl;
    cout <<"     ==============================================================================="<<endl;
}

void intro_plato()
{
        setColor(LIGHTCYAN);
    cout <<"                                                  @   @    @              "<<endl;
    cout <<"                                                    @   @  @       "<<endl;
    cout <<"                                                    @  @ @                            "<<endl;
    cout <<"                                                     @ @                       "<<endl;
    setColor(LIGHTRED);
    cout <<"                 ###        @@@@       $$$$$$$$$$)        QQQQ                      "<<endl;
    cout <<"                 ###       @@@@@@      $$$$$$$$$$))      QQQQQQ                     "<<endl;
    cout <<"                 ###      @@@  @@@     $$$$     $$))    QQQ  QQQ                    "<<endl;
    cout <<"                 ###     @@@    @@@    $$$$$$$$$$$)    QQQ    QQQ                   "<<endl;
    setColor(LIGHTCYAN);
    cout <<"               OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO                 "<<endl;
    cout <<"                  0000000000000000000000000000000000000000000000                    "<<endl;
    cout <<"                       000000000000000000000000000000000000                         "<<endl;
    cout <<"                           O000000000000000000000000000                             "<<endl;
    setColor(BROWN);
    cout <<"     ==============================================================================="<<endl;
    cout <<"     ==============================================================================="<<endl;
    setColor(LIGHTCYAN);
}

void intro_cliente()
{
     setColor(LIGHTCYAN);
    cout <<endl;
    cout <<endl;
    setColor(YELLOW);
    cout <<"                         00000                  00000                  "<<endl;
    cout <<"                       00     00              00     00                "<<endl;
    cout <<"                       00     00              00     00                "<<endl;
    cout <<"                    ( )  00000   ( )       ( )  00000   ( )            "<<endl;
    setColor(LIGHTCYAN);
    cout <<"                     ##  ######  ##         ##  ######  ##             "<<endl;
    cout <<"                      ############           ############              "<<endl;
    cout <<"                       ##########             ##########               "<<endl;
    cout <<"                      ############           ############              "<<endl;
    setColor(BROWN);
    cout <<"     ============================================================================"<<endl;
    cout <<"     ============================================================================"<<endl;
    setColor(LIGHTCYAN);
}

void intro_pedido()
{
    setColor(LIGHTRED);
    cout <<"              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$              $$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$                $$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$      $$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$$     $$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$      $$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$                $$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$              $$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    cout <<"              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$           "<<endl;
    setColor(LIGHTCYAN);
}

void intro_config()
{
    setColor(GREY);
    cout <<"                       $$$     $$$               $$   "<<endl;
    cout <<"                     $$$$     $$$$$             $$    "<<endl;
    cout <<"                    $$$$     $$$$$             $$     "<<endl;
    cout <<"                    $$$&    $$$$$             $$      "<<endl;
    cout <<"                    $$$$$$$$$$$              $$       "<<endl;
    cout <<"                     $$$$$$$$               $$        "<<endl;
    setColor(YELLOW);
    cout <<"                    $$$$$$              $$$$$$$$$     "<<endl;
    cout <<"                   $$$$$$                $$$$$        "<<endl;
    cout <<"                  $$$$$$               $$$$$$$        "<<endl;
    cout <<"                 $$$$$$               $$$$$$$         "<<endl;
    cout <<"                $$$$$$               $$$$$$$          "<<endl;
    cout <<"               $$$$$$               $$$$$$$           "<<endl;
    cout <<"               $$$$$                $$$$$$            "<<endl;
}

void intro_reporte()
{
    cout<<endl;
    setColor(LIGHTRED);
    cout <<"                             ########  "<<endl;
    cout <<"                            ########## "<<endl;
    cout <<"                           ##########  "<<endl;
    cout <<"                           #########   "<<endl;
    cout <<"                           ########    "<<endl;
    cout <<"                           #######     "<<endl;
    cout <<"                           ######      "<<endl;
    cout <<"                           #####       "<<endl;
    cout <<"                           ####        " <<endl;
    cout <<"                                "<<endl;
    cout <<"                           ###         "<<endl;
    cout <<"                          #####        "<<endl;
    cout <<"                           ###         "<<endl;
}

int menuPrincipal()
{
    int op;
    do
    {    intro();
         cout <<right;
        setColor(WHITE);
        cout <<endl;
        cout <<endl;
        cout <<setw(50)<<"     MENU PRINCIPAL     "<<endl;
        cout <<endl;
        cout <<setw(50)<<"[1] PLATOS              "<<endl;
        cout <<setw(50)<<"[2] CLIENTES            "<<endl;
        cout <<setw(50)<<"[3] PEDIDOS             "<<endl;
        cout <<setw(50)<<"[4] REPORTES            "<<endl;
        cout <<setw(50)<<"[5] CONFIGURACI0N       "<<endl;
        cout <<setw(50)<<" -----------------------"<<endl;
        cout <<setw(50)<<"[0] SALIR DEL PROGRAMA  "<<endl;
        cout <<endl;
        setColor(LIGHTRED);
        cout <<setw(42)<<" ingrese opcion ";
        cin >>op;
        cls();
        if (op>5)
        {
            cout <<"opcion incorrecta ";
            fflush(stdin);
            cin.get();
            cls();
        }
    }
    while (op>5);

    return op;
}

int menuPlato()
{
    int op;
    do
    {
        intro_plato();
        cout <<right;
        setColor(YELLOW);
        cout <<endl;
        cout <<endl;
        cout <<setw(50)<<"       MENU DE PLATOS      "<<endl;
        setColor(WHITE);
        cout <<endl;
        cout <<setw(50)<<"[1] NUEVO PLATO            "<<endl;
        cout <<setw(50)<<"[2] MODIFICAR PLATO        "<<endl;
        cout <<setw(50)<<"[3] LISTAR PLATO POR ID    "<<endl;
        cout <<setw(50)<<"[4] LISTAR POR RESTAURANT  "<<endl;
        cout <<setw(50)<<"[5] LISTAR TODOS LOS PLATOS"<<endl;
        cout <<setw(50)<<"[6] ELIMINAR PLATO         "<<endl;
        cout <<setw(50)<<" --------------------------"<<endl;
        cout <<setw(50)<<"[0] MENU PRINCIPAL         " <<endl;
         setColor(LIGHTRED);
        cout<<endl;
        cout <<setw(40)<<"  ingrese opcion ";
        cin >>op;
        setColor(LIGHTCYAN);
        cls();
        if (op>6)
        {
            cout <<"opcion incorrecta ";
            fflush(stdin);
            cin.get();
            cls();
        }
    }
    while (op>6);

    return op;
}

int menu_editar(int id)
{
    int op;

    do
    {   intro_plato();
        cout <<right;
        setColor(LIGHTGREEN);
        cout<<endl;
        cout <<setw(50)<<"QUE DESEA MODIFICAR DEL ID : "<<id<<endl;
        setColor(WHITE);
        cout <<setw(50)<<"                          "<<endl;
        cout <<setw(50)<<"[1]  NOMBRE               "<<endl;
        cout <<setw(50)<<"[2]  COSTO PREPARACION    "<<endl;
        cout <<setw(50)<<"[3]  VALOR VENTA          "<<endl;
        cout <<setw(50)<<"[4]  TIEMPO PREPARACION   "<<endl;
        cout <<setw(50)<<"[5]  ID RESTAURANTE       "<<endl;
        cout <<setw(50)<<"[6]  COMICION RESTAURANTE "<<endl;
        cout <<setw(50)<<"[7]  ID CATEGORIA         "<<endl;
        cout <<setw(50)<<"--------------------------"<<endl;
        cout <<setw(50)<<"[0]  VOLVER ALTERIOR      "<<endl;
        cout <<endl;
        setColor(LIGHTCYAN);
        cout <<setw(40)<<" ingrese opcion : ";
        cin>>op;
           if(op>7)
          {
              cout <<" opcion incorecta";
              fflush(stdin);
              cin.get();
              cls();
          }
    }
    while(op>7);
    cls();
    return op;
}


int menu_cliente()
{
    int op;
    do
    {
        intro_cliente();
        cout <<right;
        cout <<endl;
        setColor(LIGHTCYAN);
        cout <<endl;
        cout <<setw(60)<<"       MENU DE CLIENTE           "<<endl;
        cout <<endl;setColor(WHITE);
        cout <<setw(60)<<"[1] NUEVO CLIENTE                "<<endl;
        cout <<setw(60)<<"[2] MODIFICAR CLIENTE            "<<endl;
        cout <<setw(60)<<"[3] LISTAR CLIENTE POR ID        "<<endl;
        cout <<setw(60)<<"[4] LISTAR TODOS LOS CLIENTES    "<<endl;
        cout <<setw(60)<<"[5] DAR BAJA CLIENTE             "<<endl;
        cout <<setw(60)<<" ------------------------------- "<<endl;
        cout <<setw(60)<<"[0] VOLVER AL MENU PRINCIPAL     "<<endl;
        cout <<endl;
        setColor(LIGHTGREEN);
        cout <<setw(45)<<"    ingrese opcion ";
        cin >>op;
        setColor(LIGHTCYAN);
        cls();
        if (op>5)
        {
            cout <<"opcion incorrecta ";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    while (op>5);

    return op;

}


int menu_edita_cliente(int id)
{
    int op;
    do
    {   intro_cliente();
        cout<< endl;
        cout <<endl;
        setColor(LIGHTCYAN);
        cout <<"          QUE DESEA EDITAR DEL ID :"<<id<<endl;
        cout <<endl;
        cout <<"       [1] APELLIDO                   "<<endl;
        cout <<"       [2] NOMBRE                     "<<endl;
        cout <<"       [3] EMAIL                      "<<endl;
        cout <<"       [4] DOMICILIO                  "<<endl;
        cout <<"       [5] CP                         "<<endl;
        cout <<"       [6] FECHA DE NACIMIENTO        "<<endl;
        cout <<"       -------------------------------"<<endl;
        cout <<"       [0] VOLVER AL MENU ANTERIOR    *"<<endl;
        cout <<endl;
        setColor(MAGENTA);
        cout <<"      ingrese opcion ";
        cin >>op;
        setColor(LIGHTCYAN);
        cls();
        if (op>6)
        {
            cout <<"opcion incorrecta ";
            cin.ignore();
            cin.get();
            system("cls");
        }

    }
    while (op>6);
    return op;
}


int menu_pedidos()
{
    int op;
    do {
        intro_pedido();
        cout<<right;

        cout <<endl;
        setColor(LIGHTMAGENTA);
        cout <<setw(55)<<"      MENU DE PEDIDOS           "<<endl;
        cout <<endl;
        setColor(WHITE);
        cout <<setw(55)<<"[1] NUEVO PEDIDO                "<<endl;
        cout <<setw(55)<<"[2] MODIFICAR PEDIDO            "<<endl;
        cout <<setw(55)<<"[3] LISTAR PEDIDO POR ID        "<<endl;
        cout <<setw(55)<<"[4] LISTAR TODOS LOS PEDIDOS    "<<endl;
        cout <<setw(55)<<" -------------------------------"<<endl;
        cout <<setw(55)<<"[0] VOLVER AL MENU PRINCIPAL    "<<endl;
        cout <<endl;
        setColor(CYAN);
        cout <<setw(40)<<"ingrese opcion ";
        cin >>op;
        setColor(LIGHTCYAN);
        system("cls");
        if (op>4)
        {
            cout <<"opcion incorrecta ";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    while (op>4);

    return op;
}


int menu_edita_pedido(int id,int est)
{

    int op;
    do
    {   intro_pedido();
        cout <<right;
        cout <<endl;
        setColor(LIGHTCYAN);
        cout <<setw(40)<<" EL PEDIDO      : "<<id<<endl;
        cout <<setw(40)<<" ESTA EN ESTADO : "<<est<<endl;
        cout<< endl;
        setColor(LIGHTRED);
        cout <<setw(50)<<" A QUE ESTADO DESEA CAMBIAR     "<<endl;
        setColor(WHITE);
        cout <<endl;
        cout <<setw(50)<<"[1] PEDIDO EN CURSO             "<<endl;
        cout <<setw(50)<<"[2] PEDIDO EN CURSO COMPLETADO  "<<endl;
        cout <<setw(50)<<"[3] PEDIDO EN CURSO CANCELADO   "<<endl;
        cout <<setw(50)<<" -------------------------------"<<endl;
        cout <<setw(50)<<"[0] VOLVER                      "<<endl;
        cout <<endl;
        setColor(MAGENTA);
        cout <<setw(40)<<"ingrese opcion ";
        cin >>op;
        setColor(LIGHTCYAN);
        system("cls");
        if (op>4)
        {
            cout <<"opcion incorrecta ";
            fflush(stdin);
            cin.get();
            system("cls");
        }
    }
    while (op>4);

    return op;
}


int menu_reportes()
{  int op;
do{  intro_reporte();
    cout <<right;
    setColor(LIGHTCYAN);
    cout <<endl;
    cout <<setw(50)<<"          MENU REPORTES             "<<endl;
    cout <<endl;
    setColor(WHITE);
    cout <<setw(50)<<"[1] CLIENTES QUE NO HICIRON PEDIDOS "<<endl;
    cout <<setw(50)<<"[2] PLATOS QUE NO SE VENDIERON      "<<endl;
    cout <<setw(50)<<"[3] PEDIDOS CON VALORACION 0        "<<endl;
    cout <<setw(50)<<"------------------------------------"<<endl;
    cout <<setw(50)<<"[0] MENU PRINCIPAL                  "<<endl;
    cout <<endl;
    setColor(LIGHTGREEN);
    cout <<setw(35)<<"ingrese opcion ";
    cin >>op;
    setColor(LIGHTCYAN);
    cls();
    if (op>3)
    {
        cout <<"opcion incorrecta ";
        cin.ignore();
        cin.get();
        system("cls");
    }
}
while (op>3);

return op;
}

 int menu_config()
 {
      int op;

    do
    {
        intro_config();
        setColor(LIGHTCYAN);
        cout <<right;
        cout<<endl;
        cout <<setw(45)<<"    CONFIGURACIONES       "<<endl;
        setColor(WHITE);
        cout <<endl;
        cout <<setw(45)<<"[1]  CONFIG PLATO         "<<endl;
        cout <<setw(45)<<"[2]  CONFIG CLIENTE       "<<endl;
        cout <<setw(45)<<"[3]  CONFIG PEDIDOS       "<<endl;
        cout <<setw(45)<<"--------------------------"<<endl;
        cout <<setw(45)<<"[0]  MENU PRINCIPAL       "<<endl;
        setColor(LIGHTGREEN);
        cout <<endl;
        cout <<setw(38)<<" ingrese opcion  ";
        cin>>op;

         cls();
          if(op>3)
          {
              cout <<" opcion incorecta";
              fflush(stdin);
              cin.get();
              cls();
          }
    }
    while(op>3);
    return op;
 }


int menu_backup()
{    int op;
    do
        {
            setColor(WHITE);
            cout <<right;
            cout <<endl;
            cout <<setw(45)<<" CREAR BACKUP       [1]"<<endl;
            cout <<setw(45)<< " RESTAURAR BACKUP   [2]"<<endl;
            cout <<setw(45)<< " VOLVER             [0]"<<endl;
            cout <<endl;
            setColor(CYAN);
            cout <<setw(40)<<"ingrese opcion  ";
            cin>>op;

            cls();
            if (op>2)
            {
                cout <<" opcion incorrecta";
                fflush(stdin);
                cin.get();
                cls();
            }
        }
        while(op>2);
        return op;
}


int menu_continuar(char *cade)                //menu para asegurar que desea continuar con el procedimineto o no
{
     int op;

     do{     setColor(LIGHTRED);
             cout<<endl;
             cout <<"     ESTAS SEGURO DE "<<cade<<endl;
             cout <<endl;
             cout <<"              si [1]"<<endl;
             cout <<"              no [0]"<<endl;
             cout <<endl;
             setColor(WHITE);
             cout <<"       ingrsese opcion  ";
             cin>>op;
             cls();

        if (op<0||op>1)
        {
          cout <<"opcion incorrecta" ;
          fflush(stdin);
          cin.get();
          cls();
        }
   } while(op<0||op>1);
   return op;
}



float validacion_costo()
{
    float costo;
    do
    {   cout <<endl;
        cout <<"INGRESE COSTO DE PREPARACION :  ";
        cin>>costo;
        if (costo<0)
        {
            setColor(RED);
            cout <<"\n no se puede ingresar numeros negativos"<<endl;
            setColor(LIGHTCYAN);
            cout<<endl;
            cin.ignore();
            cin.get();

        }
    }
    while(costo<0);
    cls();
    return costo;
}


float  validacion_venta(float costo_pre)
{
    float valor_venta;
    do
    {   cout <<endl;
        cout <<setw(5)<<" COSTO VENTA : ";
        cin>>valor_venta;
        setColor(RED);
        if (valor_venta<0)
        {
            setColor(RED);
            cout <<"\n no se puede ingresar numeros negativos"<<endl;

            cout<<endl;
            cin.ignore();
            cin.get();
        }
        if (valor_venta<costo_pre)
        {
            setColor(RED);
            cout <<" \n El valor de la venta no puede ser"<<endl;
            cout <<"    menor al costo de preparacion"<<endl;
            cout<<endl;
            cin.ignore();
            cin.get();
        }
        setColor(LIGHTCYAN);
        cls();
    }
    while(valor_venta<0||valor_venta<costo_pre);

    return valor_venta;
}


float validacion_comision()
{
    int comi;
    do
    {   cout <<endl;
        cout <<" COMISION DEL RESTAURANTE :  ";
        cin>>comi;
        if (comi<0||comi>100)
        {
            setColor(RED);
            cout <<" la comision del restaurante no puede ser negativo ni mayor  100 & "<<endl;
            setColor(LIGHTCYAN);
            cin.ignore();
            cin.get();
            cls();
        }
    }
    while(comi<0||comi>100);
    return comi;

}





#endif // MENUS_H_INCLUDED
