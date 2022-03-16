package me.divium;

/*
    + Создание дерева
    - Удаление элемента
    + Добавление элемента
    + Поиск
    + Вывод на экран
 */

import java.util.Comparator;

public class BinaryTree<T extends Comparable<T> & Comparator<T>> {

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
           return;
        }

        if (contains(value))
            return;

        Node currentNode = head;

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
        return _getNode(value, value::compare) != null;
    }

    /**
     * Поиск элемента в дереве
     * @param value Объект для сравнения
     * @param comparator Компаратор (для нахождения можно использовать 0 как true, и любое значение как false)
     * @return Boolean
     */
    public boolean contains(T value, Comparator<T> comparator) {
        return _getNode(value, comparator) != null;
    }

    public void remove(T value) {
        _delete(value, value::compare);
    }

    public void remove(T value, Comparator<T> comparator) {
        _delete(value, comparator);
    }

    public void _delete(T value, Comparator<T> comparator) {
        Node removableNode = _getNode(value, comparator);
        Node parent = _getParentNode(value, comparator);

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
            Node minParent = _getParentNode(min.value, value);
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

    private void _removeHead() {
        Node node;
        if (this.head.right != null) {
            node = _findMin(this.head.right);
            Node parent = _getParentNode(node.value, node.value::compare);
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
    private Node _getNode(T value, Comparator<T> comparator) {
        Node parent = _getParentNode(value, comparator);
        if (comparator.compare(this.head.value, value) == 0) {
            return this.head;
        }
        else if (parent == null)
            return null;
        return comparator.compare(parent.left.value, value) == 0 ? parent.left : parent.right;
    }

    /**
     * Ищет ноду, стоящую перед искомой
     * @param value Объект для сравнения
     * @return Ноду, совпадающая с объектом
     */
    private Node _getParentNode(T value, Comparator<T> comparator) {
        Node current = this.head;
        Node parent = null;

        while (current != null) {
            if (comparator.compare(current.value, value) > 0 ) {
                parent = current;
                current = current.left;
            }
            else if (comparator.compare(current.value, value) < 0) {
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
        if (node.left != null)
            _findMin(node.left);
        else
            return node;
        return node;
    }

    @Override
    public String toString() {
        if (head == null)
            return "null";

        builder.setLength(0);
        toStringRecursion(this.head);

        return builder.toString();
    }

    private final StringBuilder builder = new StringBuilder();

    private void toStringRecursion(Node node) {
        if (node.left != null)
            toStringRecursion(node.left);

        if (node.right != null)
            toStringRecursion(node.right);

        builder.append(node.value);
    }
}
