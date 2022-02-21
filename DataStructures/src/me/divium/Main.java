package me.divium;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        var list = new LinkedList<Person>();
        list.add(new Person());
        list.add(new Person(18, "Jhon"));
        list.insert(new Person(20, "Dave"), 1);
        list.add(new Person(56, "Jane"));
        list.delete(0);
        list.delete(new Person(20, "Dave"));
        list.delete(new Person());

        System.out.println(list.toString());
        System.out.println(list.contains(new Person(18, "Jhon")));
        System.out.println(list.size());

        List<Person> javaList= new ArrayList<>() {{add(new Person()); add(new Person());}};
        LinkedList<Person> myList= new LinkedList<>() {{add(new Person()); add(new Person());}};
        System.out.println(javaList.toString());
        System.out.println(myList.toString());
    }
}
