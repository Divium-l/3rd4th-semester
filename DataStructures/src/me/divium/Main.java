package me.divium;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        //testLinkedList();
        var tree = new BinaryTree<Person>();
        tree.add(new Person(65,"Jeff"));
        tree.add(new Person(27,"Bob"));
        tree.add(new Person(21,"Mike"));
        tree.add(new Person(29,"Mike"));
        tree.add(new Person(30,"Dave"));
        tree.add(new Person(24,"Josh"));
//        tree.add(new Person(0,"Help"));
//        tree.add(new Person(3,"Richard"));
        System.out.println(tree);
        tree.remove(new Person(27, "d"));
        System.out.println(tree);
    }

    private static void testLinkedList() {
        var list = new LinkedList<Person>();
        list.insert(new Person(), 0);
        list.add(new Person(18, "Jhon"));
        list.add(new Person(56, "Jane"));
        list.add(new Person(20, "Dave"));
        list.add(new Person());
        list.add(new Person());
        list.add(new Person());
        System.out.println(list);
        list.remove(new Person());
        System.out.println(list);

        System.out.println("\n\n");

        List<Person> javaList= new ArrayList<>() {{add(new Person()); add(new Person());}};
        LinkedList<Person> myList= new LinkedList<>() {{add(new Person()); add(new Person());}};
        System.out.println(javaList);
        System.out.println(myList);
    }
}
