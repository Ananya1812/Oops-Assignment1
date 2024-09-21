#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler
{
private:
    ofstream file;

public:
    FileHandler(string filename)
    {
        file.open(filename);
        if (!file.is_open())
        {
            cerr << "Error opening file!" << endl;
        }
    }

    void writeData(const string &data)
    {
        if (file.is_open())
        {
            file << data << endl;
        }
        else
        {
            cerr << "Cannot write to file, file is closed!" << endl;
        }
    }

    ~FileHandler()
    {
        if (file.is_open())
        {
            file.close();
            cout << "File closed successfully." << endl;
        }
    }
};

int main()
{
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename);

    FileHandler fh(filename);

    string data;
    cout << "Enter data to write to the file (type 'exit' to stop):" << endl;

    while (true)
    {
        getline(cin, data);
        if (data == "exit")
        {
            break;
        }
        fh.writeData(data);
    }

    return 0;
}
