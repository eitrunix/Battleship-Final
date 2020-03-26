#ifndef __MATHHELPER_H
#define __MATHHELPER_H
#include <math.h>

namespace SDLFramework {

#define PI 3.1415926535
#define DEG_TO_RAD PI / 180.0f

	struct Vector2 {
		float x;
		float y;

		Vector2(float _x = 0.0f, float _y = 0.0f)
			: x{ _x }, y{ _y } {}

		float MagnitudeSqr() const {
			return x * x + y * y;
		}

		float Magnitude() const {
			return (float)sqrt(x * x + y * y);
		}

		Vector2 Normalized() const {
			float mag = Magnitude();
			return Vector2(x / mag, y / mag);
		}

		Vector2 & operator+=(const Vector2 & rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		Vector2 & operator-=(const Vector2 & rhs) {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		Vector2 operator-() const {
			return Vector2(-x, -y);
		}
	};

	inline Vector2 operator+(const Vector2 & lhs, const Vector2 & rhs) {
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	inline Vector2 operator-(const Vector2 & lhs, const Vector2 & rhs) {
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	inline Vector2 operator*(const Vector2 & lhs, float rhs) {
		return Vector2(lhs.x * rhs, lhs.y * rhs);
	}

	inline Vector2 operator*(float lhs, const Vector2 & rhs) {
		return Vector2(lhs * rhs.x, lhs * rhs.y);
	}

	inline Vector2 Lerp(const Vector2 & start, const Vector2 & end, float time) {
		if (time <= 0.0f) {
			return start;
		}

		if (time >= 1.0f) {
			return end;
		}

		Vector2 dir = (end - start).Normalized();
		float mag = (end - start).Magnitude();
		return start + dir * mag * time;
	}

	inline Vector2 RotateVector(const Vector2 & vec, float angle) {
		float radAngle = (float)(angle * DEG_TO_RAD);

		return Vector2(
			(float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)),
			(float)(vec.x * sin(radAngle) + vec.y * cos(radAngle))
		);
	}

	const Vector2 Vec2_Zero = { 0.0f, 0.0f };
	const Vector2 Vec2_One = { 1.0f, 1.0f };
	const Vector2 Vec2_Up = { 0.0f, 1.0f };
	const Vector2 Vec2_Right = { 1.0f, 0.0f };
}
#endif