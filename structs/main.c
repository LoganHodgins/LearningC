#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

typedef struct {
  char* name;
  int leg_count;
} animal;

void set_price(struct car *c, float new_price) {

}

int main(void) {
  // ---------- direct way to create struct
  struct car saturn;
  saturn.name = "Saturn SL/2";
  saturn.price = 15000.99;
  saturn.speed = 175;

  printf("%s, %f, %d\n", saturn.name, saturn.price, saturn.speed);

  // ------------ using struct initializers
  // We can use .property=value notation initialize values in any order
  struct car toyota = {.name="Carolla", .price=160000.99, .speed=175};
  printf("%s, %f, %d\n", toyota.name, toyota.price, toyota.speed);

  // ------------ pass struct to functions
  set_price(&toyota, 177);

  // shallow copy of struct
  struct car toyota2 = toyota;

  // ------------ struct with typedef
  animal zebra = {"Zerba", 4};
  printf("%s, %d\n", zebra.name, zebra.leg_count);
}