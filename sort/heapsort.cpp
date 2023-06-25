#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &array)
{
	int n;

	while (n != -1) {
        cin >> n;
        if (n != -1){
            		array.push_back(n);
        }


	}
}


void Heapify(vector<int> &a, int heapSize, int i, int &dem) {
	int childLeft = i * 2 + 1;
	int childRight = i * 2 + 2;
	int max = i;
	if (childLeft<heapSize && a[max]<a[childLeft])
		max = childLeft;
	if (childRight<heapSize && a[max]<a[childRight])
		max = childRight;
	if (max != i) {
        

        
        dem++;
		swap(a[max], a[i]);
		Heapify(a, heapSize, max,dem);
	}
}



void buildHeap (vector<int> &array, int n, int &count) {
	int heapSize = n;
	for (int i = n/2 - 1; i >= 0; i--)
		Heapify(array, heapSize, i,count);
}
void Sort(vector<int> &array) {
    	int count=0;
    int n=array.size();


	int heapSize= n;
	cout<<"\nN="<<heapSize<<":\t";
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << "\t";
    cout<<endl;

	buildHeap(array, heapSize,count);
	cout<<"swap: "<<count<<endl;

	for (int i = n - 1; i>0; i--) {
		swap(array[0], array[i]);
		heapSize -= 1;
        count=0;
        cout<<"\nN="<<heapSize<<":\t";
        for (int i = 0; i < array.size(); i++)
            cout << array[i] << "\t";
        cout<<endl;

		Heapify(array, heapSize, 0,count);

        cout<<"swap: "<<count<<endl;
	}
}



int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}