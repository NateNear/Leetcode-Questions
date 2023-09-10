class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> heights(m, 0);
        int area = maxRectangleAreaInHistogram(heights, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += matrix[i][j] - '0';
                }
            }
            area = max(area, maxRectangleAreaInHistogram(heights, m));
        }
        return area; 
    }

    void nextSmallestElementIndex(vector<int> &heights, vector<int> &next, int n){
        
        stack<int> s;
        s.push(n);
        
        for(int i = n - 1; i >= 0; i--){
            while(s.top() != n && heights[s.top()] >= heights[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
    }

    void prevSmallestElementIndex(vector<int> &heights, vector<int> &prev, int n){

        stack<int> stack;
        stack.push(-1);

        for(int i = 0; i < n; i++){
            while(stack.top() != -1 && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            prev[i] = stack.top();
            stack.push(i);
        }
    }

    int maxRectangleAreaInHistogram(vector<int> &heights, int n){

        vector<int> next(n, 0);
        nextSmallestElementIndex(heights, next, n);

        vector<int> prev(n, 0);
        prevSmallestElementIndex(heights, prev, n);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (heights[i]*(next[i] - prev[i] - 1)));
        }
        return ans;
    }
};