#include <iostream>

#include "advmath.h"

using namespace std;
using namespace AdvMath;

int main()
{
    Point3D p1 = {1, 2, 3};
    Point3D p2 = {4, 5, 6};
    Point3D p3 = {7, 8, 9};

    Triangle3D tr(p1, p2, p3);

    cout << tr.nature();
}