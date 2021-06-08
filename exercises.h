//
// Created by rudri on 10/18/2020.
//

#ifndef POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H
#define POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H

#include <vector>
#include <iterator>
#include <algorithm>

//#include <ranges>
#include <utility>
#include <forward_list> 

#include <initializer_list>
		

using namespace std;

template <typename Container>
void repeat(Container& container,std::size_t n){
  std::vector<typename Container::value_type> temp(container.begin(),container.end());
  for (std::size_t i = 0; i < n; i++)
  {
    container.insert(container.end(),temp.begin(),temp.end());
  }
}

template <typename T>
void repeat(forward_list<T>& container,std::size_t n){
    std::vector<T> temp(container.begin(),container.end());
    auto index = container.begin();
    
    for (std::size_t i = 0; i < n; i++){
        container.insert_after(index,temp.begin(),temp.end());
        index++;
    }
}

template<typename T>
auto sum_range(const T &conta, const T &contb){
    T cont1 = conta;
    T cont2 = contb;

    const auto tamannno1 = distance(cont1.begin(),cont2.end());
    const auto tamanno2 = distance(cont2.begin(),cont2.begin());
    int max = 0;

    if(tamannno1 > tamanno2){
        repeat(cont2,tamannno1);
    }
    else if(tamanno2 > tamannno1) {
        repeat(cont1,tamanno2);
    }


    using inner = T::value_type;
    vector<inner> result;

    for(auto elem : cont1 ){
        result.push_back(elem);    
    }
    
    int cont = 0;
    for(auto elem : cont2 ){
        result.at(cont) = result.at(cont) + elem;
        cont++;
    }
    
    return result;
}

/*
// me ayudo zero9178#6333
template <typename Cont>
auto split_range(Cont& cont,int n) {
    return std::ranges::views::iota(0)
         | std::ranges::views::take_while([end = cont.size()](std::size_t index) {
             return index * 3 < end;
         })
         | std::ranges::views::transform([&cont,n](std::size_t index) {
             return std::ranges::drop_view(cont,index * n) | std::ranges::views::take(n);
         });
}
*/

template<typename Cont, typename T>
vector<T> delete_range(Cont cont, initializer_list<T> ini){
    vector<T> result;
    
    for(auto elem : cont){
        if(count(ini.begin(),ini.end(),elem) == 0){
            result.push_back(elem);    
        }
    }
    return result;
}

template<typename Cont, typename T>
vector<T> delete_range(Cont cont, T excl){
    return delete_range(cont, {excl});
}

template<typename Cont>
auto delete_duplicated(Cont cont){
    using T = Cont::value_type;
    vector<T> result;
    
    for(auto elem : cont){
        if(count(result.begin(),result.end(),elem) == 0){
            result.push_back(elem);    
        }
    }
    return result;
}

template<typename Cont, typename ...Args> //(, ...)
auto zip(Args ...args){
   int sizez; 

    using T = Cont::value_type;

    vector<vector<T>> result;
    sizez = cont.size();
    
    for(int i = 0; i < sizez; i++){
    vector<T> temp;
        temp.push_back(cont.at(i))
        (temp.push_back(args.at(i)), ...);

        result.push_back(temp);
    }
     
    return result;
}


#endif //POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H
