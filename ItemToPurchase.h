#ifndef ONLINE_SHOPPING_CART_ITEMTOPURCHASE_H
#define ONLINE_SHOPPING_CART_ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string prodName, string prodDescription, double numPrice, int numQuantity);
    void SetName(string prodName);
    string GetName() const;
    void SetDescription(string prodDescription);
    string GetDescription() const;
    double GetPrice() const;
    void SetQuantity(int numQuantity);
    int GetQuantity() const;
    void PrintCost() const;
    void PrintDescription() const;

private:
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
};

#endif
