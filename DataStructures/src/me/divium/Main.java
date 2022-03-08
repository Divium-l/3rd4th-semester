package me.divium;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
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
