#pragma once
#include <cmath>
#include <iostream>

/// Clase que representa un vector en 3D con componentes x, y, z.
class Vector3 {
public:
    float x; ///< Componente en el eje X.
    float y; ///< Componente en el eje Y.
    float z; ///< Componente en el eje Z.

    // Constructor por defecto. Inicializa el vector en (0, 0, 0).
    Vector3() : x(0), y(0), z(0) {}

    // Destructor por defecto.
    ~Vector3() = default;

    // Constructor que inicializa un vector con los valores dados.
    // Param: x -> Valor para el componente x.
    // Param: y -> Valor para el componente y.
    // Param: z -> Valor para el componente z.
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Sobrecarga del operador + para sumar dos vectores.
    // Param: otherVector -> El vector que se va a sumar.
    // Returns: Un nuevo vector resultante de la suma.
    Vector3 operator+(const Vector3& otherVector) const {
        return Vector3(x + otherVector.x, y + otherVector.y, z + otherVector.z);
    }

    // Sobrecarga del operador - para restar dos vectores.
    // Param: otherVector -> El vector que se va a restar.
    // Returns: Un nuevo vector resultante de la resta.
    Vector3 operator-(const Vector3& otherVector) const {
        return Vector3(x - otherVector.x, y - otherVector.y, z - otherVector.z);
    }

    // Sobrecarga del operador * para multiplicar el vector por un escalar.
    // Param: escalar -> El valor escalar por el que se va a multiplicar.
    // Returns: Un nuevo vector resultante de la multiplicación.
    Vector3 operator*(float escalar) const {
        return Vector3(x * escalar, y * escalar, z * escalar);
    }

    // Calcula la magnitud (longitud) del vector.
    // Returns: La magnitud del vector.
    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Normaliza el vector, ajustando su magnitud a 1.
    // Returns: Un nuevo vector normalizado.
    Vector3 normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return Vector3(0, 0, 0);
        }
        else {
            return Vector3(x / mag, y / mag, z / mag);
        }
    }

    // Devuelve un puntero a los datos del vector.
    // Returns: Un puntero al primer elemento del vector (x).
    float* data() {
        return &x;
    }

    // Devuelve un puntero constante a los datos del vector.
    // Returns: Un puntero constante al primer elemento del vector (x).
    const float* data() const {
        return &x;
    }
};
