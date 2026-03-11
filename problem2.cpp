// Problem 2 
// Homework 2

#include <iostream>
#include <iomanip>
#include <string>


class InventoryItem 
{
private:
    std::string name_;
    int quantity_{0};
    double unit_price_{0.0};

    static int object_count_;// counts how many objects currently exist

public:
    //Constructors
    InventoryItem()
        : name_(""), quantity_(0), unit_price_(0.0)
    {
        ++object_count_;
    }

    // Parameterized constructor 
    InventoryItem(const std::string& name, 
                  int quantity, 
                  double price)
        : name_(name),
          quantity_(quantity < 0 ? 0 : quantity),
          unit_price_(price < 0.0 ? 0.0 : price)
    {
        ++object_count_;
    }

    //Destructor 
    ~InventoryItem() {
        --object_count_;
    }

    //Observers (const) 
    const std::string& name() const {return name_;}
    int quantity() const {return quantity_;}
    double price() const {return unit_price_;}

    double totalValue() const {
        return quantity_ * unit_price_;
    }

    //Static observer 
    static int objectCount() {
        return object_count_;
    }

    // Mutators 
    // restock: add amount to quantity.  amount > 0.
    bool restock(int amount) {
        if (amount <= 0) return false;
        quantity_ += amount;
        return true;
    }

    // sell: subtract amount from quantity.  0 < amount <= quantity_
    bool sell(int amount) {
        if (amount <= 0 || amount > quantity_) return false;
        quantity_ -= amount;
        return true;
    }
};

// Define the static member outside the class
int InventoryItem::object_count_ = 0;


int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Print initial object count
    std::cout << "Initial object count: "
              << InventoryItem::objectCount() << std::endl;

    // Create at least two InventoryItem objects
    InventoryItem widget("Widget", 50, 9.99);
    InventoryItem gadget("Gadget", 20, 24.50);

    // Demonstrate negative-guard in constructor
    InventoryItem bad("BadItem", -5, -3.0);
    std::cout << "BadItem quantity (should be 0): " << bad.quantity() << std::endl;
    std::cout << "BadItem price    (should be 0): " << bad.price()    << std::endl;

    //Print object count again
    std::cout << "\nObject count after creating 3 items: "
              << InventoryItem::objectCount() << std::endl;

    // Demonstrate 
    // Restocking
    std::cout << "\n -Restocking-" << std::endl;
    std::cout << widget.name() << " quantity before restock: "
              << widget.quantity() << std::endl;
    widget.restock(30);
    std::cout << widget.name() << " quantity after restock(30): "
              << widget.quantity() << std::endl;

    // Invalid restock
    bool result = widget.restock(-10);
    std::cout << "restock(-10) returned: " << std::boolalpha << result
              << " | quantity unchanged: " << widget.quantity() << std::endl;

    // Selling
    std::cout << "\n -Selling-" << std::endl;
    std::cout << gadget.name() << " quantity before sell: "
              << gadget.quantity() << std::endl;
    gadget.sell(5);
    std::cout << gadget.name() << " quantity after sell(5): "
              << gadget.quantity() << std::endl;

    // Invalid sell 
    result = gadget.sell(100);
    std::cout << "sell(100) returned: " << std::boolalpha << result
              << " | quantity unchanged: " << gadget.quantity() << std::endl;

    // Total value
    std::cout << "\n -Total Values-" << std::endl;
    std::cout << widget.name() << " total value: $"
              << widget.totalValue() << std::endl;
    std::cout << gadget.name() << " total value: $"
              << gadget.totalValue() << std::endl;

    //Print final object count
    std::cout << "\nFinal object count: "
              << InventoryItem::objectCount() << std::endl;

    return 0;
}
