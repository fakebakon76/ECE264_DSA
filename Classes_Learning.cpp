#include<iostream>
using namespace std;

class IntCell {
    public:
        explicit IntCell( int initial_value = 0 ): 
            stored_value(initial_value){}
        int read() const{ 
            return stored_value;
        }
        void write( int x ) {
            stored_value = x;
        }

    private:
        int stored_value;
};

int main() {
    IntCell obj;
    obj = 37;

    cout << obj.read() << "\n";
}
