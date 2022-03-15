/*
WordBuckets.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::vector<std::string> bucketize(std::string phrase, int n)
{
    std::vector<char> intoChar;
    std::vector<std::string> result;

    int j;

    for (int i = 0; i < phrase.length(); i++)
    {
        j++;
        if (j == n && (phrase[i] == ' ' || phrase[i + 1] == ' ' ))
        {
            std::copy(phrase[i - n + j - 1], phrase[i - n + j - 1], std::back_inserter(intoChar));
            std::string word(intoChar.begin(), intoChar.end());
            result.push_back(word);
            word = "";
            j = 0;
        }
        else if ((j < n || j == n) && (i + 1) == phrase.length())
        {
            std::copy(phrase[i - j - 1], phrase[i], std::back_inserter(intoChar));
            std::string word(intoChar.begin(), intoChar.end());
            result.push_back(word);
            word = "";
            j = 0;
        }
        else if (j == n && (phrase[i] != ' ' || phrase[i + 1] != ' '))
        {
            size_t found = phrase.find(" ", phrase[i - j]);
            std::copy(phrase[i - j - 1], phrase[found], std::back_inserter(intoChar));
            std::string word(intoChar.begin(), intoChar.end());
            result.push_back(word);
            word = "";
            j = 0;
        }
    }

    return result;
}

int main()
{
    std::string phrase;
    int n;
    std::cout << "Enter phrase : ";
    std::cin >> phrase;
    std::cout << "Enter number of characters: ";
    std::cin >> n;

    for(int i = 0; i < bucketize(phrase, n).size(); i++)
        std::cout << "Word bucket: " << bucketize(phrase, n)[i];
}


