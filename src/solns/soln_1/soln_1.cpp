#include "solns/soln_1.h"

#include <iostream>

#include "common/types.h"

namespace euler {

types::SolnRetCode Soln1(const types::SolnFuncArgs& args) {
  for (const auto& arg : args) {
    std::cout << arg << std::endl;
  }
  return types::SolnRetCode::kSuccess;
}

}  // namespace euler
