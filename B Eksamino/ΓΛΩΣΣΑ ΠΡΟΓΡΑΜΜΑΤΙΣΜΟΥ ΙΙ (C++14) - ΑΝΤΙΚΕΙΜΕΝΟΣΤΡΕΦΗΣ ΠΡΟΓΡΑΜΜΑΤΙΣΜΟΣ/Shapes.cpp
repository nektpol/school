#include <iostream>
using namespace std;

class Shape {
    protected:

        double centerX;
        double centerY;

    public:

        Shape(double centerX, double centerY) {
            this->centerX = centerX;
            this->centerY = centerY;
        }

        virtual string getName() const = 0; // Pure virtual function

        virtual void printInfo() {
            cout << "Shape: " << getName() << ", Center: (" << centerX << ", " << centerY << ")";
        }
};


class ColouredShape : public Shape {
    protected:
        string colour;

    public:
    
        ColouredShape(double centerX, double centerY, string colour) : Shape(centerX, centerY) {
            this->colour = colour;
        }

        string getColour() const {
            return colour;
        }

        void setColour(const string& colour) {
            this->colour = colour;
        }

        virtual void printInfo(){
            Shape::printInfo();
            cout << ", Colour: " << colour;
        }
};


class Rectangle : public ColouredShape{
    private:
        double a;
    
    public:
        Rectangle(double centerX, double centerY, string colour, double a) : ColouredShape(centerX, centerY, colour) {
            this->a = a;
        }

        double getA() const {
            return a;
        }

        void setA(double a) {
            this->a = a;
        }

        void printInfo() override {
            ColouredShape::printInfo();
            cout << ", Side Length: " << a;
        }

        void moveUp(double k){
            //TODO: Move the rectangle up by increasing the y-coordinate of its center
        }

        void moveDown(double k){
            //TODO: Move the rectangle down by decreasing the y-coordinate of its center
        }

};

class Circle : public ColouredShape{
    private:
        double r;

    public:

        Circle(double centerX, double centerY, string colour, double r) : ColouredShape(centerX,centerY,colour){
            this->r=r;
        }

        double getR(){
            return r;
        }

        void setR(double r){
            this->r=r;
        }

        void printInfo(){
            ColouredShape::printInfo();
            cout << ", Circle radius: "<< r;
        }

        

};