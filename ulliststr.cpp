#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string &val)
{
  // case 1 (no nodes)
  if (size_ == 0)
  {
    Item *newNode = new Item();
    head_ = newNode;
    tail_ = newNode;
    newNode->first = 0;
    newNode->last = 1;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->val[0] = val;
    size_++;
  }

  // case 2 (no room)
  else if (tail_->last == ARRSIZE)
  {
    Item *newNode = new Item();
    tail_->next = newNode;
    newNode->prev = tail_;
    newNode->next = nullptr;
    tail_ = newNode;

    tail_->last = 1;
    tail_->first = 0;
    tail_->val[tail_->first] = val;
    size_++;
  }

  // case 3 (have room)
  else
  {
    tail_->last++;
    tail_->val[tail_->last - 1] = val;
    size_++;
  }
}

void ULListStr::pop_back()
{
  // case 1 (no nodes) do nothing cause we can't pop back?
  if (size_ == 0)
  {
    return;
  }

  // case 2 (have things to pop)
  else
  {
    tail_->val[tail_->last - 1] = "";
    tail_->last--;
    size_--;

    // if the array ends up having no spaces used, deallocate the node
    if (tail_->first == tail_->last)
    {
      if (tail_->next == nullptr && tail_->prev == nullptr)
      {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
      }

      else
      {
        // delete the tail
        Item *temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
      }
    }
  }
}

void ULListStr::push_front(const std::string &val)
{
  // case 1 (no nodes)
  if (size_ == 0)
  {
    Item *newNode = new Item();
    head_ = newNode;
    tail_ = newNode;
    newNode->first = 0;
    newNode->last = 1;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->val[0] = val;
    size_++;
  }

  // case 2 (no room)
  else if (head_->first == 0 && head_->last != 0)
  {
    Item *newNode = new Item();
    head_->prev = newNode;
    newNode->next = head_;
    newNode->prev = nullptr;
    head_ = newNode;

    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
    head_->val[head_->first] = val;
    size_++;
  }

  // case 3 (have room)
  else
  {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
}

void ULListStr::pop_front()
{
  // case 1 (no nodes) do nothing cause we can't pop back?
  if (size_ == 0)
  {
    return;
  }

  // if the array ends up having no spaces used, deallocate the node
  if (head_->first == head_->last - 1)
  {
    if (head_->next == nullptr && head_->prev == nullptr)
    {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    }

    else
    {
      // delete the head
      Item *temp = head_->next;
      delete head_;
      head_ = temp;
      head_->prev = nullptr;
    }
  }

  // normal case
  else
  {
    head_->val[head_->first] = "";
    head_->first++;
  }

  size_--;
}

std::string const &ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const &ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string *ULListStr::getValAtLoc(size_t loc) const
{
  // return the pointer of the i'th value in array
  size_t counter = 0;
  size_t index = head_->first;
  Item *iter = head_;

  while (counter < loc)
  {
    if (index == iter->last - 1)
    {
      iter = iter->next;
      index = iter->first;
      index--;
    }

    counter++;
    index++;
  }

  return &(iter->val[index]);
}

void ULListStr::set(size_t loc, const std::string &val)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string &ULListStr::get(size_t loc)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const &ULListStr::get(size_t loc) const
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while (head_ != NULL)
  {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
