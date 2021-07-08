struct Cmp {
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        if(p1.second != p2.second) return p1.second > p2.second;
        else return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(string& word : words) m[word]++;
        vector<pair<string, int>> sorted_list(m.begin(), m.end());
        sort(sorted_list.begin(), sorted_list.end(), Cmp());
        vector<string> res;
        for(int i = 0; i < k; i++) res.push_back(sorted_list[i].first);
        return res;
    }
};
