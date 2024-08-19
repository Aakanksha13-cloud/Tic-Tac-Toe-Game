#include<iostream>
using namespace std;

bool CheckWin ( char arr[3][3], char b){
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == b && arr[i][1] == b && arr[i][2] == b)
            return true;
        if (arr[0][i] == b && arr[1][i] == b && arr[2][i] == b)
            return true;
        
    }
    if (arr[0][0] == b && arr[1][1] == b && arr[2][2] == b)
    return true;
    if (arr[0][2] == b && arr[1][1] == b && arr[2][0] == b)
    return true; 
    else
    return false; 
}

void drawBoard(char gameBoard [3][3]){
    for (int i = 0; i < 3; i++)
   {
    for (int j = 0; j < 3; j++)
    {      
      cout << "  " << gameBoard[i][j] << "  |";
    }
    cout<<endl;
    cout<<"-------------------"<<endl;
   }
}

int main(){

    cout<<"*********TIC-TAC-TOE*********"<<endl<<endl;
    
    char gameBoard [3][3] = {
        {' ' , ' ' , ' '},
        {' ' , ' ' , ' '},
        {' ' , ' ' , ' '},
    };

    char player = 'X';
    int a,b;
    drawBoard(gameBoard);

    for (int turn = 0; turn < 9; turn++)
    {
       
   cout << "Player :" << player << endl;
   cout<< "Plaese enter your turn:"<<endl;
   
   cout<< "row :";
   cin>> a;
   cout<< "column:";
   cin>>b;

   if (a>3 || a<1|| b>3|| b<1|| gameBoard[a-1][b-1] != ' ')
   {
    cout<< "Invalid input!! Please try again..."<<endl;
    cout<< "row :";
    cin>> a;
    cout<< "column:";
    cin>>b;
   }
   
   gameBoard[a-1][b-1] = player;
   drawBoard(gameBoard);
   if (CheckWin(gameBoard, player))
   {
    cout<<"Congratulations!!! Player "<< player <<" has won!!"<<endl;
    break;
   }
   else if (turn == 8)
   {
    cout<<"It's a draw...Nice try"<<endl;
   }
   
   player = (player == 'X') ? 'O' : 'X';     
    }  

    return 0;
}