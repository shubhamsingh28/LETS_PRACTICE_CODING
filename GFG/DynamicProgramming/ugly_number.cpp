/*
Ugly Numbers

    Difficulty Level : Medium

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
shows the first 11 ugly numbers. By convention, 1 is included. 
Given a number n, the task is to find n’th Ugly number.

Examples:  

Input  : n = 7
Output : 8

Input  : n = 10
Output : 12

Input  : n = 15
Output : 24

Input  : n = 150
Output : 5832


Algo: We can write a brute force approch in which we can check each indivisual number and increment 
the counter until out counter reach ans
TC: O(n)
SC: O(1)

Approch 2: we can use a set to store the ugly number. We will use set default propery that it's sorted and unique value 
we will always get the top element as the minimum.
We didn't choose min heap because the data can be repeated in the min heap
for eg: both 2 and 3 will push 6 in pq.

*/

// CPP program to find nth ugly number
#include <bits/stdc++.h>
using namespace std;
 
lass Solution{
public:	
	ull getNthUglyNo(int n) {
	    set<ull> s;
	    if(n==1){
	        return n;
	    }
	    n--;
	    s.insert((ull)1);
	    while(n--){
	        auto it = s.begin();
	        ull x= *it;
	        s.erase(it);
	        s.insert(x * 2);
	        s.insert(x * 3);
	        s.insert(x * 5);
	        
	    }
	    return *(s.begin());
	}
};