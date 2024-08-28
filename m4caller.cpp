#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
 
int main(int argc, char *argv[]) {

    if(argc<2){
        std::cout<<"Usage: m4caller <directory with *.asm files>"<<std::endl;
        return 0;
    }

    std::string path = argv[1];
    fs::path dir_path = path;
    fs::path full_dir_path = fs::absolute(dir_path); 
    if(!fs::exists(full_dir_path)){
        std::cout<<"Directory \""<< path<<"\" does not exist."<<std::endl;
        return 0;
    }

    const std::string prefix = "m4-";
    const std::string extension = ".asm";    
    std::vector<std::string> stems;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (entry.is_regular_file() && entry.path().extension() == extension) {
                std::string stem = entry.path().stem().string();
                if(stem.substr(0, prefix.size()) == prefix) continue;
                //std::cout << stem << std::endl;
                stems.push_back(stem);
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
    for(auto& s : stems){
        fs::path input_path = full_dir_path / fs::path(s + extension);
        fs::path output_path = full_dir_path / fs::path(prefix + s + extension);
        std::string command 
            = "m4 -DHAVE_CONFIG_H -D__GMP_WITHIN_GMP -DOPERATION_" + s + " \"" + input_path.string() + "\" > \"" + output_path.string() +"\"";
        std::cout << command << std::endl;
        system(command.c_str());
    }

 
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
//     char buffer[4096]={0};
//     if(argc>=2){
//         const char* fn = argv[1];
//         sprintf(buffer, "", fn, fn, fn);
//         system(buffer);
//     }

//     return 0;
// }
//	m4 -DOPERATION_$* `test -f '$<' || echo '$(srcdir)/'`$< >tmp-$*.s
//  m4 -DHAVE_CONFIG_H -D__GMP_WITHIN_GMP -DOPERATION_rsh1add_n rsh1add_n.asm >tmp-rsh1add_n.s

