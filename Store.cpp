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
  Store newStore;
  Product* prodToAdd;
  Customer* custToAdd;

  Product newp("00001", "Cheese Whiz", "Great on crackers!", 4.99, 10);
  prodToAdd = &newp;
  newStore.addProduct(prodToAdd);

  Product newp2("00002", "Frosted Flakes", "Tony the Tiger's favorite cereal.", 3.99, 20);
  prodToAdd = &newp2;
  newStore.addProduct(prodToAdd);

  Product newp3("00003", "Cat Scratcher", "For your furball friends", 63.49, 5);
  prodToAdd = &newp3;
  newStore.addProduct(prodToAdd);

  Product newp4("00004", "Honey", "To help sweeten Tea.", 4.99, 10);
  prodToAdd = &newp4;
  newStore.addProduct(prodToAdd);

  Product newp5("00005", "Samsung 55' TV", "Great for viewing your favorite sunday night TV shows.", 1100.00, 17);
  prodToAdd = &newp5;
  newStore.addProduct(prodToAdd);

  Product newp6("00003", "Cat Brush", "Brush to reduce shedding.", 3.49, 12);
  prodToAdd = &newp6;
  newStore.addProduct(prodToAdd); 


  Customer newCust("Clara", "70000001", true);
  custToAdd = &newCust;
  newStore.addMember(custToAdd);

  Customer newCust2("Daniel", "70000002", true);
  custToAdd = &newCust2;
  newStore.addMember(custToAdd);

  Customer newCust3("Jesse", "70000003", false);
  custToAdd = &newCust3;
  newStore.addMember(custToAdd);  


  cout << endl << "In Main" << endl;
  cout << "Location of Product 00001: " << newStore.getProductFromID("00001") << endl;
  cout << "Location of Member 700000001: " << newStore.getMemberFromID("70000001") << endl;

  return 0;
}
