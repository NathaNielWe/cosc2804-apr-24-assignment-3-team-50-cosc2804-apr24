#include <iostream>

using std::cout;
using std::endl;

void foo(int x);

int main(void) {
    
   //y comes into scope here
   int y = 7;
   cout << y << endl;

   //y comes into scope here
   int x = 1;
   cout << x << endl;
   {
      int x = 2;
      cout << x << endl;
      foo(3);
   }
   cout << x << endl;

   x = 9;
   return EXIT_SUCCESS;

   //y goes out of scope here
   //x goes out of scope here
}

void foo(int x) {
   //foo::x comes into scope here
   cout << x << endl;
   //foo::x goes out of scope here
}
