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