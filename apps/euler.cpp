#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#include "common/conversions.h"
#include "common/types.h"
#include "soln_factory/soln_factory.h"

static void PrintUsage() {
  std::cout << "usage: euler PROBLEM_ID [ARGS]..." << std::endl;
  std::cout << "display project euler solutions" << std::endl;
  std::cout << "\tPROBLEM_ID\n\t\ta project euler problem id" << std::endl;
  std::cout << "\tARGS\n\t\tzero or more problem input args" << std::endl;
}

static void PrintErrorAndExit(const std::string_view& err_msg) {
  std::cerr << "error: " << err_msg << std::endl;
  std::exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    PrintUsage();
    std::exit(EXIT_FAILURE);
  }

  auto id = euler::conv::StrToULong(argv[1]);
  if (!id.has_value()) {
    switch (id.error()) {
      case euler::conv::ErrorCode::kInvalidArg:
        PrintErrorAndExit("PROGRAM_ID is not a positive integer");
      case euler::conv::ErrorCode::kOutOfRange:
        PrintErrorAndExit("PROGRAM_ID is too large");
    }
  }

  auto soln_func = euler::sfactory::GetSoln(id.value());
  if (soln_func) {
    std::vector<std::string_view> args(argv + 2, argv + argc);
    euler::types::SolnFuncRet ret = (*soln_func)(args);
    if (ret.has_value()) {
      std::cout << "answer: " << ret.value() << std::endl;
    } else {
      PrintErrorAndExit(euler::types::kRetCodeToStr[ret.error()]);
    }
  } else {
    PrintErrorAndExit("no solution exists for problem " + std::string(argv[1]));
  }

  std::exit(EXIT_SUCCESS);
}
