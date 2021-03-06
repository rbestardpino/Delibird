#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "../Utils/socket.h"
#include "../Utils/serializacion.h"
#include "archivos.h"

void SocketEscucha();
void ConexionColas(Cliente* cliente);

void Recibir_NEW_POKEMON_BROKER(Cliente* cliente, Paquete* paqueteRecibido);
void Recibir_NEW_POKEMON(Cliente* cliente, Paquete* paqueteRecibido);
void Operacion_NEW_POKEMON(DATOS_NEW_POKEMON_ID* datos);

void Recibir_CATCH_POKEMON_BROKER(Cliente* cliente, Paquete* paqueteRecibido);
void Recibir_CATCH_POKEMON(Cliente* cliente, Paquete* paqueteRecibido);
void Operacion_CATCH_POKEMON(DATOS_CATCH_POKEMON_ID* datos);

void Recibir_GET_POKEMON_BROKER(Cliente* cliente, Paquete* paqueteRecibido);
void Recibir_GET_POKEMON(Cliente* cliente, Paquete* paqueteRecibido);
void Operacion_GET_POKEMON(DATOS_GET_POKEMON_ID* datos);

void EnviarID(Cliente* cliente, uint32_t identificador);

void Enviar_APPEARED_POKEMON(DATOS_NEW_POKEMON_ID* datos);
void Enviar_CAUGHT_POKEMON(DATOS_CATCH_POKEMON_ID* datos, bool caught);
void Enviar_LOCALIZED_POKEMON(DATOS_GET_POKEMON_ID* datos,t_list* datosArchivo);

void Recibir_ID(Cliente* cliente, Paquete* paqueteRecibido);
