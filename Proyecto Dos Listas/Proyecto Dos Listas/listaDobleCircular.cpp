#include "stdafx.h"
#include "listaDobleCircular.h"


listaDobleCircular::listaDobleCircular(void)
{
	size = 0;
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
	return (encontrado)? aux: NULL;
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

bool listaDobleCircular::agregar(int dato){
	// insertar al final y no se puede insertar repetidos
	bool ok = true;
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
			if (aux->getDato() == dato){
				ok = false;
			}
			aux = aux->getSgte();
		} while (aux != getCab() && ok);
		if (ok){
			Nodo *nuevo = new Nodo(dato);
			nuevo->setAnte(getCab()->getAnte());
			nuevo->setSgte(getCab());
			getCab()->getAnte()->setSgte(nuevo);
			getCab()->setAnte(nuevo);
		}
	}
	size++;
	return ok;
}

bool listaDobleCircular::eliminar(int dato){
	Nodo *aux = getCab();
	bool removido = false;
	if (!vacia()){
		do {
			if (aux->getDato() == dato) {
				Nodo *tmp = aux;
				aux = aux->getSgte();
				removeNodo(tmp);
				removido = true;
			}
			else {
				aux = aux->getSgte();
			}
		} while ((aux != getCab()) && !vacia());
	}

	return removido;
}

void listaDobleCircular::mostrarLista(){
	Nodo *aux = getCab();
	if (aux != NULL){
		do {
			cout << "| " << aux->getDato() << " ";
			aux = aux->getSgte();
		} while (aux != getCab());
		cout << "| " << endl;
	}
	else{
		cout << "|Lista Vacia| " << endl;
	}
}

void listaDobleCircular::removeNodo(Nodo *aux){
	if (getSize() == 1){
		delete aux;
		this->setCab(NULL);
	}
	else{
		if (aux == getCab()){
			setCab(aux->getSgte());
		}
		aux->getAnte()->setSgte(aux->getSgte());
		aux->getSgte()->setAnte(aux->getAnte());
		delete aux;
	}
	size--;
}

listaDobleCircular * listaDobleCircular::clone()
{
	listaDobleCircular *tmp = new listaDobleCircular();
	Nodo *aux = getCab();
	Nodo *it = NULL;
	if (aux != NULL){
		do {
			Nodo *nuevo = aux->clone();
			if (tmp->vacia())
			{
				nuevo->setAnte(nuevo);
				nuevo->setSgte(nuevo);
				tmp->setCab(nuevo);
			}
			else{
				it->setSgte(nuevo);
				nuevo->setAnte(it);
				tmp->getCab()->setAnte(nuevo);
				nuevo->setSgte(tmp->getCab());
			}
			it = nuevo;
			aux = aux->getSgte();
		} while (aux != getCab());
	}
	tmp->setSize(getSize());
	return tmp;
}

