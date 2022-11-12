#include <iostream>
#include <conio.h>
using namespace std;

class STO;

class Avto
{
private:
    int id;
    string name;
    int mileage;
public:
    Avto()
    {

    }
    Avto(int v_id, std::string v_name, int v_mileage)
    {
        id = v_id;
        name = v_name;
        mileage = v_mileage;

    }
    ~Avto()
    {

    };

    void setMil(int v_miliage)
    {
        mileage = v_miliage;
    }

    void setName(std::string v_name)
    {
        name = v_name;
    }

    void setId(int v_id)
    {
      
        id = v_id;
    }

    void output_data() {
        std::cout << "ID - " << id << std::endl;
        std::cout << "NAME - " << name << std::endl;
        std::cout << "COST - " << mileage << std::endl;
        std::cout << std::endl;
    }

    friend class STO;
};

class STO
{
public:
    void resetMil(Avto& car, int v_mileage)
    {
        car.mileage = v_mileage;
    }
    ~STO()
    {
        
    };
};


int main()
{
    int num = 0;
    cout << "Enter amout of cars: ";
    cin >> num;
    Avto* cars = new Avto[num];
    int id = 0;
    for (int i = 0; i < num; i++)
    {
        std::string name;
        cars[i].setId(id++);
        std::cout << id - 1 << ". Enter name: ";
        fflush(stdin);
        std::cin >> name;
        cars[i].setName(name);
        fflush(stdin);
        int mileage;
        std::cout << "Enter mileage of the car:";
        std::cin >> mileage;
        cars[i].setMil(mileage);
    }
    std::cout << std::endl;

    for (int i = 0; i < num; i++)
    {
        cars[i].output_data();
    }
    std::cout << std::endl;

    std::cout << "Do you want to change mileage of any car? Press 'N' to exit." << std::endl;
    if (_getch() == 'n') return 0;
    else
    {
        STO a;
        int kol;
        while (true)
        {
            std::cout << "Enter ID of car that you want to edit : ";
            fflush(stdin);
            std::cin >> kol;
            if (kol >= 0) break;
        }

        int mileage;
        while (true)
        {
            std::cout << "Enter mileage of the car: ";
            std::cin >> mileage;
            fflush(stdin);
            if (mileage < 0)
                std::cout << "Error data. Try again." << std::endl;
            else
                break;
        }

        a.resetMil(cars[kol], mileage);
    }

    for (int i = 0; i < num; i++)
    {
        cars[i].output_data();
    }
    std::cout << std::endl;

    delete[] cars;
    _getch();

    return 0;
}


