#pragma once
#include <string.h>
#include<iostream>
using namespace std;
template<class T>
class Nodo
{
private:
	T elem;
	Nodo<T>* izq;
	Nodo<T>* der;
	int cont;
public:
	Nodo(T& elem);
	T getElem();
	Nodo<T>*& getIzq();
	Nodo<T>*& getDer();
	int getCont();
	void setElem(T& e);
	void setIzq(Nodo<T>* Iz);
	void setDer(Nodo<T>* d);
	void imcrementarContador();

};

template<class T>
inline Nodo<T>::Nodo(T& elem)
{
	this->elem = elem;
	izq = NULL;
	der = NULL;
}

template<class T>
inline T Nodo<T>::getElem()
{
	return elem;
}

template<class T>
inline Nodo<T>*& Nodo<T>::getIzq()
{
	return izq;
}

template<class T>
inline Nodo<T>*& Nodo<T>::getDer()
{
	return der;
}

template<class T>
inline int Nodo<T>::getCont()
{
	return cont;
}

template<class T>
inline void Nodo<T>::setElem(T& e)
{
	elem = e;
}

template<class T>
inline void Nodo<T>::setIzq(Nodo<T>* Iz)
{
	izq = Iz;
}

template<class T>
inline void Nodo<T>::setDer(Nodo<T>* d)
{
	der = d;
}

template<class T>
inline void Nodo<T>::imcrementarContador()
{
	cont++;
}
