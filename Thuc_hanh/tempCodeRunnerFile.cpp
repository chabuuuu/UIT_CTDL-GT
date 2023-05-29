#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>
using namespace std;

class Bottle {
public:
    virtual double calculateVolume() const = 0;
    virtual double calculateSurfaceArea() const = 0;
};

class CylinderBottle : public Bottle {
private:
    double height;
    double radius;
    const double pi = 3.14;

public:
    CylinderBottle(double h, double r) : height(h), radius(r) {}

    double calculateVolume() const override {
        return pi * pow(radius, 2) * height;
    }

    double calculateSurfaceArea() const override {
        return 2 * pi * radius * height;
    }
};

class CuboidBottle : public Bottle {
private:
    double height;
    double length;
    double width;

public:
    CuboidBottle(double h, double l, double w) : height(h), length(l), width(w) {}

    double calculateVolume() const override {
        return height * length * width;
    }

    double calculateSurfaceArea() const override {
        return 2 * (height * length + height * width + length * width);
    }
};

class CubeBottle : public Bottle {
private:
    double sideLength;

public:
    CubeBottle(double s) : sideLength(s) {}

    double calculateVolume() const override {
        return pow(sideLength, 3);
    }

    double calculateSurfaceArea() const override {
        return 6 * pow(sideLength, 2);
    }
};

int main() {
    int n;
    cin >> n;

    vector<Bottle*> bottles;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            double height, radius;
            cin >> height >> radius;
            bottles.push_back(new CylinderBottle(height, radius));
        } else if (type == 2) {
            double height, length, width;
            cin >> height >> length >> width;
            bottles.push_back(new CuboidBottle(height, length, width));
        } else if (type == 3) {
            double sideLength;
            cin >> sideLength;
            bottles.push_back(new CubeBottle(sideLength));
        }
    }
    double dientich = 0;
    double thetich = 0;
    for (int i = 0; i < n; i++) {
        Bottle* bottle = bottles[i];
        double surfaceArea = bottle->calculateSurfaceArea();
        double volume = bottle->calculateVolume();
        dientich += surfaceArea;
        thetich += volume;
        // cout << "Dien tich chai vo: " << surfaceArea << endl;
        // cout << "Luong nuoc tren mat dat: " << volume << endl;

        delete bottle;
    }
    thetich = thetich*10/100;
    if (dientich == 0){
        cout << "Dien tich chai vo: "<< "0"<< endl;
    }
    if (thetich == 0){
        cout<< "Luong nuoc tren mat dat: "<<"0"<<endl;
    }
       cout << "Dien tich chai vo: "<<fixed<<setprecision(2) <<dientich << endl;
         cout << "Luong nuoc tren mat dat: "<<fixed<<setprecision(3)<< thetich<< endl;

    return 0;
}
