#include<iostream>
#include<windows.h>
using namespace std;
int count=0;
int check(int board[][3],int cur)
{int i,j,k,rowchk=0,colchk=0,diachk=0;
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
        return('O');
    else if(a==2)
        return(' ');
    else if(a==0)
        return('X');
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
int aii=-1,aij=-1;
int checkwin(int tboard[3][3],int cur)
{static int winf=0;

    int i,j;
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
        {   if(tboard[i][j]==2)
                {tboard[i][j]=cur;

                }
            else
                continue;
            if(check(tboard,cur)==1)
                {
                    aii=i+1;
                    aij=j+1;
                    return winf;
                }
            else
                {
                    checkwin(tboard,cur);
                    winf++;
                }
    //            tboard[i][j]=2;
        }
    }
}
int aili=-2,ailj=-2;
 int checkloss(int tboard[3][3],int cur)
{static int los=0;
static int taili=-2,tailj=-2;
 int i,j;
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
        {   if(tboard[i][j]==2)
                {
                    tboard[i][j]=cur;
                }
            else
                continue;
            if(check(tboard,cur)==1)
                {
                    aili=i+1;
                    ailj=j+1;
                    return los;
                }
            else
                {
                    checkloss(tboard,cur);
                    los++;
                }
                tboard[i][j]=2;
        }
    }
}
int loslvl,winlvl;
int checkminimax(int tboard[3][3],int cur)
{
    loslvl=checkloss(tboard,!cur);
    winlvl=checkwin(tboard,cur);
}
int main()
{int board[3][3]={2},tb[3][3],p1i,p1j,p2i,p2j,i,j,k,win=0;
 for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    board[i][j]=2;
    while(win!=1&&count<10)
    {
        system("cls");
        disp(board);
        y:cout<<"\nEnter player 1";
        cin>>p1i>>p1j;
        count++;
        p1i--;
        p1j--;
         if(board[p1i][p1j]==2)
            board[p1i][p1j]=0;
         else{
            cout<<"\nAlready filled try again";
            count--;
            goto y;
             }
        //board[p1i][p1j]=1;
        win=check(board,0);
        if(win)
            {cout<<"\nPLAYER 1 WON";
            disp(board);
            return 1;
            }
        else if(count==9)
        {
            disp(board);
            cout<<"\nDraw";
            return 0;
        }
        system("cls");
        disp(board);
        if(count>9)
        {
            cout<<"\nDraw";
            return 0;
        }
        x:cout<<"\nEnter player 2";
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            tb[i][j]=board[i][j];
        checkminimax(tb,1);
        cout<<"\nLoss acc to  minimax i and j"<<aili<<ailj<<"\nLoss lvl= "<<loslvl;
       cout<<"\nWIn Acc to minimax i and j"<<aii<<aij<<"\nWin lvl= "<<winlvl<<"\n";
        cin>>p2i>>p2j;
        count++;
        p2i--;
        p2j--;
        if(board[p2i][p2j]==2)
        board[p2i][p2j]=1;
        else{
        cout<<"\nAlready filled try again";
        goto x;
        }
        cout<<"Actual";
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                cout<<board[i][j];
        win=check(board,1);
        cout<<"Win"<<win;
        if(win)
           { cout<<"\nPLAYER 2 WON";
             disp(board);
             return 1;
           }

    }
}
