class Exp
{
public:
  virtual int eval()
  {
    return 0;
  }
  virtual void printPrefix()
  {
  }
};

class BinExp : public Exp
{
private:
  Exp *left;
  char op;
  Exp *right;

public:
  BinExp(Exp *left, char op, Exp *right)
  {
    this->left = left;
    this->op = op;
    this->right = right;
  }
  int eval()
  {
    switch (op)
    {
    case '+':
      return this->left->eval() + this->right->eval();
    case '-':
      return this->left->eval() - this->right->eval();
    case '*':
      return this->left->eval() * this->right->eval();
    case '/':
      return this->left->eval() / this->right->eval();
    };
    return 0;
  }

  void printPrefix()
  {
    cout << string(1, this->op) << " ";
    this->left->printPrefix();
    cout << " ";
    this->right->printPrefix();
  }
};

class UnExp : public Exp
{
private:
  char op;
  Exp *exp;

public:
  UnExp(char op, Exp *exp)
  {
    this->op = op;
    this->exp = exp;
  }

  int eval()
  {
    if (this->op == '-')
      return -this->exp->eval();
    return this->exp->eval();
  }

  void printPrefix()
  {
    cout << (this->op == '+' ? "+. " : "-. ");
    this->exp->printPrefix();
  }
};

class IntLit : public Exp
{
private:
  int v;

public:
  IntLit(int v)
  {
    this->v = v;
  }

  int eval()
  {
    return this->v;
  }

  void printPrefix()
  {
    cout << to_string(this->v);
  }
};
