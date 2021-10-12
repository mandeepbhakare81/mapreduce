/*
 * utils.h
 *
 *  Created on: 11-Oct-2021
 *      Author: Mandeep Bhakare
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include<mutex>



using namespace std;

#ifndef UTILS_H_
#define UTILS_H_

string runshellcommand(string command);

std::vector<std::string> getFilesToVector();
void readfiletomap(string filename, unordered_map<string, int>& word_count);

#endif /* UTILS_H_ */
