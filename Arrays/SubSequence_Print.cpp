/* Program to store all subSequence in the array and print the elements

Input: 2
       1 2

Output: 1 2
	    1
	    2
	    {} */


#include<iostream>
#include<vector>
using namespace std;

void all_seq(int a[], int index, vector<int> &v,int n, vector<vector<int>> &ans){
	if(index == n){
		ans.push_back(v);
		return;
	}
	else{
		// include
		v.push_back(a[index]); 
		all_seq(a,index+1, v, n,ans); 
		// exclude 
		v.pop_back();
		all_seq(a,index+1,v,n,ans);
	}

}

int main() {
	int n;
	cin >> n;
	int a[n];
	vector<int> v;
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	all_seq(a, 0, v, n,ans);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		if(ans[i].size() == 0){
			cout << "{}";
		}
		cout << endl;
	}
	return 0;
}