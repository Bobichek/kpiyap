#include <iostream>
using namespace std;
class Vehicle {

public:
    string m_model;

    Vehicle() {}

    Vehicle(string model) {
        m_model = model;
    }

    ~Vehicle() {}

    void GetType() {
        cout << "Модель:" << this->m_model << endl;
    }
};

class Car : public virtual Vehicle {
protected:
    string m_mileage;
public:
    Car(string mileage, string model) : Vehicle(model) {
        m_model = model;
        m_mileage = mileage;
    }
    ~Car() {}

    void GetMileage() {
        cout << "Пробег: " << this->m_mileage << endl;
    }
};

class Car21Century : public Car {
protected:
    int m_year;
public:
    Car21Century(string model, string mileage, int year) : Car(mileage, model) {
        m_year = year;
    }
    ~Car21Century() {}

    void GetYear() {
        cout << "Год выпуска: " << this->m_year << endl;
    }
};

class Bike : public virtual Vehicle {
protected:
    string m_volume;
public:
    Bike(string model, string volume) : Vehicle(model) {
        m_model = model;
        m_volume = volume;
    }
    ~Bike() {}

    void GetVolume() {
        cout << "Объем двигателя: " << this->m_volume << endl;
    }
};

class Bike21Century : public Bike {
protected:
    int m_cost;
public:
    Bike21Century(int cost, string model, string volume) : Bike(model, volume) {
        m_cost = cost;
    }
    ~Bike21Century() {}

    void GetCost() {
        cout << "Цена: " << this->m_cost << endl;
    }
};


class Offroad : public Car21Century, public Bike21Century {
protected:
    string m_company;
public:
    Offroad(string company, string model, string volume, int year, int cost, string mileage)
        :Car21Century(model, mileage, year), Bike21Century(cost, model, volume) {
        m_company = company;
    }

    ~Offroad() {}

    void GetInfo() {
        cout << "Кампания: " << this->m_company << endl;
        cout << "Модель: " << this->m_model << endl;
        cout << "Пробег: " << this->m_mileage << endl;
        cout << "Объем двигателя: " << this->m_volume << endl;
        cout << "Год выпуска:" << this->m_year << endl;
        cout << "Цена: " << this->m_cost << endl;
    }
};

int main() {

    system("chcp 1251");
    system("cls");
    Offroad A("BMW", "X5", "4.5V", 2019, 70000, "75000км");

    A.GetInfo();

    return 0;
}