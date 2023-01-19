#pragma once
#include "pch.h"
#include <string>
#include <iostream>

class IMediator;

class Component
{
public:
	enum Types
	{
		Adder = 1,
		Cheker,
		Mirror 
	};
	IMediator* m;
	Types type;
	int number;
	Component(Component::Types, int);
	void Add();
	//int GetNumber();
};



class IMediator
{
public:
	virtual void notify(Component*) = 0;
};

class MyMediator : public IMediator
{
	Component* component1;
	Component* component2;
	Component* component3;
public:
	MyMediator(Component*, Component*, Component*);
	void notify(Component*);
	void reactOn1();
	void reactOn2();
	void reactOn3();
	void PrintComponents();
};

void RunMediator();