#include<iostream>
#include<windows.h>
#include<stdio.h>
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
int aiwi=-1,aiwj=-1;
int aili=-2,ailj=-2;
int checkin(int tboard[3][3],int cur)
{
    int c=0;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        if(tboard[i][j]!=2)
            c++;

    }
    if(tboard[1][1]==cur&&c==1)
    {

            aili=1;
            ailj=1;
            return 1;

    }
    else return 0;
}
int checkimloss(int board[3][3],int cur)
{
 int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==2)
            {
                    board[i][j]=cur;
                    if(check(board,cur)==1)
                    {
                        aili=i+1;
                        ailj=j+1;
                        return 1;
                    }
                    board[i][j]=2;
            }

        }
    }
    return 0;
}

int checkmove(int a[3][3],int cur)
{
    if(a[1][1]==!cur)
    {
        if(a[0][0]==2)
        {
            aili=1;
            ailj=1;
            return 1;
        }
        else if(a[0][2]==2)
        {
            aili=1;
            ailj=3;
            return 1;
        }
        else if(a[2][0]==2)
        {
            aili=3;
            ailj=1;
            return 1;
        }
        else if(a[2][2]==2)
        {
            aili=3;
            ailj=3;
            return 1;
        }

    }
    return 0;
}
 int checkloss(int tboard[3][3],int cur)
{static int los=0;

if(checkmove(tboard,cur))
{
    return 1;
}
static int taili=-2,tailj=-2;
 int i,j,k=0;
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
        {   if(tboard[i][j]==2)
                {
                    tboard[i][j]=cur;
                    k=1;
                }
            else
                continue;
            if(check(tboard,cur)==1)
                {
                    aili=i+1;
                    ailj=j+1;
                    if(k)
                        tboard[i][j]=2;
                    return los;
                }
            else
                {
                    checkloss(tboard,cur);
                    los++;
                }
                if(k)
                   tboard[i][j]=2;
        }
    }
    if(aili!=-2)
        return 1;
    else return 0;
}
int checkimwin(int board[3][3],int cur)
{
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==2)
            {
                    board[i][j]=cur;
                    if(check(board,cur)==1)
                    {
                        aiwi=i+1;
                        aiwj=j+1;
                    }
                    board[i][j]=2;
            }

        }
    }
    if(aiwi!=-2)
        return 1;

}
int checkminimax(int board[3][3],int cur)
{
aiwi=-2;
aiwj=-2;
    if(checkimwin(board,cur)==1)
        {
            cout<<"\nDue to imdiate win";
            getchar();
            return 1;
        }
    else if(checkimloss(board,!cur)==1)
        {
            cout<<"\nDue to imdiate loss";
            getchar();
            return 0;
        }
    else {
            checkloss(board,cur);
            return 0;
    }

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
        int ret=checkminimax(tb,1);
        int b;
        cout<<"\nminimax returned"<<ret;
        if(ret==1)
            {
                cout<<"\nWIn Acc to minimax i and j"<<aiwi<<aiwj;
                cin>>b;
                p2i=aiwi;
                p2j=aiwj;
            }
        else if(ret==0)
            {
                cout<<"\nLoss acc to  minimax i and j"<<aili<<ailj;
                p2i=aili;
                p2j=ailj;
            }
        count++;
        p2i--;
        p2j--;
        if(board[p2i][p2j]==2)
            board[p2i][p2j]=1;
        else{
        cout<<"\nAlready filled try again";
        cin>>p2i>>p2j;
        p2i--;
        p2j--;
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
