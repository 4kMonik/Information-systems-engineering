#include "pch.h"
#include "iterator.h"
#include "visitor.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>


int main()
{
	//Iterator
	auto a = new Node(1);
	a->addChild(new Node(2));
	a->addChild(new Node(4));
	a->addChild(new Node(8));
	a->children[0]->addChild(new Node(10));
	a->children[1]->addChild(new Node(20));

	auto tree = new TreeCollection(a);

	for (auto iterDFS = tree->getDepthIterator(); iterDFS->hasMore();)
	{
		std::cout << " " << iterDFS->getNext()->val << " ";
	}
	std::cout << std::endl;
	for (auto iterBFS = tree->getBreadthIterator(); iterBFS->hasMore();)
	{
		std::cout << " " << iterBFS->getNext()->val << " ";
	}
	std::cout << std::endl;

	// Visitor
	auto centralMuseum = new Museum();
	auto smallCinema = new Cinema();
	auto typicalWorker = new WorkerVisitor();
	auto sleepyGuest = new GuestVisitor();

	centralMuseum->accept(typicalWorker);
	smallCinema->accept(sleepyGuest);
}



