#pragma once

#include <string>
#include <sstream>

using namespace std;

class Person
{
public:
	string name;
	int age;

	Person() {
		this->name = "UNSIGNED";
		this->age = 0;
	}

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string const toString() {
		stringstream stream;
		stream << "{" << "name: " << name << ", " << "age: " << age << "}";
		return stream.str();
	}

	bool const equals(Person* p) {
		return this->age == p->age && this->name._Equal(p->name);
	}
};

