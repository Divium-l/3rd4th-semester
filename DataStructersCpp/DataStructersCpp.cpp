#include <iostream>
#include "LinkedList.cpp"
#include "BinaryTree.cpp"
#include "Person.h"

using namespace std;

/* TODO
*   # Перенести код логики с java
*       +  Создание списка
*       +  Удаление элемента
*       +  Удаление всех элементов
*       +  Добавление и вставка элементов
*       +  Поиск по ключу
*       +  Вывод списка на экран
* 
*   # Добавить функции для C++
*       +  Деструкторы
*       +  Кастомный поиск через лямбды
*       +  Кастомный вывод объекта через лямбды
*       +  Кастомный поиск для удаления объекта через лямбды
*       +  Шаблонизация класса
*
*   # Оформление
*       +  Разбить классы на .h и cpp
*       -  Сделать меню
*       -  Сделать демонстрацию линкед листа на примере объекта
*          из прошлой курсовой работы
*/


void linkedListDemonstration();

void treeDemonstration();

void treeAdd(BinaryTree<Person>& tree, Person& root, Person& p1, Person& p2);

void treeContains(BinaryTree<Person>& tree, Person& p1, Person& p3);

void treeRemove(BinaryTree<Person>& tree, Person& root, Person& p1, Person& p2);

void pressEnterToContinue();

const string SEPARATOR = "===================================";

int main()
{
    linkedListDemonstration();
    cout << endl << endl;
    treeDemonstration();
}

void linkedListDemonstration() {
    auto p1 = Person();
    auto p2 = Person("Bob", 19);

    auto linkedList = LinkedList<Person>();

    linkedList.add(p1);
    linkedList.add(p2);

    cout << linkedList.toString() << endl;
    cout << linkedList.toString([](Person& p) -> string {return p.name; }) << endl;
    cout << linkedList.contains(Person("Bob", 19)) << endl; 
    cout << linkedList.contains(Person("Bob", 18)) << endl; 

    linkedList.insert(Person("Jane", 21), 1);
    linkedList.insert(Person(), 0);
    linkedList.add(Person());

    cout << SEPARATOR << endl;
    cout << linkedList.toString() << endl;

    linkedList.removeAll(Person());

    cout << linkedList.toString() << endl;
    cout << SEPARATOR << endl;
}

void treeDemonstration() {
    BinaryTree tree = BinaryTree<Person>();
    cout << "Adding 10 elements to the tree" << endl;
    
    Person p1 = Person("Name 1", 32);
    Person p2 = Person("Name 2", 19);
    Person p3 = Person("Name 11", 105);
    Person root = Person("Name 3", 26);

    treeAdd(tree, root, p1, p2);

    cout << tree.toString() << SEPARATOR << endl;
    pressEnterToContinue();

    treeContains(tree, p1, p3);
    pressEnterToContinue();

    cout << "Removing this elements: " << p1.toString() << p2.toString() << root.toString() << " from the tree" << endl;
    treeRemove(tree, root, p1, p2);
    cout << tree.toString() << SEPARATOR << endl;
    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << "Press enter to continue...";
    cin.get();
    cout << endl;
}

void treeAdd(BinaryTree<Person>& tree, Person& root, Person& p1, Person& p2) {
    tree.add(root);
    tree.add(Person("Name 4", 28));
    tree.add(Person("Name 5", 16));
    tree.add(Person("Name 6", 48));
    tree.add(p1);
    tree.add(p2);
    tree.add(Person("Name 7", 25));
    tree.add(Person("Name 8", 15));
    tree.add(Person("Name 9", 30));
    tree.add(Person("Name 10", 10));
}

void treeContains(BinaryTree<Person>& tree, Person& p1, Person& p3) {
    cout << "Checking if element " << p1.toString() << " is in the tree" << endl;
    string response = tree.contains(p1) ? "true" : "false";
    cout << response << endl;

    cout << "Checking if element " << p3.toString() << " is in the tree" << endl;
    response = tree.contains(p3) ? "true" : "false";
    cout << response << endl;
}

void treeRemove(BinaryTree<Person>& tree, Person& root, Person& p1, Person& p2) {
    tree.remove(root);
    tree.remove(p1);
    tree.remove(p2);
}