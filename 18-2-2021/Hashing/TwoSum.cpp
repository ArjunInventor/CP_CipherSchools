#include<bits/stdc++.h>
using namespace std;

pair<int, int> TwoSum(vector<int> &arr, int sum) {
	unordered_map<int, int> map;
    pair<int, int> result;
	for (int i = 0; i < arr.size(); i++) {
		int req = sum - arr[i];
		if (map.find(req) != map.end()) {
            result.first = arr[i];
			result.second = req;			
			return result;
		}
		map[arr[i]] = i;
	}
	return result;
}

int main() {
    vector<int> arr = {1, 2, 7,3, 6, 4, 9};
    int sum = 11;
    pair<int, int> res = TwoSum(arr, sum);
    cout<<res.first<<" "<<res.second;
    return 0;
}
