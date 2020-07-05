// 並び替えアルゴリズムの要素
template <typename T> class Element;

// フレンド関数での2項演算子アクセス（クラス内表記では1項になってしまうため）
template <typename T>
bool operator < (const Element<T> &lhs, const Element<T> &rhs);

template <typename T>
bool operator <=(const Element<T> &lhs, const Element<T> &rhs);

template <typename T>
class Element
{
public:
  Element() {}
  Element(T x): X(x) {}  
  // フレンド宣言で定義を外出し。<T> が味噌
  friend bool operator < <T>(const Element<T> &lhs, const Element<T> &rhs);
  friend bool operator <=<T>(const Element<T> &lhs, const Element<T> &rhs);
  T& get() {return X;}
  const T& get() const {return X;}

  static void setLess() {m_bLess = true;}
  static void setGreat() {m_bLess = false;}
private:
  static bool m_bLess;
  T X;
};

// スタティック変数の実体をここに記述する
template <typename T>
bool Element<T>::m_bLess;

template <typename T>
bool operator < (const Element<T> &lhs, const Element<T> &rhs)
{
  return Element<T>::m_bLess? lhs.X < rhs.X: lhs.X > rhs.X;
}

template <typename T>
bool operator <= (const Element<T> &lhs, const Element<T> &rhs)
{
  return Element<T>::m_bLess? lhs.X <= rhs.X: lhs.X >= rhs.X;
}

