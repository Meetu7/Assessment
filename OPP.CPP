#include <iostream>
#include <ctime>

using namespace std;

class ATM {
    private:
        const int ATM_PIN = 12345;
        int attempts;
        float initialBalance = 60000.0;
        float currentBalance = 20000.0;

    public:
        ATM() {
            attempts = 0;
        }

        void displayWelcomeScreen() {
            time_t now = time(0);
            char* dt = ctime(&now);
            cout << "Current Date and Time: " << dt << endl;
            cout << "Welcome to the ATM Banking Application" << endl << endl;
        }

        void displayMainMenu() {
            cout << "Please select an option:" << endl;
            cout << "1. Enter ATM Pin" << endl;
            cout << "2. Help" << endl;
            cout << "3. Exit" << endl;
        }

        void validatePin() {
            int userPin;
            cout << "Please enter your ATM PIN: ";
            cin >> userPin;

            if (userPin == ATM_PIN) {
                cout << "PIN validation successful!" << endl;
                displayMainMenu();
            }
            else {
                attempts++;
                if (attempts >= 1) {
                    cout << "Too many incorrect attempts. Exiting..." << endl;
                    exit(0);
                }
                else {
                    cout << "Invalid PIN. Please try again." << endl;
                    validatePin();
                }
            }
        }

        void displayHelpScreen() {
            cout << "ATM Banking Application Help" << endl;
            cout << "For assistance, please call customer service at 1-800-123-4567" << endl;
            displayMainMenu();
        }

        void depositFunds() {
            float depositAmount;
            cout << "Enter the amount to deposit: Rs. ";
            cin >> depositAmount;

            currentBalance += depositAmount;
            cout << "Deposit successful! Your current balance is Rs. " << currentBalance << endl;
            displayMainMenu();
        }
};

int main() {
    ATM atm;

    atm.displayWelcomeScreen();

    int choice;
    do {
        atm.displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                atm.validatePin();
                break;

            case 2:
                atm.displayHelpScreen();
                break;

            case 3:
                cout << "Exiting..." << endl;
                exit(0);
                break;

            default:
                cout << "Invalid option selected. Please try again." << endl;
                break;
        }
    } while (true);

    return 0;
}
