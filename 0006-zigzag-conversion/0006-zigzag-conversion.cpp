class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1 or greater than or equal to the length of s
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings for each row
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0; // Current row
        bool goingDown = false; // Direction flag

        // Iterate through each character in the string
        for (char c : s) {
            rows[curRow] += c; // Place the character in the current row
            // Change direction if we are at the top or bottom row
            if (curRow == 0) {
                goingDown = true; // Start going down
            } else if (curRow == numRows - 1) {
                goingDown = false; // Start going up
            }
            // Move to the next row
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to get the final result
        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};