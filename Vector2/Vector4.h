#pragma once
#include <cmath>
#include <iostream>

/// Clase que representa un vector en 4D con componentes x, y, z, w.
class Vector4 {
public:
    float x; ///< Componente en el eje X.
    float y; ///< Componente en el eje Y.
    float z; ///< Componente en el eje Z.
    float w; ///< Componente en el eje W.

    // Constructor por defecto. Inicializa el vector en (0, 0, 0, 0).
    Vector4() : x(0), y(0), z(0), w(0) {}

    // Destructor por defecto.
    ~Vector4() = default;

    // Constructor que inicializa un vector con los valores dados.
    // Param: x -> Valor para el componente x.
    // Param: y -> Valor para el componente y.
    // Param: z -> Valor para el componente z.
    // Param: w -> Valor para el componente w.
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    // Sobrecarga del operador + para sumar dos vectores.
    // Param: otherVector -> El vector que se va a sumar.
    // Returns: Un nuevo vector resultante de la suma.
    Vector4 operator+(const Vector4& otherVector) const {
        return Vector4(x + otherVector.x, y + otherVector.y, z + otherVector.z, w + otherVector.w);
    }

    // Sobrecarga del operador - para restar dos vectores.
    // Param: otherVector -> El vector que se va a restar.
    // Returns: Un nuevo vector resultante de la resta.
    Vector4 operator-(const Vector4& otherVector) const {
        return Vector4(x - otherVector.x, y - otherVector.y, z - otherVector.z, w - otherVector.w);
    }

    // Sobrecarga del operador * para multiplicar el vector por un escalar.
    // Param: escalar -> El valor escalar por el que se va a multiplicar.
    // Returns: Un nuevo vector resultante de la multiplicación.
    Vector4 operator*(float escalar) const {
        return Vector4(x * escalar, y * escalar, z * escalar, w * escalar);
    }

    // Calcula la magnitud (longitud) del vector.
    // Returns: La magnitud del vector.
    float magnitude() const {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    // Normaliza el vector, ajustando su magnitud a 1.
    // Returns: Un nuevo vector normalizado.
    Vector4 normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return Vector4(0, 0, 0, 0);
        }
        else {
            return Vector4(x / mag, y / mag, z / mag, w / mag);
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
