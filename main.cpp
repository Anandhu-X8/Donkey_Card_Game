#include <iostream>
#include <vector>
#include "types.h"
#include "Player.h"
#include "bots/bots.h"
void printMatrix(const Deck& mat)
{
  for(const auto& row : mat)
  {
    std::cout<<"| ";
    for(int x : row)
    {
      std::cout<<x<<" ";
    }
    std::cout<<"|\n";
  }
  std::cout<<"\n";
}
int main()
{
    std::cout<<"main running"<<std::endl;
    
    Player p1(std::make_unique<RandomBot>());
    Player p2(std::make_unique<HighBot>());
    Player p3(std::make_unique<LowBot>());

    std::cout<<p1.getId()<<std::endl;
    std::cout<<p2.getId()<<std::endl;
    std::cout<<p3.getId()<<std::endl;

    // make some hands for each players and check fundtions
    CardVector pile;
    for(int i=0; i<13; i++)
    {
      for(int j=0; j<4; j++)
      {
        pile.push_back(Card(j,i));
        if(i==4)
        {
          p1.addCards(pile);
          pile.clear();
          break;
        }
        if(i==8)
        {
          p2.addCards(pile);
          pile.clear();
          break;
        }
        if(i==12)
        {
          p3.addCards(pile);
          pile.clear();
          break;
        }
      }
    }

    printMatrix(p1.getHand());
    
    // remove some
    Card c1(0,0), c2(1,1), c3(2,3);
    p1.removeCard(c1);
    p1.removeCard(c2);
    p1.removeCard(c3);

    printMatrix(p1.getHand());
    Observation o;
    Legal l(p1.getHand(),false);
    Card ccc=p1.makeAction(o,l);
    
    std::cout<<ccc.suit<<" "<<ccc.rank<<std::endl;
    return 0;
}
