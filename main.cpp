#include "lib.h"
#include "Entites/LinkedList/linkedList.h"
#include "Entites/DoubleLinedList/doubleLinkedList.h"

void insertValueTest()
{
    LinkedList list;
    Item<int> item1(10);
    list.insertValue(item1);
    if (!list.isEmpty()) { cout << "Test 1: Insert Value: passed" << endl; }
    else { cout << "Test 1: Insert Value: not passed" << endl; }
}

void deleteValueTest()
{
    LinkedList list;
    Item<int> item1(10);
    list.insertValue(item1);
    bool deleted = list.deleteValue(&item1);
    if (deleted && list.isEmpty()) { cout << "Test 2: Delete Value: passed" << endl; }
    else { cout << "Test 2: Delete Value: not passed" << endl; }
}

void clearListTest()
{
    LinkedList list;
    Item<int> item1(10);
    Item<int> item2(20);
    list.insertValue(item1);
    list.insertValue(item2);
    list.clear();
    if (list.isEmpty()) { cout << "Test 3: Clear List: passed" << endl; }
    else { cout << "Test 3: Clear List: not passed" << endl; }
}

void isEmptyTest()
{
    LinkedList list;
    if (list.isEmpty()) { cout << "Test 4: Is Empty: passed" << endl; }
    else { cout << "Test 4: Is Empty: not passed" << endl; }
}

void linkedListTest()
{
    insertValueTest();
    deleteValueTest();
    clearListTest();
    isEmptyTest();
}

void insertValueDoubleLinkedListTest()
{
    DoubleLinkedList dList;
    Item<int> item1(10);
    dList.insertValue(item1);
    if (!dList.isEmpty()) { cout << "Test 1: Insert Value: passed" << endl; }
    else { cout << "Test 1: Insert Value: not passed" << endl; }
}

void deleteValueDoubleLinkedListTest()
{
    DoubleLinkedList dList;
    Item<int> item1(10);
    dList.insertValue(item1);
    bool deleted = dList.deleteValue(&item1);
    if (deleted && dList.isEmpty()) { cout << "Test 2: Delete Value: passed" << endl; }
    else { cout << "Test 2: Delete Value: not passed" << endl; }
}

void clearDoubleLinkedListTest()
{
    DoubleLinkedList dList;
    Item<int> item1(10);
    Item<int> item2(20);
    dList.insertValue(item1);
    dList.insertValue(item2);
    dList.clear();
    if (dList.isEmpty()) { cout << "Test 3: Clear: passed" << endl; }
    else { cout << "Test 3: Clear: not passed" << endl; }
}

void isEmptyDoubleLinkedListTest()
{
    DoubleLinkedList dList;
    if (dList.isEmpty()) { cout << "Test 4: Is Empty: passed" << endl; }
    else { cout << "Test 4: Is Empty: not passed" << endl; }
}

void doubleLinkedListTest()
{
    insertValueDoubleLinkedListTest();
    deleteValueDoubleLinkedListTest();
    clearDoubleLinkedListTest();
    isEmptyDoubleLinkedListTest();
}

int main()
{
    linkedListTest(); cout << endl << endl << endl << endl << endl;
    doubleLinkedListTest(); cout << endl << endl << endl << endl << endl;

    return 0;
}