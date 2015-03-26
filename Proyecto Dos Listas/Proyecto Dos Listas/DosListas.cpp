#include "stdafx.h"
#include "DosListas.h"


DosListas::DosListas(void)
{
	setListaA(new listaDobleCircular());
	setListaB(new listaDobleCircular());
}


DosListas::~DosListas(void)
{
}


listaDobleCircular *DosListas::getListaA(){
	return this->listaA;

}
void DosListas::setListaA(listaDobleCircular *_lista){
	this->listaA = _lista;

}

listaDobleCircular *DosListas::getListaB(){
	return this->listaB;
}
void DosListas::setListaB(listaDobleCircular *_lista){
	this->listaB = _lista;
}

/*** operaciones entre las dos listas ***/

listaDobleCircular *DosListas::unionL(){
	// Devuelve una lista que es igual a la unión de las dos listas 
	// El algoritmo debe hacerse en un sólo recorrido. 
	listaDobleCircular *c = new listaDobleCircular();
	if (listaA->vacia()){
		c = listaB->clone();
	}else if (listaB->vacia()){
		c = listaA->clone();
	}
	else {
		c = listaB->clone();
		Nodo * aux = listaA->getCab();
		do {
			if (listaB->dirNodo(aux->getDato()) == NULL){
				Nodo * tmp = aux->clone();
				tmp->setAnte(c->getCab());
				tmp->setSgte(c->getCab()->getSgte());
				c->getCab()->getSgte()->setAnte(tmp);
				c->getCab()->setSgte(tmp);
			}
			aux = aux->getSgte();
		} while (aux != listaA->getCab());
	}
	return c;
}

listaDobleCircular *DosListas::interseccion(){
	// Genera una lista igual a la intersección de las dos listas, ie,
	// los elementos comunes entre LA y LB
	listaDobleCircular *c = new listaDobleCircular();
	if ( !listaA->vacia() && !listaB->vacia()){
		Nodo * aux = listaA->getCab();
		do {
			if (listaB->dirNodo(aux->getDato()) != NULL){
				Nodo * tmp = aux->clone();
				if (c->vacia()){
					tmp->setAnte(tmp);
					tmp->setSgte(tmp);
					c->setCab(tmp);
				}
				else{
					tmp->setAnte(c->getCab());
					tmp->setSgte(c->getCab()->getSgte());
					c->getCab()->getSgte()->setAnte(tmp);
					c->getCab()->setSgte(tmp);
				}
			}
			aux = aux->getSgte();
		} while (aux != listaA->getCab());
	}
	return c;

}

listaDobleCircular *DosListas::diferenciaSimetrica(){
	// Genera una lista igual a la diferencia simetrica entre LA y LB,
	// diferencia simetrica= los elementos que solo aparecen una vez en cada conjunto
	listaDobleCircular *c = new listaDobleCircular();
	if (listaA->vacia()){
		c = listaB->clone();
	}
	else if (listaB->vacia()){
		c = listaA->clone();
	}
	else {
		Nodo * aux = listaA->getCab();
		do {
			if (listaB->dirNodo(aux->getDato()) == NULL){
				Nodo * tmp = aux->clone();
				if (c->vacia()){
					tmp->setAnte(tmp);
					tmp->setSgte(tmp);
					c->setCab(tmp);
				}
				else{
					tmp->setAnte(c->getCab());
					tmp->setSgte(c->getCab()->getSgte());
					c->getCab()->getSgte()->setAnte(tmp);
					c->getCab()->setSgte(tmp);
				}
			}
			aux = aux->getSgte();
		} while (aux != listaA->getCab());

		aux = listaB->getCab();
		do {
			if (listaA->dirNodo(aux->getDato()) == NULL){
				Nodo * tmp = aux->clone();
				if (c->vacia()){
					tmp->setAnte(tmp);
					tmp->setSgte(tmp);
					c->setCab(tmp);
				}
				else{
					tmp->setAnte(c->getCab());
					tmp->setSgte(c->getCab()->getSgte());
					c->getCab()->getSgte()->setAnte(tmp);
					c->getCab()->setSgte(tmp);
				}
			}
			aux = aux->getSgte();
		} while (aux != listaB->getCab());
	}
	return c;
}

listaDobleCircular *DosListas::diferencia(listaDobleCircular *A, listaDobleCircular *B){
	// Genera una lista igual a A - B
	return NULL;
}

bool DosListas::iguales(){
	// Devuelve true si las dos listas son exactamente iguales en tamaño y contenido
	return true;
}

bool DosListas::inversaIguales(){
	// Devuelve true si la lista lA es inversa igual a lB
	return true;
}

bool DosListas::subConjunto(listaDobleCircular *A, listaDobleCircular *B){
	// Devolver true si todos los elementos de A están en B.
	// Recuerden toda lista vacia es subconjunto de cuaquier conjunto.

	if (A->getSize() > B->getSize())
		return false;
	else
		if (A->vacia())
			return true;
		else {
			Nodo * aux = A->getCab();
			bool sc = true;// centinela o bandera

			do {

				if (B->dirNodo(aux->getDato()) == NULL)
					sc = false;
				else
					aux = aux->getSgte();

			} while (aux != A->getCab() && sc);

			return sc;
		}
}