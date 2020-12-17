#ifndef shape_cpp 
#define shape_cpp

class shape {
protected:
	int x, y; 
	
public:
	virtual void createShape() = 0;
};

#endif
