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

void ULListStr::push_back(const std::string& val)
{
  if(tail_ == nullptr){
    tail_ = new Item();
    tail_->last++;
    tail_->val[tail_->first] = val;
    head_ = tail_;  
    ++size_;
  }else if(tail_->last < 9){
    tail_->val[tail_->last] = val;
    tail_->last++;
    ++size_;
  }else{
    Item* temp = new Item();
    temp->val[temp->last] = val;
    temp ->last++;
    tail_->next = temp;
    temp ->prev = tail_;
    tail_ = temp;
    ++size_;
    temp->next = nullptr;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == nullptr){
    head_ = new Item();
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;  
    head_->val[head_->first] = val;
    tail_ = head_;
    ++size_;
  }else if(head_->first > 0){
    head_->val[head_->first-1] = val;
    head_->first--;
    ++size_;
  }else{
    Item* temp = new Item();
    temp->first = ARRSIZE - 1;   
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;
    head_->prev = temp;
    temp ->next = head_;
    head_  = temp;
    ++size_;
    temp->prev = nullptr;
  }
}

void ULListStr::pop_back()
{
  if(tail_ == nullptr){
    throw std::invalid_argument("tried to pop back on empty list");
  }else if(tail_ != nullptr){
    tail_->last--;
    size_--;
  }
  if(tail_->first == tail_->last){
    if(tail_== head_){
      tail_ = nullptr;
      delete head_;
      head_= nullptr;
    }else{
      Item* temp = tail_;
      tail_ = tail_-> prev;
      delete temp;
      tail_->next = nullptr;
    }
  }
}
void ULListStr::pop_front()
{
  if(head_ == nullptr){
    throw std::invalid_argument("tried to pop back on empty list");
  }else if(head_ != nullptr){
    head_->first++;
    size_--;
  }
  if(head_->first == head_->last){
    if(head_ == tail_){
      tail_= nullptr;
      delete head_;
      head_ = nullptr;
    }else{
      Item* temp  = head_;
      head_= head_->next;
      delete temp;
      head_-> prev =nullptr;
    }
  }
}
std::string const & ULListStr::back() const
{
  if(tail_ == nullptr){
    throw std::invalid_argument("tried to pop back on empty list");
  }
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  if(head_ == nullptr){
    throw std::invalid_argument("tried to pop back on empty list");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc > size_){
    return nullptr;
  } 
  Item* temp = head_;
  
  while((temp->last - temp->first)<=loc){
    loc -=(temp->last - temp->first);
    temp = temp->next;
  }
  return &temp->val[temp->first+loc];
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
