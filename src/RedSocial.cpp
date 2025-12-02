#include "C:\Programacion\RecomendacionAmigos\include\RedSocial.h"

namespace RedSocial {

// ==========================================================
// IMPLEMENTACIÓN DE MÉTODOS DE USUARIO
// ==========================================================

Usuario::Usuario(const string& n) : nombre(n) {}

void Usuario::agregarInteres(const string& interes) {
    intereses.insert(interes);
}

void Usuario::agregarAmigo(Usuario* amigo) {
    if (amigo != this) {
        for (Usuario* a : amigos) {
            if (a == amigo) return;
        }
        amigos.push_back(amigo);
    }
}

// ==========================================================
// FUNCIONES DEL ALGORITMO
// ==========================================================

int calcularSimilitud(const Usuario* u1, const Usuario* u2) {
    int similitud = 0;
    for (const string& interes : u1->intereses) {
        if (u2->intereses.count(interes)) {
            similitud++;
        }
    }
    return similitud;
}

void recomendar(Usuario* usuario_base, int umbral_similitud) {
    using std::cout;
    using std::endl;

    cout << "\n🌟 **Recomendaciones para " << usuario_base->nombre << "** 🌟" << endl;
    cout << "--------------------------------------" << endl;

    map<string, int> recomendaciones_conteo;

    vector<Usuario*> amigos_cercanos;
    cout << "👥 Amigos cercanos (Similitud >= " << umbral_similitud << "):" << endl;

    for (Usuario* amigo : usuario_base->amigos) {
        int sim = calcularSimilitud(usuario_base, amigo);

        if (sim >= umbral_similitud) {
            amigos_cercanos.push_back(amigo);
            cout << "  - " << amigo->nombre 
                 << " (Similitud: " << sim << " intereses compartidos)" << endl;

            for (const string& interes : amigo->intereses) {
                if (usuario_base->intereses.find(interes) == usuario_base->intereses.end()) {
                    recomendaciones_conteo[interes]++;
                }
            }
        }
    }

    if (amigos_cercanos.empty()) {
        cout << "  (No se encontraron amigos con similitud suficiente.)" << endl;
    }

    vector<pair<int, string>> recomendaciones_ordenadas;
    for (const auto& par : recomendaciones_conteo) {
        recomendaciones_ordenadas.push_back({par.second, par.first});
    }

    sort(recomendaciones_ordenadas.rbegin(), recomendaciones_ordenadas.rend());

    cout << "\n💡 Intereses recomendados:" << endl;
    if (recomendaciones_ordenadas.empty()) {
        cout << "  (No hay intereses nuevos para recomendar.)" << endl;
    } else {
        int count = 0;
        for (const auto& par : recomendaciones_ordenadas) {
            if (count >= 5) break;
            cout << "  - **" << par.second 
                 << "** (Visto en " << par.first << " amigos cercanos)" << endl;
            count++;
        }
    }
}

} // namespace RedSocial
