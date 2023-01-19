#include "pch.h"
#include "TemplateMethod.h"

void DataMiner::minePath(path filePath)
{
	auto file = openFile(filePath);
	auto rawData = extractData(file);
	auto data = parseData(rawData);
	auto analysis = analyseData(data);
	sendReport(analysis);
	closeFile(file);
}

analysis DataMiner::analyseData(data d)
{
	return analysis("Anlysis: " + d.data_text);
}

void DataMiner::sendReport(analysis a)
{
	std::cout << "Report send: " << a.text;
}

file PDFDataMiner::openFile(path p)
{
	return file("PDF file: " + p.path_text + "\n");
}

rawData PDFDataMiner::extractData(file f)
{
	return rawData("RawData from PDF: " + f.file_text);
}

data PDFDataMiner::parseData(rawData rd)
{
	return data("Data: " + rd.raw_data_text);
}

void PDFDataMiner::closeFile(file)
{
	std::cout << "PDF file closed" << std::endl;
}


file TXTDataMiner::openFile(path p)
{
	return file("TXT file: " + p.path_text + "\n");
}

rawData TXTDataMiner::extractData(file f)
{
	return rawData("RawData from txt: " + f.file_text);
}

data TXTDataMiner::parseData(rawData rd)
{
	return data("Data: " + rd.raw_data_text);
}

void TXTDataMiner::closeFile(file)
{
	std::cout << "TXT file closed" << std::endl;
}


