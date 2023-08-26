#ifndef PATH_H
#define PATH_H

#include <mcpp/mcpp.h>

class Path
{
public:
    Path(int maxLength);
    ~Path();

    /*
    Adds a node to path
    Contract:
        should not add beyond maxLength
    */
   void addLocation(mcpp::Coordinate loc);

   /*
   Returns the coordinate of the last node in path and deletes it.
   Contract:
        Assumes there is nodes in path to pop 
   */
  mcpp::Coordinate popLocation(void);


private:
    mcpp::Coordinate** savePath;
    int length;
    int maxLength;
};





#endif //PATH_H