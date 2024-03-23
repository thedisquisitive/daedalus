#include "daedalus_fs.h"

using namespace std;
using namespace DAEDALUS;

int main(int argc, char** argv) {
    DaedalusFS dfs;

    // Creating files
    dfs.createFile("/folder1/file1.txt", "This is file1.txt content.");
    dfs.createFile("/folder2/file2.txt", "This is file2.txt content.");
    dfs.createFile("/folder1/subfolder/file3.txt", "This is file3.txt content.");

    // Reading files
    cout << "Contents of file1.txt: " << dfs.readFile("/folder1/file1.txt") << endl;
    cout << "Contents of file2.txt: " << dfs.readFile("/folder2/file2.txt") << endl;
    cout << "Contents of file3.txt: " << dfs.readFile("/folder1/subfolder/file3.txt") << endl;

    // Trying to read non-existent file
    cout << "Contents of non-existent file: " << dfs.readFile("/non_existent_folder/file.txt") << endl;

    return 0;
}
