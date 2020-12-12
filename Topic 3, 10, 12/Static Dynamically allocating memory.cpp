#include <iostream>

using namespace std;

int main ()
{
	// Statically allocated memeory, allocated at compile time
	int i;
	int a[10];
	
	// Dynamically allocated memeory, allocated at runtime time 
	int *iptr = new int;
	int *aptr = new int[10];
	
	// How is data allocated into them ?
	i = 5;
	a[3] = 87;
	
	aptr[3] = 97;
	*iptr = 5;
	
	// How is this used in real life  ?
	cout<< "Enter Size .. please\n";
	int size; 
	cin >> size;
	cout << "Go ahead, type them :)\n";
	int *numbersList = new int[size];
	for (i = 0;i <size;i++)
	{
		cin >> numbersList[i];
		cout << numbersList[i] << endl;
	}
	
	// Dynamic memory has to be deleted or will cause leaks 
	delete iptr;
	delete [] aptr;
	delete [] numbersList;
}
