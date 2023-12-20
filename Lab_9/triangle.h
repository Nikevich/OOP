#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
    void draw(QPainter& painter) override;
};

#endif // TRIANGLE_H
