/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.


    Try to solve it in O(n log k) time and O(n) extra space.

Solution : 

We will construct 2 map . 1 for counting the words and another for frequency of the words. We will iterate through the 
second map from the back and push it to ans ;

*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        map<int,vector<string>>m1;

        for(string s:words) {
            m[s]++;
        }

        for(auto i: m) {
            string x= i.first;
            int y= i.second;
            m1[y].push_back(x);
        }

        int c=0;
        vector<string>ans;
        for (auto it = m1.rbegin(); it != m1.rend(); it++) {
            vector<string>temp = it->second;
            sort(temp.begin(),temp.end());
            for(auto s: temp){
                ans.push_back(s);
                c++;
                if(c==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};