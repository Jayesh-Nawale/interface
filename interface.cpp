#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;

class PasswordGenerator {
public:
    string generatePassword(int length, bool includeUppercase, bool includeNumbers, bool includeSymbols) {
        string allCharacters = "abcdefghijklmnopqrstuvwxyz";
        string uppercaseCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string numberCharacters = "0123456789";
        string symbolCharacters = "!@#$%^&*()-=_+[]{}|;:'<>,.?/";

        if (includeUppercase) allCharacters += uppercaseCharacters;
        if (includeNumbers) allCharacters += numberCharacters;
        if (includeSymbols) allCharacters += symbolCharacters;

        string password;

        for (int i = 0; i < length; ++i) {
            int randomIndex = rand() % allCharacters.length();
            password += allCharacters[randomIndex];
        }

        return password;
    }
};

class QuoteGenerator {
public:

    QuoteGenerator() {
        loadQuotesFromFile("quotes.txt");
        srand(time(0));
    }

    string getRandomQuote() {
        if (quotes.empty()) {
            return "No quotes available.";
        }


        random_shuffle(quotes.begin(), quotes.end());


        return quotes[0];
    }

private:
    vector<string> quotes;


    void loadQuotesFromFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string quote;
        while (getline(file, quote)) {
            quotes.push_back(quote);
        }

        file.close();
    }
};

class BudgetAnalyzer {
public:
    void analyzeBudget() {
        double income, expenses;

        cout << "Enter your monthly income: $";
        cin >> income;

        cout << "Enter your monthly expenses: $";
        cin >> expenses;

        double savings = income - expenses;

        cout << "\nBudget Analysis:\n";
        cout << "Monthly Income: $" << income << endl;
        cout << "Monthly Expenses: $" << expenses << endl;
        cout << "Savings: $" << savings << endl;

        if (savings < 0) {
            cout << "Warning: You are spending more than your income, reduce your expenses and try saving.\n";
        } else if (savings > 0) {
            cout << "Great job! You have savings. Consider investing and compounding your money.\n";
        } else {
            cout << "Your income exactly matches your expenses. Consider finding ways to save or invest.\n";
        }
    }
};

int repeat();

int main() {
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Continue Program\n";
    cout << "2. Exit Program\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: repeat();
                break;

        case 2: cout << "Program exited";
                break;

        case 3: {
            BudgetAnalyzer budgetAnalyzer;
            budgetAnalyzer.analyzeBudget();
            break;
        }

        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}

int repeat() {
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Password Generator\n";
    cout << "2. Random Quote Generator\n";
    cout << "3. Personal Budget Analyzer\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            PasswordGenerator passwordGenerator;

            int length;
            bool includeUppercase, includeNumbers, includeSymbols;

            cout << "Password Length: ";
            cin >> length;

            cout << "Include Uppercase Letters? (1 for yes, 0 for no): ";
            cin >> includeUppercase;

            cout << "Include Numbers? (1 for yes, 0 for no): ";
            cin >> includeNumbers;

            cout << "Include Symbols? (1 for yes, 0 for no): ";
            cin >> includeSymbols;

            string generatedPassword = passwordGenerator.generatePassword(length, includeUppercase, includeNumbers, includeSymbols);

            cout << "\nGenerated Password: " << generatedPassword << endl;
            break;
        }

        case 2: {
            QuoteGenerator quoteGenerator;

            string randomQuote = quoteGenerator.getRandomQuote();

            cout << "\nRandom Quote:\n" << randomQuote << endl;
            break;
        }

        case 3: {
            BudgetAnalyzer budgetAnalyzer;
            budgetAnalyzer.analyzeBudget();
            break;
        }

        default:
            cout << "Invalid choice.\n";
    }

    main();

    return 0;
}
