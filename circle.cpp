#include "shape.cpp"

class circle: public shape {
	int radius;
	float *color;

public: 
	circle() {
		x = 0;
		y = 0;
		radius = 0;
		color = NULL;
	}

	circle(int x, int y, int r, float *c) {
		this->x = x;
		this->y = y;
		radius = r;
		color = c;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getRadius() { return radius; }
	float *getColor() { return color; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setRadius(int r) { radius = r; }
	void setColor(float *c) { color = c; }

	void createShape() {
		DrawCircle(x,y,radius,color);
	}
}; 