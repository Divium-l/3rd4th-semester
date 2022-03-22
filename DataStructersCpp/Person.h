#pragma once

#include <string>
#include <sstream>
#include "IComparable.h"

using namespace std;

class Person : public IComparable<Person>
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

	bool const equals(Person p) {
		return this->age == p.age && this->name.compare(p.name);
	}

	const int compareTo(Person object) override {
		return this->age - object.age;
	}

	bool const equals(Person* p) {
		return this->age == p->age && this->name.compare(p->name);
	}

	const int compareTo(Person* object) {
		return this->age - object->age;
	}
};

