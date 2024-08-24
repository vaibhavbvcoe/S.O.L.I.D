#pragma region _HEADERS_
#include"stdafx.h"
#include<iostream>
using namespace std;
#pragma endregion _HEADERS_
/// <summary>
/// LISKOV SUBSTITUTION Principle suggests that Objects of superclass can be should be replaceable with objects of subclass without altering the correctness of program.
/// In the below example process(Rectangle& rectangle) function behaves differently in case square is passed.
/// to correct it we can decouple the rectangle classd dependency by creating an abstract class ISHAPE which would
/// </summary>
/// 

#ifdef LISKOV_SUBSTITUTION_PRINCIPLE_FAULTY_CLASS


class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle(const int width, const int height)
        : width(width),
        height(height) {}

    int get_width() const { return width; }
    int get_height() const { return height; }

    virtual void set_width(const int width) { this->width = width; }
    virtual void set_height(const int height) { this->height = height; }

    int calc_area() const { return (width * height); }

};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void set_width(const int width) override {
        this->height = width;
        this->width = width;
    }

    void set_height(const int height) override {
        this->height = height;
        this->width = height;
    }
};

void process(Rectangle& rectangle) 
{
    int width = rectangle.get_width();
    int height = 10;
    rectangle.set_height(height);

    cout << "Expected area: " << (width * height)
        << ", calculated: " << rectangle.calc_area() << endl;
}

int main(int argc, char* argv[]) 
{

    Rectangle rectangle(5, 5);
    Square square(5);

    cout << "Calling process() for rectangle:" << endl;
    process(rectangle);

    cout << "Calling process() for square:" << endl;
    process(square);

    cout << endl;
    return 0;
}

#endif// LISKOV_SUBSTITUTION_PRINCIPLE_FAULTY_CLASS

class IShape
{
public:
    virtual int get_width() = 0;
    virtual int get_height() = 0;

    virtual void set_width(const int width)=0;
    virtual void set_height(const int height)=0;

    virtual int calc_area() = 0;
};
class Rectangle :public IShape
{
    int m_width;
    int m_height;
public:
    Rectangle(int width, int height):m_width(width),m_height(height)
    {

    }
    int get_width() override
    {
        return m_width;
    }
    int get_height() override
    {
        return m_height;
    }

    void set_width(const int width) override
    {
        m_width = width;
    }
    void set_height(const int height) override
    {
        m_height = height;
    }

    int calc_area() override
    {
        return m_width * m_height;
    }
};
class Square :public IShape
{
    int m_width;
    int m_height;
public:
    Square(int val) :m_width(val), m_height(val)
    {
    }
    int get_width() override
    {
        return m_width;
    }
    int get_height() override
    {
        return m_height;
    }

    void set_width(const int width)
    {
        m_width = width;
        m_height = width;
    }
    void set_height(const int height)
    {
        m_width = height;
        m_height = height;

    }

    int calc_area()
    {
        return m_width * m_height;
    }

};


void process(IShape* shp)
{
    int width = shp->get_width();
    int height = 10;
    shp->set_height(height);

    cout << "Expected area: " << (width * height)
        << ", calculated: " << shp->calc_area() << endl;


    int h = shp->get_height();
    int w = shp->get_width();
    cout << "intial Height = " << h << ", Width = "<<w<<" ";
    cout << " Area = " << shp->calc_area() << " "<<endl;
    cout << "lets change the Height by 8" << endl;
    shp->set_height(8);

    h = shp->get_height();
    w = shp->get_width();
    cout << "Height = " << h << ", Width = " << w << " ";
    cout << "Expected Area " << 8 * w << " , Calculated Area " << shp->calc_area() << endl;
}


int main()
{
    IShape* shp = new Rectangle(4,5);
    process(shp);

    IShape* shp1 = new Square(7);
    process(shp1);
    return 0L;
}


