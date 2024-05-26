#include <iostream>

#include "common/types.h"
#include "soln_factory/soln_factory.h"

int main() {
  euler::types::SolnId id = 1;
  auto f = euler::sfactory::GetSoln(id);
  if (f) {
    (*f)({"hello", "world"});
  } else {
    std::cerr << "unknown solution id" << std::endl;
  }
  return 0;
}
