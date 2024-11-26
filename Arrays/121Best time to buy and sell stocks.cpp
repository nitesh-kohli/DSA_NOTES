#include<bits/stdc++.h>
using namespace std;

/*
Brute force approach

idea - use nested for loops (i -> 0 to n) and (j -> i+1 to n) for every ith value we buy stock 
and sell
on jth value and compare to find max

 T.C. - O(n*n)
 S.C - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] > prices[i]){
                    maxPro = max(prices[j] - prices[i],maxPro);
                }
            }
        }
        return maxPro;
    }
};


/*
Optimal approach

idea - we traverse the array from (i -> 0 to n) and we find the min value to buy stock and at the same time we try to sell stock on that ith value.
two situation occur
 - ith value is the new min and we if we sell we get profit zero.
 - ith value is greater than min value found till now and we sell on it and get some +ve profit.

so every time we also compare the profit we are getting with the maxProfit we got till so far.

T.C. - O(n)
S.C. - O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxPro = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice,prices[i]);
            maxPro = max(maxPro,prices[i] - minPrice);
        }
        return maxPro;
    }
};