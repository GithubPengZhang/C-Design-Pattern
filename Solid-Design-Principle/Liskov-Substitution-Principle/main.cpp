// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program

#include <iostream>
using namespace std;

class Rectangle
{
protected:
	int width, height;
public:
	Rectangle(int width, int height) : width(width), height(height) {}
	
	int getWidth() const { return width; }
	virtual void setWidth(int val) { width = val; }
	int getHeight() const { return height; }
	virtual void setHeight(int val) { height = val; }

	int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size, size) {}


	virtual void setWidth(int val) override
	{
		this->width = this->height = val;
	}


	virtual void setHeight(int val) override
	{
		this->width = this->height = val;
	}
};

void process(Rectangle &r)
{
	int w = r.getWidth();
	r.setHeight(10);

	cout << "expected area = " << (w * 10)
		<< ". got " << r.area() << endl;
}

struct RectangleFactory
{
	static Rectangle create_rectangle(int w, int h);
	static Rectangle create_square(int size);
};

int main()
{
	Rectangle r(3, 4);
	process(r);

	Square sq(5);
	process(sq);

	return 0;
}