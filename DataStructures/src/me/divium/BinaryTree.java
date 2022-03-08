package me.divium;

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

    private void addToNode(T value, Node node) {

    }

    //не проверялось
    @Deprecated
    private boolean inOrder(Node node, T value) {
        if (node.left != null) {
            if (node.value.compareTo(value) == 0)
                return true;
            inOrder(node.left, value);
        }
        else if (node.right != null) {
            if (node.value.compareTo(value) == 0)
                return true;
            inOrder(node.right, value);
        }

        return false;
    }

    //работает
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

    //работает
    public boolean contains(T value) {
        Node currentNode = this.head;
        while (currentNode != null) {
            if (currentNode.value.compareTo(value) > 0 )
                currentNode = currentNode.left;
            else if (currentNode.value.compareTo(value) < 0)
                currentNode = currentNode.right;
            else
                return true;
        }
        return false;
    }

    private StringBuilder builder = new StringBuilder();

    @Override
    public String toString() {
        toStringRecursion(this.head);

        return builder.toString();
    }

    private void toStringRecursion(Node node) {
        builder.append(node.toString()).append("\n");
        if (node.left != null) {
            toStringRecursion(node.left);
        }
        if (node.right != null) {
            toStringRecursion(node.right);
        }
    }

    public String ToString() {
        if (head == null)
            return "null";

        Node currentNode = head;
        nodeToString(head);
        return builder.toString();
    }

    public void nodeToString(Node node) {
        if (node.left != null)
            nodeToString(node.left);

        if (node.right != null)
            nodeToString(node.right);

        builder.append(node.value);
    }
}
