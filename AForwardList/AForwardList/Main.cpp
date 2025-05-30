#include <iostream>
#include "ForwardList.h"

int main() {
    ForwardList list;

    std::cout << "Lista vacia: " << list << std::endl << std::endl;
    std::cout << "Esta vacia? " << (list.IsEmpty() ? "Sí" : "No") << std::endl << std::endl;

    list.PushFront(10);
    list.PushFront(20);
    std::cout << "Despues de PushFront(), PushFront(): " << list << std::endl << std::endl;

    list.PushBack(30);
    list.PushBack(40);
    std::cout << "Despues de PushBack(), PushBack(): " << list << std::endl << std::endl;

    std::cout << "Primer elemento (Front): " << list.Front() << std::endl << std::endl;
    std::cout << "Ultimo elemento (Back): " << list.Back() << std::endl << std::endl;

    std::cout << "Tamano de la lista: " << list.Size() << std::endl << std::endl;

    list.Insert(25, 2);
    std::cout << "Despues de Insert(): " << list << std::endl << std::endl;

    list.Erase(20);
    std::cout << "Despues de Erase(): " << list << std::endl << std::endl;

    list.PushBackAverageNode();
    std::cout << "Despues de PushBackAverageNode(): " << list << std::endl << std::endl;

    list.PopFront();
    std::cout << "Despues de PopFront(): " << list << std::endl << std::endl;

    list.PopBack();
    std::cout << "Despues de PopBack(): " << list << std::endl << std::endl;

    ForwardList list2;
    list2.PushBack(10);
    list2.PushBack(25);
    list2.PushBack(30);
    std::cout << "Segunda lista: " << list2 << std::endl << std::endl;
    std::cout << "Las listas son iguales? " << (list == list2 ? "Sí" : "No") << std::endl << std::endl;

    ForwardList list3;
    list3.PushBack(1);
    list3.PushBack(2);
    ForwardList list4 = +list;
    std::cout << "Lista concatenada (list + [1 -> 2]): " << list4 << std::endl;

    return 0;
}
