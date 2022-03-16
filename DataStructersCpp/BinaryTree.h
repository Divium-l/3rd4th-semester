#pragma once

#include "Person.h"

typedef Person T;

class BinaryTree {
private:
	struct Node {

		T* value;
		Node* left;
		Node* right;

        Node() {
            this->value = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(T* value) {
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

    Node* _getNode(T* value) {
        Node* parent = _getParentNode(value);
        if (this->head->value->compareTo(value) == 0)
            return this->head;
    
        else if (parent == nullptr)
            return nullptr;

        return parent->left->value->compareTo(value) == 0 ? parent->left : parent->right;
    }

    Node* _getParentNode(T* value) {
        Node* current = this->head;
        Node* parent = nullptr;

        while (current != nullptr) {
            if (current->value->compareTo(value) > 0 ) {
                parent = current;
                current = current->left;
            }
            else if (current->value->compareTo(value) < 0) {
                parent = current;
                current = current->right;
            }
            else
                return parent;
        }

        return nullptr;
    }

    Node* _findMin(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void _removeHead() {
        Node* node;
        if (this->head->right != nullptr) {
            node = _findMin(this->head->right);
            Node* parent = _getParentNode(node->value);
            node->left = this->head->left;
            node->right = this->head->right;

            if (parent->left == node)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        else {
            node = this->head->left;
        }
        this->head = node;
    }

    void _delete(T* value) {
        Node* removableNode = _getNode(value);
        Node* parent = _getParentNode(value);

        if (removableNode == nullptr)
            return;

        if (parent == nullptr) {
            _removeHead();
            return;
        }

        if (removableNode->left == nullptr && removableNode->right == nullptr) {
            if (parent->left == removableNode)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        else if (removableNode->right == nullptr) {
            if (parent->left == removableNode)
                parent->left = removableNode->left;
            else
                parent->right = removableNode->left;
        }
        else if (removableNode->left == nullptr) {
            if (parent->left == removableNode)
                parent->left = removableNode->right;
            else
                parent->right = removableNode->right;
        }
        else {
            //удаление если есть и левый и правый
            Node* min = _findMin(removableNode->right);
            Node* minParent = _getParentNode(min->value);
            minParent->left = nullptr;

            if (parent->left == removableNode) {
                min->left = removableNode->left;
                min->right = removableNode->right;
                parent->left = min;
            }
            else {
                min->left = removableNode->left;
                min->right = removableNode->right;
                parent->right = min;
            }
        }
    }

public:
    void add(T* value) {
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

    bool contains(T* value) {
        return _getNode(value) != nullptr;
    }

    string toString() {
        if (head == nullptr)
            return "null";
    
        this->outputStream.flush();
        addNodeToOutputStream(head);

        return this->outputStream.str();
    }

    void remove(T* value) {
        _delete(value);
    }

    void addNodeToOutputStream(Node* node) {
        if (node->left != nullptr)
            addNodeToOutputStream(node->left);

        if (node->right != nullptr)
            addNodeToOutputStream(node->right);

        outputStream << node->value->toString() << endl;
    }

};


