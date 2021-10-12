Program Strucutre:
1) File is split in smaller files to fit into the memory.
Files were split based on number of lines and not based on size to avoid trunckating the words or lines.
At the moment number of lines are hardcoded in the program as program was written in a hurry but it can be made to be based on user input in future.
2) If the system memory is lesser then please decrease the number of lines present in each file.
3) std::async is used to process these files. It is better choice than std::thread as runtime will decide to run in main or launch new thread.
Its drawback is that it does not allow main to cancel the thread.
4) C++11/14 constructs were used where ever possible.
5) To implement work stealing I explored tbb framework from Intel but did not use it due to time constraint.

Setup to run the executable:
1) Create Sample-file.txt file in D: which will have the data to be processed. 
2) Create splitfiles directory where the splitted files will be stored.
3) Output will be present in output.txt file in D:
