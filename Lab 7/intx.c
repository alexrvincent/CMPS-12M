/* $Id: intx.c,v 1.4 2012-11-01 19:33:32-07 - - $ */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intx.h"

//static char *intx_tag = "struct intx";

struct intx {
   //char *tag;
   int value;
};

intx *new_intx (void) {
   return new_int_intx (0);
}

intx *new_int_intx (int value) {
   intx *this = malloc (sizeof (struct intx));
   assert (this != NULL);
   //new->tag = intx_tag;
   this->value = value;
   return this;
}

void free_intx (intx *this) {
   //assert (is_intx (this));
   //memset(this, 0, sizeof (struct intx));
   free (this);
}

int get_intx (intx *this) {
   //assert (is_intx (this));
   return this->value;
}

void put_intx (intx *this, int newvalue) {
   //assert (is_intx (this));
   this->value = newvalue;
}

//bool is_intx (intx_ref this) {
  // return this != NULL && this->tag == intx_tag;
//}
