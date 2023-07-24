#pragma once

/**
 * @class Point2D
 * @brief Объект 2D точки
 *
 */
class Point2D {
private:
  double m_x{0};
  double m_y{0};

public:
  Point2D(double x, double y) : m_x{x}, m_y{y} {}
  ~Point2D() = default;

  Point2D &setX(double x);
  Point2D &setY(double y);

  double getX() const;
  double getY() const;
};
