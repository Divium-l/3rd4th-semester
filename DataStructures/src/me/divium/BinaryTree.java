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

    public void delete(T value) {
        Node node = _getNode(value, value);
        Node parent = _getParentNode(value, value);

        if (node == null)
            return;

        if (parent == null) {
            _removeHead();
            return;
        }

        if (node.left == null && node.right == null) {
            if (parent.left == node)
                parent.left = null;
            else
                parent.right = null;
        }
        else if (node.right == null) {
            if (parent.left == node)
                parent.left = node.left;
            else
                parent.right = node.left;
        }
        else if (node.left == null) {
            if (parent.left == node)
                parent.left = node.right;
            else
                parent.right = node.right;
        }
        else {
            //удаление если есть и левый и правый
            return;
        }
    }

    private void _removeHead() {
        //не реализовано
        System.out.println("removing head");
    }

    /**
     * Ищет ноду
     * @param value Объект для сравнения
     * @return Ноду, совпадающая с объектом
     */
    private Node _getNode(T value, Comparator<T> comparator) {
        Node parent = _getParentNode(value, comparator);
        if (parent == null)
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
            node = _findMin(node.left);

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
