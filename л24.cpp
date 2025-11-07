#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point() : x(0), y(0) {
		cout << "[Point] Конструктор по умолчанию вызван" << endl;
	}
	Point(int xVal, int yVal) : x(xVal), y(yVal) {
		cout << "[Point] Конструктор с параметрами(" << x << "," << y << ") вызван" << endl;
	}
	Point(const Point& other) : x(other.x), y(other.y) {
		cout << "[Point] Конструктор копирования (" << x << "," << y << ") вызван" << endl;
	}
	~Point() {
		cout << "[Point] Деструктор (" << x << "," << y << ") вызван" << endl;
	}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int xVal) {
		x = xVal;
		cout << "[Point] Х установлен в " << x << endl;
	}
	void sety(int yVal) {
		y = yVal;
		cout << "[Point] Y установлен в " << y << endl;
	}
	void print() const {
		cout << "Точка(" << x << "," << y << ")";
	}
	void move(int dx, int dy) {
		x += dx;
		y += dy;
		cout << "[Point] Точка перемещена на (" << dx << "," << dy << ")" << endl;
	}
};
class Line {
private:
	Point start;
	Point end;
	string color;
public:
	Line() :start(Point(0, 0)), end(Point(1, 1)), color("black") {
		cout << "[Line] Конструктор по умолчанию вызван" << endl;
	}
	Line(const Point& s, const Point& e) : start(s), end(e), color("black") {
		cout << "[Line] Конструктор с параметрами(две точки) вызван" << endl;
	}
	Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2), color("black") {
		cout << "[Line] Конструктор с параметрами ( координаты) вызван" << endl;
	}
	Line(const Line& other) : start(other.start), end(other.end), color(other.color) {
		cout << "[Line] Конструктор копирования вызван" << endl;
	}
	~Line() {
		cout << "[Line] Деструктор вызван" << endl;
	}
	void print() const {
		cout << "[Line] Линия: ";
		start.print();
		cout << " -> ";
		end.print();
		cout << ", цвет: " << color << endl;
	}
	void setColor(const string& newColor) {
		color = newColor;
		cout << "[Line] Цвет изменен на: " << color << endl;
	}
	void move(int dx, int dy) {
		cout << "[Line] Перемещаем линию на (" << dx << "," << dy << ")" << endl;
		start.move(dx, dy);
		end.move(dx, dy);
	}
	double getLength() const {
		int dx = end.getX() - start.getX();
		int dy = end.getY() - start.getY();
		return sqrt(dx * dx + dy * dy);
	}
};
class Rectangle {
private:
    Line top;      
    Line right;     
    Line bottom;   
    Line left;     
    string fillColor; 

public:
    Rectangle() :
        top(Line(Point(0, 0), Point(2, 0))),
        right(Line(Point(2, 0), Point(2, 1))),
        bottom(Line(Point(2, 1), Point(0, 1))),
        left(Line(Point(0, 1), Point(0, 0))),
        fillColor("white") {
        cout << "[Rectangle] Конструктор по умолчанию вызван" << endl;
    }
    Rectangle(const Point& topLeft, int width, int height) :
        top(Line(topLeft, Point(topLeft.getX() + width, topLeft.getY()))),
        right(Line(Point(topLeft.getX() + width, topLeft.getY()),
            Point(topLeft.getX() + width, topLeft.getY() + height))),
        bottom(Line(Point(topLeft.getX() + width, topLeft.getY() + height),
            Point(topLeft.getX(), topLeft.getY() + height))),
        left(Line(Point(topLeft.getX(), topLeft.getY() + height), topLeft)),
        fillColor("white") {
        cout << "[Rectangle] Конструктор с параметрами вызван" << endl;
    }
    Rectangle(const Rectangle& other) :
        top(other.top), right(other.right), bottom(other.bottom), left(other.left),
        fillColor(other.fillColor) {
        cout << "[Rectangle] Конструктор копирования вызван" << endl;
    }
    ~Rectangle() {
        cout << "[Rectangle] Деструктор вызван" << endl;
    }
    void print() const {
        cout << "[Rectangle] Прямоугольник:" << endl;
        cout << "  "; top.print();
        cout << "  "; right.print();
        cout << "  "; bottom.print();
        cout << "  "; left.print();
        cout << "  Цвет заливки: " << fillColor << endl;
    }
    void setFillColor(const string& color) {
        fillColor = color;
        cout << "[Rectangle] Цвет заливки изменен на: " << fillColor << endl;
    }
    void setBorderColor(const string& color) {
        top.setColor(color);
        right.setColor(color);
        bottom.setColor(color);
        left.setColor(color);
        cout << "[Rectangle] Цвет границы изменен на: " << color << endl;
    }
    void move(int dx, int dy) {
        cout << "[Rectangle] Перемещаем прямоугольник на (" << dx << "," << dy << ")" << endl;
        top.move(dx, dy);
        right.move(dx, dy);
        bottom.move(dx, dy);
        left.move(dx, dy);
    }
    int getArea() const {
        int width = top.getLength(); 
        int height = left.getLength();
        return width * height;
    }
};