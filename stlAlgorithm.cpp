#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

template<typename T>
void print(T t)
{
    for(const auto& e : t)
    {
        std::cout<<e<<" ";
    }
    std::cout<<std::endl;
}


//std::sort, this is implemented by introsort, which is a hybrid of
//quicksort and heapsort.
void sort_example()
{
    std::vector<int> v {2,3,4,1};
    print(v);
    sort(v.begin(),v.end());
    print(v);

    //string example
    std::cout<<"this is string example"<<std::endl;
    std::vector<std::string> v2 = {"mouse","dog","cat","ant","moth","elephant"};
    print(v2);
    sort(v2.begin(),v2.end());
    print(v2);

    //use the lamda as the sort function.
    // the order of the ant, cat and moth is not ganranteed.
    std::cout<<"this is using the lambda as the comparison parameter for the sorting"<<std::endl;
    auto sortByLength = [](const auto& a, const auto& b) {return a.size() < b.size();};
    print(v2);
    sort(v2.begin(),v2.end(),sortByLength);
    print(v2);
}

//std::binary_seach
void binary_search_example()
{
    std::vector<int> v{1,3,5,7};
    std::cout<<(std::binary_search(v.begin(),v.end(),3)?"Found" : "Not found")<<std::endl;
}

//lower_bound, (O(logn)) return the iterator to the first equal to or greater to a given value 
//in sorted sequence. 
//upper_bound is similar, it will return the iterator to the first grater to a given value.
void lower_bound_example()
{
    std::vector<int> v{1,3,3,5,7};
    auto it = lower_bound(v.begin(),v.end(),3);
    auto it2 = lower_bound(v.begin(),v.end(),4);
    auto it3 = lower_bound(v.begin(),v.end(),8);

    cout<<(it != v.end()?to_string(*it) : "Not found")<<endl;
    cout<<(it2 != v.end()?to_string(*it2) : "Not found")<<endl;
    cout<<(it3 != v.end()?to_string(*it3) : "Not found")<<endl;
    cout<<distance(v.begin(),it)<<endl;
}

//implementation of the algorithm that is first less than the given value.
template<typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first,ForwardIterator last,T value)
{
    auto it = std::lower_bound(first,last,value);
    return (it == first ? last : --it);
}

void first_less_than_example()
{
    std::vector<int> v{1,3,3,5,7};
    auto it = first_less_than(v.begin(),v.end(),3);
    auto it2 = first_less_than(v.begin(),v.end(),4);
    auto it3 = first_less_than(v.begin(),v.end(),1);

    cout<<(it != v.end()?to_string(*it) : "Not found")<<endl;
    cout<<(it2 != v.end()?to_string(*it2) : "Not found")<<endl;
    cout<<(it3 != v.end()?to_string(*it3) : "Not found")<<endl;
    
}

//std::reverse  O(n)
void reverse_example()
{
    vector<int> v{1,2,3};
    print(v);
    reverse(v.begin(),v.end());
    print(v);
}

//std::rotate O(n), this is used tp shift the elements between first and last so the middle value is now the first.
void rotate_example()
{
    vector<int> v = {1,2,3,4,5};
    print(v);
    rotate(v.begin(),v.begin() + 2, v.end());
    print(v);
}

//std::partial_sum O(n).
//std::iota,fill the range with sequentially increasing values. strating with value.
void partial_sum_example()
{
    vector<int> a(5), b(5), c(5);
    iota(a.begin(),a.end(),1);
    partial_sum(a.begin(),a.end(),b.begin());
    partial_sum(a.begin(),a.end(),c.begin(),multiplies<>());
    print(a);
    print(b);
    print(c);
}

//set_union
//set_intersection


//minmax
void minmax_example()
{
    int a = 2;
    int b = 1;
    auto p = minmax(a,b);
    cout<<"The min is:"<<p.first<<" "<<"The max is:"<<p.second<<std::endl;
}

int main()
{
    //sort_example();
    //binary_search_example();
    //lower_bound_example();
    //first_less_than_example();
    //reverse_example();
    //rotate_example();
    //partial_sum_example();
    minmax_example();
}