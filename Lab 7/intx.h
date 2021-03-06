// $Id: intx.h,v 1.6 2013-05-01 13:15:50-07 - - $ //

#ifndef __INTX_H__
#define __INTX_H__

#include <stdbool.h>

// NAME
//    intx ADT
//
// DESCRIPTION
//    A simple ADT that permits the holding of an integer in a box
//    similar to the way Java uses an `Integer' to box an `int'.

typedef struct intx intx;
   // Incomplete type defined in implementation file.

intx *new_intx (void);
   // Constructor: create a new `intx' box initialized to 0.
   // Postcond:    new intx box is returned.

intx *new_int_intx (int value);
   // Constructor: create a new `intx' box initialized by caller.
   // Postcond:    new intx box is returned.

void free_intx (intx *this);
   // Destructor: destroys an allocated box
   // Precond:    box created by new_intx/1.
   // Postcond:   this pointer is dangling.

int get_intx (intx *this);
   // Accessor:   retrieves the integer from the box.
   // Precond:    valid handle to an intx.
   // Postcond:   returns the value in the box.

void put_intx (intx *this, int newvalue);
   // Mutator:    replaces the integer in the box with a new one.
   // Precond:    valid handle to an intx.
   // Postcond:   old value is lost, new value is kept

#endif