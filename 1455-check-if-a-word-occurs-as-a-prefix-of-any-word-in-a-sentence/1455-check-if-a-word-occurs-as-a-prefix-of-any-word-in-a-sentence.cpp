class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        
        stringstream ss(sentence);
        string word;
        int index = 0;

        while (ss >> word) {
            index++;
         
            if (word.substr(0, searchWord.size()) == searchWord) {
                return index;
            }
        }

        return -1;
        
    }
};