// Labo_ArbolBusqueda_Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"ArbolBBinario.h"
#include <iostream>
using namespace std;


void menu() {
    cout << "---------------MENU---------------" << endl;
    cout << "1) Insertar elemento" << endl;
    cout << "2) Contar Nodos" << endl;
    cout << "3) Calcular altura" << endl;
    cout << "4) Encontrar el menor" << endl;
    cout << "5) Encontrar el mayor" << endl;
    cout << "6) Recorrer In Order" << endl;
    cout << "7) Recorrer Pre Order" << endl;
    cout << "8) Recorrer Post Order" << endl;
    cout << "9) mostrar por Niveles" << endl;
    cout << "10) insertar contando de Archivo" << endl;
    cout << "11) mostrar contando" << endl;
    cout << "12) Terminar" << endl;
    cout << "----------------------------------" << endl;
}

int main() {
    ArbolBBinario<string> arbol;
    ArbolBBinario<string> arbolInvertido;
    int opcion;

    while (true) {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string elemento;
            cout << "Ingrese el elemento a insertar: ";
            cin >> elemento;
            arbol.insertar(elemento);
            break;
        }
        case 2: {
            int numNodos = arbol.contarNodos();
            cout << "Numero de nodos en el arbol: " << numNodos << endl;
            break;
        }
        case 3: {
            int alturaArbol = arbol.altura();
            cout << "Altura del arbol: " << alturaArbol << endl;
            break;
        }
        case 4: {
            string menorValor = arbol.menor();
            cout << "Menor valor en el arbol: " << menorValor << endl;
            break;
        }
        case 5: {
            string mayorValor = arbol.mayor();
            cout << "Mayor valor en el arbol: " << mayorValor << endl;
            break;
        }
        case 6: {
            cout << "Recorrido In Order: ";
            arbol.inorder();
            cout << endl;
            break;
        }
        case 7: {
            cout << "Recorrido Pre Order: ";
            arbol.preorder();
            cout << endl;
            break;
        }
        case 8: {
            cout << "Recorrido Post Order: ";
            arbol.postorder();
            cout << endl;
            break;
        }
        case 9: {
            cout << " Mostrar por Niveles: " << endl;
            arbol.mostrarPorNiveles();
            cout << endl;
            break;
        }
        case 10: {
            cout << " insertar contando de Archivo: " << endl;
            //arbol.llenar_Hash_desde_Archivo("cien_anios_de_soledad.txt");
            arbol.leerArchivo();
            cout << endl;
            cout << "ya se insertoo";
            break;
        }
        case 11: {
            cout << " mostrar contando: " << endl;
            arbol.mostrarPorNiveles_contando();
            cout << endl;
            break;
        }
              
              /*
        case 10: {
            ArbolBBinario<int> arbolInvertido;
            cout << " Mostrar INVERTIDO: " << endl;
            Nodo<int>* Invertido = arbol.encontrarE();
            cout << endl;
            arbol.mostrarPorNiveles(Invertido);
            cout << endl;
            break;
        }*/
        case 12: {
            cout << "Saliendo del programa." << endl;
            return 0;
        }
        default: {
            cout << "Opcio no valida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
        }
    }

    return 0;

}
