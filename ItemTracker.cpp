// ItemTracker.cpp
//By William Baer 10/19/25

#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

//Initiates the tracker object
ItemTracker::ItemTracker() {}

//Validates file input
void ItemTracker::LoadDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string item;
    if (inputFile.is_open()) {
        while (inputFile >> item) {
            ++itemFrequency[item];
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open input file: " << filename << std::endl;
    }
}


int ItemTracker::GetItemFrequency(const std::string& item) {
    if (itemFrequency.count(item)) {
        return itemFrequency[item];
    }
    return 0;
}

void ItemTracker::PrintAllFrequencies() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

//prints the histogram format 
void ItemTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(15) << std::left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

//Writes the file to back up all data
void ItemTracker::WriteBackupFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        outFile.close();
    }
    else {
        std::cerr << "Unable to write backup file: " << filename << std::endl;
    }
}