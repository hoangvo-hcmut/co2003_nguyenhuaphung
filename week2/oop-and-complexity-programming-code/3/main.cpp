#include <iostream>
using namespace std;

class BinExp;
class UnExp;
class IntLit;

class Visitor {
public:
  virtual int visit(BinExp *exp) = 0;
  virtual int visit(UnExp *exp) = 0;
  virtual int visit(IntLit *exp) = 0;
};

class Exp {
public:
  virtual int accept(Visitor *v) = 0;
};

class BinExp : public Exp {
public:
  Exp *left;
  char op;
  Exp *right;
  BinExp(Exp *left, char op, Exp *right) {
    this->left = left;
    this->op = op;
    this->right = right;
  }

  int accept(Visitor *v) { return v->visit(this); };
};

class UnExp : public Exp {
public:
  char op;
  Exp *exp;
  UnExp(char op, Exp *exp) {
    this->op = op;
    this->exp = exp;
  }

  int accept(Visitor *v) { return v->visit(this); };
};

class IntLit : public Exp {

public:
  int v;
  IntLit(int v) { this->v = v; }

  int accept(Visitor *v) { return v->visit(this); };
};

class Eval : public Visitor {
public:
  int visit(BinExp *exp) override {
    switch (exp->op) {
    case '+':
      return exp->left->accept(this) + exp->right->accept(this);
    case '-':
      return exp->left->accept(this) - exp->right->accept(this);
    case '*':
      return exp->left->accept(this) * exp->right->accept(this);
    case '/':
      return exp->left->accept(this) / exp->right->accept(this);
    };
    return 0;
  }

  int visit(UnExp *exp) override {
    if (exp->op == '-')
      return -exp->exp->accept(this);
    return exp->exp->accept(this);
  }

  int visit(IntLit *exp) override { return exp->v; }
};

class PrintPrefix : public Visitor {
public:
  int visit(BinExp *exp) override {
    cout << exp->op << " ";
    exp->left->accept(this);
    cout << " ";
    exp->right->accept(this);
    return 0;
  }

  int visit(UnExp *exp) override {
    cout << (exp->op == '+' ? "+. " : "-. ");
    exp->exp->accept(this);
    return 0;
  }

  int visit(IntLit *exp) override {
    cout << to_string(exp->v);
    return 0;
  }
};

class PrintPostfix : public Visitor {
public:
  int visit(BinExp *exp) override {
    exp->left->accept(this);
    cout << " ";
    exp->right->accept(this);
    cout << " ";
    cout << exp->op;
    return 0;
  }

  int visit(UnExp *exp) override {
    exp->exp->accept(this);
    cout << (exp->op == '+' ? " +." : " -.");
    return 0;
  }

  int visit(IntLit *exp) override {
    cout << to_string(exp->v);
    return 0;
  }
};
