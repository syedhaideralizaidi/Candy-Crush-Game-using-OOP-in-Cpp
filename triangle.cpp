#include "shape.cpp"

class triangle: public shape {
	int x1,x2,y1,y2;
	float *color;

public: 
	triangle() {
		x = 0; x1 = 0; x2 = 0;
		y = 0; y1 = 0; y2 = 0; 
		color = 0;
	}

	int getX1() { return x; }
	int getX2() { return x1; }
	int getX3() { return x2; }
	int getY1() { return y; }
	int getY2() { return y1; }
	int getY3() { return y2; }
	float *getColor() { return color; }
	void setX1(int x) { this->x = x; }
	void setX2(int x) { this->x1 = x; }
	void setX3(int x) { this->x2 = x; }
	void setY1(int y) { this->y = y; }
	void setY2(int y) { this->y1 = y; }
	void setY3(int y) { this->y2 = y; }
	void setColor(float *c) { color = c; }

	triangle(int a, int b, int c, int d, int e, int f, float *cl) {
		x = a; x1 = b; x2 = c; 
		y = d; y1 = e; y2 = f;
		color = cl;
	}

	void createShape() {
		DrawTriangle(x,y,x1,y1,x2,y2,color);
	}
};