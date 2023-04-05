#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[50];
int root = -1;
int d;
int cnt = 0;

void func(int cur){
	if(arr[cur].empty()){
	       	cnt++;
		return;
	}
	
	for(int i = 0; i < arr[cur].size(); i++){
		if(arr[cur][i] == d){
		       if(arr[cur].size() == 1) cnt++;
		       continue;
		}
		func(arr[cur][i]);
	}	
}


int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) arr[i] = vector<int>();
	for(int temp, i = 0; i < n; i++){
		cin >> temp;
		if(temp == -1) root = i;
		else arr[temp].push_back(i);
	}
	cin >> d;
	if(d == root) {
		cout << 0 << endl;
		return 0;
	}
	func(root);
	cout << cnt << endl;
	return 0;
}
