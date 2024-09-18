#include <iostream>
#include <initializer_list>

namespace worse{
  template <class T, size_t N>class array{
   public:
    array(std::initializer_list<T> values) {
      if (values.size() > N) {
        throw std::invalid_argument("the amount of value is more than it should be");
      }
    }
    T& at(size_t index){
      return arr[index];
    }
    T& operator[](size_t index){
      return arr[index];
    }
    T& front(){
      return arr[0];
    }
    T& back(){
      return arr[N - 1];
    }
    T* data(){
      return arr;
    }
    T fill(T n){
      for(int i = 0; i < N - 1; ++i){
        arr[i] = n;
      }
    }
   private:
    T arr[N];
  };
  template <class T, size_t N>class vector{
   public:
    vector(std::initializer_list<T> values) {
      if (values.size() > N) {
        throw std::invalid_argument("the amount of value is more than it should be");
      }
    }
    ~vector();
   private:
    T vec[];
  };
}