#ifndef PATH_H
#define PATH_H

#include <mcpp/mcpp.h>
#include <vector>

class Path
{
public:
    Path();
    ~Path();

    /*
    Adds a node to path
    Contract:
        should not add beyond maxLength
    */
   void pushCoordinate(mcpp::Coordinate loc);

   /*
   return the current length of the path
   */
   int getLength(void);


   /*
   Returns the coordinate of the last node in path and deletes it.
   Contract:
        Assumes there is nodes in path to pop 
   */
  mcpp::Coordinate popCoordinate(void);

    /*
    Print the path to os stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Path& p);

private:
    //mcpp::Coordinate** savePath;
    std::vector<mcpp::Coordinate*> savePath;
    // int length;
    // int maxLength;
};





#endif //PATH_H