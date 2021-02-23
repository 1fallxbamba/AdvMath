#include <vector>

using namespace std;

/*****OPERATIONS SPECIALES BASIQUES*****/

// Elever un nombre au carré
double sqr(double n)
{
    return n * n;
}

// Echange deux valeurs
void swapVals(double &a, double &b)
{
    double c(b);
    b = a;
    a = c;
}

/* Compare deux Points 2D
    Retourne True si les deux points sont à la même position (ont les même coordonnées)
    Et False dans le cas contraire
    */
bool compare2D(Point2D p1, Point2D p2)
{
    if ((p1.x == p2.x) && (p1.y == p2.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Compare deux Points 3D
    Retourne True si les deux points sont à la même position (ont les même coordonnées)
    Et False dans le cas contraire
    */
bool compare3D(Point3D p1, Point3D p2)
{
    if ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*****-END-  OPERATIONS SPECIALES BASIQUES*****/


/*****OPERATIONS SUR LES TABLEAUX (VECTOR/ARRAY)*****/

// Calcule et retourne la moyenne des éléments d'un "vector" de "double" ou de "int"
double avgVect(vector<double> vect)
{
    double sum;

    for (auto el : vect)
    {
        sum += el;
    }

    return sum / vect.size();
}

// Retourne la plus petite valeur d'un "vector" de "double" ou de "int"
double minInVect(vector<double> vect)
{
    double minValue = vect[0];

    for (size_t i(0); i < vect.size(); ++i)
    {
        if (vect[i] < minValue)
        {
            minValue = vect[i];
        }
    }

    return minValue;
}

// Retourne la plus grande valeur d'un "vector" de "double" ou de "int"
double maxInVect(vector<double> vect)
{
    double maxValue = vect[0];

    for (size_t i(0); i < vect.size(); ++i)
    {
        if (vect[i] > maxValue)
        {
            maxValue = vect[i];
        }
    }

    return maxValue;
}

/*****-END- OPERATIONS SUR LES TABLEAUX (VECTOR/ARRAY)*****/