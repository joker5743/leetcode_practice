// 17 电话号码的字母组合

#include <vector>
#include<unordered_map>
#include<string>
using namespace std;

class LetterCombinations
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations;
        if(digits.empty())
            return combinations;

        unordered_map<char, string> phonemap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phonemap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string> & combinations, const unordered_map<char, string> &phoneMap, const string& digits, int index, string& combination)
    {
        if(index == digits.length()){
            combinations.push_back(combination);
        }
        else{
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for(const char& letter: letters){
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index+1, combination);
                combination.pop_back();
            }
        }
    }
};