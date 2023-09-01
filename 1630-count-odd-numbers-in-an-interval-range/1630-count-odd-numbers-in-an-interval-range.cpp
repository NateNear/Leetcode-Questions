class Solution {
public:
    int countOdds(int low, int high) {
        int count  = 0;

        while(low<=high){
            if(low%2 == 0){
                low++;
            }
            else{
                low++;
                count++;
            }
        }
        return count;
    }
};