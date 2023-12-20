#include "triangle.h"
#include <QPolygonF>

void Triangle::draw(QPainter& painter) {
    QPolygonF triangle;
    triangle << QPointF(10, 10) << QPointF(50, 10) << QPointF(30, 50);

    painter.drawPolygon(triangle);
}
