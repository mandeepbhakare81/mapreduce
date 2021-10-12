//============================================================================
// Name        : Anton-WordCount.cpp
// Author      : Mandeep Bhakare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iterator>
#include <functional>
#include <thread>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <map>
#include <cmath>
#include <thread>
#include <future>

#include "utils.h"


using namespace std;



unordered_map<string, int> countwords(string filename)
{
	vector<string> words_v;
	unordered_map<string, int> word_count;
	readfiletomap(filename, word_count);
	return word_count;
}

void parse_file(string filename, unordered_map<string, int>& master_map)
{
	std::mutex m_mutex;
	cout<<"Launching threads"<<endl;
	std::future<unordered_map<string, int>> word_future = std::async(countwords, filename);
	unordered_map<string, int> word_map = word_future.get();

	m_mutex.lock();
	for_each(word_map.begin(), word_map.end(), [ &master_map ](std::pair<std::string, int> element)
			{
				string word = element.first;
				int count = (master_map[word])+element.second;
				master_map[word] = count;
			});
	m_mutex.unlock();
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	unordered_map<string, int> master_map;
	ostringstream ostream;
	string result;
	string command;
	//const string number_of_lines_per_file = "150000";
	const string number_of_lines_per_file = "16";

	std::string splitpath = "D:\\splitfiles\\";
	command = "split -l "+number_of_lines_per_file+" -e /d/Sample-file.txt /d/splitfiles/file_";
	result = runshellcommand(command);
	command = "ls /d/splitfiles |wc -l";
	result = runshellcommand(command);
	int res = chdir(splitpath.c_str());
	cout<<"Total number of files after split="<<result<<endl;
	std::vector<string> filenames_v = getFilesToVector();

	for(auto a: filenames_v)
	{
		parse_file(a, master_map);
		cout<<"Called parse_file for file "<<a<<endl;
	}

	std::ofstream fout("D:\\output.txt");
	for(auto a: master_map)
	{
		fout<<a.first;
		fout<<" : ";
		fout<<a.second;
		fout<<endl;
	}

	return 0;
}
