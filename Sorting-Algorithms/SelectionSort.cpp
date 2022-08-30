#include<iostream>
using namespace std;

void swap(int& m, int& n){
	int temp = m;
	m =n;
	n = temp;
}

void display(int a[], int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {

	int n,min_idx;;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n;i++){

		min_idx = i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i]){
				min_idx = j;
			}
		}
		if(min_idx != i){
			swap(a[min_idx], a[i]);
		}
	}
	display(a, n);
	return 0;
// Time Complexity: O(N^2)

}