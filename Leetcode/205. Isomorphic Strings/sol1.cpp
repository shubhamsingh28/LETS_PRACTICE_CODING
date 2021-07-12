/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

 

Constraints:

    1 <= s.length <= 5 * 10^4
    t.length == s.length
    s and t consist of any valid ascii character.

Approch we will use 2 map 1 to save mao and other to save reverse transformation map
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int>m;
        map<char,int>rm;
        int n =s.length();
        for(int i=0;i<n;i++){
            if(m[s[i]] == 0 && rm[t[i]]==0){
                m[s[i]]=t[i]+1;
                rm[t[i]] = s[i]+1;
            }else{
                //match the transformation map
                if(m[s[i]]==t[i]+1 && rm[t[i]]==s[i]+1){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};