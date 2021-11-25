#include <iostream>
#include <utility>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string prodName, string prodDescription, double numPrice, int numQuantity) {
    SetName(std::move(prodName));
    SetDescription(std::move(prodDescription));
    itemPrice = numPrice;
    itemQuantity = numQuantity;
}
void ItemToPurchase::SetName(string prodName) {
    itemName = std::move(prodName);
}
string ItemToPurchase::GetName() const {
    return itemName;
}
void ItemToPurchase::SetDescription(string prodDescription) {
    itemDescription = std::move(prodDescription);
}
string ItemToPurchase::GetDescription() const {
    return itemDescription;
}
double ItemToPurchase::GetPrice() const{
    return itemPrice;
}
void ItemToPurchase::SetQuantity(int numQuantity) {
    itemQuantity = numQuantity;
}
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
void ItemToPurchase::PrintCost() const {
    cout << GetName() << " " << GetQuantity() << " @ $" << fixed << setprecision(2) << GetPrice()  << " = $" << (GetQuantity() * GetPrice()) << endl;
}
void ItemToPurchase::PrintDescription() const {
    cout << GetName() << ": " << GetDescription() << endl;
}
