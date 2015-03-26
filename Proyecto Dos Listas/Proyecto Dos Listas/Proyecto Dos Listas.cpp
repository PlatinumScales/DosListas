// Proyecto Dos Listas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DosListas.h"


void menu(DosListas *DL){

	int x;
	int opc = 0;
	listaDobleCircular *tmp = new listaDobleCircular();
	do {
		system("cls");
		cout << " OPERACIONES CON DOS LISTAS   " << endl;
		cout << "( 1 ) Agregar elemento a la lista A" << endl;
		cout << "( 2 ) Agregar elemento a la lista B" << endl;
		cout << "( 3 ) Eliminar un elemento de la lista A" << endl;
		cout << "( 4 ) Eliminar un elemento de la lista B" << endl;
		cout << "( 5 ) Mostrar la lista A" << endl;
		cout << "( 6 ) Mostrar la lista B" << endl;
		cout << "( 7 ) Mostrar la union de las listas" << endl;
		cout << "( 8 ) Mostrar la Interseccion de las listas" << endl;
		cout << "( 9 ) Mostrar la Diferencia simétrica de las listas" << endl;
		cout << "( 0 ) Salir" << endl;
		cout << "Opción seleccionada ? " << endl;
		cin >> opc;


		switch (opc){
		case 1:
			cout << "Elemento a agregar ??";
			cin >> x;
			if (DL->getListaA()->agregar(x))
				cout << "Se agrego exitosamente" << endl;
			else
				cout << "El dato ya habia sido ingresado" << endl;
			break;
		case 2:
			cout << "Elemento a agregar ??";
			cin >> x;
			if (DL->getListaB()->agregar(x))
				cout << "Se agrego exitosamente" << endl;
			else
				cout << "El dato ya habia sido ingresado" << endl;
			break;
		case 3:
			cout << "Elemento a eliminar ??";
			cin >> x;
			if (DL->getListaA()->eliminar(x))
				cout << "Se eliminó exitosamente" << endl;
			else
				cout << "El dato no fue eliminado" << endl;
			break;
		case 4:
			cout << "Elemento a eliminar ??";
			cin >> x;
			if (DL->getListaB()->eliminar(x))
				cout << "Se eliminó exitosamente" << endl;
			else
				cout << "El dato no fue eliminado" << endl;
			break;
		case 5:
			DL->getListaA()->mostrarLista();
			break;
		case 6:
			DL->getListaB()->mostrarLista();
			break;
		case 7:
			tmp  = DL->unionL();
			tmp->mostrarLista();
			break;
		case 8:
			tmp = DL->interseccion();
			tmp->mostrarLista();
			break;
		case 9:
			tmp = DL->diferenciaSimetrica();
			tmp->mostrarLista();
			break;
		case 0:cout << "Fin del programa..." << endl;
			break;
		default: cout << "Opcion no valida..." << endl;

		}// fin del switch
		system("pause");

	} while (opc != 0);


}


int _tmain(int argc, _TCHAR* argv[])
{
	DosListas *DL = new DosListas();
	menu(DL);
	return 0;
}

