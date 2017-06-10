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
// the search function will be case insensitive
void Store::productSearch(string str) {
  //lowercase the entire string to search
  for(int i; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }

  cout << endl << "Searching for: " << str << endl;
  //iterate through all items in inventory
  for (int index = 0; index < inventory.size(); index++) {

    string titleToSearch = inventory[index]->getTitle();
    string descriptionToSearch = inventory[index]->getDescription();
    
    //combine strings to search
    string concatStringToSearch = titleToSearch + " " + descriptionToSearch;

    //make string lowercase
    for (int i = 0; i < concatStringToSearch.length(); i++) {
      concatStringToSearch[i] = tolower(concatStringToSearch[i]);
    }

    size_t found = concatStringToSearch.find(str); //if string is found, print ID/Title/Description/Price
    if (found != string::npos) {
      cout << endl << "Product ID: " << inventory[index]->getIdCode() << endl;
      cout << "Title: " << inventory[index]->getTitle() << endl;
      cout << "Description: " << inventory[index]->getDescription()<< endl;
      cout << "Price : " << inventory[index]->getPrice() << endl << endl;
    }
  }
}


void Store::addProductToMemberCart(string pID, string mID) {
    Product* tempProduct = getProductFromID(pID);
    Customer* tempMember = getMemberFromID(mID);

    if (tempProduct == NULL) {
      cout << "Product # " << pID << " not found." << endl;
    }

    if (tempMember == NULL) {
      cout << "Member # " << mID << " not found." << endl;
      return;
    }    

    if ( (*tempProduct).getQuantityAvailable() >= 1) {
      (*tempMember).addProductToCart(pID);
      cout << "Added Product # " << pID << " to cart, for member # " << mID <<"." << endl << endl;
    } else {
      cout << "Sorry, Product # "<< pID << " is currently out of stock." << endl << endl;
    }
}

void Store::checkOutMember(string mID) {
  Customer* tempMember = getMemberFromID(mID);
  double subtotal = 0.0;
  double shipping = 0.0;
  if (tempMember == NULL) {
    cout << "Member # " << mID << " not found." << endl << endl;
    return;
  } else {
    vector<string> custCart = (*tempMember).getCart();
    for (int item = 0; item < custCart.size(); item++) {
      Product* cartProduct = getProductFromID(custCart[item]);
      if ( (*cartProduct).getQuantityAvailable() < 1) {
        cout << "Sorry, product # " << (*cartProduct).getIdCode() << ", ";
        cout << (*cartProduct).getTitle() << " is no longer available." << endl << endl;
      } else { 
        cout << (*cartProduct).getTitle() << " - $" << (*cartProduct).getPrice() << endl;
        subtotal += (*cartProduct).getPrice();
        (*cartProduct).decreaseQuantity();
      }
    }

    if ((*tempMember).isPremiumMember()) {
      shipping = 0.0;
    } else {
      shipping = (subtotal * 0.07);
    }
  }

  if ((*tempMember).getCart().size() > 0) {
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Shipping Cost: $" << shipping << endl;
    cout << "Total: $" << (subtotal + shipping) << endl << endl;
    (*tempMember).emptyCart();
  } else {
    cout << "There are no items in the cart." << endl << endl;
  }
}


int main() {
  Store newStore;
  Product* prodToAdd;
  Customer* custToAdd;

  Product newp("00001", "Cheese Whiz", "Great on crackers!", 4.99, 2);
  prodToAdd = &newp;
  newStore.addProduct(prodToAdd);

  Product newp2("00002", "Frosted Flakes", "Tony the Tiger's favorite cereal.", 3.99, 0);
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

  Product newp6("00006", "Cat Brush", "Brush to reduce shedding.", 3.49, 12);
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

  cout << "Location of Product 00001: " << newStore.getProductFromID("00001") << endl;
  cout << "Location of Member 700000001: " << newStore.getMemberFromID("70000001") << endl;
  newStore.productSearch("F");

  newStore.addProductToMemberCart("000022", "700000033");
  newStore.addProductToMemberCart("00002", "70000001");
  newStore.addProductToMemberCart("00005", "70000001");
  newStore.addProductToMemberCart("00006", "70000002");
  newStore.addProductToMemberCart("00003", "70000002");
  newStore.addProductToMemberCart("00001", "70000002");
  newStore.addProductToMemberCart("00001", "70000003");
  newStore.addProductToMemberCart("00001", "70000003");

  newStore.checkOutMember("57832550");
  newStore.checkOutMember("70000001");
  newStore.checkOutMember("70000002");
  newStore.checkOutMember("70000003");
  newStore.checkOutMember("70000003");

  return 0;
}
