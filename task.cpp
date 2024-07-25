#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    string description;
    Task(const string& n, const string& desc) : name(n), description(desc) {}
};

void displayTasks(const vector<Task*>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]->name << ": " << tasks[i]->description << endl;
        }
    }
}

void deleteTasks(vector<Task*>& tasks) {
    for (auto& task : tasks) {
        delete task;
    }
    tasks.clear();
}

int main() {
    vector<Task*> tasks;

    int choice;
    do {
        cout << "\n===== To-Do List Manager =====" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. View tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                string name, desc;
                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, desc);
                Task* task = new Task(name, desc);
                tasks.push_back(task);
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    cout << "No tasks to remove." << endl;
                } else {
                    int index;
                    cout << "Enter task number to remove: ";
                    cin >> index;
                    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
                        delete tasks[index - 1];
                        tasks.erase(tasks.begin() + index - 1);
                        cout << "Task removed." << endl;
                    } else {
                        cout << "Invalid task number!" << endl;
                    }
                }
                break;
            }
            case 3:
                displayTasks(tasks);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }

    } while (choice != 4);

    deleteTasks(tasks);

    return 0;
}
