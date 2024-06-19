#include "solns/soln_22.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <string>

#include "common/types.h"

namespace euler {

types::SolnFuncRet Soln22(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  std::ifstream fhandle(args[0].data());
  std::string line;
  std::vector<std::string> names;
  while (std::getline(fhandle, line)) {
    names.push_back(line);
  }

  std::sort(names.begin(), names.end());

  int64_t score = 0;
  for (std::size_t i = 0; i < names.size(); ++i) {
    score += (i + 1) * std::accumulate(names[i].cbegin(), names[i].cend(), 0ULL,
                                       [](int64_t acc, char c) {
                                         return (acc + (c - 'A' + 1));
                                       });
  }

  return score;
}

}  // namespace euler
