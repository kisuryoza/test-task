#pragma once

#include "Point2D.hpp"

/**
 * @class Segment
 * @brief Объект отрезка
 *
 */
class Segment {
private:
  Point2D m_point1{0, 0};
  Point2D m_point2{0, 0};

public:
  Segment(double x1, double y1, double x2, double y2)
      : m_point1{x1, y1}, m_point2{x2, y2} {}
  ~Segment() = default;

  Point2D getPoint1() const;
  Point2D getPoint2() const;

  double getX1() const;
  double getY1() const;
  double getX2() const;
  double getY2() const;
};
