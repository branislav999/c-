#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    string description;
    bool completed;

    Task(const string& n, const string& desc) : name(n), description(desc), completed(false) {}
};

void displayTasks(const vector<Task*>& tasks, bool showCompleted = false) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << (showCompleted ? "Completed Tasks:" : "Tasks:") << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i]->completed == showCompleted) {
                cout << i + 1 << ". " << tasks[i]->name << ": " << tasks[i]->description;
                if (showCompleted) {
                    cout << " (Completed)";
                }
                cout << endl;
            }
        }
    }
}

void markTaskCompleted(vector<Task*>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1]->completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number!" << endl;
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
        cout << "4. Mark a task as completed" << endl;
        cout << "5. View completed tasks" << endl;
        cout << "6. Exit" << endl;
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
                markTaskCompleted(tasks);
                break;
            case 5:
                displayTasks(tasks, true);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
        }

    } while (choice != 6);

    deleteTasks(tasks);

    return 0;
}
