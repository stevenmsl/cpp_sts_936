
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;
namespace sol936
{

  class Solution
  {
  private:
    int removeStamp(string &stamp, string &target, int s);

  public:
    vector<int> stamp(string stamp, string target);
  };
}
#endif