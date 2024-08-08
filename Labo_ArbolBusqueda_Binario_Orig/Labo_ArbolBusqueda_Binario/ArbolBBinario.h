#pragma once
#include"Nodo.h"
#include<iostream>
#include<fstream>
#define TAM 1000
using namespace std;
template<class T>
class ArbolBBinario
{
private:
	Nodo<T>* raiz;
public:
	ArbolBBinario();
	~ArbolBBinario();
	void insertar(T elem);
	void insertar(T elem, Nodo<T> *& raiz);
	void insertar_contando(T elem);
	void insertar_contando(T elem, Nodo<T>*& raiz);
	int contarNodos();
	int contarNodos(Nodo<T>*& raiz);
	int altura();
	int altura(Nodo<T>*& raiz);
	void preorder();
	void inorder();
	void postorder();
	void inorder(Nodo<T>*& raiz);
	void preorder(Nodo<T>*& raiz);
	void postorder(Nodo<T>*& raiz);
	int contarHojas();
	int contarHojas(Nodo<T>*& raiz);
	void mostrarPorNiveles();
	void mostrarPorNiveles(Nodo<T>*& raiz);
	void mostrarPorNiveles_contando();
	void mostrarPorNiveles_contando(Nodo<T>*& raiz);
	void imprimirNivel(int nivelActual, Nodo<T>*& nodo);
	void imprimirNivel_contando(int nivelActual, Nodo<T>*& nodo);
	//bool buscar(T datoBus);
	Nodo<T>* buscarr(T datoBus);

	Nodo<T>* buscar(T elemBus, Nodo<T>*& raiz);
	T menor();
	T mayor();
	void menor(Nodo<T>*& raiz, T& menorEl, bool& siMenor);
	void mayor(Nodo<T>*& raiz, T& mayorEl, bool& siMayor);
	Nodo<T>*& getRaiz();
	Nodo<T>*& espejo(Nodo<T>*& raiz);
	Nodo<T>*& encontrarEspejo();
	void eliminar(T datoElim, Nodo<T>*& raiz);
	void eliminar(T datoElim);
	void eliminarTodo();
	void llenar_Hash_desde_Archivo(string nombreArch);
	void llenar_Hash_desde_Archivo2(ArbolBBinario AbolBin, string nombreArch);
	void leerArchivo();
};

template<class T>
inline ArbolBBinario<T>::ArbolBBinario()
{
	void eliminarTodo();
}

template<class T>
inline ArbolBBinario<T>::~ArbolBBinario()
{

}

template<class T>
inline void ArbolBBinario<T>::insertar(T elem)
{
	insertar(elem, raiz);
}

template<class T>
inline void ArbolBBinario<T>::insertar(T elem, Nodo<T>*& raiz)
{
	if (raiz == NULL) {
		raiz = new Nodo<T>(elem);
	}
	else {
		if (elem < raiz->getElem()) {
			insertar(elem, raiz->getIzq());
		}
		if (elem > raiz->getElem()) {
			insertar(elem, raiz->getDer());
		}
	}
}

template<class T>
inline void ArbolBBinario<T>::insertar_contando(T elem)
{
	insertar_contando(elem, raiz);
}

template<class T>
inline void ArbolBBinario<T>::insertar_contando(T elem, Nodo<T>*& raiz)
{
	//T& elemento = buscarr(elem);
	Nodo<T>* nodoEnc = buscarr(elem);
	//nodoEnc->setElem(elemento);
	if (nodoEnc == NULL) {
		insertar(elem);
	}
	else {
		nodoEnc->imcrementarContador();
	}
}

template<class T>
inline int ArbolBBinario<T>::contarNodos()
{
	return contarNodos(raiz);
}

template<class T>
inline int ArbolBBinario<T>::contarNodos(Nodo<T>*& raiz)
{
	int resp = 0;
	if (raiz != NULL) {
		int resizq;
		int resder;
		resizq = contarNodos(raiz->getIzq());// vamos por izquierda
		resder = contarNodos(raiz->getDer());
		resp = resizq + resder + 1;
	}
	return resp;
}

template<class T>
inline int ArbolBBinario<T>::altura()
{
	return altura(raiz);
}

template<class T>
inline int ArbolBBinario<T>::altura(Nodo<T>*& raiz)
{
	int resp = 0;
	if (raiz != NULL) {
		int resizq;
		int resder;
		resizq = altura(raiz->getIzq());// vamos por izquierda
		resder = altura(raiz->getDer());
		resp = max(resizq, resder) + 1;
	}
	return resp;
}

template<class T>
inline void ArbolBBinario<T>::preorder()
{
	preorder(raiz);
}

template<class T>
inline void ArbolBBinario<T>::inorder()
{
	inorder(raiz);
}

template<class T>
inline void ArbolBBinario<T>::postorder()
{
	postorder(raiz);
}

template<class T>
inline void ArbolBBinario<T>::inorder(Nodo<T>*& raiz)
{
	if (raiz != NULL) {
		inorder(raiz->getIzq());
		cout << raiz->getElem() << " "<< "Contador: " << raiz->getCont()<< "----";
		inorder(raiz->getDer());
	}
}

template<class T>
inline void ArbolBBinario<T>::preorder(Nodo<T>*& raiz)
{
	if (raiz != NULL) {
		cout << raiz->getElem() << " ";
		preorder(raiz->getIzq());
		preorder(raiz->getDer());
	}

}

template<class T>
inline void ArbolBBinario<T>::postorder(Nodo<T>*& raiz)
{
	if (raiz != NULL) {
		postorder(raiz->getIzq());
		postorder(raiz->getDer());
		cout << raiz->getElem() << " ";
	}
}

template<class T>
inline int ArbolBBinario<T>::contarHojas()
{
	return contarHojas(raiz);
}

template<class T>
inline int ArbolBBinario<T>::contarHojas(Nodo<T>*& raiz)
{
	int hojas = 0;
	if (raiz != NULL) {
		if (raiz->getIzq() == NULL && raiz->getDer() == NULL) {
			hojas = 1; 
		}
		else {
			hojas = contarHojas(raiz->getIzq()) + contarHojas(raiz->getDer());
		}
	}
	return hojas;
}
/*
template<class T>
inline bool ArbolBBinario<T>::buscar(T datoBus)
{
	Nodo<T>* elemBusc = buscar(datoBus, raiz);
	return elemBusc;
}
 */


template<class T>
inline Nodo<T>* ArbolBBinario<T>::buscar(T elemBus, Nodo<T>*& raiz)
{
	Nodo<T>* nodoEnc = NULL;
	if (raiz == NULL) {
		nodoEnc = NULL;
	}
	else {
		if (elemBus == raiz->getElem()) {
			nodoEnc = raiz;
		}
		if (elemBus < raiz->getElem()) {
			nodoEnc = buscar(elemBus, raiz->getIzq());// vamos por la izquierda
		}
		if (elemBus > raiz->getElem()) {
			nodoEnc = buscar(elemBus, raiz->getDer());// vamos por derecha
		}
	}
	return nodoEnc;
}

template<class T>
inline T ArbolBBinario<T>::menor()
{
	T elMenor=0;
	bool hayMenor = false;
	menor(raiz, elMenor, hayMenor);
	return elMenor;

	// TODO: Insertar una instrucci n "return" aqu 
}

template<class T>
inline T ArbolBBinario<T>::mayor()
{
	T elMayor=0;
	bool hayMayor = false;
	mayor(raiz, elMayor, hayMayor);
	return elMayor;
}

template<class T>
inline void ArbolBBinario<T>::menor(Nodo<T>*& raiz, T& menorEl, bool& siMenor)
{
	if (raiz != NULL) {
		menor(raiz->getIzq(), menorEl, siMenor);
		if (siMenor == false) {
			menorEl = raiz->getElem();
			siMenor = true;
		}
	}
	// TODO: Insertar una instrucci n "return" aqu 
}

template<class T>
inline void ArbolBBinario<T>::mayor(Nodo<T>*& raiz, T& mayorEl, bool& siMayor)
{
	if (raiz != NULL) {
		mayor(raiz->getDer(), mayorEl, siMayor);
		if (siMayor == false) {
			mayorEl = raiz->getElem();
			siMayor = true;
		}
	}
}

template<class T>
inline Nodo<T>*& ArbolBBinario<T>::getRaiz()
{
	return raiz;
}

template<class T>
Nodo<T>*& ArbolBBinario<T>::espejo(Nodo<T>*& raiz) {
	if (raiz == NULL)
		return NULL;

	Nodo<T>* nuevoNodo = new Nodo<T>(raiz->getElem());
	nuevoNodo->setIzq(espejo(raiz->getDer()));
	nuevoNodo->setDer(espejo(raiz->getIzq()));
	return nuevoNodo;
}


template<class T>
Nodo<T>*& ArbolBBinario<T>::encontrarEspejo()
{
	Nodo<T>* Espejo = new Nodo<T>(NULL);
	Espejo = espejo(raiz);
	return Espejo;
}

template<class T>
inline void ArbolBBinario<T>::mostrarPorNiveles() {
	int nivelMaximo = altura(raiz);
	for (int nivel = 1; nivel <= nivelMaximo; nivel++) {
		imprimirNivel(nivel, raiz);
		cout << endl;
	}
}

template<class T>
inline void ArbolBBinario<T>::mostrarPorNiveles(Nodo<T>*& raiz)
{
	int nivelMaximo = altura(raiz);
	for (int nivel = 1; nivel <= nivelMaximo; nivel++) {
		imprimirNivel(nivel, raiz);
		cout << endl;
	}
}

template<class T>
inline void ArbolBBinario<T>::mostrarPorNiveles_contando()
{
	int nivelMaximo = altura(raiz);
	for (int nivel = 1; nivel <= nivelMaximo; nivel++) {
		imprimirNivel_contando(nivel, raiz);
		cout << endl;
	}
}

template<class T>
inline void ArbolBBinario<T>::mostrarPorNiveles_contando(Nodo<T>*& raiz)
{
	int nivelMaximo = altura(raiz);
	for (int nivel = 1; nivel <= nivelMaximo; nivel++) {
		imprimirNivel_contando(nivel, raiz);
		cout << endl;
	}
}

template<class T>
inline void ArbolBBinario<T>::imprimirNivel(int nivelActual, Nodo<T>*& nodo) {
	if (nodo == NULL)
		return;

	if (nivelActual == 1) {
		cout << nodo->getElem() << " ";
	}
	else if (nivelActual > 1) {
		imprimirNivel(nivelActual - 1, nodo->getIzq());
		imprimirNivel(nivelActual - 1, nodo->getDer());
	}
}


template<class T>
inline void ArbolBBinario<T>::imprimirNivel_contando(int nivelActual, Nodo<T>*& nodo) {
	if (nodo == NULL)
		return;

	if (nivelActual == 1) {
		cout << nodo->getElem() << " "<<"contador: "<<nodo->getCont()  << "--";
	}
	else if (nivelActual > 1) {
		imprimirNivel_contando(nivelActual - 1, nodo->getIzq());
		imprimirNivel_contando(nivelActual - 1, nodo->getDer());
	}
}

template<class T>
inline Nodo<T>* ArbolBBinario<T>::buscarr(T datoBus)
{
	Nodo<T>* elemBusc = buscar(datoBus, raiz);
	return elemBusc;
}


template<class T>
inline void ArbolBBinario<T>::eliminar(T datoElim, Nodo<T>*& raiz)
{
	if (raiz != NULL) {
		if (datoElim == raiz->getElem()) {
			if (raiz->getIzq() == NULL && raiz->getDer() == NULL) {
				raiz = NULL;
			}
			else if (raiz->getDer() != NULL) {// si tienes un hijo derecho
				T menorEl;
				bool hayMenor = false;
				menor(raiz->getDer(), menorEl, hayMenor);
				raiz->setElem(menorEl);
				eliminar(menorEl, raiz->getDer());
			}
			else if (raiz->getIzq() != NULL) {
				T  mayorEl;
				bool hayMayor = false;
				mayor(raiz->getIzq(), mayorEl, hayMayor);
				raiz->setElem(mayorEl);
				eliminar(mayorEl, raiz->getIzq());
			}
		}
		else if (datoElim < raiz->getElem()) {
			eliminar(datoElim, raiz->getIzq());// vamos por la izquierda
		}
		else if (datoElim > raiz->getElem()) {
			eliminar(datoElim, raiz->getDer());// vamos por derecha
		}
	}
}

template<class T>
inline void ArbolBBinario<T>::eliminar(T datoElim)
{
	eliminar(datoElim, raiz);
}

template<class T>
inline void ArbolBBinario<T>::eliminarTodo()
{

}

template<class T>
inline void ArbolBBinario<T>::llenar_Hash_desde_Archivo(string nombreArch)
{
	ifstream arch("reemplazo texto.txt");
	arch.open("reemplazo texto.txt");
	T palabra;
	int contPal;
	cout << "prueba 1  ";
	while (!arch.eof())
	{
		cout << "prueba 2  ";
		arch >> palabra;
		cout << "prueba 3  ";
		insertar_contando(palabra);
		cout << "prueba 4  ";

	}
	arch.close();

}

template<class T>
inline void ArbolBBinario<T>::llenar_Hash_desde_Archivo2(ArbolBBinario  AbolBin , string nombreArch)
{
	ifstream arch(nombreArch);
	arch.open(nombreArch);
	T palabra;
	while (arch >> palabra)
	{
		AbolBin->insertar_contando(new T(palabra));
	}
	arch.close();

}

template<class T>
void ArbolBBinario<T>::leerArchivo()
{
	string ruta = "cien_anios_de_soledad.txt";
	T palabra;
	ifstream Archivo;
	Archivo.open(ruta);
	while (!Archivo.eof())
	{
		Archivo >> palabra;
		insertar_contando(palabra);
	}
}
