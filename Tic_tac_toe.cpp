#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string BOARD[5][5] = {
    {" ", " | ", " ", "|", " "},
    {"--", "+", "--", "+", "--"},
    {" ", " | ", " ", " | ", " "},
    {"--", "+", "--", "+", "--"},
    {" ", " | ", " ", " | ", " "}
};


void clear_board(string board[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            board[i][j]=BOARD[i][j];
        }
    }
}





int cls_screen() {
    #if defined(_WIN32) || defined(_WIN64)
        cout << "Running on Windows" << endl;
        system("cls");
    #elif defined(__linux__)
        cout << "Running on Linux" << endl;
        system("clear");
    #elif defined(__APPLE__) || defined(__MACH__)
        cout << "Running on macOS" << endl;
        system("clear");
    #else
        cout << "Unknown operating system" << endl;
    #endif

    return 0;
}


//^ Checking for WIN
bool winchecklogic(const string board[5][5], char symbol) {
    // Convert symbol to a string for comparison
    string symbolStr(1,symbol);

    // rows
    if((board[0][0] == symbolStr && board[0][2] == symbolStr && board[0][4] == symbolStr) ||
        (board[2][0] == symbolStr && board[2][2] == symbolStr && board[2][4] == symbolStr) ||
        (board[4][0] == symbolStr && board[4][2] == symbolStr && board[4][4] == symbolStr))
        return true;

    // columns
    if((board[0][0] == symbolStr && board[2][0] == symbolStr && board[4][0] == symbolStr) ||
        (board[0][2] == symbolStr && board[2][2] == symbolStr && board[4][2] == symbolStr) ||
        (board[0][4] == symbolStr && board[2][4] == symbolStr && board[4][4] == symbolStr)
        )
        return true;

    // diagonals
    if((board[0][0] == symbolStr && board[2][2] == symbolStr && board[4][4] == symbolStr) ||
        (board[0][4] == symbolStr && board[2][2] == symbolStr && board[4][0] == symbolStr))
        
        return true;


    return false;
    // This alone took like 40 minutes ;=|
}






int main(){

    int user_choice;
    cout << "How do you want to play? \n1.With a Friend.\n2.With Computer.\nEnter 1 or 2";
    cin >> user_choice;
    
    //^ Creating board (Kind of a roundabout way.)
    string board[5][5];
    clear_board(board);
    
    
    //^ Player Vs Player

    if(user_choice==1){
        // Main loop
        bool result = false;
        int turn = 0;

        
        // Max 9 Turns, after that terminates 
        while(turn < 9 && result != true){
            // Co ordintated
            int x,y;
            char symbol;
            cls_screen();
            //& Print Board;
            for(int i=0;i<=4;i++){
                for(int j=0;j<=4;j++){
                    cout << board[i][j];
                    }
                cout << endl;
                }   
            if(turn>3){
                
                result = winchecklogic(board,symbol);
                if(result==true){
                    if(symbol == 'X'){
                        cout << "Player 1 Wins!!!!";
                        break;
                    }
                    else{
                        cout << "Player 2 Wins!!!!";
                        break;
                    }
                }
            }
            if(turn % 2 == 0){ // Player 1's Turn
                if(turn == 0){ // Extra info for First turn
                    symbol = 'O';
                    cout << "Player 1's Turn\n\nEnter coordinated seperated by space: ";
                } 
                else{
                    symbol = 'O';
                    cout << "Player 1's Turn: ";
                }
                
                
            }
            else{
                symbol = 'X';
                cout << "Player 2's Turn: ";
            }
            cin >> x >> y;
            if(x < 0 || x > 2 || y < 0 || y > 2 || board[x*2][y*2] != " ") {
                cout << "Invalid move. Try again." << endl;
                continue; // Skip this iteration if the move is invalid
            }
            
            board[x*2][y*2] = symbol;
            
            
            turn++; 
            
        }
    }

        




    return 0;
    }
