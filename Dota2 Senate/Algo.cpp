#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string predictPartyVictory(string senate);

int main() {
    string result = predictPartyVictory("RDD");
    cout<< result;
}

string predictPartyVictory(string senate) {
    int rCount = count(senate.begin(), senate.end(), 'R');
    int dCount = senate.size() - rCount;

    auto ban = [&](char bannedChar, int startAt) {
        bool isLoop = false;
        int pointer = startAt;

        while (true)
        {
            if(pointer == 0)
                isLoop = true;
            if(senate[pointer] == bannedChar)
            {
                senate.erase(pointer, 1);
                break;
            }
            pointer = (1 + pointer) % senate.size();
        }
        
        return isLoop;
    };

    int count = 0;
    while(rCount > 0 && dCount > 0)
    {
        if(senate[count] == 'R') {
            bool res = ban('D', (count + 1)%senate.size());
            dCount--;
            if(res)
                count--;
        }
        else {
            bool res = ban('R', (count + 1)%senate.size());
            rCount--;
            if(res)
                count--;
        }

        count = (count + 1) % senate.size();
    }

    return dCount == 0 ? "Radiant" : "Dire";
}