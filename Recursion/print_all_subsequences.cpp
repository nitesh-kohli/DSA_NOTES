#include<bits/stdc++.h>
using namespace std;

void printSubsequence(int index,vector<int>& ds,vector<int>& nums,int n){
    if(index == n){
        for(auto d : ds){
            cout<<d<<" ";
        }
        if(ds.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }


    //take
    ds.push_back(nums[index]);
    printSubsequence(index+1,ds,nums,n);
    // not take
    ds.pop_back();
    printSubsequence(index+1,ds,nums,n);
}

int main(){
    vector<int> nums = {1,3,5};
    // print all subsequence of nums array
    vector<int> ds;
    int n = nums.size();
    printSubsequence(0,ds,nums,n);

    return 0;
}