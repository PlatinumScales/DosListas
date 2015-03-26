#pragma once
#include "Nodo.h"
class listaDobleCircular
{
private:
	Nodo *cab;
	int size;

	
public:
	listaDobleCircular(void);
	~listaDobleCircular(void);


	Nodo *getCab();
	void setCab(Nodo *);

	int getSize();
	void setSize(int);
	bool vacia();
	Nodo *dirNodo(int);

	//* método propios de la lista  *//

	bool agregar(int );
	bool eliminar(int );
	void mostrarLista();
	void removeNodo(Nodo *aux);
	listaDobleCircular * clone();
};

