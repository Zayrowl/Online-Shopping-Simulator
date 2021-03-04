#include <iostream>
#include <iomanip>  //to use setprecision()
#include <cctype>   //to use toupper()
using namespace std;

//Function stubs
void itemList();
void customerDetails();
char newResponse(char);
void displayCustomerDetails(string, int, string, string, string);

struct CUSDETAILS //Data Structures
{
	string name;
	int contactNum;
	string address;
	string email;
} Details;


int main ()
{
	//Initializing the variables
	int itemQuantity[100], choice, i, z, quantity;
	float itemPrice [100], price, sum = 0, totalCurrentItem;
	string itemlist [100], item, statMember;
	char response = 'Y';
	
	string membership[2] = {"Member" , "Non-member"};
	
	cout << "=====================================================";
	cout << "\n        WELCOME TO MASTER IT ONLINE SHOPPING!\n";
	cout << "=====================================================\n\n";
	
	itemList(); //Calling function
	
	do //Do / while loop to ask the customer whether to add item(s) or not
	{
		cout << "\nPlease enter your item choice [1/2/3/4/5/6] : ";
		cin >> choice;

	
		
		if (cin.fail() || choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
		{
			cout << "Invalid response. Please enter the provided options. [1/2/3/4/5/6] : ";
			cin.clear();
			cin.ignore();
			continue;
		}
	
		switch(choice) //selection to choose items
		{
			case 1:
				item = "Tripods";
				price = 22.50;
				break;
		 
			case 2:
				item = "Toaster";
				price = 35.20;
				break;
			
			case 3:
				item = "Study Lamp";
				price = 25.00;
				break;
			
			case 4:
				item = "Candles";
				price = 10.90;
				break;
			
			case 5:
				item = "Gaming chair";
				price = 40.00;
				break;
			
			case 6:
				item = "Foldable table";
				price = 20.50;
				break;
			
		}
		
		//Calculates the sum of all items chosen
		cout << "Quantity : ";
		cin >> quantity;
		while(cin.fail()){ //If input is false, will enter the loop, else continue as usual
			cin.clear();
			cin.ignore();
			cout << "Invalid response. Please enter the quantity :";
			cin >> quantity;
			if (cin.fail())
			{
				continue; //Continue to loop whenever user input other than int
			}else {
				break; //Break the loop when user input int
			}
		}
		totalCurrentItem = price*quantity;
		sum += totalCurrentItem ; 
		cout << "-----------------------------------------------\n";
		
		//Inserting elements in their position respectively
		itemQuantity[i] = quantity; 
		itemPrice[i] = price; 
		itemlist[i] = item ;
		i++;
		
		cout << "Do you want to add another item? [Y/N] : ";
		cin >> response;
		response = toupper(response); // Making sure that the char will always be capitalized
		
		// Loop for when responses besides Y/N are inputted
		while (response != 'Y' && response != 'N') 
		{
			response = newResponse(response);
		}
		
	}while (response == 'Y'); 
	cout << "\n\n\n";
	customerDetails(); //Calling function
	
	cout << "\nAre you a member of Master IT online? [Y/N]: ";
	cin >> response;
	response = toupper(response); // Making sure that the char will always be capitalized
	
	while (response != 'Y' && response != 'N') 
		{
			response = newResponse(response);
		}
	
	if (response == 'N')
	{
		cout << "\nBe part of our member! Many prizes awaits by using the points collected thorugh your purchases!! \n";
		cout << "Would you like to be a part of our member? Only RM10 will be charged!  [Y/N] : ";
		cin >> response;
		response = toupper(response); // Making sure that the char will always be capitalized
		while (response != 'Y' && response != 'N')
		{
			response = newResponse(response);
		}
		
		if (response == 'Y')
		{
			cout << "\nCongratz, You are now a part of the family!\n";
			sum += 10; 
			statMember=membership[0];
			z=i+1;
			itemlist[i] = "Membership";
			itemPrice[i] = 10;
			itemQuantity[i] = 1;
		}
		
		else if (response == 'N')
		{
			cout << "\nAlright!\n";
			statMember=membership[1];
			z=i;
		}
	}
	
	else if (response == 'Y')
	{
		statMember=membership[0];
		z=i;		
	}
	
	displayCustomerDetails(Details.name,Details.contactNum,Details.address,Details.email,statMember); //Calling function

	for(int j = 0 ; j < z ; j++) //Displaying the elements in the array
			{
				cout << itemlist[j] << " \tRM" << fixed <<setprecision(2) << itemPrice[j] << "\t\t  " << itemQuantity[j] << endl;
			}
	cout << "=============================================\n";
		
	cout << "The total price of all the items is RM" << sum;
	cout << "\n=============================================\n";

	return 0;
}



void itemList() //Function to display list of items with price
{
	cout << "-----------------------------------------------";
	cout << "\n\t      ITEM AVAILABILITY";
	cout << "\n-----------------------------------------------";	
	cout << "\n[1]Tripod \t\t- RM22.50 ";
	cout << "\n[2]Toaster \t\t- RM35.20 ";
	cout << "\n[3]Study Lamp \t\t- RM25.00";
	cout << "\n[4]Candles \t\t- RM10.90";
	cout << "\n[5]Gaming chair \t- RM40.00";
	cout << "\n[6]Foldable table \t- RM20.50";
	cout << "\n-----------------------------------------------";	
}

void customerDetails() //Function to prompt customer's details
{
	cin.ignore();
	cout << "Please fill in your details for delivery purposes: \n";
	cout << "Full name \t: ";
	getline(cin , Details.name);
	cout << "Contact number \t: ";
	cin >> Details.contactNum;
	cin.ignore();
	cout << "Delivery Address: ";
	getline(cin , Details.address);
	cout << "Email \t\t: ";
	cin >> Details.email;	
}

void displayCustomerDetails(string name, int contactNum, string address, string email,string statMember)
{
	//Displaying the customer and order's details.
	cout << "\n=============================================\n";
	cout << "\t      Your Details\n";
	cout << "=============================================\n";
	cout << "Name \t\t : " << name;
	cout << "\nContact Number \t :(+60) " << contactNum;
	cout << "\nDelivery Address : " << address;
	cout << "\nEmail \t\t : " << email; 
	cout << "\nMembership Status: " << statMember;
			
	cout << "\n=============================================\n";
	cout << "\t      Order Details";
	cout << "\n=============================================\n";
			
	cout << "Item\t\tPrice\t\tQuantity\n";
	cout << "---------------------------------------------\n";		
}

char newResponse(char response)
{
	cout << "Invalid response. Please enter the provided options. [Y/N] : ";
	cin >> response;
	response = toupper(response); // Making sure that the char will always be capitalized
	return response;
}

