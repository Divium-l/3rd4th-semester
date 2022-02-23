#pragma once

#include "Person.h"
#include <sstream>

class LinkedList {

	struct Node {

		Person* data;
		Node* next;

		Node() {
			this->data = nullptr;
			this->next = nullptr;
		}

		Node(Person* data) {
			this->data = data;
			this->next = nullptr;
		}
	};

	Node* node;
	size_t size;

	void increaseSize() {
		size++;
	}


	void decreaseSize() {
		size--;
	}

	void const validateIndex(const int index) {
		if (index < 0 || index > size - 1)
			throw new exception("Index out of bounds");
	}

public:
	LinkedList() {
		this->node = new Node();
		this->size = 1;
	}

	void add(Person* data) {
		Node* currentNode = this->node;

		//Первичное добавление элемента в список
		if (currentNode->data == nullptr) {
			currentNode->data = data;
			return;
		}

		//Добавление элемента в конец списка
		//Поиск последней ноды
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		currentNode->next = new Node(data);
		increaseSize();
	}

	void insert(Person* data, const int index) {
		validateIndex(index);

		int currentIndex = 0;
		Node* currentNode = this->node;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		Node* nextNode = currentNode->next;
		currentNode->next = new Node(data);
		currentNode->next->next = nextNode;
		increaseSize();
	}

	bool const contains(Person* data) {
		Node* currentNode = this->node;

		while (currentNode != nullptr) {
			if (currentNode->data->equals(data))
				return true;

			currentNode = currentNode->next;
		}

		return false;
	}

	bool const contains(Person* data, bool (*lambda)(Person* object)) {
		Node* currentNode = this->node;

		while (currentNode != nullptr) {
			if (lambda(currentNode->data))
				return true;

			currentNode = currentNode->next;
		}

		return false;
	}

	int const size() {
		return size;
	}

	string toString() {
		stringstream stream;
		Node* currentNode = this->node;

		while (currentNode != nullptr) {
			stream << currentNode->data->toString() << " -> ";
			currentNode = currentNode->next;
		}

		stream << "null";
		return stream.str();
	}

	/*
	* @param string (*lambda)(Person* object) - Функция для преобразования объекта в строку
	*/
	string toString(string (*lambda)(Person* object)) {
		stringstream stream;
		Node* currentNode = this->node;

		while (currentNode != nullptr) {
			stream << lambda(currentNode->data) << "->";
			currentNode = currentNode->next;
		}

		stream << "null";
		return stream.str();
	}
};

