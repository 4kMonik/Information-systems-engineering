#pragma once

class Visitor;
class WorkerVisitor;
class GuestVisitor;

class Place
{
public:
	virtual void accept(Visitor* v) = 0;
};

class Museum : public Place
{
public:
	void accept(Visitor* v);
	void getExponauts();
};

class  Cinema : public Place
{
public:
	void accept(Visitor* v);
	void getSchelude();
};


class Visitor
{
public:
	virtual void visit(Museum* e) = 0;
	virtual void visit(Cinema* e) = 0;
};

class WorkerVisitor : public Visitor
{
public:
	void visit(Museum* e);
	void visit(Cinema* e);
};

class GuestVisitor : public Visitor
{
public:
	void visit(Museum* e);
	void visit(Cinema* e);
};



