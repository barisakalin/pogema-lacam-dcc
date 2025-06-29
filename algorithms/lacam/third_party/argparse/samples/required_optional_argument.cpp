// SPDX-License-Identifier: MIT

#include <argparse/argparse.hpp>

int main(int argc, char *argv[]) {
  argparse::ArgumentParser program("test");

  program.add_argument("-o", "--output")
      .required()
      .help("specify the output file.");

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  std::cout << "Output written to " << program.get("-o") << "\n";
}
