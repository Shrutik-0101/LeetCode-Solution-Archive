/*
Trick to Remember
Cut-Paste Hack:
If goal is a rotation of s, then it must be a substring of s + s.
So, checking rotation becomes a substring search.

Why Use KMP?
Brute force takes O(n*m) — slow
KMP uses LPS array to skip unnecessary comparisons
KMP = Smart Search = O(n + m)

Steps / Notes for CP Notebook
Check lengths
If len(s) != len(goal): return false
Concatenate
doubled = s + s
Why? All possible rotations are inside this

KMP Search (goal inside doubled)
If yes, return true, else false

LPS Array Trick (For Pattern)
LPS[i] = length of longest prefix = suffix ending at i

Helps skip rechecking already matched parts

Example: "abab" → LPS: [0, 0, 1, 2]

Memory Triggers:
KMP = LPS + Pattern Jumping
Rotation? Double the string & search it.
No match? Don’t restart, LPS helps slide smartly
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of both strings are different; if so, they can't
        // be rotations
        if (s.length() != goal.length()) return false;

        // Concatenate 's' with itself to create a new string containing all
        // possible rotations
        string doubledString = s + s;

        // Perform KMP substring search to check if 'goal' is a substring of
        // 'doubledString'
        return kmpSearch(doubledString, goal);
    }

private:
    bool kmpSearch(string& text, string& pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        vector<int> lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            // If there's a mismatch after some matches, use the LPS array to
            // skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }
        // Pattern not found in text
        return false;
    }

    vector<int> computeLPS(string& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern[index] == pattern[length]) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
};