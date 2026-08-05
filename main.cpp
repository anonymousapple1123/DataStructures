#include "hash_maps/unordered_map.hpp"
#include <iostream>

int main(){
    if(u_map()){
        std::cout<<"Map function called... "<<std::endl;
    }else{
        std::cout<<"ERROR : Map function returned false "<<std::endl;
    }
    return 0;
}
