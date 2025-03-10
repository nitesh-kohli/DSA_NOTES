#include<bits/stdc++.h>
using namespace std;

void printSubset(int i, int n, vector<int>& nums, vector<int>& temp){
    if( i == n){
        if(temp.size() == 0){
            cout<<"null"<<"\n";
        }
        for(int num : temp)
            cout<<num<<" ";
        cout<<"\n";
        return;
    }

    //inclusion
    temp.push_back(nums[i]); 
    printSubset(i+1,n,nums,temp);

    temp.pop_back();//backtrack

    //skipping duplicate values
    int idx  = i + 1;
    while(idx < nums.size() && nums[idx] == nums[idx - 1])  idx++;


    //exclusion
    printSubset(idx,n,nums,temp);
}

int main(){
    vector<int> nums = {1,2,2};
    vector<int> temp = {};
    printSubset(0,nums.size(),nums,temp);

    return 0;
}

/*
intution:-
1) we have to skip duplicate subsets
2) for that we first have to understand where the duplicates coming from
3) in one step if we chose to exclude a value we have to exclude it no matter how many time it will
come in future.
4) for that elements should arrange in sorted order

time complexity:
sorting the array + (total calls * work done in each call)
O(nlogn) + O(2^n * 1)

T.C. =  O(2^n)
S.C. = O(2^n)

*/