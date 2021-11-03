//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <vector>
#include "PrecondViolatedExcept.h"

using namespace std;


LinkedList<string>* convertToList(vector<string> data)
{
  LinkedList<string>* ptr = new LinkedList<string>();
  for (int i=0; i<data.size(); i++) {
    if (!ptr->insert(i+1, data[i])) {
      cout << "Cannot insert " << data[i] << " at position " << (i + 1)
           << endl;
    }
  }
  return ptr;
}


void print(const string& str) {
  cout << "\n---------------------------------\n";
  cout << str;
  cout << "\n---------------------------------\n";
}


int main()
{

  vector<string> weekdays = {"Mon", "Tue", "Wed", "thu", "Fri"};
  vector<string> weekend = {"Sat", "sun"};

  print("Test replace");
  LinkedList<string>* listPtr1 = convertToList(weekdays);
  cout << "List 1: " << *listPtr1 << endl;;
  cout << "Replace `thu` with `Thu`\n";
  try {
    string replaced1 = listPtr1->replace(4, "Thu");
    cout << "The replaced item: " << replaced1 << endl;
  }
  catch (PrecondViolatedExcept except) {
    cout << "Failed to replace position 4\n";
  }
  cout << "List 1: " << *listPtr1 << endl;
  int pos = listPtr1->getLength()+2;
  cout << "\nTest list1's replace at position getLength()+2 = " << pos << endl;
  try {
    string replaced = listPtr1->replace(pos, "Test");
    cout << "The replaced item: " << replaced << endl;
  }
  catch (PrecondViolatedExcept except) {
    cout << "Caught an exception replacing list1 at position " << pos << endl;
  }

  LinkedList<string>* listPtr2 = convertToList(weekend);
  cout << "\nList 2: " << *listPtr2 << endl;
  cout << "Replace `sun` with `Sun`\n";
  string replaced2 = listPtr2->replace(listPtr2->getLength(), "Sun");
  cout << "The replaced item: " << replaced2 << endl;
  cout << "List 2: " << *listPtr2 << endl;


  print("Test copy constructor");
  cout << "Create list 3 as a copy of list 2 \n";
  LinkedList<string> list3 = *listPtr2; 
  cout << "List 3: " << list3 << endl;
  cout << "Add `Mon` to end of list 3\n";
  listPtr2->insert(listPtr2->getLength() + 1, "Mon");
  cout << "List 2: " << *listPtr2 << endl;
  cout << "List 3: " << list3 << endl;

  cout << "Clear list 2 \n";
  listPtr2->clear();
  cout << "List 2: " << *listPtr2 << endl;
  cout << "List 3: " << list3 << endl;

  print("Test operator+");
  cout << "Assign list4 = list3 + list1 + list3\n";
  LinkedList<string> list4 = list3 + *listPtr1 + list3;
  cout << "List 4: " << list4 << endl;
  cout << "Remove the first node\n";
  list4.remove(1);
  cout << "List 4: " << list4 << endl;
  cout << "Remove the last node\n";
  list4.remove(list4.getLength());
  cout << "List 4: " << list4 << endl;

  print("Test assignment operator");
  cout << "List 1: " << *listPtr1 << endl;
  cout << "Assign list5 = list1\n";
  LinkedList<string> list5;
  list5 = *listPtr1;
  cout << "List 1: " << *listPtr1 << endl;
  cout << "List 5: " << list5 << endl;
  cout << "After removing third node of list1: \n";
  listPtr1->remove(3);
  cout << "List 1: " << *listPtr1 << endl;
  cout << "List 5: " << list5 << endl;

  cout << "Now assign list2 = list5 = list1\n";
  *listPtr2 = list5 = *listPtr1;
  cout << "List 1: " << *listPtr1 << endl;
  cout << "List 2: " << *listPtr2 << endl;
  cout << "List 5: " << list5 << endl;

  print("Test operator==");
  LinkedList<string>* listPtr6 = convertToList(weekdays);
  cout << "Create list6 out of weekdays, then replace `thu` with `Thu`: " << endl;
  listPtr6->replace(4, "Thu");
  cout << "list6: " << *listPtr6 << endl;
  cout << "Add `Sun` as the first node and `Sat` as the last node\n";
  listPtr6->insert(1, "Sun");
  listPtr6->insert(7, "Sat");
  cout << "list6: " << *listPtr6 << endl;
  cout << "list4: " << list4 << endl;
  cout << "Comparing list6 and list4\n";
  if (*listPtr6 == list4) {
    cout << "list6 == list4: as expected\n";
  }
  else {
    cout << "list6 != list4: Why not? It should\n";
  }

  cout << endl << endl;


  /*
  LinkedList<string>* listPtr = new LinkedList<string>();

  string data[] = {"one", "two", "three", "four", "five", "six"};
  cout << "isEmpty: returns " << listPtr->isEmpty()
       << "; should be 1 (true)" << endl;

  for (int i = 0; i < 6; i++) {
    if (listPtr->insert(i + 1, data[i])) {
      try {
         cout << "Inserted " << listPtr->getEntry(i + 1)
              << " at position " << (i + 1) << endl;
      }
      catch (PrecondViolatedExcept except) {
        cout << "Failed to get entry at position "
                  << (i + 1) << endl;
      }
    }
    else {
      cout << "Cannot insert " << data[i] << " at position " << (i + 1)
           << endl;
    }
  }
  */


  return 0;
}

