/*

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

*/

class Solution
{
public:
    bool isNumber(string s)
    {
        int i = 0;

        // skip the whilespaces
        for (; s[i] == ' '; i++)
        {
        }

        // check the significand
        if (s[i] == '+' || s[i] == '-')
            i++; // skip the sign if exist

        int n_nm, n_pt;
        for (n_nm = 0, n_pt = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; i++)
            s[i] == '.' ? n_pt++ : n_nm++;
        if (n_pt > 1 || n_nm < 1) // no more than one point, at least one digit
            return false;

        // check the exponent if exist
        if (s[i] == 'e')
        {
            i++;
            if (s[i] == '+' || s[i] == '-')
                i++; // skip the sign

            int n_nm = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++, n_nm++)
            {
            }
            if (n_nm < 1)
                return false;
        }

        // skip the trailing whitespaces
        for (; s[i] == ' '; i++)
        {
        }

        return s[i] == 0; // must reach the ending 0 of the string
    }
};