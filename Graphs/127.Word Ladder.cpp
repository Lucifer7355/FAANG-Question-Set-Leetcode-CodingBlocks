class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        set<string> s;
        for(auto i : wordList){
            s.insert(i);
        }
        while(!q.empty()){
            pair<string,int> x = q.front();
            q.pop();
            vector<string> neighbours = transformations(s,x.first);
            cout<<x.first<<" : ";
            for(auto s : neighbours){
                cout<<s<<" ";
            }
            cout<<endl;
            for(auto s : neighbours){
                if(endWord == s){
                    return x.second + 1;
                }
                q.push(make_pair(s,x.second+1));
            }
        }
        return 0;
    }

    vector<string> transformations(set<string>& s,string word){
        vector<string> neighbours;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            for(char ch='a';ch<='z';ch++){
                if(c==ch){
                    continue;
                }
                word[i] = ch;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    neighbours.push_back(word);
                }
            }
            word[i] = c;
        }
        return neighbours;
    }

};
