 #include<graphics.h>
 #include<fstream.h>
 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<process.h>
 #include<stdlib.h>

 int a[9][9],b[9][9];
 void display(int arr[9][9]);
 void menu();
 void play();
 int solve(int x, int y);

 //class for generating.
 class Sudoku
{
  int g[9][9];
  int find;

  public:
  void input();

  int getsdk()
  {
  return find;
  }
  void assign();

}obj,obj1;

void Sudoku::input()
{   cout<<"Enter sudoku:  \n";
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    cin>>g[i][j];
    cout<<"\n";


    cout<<"Enter number  :  ";
    cin>>find;


    }
void Sudoku::assign()
{
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    a[i][j]=g[i][j];

}


 //Func to generate Sudoku.
 void generate()
{
/* ofstream fout("sudoku",ios::out);

 for(int k=0;k<3;k++)
 {obj.input();
 fout.write((char*)&obj,sizeof(obj));
 }
 fout.seekp(0);
 fout.close();
*/
 char lvl;
 int mode;
 diff:
 clrscr();
 cout<<"Enter difficulty level\n 1.Easy\n 2.Normal\n 3.Hard\n";
 cin>>lvl;

 switch(lvl)
 {case '1': mode=random(1)+1;
	  break;
  case '2': mode=random(1)+2;
	  break;
  case '3': mode=random(1)+3;
	  break;
  default:cout<<"wrong value";
	  goto diff;

}
cout<<mode;
 ifstream fin("sudoku",ios::in);
 while(!fin.eof())
 {fin.read((char*)&obj1,sizeof(obj1));

  if(obj1.getsdk()==mode)
  {obj1.assign();
  fin.close();
  }

 }
    clrscr();





    display(a);


    //Copying the input to another for the purpose of solving;
   for (int i=0;i<9;i++)
   for (int j=0;j<9;j++)
   b[i][j]=a[i][j];



   //solving
   solve(0,0) ;
   char ch;

   cout<< "\nPress 1 to play the SuDoKu\n";
   cout<< " Press any key to get the solution of the SuDoKu\n";
   cin>> ch;

   if (ch=='1')
   {

    play();

    }

   else
  {
   clrscr();
   cout<<"\n\t\The Solution is\n"  ;
   display(b);

   cout<<"\n\n\nPress any key to continue:  "  ;
   getch();


  }


  }

 //Instructions
 void instruction()
 {
  clrscr();

  gotoxy(35,2);
  cout<<"INSTRUCTIONS\n\n" ;

  cout<<" A Sudoku puzzle is defined as a logic-based, number-placement puzzle.\n";
  cout<<" The objective is to fill a 9*9 grid with digits in such a way that\n";
  cout<<" each column, each row, and each of the nine 3*3 grids that make up\n" ;
  cout<<" the larger 9*9 grid contains all of the digits from 1 to 9.\n";
  cout<<" Each Sudoku puzzle begins with some cells filled in. The player\n";
  cout<<" uses these seed numbers as a launching point toward finding the\n";
  cout<<" unique solution. It is important to stress the fact that no number\n";
  cout<<" from 1 to 9 can be repeated in any row or column (although,\n";
  cout<<" the can be repeated along the diagonals).\n";
  cout<<" For a puzzle to be a true Sudoku puzzle, it can have one (and only one)\n";
  cout<<" solution. There can be no ambiguity in Sudoku. Each number has\n";
  cout<<" a single location it must reside in. Otherwise, the player is forced\n";
  cout<<" to guess which location to choose thus changing the puzzle into a\n";
  cout<<" game of chance.\n\n" ;

  getch();
  clrscr();
  display(a);
  cout<<"\n\n\n In  Sudoku\n Rows are horizontal collection of digits\n Columns are vertical collection of digits";
  getch();
  clrscr();
  gotoxy(35,6);
 cout<<"Types of games\n\n" ;
 cout<<"1.To give input and solve\n";
 cout<<"You have to provide the input from any source that you wants to solve.\nEach value has to be entered one by one, providing their positions.\nAfter entering all the values you can either solve the sudoku with\n assistance or get the solution directly.\n\n";
 cout<<"2.To generate and solve\n";
 cout<<"Enter the difficulty level of sudoku that you want to solve.\nYou will get an automaticaaly generated sudoku on your screen.\nYou will be able to solve this Sudoku by entering the values along with\n their positions one by one.";
 getch();
 }


  //INPUT
  void readvalue()
 {
  clrscr();

  int x, y;

 char ch='y';

 cout<<"Enter the known values\n";

 while(ch=='y'||ch=='Y')
 {clrscr();


  display(a);
  cout<<"\n";
   r:
   cout<<"Enter the row:";
   cin>>x;
   if(x>9||x<1)
   {cout<<"wrong position \n";
    goto r;    }


   c:
   cout<<"Enter the column:";
   cin>>y;
   if(y>9||y<1)
   {cout<<"wrong position \n";
    goto c;     }


   v:
   cout<<"Enter the value:";
   cin>>a[x-1][y-1];
   if(a[x-1][y-1]>9||a[x-1][y-1]<1)
   {cout<<"wrong value \n ";
    goto v;      }

   clrscr();
   display(a);
   cout<<"\n";
   cout<<"Want to enter more values\n Press (y/Y) for yes \n Press any other key to solve\n" ;
   cin>>ch;
   }


   //Copying the input to another for the purpose of solving;
   for (int i=0;i<9;i++)
   for (int j=0;j<9;j++)
   b[i][j]=a[i][j];


   //solving
   solve(0,0) ;
   clrscr();
   cout<< "\n\n\nPress 1 to play the SuDoKu\n\n Press any key to get the solution of the SuDoKu\n";
   cin>> ch;
   if (ch=='1')
   {

    play();

    }

   else
  {clrscr();
   cout<<"The Solution is \n\n" ;
   display(b);
   cout<<"\n\nPress any key to continue:  "  ;
   getch();

  }
  }


 //Diplays the SuDoKu
 void display(int arr[9][9])
 {
   int i,j;

   cout<<"\n";
    for(i=0;i<9;i++)
  { gotoxy(27,i+4);
    for(j=0;j<9;j++)
    cout<<arr[i][j]<<"  ";
  }
    //top
    gotoxy(26,2);
    for(i=0;i<27;i++)
    cout<<"_";

    //left
    for(i=0;i<10;i++)
   {gotoxy(25,i+3);
    cout<<"|\n";
   }

    //right
    for(i=0;i<10;i++)
   {gotoxy(53,i+3);
    cout<<"|\n";
   }


    //bottom
    gotoxy(26,12);
    for(i=0;i<27;i++)
    cout<<"_";


 }


 //Playing SuDoKu

 void play()
  {
   clrscr();
   display(a);

  int count;

  int x,y;
  cout<<"Start playing\n\n";



  cout<<"Press any key to continue";

  char w;
  cin>>w;
  char ch='y';

  while(ch == 'y'||ch=='Y')
  { count=0;

   r1:
   cout<<"Enter the row:";
   cin>>x;
   if(x>9||x<1)
   {cout<<"wrong position \n";
    goto r1;    }


   c1:
   cout<<"Enter the column:";
   cin>>y;
   if(y>9||y<1)
   {cout<<"wrong position \n";
    goto c1;     }


   v1:
   cout<<"Enter the value:";
   cin>>a[x-1][y-1];
   if(a[x-1][y-1]>9||a[x-1][y-1]<1)
   {cout<<"wrong value \n ";
    goto v1;      }


   if(a[x-1][y-1]==b[x-1][y-1])
   {cout<<"Correct value entered\n";
   }
   else
   {cout<<"incorrect value entered\n";
    a[x-1][y-1]=0;
    }

   clrscr();
   display(a);
   cout<<"\n";

   for(int i=0; i<9; i++)
   for(int j=0; j<9; j++)
   if( a[i][j]==b[i][j])
     count++;
   if(count==81)
   cout<<"SUCCESS\n";

   else
   cout<<"Do you want to continue \n Press (Y/y) to continue\n Press any other key to quit game and get solution\n";
   cin>>ch;

   if(ch!= 'y'&& ch!='Y')
   {clrscr();
    cout<<"The solution is:\n\n" ;
    clrscr();
    display(b);
    cout<<"\n\nPress any key to continue:  "  ;
    getch();

   }
   }
   }


 int inputvalue(int x, int y, int value)
 { //scanning vertically and horizontally
 for(int i=0;i<9;i++)

 {
 if (value == b[x][i] || value==b[i][y])
 return 0;
 }

 //scanning in its own square
 for(i=(x/3)*3;i<=((x/3)*3)+2;i++)
 for(int j=(y/3)*3;j<=((y/3)*3)+2;j++)

 if(value==b[i][j])

 return 0;

 return value;

 }






int solve(int x, int y)
{
  int temp, i, j;
  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++)
      if (b[i][j] > 9 || b[i][j] < 0)
	return 0;

  if (b[x][y] == 0)

  {

    for (i = 1; i < 10; i++)
    {

      temp = inputvalue(x, y, i);
      if (temp > 0)
      {
	b[x][y] = temp;

	if (x == 8 && y == 8)
	{

	  return 1;
	}

	else if (x == 8)
	{
	  if (solve(0, y + 1)) return 1;
	}

	else
	{
	  if (solve(x + 1, y)) return 1 ;
	}
      }
    }

    if (i == 10)
    {
      if (b[x][y] !=  a[x][y]) b[x][y] = 0;
      return 0;
    }
  }

  else
  {

    if (x == 8 && y == 8)
    {
      return 1;
    }

    else if (x == 8)
    {
      if (solve(0, y + 1)) return 1;
    }

    else
    {

      if (solve(x + 1, y)) return 1;
    }
  }

}






 void main()
 {

 clrscr();
 textbackground(22);
 textcolor(555);

 menu();

 getch();

 }


void menu()
{

for(int i=0;i<9;i++)
 for(int j=0;j<9;j++)
 a[i][j]=0;
beg:
clrscr();
 gotoxy(30,3);
 cout<<"WELCOME TO SuDoKu GAME\n\n";
 gotoxy(40,6);
 cout<<"MENU\n\n" ;
 cout<<"1.To give input and solve\n";
 cout<<"2.To generate and solve\n";
 cout<<"3.Instructions\n" ;
 cout<<"4.Quit\n";
 char choice;
 cout<<"Enter your choice:  ";

 cin>>choice;

 switch(choice)
   {
 case '1': clrscr();
	   readvalue();
	   goto beg;

 case '2': clrscr();
	   generate();
	   goto beg;
 case '3': clrscr();
	   instruction();
	   clrscr();
	   goto beg;

 case '4': exit(0);
	   break;
 default: cout<<"Wrong value\n";
	  clrscr();
	  goto beg;
   }
 }
