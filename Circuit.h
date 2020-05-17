#ifndef CIRCUIT_H_
#define CIRCUIT_H_
#include <bits/stdc++.h>
using namespace std;
//PARSER for BOOLEAN LOGIC.
/*
    My 'PEMDAS' equivalent is in order of least to most important:
    
    Literally just not implementing it.

    Use parentheses.

    Thats about it--without parentheses, your equation wont compile. 
    Its not that youll get incorrect output--you literally wont get output.

    Do yourself a favor, write with parentheses, youll thank yourself in the future.
*/
class GATES
{
public:
    string type;
    vector<string> dependencies;
};
vector<GATES> circuit;
map<string, string> names;
void parser()
{
    cout << "What gate would you like to add?\n";
    cout << "1. AND\n2. OR\n3. NOT\n4. NAND\n5. NOR\n6. XOR\n7. XNOR\n\n";
    int user_input_gate;
    cin >> user_input_gate;
    while (cin.fail() || user_input_gate < 1 || user_input_gate > 7)
    {
        cout << "That input was not a listed option. Please choose a listed option.\n";
        cin >> user_input_gate;
    }

    //you might wonder: why braces? Are you a plebian?
    //well, no.
    //A switch case is actually just a goto with a fancy wrapper, and without braces it doesnt like a lot of things.
    //protect your switch cases.

    switch (user_input_gate)
    {
    case 1:{
        GATES and_gate;
        and_gate.type = "AND";
        cout << "How many inputs would you like for this gate? (You will provide values.)  ";
        int user_input;
        cin >> user_input;
        while (cin.fail())
        {
            cout << "That input was not a viable number.\n";
            cout << "Please enter a valid number of inputs: ";
            cin >> user_input;
            cout << "\n";
        }
        cout << "Enter names for your inputs (These will be saved across gates):\n";
        string name_input = "";
        for (int i = 0; i < user_input; i++)
        {
            cout << "Input " << i << ": ";

            cin >> name_input;
            cout << "\n";
            and_gate.dependencies.push_back(name_input);
            if (names.count(name_input))
            {
                cout << "This input has already been used. Using cached value for multi-gated input.\n\n";
            }
            else
            {
                cout << "Please enter a binary string (only containing 1s and 0s) as a value for " << name_input << ": ";
                string binary_input;
                cin >> binary_input;
                cout << "\n";
                while (binary_input.find_first_not_of("01") != std::string::npos)
                {
                    cout << "Invalid binary string. Please enter a valid binary string: ";
                    cin >> binary_input;
                }
                names[name_input] = binary_input;
            }

            name_input = "";
        }

        break;
    }
    case 2:{
        GATES and_gate;
        and_gate.type = "OR";
        cout << "How many inputs would you like for this gate? (You will provide values.)  ";
        int user_input;
        cin >> user_input;
        while (cin.fail())
        {
            cout << "That input was not a viable number.\n";
            cout << "Please enter a valid number of inputs: ";
            cin >> user_input;
            cout << "\n";
        }
        cout << "Enter names for your inputs (These will be saved across gates):\n";
        string name_input = "";
        for (int i = 0; i < user_input; i++)
        {
            cout << "Input " << i << ": ";

            cin >> name_input;
            cout << "\n";
            and_gate.dependencies.push_back(name_input);
            if (names.count(name_input))
            {
                cout << "This input has already been used. Using cached value for multi-gated input.\n\n";
            }
            else
            {
                cout << "Please enter a binary string (only containing 1s and 0s) as a value for " << name_input << ": ";
                string binary_input;
                cin >> binary_input;
                cout << "\n";
                while (binary_input.find_first_not_of("01") != std::string::npos)
                {
                    cout << "Invalid binary string. Please enter a valid binary string: ";
                    cin >> binary_input;
                }
                names[name_input] = binary_input;
            }

            name_input = "";
        }

        break;
    }
    case 3:{
        GATES and_gate;
        and_gate.type = "NOT";
        cout << "This gate only takes one input.\n";
        
        cout << "Enter the name for your input (This will be saved across gates):\n";
        string name_input = "";
        for (int i = 0; i < 1; i++)
        {
            cout << "Input" << ": ";

            cin >> name_input;
            cout << "\n";
            and_gate.dependencies.push_back(name_input);
            if (names.count(name_input))
            {
                cout << "This input has already been used. Using cached value for multi-gated input.\n\n";
            }
            else
            {
                cout << "Please enter a binary string (only containing 1s and 0s) as a value for " << name_input << ": ";
                string binary_input;
                cin >> binary_input;
                cout << "\n";
                while (binary_input.find_first_not_of("01") != std::string::npos)
                {
                    cout << "Invalid binary string. Please enter a valid binary string: ";
                    cin >> binary_input;
                }
                names[name_input] = binary_input;
            }

            name_input = "";
        }

        break;
    }
    case 4:
    case 5:
    case 6:
    case 7:
    default:
        exit(0);
    }
}

#endif