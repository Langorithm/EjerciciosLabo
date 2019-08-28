
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
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
                    Nodo* nuevo = new Nodo(clave);
                    p->izq = nuevo;                 //Creo e inserto nodo.
                    return;
                }

            } else {                        //Rama Derecha

                if (p->der) {
                    p = p->der;                     //Recorro el árbol por izquierda
                } else {
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
/*
    if (clave == _raiz->valor){                     //Manejo el caso de la raiz por separado

        if (_raiz->_esHoja()) _raiz = nullptr;          //Caso: Sin hijos

        if (_raiz->izq && _raiz->der){                  //Caso: Dos hijos

            if (_raiz->_sucesorInmediato()->der) _raiz->_sucesorInmediato()->der
        }
    }

    Nodo* p = _raiz;

    while (p){
        if (p->izq)
    }
*/
}


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(pertenece(clave) && clave != maximo());


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


}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

