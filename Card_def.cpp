#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <random>
#include "Card.hpp"
using namespace std;

Card::suite Card::getFace(int choice)
{
    Card::suite temp;
    string error = "Error";
    switch (choice)
    {
    case Card::Hearts:
        temp = Card::Hearts;
        break;

    case Card::Diamonds:
        temp = Card::Diamonds;
        break;

    case Card::Clubs:
        temp = Card::Clubs;
        break;

    case Card::Spades:
        temp = Card::Spades;

        break;

    default:
        temp = Card::Invalid;
        break;
    }
    return temp;
}

Card::value Card::getFaceValue(int numValArg)
{
    Card::value temp;
    string error = "Error";
    switch (numValArg)
    {
    case Card::Ace:
        temp = Card::Ace;
        break;

    case Card::two:
        temp = Card::two;
        break;

    case Card::three:
        temp = Card::three;
        break;

    case Card::four:
        temp = Card::four;

        break;

    case Card::five:
        temp = Card::five;

        break;

    case Card::six:
        temp = Card::six;

        break;

    case Card::seven:
        temp = Card::seven;

        break;

    case Card::eight:
        temp = Card::eight;

        break;

    case Card::nine:
        temp = Card::nine;

        break;

    case Card::ten:
        temp = Card::ten;

        break;

    case Card::Jack:
        temp = Card::Jack;

        break;

    case Card::Queen:
        temp = Card::Queen;

        break;

    case Card::King:
        temp = Card::King;

        break;

    default:
        temp = Card::InvalidVal;
        break;
    }
    return temp;
}

Card::Card() : newSuite(Card::Diamonds), faceValue(Card::Ace) {} /* default constructor */
Card::Card(int num, int numVal) : newSuite(getFace(num)), faceValue(getFaceValue(numVal)) {}

std::pair<Card::suite, Card::value> Card::printFace() const { return std::make_pair(newSuite, faceValue); }

std::vector<Card> &Deck::makeDeck()
{
    std::vector<Card> newDeck1;
    for (int i = 80; i < 84; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            Card card1(i, j);
            newDeck1.push_back(card1);
        }
    }

    return newDeck1;
}

std::vector<std::string> Deck::selectRandom()
/* an argument needs be supplied since we can have decks of different sizes and the random cards must reflect this size */
{
    srand(time(NULL));
    int val = rand() % 13 + 1;
    int suite = rand() % 4 + 80;
    /* later use the actual size of the deck for any random sized deck that can be input as argument */
    std::vector<std::string> suiteValue;

    std::map<int, std::string> mapping;
    mapping.insert(std::make_pair(1, "Ace"));
    mapping.insert(std::make_pair(2, "Two"));
    mapping.insert(std::make_pair(3, "Three"));
    mapping.insert(std::make_pair(4, "Four"));
    mapping.insert(std::make_pair(5, "Five"));
    mapping.insert(std::make_pair(6, "Six"));
    mapping.insert(std::make_pair(7, "Seven"));
    mapping.insert(std::make_pair(8, "Eight"));
    mapping.insert(std::make_pair(9, "Nine"));
    mapping.insert(std::make_pair(10, "Ten"));
    mapping.insert(std::make_pair(11, "Jack"));
    mapping.insert(std::make_pair(12, "Queen"));
    mapping.insert(std::make_pair(13, "King"));
    /* for the suite */
    mapping.insert(std::make_pair(80, "Hearts"));
    mapping.insert(std::make_pair(81, "Diamonds"));
    mapping.insert(std::make_pair(82, "Clubs"));
    mapping.insert(std::make_pair(83, "Spades"));

    std::map<int, std::string>::const_iterator iterSuite = mapping.find(val);
    std::map<int, std::string>::const_iterator iterValue = mapping.find(suite);

    suiteValue.push_back(iterSuite->second);
    suiteValue.push_back(iterValue->second);
    std::vector<std::string>::iterator itr = suiteValue.begin();

    cout << *itr << " Of ";
    advance(itr, 1); // advances iterator by 1 to yield the second element from the beginning
    cout << *itr << endl;

    return suiteValue;
}


