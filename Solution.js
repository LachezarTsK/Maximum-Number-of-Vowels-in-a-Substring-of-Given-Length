
/**
 * @param {string} input
 * @param {number} substringSize
 * @return {number}
 */
var maxVowels = function (input, substringSize) {

    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let currentVowels = 0;
    for (let i = 0; i < substringSize; ++i) {
        if (vowels.has(input.charAt(i))) {
            ++currentVowels;
        }
    }

    let maxVowels = currentVowels;
    let head = substringSize;

    while (head < input.length) {
        if (vowels.has(input.charAt(head))) {
            ++currentVowels;
        }
        if (vowels.has(input.charAt(head - substringSize))) {
            --currentVowels;
        }
        maxVowels = Math.max(maxVowels, currentVowels);
        ++head;
    }
    return maxVowels;
};
