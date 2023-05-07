#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1001] = {0,};
int dp[1001] = {0,};
int from[1001] = {0,};

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	int r_index = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		int most  = 0;
		int index = 0;
		for(int j = 1; j < i; j++){
			if(arr[j] < arr[i] && most < dp[j]) {
				most = dp[j];
				index = j;
			}
		}
		from[i] = index;
		dp[i] = most + 1;
		if(dp[r_index] < dp[i]) r_index = i;
	}

	stack<int> s;
	int cur = r_index;
	cout << dp[cur] << endl;
	while(cur){
		s.push(arr[cur]);
		cur = from[cur];
	}
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	return 0;
}
