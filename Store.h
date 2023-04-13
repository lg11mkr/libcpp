#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Drink {
private:
    string name;
    double basicPrice;
    string size;
    vector<string> toppings;

public:
    Drink(string n, double bp, string s) : name(n), basicPrice(bp), size(s) {}

    string getName() const {
        return name;
    }

    double getBasicPrice() const {
        return basicPrice;
    }

    string getSize() const {
        return size;
    }

    vector<string> getToppings() const {
        return toppings;
    }

    void addTopping(string t) {
        toppings.push_back(t);
    }

    double getPrice() const {
        double totalPrice = basicPrice;
        for (auto t : toppings) {
            if (t == "jelly") {
                totalPrice += 0.5;
            } else if (t == "pudding") {
                totalPrice += 0.7;
            } else if (t == "bobas") {
                totalPrice += 0.8;
            }
        }
        return totalPrice;
    }
};

class Store {
private:
    vector<Drink*> drinks;

public:
    Store() {}

    ~Store() {
        for (auto d : drinks) {
            delete d;
        }
    }

    Store(const Store& other) {
        for (auto d : other.drinks) {
            Drink* newDrink = new Drink(d->getName(), d->getBasicPrice(), d->getSize());
            for (auto t : d->getToppings()) {
                newDrink->addTopping(t);
            }
            drinks.push_back(newDrink);
        }
    }

    Store& operator=(const Store& other) {
        if (this != &other) {
            for (auto d : drinks) {
                delete d;
            }
            drinks.clear();
            for (auto d : other.drinks) {
                Drink* newDrink = new Drink(d->getName(), d->getBasicPrice(), d->getSize());
                for (auto t : d->getToppings()) {
                    newDrink->addTopping(t);
                }
                drinks.push_back(newDrink);
            }
        }
        return *this;
    }

    void addDrink(string name, double price, string size, vector<string> toppings) {
        Drink* newDrink = new Drink(name, price, size);
        for (auto t : toppings) {
            newDrink->addTopping(t);
        }
        drinks.push_back(newDrink);
    }

    void printDrinks() const {
        for (auto d : drinks) {
            cout << d->getName() << " (" << d->getSize() << "): $" << d->getPrice() << endl;
        }
    }
};
int main() {
    // Tạo một cửa hàng mới
    Store myStore("My Store");

    // Thêm đồ uống vào cửa hàng
    myStore.addDrink(new Drink("Cappuccino", 2.5, "medium"));
    myStore.addDrink(new Drink("Espresso", 1.8, "small"));
    myStore.addDrink(new Drink("Latte", 3.0, "large"));

    // Hiển thị danh sách đồ uống
    myStore.displayDrinkMenu();

    // Tạo một khách hàng mới
    Customer myCustomer("John");

    // Khách hàng đặt hàng
    myCustomer.placeOrder(myStore.getDrinkByName("Cappuccino"), {"sugar", "milk"});
    myCustomer.placeOrder(myStore.getDrinkByName("Latte"), {"caramel"});

    // Hiển thị hóa đơn của khách hàng
    myCustomer.displayOrder();

    return 0;
}