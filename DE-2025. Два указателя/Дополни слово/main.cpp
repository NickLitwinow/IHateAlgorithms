#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  string s;
  cin >> s;
  int n = s.size();
  if(n < 26){
    cout << -1;
    return 0;
  }

  int pos = -1;
  for (int i = 0; i <= n - 26; i++){
    int cnt[26] = {0};
    int question = 0;
    bool valid = true;
    for (int j = i; j < i + 26; j++){
      if(s[j] == '?'){
        question++;
      } else {
        cnt[s[j] - 'A']++;
        if(cnt[s[j] - 'A'] > 1){
          valid = false;
          break;
        }
      }
    }

    if(valid){
      int distinct = 0;
      for (int k = 0; k < 26; k++){
        if(cnt[k] == 1)
          distinct++;
      }
      if(question == 26 - distinct){
        pos = i;
        break;
      }
    }
  }

  if(pos == -1){
    cout << -1;
    return 0;
  }

  bool used[26] = {0};
  for (int j = pos; j < pos + 26; j++){
    if(s[j] != '?'){
      used[s[j] - 'A'] = true;
    }
  }
  vector<char> missing;
  for (int k = 0; k < 26; k++){
    if(!used[k])
      missing.push_back('A' + k);
  }

  int idx = 0;
  for (int j = pos; j < pos + 26; j++){
    if(s[j] == '?'){
      s[j] = missing[idx++];
    }
  }

  for (int i = 0; i < n; i++){
    if(s[i] == '?')
      s[i] = 'A';
  }

  cout << s;
  return 0;
}
