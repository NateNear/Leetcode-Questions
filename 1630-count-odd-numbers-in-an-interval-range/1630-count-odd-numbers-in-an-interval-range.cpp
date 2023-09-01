class Solution {
public:
    int countOdds(int low, int high) {
        int count  = ((high+1)/2) - (low/2);

        // while(low<=high){
        //     if(low%2 == 0){
        //         low++;
        //     }
        //     else{
        //         low++;
        //         count++;
        //     }
        // }
        return count;
    }
};