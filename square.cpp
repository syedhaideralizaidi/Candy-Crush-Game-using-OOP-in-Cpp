#include "shape.cpp"

class square: public shape {
	int size;
	float *color;
	
public:
	square() {
		x = 0;
		y = 0;
		size = 0;
		color = 0;
	}

	square(int x, int y, int s, float *c) {
		this->x = x;
		this->y = y;
		size = s;
		color = c;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getSize() { return size; }
	float *getColor() { return color; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setSize(int s) { size = s; }
	void setColor(float *c) { color = c; }

	void createShape() {
		DrawSquare(x, y, size, color);
	}
};
