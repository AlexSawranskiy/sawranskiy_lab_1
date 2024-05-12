#include <iostream>
#include <cmath>

using namespace std;

class Sphere
{
private:
	double radius;

public:
	Sphere(double r) : radius(r) {}

	double getRadius() const
	{
		return radius;
	}

	void SetRadius(double r)
	{
		if (r > 0)
		{
			radius = r;
		}
		else
		{
			cout << "Radius must be a positive number" << endl;
		}

	}

	double surfaceArea() const
	{
		return 4 * M_PI * radius * radius;
	}

	double volume() const
	{
		return (4.0 / 3.0) * M_PI * radius * radius * radius;
	}
};

int main()
{
	double radius;
	cout << "Enter the radius of the sphere: ";
	cin >> radius;
	Sphere mySphere(radius);

	cout << "Surface area of ​​a sphere: " << mySphere.surfaceArea() << endl;
	cout << "Volume of the sphere: " << mySphere.volume() << endl;

	double newRadius;
	cout << "Enter new radius of the sphere: ";
	cin >> newRadius;
	mySphere.SetRadius(newRadius);

	cout << "New radius of the sphere: " << mySphere.getRadius() << endl;
	cout << "The new surface area of ​​the sphere: " << mySphere.surfaceArea() << endl;
	cout << "New volume of the sphere: " << mySphere.volume() << endl;

	return 0;

}