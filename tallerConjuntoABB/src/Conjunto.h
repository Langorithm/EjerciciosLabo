#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();


        bool esVacio() const;
        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        //Definición de Nodo de ABB
        struct Nodo
        {
            const T valor;                // El elemento al que representa el nodo.
            Nodo* izq;              // Puntero a la raíz del subárbol izquierdo.
            Nodo* der;              // Puntero a la raíz del subárbol derecho.

                                    // El constructor, toma el elemento al que representa el nodo.

            //Constructores
            Nodo(Nodo* izq, const T &v, Nodo* der) : izq(izq), valor(v), der(der){
            };

            Nodo(const T &v) : izq(nullptr), valor(v), der(nullptr){
            };

            bool _esHoja(){
                return (!izq && !der);
            }

            //Funciones útiles
            Nodo* _sucesorInmediato(){

                assert(der);

                Nodo* p = der;

                while (p->izq){
                    p = p->izq;
                }

                return p;
            }


        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;

        // Cardinal
        unsigned int _size;


};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
