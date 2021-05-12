#include "Rectangle.hpp"
#include <iostream>
#include <cstdlib>


Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y) {
    this->width = width;
    this->height = height;
};

Rectangle::~Rectangle()=default;

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
};

bool Rectangle::is_inside(int x, int y) const {
    return (2 * abs(this->x - x) <= width) && (2 * abs(this->y - y) <= height);
};

void Rectangle::zoom(int factor) {
    width *= factor;
    height *= factor;
};
