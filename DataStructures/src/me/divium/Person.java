package me.divium;

public class Person implements Comparable {
    private static int count = -1;
    public int id;
    public int age;
    public String name;

    public Person() {
        incrementCount();
        this.id = count;
        this.age = 0;
        this.name = "UNSIGNED";
    }

    public Person(int age, String name) {
        incrementCount();
        this.id = count;
        this.age = age;
        this.name = name;
    }

    @Override
    public String toString() {
        return String.format("{id: %d, name: %s, age: %d}", id, name, age);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Person))
            return false;

        Person person = (Person) obj;
        return person.name.equals(this.name) && person.age == this.age;
    }

    private void incrementCount() {
        this.count++;
    }

    @Override
    public int compareTo(Object o) {
        return this.age - ((Person) o).age;
    }
}
