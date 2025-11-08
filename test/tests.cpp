#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "../include/rectangle.h"
#include "../include/square.h"
#include "../include/trapezoid.h"
#include "../include/point.h"
#include "../include/array.h"
#include "../include/figure.h"


TEST(PointTest, ConstructorAndGetters) {
    geom::Point<int> p1(5, 10);
    EXPECT_EQ(p1.x(), 5);
    EXPECT_EQ(p1.y(), 10);
}

TEST(PointTest, ArithmeticOperations) {
    geom::Point<int> p1(2, 3);
    geom::Point<int> p2(1, 1);
    
    auto sum = p1 + p2;
    EXPECT_EQ(sum.x(), 3);
    EXPECT_EQ(sum.y(), 4);
}

TEST(PointTest, Comparison) {
    geom::Point<int> p1(2, 3);
    geom::Point<int> p2(2, 3);
    geom::Point<int> p3(2, 4);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}


TEST(RectangleTest, AreaCalculation) {
    Rectangle<int> rect;
    std::istringstream input("0 0 4 0 4 3 0 3");
    EXPECT_NO_THROW(rect.read(input));
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle<double> rect;
    std::istringstream input("0 0 6 0 6 4 0 4");
    EXPECT_NO_THROW(rect.read(input));
    
    auto center = rect.center();
    EXPECT_DOUBLE_EQ(center.x(), 3.0);
    EXPECT_DOUBLE_EQ(center.y(), 2.0);
}

TEST(RectangleTest, DoubleConversion) {
    Rectangle<int> rect;
    std::istringstream input("0 0 5 0 5 2 0 2");
    EXPECT_NO_THROW(rect.read(input));
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 10.0);
}


TEST(SquareTest, AreaCalculation) {
    Square<int> square;
    std::istringstream input("0 0 5 0 5 5 0 5");
    EXPECT_NO_THROW(square.read(input));
    EXPECT_DOUBLE_EQ(square.area(), 25.0);
}

TEST(SquareTest, CenterCalculation) {
    Square<double> square;
    std::istringstream input("0 0 4 0 4 4 0 4");
    EXPECT_NO_THROW(square.read(input));
    
    auto center = square.center();
    EXPECT_DOUBLE_EQ(center.x(), 2.0);
    EXPECT_DOUBLE_EQ(center.y(), 2.0);
}


TEST(ArrayTest, BasicOperations) {
    Array<std::shared_ptr<Figure<double>>> array;
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.capacity(), 0);
}

TEST(ArrayTest, AddAndGetFigures) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    auto rect = std::make_shared<Rectangle<double>>();
    std::istringstream input1("0 0 4 0 4 3 0 3");
    rect->read(input1);
    
    array.add(rect);
    EXPECT_EQ(array.size(), 1);
    EXPECT_DOUBLE_EQ(array.get(0)->area(), 12.0);
}

TEST(ArrayTest, RemoveFigure) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    auto rect = std::make_shared<Rectangle<double>>();
    std::istringstream input("0 0 4 0 4 3 0 3");
    rect->read(input);
    
    array.add(rect);
    EXPECT_EQ(array.size(), 1);
    
    EXPECT_NO_THROW(array.remove(0));
    EXPECT_EQ(array.size(), 0);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    auto rect = std::make_shared<Rectangle<double>>();
    std::istringstream input1("0 0 4 0 4 3 0 3");
    rect->read(input1);
    
    auto square = std::make_shared<Square<double>>();
    std::istringstream input2("0 0 2 0 2 2 0 2");
    square->read(input2);
    
    array.add(rect);
    array.add(square);
    
    double rect_area = rect->area();
    double square_area = square->area();
    double total = array.totalArea();
    double expected = rect_area + square_area;
    
    // std::cout << "Debug: rect_area=" << rect_area 
    //           << ", square_area=" << square_area 
    //           << ", total=" << total 
    //           << ", expected=" << expected << std::endl;
    
    EXPECT_DOUBLE_EQ(total, expected);
}

TEST(ArrayTest, MultipleAddAndRemove) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    for (int i = 0; i < 5; ++i) {
        auto rect = std::make_shared<Rectangle<double>>();
        std::istringstream input("0 0 2 0 2 2 0 2");
        rect->read(input);
        array.add(rect);
    }
    
    EXPECT_EQ(array.size(), 5);
    
    array.remove(2);
    array.remove(0);
    
    EXPECT_EQ(array.size(), 3);
}


TEST(FigureTest, PolymorphicBehavior) {
    std::shared_ptr<Figure<double>> figure1 = std::make_shared<Rectangle<double>>();
    std::shared_ptr<Figure<double>> figure2 = std::make_shared<Square<double>>();
    
    std::istringstream input1("0 0 4 0 4 3 0 3");
    std::istringstream input2("0 0 3 0 3 3 0 3");
    
    figure1->read(input1);
    figure2->read(input2);
    
    EXPECT_DOUBLE_EQ(figure1->area(), 12.0);
    EXPECT_DOUBLE_EQ(figure2->area(), 9.0);
}

TEST(FigureTest, CloneMethod) {
    auto original = std::make_shared<Rectangle<double>>();
    std::istringstream input("0 0 5 0 5 2 0 2");
    original->read(input);
    
    auto cloned = original->clone();
    EXPECT_DOUBLE_EQ(original->area(), cloned->area());
}


TEST(ExceptionTest, ArrayBounds) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    EXPECT_THROW(array.get(0), std::out_of_range);
    EXPECT_THROW(array.remove(0), std::out_of_range);
    
    auto rect = std::make_shared<Rectangle<double>>();
    std::istringstream input("0 0 2 0 2 2 0 2");
    rect->read(input);
    array.add(rect);
    
    EXPECT_NO_THROW(array.get(0));
    EXPECT_THROW(array.get(1), std::out_of_range);
}

TEST(ExceptionTest, InvalidIndexOperations) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    EXPECT_THROW(array.remove(0), std::out_of_range);
    
    auto rect = std::make_shared<Rectangle<double>>();
    std::istringstream input("0 0 2 0 2 2 0 2");
    rect->read(input);
    array.add(rect);
    
    EXPECT_THROW(array.get(1), std::out_of_range);
    EXPECT_THROW(array.remove(1), std::out_of_range);
    EXPECT_THROW(array.remove(5), std::out_of_range);
}


TEST(TemplateTest, DifferentScalarTypes) {
    Square<int> square_int;
    std::istringstream input1("0 0 3 0 3 3 0 3");
    square_int.read(input1);
    EXPECT_DOUBLE_EQ(square_int.area(), 9.0);
    
    Square<double> square_double;
    std::istringstream input2("0 0 3.5 0 3.5 3.5 0 3.5");
    square_double.read(input2);
    EXPECT_DOUBLE_EQ(square_double.area(), 12.25);
}

TEST(TemplateTest, ArrayCapacityGrowth) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    size_t initial_capacity = array.capacity();
    
    for (int i = 0; i < 10; ++i) {
        auto square = std::make_shared<Square<double>>();
        std::istringstream input("0 0 1 0 1 1 0 1");
        square->read(input);
        array.add(square);
    }
    
    EXPECT_EQ(array.size(), 10);
    EXPECT_GE(array.capacity(), initial_capacity);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}