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

    /**
     * Всталяет объект в конец списка
     * @param data Объект
     */
    public void add(T data) {
        var currentNode = this.node;

        //Первичное добавление элемента в список
        if (currentNode.data == null) {
            currentNode.data = data;
            return;
        }

        //Добавление элемента в конец списка
        while (currentNode.next != null)
            currentNode = currentNode.next;

        currentNode.next = new Node(data);
        increaseSize();
    }

    /**
     * Вставляет объект на указываемый индекс. Нельзя вставить в конец списка
     * @param data Вставляемый объект
     * @param index Индекс
     */
    public void insert(T data, int index) {
        validateIndex(index);

        //Вставка в если в списке ничего нет
        if (this.node.data == null) {
            add(data);
            return;
        }

        //Вставка в начало списка
        if (index == 0) {
            Node movedNode = this.node;
            this.node = new Node(data);
            this.node.next = movedNode;
            return;
        }

        Node currentNode = this.node;
        for (int i = 0; i + 1 != index; i++)
            currentNode = currentNode.next;

        Node nextNode = currentNode.next;
        currentNode.next = new Node(data);
        currentNode.next.next = nextNode;
        increaseSize();
    }

    public void remove(int index) {
        removeByIndex(index);
    }

    public void remove(T data) {
        removeByObject(data);
    }

    public void removeAll(T data) {
        while (this.contains(data))
            remove(data);
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

//===============================================================================

    private void increaseSize() {
        this.size++;
    }

    private void decreaseSize() {
        this.size--;
    }

    private void validateIndex(int index) {
        if (index < 0 || index > size - 1)
            throw new IllegalArgumentException("Index out of bounds");
    }

    private void removeFirstNode() {
        this.node = this.node.next;
        decreaseSize();
    }

    private void removeNextNode(Node currentNode) {
        var deleteNode = currentNode.next;
        currentNode.next = deleteNode.next;
        decreaseSize();
    }

    private void removeByIndex(int index) {
        validateIndex(index);

        if (index == 0) {
            removeFirstNode();
            return;
        }

        var currentNode = this.node;
        int currentIndex = 0;

        while (currentIndex + 1 != index) {
            currentNode = currentNode.next;
            currentIndex++;
        }

        removeNextNode(currentNode);
    }

    private void removeByObject(T data) {
        if (this.node.data.equals(data)) {
            removeFirstNode();
            return;
        }

        var currentNode = this.node;
        while (currentNode.next != null) {
            if (currentNode.next.data.equals(data)) {
                removeNextNode(currentNode);
                return;
            }
            currentNode = currentNode.next;
        }
    }

}
