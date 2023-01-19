#include "pch.h"
#include "AbstractFactoryClasses.h"

Triangle::Triangle(std::tuple<double, double> p1, std::tuple<double, double> p2, std::tuple<double, double> p3): point1(p1), point2(p2), point3(p3)
{
	std::cout << "Triangle created\n";
}

double Triangle::Area()
{
	auto x1 = std::get<0>(point1);
	auto x2 = std::get<0>(point2);
	auto x3 = std::get<0>(point3);
	auto y1 = std::get<1>(point1);
	auto y2 = std::get<1>(point2);
	auto y3 = std::get<1>(point3);
	return std::abs(0.5*((x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3)));
}

double Triangle::Perimeter()
{
	double P = 0;
	P += std::sqrt(std::pow(std::get<0>(point1) - std::get<0>(point2), 2) + std::pow(std::get<1>(point1) - std::get<1>(point2), 2));
	P += std::sqrt(std::pow(std::get<0>(point2) - std::get<0>(point3), 2) + std::pow(std::get<1>(point2) - std::get<1>(point3), 2));
	P += std::sqrt(std::pow(std::get<0>(point3) - std::get<0>(point1), 2) + std::pow(std::get<1>(point3) - std::get<1>(point1), 2));
	return P;
}

Round::Round(std::tuple<double, double> center, double r) : radius(r), centerPoint(center)
{
	std::cout << "Round created\n";
}

double Round::Area()
{
	return M_PI * std::pow(radius, 2);
}

double Round::Perimeter()
{
	return 2 * M_PI * radius;
}

Rectangle::Rectangle(std::tuple<double, double> leftBottomP, std::tuple<double, double> rightTopP): leftBottomPoint(leftBottomP), rightTopPoint(rightTopP)
{
	std::cout << "Round created\n";
}

double Rectangle::Area()
{
	return std::abs(std::get<0>(leftBottomPoint) - std::get<0>(rightTopPoint)) * std::abs(std::get<1>(leftBottomPoint) - std::get<1>(rightTopPoint));
}

double Rectangle::Perimeter()
{
	return 2 * std::abs(std::get<0>(leftBottomPoint) - std::get<0>(rightTopPoint)) + 2 * std::abs(std::get<1>(leftBottomPoint) - std::get<1>(rightTopPoint));
}
