🌐 Módulo: Sistema de Recomendación de Amigos (RedSocial)
🧠 Algoritmo de similitud basado en intereses
🎯 1. Objetivo del Módulo

El propósito de este módulo es implementar un sistema de recomendación de amigos que analice los intereses de los usuarios dentro de una red social y determine qué tan compatibles son.

✔ Identifica similitudes
✔ Ordena usuarios por afinidad
✔ Recomienda nuevas conexiones

Este módulo forma parte del proyecto RedSocial, enfocado en modelar un sistema básico pero funcional de sugerencias sociales.

🤝 2. Concepto: Recomendación Basada en Similitud

El sistema utiliza el método Interests Matching, comparando intereses comunes entre usuarios.

🔎 Principio de Funcionamiento

🧍 Cada usuario tiene una lista de intereses
🔄 Se comparan los intereses del usuario objetivo con los demás
📊 Se calcula un puntaje de similitud
⭐ Se recomiendan los usuarios con mayor afinidad

📐 Fórmula de similitud
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

Entre más elementos compartan, mayor afinidad existe.

🏗️ 3. Implementación del Sistema
⚙️ 3.1 Lenguaje y Organización

📌 Lenguaje: C++
📌 Archivos utilizados:

📁 RedSocial.h  
📁 RedSocial.cpp  
📁 main.cpp  


El código está diseñado para ser claro, modular y fácil de extender.

🧩 3.2 Estructuras de Datos Clave
🧱 Componente	🔠 Tipo	📝 Descripción
Usuario	Clase	Representa un usuario con nombre e intereses
Intereses	vector<string>	Lista dinámica de intereses
RedSocial	Clase	Contiene usuarios y el sistema de recomendación
Similitud	Entero	Número de intereses en común
🧮 3.3 Algoritmo de Recomendación

🎯 Seleccionar usuario objetivo

🔍 Comparar sus intereses con los demás

➕ Calcular similitud

📊 Ordenar por mayor afinidad

🤝 Devolver usuarios recomendados

📊 4. Resultados y Ejemplo
👥 4.1 Usuarios del ejemplo
Usuario	Intereses
Ana	Música, Cine, Programación
Luis	Programación, Videojuegos
Marta	Música, Lectura
Pedro	Cine, Programación
⭐ Recomendación para Ana
Usuario	Intereses compartidos	Puntaje
Pedro	Cine, Programación	2
Luis	Programación	1
Marta	Música	1
💻 Salida esperada
Recomendaciones para Ana:
1. Pedro (2 intereses en común)
2. Luis (1 interés en común)
3. Marta (1 interés en común)

🧾 5. Código del Sistema
📂 5.1 RedSocial.h
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

📂 5.2 RedSocial.cpp
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

📂 5.3 main.cpp
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

⚡ 6. Complejidad Temporal
Operación	Complejidad
Comparar dos usuarios	
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
Comparar con N usuarios	
𝑂
(
𝑁
×
𝐼
2
)
O(N×I
2
)

✔ Eficiente para redes pequeñas
✔ Fácil de mejorar con estructuras hash

🏁 7. Conclusión

Este sistema permite:

✨ Registrar usuarios
✨ Calcular similitud
✨ Ordenar recomendaciones
✨ Extender el modelo fácilmente

Es un enfoque práctico, escalable y excelente como primer sistema de recomendación.