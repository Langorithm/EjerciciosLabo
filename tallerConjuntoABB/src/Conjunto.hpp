
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _size(0) {
}

template <class T>
Conjunto<T>::~Conjunto() { 

}

template <class T>
bool Conjunto<T>::esVacio() const {
    return !_raiz;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {

    Nodo* p = _raiz;

    while (p){

        if (clave == p->valor) return true;

        if (clave < p->valor){
            p = p->izq;
        } else {
            p = p->der;
        }
    }

    return false;
}



template <class T>
void Conjunto<T>::insertar(const T& clave) {

    if (esVacio()){
        Nodo* nuevo = new Nodo(clave);
        _raiz = nuevo;


    } else {

        Nodo* p = _raiz;                            //Puntero para recorrer el árbol

        while (p){
            if (clave == p->valor){
                return;                             //El elemento ya estaba presente

            } else if (clave < p->valor){   //Rama Izquierda

                if (p->izq) {
                    p = p->izq;                     //Recorro el árbol por izquierda
                } else {
                    _size++;
                    Nodo* nuevo = new Nodo(clave);
                    p->izq = nuevo;                 //Creo e inserto nodo.
                    return;
                }

            } else {                        //Rama Derecha

                if (p->der) {
                    p = p->der;                     //Recorro el árbol por izquierda
                } else {
                    _size++;
                    Nodo* nuevo = new Nodo(clave);
                    p->der = nuevo;                 //Creo e inserto nodo.
                    return;
                }

            }
        }


    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {

    if (esVacio()) return;

    //Buscamos el elemento y le apuntamos
    Nodo* p = _raiz;

    while (!p || p->valor != clave){

        if (!p) return;                         //No lo encontramos, termina

        if (clave < p->valor)
            p = p->izq;
        else
            p = p->der;
    }

    _size--;

    if ( p->_esHoja() ){
        delete p;

    } else if (p->izq && p->der){
        Nodo* sig = p->_sucesorInmediato();     //Encontramos un nodo que podría reemplazar al actual manteniendo el invariante
        p->valor = sig->valor;                  //Pisamos el valor que queríamos remover
        delete sig;                             //Borramos el nodo duplicado

    } else if (p->izq){
        p->izq = p->izq->izq;            //Puenteamos al nodo de la izquierda
        p->valor = p->izq->valor;       //Pisamos el valor que queríamos remover y preservamos el siguiente
        delete p->izq;                  //Borramos el nodo de la izquierda

    } else {
        p->der = p->der->der;            //Puenteamos al nodo de la derecha
        p->valor = p->der->valor;       //Pisamos el valor que queríamos remover y preservamos el siguiente
        delete p->der;                  //Borramos el nodo de la derecha

    }

}


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(pertenece(clave) && clave != maximo());

    Nodo* p = _raiz;

    while (clave != p->valor){
        p = (clave < p->valor) ? p->izq : p->der;
    }


    Nodo* sig = p->_sucesorInmediato();

    return sig->valor;

}

template <class T>
const T& Conjunto<T>::minimo() const {
    assert(!esVacio());

    Nodo* p = _raiz;

    while (p->izq){
        p = p->izq;
    }

    return p->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(!esVacio());

    Nodo* p = _raiz;

    while (p->der){
        p = p->der;
    }

    return p->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _size;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

