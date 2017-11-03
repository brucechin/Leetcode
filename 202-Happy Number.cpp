/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

// set记录一下出现过哪些，一旦重复就肯定进入循环
class Solution {
public:
    set<int> record;
    bool isHappy(int n) {
        record.insert(n);
        int result = 0,flag=0;
        while(n!=0){
            flag = n % 10;
            n = n / 10;
            result += flag * flag;
        }
        if(result == 1)return true;
        if(record.find(result) != record.end()){
            return false;
        }else{
            return isHappy(result);
        }
    }
};
