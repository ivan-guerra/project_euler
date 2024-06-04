#include "solns/soln_18.h"

#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "common/types.h"

namespace euler {

using Level = std::vector<int>;
using Triangle = std::vector<Level>;

static Triangle LoadTriangle(const std::string_view filename) {
  std::ifstream fhandle(filename.data());
  std::string line;
  Triangle triangle;

  while (std::getline(fhandle, line)) {
    Level level;
    std::stringstream ss(line);
    int value = 0;
    while (ss >> value) {
      level.push_back(value);
    }
    triangle.push_back(level);
  }
  return triangle;
}

static int64_t MaxPathSum(const Triangle& tri, std::size_t level,
                          std::size_t index) {
  if (level == tri.size()) {
    return 0;
  }

  int64_t max_sum = tri[level][index];
  max_sum += std::max(MaxPathSum(tri, level + 1, index),
                      MaxPathSum(tri, level + 1, index + 1));
  return max_sum;
}

types::SolnFuncRet Soln18(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  Triangle triangle = LoadTriangle(args[0]);
  return MaxPathSum(triangle, 0, 0);
}

}  // namespace euler
