// Copyright 2021 roflanpotsan l1sZ@ya.ru

#include "header.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (argc == 2 && static_cast<string>(argv[1]) == "help") call_help();
    else if (argc != 3) call_error(1);

    const string mode(argv[1]);
    if (mode != "encryption" && mode != "decryption" || mode == "help" && argc == 3) call_error(3);

    const string fileName(argv[2]);

    string key, content;
    if (mode == "encryption") {
        request(content, "content");
        request(key, "key");
        encrypt(key, content, fileName);
    } else if (mode == "decryption") {
        request(key, "key");
        decrypt(key, fileName);
    }
    return 0;
}
