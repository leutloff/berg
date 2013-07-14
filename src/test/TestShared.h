/*
 * @file TestShared.h
 * This header provides the functions used for testing purposes only.
 *
 * Copyright 2013 Christian Leutloff <leutloff@sundancer.oche.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TEST_SHARED_H_
#define TEST_SHARED_H_

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include <string>

namespace berg
{
    namespace testonly
    {
        /**
         * @brief determines the directory used for input files for the test cases.
         * @return the directory with the input files
         */
        inline std::string GetInputDir()
        {
            std::string input = "../../src/test/input/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            input = "../src/test/input/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            return "";
        }

        /**
         * @brief determines the directory with archive files used for the test cases.
         * @return the directory with the archive files
         */
        inline std::string GetArchiveDir()
        {
            std::string input = "../../src/test/input/archive/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            input = "../src/test/input/archive/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            return "";
        }

        /**
         * @brief determines the directory used to write files within the test cases.
         * @return the directory to write files
         */
        inline std::string GetOutputDir()
        {
            std::string input = "../../src/test/output/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            input = "../src/test/output/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            return "";
        }

        /**
         * @brief determines the directory where the input, output and expected directories are located.
         * Path used to execute the perl scripts.
         * @return the main test directory
         */
        inline std::string GetTestDir()
        {
            std::string input = "../../src/test/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            input = "../src/test/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            return "";
        }

        /**
         * @brief determines the directory containing files used to validate the outcome of some steps.
         * @return the directory with expected output files
         */
        inline std::string GetExpectedDir()
        {
            std::string input = "../../src/test/expected/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            input = "../src/test/expected/";
            if (boost::filesystem::exists(input))
            {
                return input;
            }
            return "";
        }

        /**
         * @brief Read the file and print each line to the output stream
         * @param file to read
         * @param oss stream the content is written to
         */
        inline void PrintFileToStream(boost::filesystem::path const& file, std::ostream &oss)
        {
            if (boost::filesystem::exists(file))
            {
                boost::filesystem::ifstream ifs(file);
                if (ifs.is_open())
                {
                    std::string line;
                    int cnt = 0;
                    while (ifs.good())
                    {
                        std::getline(ifs, line);
                        ++cnt;
                        oss << line << "\n";
                    }
                }
                else
                {
                    oss << "Die Datei (" << file.c_str() << ") konnte nicht geöffnet werden!\n";
                }
            }
            else
            {
                oss << "Datei (" << file.c_str() << ") nicht existiert und kann deswegen nicht ausgegeben werden!\n";
            }
        }

    }
}

#endif /* TEST_SHARED_H_ */


