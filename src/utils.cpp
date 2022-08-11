#include "utils.hpp"

void message(string message){
    cout <<  message << endl;
}

void error_message(string message){
    cout <<  "\n>>>>\t" << message << endl;
}

void print_line() {
    cout << "-----------------------------------------" << endl;
}


int get_input_int(string prompt){
    string input{};
    int int_val{-1};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    try{ 
        int_val = stol(input);
    }
    catch (...){}

    return int_val;
}

void clear_console() {
    system("clear");
}


string capitalize_first_letter(string text) {

	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}


string get_input_string(string prompt){
    string input{};

    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    
    return input;
}

string get_input_email(string prompt){
    string email{};
    int retry{0};

    while (retry++ < INPUT_RETRY_COUNT) {
        cout <<  prompt << " : " ;
        std::getline(std::cin, email);
        if ( is_valid_email(email) ) {
            break;
        }
        
        message("Invalid email. Please try again.");
    }

    if (INPUT_RETRY_COUNT == retry  ) {
        message("You have reached the limit of number of retires.");
        return "";
    }
        
    return email;
}

bool is_valid_email(string email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {
  
        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;
  
    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++) {
  
        // If the character is '@'
        if (email[i] == '@') {
  
            At = i;
        }
  
        // If character is '.'
        else if (email[i] == '.') {
  
            Dot = i;
        }
    }
  
    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;
  
    // If Dot is present before At
    if (At > Dot)
        return 0;
  
    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}


// Function to check the character
// is an alphabet or not
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}
  
// Function to check the character
// is an digit or not
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}