#pragma once
#include "Vector3.h"
#include "MathUtilities.h"

/**
 * @class Quaternion
 * @brief Clase que representa un cuaternión, utilizado para realizar cálculos de rotación en 3D.
 */
class Quaternion {
public:
    float x; ///< Componente X del cuaternión.
    float y; ///< Componente Y del cuaternión.
    float z; ///< Componente Z del cuaternión.
    float w; ///< Componente escalar del cuaternión.

    /**
     * @brief Constructor por defecto. Inicializa los valores en 0.
     */
    Quaternion() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Destructor por defecto.
     */
    ~Quaternion() = default;

    /**
     * @brief Constructor que inicializa el cuaternión con valores dados.
     * @param x Valor para la componente X.
     * @param y Valor para la componente Y.
     * @param z Valor para la componente Z.
     * @param w Valor para la componente W.
     */
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    /**
     * @brief Inicializa un cuaternión a partir de un eje y un ángulo de rotación.
     * @param axis Vector que representa el eje de rotación.
     * @param angle Ángulo de rotación en radianes.
     * @return El cuaternión resultante de la rotación.
     *
     * Se basa en la fórmula q = (x * sin(θ/2), y * sin(θ/2), z * sin(θ/2), cos(θ/2)),
     * donde los primeros tres valores corresponden al eje y el último al escalar.
     */
    Quaternion fromAxisAndAngle(Vector3& axis, float angle) {
        float halfAngle = angle * 0.5f;
        float sinHalfAngle = sin(halfAngle);

        x = axis.x * sinHalfAngle;
        y = axis.y * sinHalfAngle;
        z = axis.z * sinHalfAngle;
        w = cos(halfAngle);

        return Quaternion(x, y, z, w);
    }

    /**
     * @brief Sobrecarga del operador + para sumar dos cuaterniones.
     * @param otherQuaternion El cuaternión que se va a sumar.
     * @return El cuaternión resultante de la suma.
     */
    Quaternion operator+(const Quaternion& otherQuaternion) const {
        return Quaternion(
            x + otherQuaternion.x,
            y + otherQuaternion.y,
            z + otherQuaternion.z,
            w + otherQuaternion.w
        );
    }

    /**
     * @brief Sobrecarga del operador * para multiplicar el cuaternión por un escalar.
     * @param escalar Valor por el cual se va a multiplicar el cuaternión.
     * @return El cuaternión resultante de la multiplicación.
     */
    Quaternion operator*(float escalar) const {
        return Quaternion(
            x * escalar,
            y * escalar,
            z * escalar,
            w * escalar
        );
    }

    /**
     * @brief Sobrecarga del operador * para multiplicar dos cuaterniones.
     * @param otherQuaternion El cuaternión que se va a multiplicar.
     * @return El cuaternión resultante de la multiplicación.
     */
    Quaternion operator*(const Quaternion& otherQuaternion) const {
        return Quaternion(
            w * otherQuaternion.w - x * otherQuaternion.x - y * otherQuaternion.y - z * otherQuaternion.z,
            w * otherQuaternion.x + x * otherQuaternion.w + y * otherQuaternion.z - z * otherQuaternion.y,
            w * otherQuaternion.y - x * otherQuaternion.z + y * otherQuaternion.w + z * otherQuaternion.x,
            w * otherQuaternion.z + x * otherQuaternion.y - y * otherQuaternion.x + z * otherQuaternion.w
        );
    }

    /**
     * @brief Calcula la magnitud (norma) del cuaternión.
     * @return La magnitud del cuaternión.
     */
    float magnitude() const {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Normaliza el cuaternión, ajustando su magnitud a 1.
     * @return El cuaternión normalizado.
     */
    Quaternion normalize() {
        float mag = magnitude();
        if (mag == 0) {
            return Quaternion(1, 0, 0, 0);
        }
        return Quaternion(x / mag, y / mag, z / mag, w / mag);
    }

    /**
     * @brief Calcula el conjugado del cuaternión.
     * @return El conjugado del cuaternión.
     */
    Quaternion conjugate() {
        return Quaternion(-x, -y, -z, w);
    }

    /**
     * @brief Devuelve un puntero a los datos del cuaternión.
     * @return Un puntero al primer elemento del cuaternión (componente w).
     */
    float* data() {
        return &w;
    }

    /**
     * @brief Devuelve un puntero constante a los datos del cuaternión.
     * @return Un puntero constante al primer elemento del cuaternión (componente w).
     */
    const float* data() const {
        return &w;
    }
};