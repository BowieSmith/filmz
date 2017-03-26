//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2017 __Pearson Education__. All rights reserved.

/** @file PrecondViolatedExcep.h */

#ifndef _PRECOND_VIOLATED_EXCEPT
#define _PRECOND_VIOLATED_EXCEPT

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep 
#endif
