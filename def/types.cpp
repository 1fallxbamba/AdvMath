#include <array>

using namespace std;

// Type Solutions : représente les solutions d'un polynome de 2nd degré (x1 et x2)
struct Solutions
{
    double x1;
    double x2;

    void zero() {x1 = 0.0; x2 = 0.0;};
};

// Type Point2D : représente les coordonnées d'un point dans un repére cartésien (O, i, j)
struct Point2D
{
    double x;
    double y;
};

// Type Point3D : représente les coordonnées d'un point dans un l'espace (x, y, z)
struct Point3D
{
    double x;
    double y;
    double z;
};

#define PI 3.14159265358979323846
// Ce type est un tableau de Point3D qui représente les sommets d'un triangle 3D (A, B, C)
typedef array<Point3D, 3> CORNERS3D;