#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart() {
    std::string customerName = "none";
    std::string todayDate = "January 1, 1970";
}
ShoppingCart::ShoppingCart(string userName, string cartDate) {
    this->userName = std::move(userName);
    this->cartDate = std::move(cartDate);
}
void ShoppingCart::GetCartDate() {
    cout << userName << "'s Shopping Cart - " << cartDate <<  endl;
}
void ShoppingCart::AddToCart(const ItemToPurchase &newItem) {
    for (int i = 0; i < shoppingItems.size(); ++i) {
        if (shoppingItems.at(i).GetName() == newItem.GetName()) {
            cout << "Item is already found in the cart. It will not be added." << endl;
            return;
        }
    }
    shoppingItems.push_back(newItem);
}
void ShoppingCart::RemoveFromCart(const string &itemName) {
    bool itemErased = false;
    for (int i = 0; i < shoppingItems.size(); ++i) {
        if (shoppingItems.at(i).GetName() == itemName) {
            shoppingItems.erase(shoppingItems.begin()+i);
            itemErased = true;
            break;
        }
    }
    if (!itemErased) {
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}
void ShoppingCart::UpdateItemQuantity(const string &itemName, int itemQuantity) {
    bool quantityUpdated = false;
    for (int i = 0; i < shoppingItems.size(); ++i) {
        if (shoppingItems.at(i).GetName() == itemName) {
            shoppingItems.at(i).SetQuantity(itemQuantity);
            quantityUpdated = true;
            break;
        }
    }
    if (!quantityUpdated) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }
}
void ShoppingCart::GetQuantity() {
    int totalQuantity = 0;
    for (int i = 0; i < shoppingItems.size(); ++i) {
        totalQuantity = shoppingItems.at(i).GetQuantity() + totalQuantity;
    }
    cout << totalQuantity << endl;
}
void ShoppingCart::GetTotalCost() {
    double totalCost = 0.0;
    for (int i = 0; i < shoppingItems.size(); ++i) {
        totalCost = (shoppingItems.at(i).GetPrice() * shoppingItems.at(i).GetQuantity()) + totalCost;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalCost << endl;
}
void ShoppingCart::PrintAllDescriptions() {
    GetCartDate();
    if (shoppingItems.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < shoppingItems.size(); ++i) {
            shoppingItems.at(i).PrintDescription();
        }
    }
}
void ShoppingCart::PrintAllItemsAndCost() {
    GetCartDate();
    if (shoppingItems.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << endl << "Number of Items: ";
        GetQuantity();
        for (int i = 0; i < shoppingItems.size(); ++i) {
            shoppingItems.at(i).PrintCost();
        }
        cout << endl << endl;
        GetTotalCost();
    }
}

