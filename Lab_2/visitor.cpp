#include "pch.h"
#include "visitor.h"
#include <iostream>

void WorkerVisitor::visit(Museum* e)
{
	std::cout << "Worker visit museum. ";
	e->getExponauts();
	std::cout << std::endl;
}

void WorkerVisitor::visit(Cinema* e)
{
	std::cout << "Worker visit cinema. ";
	e->getSchelude();
	std::cout << std::endl;
}

void GuestVisitor::visit(Museum* e)
{
	std::cout << "Guest visit museum. ";
	e->getExponauts();
	std::cout << std::endl;
}

void GuestVisitor::visit(Cinema* e)
{
	std::cout << "Guest visit cinema. ";
	e->getSchelude();
	std::cout << std::endl;
}

void Museum::accept(Visitor* v)
{
	v->visit(this);
}

void Museum::getExponauts()
{
	std::cout << "There are some ancient stuff inside.";
}

void Cinema::accept(Visitor* v)
{
	v->visit(this);
}

void Cinema::getSchelude()
{
	std::cout << "There are some movies.";
}
