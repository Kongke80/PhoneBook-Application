#include <bits/stdc++.h>
#include <windows.h>
#include <string>
using namespace std;
void start();
char menu();

int main(){
	unordered_map<string, string> mp;
	start();
	char check = '0';
	while(check!=9)
	{
		check = menu();
		system("CLS");
		// Add contacts
		//variables usedcout
		string name, number, numberToSearch, nameToSearch, oldName, newName, newNumber, nameToBeDeleted;
		if (check == '1'){
			cout << "\t\t\t\t\t\t Name :";
			cin.ignore(1, '/n');	//buffer is int type
			getline(cin, name);
			cout << "\t\t\t\t\t\t Phone no :";
			cin >> number;
			mp[name]=number;
		}

		// Display contacts
		else if (check == '2'){	
			if(mp.size()==0)
				cout << "\t\t\t\t\t\t No Contacts to display"<<endl;
			for(auto it: mp)
				cout << "\t\t\t\t\t\t Name :" << it.first << "          Phone :" << it.second << endl;
			cout<<"\t\t\t\t\t\t Total Contacts=" <<mp.size()<<endl; 
		}

		// Search by Number
		else if (check == '3'){
			cout << "\t\t\t\t\tNumber : ";
			cin >> numberToSearch;
			if(mp.size()==0){
				cout << "\t\t\t\t\t\t No Contacts to Search";
				continue;
			}

			if(mp.find(numberToSearch)!=mp.end()){	
				auto it=mp.find(numberToSearch);
				cout << "\t\t\t\t\tNumber is Found"<<endl;
				cout << "\t\t\t\t\t\t Name :" << it->first << "          Phone :" << it->second << endl;
			}
			else
				cout << "\t\t\t\t\tNumber is NOT Found"<<endl;
		}

		// Search by Name
		else if (check == '4'){
			if(mp.size()==0){
				cout << "\t\t\t\t\t\t No Contacts to Search";
				continue;
			}
			cout << "\t\t\t\t\tName : ";
			cin.ignore(1, '/n');
			getline(cin, nameToSearch);
			if (mp.find(nameToSearch)!=mp.end()){
				auto it=mp.find(nameToSearch);
				cout << "\t\t\t\t\tName is Found"<<endl;
				cout << "\t\t\t\t\tName : " << it->first << "    Phone : " << it->second << endl;
	
			}			
			else
				cout << "\t\t\t\t\t This name is not found in your contact list\n";
		}

		// Update
		else if (check == '5'){	
			if(mp.size()==0){
				cout << "\t\t\t\t\t\t No Contacts to update";
				continue;
			}
			cout << "\t\t\t\t\tName of the contact to be Updated: ";
			cin.ignore(1,'/n');		
        	getline(cin,oldName);
			if (mp.find(oldName)!=mp.end()){
				auto it=mp.find(oldName);
				cout<<"\t\t\t\t\tName Found!!!"<<endl;
				cout << "\t\t\t\t\tNew Name : ";
				// cin.ignore(1,'/n');		as buffer is string type previously
        		getline(cin,newName);
				string t;
				jump:
				cout << "\t\t\t\t\tDo you want to update the number too?(Y/N)";
				cin>>t;
				if(t=="Y" or t=="y" or t=="Yes" or t=="yes"){
					cout << "\t\t\t\t\tOld number : " << it->second << endl;
					cout << "\t\t\t\t\tNew Number : ";
					cin >> newNumber;
					mp[newName]=newNumber;	
				}
				else if(t=="N" or t=="n" or t=="No" or t=="no"){
					mp[newName]=mp[oldName];
					cout<<"\t\t\t\t\tNumber is unchanged."<<endl;
				}
				else{
					cout << "\t\t\t\t\t wrong input. Please try again"<<endl;
					goto jump;
				}
				cout << "\t\t\t\t\tName : " << mp.find(newName)->first << "    Phone : " << mp.find(newName)->second << endl;
				cout << "\t\t\t\t\tUpdated Successfully!!"<<endl;
				mp.erase(it);
			}
			else
				cout << "\t\t\t\t\tThis name is not found in your contact list"<<endl;
		}

		// Delete
		else if (check == '6'){
			if(mp.size()==0){
				cout << "\t\t\t\t\t\tNo Contacts available to delete"<<endl;
				continue;
			}
			cout<<"\t\t\t\t\tName of the contact to be deleted : ";
			cin.ignore(1,'/n');		
        	getline(cin,nameToBeDeleted);
			if (mp.find(nameToBeDeleted)!=mp.end()){
				auto it=mp.find(nameToBeDeleted);
				cout << "\t\t\t\t\tName : " << it->first << "    Phone : " << it->second << endl;
				cout << "\t\t\t\t\tDeleted Successfully"<<endl;
				mp.erase(it);
			}
			else
				cout << "\t\t\t\t\t This name is not found in your contact list"<<endl;
		}

		// delete All
		else if (check == '7'){
			if(mp.size()==0){
				cout<<"\t\t\t\t\tPhone-Book is already Empty!"<<endl;
				continue;
			}
			mp.clear();
			cout << "\t\t\t\t\tAll Contacts are Deleted Successfully"<<endl;
		}
		// Display number of contacts
		else if (check == '8')
			cout << "\t\t\t\t\tTotal Number of contact list are: " << mp.size() << endl;
		else{
			if (check != '9')
				cout << "INVALID CHOICE...Please try again!!!" << endl;
			else{
				cout << "Thank you"<<endl<<"Credits: Aditya Hazarika"<<endl;
				break;
			}
		}

	}  
	

	Sleep(100000);
}

char menu()
{
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t--------------------------------------------------\n";
	cout << "\t\t\t\t\t--------------------------------------------------\n";
	cout << "\t\t\t\t\t|         PHONE BOOK APPLICATION                 |\n";
	cout << "\t\t\t\t\t--------------------------------------------------\n";
	cout << "\t\t\t\t\t|                                                |\n";
	cout << "\t\t\t\t\t|          [1] Add Contacts                      |\n";
	cout << "\t\t\t\t\t|          [2] Display All Contacts              |\n";
	cout << "\t\t\t\t\t|          [3] Search by Number                  |\n";
	cout << "\t\t\t\t\t|          [4] Search by Name                    |\n";
	cout << "\t\t\t\t\t|          [5] Update                            |\n";
	cout << "\t\t\t\t\t|          [6] Delete                            |\n";
	cout << "\t\t\t\t\t|          [7] Delete All                        |\n";
	cout << "\t\t\t\t\t|          [8] Number of contacts                |\n";
	cout << "\t\t\t\t\t|                                                |\n";
	cout << "\t\t\t\t\t--------------------------------------------------\n";
	cout << "\t\t\t\t\t|           [9] Exit                             |\n";
	cout << "\t\t\t\t\t--------------------------------------------------\n";
	char a;
	cout << "\t\t\t\t\t";
	cin >> a;
	return a;
}
void start()
{
	system("color 9F");
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t\t--------------------------------------------\n";
	cout << "  "
		 << "\t\t\t\t\t\t PHONE BOOK APPLICATION\n";
	cout << "\t\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t\t--------------------------------------------\n\n";
	cout << "\t\t\t\t\t Please Wait While it is loading" << endl;

	cout << endl;
	cout << "\t\t\t\t\t";
	char x = 219;
	for (int i = 0; i < 35; i++)
	{
		cout << x;
		if (i < 10)
			Sleep(300);
		if (i >= 10 && i < 20)
			Sleep(150);
		if (i >= 20)
			Sleep(25);
	}
	system("cls");
}
