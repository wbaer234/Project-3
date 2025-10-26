// ItemTracker.h
//By William Baer 10/19/25

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>


//the main class used by the main program
class ItemTracker {

    //Private variable
private:
    std::map<std::string, int> itemFrequency;


//Public variables
public:
    ItemTracker();
    void LoadDataFromFile(const std::string& filename);
    int GetItemFrequency(const std::string& item);
    void PrintAllFrequencies();
    void PrintHistogram();
    void WriteBackupFile(const std::string& filename);
};

#endif