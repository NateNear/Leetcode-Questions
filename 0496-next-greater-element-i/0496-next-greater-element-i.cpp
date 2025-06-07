class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i=0; i<nums2.size(); i++){
            
            while (!st.empty() && nums2[i] > st.top()){
                int temp = st.top();
                st.pop();
                mp[temp] = nums2[i];
            }
            st.push(nums2[i]);
            
        }

        for(int i=0;i <nums1.size(); i++){
            if (mp.find(nums1[i]) != mp.end()) {
                ans.push_back(mp[nums1[i]]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};