#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //사전순 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size();i++){
        if(participant[i]!=completion[i]){
            answer = participant[i];
            if(i==participant.size()-1)
                cout << completion[i] <<"dd";
            break;
        }        
        
    }
    
 
    return answer;
}