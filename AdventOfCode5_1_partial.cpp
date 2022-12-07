#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>
#include <set>
using namespace std;

int getNumber(char);
void popVec(int, int, vector<vector<int>>);
void pushpop(int, int, int, std::vector<std::vector<int>> &);
void printVector(int, int, std::vector<std::vector<int>>);
// void printAfter(int , int , std::vector<std::vector<int>> );

int main()
{
    std::vector<std::vector<int>> myvector_copy(9, std::vector<int>(8, 100)), myvector_copy1(9, std::vector<int>(8, 100));
    std::vector<std::vector<char>> myvector = {
        {'H', 'T', 'Z', 'D'},
        {'Q', 'R', 'W', 'T', 'G', 'C', 'S'},
        {'P', 'B', 'F', 'Q', 'N', 'R', 'C', 'H'},
        {'L', 'C', 'N', 'F', 'H', 'Z'},
        {'G', 'L', 'F', 'Q', 'S'},
        {'V', 'P', 'W', 'Z', 'B', 'R', 'C', 'S'},
        {'Z', 'F', 'J'},
        {'D', 'L', 'V', 'Z', 'R', 'H', 'Q'},
        {'B', 'H', 'G', 'N', 'F', 'Z', 'L', 'D'}

    };

    for (int k = 0; k < myvector.size(); ++k)
    {
        // cout << " myvector[i].size() : " << myvector[k].size() << endl;
    }

    for (int i = 0; i < myvector.size(); ++i)
    {
        for (int j = 0; j < myvector[i].size(); ++j)
            myvector_copy[i][j] = getNumber(myvector[i][j]);
    }

    for (int i = 0; i < myvector_copy.size(); ++i)
    {
        for (int j = 0; j < myvector_copy[i].size(); ++j)
        {
            for (int k = 0; k < (myvector_copy[i].size() - myvector[i].size()); ++k)
            {
                myvector_copy[i].pop_back();
            }
        }
    }

    pushpop(2, 6, 1, myvector_copy);
    /*move 1 from 4 to 8 */
    printVector(3, 7, myvector_copy);
    pushpop(1, 3, 7, myvector_copy);
    pushpop(2, 0, 8, myvector_copy);
    printVector(3, 7, myvector_copy);

    return 0;
}

void printVector(int rowFrom, int rowTo, std::vector<std::vector<int>> someVec)
{
    cout << " -------------------------------------------------" << endl;
    for (int j = 0; j < someVec[rowFrom].size(); ++j)
    {
        cout << "myvector_copy[" << rowFrom << "][" << j << "]: " << someVec[rowFrom][j] << endl;
    }
    for (int j = 0; j < someVec[rowTo].size(); ++j)
    {
        cout << "myvector_copy[" << rowTo << "][" << j << "]: " << someVec[rowTo][j] << endl;
    }
    for (int z = 0; z < 9; ++z){ cout << "Top element of each crate : " << z+1 << " is : " << someVec[z].back() << endl; }
    
}

/* Eg: move 2 from 7 to 2 */
/* which means move 2 from 6 to 1 */
/* repeat the below six lines as many times as the number of moves requested */
/* so in this case, it is repeating twice since we move 2 */
void pushpop(int number, int fromQueue, int toQueue, std::vector<std::vector<int>> &myvec)
{
    /* create a vector of vectors to store the pops and pushes */
    /* cleans out the temp vector to enable addition of various elements */
    std::vector<std::vector<int>> temp(9, std::vector<int>(9, 100));
    for (int i = 0; i < temp.size(); ++i)
    {
        for (int j = 0; j < 9; ++j)
            temp[i].pop_back();
    }

    for (int z = 0; z < number; ++z)
    {
        int val = myvec[fromQueue].back();
        myvec[fromQueue].pop_back();
        temp[fromQueue].push_back(val);

        int val2 = temp[fromQueue].back();
        temp[fromQueue].pop_back();
        myvec[toQueue].push_back(val2);
    }
}

void popVec(int num, int row, vector<vector<int>> &myvector_copy)
{
    for (int i = 0; i < num; ++i)
    {
        myvector_copy[row].pop_back();
    }
}

int getNumber(char val)
{
    std::map<char, int> mapObject_u, mapObject_l;

    for (int i = 1; i < 27; i++)
    {
        mapObject_u.insert(pair<char, int>('A' + i - 1, 27 + i - 1));
        mapObject_l.insert(pair<char, int>('a' + i - 1, i));
    }
    std::map<char, int>::iterator itr_l, itr_u;
    bool upper, lower;
    if (int(val) >= 97 && int(val) <= 122)
    {
        lower = true;
    }
    else
    {
        upper = true;
    }
    if (lower)
    {
        itr_l = mapObject_l.find(val);
        return itr_l->second;
    }
    else
    {
        return mapObject_u.find(val)->second;
    }
}

/* int count = 0;
    for (int i = 0; i < myvector_copy.size(); ++i)
    {
        for (int j = 0; j < myvector_copy[i].size(); ++j)
        {

            cout << myvector_copy[i][j] << endl;
            count++;
        }
    }

    cout << "count: " << count << endl;*/