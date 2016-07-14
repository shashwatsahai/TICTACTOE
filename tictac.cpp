#include<iostream>
using namespace std;
int count=0;
int check(int board[][3],int cur)
{int i,j,k,rowchk,colchk,diachk;
    for(i=0;i<3;i++)
        if((board[i][0]==cur)&&(board[i][1]==cur)&&(board[i][2]==cur))
            rowchk=1;
    for(j=0;j<3;j++)
        if((board[0][j]==cur)&&(board[1][j]==cur)&&(board[2][j]==cur))
            colchk=1;
    if(((board[0][0]==cur)&&(board[1][1]==cur)&&(board[2][2]==cur))||((board[0][2]==cur)&&(board[1][1]==cur)&&(board[2][0]==cur)))
        diachk=1;
    if(rowchk==1||diachk==1||colchk==1)
        return 1;
    else
        return 0;

}
char sym(int a)
{
    if(a==1)
        return('X');
    else if(a==2)
        return('O');
    else if(a==0)
        return(' ');
}
void disp(int board[][3])
{int i,j,k;
cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j!=2)
                cout<<sym(board[i][j])<<"|";
            else
                cout<<sym(board[i][j]);
        }
        if(i!=2)
        {
        cout<<"\n";
        for(k=0;k<5;k++)
        {
            cout<<"-";
        }
        }
        cout<<"\n";

    }

}

int main()
{int board[3][3]={0},p1i,p1j,p2i,p2j,i,j,k,win=0;
    while(win!=1&&count<10)
    {
        disp(board);
        y:cout<<"\nEnter player 1";
        cin>>p1i>>p1j;
        count++;
        p1i--;
        p1j--;
         if(board[p1i][p1j]==0)
            board[p1i][p1j]=1;
         else{
            cout<<"\nAlready filled try again";
            goto y;
             }
        board[p1i][p1j]=1;
        win=check(board,1);
        if(win)
            {cout<<"\nPLAYER 1 WON";
            disp(board);
            return 1;
            }
        disp(board);
        if(count>9)
        {
            cout<<"\nDraw";
            return 0;
        }
        x:cout<<"\nEnter player 2";
        cin>>p2i>>p2j;
        count++;
        p2i--;
        p2j--;
        if(board[p2i][p2j]==0)
        board[p2i][p2j]=2;
        else{
        cout<<"\nAlready filled try again";
        goto x;
        }
        win=check(board,2);
        if(win)
           { cout<<"\nPLAYER 2 WON";
             disp(board);
             return 1;
           }

    }
}

