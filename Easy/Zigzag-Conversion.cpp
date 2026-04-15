// Link: https://leetcode.com/problems/zigzag-conversion
// Problem: Zigzag Conversion
// Difficulty: Medium

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        std::vector<std::string> rows(numRows);
        
        bool goingDown = true;  
        int currentRow = 0;        
        
        for (int i = 0; i < s.length(); i++) {
            rows[currentRow].push_back(s[i]);
            
            if (currentRow == numRows - 1) {
                goingDown = false;   
            }
            else if (currentRow == 0) {
                goingDown = true;    
            }
            
            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }
        
        std::string result;
        for (std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};