/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-15 11:20:53
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 11:41:04
 */
#include "precompiled_headers.h"

class SalesData{
    private:
    std::string data;
    public:
    explicit SalesData(const std::string& d):data(d){

    }

    explicit operator bool(){
        return !data.empty();
    }

    static void output(SalesData salesData){
        std::cout<<salesData.data<<std::endl;
    }
};

int main(){
    SalesData::output(static_cast<SalesData>(std::string("kask")));
    SalesData s(static_cast<SalesData>(std::string("kask")));
    if(s){
        std::cout<<std::boolalpha<<static_cast<bool>(s)<<std::endl;
    }
}

