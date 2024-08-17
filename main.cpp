#include <filesystem>
#include <iostream>
using namespace std;
using namespace filesystem;

const path GAMES_DIRECTORY = "./games";

string strip_directory(string s) {
    int path_length = GAMES_DIRECTORY.string().length();
    return s.substr(path_length + 1, s.length() - path_length - 1);
}

int main() {
    if (exists(GAMES_DIRECTORY) && is_directory(GAMES_DIRECTORY)) {
        for (const auto& entry : directory_iterator(GAMES_DIRECTORY)) {
            cout << strip_directory(entry.path()) << endl;
        }
    } else {
        cerr << "Directory: " << GAMES_DIRECTORY << " not found." << endl;
    }
    return 0;
}
