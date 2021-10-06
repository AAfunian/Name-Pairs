#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to hold desired amount of names and corresponding ages
class Name_pairs {
private:
    vector<string> name;
    vector<double> age;
public:
    void read_names();
    void read_ages();
    void print();
    void sort();
};
// Read names through input stream
void Name_pairs::read_names() {
    string temp;
    cout << "Enter names separated by space (0 to exit): ";
    bool run = true;
    bool last = true;
    string final;
    while (run == true) {
        cin >> temp;
        for (char x : temp) {
            if (x == '0') { 
                run = false;
            }
        }
        if (run == false) {
            if (temp[0] == '0') last = false;
            else {
                for (char x : temp) {
                    if (x != '0') final.push_back(x);
                }
                temp = final;
            }
        }
        if (last) name.push_back(temp);
        temp = "";
    }
}
// Read ages through input stream
void Name_pairs::read_ages() {
    double temp;
    for (int i = 0; i < name.size(); ++i) {
        cout << "Enter the age of " << name[i] << ": ";
        cin >> temp;
        age.push_back(temp);
    }
}
// Print a name the corresponding age per line
void Name_pairs::print() {
    for (int i = 0; i < name.size(); ++i) {
        cout << "Name: " << name[i] << ", Age: " << age[i] << '\n';
    }
}
// Sort name vector alphabetically (assumes correct name case)
void Name_pairs::sort() {
    string temp;
    double temp_age;
    for (int i = 0; i < name.size(); ++i) {
        for (int j = 0; j < name.size(); j++) {
            if (name[i].compare(name[j]) < 0) {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
                // Rearrange ages in tandem with sorted names
                temp_age = age[i];
                age[i] = age[j];
                age[j] = temp_age;
            }
        }
    }
}

int main()
{
    Name_pairs test;
    test.read_names();
    test.read_ages();
    test.sort();
    test.print();
}
