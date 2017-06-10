/****************************************************************
** Author: Daniel Roteneberg
** Date: 6/9/2017
** Description: This program creates class called Product. Each
                product has an id #, title, description, price,
                and quantity available.
****************************************************************/

#include "Product.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

//constructor

Product::Product(string id, string t, string d, double p, int qa) {
  idCode = id;
  title = t;
  description = d;
  price = p;
  quantityAvailable = qa;
}

//get methods

  string Product::getIdCode() {
    return idCode;
  }
  string Product::getTitle() {
    return title;
  }
  string Product::getDescription() {
    return description;
  }
  double Product::getPrice() {
    return price;
  }
  int Product::getQuantityAvailable() {
    return quantityAvailable;
  }

//function to decrease quantity

  void Product::decreaseQuantity() {
    quantityAvailable -= 1;
  }

// int main() {

//   Product testProduct("0001", "Desk Lamp", "Lamp that lights up your workstation", 24.99, 10);

//   cout << endl << "The product we have on hand is: " << testProduct.getTitle() << endl;
//   cout << "The product ID is: " << testProduct.getIdCode() << endl;
//   cout << "The product description is: " << testProduct.getDescription() << endl;
//   cout << "The price of this product is: " << testProduct.getPrice() << endl;
//   cout << "The amount in stock is: " << testProduct.getQuantityAvailable() << endl;
//   testProduct.decreaseQuantity();
//   cout << endl << "One of these products has just been purchased" << endl;
//   cout << "Now the amount in stock is : " << testProduct.getQuantityAvailable() << endl << endl;

//   return 0;
// }