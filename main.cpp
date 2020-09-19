#include <iostream>
#include "SingleLinkedList.hpp"
#include <forward_list>

int main(){

  SinglyLinkedList<std::string> SLL;
  SLL.append("Blue");
  SLL.append("Red");
  SLL.prepend("Green");
  SLL.pop_front();

  std::forward_list<std::string> FL;
  FL.push_front("Blue");
  FL.insert_after(FL.begin(), "Red");
  FL.push_front("Green");
  FL.pop_front();

return 0;
}
