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
//all gates in a circuit
map<string, vector<GATES>> circuit;
//names of gates keys, with gates as values.
map<string, GATES> memory;
//input_names keys with binary string values
map<string, string> names;
void parser()
{
    while (true)
    {
        GATES and_gate;
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
        case 1:
        {

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
        case 2:
        {

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
        case 3:
        {

            and_gate.type = "NOT";
            cout << "This gate only takes one input.\n";

            cout << "Enter the name for your input (This will be saved across gates):\n";
            string name_input = "";
            for (int i = 0; i < 1; i++)
            {
                cout << "Input"
                     << ": ";

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
        {

            and_gate.type = "NAND";
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
        case 5:
        {

            and_gate.type = "NOR";
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
        case 6:
        {

            and_gate.type = "XOR";
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
        case 7:
        {

            and_gate.type = "EXOR";
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
        default:
        {
            exit(0);
        }
        }
        string gate_name;
        cout << "Please name your gate, so as to easily use it in a circuit.\nGate name: ";
        cin >> gate_name;

        while (memory.count(gate_name))
        {
            cout << "\n";
            cout << "This name was already used by an '" << memory[gate_name].type << "' type gate. Please choose a different one.\nGate name: ";
            cin >> gate_name;
        }
        memory[gate_name] = and_gate;
        char continue_or_break;
        cout << "\nWould you like to add another gate? ([y]/[n]) ";
        cin >> continue_or_break;
        while (cin.fail() || (tolower(continue_or_break) != 'y' && tolower(continue_or_break) != 'n'))
        {
            cout << "\nThat was an invalid option. Please choose [y]/[n].\n";
            cout << "\nWould you like to add another gate? ([y]/[n]) ";
        }
        if (continue_or_break == 'y')
        {
            continue;
        }
        else
        {
            return;
        }
    }
}
void connector()
{
    cout << "Would you like to edit a premade circuit (1), or would you like to make a new circuit (2)? ";
    int user_circuit_choice;
    cin >> user_circuit_choice;
    while (cin.fail() || user_circuit_choice < 1 || user_circuit_choice > 2)
    {
        cout << "That input was invalid. Please enter a valid choice.\n";
        cout << "Would you like to edit a premade circuit (1), or would you like to make a new circuit (2)? ";
        cin >> user_circuit_choice;
    }
    cout << "\n";
    if (user_circuit_choice == 1)
    {
        for (auto p : circuit)
        {
            cout << "Circuit '" << p.first << "' with:\n";
            vector<int> num_gates(7, 0);
            for (auto itr : p.second)
            {
                if (itr.type == "AND")
                    num_gates[0]++;
                else if (itr.type == "OR")
                    num_gates[1]++;
                else if (itr.type == "NOT")
                    num_gates[2]++;
                else if (itr.type == "NAND")
                    num_gates[3]++;
                else if (itr.type == "NOR")
                    num_gates[4]++;
                else if (itr.type == "XOR")
                    num_gates[5]++;
                else if (itr.type == "XNOR")
                    num_gates[6]++;
            }
            for (int i = 0; i < 7; i++)
            {
                switch (i)
                {
                case 0:
                {
                    cout << "\t\t" << num_gates[i] << " AND gates\n";
                    break;
                }
                case 1:
                {
                    cout << "\t\t" << num_gates[i] << " OR gates\n";
                    break;
                }
                case 2:
                {
                    cout << "\t\t" << num_gates[i] << " NOT gates\n";
                    break;
                }
                case 3:
                {
                    cout << "\t\t" << num_gates[i] << " NAND gates\n";
                    break;
                }
                case 4:
                {
                    cout << "\t\t" << num_gates[i] << " NOR gates\n";
                    break;
                }
                case 5:
                {
                    cout << "\t\t" << num_gates[i] << " XOR gates\n";
                    break;
                }
                case 6:
                {
                    cout << "\t\t" << num_gates[i] << " XNOR gates\n";
                    break;
                }
                }
            }
            cout << "\n\n\n";
        }
        cout << "Please give your decision as to which circuit you wish to edit by typing its name.";
        string user_choice;
        cin >> user_choice;
        cout << "\n";
        while (!circuit.count(user_choice))
        {
            cout << "Invalid choice. Please choose a circuit from the listed choices.\n";
            cout << "Please give your decision as to which circuit you wish to edit by typing its name.";
            cin >> user_choice;
        }

        vector<GATES> current_circuit = circuit[user_choice];
        cout << "\nWhich gate would you like to work with? ";
        string gate_input;
        cin >> gate_input;
        //this will edit gates
        
    }
    else
    {
    }
}
#endif