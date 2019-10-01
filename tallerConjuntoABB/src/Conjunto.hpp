
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
        _size = 1;

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

    //Conjunto vacío
    if (esVacio()) return;

    //Busco el nodo a borrar y su padre y les apunto

    Nodo* pN = _raiz;
    Nodo* pPadre = _raiz;

    while (pN && pN->valor != clave){

        pPadre = pN;
        if (clave < pN->valor) //Rama izquierda
            pN = pN->izq;
        else
            pN = pN->der;      //Rama derecha
    }

    if (!pN) return;        //No lo encontramos, el programa termina

    _size--;    //Ajustamos el cardinal

    //Determino en qué caso de borrado estamos (0 vs 1 vs 2 hijos)

    //sin hijos
    if (pN->_esHoja()){
        delete pN;
        return;
    }

    //dos hijos. Se busca el sucesor inmediato y se usa para reemplazar el nodo a borrar
    if (pN->izq && pN->der){

        Nodo* pSucesor = pN->_sucesorInmediato();

        Nodo* nuevo = new Nodo(
                 pN->izq
                ,pSucesor->valor
                ,pN->der
                );

        if (pN->valor < pPadre->valor)
            pPadre->izq = nuevo;
        else
            pPadre->der = nuevo;

        delete pSucesor;
        delete pN;
        return;
    }

    //un hijo. Se puentea el nodo a borrar

    if (pN->izq){
        if (pN->valor < pPadre->valor)
            pPadre->izq = pN->izq;
        else
            pPadre->der = pN->izq;
    } else {
        if (pN->valor < pPadre->valor)
            pPadre->izq = pN->der;
        else
            pPadre->der = pN->der;
    }
    //y se borra
    delete pN;

    return;

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

