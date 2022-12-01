#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*  create a deck of cards that may be sorted using either their
value (e.g., all aces, then all twos, then all threes ...) or suite-value combination.
Finally make it possible to shuffle the deck. */

// a card must be represented as a type with a value . eg: 7 of spades will be 7S, Ace of clubs will be 1C, King of diamonds
// would be 13D...or KD

 class Card
{
public:
    string faces;
    int values;
    Card(int x, string y): values(x), faces(y){}

    void printFace(){ cout << values << " of " << faces <<  endl;}
    
}; 


int main()
{
    char *type[4] = {"Spades", "Clubs", "Diamonds", "Hearts"};
    char *value[13] = {"Ace",
                       "two",
                       "three",
                       "four",
                       "five",
                       "six",
                       "seven", "eight", "nine", "ten", "King", "Queen", "Jack" };
    int values[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    int count = 0; vector<Card> deck;
    for (int i = 0; i < sizeof(type)/sizeof(type[0]) ; i++){
        for (int k = 0; k < sizeof(value)/sizeof(value[0]) ; k++){
                count++;
                Card card1(values[k], *(type+i));
                deck.push_back(card1);
        }
            
    } 
    
    // vector<Card>::iterator iter;
    for (auto i = deck.begin(); i != deck.end(); i++)
    {
        i->printFace();
    }
    
    //cout << deck.begin() .printFace() << endl;


    
    
    
}