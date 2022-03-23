#pragma once

#include <sstream>

template<class T> class BinaryTree {
private:    
	struct Node {
		T value;
		Node* left;
		Node* right;

        Node(T value);

        ~Node();
	};

	Node* head;
	int treeSize;
    std::stringstream outputStream;

    Node* _getNode(T value);

    Node* _getParentNode(T value);

    Node* _findMin(Node* node);

    void _removeHead();

    void _delete(T value);

    void _addNodeToOutputStream(Node* node);

public:
    BinaryTree();

    ~BinaryTree();

    /*
    * @brief Добавление элемента в дерево
    * @param value Добовляемый элемент
    */
    void add(T value);

    /*
    * @brief Проверка, есть ли элемент в дереве
    * @param value Искомый элемент
    */
    bool contains(T value);

    /*
    * @brief Преобразование дерева с строку
    */
    std::string toString();

    /*
    * @brief Удаление элемента из дерева
    * @param value Удаляемый элемент
    */
    void remove(T value);

    /*
    * @brief Возвращает размер дерева
    */
    int size();
};