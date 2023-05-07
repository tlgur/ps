#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[1000001] = {0,};
vector<pair<int ,int>> dp;
int from[1000001] = {0,};

void renew_upper_bound(int target, int index){
	int left = 0;
	int right = dp.size() - 1;
	
	int mid;
	while(left + 1 < right){
		mid = (left + right) / 2;
		
		if(target <= dp[mid].first) right = mid;
		else left = mid;
	}
	from[index] = dp[right - 1].second;
	dp[right] = {target, index};
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	dp.push_back({INT_MIN, 0});
	for(int i = 1; i <= n; i++){
		int temp = arr[i];
		if(dp.back().first < temp) {
			from[i] = dp.back().second;
			dp.push_back({temp, i});
		}
		else renew_upper_bound(temp, i);
	}
	
	cout << dp.size() - 1<< endl;
	int cur = dp.back().second;
	stack<int> s;
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
