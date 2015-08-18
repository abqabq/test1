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
