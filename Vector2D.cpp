#include "Vector2D.h"

Vector2D& operator+(Vector2D& v1, Vector2D& v2)
{
	Vector2D res;
	res.setX(v1.x() + v2.x());
	res.setY(v1.y() + v2.y());

	return res;
}

Vector2D& operator-(Vector2D& v1, Vector2D& v2)
{
	Vector2D res;
	res.setX(v1.x() - v2.x());
	res.setY(v1.y() - v2.y());

	return res;
}