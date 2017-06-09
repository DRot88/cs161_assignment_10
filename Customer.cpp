#include "Customer.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::vector;

//constructor for new Customers
Customer::Customer(string n, string a, bool pm) {
  name = n;
  accountID = a;
  premiumMember = pm;
}

//returns AccountID from the customer
string Customer::getAccountID() {
  return accountID;
}

//returns customer cart
vector<string> Customer::getCart() {
  return cart;
}

//adds a new product to the end of the Customers cart
void Customer::addProductToCart(string productID){
  cart.push_back(productID);
}

//true or false value to determine if customer is premium or not
bool Customer::isPremiumMember() {
  return premiumMember;
}

//clears customer cart of all items
void Customer::emptyCart() {
  cart.clear();
}

// int main() {

//   Customer newCust("Daniel", "1000001", true);

//   cout << endl << "The customer ID is : " << newCust.getAccountID() << endl;
//   cout << "Is the customer a premium member? : " << newCust.isPremiumMember() << endl;

//   newCust.addProductToCart("0001");
//   newCust.addProductToCart("0002");
//   newCust.addProductToCart("0003");
//   vector <string> customerCart = newCust.getCart();

//   cout << "The below items are in the cart: " << endl << endl; 

//   for (int x = 0; x < customerCart.size(); x++) {
//     cout << customerCart[x] << endl;
//   }

//   newCust.emptyCart();
//   customerCart = newCust.getCart();
//   cout << "After clearing the cart, the below items are in the cart: " << endl << endl; 

//   for (int x = 0; x < customerCart.size(); x++) {
//     cout << customerCart[x] << endl;
//   }

//   return 0;
// }