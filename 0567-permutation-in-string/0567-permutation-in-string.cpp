class Solution {
private:
    bool checkEqual(int a[], int b[]){
        for(int i = 0; i<26; i++){
            if(a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        
        int count1[26] = {0};
        //creating an array of character count.
        for(int i = 0; i<s1.length(); i++){
            int ind = s1[i] - 'a';
            count1[ind]++;
        }
        
        int window = s1.length();
        //traversing s2 for windows size of length s1, 1st window.
        
        int i = 0;
        int count2[26] = {0};
        
        while(i<window && i<s2.length()){
            
            int ind = s2[i] - 'a';
            count2[ind]++;
            i++;
            }
         //check karlo kahi equal to nahi ho gaya? nahi hua to aage wali window pe jaao.
        if (checkEqual(count1, count2)){
                return 1;
        }
        
        while(i<s2.length()){
            //new window mai aane wala char ka count badhao
            int index = s2[i] - 'a';
            count2[index]++;
            
            //puran window wala character ka count kam karo
            char old = s2[i-window];
            index = old - 'a';
            
            count2[index]--;
            i++;
            
            //ab to nahi ho gaya equal? check karlo.
            if (checkEqual(count1, count2)){
                return 1;
        }
            
        }
        return 0;
    }
};