class Solution {
public:

    string encode(vector<string>& strs) {

        string out = "";

        for(int i = 0; i<strs.size(); i++){
            out += to_string(strs[i].size()) + '#' + strs[i];
        }

        return out;

    }

    vector<string> decode(string s) {

        int i = 0;

        vector<string> out;

        while(i<s.size()){

            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j-i));

            i = j+1;
            j = i+length;
            out.push_back(s.substr(i, length));

            i = j;
        }

        return out;

    }
};
