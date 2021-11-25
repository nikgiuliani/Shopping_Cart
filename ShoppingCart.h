#ifndef ONLINE_SHOPPING_CART_SHOPPINGCART_H
#define ONLINE_SHOPPING_CART_SHOPPINGCART_H
#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string userName, string cartDate);
    void GetCartDate();
    void AddToCart(const ItemToPurchase &newItem);
    void RemoveFromCart(const string &itemName);
    void UpdateItemQuantity(const string &itemName, int itemQuantity);
    void GetQuantity();
    void GetTotalCost();
    void PrintAllDescriptions();
    void PrintAllItemsAndCost();

private:
    string userName;
    string cartDate;
    vector<ItemToPurchase> shoppingItems;
};
#endif
