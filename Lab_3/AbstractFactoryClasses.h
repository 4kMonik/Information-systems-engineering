#pragma once
#define _USE_MATH_DEFINES
#include <tuple>
#include <iostream>
#include <cmath>
class Figure
{
public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;

};

class Triangle : public Figure
{
private:
	std::tuple<double, double> point1;
	std::tuple<double, double> point2;
	std::tuple<double, double> point3;
public:
	Triangle(std::tuple<double, double> p1, std::tuple<double, double> p2, std::tuple<double, double> p3);
	double Area();
	double Perimeter();
};

class Round : public Figure
{
private:
	double radius;
	std::tuple<double, double> centerPoint;
public:
	Round(std::tuple<double, double> center, double radius);
	double Area();
	double Perimeter();
};

class Rectangle : public Figure
{
private:
	std::tuple<double, double> leftBottomPoint, rightTopPoint;
public:
	Rectangle(std::tuple<double, double> leftBottomP, std::tuple<double, double> rightTopP);
	double Area();
	double Perimeter();
};