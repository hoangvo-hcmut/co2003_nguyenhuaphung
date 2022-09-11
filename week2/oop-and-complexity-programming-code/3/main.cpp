#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class BinExp;
class UnExp;
class IntLit;

class Visitor
{
public:
  virtual string visit(BinExp *exp) = 0;
  virtual string visit(UnExp *exp) = 0;
  virtual string visit(IntLit *exp) = 0;
};

class Exp
{
public:
  virtual string accept(Visitor &v) = 0;
};

class BinExp : public Exp
{
public:
  Exp *left;
  char op;
  Exp *right;
  BinExp(Exp *left, char op, Exp *right)
  {
    this->left = left;
    this->op = op;
    this->right = right;
  }

  string accept(Visitor &v)
  {
    return v.visit(this);
  };
};

class UnExp : public Exp
{
public:
  char op;
  Exp *exp;
  UnExp(char op, Exp *exp)
  {
    this->op = op;
    this->exp = exp;
  }

  string accept(Visitor &v)
  {
    return v.visit(this);
  };
};

class IntLit : public Exp
{

public:
  int v;
  IntLit(int v)
  {
    this->v = v;
  }

  string accept(Visitor &v)
  {
    return v.visit(this);
  };
};

class Eval : public Visitor
{
public:
  string visit(BinExp *exp) override
  {
    switch (exp->op)
    {
    case '+':
      return to_string(stoi(exp->left->accept(*this)) + stoi(exp->right->accept(*this)));
    case '-':
      return to_string(stoi(exp->left->accept(*this)) - stoi(exp->right->accept(*this)));
    case '*':
      return to_string(stoi(exp->left->accept(*this)) * stoi(exp->right->accept(*this)));
    case '/':
      return to_string(stoi(exp->left->accept(*this)) / stoi(exp->right->accept(*this)));
    };
    return 0;
  }

  string visit(UnExp *exp) override
  {
    if (exp->op == '-')
      return to_string(-stoi(exp->exp->accept(*this)));
    return exp->exp->accept(*this);
  }

  string visit(IntLit *exp) override
  {
    return to_string(exp->v);
  }
};

class PrintPrefix : public Visitor
{
public:
  string visit(BinExp *exp) override
  {
    return string(1, exp->op) + string(1, ' ') + exp->left->accept(*this) + string(1, ' ') + exp->right->accept(*this);
  }

  string visit(UnExp *exp) override
  {
    return (exp->op == '+' ? "+. " : "-. ") + exp->exp->accept(*this);
  }

  string visit(IntLit *exp) override
  {
    return to_string(exp->v);
  }
};

class PrintPostfix : public Visitor
{
public:
  string visit(BinExp *exp) override
  {
    return exp->left->accept(*this) + string(1, ' ') + exp->right->accept(*this) + string(1, ' ') + string(1, exp->op);
  }

  string visit(UnExp *exp) override
  {
    return exp->exp->accept(*this) + (exp->op == '+' ? " +." : " -.");
  }

  string visit(IntLit *exp) override
  {
    return to_string(exp->v);
  }
};

int main()
{
  BinExp *bii = new BinExp(new IntLit(1), '+', new IntLit(2));

  PrintPrefix printPrefix;

  cout << bii->accept(printPrefix);
}
