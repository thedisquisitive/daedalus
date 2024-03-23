#include "daedalus_fs.h"

namespace DAEDALUS
{
    void DaedalusFS::createFile(const string& path, const string& content) {
        vector<string> parts = splitPath(path);
        DaedalusDirectory* currDir = &root;
        for (size_t i = 0; i < parts.size() - 1; ++i) {
            if (currDir->directories.find(parts[i]) == currDir->directories.end()) {
                currDir->directories.emplace(parts[i], DaedalusDirectory());
            }
            currDir = &currDir->directories.at(parts[i]);
        }
        currDir->files.emplace(parts.back(), DaedalusFile{ content });
    }

    // Function to read the content of a file at a given path
    string DaedalusFS::readFile(const string& path) {
        vector<string> parts = splitPath(path);
        DaedalusDirectory* currDir = &root;
        for (const string& part : parts) {
            auto it = currDir->directories.find(part);
            if (it == currDir->directories.end()) {
                auto fileIt = currDir->files.find(part);
                if (fileIt != currDir->files.end()) {
                    return fileIt->second.content;
                }
                else {
                    return "File not found!";
                }
            }
            currDir = &it->second;
        }
        return "File not found!";
    }

    // Function to split a path into directory parts
    vector<string> DaedalusFS::splitPath(const string& path) {
        vector<string> parts;
        string part;
        for (char c : path) {
            if (c == '/') {
                if (!part.empty()) {
                    parts.push_back(part);
                    part.clear();
                }
            }
            else {
                part += c;
            }
        }
        if (!part.empty()) {
            parts.push_back(part);
        }
        return parts;
    }
}