#include "soln_factory/soln_factory.h"

#include <optional>

#include "common/types.h"
#include "solns/soln_1.h"

namespace euler {
namespace sfactory {

std::optional<types::SolnFunc> GetSoln(types::SolnId id) {
  switch (id) {
    case 1:
      return Soln1;
    default:
      return std::nullopt;
  }
}

}  // namespace sfactory
}  // namespace euler
