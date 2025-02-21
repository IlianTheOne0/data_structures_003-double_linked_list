#include <iostream>
#include <string>
#include "UseCases/structUseCases.h"

using std::cout;
using std::endl;
using std::string;

void insertInHeadTest()
{
    DoubleLinkedListUseCases<int> list1(0);
    list1.insertInHead(1);
    if (list1.getHead()->_data == 1 && list1.getTail()->_data == 0) { cout << "Test 1: Insert in Head : passed" << endl; }
    else { cout << "Test 1: Insert in Head: not passed" << endl; }
}

void insertInTailTest()
{
    DoubleLinkedListUseCases<int> list2(0);
    list2.insertInTail(1);
    if (list2.getHead()->_data == 0 && list2.getTail()->_data == 1) { cout << "Test 2: Insert in Tail: passed" << endl; }
    else { cout << "Test 2: Insert in Tail: not passed" << endl; }
}

void deleteHeadTest()
{
    DoubleLinkedListUseCases<int> list3(0);
    list3.insertInHead(1);
    int deletedHead = list3.deleteHead();
    if (deletedHead == 1 && list3.getHead()->_data == 0) { cout << "Test 3: Delete Head: passed" << endl; }
    else { cout << "Test 3: Delete Head: not passed" << endl; }
}

void deleteTailTest()
{
    DoubleLinkedListUseCases<int> list4(0);
    list4.insertInTail(1);
    int deletedTail = list4.deleteTail();
    if (deletedTail == 1 && list4.getTail()->_data == 0) { cout << "Test 4: Delete Tail: passed" << endl; }
    else { cout << "Test 4: Delete Tail: not passed" << endl; }
}

void clearListTest()
{
    DoubleLinkedListUseCases<int> list5(0);
    list5.insertInHead(1);
    list5.insertInTail(2);
    list5.clear();
    if (list5.isEmpty()) { cout << "Test 5: Clear List: passed" << endl; }
    else { cout << "Test 5: Clear List: not passed" << endl; }
}

int main() {
    insertInHeadTest();
    insertInTailTest();
    deleteHeadTest();
    deleteTailTest();
    clearListTest();

    return 0;
}