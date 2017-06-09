#include "Store.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::vector;

// adds a product to the inventory
void Store::addProduct(Product* p) {
  inventory.push_back(p);
}

// adds a customer to the members
void Store::addMember(Customer* c) {
  members.push_back(c);
}

// returns pointer to product with matching ID.  Returns NULL if no matching ID is found.
Product* Store::getProductFromID(string productID) {
  for(int index = 0; index < inventory.size(); index++) {
    if (productID == inventory[index]->getIdCode()) {
      return inventory[index];
    }
  }
  return NULL;
}

// returns pointer to customer with matching ID.  Returns NULL if no matching ID is found.
Customer* Store::getMemberFromID(string memberID) {
  for (int index = 0; index < members.size(); index++) {
    if (memberID == members[index]->getAccountID()) {
      return members[index];
    }
  }
  return NULL;
}

// for every product whose title or description contains the search string, 
// prints out that product's title, ID code, price and description
// case insensitive
// void Store::productSearch(string str) {
//   for (int index = 0; index < inventory.size(); index++) {
//     if ()
//   }
// }

void Store::addProductToMemberCart(string pID, string mID) {

}

void Store::checkOutMember(string mID) {

}


int main() {
  Product* prod;
  Store testStore;
  Product newp("10000002", "Cheese Whiz", "Great on crackers!", 4.99, 10);
  prod = &newp;

  cout << endl << "In Main" << endl;
  Store newStore;
  newStore.addProduct(prod);
  cout << prod << endl;
  cout << newStore.getProductFromID("10000002") << endl;

  return 0;
}
