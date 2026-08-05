#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

bool u_map(){
    std::unordered_map<std::string, int> map;
    map["Abdul"] = 100;
    map["Badal"]= 200;

    if(map.contains("Abdul")){
        std::cout<<"Abdul exists."<<std::endl;
    }else{
        std::cout<<"Find abdulllll...";
    }
    //Printing everyone...
    std::cout<<"Printing everyone...";

    for (const auto& [key, value] : map){
        std::cout<<key<<" => " << value<< std::endl;
    }
    return true;
}
