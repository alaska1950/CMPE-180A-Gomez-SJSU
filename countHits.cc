//Time Complexity: O(n)
//Space Complecity: O(n)

#include <iostream>
#include <vector>
#include "countHits.h"
using namespace std;

int countHits (vector<Asteroid> a)
{
  vector<int> vec;
  for (int x = 0; x < a.size (); x++)
    {
      if (a.at (x).d == 1)
        {
          vec.push_back (a.at (x).m);
        }
      else
        {
          if (vec.size () == 0)
            {
              continue;
            }
          int last_astr = vec.at (vec.size () - 1);
          while ((last_astr <= a.at (x).m) && vec.size () != 0)
            {
              if ((last_astr == a.at (x).m) && vec.size () != 0)
                {
                  vec.erase (vec.begin () + vec.size () - 1);
                  break;
                }
              else
                {
                  vec.erase (vec.begin () + vec.size () - 1);
                }
              last_astr = vec.size () > 0 ? vec.at (vec.size () - 1)
                                          : (a.at (x).m) + 1;
            }
        }
    }
  return vec.size ();
}
