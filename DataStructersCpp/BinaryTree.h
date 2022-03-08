#pragma once

#include "Person.h"

class BinaryTree
{
private:
	struct Node {

		Person* value;
		Node* left;
		Node* right;

        Node() {
            this->value = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(Person* value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~Node() {
            if (this->left != nullptr) {
                delete this->left;
                this->left = nullptr;
            }
            if (this->right != nullptr) {
                delete this->right;
                this->right = nullptr;
            }
            delete this;
        }
	};

	Node* head;
	int size;
    stringstream outputStream;

public:
    void add(Person* value) {
        if (this->head == nullptr) {
            this->head = new Node(value);
            return;
        }

        if (contains(value))
            return;

        Node* currentNode = head;

        while (currentNode != nullptr) {
            if (currentNode->value->compareTo(value) > 0) {
                //вставляем влево
                if (currentNode->left == nullptr) {
                    currentNode->left = new Node(value);
                    return;
                }
                //идём дальше
                else        
                    currentNode = currentNode->left;
            }
            else {
                //вставляем вправо
                if (currentNode->right == nullptr) {
                    currentNode->right = new Node(value);
                    return;
                }
                //идём дальше
                else
                    currentNode = currentNode->right;
            }
        }
    }

    bool contains(Person* value) {
        Node* currentNode = this->head;

        while (currentNode != nullptr) {
            if (currentNode->value->compareTo(value) > 0)
                currentNode = currentNode->left;
            else if (currentNode->value->compareTo(value) < 0)
                currentNode = currentNode->right;
            else
                return true;
        }

        return false;
    }

    string toString() {
        if (head == nullptr)
            return "null";
    
        this->outputStream.flush();
        addNodeToOutputStream(head);

        return this->outputStream.str();
    }

    void addNodeToOutputStream(Node* node) {
        if (node->left != nullptr)
            addNodeToOutputStream(node->left);

        if (node->right != nullptr)
            addNodeToOutputStream(node->right);

        outputStream << node->value->toString() << endl;
    }

    void remove(Person* value) {

    }
};

