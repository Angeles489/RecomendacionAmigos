Módulo: Sistema de Recomendación de Amigos (RedSocial)
1. Objetivo del Módulo

El objetivo de este módulo es implementar un sistema de recomendación de amigos basado en similitud entre usuarios.
El algoritmo analiza los intereses registrados por cada usuario dentro de la red social y calcula coincidencias para determinar qué usuarios son compatibles entre sí.

Este módulo forma parte del proyecto RedSocial, cuyo propósito es modelar una red simple capaz de sugerir conexiones relevantes utilizando criterios básicos de afinidad.

2. Concepto: Recomendación Basada en Similitud

Un sistema de recomendación de amigos se fundamenta en identificar qué tan similares son dos usuarios según sus intereses.

El enfoque utilizado en este proyecto es Coincidencia de Intereses (Interests Matching).

Principio de funcionamiento

Cada usuario posee un conjunto de intereses (ej. "Música", "Programación", "Videojuegos").

Para cada usuario, se comparan sus intereses con los de todos los demás.

Se calcula un puntaje de similitud basado en:

Cantidad de intereses en común.

Intereses únicos o distintos.

Los usuarios con mayor puntaje son sugeridos como “amigos recomendados”.

Este método es simple pero muy efectivo en redes pequeñas y en sistemas donde la información de usuarios es limitada.

3. Implementación del Sistema
3.1 Lenguaje de implementación

El módulo está implementado en C++, utilizando clases separadas en:

RedSocial.h

RedSocial.cpp

main.cpp

El código está estructurado para ser claro, modular y escalable.

3.2 Estructuras de Datos Clave
Componente	Tipo	Descripción
Usuario	Clase	Contiene nombre y lista de intereses.
Intereses	vector<string>	Lista dinámica de intereses por usuario.
RedSocial	Clase	Contiene la colección de usuarios y las funciones de recomendación.
Similitud	Entero	Representa cuántos intereses coinciden entre dos usuarios.
3.3 Algoritmo de Recomendación

El algoritmo sigue estos pasos:

Seleccionar el usuario objetivo.

Comparar sus intereses con los de cada otro usuario.

Calcular la similitud:

similitud
(𝐴,𝐵)=∣ intereses (𝐴) ∩ intereses (𝐵)∣
similitud(A,B)=∣intereses(A)∩intereses(B)∣

Ordenar a los usuarios por mayor similitud.

Devolver los usuarios con mayor puntaje.

Este método es equivalente a un conteo de intersección, ideal para un primer sistema de recomendaciones.

4. Resultados y Ejemplo
4.1 Ejemplo de Usuarios
Usuario	Intereses
Ana	Música, Cine, Programación
Luis	Programación, Videojuegos
Marta	Música, Lectura
Pedro	Cine, Programación
Recomendación para Ana
Usuario	Intereses compartidos	Puntaje
Pedro	Cine, Programación	2
Luis	Programación	1
Marta	Música	1

Salida esperada en consola:

Recomendaciones para Ana:
1. Pedro (2 intereses en común)
2. Luis (1 interés en común)
3. Marta (1 interés en común)

5. Código del Sistema
5.1 RedSocial.h
#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <string>
#include <vector>
#include <algorithm>

class Usuario {
private:
    std::string nombre;
    std::vector<std::string> intereses;

public:
    Usuario(std::string nombre, std::vector<std::string> intereses);

    std::string getNombre() const;
    std::vector<std::string> getIntereses() const;
};

class RedSocial {
private:
    std::vector<Usuario> usuarios;

    int calcularSimilitud(const Usuario& u1, const Usuario& u2) const;

public:
    void agregarUsuario(std::string nombre, std::vector<std::string> intereses);
    std::vector<std::pair<std::string, int>> recomendarAmigos(std::string nombreUsuario);
};

#endif

5.2 RedSocial.cpp
#include "RedSocial.h"

Usuario::Usuario(std::string nombre, std::vector<std::string> intereses)
    : nombre(nombre), intereses(intereses) {}

std::string Usuario::getNombre() const {
    return nombre;
}

std::vector<std::string> Usuario::getIntereses() const {
    return intereses;
}

void RedSocial::agregarUsuario(std::string nombre, std::vector<std::string> intereses) {
    usuarios.emplace_back(nombre, intereses);
}

int RedSocial::calcularSimilitud(const Usuario& u1, const Usuario& u2) const {
    int similitud = 0;

    for (const auto& interes1 : u1.getIntereses()) {
        for (const auto& interes2 : u2.getIntereses()) {
            if (interes1 == interes2) {
                similitud++;
            }
        }
    }

    return similitud;
}

std::vector<std::pair<std::string, int>> RedSocial::recomendarAmigos(std::string nombreUsuario) {
    Usuario* objetivo = nullptr;
    for (auto& u : usuarios) {
        if (u.getNombre() == nombreUsuario) {
            objetivo = &u;
            break;
        }
    }

    if (!objetivo) return {};

    std::vector<std::pair<std::string, int>> recomendaciones;

    for (auto& otro : usuarios) {
        if (otro.getNombre() != nombreUsuario) {
            int score = calcularSimilitud(*objetivo, otro);
            recomendaciones.push_back({otro.getNombre(), score});
        }
    }

    std::sort(recomendaciones.begin(), recomendaciones.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    return recomendaciones;
}

5.3 main.cpp
#include <iostream>
#include "RedSocial.h"

int main() {
    RedSocial red;

    red.agregarUsuario("Ana", {"Música", "Cine", "Programación"});
    red.agregarUsuario("Luis", {"Programación", "Videojuegos"});
    red.agregarUsuario("Marta", {"Música", "Lectura"});
    red.agregarUsuario("Pedro", {"Cine", "Programación"});

    auto recomendaciones = red.recomendarAmigos("Ana");

    std::cout << "Recomendaciones para Ana:\n";
    for (auto& r : recomendaciones) {
        std::cout << "- " << r.first << " (" << r.second << " intereses en común)\n";
    }

    return 0;
}

6. Complejidad Temporal

Calcular similitud entre dos usuarios:

𝑂(𝐼1×𝐼2)

Comparar el usuario objetivo con N usuarios:

𝑂(𝑁×𝐼2)

Para redes pequeñas, este método funciona perfectamente y mantiene buena eficiencia.
En redes grandes, se podrían considerar estructuras optimizadas como hash sets.

7. Conclusión

El sistema implementado permite:

Registrar usuarios con intereses.

Calcular similitud entre perfiles.

Generar recomendaciones ordenadas.

Extender fácilmente el modelo (pesos, categorías, redes grandes).

Este módulo demuestra un enfoque práctico y claro para construir un primer sistema de recomendación dentro de una red social.
