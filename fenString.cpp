#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <map>
using namespace std;

/*
@ a function that takes in a space-separatedFEN string and splits it into
  a vector of strings
@ returns a vector of those strings.
*/

void FENString(string FEN){

    char space_char = ' ';
    vector<string> words{};

    stringstream sstream(FEN);
    string word;

    while (getline(sstream, word, space_char)){
        //word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(word);
    }

    for (const auto &str : words) {
        cout << str << endl;
    }

    //return words;
}

/* this function takes in a string with known rank number and returns
file numbers of all valied congo pieces on the input string
*/

string fileNumber(string rankedString){

    int counter=0;
    map<char, int> mapObject;
    for(int i=0;i<rankedString.length();i++){
        if(isdigit(rankedString[i])){
           //int correspondingNum = stoi(rankedString[i]);
           int correspondingNum = rankedString[i] - '0';
           counter = counter + correspondingNum;
        }else{

        }
    }

}

int main(){
    string myFEN = "2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23";
    FENString(myFEN);
    return 0;
}
