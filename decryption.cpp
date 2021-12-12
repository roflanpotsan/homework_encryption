// Copyright 2021 roflanpotsan l1sZ@ya.ru

#include "header.h"

void decrypt(const string &key, const string &fileName) {
    unsigned int encryption_key = 0;
    unsigned int l_shift = 2;
    vector<unsigned char> decrypted_data;

    for (const char x: key) {
        encryption_key += static_cast<unsigned char>(x);
    }
    srand(encryption_key);

    if (!file_exists(fileName)) call_error(2);
    ifstream in(fileName, ios::binary);
    vector<unsigned char> encrypted_data((istreambuf_iterator<char>(in)),
                                         istreambuf_iterator<char>());
    in.close();

    for (auto x: encrypted_data) {
        auto symbol = static_cast<unsigned int>(x);
        unsigned int gamma = rand();
        symbol = ((symbol >> l_shift) | (symbol << (8 - l_shift))) & 0xFF;
        unsigned int data = (symbol ^ (gamma)) & 0xFF;
        auto out_data = static_cast<unsigned char>(data);
        decrypted_data.push_back(out_data);
    }

    cout << "Decrypted data: ";
    for (unsigned char symbol: decrypted_data) cout << symbol;
}
