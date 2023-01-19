#pragma once
#include "pch.h"
#include <string>
#include <iostream>

class path
{
public:
	path(std::string path) : path_text(path) {};
	std::string path_text;
};

class file
{
public:
	file(std::string file) : file_text(file) {};
	std::string file_text;
};

class rawData
{
public:
	rawData(std::string raw_data) : raw_data_text(raw_data) {};
	std::string raw_data_text;
};

class data
{
public:
	data(std::string data) : data_text(data) {};
	std::string data_text;
};

class analysis
{
public:
	analysis(std::string analysis) : text(analysis) {};
	std::string text;
};

class DataMiner
{
public:
	void minePath(path);
protected:
	virtual file openFile(path) = 0;
	virtual rawData extractData(file) = 0;
	virtual data parseData(rawData) = 0;
	analysis analyseData(data);
	void sendReport(analysis);
	virtual void closeFile(file) = 0;
};

class PDFDataMiner : public DataMiner
{
	file openFile(path);
	rawData extractData(file);
	data parseData(rawData);
	void closeFile(file);
};

class TXTDataMiner : public DataMiner
{
	file openFile(path);
	rawData extractData(file);
	data parseData(rawData);
	void closeFile(file);
};