#pragma once
#include <cmath>
#include <iostream>

class Vector2 {
public:
	float x;
	float y;

	Vector2() : x(0), y(0) {};

	~Vector2() = default;

	Vector2(float x = 0, float y = 0) : x(x), y(y){}

	//Suma, sobrecarga el operador de operador uniario
	Vector2
		operator+(const Vector2& otherVector) const {
		return Vector2(x + otherVector.x, y + otherVector.y);
	}
	//Resta, sobrecarga el operador de operador uniario
	Vector2
		operator-(const Vector2& otherVector) const {
		return Vector2(x - otherVector.x, y - otherVector.y);
	}
	//Muliplicacion, sobrecarga el operador de operador uniario
	//Y multiplicacion por escalar
	Vector2
		operator*(float escalar) const {
		return Vector2(x * escalar, y * escalar);
	}

	//Calcular magnitud
	float
		magnitude() const {
		return sqrt(x * x + y * y);
	}

	//Normalizar vector
	Vector2
		normalize() const {
		float mag = magnitude();
		if (mag == 0) {
			return Vector2(0, 0);
		}
		else {
			return Vector2(x / mag, y / mag);
		}
	}

	float*
		data() {
		return &x; //Con acceder a uno, accedemos a ambos
	}
	const float*
		data() const {
		return &x; //Al ser constante, no se puede modificar
	}

	// Método para imprimir el vector
	void print() const {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}
};