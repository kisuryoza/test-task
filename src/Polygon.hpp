#pragma once

#include <vector>

#include "Point2D.hpp"

/**
 * @class Polygon
 * @brief Объект многоугольника
 *
 */
class Polygon {
private:
  /** массив из объектов c координатами вершин многоугольника */
  std::vector<Point2D> m_coordinates{};

public:
  Polygon() = default;
  ~Polygon() = default;

  Polygon &setArrayPos(const std::vector<Point2D> &coordinates);
  std::vector<Point2D> getCoordinates() const;
};
