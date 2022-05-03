#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol936;
using namespace std;

/*takeaways
  - use greedy and reverse simulation
  - T="ababc", S="abc"
    - find an exact match of S in T and
      remove the stamp
    - T="ab???", the start index is 2
    - find a partial match of the stamp in
      T and remove the stamp
    - T="?????", the start index is 0
  - so since we are reversing the process
    so the normal process should be done
    in backward of what we do
    [2,0] -> [0,2]

*/

int Solution::removeStamp(string &stamp, string &target, int s)
{
  /* initially since no char will be marked as '?'
     so this function will try to find a exact match
     first
     - the very last stamp will get to keep the
       whole stamp without some of the chars it stamped
       been replaced as it's the very last stamp
     - so if the target can be produce by a series
       of stamps it must contain a substring that
       is the same as the stamp
     - a partial match is defined as the following
       target = ??ab???
       stamp = abc
       partial match started at target[2..4]

  */

  /* total chars reverted to '?' */
  int count = stamp.size();

  for (auto i = 0; i < stamp.size(); i++)
    if (target[s + i] == '?')
      count--;
    else if (target[s + i] != stamp[i])
      return 0;
  if (count != 0)
    /* just reverse everything in the range even though
       some chars might have been reverse to '?' before
       as otherwise you have to remember which chars
       you need to reverse

       - ????ab
       - ab????
       - ?ab???
    */
    fill(begin(target) + s, begin(target) + s + stamp.size(), '?');

  return count;
}

vector<int> Solution::stamp(string stamp, string target)
{
  const int m = stamp.size(), n = target.size();

  auto result = vector<int>();
  /* total chats in target reverted to '?' */
  auto total = 0;

  /* to optimize a bit */
  auto visited = vector<bool>(n, false);

  while (total < n)
  {
    bool removed = false;

    /* the stamp must be fully contained in the boundaries
       so the very last start index of the stamp is n-m
    */
    for (auto i = 0; i <= n - m; i++)
    {
      if (visited[i])
        continue;
      auto r = removeStamp(stamp, target, i);
      if (r == 0)
        continue;
      removed = true;
      total += r;
      result.push_back(i);
      visited[i] = true;
    }
    if (!removed)
      return {};
  }

  /* reverse the process */
  reverse(begin(result), end(result));
  return result;
}