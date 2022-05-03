#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol936;

/*
Input: stamp = "abc", target = "ababc"
Output: [0,2]
([1,0,2] would also be accepted as an answer, as well as some other answers.)
*/
tuple<string, string, vector<int>>
testFixture1()
{
  return make_tuple("abc", "ababc", vector<int>{0, 2});
}

/*
Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
*/
tuple<string, string, vector<int>>
testFixture2()
{
  return make_tuple("abca", "aabcaca", vector<int>{3, 0, 1});
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << Util::toString(get<2>(f))
       << ": " << Util::toString(sol.stamp(get<0>(f), get<1>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << Util::toString(get<2>(f))
       << ": " << Util::toString(sol.stamp(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}