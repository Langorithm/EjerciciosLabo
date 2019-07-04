//FUNCIONES AUXILIARES
vector<int> _str2Vec(const string& s) {
    vector<int> v(s.size());

    for (int i = 0; i < s.size(); ++i) {
        v[i] = int(s[i]);
    }
    return v;
}


template <typename T>
string_map<T>::string_map(){
    _raiz = new Nodo();
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    vector<int> vClave = _str2Vec(clave);
    Nodo* p = _raiz;

    for (int i = 0; i < vClave.size(); ++i) {
        p = p->siguientes[i];
    }


}


template <typename T>
int string_map<T>::count(const string& clave) const{
    bool esta = true;
    vector<int> vClave = _str2Vec(clave);
    Nodo* p = _raiz;


    for (int i = 0; esta && i < vClave.size(); ++i) {
        if (p->siguientes[i])
            p = p->siguientes[i];
        else
            esta = false;
    }

    return int(esta);
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    assert(this->count(clave) == 1);

    vector<int> vClave = _str2Vec(clave);
    Nodo* p = _raiz;

    for (int i = 0; i < vClave.size(); ++i) {
        p = p->siguientes[i];
    }

    return **p->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    assert(this->count(clave) == 1);

    vector<int> vClave = _str2Vec(clave);
    Nodo* p = _raiz;

    for (int i = 0; i < vClave.size(); ++i) {
        p = p->siguientes[i];
    }

    return **p->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
}