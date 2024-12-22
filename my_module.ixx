module;
#include <stdexcept>

export module my_module;


import std;


namespace my_ns {
    export template<typename T>
    class Vector final {
    public:
        Vector() {
            mpMemory = new T[mMaxSize];
        }

        void push_back(T value) {
            if (mSize >= mMaxSize) {
                resize_memory(2 * mMaxSize);
            }
            mpMemory[mSize] = value;
            mSize++;
        }

        T get(unsigned int position) {
            if (position < mSize) {
                return mpMemory[position];
            } else {
                throw std::out_of_range("Index must be smaller than vector size.");
            }
        }

    private:
        int mSize = 0;
        int mMaxSize = 2;
        T* mpMemory;

        void resize_memory(int newMemorySize) {
            std::cout << "Vector memory has been resized.\n";
            auto oldMaxSize = mMaxSize;
            mMaxSize = newMemorySize;
            auto pOldMemory = mpMemory;

            mpMemory = new T[mMaxSize];
            for (int i = 0; i < oldMaxSize; i++) {
                mpMemory[i] = std::move(pOldMemory[i]);
            }

            delete[] pOldMemory;
        }
    };
}