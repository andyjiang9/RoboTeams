// C++ includes used for precompiling -*- C++ -*-
2
3 // Copyright (C) 2003-2013 Free Software Foundation, Inc.
4 //
5 // This file is part of the GNU ISO C++ Library.  This library is free
6 // software; you can redistribute it and/or modify it under the
7 // terms of the GNU General Public License as published by the
8 // Free Software Foundation; either version 3, or (at your option)
9 // any later version.
10
11 // This library is distributed in the hope that it will be useful,
12 // but WITHOUT ANY WARRANTY; without even the implied warranty of
13 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
14 // GNU General Public License for more details.
15
16 // Under Section 7 of GPL version 3, you are granted additional
17 // permissions described in the GCC Runtime Library Exception, version
18 // 3.1, as published by the Free Software Foundation.
19
20 // You should have received a copy of the GNU General Public License and
21 // a copy of the GCC Runtime Library Exception along with this program;
22 // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
23 // <http://www.gnu.org/licenses/>.
24
25 /** @file stdc++.h
26  *  This is an implementation file for a precompiled header.
27  */
28
29 // 17.4.1.2 Headers
30
31 // C
32 #ifndef _GLIBCXX_NO_ASSERT
33 #include <cassert>
34 #endif
35 #include <cctype>
36 #include <cerrno>
37 #include <cfloat>
38 #include <ciso646>
39 #include <climits>
40 #include <clocale>
41 #include <cmath>
42 #include <csetjmp>
43 #include <csignal>
44 #include <cstdarg>
45 #include <cstddef>
46 #include <cstdio>
47 #include <cstdlib>
48 #include <cstring>
49 #include <ctime>
50
51 #if __cplusplus >= 201103L
52 #include <ccomplex>
53 #include <cfenv>
54 #include <cinttypes>
55 #include <cstdalign>
56 #include <cstdbool>
57 #include <cstdint>
58 #include <ctgmath>
59 #include <cwchar>
60 #include <cwctype>
61 #endif
62
63 // C++
64 #include <algorithm>
65 #include <bitset>
66 #include <complex>
67 #include <deque>
68 #include <exception>
69 #include <fstream>
70 #include <functional>
71 #include <iomanip>
72 #include <ios>
73 #include <iosfwd>
74 #include <iostream>
75 #include <istream>
76 #include <iterator>
77 #include <limits>
78 #include <list>
79 #include <locale>
80 #include <map>
81 #include <memory>
82 #include <new>
83 #include <numeric>
84 #include <ostream>
85 #include <queue>
86 #include <set>
87 #include <sstream>
88 #include <stack>
89 #include <stdexcept>
90 #include <streambuf>
91 #include <string>
92 #include <typeinfo>
93 #include <utility>
94 #include <valarray>
95 #include <vector>
96
97 #if __cplusplus >= 201103L
98 #include <array>
99 #include <atomic>
100 #include <chrono>
101 #include <condition_variable>
102 #include <forward_list>
103 #include <future>
104 #include <initializer_list>
105 #include <mutex>
106 #include <random>
107 #include <ratio>
108 #include <regex>
109 #include <scoped_allocator>
110 #include <system_error>
111 #include <thread>
112 #include <tuple>
113 #include <typeindex>
114 #include <type_traits>
115 #include <unordered_map>
116 #include <unordered_set>
117 #endif