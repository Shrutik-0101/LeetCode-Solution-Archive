/*
Trick to Remember
“Balance up on '(', balance down on ')'. Add only when inside.”

When you see '(':
→ Increase balance after checking if you’re already inside.
→ Add it only if balance > 0 (i.e., you're not at the outermost).

When you see ')':
→ Decrease balance first, then check.
→ Add it only if new balance > 0 (i.e., you're not closing the outermost).

Think: Ignore the outer layer of each bracket group. Keep the inner parts.

Approach Notes:
Problem: Remove Outermost Parentheses
Type: String traversal with nesting counter

Steps:
Initialize:
result = ""
balance = 0

For each character c in s:
If c == '(':
If balance > 0, add to result
balance++

If c == ')':
balance--

If balance > 0, add to result

Return result
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(balance > 0){
                    result += s[i];
                }
                balance++;
            }
            else{
                balance--;
                if(balance > 0){
                    result += s[i];
                }
            }
        }
        return result;
    }
};