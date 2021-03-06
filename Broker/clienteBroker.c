#include "clienteBroker.h"
#include "memoria.h"
#include "../Utils/dictionaryInt.h"
#include <commons/config.h>
#include <stdlib.h>

t_dictionaryInt* clientes;
pthread_mutex_t mutexClientes;

uint32_t siguienteIDCliente = 0;
pthread_mutex_t mutexIDCliente;

void InicializarClienteBroker()
{
	clientes = dictionaryInt_create();
	pthread_mutex_init(&mutexClientes, NULL);
	pthread_mutex_init(&mutexIDCliente, NULL);
}

void AvanzarIDCliente(uint32_t anterior)
{
	siguienteIDCliente = anterior++;
}

void AgregarClienteBroker(ClienteBroker* cliente)
{
	pthread_mutex_lock(&mutexClientes);
	dictionaryInt_put(clientes, cliente->id, cliente);
	pthread_mutex_unlock(&mutexClientes);
}

ClienteBroker* CrearClienteBroker(Cliente* cliente)
{
	ClienteBroker* clienteBroker = malloc(sizeof(ClienteBroker));
	clienteBroker->cliente = cliente;

	pthread_mutex_lock(&mutexIDCliente);
	clienteBroker->id = siguienteIDCliente;
	siguienteIDCliente++;
	pthread_mutex_unlock(&mutexIDCliente);

	AgregarClienteBroker(clienteBroker);

	return clienteBroker;
}



ClienteBroker* ObtenerClienteBroker(uint32_t id)
{
	pthread_mutex_lock(&mutexClientes);
	ClienteBroker* clienteBroker = dictionaryInt_get(clientes, id);
	pthread_mutex_unlock(&mutexClientes);
	return clienteBroker;
}

void RemoverClienteBroker(uint32_t id)
{
	pthread_mutex_lock(&mutexClientes);
	dictionaryInt_remove(clientes, id);
	pthread_mutex_unlock(&mutexClientes);
}
