module;
#include <stdexcept>

export module my_module;

//import <iostream>;


namespace my_ns {
    export template<typename T>
    class Vector final {
    public:
        Vector() {
            mpMemory = new T[mMaxSize];
        }

        void push_back(T value) {
            if (mSize > mMaxSize) {
                resize_memory();
            }
            mpMemory[mSize] = value;
            mSize++;
        }

        T get(int position) {
            if (position < mSize) {
                return mpMemory[position];
            } else {
                throw std::out_of_range("Index must be smaller than vector size.");
            }
        }

    private:
        int mSize = 0;
        int mMaxSize = 1024;
        T* mpMemory;

        void resize_memory() {
            auto oldMaxSize = mMaxSize;
            mMaxSize *= 2;
            auto pOldMemory = mpMemory;

            mpMemory = new T[mMaxSize];
            for (int i = 0; i < oldMaxSize; i++) {
                mpMemory[i] = std::move(pOldMemory[i]);
            }

            delete[] pOldMemory;
        }
    };
}