#include "BinaryTree.h"

using namespace std;

template<class T> typename T::Node* TreeNode;

#pragma region Node
template<class T> BinaryTree<T>::Node::Node(T value) {
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

template<class T> BinaryTree<T>::Node::~Node() {
	if (this->left != nullptr) {
		delete this->left;
		this->left = nullptr;
	}

	if (this->right != nullptr) {
		delete this->right;
		this->right = nullptr;
	}
}
#pragma endregion Node

#pragma region Private
template<class T> typename BinaryTree<T>::Node* BinaryTree<T>::_getNode(T value) {
	Node* parent = _getParentNode(value);

	if (this->head->value.compareTo(value) == 0)
		return this->head;

	else if (parent == nullptr)
		return nullptr;

	return parent->left->value.compareTo(value) == 0 ? parent->left : parent->right;
}

template<class T> typename BinaryTree<T>::Node* BinaryTree<T>::_getParentNode(T value) {
	Node* current = this->head;
	Node* parent = nullptr;

	while (current != nullptr) {
		if (current->value.compareTo(value) > 0) {
			parent = current;
			current = current->left;
		}
		else if (current->value.compareTo(value) < 0) {
			parent = current;
			current = current->right;
		}
		else
			return parent;
	}

	return nullptr;
}

template<class T> typename BinaryTree<T>::Node* BinaryTree<T>::_findMin(Node* node) {
	Node* current = node;

	while (current->left != nullptr)
		current = current->left;


	return current;
}

template<class T> void BinaryTree<T>::_removeHead() {
	Node* node;

	if (this->head->right != nullptr) {
		node = _findMin(this->head->right);
		Node* parent = _getParentNode(node->value);

		if (this->head->left != node)
			node->left = this->head->left;

		if (this->head->right != node)
			node->right = this->head->right;

		if (parent->left == node)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
	else
		node = this->head->left;

	this->head = node;
}

template<class T> void BinaryTree<T>::_delete(T value) {
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

 template<class T> void BinaryTree<T>::_appendLeft(Node* node) {
    if (node != nullptr) {
        _appendLeft(node->left);
        outputStream << node->value.toString() << endl;
        if (node->right != nullptr) {
            _appendLeft(node->right);
        }
    }
}

template<class T> void BinaryTree<T>::_appendRight(Node* node) {
    if (node != nullptr) {
        _appendLeft(node->left);
        outputStream << node->value.toString() << endl;
        if (node->right != nullptr) {
            _appendLeft(node->right);
        }
    }
}
#pragma endregion Private

#pragma region Public
template<class T> BinaryTree<T>::BinaryTree() {
	this->head = nullptr;
	this->treeSize = 0;
}

template<class T> BinaryTree<T>::~BinaryTree() {
	if (this->head != nullptr)
		delete this->head;
}

template<class T> void BinaryTree<T>::add(T value) {
	if (this->head == nullptr) {
		this->head = new Node(value);
		return;
	}

	if (contains(value))
		return;

	Node* currentNode = head;
	treeSize++;

	while (currentNode != nullptr) {
		if (currentNode->value.compareTo(value) > 0) {
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

template<class T> bool BinaryTree<T>::contains(T value) {
	return _getNode(value) != nullptr;
}

template<class T> string BinaryTree<T>::toString() {
	if (head == nullptr)
		return "null";

	this->outputStream.str("");

	_appendLeft(this->head->left);
    outputStream << this->head->value.toString() << endl;
    _appendRight(this->head->right);

	return this->outputStream.str();
}

template<class T> void BinaryTree<T>::remove(T value) {
	_delete(value);
	treeSize--;
}

template<class T> int BinaryTree<T>::size() {
	return this->treeSize;
}
#pragma endregion Public

template<class T> ostream& operator<<(std::ostream& out, BinaryTree<T>& tree) {
	return out << tree.toString();
}
