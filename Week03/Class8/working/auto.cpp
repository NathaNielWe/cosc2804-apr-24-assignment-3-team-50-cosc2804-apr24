
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(void) {
   auto a = -8;
   auto b = 6.8f;
   auto c = 10.0;
   auto d = &a;
   auto e = &c;
   auto f = "hello world";
   auto g = std::string("hello world");

     
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
   cout << d << endl;
   cout << e << endl;
   cout << f << endl;
   cout << g << endl;

   // cout << f + "!" << endl;
   cout << g + "!" << endl;


   auto x = 1;
   std::cout << x/2 << std::endl;

   return EXIT_SUCCESS;
}
