#include <iostream>
#include <vector>
#include <string>

class InventoryItem {
public:
    InventoryItem(const std::string& name, int quantity)
        : name(name), quantity(quantity) {}

    const std::string& getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void addStock(int amount) {
        quantity += amount;
    }

private:
    std::string name;
    int quantity;
};

class Inventory {
public:
    void addItem(const std::string& name, int quantity) {
        items.emplace_back(name, quantity);
    }

    void restock(const std::string& name, int amount) {
        for (auto& item : items) {
            if (item.getName() == name) {
                item.addStock(amount);
            }
        }
    }

    void print() const {
        std::cout << "Inventory Report\n";
        std::cout << "----------------\n";
        for (const auto& item : items) {
            std::cout << item.getName() << ": " << item.getQuantity() << std::endl;
        }
    }

private:
    std::vector<InventoryItem> items;
};

int main() {
    Inventory inventory;

    inventory.addItem("Keyboard", 12);
    inventory.addItem("Mouse", 25);
    inventory.addItem("Monitor", 8);
    inventory.addItem("Headphones", 14);

    inventory.restock("Mouse", 5);
    inventory.restock("Monitor", 3);

    inventory.print();

    return 0;
}
