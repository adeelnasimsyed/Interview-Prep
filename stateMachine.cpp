#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

class StateMachine{
    private:
        int startState;
        int currentState;
        map<pair<int, char>, int> transitions;
    
    public:
        StateMachine(int sS, vector<tuple<int, char, int>> vec)
        {
        
            startState = sS;
            currentState = sS;
        
            for(auto entry: vec)
            {
                cout<< get<0>(entry) <<endl;
            
                transitions[{get<0>(entry), get<1>(entry)}] = get<2>(entry);
            }
        
        }
    
        bool isAccepted(char check)
        {
        
            auto itr = transitions.find({currentState, check});
            if (itr != transitions.end())
            {   
            
                currentState = transitions[itr->first]; 
                cout << currentState <<endl;
                return true;
            }
        
            return false;
        }
};



int main()
{   
    tuple<int, char, int> tup;
    vector<tuple<int, char, int>> vec;
    vec.emplace_back(1, 'a', 2);
    vec.emplace_back(2, 'b', 1);
    
    StateMachine sM(1, vec);
    
    cout << sM.isAccepted('b') << endl;
    return 0;
}

