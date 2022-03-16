package me.divium;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        //testLinkedList();
        var tree = new BinaryTree<Person>();
        //left branch
        tree.add(new Person(500,"Jeff"));
        tree.add(new Person(400,"Bob"));
        tree.add(new Person(450,"Mike"));
        tree.add(new Person(300,"Mike"));
        tree.add(new Person(425,"Dave"));
        tree.add(new Person(475,"Josh"));
        tree.add(new Person(350,"Josh"));
        tree.add(new Person(200,"Josh"));
        //right branch
        tree.add(new Person(600,"Josh"));
        tree.add(new Person(550,"Josh"));
        tree.add(new Person(700,"Josh"));
        tree.add(new Person(650,"Josh"));
        tree.add(new Person(625,"Josh"));
        tree.add(new Person(675,"Josh"));
        tree.add(new Person(800,"Josh"));
        tree.add(new Person(801,"Josh"));
        tree.add(new Person(799,"Josh"));
//        tree.add(new Person(0,"Help"));
//        tree.add(new Person(3,"Richard"));
        System.out.println(tree);
        tree.remove(new Person(700, "d"));
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
