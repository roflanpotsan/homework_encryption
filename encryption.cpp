// Copyright 2021 roflanpotsan l1sZ@ya.ru

#include "header.h"

void encrypt(const string &key, const string &content, const string &fileName) {
    unsigned long encryption_key = 0;
    unsigned int l_shift = 2;
    size_t c_size = content.size();
    vector<unsigned char> bytes;

    for (size_t i = 0; i < c_size; i++) {
        bytes.push_back(static_cast<unsigned char>(content[i]));
    }

    for (const char x: key) {
        encryption_key += static_cast<unsigned char>(x);
    }
    srand(encryption_key);

    if (!file_exists(fileName)) cout << "New file has been created.\n";

    ofstream out(fileName, ios::binary);
    for (unsigned char x: bytes) {
        unsigned int gamma = rand();
        unsigned int gamma_data = (static_cast<unsigned int>(x) ^ (gamma)) & 0xFF;
        unsigned int shifted_data = ((gamma_data << l_shift) |
                                     (gamma_data >> (8 - l_shift))) & 0xFF;
        auto encrypted_data = static_cast<unsigned char>(shifted_data);
        out << encrypted_data;
    }
    out.close();

    cout << "Data has been encrypted successfully.\n";
}
