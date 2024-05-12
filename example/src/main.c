#include <stdio.h>
#include "my_math.h"

int
main(void)
{
  printf("Hello World, lets do some math!\n");

  int result = 0;
  int x = 12;
  int y = 6;

  result = add_integers(x, y);
  printf("%d + %d = %d\n", x, y, result);

  result = subtract_integers(x, y);
  printf("%d - %d = %d\n", x, y, result);

  return 0;
}
