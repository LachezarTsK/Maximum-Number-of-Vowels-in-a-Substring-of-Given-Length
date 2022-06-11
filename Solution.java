
import java.util.Set;

public class Solution {

    public int maxVowels(String input, int substringSize) {

        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        int currentVowels = 0;
        for (int i = 0; i < substringSize; ++i) {
            if (vowels.contains(input.charAt(i))) {
                ++currentVowels;
            }
        }

        int maxVowels = currentVowels;
        int head = substringSize;
 
        while (head < input.length()) {
            if (vowels.contains(input.charAt(head))) {
                ++currentVowels;
            }
            if (vowels.contains(input.charAt(head - substringSize))) {
                --currentVowels;
            }
            maxVowels = Math.max(maxVowels, currentVowels);
            ++head;
        }
        return maxVowels;
    }
}
