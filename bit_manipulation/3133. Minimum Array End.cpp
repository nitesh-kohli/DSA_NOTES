class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        // we run loop from 1 to n-1
        // ptr_x is pointer on bits of x
        // ptr_n is pointer on bits of n
        for(long long ptr_x = 1,ptr_n = 1; ptr_n < n;ptr_x <<= 1){
            // check if x's bit is set or not
            if((ptr_x & x) == 0){
                // now that means bit is 0 and we can change it
                // into n-1's bit
                if(ptr_n & (n-1)){
                    //if bit is 1 that means we have to change
                    //this code is for kisme change krna h 0 mai ya 
                    // 1 mai , agr n-1's bit mai 1 h tabhi change krunga

                    res += ptr_x;
                    // isse kya hoga , isse wo wali bit change hogi jo 0 thi
                }
                ptr_n <<= 1;
            }
        }

        return res;
    }
};