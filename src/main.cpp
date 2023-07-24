#include <vector>

#include "Point2D.hpp"
#include "Polygon.hpp"
#include "Segment.hpp"
#include "processFiles.hpp"

/**
 * @brief Ray casting
 *
 * @param v1p1 Первая точка вектора #1
 * @param v1p2 Вторая точка вектора #1
 * @param v2p1 Первая точка вектора #2
 * @param v2p2 Вторая точка вектора #2
 * @return Кол-во пересечений между векторами: 0 - нету, 1 - есть, 2 - два вектора на одной линии
 */
int areIntersecting(Point2D v1p1, Point2D v1p2, Point2D v2p1, Point2D v2p2) {
  double v1x1{v1p1.getX()}, v1y1{v1p1.getY()};
  double v1x2{v1p2.getX()}, v1y2{v1p2.getY()};
  double v2x1{v2p1.getX()}, v2y1{v2p1.getY()};
  double v2x2{v2p2.getX()}, v2y2{v2p2.getY()};

  double d1, d2;
  double a1, a2, b1, b2, c1, c2;

  // Преобразование вектора 1 в линию бесконечной длины
  a1 = v1y2 - v1y1;
  b1 = v1x1 - v1x2;
  c1 = (v1x2 * v1y1) - (v1x1 * v1y2);

  d1 = (a1 * v2x1) + (b1 * v2y1) + c1;
  d2 = (a1 * v2x2) + (b1 * v2y2) + c1;

  if (d1 > 0 && d2 > 0)
    return 0;
  if (d1 < 0 && d2 < 0)
    return 0;

  // Преобразование вектора 2 в линию бесконечной длины
  a2 = v2y2 - v2y1;
  b2 = v2x1 - v2x2;
  c2 = (v2x2 * v2y1) - (v2x1 * v2y2);

  d1 = (a2 * v1x1) + (b2 * v1y1) + c2;
  d2 = (a2 * v1x2) + (b2 * v1y2) + c2;

  if (d1 > 0 && d2 > 0)
    return 0;
  if (d1 < 0 && d2 < 0)
    return 0;

  if ((a1 * b2) - (a2 * b1) == 0.0f)
    return 2;

  return 1;
}

/**
 * @brief Определяет отношение отрезков к многоугольнику
 *
 * @param polygon Класс с объектом многоульника
 * @param arrayOfSegments Массив с координатами отрезков
 */
void describeStatus(const Polygon &polygon,
                    const std::vector<Segment> &listOfSegments) {
  std::vector<Point2D> points{polygon.getCoordinates()};
  int amountOfPoints{static_cast<int>(points.size())};

  // Создание точки, которая однозначно не может находится внутри полигона
  double Xmin{points.at(0).getX()}, Ymin{points.at(0).getY()};
  for (int i = 0; i < amountOfPoints; ++i) {
    Xmin = std::min(points.at(i).getX(), Xmin);
    Ymin = std::min(points.at(i).getY(), Ymin);
  }
  Point2D pointOutsideOfPolygon{Xmin - 1.0 / points.at(0).getY(),
                                Ymin - 1.0 / points.at(0).getX()};

  int iterOfSegment{1};
  for (Segment segment : listOfSegments) {
    Point2D p1{segment.getPoint1()}, p2{segment.getPoint2()};

    int amountOfIntersections{0};
    int j{1};
    for (int i = 0; i < amountOfPoints; ++i, ++j) {
      if (i == amountOfPoints - 1)
        j = 0;
      amountOfIntersections +=
          areIntersecting(p1, p2, points.at(i), points.at(j));
    }

    if (amountOfIntersections > 0) {
      if (amountOfIntersections % 2 == 0)
        // Oтрезок пересекает многоугольник
        writeResults(1, iterOfSegment);
      else
        // Oтрезок частично пересекает многоугольник
        writeResults(2, iterOfSegment);
      ++iterOfSegment;
      continue;
    }

    amountOfIntersections = 0;
    j = 1;
    for (int i = 0; i < amountOfPoints; ++i, ++j) {
      if (i == amountOfPoints - 1)
        j = 0;
      amountOfIntersections += areIntersecting(p1, pointOutsideOfPolygon,
                                               points.at(i), points.at(j));
    }
    if (amountOfIntersections % 2 == 0)
      // Отрезок не имеет ничего общего с многоугольником
      writeResults(3, iterOfSegment);
    else
      // Oтрезок находится внутри многоугольника
      writeResults(0, iterOfSegment);

    ++iterOfSegment;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    return 1;
  }

  Polygon polygon{};
  processPolys(argv[1], polygon);

  std::vector<Segment> listOfSegments{};
  processLines(argv[2], listOfSegments);

  describeStatus(polygon, listOfSegments);

  return 0;
}
