#include <vector>

#include "Polygon.hpp"
#include "Segment.hpp"

void processPolys(const char *file, Polygon &polygon);

void processLines(const char *file, std::vector<Segment> &listOfSegments);

void writeResults(const int &status, const int &line);
