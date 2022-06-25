#include<bits/stdc++.h>
#include<windows.h>
#include<string>
using namespace std;
void start();
char menu();


class node
{
    public:
    std::string name;
    string no;
    node *next;

};
node*head,*tail;

void push(string tname,string tno){
    node*new_node=new node();
    new_node->name=tname;
    new_node->no=tno;
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->next=new_node;

        tail=new_node;

    }

}


int main()
{
	start();
    char check='0';
    int Total_contacts=0;
    string tname;
	string tno;
    node*temp;
    do
    {
    	check=menu();
    	system("CLS");
        //Add contacts
	    if(check=='1')
        {
        cout<<"\t\t\t\t\t\t Name :";
		cin.ignore(1,'/n');		
        getline(cin,tname);
        cout<<"\t\t\t\t\t\t Phone no :";
        cin>>tno;

        push(tname,tno);
        Total_contacts++;
        }
        //Display contacts
        else if(check=='2')
        {
            int check2=0;

            temp=head;
            while(temp!=NULL)
            {

                cout<<"\t\t\t\t\t\t Name :"<<temp->name<< "          Phone :"<<temp->no<<endl;
                temp=temp->next;
                check2++;
            }
            if(check2==0)
            {
                cout<<"\t\t\t\t\t\t No Contacts to display";
            }
        }
        //Search by Number
else if(check=='3')
{
string temp_name;

//----------------------------------------------------------
cout<<"\t\t\t\t\tNumber : ";
cin>>temp_name;
int check2=0;
temp=head;
while(temp!=NULL)
{
	if(temp_name==temp->no)
	{
		cout<<"\t\t\t\t\tNumber is Found\n";
		cout<<"\t\t\t\t\tName : "<<temp->name<<"    Phone : "<<temp->no<<endl;
	        check2++;
	}
	temp=temp->next;
}
if(check2==0)cout<<"\t\t\t\t\tNumber is NOT Found\n";
}
 //Search by Name
else if(check=='4')
{
	string temp_name;
	cout<<"\t\t\t\t\tName : ";
	cin>>temp_name;
	int check2=0;
	temp=head;
	while(temp!=NULL)
	{
		if(temp_name==temp->name)
		{
			cout<<"\t\t\t\t\tName is Found\n";
			cout<<"\t\t\t\t\tName : "<<temp->name<<"    Phone : "<<temp->no<<endl;
			check2++;
		}
		temp=temp->next;
	}
	if(check2==0)
	{
		cout<<"\t\t\t\t\t This name is not found in your contact list\n";
	}
}
//Update
else if(check=='5')
{
	string temp1,temp2,temp3;
	cout<<"\t\t\t\t\tName : ";
	cin>>temp1;
	int check2=0;
	temp=head;
	while(temp!=NULL)
	{
		if(temp1==temp->name)
		{
			cout<<"\t\t\t\t\tNew Name : ";
			cin>>temp2;
			cout<<"\t\t\t\t\tNew Number : ";
			cin>>temp3;
			temp->name=temp2;
			temp->no=temp3;
			check2++;
			cout<<"\t\t\t\t\tUpdated Successfully ";
		}
		temp=temp->next;
		}
	if(check2==0)
	{
		cout<<"\t\t\t\t\t This name is not found in your contact list\n";
	}
}
//Delete
else if(check=='6')
{
	string temp_name;
	cout<<"\t\t\t\t\tFor Delete Enter Name : ";
	cin>>temp_name;
	int check2=0;
	temp=head;
	node*prev;
	while(temp!=NULL)
	{
		if(temp_name==temp->name)
		{
			cout<<"\t\t\t\t\tDeleted Successfully\n";
			cout<<"\t\t\t\t\tName : "<<temp->name<<"    Phone : "<<temp->no<<endl;

            if(temp==head)head=head->next;
            else
			prev->next=temp->next;


			check2++;
			Total_contacts--;
			break;
		}
		prev=temp;
    temp=temp->next;
	}
	if(check2==0)
	{
		cout<<"\t\t\t\t\t This name is not found in your contact list\n";
	}
}
//delete All
else if(check=='7')
{
			cout<<"\t\t\t\t\tAll Deleted Successfully\n";
	        head=NULL;
	        tail=NULL;

			Total_contacts=0;
}
//Display number of contacts
else if(check=='8')
{
	cout<<"\t\t\t\t\tTotal Number of contact list are : "<<Total_contacts<<endl;
}
else {
        if(check!='9')
    cout<<"INVALID CHOICE...try again!!!"<<endl;
}

}while(check != '9');

cout<<"Credits:\nRATUL PEGU\nRATUL MAZUMDAR\nSUNIL UPADHYAY\nMUKIB KHAN\nADITYA HAZARIKA\nBIDISHA GOGOI\nDIVYANSHU KUMAR\nKALPATARU NARAH\nANKIT JHAWAR\nSWAPNIL DAS\n\n"<<endl;


Sleep(1000);
}

char menu()
{
cout<<"\n\n\n\n\n\n";
cout<<"\t\t\t\t\t--------------------------------------------------\n";
cout<<"\t\t\t\t\t--------------------------------------------------\n";
cout<<"\t\t\t\t\t|         PHONE BOOK APPLICATION                 |\n";
cout<<"\t\t\t\t\t--------------------------------------------------\n";
cout<<"\t\t\t\t\t|                                                |\n";
cout<<"\t\t\t\t\t|          [1] Add Contacts                      |\n";
cout<<"\t\t\t\t\t|          [2] Display All Contacts              |\n";
cout<<"\t\t\t\t\t|          [3] Search by Number                  |\n";
cout<<"\t\t\t\t\t|          [4] Search by Name                    |\n";
cout<<"\t\t\t\t\t|          [5] Update                            |\n";
cout<<"\t\t\t\t\t|          [6] Delete                            |\n";
cout<<"\t\t\t\t\t|          [7] Delete All                        |\n";
cout<<"\t\t\t\t\t|          [8] Number of contacts                |\n";
cout<<"\t\t\t\t\t|                                                |\n";
cout<<"\t\t\t\t\t--------------------------------------------------\n";
cout<<"\t\t\t\t\t|           [9] Exit                             |\n";
cout<<"\t\t\t\t\t--------------------------------------------------\n";
 char a;
 cout<<"\t\t\t\t\t";
 cin>>a;
 return a;
}
void start()
{
    system("color 9F");
    cout<<"\n\n\n\n\n\n\n\n\n";
     cout<<"\t\t\t\t\t--------------------------------------------\n";
     cout<<"\t\t\t\t\t--------------------------------------------\n";
     cout<<"  "<<"\t\t\t\t\t\t PHONE BOOK APPLICATION\n";
       cout<<"\t\t\t\t\t--------------------------------------------\n";
     cout<<"\t\t\t\t\t--------------------------------------------\n\n";
    cout<<"\t\t\t\t\t Please Wait While it is loading"<<endl;

    cout<<endl;
    cout<<"\t\t\t\t\t";
char x= 219;
for(int i=0;i<35;i++)
{
cout<<x;
if(i<10)
Sleep(300);
if(i>=10 && i<20)
Sleep(150);
if(i>=20)
Sleep(25);
}
system("cls");
}
