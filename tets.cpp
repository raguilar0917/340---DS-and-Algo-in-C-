#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int findmatch(char* p, char *t){
  int plen = strlen(p);
  int tlen = strlen(t);
  cout<<plen<<endl;

  return 0;
}
int main() {
    char t[11] = {'a', 'b', 'a', 'a', 'b', 'a', 'b', 'b', 'a', 'b', 'a'};
  char p[4] = {'a', 'b', 'b', 'a'};
  cout<<findmatch(p, t);
  return 0;
}