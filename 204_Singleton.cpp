class Solution {
public:
  static Solution* getInstance() {
    static Solution *sol = new Solution();
    return sol;
  }

private:
  Solution();
  ~Soltion();
  Solution(const Solution&);
  Solution& operator=(const Solution&);
};


class Singleton {
private:
  Singleton();
  ~Singleton();
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
  
  static Singleton* instance;

public:
  static Singleton* getIntance() {
    if (instance == NULL) {
      Lock();
      // double check
      if (instance == NULL) {
        instance = new Singleton();
      }
      Unlock();
    }
  }
}
