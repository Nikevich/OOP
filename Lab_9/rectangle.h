#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    void draw(QPainter& painter) override;
};

#endif // RECTANGLE_H
