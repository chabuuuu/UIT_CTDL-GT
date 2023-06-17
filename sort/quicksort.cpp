#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

void quickSort(vector<int> &array, int l, int r, int &dem){
    int pivot=array[(l+r)/2];


    int i=l, j=r;
    dem++;
     cout<<"["<<l<<" - "<<r<<"]: ";
    while(i<j){

        while(array[i]< pivot) i++;
        while(array[j]> pivot) j--;
        if(i<=j) {
            swap(array[i], array[j]);
            i++;j--;
        }
    }
    for (int i = l; i <= r; i++)
        cout << array[i] << "\t";

    cout<<"\n";

    if(l<j) quickSort(array, l, j,dem);
    if(i<r) quickSort(array, i, r,dem);
}


void Sort(vector<int> &array)
{
     int dem=0;
	quickSort(array,0,array.size()-1,dem);
}


int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}