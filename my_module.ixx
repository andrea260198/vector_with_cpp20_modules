//module;
//#include <iostream>

export module my_module;

//import <iostream>;


namespace my_ns {
    export template<typename T>
    class Vector final {
    public:
        Vector() {
            memory_p = new T[max_size];
        }

        void push_back(T value) {
            memory_p[size] = value;
            size++;
        }

        T get(int position) {
            return memory_p[position];
        }

    private:
        int size = 0;
        int max_size = 1024;
        T* memory_p;
    };
}