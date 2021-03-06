// { dg-require-namedlocale "" }

// 2001-08-15 Benjamin Kosnik  <bkoz@redhat.com>

// Copyright (C) 2001, 2002, 2003, 2005 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// 22.2.4.1.1 collate members

#include <testsuite_hooks.h>

#define main discard_main_1
#include "1.cc"
#undef main 

#define main discard_main_2
#include "2.cc"
#undef main 

#define main discard_main_3
#include "3.cc"
#undef main 

#define main discard_main_4
#include "4.cc"
#undef main 

#define main discard_main_5
#include "5.cc"
#undef main 

int main()
{
  using namespace __gnu_test;
  func_callback two;
  two.push_back(&test01);
  two.push_back(&test02);
  two.push_back(&test03);
  two.push_back(&test04);
  two.push_back(&test05);
  run_tests_wrapped_locale("ja_JP.eucjp", two);
  return 0;
}
