#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "Point2D.hpp"
#include "Polygon.hpp"
#include "Segment.hpp"

/**
 * @brief Обрабатать файл с координатами вершин многоугольника
 *
 * @param file Файл
 * @param polygon Класс с объектом полигона
 */
void processPolys(const char *file, Polygon &polygon) {
  std::ifstream polys{file};
  assert(polys && "Couldn't open the file with polys");

  std::vector<Point2D> positions{};
  const std::string separator{','};

  // Читать файл до конца
  while (polys) {
    std::string coordinate;

    polys >> coordinate;
    if (coordinate.length() == 0)
      continue;

    // Конвертировать числовую строку в целое число
    double x{std::stod(coordinate.substr(0, coordinate.find(separator)))};
    double y{std::stod(coordinate.substr(coordinate.find(separator) + 1,
                                         coordinate.length()))};
    positions.push_back({x, y});
  };

  polygon.setArrayPos(positions);
}

/**
 * @brief Обрабатать файл с координатами отрезка
 *
 * @param file Файл
 * @param arrayOfSegments Массив с объектами отрезков
 */
void processLines(const char *file, std::vector<Segment> &listOfSegments) {
  std::ifstream lines{file};
  assert(lines && "Couldn't open the file with lines");

  const std::string separator{','};
  double x1, y1, x2, y2;

  // Читать файл до конца
  while (lines) {
    std::string coordinate;

    lines >> coordinate;
    if (coordinate.length() == 0)
      continue;

    // Конвертировать числовую строку в целое число
    x1 = std::stoi(coordinate.substr(0, coordinate.find(separator)));
    y1 = std::stoi(
        coordinate.substr(coordinate.find(separator) + 1, coordinate.length()));

    lines >> coordinate;
    // На случай если в файле нечетное кол-во координат
    if (coordinate.length() == 0)
      continue;

    // Конвертировать числовую строку в целое число
    x2 = std::stoi(coordinate.substr(0, coordinate.find(separator)));
    y2 = std::stoi(
        coordinate.substr(coordinate.find(separator) + 1, coordinate.length()));

    Segment segment{x1, y1, x2, y2};
    listOfSegments.push_back(segment);
  };
}

/**
 * @brief Вывести результаты в файл
 *
 * @param status ID статуса
 * @param line Номер линии координаты отрезка из файла с координатами отрезка
 */
void writeResults(const int &status, const int &line) {
  static std::ofstream results{"results.txt"};
  assert(results && "Couldn't open the file results.txt");
  results << status << std::endl;

  switch (status) {
  case 0:
    std::cout << "[Отрезок #" << line << "] "
              << "Oтрезок находится внутри многоугольника" << std::endl;
    break;
  case 1:
    std::cout << "[Отрезок #" << line << "] "
              << "Oтрезок пересекает многоугольник" << std::endl;
    break;
  case 2:
    std::cout << "[Отрезок #" << line << "] "
              << "Oтрезок частично пересекает многоугольник" << std::endl;
    break;
  case 3:
    std::cout << "[Отрезок #" << line << "] "
              << "Oтрезок не имеет ничего общего с многоугольником"
              << std::endl;
    break;
  default:
    break;
  }
}
