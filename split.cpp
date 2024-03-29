/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node *&in, Node *&odds, Node *&evens)
{
  if (in != nullptr)
  {
    if (in->value % 2 == 1)
    {
      odds = in;
      in = in->next;
      odds->next = nullptr;
      split(in, odds->next, evens);
    }
    else
    {
      evens = in;
      in = in->next;
      evens->next = nullptr;
      split(in, odds, evens->next);
    }
  }

  else
  {
    in = nullptr;
    odds = nullptr;
    evens = nullptr;
  }
}

/* If you needed a helper function, write it here */