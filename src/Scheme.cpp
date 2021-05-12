#include "Scheme.hpp"
#include "Figure.hpp"
#include <iostream>


Scheme::Scheme(int capacity) : size(0) {
    figures_ = new Figure*[capacity];
    this->capacity = capacity;
}

Scheme::~Scheme() {
    for (int i = 0; i < size; i++) {
        delete figures_[i];
    }
    delete[] figures_;
}

void Scheme::push_back_figure(Figure* fg) {
    if(size == capacity) {
        printf("You cannot surpass the capacity of the scheme");
        return;
    }
    figures_[size] = fg;
    size++;
}

int Scheme::get_figure_position(int id) {
    int position = 0;
    while (position < size && figures_[position]->get_id() != id) {
        position++;
    }
    return position < size ? position : -1;
}

void Scheme::remove_figure(int id) {
    int position = this->get_figure_position(id);
    if(position == -1) {
        printf("No figure with this id\n");
        return;
    }
    delete figures_[position];
    for(int j = position; j < size - 1; j++) {
        figures_[j] = figures_[j + 1];
    }
    size--;
}

void Scheme::print_all_figures() {
    for(int i = 0; i < size; i++) {
        figures_[i]->print();
    }
}

void Scheme::zoom_figure(int id, int factor) {
    int position = this->get_figure_position(id);
    if(position == -1) {
        printf("No figure with this id\n");
        return;
    }
    figures_[position]->zoom(factor);
}

// если внутри нескольких фигур, то возвращается любая из них
Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < size; i++) {
        if(figures_[i]->is_inside(x, y)){
            return figures_[i];
        };
    }
    return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
    int position = this->get_figure_position(id);
    if (position == -1) {
        printf("No figure with this id\n");
        return;
    }
    figures_[position]->move(new_x, new_y);
}
