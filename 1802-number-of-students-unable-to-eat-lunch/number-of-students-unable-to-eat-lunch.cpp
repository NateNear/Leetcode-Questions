class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        stack<int> swd;

        for(auto i:students){
            stud.push(i);
        }

        for(int i=sandwiches.size()-1;i>=0;i--) 
            swd.push(sandwiches[i]);
        
        int loop=0;

        while(!stud.empty() && loop<stud.size()){
            if(swd.top() == stud.front()){
                swd.pop();
                stud.pop();
                loop=0;
            }
            else{
                stud.push(stud.front());
                stud.pop();
                loop++;
            }
        }
        return stud.size();
    }
};