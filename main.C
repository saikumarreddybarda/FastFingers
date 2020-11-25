#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <graphics.h>

#define TESTMODE '1'
#define TRAINMODE '2'
#define QUIT '3'
#define ESC '\x1b'
#define Y 'y'
#define N 'n'
struct usercmp{
   char str[20];
   float avg;
} p[10];
void MainInitial () ;
void Body () ;
void MainProcess () ;
void RegisterProcess();
void NewUser();
void OldUser();
void ProgText();
void Cprog();
void java();
void python();
void FavText() ;
void Movies();
void Politics();
void Poems();
void TestMode (FILE *) ;
void TestInitial (int * , int * , FILE * , char *) ;
void TestProcess (int * , int * , int * , int * , char * , int * ) ;
void UserInput (int * , int * , int * , int * , char *) ;
void EndTestMode () ;
void OutputLetter (int * , int * , char , int *) ;
void CheckCursorPosition (int * , int * , int * , char * , int *) ;
void NewFile (int * , int * , FILE *) ;
void NewPage (int * , int * , char * , int *) ;
void NewLine (int * , int *) ;
void CheckIfTyped(int * , int *) ;
void Report (int * , int *) ;
void CalPrac();
void Basics();
void TrainMode () ;
void TrainInitial () ;
void TrainInitial_cal() ;
void TrainLetter () ;
void TrainWord () ;
void TrainProcess (int * , int *) ;
void SelectLetter (char , int * , int *) ;
void SelectLetter_cal(char , int * , int *) ;
void PrintLetter () ;
void PrintLetter_cal();
void TrainUserInput (char , int * , int *) ;
void EndTrainMode () ;
void TrainOutputLetter (int , int * , int *) ;
void SelectWord (int * , int *) ;
void PrintWord (char *) ;
void TrainUserInputWord (char * , int * , int *) ;
void EndTrainWordMode () ;
void TrainOutputWord (int * , int *) ;
void TrainCheckIfTyped (int * , int *) ;
void TrainReport (int * , int *) ;
void Game();
void LeaderBoard();
void QuitConfirm () ;
void EndBody () ;
void EndProgram () ;
enum Boolean { FALSE , TRUE } ;
enum Boolean 	ExitProgram , ExitTestProcess , ExitTrainProcess , ExitTrainUserInput
	      ,	MiddleRow , UpperRow , LowerRow , NumberRow,CalRow
	      , TrainSelect , ChoiceLetter , ExitTrainUserInputWord
	      , EndOfWord ;

int FileLength ;
char RequiredLetter,USERNAME[100], fname[10]=".txt";
float TimeUsed,Accr,Wpm;
char MiddleRowLetters [9] = {'a','s','d','f','g','h','j','k','l'} ;
char UpperRowLetters [10] = {'q','w','e','r','t','y','u','i','o','p'} ;
char LowerRowLetters [7]  = {'z','x','c','v','b','n','m'} ;
char NumberRowLetters [10]= {'0','1','2','3','4','5','6','7','8','9'} ;
char CalculatorKeys[20]={'-','+','*','/','.','<','>',':','(',')','^','%','#','@','!'};
char GAMECHOICE;
int GAMEMODE=0;
clock_t TimeStart , TimeStop ;

void main()
{
	//randomize () ;   //to make the random number generated more randomly

	MainInitial () ;

	Body () ;

	EndProgram () ;
}

void MainInitial ()
{
	ExitProgram = FALSE ;
}

void Body ()
{
    RegisterProcess();

	do
	{
	       MainProcess () ;

	} while (ExitProgram == FALSE) ;  //Once ExitProgram is True,
}

void RegisterProcess(){
	int Count ;
	char MenuChoice ;
textcolor(WHITE);	//change the text and background colour
	textbackground(GREEN);
	clrscr () ;
	gotoxy (10 , 4) ;
printf("++++++++++++++++++++++++FAST FINGERS+++++++++++++++++++++++++");
    gotoxy (10 , 5) ;
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    gotoxy(20,6);
    printf("Here you can become \x84 king in typing!");
	gotoxy (30 , 9) ;	//display the frame
	printf ("\xc9") ;
		for (Count = 1 ; Count <= 25 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 9) ;
		for (Count = 1 ; Count <= 6 ; Count++ )
		{
			gotoxy (30 , 9 + Count) ;
			printf ("\xba") ;
		}
	gotoxy (56 , 9) ;
	printf ("\xbb") ;
	gotoxy (30 , 15) ;
	printf ("\xc8") ;
		for (Count = 1 ; Count <= 26 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 15) ;
	printf ("\xbc") ;
		for (Count = 1 ; Count <= 5 ; Count++ )
		{
			gotoxy (56 , 9 + Count) ;
			printf ("\xba") ;
		}
	gotoxy (35 , 10) ;
	printf ("1.new user ") ;       //Display the menu
	gotoxy (35 , 11) ;
	printf ("2.old user") ;
	gotoxy (35 , 12) ;
	printf ("select your Choice?: \n") ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;
	gotoxy (52 , 14) ;
	MenuChoice = getch () ;           //Accept a key value from the user
	switch (MenuChoice)
	{
		case '1' :		 //if the user press 1

			NewUser();
			break ;

		case '2' :	 //if the user press 2

			OldUser();
			break ;

	}
}
void NewUser(){
    char name[100];
    	int Count ;
    	 char ch,tempstr[20][100],temp[50];
	 int k=12,i=0,m=0;
    	FILE *ptr,*uptr;
    	textcolor(WHITE);	//change the text and background colour
	textbackground(BLACK);
	clrscr () ;
	gotoxy (30 , 9) ;	//display the frame
	printf ("\xc9") ;
		for (Count = 1 ; Count <= 25 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 9) ;
		for (Count = 1 ; Count <= 6 ; Count++ )
		{
			gotoxy (30 , 9 + Count) ;
			printf ("\xba") ;
		}
	gotoxy (56 , 9) ;
	printf ("\xbb") ;
	gotoxy (30 , 15) ;
	printf ("\xc8") ;
		for (Count = 1 ; Count <= 26 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 15) ;
	printf ("\xbc") ;
		for (Count = 1 ; Count <= 5 ; Count++ )
		{
			gotoxy (56 , 9 + Count) ;
			printf ("\xba") ;
		}

	gotoxy (35 , 10) ;
	printf ("Enter your name") ;
	gotoxy (35 , 11) ;
	scanf("%[^\n]%*c", name);
	strcpy(USERNAME,name);
	 ptr = fopen("usernames.txt", "r");
       if(ptr!=NULL){
            while ((ch = fgetc(ptr) )!= EOF)
        {
            if(ch=='\n'){
                strcpy(tempstr[m],temp);
                m++;
                gotoxy (35 , k) ;
                k=k+1;
                 memset(temp,0,strlen(temp));
                 i=0;
            }
            else{
            temp[i]=ch;
            i++;
            }
        }
       fclose(ptr);
       }
       else{
        printf("file not exist!");
       }
	i=0;
	while(i<=m){
        if(strcmp(name,tempstr[i])==0){
             break;
        }
        i++;
	}
	if(i>m){
       ptr = fopen("usernames.txt", "a");
       if(ptr!=NULL){
       fprintf(ptr, "%s\n", name);
       fclose(ptr);
       gotoxy (30 , 25) ;
       printf("press any key to continue..");
       getch();
       }
       else{
        printf("file not exist!");
       }
    strcat(name,fname);
    uptr=fopen(name,"w");
    fclose(uptr);
	}
	else{
         clrscr () ;
    textcolor(WHITE);	//change the text and background colour
	textbackground(RED);
	 gotoxy(10,3);
            printf("This name is already there in the list please reenter the name again!");
            gotoxy (30 , 25) ;
       printf("press any key to continue..");
        getch();
            NewUser();
	}
}
void OldUser(){
   char name[100];
    	int Count ;
    	FILE *ptr;
    	 char ch,tempstr[20][100],temp[50];
	 int k=12,i=0,m=0;
	  	textcolor(WHITE);	//change the text and background colour
	textbackground(RED);
	clrscr () ;
	gotoxy (30 , 9) ;	//display the frame
	printf ("\xc9") ;
		for (Count = 1 ; Count <= 25 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 9) ;
		for (Count = 1 ; Count <= 6 ; Count++ )
		{
			gotoxy (30 , 9 + Count) ;
			printf ("\xba") ;
		}
	gotoxy (56 , 9) ;
	printf ("\xbb") ;
	gotoxy (30 , 15) ;
	printf ("\xc8") ;
		for (Count = 1 ; Count <= 26 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (56 , 15) ;
	printf ("\xbc") ;
		for (Count = 1 ; Count <= 5 ; Count++ )
		{
			gotoxy (56 , 9 + Count) ;
			printf ("\xba") ;
		}
	clrscr () ;
	gotoxy (35 , 10) ;
	printf ("enter your name") ;
	gotoxy (35 , 11) ;
	 ptr = fopen("usernames.txt", "r");
       if(ptr!=NULL){
            while ((ch = fgetc(ptr) )!= EOF)
        {
            if(ch=='\n'){
                strcpy(tempstr[m],temp);
                printf("%s ",tempstr[m]);
                m++;
                gotoxy (35 , k) ;
                k=k+1;
                 memset(temp,0,strlen(temp));
                 i=0;
            }
            else{
            temp[i]=ch;
            i++;
           // printf ("%c", ch);
            }
        }
       fclose(ptr);
       }
       else{
        printf("file not exist!");
       }
	gotoxy (35 , k+1) ;
	scanf("%[^\n]%*c", name);
	strcpy(USERNAME,name);
	i=0;
	while(i<=m){
        if(strcmp(name,tempstr[i])==0){
             break;
        }
        i++;
	}
	if(i>m){
            clrscr () ;
    textcolor(WHITE);	//change the text and background colour
	textbackground(RED);
	 gotoxy(10,3);
            printf("Your name is not there in the list please reenter the name again");
            gotoxy (30 , 25) ;
       printf("press any key to continue..");
        getch();
            OldUser();
	}
	gotoxy (30 , 25) ;
       printf("press any key to continue..");
        getch();
}
void MainProcess ()
{
	int Count ;
	char MenuChoice ;
clrscr () ;
textcolor(WHITE);	//change the text and background colour
	textbackground(YELLOW);
    gotoxy (10 , 2) ;
printf("************************FAST FINGERS*************************");
	gotoxy (20 , 3) ;	//display the frame
	printf ("\xc9") ;
		for (Count = 1 ; Count <= 45 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (40 , 3) ;
		for (Count = 1 ; Count <= 15 ; Count++ )
		{
			gotoxy (20 , 3 + Count) ;
			printf ("\xba") ;
		}
	gotoxy (20 , 19) ;
	printf ("\xc8") ;
		for (Count = 1 ; Count <= 45 ; Count++ )
		{
			printf ("\xcd") ;
		}
	gotoxy (52 ,4 ) ;
	//printf ("\xbc") ;
		for (Count = 1 ; Count <= 17 ; Count++ )
		{
			gotoxy (65 , 2 + Count) ;
			printf ("\xba") ;
		}
		gotoxy(23,4);
		printf("hi,%s lets start practicing!",USERNAME);
		 gotoxy (23,5) ;
		 printf("We strongly recommend you to practice on");
		 gotoxy (23,6) ;
		 printf("Basics Before going to another modules");
//Display the menu
	gotoxy (35 , 10) ;
	printf ("1.BASICS PRACTICE") ;
	gotoxy (35 , 11) ;
	printf ("2.PROGRAMMING TEXT") ;
	gotoxy (35 , 12) ;
	printf ("3.CALCULATOR PRACTICE") ;
	gotoxy (35 , 13) ;
	printf ("4.FAVORITE TEXT") ;
	gotoxy (35 , 14) ;
	printf ("5.GAME") ;
	gotoxy (35 , 15) ;
	printf ("6.LEADER BOARD") ;
	gotoxy (35 , 16) ;
	printf ("7. Quit Now") ;
	gotoxy (35 , 17) ;
	printf ("Enter your Choice? : \n") ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;
	gotoxy (52 , 18) ;
	MenuChoice = getch () ;           //Accept a key value from the user

	switch (MenuChoice)
	{
		case '2' :
            ProgText();
			break ;

		case '4' :

            FavText() ;
			break ;
        case '3' :

            CalPrac() ;
			break ;
        case '1' :

            Basics() ;
			break ;
        case '6' :
            LeaderBoard() ;
			break ;
        case '5' :
            Game() ;
			break ;
		case '7' :	case ESC :	//if the user press ESC or 3

			QuitConfirm () ;	//Call QuitConfirm ()
	}					//function to confirm if the
}						//user want to quit or
					//selected it by mistake
void  ProgText(){
    char MenuChoice;
    clrscr () ;
        textcolor(WHITE);	//change the text and background colour
	textbackground(BLACK);
 gotoxy (10, 7) ;
 printf("These are some Programming languages you practice on you choice!");
	gotoxy (35 , 10) ;
    printf ("1.C language") ;
	gotoxy (35 , 11) ;
	printf ("2.python") ;
	gotoxy (35 , 12) ;
	printf ("3.java");
	gotoxy (35 , 13) ;
	printf ("4. Quit Now") ;
	gotoxy (35 , 15) ;
	printf ("What Choice? : \n") ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to back.") ;
	gotoxy (52 , 16) ;

	MenuChoice = getch () ;           //Accept a key value from the user

	switch (MenuChoice)
	{
		case '1' :		 //if the user press 1
            Cprog();
			break ;

		case '2':	 //if the user press 2
			python() ;
			break ;
        case '3':	 //if the user press 2
			java() ;
			break ;

		case '4' :	case ESC :	//if the user press ESC or 3
                break;
			 	//Call QuitConfirm ()
	}					//function to confirm if the
}
void Cprog(){
     FILE *FilePointer;
     char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("c_prog_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("c_prog_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3' :
			FilePointer = fopen ("c_prog_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
	}
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}


}
void python(){
     FILE *FilePointer;
    char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("python_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("python_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3':
			FilePointer = fopen ("python_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
    }
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}

}
void java(){
     FILE *FilePointer;
    char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("java_prog_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("java_prog_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3' :
			FilePointer = fopen ("java_prog_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
	}
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}
}
void FavText(){
      char MenuChoice;
        textcolor(WHITE);	//change the text and background colour
	textbackground(BLUE);

	clrscr () ;
	gotoxy (35 , 10) ;
    printf ("1.Movies") ;
	gotoxy (35 , 11) ;
	printf ("2.Politics") ;
	gotoxy (35 , 12) ;
	printf ("3.Poems");
	gotoxy (35 , 13) ;
	printf ("4. Quit Now") ;
	gotoxy (35 , 15) ;
	printf ("What Choice? : \n") ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;
	gotoxy (52 , 16) ;

	MenuChoice = getch () ;           //Accept a key value from the user

	switch (MenuChoice)
	{
		case '1' :		 //if the user press 1
            Movies();
			break ;

		case '2':	 //if the user press 2
			Politics() ;
			break ;
        case '3':	 //if the user press 2
			Poems() ;
			break ;

		case '4' :	case ESC :	//if the user press ESC or 3
            break;
				//Call QuitConfirm ()
	}					//function to confirm if the
}
void Movies(){
      FILE *FilePointer;
     int RandomFile ;
	 char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("movie_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("movie_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3' :
			FilePointer = fopen ("movie_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
	}
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}

}
void Politics(){
         FILE *FilePointer;
  char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("politics_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("politics_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3' :
			FilePointer = fopen ("politics_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
	}
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}

}
void Poems(){
     FILE *FilePointer;
   char ch;
     clrscr();
     gotoxy(30,9);
    printf("press 1, 2 or 3");
	ch=getch();
	if(ch=='1'||ch=='2'||ch=='3'){
	switch (ch)    //select a random file
	{
		case '1' :
			FilePointer = fopen ("poems_1.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '2' :
			FilePointer = fopen ("poems_2.txt" , "r") ;
			TestMode(FilePointer);
			break ;
		case '3' :
			FilePointer = fopen ("poems_3.txt" , "r") ;
			TestMode(FilePointer);
			break ;
	}
    }
	else{
            clrscr();
        gotoxy(30,15);
        printf("please press only 1 ,2 or 3!");
        getch();
	}
}
void TestMode(FILE *fp)
{
    FILE *FilePointer ;	//initial the pointer of the file
    char str[50000] ;	 //declare a buffer to hold the passage
	int x = 0 , y = 0 , InputCount = 0 , CorrectInputCount = 0 ,Page = 0 ;
	FilePointer=fp;

	clrscr () ;                //clear the screen

	TestInitial (&x , &y , FilePointer , str) ;

	do                         //Once the user pressed ESC, it will exit
	{			   //TestProcess
		TestProcess (    &x , &y , &InputCount ,
			&CorrectInputCount , str , &Page ) ;

	} while (ExitTestProcess == FALSE) ;

	//if the user have not typed any letter, no report will be printed
	CheckIfTyped (&InputCount , &CorrectInputCount) ;

	fclose (FilePointer) ;	//close the file
}

void TestInitial (int *x , int *y , FILE *FilePointer , char *str)
{
	int Row , Column , Count , Size;
	if ( FilePointer == NULL )		//if cannot open the file
	{
		printf ("\nCannot open the file.") ;
		ExitTestProcess = TRUE ;
	}
	else					//if can open the file
	{
		clrscr () ;
		//The letters of the external file are checked if they are
		//newlines or tabs. If they are , they will be changed into
		//spaces to avoid any error.
		for ( Count = 0 ;  !feof(FilePointer)  ; Count++ )
		{
			if (   (str[Count] = fgetc(FilePointer))  ==  '\t'
				||   str[Count] == '\n'	)
			{
				str[Count] = ' ' ;
			}
		}
		//Print out the passage to the screen and add empty lines
		//between every lines
		for (Row = 0 ; Row < 6 ; Row++)
		{
			for (Column = 1 ; Column <= 80 ; Column++)
			{
				if (str[80 * Row + Column - 1] == EOF)
				{
					goto ExitFor ;
				}
				printf ("%c" , str[80 * Row + Column - 1] ) ;
			}
			printf ("\n\n")  ;
		}
	}

ExitFor :

	ExitTestProcess = FALSE ;

	*x = 1 ;	//tell the computer that the starting cursor position
	*y = 2 ;	//is (1 , 2) .

	gotoxy (1 , 25) ;
	printf ("Press any key to start!") ;
	getch () ;	//wait for the user to press any key

	delline () ;	//delete all the content of the current line

	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;

	TimeUsed = 0 ;
	TimeStart = clock () ;	//record the current time into TimeStart

	gotoxy (1 , 2) ;
}

void TestProcess (int *x , int *y , int *InputCount ,
		  int *CorrectInputCount , char *str , int *Page )
{
	UserInput (x , y , InputCount , CorrectInputCount , str ) ;

	CheckCursorPosition (x , y , CorrectInputCount , str , Page) ;
}

void UserInput (int *x , int *y , int *InputCount , int *CorrectInputCount ,
		char *str )
{
	char InputLetter ;
	static float TimeStop ;
	gotoxy (27 , 19) ;
		printf ("Time used     :   ") ;
	gotoxy (27 , 20) ;
		printf ("Accuracy      :   ") ;
	gotoxy (27 , 21) ;
		printf ("Speed         :   ") ;
	gotoxy (27 , 22) ;
		printf ("Wrong letters :   ") ;
	gotoxy (27 , 23) ;
		printf ("Typed letters :   ") ;
	gotoxy (*x , *y) ;
while ( !kbhit() )
{
	if ( *InputCount > 0 )
	{
	double Speed ;
	//Calculate the accuracy
	float Accuracy = (float) *CorrectInputCount * 100 / *InputCount ;
	//Calculate the number of letters typed wrongly
	int WrongInput = *InputCount - *CorrectInputCount ;
	//Calculate wpm
	TimeStop = clock () ;
	TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK ;
	Speed = *CorrectInputCount / 5 / (TimeUsed / 60) ;
	if(GAMEMODE==1){
        if(GAMECHOICE=='1'&&TimeUsed>=60){
            EndTestMode();
        }
         if(GAMECHOICE=='2'&&TimeUsed>=30){
            EndTestMode();
        }
         if(GAMECHOICE=='3'&&TimeUsed>=15){
            EndTestMode();
        }
	}
	TimeStart = clock () ;
	gotoxy (45 , 19) ;
		printf ("%10.2f seconds" , TimeUsed) ;
	gotoxy (45 , 20) ;
		printf ("%10.2f %%" , Accuracy) ;
	gotoxy (45 , 21) ;
		printf ("%10.2f wpm" , Speed) ;
	gotoxy (45 , 22) ;
		printf ("%10d letters" , WrongInput) ;
	gotoxy (45 , 23) ;
		printf ("%10d letters" , *InputCount) ;
	gotoxy (*x , *y) ;
	delay (100) ;
	}
}
	InputLetter = getch () ;
	if (InputLetter == ESC)	//if the user press ESC
	{
	       TimeStop = clock () ;
	       EndTestMode () ;
	}
	else
	{
		//if the user typed correcly
		if ( InputLetter == str [ *CorrectInputCount ] )
		{
			OutputLetter (x , InputCount ,
					 InputLetter , CorrectInputCount) ;
		}
		else            //if the user typed wrongly
		{
			(*InputCount) ++ ;
		}
	}
}

void EndTestMode ()
{
	ExitTestProcess = TRUE ;
}

void OutputLetter (int *x , int *InputCount ,
			 char InputLetter , int *CorrectInputCount)
{
	(*CorrectInputCount) ++ ;	//the user typed 1 more correct
	(*InputCount) ++ ;		//the user typed 1 more letter
	putchar (InputLetter) ;		//output the key the user pressed

	(*x) ++ ;			//tell the computer that
					//the cursor should be shifted
					//to right by 1 position
}

void CheckCursorPosition (int *x , int *y ,
			int *CorrectInputCount , char *str , int *Page)
{
	if ( str[*CorrectInputCount] == EOF )
	{
		getch () ;
		TimeStop = clock () ;
		EndTestMode () ;
	}
	else	//if the cursor reach the end of any line ,
	{
		if (	wherex () == 1 && wherey () >= 17   )
		{
			clrscr () ;
			NewPage (x , y , str , Page) ;
		}
		else
		{
			if (*x == 81)
			{
				NewLine (x , y) ;
			}
		}
	}
}

void NewPage (int *x , int *y , char *str , int *Page)
{
	int Row , Column ;

	(*Page) ++ ;

	clrscr () ;

	for (Row = 0 ; Row < 6 ; Row++)
	{
		for ( Column = 1 ; Column <= 80 ; Column++   )
		{
			if (str[ (Row * 80  + Column - 1)
				+ (*Page * 80 * 6) ] == EOF)
			{
				goto ExitFor ;
			}
			printf ("%c" ,
			 str[ (Row * 80  + Column - 1) + (*Page * 80 * 6) ] ) ;
		}
		printf ("\n\n")  ;
	}

ExitFor:
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;

	*x = 1 ;
	*y = 2 ;

	gotoxy (*x , *y) ;
}

void NewLine (int *x , int *y)
{
	*x = 1 ;
	*y += 3 ;	//tell computer to shift the cursor down two rows

	gotoxy (*x , *y) ;
}

void CheckIfTyped (int *InputCount , int *CorrectInputCount)
{
	if (*InputCount != 0)	//if the user have not typed anything
		Report (InputCount , CorrectInputCount) ;//generate report
}

void Report (int *InputCount , int *CorrectInputCount)
{
    FILE *uptr;
	char name[100];
	//Calculate the accuracy
	float Accuracy = (float) *CorrectInputCount * 100 / *InputCount ;
	//Calculate the number of letters typed wrongly
	int WrongInput = *InputCount - *CorrectInputCount ;
	//Calculate wpm
	double Speed = *CorrectInputCount / 5 / (TimeUsed / 60) ;

	clrscr () ;

	gotoxy (20 , 8) ;
	printf ( "Time Used       : %10.2f seconds" , TimeUsed ) ;
	gotoxy (20 , 10) ;
	printf ( "Character Typed : %10d letters" , *InputCount ) ;
	gotoxy (20 , 12) ;
	printf ( "Wrong Input     : %10d letters" , WrongInput ) ;
	gotoxy (20 , 14) ;
	printf ( "Accuracy        : %10.2f %%" , Accuracy) ;
	gotoxy (20 , 16) ;
	printf ( "Speed           : %10.2f wpm (words per minute)" , Speed) ;
	gotoxy (26 , 25) ;
	printf ( "Press ESC key to exit") ;
    Accr=Accuracy;
    Wpm=Speed;
	strcpy(name,USERNAME);
    strcat(name,fname);
    uptr=fopen(name,"w");
    fprintf(uptr,"%f\n%f",Accr,Wpm);
    fclose(uptr);
	//wait until the user press ESC
	while (    tolower(getch ())  != ESC  ) {}
}

void CalPrac(){
    int CorrectInputCount = 0 , InputCount = 0 ;
    char InputLetter ;
	TimeUsed = 0 ;

	TrainInitial_cal() ;

	//Once the user pressed ESC , it will end TrainProcess
	while (ExitTrainProcess == FALSE)
	{
		SelectLetter_cal(InputLetter , &CorrectInputCount , &InputCount) ;
	}

	//Check if the user typed in train mode
	TrainCheckIfTyped ( &CorrectInputCount , &InputCount ) ;
}
void SelectLetter_cal(char InputLetter , int *CorrectInputCount , int *InputCount)
{
	ExitTrainUserInput = FALSE ;

	PrintLetter_cal() ;

	do	//Once the user press ESC key , it will exit Train mode
	{
		TrainUserInput ( InputLetter , CorrectInputCount , InputCount ) ;

	} while ( ExitTrainUserInput == FALSE ) ;
}
void TrainInitial_cal() {
    char ch ;
	int temp ;

	ChoiceLetter = TRUE ;

	ExitTrainProcess = FALSE ;
	NumberRow = TRUE ;
	CalRow=TRUE;
	clrscr () ;
	gotoxy (1 , 25) ;
	printf ("Press any key when ready.") ;	//wait for the user to press
	getch() ;
}
void PrintLetter_cal(){
	//make a random number to choose a random row.
	int RandomRow = random (2) + 1 ;

	int RandomNumberLetter	 , RandomCalLetter  ;

	RandomNumberLetter = random (10) ;	//from 0 to 9

    RandomCalLetter = random (15) ;	//from 0 to 6
    switch (RandomRow)
			{
				case 1 :
					RequiredLetter=CalculatorKeys[RandomCalLetter];
					break ;
				case 2 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
                default :
			printf("\nYou are at the default position") ;
	}
	clrscr () ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;

	gotoxy (40 , 12) ;
	printf ("%c" , RequiredLetter) ;
	TimeStart = clock () ;
}
void Basics(){
      int CorrectInputCount = 0 , InputCount = 0 ;

	TimeUsed = 0 ;

	TrainInitial() ;

	//Once the user pressed ESC , it will end TrainProcess
	while (ExitTrainProcess == FALSE)
	{
		TrainProcess ( &CorrectInputCount , &InputCount) ;
	}

	//Check if the user typed in train mode
	TrainCheckIfTyped ( &CorrectInputCount , &InputCount ) ;
}

void TrainInitial ()
{

	char ch ;
	clrscr () ;
	ExitTrainUserInputWord = FALSE ;
	ExitTrainProcess = FALSE ;

	gotoxy (28 , 12) ;
	printf ("1. Do you want to train single letters.") ;
	gotoxy (28 , 14) ;
	printf ("2. Do you want to train With words.");
	gotoxy (28 , 16) ;
	printf ("Please press either 1 , 2 or ESC : ") ;
	while (   (ch = getch ())   !=   '1'  &&   ch   !=   '2'
			&&	ch   !=   ESC  )
	{}

	if (ch == ESC)
	{
		ExitTrainProcess = TRUE ;
	}
	else
	{
		if (ch == '1')
		{
			TrainLetter () ;
		}
		else
		{
			TrainWord () ;
		}
	}
}

void TrainLetter ()
{
	char ch ;
	int temp ;

	ChoiceLetter = TRUE ;

	ExitTrainProcess = FALSE ;
	MiddleRow = TRUE ;
	UpperRow  = TRUE ;
	LowerRow  = TRUE ;
	NumberRow = TRUE ;
	clrscr () ;
	gotoxy (1 , 25) ;
	printf ("Press any key when ready.") ;	//wait for the user to press
	getch() ;				//any key.
}

void TrainWord ()
{
	ChoiceLetter = FALSE ;
}

void TrainProcess (int *CorrectInputCount , int *InputCount)
{
	char InputLetter ;

	if (ChoiceLetter == TRUE)
	{
		SelectLetter (InputLetter , CorrectInputCount , InputCount) ;
	}
	else
	{
		SelectWord (CorrectInputCount , InputCount) ;
	}
}

void SelectLetter(char InputLetter , int *CorrectInputCount , int *InputCount)
{
	ExitTrainUserInput = FALSE ;

	PrintLetter () ;

	do	//Once the user press ESC key , it will exit Train mode
	{
		TrainUserInput ( InputLetter , CorrectInputCount , InputCount ) ;

	} while ( ExitTrainUserInput == FALSE ) ;
}
void PrintLetter ()
{
	//Convert the four choices into binary number to analyst
	int RowChoice = 1000*MiddleRow + 100*UpperRow
				 + 10*LowerRow + NumberRow ;

	//make a random number to choose a random row.
	int RandomRow = random (MiddleRow + UpperRow
				 + LowerRow + NumberRow) + 1 ;

	int RandomUpperLetter    ,    RandomMiddleLetter ,
	    RandomNumberLetter	 ,    RandomLowerLetter ;

	RandomNumberLetter = random (10) ;	//from 0 to 9

	RandomUpperLetter = random (10) ;	//generate a random
						//from 0 to 9

	RandomMiddleLetter = random (9) ;	// from 0 to 8

	RandomLowerLetter = random (7) ;	//from 0 to 6

	switch (RowChoice)
	{
/*number only*/	case    1 :
			RequiredLetter=NumberRowLetters[RandomNumberLetter]; //from 0 to 9
			break ;
/*lower only*/	case   10 :
			RequiredLetter=LowerRowLetters[RandomLowerLetter];
			break ;
		case   11 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
				case 2 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
/*upper only*/	case  100 :
			RequiredLetter=UpperRowLetters[RandomUpperLetter];
			break ;
		case  101 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 2 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
		case  110 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 2 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
			}
			break ;
		case  111 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 2 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
				case 3 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
/*middle only*/	case 1000 :
			RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
			break ;
		case 1001 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
		case 1010 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
			}
			break ;
		case 1011 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
				case 3 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
		case 1100 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
			}
			break ;
		case 1101 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 3 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
		case 1110 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 3 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
			}
			break ;
/*All the rows*/
		case 1111 :
			switch (RandomRow)
			{
				case 1 :
					RequiredLetter=MiddleRowLetters[RandomMiddleLetter];
					break ;
				case 2 :
					RequiredLetter=UpperRowLetters[RandomUpperLetter];
					break ;
				case 3 :
					RequiredLetter=LowerRowLetters[RandomLowerLetter];
					break ;
				case 4 :
					RequiredLetter=NumberRowLetters[RandomNumberLetter];
					break ;
			}
			break ;
		default :
			printf("\nYou are at the default position") ;
	}

	clrscr () ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;

	gotoxy (40 , 12) ;
	printf ("%c" , RequiredLetter) ;
	TimeStart = clock () ;	//record the current time as start time
}

void TrainUserInput (char InputLetter , int *CorrectInputCount , int *InputCount)
{
	gotoxy (40 , 13) ;

	InputLetter = getch () ; //wait for the user to input choice

	if (InputLetter == ESC)  //Pressed ESC key
	{
		EndTrainMode () ;
	}
	else
	{
		if (InputLetter == RequiredLetter)	 //Typed correctly
		{
			TrainOutputLetter (InputLetter , CorrectInputCount , InputCount) ;
		}
		else					//Typed wrongly
		{
			(*InputCount) ++ ;
		}
	}

}

void EndTrainMode ()
{
	ExitTrainUserInput = TRUE ;
	ExitTrainProcess   = TRUE ;
}

void TrainOutputLetter (int InputLetter , int *CorrectInputCount , int *InputCount)
{
	TimeStop = clock () ;	//Record the current time as stop time

	(*CorrectInputCount) ++ ;

	(*InputCount) ++ ;

	printf ("%c" , InputLetter) ;

	ExitTrainUserInput = TRUE ;

	//Accumulate the time used of the user to type many letters
	TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK  ;

}

void SelectWord (int *CorrectInputCount , int *InputCount)
{
	char Word[20] ;
	int Count ;

	ExitTrainUserInputWord = FALSE ;

	for (Count = 0 ; Count < 20 ; Count++)
	{
		Word[Count] = 0 ;
	}

	PrintWord (Word) ;

	do
	{
		TrainUserInputWord (Word , CorrectInputCount , InputCount) ;

	} while (  (ExitTrainUserInputWord == FALSE)  &&  (EndOfWord == FALSE)   ) ;

}

void PrintWord (char *Word)
{
	FILE *FilePointer ;

	long int Random = random (20000) , Count = 0 ;

	FilePointer = fopen ("words.txt" , "r") ;

	clrscr () ;

	if (FilePointer == NULL)
	{
		printf ("Cannot open the file 'words.txt'."
			"\nPlease copy it into the directory.") ;
		ExitTrainUserInputWord = TRUE ;
		ExitTrainProcess = TRUE ;
	}
	else
	{
		fseek (FilePointer , 16 * Random , SEEK_SET) ;

		while (	  (Word[Count] = fgetc(FilePointer))  !=  ' '
			&&   (Word[Count++]   !=   '\n')	)
		{}

		gotoxy (35 , 12) ;
		for (Count = 0 ; Count < 20 ; Count++)
		{
			printf ( "%c" , Word[Count] ) ;
		}

		gotoxy (1 , 25) ;
		printf ("Press any key to start!") ;
		getch () ;	//wait for the user to press any key

		delline () ;	//delete all the content of the current line

		gotoxy (35 , 13) ;

		EndOfWord = FALSE ;

		fclose (FilePointer) ;
	}
}

void TrainUserInputWord (char *Word , int *CorrectInputCount
				    , int *InputCount)
{
	char InputLetter ;

	static Count = 0 ;

	int x = wherex () , y = wherey () ;

	gotoxy (27 , 19) ;
		printf ("Time used     :   ") ;
	gotoxy (27 , 20) ;
		printf ("Accuracy      :   ") ;
	gotoxy (27 , 21) ;
		printf ("Speed         :   ") ;
	gotoxy (27 , 22) ;
		printf ("Wrong letters :   ") ;
	gotoxy (27 , 23) ;
		printf ("Typed letters :   ") ;
	gotoxy (x , y) ;

while ( !kbhit() )
{
	if ( *InputCount > 0 )
	{
		double Speed ;

		float Accuracy = (float) *CorrectInputCount * 100 / *InputCount ;

		int WrongInput = *InputCount - *CorrectInputCount ;

		TimeStop = clock () ;
		TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK ;
		Speed = *CorrectInputCount / 5 / (TimeUsed / 60) ;
		TimeStart = clock () ;
		gotoxy (45 , 19) ;
			printf ("%10.2f seconds" , TimeUsed) ;
		gotoxy (45 , 20) ;
			printf ("%10.2f %%" , Accuracy) ;
		gotoxy (45 , 21) ;
			printf ("%10.2f wpm" , Speed) ;
		gotoxy (45 , 22) ;
			printf ("%10d letters" , WrongInput) ;
		gotoxy (45 , 23) ;
			printf ("%10d letters" , *InputCount) ;
		gotoxy (x , y) ;
		delay (100) ;
	}
}
	InputLetter = getch () ;

	if (InputLetter == ESC)
	{
		EndTrainWordMode() ;
		Count = 0 ;
	}
	else
	{
		if (Word[Count + 1] == 0)
		{
			EndOfWord = TRUE ;
			Count = 0 ;
		}
		else
		{
			if (InputLetter == Word[Count] )
			{
				TrainOutputWord (CorrectInputCount , InputCount);
				gotoxy (x , y) ;
				printf ("%c" , InputLetter) ;
				Count++ ;
			}
			else
			{
				(*InputCount) ++ ;
			}
		}
	}
}

void EndTrainWordMode ()
{
	ExitTrainUserInputWord = TRUE ;
	ExitTrainProcess = TRUE ;
}

void TrainOutputWord (int *CorrectInputCount , int *InputCount)
{
	(*CorrectInputCount) ++ ;
	(*InputCount) ++ ;
}

void TrainCheckIfTyped (int *CorrectInputCount , int *InputCount)
{
	if (*InputCount)	//if the user has typed some letters
	{
		TrainReport (CorrectInputCount , InputCount) ;
	}
}

void TrainReport (int *CorrectInputCount , int *InputCount)
{
    FILE *uptr;
	double Accuracy = *CorrectInputCount * 100 / *InputCount ;

	double Speed = *CorrectInputCount / 5 / (TimeUsed / 60) ;

	int WrongInput = *InputCount - *CorrectInputCount ;
	char name[100];

	clrscr () ;

	//Display the report
	gotoxy ( 20 , 8 ) ;
	printf ( "Time used       : %10.2f seconds per letter." ,
			 (float) TimeUsed / *CorrectInputCount) ;

	gotoxy ( 20 , 10 ) ;
	printf ( "Character Typed : %10d letters" , *InputCount) ;
	gotoxy ( 20 , 12 ) ;
	printf ( "WrongInput      : %10d letters" , WrongInput) ;
	gotoxy ( 20 , 14 ) ;
	printf ( "Accuracy        : %10.2f %%" , Accuracy) ;
	gotoxy ( 20 , 16 ) ;
	printf ( "Speed           : %10.2f wpm (words per minute)" , Speed) ;
    Accr=Accuracy;
    Wpm=Speed;
	strcpy(name,USERNAME);
    strcat(name,fname);
    uptr=fopen(name,"w");
    fprintf(uptr,"%f\n%f",Accr,Wpm);
    fclose(uptr);
	gotoxy ( 20 , 25 ) ;

	printf ( "Press any key (except ESC) to exit") ; //wait for the user to press

	while ( getch () == ESC ) {}		//any key to exit
}
void LeaderBoard(){
  FILE *ptr;
   struct usercmp t;
    int k=0,i=0,z=0,f=0,m=0,j;
    char temp[50];
    char ch;
	char name[100];
	float acc[50],speed[50];
	float n;
	textcolor(WHITE);	//change the text and background colour
	textbackground(BLUE);
	clrscr () ;
    ptr=fopen("USERNAMES.txt", "r");
    //storing usernames from the file into a string which is declared in a structure
       if(ptr!=NULL){
            while ((ch = fgetc(ptr) )!= EOF)
        {

            if(ch=='\n'){
                p[k].str[i]='\0';
                 k=k+1;
                 i=0;
            }
            else{
                p[k].str[i]=ch;
                i++;
            }
        }
       fclose(ptr);
       }
       else{
        //printf("file not exist!");
       }
       i=0;
       //converting userdata into integer from their file and taking their average
       while(i<=k){
        strcpy(name,p[i].str);
        strcat(name,fname);
        ptr=fopen(name,"r");
       if(ptr!=NULL){
            while ((ch = fgetc(ptr) )!= EOF)
        {
            if(ch=='\n'){
                n=atof(temp);
                acc[f]=n;
                z=0;
               f++;
            }
            else{
                temp[z]=ch;
                z++;
            }
        }
          z=0;
        n=atof(temp);
         speed[m]=n;
         m++;

       fclose(ptr);
       }
       else{
       // printf("file not exist!");
       }
      i++;
    }
    i=0;
    while(i<3){
        p[i].avg=(acc[i]+speed[i])/2;
        i++;
    }
    //sorting them based on user average value
    for (i = 1; i <k; i++)
      for (j = 0; j < k- i; j++) {
         if (p[j].avg>p[j+1].avg) {
            t= p[i];
            p[i]= p[j + 1];
            p[j + 1] = t;
         }
      }
    gotoxy (30 , 9) ;
    m=10;
    //displaying them in descending order
    for( i=0; i<k;i++){
        printf("%d : %s \n",i+1,p[i].str);
        gotoxy (30 , m) ;
        m++;
    }
    gotoxy(30,20);
    printf("press any key to exit\n");
    getch();

}
void Game(){
    int Count ;
	char MenuChoice ;
	FILE *ptr;
	ptr=fopen("c_prog_1.txt","r");
    clrscr () ;
    GAMEMODE=1;
	textcolor(WHITE);	//change the text and background colour
	textbackground(BLUE);
	gotoxy(30,3);
	printf("hi,%s lets start an interesting game!!",USERNAME);
	gotoxy(20,4);
	printf("first select the time,we will give you a task and you should");
	gotoxy(20,5);
	printf("complete it within the selected time");
//Display the menu
	gotoxy (35 , 10) ;
	printf ("1. one min") ;
	gotoxy (35 , 11) ;
	printf ("2. 30 sec") ;
	gotoxy (35 , 12) ;
	printf ("3. 15 sec") ;
	gotoxy (35 , 13) ;
	printf ("4. Quit Now") ;
	gotoxy (35 , 14) ;
	printf ("select your Choice? : ") ;
	gotoxy (30 , 25) ;
	printf ("Press ESC to quit.") ;
	gotoxy (52 , 16) ;
	MenuChoice = getch () ;           //Accept a key value from the user
    GAMECHOICE=MenuChoice;
	switch (MenuChoice)
	{
		case '1' : case '2' :case '3':
            TestMode(ptr);
            GAMEMODE=0;
			break ;
		case '4' :	case ESC :	//if the user press ESC or 3
            break;
	}
}
//It is for Quite confirmation
void QuitConfirm ()
{
	char QuitChoice,name[100];
	clrscr () ;
	gotoxy (30 , 12) ;
	printf ("Really want to quit? (y/n) : ") ;
	//wait for the user to press y or n
	if ((QuitChoice = getch ()) != ESC)
	{
		while ((tolower(QuitChoice)    !=   Y )
				&&   ( tolower(QuitChoice) != N)    )
		{
			clrscr () ;
			gotoxy (25 , 12) ;
			printf ("Please press 'y' or 'n' only!") ;
			gotoxy (25 , 14) ;
			printf ("Really want to quit? (y/n) : ") ;
			QuitChoice = getch () ;
		}
	}

	printf ("%c" , QuitChoice) ;

	if (tolower(QuitChoice) == Y)      //if the user pressed y ,
	{				   //then exit the program
		EndBody () ;
	}
}

void EndBody()
{
	ExitProgram = TRUE ;
}

void EndProgram ()
{

}
