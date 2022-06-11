
#include <string>
#include <unordered_set>
using namespace std;

class Solution {

public:
    int maxVowels(string input, int substringSize) {

        unordered_set<char> vowels{ 'a', 'e', 'i', 'o', 'u'};
        int currentVowels = 0;
        for (int i = 0; i < substringSize; ++i) {
            //C++20: vowels.contains(...)
            if (vowels.find(input[i]) != vowels.end()) {
                ++currentVowels;
            }
        }

        int maxVowels = currentVowels;
        int head = substringSize;
       
        while (head < input.length()) {
            if (vowels.find(input[head]) != vowels.end()) {
                ++currentVowels;
            }
            if (vowels.find(input[head - substringSize]) != vowels.end()) {
                --currentVowels;
            }
            maxVowels = max(maxVowels, currentVowels);
            ++head;
        }
        return maxVowels;
    }
};
