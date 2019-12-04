#include<iostream>

// a) f en protected
class  C1	
{	
protected: virtual void	f(){}	
  friend  class	A;	
  friend  class	B;	
public:	
  virtual void  mc1();	
};	
	
class  C2 : public virtual C1	
{
public:
 virtual void	mc2();	
};	
	
void   C1::mc1(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
void   C2::mc2(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
	
class	A	
{public:	
  virtual  void	ma(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class  B:public	virtual	A	
{public:	
  virtual  void	mb(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class	D	
{public:	
  virtual  void	md(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
int main(){C1 *c1;c1->f();C2 *c2;c2->f();}	

// b) f en private

/*
class  C1	
{	
private: virtual void	f(){}	
  friend  class	A;	
  friend  class	B;	
public:	
  virtual void  mc1();	
};	
	
class  C2 : public virtual C1	
{
public:
 virtual void	mc2();	
};	
	
void   C1::mc1(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
void   C2::mc2(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
	
class	A	
{public:	
  virtual  void	ma(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class  B:public	virtual	A	
{public:	
  virtual  void	mb(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class	D	
{public:	
  virtual  void	md(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
int main(){C1 *c1;c1->f();C2 *c2;c2->f();}	
*/

// c)- avec redefinition de C2
/*
class  C1	
{	
private: virtual void	f(){}	
  friend  class	A;	
  friend  class	B;	
public:	
  virtual void  mc1();	
};	
	
class  C2 : public virtual C1	
{
protected:virtual void f(){}
public:
 virtual void	mc2();	
 friend class D;
};	
	
void   C1::mc1(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
void   C2::mc2(){C1 *c1;c1->f();C2 *c2;	c2->f();}	
	
class	A	
{public:	
  virtual  void	ma(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class  B:public	virtual	A	
{public:	
  virtual  void	mb(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
class	D	
{public:	
  virtual  void	md(){C1	*c1;c1->f();C2 *c2;c2->f();}	
};	
	
int main(){C1 *c1;c1->f();C2 *c2;c2->f();}	
*/
