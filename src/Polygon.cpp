#include "Polygon.hpp"

/**
 * @brief Заполняет переменную с кординатами прямоугольника
 *
 * @param coordinates
 * @return Polygon
 */
Polygon &Polygon::setArrayPos(const std::vector<Point2D> &coordinates) {
  m_coordinates = coordinates;
  return *this;
}

std::vector<Point2D> Polygon::getCoordinates() const { return m_coordinates; }
