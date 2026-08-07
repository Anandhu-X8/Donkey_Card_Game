#include <iostream>
#include <vector>
#include "types.h"
#include "bots/bots.h"
int main()
{
    std::vector<std::vector<int>> obs(4, std::vector<int>(13,0)), legal(4, std::vector<int>(13,0));
    Observation obsreal;
    legal[0][1]=1;
    legal[1][3]=1;
    legal[2][3]=1;
    legal[3][3]=1;

    RandomBot R1;
    LowBot L1;
    HighBot H1;
    Card c=R1.makeAction(obsreal, legal);
    Card c2=H1.makeAction(obsreal, legal);
    Card c3=L1.makeAction(obsreal, legal);
    std::cout<<"rand"<<c.suit<<" "<<c.rank<<std::endl;
    std::cout<<"high"<<c2.suit<<" "<<c2.rank<<std::endl;
    std::cout<<"low"<<c3.suit<<" "<<c3.rank<<std::endl;
    return 0;
}
