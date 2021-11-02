#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node* next) : val(x), next(next) {}
};


/// <summary>
/// This is where you will implement your solution to the problem:
/// 
/// Given two linked lists that represent numbers starting with the most significat digit,
/// add the two numbers together and return a list that represents the sum of the two numbers.
/// 
/// You may assume the numbers are non negative and have no leading zeros.
/// 
/// Example 1:
/// 321 + 432 = 753
/// 
///   3 -> 2 -> 1 -> null
/// + 4 -> 3 -> 2 -> null
/// = 7 -> 5 -> 3 -> null
/// 
/// Example 2:
/// 999 + 99 = 1098
/// 
///   9 -> 9 -> 9 -> null
/// + 9 -> 9 -> null
/// = 1 -> 0 -> 9 -> 8 -> null
/// 
/// </summary>
/// <param name="first">A list that represents the first number</param>
/// <param name="second">A list that represents the second number</param>
/// <returns>A list that represents the sum of first and second</returns>
Node* addTwoNumbers(Node* first, Node* second) {

  // delete this code and implement with your own solution
  Node* res2 = new Node(3);
  Node* res1 = new Node(5, res2);
  Node* res0 = new Node(7, res1);

  return res0;
}


void test(Node* res, Node* key, int testNumber) {
  while (key != nullptr) {
      if (res == nullptr || key->val != res->val) {
          cout << "Test " << testNumber << " Failed\n";
          return;
      }
      key = key->next;
      res = res->next;
  }

  cout << "Test " << testNumber << " Passed\n";
}

void test1() {
  // first number
  Node* first2 = new Node(1);
  Node* first1 = new Node(2, first2);
  Node* first0 = new Node(3, first1);

  // second number
  Node* sec2 = new Node(2);
  Node* sec1 = new Node(3, sec2);
  Node* sec0 = new Node(4, sec1);

  // key number
  Node* key2 = new Node(3);
  Node* key1 = new Node(5, key2);
  Node* key0 = new Node(7, key1);

  Node* res = addTwoNumbers(first0, sec0);

  test(res, key0, 1);
}

void test2() {
    // first number
    Node* first2 = new Node(9);
    Node* first1 = new Node(9, first2);
    Node* first0 = new Node(9, first1);

    // second number
    Node* sec1 = new Node(9);
    Node* sec0 = new Node(9, sec1);

    // key number
    Node* key3 = new Node(8);
    Node* key2 = new Node(9, key3);
    Node* key1 = new Node(0, key2);
    Node* key0 = new Node(1, key1);

    Node* res = addTwoNumbers(first0, sec0);

    test(res, key0, 2);
}

int main() {
    test1();
    test2();
}
