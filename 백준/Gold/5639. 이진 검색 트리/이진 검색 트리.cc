#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> nums;

void postorder(int start, int end){
    if(start >= end) return;
    int root = nums[start];
    int low = start+1, high = end;
    while(low < high){
        int mid = (low+high)>>1;
        if(nums[mid] <= root) low = mid+1;
        else high = mid;
    }
    postorder(start+1, low);
    postorder(low, end);
    cout << root << '\n';
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int x;
    while(cin >> x) nums.push_back(x);
    postorder(0, nums.size());
    return 0;
} 