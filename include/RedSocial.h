#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

namespace RedSocial {

using namespace std;

// ==========================================================
// 1. CLASE USUARIO
// ==========================================================
class Usuario {
public:
    string nombre;
    set<string> intereses;
    vector<Usuario*> amigos;

    Usuario(const string& n);

    void agregarInteres(const string& interes);
    void agregarAmigo(Usuario* amigo);
};

// ==========================================================
// 2. FUNCIONES DEL ALGORITMO
// ==========================================================

int calcularSimilitud(const Usuario* u1, const Usuario* u2);
void recomendar(Usuario* usuario_base, int umbral_similitud = 1);

} // namespace RedSocial

#endif
