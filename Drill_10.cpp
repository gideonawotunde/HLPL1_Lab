#include "std_lib_facilities.h"

//1) Define the data type, Point.
class Point {
public:
	int x;
	int y;
} ;
ostream& operator<<(ostream& os, Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}
int main()
try {
	//2) Prompt the user to input seven(x,y) pairs and store them in a vector called original_points.
	cout << "Dear user, we kindly ask you to input 7(x,y) pairs" << endl;
	vector<Point> original_points;
	int i = 1;
	for (i = 1; i < 8; i++)
	{
		char ch1, ch2, ch3;
		int xx, yy;
		cin >> ch1 >> xx >> ch2 >> yy >> ch3;
		original_points.push_back(Point{ xx, yy });
	}
	// 3) Print the data in original_points
	cout << "Print out the original points:" << endl;
	for (auto e : original_points)
		cout << e << " ";

	//4) Output the points to "mydata.txt".
	string fname = "mydata.txt";
	ofstream opp{ fname };
	if (!opp) error("Cannot open file: ", fname);
	for (Point P : original_points)
		opp << P;
	
	//5) Close the ofstream
	opp.close();
	vector<Point> processed_points;

	//Open an ifstream for mydata.txt
	ifstream ipp{ fname };
	if (!ipp) error("Cannot open input file: ", fname);
	for (i = 1; i < 8; i++)
	{
		int xx, yy;
		char ch1, ch2, ch3;
		ipp >> ch1 >> xx >> ch2 >> yy >> ch3;
		processed_points.push_back(Point{ xx,yy });
	}
	//6) Print out the data elements from both vectors.
	cout << "Print out the data elements:" << endl;
	for (auto p : processed_points)
		cout << p << " ";

	cout << "Print out the original points:" << endl;
	for (auto e : original_points)
		cout << e << " ";
	
	//7)Comparison of Original points, and Processed points
	if (original_points.size() != processed_points.size())
		cout << "Something's wrong!\n";
}
catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Something terrible has happened!\n";
	return 2;
}