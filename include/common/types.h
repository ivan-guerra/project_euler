#ifndef TYPES_H_
#define TYPES_H_

#include <functional>
#include <string_view>
#include <vector>

namespace euler {
namespace types {

using SolnId = unsigned long; /**< Project Euler problem ID. */
using SolnFuncArgs =
    std::vector<std::string_view>; /**< Solution function arguments. */
using SolnFunc =
    std::function<void(const SolnFuncArgs&)>; /**< Solution function object. */

}  // namespace types
}  // namespace euler

#endif
