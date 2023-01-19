#pragma once
#include "AbstractFactoryClasses.h"
#include <random>
#include <ctime>

class FigureFactory
{
public:
	virtual Triangle* createTriangle() = 0;
	virtual Round* createRound() = 0;
	virtual Rectangle* createRectangle() = 0;
};

class OnesFigureFactory : public FigureFactory
{
public:
	Triangle* createTriangle();
	Round* createRound();
	Rectangle* createRectangle();
};

class RandomFigureFactory : public FigureFactory
{
public:
	Triangle* createTriangle();
	Round* createRound();
	Rectangle* createRectangle();
};

void RunAbstractFactory();