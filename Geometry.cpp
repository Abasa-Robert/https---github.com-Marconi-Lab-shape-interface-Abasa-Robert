#include<iostream>
#include<cmath>

using namespace std;
#define PI  3.142

class Shape{

        public:
            virtual double area() const = 0;
           virtual  double perimeter() const = 0;
           virtual ~Shape()
           { }
};
class Circle : public Shape{
    double radius;
            public:
              Circle(double r)
                    {
                        cout<<"enter the radius of the circle"<<endl;
                        cin>>r;
                        radius = r;

                    }
                double area() const
                    {
                        return PI* pow(radius,2);
                       }
                        double perimeter() const
                            {
                            return 2*PI*radius;
                            }   

};

class Rectangle : public Shape{

                protected:
                    double length;
                    double width;

                public:
                Rectangle(double l, double w)
                    {
                        cout<<"enter the length and width of the rectangle"<<endl;
                        cin>>l>>w;
                        length = l;
                        width = w;
                    }
               double area() const override
                            {
                                return length*width;
                            }
              double perimeter() const override
                            {
                                return 2*(length+width);
                            }


               
};
class Square : public Rectangle
    {
        public:
        double side_size;
            Square(double s) {
                cout<<"Enter the length of the square"<<endl; 
                cin>>s;
                side_size = s;
            }
            double area() const override
                {
                    return side_size * side_size;
                }
            double perimeter() const override
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
                            base = b;
                            height = h;
                            hypotenuse = p;
                        }
                    
                    double area() const
                        {
                            return 0.5*base * height;
                        }
                    double perimeter() const
                        {
                            return base + height + hypotenuse;
                        }
                };
        
int main()
    {
         double radius=0, //length = 0, width = 0, side = 0 , base = 0, height = 0, hypotenuse = 0;

       Shape *shapes;
       shapes = new Circle(radius);
       cout<<"The area of the circle is "<<shapes->area()<<endl;
       
            return 0;
    }