#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class DirTree {
private:
    map<string, DirTree> children;

public:
    void insert(const vector<string>& path) {
        if (path.empty()) return;
        string dir = path[0];
        vector<string> subpath(path.begin() + 1, path.end());
        children[dir].insert(subpath);
    }

    void print(int level = 0) const {
        for (const auto& child : children) {
            cout << string(level, ' ') << child.first << endl;
            child.second.print(level + 1);
        }
    }
};

vector<string> splitPath(const string& path) {
    vector<string> parts;
    stringstream ss(path);
    string part;
    
    while (getline(ss, part, '\\')) {
        parts.push_back(part);
    }
    
    return parts;
}

int main() {
    int N;
    cin >> N; // Read the number of directory paths
    cin.ignore();

    DirTree root;
    string path;

    // Read each path and insert it into the directory tree
    for (int i = 0; i < N; ++i) {
        getline(cin, path);
        vector<string> parts = splitPath(path);
        root.insert(parts);
    }

    // Print the formatted directory tree
    root.print();

    return 0;
}
