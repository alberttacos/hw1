#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list1;
  cout << "Empty List1" << endl;
  cout << "Check if Empty:" << boolalpha << " " << list1.empty() << endl;

  cout << "Return size:" << " " << list1.size() << endl;

  for(unsigned int i = 0; i < list1.size();i++){
    cout << list1.get(i) << " ";
  }

  cout << endl;
  cout << endl;

  ULListStr list2;
  list2.push_back("Albert");
  list2.push_front("Chung");
  list2.push_front("USC");

  for(unsigned int i = 0; i < list2.size();i++){
    cout << list2.get(i) << " ";
  }
  
  cout << endl;

  cout << "Size for list #2:" << " " << list2.size() << endl;

  cout << "Testing Pop Front" << endl;
  cout << "Testing Pop Back" << endl;
  list2.pop_back();
  list2.pop_front();

  cout << "Updated list: ";

  for(unsigned int i = 0; i < list2.size();i++){
    cout << list2.get(i) << " ";
  }

  cout << endl;

  ULListStr list3;

  list3.push_back("1");
  list3.push_back("2");
  list3.push_back("3");
  list3.push_back("4");
  list3.push_back("5");
  list3.push_back("6");
  list3.push_back("7");
  list3.push_back("8");
  list3.push_back("9");
  list3.push_back("10");

  list3.push_front("a");
  list3.push_front("b");
  list3.push_front("c");
  list3.push_front("d");
  list3.push_front("e");
  list3.push_front("f");
  list3.push_front("g");

  for(unsigned int i = 0; i < list3.size();i++){
    cout << list3.get(i) << " ";
  }

  cout << endl;

  list3.pop_back();
  list3.pop_front();
  list3.pop_back();
  list3.pop_front();
  list3.pop_back();
  list3.pop_front();

  cout << "Testing List3 with pop front and pop back" << endl;

  for(unsigned int i = 0; i < list3.size();i++){
    cout << list3.get(i) << " ";
  }
  cout << endl;

  cout << "Testing front function: " << list3.front() << endl;
  cout << "Testing back function: " << list3.back() << endl;

  cout << "Val at location 4: " << list3.get(4) << endl;
  list3.set(3,"4");
  cout << "Test set function: " << endl;

  for(unsigned int i = 0; i < list3.size();i++){
    cout << list3.get(i) << " ";
  }
  cout << endl;

  cout << "Testing clear" << endl;

  list3.clear();

  for(unsigned int i = 0; i < list3.size();i++){
    cout << list3.get(i) << " ";
  }

  cout << endl;

}
