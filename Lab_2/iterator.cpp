#include "pch.h"
#include "iterator.h"

Node::Node(int initValue) : val(initValue) {};

void Node::addChild(Node* child)
{
	children.push_back(child);
}


DepthFirstIterator::DepthFirstIterator(Node *firstElem) : currentElement(firstElem)
{
	nodeQueue.push(firstElem);
}

Node* DepthFirstIterator::getNext()
{
	currentElement = nodeQueue.top();
	nodeQueue.pop();
	for (auto elem : currentElement->children)
	{
		nodeQueue.push(elem);
	}
	return currentElement;
}

bool DepthFirstIterator::hasMore()
{
	if (nodeQueue.empty())
		return false;
	return true;
}


BreadthFirstIterator::BreadthFirstIterator(Node *firstElem) : currentElement(firstElem)
{
	nodeQueue.push(firstElem);
}

Node* BreadthFirstIterator::getNext()
{
	currentElement = nodeQueue.front();
	nodeQueue.pop();
	for (auto elem : currentElement->children)
	{
		nodeQueue.push(elem);
	}
	return currentElement;
}
bool BreadthFirstIterator::hasMore()
{
	if (nodeQueue.empty())
		return false;
	return true;
}

DepthFirstIterator* TreeCollection::getDepthIterator() { return new DepthFirstIterator(root); }
BreadthFirstIterator* TreeCollection::getBreadthIterator() { return new BreadthFirstIterator(root); }
TreeCollection::TreeCollection(Node* initRoot) : root(initRoot) {}