// Copyright 2021 roflanpotsan l1sZ@ya.ru

#ifndef HW2_HEADER_H
#define HW2_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void encrypt(const string &key, const string &content, const string &fileName);

void decrypt(const string &key, const string &fileName);

void request(string &key, const string &mode);

void call_error(const int &error_code);

bool file_exists(const string &fileName);

void call_help();

#endif //HW2_HEADER_H
