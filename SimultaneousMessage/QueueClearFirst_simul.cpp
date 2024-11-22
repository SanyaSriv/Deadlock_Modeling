/******************************
  Program "QueueClearFirst_simul.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "QueueClearFirst_simul"
#define BITS_IN_WORLD 140
#define HASHC

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_MessageState: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageState& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageState& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageState::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageState (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_MessageState (void): mu__byte(1, 3, 2) {};
  mu_1_MessageState (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -1]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -1] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageState::values[] = {"empty","response","request",NULL };

/*** end of enum declaration ***/
mu_1_MessageState mu_1_MessageState_undefined_var;

class mu_1_NodeIDs: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_NodeIDs& val) { return mu__byte::operator=((int) val); };
  mu_1_NodeIDs (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_NodeIDs (void): mu__byte(0, 1, 2) {};
  mu_1_NodeIDs (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_NodeIDs mu_1_NodeIDs_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MessageState mu_msg_type;
  mu_1_NodeIDs mu_dest_nid;
  mu_1_NodeIDs mu_src_nid;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_msg_type, b.mu_msg_type);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dest_nid, b.mu_dest_nid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src_nid, b.mu_src_nid);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_msg_type, b.mu_msg_type);
    if (w!=0) return w;
    w = Compare(a.mu_dest_nid, b.mu_dest_nid);
    if (w!=0) return w;
    w = Compare(a.mu_src_nid, b.mu_src_nid);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_msg_type.MultisetSort();
    mu_dest_nid.MultisetSort();
    mu_src_nid.MultisetSort();
  }
  void print_statistic()
  {
    mu_msg_type.print_statistic();
    mu_dest_nid.print_statistic();
    mu_src_nid.print_statistic();
  }
  void clear() {
    mu_msg_type.clear();
    mu_dest_nid.clear();
    mu_src_nid.clear();
 };
  void undefine() {
    mu_msg_type.undefine();
    mu_dest_nid.undefine();
    mu_src_nid.undefine();
 };
  void reset() {
    mu_msg_type.reset();
    mu_dest_nid.reset();
    mu_src_nid.reset();
 };
  void print() {
    mu_msg_type.print();
    mu_dest_nid.print();
    mu_src_nid.print();
  };
  void print_diff(state *prevstate) {
    mu_msg_type.print_diff(prevstate);
    mu_dest_nid.print_diff(prevstate);
    mu_src_nid.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_msg_type.to_state(thestate);
    mu_dest_nid.to_state(thestate);
    mu_src_nid.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_msg_type.value(from.mu_msg_type.value());
    mu_dest_nid.value(from.mu_dest_nid.value());
    mu_src_nid.value(from.mu_src_nid.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_msg_type.set_self_2(name, ".msg_type", os + 0 ); else mu_msg_type.set_self_2(NULL, NULL, 0);
  if (name) mu_dest_nid.set_self_2(name, ".dest_nid", os + 2 ); else mu_dest_nid.set_self_2(NULL, NULL, 0);
  if (name) mu_src_nid.set_self_2(name, ".src_nid", os + 4 ); else mu_src_nid.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu__subrange_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_6& val) { return mu__byte::operator=((int) val); };
  mu__subrange_6 (const char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_6 (void): mu__byte(0, 4, 3) {};
  mu__subrange_6 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_6 mu__subrange_6_undefined_var;

class mu_1_Queue
{
 public:
  mu_1_Message array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_Queue (const char *n, int os) { set_self(n, os); };
  mu_1_Queue ( void ) {};
  virtual ~mu_1_Queue ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 4 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1_Queue& operator= (const mu_1_Queue& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_Queue& a, mu_1_Queue& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_Queue& a, mu_1_Queue& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<5; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<5; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 5; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 5; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 5; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 5; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 5; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 5; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_Queue::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Queue::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Queue::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 6 + os);
    delete[] s;
  }
};
mu_1_Queue::~mu_1_Queue()
{
}
/*** end array declaration ***/
mu_1_Queue mu_1_Queue_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 1, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_1__type_0 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_1 (const char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1__type_0& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  mu_1__type_1 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_1__type_1& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 4 + os);
    delete[] s;
  }
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_Queue array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_Queue& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 30 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4
{
 public:
  mu_1__type_3 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1__type_3& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_4::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 60 + os);
    delete[] s;
  }
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_5& val) { return mu__byte::operator=((int) val); };
  mu_1__type_5 (const char *name, int os): mu__byte(0, 5, 3, name, os) {};
  mu_1__type_5 (void): mu__byte(0, 5, 3) {};
  mu_1__type_5 (int val): mu__byte(0, 5, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1__type_5 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_6 (const char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1__type_5& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7
{
 public:
  mu_1__type_6 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_7 (const char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1__type_6& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 1 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_7::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 2; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 6 + os);
    delete[] s;
  }
};
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu__subrange_16: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_16& val) { return mu__byte::operator=((int) val); };
  mu__subrange_16 (const char *name, int os): mu__byte(1, 4, 3, name, os) {};
  mu__subrange_16 (void): mu__byte(1, 4, 3) {};
  mu__subrange_16 (int val): mu__byte(1, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_16 mu__subrange_16_undefined_var;

class mu__subrange_17: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_17& val) { return mu__byte::operator=((int) val); };
  mu__subrange_17 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_17 (void): mu__byte(0, 1, 2) {};
  mu__subrange_17 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_17 mu__subrange_17_undefined_var;

class mu__subrange_18: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_18& val) { return mu__byte::operator=((int) val); };
  mu__subrange_18 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_18 (void): mu__byte(0, 1, 2) {};
  mu__subrange_18 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_18 mu__subrange_18_undefined_var;

class mu__subrange_19: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_19& val) { return mu__byte::operator=((int) val); };
  mu__subrange_19 (const char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_19 (void): mu__byte(0, 4, 3) {};
  mu__subrange_19 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_19 mu__subrange_19_undefined_var;

class mu__subrange_20: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_20& val) { return mu__byte::operator=((int) val); };
  mu__subrange_20 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_20 (void): mu__byte(0, 1, 2) {};
  mu__subrange_20 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_20 mu__subrange_20_undefined_var;

class mu__subrange_21: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_21& val) { return mu__byte::operator=((int) val); };
  mu__subrange_21 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_21 (void): mu__byte(0, 1, 2) {};
  mu__subrange_21 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_21 mu__subrange_21_undefined_var;

class mu__subrange_22: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_22& val) { return mu__byte::operator=((int) val); };
  mu__subrange_22 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_22 (void): mu__byte(0, 1, 2) {};
  mu__subrange_22 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_22 mu__subrange_22_undefined_var;

class mu__subrange_23: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_23& val) { return mu__byte::operator=((int) val); };
  mu__subrange_23 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_23 (void): mu__byte(0, 1, 2) {};
  mu__subrange_23 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_23 mu__subrange_23_undefined_var;

class mu__subrange_24: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_24& val) { return mu__byte::operator=((int) val); };
  mu__subrange_24 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_24 (void): mu__byte(0, 1, 2) {};
  mu__subrange_24 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_24 mu__subrange_24_undefined_var;

class mu__subrange_25: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_25& val) { return mu__byte::operator=((int) val); };
  mu__subrange_25 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_25 (void): mu__byte(0, 1, 2) {};
  mu__subrange_25 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_25 mu__subrange_25_undefined_var;

class mu__subrange_26: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_26& val) { return mu__byte::operator=((int) val); };
  mu__subrange_26 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_26 (void): mu__byte(0, 1, 2) {};
  mu__subrange_26 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_26 mu__subrange_26_undefined_var;

class mu__subrange_27: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_27& val) { return mu__byte::operator=((int) val); };
  mu__subrange_27 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_27 (void): mu__byte(0, 1, 2) {};
  mu__subrange_27 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_27 mu__subrange_27_undefined_var;

class mu__subrange_28: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_28& val) { return mu__byte::operator=((int) val); };
  mu__subrange_28 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_28 (void): mu__byte(0, 1, 2) {};
  mu__subrange_28 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_28 mu__subrange_28_undefined_var;

class mu__subrange_29: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_29& val) { return mu__byte::operator=((int) val); };
  mu__subrange_29 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_29 (void): mu__byte(0, 1, 2) {};
  mu__subrange_29 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_29 mu__subrange_29_undefined_var;

class mu__subrange_30: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_30& val) { return mu__byte::operator=((int) val); };
  mu__subrange_30 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_30 (void): mu__byte(0, 1, 2) {};
  mu__subrange_30 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_30 mu__subrange_30_undefined_var;

class mu__subrange_31: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_31& val) { return mu__byte::operator=((int) val); };
  mu__subrange_31 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_31 (void): mu__byte(0, 1, 2) {};
  mu__subrange_31 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_31 mu__subrange_31_undefined_var;

class mu__subrange_32: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_32& val) { return mu__byte::operator=((int) val); };
  mu__subrange_32 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_32 (void): mu__byte(0, 1, 2) {};
  mu__subrange_32 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_32 mu__subrange_32_undefined_var;

class mu__subrange_33: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_33& val) { return mu__byte::operator=((int) val); };
  mu__subrange_33 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_33 (void): mu__byte(0, 1, 2) {};
  mu__subrange_33 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_33 mu__subrange_33_undefined_var;

class mu__subrange_34: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_34& val) { return mu__byte::operator=((int) val); };
  mu__subrange_34 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_34 (void): mu__byte(0, 1, 2) {};
  mu__subrange_34 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_34 mu__subrange_34_undefined_var;

class mu__subrange_35: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_35& val) { return mu__byte::operator=((int) val); };
  mu__subrange_35 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_35 (void): mu__byte(0, 1, 2) {};
  mu__subrange_35 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_35 mu__subrange_35_undefined_var;

class mu__subrange_36: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_36& val) { return mu__byte::operator=((int) val); };
  mu__subrange_36 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_36 (void): mu__byte(0, 1, 2) {};
  mu__subrange_36 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_36 mu__subrange_36_undefined_var;

class mu__subrange_37: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_37& val) { return mu__byte::operator=((int) val); };
  mu__subrange_37 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_37 (void): mu__byte(0, 1, 2) {};
  mu__subrange_37 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_37 mu__subrange_37_undefined_var;

class mu__subrange_38: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_38& val) { return mu__byte::operator=((int) val); };
  mu__subrange_38 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 1, 2) {};
  mu__subrange_38 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_38 mu__subrange_38_undefined_var;

class mu__subrange_39: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_39& val) { return mu__byte::operator=((int) val); };
  mu__subrange_39 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_39 (void): mu__byte(0, 1, 2) {};
  mu__subrange_39 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_39 mu__subrange_39_undefined_var;

const int mu_NumberNodes = 2;
const int mu_BufferSpace = 5;
const int mu_empty = 1;
const int mu_response = 2;
const int mu_request = 3;
/*** Variable declaration ***/
mu_1__type_2 mu_Network("Network",0);

/*** Variable declaration ***/
mu_1__type_4 mu_IncomingQueue("IncomingQueue",8);

/*** Variable declaration ***/
mu_1__type_7 mu_TailPointers("TailPointers",128);

void mu_SendRequest(const mu_1_MessageState& mu_msg_type, const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_dest_nid)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if (mu_msg_type.isundefined())
  mu_msg_to_send.mu_msg_type.undefine();
else
  mu_msg_to_send.mu_msg_type = mu_msg_type;
if (mu_src_nid.isundefined())
  mu_msg_to_send.mu_src_nid.undefine();
else
  mu_msg_to_send.mu_src_nid = mu_src_nid;
if (mu_dest_nid.isundefined())
  mu_msg_to_send.mu_dest_nid.undefine();
else
  mu_msg_to_send.mu_dest_nid = mu_dest_nid;
mu_IncomingQueue[mu_dest_nid][mu_src_nid][mu_TailPointers[mu_dest_nid][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_dest_nid][mu_src_nid] = (mu_TailPointers[mu_dest_nid][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessResponse(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_dst_nid)
{
{
for(int mu_i = 1; mu_i <= 4; mu_i++) {
mu_IncomingQueue[mu_src_nid][mu_dst_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_dst_nid][mu_i];
mu_IncomingQueue[mu_src_nid][mu_dst_nid][mu_i].mu_msg_type = mu_empty;
};
};
mu_IncomingQueue[mu_src_nid][mu_dst_nid][(mu_TailPointers[mu_src_nid][mu_dst_nid]) - (1)].mu_msg_type = mu_empty;
mu_TailPointers[mu_src_nid][mu_dst_nid] = (mu_TailPointers[mu_src_nid][mu_dst_nid]) - (1);
};
/*** end procedure declaration ***/

void mu_ProcessRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_dst_nid)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

mu_msg_to_send.mu_msg_type = mu_response;
if (mu_src_nid.isundefined())
  mu_msg_to_send.mu_src_nid.undefine();
else
  mu_msg_to_send.mu_src_nid = mu_src_nid;
if (mu_dst_nid.isundefined())
  mu_msg_to_send.mu_dest_nid.undefine();
else
  mu_msg_to_send.mu_dest_nid = mu_dst_nid;
{
int mu__ub8 = (mu_TailPointers[mu_src_nid][mu_dst_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub8; mu_i += 1) {
mu_IncomingQueue[mu_src_nid][mu_dst_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_dst_nid][mu_i];
};
};
mu_TailPointers[mu_src_nid][mu_dst_nid] = (mu_TailPointers[mu_src_nid][mu_dst_nid]) - (1);
mu_IncomingQueue[mu_src_nid][mu_dst_nid][mu_TailPointers[mu_src_nid][mu_dst_nid]].mu_msg_type = mu_empty;
mu_IncomingQueue[mu_dst_nid][mu_src_nid][mu_TailPointers[mu_dst_nid][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_dst_nid][mu_src_nid] = (mu_TailPointers[mu_dst_nid][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Network.clear();
  mu_IncomingQueue.clear();
  mu_TailPointers.clear();
}
void world_class::undefine()
{
  mu_Network.undefine();
  mu_IncomingQueue.undefine();
  mu_TailPointers.undefine();
}
void world_class::reset()
{
  mu_Network.reset();
  mu_IncomingQueue.reset();
  mu_TailPointers.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Network.print();
  mu_IncomingQueue.print();
  mu_TailPointers.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Network.print_statistic();
  mu_IncomingQueue.print_statistic();
  mu_TailPointers.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Network.print_diff(prevstate);
    mu_IncomingQueue.print_diff(prevstate);
    mu_TailPointers.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Network.to_state( newstate );
  mu_IncomingQueue.to_state( newstate );
  mu_TailPointers.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_39 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_38 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous (Process Response + Send request), n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_39 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_38 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr9;
bool mu__boolexpr10;
bool mu__boolexpr11;
bool mu__boolexpr12;
bool mu__boolexpr13;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr10)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr9;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_39 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_38 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr14;
bool mu__boolexpr15;
bool mu__boolexpr16;
bool mu__boolexpr17;
bool mu__boolexpr18;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr18)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr14) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_39 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_38 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessResponse ( (int)mu_n1, (int)mu_n2 );
mu_SendRequest ( mu_request, (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous (Process Request -> Send Response + Send request), n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
bool mu__boolexpr24;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr19;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 8 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr25) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 4;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessRequest ( (int)mu_n1, (int)mu_n2 );
mu_SendRequest ( mu_request, (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_34 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous (Process Request -> Send Response + Process response), n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_34 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_response)) ; 
}
    return mu__boolexpr31;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_34 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr34;
bool mu__boolexpr35;
bool mu__boolexpr36;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_response)) ; 
}
	      if (mu__boolexpr34) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 8;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_34 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessRequest ( (int)mu_n1, (int)mu_n2 );
mu_ProcessResponse ( (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous Process Request -> Send Response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr37;
bool mu__boolexpr38;
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr37;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 16 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr41;
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr41) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 12;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessRequest ( (int)mu_n1, (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_31 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous Process Response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_31 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_response)) ; 
}
    return mu__boolexpr45;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu__subrange_31 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 20 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr47;
bool mu__boolexpr48;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_IncomingQueue[mu_n2][mu_n1][0].mu_msg_type) == (mu_response)) ; 
}
	      if (mu__boolexpr47) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 16;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_31 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessResponse ( (int)mu_n1, (int)mu_n2 );
mu_ProcessResponse ( (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_29 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Simultaneous Send Request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_29 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr49;
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
bool mu__boolexpr53;
bool mu__boolexpr54;
bool mu__boolexpr55;
  if (!((mu_Network[mu_n1][mu_n2]) == (1))) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_TailPointers[mu_n1][mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr49;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu__subrange_29 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 24 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
  if (!((mu_Network[mu_n1][mu_n2]) == (1))) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_TailPointers[mu_n1][mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_Network[mu_n2][mu_n1]) == (1)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_TailPointers[mu_n2][mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_TailPointers[mu_n1][mu_n2]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr56) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 20;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_29 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_SendRequest ( mu_request, (int)mu_n1, (int)mu_n2 );
mu_SendRequest ( mu_request, (int)mu_n2, (int)mu_n1 );
  };

};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Process Response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr63;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr63;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 24;
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 28 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr64;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_response))) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr64) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 24;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessResponse ( (int)mu_n1, (int)mu_n2 );
  };

};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_25 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_24 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Process Request -> Send Response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_25 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_24 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr65;
bool mu__boolexpr66;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr65;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 28;
    static mu__subrange_25 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_24 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 32 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr67;
bool mu__boolexpr68;
  if (!((mu_IncomingQueue[mu_n1][mu_n2][0].mu_msg_type) == (mu_request))) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr67) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 28;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_25 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_24 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_ProcessRequest ( (int)mu_n1, (int)mu_n2 );
  };

};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_23 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_22 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("Send Request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_23 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_22 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
bool mu__boolexpr69;
bool mu__boolexpr70;
bool mu__boolexpr71;
  if (!((mu_Network[mu_n1][mu_n2]) == (1))) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_TailPointers[mu_n1][mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr70)) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr69;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 32;
    static mu__subrange_23 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_22 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 36 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr72;
bool mu__boolexpr73;
bool mu__boolexpr74;
  if (!((mu_Network[mu_n1][mu_n2]) == (1))) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_TailPointers[mu_n1][mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_TailPointers[mu_n2][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr72) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 32;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_23 mu_n2;
    mu_n2.value((r % 2) + 0);
    r = r / 2;
    static mu__subrange_22 mu_n1;
    mu_n1.value((r % 2) + 0);
    r = r / 2;
mu_SendRequest ( mu_request, (int)mu_n1, (int)mu_n2 );
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<4)
    { R0.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<8)
    { R1.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<12)
    { R2.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<16)
    { R3.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<20)
    { R4.NextRule(what_rule);
      if (what_rule<20) return; }
  if (what_rule>=20 && what_rule<24)
    { R5.NextRule(what_rule);
      if (what_rule<24) return; }
  if (what_rule>=24 && what_rule<28)
    { R6.NextRule(what_rule);
      if (what_rule<28) return; }
  if (what_rule>=28 && what_rule<32)
    { R7.NextRule(what_rule);
      if (what_rule<32) return; }
  if (what_rule>=32 && what_rule<36)
    { R8.NextRule(what_rule);
      if (what_rule<36) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=3) return R0.Condition(r-0);
  if (r>=4 && r<=7) return R1.Condition(r-4);
  if (r>=8 && r<=11) return R2.Condition(r-8);
  if (r>=12 && r<=15) return R3.Condition(r-12);
  if (r>=16 && r<=19) return R4.Condition(r-16);
  if (r>=20 && r<=23) return R5.Condition(r-20);
  if (r>=24 && r<=27) return R6.Condition(r-24);
  if (r>=28 && r<=31) return R7.Condition(r-28);
  if (r>=32 && r<=35) return R8.Condition(r-32);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=3) { R0.Code(r-0); return; } 
  if (r>=4 && r<=7) { R1.Code(r-4); return; } 
  if (r>=8 && r<=11) { R2.Code(r-8); return; } 
  if (r>=12 && r<=15) { R3.Code(r-12); return; } 
  if (r>=16 && r<=19) { R4.Code(r-16); return; } 
  if (r>=20 && r<=23) { R5.Code(r-20); return; } 
  if (r>=24 && r<=27) { R6.Code(r-24); return; } 
  if (r>=28 && r<=31) { R7.Code(r-28); return; } 
  if (r>=32 && r<=35) { R8.Code(r-32); return; } 
}
int Priority(unsigned short r)
{
  if (r<=3) { return R0.Priority(); } 
  if (r>=4 && r<=7) { return R1.Priority(); } 
  if (r>=8 && r<=11) { return R2.Priority(); } 
  if (r>=12 && r<=15) { return R3.Priority(); } 
  if (r>=16 && r<=19) { return R4.Priority(); } 
  if (r>=20 && r<=23) { return R5.Priority(); } 
  if (r>=24 && r<=27) { return R6.Priority(); } 
  if (r>=28 && r<=31) { return R7.Priority(); } 
  if (r>=32 && r<=35) { return R8.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=3) return R0.Name(r-0);
  if (r>=4 && r<=7) return R1.Name(r-4);
  if (r>=8 && r<=11) return R2.Name(r-8);
  if (r>=12 && r<=15) return R3.Name(r-12);
  if (r>=16 && r<=19) return R4.Name(r-16);
  if (r>=20 && r<=23) return R5.Name(r-20);
  if (r>=24 && r<=27) return R6.Name(r-24);
  if (r>=28 && r<=31) return R7.Name(r-28);
  if (r>=32 && r<=35) return R8.Name(r-32);
  return NULL;
}
};
const unsigned numrules = 36;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 36


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_nid1 = 0; mu_nid1 <= 1; mu_nid1++) {
{
for(int mu_nid2 = 0; mu_nid2 <= 1; mu_nid2++) {
{
for(int mu_s = 0; mu_s <= 4; mu_s++) {
mu_IncomingQueue[mu_nid1][mu_nid2][mu_s].mu_msg_type = mu_empty;
};
};
mu_TailPointers[mu_nid1][mu_nid2] = 0;
};
};
};
};
{
for(int mu_nid = 0; mu_nid <= 1; mu_nid++) {
{
for(int mu_nid2 = 0; mu_nid2 <= 1; mu_nid2++) {
if ( (mu_nid) != (mu_nid2) )
{
mu_Network[mu_nid][mu_nid2] = 1;
}
else
{
mu_Network[mu_nid][mu_nid2] = 0;
}
};
};
};
};
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
Network:NoScalarset
IncomingQueue:NoScalarset
TailPointers:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_Network.MultisetSort();
        mu_IncomingQueue.MultisetSort();
        mu_TailPointers.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_MessageState::Permute(PermSet& Perm, int i) {};
void mu_1_MessageState::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageState::Canonicalize(PermSet& Perm) {};
void mu_1_MessageState::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageState::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageState::Limit(PermSet& Perm) {};
void mu_1_MessageState::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_NodeIDs::Permute(PermSet& Perm, int i) {};
void mu_1_NodeIDs::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_NodeIDs::Canonicalize(PermSet& Perm) {};
void mu_1_NodeIDs::SimpleLimit(PermSet& Perm) {};
void mu_1_NodeIDs::ArrayLimit(PermSet& Perm) {};
void mu_1_NodeIDs::Limit(PermSet& Perm) {};
void mu_1_NodeIDs::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm){}
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu__subrange_6::Permute(PermSet& Perm, int i) {};
void mu__subrange_6::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_6::Canonicalize(PermSet& Perm) {};
void mu__subrange_6::SimpleLimit(PermSet& Perm) {};
void mu__subrange_6::ArrayLimit(PermSet& Perm) {};
void mu__subrange_6::Limit(PermSet& Perm) {};
void mu__subrange_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Queue::Permute(PermSet& Perm, int i)
{
  static mu_1_Queue temp("Permute_mu_1_Queue",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
};
void mu_1_Queue::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_Queue::Canonicalize(PermSet& Perm){};
void mu_1_Queue::SimpleLimit(PermSet& Perm){}
void mu_1_Queue::ArrayLimit(PermSet& Perm) {}
void mu_1_Queue::Limit(PermSet& Perm){}
void mu_1_Queue::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm){};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm) {}
void mu_1__type_2::Limit(PermSet& Perm){}
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm) {}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i) {};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_5::Canonicalize(PermSet& Perm) {};
void mu_1__type_5::SimpleLimit(PermSet& Perm) {};
void mu_1__type_5::ArrayLimit(PermSet& Perm) {};
void mu_1__type_5::Limit(PermSet& Perm) {};
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm) {}
void mu_1__type_7::Limit(PermSet& Perm){}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_16::Permute(PermSet& Perm, int i) {};
void mu__subrange_16::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_16::Canonicalize(PermSet& Perm) {};
void mu__subrange_16::SimpleLimit(PermSet& Perm) {};
void mu__subrange_16::ArrayLimit(PermSet& Perm) {};
void mu__subrange_16::Limit(PermSet& Perm) {};
void mu__subrange_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_17::Permute(PermSet& Perm, int i) {};
void mu__subrange_17::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_17::Canonicalize(PermSet& Perm) {};
void mu__subrange_17::SimpleLimit(PermSet& Perm) {};
void mu__subrange_17::ArrayLimit(PermSet& Perm) {};
void mu__subrange_17::Limit(PermSet& Perm) {};
void mu__subrange_17::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_18::Permute(PermSet& Perm, int i) {};
void mu__subrange_18::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_18::Canonicalize(PermSet& Perm) {};
void mu__subrange_18::SimpleLimit(PermSet& Perm) {};
void mu__subrange_18::ArrayLimit(PermSet& Perm) {};
void mu__subrange_18::Limit(PermSet& Perm) {};
void mu__subrange_18::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_19::Permute(PermSet& Perm, int i) {};
void mu__subrange_19::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_19::Canonicalize(PermSet& Perm) {};
void mu__subrange_19::SimpleLimit(PermSet& Perm) {};
void mu__subrange_19::ArrayLimit(PermSet& Perm) {};
void mu__subrange_19::Limit(PermSet& Perm) {};
void mu__subrange_19::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_20::Permute(PermSet& Perm, int i) {};
void mu__subrange_20::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_20::Canonicalize(PermSet& Perm) {};
void mu__subrange_20::SimpleLimit(PermSet& Perm) {};
void mu__subrange_20::ArrayLimit(PermSet& Perm) {};
void mu__subrange_20::Limit(PermSet& Perm) {};
void mu__subrange_20::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_21::Permute(PermSet& Perm, int i) {};
void mu__subrange_21::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_21::Canonicalize(PermSet& Perm) {};
void mu__subrange_21::SimpleLimit(PermSet& Perm) {};
void mu__subrange_21::ArrayLimit(PermSet& Perm) {};
void mu__subrange_21::Limit(PermSet& Perm) {};
void mu__subrange_21::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_22::Permute(PermSet& Perm, int i) {};
void mu__subrange_22::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_22::Canonicalize(PermSet& Perm) {};
void mu__subrange_22::SimpleLimit(PermSet& Perm) {};
void mu__subrange_22::ArrayLimit(PermSet& Perm) {};
void mu__subrange_22::Limit(PermSet& Perm) {};
void mu__subrange_22::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_23::Permute(PermSet& Perm, int i) {};
void mu__subrange_23::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_23::Canonicalize(PermSet& Perm) {};
void mu__subrange_23::SimpleLimit(PermSet& Perm) {};
void mu__subrange_23::ArrayLimit(PermSet& Perm) {};
void mu__subrange_23::Limit(PermSet& Perm) {};
void mu__subrange_23::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_24::Permute(PermSet& Perm, int i) {};
void mu__subrange_24::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_24::Canonicalize(PermSet& Perm) {};
void mu__subrange_24::SimpleLimit(PermSet& Perm) {};
void mu__subrange_24::ArrayLimit(PermSet& Perm) {};
void mu__subrange_24::Limit(PermSet& Perm) {};
void mu__subrange_24::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_25::Permute(PermSet& Perm, int i) {};
void mu__subrange_25::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_25::Canonicalize(PermSet& Perm) {};
void mu__subrange_25::SimpleLimit(PermSet& Perm) {};
void mu__subrange_25::ArrayLimit(PermSet& Perm) {};
void mu__subrange_25::Limit(PermSet& Perm) {};
void mu__subrange_25::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_26::Permute(PermSet& Perm, int i) {};
void mu__subrange_26::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_26::Canonicalize(PermSet& Perm) {};
void mu__subrange_26::SimpleLimit(PermSet& Perm) {};
void mu__subrange_26::ArrayLimit(PermSet& Perm) {};
void mu__subrange_26::Limit(PermSet& Perm) {};
void mu__subrange_26::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_27::Permute(PermSet& Perm, int i) {};
void mu__subrange_27::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_27::Canonicalize(PermSet& Perm) {};
void mu__subrange_27::SimpleLimit(PermSet& Perm) {};
void mu__subrange_27::ArrayLimit(PermSet& Perm) {};
void mu__subrange_27::Limit(PermSet& Perm) {};
void mu__subrange_27::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_28::Permute(PermSet& Perm, int i) {};
void mu__subrange_28::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_28::Canonicalize(PermSet& Perm) {};
void mu__subrange_28::SimpleLimit(PermSet& Perm) {};
void mu__subrange_28::ArrayLimit(PermSet& Perm) {};
void mu__subrange_28::Limit(PermSet& Perm) {};
void mu__subrange_28::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_29::Permute(PermSet& Perm, int i) {};
void mu__subrange_29::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_29::Canonicalize(PermSet& Perm) {};
void mu__subrange_29::SimpleLimit(PermSet& Perm) {};
void mu__subrange_29::ArrayLimit(PermSet& Perm) {};
void mu__subrange_29::Limit(PermSet& Perm) {};
void mu__subrange_29::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_30::Permute(PermSet& Perm, int i) {};
void mu__subrange_30::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_30::Canonicalize(PermSet& Perm) {};
void mu__subrange_30::SimpleLimit(PermSet& Perm) {};
void mu__subrange_30::ArrayLimit(PermSet& Perm) {};
void mu__subrange_30::Limit(PermSet& Perm) {};
void mu__subrange_30::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_31::Permute(PermSet& Perm, int i) {};
void mu__subrange_31::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_31::Canonicalize(PermSet& Perm) {};
void mu__subrange_31::SimpleLimit(PermSet& Perm) {};
void mu__subrange_31::ArrayLimit(PermSet& Perm) {};
void mu__subrange_31::Limit(PermSet& Perm) {};
void mu__subrange_31::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_32::Permute(PermSet& Perm, int i) {};
void mu__subrange_32::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_32::Canonicalize(PermSet& Perm) {};
void mu__subrange_32::SimpleLimit(PermSet& Perm) {};
void mu__subrange_32::ArrayLimit(PermSet& Perm) {};
void mu__subrange_32::Limit(PermSet& Perm) {};
void mu__subrange_32::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_33::Permute(PermSet& Perm, int i) {};
void mu__subrange_33::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_33::Canonicalize(PermSet& Perm) {};
void mu__subrange_33::SimpleLimit(PermSet& Perm) {};
void mu__subrange_33::ArrayLimit(PermSet& Perm) {};
void mu__subrange_33::Limit(PermSet& Perm) {};
void mu__subrange_33::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_34::Permute(PermSet& Perm, int i) {};
void mu__subrange_34::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_34::Canonicalize(PermSet& Perm) {};
void mu__subrange_34::SimpleLimit(PermSet& Perm) {};
void mu__subrange_34::ArrayLimit(PermSet& Perm) {};
void mu__subrange_34::Limit(PermSet& Perm) {};
void mu__subrange_34::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_35::Permute(PermSet& Perm, int i) {};
void mu__subrange_35::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_35::Canonicalize(PermSet& Perm) {};
void mu__subrange_35::SimpleLimit(PermSet& Perm) {};
void mu__subrange_35::ArrayLimit(PermSet& Perm) {};
void mu__subrange_35::Limit(PermSet& Perm) {};
void mu__subrange_35::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_36::Permute(PermSet& Perm, int i) {};
void mu__subrange_36::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_36::Canonicalize(PermSet& Perm) {};
void mu__subrange_36::SimpleLimit(PermSet& Perm) {};
void mu__subrange_36::ArrayLimit(PermSet& Perm) {};
void mu__subrange_36::Limit(PermSet& Perm) {};
void mu__subrange_36::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_37::Permute(PermSet& Perm, int i) {};
void mu__subrange_37::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_37::Canonicalize(PermSet& Perm) {};
void mu__subrange_37::SimpleLimit(PermSet& Perm) {};
void mu__subrange_37::ArrayLimit(PermSet& Perm) {};
void mu__subrange_37::Limit(PermSet& Perm) {};
void mu__subrange_37::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_38::Permute(PermSet& Perm, int i) {};
void mu__subrange_38::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_38::Canonicalize(PermSet& Perm) {};
void mu__subrange_38::SimpleLimit(PermSet& Perm) {};
void mu__subrange_38::ArrayLimit(PermSet& Perm) {};
void mu__subrange_38::Limit(PermSet& Perm) {};
void mu__subrange_38::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_39::Permute(PermSet& Perm, int i) {};
void mu__subrange_39::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_39::Canonicalize(PermSet& Perm) {};
void mu__subrange_39::SimpleLimit(PermSet& Perm) {};
void mu__subrange_39::ArrayLimit(PermSet& Perm) {};
void mu__subrange_39::Limit(PermSet& Perm) {};
void mu__subrange_39::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_Network.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Network.MultisetSort();
              mu_IncomingQueue.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_TailPointers.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_Network.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Network.MultisetSort();
          mu_IncomingQueue.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_IncomingQueue.MultisetSort();
          mu_TailPointers.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_TailPointers.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Network.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Network.MultisetSort();
              mu_IncomingQueue.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_TailPointers.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_Network.MultisetSort();
      mu_IncomingQueue.MultisetSort();
      mu_TailPointers.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Network.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Network.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_IncomingQueue.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_IncomingQueue.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_TailPointers.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_TailPointers.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
