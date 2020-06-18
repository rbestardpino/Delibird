#pragma once

#include <stdbool.h>
#include <commons/config.h>
#include <commons/string.h>
#include <string.h>
#include <stdio.h>
#include "../Utils/protocolo.h"
#include <commons/bitarray.h>
#include "arbol.h"
#include "gameCard.h"

typedef struct {
	Posicion pos;
	uint32_t cantidad;
} DatosBloques;

typedef struct {
	uint32_t tamanioBlocks;
	uint32_t cantidadBlocks;
	char* magicNumber;
} ConfigFS;

ConfigFS configFS;

void cerrar(t_config* conf);
void abrir(t_config* conf);

char* pathMetadataBinDe(char* path, char* nombreArchivo);
char* posicionAString(DatosBloques* d);
t_list* convertirBloques(t_list* bloques, int cantBloques);
t_list* interpretarCadena(char* cadenaDatos, int cantBloques);

char* leerOpen(char* conf);
char* leerBlocksPorConfig(char* path);
char* leerArchivos(t_list* bloques, int cantBloques);
t_list* leerBlocks(int* cantBloques, t_config* conf);

int tamanioBloque(int* nroBloque);

bool sonIguales(char* a, char* b);
bool estaAbierto(char* path);
bool existeDirectorio(char* path);
short existeArchivo(char *path);

void crearBitmap(char* path);
void crearArchivo(char* path);
void crearDirectorioFiles();
void crearDirectorioBlocks();
void crearDirectorioMetadata();
void crearBloques();

NodoArbol* crearPokemon(char* nombre);
void crearMetadataPokemon(char* path);

DatosBloques* encontrarPosicion(t_list* pokemon, Posicion pos);

int agregarCantidadEnPosicion(t_list* pokemon, DatosBloques posYCant, t_list* numerosBloques);
void escribirListaEnArchivo(t_list* pokemon, t_list* numerosBloques);
void cambiarMetadataPokemon(t_config* c, t_list* numerosBloques, int bytes);
bool atraparPokemon(t_list* datosBloques, Posicion pos, t_list* numerosBloques, int* bytes);
