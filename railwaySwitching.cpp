#include <iostream>
#include <stack>
using namespace std;

int count = 0;
void railwaySwitching(int num);
void permutation(int *arr, int start, int size);
bool isValid(int *arr, int size);
void print(int *arr, int size);

int main()
{
	int numOfCars;
	cout << "Please enter the number of cars:" << endl; 
	cin >> numOfCars;
	
	cout << endl << "The possible results:" << endl;
	railwaySwitching(numOfCars);
	cout << endl << count << " ways in all." << endl;
	return 0;
}

void railwaySwitching(int num)
{
	int *arr = new int[num];
	for (int i = 0; i < num; ++i)
		arr[i] = i + 1;
	
	permutation(arr, 0, num);
	
	delete []arr;
}

void permutation(int *arr, int start, int size)
{
	if ( start == size - 1 && isValid(arr, size) )
	{
		print(arr, size);
		count++;
		return;
	}
	
	for (int i = start; i < size; ++i)
	{
		int temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		
		permutation(arr, start + 1, size);
		
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
	}
}

bool isValid(int *arr, int size)
{
	int index = 0;
	
	stack<int> s;
	for (int i = 1; i <= size; ++i)
	{
		s.push(i);
		while ( !s.empty() && s.top() == arr[index] ) {
			s.pop();
			index++;
		} 
	}
	
	return s.empty();
}

void print(int *arr, int size)
{
	for (int i = 0; i < size; ++i )
		cout << arr[i] << " ";
	cout << endl;
}
