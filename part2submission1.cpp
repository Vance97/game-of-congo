#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitString(string input,char character){
    string word = "";
    vector<string> outputString;
    for(auto x : input){
        if(x == character){
            outputString.push_back(word);
            word = "";
        }
        else{
            word = word + x;
        }
    }
    outputString.push_back(word);

    return outputString;
}

class Piece{
    //Variables
    public:
    char file;
    int rank;
    char value;
    string position;

    // constructor
    Piece(int column,int row,char type){
        file = char(column + 96);
        rank = row;
        position = file + to_string(rank);
        value = type;
    }
};

class Board{
    // Variables
    public:
    vector<Piece> board;
    string positionOfPieces;
    string sideToMove;
    int moveNumber;
    vector<vector<string>> piecePosition = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}};
    
    //Construtor
    Board(string position, char side, int moveNum){
        positionOfPieces = position;
        if(side == 'w'){
            sideToMove = "white";
        }
        else{
            sideToMove = "black";
        }
        moveNumber = moveNum;
    }

    //Methods
    void createPiece(int col, int row, char v){ // Create a piece and add it to the board to keep track of all pieces on the board with their file and rank
        Piece piece(col,row,v);
        board.push_back(piece);
    }
    //Creates all pieces of the board based on the positionOfPieces given and empty('e') spaces and keeps record of them 
    void createBoard(){
        int i = 7;
        int j = 1;

        for(int p = 0; p<positionOfPieces.length();p++){
            char current = positionOfPieces[p];
            if(isdigit(current)){
                int intCurrent = int(current) - 48;
                for(int k = 0; k<intCurrent;k++){
                    createPiece(j,i,'n');
                    j++;
                }
            }
            else if(current =='/'){
                i--;
                j = 1;
            }
            else{
                createPiece(j,i,current);
                j++;
            }
        }
    }

    void printBoard(){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                if(j != 6){
                    cout << board[i*7+j].value <<" ";
                }
                else{
                    cout << board[i*7+j].value << endl;
                }
            }
        }
    }

    Piece getPiece(int file, int rank){
        if(rank == 0 || file == 0){
            cout << "Out of bouce Rank or  File ranges from 1 to 7\n";
        }
        return board[49 - 7 * rank + file -1];
    }

    void printPieceDeatails(int file, int rank){
        Piece piece = getPiece(file,rank);
        cout<< piece.position << "=" << piece.value << endl;
    }

    // log position of all pieces on the Board
    void logPositionOfPiece(){
        for(int i = 1; i<= 7; i++){
            for(int j = 1; j<=7; j++){
                Piece piece = getPiece(i,j);

                if(piece.value == 'P'){
                    piecePosition[0].push_back(piece.position);
                }
                else if(piece.value == 'p'){
                    piecePosition[1].push_back(piece.position);
                }
                else if(piece.value == 'S'){
                    piecePosition[2].push_back(piece.position);
                }
                else if(piece.value == 's'){
                    piecePosition[3].push_back(piece.position);
                }
                else if(piece.value == 'G'){
                    piecePosition[4].push_back(piece.position);
                }
                else if(piece.value == 'g'){
                    piecePosition[5].push_back(piece.position);
                }
                else if(piece.value == 'M'){
                    piecePosition[6].push_back(piece.position);
                }
                else if(piece.value == 'm'){
                    piecePosition[7].push_back(piece.position);
                }
                else if(piece.value == 'E'){
                    piecePosition[8].push_back(piece.position);
                }
                else if(piece.value == 'e'){
                    piecePosition[9].push_back(piece.position);
                }
                else if(piece.value == 'L'){
                    piecePosition[10].push_back(piece.position);
                }
                else if(piece.value == 'l'){
                    piecePosition[11].push_back(piece.position);
                }
                else if(piece.value == 'C'){
                    piecePosition[12].push_back(piece.position);
                }
                else if(piece.value == 'c'){
                    piecePosition[13].push_back(piece.position);
                }
                else if(piece.value == 'Z'){
                    piecePosition[14].push_back(piece.position);
                }
                else if(piece.value == 'z'){
                    piecePosition[15].push_back(piece.position);
                }
            }
        }
    }

    Piece getLion(char side){
        for(int i = 0;i<board.size();i++){
            if(side == 'b'){
                if(board[i].value =='l'){
                    return board[i];
                }
            }
            else{
                if(board[i].value == 'L'){
                    return board[i];
                }
            }
        }
    }

    vector<string> checkZebraMoves(char side) {
        vector<string> availableMoves;
        Piece l = getLion(side);
        char op;
        if(side == 'w'){
            op = 'b';
        }
        else{
            op = 'w';
        }
        Piece opL = getLion(op);
        
        // check all available moves around lion
        for(int i = -1;i<=1;i++){
            int file = l.file - 96;
            int rank = l.rank;
            if(file +i<3||file+i>5){
                    continue;
                }
            for(int j = -1;j<=1;j++){
                string currentLocation = l.position;
                if(rank+j <= 0|| rank+j>7){
                    continue;
                }
                else if (i ==0 && j == 0){
                    continue;
                }
                else if(rank + j == 4){
                    if(rank <4){
                        if(file +2 <=5 && getPiece(file+2,rank-2).value =='L' && side == 'b'){
                            string temp = getPiece(file+2, rank-2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                        else if(file -2 >= 3 && getPiece(file-2,rank-2).value =='L' && side == 'b'){
                            string temp = getPiece(file+2, rank+2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                        else if (getPiece(file,rank - 2).value == 'L' && side == 'b'){
                            string temp = getPiece(file+2, rank+2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                        else if(file + 2 <=5 && getPiece(file+2,rank+2).value == 'l' && side == 'w'){
                            string temp = getPiece(file+2, rank+2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                        else if(file - 2 <= 3 && getPiece(file-2,rank+2).value == 'l' && side == 'w'){
                            string temp = getPiece(file+2, rank+2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                        else if(getPiece(file,rank+2).value == 'l' && side == 'w'){
                            string temp = getPiece(file+2, rank+2).position;
                            availableMoves.push_back(currentLocation+temp);
                        }
                    }
                }
                else if (getPiece(file+i,rank+j).value != 'n')
                {
                    if(getPiece(file+i,rank+j).value == 'e' && side == 'b' ){
                        continue;
                    }
                    else if (getPiece(file+i,rank+j).value == 'z' && side == 'b')
                    {
                        continue;
                    }
                    else if (getPiece(file+i,rank+j).value == 'p' && side == 'b')
                    {
                        continue;
                    }
                    else if (getPiece(file+i,rank+j).value == 'E' && side == 'w')
                    {
                        continue;
                    }
                    else if (getPiece(file+i,rank+j).value == 'Z' && side == 'w')
                    {
                        continue;
                    }
                    else if (getPiece(file+i,rank+j).value == 'P' && side == 'w')
                    {
                        continue;
                    }
                    else{
                    string temp = getPiece(file+i, rank+j).position;
                    availableMoves.push_back(currentLocation+temp);
                    }
                }
                else{
                    string temp = getPiece(file+i, rank+j).position;
                    availableMoves.push_back(currentLocation+temp);
                }

            }
        }
                // check if lion can capture the other lion
                if(l.file == opL.file){
                    int d = abs(l.rank - opL.rank);

                    if(l.rank > opL.rank){
                        for(int t = l.rank -1; t >= opL.rank; t--){
                            string currentLocation = l.position;
                            // cout << currentLocation << endl;
                            int intFile = l.file - 96;
                            if(getPiece(intFile,t).value == 'n'){
                                continue;
                            }
                            else if(getPiece(intFile,t).value == opL.value){
                                string temp = getPiece(intFile, t).position;
                                availableMoves.push_back(currentLocation+temp);
                            }
                            else{
                                break;
                            }
                        }
                    }
                    else {
                         for(int t = l.rank+1; t <= opL.rank; t++){
                             string currentLocation = l.position;
                             int intFile = l.file - 96;
                            if(getPiece(intFile,t).value == 'n'){
                                continue;
                            }
                            else if(getPiece(intFile,t).value == opL.value){
                                string temp = getPiece(intFile, t).position;
                                availableMoves.push_back(currentLocation+temp);
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                // sort in order
                if(availableMoves.size() > 1){
                    for(int t = 0; t<availableMoves.size();t++){
                        for(int v = 0 ;v <availableMoves.size();v++){
                            if(t == v){
                                continue;
                            }
                            else if (availableMoves[t] > availableMoves[v])
                            {
                                string temp = availableMoves[t];
                                availableMoves[t] = availableMoves[v];
                                availableMoves[v] = temp;
                            }
                            else{
                                continue;
                            }
                            
                        }
                    }
                }
                // reverse the order
                vector<string> orderedMoves;
                for(int j = availableMoves.size() - 1;j>=0;j--){
                    orderedMoves.push_back(availableMoves[j]);
                }

        return orderedMoves;
        
    }

    void printPositionOfPiece(){
        for(int i = 0 ;i <16;i++){
            if(i == 0){
                cout << "white pawn:";
            }
            else if (i == 1){
                cout << "black pawn:";
            }
            else if (i == 2){
                cout << "white superpawn:";
            }
            else if (i == 3){
                cout << "black superpawn:";
            }
            else if (i == 4){
                cout << "white giraffe:";
            }
            else if (i == 5){
                cout << "black giraffe:";
            }
            else if (i == 6){
                cout << "white monkey:";
            }
            else if (i == 7){
                cout << "black monkey:";
            }
            else if (i == 8){
                cout << "white elephant:";
            }
            else if (i == 9){
                cout << "black elephant:";
            }
            else if (i == 10){
                cout << "white lion:";
            }
            else if (i == 11){
                cout << "black lion:";
            }
            else if (i == 12){
                cout << "white crocodile:";
            }
            else if (i == 13){
                cout << "black crocodile:";
            }
            else if (i == 14){
                cout << "white zebra:";
            }
            else if (i == 15){
                cout << "black zebra:";
            }

            int numberOfPieces = piecePosition[i].size();

            for(int j = 0 ; j < numberOfPieces;j++){
                cout << " "<< piecePosition[i][j];
            }
            cout << endl;
        }
    }

    void showsideToMove(){
        cout << "side to play: "<< sideToMove;
    }

};


int main(){
    vector<string> inputStrings;
    int numberOfInput;
    cin >> numberOfInput;

    for(int i = 0;i < numberOfInput; i++){
        string FENString;
        getline(cin >> ws,FENString);
        inputStrings.push_back(FENString);
    }

    for(int i = 0;i<inputStrings.size();i++){
        // put position of pieces and side move + move number in seperate vector
        string currentInput = inputStrings.at(i);
        // vector<string> piecePosition = splitString(currentInput,'/');
        // vector<string> gdt = splitString(piecePosition.at(6),' ');
        // piecePosition.at(6) = gdt.at(0);
        // vector<string> gameDetails;
        // for(int j = 1; j<gdt.size();j++){
        //     gameDetails.push_back(gdt.at(j));
        // }
        vector<string> data = splitString(currentInput,' ');
        string position = data[0];
        // cout<< position << endl;
        char side = data[1][0] ;
        // cout << side << endl;
        int moveNum = stoi(data[2]);
        // cout << monveNum << endl;

        // create Board
        Board board(position,side,moveNum);
        board.createBoard();
        board.logPositionOfPiece();
        // board.printPositionOfPiece();
        // board.showsideToMove();

        // if(i != numberOfInput -1){
        //     cout<<endl<<endl;
        // }
        // Piece t = board.getLion(side);

        // int temp = t.file - 96;
        vector<string> moves = board.checkZebraMoves(side);

        

        if(moves.size()>0){
            for(int k = 0; k< moves.size(); k++){
                if(k != moves.size()-1){
                    cout << moves[k]+" ";
                }
                else{
                    cout << moves[k] << endl;
                }
                
            }
        }

        // Piece p = board.getPiece(temp,t.rank +2);

        // cout << temp << endl;
    }

    return 0;
}