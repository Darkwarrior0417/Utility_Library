#pragma once
#include "MathFunction.h"

class Vector3
{
public:
    float x; // Valor en x del vector
    float y; // Valor en y del vector
    float z; // Valor en z del vector

    /**
      * @brief Constructor por defecto que inicializa los valores "x", "y" y "z" en 0
      */
    Vector3() : x(0), y(0), z(0) {};

    /**
      * @brief Constructor con par�metros para los valores "x", "y" y "z"
      */
    Vector3(float xVec, float yVec, float zVec) : x(xVec), y(yVec), z(zVec) {}

    /**
      * @brief Destructor por defecto
      */
    ~Vector3() = default;

    /**
       * @brief Sobrecarga del operador +, para sumar un vector a otro vector.
       * @param other El otro vector que se sumar�.
       */
    Vector3
        operator+(const Vector3& other) const {
        float new_xVec = x + other.x;
        float new_yVec = y + other.y;
        float new_zVec = z + other.z;
        return Vector3(new_xVec, new_yVec, new_zVec);
    }

    /**
       * @brief Sobrecarga del operador -, para restar un vector a otro vector.
       * Se optimiza realizando ahora las operaciones dentro del return.
       * @param other El otro vector que se restar�.
       */
    Vector3
        operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    /**
       * @brief Sobrecarga del operador *, para multiplicar un vector a otro vector.
       * @param other El otro vector que se multiplicar�.
       */
    Vector3
        operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    /**
      * @brief Se cacula la magnitud de los valores del vector
      */
    float
        magnitude() {
        return sqrt(x * x + y * y + z * z);
    }

    /**
       * @brief Normalizaci�n del vector que devuelva un vector con la misma direcci�n
       */
    Vector3
        normalize() {
        float magnitud = magnitude();
        // Si la magnitud es 0, se devuelve un vector con las coordenadas (0,0,0)
        if (magnitud == 0) {
            return Vector3(0, 0, 0);
        }
        return Vector3(x / magnitud, y / magnitud, z / magnitud);
    }

    /**
      * @brief M�todo que devuelve un puntero a los componentes del vector
      */
    float*
        data() {
        return &x;
    }

    /**
      * @brief M�todo constante con un puntero a los componentes del vector sin modificarlos
      */
    const float*
        data() const {
        return &x;
    }

private:

};
