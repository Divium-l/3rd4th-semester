package me.divium;

/*
    + Создание дерева
    - Удаление элемента
    + Добавление элемента
    + Поиск
    + Вывод на экран
 */

import java.util.Comparator;

public class BinaryTree<T extends Comparable<T>> {

    private class Node {
        public Node left;
        public Node right;
        public T value;

        Node(T value) {
            this.value = value;
            left = null;
            right = null;
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    private Node head;
    private int size;

    /**
     * Добавление элемента в дерево
     * @param value Добовляемый элемент
     */
    public void add(T value) {
        if (this.head == null) {
           this.head = new Node(value);
           size++;
           return;
        }

        if (contains(value))
            return;

        Node currentNode = head;
        size++;

        while (currentNode != null) {
            if (currentNode.value.compareTo(value) > 0) {
                if (currentNode.left == null) {
                    currentNode.left = new Node(value);
                    return;
                }
                else
                    //идём дальше
                    currentNode = currentNode.left;
            }
            else {
                if (currentNode.right == null) {
                    currentNode.right = new Node(value);
                    return;
                }
                else
                    //идём дальше
                    currentNode = currentNode.right;
            }
        }
    }

    /**
     * Поиск элемента в дереве
     * @param value Объект для сравнения
     * @return Boolean
     */
    public boolean contains(T value) {
        return _getNode(value) != null;
    }

    /**
     * Удаление элемента дерева
     * @param value Удаляемый элемент
     */
    public void remove(T value) {
        size--;
        _delete(value);
    }

    /**
     * Возвращает размер дерева
     * @return Размер дерева
     */
    public int size() {
        return this.size;
    }

    /**
     * Реализация удаления элемента
     * @param value Удаляемый элемент
     */
    private void _delete(T value) {
        Node removableNode = _getNode(value);
        Node parent = _getParentNode(value);

        if (removableNode == null)
            return;

        if (parent == null) {
            _removeHead();
            return;
        }

        if (removableNode.left == null && removableNode.right == null) {
            if (parent.left == removableNode)
                parent.left = null;
            else
                parent.right = null;
        }
        else if (removableNode.right == null) {
            if (parent.left == removableNode)
                parent.left = removableNode.left;
            else
                parent.right = removableNode.left;
        }
        else if (removableNode.left == null) {
            if (parent.left == removableNode)
                parent.left = removableNode.right;
            else
                parent.right = removableNode.right;
        }
        else {
            //удаление если есть и левый и правый
            Node min = _findMin(removableNode.right);
            Node minParent = _getParentNode(min.value);
            minParent.left = null;

            if (parent.left == removableNode) {
                min.left = removableNode.left;
                min.right = removableNode.right;
                parent.left = min;
            }
            else {
                min.left = removableNode.left;
                min.right = removableNode.right;
                parent.right = min;
            }
        }
    }

    /**
     * Удаление корня дерева
     */
    private void _removeHead() {
        Node node;
        if (this.head.right != null) {
            node = _findMin(this.head.right);
            Node parent = _getParentNode(node.value);
            node.left = this.head.left;
            node.right = this.head.right;

            if (parent.left == node)
                parent.left = null;
            else
                parent.right = null;
        }
        else {
            node = this.head.left;
        }
        this.head = node;
    }

    /**
     * Ищет ноду
     * @param value Объект для сравнения
     * @return Ноду, совпадающая с объектом
     */
    private Node _getNode(T value) {
        Node parent = _getParentNode(value);
        if (this.head.value.compareTo(value) == 0) {
            return this.head;
        }
        else if (parent == null)
            return null;
        return parent.left.value.compareTo(value) == 0? parent.left : parent.right;
    }

    /**
     * Ищет ноду, стоящую перед искомой
     * @param value Объект для сравнения
     * @return Ноду, совпадающая с объектом
     */
    private Node _getParentNode(T value) {
        Node current = this.head;
        Node parent = null;

        while (current != null) {
            if (current.value.compareTo(value) > 0 ) {
                parent = current;
                current = current.left;
            }
            else if (current.value.compareTo(value) < 0) {
                parent = current;
                current = current.right;
            }
            else
                return parent;
        }
        return null;
    }

    /**
     * Идёт налево пока не достигнет null
     * @param node Откуда искать минимальное значение
     * @return Нода с минимальным значением
     */
    private Node _findMin(Node node) {
        Node current = node;
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    @Override
    public String toString() {
        if (head == null)
            return "null";

        builder.setLength(0);
        _toStringRecursion(this.head);

        return builder.toString();
    }

    private final StringBuilder builder = new StringBuilder();

    private void _toStringRecursion(Node node) {
        if (node.left != null)
            _toStringRecursion(node.left);

        if (node.right != null)
            _toStringRecursion(node.right);

        builder.append(node.value);
    }
}
