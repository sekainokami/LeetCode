#include <iostream>

using namespace std;

class String
{
private:
  char* s;
  size_t sz;

public:

  String(): s(nullptr), sz(0){}

  String(const char* _s)
  {
    size_t len =  0;
    const char* t = _s;
    while (*_s)
    {
      len++;
      _s++;
    }

    sz = len;
    s = new char[len];
    for (size_t i = 0; i < len; ++i)
      s[i] = t[i];
  }

  String(const String& rhs): sz(rhs.size())
  {
    size_t len = rhs.size();
    s = new char[len];
    for (size_t i = 0; i < len; ++i)
      s[i] = rhs.s[i];
  }

  String(String&& rhs): sz(rhs.size())
  {
    s = rhs.s;
    rhs.s = nullptr;
  }

  String& operator=(const String& rhs)
  {
    size_t len = rhs.size();
    sz = len;

    s = new char[len];
    for (size_t i = 0; i < len; ++i)
      s[i] = rhs.s[i];

    return *this;
  }

  String& operator=(String&& rhs)
  {
    sz = rhs.size();
    s = rhs.s;
    rhs.s = nullptr;
    return *this;
  }

  char& operator[](size_t index) const
  {
    return s[index];
  }

  size_t size() const
  {
    return sz;
  }

  bool operator==(const String& rhs) const
  {
    if (rhs.size() != sz)
      return false;
    for (size_t i = 0; i < rhs.size(); ++i)
    {
      if (rhs[i] != s[i])
        return false;
    }
    return true;
  }

  String operator+(const String& rhs) const
  {
      size_t len = sz + rhs.size();
      char* buffer = new char[len];
      for (size_t i = 0; i < sz; ++i)
        buffer[i] = s[i];
      for (size_t i = sz; i < len; ++i)
        buffer[i] = rhs.s[i-sz];

      String res(buffer);
      return res;
  }

  friend ostream& operator<<(ostream& os, const String& rhs)
  {
    for (size_t i = 0; i < rhs.size(); ++i)
      os << rhs.s[i];
    return os;
  }

  ~String()
  {
    delete [] s;
  }
};



int main()
{
  char c[] = "helloworld";
  String s(c);
  String s2(s);
  String s3 = s;
  s3[0] = 'H';
  String s4(String("Moved"));
  String s5(s + s4);
  cout << s << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl;
  cout << s5 << endl;

  if (s == s2)
    cout << s << " == " << s2 << endl;

  if (s == s5)
    cout << "equal" << endl;
  else
    cout << s << " != " << s5 << endl;

}
