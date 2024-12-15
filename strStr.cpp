// we are given with the two strings needle= "sad" and haystack = "sadbutsad"
// we need to return the first occurance of the needle or if  not found -1;

//brute force would be iterating over the haystack and if we match the first occurance we can compare the needle
// if found we can return the index
class Solution {
public:
    int strStr(string haystack, string needle) {
        //get the length 
        int n = needle.size();
        int m = haystack.size();
        int prime = 1000001;
        int posFac= 1;
        int hash = 0;

        for(int i = 0 ; i < n; i++)
        {
            posFac = (posFac *26)%prime;
        }
        for(int i = 0; i < needle.size(); i++)
        {
            char c = needle[i];
            hash = (hash * 26 + (c-'a' + 1)) % prime;
        }
        int currhash = 0;

        for(int i = 0; i < haystack.size(); i++)
        {
            char in = haystack[i];
            currhash = (currhash * 26 + (in - 'a' +1)) % prime;

            if(i >= n)
            {
                char out = haystack[i-n];
                //calculate the out hash
                currhash = (currhash - ((posFac * (out-'a'+ 1)) % prime));
            }
            if(currhash < 0) currhash += prime;
            
            if(currhash == hash && haystack.substr(i - n + 1, n) == needle)
                return i-n+1;
        }
        
         return -1;
    }
   
};
//Time complexity O(N)+ for computing the hash of the needle we need to O(M)
//space complexity O(1)