#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
#define PI  3.142

class Shape{

        public:
            virtual double area()  = 0;
           virtual  double perimeter()  = 0;
};
class Circle : public Shape{
    double radius;
            public:
              Circle(double r)
                    {
                        cout<<"enter the radius of the circle"<<endl;
                        cin>>r;
                        if(r<0)
                            {
                                cout<<"Wrong radius"<<endl;
                            }
                    else
                        {
                            radius = r;
                        }

                    }
                double area() override 
                    {
                        return PI* pow(radius,2);
                       }
                        double perimeter() override 
                            {
                            return 2*PI*radius;
                            }   

};

class Rectangle : public Shape{

                protected:
                    double length;
                    double width;

                public:
                    Rectangle(double l, double w) : length(l), width(w) {}
                    double area() override
                    {
                        return length * width;
                            }
              double perimeter()  override
                            {
                                return 2*(length+width);
                            }


               
};
class Square : public Rectangle
    {
        private:
        double side_size;
        public:
        Square(double s):Rectangle(s,s) {
                cout<<"Enter the side size of the square"<<endl;
                cin>>s;
                if(s<0)
                    {
                        cout<<"The square cannot have a negative side size"<<endl;
                    }
        else
            {
                side_size = s;
                    
                     }
                
            }
                     double area() override
                {
                    return side_size * side_size;
                }
            double perimeter() override
                    {
                        return 4 * side_size;
                    }
    };

    class Triangle : public Shape
                {
                    public:
                       double base;
                        double height;
                        double hypotenuse;
                    Triangle(double b, double h, double p)
                        {
                            cout<<"enter the base, height and hypotenuse of the triangle"<<endl;
                            cin>>b>>h>>p;
                            if (b<0 || h<0 || p<0 )
                                {
                                    cout<<"Invalid triangle sides"<<endl;
                                }
                            else
                                {

                                    base = b;
                                    height = h;
                                    hypotenuse = p;
                                }
                           
                        }
                    
                    double area() override
                        {
                            return 0.5*base * height;
                        }
                    double perimeter() override
                        {
                            return base + height + hypotenuse;
                        }
                };
        
int main()
    {
            int raised;
            double len, wid, side;
            int height, base, hypotenuse;
        Shape* shape;
        shape = new Circle(raised);
        cout<<"Enter the length and width of the rectangle"<<endl;
        cin>>len>>wid;
            if(len<0 || wid<0)
            {
                cout<<"Invalid rectangle sides"<<endl;
            }
        else
        {
            shape = new Rectangle(len, wid);
        }
       

        shape = new Triangle(base, height, hypotenuse);
       

        Rectangle* r1;

        r1 = new Square(side);
       
        cout << "Area of the circle: " <<setprecision(2)<<shape->area() << endl;   //area for the circle
        cout << "Perimeter(circumference): " <<setprecision<<shape->perimeter() << endl; // perimeter (circumference) for the circle

        cout << "Area of the rectangle: " <<setprecision(2)<<shape->area() << endl;  // area for the rectangle
        cout << "Perimeter of the rectangle: " <<setprecision(2)<<shape->perimeter() << endl; // perimeter for the rectangle

        cout << "Area of the triangle: " <<setprecision(2)<<shape->area() << endl; //area for the triangle
        cout << "Perimeter of the triangle: " <<setprecision(2)<<shape->perimeter() << endl; //perimeter for the triangle

        cout << "Area of the square: " <<setprecision(2)<< r1->area() << endl; //area of the square
        cout << "Perimeter of the square: " <<setprecision(2)<<r1->perimeter() << endl;  //perimeter of the square

        return 0;
    }
           
    