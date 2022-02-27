#include <iostream>
#include "LinkedList.cpp"
#include "Person.h"
#include <string>
#include <vector>
#include <functional>

/* TODO
*   # Перенести код логики с java
*       +  Создание списка
*       +  Удаление элемента
*       +  Удаление всех элементов
*       +  Добавление и вставка элементов
*       +  Поиск по ключу
*       +  Вывод списка на экран
* 
*   # Добавить костыли для C++
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

using namespace std;

int main()
{
    auto p1 = new Person();
    auto p2 = new Person("Bob", 19);
    
    auto linkedList = new LinkedList<Person>();
    linkedList->add(p1);
    linkedList->add(p2);
    cout << linkedList->toString() << endl;
    cout << linkedList->toString([](Person* p) -> string {return p->name; }) << endl;
    cout << linkedList->contains(new Person("Bob", 19)) << endl;
    cout << linkedList->contains(new Person("Bob", 18)) << endl;
    linkedList->insert(new Person("Jane", 21), 1);
    linkedList->insert(new Person(), 0);
    linkedList->add(new Person());
    cout << "=================================\n";
    cout << linkedList->toString() << endl;
    linkedList->removeAll(new Person());
    cout << linkedList->toString() << endl;
    cout << "=================================\n";

    delete linkedList;
    delete p1, p2;

    auto a = new LinkedList<double>();
    a->add(new double(5));
    cout << a->contains(new double(4), [](auto a, auto b) {return *a == *b; }); //0
    cout << a->contains(new double(5), [](auto a, auto b) {return *a == *b; }); //1
    delete a;
}
