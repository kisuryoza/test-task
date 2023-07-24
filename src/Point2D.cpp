#include "Point2D.hpp"

Point2D &Point2D::setX(double x) {
  m_x = x;
  return *this;
}

Point2D &Point2D::setY(double y) {
  m_y = y;
  return *this;
}

double Point2D::getX() const { return m_x; }
double Point2D::getY() const { return m_y; }
