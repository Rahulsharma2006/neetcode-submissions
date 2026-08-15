class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        int freq[26] = {0};
        int freq2[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windowsize = s1.length();
        for (int i = 0; i < windowsize; i++) {
            freq2[s2[i] - 'a']++;
        }

        for (int i = windowsize; i < s2.length(); i++) {
            bool match = true;
            for (int k = 0; k < 26; k++) {
                if (freq[k] != freq2[k]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
            freq2[s2[i] - 'a']++;
            freq2[s2[i - windowsize] - 'a']--;
        }

        for (int k = 0; k < 26; k++) {
            if (freq[k] != freq2[k]) return false;
        }

        return true;
    }
};

 
