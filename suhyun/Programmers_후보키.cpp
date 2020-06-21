#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int col = relation[0].size();
    int row = relation.size();
    vector<int> answer;
    for(int i=1; i<(1<<col);i++){   //조합 가능한 개수
        set<string> s;
        for(int j=0; j<row;j++){
            string tmp="";
            for(int k=0; k<col;k++){
                if(i&(1<<k)){
                    tmp+= relation[j][k];
                }
            }
            s.insert(tmp);  
            if(s.size() == row){    //s의 개수와 row 개수 같으면 유일성 만족
                bool minimality = true;
                for(int k=0; k<answer.size();k++){
                    if((answer[k] & i) == answer[k]){   //ex) 조합 0001이 이미 존재하면 0011은 최소성 만족x
                        minimality = false;
                        break;
                    }
                }
                if(minimality)      //최소성 만족
                    answer.push_back(i);
            }
        }
    }

    return answer.size();
}