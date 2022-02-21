package me.divium;

/*
    + Создание списка
   +- Удаление элемента (Не работает удаление одинаквоых элементов, когда они стоят рядом)
    + Добавление/вставка элемента
    + Поиск по ключу
    + Вывод списка на экран
 */

public class LinkedList<T> {

    private Node node;
    private int size;

    private class Node {
        T data;
        Node next;

        public Node() {
            this.data = null;
            this.next = null;
        }

        public Node(T data) {
            this.data = data;
            this.next = null;
        }

        @Override
        public String toString() {
            return data.toString();
        }
    }

    public LinkedList() {
        this.node = new Node();
        this.size = 1;
    }

    public void add(T data) {
        var currentNode = this.node;

        //Первичное добавление элемента в список
        if (currentNode.data == null) {
            currentNode.data = data;
            return;
        }

        //Добавление элемента в конец списка
        //Поиск последней ноды
        while (currentNode.next != null)
            currentNode = currentNode.next;

        currentNode.next = new Node(data);
        increaseSize();
    }

    public void insert(T data, int index) {
        validateIndex(index);

        int currentIndex = 0;
        Node currentNode = this.node;

        while (currentIndex != index) {
            currentNode = currentNode.next;
            currentIndex++;
        }

        Node nextNode = currentNode.next;
        currentNode.next = new Node(data);
        currentNode.next.next = nextNode;
        size++;
    }

    public void delete(int index) {
        deleteByIndexRealization(index);
    }

    public void delete(T data) {
        deleteByObjectRealization(data, false);
    }

    @Deprecated
    public void deleteAll(T data) {
        deleteByObjectRealization(data, true);
    }

    public boolean contains(T data) {
        var currentNode = this.node;

        while (currentNode != null) {
            if (currentNode.data.equals(data))
                return true;
            currentNode = currentNode.next;
        }

        return false;
    }

    public int size() {
        return size;
    }

    @Override
    public String toString() {
        var builder = new StringBuilder();
        var currentNode = this.node;

        while (currentNode != null) {
            builder.append(currentNode.data.toString()).append(" -> ");
            currentNode = currentNode.next;
        }

        builder.append("null");
        return builder.toString();
    }

    private void increaseSize() {
        this.size++;
    }

//===============================================================================

    private void decreaseSize() {
        this.size--;
    }

    private void validateIndex(int index) {
        if (index < 0 || index > size - 1)
            throw new IllegalArgumentException("Index out of bounds");
    }

    private void deleteFirstNode() {
        this.node = this.node.next;
        decreaseSize();
    }

    private void deleteNextNode(Node currentNode) {
        var deleteNode = currentNode.next;
        currentNode.next = deleteNode.next;
        decreaseSize();
    }

    private void deleteByIndexRealization(int index) {
        validateIndex(index);

        if (index == 0) {
            deleteFirstNode();
            return;
        }

        var currentNode = this.node;
        int currentIndex = 0;

        while (currentIndex + 1 != index) {
            currentNode = currentNode.next;
            currentIndex++;
        }

        deleteNextNode(currentNode);
    }

    private void deleteByObjectRealization(T data, boolean all) {
        if (this.node.data.equals(data)) {
            deleteFirstNode();
        }

        var currentNode = this.node;

        while (currentNode.next != null) {
            if (currentNode.next.data.equals(data)) {
                deleteNextNode(currentNode);
                if (!all) return;
            }
            currentNode = currentNode.next;
        }
    }

}
