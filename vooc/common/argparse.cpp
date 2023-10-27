#include "errhandler.h"
#include <string>
#include <vector>
#include <sstream>

bool argc_parse(int argc) { 
    // Check for errors in cli usage
    if(argc<2) {
        missing_arg();
        return false;
    }

    return true;
}

std::string join_vec(const std::vector<std::string>& elements, const std::string& separator) {
    std::ostringstream result;
    
    if (!elements.empty()) {
        result << elements[0];
        for (size_t i = 1; i < elements.size(); ++i) {
            result << separator << elements[i];
        }
    }
    
    return result.str();
}
