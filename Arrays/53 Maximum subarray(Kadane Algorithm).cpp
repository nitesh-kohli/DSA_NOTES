#include<bits/stdc++.h>
using namespace std;

/*
Brute force approach
 - we use nested for loops

 T.C. - O(N^3)
 S.C. - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum += nums[k];
                }
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};

/*
Better approach
 - need only 2 nested loops
 T.C. - O(N^2)
 S.C. - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};

/*
Optimal approach (Kadane's Algorithm)

Intution - A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

The steps are as follows:
 - We will run a loop(say i) to iterate the given array.
 - Now, while iterating we will add the elements to the sum variable and consider the maximum one.
 - If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

 T.C. - O(N)
 S.C. - O(1)
 ..
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxi)  maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};