#pragma once

// Constantes
const float PI = 3.14159265358979323846f;
const float E = 2.71828182845904523536f;

/**
 * @brief Calcula la ra�z cuadrada mediante el m�todo de Newton-Raphson.
 * @param value Valor del que se calcula la ra�z cuadrada.
 */
inline float 
abs(float num) {
    return num < 0 ? -num : num;
}

/**
 * @brief Calcula la ra�z cuadrada (aproximaci�n) mediante el m�todo de Newton.
 * @param num Valor del que se calcula la ra�z cuadrada.
 */
float
sqrtNewton(int num) {
    float errMargin = 0.0001f; // Margen permitido de error
    float estimate = 1.0f;     // Primera estimaci�n
    // Se calcula hasta que la estimaci�n sea cercana a la ra�z cuadrada del n�mero
    while (abs((estimate * estimate) - num) >= errMargin) {
        float quotient = num / estimate;           // Cociente entre el n�mero y la estimaci�n actual
        estimate = (quotient + estimate) / 2.0f;   // C�lculo para el valor de estimaci�n
    }
    return estimate;
}

/**
 * @brief Calcula la ra�z cuadrada mediante el m�todo de Newton-Raphson.
 * @param value Valor del que se calcula la ra�z cuadrada.
 */
inline float 
sqrt(float value) {
    // Si el valor es negativo, se retorna 0 ya que la ra�z cuadrada de un n�mero negativo no est� definida en los n�meros reales.
    if (value < 0) {
        return 0;
    }

    // Inicializaci�n de las variables para el m�todo de Newton-Raphson.
    float x = value; // Valor inicial de x, comienza siendo igual al valor dado.
    float y = 1.0f;  // Valor inicial de y, comienza en 1.
    float epsilon = 0.0001f; // Margen de error permitido.

    // Itera hasta que la diferencia entre x e y sea menor que epsilon.
    while (abs(x - y) > epsilon) {
        x = (x + y) / 2.0f; // Actualiza x al promedio de x e y.
        y = value / x;      // Actualiza y dividiendo el valor original entre la nueva x.
    }

    return x;
}

/**
 * @brief Calcula el seno de un �ngulo en radianes mediante serie de Taylor.
 * @param angle �ngulo en radianes.
 */
inline float
sin(float angle) {
    float result = 0.0f;
    float term = angle;
    float angle_squared = angle * angle;
    int n = 1;
    while (abs(term) > 0.000001f) {
        result += term;
        term *= -angle_squared / ((2 * n) * (2 * n + 1));
        ++n;
    }
    return result;
}

/**
 * @brief Calcula el coseno de un �ngulo en radianes mediante serie de Taylor.
 * @param angle �ngulo en radianes.
 */
inline float
cos(float angle) {
    float result = 1.0f;
    float term = 1.0f;
    float angle_squared = angle * angle;
    int n = 1;
    while (abs(term) > 1e-6f) {
        term *= -angle_squared / ((2 * n - 1) * (2 * n));
        result += term;
        ++n;
    }
    return result;
}

/**
 * @brief Calcula la tangente de un �ngulo en radianes y comprueba que no se divida entre 0.
 * @param angle �ngulo en radianes.
 */
inline float 
tan(float angle) {
    float tSin = sin(angle);
    float tCos = cos(angle);
    return tCos != 0.0f ? tSin / tCos : 0.0f;
}
