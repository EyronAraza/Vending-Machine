#include<iostream>
#include<string>
#include<Windows.h> // for using text colors
#include<conio.h> // for using system("cls"); to clear console screen
using namespace std;

// STOCK ITEMS
static bool stockCheck(bool itemCheck, int itemStock);
int chipsStock[] = { 8, 8, 8, 8, 8 };
int sweetsStock[] = { 8, 8, 8, 8 };
int drinksStock[] = { 8, 8, 8 };

// defining function for main screen and going back to main screen
void mainScreen(); 
static void backToMenu(bool exit);

// defining functions for chips category
void chipsScreenMenu(); 
void chipsScreen();
// defining functions for sweets category
void sweetsScreenMenu();
void sweetsScreen();
// defining functions for drinks category
void drinksScreenMenu();
void drinksScreen();

// defining functions for calculations
double purchase(double money, double price);

// ----------------------------------------------------------------------------------------------- //

// THE MAIN PROGRAM
int main() { 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // colors for the text

	mainScreen();

	system("cls");
	SetConsoleTextAttribute(h, 15); // bright white color text
	return 0;
}

// THE MAIN SCREEN
void mainScreen() {
	bool exit = false; // to exit out of the loop if set to true
	bool invalidMsg = false; // if user input the wrong input, it will set the bool to true

	// using while loop to repeat the main screen
	while (!exit || !invalidMsg) {
		system("cls");
		cout << endl << endl;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "       ";

		// TITLE
		SetConsoleTextAttribute(h, 143); // bright white with grey backround text
		cout << "                                                                                                    " << endl;
		SetConsoleTextAttribute(h, 0); // blank color
		cout << "       ";
		SetConsoleTextAttribute(h, 143); // bright white with grey backround text
		cout << "                                         THE VENDING MACHINE                                        " << endl;
		SetConsoleTextAttribute(h, 0);
		cout << "       ";
		SetConsoleTextAttribute(h, 143); // bright white with grey backround text
		cout << "                                                                                                    " << endl;

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";

		// CATEGORIES
		SetConsoleTextAttribute(h, 79); // bright white with red backround text
		cout << " |1|CHIPS           PRICE         ";

		SetConsoleTextAttribute(h, 95); // bright white with purple backround text
		cout << " |2|SWEETS          PRICE        ";

		SetConsoleTextAttribute(h, 31); // bright white with dark blue backround text
		cout << " |3|DRINKS          PRICE        " << endl;

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";

		// LIST OF ITEMS WITH PRICE
		SetConsoleTextAttribute(h, 240); // bright white with black backround text
		cout << " PRINGLES          4.40 AED        KIT KAT           3.25 AED       WATER             1.75 AED      " << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 240); // bright white with black backround text
		cout << " LAYS              2.20 AED        BREAK             2.00 AED       COLA              3.00 AED      " << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 240); // bright white with black backround text
		cout << " DORITOS           3.00 AED        GALAXY            2.50 AED       JUICE             2.20 AED      " << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 240); // bright white with black backround text
		cout << " CHEETOS           2.00 AED        BUBBLEGUM         3.50 AED                                       " << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 240); // bright white with black backround text
		cout << " BUGLES            2.50 AED                                                                         " << endl;

		// CATEGORY SELECTION
		int userSelect;
		
		cout << endl;

		if (invalidMsg == true) { // once the invalidMsg is set to true when user makes wrong input, it will display the invalid message
			SetConsoleTextAttribute(h, 12); // red text
			cout << "                                                   INVALID INPUT" << endl;
		}

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                            Welcome user!" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                              Enter a number (1-3) to select a category" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "                                                         ";

		SetConsoleTextAttribute(h, 14);

		cin >> userSelect; // user input to select a category
		cin.clear();
		cin.ignore(250, '\n');

		switch (userSelect) { // using switch for category selection
		case 1: { // go to chips category
			exit = true;
			invalidMsg = true;
			chipsScreen();
		}
			break;
		case 2: // go to sweets category
			exit = true;
			invalidMsg = true;
			sweetsScreen();
			break;
		case 3: // go to drinks category
			exit = true;
			invalidMsg = true;
			drinksScreen();
			break;
		default: // if user input any wrong value, it will set the invalidMsg bool to true to display the invalid message
			invalidMsg = true;
			break;
		}
	}
}

// CHIPS CATEGORY: MENU LIST
void chipsScreenMenu() {
	cout << endl << endl << endl << endl << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "                                  ";

	// LIST OF CHIPS WITH PRICE AND STOCK
	SetConsoleTextAttribute(h, 79); // red white with grey backround text
	cout << " |1|CHIPS                       PRICE          STOCK     " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  1|PRINGLES (ORIGINAL)        4.70 AED          " << chipsStock[0] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  2|LAYS (BLACK PEPPER)        2.20 AED          " << chipsStock[1] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  3|DORITOS (SWEET CHILI)      3.00 AED          " << chipsStock[2] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  4|CHEETOS (FLAMIN HOT)       2.00 AED          " << chipsStock[3] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  5|BUGLES (CHEESE)            2.50 AED          " << chipsStock[4] << "       " << endl;

	cout << endl;
}

// CHIPS CATEGORY: SELECTION
void chipsScreen() {
	bool exit = false; // to exit out of the loop if set to true
	bool invalidMsg = false; // if user input the wrong input, it will set the bool to true
	bool stock = false;

	while (!exit || !invalidMsg || !stock) {
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		chipsScreenMenu();

		// CHIPS SELECTION
		int selection;

		if (invalidMsg == true) { // display invalid input message
			SetConsoleTextAttribute(h, 12); // red text
			cout << "                                                       INVALID INPUT" << endl;
		}

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                            What would you like?" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                           6 = Back to Main Menu" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                      Enter a number to select an item" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "                                                            ";

		SetConsoleTextAttribute(h, 14); // yellow text
		cin >> selection;
		cin.clear();
		cin.ignore(250, '\n');

		switch (selection) { // using switch to select chips
		case 6: { // back to main menu
			exit = true;
			mainScreen();
		}
			break;
		case 1: // pringles selection
		{
			// item details with name and price
			string itemName = "Pringles";
			double price = 4.70;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, chipsStock[0]);
			if (stocked) {
				system("cls");
				chipsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			} else { // else continue the program if stock available

			exit = true;
			bool exit2 = false;
			invalidMsg = false;
			while (!exit2 || !invalidMsg) {
				system("cls");
				chipsScreenMenu();

				if (invalidMsg == true) {  // display invalid input message
					SetConsoleTextAttribute(h, 12); // red text
					cout << "                                                       INVALID INPUT" << endl;
				}

				SetConsoleTextAttribute(h, 0); // space
				cout << "       ";
				SetConsoleTextAttribute(h, 14); // yellow text
				cout << "                                           YOU SELECTED: " << itemName << endl;
				SetConsoleTextAttribute(h, 0); // space
				cout << "       ";
				SetConsoleTextAttribute(h, 14); // yellow text
				cout << "                                               PRICE: " << price << " AED" << endl;
				SetConsoleTextAttribute(h, 0); // space
				cout << "       ";
				SetConsoleTextAttribute(h, 14); // yellow text
				cout << "                                         Would you like to buy? (Y/N)" << endl;
				SetConsoleTextAttribute(h, 0); // space
				cout << "                                                            ";

				SetConsoleTextAttribute(h, 14); // yellow text
				char selectionYN;
				cin >> selectionYN;
				selectionYN = toupper(selectionYN); // convert lowercase to uppercase
				cin.clear();
				cin.ignore(250, '\n');

				switch (selectionYN) { // Yes or No selection
				case 'Y': // Yes
				{
					exit2 = true;
					bool exit3 = false;
					invalidMsg = false;
					while (!exit3 || !invalidMsg) {
						system("cls");
						chipsScreenMenu();

						if (invalidMsg == true) { // display invalid input message
							SetConsoleTextAttribute(h, 12); // red text
							cout << "                                                       INVALID INPUT" << endl;
						}

						SetConsoleTextAttribute(h, 0); // space
						cout << "       ";
						SetConsoleTextAttribute(h, 14); // yellow text
						cout << "                                           YOU SELECTED: " << itemName << endl;
						SetConsoleTextAttribute(h, 0); // space
						cout << "       ";
						SetConsoleTextAttribute(h, 14); // yellow text
						cout << "                                               PRICE: " << price << " AED" << endl;
						SetConsoleTextAttribute(h, 0); // space
						cout << "       ";
						SetConsoleTextAttribute(h, 14); // yellow text
						cout << "                                             Enter Money: ";

						// user input their money
						double userMoney;
						cin >> userMoney;
						cin.ignore();
						cin.clear(250, '\n');

						if (userMoney >= price) { // user made the purchase
							system("cls");
							chipsScreenMenu();

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                      Press Enter key to go back to menu" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "                                                             ";

							chipsStock[0]--; // reduce one stock after purchase
							backToMenu(exit3); // go back to menu		
						}
						else if (price > userMoney) { // if user doesn't have enough money
							system("cls");
							chipsScreenMenu();

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 12); // yellow text
							cout << "                                              NOT ENOUGH MONEY" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                        Your money has been returned" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           Money received: " << userMoney << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                      Press Enter key to go back to menu" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "                                                             ";

							backToMenu(exit3); // go back to menu
						}
					}
				}
				break;
				case 'N': // No, goes back to item selection
					exit2 = true;
					chipsScreen();
					break;
				default: // Invalid input
					invalidMsg = true;
					break;
				}
			}
			}
		}
			break;
		case 2: // lays selection
		{
			// item details with name and price
			string itemName = "Lays (Black Pepper)";
			double price = 2.20;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, chipsStock[1]);
			if (stocked) {
				system("cls");
				chipsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					chipsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							chipsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								chipsStock[1]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						chipsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
			break;
		case 3: // doritos selection
		{
			// item details with name and price
			string itemName = "Doritos (Sweet Chili)";
			double price = 3.00;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, chipsStock[2]);
			if (stocked) {
				system("cls");
				chipsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					chipsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							chipsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								chipsStock[2]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						chipsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
			break;
		case 4: // cheetos selection
		{
			// item details with name and price
			string itemName = "Cheetos (Flamin Hot)";
			double price = 2.00;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, chipsStock[3]);
			if (stocked) {
				system("cls");
				chipsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					chipsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							chipsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								chipsStock[3]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						chipsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
			break;
		case 5: // bugles selection
		{
			// item details with name and price
			string itemName = "Bugles (Cheese)";
			double price = 2.50;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, chipsStock[4]);
			if (stocked) {
				system("cls");
				chipsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					chipsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							chipsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								chipsStock[4]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								chipsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						chipsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
			break;
		default: // Invalid input
			invalidMsg = true;
			break;
		}
	}
}

// SWEETS CATEGORY: MENU LIST
void sweetsScreenMenu() {
	cout << endl << endl << endl << endl << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "                                  ";

	// LIST OF SWEETS WITH PRICE AND STOCK
	SetConsoleTextAttribute(h, 95); // red white with grey backround text
	cout << " |1|SWEETS                       PRICE          STOCK    " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  1|KIT KAT                    3.25 AED           " << sweetsStock[0] << "      " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  2|BREAK                      2.00 AED           " << sweetsStock[1] << "      " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  3|GALAXY                     2.50 AED           " << sweetsStock[2] << "      " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  4|BUBBLEGUM                  3.50 AED           " << sweetsStock[3] << "      " << endl;

	cout << endl;
}

// SWEETS CATEGORY: SELECTION
void sweetsScreen() {
	bool exit = false; // to exit out of the loop if set to true
	bool invalidMsg = false; // if user input the wrong input, it will set the bool to true
	bool stock = false;

	while (!exit || !invalidMsg || !stock) {
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		sweetsScreenMenu();

		// SWEETS SELECTION
		int selection;

		if (invalidMsg == true) { // display invalid input message
			SetConsoleTextAttribute(h, 12); // red text
			cout << "                                                       INVALID INPUT" << endl;
		}

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                            What would you like?" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                           5 = Back to Main Menu" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                      Enter a number to select an item" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "                                                            ";

		SetConsoleTextAttribute(h, 14); // yellow text
		cin >> selection;
		cin.clear();
		cin.ignore(250, '\n');

		switch (selection) { // using switch to select chips
		case 5: { // back to main menu
			exit = true;
			mainScreen();
		}
			  break;
		case 1:
		{
			// item details with name and price
			string itemName = "Kit Kat";
			double price = 3.25;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, sweetsStock[0]);
			if (stocked) {
				system("cls");
				sweetsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					sweetsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							sweetsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								sweetsStock[0]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						sweetsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		case 2: 
		{
			// item details with name and price
			string itemName = "Break";
			double price = 2.00;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, sweetsStock[1]);
			if (stocked) {
				system("cls");
				sweetsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					sweetsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							sweetsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								sweetsStock[1]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						sweetsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		case 3:
		{
			// item details with name and price
			string itemName = "Galaxy";
			double price = 2.50;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, sweetsStock[2]);
			if (stocked) {
				system("cls");
				sweetsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					sweetsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							sweetsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								sweetsStock[2]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						sweetsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		case 4: 
		{
			// item details with name and price
			string itemName = "Bubblegum";
			double price = 3.50;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, sweetsStock[3]);
			if (stocked) {
				system("cls");
				sweetsScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					sweetsScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							sweetsScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								sweetsStock[3]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								sweetsScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						sweetsScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		default:
		{
			invalidMsg = true;
		}
		break;
		}
	}
}

// DRINKS CATEGORY: MENU LIST
void drinksScreenMenu() {
	cout << endl << endl << endl << endl << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "                                  ";

	// LIST OF SWEETS WITH PRICE AND STOCK
	SetConsoleTextAttribute(h, 31); // red white with grey backround text
	cout << " |1|DRINKS                       PRICE          STOCK     " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  1|WATER                      1.75 AED           " << drinksStock[0] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  2|COLA                       3.00 AED           " << drinksStock[1] << "       " << endl;
	SetConsoleTextAttribute(h, 0); // space
	cout << "                                  ";
	SetConsoleTextAttribute(h, 240); // bright white with black backround text
	cout << "  3|APPLE JUICE                2.20 AED           " << drinksStock[2] << "       " << endl;

	cout << endl;
}

// DRINKS CATEGORY: SELECTION
void drinksScreen() {
	bool exit = false; // to exit out of the loop if set to true
	bool invalidMsg = false; // if user input the wrong input, it will set the bool to true
	bool stock = false;

	while (!exit || !invalidMsg || !stock) {
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		drinksScreenMenu();

		// DRINKS SELECTION
		int selection;

		if (invalidMsg == true) { // display invalid input message
			SetConsoleTextAttribute(h, 12); // red text
			cout << "                                                       INVALID INPUT" << endl;
		}

		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                            What would you like?" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                           4 = Back to Main Menu" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "       ";
		SetConsoleTextAttribute(h, 14); // yellow text
		cout << "                                      Enter a number to select an item" << endl;
		SetConsoleTextAttribute(h, 0); // space
		cout << "                                                            ";

		SetConsoleTextAttribute(h, 14); // yellow text
		cin >> selection;
		cin.clear();
		cin.ignore(250, '\n');

		switch (selection) { // using switch to select chips
		case 4: { // back to main menu
			exit = true;
			mainScreen();
		}
			  break;
		case 1:
		{
			// item details with name and price
			string itemName = "Water";
			double price = 1.75;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, drinksStock[0]);
			if (stocked) {
				system("cls");
				drinksScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					drinksScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							drinksScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								drinksStock[0]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						drinksScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		case 2:
		{
			// item details with name and price
			string itemName = "Cola";
			double price = 3.00;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, drinksStock[1]);
			if (stocked) {
				system("cls");
				drinksScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					drinksScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							drinksScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								drinksStock[1]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						drinksScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		case 3:
		{
			// item details with name and price
			string itemName = "Apple Juice";
			double price = 2.20;

			// checks if item is out of stock
			bool stocked = stockCheck(stock, drinksStock[2]);
			if (stocked) {
				system("cls");
				drinksScreenMenu();
				exit = false;
				invalidMsg = false;
				SetConsoleTextAttribute(h, 12); // red text
				cout << "                                                       OUT OF STOCK" << endl;
				cout << "                                                 (Press Enter to continue)" << endl;
				cout << "                                                            ";
				cin.get();
			}
			else { // else continue the program if stock available

				exit = true;
				bool exit2 = false;
				invalidMsg = false;
				while (!exit2 || !invalidMsg) {
					system("cls");
					drinksScreenMenu();

					if (invalidMsg == true) {  // display invalid input message
						SetConsoleTextAttribute(h, 12); // red text
						cout << "                                                       INVALID INPUT" << endl;
					}

					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                           YOU SELECTED: " << itemName << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                               PRICE: " << price << " AED" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "       ";
					SetConsoleTextAttribute(h, 14); // yellow text
					cout << "                                         Would you like to buy? (Y/N)" << endl;
					SetConsoleTextAttribute(h, 0); // space
					cout << "                                                            ";

					SetConsoleTextAttribute(h, 14); // yellow text
					char selectionYN;
					cin >> selectionYN;
					selectionYN = toupper(selectionYN); // convert lowercase to uppercase
					cin.clear();
					cin.ignore(250, '\n');

					switch (selectionYN) { // Yes or No selection
					case 'Y': // Yes
					{
						exit2 = true;
						bool exit3 = false;
						invalidMsg = false;
						while (!exit3 || !invalidMsg) {
							system("cls");
							drinksScreenMenu();

							if (invalidMsg == true) { // display invalid input message
								SetConsoleTextAttribute(h, 12); // red text
								cout << "                                                       INVALID INPUT" << endl;
							}

							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                           YOU SELECTED: " << itemName << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                               PRICE: " << price << " AED" << endl;
							SetConsoleTextAttribute(h, 0); // space
							cout << "       ";
							SetConsoleTextAttribute(h, 14); // yellow text
							cout << "                                             Enter Money: ";

							// user input their money
							double userMoney;
							cin >> userMoney;
							cin.ignore();
							cin.clear(250, '\n');

							if (userMoney >= price) { // user made the purchase
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           SUCCESSFULLY PURCHASED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                         ITEM(S) HAS BEEN DISPENSED!" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Change received: " << purchase(userMoney, price) << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								drinksStock[2]--; // reduce one stock after purchase
								backToMenu(exit3); // go back to menu		
							}
							else if (price > userMoney) { // if user doesn't have enough money
								system("cls");
								drinksScreenMenu();

								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 12); // yellow text
								cout << "                                              NOT ENOUGH MONEY" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                        Your money has been returned" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                           Money received: " << userMoney << " AED" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "       ";
								SetConsoleTextAttribute(h, 14); // yellow text
								cout << "                                      Press Enter key to go back to menu" << endl;
								SetConsoleTextAttribute(h, 0); // space
								cout << "                                                             ";

								backToMenu(exit3); // go back to menu
							}
						}
					}
					break;
					case 'N': // No, goes back to item selection
						exit2 = true;
						drinksScreen();
						break;
					default: // Invalid input
						invalidMsg = true;
						break;
					}
				}
			}
		}
		break;
		default:
		{
			invalidMsg = true;
		}
		break;
		}
	}
}

// BACK TO MENU
static void backToMenu(bool exit) {
	string backToMenu;
	cin >> backToMenu;
	cin.clear();
	cin.ignore(250, '\n');
	if (backToMenu == "") {
		exit = true;
		mainScreen();
	}
	else {
		exit = true;
		mainScreen();
	}
}

// CALCULATION FOR CHANGE
double purchase(double money, double price) {
	double change = money - price;
	return change;
}

// STOCK SYSTEM
static bool stockCheck(bool itemCheck, int itemStock) {
	if (itemStock <= 0) {
		return true;
	}
	else {
		return false;
	}
}