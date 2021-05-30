//
// Created by rudri on 10/18/2020.
//

#ifndef POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H
#define POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H

#include <vector>
#include <iterator>
#include <algorithm>

#include <ranges>
#include <vector>

using namespace std;

/*
template<typename... Args>
void unpack(Args.. args){
//(v.push_back(std::forward<Args>(args)), ...);
(args = )
}
*/

template<typename Cont>
auto split_range(Cont cont, int n){
    std::vector<Cont> v;
    Cont temp;

    for(auto i : ranges::iota_view(0,n+1)){

        auto elem = ranges::take_view(ranges::drop_view(cont,i*n),n);
        temp = Cont(elem.begin(),elem.end());
        v.push_back(temp);
        
    }
    return v;
}

#endif //POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H
