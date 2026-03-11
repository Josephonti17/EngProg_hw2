// Problem 4 
// Homework 2

// Why std::list instead of std::vector:
//
//   We need to keep an iterator pointing to the current task while we
//   insert and remove other tasks around it. std::list is a doubly-linked
//   list, so inserting or erasing nodes doesn't mess with any other
//   iterators — only the one pointing to the erased node gets invalidated.
//
//   If we used std::vector, inserting or erasing could trigger a reallocation
//   of the whole array, which would invalidate every iterator we're holding.
//   That would break our current-task pointer, so list is the safer choice.
//
// Iterator behavior with list insert/erase:
//
//   - Insert: all existing iterators stay valid since we're just linking
//     in a new node without moving anything else around.
//   - Erase: only the iterator to the deleted node is invalidated.
//     erase() returns an iterator to the next element so we can keep going.

#include <iostream>
#include <list>
#include <string>


void printTaskList(const std::list<std::string>& tasks) {
    // Print the entire task list
    std::cout << "Task list: [ ";
    for (const auto& t : tasks) {
        std::cout << "\"" << t << "\" ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::list<std::string> tasks;

    // Add 3 tasks to the list
    tasks.push_back("Init_Sensors");
    tasks.push_back("Read_GPS");
    tasks.push_back("Transmit_Data");

    std::cout << "After adding 3 tasks:" << std::endl;
    printTaskList(tasks);

    // Set current to the first task
    auto current = tasks.begin();
    std::cout << "\nCurrent task: \"" << *current << "\"" << std::endl;

    // Insert a new task AFTER current
    // std::list::insert inserts BEFORE the given iterator, so we advance
    // by one to insert after current.
    auto afterCurrent = std::next(current);
    tasks.insert(afterCurrent, "Calibrate_IMU");

    std::cout << "\nAfter inserting \"Calibrate_IMU\" after current:" << std::endl;
    printTaskList(tasks);
    std::cout << "Current task is still valid: \"" << *current << "\"" << std::endl;

    // Erase the current task
    // std::list::erase invalidates ONLY the erased iterator and returns
    // an iterator to the next element.
    current = tasks.erase(current);

    std::cout << "\nAfter erasing the current task (\"Init_Sensors\"):" << std::endl;
    printTaskList(tasks);
    std::cout << "current now points to: \"" << *current << "\"" << std::endl;

    // Advance to the next task
    ++current;
    std::cout << "\nAfter advancing current:" << std::endl;

    // Print the entire task list and the current task
    printTaskList(tasks);
    std::cout << "Current task: \"" << *current << "\"" << std::endl;

    return 0;
}
