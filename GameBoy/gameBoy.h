// INCLUDES Y DEFINES
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Utils/net.h"
#include "../Utils/socket.h"

typedef void* (*Serializar)(void*,int*);

//MANDAR MENSAJES
void send_MESSAGE(CodigoDeOperacion codOp, void* datos, Serializar funcion, int numSocket);

// DECLARACIONES
void ConectadoConProceso(char*);
void DesconectadoProceso(char*);
void conexionBroker(Cliente* cliente, Paquete* paquete);
void terminarPrograma(t_log* logger, t_config* config);

//VERIFICAR DATOS
void verificarConexion(int conexion, t_log* logger);
bool sonIguales(char* a, char* b);
int cantidadParametros(char* parametros[]);

//CONVERTIR MENSAJES INGRESADOS POR CONSOLA
CodigoDeCola* convertirCodigo(char* codigo);

DATOS_NEW_POKEMON* convertir_NEW_POKEMON(int cantParametros, char* parametros[]);
DATOS_NEW_POKEMON_ID* convertir_NEW_POKEMON_ID(int cantParametros, char* parametros[]);
DATOS_APPEARED_POKEMON* convertir_APPEARED_POKEMON(int cantParametros, char* parametros[]);
DATOS_APPEARED_POKEMON_ID* convertir_APPEARED_POKEMON_ID(int cantParametros, char* parametros[]);
DATOS_CATCH_POKEMON* convertir_CATCH_POKEMON(int cantParametros, char* parametros[]);
DATOS_CATCH_POKEMON_ID* convertir_CATCH_POKEMON_ID(int cantParametros, char* parametros[]);
DATOS_CAUGHT_POKEMON_ID* convertir_CAUGHT_POKEMON_ID(int cantParametros, char* parametros[]);
DATOS_GET_POKEMON* convertir_GET_POKEMON(int cantParametros, char* parametros[]);
DATOS_GET_POKEMON_ID* convertir_GET_POKEMON_ID(int cantParametros, char* parametros[]);







