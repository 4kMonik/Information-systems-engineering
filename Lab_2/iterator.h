#pragma once
#include <vector>
#include <stack>
#include <queue>

class Node
{
public:
	std::vector<Node*> children;
	int val;
	Node(int initValue);
	void addChild(Node* child);
};

class DepthFirstIterator
{
private:
	Node* currentElement;
	std::stack<Node*> nodeQueue;
public:
	DepthFirstIterator(Node *firstElem);
	Node* getNext();
	bool hasMore();
};

class BreadthFirstIterator
{
private:
	Node* currentElement;
	std::queue<Node*> nodeQueue;
public:
	BreadthFirstIterator(Node *firstElem);
	Node* getNext();
	bool hasMore();
};

class TreeCollection
{
public:
	Node* root;

	DepthFirstIterator* getDepthIterator();
	BreadthFirstIterator* getBreadthIterator();
	TreeCollection(Node* initRoot);
};
