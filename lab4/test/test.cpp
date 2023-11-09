#include <gtest/gtest.h>

#include "point.hpp"
#include "figure.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "octagon.hpp"

TEST(test_triangles, test_area_1) {
    Point2D<double> points[3] = { {0, 0}, {3, 0}, {0, 4} };
    Figure *A = new Triangle(points);
    ASSERT_TRUE (double(*A) == 6.0);
}

TEST(test_triangles, test_area_2) {
    Point2D<double> points[3] = { {0, 0}, {5, 0}, {0, 6} };
    Figure *A = new Triangle(points);
    ASSERT_TRUE (double(*A) == 15.0);
}

TEST(test_triangles, test_center_1) {
    Point2D<double> points[3] = { {0, 0}, {3, 0}, {0, 4} };
    Figure *A = new Triangle(points);
    ASSERT_TRUE (A->geometrical_center() == Point2D<double>({1, double(4) / double(3)}) );
}

TEST(test_triangles, test_center_2) {
    Point2D<double> points[3] = { {0, 0}, {5, 0}, {0, 6} };
    Figure *A = new Triangle(points);
    ASSERT_TRUE (A->geometrical_center() == Point2D<double>({double(5) / double(3), 2}) );
}

TEST(test_triangles, test_equal_1) {
    Point2D<double> points[3] = { {0, 0}, {5, 0}, {0, 6} };
    Point2D<double> points2[3] = { {0, 6}, {0, 0}, {5, 0} };
    Figure* A = new Triangle(points);
    Figure* B = new Triangle(points2);
    ASSERT_TRUE (*A == *B);
}

TEST(test_triangles, test_equal_2) {
    Point2D<double> points[3] = { {0, 0}, {5, 0}, {0, 6} };
    Point2D<double> points2[3] = { {0, 6}, {0, 3}, {5, 0} };
    Figure* A = new Triangle(points);
    Figure* B = new Triangle(points2);
    ASSERT_TRUE (*A != *B);
}

TEST(test_triangles, test_validation_1) {
    Point2D<double> points[3] = { {0, 0}, {5, 0}, {0, 6} };
    try {
        Figure* A = new Triangle(points);
        SUCCEED();
    } 
    catch (std::logic_error &l_ex) {
        FAIL() << l_ex.what() << std::endl;
    }
}

TEST(test_triangles, test_validation_2) {
    Point2D<double> points[3] = { {0, 0}, {0, 0}, {0, 6} };
    try {
        Figure* A = new Triangle(points);
        FAIL();
    } 
    catch (std::logic_error &l_ex) {
        SUCCEED() << l_ex.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}