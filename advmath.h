///                                       AdvMath Library -- Author : Bamba Fall (fbamba99@gmail.com).

#include <cmath>

#include "def/types.cpp"
#include "def/methods.cpp"

namespace AdvMath // namespace Advanced Math (Opérations Mathématiques avancées)
{

    /* Classe pour calculer les solutions d'un Polynome de 2nd degré (Ax² + Bx + c)
    Les valeurs par défaut sont 0*/
    class Polynome2
    {
    private:
        double _a, _b, _c;

    public:
        // Initialise le polynome avec les valeurs de a, b et c
        Polynome2(double a = 0.0, double b = 0.0, double c = 0.0)
            : _a(a), _b(b), _c(c) {}

        /* Renvoie les solutions (x1 et x2)  du polynome sous forme de Structure
        Renvoie x1 = 0 et x2 = 0 si delta est négatif
        Renvoie une seule solution x1 si delta = 0
        */
        Solutions solutions()
        {
            double delta((_b * _b) - (4 * _a * _c));

            Solutions x1x2;

            if (delta < 0.0)
            {
                x1x2.zero(); // x_1 = 0 et x_2 = 0
            }
            else if (delta == 0.0)
            {
                x1x2.x1 = -_b / (2 * _a); // Si Delta = 0 on a une solution unique que l'on choisi de mettre dans x1
                x1x2.x2 = 0.0;
            }
            else
            {
                x1x2.x1 = (-_b - sqrt(delta)) / (2 * _a);
                x1x2.x2 = (-_b + sqrt(delta)) / (2 * _a);
            }

            return x1x2;
        }
    };

    /* Classe permettant de faire des opérations sur un cercle
    Ici, un cercle se trouve dans un repére cartésien (O, i, j). Son centre est donc un Point (x;y)
    Les valeurs par défaut du rayon et du centre sont 0
    */
    class Circle
    {
    private:
        double _radius;
        Point2D _center;

    public:
        // Initialise le rayon et le centre du cercle
        Circle(double radius = 0.0, Point2D center = {0.0, 0.0})
            : _radius(radius), _center(center) {}

        // -GETTERS-

        //Retourne le rayon du cercle
        double radius() const { return _radius; }
        //Retourne le centre du cercle
        Point2D center() const { return _center; }
        //Retourne le diamétre du cercle
        double diameter() const { return _radius * 2; }

        // -SETTERS-

        //Affecte une valeur au rayon du cercle
        void radius(double radius) { _radius = radius; }
        //Affecte une valeur au centre du cercle
        void center(Point2D center) { _center = center; }

        // Calcule et retourne la surface du cercle
        double area() const { return PI * (_radius * _radius); }

        // Calcule et retourne la circonférence du cercle
        double circum() const { return 2 * PI * _radius; }

        // Verifie si un Point donné appartient au cercle
        bool isInCircle(Point2D p)
        {
            /*Après traçage sur papier, j'ai remarqué que les coordonnées du diamètre (constitué de 2 Points) peuvent être calculées comme suit :
            Point1 : 
                -abcisse (x) du centre - rayon
                -ordonnée (y) du centre - rayon
            
            Point2 : 
                -abcisse (x) du centre + rayon
                -ordonnée (y) du centre + rayon
            */

            // Point 1
            double x_1_diameter(_center.x - _radius);
            double y_1_diameter(_center.y - _radius);
            // Point 2
            double x_2_diameter(_center.x + _radius);
            double y_2_diameter(_center.y + _radius);

            /* Pour maintenant savoir si le Point est à l'intérieur ou à l'extérieur du Cercle,
            la logique est de tester la position de ce point par rapport au diamètre
            */

            if ((p.x == x_1_diameter) || (p.x == x_2_diameter))
            {
                if ((p.y < y_1_diameter) || (p.y > y_2_diameter))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (p.x > x_1_diameter)
            {
                if (p.x < x_2_diameter)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    };

    /* Classe permettant de faire des opérations sur un Triangle
    Ici, un Triangle se trouve dans l'espace 3D (x, y, z).
    Chacun de ses sommets est donc un Point3D
    Les valeurs par défaut sont 0
    */
    class Triangle3D
    {
    private:
        CORNERS3D Corners;

        /*-La formule pour calculer la distance entre deux points de l'espace (x1, y1, z1) et (x2, y2, z2) est :
                sqrt( (x1 - x2)² + (y1 - y2)² + (z1 - z2)² )
        */

        // Distance entre le sommet 1 et le sommet 2
        double d_1()
        {
            return sqrt(pow((Corners[0].x - Corners[1].x), 2) + pow((Corners[0].y - Corners[1].y), 2) + pow((Corners[0].z - Corners[1].z), 2));
        }

        // Distance entre le sommet 2 et le sommet 3
        double d_2()
        {
            return sqrt(pow((Corners[1].x - Corners[2].x), 2) + pow((Corners[1].y - Corners[2].y), 2) + pow((Corners[1].z - Corners[2].z), 2));
        }

        // Distance entre le sommet 1 et le sommet 3
        double d_3()
        {
            return sqrt(pow((Corners[0].x - Corners[2].x), 2) + pow((Corners[0].y - Corners[2].y), 2) + pow((Corners[0].z - Corners[2].z), 2));
        }

        // Verifie si le triangle est isocèle
        bool isIsocele()
        {
            /* Indications :
                -Un triangle est isocèle si au moins deux côtés ont la même longueur

                La logique est donc de calculer la distance entre chaque sommet puis de vérifier une éventuelles égalité de longueur
            */
            if ((d_1() == d_2()) || (d_1() == d_3()) || (d_2() == d_3()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Verifie si le triangle est rectangle
        bool isRectangle()
        {
            if (((sqr(d_1()) + sqr(d_2())) == sqr(d_3())))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    public:
        Triangle3D(Point3D A = {0, 0, 0}, Point3D B = {0, 0, 0}, Point3D C = {0, 0, 0})
        {
            Corners[0] = A;
            Corners[1] = B;
            Corners[2] = C;
        }

        // -SETTERS-

        // Affecte des valeurs aux sommets du triangle
        CORNERS3D corners(Point3D A, Point3D B, Point3D C) { Triangle3D(A, B, C); }

        /* Renvoie la nature du triangle
        Q : Quelconque 
        T : Triangle
        I : Isocèle
        */
        char nature()
        {
            if (this->isRectangle())
            {
                return 'R';
            }
            else if (this->isIsocele())
            {
                return 'I';
            }
            else
            {
                return 'Q';
            }
        }

        // Calcule et retourne le périmètre du triangle
        double perim() { return d_1() + d_2() + d_3(); }
    };

} // namespace AdvMath