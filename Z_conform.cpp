// 6. N字型转换

#include<vector>
#include<string>
using namespace std;


class ZConform{
  public:
  string convert_1(string s, int rows){
    int n = s.length(), r = rows;
    if(r == 1 || r >= n)
      return s;

    int t = 2 * r - 2;
    int c = (n + t -1 ) / t * (r - 1);
    vector<string> mat(r, string(c, 0));
    for(int i = 0, x =0,y = 0; i < n; i++)
    {
      mat[x][y] = s[i];
      if(i % t < r -1)
        ++x;
      else{
        --x;
        ++y;
      }
    }

    string result;
    for (auto &row : mat)
    {
      for (char &ch : row)
      {
        if(ch){
          result += ch;
        }
      }
    }
    return result;
  }

  string convert_2(string s, int rows){
    int n = s.length(), r = rows;
    if(r == 1 || r >= n)
      return s;

    int t = 2 * r - 2;
    vector<string> mat(r);
    for (int i = 0, x = 0; i < n; i++)
    {
      mat[x] = s[i];
      i % t < r -1 ? ++x : --x;
    }

    string ans;
    for (auto &row : mat)
    {
      ans += row;
    }
    return ans;
  }

  string convert_3(string s, int rows){
    int n = s.length(), r = rows;
    if(r == 1 || r >= n)
      return s;

    string ans;
    int t = r + r - 2;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; i + j < n; j += t)
      {
        ans += s[i + j];
        if (i >0 && i < r-1 && j + t - i < n)
        {
          ans += s[j + t - i];
        }
      }
    }
    return ans;
  }
};