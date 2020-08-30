#pragma once
#include <cmath>

class Vector2D
{
	double m_x, m_y;
	
public:
	Vector2D() {}
	Vector2D(double x, double y) : m_x(x), m_y(y) {}
	
	void normalize()
	{
		if (m_x == 0 && m_y == 0)
			return;

		m_x = m_x * abs(m_x / sqrt(m_x*m_x + m_y*m_y));
		m_y = m_y * abs(m_y / sqrt(m_x*m_x + m_y*m_y));
	}
	void setX(double x)
	{
		m_x = x;
	}
	void setY(double y)
	{
		m_y = y;
	}
	void set(double x, double y)
	{
		m_x = x;
		m_y = y;
	}

	double x()
	{
		return m_x;
	}
	double y()
	{
		return m_y;
	}

	void operator+=(Vector2D& v)
	{
		this->m_x += v.x();
		this->m_y += v.y();
	}
	void operator-=(Vector2D& v)
	{
		this->m_x -= v.x();
		this->m_y -= v.y();
	}

};

Vector2D& operator+(Vector2D& v1, Vector2D& v2);
Vector2D& operator-(Vector2D& v1, Vector2D& v2);