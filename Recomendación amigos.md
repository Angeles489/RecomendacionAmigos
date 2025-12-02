# 🌐💬 Sistema de Recomendación de Amigos — RedSocial (C++)

Este proyecto implementa un sistema básico de recomendación de amigos utilizando un algoritmo simple de **Coincidencia de Intereses (Interests Matching)**. Forma la base del proyecto *RedSocial*, diseñado para sugerir conexiones relevantes basadas en afinidad entre perfiles.



---

## 🎯 1. Concepto y Objetivo

El módulo busca modelar una red simple capaz de sugerir nuevos amigos. El principio central es la **Similitud Basada en Intereses**, que calcula cuántos intereses tienen dos usuarios en común.

### 🧠 Principio de Funcionamiento

El algoritmo compara el conjunto de intereses del **usuario objetivo** contra los de todos los demás perfiles en la red.

1.  **🔍 Comparación:** Determina la intersección de intereses entre dos usuarios.
2.  **🧮 Cálculo de Similitud:** El puntaje es igual a la cantidad de intereses compartidos.
3.  **⭐ Ordenamiento:** Los usuarios se ordenan de mayor a menor puntaje de similitud.
4.  **📤 Sugerencia:** Se devuelven los perfiles más compatibles.

### 📊 Fórmula de Similitud

La métrica de similitud se define como la cardinalidad de la intersección de los conjuntos de intereses:

$$\text{similitud}(A,B) = |\text{intereses}(A) \cap \text{intereses}(B)|$$

---

## 🛠 2. Implementación del Sistema

El módulo está escrito en **C++** y sigue un diseño modular y orientado a objetos, priorizando la claridad y el rendimiento en redes pequeñas.

### 📌 2.1 Estructura del Código

| Archivo | Rol | Descripción |
| :--- | :--- | :--- |
| **`RedSocial.h`** | Interfaz (Header) | Define las clases `Usuario` y `RedSocial`, y sus métodos públicos. |
| **`RedSocial.cpp`** | Implementación | Contiene la lógica de inicialización, gestión de intereses y el algoritmo `calcularSimilitud`. |
| **`main.cpp`** | Ejecución/Ejemplo | Archivo principal que inicializa la red con datos de ejemplo y muestra las recomendaciones. |

### 📦 2.2 Estructuras de Datos Clave

| Componente | Tipo | Descripción |
| :--- | :--- | :--- |
| `Usuario` | Clase | Gestiona el nombre y el conjunto de intereses de cada perfil. |
| `Intereses` | `std::vector<std::string>` | Lista dinámica utilizada para almacenar los intereses del usuario. |
| `RedSocial` | Clase | Contenedor principal que almacena todos los `Usuario`s y expone la función de recomendación. |

---

## 🖥 3. Resultados y Ejemplo de Ejecución

El `main.cpp` inicializa un ejemplo de red social para demostrar el funcionamiento del algoritmo.

### 👥 3.1 Usuarios de Ejemplo

| Usuario | Intereses |
| :--- | :--- |
| **Ana** (Objetivo) | Música, Cine, Programación |
| **Pedro** | Cine, Programación |
| **Luis** | Programación, Videojuegos |
| **Marta** | Música, Lectura |

### 🔎 3.2 Análisis de Recomendación para **Ana**

| Usuario | Intereses Compartidos | Puntaje ($\text{similitud}$) |
| :--- | :--- | :--- |
| **Pedro** | Cine, Programación | **2** |
| **Luis** | Programación | **1** |
| **Marta** | Música | **1** |

### 📄 Salida de Consola Esperada

```bash
Recomendaciones para Ana:
- Pedro (2 intereses en común)
- Luis (1 intereses en común)
- Marta (1 intereses en común)
💻 4. Código FuenteA continuación, se muestra el código esencial de cada componente del sistema.📄 4.1 RedSocial.hC++#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <string>
#include <vector>
#include <algorithm>

class Usuario {
// ... (Definición de Usuario)
};

class RedSocial {
// ... (Definición de RedSocial y funciones)
};

#endif
📄 4.2 RedSocial.cppC++#include "RedSocial.h"

// Implementación de Usuario::Usuario, getNombre, getIntereses, etc.

int RedSocial::calcularSimilitud(const Usuario& u1, const Usuario& u2) const {
    int similitud = 0;
    // Lógica: Se itera sobre los intereses de u1 y se comparan contra los intereses de u2.
    // ... (Implementación)
    return similitud;
}

std::vector<std::pair<std::string, int>> RedSocial::recomendarAmigos(std::string nombreUsuario) {
    // Lógica: Busca el usuario objetivo, calcula la similitud con todos los demás, ordena los resultados.
    // ... (Implementación)
}
📄 4.3 main.cppC++#include <iostream>
#include "RedSocial.h"

int main() {
    RedSocial red;
    
    // Inicialización de datos de ejemplo
    red.agregarUsuario("Ana", {"Música", "Cine", "Programación"});
    red.agregarUsuario("Luis", {"Programación", "Videojuegos"});
    // ...
    
    // Generación y muestra de resultados
    auto recomendaciones = red.recomendarAmigos("Ana");
    // ...
    
    return 0;
}
⏱ 5. Consideraciones de RendimientoComplejidad TemporalEl cálculo de similitud entre dos usuarios es de $O(I_1 \times I_2)$ (donde $I$ es la cantidad de intereses). Al comparar esto contra $N$ usuarios en la red:$$O(N \times I^2)$$Aplicabilidad: Este método es eficiente para redes pequeñas y usuarios con pocos intereses.Escalabilidad: Para redes de gran escala, se recomienda migrar el almacenamiento de intereses a estructuras con complejidad de búsqueda $O(1)$ como hash sets (std::unordered_set) para optimizar la función calcularSimilitud.

🏁 6. Conclusión



El sistema permite:



✔ Registrar usuarios con intereses

✔ Calcular similitud entre perfiles

✔ Generar recomendaciones ordenadas

✔ Escalar y extender fácilmente



Es una base excelente para construir un sistema de recomendación social.