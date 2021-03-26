/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

template < typename T, int asize > class stack
{
public:

  stack (void)
  {
    main_array = new T (asize);
    size = asize;
    current = 0;
  }

  virtual T pop (void)
  {
    if (this->current <= 0)
      {
	cout << "index range out" << endl;
	exit (1);
      }

    return this->main_array[--this->current];
  }
  virtual void push (T value)
  {
    if (this->current >= this->size)
      {
	cout << "index range out" << endl;
	exit (1);
      }

    this->main_array[this->current++] = value;
  }

protected:

  int size, current;
  T *main_array;
};

template < typename T, int asize > class queue:stack < T, asize >
{
public:

  virtual T pop (void) override
  {
    T buf = this->main_array[0];

      this->shift ();

      return buf;
  }

  void shift (void)
  {
    for (int i = 1; i < this->size; i++)
      this->main_array[i - 1] = this->main_array[i];
    this->current--;
  }

  virtual void push (T value) override
  {
    if (this->current >= this->size)
      this->shift ();
    this->main_array[this->current++] = value;
  }

};


int
main ()
{
  stack < int, 2 > w;

  w.push (123);
  w.push (456);

  cout << w.pop () << " " << w.pop () << endl;


  queue < int, 2 > q;

  q.push (123);
  q.push (456);
  q.push (789);

  cout << q.pop () << " " << q.pop () << endl;

  return 0;
}
