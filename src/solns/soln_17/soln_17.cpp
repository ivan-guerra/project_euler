#include "solns/soln_17.h"

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "common/conversions.h"
#include "common/types.h"

namespace euler {

static std::string TranslateNumToStr(unsigned long num) {
  std::string num_str = std::to_string(num);
  using NumToStr = std::unordered_map<int, std::string>;
  static NumToStr kOnes = {
      {1, "one"}, {2, "two"},   {3, "three"}, {4, "four"}, {5, "five"},
      {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
  };
  static NumToStr kOnesInTheTens = {
      {0, "ten"},      {1, "eleven"},   {2, "twelve"},  {3, "thirteen"},
      {4, "fourteen"}, {5, "fifteen"},  {6, "sixteen"}, {7, "seventeen"},
      {8, "eighteen"}, {9, "nineteen"},
  };
  static NumToStr kTens = {
      {2, "twenty"}, {3, "thirty"},  {4, "forty"},  {5, "fifty"},
      {6, "sixty"},  {7, "seventy"}, {8, "eighty"}, {9, "ninety"},
  };
  static NumToStr kDigitsPlace = {
      {2, "hundred"},
      {3, "thousand"},
  };

  if (num_str.size() == 1) {
    return kOnes[num_str[0] - '0'];
  }

  std::string result;
  int digit_place = num_str.size();
  for (std::size_t i = 0; i < num_str.size(); ++i) {
    int digit = num_str[i] - '0';
    if (digit_place > 2) {     /* We're looking at numbers >= 100 */
      if (num_str[0] != '0') { /* Zero doesn't get a print out. */
        result += kOnes[digit] + " " + kDigitsPlace[digit_place - 1];
        if (std::any_of(num_str.cbegin() + i + 1, num_str.cend(),
                        [](char c) { return c != '0'; })) {
          result += " and ";
        } else {
          break;
        }
      }
    } else {
      if (num_str[i] == '1') { /* The digits make a num in the teens. */
        result += kOnesInTheTens[num_str[i + 1] - '0'];
      } else { /* The digits make a num in XXXty. */
        result += kTens[digit] + " " + kOnes[num_str[i + 1] - '0'];
      }
      break;
    }
    digit_place--;
  }
  return result;
}

types::SolnFuncRet Soln17(const types::SolnFuncArgs& args) {
  if (args.size() != 1) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  const auto kLimit = euler::conv::StrToULong(args[0]);
  if (!kLimit.has_value()) {
    return std::unexpected(types::SolnErrorCode::kCannotConvertStrToUInt);
  }

  int64_t num_chars = 0;
  for (unsigned long i = 1; i <= kLimit.value(); ++i) {
    std::string num = TranslateNumToStr(i);
    num_chars += std::count_if(num.cbegin(), num.cend(),
                               [](char c) { return !std::isspace(c); });
  }
  return num_chars;
}

}  // namespace euler
