class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int sum = (numRows - 1) * 2;
        int delta = 0;
        
        if (sum == 0) {
            sum = 1;
        }
        
        for (int i = 0; i < numRows; ++i) {
            int index = i;
            bool addSum = true;
            bool addElement = true;
            
            while (index < s.size()) {
                if (addElement) {
                    res += s[index];
                }
                addElement = true;
                
                int newIndex = index;
                
                if (addSum) {
                    newIndex += sum;
                    addSum = false;
                }
                else {
                    newIndex += delta;
                    addSum = true;
                }
                
                if (newIndex == index) {
                    addElement = false;
                }
                
                index = newIndex;
            }
            
            sum -= 2;
            delta += 2;
        }
        
        return res;
    }
};
