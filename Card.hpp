#ifndef CARD_H
#define CARD_H

class Card
{
private:
    enum suite
    {
        Hearts = 80,
        Diamonds,
        Clubs,
        Spades,
        Invalid = 100
    };

    enum value
    {
        Ace = 1,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        Jack,
        Queen,
        King,
        InvalidVal = 100
    };

    suite newSuite;
    value faceValue;

public:
    Card::suite getFace(int choice);
    Card::value getFaceValue(int valueChoice); // valueChoice goes from 1-13 for each of the 13 cards in enum value
    std::pair<Card::suite, Card::value> printFace() const;
    Card();
    Card(int num, int num1);
};

class Deck
{
    private:
    std::vector<Card> newDeck;
    public:
    Deck();
    Deck(std::vector<Card> myDeck) : newDeck(myDeck) {}
    /* create a default constructor that will initialize all entries in newDeck as Ace of Diamonds for example */
    std::vector<Card> &makeDeck(); // creates a default deck of 52 Card objects and stores it as a vector.
    // each card is stored as a suit-value combination eg., 8 of diamonds is stored as (Diamonds, eight).
    std::vector<Card> &sortDeck(std::vector<Card> &newDeck, char *key);
    void printDeck(std::vector<Card> &newDeck) const;
    std::vector<Card> &shuffleDeck(std::vector<Card> &newDeck);
    std::vector<std::string> selectRandom();
};

#endif
