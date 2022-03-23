package me.divium;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        //testLinkedList();
        var tree = new BinaryTree<Person>();
//        //left branch
//        tree.add(new Person(500,"Jeff"));
//        tree.add(new Person(400,"Bob"));
//        tree.add(new Person(450,"Mike"));
//        tree.add(new Person(300,"Mike"));
//        tree.add(new Person(425,"Dave"));
//        tree.add(new Person(475,"Josh"));
//        tree.add(new Person(350,"Josh"));
//        tree.add(new Person(200,"Josh"));
//        //right branch
//        tree.add(new Person(600,"Josh"));
//        tree.add(new Person(550,"Josh"));
//        tree.add(new Person(700,"Josh"));
//        tree.add(new Person(650,"Josh"));
//        tree.add(new Person(625,"Josh"));
//        tree.add(new Person(675,"Josh"));
//        tree.add(new Person(800,"Josh"));
//        tree.add(new Person(801,"Josh"));
//        tree.add(new Person(799,"Josh"));
        tree.add(new Person("Name 3", 26));
        tree.add(new Person("Name 4", 28));
        tree.add(new Person("Name 5", 16));
        tree.add(new Person("Name 6", 48));
        tree.add(new Person("Name 1", 32));
        tree.add(new Person("name 2", 19));
        tree.add(new Person("Name 8", 15));
        tree.add(new Person("Name 9", 30));
        tree.add(new Person("Name 10", 10));
//        tree.add(new Person(0,"Help"));
//        tree.add(new Person(3,"Richard"));
        System.out.println(tree);
        tree.remove(new Person(26, "d"));
        //System.out.println(tree);

        System.out.println();
        System.out.println();

        var treeSet = new TreeSet<Integer>();
        treeSet.add(26);
        treeSet.add(16);
        treeSet.add(15);
        treeSet.add(10);
        treeSet.add(19);
        treeSet.add(28);
        treeSet.add(25);
        treeSet.add(30);
        treeSet.add(48);
        treeSet.add(32);
        System.out.println(treeSet);
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
