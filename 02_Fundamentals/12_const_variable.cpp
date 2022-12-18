#include <iostream>
using namespace std;

int main()
{

	// const int x; CTE error
	// x = 9; CTE error
	const int y = 10;
    // y++; <- It will return error 
	cout << y;

	return 0; 
}
// 10
