// Copyright 2021 roflanpotsan l1sZ@ya.ru

#include "header.h"

void request(string &line, const string &mode) {
    if (mode == "key") cout << "Enter key: ";
    else if (mode == "content") cout << "Enter text: ";
    getline(cin, line);
}

void call_error(const int &error_code) {
    if (error_code == 1)
        cerr << "Error: Use two parameters: 'mode' and 'filename'; Use 'help' as a solo parameter for more info.\n";
    if (error_code == 2) cerr << "Error: could not open the file.\n";
    if (error_code == 3) cerr << "Error: wrong parameters; Use 'help' as a solo parameter for more info.\n";
    exit(error_code);
}

void call_help() {
    cout << "Usage: encrypt and decrypt text you enter; Encrypted text is saved to a specified file.\n"
         << "Parameters: 'mode', 'filename'.\n" << "Modes: 'help', 'encryption', 'decryption'.\n";
    exit(4);
}

bool file_exists(const string &fileName) {
    ifstream in(fileName);
    return in.good();
}
