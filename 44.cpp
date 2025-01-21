class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;
        
        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                star = j;   
                match = i;  
                j++;       
            } else if (star >= 0) {
                
                j = star + 1;  
                i = ++match;   
            } else {
                return false;
            }
        }
        
        while (j < p.size() && p[j] == '*') {
            j++;
        }
                return j == p.size();
    }
};