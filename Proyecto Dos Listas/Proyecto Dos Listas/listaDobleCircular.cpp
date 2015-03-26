#include "stdafx.h"
#include "listaDobleCircular.h"


listaDobleCircular::listaDobleCircular(void)
{
}


listaDobleCircular::~listaDobleCircular(void)
{
}

Nodo *listaDobleCircular::dirNodo(int dato){
	Nodo *aux = getCab();
	bool encontrado = false;
	if (aux != NULL){
		do {
			if (aux->getDato() == dato) {
				encontrado = true;
			}
			else {
				aux = aux->getSgte();
			}
		} while ((aux != getCab()) && (!encontrado));
	}
	return aux;
}

Nodo *listaDobleCircular::getCab(){
	return this->cab;
}

void listaDobleCircular::setCab(Nodo *aux){
	this->cab = aux;
}

int listaDobleCircular::getSize(){
	return this->size;
}

void listaDobleCircular::setSize(int n_size){
	this->size = n_size;
}

bool listaDobleCircular::vacia(){
	return (cab == NULL);
}

//* método propios de la lista  *//

bool listaDobleCircular::agregar(int dato ){
// insertar al final y no se puede insertar repetidos
	if (vacia())
	{
		Nodo *nuevo = new Nodo(dato);
		nuevo->setAnte(nuevo);
		nuevo->setSgte(nuevo);
		setCab(nuevo);
	}
	else{
		Nodo *aux = getCab();
		do {
			aux = aux->getSgte();
		} while (aux->getSgte() != getCab());
		Nodo *nuevo = new Nodo(dato);
		aux->setSgte(nuevo);
		nuevo->setAnte(aux);
		nuevo->setSgte(getCab());
		getCab()->setAnte(nuevo);
	}
	
}

bool listaDobleCircular::eliminar(int dato ){
	Nodo *aux = getCab();
	if (!vacia()){
		do {
			if (aux->getDato() == dato) {
				Nodo *tmp = aux;
				aux = aux->getSgte();
				removeNodo(tmp);
			}
			else {
				aux = aux->getSgte();
			}
		} while ((aux != getCab()) && !vacia() );
	}
	return true;
}

void listaDobleCircular::mostrarLista( ){
	Nodo *aux = getCab();
	if (aux != NULL){
		do {
			cout << "| " << aux->getDato() << " ";
			aux = aux->getSgte();
		} while (aux != getCab());
	}
}

void listaDobleCircular::removeNodo(Nodo *aux){
	aux->getAnte()->setSgte(aux->getSgte());
	aux->getSgte()->setAnte(aux->getAnte());
	delete aux;
}