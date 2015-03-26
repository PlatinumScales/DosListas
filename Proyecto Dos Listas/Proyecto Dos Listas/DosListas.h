#pragma once
#include "listaDobleCircular.h"

class DosListas
{
private:
	listaDobleCircular *listaA;
	listaDobleCircular *listaB;

public:
	DosListas(void);
	~DosListas(void);

	listaDobleCircular *getListaA();
	void setListaA(listaDobleCircular *);

	listaDobleCircular *getListaB();
	void setListaB(listaDobleCircular *);


	/*** operaciones entre las dos listas ***/

	listaDobleCircular *unionL();
	listaDobleCircular *interseccion();
	listaDobleCircular *diferenciaSimetrica();
	listaDobleCircular *diferencia (listaDobleCircular *, listaDobleCircular *);
	bool iguales();
	bool inversaIguales();
	bool subConjunto(listaDobleCircular *, listaDobleCircular *);


};

