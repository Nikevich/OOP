#include "mainwindow.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    shapes.push_back(std::make_unique<Triangle>());
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Rectangle>());
}

MainWindow::~MainWindow() = default;

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    for (const auto& shape : shapes) {
        shape->draw(painter);
    }
}
