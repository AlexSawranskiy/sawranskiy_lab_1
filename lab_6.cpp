#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

// Global variable
string global_variable = "Some Global Value";

class Train 
{
public:
    static int instance_count; // A static field for counting the number of instances
    string name; // Field attribute "object name"

    Train(const string& name) : name(name) 
    {
        instance_count++;
    }
};

int Train::instance_count = 0;

class Logger 
{
private:
    vector<string> log;
    static Logger* instance;

    Logger() {}

public:
    static Logger* getInstance() 
    {
        if (instance == nullptr) 
        {
            instance = new Logger();
        }
        return instance;
    }

    void addRecord(const string& record) 
    {
        log.push_back(record);
    }

    void saveLog() {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        string filename = "log.txt";

        ofstream log_file(filename, ios::app);
        if (log_file.is_open()) 
        {
            for (const auto& record : log) 
            {
                log_file << record << endl;
            }
            log_file.close();
        }
        else 
        {
            cerr << "Unable to open log file!" << endl;
        }
    }
};

Logger* Logger::instance = nullptr;

int main() 
{
    // Creating objects of the Train class
    Train train1("Train1");
    Train train2("Train2");

    // Logging of object creation
    Logger::getInstance()->addRecord("Train created: " + train1.name + ", Total instances: " + std::to_string(Train::instance_count));
    Logger::getInstance()->addRecord("Train created: " + train2.name + ", Total instances: " + std::to_string(Train::instance_count));

    // Logging the value of a global variable
    Logger::getInstance()->addRecord("Global variable value: " + global_variable);

    // Saving logs to a file
    Logger::getInstance()->saveLog();

    return 0;
}
