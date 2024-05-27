#!/usr/bin/python

import os
import shutil
import argparse
import in_place
import re


class SolutionGenerator:
    def __init__(self):
        self.PROJECT_DIR = os.path.join(os.getcwd(), os.pardir)
        self.TEMPLATE_DIR = os.path.join(os.getcwd(), 'templates')

    def __insert_id(self, id, filepath):
        with in_place.InPlace(filepath) as file:
            for line in file:
                line = line.replace('<N>', id)
                file.write(line)
            file.close()

    def __add_file(self, id, project_dir_suffix, template_dir_suffix, target_filename):
        template_file = os.path.join(
            self.TEMPLATE_DIR, template_dir_suffix)
        target_dir = os.path.join(self.PROJECT_DIR, project_dir_suffix)
        target_file = os.path.join(target_dir, target_filename)

        shutil.copy(template_file, target_file)

        self.__insert_id(id, target_file)

    def __add_target_include(self, id):
        self.__add_file(id,
                        'include/solns',
                        'soln_target/soln_n.h.template',
                        'soln_' + id + '.h')

    def __add_target_src(self, id):
        # Create the target source directory.
        src_dir_suffix = 'src/solns/soln_' + id
        src_dir = os.path.join(
            self.PROJECT_DIR, src_dir_suffix)
        os.mkdir(src_dir)

        # Install the CMakeLists.txt.
        self.__add_file(id,
                        src_dir_suffix,
                        'soln_target/CMakeLists.txt.template',
                        'CMakeLists.txt')

        # Install the CPP.
        self.__add_file(id,
                        src_dir_suffix,
                        'soln_target/soln_n.cpp.template',
                        'soln_' + id + '.cpp')

        # Add the new solution target's directory.
        toplevel_cmake = os.path.join(
            self.PROJECT_DIR, 'src/solns/CMakeLists.txt')
        with open(toplevel_cmake, 'a') as fp:
            fp.write('add_subdirectory(soln_' + id + ')\n')

    def __add_target_benchmark(self, id):
        # Create the target source directory.
        benchmark_dir_suffix = 'benchmark/solns/soln_' + id
        benchmark_dir = os.path.join(
            self.PROJECT_DIR, benchmark_dir_suffix)
        os.mkdir(benchmark_dir)

        # Install the CMakeLists.txt.
        self.__add_file(id,
                        benchmark_dir_suffix,
                        'soln_benchmark/CMakeLists.txt.template',
                        'CMakeLists.txt')

        # Install the CPP.
        self.__add_file(id,
                        benchmark_dir_suffix,
                        'soln_benchmark/soln_n_benchmark.cpp.template',
                        'soln_' + id + '_benchmark.cpp')

        # Add the new benchmark target's directory.
        toplevel_cmake = os.path.join(
            self.PROJECT_DIR, 'benchmark/solns/CMakeLists.txt')
        with open(toplevel_cmake, 'a') as fp:
            fp.write('add_subdirectory(soln_' + id + ')\n')

    def __update_soln_factory_link(self, id):
        soln_factory_cmake = os.path.join(
            self.PROJECT_DIR, 'src/soln_factory/CMakeLists.txt')
        pattern = re.compile('soln_[0-9]+\\)')
        with in_place.InPlace(soln_factory_cmake) as file:
            for line in file:
                if re.search(pattern, line):
                    # -2 to caputre both the newline and the closing paren.
                    file.write(line[:-2] + '\n')
                    file.write(10 * ' ' + 'soln_' + id + ')' + '\n')
                else:
                    file.write(line)
            file.close()

    def __update_soln_factory_src(self, id):
        soln_factory_src = os.path.join(
            self.PROJECT_DIR, 'src/soln_factory/soln_factory.cpp')
        previous = ''
        with in_place.InPlace(soln_factory_src) as file:
            for line in file:
                if line == '\n' and previous.startswith('#include "solns'):
                    file.write('#include "solns/soln_' + id + '.h"\n')
                elif line.find('default:') != -1:
                    file.write(' ' * 4 + 'case ' + id + ':\n' +
                               6 * ' ' + 'return Soln' + id + ';\n')
                file.write(line)
                previous = line
            file.close()

    def add_solution(self, id):
        self.__add_target_include(id)
        self.__add_target_src(id)
        self.__add_target_benchmark(id)
        self.__update_soln_factory_link(id)
        self.__update_soln_factory_src(id)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("id", type=int, help="problem id")
    args = parser.parse_args()

    soln_gen = SolutionGenerator()
    soln_gen.add_solution(str(args.id))
