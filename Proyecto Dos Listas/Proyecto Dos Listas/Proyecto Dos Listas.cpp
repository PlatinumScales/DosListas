// Proyecto Dos Listas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DosListas.h"


void menu(DosListas *DL ){
	

	int opc = 0;

	do {
		system( "cls");
		cout << " OPERACIONES CON DOS LISTAS   "<< endl;
		cout << "( 1 ) Agregar elemento a la lista A"<< endl;
		cout << "( 2 ) Agregar elemento a la lista B"<< endl;
		cout << "( 3 ) Eliminar un elemento de la lista A"<< endl;
		cout << "( 4 ) Eliminar un elemento de la lista B"<< endl;
		cout << "( 5 ) Mostrar la lista A"<< endl;
		cout << "( 6 ) Mostrar la lista B"<< endl;
		cout << "( 0 ) Salir" << endl;
		cout << "Opción seleccionada ? "<< endl;
		cin >> opc;


		switch (opc ){
		case 1:cout << "Elemento a agregar ??";
				int x;
				cin>> x;
				if ( DL->getListaA()->agregar( x ))
					cout <<"Se agrego exitosamente"<< endl;
				else
					cout <<"El dato ya habia sido ingresado"<< endl;
				break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 0:cout << "Fin del programa..."<< endl;
			break;
		default: cout <<"Opcion no valida..."<< endl;
	
	
	
	
		}// fin del switch
		system ("pause");

	}while ( opc != 0);


}


int _tmain(int argc, _TCHAR* argv[])
{
	DosListas *DL;

	return 0;
}

