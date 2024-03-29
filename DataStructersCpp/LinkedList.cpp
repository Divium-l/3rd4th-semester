﻿#pragma once

#include "LinkedList.h"

using namespace std;

#pragma region Node constructors and destructors
template<class T> LinkedList<T>::Node::Node(T data) {
	this->data = data;
	this->next = nullptr;
}

template<class T> LinkedList<T>::Node::~Node() {
	if (next != nullptr)
		delete next;
}
#pragma endregion

#pragma region Linked List Private Methods
template<class T> void LinkedList<T>::increaseSize() {
	listSize++;
}

template<class T> void LinkedList<T>::decreaseSize() {
	listSize--;
}

template<class T> void const LinkedList<T>::validateIndex(const int index) {
	if (index < 0 || index > listSize)
		throw new out_of_range("Index out of bounds");
}

template<class T> void LinkedList<T>::deleteFirstNode() {
	//сохраняем указатель на 2-ую ноду
	auto secondNode = this->node->next;

	//удаляем первую ноду, присваиваем нулевой указатель чтобы не запустилась цепная реакция
	this->node->next = nullptr;
	delete this->node;

	//делаем вторую ноду первой
	this->node = secondNode;
	decreaseSize();
}

template<class T> void LinkedList<T>::deleteNextNode(Node* currentNode) {
	//пропускаем ноду которую надо удалить
	auto deleteNode = currentNode->next;
	currentNode->next = deleteNode->next;

	//теперь удаляем её
	deleteNode->next = nullptr;
	delete deleteNode;
	decreaseSize();
}
#pragma endregion

#pragma region Linked List Constructors and destructors
template<class T> LinkedList<T>::LinkedList() {
	this->node = nullptr;
	this->listSize = 0;
}

template<class T> LinkedList<T>::~LinkedList() {
	delete node;
}
#pragma endregion

#pragma region Linked List Public Methods
template<class T> void LinkedList<T>::add(T data) {
	//Первичное добавление элемента в список
	if (this->node == nullptr) {
		this->node = new Node(data);
		return;
	}

	Node* currentNode = this->node;

	//Добавление элемента в конец списка
	//Поиск последней ноды
	while (currentNode->next != nullptr)
		currentNode = currentNode->next;

	currentNode->next = new Node(data);
	increaseSize();
}

template<class T> void LinkedList<T>::insert(T data, const int index) {
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

template<class T> void LinkedList<T>::insert(T data, T after) {
	Node* currentNode = this->node;

	while (currentNode != nullptr && currentNode->data.equals(after))
		currentNode = currentNode->next;

	Node* nextNode = currentNode->next;
	currentNode->next = new Node(data);
	currentNode->next->next = nextNode;
	increaseSize();
}

template<class T> bool const LinkedList<T>::contains(T data) {
	Node* currentNode = this->node;

	while (currentNode != nullptr) {
		if (currentNode->data.equals(data))
			return true;

		currentNode = currentNode->next;
	}

	return false;
}

template<class T> bool const LinkedList<T>::contains(T data, bool (*lambda)(T& object1, T& object2)) {
	Node* currentNode = this->node;

	while (currentNode != nullptr) {
		if (lambda(currentNode->data, data))
			return true;

		currentNode = currentNode->next;
	}

	return false;
}

template<class T> void LinkedList<T>::remove(const int index) {
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

template<class T> void LinkedList<T>::remove(T data) {
	if (this->node == nullptr)
		return;

	if (this->node->data.equals(data)) {
		deleteFirstNode();
		return;
	}

	auto currentNode = this->node;
	while (currentNode->next != nullptr) {
		if (currentNode->next->data.equals(data)) {
			deleteNextNode(currentNode);
			return;
		}

		currentNode = currentNode->next;
	}

}

template<class T> void LinkedList<T>::remove(T data, bool (*lambda)(T& object1, T& object2)) {
	if (this->node == nullptr)
		return;

	if (lambda(this->node->data, data)) {
		deleteFirstNode();
		return;
	}

	auto currentNode = this->node;
	while (currentNode->next != nullptr) {
		if (lambda(currentNode->next->data, data)) {
			deleteNextNode(currentNode);
			return;
		}
		deleteNextNode(currentNode);
	}
}

template<class T> void LinkedList<T>::removeAll(T data) {
	while (this->contains(data))
		remove(data);
}

template<class T> void LinkedList<T>::removeAll(T data, bool (*lambda)(T& object1, T& object2)) {
	while (this->contains(data, lambda))
		remove(data, lambda);
}

template<class T> size_t const LinkedList<T>::size() {
	return this->listSize;
}

template<class T> string const LinkedList<T>::toString() {
	stringstream stream;
	Node* currentNode = this->node;

	while (currentNode != nullptr) {
		stream << currentNode->data.toString() << "->";
		currentNode = currentNode->next;
	}

	stream << "null";
	return stream.str();
}

template<class T> string const LinkedList<T>::toString(string(*lambda)(T& object)) {
	stringstream stream;
	Node* currentNode = this->node;

	while (currentNode != nullptr) {
		stream << lambda(currentNode->data) << "->";
		currentNode = currentNode->next;
	}

	stream << "null";
	return stream.str();
}
#pragma endregion