class CustomStack {
public:
    int maxSize;
    stack<int> st;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if((int)st.size()<maxSize)
        {
            st.push(x);
        }
    }
    
    int pop() {
        if(!st.empty())
        {
            int ans=st.top();
            st.pop();
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        int count=0;
        for(int i=0;!st.empty();i++)
        {
            temp.push(st.top());
            st.pop();
        }
        for(int i=0;i<k && !temp.empty();i++)
        {
            count++;
            st.push(temp.top()+val);
            temp.pop();
        }
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */