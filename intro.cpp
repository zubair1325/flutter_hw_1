#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std; 
bool login()
{
    //system("cls");
	system("clear");
    string SAName;
    string SAPass;
    int ch, i = 0, gen_captcha = 0, Input_captcha = 0;
    cout << "\t\tUser Name : ";
    cin >> SAName;
    cout << "\t\tPassword : ";
    cin>>SAPass;
    srand(time(0));
    gen_captcha = rand()%1000;
    cout << endl << "Enter this number below : " << gen_captcha << endl;
    cout << "Enter the above number : ";
    cin >> Input_captcha;
    if (SAName== "user" && SAPass == "pass" && gen_captcha == Input_captcha )
    {
        cout << endl << "\t\t\t\t | Veryfing User | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 2; s++)
        {
            sleep(2);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   User Verified... ;)" << endl << endl;
        //system("pause");
	
        return true;
    }
    else
    {
        cout << endl << "\t\t\t\t | Veryfing User | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 5; s++)
        {
            sleep(1);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   Access Denied... :(" << endl << endl;
        //system("pause");
        return false;
    }
}


int main() 
{ 
system("clear");
string letters[9] = { 
"       OOOOOOOO00O SSSSSSSSSS", 
"       O         O S", 
"       O         O S",
"       O         O S",
"       O         O SSSSSSSSS",
"       O         O         S",
"       O         O         S",
"       O         O         S",
"       OOOOOOOOOOO SSSSSSSSS" 
}; 


cout << "\n\n\n\t\t\t\tWelcome to\n\n";
for (int i = 0; i < 9; i++) 
{ 
cout <<"\t\t   ";
for (int j = 0; j < letters[i].length(); j++) 
{ 
cout << letters[i][j];
 } 
cout << "  "<<endl;  // Add spacing between the letters 
}
cout << "\n\t\tCREDITS: Md. Zubair Rahman(1325)\n\t\t\t |Ashraful Alom Chowdhury(1317)\n\t\t\t |Fiza Afroz(1311)\n\t\t\t |Tonima Khan Mim(1365)\n\t\t\t |Rafia Anjum(1327)\n";
cout << endl << "\t\t\t        | Loading | " << endl;
        cout << "\t\t\t         ";
	for (int s = 0; s < 4; s++)
        	{
			sleep(1);
            		cout << "..";
        	}	
        cout<<endl;
	puts("Press enter to continue...");
	getchar(); // wait for user input
	system("clear");
	while(!login());
	puts("Press enter to continue...");
	getchar(); // wait for user input
	system("clear");
	system("./main"); // run the main program  
	
 return 0; 
}


