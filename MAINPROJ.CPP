//project on computer quiz
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
void intro();
void playuser();
void displayu();
void mainmenu();
void pswdcheck();
void pswdchange();
void addq();
void editq();
void delq();
void showq();
void countq(int level=0);
void admin();
void play();
char name[42]={"hitesh"};
int r3=0;
class quiz  //class declaration for questions
{
 public:
	int ans;
	char q[350],opt[4][50];
	quiz()
	{
	 ans=1;
	}
	void readq()
	{
	 cout<<"\n ENTER QUESTION :";
	 gets(q);
	 cout<<"\n ENTER OPTION 1 :";
	 gets(opt[0]);
	 cout<<"\n ENTER OPTION 2 :";
	 gets(opt[1]);
	 cout<<"\n ENTER OPTION 3 :";
	 gets(opt[2]);
	 cout<<"\n ENTER OPTION 4 :";
	 gets(opt[3]);
	 cout<<"\n ENTER CORRECT ANSWER :";
	 cin>>ans;
	 cout<<"\n QUESTION ADDED ...";
	}
	void show();
	int getans()
	{
	 return ans;
	}
	void playquiz()
	{
	 cout<<q<<endl;
	 cout<<"1. "<<opt[0]<<endl;
	 cout<<"2. "<<opt[1]<<endl;
	 cout<<"3. "<<opt[2]<<endl;
	 cout<<"4. "<<opt[3]<<endl;
	 cout<<"\n ENTER CORRECT ANSWER OPTION(1 TO 4) OR 5 TO PASS";
	}
};
void quiz::show()
{
 if(strlen(q)<80)
  cout<<q;
 else
 {
  for(int i=0;i<68;i++)
   cout<<q[i];
  cout<<"...";
 }
 cout<<"?"<<endl;
 cout<<"CORRECT ANSWER IS:"<<opt[ans-1];
}
class user // class declaration for user details
{
	 char name[45],sex;
	 int age;
 public: int score,pass;
	 float perc;
	 user()
	 {
	  score=0;
	  pass=0;
	  perc=0.0;
	 }
	 void getuser()
	 {
	  clrscr();
	  cout<<"\n ENTER USERNAME:";
	  gets(name);
	  cout<<"\n ENTER AGE :";
	  cin>>age;
	  cout<<"\n ENTER SEX(M/F/O)";
	  cin>>sex;
	  if(sex=='m')
	   sex='M';
	  else if(sex=='f')
	   sex='F';
	  else if(sex=='o')
	   sex='O';
	 }
	 void showuser()
	 {
	  cout<<"\n PLAYERS DETAILS:.............."<<endl;
	  cout<<"\n USERNAME :"<<name;
	  cout<<"\n AGE :"<<age;
	  cout<<"\n SEX :"<<sex;
	  cout<<"\n SCORE :"<<score;
	  cout<<"\n QUESTIONS PASSED :"<<pass;
	  cout<<"\n WIN PERCENTAGE :"<<perc<<"%";
	 }
	 char *retname()
	 {
	  return name;
	 }
	 int retage()
	 {
	  return age;
	 }
	 char retsex()
	 {
	 return sex;
	 }
	 int retscore()
	 {
	  return score;
	 }
}u,u1;
void main()
{
 clrscr();
 intro();
 mainmenu();
}
void mainmenu()//1st menu after opening of game
{
 clrscr();
 int ch;
 do
 {
  gotoxy(10,5);
  cout<<"\n MENU:"<<endl;
  cout<<"\n 1. ADMINISTRATOR"<<endl;
  cout<<"\n 2. PLAY"<<endl;
  cout<<"\n 0. QUIT"<<endl;
  cout<<"\n ENTER YOUR CHOICE :"<<endl;
  cin>>ch;
  switch(ch)
  {
   case 1:admin();
	  break;
   case 2:play();
	  clrscr();
	  break;
   case 0:exit(0);
   default:cout<<"\n INVALID CHOICE "<<endl;
	   getch();
  }
 }while(ch>=0&&ch<=2);
}
void intro() //function to display front page
{
 cout<<"\n_________________________________________________________________________"<<endl;
 cout<<"\n|\t\t\t  _  _   _  ___  __  __ ___      \t\t|";
 cout<<"\n|\t\t\t |_||_| | |  |  |_  |    |       \t\t|";
 cout<<"\n|\t\t\t |  |\\  |_| _|  |__ |__  |       \t\t|";
 cout<<"\n|\t\t\t             _	                   \t\t|";
 cout<<"\n|\t\t\t            | | |\\ |             \t\t|";
 cout<<"\n|\t\t\t            |_| | \\|             \t\t|";
 cout<<"\n|\t\t\t   __  __        __      ___  __  __  \t\t|";
 cout<<"\n|\t\t\t  |   |  | |\\/| |__||  |  |  |_  |__|\t\t|";
 cout<<"\n|\t\t\t  |__ |__| |  | |   |__|  |  |__ |\\  \t\t|";
 cout<<"\n|\t\t\t          __          ___             \t\t|";
 cout<<"\n|\t\t\t         |  |  |  | |   /             \t\t|";
 cout<<"\n|\t\t\t         |_\\|  |__| | /__            \t\t|";
 cout<<"\n|\t\t\t             \\                       \t\t|";
 cout<<"\n|\t                         \t\t\t \t\t|";
 cout<<"\n|\t                         \t\t\t \t\t|";
 cout<<"\n|\t                         \t\t\t \t\t|";
 cout<<"\n|\t   \t\t\t\t\t DESIGNED BY :-       \t|";
 cout<<"\n|\t   \t\t\t\t\t      HITESH AGARWAL  \t|";
 cout<<"\n_________________________________________________________________________";
 getch();
}
void pswdcheck()  //function to check administrator password
{
 char check[40];
 clrscr();
 cout<<"\n ______________PASSWORD AUTHENTICATION_______________";
 cout<<"\n ENTER CURRENT PASSWORD:"<<endl;
 gets(check);
 fstream file("pswd.dat",ios::in|ios::binary);
 file.read((char*)&name,42);
 file.close();
 if(strcmp(check,name)!=0)
 {
  cout<<"WRONG PASSWORD TRY AGAIN....";
  cout<<"press any key..";
  getch();
  clrscr();
  mainmenu();
 }
}
void pswdchange() // function to change administraator password
{
 char check[42],recheck[42];
 pswdcheck();
 pswdchange:
 cout<<"\n ENTER NEW PASSWORD"<<endl;
 gets(check);
 cout<<"\n CONFIRM NEW PASSWORD"<<endl;
 gets(recheck);
 if(strcmp(check,recheck)==0)
 {
  cout<<"\n PASSWORD CHANGED.......";
  fstream file("pswd.dat",ios::out|ios::binary);
  file.write((char*)&recheck,42);
  file.close();
  getch();
  clrscr();
 }
 else
 {
  cout<<"\n SORRY PASSWORDS DONOT MATCH!!!! TRY AGAIN";
  goto pswdchange;
 }
}
void addq()  // function to add question
{
 clrscr();
 quiz quizq;
 int level=0,i=1;
 char ch='y';
 cout<<"\n ENTER THE LEVEL YOU WANT TO ADD QUESTION FOR(LEVELS ARE 1 TO 13)";
 cin>>level;
 char qname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>8)
 {
  qname[5]='1';
  if(level==10)
   qname[6]='0';
  if(level==11)
   qname[6]='1';
  if(level==12)
   qname[6]='2';
  if(level==13)
   qname[6]='3';
 }
 fstream file(qname,ios::out|ios::binary|ios::app);
 do
 {
  cout<<"\n Q NO"<<i<<":";
  quizq.readq();
  file.write((char*)&quizq,sizeof(quizq));
  cout<<"\n DO YOU WANT TO ADD MORE QUESTIONS(y/n) :"<<endl;
  cin>>ch;
  i++;
 }while(ch=='y'||ch=='Y');
 file.close();
}
void countq(int level)   // function to count question
{
 r3=0;
 quiz q1;
 char qname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>8)
 {
  qname[5]='1';
  if(level==10)
   qname[6]='0';
  if(level==11)
   qname[6]='1';
  if(level==12)
   qname[6]='2';
  if(level==13)
   qname[6]='3';
 }
 fstream file(qname,ios::in|ios::binary);
 while(file.read((char*)&q1,sizeof(q1)))
  r3++;
 file.close();
}
void editq() //function to edit question
{
 editques:
 clrscr();
 quiz q2;
 int level=0,qno=0;
 char ch='y';
 cout<<"\n ENTER THE LEVEL YOU WANT TO EDIT QUESTION FOR(LEVELS ARE 1 TO 13)";
 cin>>level;
 char qname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>8)
 {
  qname[5]='1';
  if(level==10)
   qname[6]='0';
  if(level==11)
   qname[6]='1';
  if(level==12)
   qname[6]='2';
  if(level==13)
   qname[6]='3';
 }
 fstream file(qname,ios::in|ios::binary|ios::app);
 cout<<"\n ENTER QUESTION NUMBER TO BE EDITED";
 cin>>qno;
 countq(level);
 if(qno<0||qno>r3)
 {
  cout<<"\n SORRY NO RECORD FOUND!!\n PRESS ANY KEY TO CONTINUE";
  getch();
  goto editques;
 }
 int r1=0;
 fstream file1("temp.dat",ios::out|ios::binary);
 while(file.read((char*)&q2,sizeof(q2)))
 {
  r1++;
  if(r1==qno)
  {
   q2.show();
   cout<<"\n IS THIS THE QUESTION YOU WANT TO EDIT(Y/N):"<<endl;
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
    cout<<"\n ENTER NEW DETAILS OF QUESTION"<<endl;
    q2.readq();
    file1.write((char*)&q2,sizeof(q2));
   }
   else
   {
    cout<<"\n QUESTION NOT EDITED....";
    file.close();
    file1.close();
    goto editques;
   }
  }
  else
   file1.write((char*)&q2,sizeof(q2));
 }
 file.close();
 file1.close();
 remove(qname);
 rename("temp.dat",qname);
}
void delq()//function to delete question
{
 delques:
 clrscr();
 quiz q2;
 int level=0,qno=0;
 char ch='y';
 cout<<"\n ENTER THE LEVEL YOU WANT TO DELETE QUESTION FOR(LEVELS ARE 1 TO 13)";
 cin>>level;
 char qname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>8)
 {
  qname[5]='1';
  if(level==10)
   qname[6]='0';
  if(level==11)
   qname[6]='1';
  if(level==12)
   qname[6]='2';
  if(level==13)
   qname[6]='3';
 }
 fstream file(qname,ios::in|ios::binary|ios::app);
 cout<<"\n ENTER QUESTION NUMBER TO BE DELETED";
 cin>>qno;
 countq(level);
 if(qno<0||qno>r3)
 {
  cout<<"\n SORRY NO RECORD FOUND!!\n PRESS ANY KEY TO CONTINUE";
  getch();
  goto delques;
 }
 int r1=0;
 fstream file1("temp.dat",ios::out|ios::binary);
 while(file.read((char*)&q2,sizeof(q2)))
 {
  r1++;
  if(r1==qno)
  {
   q2.show();
   cout<<"\n IS THIS THE QUESTION YOU WANT TO DELETE(Y/N):"<<endl;
   cin>>ch;
   if(ch=='n'||ch=='N')
   {
    file1.write((char*)&q2,sizeof(q2));
    cout<<"\n QUESTION NOT DELETED....\n PRESS ANY KEY TO CONTINUE...";
    getch();
    file.close();
    file1.close();
    goto delques;
   }
   else
   {
    cout<<"\n QUESTION DELETED SUCCESFULLY \n PRESS ANY KEY TO CONTINUE";
    getch();
   }
  }
  else
   file1.write((char*)&q2,sizeof(q2));
 }
 file.close();
 file1.close();
 remove(qname);
 rename("temp.dat",qname);
}
void showq() // function to show questions
{
 showques:
 clrscr();
 quiz obj1;
 int level=0;
 cout<<"\n ENTER THE LEVEL YOU WANT TO SHOW QUESTION FOR(LEVELS ARE 1 TO 13)";
 cin>>level;
 int read=0;
 if(level==0)
  level++;
 char fname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>=9)
 {
  fname[5]='1';
  if(level==10)
   fname[6]='0';
  if(level==11)
   fname[6]='1';
  if(level==12)
   fname[6]='2';
  if(level==13)
   fname[6]='3';
 }
 ifstream file(fname,ios::binary|ios::in);
 long filesize=0;
 int nofrecord=0;
 if(file)
 {
  file.seekg(0,ios::end);
  filesize=file.tellg();
  nofrecord=filesize/sizeof(quiz);
  file.seekg(0,ios::beg);
 }
 else
 {
  cout<<"FILE NOT FOUND. ERROR!!";
  getch();
  goto showques;
 }
 cout<<"_________________QUESTIONS ARE:_________________________";
 while(file && read<nofrecord)
 {
  cout<<endl;
  file.read((char*)&obj1,sizeof(obj1));
  read++;
  cout<<read<<">";
  obj1.show();
 }
 file.close();
}
void viewusers()// function to view all users present
{
 clrscr();
 int ch;
 cout<<"\n __________ALL USER'S RECORDS ARE:____________________________";
 fstream file("user.dat",ios::in|ios::binary);
 if(!file)
 {
  cout<<"\n NO USERS FOUND...";
 }
 while(file.read((char*)&u,sizeof(u)))
 {
  u.showuser();
  cout<<"\n PRESS ANY KEY TO CONTINUE....(0 to exit)";
  ch=getch();
  if(ch=='0')
   break;
 }
 file.close();
}
void searchuser()// function to search a particular user
{
 int ch,age,r2;
 char check[50],name[50];
 int flag=0;
 clrscr();
 cout<<"\n USER DETAILS CAN BE SEARCHED BY";
 cout<<"\n 1. USERNAME";
 cout<<"\n 2. AGE";
 cout<<"\n ENTER YOUR CHOICE:";
 cin>>ch;
 fstream file("user.dat",ios::in|ios::binary);
 switch(ch)
 {
  case 1:cout<<"\n ENTER USERNAME TO BE SEARCHED:"<<endl;
	 gets(check);
	 flag=0;
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  strcpy(name,u.retname());
	  if(strcmp(name,check)==0)
	  {
	   flag=1;
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE...";
	   getch();
	  }
	 }
	 if(flag==0)
	 {
	  cout<<"\n USERNAME DOESNOT EXIST!!!\n PRESS ANY KEY TO CONTINUE";
	  getch();
	 }
	 break;
  case 2:cout<<"\n ENTER YOUR AGE :"<<endl;
	 cin>>age;
	 flag=0;
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  r2=u.retage();
	  if(r2==age)
	  {
	   flag=1;
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE...";
	   getch();
	  }
	 }
	 if(flag==0)
	 {
	  cout<<"\n USERNAME DOESNOT EXIST!!!\n PRESS ANY KEY TO CONTINUE";
	  getch();
	 }
	 break;
  default:cout<<"\n INVALID CHOICE!!!!!";
 }
 file.close();
}
void edituser()// function to edit details of a user
{
 char check[50],name[50];
 int flag=0;
 clrscr();
 cout<<"\n ENTER THE USERNAME WHOSE RECORD YOU WANT TO SEARCH :"<<endl;
 gets(check);
 fstream file("user.dat",ios::in|ios::binary);
 fstream file1("temp.dat",ios::out|ios::binary);
 flag=0;
 while(file.read((char*)&u,sizeof(u)))
 {
  strcpy(name,u.retname());
  if(strcmp(check,name)==0)
  {
   flag=1;
   cout<<"\n ENTER NEW DETAILS OF USER "<<name<<endl;
   u1.getuser();
   u1.score=u.score;
   u1.pass=u.pass;
   u1.perc=u.perc;
   cout<<"\n USER DETAILS ARE EDITED \n PRESS ANY KEY TO CONTINUE";
   file1.write((char*)&u1,sizeof(u1));
   getch();
  }
  else
   file1.write((char*)&u,sizeof(u));
 }
 if(flag==0)
 {
  cout<<"\n USERNAME DOESNOT EXIST!!\n PRESS ANY KEY TO CONTINUE";
  getch();
 }
 file.close();
 file1.close();
 remove("user.dat");
 rename("temp.dat","user.dat");
}
void deluser()// function to delete a user
{
 char check[50],name[50];
 int flag=0;
 clrscr();
 cout<<"\n ENTER USERNAME OF WHOSE RECORD IS TO BE DELETED :"<<endl;
 gets(check);
 fstream file("user.dat",ios::in|ios::binary);
 fstream file1("temp.dat",ios::out|ios::binary);
 flag=0;
 while(file.read((char*)&u,sizeof(u)))
 {
  strcpy(name,u.retname());
  if(strcmp(check,name)==0)
   flag=1;
  else
   file1.write((char*)&u,sizeof(u));
 }
 if(flag==0)
 {
  cout<<"\n USERNAME DOES NOT FOUND !!! \n PRESS ANY KEY TO CONTINUE..";
  getch();
 }
 file.close();
 file1.close();
 remove("user.dat");
 rename("temp.dat","user.dat");
}
void highscore()// function to calculate the highest score till now
{
 int ch=0,r1,r2;
 float p1,p2;
 clrscr();
 fstream file("user.dat",ios::in|ios::binary);
 file.read((char*)&u,sizeof(u));
 cout<<"\n __________________DISPLAY HIGHSCORE ACCORDING TO_______________";
 cout<<"\n 1. ACTUAL SCORE";
 cout<<"\n 2. ACCURACY PERCENTAGE";
 cout<<"\n ENTER YOUR CHOICE :"<<endl;
 cin>>ch;
 switch(ch)
 {
  case 1:r1=u.score;
	 while(file.read((char*)&u1,sizeof(u1)))
	 {
	  r2=u1.score;
	  if(r2>r1)
	   r1=r2;
	 }
	 cout<<"\n HIGHEST SCORE IS :"<<r1;
	 cout<<"\n DEATILS OF USER WITH HIGHSCORE IS :"<<endl;
	 file.close();
	 file.open("user.dat",ios::in|ios::binary);
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  if(u.score==r1)
	  {
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE ";
	   getch();
	  }
	 }
	 file.close();
	 break;
  case 2:p1=u.perc;
	 while(file.read((char*)&u1,sizeof(u1)))
	 {
	  p2=u1.perc;
	  if(p2>p1)
	   p1=p2;
	 }
	 cout<<"\n HIGHEST PERCENTAGE IS :"<<p1;
	 cout<<"\n DEATILS OF USER WITH HIGHPERCENTAGE IS :"<<endl;
	 file.close();
	 file.open("user.dat",ios::in|ios::binary);
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  if(u.perc==p1)
	  {
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE ";
	   getch();
	  }
	 }
	 file.close();
	 break;
  default:cout<<"\n WRONG CHOICE!!";
 }
}
void admin()     //administrator menu
{
 int ch;
 clrscr();
 pswdcheck();
 clrscr();
 gotoxy(20,2);
 do
 {
  clrscr();
  cout<<"\n ADMINISTRATOR MENU:";
  cout<<"\n _________ADMINISTRATION OPTION____________";
  cout<<"\n 11. CHANGE THE PASSWORD";
  cout<<"\n _________QUESTION DATABASE MODE___________";
  cout<<"\n 1. ADD QUESTIONS TO DATABASE";
  cout<<"\n 2. EDIT A QUESTIONS OF DATABASE";
  cout<<"\n 3. DELETE QUESTIONS OF DATABASE";
  cout<<"\n 4. NO OF QUESTIONS PRESENT IN DATABASE";
  cout<<"\n 5. SHOW QUESTIONS PRESENT IN DATABASE";
  cout<<"\n _________USER DATABASE MODE______________";
  cout<<"\n 6. VIEW USERS PRESENT";
  cout<<"\n 7. SEARCH USER RECORDS";
  cout<<"\n 8. EDIT USER RECORDS";
  cout<<"\n 9. DELETE USER'S RECORDS";
  cout<<"\n 10. VIEW HIGHEST SCORE";
  cout<<"\n 0.EXIT FROM ADMIN MENU";
  cout<<"\n ENTER YOUR CHOICE :"<<endl;
  cin>>ch;
  switch(ch)
  {
   case 11:pswdchange();
	    break;
   case 1:addq();
	  getch();
	  break;
   case 2:editq();
	  getch();
	  break;
   case 3:delq();
	  getch();
	  break;
   case 4:int level;
	  clrscr();
	  cout<<"\n ENTER THE LEVEL YOU WANT TO COUNT QUESTION FOR(LEVELS ARE 1 TO 13)";
	  cin>>level;
	  countq(level);
	  cout<<"\n NO OF QUESTIONS PRESENT IN "<<level<<" FILE IS :"<<r3;
	  getch();
	  break;
   case 5:showq();
	  getch();
	  break;
   case 6:viewusers();
	  getch();
	  break;
   case 7:searchuser();
	  getch();
	  break;
   case 8:edituser();
	  getch();
	  break;
   case 9:deluser();
	  getch();
	  break;
   case 10:highscore();
	   getch();
	   break;
   case 0:mainmenu();
   default:cout<<"\n INVALID CHOICE!!!";
  }
 }while(ch>=0 && ch<=11);
}
void play()//user menu
{
 clrscr();
 int ch;
 do
 {
  clrscr();
  cout<<"\n MENU:";
  cout<<"\n 1. PLAY";
  cout<<"\n 2. DISPLAY SCORE";
  cout<<"\n 3. EXIT";
  cout<<"\n ENTER YOUR CHOICE";
  cin>>ch;
  switch(ch)
  {
   case 1:puser:
	  u.getuser();
	  fstream file("user.dat",ios::in|ios::binary);
	  while(file.read((char*)&u1,sizeof(u1)))
	  {
	   if(strcmp(u.retname(),u1.retname())==0)
	   {
	    cout<<"\n USER NAME ALREADY EXIST ENTER AGAIN";
	    getch();
	    goto puser;
	   }
	  }
	  playuser();
	  break;
   case 2:displayu();
	  break;
   case 3:mainmenu();
   default:cout<<"\n INVALID CHOICE!!";
  }
 }while(ch>=1&&ch<=3);
 getch();
}
void displayu()//function to display a users score
{
 int ch,age,r2;
 char check[50],name[50];
 int flag=0;
 clrscr();
 cout<<"\n USER DETAILS CAN BE SEARCHED BY";
 cout<<"\n 1. USERNAME";
 cout<<"\n 2. AGE";
 cout<<"\n ENTER YOUR CHOICE:";
 cin>>ch;
 fstream file("user.dat",ios::in|ios::binary);
 switch(ch)
 {
  case 1:cout<<"\n ENTER USERNAME TO BE SEARCHED:"<<endl;
	 gets(check);
	 flag=0;
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  strcpy(name,u.retname());
	  if(strcmp(name,check)==0)
	  {
	   flag=1;
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE...";
	   getch();
	  }
	 }
	 if(flag==0)
	 {
	  cout<<"\n USERNAME DOESNOT EXIST!!!\n PRESS ANY KEY TO CONTINUE";
	  getch();
	 }
	 break;
  case 2:cout<<"\n ENTER YOUR AGE :"<<endl;
	 cin>>age;
	 flag=0;
	 while(file.read((char*)&u,sizeof(u)))
	 {
	  r2=u.retage();
	  if(r2==age)
	  {
	   flag=1;
	   u.showuser();
	   cout<<"\n PRESS ANY KEY TO CONTINUE...";
	   getch();
	  }
	 }
	 if(flag==0)
	 {
	  cout<<"\n USERNAME DOESNOT EXIST!!!\n PRESS ANY KEY TO CONTINUE";
	  getch();
	 }
	 break;
  default:cout<<"\n INVALID CHOICE!!!!!";
 }
 file.close();
}
void playuser()//function to play quiz
{
 clrscr();
 cout<<"\n _________________USER MODE___________________________";
 cout<<"\n RULES.....";
 cout<<"\n 1. EACH CORRECT ANSWER = +10PTS";
 cout<<"\n 2. EACH WRONG ANSWER = -5PTS";
 cout<<"\n 3. FOR PASS NO PTS";
 cout<<"\n GET READY TO PLAY THE QUIZ..... \n PRESS ANY KEY TO CONTINUE..";
 getch();
 int r1=0,r2=0,level=0;
 float ch=0.0,r4=0.0;
 int cch;
 quiz q;
 cout<<"\n ENTER THE LEVEL YOU WANT TO PLAY FOR(LEVELS ARE 1 TO 13)";
 cin>>level;
 char qname[20]={'l','e','v','e','l',' ',level+48,'-','q','u','i','z','\0'};
 if(level>8)
 {
  qname[5]='1';
  if(level==10)
   qname[6]='0';
  if(level==11)
   qname[6]='1';
  if(level==12)
   qname[6]='2';
  if(level==13)
   qname[6]='3';
 }
 if(!ifstream(qname))
 {
  cout<<"\n FILE DOESNOT EXIST!!!";
  getch();
  play();
 }
 fstream file(qname,ios::in|ios::binary|ios::app);
 while(file.read((char*)&q,sizeof(q)))
 {
  r4++;
  clrscr();
  cout<<"\n QUESTION NO :"<<r3;
  q.playquiz();
  cin>>r1;
  r2=q.getans();
  if(r1==r2)
  {
   cout<<"WELL DONE ... YOU GOT THE CORRECT ANSWER......";
   u.score+=10;
   ch++;
  }
  else if(r1==5)
  {
   u.pass++;
  }
  else
  {
   u.score-=5;
   cout<<"\n OPPS WRONG ANSWER!!CORRESCT ANSWER IS"<<r2;
  }
  cout<<"\n PRESS ANY KEY TO CONTINUE(OR '0' TO FINISH QUIZ)....";
  cch=getch();
  if(cch==0)
   break;
 }
 u.perc=((ch*100)/r4);
 cout<<"\n YOU SCORED :"<<u.score;
 cout<<"\n NO OF PASSES ARE :"<<u.pass;
 cout<<"\n ATTEMPTED ARE :"<<r4;
 file.close();
 fstream file1("user.dat",ios::app|ios::out|ios::in|ios::binary);
 file1.write((char*)&u,sizeof(u));
 file1.close();
 cout<<"\n PRESS ANY KEY TO CONTINUE";
 getch();
}