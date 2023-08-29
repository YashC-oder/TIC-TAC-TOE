#include<iostream>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
class tictactoe{
    public:
    char player,computer;
    char slot[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int p[9],c[9]={0,0,0,0,0,0,0,0,0},num;
    void getsign();
    void printboard();
    bool wincondition(int*);
    bool move(int,char);
    bool checkwin();
    bool playermove();
    bool computermove();
    bool Continue();
    tictactoe()
    {
    cout<<"HELLO IM YASH AND THIS IS BASIC TIC-TAC-TOE GAME IN C++\n-THIS CODE ACCEPT ONLY NUMBER AS INPUT\n-INDEXES OF THE SLOT IS ALLOTED AS BELOW :"<<endl;
    cout<<"    "<<"1"<<"\t|   "<<"2"<<"\t|   "<<"3"<<endl;
    cout<<"========================="<<endl;
    cout<<"    "<<"4"<<"\t|   "<<"5"<<"\t|   "<<"6"<<endl;
    cout<<"========================="<<endl;
    cout<<"    "<<"7"<<"\t|   "<<"8"<<"\t|   "<<"9"<<endl;
    }
    ~tictactoe()
    {
       cout<<"THANKS FOR TRYING MY CODE\n";
    }
};
int main()
{
    tictactoe game;
    game.getsign();
    label:
    if(game.player=='O')
    {
        game.printboard();
        while(game.playermove())
        {
            if(game.computermove()) game.printboard();
            else break;
        }
        game.printboard();
    }
    else
    {
        while(game.computermove())
        {
            game.printboard();
            if(game.playermove()) continue;
            else break;
        }
        game.printboard();
    }
    if(game.Continue()) goto label;
    return 0;
}

void tictactoe::getsign()
{
    int n;
    cout<<"YOUR SIGN!"<<endl;
    cout<<"(O:FIRST MOVE)->1\t(X:SECOND MOVE)->2"<<endl;
    do
    {
    cout<<"ENTER : ";
    cin>>n;
    }while(n>2||n<1);
    if(n==1) {player='O',computer='X';}
    else {player='X',computer='O';}
}

void tictactoe::printboard()
{
    cout<<"    "<<slot[0][0]<<"\t|   "<<slot[0][1]<<"\t|   "<<slot[0][2]<<endl;
    cout<<"========================="<<endl;
    cout<<"    "<<slot[1][0]<<"\t|   "<<slot[1][1]<<"\t|   "<<slot[1][2]<<endl;
    cout<<"========================="<<endl;
    cout<<"    "<<slot[2][0]<<"\t|   "<<slot[2][1]<<"\t|   "<<slot[2][2]<<endl;
}

bool tictactoe::move(int n,char ch)
{
    switch(n)
    {
        case 1:
        if(slot[0][0]==' ')
        {
        slot[0][0]=ch;
        return false;
        }
        return true;
        break;

        case 2:
        if(slot[0][1]==' ')
        {
        slot[0][1]=ch;
        return false;}
        return true;
        break;

         case 3:
        if(slot[0][2]==' ')
        {
        slot[0][2]=ch;
        return false;}
        return true;
        break;

         case 4:
        if(slot[1][0]==' ')
        {
        slot[1][0]=ch;
        return false;}
        return true;
        break;

         case 5:
        if(slot[1][1]==' ')
        {
        slot[1][1]=ch;
        return false;}
        return true;
        break; 

         case 6:
        if(slot[1][2]==' ')
        {
        slot[1][2]=ch;
        return false;}
        return true;
        break; 

         case 7:
        if(slot[2][0]==' ')
        {
        slot[2][0]=ch;
        return false;}
        return true;
        break; 

         case 8:
        if(slot[2][1]==' ')
        {
        slot[2][1]=ch;
        return false;}
        return true;
        break;

         case 9:
        if(slot[2][2]==' ')
        {
        slot[2][2]=ch;
        return false;}
        return true;
        break;

        default :
        return true;   
    }
}

bool tictactoe::playermove()
    {
        int n;
        do{
        cout<<endl<<"YOUR MOVE : ";
        cin>>n;
        }while(n<1||n>9||move(n,player));
        static int i=0;
        p[i]=n; i++;
        return checkwin();
    }

bool tictactoe::computermove()
{
    static int n=0;    
        if(wincondition(c))
        {
            move(num,computer);
        }
        else if(wincondition(p))
        {
          move(num,computer);  
        }
        else
        {
        do
        {
        srand(time(0));
        num=rand()%9+1;
        }while(move(num,computer));
        }
    c[n]=num; n++; 
    cout<<"COMPUTER MOVE : "<<num<<endl;
    return checkwin();
}

bool findnum(int* a,int i)
{
    for(int j=0;j<9;j++)
    {
        if(*(a+j)==i) return true;
    }
    return false;
}

bool tictactoe::wincondition(int* a)
{
    switch(1)
    {
        //row 1
        case 1:
        if(findnum(a,1))
        {
            if(findnum(a,2))
            {
                if(slot[0][2]==' ')
                {
                num=3;
                return true;
                break;
                }
            }
            else if(findnum(a,3))
            {
                if(slot[0][1]==' ')
                {num=2;
                return true;
                break;}
            }
        }

        case 2:
        if(findnum(a,2))
        {
            if(findnum(a,3))
            {
                if(slot[0][0]==' ')
                {num=1;
                return true;
                break;}
            }
        }
        //row 2
        case 3:
        if(findnum(a,4))
        {
            if(findnum(a,5))
            {
                if(slot[1][2]==' ')
                {
                num=6;
                return true;
                break;
                }
            }
            else if(findnum(a,6))
            {
                if(slot[1][1]==' ')
                {num=5;
                return true;
                break;}
            }
        }

        case 4:
        if(findnum(a,5))
        {
            if(findnum(a,6))
            {
                if(slot[1][0]==' ')
                {num=4;
                return true;
                break;}
            }
        }
        //row 3
        case 5:
        if(findnum(a,7))
        {
            if(findnum(a,8))
            {
                if(slot[2][2]==' ')
                {
                num=9;
                return true;
                break;
                }
            }
            else if(findnum(a,9))
            {
                if(slot[2][1]==' ')
                {num=8;
                return true;
                break;}
            }
        }

        case 6:
        if(findnum(a,8))
        {
            if(findnum(a,9))
            {
                if(slot[2][0]==' ')
                {num=7;
                return true;
                break;}
            }
        }
        // col 1
        case 7:
        if(findnum(a,1))
        {
            if(findnum(a,4))
            {
                if(slot[2][0]==' ')
                {
                num=7;
                return true;
                break;
                }
            }
            else if(findnum(a,7))
            {
                if(slot[1][0]==' ')
                {num=4;
                return true;
                break;}
            }
        }

        case 8:
        if(findnum(a,4))
        {
            if(findnum(a,7))
            {
                if(slot[0][0]==' ')
                {num=1;
                return true;
                break;}
            }
        }
        //col 2
        case 9:
        if(findnum(a,2))
        {
            if(findnum(a,5))
            {
                if(slot[2][1]==' ')
                {
                num=8;
                return true;
                break;
                }
            }
            else if(findnum(a,8))
            {
                if(slot[1][1]==' ')
                {num=5;
                return true;
                break;}
            }
        }

        case 10:
        if(findnum(a,5))
        {
            if(findnum(a,8))
            {
                if(slot[0][1]==' ')
                {num=2;
                return true;
                break;}
            }
        }
        //col 3
        case 11:
        if(findnum(a,3))
        {
            if(findnum(a,6))
            {
                if(slot[2][2]==' ')
                {
                num=9;
                return true;
                break;
                }
            }
            else if(findnum(a,9))
            {
                if(slot[1][2]==' ')
                {num=6;
                return true;
                break;}
            }
        }

        case 12:
        if(findnum(a,6))
        {
            if(findnum(a,9))
            {
                if(slot[0][2]==' ')
                {num=3;
                return true;
                break;}
            }
        }
        //cross \;
        case 13:
        if(findnum(a,1))
        {
            if(findnum(a,5))
            {
                if(slot[2][2]==' ')
                {
                num=9;
                return true;
                break;
                }
            }
            else if(findnum(a,9))
            {
                if(slot[1][1]==' ')
                {num=5;
                return true;
                break;}
            }
        }

        case 14:
        if(findnum(a,5))
        {
            if(findnum(a,9))
            {
                if(slot[0][0]==' ')
                {num=1;
                return true;
                break;}
            }
        }
        //cross /;
        case 15:
        if(findnum(a,3))
        {
            if(findnum(a,5))
            {
                if(slot[2][0]==' ')
                {
                num=7;
                return true;
                break;
                }
            }
            else if(findnum(a,7))
            {
                if(slot[1][1]==' ')
                {num=5;
                return true;
                break;}
            }
        }

        case 16:
        if(findnum(a,5))
        {
            if(findnum(a,7))
            {
                if(slot[0][2]==' ')
                {num=3;
                return true;
                break;}
            }
        }

        default :
        return false;
        break;
    }
}

bool tictactoe::checkwin()
{
    switch(1)
    {
        //row
        case 1 :
        if(slot[0][0]==slot[0][1] && slot[0][1]==slot[0][2] && slot[0][0]!=' ')
        {
            slot[0][0]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        case 2 :
        if(slot[1][0]==slot[1][1] && slot[1][1]==slot[1][2] && slot[1][0]!=' ')
        {
            slot[1][0]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        case 3 :
        if(slot[2][0]==slot[2][1] && slot[2][1]==slot[2][2] && slot[2][0]!=' ')
        {
            slot[2][0]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        //col
        case 4 :
        if(slot[0][0]==slot[1][0] && slot[1][0]==slot[2][0] && slot[0][0]!=' ')
        {
            slot[0][0]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        case 5 :
        if(slot[0][1]==slot[1][1] && slot[1][1]==slot[2][1] && slot[0][1]!=' ')
        {
            slot[0][1]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        case 6 :
        if(slot[0][2]==slot[1][2] && slot[1][2]==slot[2][2] && slot[0][2]!=' ')
        {
            slot[0][2]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        //cross/;
        case 7 :
        if(slot[0][2]==slot[1][1] && slot[1][1]==slot[2][0] && slot[0][2]!=' ')
        {
            slot[0][2]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        //cross\;
        case 8 :
        if(slot[0][0]==slot[1][1] && slot[1][1]==slot[2][2] && slot[0][0]!=' ')
        {
            slot[0][0]==player?cout<<"YOU WIN\n":cout<<"COMPUTER WIN\n";
            return false;
        }
        case 9 :
        int m=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(slot[i][j]!=' ') m++;
            }
        }
        if(m==9)
        {
            cout<<"MATCH DRAW\n";
            return false;
        }
        else return true;
    }
    return true;
}
bool tictactoe::Continue()
{
    for(int i=0;i<9;i++)
    {
        p[i]=0;
        c[i]=0;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            slot[i][j]=' ';
        }
    }
     int t;
        do
        {
        cout<<"\nCONTINUE('1' FOR YES & '0' FOR NO) : ";
        cin>>t;
        }while(t<0||t>1);
        if(t==1) return true;
        return false;
}
