#include "pch.h"
#include "AbstractFactory.h"

Triangle* OnesFigureFactory::createTriangle()
{
	return new Triangle(std::make_tuple<double, double>(1, 1), std::make_tuple<double, double>(1, 0), std::make_tuple<double, double>(0, 1));
}

Round* OnesFigureFactory::createRound()
{
	return new Round(std::make_tuple <double, double>(1,1), 1);
}

Rectangle * OnesFigureFactory::createRectangle()
{
	return new Rectangle(std::make_tuple <double, double>(0, 0), std::make_tuple <double, double>(1, 1));
}

Triangle * RandomFigureFactory::createTriangle()
{
	std::srand(time(0));
	auto max = 10;
	return new Triangle(std::make_tuple<double, double>(rand()%max, rand()%max), std::make_tuple<double, double>(rand() % max, rand() % max), std::make_tuple<double, double>(rand() % max, rand() % max));;
}

Round * RandomFigureFactory::createRound()
{
	std::srand(time(0));
	auto max = 10;
	return new Round(std::make_tuple<double, double>(rand() % max, rand() % max), rand()%max);
}

Rectangle * RandomFigureFactory::createRectangle()
{
	std::srand(time(0));
	auto max = 10;
	return new Rectangle(std::make_tuple<double, double>(rand() % max, rand() % max), std::make_tuple<double, double>(rand() % max, rand() % max));
}

void RunAbstractFactory()
{
	auto factory = new OnesFigureFactory();
	auto myTriangle = factory->createTriangle();
	std::cout << myTriangle->Area() << " " << myTriangle->Perimeter();
	std::cout << std::endl;
	auto myRound = factory->createRound();
	std::cout << myRound->Area() << " " << myRound->Perimeter();
	std::cout << std::endl;
	auto myRectangle = factory->createRectangle();
	std::cout << myRectangle->Area() << " " << myRectangle->Perimeter();
}
