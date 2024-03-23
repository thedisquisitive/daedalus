#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

namespace DAEDALUS
{
    // Define a structure to represent a file
    struct DaedalusFile {
        string content;
    };

    // Define a structure to represent a directory
    struct DaedalusDirectory {
        unordered_map<string, DaedalusFile> files;
        unordered_map<string, DaedalusDirectory> directories;
    };

    // Define the virtual file system class
    class DaedalusFS {
    private:
        DaedalusDirectory root; // Root directory of the filesystem

    public:
        // Function to create a file at a given path
        void createFile(const string& path, const string& content);

        // Function to read the content of a file at a given path
        string readFile(const string& path);

    private:
        // Function to split a path into directory parts
        vector<string> splitPath(const string& path);
    };
}
