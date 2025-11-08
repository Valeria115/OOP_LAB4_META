#include <iostream>
#include <memory>
#include <sstream>
#include "include/array.h"
#include "include/rectangle.h"
#include "include/square.h"
#include "include/trapezoid.h"
#include "include/figure.h"

void printMenu() {
    std::cout << "\nActions:" << std::endl;
    std::cout << "1. Add rectangle" << std::endl;
    std::cout << "2. Add square" << std::endl;
    std::cout << "3. Add trapezia" << std::endl;
    std::cout << "4. All figure" << std::endl;
    std::cout << "5. Delete figure by index" << std::endl;
    std::cout << "6. Total area" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

void addRectangle(Array<std::shared_ptr<Figure<double>>>& array) {
    auto rect = std::make_shared<Rectangle<double>>();
    std::cout << "Add 4 point of rectangle: ";
    rect->read(std::cin);
    array.add(rect);
    std::cout << "Successful" << std::endl;
}

void addSquare(Array<std::shared_ptr<Figure<double>>>& array) {
    auto square = std::make_shared<Square<double>>();
    std::cout << "Add 4 point of square: ";
    square->read(std::cin);
    array.add(square);
    std::cout << "Successfull" << std::endl;
}

void addTrapezoid(Array<std::shared_ptr<Figure<double>>>& array) {
    auto trap = std::make_shared<Trapezoid<double>>();
    std::cout << "Add 4 point of trapezion: ";
    trap->read(std::cin);
    array.add(trap);
    std::cout << "Successfull" << std::endl;
}

void showAllFigures(Array<std::shared_ptr<Figure<double>>>& array) {
    if (array.size() == 0) {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    std::cout << "\nAll figure " << array.size() << std::endl;
    array.print(std::cout);
}

void removeFigure(Array<std::shared_ptr<Figure<double>>>& array) {
    if (array.size() == 0) {
        std::cout << "Array empty" << std::endl;
        return;
    }
    
    std::cout << "Add index (0-" << array.size()-1 << "): ";
    size_t index;
    std::cin >> index;
    
    try {
        array.remove(index);
        std::cout << "Figure delete" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: incorrect index" << std::endl;
    }
}

void showTotalArea(Array<std::shared_ptr<Figure<double>>>& array) {
    std::cout << "Total area: " << array.totalArea() << std::endl;
}

int main() {
    Array<std::shared_ptr<Figure<double>>> array;
    int choice = 0;
    
    // "Прямоугольник: 0 0 4 0 4 3 0 3"
    // "Квадрат: 0 0 3 0 3 3 0 3" 
    // "Трапеция: 0 0 5 0 4 2 1 2"
    
    while (choice != 7) {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addRectangle(array);
                break;
            case 2:
                addSquare(array);
                break;
            case 3:
                addTrapezoid(array);
                break;
            case 4:
                showAllFigures(array);
                break;
            case 5:
                removeFigure(array);
                break;
            case 6:
                showTotalArea(array);
                break;
            case 7:
                std::cout << "Exit" << std::endl;
                break;
            default:
                std::cout << "Error" << std::endl;
            
                std::cin.clear();
                std::cin.ignore(10000, '\n');
        }
    }
    return 0;
}