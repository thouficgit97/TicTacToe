#include<iostream>
#include<cstring>
using namespace std;
char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char value,player1,player2;
short cnt=9;

void display();
void playerTurn();
void check();
bool gameOver();
void display()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl<<endl;
    
}
bool check(char pos)
{
    int row=((pos-48)-1)/3;
    int col=((pos-48)-1)%3;
    if(board[row][col]=='X' || board[row][col]=='O')
    {
        cout<<"This position has been occupied!"<<endl;
        return true;
        
    }
    return false;
}
void playerTurn()
{
    if(cnt%2) value=player1;
    else value=player2;
    cout<<"Player "<<value<<" turn"<<endl;
    char position;
    cout<<"Enter the position(from 1 to 9):";
    cin>>position;
    //cout<<endl;
    if(check(position))
       { 
       playerTurn();
       return;
       }
    if(position=='1')
    {
    
        board[0][0]=value;
    }
    else if(position=='2')
    {
        board[0][1]=value;
    }
    else if(position=='3')
    {
        board[0][2]=value;
    }
    else if(position=='4')
    {
        board[1][0]=value;
    }
    else if(position=='5')
    {
        board[1][1]=value;
    }
    else if(position=='6')
    {
        board[1][2]=value;
    }
    else if(position=='7')
    {
        board[2][0]=value;
    }
    else if(position=='8')
    {
        board[2][1]=value;
    }
    else if(position=='9')
    {
        board[2][2]=value;
    }
    else 
    {
        cout<<"You have not entered from 1 to 9"<<endl;
        playerTurn();
        return;
        
    }
    
   // gameOver();
    display();
    /*if(value=='X') value='O';
    else value='X';*/
}
bool winOrnot()
{

if(board[0][0]==player1 && board[0][1]==player1 && board[0][2]==player1)
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    else if(board[0][0]==player2 && board[0][1]==player2 && board[0][2]==player2)
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[0][0] == player1 && board[1][0]==player1 && board[2][0]==player1)
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    else if(board[0][0] == player2 && board[1][0]==player2 && board[2][0]==player2)
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[0][2] == player1 && board[1][2]==player1 && board[2][2]==player1)
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    
    else if(board[0][2] == player2 && board[1][2]==player2 && board[2][2]==player2)
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[2][0] == player1 && board[2][1] == player1 && board[2][2]==player1)
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    else if(board[2][0] == player2 && board[2][1] == player2 && board[2][2]==player2)
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[0][0] == player1 && board[1][1]==player1 && player1==board[2][2])
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    
     else if(board[0][0] == player2 && board[1][1]==player2 && player2==board[2][2])
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[0][2]==player1 && board[1][1]== player1 && player1==board[2][0])
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    
        else if(board[0][2]==player2 && board[1][1]== player2 && player2==board[2][0])
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    else if(board[0][1] == player1 && board[1][1]==player1 && player1==board[2][1])
    {
        cout<<"player "<<player1<<" has won";
        return true;
    }
    else if(board[0][1] == player2 && board[1][1]==player2 && player2==board[2][1])
    {
        cout<<"player "<<player2<<" has won";
        return true;
    }
    return false;
 }
bool drawOrnot()
{
    
    
    
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==' ')
                {
                    return false;   
                }
            }
        }
    
    cout<<"Match Draw";
    return true;
}
void choose()
{
   cout<<"Do you want X or O:";
    cin>>player1;
    player1=toupper(player1);
    if(player1!='X' && player1!='O')
    { 
        cout<<"Enter X or O!"<<endl;
        choose();
        return;
    }
    
    player2=(player1=='X'?'O':'X');
}
int main()
{
    
    choose();
    display();
    while(cnt)
    {
   
    playerTurn();
    if(winOrnot())
    break;
    if(drawOrnot())
     break;
     
     cnt--;
    }
    
}
