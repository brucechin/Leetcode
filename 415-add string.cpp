class Solution {
public:
    string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    int sum = 0;
    while(i>=0 || j>=0 || carry){
        sum =0;

        if(i >= 0){sum += (num1[i--] - '0');}
        if(j >= 0){sum += (num2[j--] - '0');}
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        res =  (char)('0'+sum) + res;
        }
    return res;
    }
};
