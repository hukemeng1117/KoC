#include <iostream>
using namespace std;

class first
{
	int a = 10;
public:
	first(int a) {
		this->a = a;
	};
};

struct test
{
	int a;
};

int main(int argc, char const *argv[])
{
	cout<<sizeof(first)<<endl;
	cout<<sizeof(test)<<endl;

	first f1 = 10;

	int a = 10;
	int& b = a;
	cout<<&b << " " << &a <<endl;
	return 0;
}