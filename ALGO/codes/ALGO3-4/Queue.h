#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "List.h"

static link head;
static link tail;

int QUEUEempty();
void QUEUEenqueue(Item item);
Item QUEUEdequeue();
