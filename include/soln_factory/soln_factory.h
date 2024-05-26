#ifndef SOLN_FACTORY_H_
#define SOLN_FACTORY_H_

#include <optional>

#include "common/types.h"

namespace euler {
namespace sfactory {

/**
 * \brief Return a soln function for the Project Euler problem with ID \p id.
 * \param [in] id ID of a Project Euler problem.
 * \returns A callable #SolnFunc object representing the solution to the
 *          problem. std::nullopt is returned when no solution has yet
 *          been implemented for the requested ID.
 */
std::optional<types::SolnFunc> GetSoln(types::SolnId id);

}  // namespace sfactory
}  // namespace euler

#endif
