#include "soln_factory/soln_factory.h"

#include <optional>

#include "common/types.h"
#include "solns/soln_1.h"
#include "solns/soln_2.h"
#include "solns/soln_3.h"

namespace euler {
namespace sfactory {

std::optional<types::SolnFunc> GetSoln(types::SolnId id) {
  switch (id) {
    case 1:
      return Soln1;
    case 2:
      return Soln2;
    case 3:
      return Soln3;
    default:
      return std::nullopt;
  }
}

}  // namespace sfactory
}  // namespace euler
