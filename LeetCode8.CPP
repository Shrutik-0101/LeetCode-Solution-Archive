/*
Procedure:
Initialize variables i (for iterating through the string), sign (to store the sign of the number),
and ans (to accumulate the converted integer).

Skip leading whitespaces by incrementing i until a non-whitespace character is encountered.
Determine the sign of the number by checking for '-' or '+'.
Update the sign variable accordingly.

Iterate through the remaining characters of the string, converting numeric characters to integers and updating the result (ans).

Check for overflow conditions during the conversion process.
If overflow occurs, return INT_MIN or INT_MAX depending on the sign

Return the final result, considering the sign of the number.

ans = ans * 10 + (s[i] - '0');
This line is doing the main conversion of characters to an actual number:
s[i] - '0' converts the char digit (like '3') into its numeric value (3).
ans * 10 + ... shifts the previous digits left and adds the new digit.
Example:
'1' → ans = 1
'2' → ans = 1 * 10 + 2 = 12
'3' → ans = 12 * 10 + 3 = 123
*/

class Solution {
public:
    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                i++;
            }
            else
                return ans*sign;
        }
        return (ans*sign);
    }
};