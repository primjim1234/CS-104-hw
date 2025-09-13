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

////////////////////////////////////////////////////

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(empty()){
    return nullptr;
  }
  if(loc >= size_){
    return nullptr;
  }
  Item* curr = head_;
  while(curr != nullptr){
    size_t blockSize = curr->last - curr->first;
    if(loc < blockSize){
      return &curr->val[curr->first + loc];
    }
    else{
      loc -= blockSize;
      curr = curr->next;
    }
     
  }
  return nullptr;

}


std::string const & ULListStr::back() const
{
  if(empty()){
    throw std::invalid_argument("List is empty");
  }
  return tail_->val[tail_->last-1];
}
// WRITE YOUR CODE HERE
std::string const & ULListStr::front() const
{
  if(empty()){
    throw std::invalid_argument("List is empty");
  }
  return head_->val[head_->first];
}


void ULListStr::push_back(const std::string& val)
{
  if(empty()){
    head_= new Item();
    tail_ = head_;
    head_->first = 0;
    head_->last =0;
    head_->prev = nullptr;
    head_->next = nullptr;
  }
  if(tail_->last == ARRSIZE){
    Item* node = new Item();
    node->first = 0;
    node->last = 0;
    node->prev = tail_;
    node->next = nullptr;
    tail_->next = node;
    tail_ = node;
  }
  tail_->val[tail_->last] = val;
  tail_->last += 1;
  size_ +=1;
}

void ULListStr::push_front(const std::string& val)
{
  if(empty()){
    head_= new Item();
    tail_ = head_;
    head_->first = ARRSIZE;
    head_->last =ARRSIZE;
    head_->prev = nullptr;
    head_->next = nullptr;
  }
  if(head_->first == 0){
    Item* node = new Item();
    node->first = ARRSIZE;
    node->last = ARRSIZE;
    node->prev = nullptr;
    node->next = head_;
    head_->prev = node;
    head_ = node;
  }
  head_->first -= 1;
  head_->val[head_->first] = val;
  size_ +=1;
}


void ULListStr::pop_back()
{
  if(empty()){
    return;
  }

  tail_->last -= 1;
  size_ -= 1;

  if(tail_->first == tail_ -> last){
    Item* old = tail_;
    tail_ = tail_->prev;
    if(tail_){
      tail_->next = nullptr;
    }
    else{
      head_ = nullptr;
    }
    delete old;
  }
}

void ULListStr::pop_front()
{
  if(empty()){
    return;
  }

  head_->first += 1;
  size_ -= 1;

  if(head_->first == head_ -> last){
    Item* old = head_;
    head_ = head_->next;
    if(head_){
      head_->prev = nullptr;
    }
    else{
      tail_ = nullptr;
    }
    delete old;
  }
}




void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}



