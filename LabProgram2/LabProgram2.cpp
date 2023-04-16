/*
Write a Program to read and write Students Objects with Fixed length records and the fields delimited by 
"|". Implement pack(),unpack(),modify() and search() methods.
*/

#include <conio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstring>

using namespace std;

class Student
{
    public:char name[25],usn[15],branch[15],buffer[100];
}temp,s,s1[100];

char extra[45];
int i,no = 0,mode = 1;

void pack()
{
    fstream app;
    if(mode == 0)
        app.open("st1.txt",ios::app);
    else
        app.open("st1.txt",ios::out);
    if(!app)
    {
        cout<<"Can't open the file in output mode.";
        _getch();
        exit(0);
    }

    strcpy(s.buffer,s.name);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.usn);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.branch);

    int count = strlen(s.buffer);

    for(int k = 0; k <45 - count; k++)
    {
        strcat(s.buffer,"|");
        strcat(s.buffer,"\n");
        app<<s.buffer;
        app.close();
    }
}

void unpack()
{
    fstream in;
    in.open("st1.txt",ios::in);
    i = 0; no = 0;
    if(!in)
    {
        cout<<"Can't Open file in input mode";
        _getch();
        exit(0);
    }
    while(!in.eof())
    {
        in.getline(s1[i].name,15,'|');
        in.getline(s1[i].usn,15,'|');
        in.getline(s1[i].branch,15,'|');
        in.getline(extra,45,'\n');
        no++;
        i++;
    }
    in.close();
}

void write()
{
    cout<<"\n Enter the student name: ";
    cin>>s.name;
    cout<<"\n Enter the student usn: ";
    cin>>s.usn;
    cout<<"\n Enter the student branch: ";
    cin>>s.branch;
    
    pack();
    mode = 0;
}

void display()
{
    cout<<"Name\t\tUsn\t\tBranch\n\n";
    unpack();
    for(int i=0; i<no; i++)
    {
        cout<<"\n\n"<<s1[i].name<<"\t\t"<<s1[i].usn<<"\t\t"<<s1[i].branch;
        _getch();
    }
}

void search()
{
    char usn[15],extra[15];
    cout<<"Enter the usn to search = ";
    cin>>usn;

    unpack();

    for(int i=0;i<no; i++)
    {
        if(strcmp(s1[i].usn,usn)==0)
        {
            cout<<"\n Record Found";
            cout<<"\n"<<s1[i].name<<"\t"<<s1[i].usn<<"\t"<<s1[i].branch;
            _getch();
            return;
        }
    }

    cout<< "Record Not Found";
    _getch();
    return;
}

void modify()
{
    char usn[15];int j;
    cout<<"Enter the usn to search \n";
    cin >> usn;

    unpack();
    no--;

    for(int j=0; j<no; j++)
    {
        if(strcmp(usn,s1[j].usn)==0)
        {
            cout<<"The Old Values of the Record are with usn : "<< usn <<" are";
            cout<<"\nname = "<<s1[j].name;
            cout<<"\nusn = "<<s1[j].usn;
            cout<<"\nbranch = "<<s1[j].branch;

            cout<<"Enter the new values\n";
            cout<<"\nname = ";
            cin>>s1[j].name;
            cout<<"\nusn = ";
            cin>>s1[j].usn;
            cout<<"\nbranch = ";
            cin>>s1[j].branch;
            break;
        }
    }

    if(j == no)
    {
        cout<<"The Record with usn is not present";
        _getch();
        return;
    }
    mode = 1;

    for(j=0; j<no; j++)
    {
        strcpy(s.name,s1[j].name);
        strcpy(s.usn,s1[j].usn);
        strcpy(s.branch,s1[j].branch);
        pack();
        mode = 0;
    }
    cout<<"Record Modified\n";
}

int main()
{
    int choice;
    for(;;)
    {
        cout<<"\n0:Exit";
        cout<<"\n1:Write";
        cout<<"\n2:Display";
        cout<<"\n3:Modify";
        cout<<"\n4:Search";
        cout<<"\nEnter the Choice\n";
        cin>>choice;

        switch(choice)
        {
            case 1: write();
                    break;
            case 2: display();
                    break;
            case 3: modify();
                    break;
            case 4: search();
                    break;
            case 0: exit(0);
                    break;
            default: cout<<"\n Invalid Input"; 
                    break;
        }
    }
}

/*
OUTPUT:

0:Exit
1:Write
2:Display       
3:Modify        
4:Search        
Enter the Choice
2
Name            Usn             Branch     



Adarsh          1BG20IS002              ISE

Abhay           1BG20IS001              CSE


0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
3
Enter the usn to search 
1BG20IS002
The Old Values of the Record are with usn : 1BG20IS002 are
name = Adarsh
usn = 1BG20IS002
branch = ISEEnter the new values

name = AdarshV

usn = 1BG20IS002

branch = CSE
Record Modified

0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
1

 Enter the student name: Aditi

 Enter the student usn: 1BG20IS003

 Enter the student branch: ISE

0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
4
Enter the usn to search = 1BG20IS001

 Record Found
Abhay   1BG20IS001      CSE
0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
4
Enter the usn to search = 1BG20IS002

 Record Found
AdarshV 1BG20IS002      CSE
0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
4
Enter the usn to search = 1BG20IS003

 Record Found
Aditi   1BG20IS003      ISE
0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
4
Enter the usn to search = 1BG20IS006
Record Not Found
0:Exit
1:Write
2:Display
3:Modify
4:Search
Enter the Choice
0

*/