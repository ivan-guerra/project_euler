#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

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

  try {
    euler::types::SolnId id = std::stoul(argv[1]);

    auto f = euler::sfactory::GetSoln(id);
    if (f) {
      std::vector<std::string_view> args(argv + 2, argv + argc);
      (*f)(args);
    } else {
      PrintErrorAndExit("no solution exists for problem " +
                        std::string(argv[1]));
    }
  } catch (const std::invalid_argument& e) {
    PrintErrorAndExit("PROGRAM_ID is not a positive integer");
  } catch (const std::out_of_range& e) {
    PrintErrorAndExit("PROGRAM_ID is too large");
  }
  std::exit(EXIT_SUCCESS);
}
