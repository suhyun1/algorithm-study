#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int col = relation[0].size();
    int row = relation.size();
    vector<int> answer;
    for(int i=1; i<(1<<col);i++){   //���� ������ ����
        set<vector<string> > s;     
        for(int j=0; j<row;j++){
            vector<string> attribute_val;   //�Ӽ�����
            for(int k=0; k<col;k++){
                if(i&(1<<k)){
                    attribute_val.push_back(relation[j][k]);
                }
            }
            s.insert(attribute_val);  
            if(s.size() == row){    //s�� ������ row ���� ������ ���ϼ� ����
                bool minimality = true;
                for(int k=0; k<answer.size();k++){
                    if((answer[k] & i) == answer[k]){   //0001�� �̹� �����ϸ� 0011�� �ּҼ� ����x
                        minimality = false;
                        break;
                    }
                }
                if(minimality)      //�ּҼ� ����
                    answer.push_back(i);
            }
        }
    }

    return answer.size();
}