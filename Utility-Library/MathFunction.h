#pragma once

// Constantes
const float PI = 3.14159265358979323846f;
const float E = 2.71828182845904523536f;

/**
 * @brief Calcula la raíz cuadrada mediante el método de Newton-Raphson.
 * @param value Valor del que se calcula la raíz cuadrada.
 */
inline float 
abs(float num) {
    return num < 0 ? -num : num;
}

/**
 * @brief Calcula la raíz cuadrada (aproximación) mediante el método de Newton.
 * @param num Valor del que se calcula la raíz cuadrada.
 */
float
sqrtNewton(int num) {
    float errMargin = 0.0001f; // Margen permitido de error
    float estimate = 1.0f;     // Primera estimación
    // Se calcula hasta que la estimación sea cercana a la raíz cuadrada del número
    while (abs((estimate * estimate) - num) >= errMargin) {
        float quotient = num / estimate;           // Cociente entre el número y la estimación actual
        estimate = (quotient + estimate) / 2.0f;   // Cálculo para el valor de estimación
    }
    return estimate;
}

/**
 * @brief Calcula la raíz cuadrada mediante el método de Newton-Raphson.
 * @param value Valor del que se calcula la raíz cuadrada.
 */
inline float 
sqrt(float value) {
    // Si el valor es negativo, se retorna 0 ya que la raíz cuadrada de un número negativo no está definida en los números reales.
    if (value < 0) {
        return 0;
    }

    // Inicialización de las variables para el método de Newton-Raphson.
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
 * @brief Calcula el seno de un ángulo en radianes mediante serie de Taylor.
 * @param angle Ángulo en radianes.
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
 * @brief Calcula el coseno de un ángulo en radianes mediante serie de Taylor.
 * @param angle Ángulo en radianes.
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
 * @brief Calcula la tangente de un ángulo en radianes y comprueba que no se divida entre 0.
 * @param angle Ángulo en radianes.
 */
inline float 
tan(float angle) {
    float tSin = sin(angle);
    float tCos = cos(angle);
    return tCos != 0.0f ? tSin / tCos : 0.0f;
}
