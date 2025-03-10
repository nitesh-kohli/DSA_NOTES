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

    //exclusion
    printSubset(i+1,n,nums,temp);
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> temp = {};
    printSubset(0,nums.size(),nums,temp);

    return 0;
}

/*
intution:-
1) we have to print all possible subset of a set.
2) there are 2^n subsets of a set size n.
3) if set has 3 elements there will be 2^3 = 8 subsets.
4) that means all the 3 elements has 2 choices include or exclude.
5) so we apply include exclude algorithm for each element of the array.


time complexity:-
total calls * work done in each call
2^n calls for each subset and getting that subset the work in constant O(1)

T.C. - O(2^n) * O(1)
S.C. - O(2^n) for recursion stack
















*/