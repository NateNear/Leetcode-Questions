class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int cnt =0;
        int bqtCnt = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bqtCnt += (cnt/k);
                cnt = 0;
            }
        }
        bqtCnt += (cnt/k);

        return bqtCnt >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long val = m * 1LL * k * 1LL;

        if (val > bloomDay.size()) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int s = mini;
        int e = maxi;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(possible(bloomDay, m, k, mid)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};