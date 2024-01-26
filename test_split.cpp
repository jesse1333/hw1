/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream> 
using namespace std;

int main(int argc, char* argv[])
{
   Node* head = new Node(1, nullptr);
   Node* current = new Node(3, nullptr);
   head -> next = current;
   Node* prev = current;
   current = new Node(5, nullptr);
   prev -> next = current;
   prev = current;
   current = new Node(6, nullptr);
   prev -> next = current;

   // Node* head = new Node(0, nullptr);
   // Node* current = new Node(20, nullptr);
   // head -> next = current;

   Node* odds = nullptr;
   Node* evens = nullptr;

   // print list!
   cout << "Original: ";
   for (Node* iter = head; iter != nullptr; iter = iter -> next) {
      if (iter -> next == nullptr) {
         cout << iter -> value;
      }
      else  {
         cout << iter -> value << "->";
      }
   }  

   split(head, odds, evens);

   cout << endl << "Odds: ";
   // print list!
   for (Node* iter = odds; iter != nullptr; iter = iter -> next) {
      if (iter -> next == nullptr) {
         cout << iter -> value;
      }
      else  {
         cout << iter -> value << "->";
      }
   } 

   cout << endl;

   cout << "Evens: ";
   for (Node* iter = evens; iter != nullptr; iter = iter -> next) {
      if (iter -> next == nullptr) {
         cout << iter -> value;
      }
      else  {
         cout << iter -> value << "->";
      }
   } 



}
