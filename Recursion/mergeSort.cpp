#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }
    while(left <= mid)
        temp.push_back(nums[left++]);
    while(right <= high)
        temp.push_back(nums[right++]);
    
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& nums,int low,int high){
    // divide
    if(low == high) return;
    int mid = (low + high)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

int main(){
    vector<int> nums = {10,1,5,11,20,23,7};
    int n = nums.size();
    mergeSort(nums,0,n-1);

    for(auto num : nums){
        cout<<num<<" ";
    }
    return 0;
}