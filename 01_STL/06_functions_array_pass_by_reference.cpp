// Array always passes to function by pass_reference , it will not get passed to function by pass_value

#include <iostream>
using namespace std;
void fun(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		arr[i]++;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fun(arr, n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

// 2 3 4 5 6 7 8 9

