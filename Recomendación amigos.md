🌐💬 Sistema de Recomendación de Amigos — RedSocial
🎯 1. Objetivo del Módulo

El propósito de este módulo es implementar un sistema de recomendación de amigos basado en similitud entre usuarios dentro de una red social.

El algoritmo analiza los intereses de cada usuario y calcula coincidencias para sugerir qué perfiles son más compatibles.

Este módulo forma parte del proyecto RedSocial, cuyo objetivo es modelar una red simple capaz de sugerir conexiones relevantes utilizando criterios de afinidad.

🤝 2. Concepto: Recomendación Basada en Similitud

El sistema implementado utiliza el enfoque Interests Matching (coincidencia de intereses).

🧠 Principio de Funcionamiento

Cada usuario posee un conjunto de intereses, por ejemplo:
"Música", "Programación", "Videojuegos".

El proceso es:

🔍 Comparar los intereses del usuario objetivo con los de todos los demás.

📊 Calcular un puntaje de similitud basado en:

Cantidad de intereses compartidos.

Intereses distintos.

⭐ Ordenar a los usuarios según compatibilidad.

🤖 Sugerir los usuarios con mayor similitud.

Es un método simple, eficiente y ideal para redes pequeñas.

🛠 3. Implementación del Sistema
📌 3.1 Lenguaje de implementación

El módulo está implementado en C++, organizado en tres archivos:

RedSocial.h

RedSocial.cpp

main.cpp

Se prioriza claridad, modularidad y escalabilidad.

📦 3.2 Estructuras de Datos Clave
Componente	Tipo	Descripción
Usuario	Clase	Gestiona nombre + intereses.
Intereses	vector<string>	Lista dinámica de intereses.
RedSocial	Clase	Contiene usuarios y funciones de recomendación.
Similitud	Entero	Representa coincidencias entre dos usuarios.
⚙️ 3.3 Algoritmo de Recomendación

El algoritmo sigue estos pasos:

🧍 Seleccionar usuario objetivo.

🔄 Comparar intereses con los demás usuarios.

🧮 Calcular similitud:

𝑠
𝑖
𝑚
𝑖
𝑙
𝑖
𝑡
𝑢
𝑑
(
𝐴
,
𝐵
)
=
∣
𝑖
𝑛
𝑡
𝑒
𝑟
𝑒
𝑠
𝑒
𝑠
(
𝐴
)
∩
𝑖
𝑛
𝑡
𝑒
𝑟
𝑒
𝑠
𝑒
𝑠
(
𝐵
)
∣
similitud(A,B)=∣intereses(A)∩intereses(B)∣

📈 Ordenar usuarios según mayor similitud.

📤 Devolver lista de sugeridos.

Este método es equivalente a un conteo de intersección, ideal para un primer sistema de recomendaciones.

📊 4. Resultados y Ejemplo
👥 4.1 Usuarios de ejemplo
Usuario	Intereses
Ana	Música, Cine, Programación
Luis	Programación, Videojuegos
Marta	Música, Lectura
Pedro	Cine, Programación
🔎 Recomendación para Ana
Usuario	Intereses compartidos	Puntaje
Pedro	Cine, Programación	2
Luis	Programación	1
Marta	Música	1
🖥 Salida esperada en consola
Recomendaciones para Ana:
1. Pedro (2 intereses en común)
2. Luis (1 interés en común)
3. Marta (1 interés en común)

💻 5. Código del Sistema
📄 5.1 RedSocial.h
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

📄 5.2 RedSocial.cpp
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

📄 5.3 main.cpp
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

⏱ 6. Complejidad Temporal

Similitud entre dos usuarios:

𝑂
(
𝐼
1
×
𝐼
2
)
O(I
1
	​

×I
2
	​

)

Comparar contra N usuarios:

𝑂
(
𝑁
×
𝐼
)
O(N×I)

Funciona eficientemente en redes pequeñas.
Para redes grandes, podrían usarse estructuras como hash sets.

🏁 7. Conclusión

El sistema permite:

✔ Registrar usuarios con intereses
✔ Calcular similitud entre perfiles
✔ Generar recomendaciones ordenadas
✔ Escalar y extender fácilmente

Es una base excelente para construir un sistema de recomendación social.