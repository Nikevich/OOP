#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    void draw(QPainter& painter) override;
};

#endif // CIRCLE_H
