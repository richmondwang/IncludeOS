#pragma once
#include <lest/lest.hpp>
#include <vector>

#define CASE( name ) lest_CASE( specification(), name )
extern lest::tests & specification();

#define DEBUG_UNIT
#ifdef DEBUG_UNIT
#define LINK printf("%s:%i: OK\n",__FILE__,__LINE__)
#else
#define LINK (void)
#endif

namespace test {

uint64_t rand64();
template <int N>
static std::vector<uint64_t> rands64()
{
  static std::vector<uint64_t> rnd;

  if (rnd.empty())
  {
    for (int i = 0; i < N; i++)
    {
      rnd.push_back(rand64());
    }
  }

  return rnd;
}

const std::vector<uint64_t> random = rands64<10>();

}

#ifndef HAVE_LEST_MAIN
#include "lestmain.cxx"
#endif
