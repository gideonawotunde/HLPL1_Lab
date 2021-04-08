#include "std_lib_facilities.h"
//9.4.1
struct Date {
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
{
	if (d < 1 || d > 31) error("Such day does not exist");
	if (m < 1 || m > 12) error("Such month does not exist");

	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n)
{
	dd.d += n;
	if (dd.d > 31) dd.d %= 31;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
{
	Date today;
	init_day(today, 1978, 6, 25);

	Date tomorrow = today;
	add_day(tomorrow, 1);
	cout << today << '\n'
		<< tomorrow << '\n';
	//Date bad_day;
	//init_day(bad_day, 2009, 17, -32);
}
