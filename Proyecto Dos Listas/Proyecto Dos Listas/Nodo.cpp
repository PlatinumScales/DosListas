#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo(void)
{
}


Nodo::~Nodo(void)
{
}


Nodo::Nodo( int _dato ){
	this->dato = _dato;
}

int Nodo::getDato(){
	return this->dato;
}
void Nodo::setDato(int _dato){
	this->dato = _dato;
}

Nodo *Nodo::getSgte(){
	return this->sgte;
}
void Nodo::setSgte(Nodo *aux){
	this->sgte = aux;
}

Nodo *Nodo::getAnte(){
	return this->ante;
}
void Nodo::setAnte(Nodo *aux){
	this->ante = aux;
}