#pragma once

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
    while (x - y > epsilon) {
        x = (x + y) / 2.0f; // Actualiza x al promedio de x e y.
        y = value / x;      // Actualiza y dividiendo el valor original entre la nueva x.
    }

    // Retorna la aproximación de la raíz cuadrada.
    return x;
}
