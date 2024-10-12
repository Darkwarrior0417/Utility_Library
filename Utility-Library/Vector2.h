#pragma once
#include "MathFunction.h"

class
	Vector2 {
public:
	float x;
	float y;

	Vector2() : x(0), y(0) {};


	Vector2(float xVec, float yVec) : x(xVec), y(yVec) {}

	~Vector2() = default;

	Vector2
		operator+(const Vector2& other) const {
		float new_xVec = x - other.x;
		float new_yVec = y - other.y;
		return Vector2(new_xVec, new_yVec);
	}
	Vector2
		operator-(const Vector2& other) const {
		float new_xVec = x - other.x;
		float new_yVec = y - other.y;
		return Vector2(new_xVec, new_yVec);
	}
	Vector2
		operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}
	float
		magnitude() const {
		return sqrt(x * x + y * y);
	}

	Vector2
		normalize() const {
		float magnitud = magnitude();
		if (magnitud == 0) {
			return Vector2(0, 0);
		}
		return Vector2(x / magnitud, y / magnitud);
	}
	float*
		data() {
		return &x;
	}

	const float*
		data() const {
		return &x;
	}

private:
}; #pragma once
