/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011, 2012                                                   *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation, either version 3 of the License                  *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/


#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <stdexcept>

template<typename T>
T rd(char const* cstr)
{
    char* endptr = nullptr;
    T result = static_cast<T>(strtol(cstr, &endptr, 10));
    if (endptr == nullptr || *endptr != '\0')
    {
        std::string errstr;
        errstr += "\"";
        errstr += cstr;
        errstr += "\" is not an integer";
        throw std::invalid_argument(errstr);
    }
    return result;
}

int num_cores()
{
    char cbuf[100];
    FILE* cmd = popen("cat /proc/cpuinfo | grep processor | wc -l", "r");
    if (fgets(cbuf, 100, get_uuid_cmd) != 0)
    {
        throw std::runtime_error("cannot determine number of cores");
    }
    pclose(cmd);
    return rd<int>(cbuf);
}

#endif // UTILITY_HPP