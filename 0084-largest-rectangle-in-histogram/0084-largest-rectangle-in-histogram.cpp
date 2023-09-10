class Solution {
vector<int> nextSmallerElement(vector<int> &heights, int n){
        vector<int> next(n);
        stack<int> st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }

 vector<int> prevSmallerElement(vector<int> &heights, int n){
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int area = 0;

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        for(int i = 0; i<n; i++){
            int length = heights[i];
           
            if(next[i] == -1)
            next[i] = n;

            int breadth = next[i]-prev[i]-1;

            int newArea = length * breadth;

            area = max(area, newArea);
        }

        return area;
    }
};