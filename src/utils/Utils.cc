#include "Utils.h"
#include "Error.h"
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void Utils::collectDirectoryContent(string sourceType, string dirName){
    if (sourceType == "-c")
    {
        Utils::collectCppDirectoryContent(dirName);
    }else if (sourceType == "-r")
    {
        Utils::collectRustDirectoryContent(dirName);
    }else
    {
        Utils::collectJavaDirectoryContent(dirName);
    }
}


void Utils::findContent(string dirName, string fileName){
    fs::path p = Utils::findAFile(dirName, fileName); 
    cout << "p = " << p << "\n";
}

vector<string> Utils::collectCppDirectoryContent(string dirName){
    vector<string> cppFileExt = {".cpp", ".cc", ".h", ".hpp"};
    vector<string> dirs;
    string s;

    for(fs::path p: fs::recursive_directory_iterator(dirName)){
        //auto it = std::find(cppFileExt.begin(), cppFileExt.end(), p.extension()) != cppFileExt.end();
        //cout << p << "\n";
        if(!fs::is_empty(p) && fs::is_regular_file(p)){
            if ((p.extension() == ".cc") || (p.extension() == ".cpp") || (p.extension() == ".hpp") || (p.extension() == ".h"))
            {
                //std::ifstream pa(p);
                if (p.filename() == "fpdfview.h")
                {
                    cout << p << "\n";
                }
                
                
                
                /*
                if(!pa.is_open()){
                    cout << "enable to open the file";
                }
                cout << "enable to open the file";
                while (std::getline(pa, s))
                {
                    cout << s << "\n";
                }
                */
            }
        }
    }
    return dirs;
}


fs::path Utils::findAFile(string dirName, string fileName){
   
    fs::path p2;
    for(fs::path p: fs::recursive_directory_iterator(dirName)){
        if(!fs::is_empty(p) && fs::is_regular_file(p)){
            if ((p.extension() == ".cc") || (p.extension() == ".cpp") || (p.extension() == ".hpp") || (p.extension() == ".h"))
            {
                //std::ifstream pa(p);
                if (p.filename() == fileName)
                {
                    p2 = p;
                    return p2;
                }
            }
        }
    }
    return p2;
}



vector<string> Utils::collectRustDirectoryContent(string dirName){
    vector<string> dirs;
    return dirs;
}



vector<string> Utils::collectJavaDirectoryContent(string dirName){
    vector<string> dirs;
    return dirs;
}


void Utils::usage(){
    cout << "usage vulnpattern [OPTION] directory" << "\n";
    cout << "Options available :" << "\n";
    cout << "\t\t-c : for c and c++ source code\n\t\t-r : for rust source code\n\t\t-j : for java source code\n\t\t-f : for find a file" << "\n";
}




