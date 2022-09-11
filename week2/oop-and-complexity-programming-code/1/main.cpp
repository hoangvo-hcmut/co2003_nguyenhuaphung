class Exp
{
public:
  virtual int eval()
  {
    return 0;
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
};
