#pragma once

// Constantes matem�ticas
constexpr float PI = 3.14159265358979323846f;
constexpr float EULER = 2.71828182845904523536f;

// Funci�n para calcular el valor absoluto
float absolute(float value) {
    return (value < 0) ? -value : value;
}

// Aproximaci�n de la ra�z cuadrada usando el m�todo de Newton-Raphson
float sqrtApproximation(int number) {
    float marginError = 1e-4f;
    float guess = 1.0f;

    while (absolute((guess * guess) - number) >= marginError) {
        guess = (number / guess + guess) / 2.0f;
    }
    return guess;
}

// Funci�n en l�nea para calcular la ra�z cuadrada
inline float sqrt(float value) {
    if (value < 0) {
        return 0.0f;
    }
    float approx = value;
    float betterGuess = 1.0f;
    float tolerance = 1e-5f;

    while (approx - betterGuess > tolerance) {
        approx = (approx + betterGuess) / 2.0f;
        betterGuess = value / approx;
    }
    return approx;
}

// Funci�n en l�nea para calcular el seno utilizando una serie de Taylor
inline float sine(float angle) {
    float sineResult = 0.0f;
    float term = angle;
    float angleSquared = angle * angle;
    int n = 1;

    while (absolute(term) > 1e-6f) {
        sineResult += term;
        term *= -angleSquared / ((2 * n) * (2 * n + 1));
        ++n;
    }
    return sineResult;
}

// Funci�n en l�nea para calcular el coseno utilizando una serie de Taylor
inline float cosine(float angle) {
    float cosineResult = 1.0f;
    float term = 1.0f;
    float angleSquared = angle * angle;
    int n = 1;

    while (absolute(term) > 1e-6f) {
        term *= -angleSquared / ((2 * n - 1) * (2 * n));
        cosineResult += term;
        ++n;
    }
    return cosineResult;
}

// Funci�n en l�nea para calcular la tangente y evitar divisiones por cero
inline float tangent(float angle) {
    float sinValue = sine(angle);
    float cosValue = cosine(angle);
    return (cosValue != 0.0f) ? (sinValue / cosValue) : 0.0f;
}
