#pragma once
#include "MathFunction.h"

/**
 * @brief Clase que representa un vector en 2D.
 */
class Vector2 {
public:
    float x; ///< Coordenada x del vector
    float y; ///< Coordenada y del vector

    /**
     * @brief Constructor por defecto que inicializa el vector a (0,0).
     */
    Vector2() : x(0), y(0) {}

    /**
     * @brief Constructor que inicializa el vector con valores específicos.
     * @param xVec Valor de la coordenada x.
     * @param yVec Valor de la coordenada y.
     */
    Vector2(float xVec, float yVec) : x(xVec), y(yVec) {}

    /**
     * @brief Destructor por defecto.
     */
    ~Vector2() = default;

    /**
     * @brief Suma dos vectores.
     * @param other El otro vector a sumar.
     */
    Vector2 operator+(const Vector2& other) const {
        float new_xVec = x + other.x; // Sumar las coordenadas x
        float new_yVec = y + other.y; // Sumar las coordenadas y
        return Vector2(new_xVec, new_yVec); // Retornar un nuevo vector con las coordenadas sumadas
    }

    /**
     * @brief Resta dos vectores.
     * @param other El otro vector a restar.
     */
    Vector2 operator-(const Vector2& other) const {
        float new_xVec = x - other.x; // Restar las coordenadas x
        float new_yVec = y - other.y; // Restar las coordenadas y
        return Vector2(new_xVec, new_yVec); // Retornar un nuevo vector con las coordenadas restadas
    }

    /**
     * @brief Multiplica el vector por un escalar.
     * @param scalar El valor escalar por el cual multiplicar.
     */
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar); // Multiplicar las coordenadas x e y por el escalar
    }

    /**
     * @brief Calcula la magnitud del vector.
     */
    float magnitude() const {
        return sqrt(x * x + y * y); // Calcular la magnitud usando la raíz cuadrada de la suma de los cuadrados de las coordenadas
    }

    /**
     * @brief Normaliza el vector.
     */
    Vector2 normalize() const {
        float magnitud = magnitude(); // Obtener la magnitud del vector
        if (magnitud == 0) { // Si la magnitud es cero, retornar un vector (0,0)
            return Vector2(0, 0);
        }
        return Vector2(x / magnitud, y / magnitud); // Dividir las coordenadas por la magnitud para normalizar el vector
    }

    /**
     * @brief Devuelve un puntero a los datos del vector.
     */
    float* data() {
        return &x; // Retornar la dirección de memoria de la coordenada x
    }

    /**
     * @brief Devuelve un puntero constante a los datos del vector.
     */
    const float* data() const {
        return &x; // Retornar la dirección de memoria de la coordenada x
    }

private:
   
};
