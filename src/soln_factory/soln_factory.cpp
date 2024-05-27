#include "soln_factory/soln_factory.h"

#include <optional>

#include "common/types.h"
#include "solns/soln_1.h"
#include "solns/soln_2.h"
#include "solns/soln_3.h"
#include "solns/soln_4.h"
#include "solns/soln_5.h"
#include "solns/soln_6.h"
#include "solns/soln_7.h"
#include "solns/soln_8.h"
#include "solns/soln_9.h"
#include "solns/soln_10.h"

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
    case 4:
      return Soln4;
    case 5:
      return Soln5;
    case 6:
      return Soln6;
    case 7:
      return Soln7;
    case 8:
      return Soln8;
    case 9:
      return Soln9;
    case 10:
      return Soln10;
    default:
      return std::nullopt;
  }
}

}  // namespace sfactory
}  // namespace euler
