#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <map>
using namespace std;

vector<string> splitString(string input, char character){
    string word = "";
    vector<string> outputString;
    for(auto x:input){
        if(x==character){
            outputString.push_back(word);
            word = "";
        }else{
            word = word+x;
        }
    }
    outputString.push_back(word);

    return outputString;
}

class Piece{
    public:
    char file;
    int rank;
    char value;
    string position;

    Piece(int column, int row, char type){
        file = char(column+96);
        rank=row;
        position = file+to_string(rank);
        value = type;
    }
};

class Board{
    public:
    vector<Piece> board;
    string positionOfPieces;
    string sideToMove;
    int moveNumber;
    vector<vector<string>>piecePosition = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}};

    Board(string position, char side, int moveNum){
        positionOfPieces = position;
        if(side == 'w'){
            sideToMove = "white";
        }else{
            sideToMove = "black";
        }
        moveNumber = moveNum;
    }

    void createPiece(int col, int row, char v){
        Piece piece(col, row, v);
        board.push_back(piece);
    }

    void createBoard(){
        int i = 7;
        int j = 1;

        for(int p = 0; p<positionOfPieces.length();p++){
            char current = positionOfPieces[p];
            if(isdigit(current)){
                int intCurrent = int(current) - 48;
                for(int k = 0;k<int(intCurrent);k++){
                    createPiece(j,i,'n');
                    j++;
                }
            }else if(current == '/'){
                i--;
                j=1;
            }else{
                createPiece(j,i,current);
                j++;
            }
        }
    }

    void printBoard(){
        for(int i=0;i<7;i++){
            for(int j;j<7;j++){
                if(j!=6){
                    cout<<board[i*7+j].value<<" ";
                }else{
                    cout<<board[i*7+j].value<<endl;
                }
            }
        }
    }

    Piece getPiece(int file, int rank){
        if(rank ==0 || file ==0){
            cout<<"Out of bounds rank or file ranges from 1 to 7\n";
        }
        return board[49-7*rank+file-1];
    }

    void printPieceDetails(int file, int rank){
        
    }

};