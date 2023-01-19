#include "pch.h"
#include "Adapter.h"


Data::Data(int init_id, std::string init_name, double init_height, double init_weight): id(init_id), name(init_name), height(init_height), weight(init_weight)
{
	
}

void Client::Print(Data person)
{
	std::cout << person.id << " \n";
	std::cout << person.name << " \n";
	std::cout << person.height << " \n";
	std::cout << person.weight << " \n";
}

void Service::PrintString(std::string data)
{
	std::cout << data;
}

std::string Data_To_String_Adapter::Convert(Data person)
{
	auto person_str = new std::string("");
	person_str->append(std::to_string(person.id));
	person_str->append(person.name);
	person_str->append(std::to_string(person.height));
	person_str->append(std::to_string(person.weight));
	return *person_str;
}

void Data_To_String_Adapter::Print(Data person)
{
	auto person_str = Convert(person);
	PrintString(person_str);
}

void RunAdapter()
{
	auto client = new Client();
	auto serviceAdapter = new Data_To_String_Adapter();
	Data person1(1, "Mark", 178.4, 56.3);
	Data person2(2, "Anya", 163.7, 45.6);

	client->Print(person1);
	serviceAdapter->Print(person1);
}
