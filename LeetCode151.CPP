/*
Trick to Remember Pattern
"Split → Reverse → Join"

Just like:
Break the sentence into words
Reverse the list
Join them back with single space

Goal: Return sentence with words in reverse order, no extra spaces.

Approach:
Split the string by spaces
Use istringstream or manual loop
Skip empty strings
Reverse the vector of words
Join words with single spaces between them
*/

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        int left = 0, right = words.size() - 1;
        while (left < right) {
            swap(words[left], words[right]);
            left++;
            right--;
        }

        string result;
        for (const string& w : words) {
            if (!result.empty()) {
                result += " ";
            }
            result += w;
        }

        return result;
    }
};