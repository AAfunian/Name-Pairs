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
    void sort();
    vector<string> getNames() { return name; }
    vector<double> getAges() { return age; }
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
// Overload the << operator for use on Name_pairs objects
ostream& operator<<(ostream& os, Name_pairs n) {
    for (int i = 0; i < n.getNames().size(); ++i) {
        cout << "Name: " << n.getNames()[i] << ", Age: " << n.getAges()[i] << '\n';
    }
    return os << '\n';
}
// Overload the == operator for use on Name_pairs objects
bool operator==(Name_pairs x, Name_pairs y) {
    if (x.getNames().size() == y.getNames().size()) {
        for (int i = 0; i < x.getNames().size(); ++i) {
            if (x.getNames()[i] == y.getNames()[i] && x.getAges()[i] == y.getAges()[i]) {}
            else { 
                cout << "Not equal!\n";
                return false;
            }
        }
    }
    else {
        cout << "Not equal!\n";
        return false;
    }
    cout << "Equal!\n";
    return true;
}
// Overload the != operator for use on Name_pairs objects
bool operator!=(Name_pairs x, Name_pairs y) {
    if (x.getNames().size() == y.getNames().size()) {
        for (int i = 0; i < x.getNames().size(); ++i) {
            if (x.getNames()[i] == y.getNames()[i] && x.getAges()[i] == y.getAges()[i]) {}
            else {
                cout << "Not equal!\n";
                return true;
            }
        }
    }
    else {
        cout << "Not equal!\n";
        return true;
    }
    cout << "Equal!\n";
    return false;
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
    Name_pairs test1;
    Name_pairs test2;
    test1.read_names();
    test1.read_ages();
    test1.sort();
    test2.read_names();
    test2.read_ages();
    test2.sort();
    cout << test1 << test2;
    test1 == test2;
    test1 != test2;
    return 0;
}
