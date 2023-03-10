#include "pch.h"
#include "TemplateMethod.h"
#include <iostream>
#include <string>


class Point
{
public:
	int x;
	int y;
	Point(int newX, int newY) : x(newX), y(newY){};
};

class Route 
{
	std::string name;
	Point start;
	Point end;

public:
	Route(std::string iniName, Point A, Point B) : name(iniName), start(A), end(B) {};
	void PrintRoute();
};

class RouteStrategy
{
public:
	virtual Route buildRoute(Point A, Point B) = 0;
};

class Road : public RouteStrategy
{
	Route buildRoute(Point A, Point B);
};

class Walking : public RouteStrategy
{
	Route buildRoute(Point A, Point B);
};

class PublicTransport : public RouteStrategy
{
	Route buildRoute(Point A, Point B);
};

class Navigator
{
private:
	RouteStrategy* route;
public:
	Navigator(RouteStrategy* routeStrategy) : route(routeStrategy) {};
	Route buildRoute(Point A, Point B)
	{
		return route->buildRoute(A, B);
	}
};


int main()
{
	/*
	auto nav1 = new Navigator(new Road);
	auto nav2 = new Navigator(new Walking);
	auto nav3 = new Navigator(new PublicTransport);
	Point A(1, 3);
	Point B(2, 5);

	auto route1 = nav1->buildRoute(A, B);
	auto route2 = nav2->buildRoute(A, B);
	auto route3 = nav3->buildRoute(A, B);

	route1.PrintRoute();
	route2.PrintRoute();
	route3.PrintRoute();
	*/

	auto dm1 = new PDFDataMiner();
	path pdfPath("aaa.pdf");
	dm1->minePath(pdfPath);

	auto dm2 = new TXTDataMiner();
	path txtPath("bbb.txt");
	dm2->minePath(txtPath);
	

}
void Route::PrintRoute()
{
	std::cout << name << " between points: (" << start.x << ", " << start.y << ") (" << end.x << ", " << end.y << ")" << std::endl;
}


Route Road::buildRoute(Point A, Point B)
{
	return Route("Road route", A, B);
}

Route Walking::buildRoute(Point A, Point B)
{
	return Route("Walking route", A, B);
}

Route PublicTransport::buildRoute(Point A, Point B)
{
	return Route("Public transport route", A, B);
}
