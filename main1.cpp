#include <cstddef>    // size_t
#include <iostream>
#include <vector>
#include <forward_list>


#include "SinglyLinkedList.hpp"

using std::cout;
using std::endl;
using std::forward_list;
using std::size_t;
using std::vector;
using std::iterator;

class Item {
  private:
    int    _quantity = 0;
    double _unitPrice  = 0.0;

  public:
    Item() = default;
    Item( int quantity , double unitPrice ) : _quantity( quantity ), _unitPrice( unitPrice ) {}

    void setQuantity( int quantity      )    { _quantity = quantity; }
    void setUnitPrice( double unitPrice )    { _unitPrice = unitPrice; }

    int  getQuantity() const           { return _quantity; }
    double getUnitPrice() const            { return _unitPrice; }


};


double calculate( const vector<Item> & shoppingCart ) {
// TO BE IMPLEMENTED
  int sum = 0;
  for(int i = 0; i < shoppingCart.size(); i++) {
    sum += shoppingCart[i].getQuantity()* shoppingCart[i].getUnitPrice();
  }
  return sum;
}

double calculate( const forward_list<Item> & shoppingCart ) {
// TO BE IMPLEMENTED
  int sum = 0;
  for(auto item: shoppingCart){
    sum += item.getQuantity()* item.getUnitPrice();
  }
  return sum;
}

// Intentionally pass by value (there is no size() or end() function to
// indicate we've visited all nodes)
double calculate( SinglyLinkedList<Item> shoppingCart ) {
// TO BE IMPLEMENTED
//do while head!=tail shit
  int sum = 0;
  while(!shoppingCart.empty()) {
    sum += shoppingCart.front().getQuantity() * shoppingCart.front().getUnitPrice();
    shoppingCart.pop_front();
  }
  return sum;
}


int main() {

     // shoppingCart using Vector
  vector<Item> shoppingCartVector = {{5, 2.56}, {3, 7.29}, {8, 5.04}};

  cout << endl << "total price of shoppingCart using vector is $";
  cout << calculate( shoppingCartVector );

  // shoppingCart using the Standard Library's singly linked list
  forward_list<Item> shoppingCartForwardList = {{5, 2.56}, {3, 7.29}, {8, 5.04}};

  cout << endl << "total price of Shopping Cart using forward_list is $";
  cout << calculate( shoppingCartForwardList );


  // shoppingCart using our zyBook inspired linked list on Github,
// SinglyLinkedList.hpp

 SinglyLinkedList<Item> shoppingCartSinglyLinkedList;
  // DEVELOP YOUR INITIALIZATION PART HERE
  Item Eggs = {5, 2.56};
  Item Milk = {3, 7.29};
  Item Bread = {8, 5.04};

  shoppingCartSinglyLinkedList.append(Eggs);
  shoppingCartSinglyLinkedList.append(Milk);
  shoppingCartSinglyLinkedList.append(Bread);

    cout << endl << "total price of shoppingCart using SinglyLinkedList is $";
    cout << calculate( shoppingCartSinglyLinkedList );


    return 0;



}
