class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        int n1=ransomNote.size();
        int n2=magazine.size();


        for(int i=0;i<n1;i++){
            m1[ransomNote[i]]++; 
        }

        for(int i=0;i<n2;i++){
            m2[magazine[i]]++; 
        }

        for(auto i:m1){
            char fir = i.first;
            int seco = i.second;

            int have = m2[fir];
            if(seco >  have){
                return false;
            }
        }

        return true;

    }
};