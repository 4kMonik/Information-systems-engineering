#pragma once
#include "pch.h"
#include <string>
#include <iostream>

class Data
{
public:
	int id;
	std::string name;
	double height;
	double weight;
	Data(int, std::string, double, double);
	
};

class Client
{
public:
	void Print(Data);
};

class Service
{
public:
	void PrintString(std::string);
};

class Data_To_String_Adapter : public Client, public Service
{
private:
	std::string Convert(Data);
public:
	void Print(Data);
};

void RunAdapter();