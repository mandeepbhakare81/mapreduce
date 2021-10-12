/*
 * utils.cpp
 *
 *  Created on: 11-Oct-2021
 *      Author: Mandeep Bhakare
 */

#include "utils.h"
#include <dirent.h>

using namespace std;
string runshellcommand(string command)
{
	char buffer[4112];
	string result;
	command.append(" 2>&1");
	FILE* pipe = popen(command.c_str(), "r");
	if(!pipe) throw std::runtime_error("");
	try{
		while(!feof(pipe))
			if(fgets(buffer, 4112, pipe) != NULL) result.append(buffer);
	}catch(...)
	{
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}





std::vector<std::string> getFilesToVector()
{
	cout<<"In getFilesToVector"<<endl;
	const char* path = "D:\\splitfiles";
    std::vector<std::string> files;
    struct dirent *entry;
	DIR *dir = opendir(path);

	if (dir == NULL)
	{
		cout<<"dir==null"<<endl;
	  return files;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		files.push_back(entry->d_name);
	}
	closedir(dir);

	return files;
}


void readfiletomap(string filename, unordered_map<string, int>& word_count)
{
	vector<string> word_v;
    // Define the filestream object used to read data from file
    ifstream fin(filename);

    // Get input stream and end of stream iterators
    istream_iterator<string> fin_it(fin);
    istream_iterator<string> eos;

    // Get output stream iterators
    ostream_iterator<string> cout_it(cout, " ");

    // Copy elements from input to vector using copy function
    copy(fin_it, eos, back_inserter(word_v));
    for_each(word_v.begin(), word_v.end(), [&](string s){
    	int i = word_count[s];
    	word_count[s]= ++i;

    });

    // Sort the vector
    sort(word_v.begin(), word_v.end());

}




