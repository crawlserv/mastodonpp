/*  This file is part of mastodonpp.
 *  Copyright © 2020 tastytea <tastytea@tastytea.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MASTODONPP_LOG_HPP
#define MASTODONPP_LOG_HPP

#include <iostream>

namespace mastodonpp
{

using std::cerr;

#ifndef NDEBUG
    #define debuglog cerr << "[" << __FILE__ << ":" << __LINE__ << "] DEBUG: "
#else
    #define debuglog false && cerr
#endif

} // namespace mastodonpp

#endif  // MASTODONPP_LOG_HPP
