class Solution {
public:
    int romanToInt(string s) {
        int a=0;
        unordered_map<char, int> number = {
            {'I',1}, {'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
            for(int i=0;i<s.size()-1;i++){
                if(number[s[i]] < number[s[i+1]]){
                    a-=number[s[i]];
                }else{
                    a+=number[s[i]];
                }
            }
        return a+number[s[s.size()-1]];
    }
};