#include <iostream>
#include <string>


using namespace std;

class Ship {
private:
  string name;
  string yearBuilt;

public:
  Ship();
  Ship(string, string);
  void setName(string);
  void setYearBuilt(string);

  string getName(); //const;
  string getYearBuilt(); //const;
  virtual void print() = 0;
};
Ship::Ship() {
    setName("");
    setYearBuilt("");
}
Ship::Ship(string nm, string yrblt) {
    setName(nm);
    setYearBuilt(yrblt);
}
void Ship::setName(string nm) { name = nm; }
void Ship::setYearBuilt(string yrblt) { yearBuilt = yrblt; }
string Ship::getName() { return name; }
string Ship::getYearBuilt() { return yearBuilt; }
void Ship::print() { cout << "Name: " << getName() << ", Year Built: " << getYearBuilt() << endl; }

class CruiseShip : public Ship {
private:
    int passengerCapacity;
public:
    CruiseShip(string, string, int);
    void setPassengerCapacity(int);
    int getPassengerCapacity(); // const;
    void print();
};
CruiseShip::CruiseShip(string nm, string yrblt, int psngrCap) : Ship(nm,yrblt) {
    setPassengerCapacity(psngrCap);
}
void CruiseShip::setPassengerCapacity(int psngrCap) { passengerCapacity = psngrCap; }
int CruiseShip::getPassengerCapacity() { return passengerCapacity; }
void CruiseShip::print() { cout << "Name: " << getName() << ", Year Built: " << getYearBuilt() 
    << ", Pasenger Capacity: " << getPassengerCapacity() << endl; }


class CargoShip : public Ship {
private:
    int tonnage;
public:
    CargoShip(string, string, int);
    void setTonnage(int);
    int getTonnage(); // const;
    void print();
};
CargoShip::CargoShip(string nm, string yrblt, int tng) : Ship(nm, yrblt) {
    setTonnage(tng);
}
void CargoShip::setTonnage(int tng) { tonnage = tng; }
int CargoShip::getTonnage() { return tonnage; }
void CargoShip::print() { cout << "Name: " << getName() << ", Year Built: " << getYearBuilt() 
    << ", Tonnage: " << getTonnage() << endl; }

int main()
{
    const int SZ = 2;
    Ship *ships[SZ];
    ships[0] = new CargoShip("Edmond Fitzgerald", "1957", 13632);
    ships[1] = new CruiseShip("Titanic", "1909", 3320);

    for (int i = 0; i < SZ; i++) {
        ships[i]->print();
    }

    return 0;
}