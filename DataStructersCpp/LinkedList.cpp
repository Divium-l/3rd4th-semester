#pragma once

#include "Person.h"
#include <sstream>
#include <iostream>

/*
* @brief Односвязный список
*/
class LinkedList {

	/*
	* @brief Контейнер для хранения данных
	*/
	class Node {
	public:

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

		~Node() {
			if (next != nullptr)
				delete next;
		}
	};

	/*
	* @brief Указатель на первый контейнер
	*/
	Node* node;
	size_t listSize;

	void increaseSize() {
		listSize++;
	}

	void decreaseSize() {
		listSize--;
	}

	void const validateIndex(const int index) {
		if (index < 0 || index > listSize - 1)
			throw new exception("Index out of bounds");
	}

	void deleteFirstNode() {
		//сохраняем указатель на 2-ую ноду
		auto secondNode = this->node->next;

		//удаляем первую ноду, присваиваем нулевой указатель чтобы не запустилась цепная реакция
		this->node->next = nullptr;
		delete this->node;

		//делаем вторую ноду первой
		this->node = secondNode;
		decreaseSize();
	}

	void deleteNextNode(Node* currentNode) {
		//пропускаем ноду которую надо удалить
		auto deleteNode = currentNode->next;
		currentNode->next = deleteNode->next;

		//теперь удаляем её
		deleteNode->next = nullptr;
		delete deleteNode;
		decreaseSize();
	}

public:
	LinkedList() {
		this->node = new Node();
		this->listSize = 1;
	}

	~LinkedList() {
		delete node;		
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

		if (index == 0) {
			Node* movedNode = this->node;
			this->node = new Node(data);
			this->node->next = movedNode;
			return;
		}

		int currentIndex = 0;
		Node* currentNode = this->node;

		while (currentIndex + 1 != index) {
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

	void remove(const int index) {
		validateIndex(index);

		if (index == 0) {
			deleteFirstNode();
			return;
		}

		auto currentNode = this->node;
		for (int i = 0; i + 1 != index; i++)
			currentNode = currentNode->next;

		deleteNextNode(currentNode);
	}

	void remove(Person* data) {
		if (this->node->data->equals(data)) {
			deleteFirstNode();
			return;
		}
			
		auto currentNode = this->node;
		while (currentNode->next != nullptr) {
			if (currentNode->next->data->equals(data)) {
				deleteNextNode(currentNode);
				return;
			}
				
			currentNode = currentNode->next;
		}
			
	}

	void remove(Person* data, bool (*lambda)(Person* object)) {
		if (lambda(this->node->data)) {
			deleteFirstNode();
			return;
		}
			
		auto currentNode = this->node;
		while (currentNode->next != nullptr) {
			if (lambda(currentNode->next->data)) {
				deleteNextNode(currentNode);
				return;
			}
			deleteNextNode(currentNode);
		}
	}

	void removeAll(Person* data) {
		while (this->contains(data))
			remove(data);
	}

	void removeAll(Person* data, bool (*lambda)(Person* object)) {
		while (this->contains(data, lambda))
			remove(data, lambda);
	}

	size_t const size() {
		return this->listSize;
	}

	string const toString() {
		stringstream stream;
		Node* currentNode = this->node;

		while (currentNode != nullptr) {
			stream << currentNode->data->toString() << "->";
			currentNode = currentNode->next;
		}

		stream << "null";
		return stream.str();
	}

	string const toString(string(*lambda)(Person* object)) {
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
