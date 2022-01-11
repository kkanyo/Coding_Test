#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
public:
    void read_input() {
        cin>>width>>height;
    }
    virtual void display() {
        cout<<width<<" "<<height<<endl;
    }
    int get_width() {
        return width; 
    }
    int get_height() {
        return height;
    }
private:
    int width;
    int height;
};
 
class RectangleArea : public Rectangle {
public:
    void display() {
        cout<<get_width()*get_height()<<endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}