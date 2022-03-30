#pragma once

#include <sstream>
#include <string>

template<class T> class LinkedList {
private:
	/* @brief Контейнер для хранения данных*/
	struct Node {

		T data;
		Node* next;

		Node(T data);

		~Node();
	};

	/* @brief Указатель на первый контейнер */
	Node* node;
	size_t listSize;

	void increaseSize();

	void decreaseSize();

	/*
	* @brief Проверка является ли индекс валидным
	* @param index Индекс
	* @exception out_of_range
	*/
	void const validateIndex(const int index);

	void deleteFirstNode();

	void deleteNextNode(Node* currentNode);

public:
	LinkedList();

	~LinkedList();

	/*
	* @brief Добавляет элемент в конец списка
	* @param data Добовляемый объект
	*/
	void add(T data);

	/*
	* @brief Всталяет элемент на указанный индекс (нельзя добавить элмент в конец списка)
	* @param data Всталяемый объект
	* @param idnex Индекс
	*/
	void insert(T data, const int index);

	/*
	* @brief Проверяет есть ли элемет в списке. Для проверки вызывает метод equals у объекта
	* @param data Искомый объект
	* @return True если есть
	*/
	bool const contains(T data);

	/*
	* @brief Проверяет есть ли элемет в списке. Для проверки используется функция компоратор 
	* @param data Искомый объект
	* @param lambda Компоратор 
	* @return True если есть
	*/
	bool const contains(T data, bool (*lambda)(T& object1, T& object2));

	/*
	* @brief Удаляет элмент по индексу
	* @param index Индекс
	*/
	void remove(const int index);

	/*
	* @brief Удаляет искомый элмент в списке. Для поиска элемента вызывается метод equals
	* @param data Искомый объект
	*/
	void remove(T data);

	/*
	* @brief Удаляет искомый элемет в списке. Для поиска используется функция компоратор 
	* @param data Искомый объект
	* @param lambda Компоратор 
	*/
	void remove(T data, bool (*lambda)(T& object1, T& object2));

	/*
	* @brief Удаляет все искомые элементы в списке. Для поиска вызывается метод equals
	* @param data Искомый объект
	*/
	void removeAll(T data);

	/*
	* @brief Удаляет все искомые элементы. Для проверки используется функция компоратор 
	* @param data Искомый объект
	* @param lambda Компоратор 
	* @return True если есть
	*/
	void removeAll(T data, bool (*lambda)(T& object1, T& object2));

	/*
	* @return Размер списка
	*/
	size_t const size();

	/*
	* @brief Конвертирует список в строку. Для конвертации объектов используется метод toString
	* @return Строка вида {element1} -> {element2} -> ... -> null
	*/
	std::string const toString();

	/*
	* @brief Конвертирует список в строку
	* @param lambda Функция реализации преобразования объекта в строку
	* @return Строка заданного вида
	*/
	std::string const toString(std::string(*lambda)(T& object));
};