#include "Segment.hpp"

Point2D Segment::getPoint1() const { return m_point1; }
Point2D Segment::getPoint2() const { return m_point2; }

double Segment::getX1() const { return m_point1.getX(); }
double Segment::getY1() const { return m_point1.getY(); }
double Segment::getX2() const { return m_point2.getX(); }
double Segment::getY2() const { return m_point2.getY(); }
