#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return this->width;
    }
    double GetHeight() {
        return this->height;
    }
    double GetDepth() {
        return this->depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

class Cylinder :Solid {
private:
    double radius;
    double height;

public:
    Cylinder(
        double radius,
        double height) {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetHeight() {
        return this->height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height;
    }
    double GetSurface() {
        return (radius * 2 * M_PI * height) + ((radius * radius * M_PI) * 2);
    }
};

class Cone :Solid {
private:
    double radius;
    double height;

public:
    Cone(
        double radius,
        double height) {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetHeight() {
        return this->height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI + (radius * M_PI * (radius + sqrt(radius * 2 + height * 2)));
    }
};

class Sphere :Solid {
private:
    double radius;

public:
    Sphere(
        double radius) {
        this->radius = radius;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetVolume() {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI * 4;
    }
};

int main()
{
    Box box{ 3,5,2.5 };
    Cylinder cylinder{ 3,5 };
    Cone cone{ 4,9 };
    Sphere sphere{ 7 };

    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;

    cout << "cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "cylinderの表面積=" << cylinder.GetSurface() << endl;

    cout << "coneの体積=" << cone.GetVolume() << endl;
    cout << "coneの表面積=" << cone.GetSurface() << endl;

    cout << "sphereの体積=" << sphere.GetVolume() << endl;
    cout << "sphereの表面積=" << sphere.GetSurface() << endl;


}