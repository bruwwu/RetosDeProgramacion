#include "Vector2.h"

int main() {
    // Creación de los vectores
    Vector2 v1(3.0f, 4.0f);
    Vector2 v2;
    Vector2 v3 = v1 + Vector2(1.0f, 2.0f);
    Vector2 v4 = v1 - Vector2(0.5f, 0.5f);
    Vector2 v5 = v1 * 2.0f;

    // Magnitud y normalización
    float mag = v1.magnitude();
    Vector2 v6 = v1.normalize();
    const float* data = v1.data();

    // Mostrar los resultados
    std::cout << "v1: ";
    v1.print();

    std::cout << "v2 (default): ";
    v2.print();

    std::cout << "v3 Suma de dos Vectores: ";
    v3.print();

    std::cout << "v4 Resta de dos vectores: ";
    v4.print();

    std::cout << "v5 multiplicacion por escalar ";
    v5.print();

    std::cout << "Magnitud v1: " << mag << std::endl;

    std::cout << "v6 (v1 normalizado): ";
    v6.print();

    std::cout << "Datos de v1 (pointers): [" << data[0] << ", " << data[1] << "]" << std::endl;

    return 0;
}
