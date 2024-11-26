#include<bits/stdc++.h>
using namespace std;

/*
Brute force approach

- sorting , apply any sorting algorithm like merge sort etc.

T.C. - O(nlogn)
S.C. - O(1)
*/

/*
Better approach

- keeping count of values
- there are only 3 types of values so we will keep count of them and repopulate the array with the values

T.C. - O(N) + O(N)
S.C. - O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0,count1 = 0,count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) count0++;
            if(nums[i] == 1) count1++;
            else count2++;
        }

        for(int i = 0; i < count0; i++) nums[i] = 0;
        for(int i = count0; i < count0 + count1; i++) nums[i] = 1;
        for(int i = count0 + count1; i < nums.size(); i++) nums[i] = 2;
    }
};


/*
optimal approach (Dutch national flag algorithm)

- this algorithm contains 3 pointers and 3 rules:-
    3 pointers - low, mid, high
    3 rules
          0 ... low - 1  -> contains 0
          low ... mid - 1 -> contains 1
          high + 1 ... n - 1 -> contains 2

          mid ... high -> unsorted part

    0   0   0       1    1    1      0     0        2      2     2    2
    0       low-1   low       mid-1  mid   high     high+1            n-1

    steps :-
     - we will run a loop that will continue until mid <= high.
     - There can be three different values of mid pointer
        - arr[mid] == 0 -> swap(arr[mid],arr[low]) mid++,low++
        - arr[mid] == 1 -> mid++
        - arr[mid] == 2 -> swap(arr[mid],arr[high]),high--

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //3 pointers
        int low = 0, mid = 0, high = nums.size() - 1;
        //0 to low-1 - 000
        //low to mid-1 - 111
        //mid to high-1 - unsorted part
        // high to n-1 - 222
        //between mid and high we have unsorted part which we are trying to sort
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};



int main(){
    return 0;
}