//given the string s=  "abaebadacd" and p = "abc"
// we can use two pointer approach to solve this problem 

class Solution {
public:
    bool compare(vector<int>&a,vector<int>&b)
    {
        for(int i = 0; i <26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        vector<int>scount(26,0);
        vector<int>pcount(26,0);

        int i = 0;
        
        for(char c : p)
        {
            pcount[c-'a']++;
        }
        
        while(i < s.size())
        {
            scount[s[i]-'a']++;

            if(i >=(p.size()-1))
            {
                int out = i-p.size() +1;

                if(compare(pcount,scount))
                    result.push_back(out);
                
                scount[s[out]-'a']--;
            }
            
            i++;

        }
        return result;
    }
};
//Time complexity is O(N + S) 
//space complexity O(N + S)