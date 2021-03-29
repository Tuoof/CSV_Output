#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CSV
{
private:
    string name;
    string file;
    string line;
    vector<string> data;
    vector<string> row;

public:
    void inputFile();
    void outputFile();
    void cloneFile();
};

void CSV::inputFile()
{
    ifstream inputFile;
    inputFile.open("daftar-nama.txt");

    if (!inputFile)
    {
        cout << "File not opened!";
        exit(1);
    }

    while (!inputFile.eof())
    {
        getline(inputFile, file);
        data.push_back(file);
    }

    for (int i = 0; i < data.size(); i++)
    {
        stringstream ss(data[i]);
        
        while (getline(ss, line))
        {
            replace(line.begin(), line.end(), ' ', ',');
            replace(line.begin(), line.end(), '\t', ',');
            row.push_back(line);
        }
    }
    inputFile.close();

    cout << data[0] << " \t" << endl << data[1] << " \t" << endl;
    for (int i = 2; i < data.size(); i++)
    {
        cout << row[i] << endl;
    }
}

void CSV::outputFile()
{
    string inputFile("daftar-nama.csv");
    fstream saveFile;
    saveFile.open(inputFile, ios::out);

    for (int i = 0; i < data.size(); i++)
    {
        saveFile << row[i] << endl;
    }

    saveFile.close();
}

void CSV::cloneFile()
{
    string inputFile("4210191022_Andika-Rizky.csv");
    fstream saveFile;
    saveFile.open(inputFile, ios::out);

    for (int i = 0; i < data.size(); i++)
    {
        saveFile << row[i] << endl;
    }
    for (int i = data.size() -1; i > 1; i--)
    {
        saveFile << row[i] << endl;
    }

    saveFile.close();
}

int main()
{
    CSV dNama;
    dNama.inputFile();
    dNama.outputFile();
    dNama.cloneFile();

    return 0;
}