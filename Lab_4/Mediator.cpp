#include "pch.h"
#include "Mediator.h"

Component::Component(Component::Types init_type, int init_number) : type(init_type), number(init_number)
{

}

void Component::Add()
{
	this->number ++;
	m->notify(this);
}



MyMediator::MyMediator(Component* adder, Component* checker, Component* mirror) : component1(adder), component2(checker), component3(mirror)
{
	component1->m = this;
	component2->m = this;
	component3->m = this;
}

void MyMediator::notify(Component* sender)
{
	switch (sender->type)
	{
	case Component::Adder:
		reactOn1();
		break;
	case Component::Cheker:
		reactOn2();
		break;
	case Component::Mirror:
		reactOn3();
		break;
	default:
		break;
	}
}

void MyMediator::reactOn1()
{
	if (component1->number > 4)
		component2->number = 100;
	else 
		component2->number = 0;
	component3->number--;
}

void MyMediator::reactOn2()
{
}

void MyMediator::reactOn3()
{
	component1->number--;
	if (component1->number > 4)
		component2->number = 100;
	else
		component2->number = 0;
}

void MyMediator::PrintComponents()
{
	std::cout << "Adder: " << component1->number << std::endl;
	std::cout << "Cheker: " << component2->number << std::endl;
	std::cout << "Mirror: " << component3->number << std::endl;
	std::cout << std::endl;
}

void RunMediator()
{
	auto adder = new Component(Component::Adder, 4);
	auto cheker = new Component(Component::Cheker, 50);
	auto mirror = new Component(Component::Mirror, 4);

	auto mediator = new MyMediator(adder, cheker, mirror);

	mediator->PrintComponents();
	adder->Add();
	mediator->PrintComponents();
	mirror->Add();
	mediator->PrintComponents();
	
}
