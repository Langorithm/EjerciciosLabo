#include "Lista.h"


//Test
template <typename T>
Lista<T>::Lista() {
    _prim = nullptr;
    _ulti = nullptr;
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {

    while (_prim){
        eliminar(0);
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {


    for (int i = longitud(); i > aCopiar.longitud(); i--) {             //Borrar el excedente de la primera lista
        eliminar(i-1);                            //Si no tiene no entra al FOR
    }

    for (int i = 0; i < longitud(); ++i) {
        iesimo(i) = aCopiar.iesimo(i);         //Copiar hasta terminar la longitud de la primera lista
    }

    for (int j = longitud(); j < aCopiar.longitud(); ++j) {
        agregarAtras(aCopiar.iesimo(j));               //Agregar el resto
    }

}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {

    Nodo* nuevo = new Nodo(elem);

    if (_prim){              //Lista no vacia
        nuevo->_sig = _prim;
        _prim->_ant = nuevo;
        _prim = nuevo;
    } else {                //Lista vacia
        _prim = nuevo;
        _ulti = nuevo;
    }

}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {

    Nodo* nuevo = new Nodo(elem);

    if (_prim){              //Lista no vacia
        nuevo->_ant = _ulti;
        _ulti->_sig = nuevo;
        _ulti = nuevo;
    } else {                //Lista vacia
        _prim = nuevo;
        _ulti = nuevo;
    }

}

template <typename T>
void Lista<T>::eliminar(Nat i) {

    Nodo* p = _prim;

    for (int j = 0; j < i; ++j) {           //Recorrer la lista
        p = p->_sig;
    }

    if (longitud() == 1){
        _prim = nullptr;
        _ulti = nullptr;
    } else {

        if (p == _prim) {
            p->_sig->_ant = nullptr;          //No elimina el anterior a P
            _prim = p->_sig;                  //porque no existe
        } else {
            p->_ant->_sig = p->_sig;
        }

        if (p == _ulti) {                    //Simetrico al de arriba
            p->_ant->_sig = nullptr;
            _ulti = p->_ant;
        } else {
            p->_sig->_ant = p->_ant;
        }

    }
    delete p;
}

template <typename T>
int Lista<T>::longitud() const {

    int contador = 0;
    Nodo* p = _prim;

    while (p){
        contador++;
        p = p->_sig;
    }

    return contador;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    assert(i<longitud());

    Nodo* p = _prim;

    for (int j = 0; j < i; ++j) {
        p = p->_sig;
    }
    return p->_valor;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar
    assert(i<longitud());

    Nodo* p = _prim;

    for (int j = 0; j < i; ++j) {
        p = p->_sig;
    }

    return p->_valor;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}