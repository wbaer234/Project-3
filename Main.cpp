// main.cpp
//By William Baer 10/19/25

#include <iostream>
#include "ItemTracker.h"

//Displayes the text of the menu
void DisplayMenu() {
    std::cout << "\n===== Corner Grocer Menu =====" << std::endl;
    std::cout << "1. Search for item frequency" << std::endl;
    std::cout << "2. Display all item frequencies" << std::endl;
    std::cout << "3. Display histogram of item frequencies" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice (1-4): ";
}


int main() {

    //creates item tracker object then loads the data into it and saves the backup file.
    ItemTracker tracker;
    tracker.LoadDataFromFile("list.txt");
    tracker.WriteBackupFile("frequency.dat");

    int choice;
    std::string itemName;


    //loop displayes menu until exit is selected. 
    while (true) {
        DisplayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter item name: ";
            std::cin >> itemName;
            std::cout << itemName << " was purchased "
                << tracker.GetItemFrequency(itemName)
                << " time(s)." << std::endl;
            break;

        case 2:
            std::cout << "\nItem Frequencies:\n";
            tracker.PrintAllFrequencies();
            break;

        case 3:
            std::cout << "\nItem Frequency Histogram:\n";
            tracker.PrintHistogram();
            break;

        case 4:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            return 0;

        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}