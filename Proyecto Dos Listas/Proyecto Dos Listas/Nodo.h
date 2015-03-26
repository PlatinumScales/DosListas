#pragma once
class Nodo
{
private:
	int dato;
	Nodo *sgte;
	Nodo *ante;

public:
	Nodo(void);
	~Nodo(void);

	Nodo( int );

	int getDato();
	void setDato(int);

	Nodo *getSgte();
	void setSgte(Nodo *);

	Nodo *getAnte();
	void setAnte(Nodo *);
	Nodo * clone();
};

