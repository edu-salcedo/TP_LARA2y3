#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED
using namespace std;
  // menues
void intro();
void intro_plato();
void intro_cliente();
void intro_pedido();
void intro_config();
void intro_reporte();
int menuPrincipal();
int menuPlato();
int menu_editar(int );
int menu_cliente();
int menu_edita_cliente(int);
int menu_pedidos();
int menu_edita_pedido(int ,int);
 int menu_reportes();
 int menu_backup();
 int menu_continuar(char *);
 int menu_config();

void lis_backplato();
void lis_backcliente();
void lis_backpedido();
// funciones de registros de platos
void opcion_plato ( );
bool cargar_plato(struct platos *);
int buscar_ID_plato(int );
void guardar_plato(struct platos);
int listar(struct platos );
void listar_todo(struct platos);
struct platos leer_platos(int);
void listar_plato_id(struct platos);
void editar_plato();
bool sobreescribir(struct platos ,int);
void platos_restaurante(struct platos );
float validacion_costo();
float  validacion_venta(float);
float validacion_comision();
void logotipo ();
void baja_plato();
void no_encontro_id();
int  validacion_negativo(char *);
int cantidad_platos();
int buscar_ID_resta(int);
void nombre_campos();

 //prototipos de cliente
 void opcion_cliente();
bool registrar_cliente(struct cliente *);
int cantidad_clientes();
void guardar_cliente(struct cliente );
void modificar_cliente();
int buscar_ID_cliente(int );
struct cliente leer_cliente(int );
void validar_campovacio(char*,char *);
void fecha_validada(struct cliente *);
void validar_mail(struct cliente *);
void listar_cliente_id();
void listar_cliente(struct cliente );
void listar_registros(struct cliente);
bool sobreescribir_registro(struct cliente ,int);
void ordenar_cliente(struct cliente *,int) ;
void baja_cliente();
void campos_cliente();

// prototipos pedidos
void opccion_pedido();
int cantidad_pedidos();
bool registrar_pedidos(struct pedidos *);
void guardar_pedido(struct pedidos);
struct fecha  fecha_actual();
int buscar_ID_pedido();
struct pedidos leer_pedidos(int );
bool cambiar_estado(struct pedidos,int );
void listar_pedido_id();
void listar_pedidos( struct pedidos );
void listar_todo_pedidos(struct pedidos );
 void editar_pedido();
 void campos_pedido();


//FUNCIONES PARA REPORTES
void opccion_reporte();
void reporte_1();
bool hizo_pedido(int);
void reporte_2();
bool plato_vendido(int);
void reporte_3();
void backup_plato();
void guardar_backup();
void opccion_config();
void config_Platos();
void config_Clientes();
void config_Pedidos();
void backup_cliente();
void backup_pedido();
void restaurar_plato();
void restaurar_pedido();
void restaurar_cliente();
#endif // PROTOTIPO_H_INCLUDED
