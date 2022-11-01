class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
int ansIndex = 0;
int n = chars.size();

    while(i<n){
        int j= i+1;
        while(j<n && chars[i]==chars[j])
        {
            j++;
        }
        
        // yaha kab aayega
        //ya to vector puta tracverse krdia
        //ya fir new/Diffrent character encounter kia hai
        
        //oldChar store karlo
        chars[ansIndex++] = chars[i];
        
        int count = j-i;
        
        if(count >1){
            //converting counting into singal digit and saving answer
            string cnt = to_string(count);
            for(char ch: cnt){
                chars[ansIndex++] = ch;
            }
        }
        //moving to diffrent charter
        i=j;
    }
    
    return ansIndex;
}
    };
