#include <iostream>

using namespace std;

class Item {
private:
    string part_name, part_number;
    int number_on_hand, number_on_order;
public:
    Item(string name, string idNumber, int qtyOnHand, int qtyOnOrder) {
        part_name = name;
        part_number = idNumber;
        number_on_hand = qtyOnHand;
        number_on_order = qtyOnOrder;
    }
    Item(string name, string idNumber) {
        part_name = name;
        part_number = idNumber;
        number_on_hand = 0;
        number_on_order = 0;
    }

    string getName() {
        return part_name;
    }
    string getId() {
        return part_number;
    }
    int getQtyOnHand() {
        return number_on_hand;
    }
    int getQtyOnOrder() {
        return number_on_order;
    }

    void setQtyOnHand(int qtyOnHand) {
        number_on_hand = qtyOnHand;
    }
    void setQtyOnOrder(int qtyOnOrder) {
        number_on_order = qtyOnOrder;
    }

    void display() {
        cout << getName() << ", SKU " << getId() << " (" << getQtyOnHand() << " on hand, " << getQtyOnOrder() << " on order)" << endl;
    }
};


int main()
{
    Item i1("Jolly Ranchers - Family Size", "1001-H", 25, 5);
    Item i2("Twizzlers - 12 pk", "1002-S", 50, 0);
    Item i3("Skittles - Fun Size Tropical", "1003-S");
    i1.display();
    i2.display();
    i3.display();

    cout << "...ordering" << endl;

    i3.setQtyOnOrder(20);
    i3.display();
    cout << "...order on route" << endl;
    
    i3.setQtyOnHand(20);
    i3.setQtyOnOrder(0);
    i3.display();
    cout << "...order arrived" << endl;

    return 0;
}
