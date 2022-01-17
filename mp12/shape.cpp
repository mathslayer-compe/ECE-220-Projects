#include "shape.hpp"



//Base class
//Please implement Shape's member functions
//constructor, getName()


//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable 

Shape::Shape(string name){
	name_=name;
}

string Shape::getName(){
	return name_;
}


//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Rectangle::Rectangle(double width, double length): Shape("Rectangle"){
	width_=width;
	length_=length;
}

double Rectangle::getArea()const{
	return length_*width_;
}

double Rectangle::getVolume()const{
	return 0;
}

Rectangle Rectangle::operator + (const Rectangle& rec){
	double width=width_+rec.width_;
	double length= length_+rec.length_;
	return Rectangle(width,length);
}

Rectangle Rectangle::operator - (const Rectangle& rec){
	double width=fmax(0,width_-rec.width_);
	double length=fmax(0,length_-rec.length_);
	return Rectangle(width,length);
}



double Rectangle::getWidth()const{return width_;}
double Rectangle::getLength()const{return length_;}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Circle::Circle(double radius):Shape("Circle"){
	radius_=radius;
}

double Circle::getArea()const{
	return M_PI*radius_*radius_;
}

double Circle::getVolume()const{
	return 0;
}

Circle Circle::operator + (const Circle& cir){
	double radius=radius_+cir.radius_;
	return Circle(radius);
}

Circle Circle::operator - (const Circle& cir){
	double radius=fmax(0, radius_-cir.radius_);
	return Circle(radius);
}

double Circle::getRadius()const{return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Sphere::Sphere(double radius):Shape("Sphere"){
	radius_=radius;
}

double Sphere::getArea()const{
	return 4*M_PI*radius_*radius_;
}

double Sphere::getVolume()const{
	return (4.0/3.0)*M_PI*radius_*radius_*radius_;
}

Sphere Sphere::operator + (const Sphere& sph){
	double radius=radius_+sph.radius_;
	return Sphere(radius);
}

Sphere Sphere::operator - (const Sphere& sph){
	double radius=fmax(0, radius_-sph.radius_);
	return Sphere(radius);
}


double Sphere::getRadius()const{return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

RectPrism::RectPrism(double width, double length, double height):Shape("RectPrism"){
	length_=length;
	width_=width;
	height_=height;
}

double RectPrism::getArea()const{
	return 2*((width_*length_)+(height_*length_)+(height_*width_));
}

double RectPrism::getVolume()const{
	return width_*length_*height_;
}

RectPrism RectPrism::operator + (const RectPrism& rectp){
	double length=length_+rectp.length_;
	double width=width_+rectp.width_;
	double height=height_+rectp.height_;
	return RectPrism(width, length, height);
}

RectPrism RectPrism::operator - (const RectPrism& rectp){
	double length=fmax(0, length_-rectp.length_);
	double width=fmax(0, width_-rectp.width_);
	double height=fmax(0, height_-rectp.height_);
	return RectPrism(width, length, height);
}

double RectPrism::getWidth()const{return width_;}
double RectPrism::getHeight()const{return height_;}
double RectPrism::getLength()const{return length_;}


 
// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects 
vector<Shape*> CreateShapes(char* file_name){
	//@@Insert your code here
	ifstream myfile(file_name);
	vector<Shape*> shapes;
	Shape* shape_ptr;
	int r;
	myfile >> r;
	for(int i=0; i<r; i++){
		string name;
		myfile >> name;
		if(name=="Rectangle"){
			double width, length;
			myfile >> width >> length;
			shape_ptr= new Rectangle(width, length);
		}
		if(name=="Circle"){
			double radius;
			myfile >> radius;
			shape_ptr= new Circle(radius);
		}
		if(name=="Sphere"){
			double radius;
			myfile >> radius;
			shape_ptr=new Sphere(radius);
		}
		if(name=="RectPrism"){
			double width, length, height;
			myfile >> width >> length >> height;
			shape_ptr= new RectPrism(width, length, height);
		}
		shapes.push_back(shape_ptr);

	}
	myfile.close();
	return shapes;


}

// call getArea() of each object 
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
	//@@Insert your code here
	double temp;
	for(int i=0; i<shapes.size(); i++){
		temp=shapes[i]->getArea();
		if(temp>max_area){
			max_area=temp;
		}
	}
	return max_area;
}


// call getVolume() of each object 
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here
	double temp;
	for(int i=0; i<shapes.size(); i++){
		temp=shapes[i]->getVolume();
		if(temp>max_volume){
			max_volume= temp;
		}
	}

	
	return max_volume;
}

