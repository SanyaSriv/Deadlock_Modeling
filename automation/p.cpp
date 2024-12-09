/******************************
  Program "p.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "p"
#define BITS_IN_WORLD 236
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

  mu_1_MessageState (const char *name, int os): mu__byte(1, 5, 3, name, os) {};
  mu_1_MessageState (void): mu__byte(1, 5, 3) {};
  mu_1_MessageState (int val): mu__byte(1, 5, 3, "Parameter or function result.", 0)
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

const char *mu_1_MessageState::values[] = {"empty","response","request","fwd_request","fwd_response",NULL };

/*** end of enum declaration ***/
mu_1_MessageState mu_1_MessageState_undefined_var;

class mu_1_NodeIDs: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_NodeIDs& val) { return mu__byte::operator=((int) val); };
  mu_1_NodeIDs (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_NodeIDs (void): mu__byte(0, 2, 2) {};
  mu_1_NodeIDs (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  if (name) mu_dest_nid.set_self_2(name, ".dest_nid", os + 3 ); else mu_dest_nid.set_self_2(NULL, NULL, 0);
  if (name) mu_src_nid.set_self_2(name, ".src_nid", os + 5 ); else mu_src_nid.set_self_2(NULL, NULL, 0);
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
  mu__subrange_6 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_6 (void): mu__byte(0, 2, 2) {};
  mu__subrange_6 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu_1_Message array[ 3 ];
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
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_Queue& a, mu_1_Queue& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_Queue& a, mu_1_Queue& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 7 + os);
    delete[] s;
  }
};
mu_1_Queue::~mu_1_Queue()
{
}
/*** end array declaration ***/
mu_1_Queue mu_1_Queue_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_Queue array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_Queue& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 21 + os);
    delete[] s;
  }
};
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_1__type_0 array[ 3 ];
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
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 63 + os);
    delete[] s;
  }
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 3, 3) {};
  mu_1__type_2 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1__type_2 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1__type_2& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
    for (int i = 0; i < 3; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
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
  mu_1__type_3 array[ 3 ];
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
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 9 + os);
    delete[] s;
  }
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu__subrange_13: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_13& val) { return mu__byte::operator=((int) val); };
  mu__subrange_13 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_13 (void): mu__byte(0, 3, 3) {};
  mu__subrange_13 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_13 mu__subrange_13_undefined_var;

class mu_1__type_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_5& val) { return mu__byte::operator=((int) val); };
  mu_1__type_5 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_5 (void): mu__byte(0, 1, 2) {};
  mu_1__type_5 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
  mu_1__type_5 array[ 4 ];
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
    if ( ( index >= 0 ) && ( index <= 3 ) )
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
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<4; i++) {
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
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
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
  mu_1_NodeIDs array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_7 (const char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1_NodeIDs& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
    for (int i = 0; i < 3; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8
{
 public:
  mu_1_NodeIDs array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_8 (const char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1_NodeIDs& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
    for (int i = 0; i < 3; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_8::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_8::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu__subrange_18: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_18& val) { return mu__byte::operator=((int) val); };
  mu__subrange_18 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_18 (void): mu__byte(1, 2, 2) {};
  mu__subrange_18 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_19 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_19 (void): mu__byte(0, 2, 2) {};
  mu__subrange_19 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_20 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_20 (void): mu__byte(0, 2, 2) {};
  mu__subrange_20 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_21 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_21 (void): mu__byte(0, 2, 2) {};
  mu__subrange_21 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_22 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_22 (void): mu__byte(0, 2, 2) {};
  mu__subrange_22 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_23 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_23 (void): mu__byte(0, 2, 2) {};
  mu__subrange_23 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_24 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_24 (void): mu__byte(0, 2, 2) {};
  mu__subrange_24 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_25 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_25 (void): mu__byte(0, 2, 2) {};
  mu__subrange_25 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_26 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_26 (void): mu__byte(0, 2, 2) {};
  mu__subrange_26 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_27 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_27 (void): mu__byte(0, 2, 2) {};
  mu__subrange_27 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_28 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_28 (void): mu__byte(0, 2, 2) {};
  mu__subrange_28 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_29 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_29 (void): mu__byte(0, 2, 2) {};
  mu__subrange_29 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_30 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_30 (void): mu__byte(0, 2, 2) {};
  mu__subrange_30 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_31 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_31 (void): mu__byte(0, 2, 2) {};
  mu__subrange_31 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_32 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_32 (void): mu__byte(0, 2, 2) {};
  mu__subrange_32 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_33 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_33 (void): mu__byte(0, 2, 2) {};
  mu__subrange_33 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_34 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_34 (void): mu__byte(0, 2, 2) {};
  mu__subrange_34 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_35 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_35 (void): mu__byte(0, 2, 2) {};
  mu__subrange_35 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_36 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_36 (void): mu__byte(0, 2, 2) {};
  mu__subrange_36 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_37 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_37 (void): mu__byte(0, 2, 2) {};
  mu__subrange_37 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_38 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 2, 2) {};
  mu__subrange_38 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_39 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_39 (void): mu__byte(0, 2, 2) {};
  mu__subrange_39 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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

class mu__subrange_40: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_40& val) { return mu__byte::operator=((int) val); };
  mu__subrange_40 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_40 (void): mu__byte(0, 2, 2) {};
  mu__subrange_40 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_40 mu__subrange_40_undefined_var;

class mu__subrange_41: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_41& val) { return mu__byte::operator=((int) val); };
  mu__subrange_41 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_41 (void): mu__byte(0, 2, 2) {};
  mu__subrange_41 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_41 mu__subrange_41_undefined_var;

class mu__subrange_42: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_42& val) { return mu__byte::operator=((int) val); };
  mu__subrange_42 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_42 (void): mu__byte(0, 2, 2) {};
  mu__subrange_42 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_42 mu__subrange_42_undefined_var;

class mu__subrange_43: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_43& val) { return mu__byte::operator=((int) val); };
  mu__subrange_43 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_43 (void): mu__byte(0, 2, 2) {};
  mu__subrange_43 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_43 mu__subrange_43_undefined_var;

class mu__subrange_44: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_44& val) { return mu__byte::operator=((int) val); };
  mu__subrange_44 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_44 (void): mu__byte(0, 2, 2) {};
  mu__subrange_44 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_44 mu__subrange_44_undefined_var;

class mu__subrange_45: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_45& val) { return mu__byte::operator=((int) val); };
  mu__subrange_45 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_45 (void): mu__byte(0, 2, 2) {};
  mu__subrange_45 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_45 mu__subrange_45_undefined_var;

class mu__subrange_46: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_46& val) { return mu__byte::operator=((int) val); };
  mu__subrange_46 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_46 (void): mu__byte(0, 2, 2) {};
  mu__subrange_46 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_46 mu__subrange_46_undefined_var;

class mu__subrange_47: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_47& val) { return mu__byte::operator=((int) val); };
  mu__subrange_47 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_47 (void): mu__byte(0, 2, 2) {};
  mu__subrange_47 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_47 mu__subrange_47_undefined_var;

class mu__subrange_48: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_48& val) { return mu__byte::operator=((int) val); };
  mu__subrange_48 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_48 (void): mu__byte(0, 2, 2) {};
  mu__subrange_48 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_48 mu__subrange_48_undefined_var;

class mu__subrange_49: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_49& val) { return mu__byte::operator=((int) val); };
  mu__subrange_49 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_49 (void): mu__byte(0, 2, 2) {};
  mu__subrange_49 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_49 mu__subrange_49_undefined_var;

class mu__subrange_50: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_50& val) { return mu__byte::operator=((int) val); };
  mu__subrange_50 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_50 (void): mu__byte(0, 2, 2) {};
  mu__subrange_50 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_50 mu__subrange_50_undefined_var;

class mu__subrange_51: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_51& val) { return mu__byte::operator=((int) val); };
  mu__subrange_51 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_51 (void): mu__byte(0, 2, 2) {};
  mu__subrange_51 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_51 mu__subrange_51_undefined_var;

class mu__subrange_52: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_52& val) { return mu__byte::operator=((int) val); };
  mu__subrange_52 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_52 (void): mu__byte(0, 2, 2) {};
  mu__subrange_52 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_52 mu__subrange_52_undefined_var;

class mu__subrange_53: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_53& val) { return mu__byte::operator=((int) val); };
  mu__subrange_53 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_53 (void): mu__byte(0, 2, 2) {};
  mu__subrange_53 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_53 mu__subrange_53_undefined_var;

class mu__subrange_54: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_54& val) { return mu__byte::operator=((int) val); };
  mu__subrange_54 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_54 (void): mu__byte(0, 2, 2) {};
  mu__subrange_54 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_54 mu__subrange_54_undefined_var;

class mu__subrange_55: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_55& val) { return mu__byte::operator=((int) val); };
  mu__subrange_55 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_55 (void): mu__byte(0, 2, 2) {};
  mu__subrange_55 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_55 mu__subrange_55_undefined_var;

class mu__subrange_56: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_56& val) { return mu__byte::operator=((int) val); };
  mu__subrange_56 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_56 (void): mu__byte(0, 2, 2) {};
  mu__subrange_56 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_56 mu__subrange_56_undefined_var;

class mu__subrange_57: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_57& val) { return mu__byte::operator=((int) val); };
  mu__subrange_57 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_57 (void): mu__byte(0, 2, 2) {};
  mu__subrange_57 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_57 mu__subrange_57_undefined_var;

class mu__subrange_58: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_58& val) { return mu__byte::operator=((int) val); };
  mu__subrange_58 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_58 (void): mu__byte(0, 2, 2) {};
  mu__subrange_58 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_58 mu__subrange_58_undefined_var;

class mu__subrange_59: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_59& val) { return mu__byte::operator=((int) val); };
  mu__subrange_59 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_59 (void): mu__byte(0, 2, 2) {};
  mu__subrange_59 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_59 mu__subrange_59_undefined_var;

class mu__subrange_60: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_60& val) { return mu__byte::operator=((int) val); };
  mu__subrange_60 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_60 (void): mu__byte(0, 2, 2) {};
  mu__subrange_60 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_60 mu__subrange_60_undefined_var;

class mu__subrange_61: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_61& val) { return mu__byte::operator=((int) val); };
  mu__subrange_61 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_61 (void): mu__byte(0, 2, 2) {};
  mu__subrange_61 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_61 mu__subrange_61_undefined_var;

class mu__subrange_62: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_62& val) { return mu__byte::operator=((int) val); };
  mu__subrange_62 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_62 (void): mu__byte(0, 2, 2) {};
  mu__subrange_62 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_62 mu__subrange_62_undefined_var;

class mu__subrange_63: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_63& val) { return mu__byte::operator=((int) val); };
  mu__subrange_63 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_63 (void): mu__byte(0, 2, 2) {};
  mu__subrange_63 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_63 mu__subrange_63_undefined_var;

class mu__subrange_64: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_64& val) { return mu__byte::operator=((int) val); };
  mu__subrange_64 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_64 (void): mu__byte(0, 2, 2) {};
  mu__subrange_64 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_64 mu__subrange_64_undefined_var;

class mu__subrange_65: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_65& val) { return mu__byte::operator=((int) val); };
  mu__subrange_65 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_65 (void): mu__byte(0, 2, 2) {};
  mu__subrange_65 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_65 mu__subrange_65_undefined_var;

class mu__subrange_66: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_66& val) { return mu__byte::operator=((int) val); };
  mu__subrange_66 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_66 (void): mu__byte(0, 2, 2) {};
  mu__subrange_66 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_66 mu__subrange_66_undefined_var;

class mu__subrange_67: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_67& val) { return mu__byte::operator=((int) val); };
  mu__subrange_67 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_67 (void): mu__byte(0, 2, 2) {};
  mu__subrange_67 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_67 mu__subrange_67_undefined_var;

class mu__subrange_68: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_68& val) { return mu__byte::operator=((int) val); };
  mu__subrange_68 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_68 (void): mu__byte(0, 2, 2) {};
  mu__subrange_68 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_68 mu__subrange_68_undefined_var;

class mu__subrange_69: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_69& val) { return mu__byte::operator=((int) val); };
  mu__subrange_69 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_69 (void): mu__byte(0, 2, 2) {};
  mu__subrange_69 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_69 mu__subrange_69_undefined_var;

class mu__subrange_70: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_70& val) { return mu__byte::operator=((int) val); };
  mu__subrange_70 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_70 (void): mu__byte(0, 2, 2) {};
  mu__subrange_70 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_70 mu__subrange_70_undefined_var;

class mu__subrange_71: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_71& val) { return mu__byte::operator=((int) val); };
  mu__subrange_71 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_71 (void): mu__byte(0, 2, 2) {};
  mu__subrange_71 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_71 mu__subrange_71_undefined_var;

class mu__subrange_72: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_72& val) { return mu__byte::operator=((int) val); };
  mu__subrange_72 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_72 (void): mu__byte(0, 2, 2) {};
  mu__subrange_72 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_72 mu__subrange_72_undefined_var;

class mu__subrange_73: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_73& val) { return mu__byte::operator=((int) val); };
  mu__subrange_73 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_73 (void): mu__byte(0, 2, 2) {};
  mu__subrange_73 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_73 mu__subrange_73_undefined_var;

class mu__subrange_74: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_74& val) { return mu__byte::operator=((int) val); };
  mu__subrange_74 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_74 (void): mu__byte(0, 2, 2) {};
  mu__subrange_74 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_74 mu__subrange_74_undefined_var;

class mu__subrange_75: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_75& val) { return mu__byte::operator=((int) val); };
  mu__subrange_75 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_75 (void): mu__byte(0, 2, 2) {};
  mu__subrange_75 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_75 mu__subrange_75_undefined_var;

class mu__subrange_76: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_76& val) { return mu__byte::operator=((int) val); };
  mu__subrange_76 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_76 (void): mu__byte(0, 2, 2) {};
  mu__subrange_76 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_76 mu__subrange_76_undefined_var;

class mu__subrange_77: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_77& val) { return mu__byte::operator=((int) val); };
  mu__subrange_77 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_77 (void): mu__byte(0, 2, 2) {};
  mu__subrange_77 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_77 mu__subrange_77_undefined_var;

class mu__subrange_78: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_78& val) { return mu__byte::operator=((int) val); };
  mu__subrange_78 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_78 (void): mu__byte(0, 2, 2) {};
  mu__subrange_78 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_78 mu__subrange_78_undefined_var;

class mu__subrange_79: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_79& val) { return mu__byte::operator=((int) val); };
  mu__subrange_79 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_79 (void): mu__byte(0, 2, 2) {};
  mu__subrange_79 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_79 mu__subrange_79_undefined_var;

class mu__subrange_80: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_80& val) { return mu__byte::operator=((int) val); };
  mu__subrange_80 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_80 (void): mu__byte(0, 2, 2) {};
  mu__subrange_80 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_80 mu__subrange_80_undefined_var;

class mu__subrange_81: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_81& val) { return mu__byte::operator=((int) val); };
  mu__subrange_81 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_81 (void): mu__byte(0, 2, 2) {};
  mu__subrange_81 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_81 mu__subrange_81_undefined_var;

class mu__subrange_82: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_82& val) { return mu__byte::operator=((int) val); };
  mu__subrange_82 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_82 (void): mu__byte(0, 2, 2) {};
  mu__subrange_82 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_82 mu__subrange_82_undefined_var;

class mu__subrange_83: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_83& val) { return mu__byte::operator=((int) val); };
  mu__subrange_83 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_83 (void): mu__byte(0, 2, 2) {};
  mu__subrange_83 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_83 mu__subrange_83_undefined_var;

class mu__subrange_84: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_84& val) { return mu__byte::operator=((int) val); };
  mu__subrange_84 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_84 (void): mu__byte(0, 2, 2) {};
  mu__subrange_84 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_84 mu__subrange_84_undefined_var;

class mu__subrange_85: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_85& val) { return mu__byte::operator=((int) val); };
  mu__subrange_85 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_85 (void): mu__byte(0, 2, 2) {};
  mu__subrange_85 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_85 mu__subrange_85_undefined_var;

class mu__subrange_86: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_86& val) { return mu__byte::operator=((int) val); };
  mu__subrange_86 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_86 (void): mu__byte(0, 2, 2) {};
  mu__subrange_86 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_86 mu__subrange_86_undefined_var;

class mu__subrange_87: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_87& val) { return mu__byte::operator=((int) val); };
  mu__subrange_87 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_87 (void): mu__byte(0, 2, 2) {};
  mu__subrange_87 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_87 mu__subrange_87_undefined_var;

class mu__subrange_88: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_88& val) { return mu__byte::operator=((int) val); };
  mu__subrange_88 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_88 (void): mu__byte(0, 2, 2) {};
  mu__subrange_88 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_88 mu__subrange_88_undefined_var;

class mu__subrange_89: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_89& val) { return mu__byte::operator=((int) val); };
  mu__subrange_89 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_89 (void): mu__byte(0, 2, 2) {};
  mu__subrange_89 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_89 mu__subrange_89_undefined_var;

class mu__subrange_90: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_90& val) { return mu__byte::operator=((int) val); };
  mu__subrange_90 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_90 (void): mu__byte(0, 2, 2) {};
  mu__subrange_90 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_90 mu__subrange_90_undefined_var;

class mu__subrange_91: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_91& val) { return mu__byte::operator=((int) val); };
  mu__subrange_91 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_91 (void): mu__byte(0, 2, 2) {};
  mu__subrange_91 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_91 mu__subrange_91_undefined_var;

class mu__subrange_92: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_92& val) { return mu__byte::operator=((int) val); };
  mu__subrange_92 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_92 (void): mu__byte(0, 2, 2) {};
  mu__subrange_92 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_92 mu__subrange_92_undefined_var;

class mu__subrange_93: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_93& val) { return mu__byte::operator=((int) val); };
  mu__subrange_93 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_93 (void): mu__byte(0, 2, 2) {};
  mu__subrange_93 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_93 mu__subrange_93_undefined_var;

class mu__subrange_94: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_94& val) { return mu__byte::operator=((int) val); };
  mu__subrange_94 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_94 (void): mu__byte(0, 2, 2) {};
  mu__subrange_94 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_94 mu__subrange_94_undefined_var;

class mu__subrange_95: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_95& val) { return mu__byte::operator=((int) val); };
  mu__subrange_95 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_95 (void): mu__byte(0, 2, 2) {};
  mu__subrange_95 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_95 mu__subrange_95_undefined_var;

class mu__subrange_96: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_96& val) { return mu__byte::operator=((int) val); };
  mu__subrange_96 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_96 (void): mu__byte(0, 2, 2) {};
  mu__subrange_96 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_96 mu__subrange_96_undefined_var;

class mu__subrange_97: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_97& val) { return mu__byte::operator=((int) val); };
  mu__subrange_97 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_97 (void): mu__byte(0, 2, 2) {};
  mu__subrange_97 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_97 mu__subrange_97_undefined_var;

class mu__subrange_98: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_98& val) { return mu__byte::operator=((int) val); };
  mu__subrange_98 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_98 (void): mu__byte(0, 2, 2) {};
  mu__subrange_98 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_98 mu__subrange_98_undefined_var;

class mu__subrange_99: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_99& val) { return mu__byte::operator=((int) val); };
  mu__subrange_99 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_99 (void): mu__byte(0, 2, 2) {};
  mu__subrange_99 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_99 mu__subrange_99_undefined_var;

class mu__subrange_100: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_100& val) { return mu__byte::operator=((int) val); };
  mu__subrange_100 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_100 (void): mu__byte(0, 2, 2) {};
  mu__subrange_100 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_100 mu__subrange_100_undefined_var;

class mu__subrange_101: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_101& val) { return mu__byte::operator=((int) val); };
  mu__subrange_101 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_101 (void): mu__byte(0, 2, 2) {};
  mu__subrange_101 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_101 mu__subrange_101_undefined_var;

class mu__subrange_102: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_102& val) { return mu__byte::operator=((int) val); };
  mu__subrange_102 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_102 (void): mu__byte(0, 2, 2) {};
  mu__subrange_102 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_102 mu__subrange_102_undefined_var;

class mu__subrange_103: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_103& val) { return mu__byte::operator=((int) val); };
  mu__subrange_103 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_103 (void): mu__byte(0, 2, 2) {};
  mu__subrange_103 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_103 mu__subrange_103_undefined_var;

class mu__subrange_104: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_104& val) { return mu__byte::operator=((int) val); };
  mu__subrange_104 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_104 (void): mu__byte(0, 2, 2) {};
  mu__subrange_104 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_104 mu__subrange_104_undefined_var;

class mu__subrange_105: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_105& val) { return mu__byte::operator=((int) val); };
  mu__subrange_105 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_105 (void): mu__byte(0, 2, 2) {};
  mu__subrange_105 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_105 mu__subrange_105_undefined_var;

class mu__subrange_106: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_106& val) { return mu__byte::operator=((int) val); };
  mu__subrange_106 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_106 (void): mu__byte(0, 2, 2) {};
  mu__subrange_106 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_106 mu__subrange_106_undefined_var;

class mu__subrange_107: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_107& val) { return mu__byte::operator=((int) val); };
  mu__subrange_107 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_107 (void): mu__byte(0, 2, 2) {};
  mu__subrange_107 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_107 mu__subrange_107_undefined_var;

class mu__subrange_108: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_108& val) { return mu__byte::operator=((int) val); };
  mu__subrange_108 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_108 (void): mu__byte(0, 2, 2) {};
  mu__subrange_108 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_108 mu__subrange_108_undefined_var;

class mu__subrange_109: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_109& val) { return mu__byte::operator=((int) val); };
  mu__subrange_109 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_109 (void): mu__byte(0, 2, 2) {};
  mu__subrange_109 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_109 mu__subrange_109_undefined_var;

class mu__subrange_110: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_110& val) { return mu__byte::operator=((int) val); };
  mu__subrange_110 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_110 (void): mu__byte(0, 2, 2) {};
  mu__subrange_110 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_110 mu__subrange_110_undefined_var;

class mu__subrange_111: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_111& val) { return mu__byte::operator=((int) val); };
  mu__subrange_111 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_111 (void): mu__byte(0, 2, 2) {};
  mu__subrange_111 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_111 mu__subrange_111_undefined_var;

class mu__subrange_112: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_112& val) { return mu__byte::operator=((int) val); };
  mu__subrange_112 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_112 (void): mu__byte(0, 2, 2) {};
  mu__subrange_112 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_112 mu__subrange_112_undefined_var;

class mu__subrange_113: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_113& val) { return mu__byte::operator=((int) val); };
  mu__subrange_113 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_113 (void): mu__byte(0, 2, 2) {};
  mu__subrange_113 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_113 mu__subrange_113_undefined_var;

class mu__subrange_114: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_114& val) { return mu__byte::operator=((int) val); };
  mu__subrange_114 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_114 (void): mu__byte(0, 2, 2) {};
  mu__subrange_114 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_114 mu__subrange_114_undefined_var;

class mu__subrange_115: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_115& val) { return mu__byte::operator=((int) val); };
  mu__subrange_115 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_115 (void): mu__byte(0, 2, 2) {};
  mu__subrange_115 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_115 mu__subrange_115_undefined_var;

class mu__subrange_116: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_116& val) { return mu__byte::operator=((int) val); };
  mu__subrange_116 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_116 (void): mu__byte(0, 2, 2) {};
  mu__subrange_116 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_116 mu__subrange_116_undefined_var;

class mu__subrange_117: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_117& val) { return mu__byte::operator=((int) val); };
  mu__subrange_117 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_117 (void): mu__byte(0, 2, 2) {};
  mu__subrange_117 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_117 mu__subrange_117_undefined_var;

class mu__subrange_118: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_118& val) { return mu__byte::operator=((int) val); };
  mu__subrange_118 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_118 (void): mu__byte(0, 2, 2) {};
  mu__subrange_118 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_118 mu__subrange_118_undefined_var;

class mu__subrange_119: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_119& val) { return mu__byte::operator=((int) val); };
  mu__subrange_119 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_119 (void): mu__byte(0, 2, 2) {};
  mu__subrange_119 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_119 mu__subrange_119_undefined_var;

class mu__subrange_120: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_120& val) { return mu__byte::operator=((int) val); };
  mu__subrange_120 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_120 (void): mu__byte(0, 2, 2) {};
  mu__subrange_120 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_120 mu__subrange_120_undefined_var;

class mu__subrange_121: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_121& val) { return mu__byte::operator=((int) val); };
  mu__subrange_121 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_121 (void): mu__byte(0, 2, 2) {};
  mu__subrange_121 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_121 mu__subrange_121_undefined_var;

class mu__subrange_122: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_122& val) { return mu__byte::operator=((int) val); };
  mu__subrange_122 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_122 (void): mu__byte(0, 2, 2) {};
  mu__subrange_122 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_122 mu__subrange_122_undefined_var;

class mu__subrange_123: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_123& val) { return mu__byte::operator=((int) val); };
  mu__subrange_123 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_123 (void): mu__byte(0, 2, 2) {};
  mu__subrange_123 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_123 mu__subrange_123_undefined_var;

class mu__subrange_124: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_124& val) { return mu__byte::operator=((int) val); };
  mu__subrange_124 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_124 (void): mu__byte(0, 2, 2) {};
  mu__subrange_124 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_124 mu__subrange_124_undefined_var;

class mu__subrange_125: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_125& val) { return mu__byte::operator=((int) val); };
  mu__subrange_125 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_125 (void): mu__byte(0, 2, 2) {};
  mu__subrange_125 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_125 mu__subrange_125_undefined_var;

class mu__subrange_126: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_126& val) { return mu__byte::operator=((int) val); };
  mu__subrange_126 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_126 (void): mu__byte(0, 2, 2) {};
  mu__subrange_126 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_126 mu__subrange_126_undefined_var;

class mu__subrange_127: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_127& val) { return mu__byte::operator=((int) val); };
  mu__subrange_127 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_127 (void): mu__byte(0, 2, 2) {};
  mu__subrange_127 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_127 mu__subrange_127_undefined_var;

class mu__subrange_128: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_128& val) { return mu__byte::operator=((int) val); };
  mu__subrange_128 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_128 (void): mu__byte(0, 2, 2) {};
  mu__subrange_128 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_128 mu__subrange_128_undefined_var;

class mu__subrange_129: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_129& val) { return mu__byte::operator=((int) val); };
  mu__subrange_129 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_129 (void): mu__byte(0, 2, 2) {};
  mu__subrange_129 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_129 mu__subrange_129_undefined_var;

class mu__subrange_130: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_130& val) { return mu__byte::operator=((int) val); };
  mu__subrange_130 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_130 (void): mu__byte(0, 2, 2) {};
  mu__subrange_130 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_130 mu__subrange_130_undefined_var;

class mu__subrange_131: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_131& val) { return mu__byte::operator=((int) val); };
  mu__subrange_131 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_131 (void): mu__byte(0, 2, 2) {};
  mu__subrange_131 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_131 mu__subrange_131_undefined_var;

class mu__subrange_132: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_132& val) { return mu__byte::operator=((int) val); };
  mu__subrange_132 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_132 (void): mu__byte(0, 2, 2) {};
  mu__subrange_132 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_132 mu__subrange_132_undefined_var;

class mu__subrange_133: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_133& val) { return mu__byte::operator=((int) val); };
  mu__subrange_133 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_133 (void): mu__byte(0, 2, 2) {};
  mu__subrange_133 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_133 mu__subrange_133_undefined_var;

class mu__subrange_134: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_134& val) { return mu__byte::operator=((int) val); };
  mu__subrange_134 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_134 (void): mu__byte(0, 2, 2) {};
  mu__subrange_134 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_134 mu__subrange_134_undefined_var;

class mu__subrange_135: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_135& val) { return mu__byte::operator=((int) val); };
  mu__subrange_135 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_135 (void): mu__byte(0, 2, 2) {};
  mu__subrange_135 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_135 mu__subrange_135_undefined_var;

class mu__subrange_136: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_136& val) { return mu__byte::operator=((int) val); };
  mu__subrange_136 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_136 (void): mu__byte(0, 2, 2) {};
  mu__subrange_136 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_136 mu__subrange_136_undefined_var;

class mu__subrange_137: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_137& val) { return mu__byte::operator=((int) val); };
  mu__subrange_137 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_137 (void): mu__byte(0, 2, 2) {};
  mu__subrange_137 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_137 mu__subrange_137_undefined_var;

class mu__subrange_138: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_138& val) { return mu__byte::operator=((int) val); };
  mu__subrange_138 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_138 (void): mu__byte(0, 2, 2) {};
  mu__subrange_138 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_138 mu__subrange_138_undefined_var;

class mu__subrange_139: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_139& val) { return mu__byte::operator=((int) val); };
  mu__subrange_139 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_139 (void): mu__byte(0, 2, 2) {};
  mu__subrange_139 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_139 mu__subrange_139_undefined_var;

class mu__subrange_140: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_140& val) { return mu__byte::operator=((int) val); };
  mu__subrange_140 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_140 (void): mu__byte(0, 2, 2) {};
  mu__subrange_140 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_140 mu__subrange_140_undefined_var;

class mu__subrange_141: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_141& val) { return mu__byte::operator=((int) val); };
  mu__subrange_141 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_141 (void): mu__byte(0, 2, 2) {};
  mu__subrange_141 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_141 mu__subrange_141_undefined_var;

class mu__subrange_142: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_142& val) { return mu__byte::operator=((int) val); };
  mu__subrange_142 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_142 (void): mu__byte(0, 2, 2) {};
  mu__subrange_142 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_142 mu__subrange_142_undefined_var;

class mu__subrange_143: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_143& val) { return mu__byte::operator=((int) val); };
  mu__subrange_143 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_143 (void): mu__byte(0, 2, 2) {};
  mu__subrange_143 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_143 mu__subrange_143_undefined_var;

class mu__subrange_144: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_144& val) { return mu__byte::operator=((int) val); };
  mu__subrange_144 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_144 (void): mu__byte(0, 2, 2) {};
  mu__subrange_144 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_144 mu__subrange_144_undefined_var;

class mu__subrange_145: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_145& val) { return mu__byte::operator=((int) val); };
  mu__subrange_145 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_145 (void): mu__byte(0, 2, 2) {};
  mu__subrange_145 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_145 mu__subrange_145_undefined_var;

class mu__subrange_146: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_146& val) { return mu__byte::operator=((int) val); };
  mu__subrange_146 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_146 (void): mu__byte(0, 2, 2) {};
  mu__subrange_146 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_146 mu__subrange_146_undefined_var;

class mu__subrange_147: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_147& val) { return mu__byte::operator=((int) val); };
  mu__subrange_147 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_147 (void): mu__byte(0, 2, 2) {};
  mu__subrange_147 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_147 mu__subrange_147_undefined_var;

class mu__subrange_148: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_148& val) { return mu__byte::operator=((int) val); };
  mu__subrange_148 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_148 (void): mu__byte(0, 2, 2) {};
  mu__subrange_148 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_148 mu__subrange_148_undefined_var;

class mu__subrange_149: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_149& val) { return mu__byte::operator=((int) val); };
  mu__subrange_149 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_149 (void): mu__byte(0, 2, 2) {};
  mu__subrange_149 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_149 mu__subrange_149_undefined_var;

class mu__subrange_150: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_150& val) { return mu__byte::operator=((int) val); };
  mu__subrange_150 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_150 (void): mu__byte(0, 2, 2) {};
  mu__subrange_150 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_150 mu__subrange_150_undefined_var;

class mu__subrange_151: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_151& val) { return mu__byte::operator=((int) val); };
  mu__subrange_151 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_151 (void): mu__byte(0, 2, 2) {};
  mu__subrange_151 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_151 mu__subrange_151_undefined_var;

class mu__subrange_152: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_152& val) { return mu__byte::operator=((int) val); };
  mu__subrange_152 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_152 (void): mu__byte(0, 2, 2) {};
  mu__subrange_152 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_152 mu__subrange_152_undefined_var;

class mu__subrange_153: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_153& val) { return mu__byte::operator=((int) val); };
  mu__subrange_153 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_153 (void): mu__byte(0, 2, 2) {};
  mu__subrange_153 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_153 mu__subrange_153_undefined_var;

class mu__subrange_154: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_154& val) { return mu__byte::operator=((int) val); };
  mu__subrange_154 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_154 (void): mu__byte(0, 2, 2) {};
  mu__subrange_154 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_154 mu__subrange_154_undefined_var;

class mu__subrange_155: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_155& val) { return mu__byte::operator=((int) val); };
  mu__subrange_155 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_155 (void): mu__byte(0, 2, 2) {};
  mu__subrange_155 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_155 mu__subrange_155_undefined_var;

class mu__subrange_156: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_156& val) { return mu__byte::operator=((int) val); };
  mu__subrange_156 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_156 (void): mu__byte(0, 2, 2) {};
  mu__subrange_156 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_156 mu__subrange_156_undefined_var;

class mu__subrange_157: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_157& val) { return mu__byte::operator=((int) val); };
  mu__subrange_157 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_157 (void): mu__byte(0, 2, 2) {};
  mu__subrange_157 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_157 mu__subrange_157_undefined_var;

class mu__subrange_158: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_158& val) { return mu__byte::operator=((int) val); };
  mu__subrange_158 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_158 (void): mu__byte(0, 2, 2) {};
  mu__subrange_158 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_158 mu__subrange_158_undefined_var;

class mu__subrange_159: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_159& val) { return mu__byte::operator=((int) val); };
  mu__subrange_159 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_159 (void): mu__byte(0, 2, 2) {};
  mu__subrange_159 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_159 mu__subrange_159_undefined_var;

class mu__subrange_160: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_160& val) { return mu__byte::operator=((int) val); };
  mu__subrange_160 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_160 (void): mu__byte(0, 2, 2) {};
  mu__subrange_160 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_160 mu__subrange_160_undefined_var;

class mu__subrange_161: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_161& val) { return mu__byte::operator=((int) val); };
  mu__subrange_161 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_161 (void): mu__byte(0, 2, 2) {};
  mu__subrange_161 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_161 mu__subrange_161_undefined_var;

class mu__subrange_162: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_162& val) { return mu__byte::operator=((int) val); };
  mu__subrange_162 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_162 (void): mu__byte(0, 2, 2) {};
  mu__subrange_162 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_162 mu__subrange_162_undefined_var;

class mu__subrange_163: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_163& val) { return mu__byte::operator=((int) val); };
  mu__subrange_163 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_163 (void): mu__byte(0, 2, 2) {};
  mu__subrange_163 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_163 mu__subrange_163_undefined_var;

class mu__subrange_164: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_164& val) { return mu__byte::operator=((int) val); };
  mu__subrange_164 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_164 (void): mu__byte(0, 2, 2) {};
  mu__subrange_164 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_164 mu__subrange_164_undefined_var;

class mu__subrange_165: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_165& val) { return mu__byte::operator=((int) val); };
  mu__subrange_165 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_165 (void): mu__byte(0, 2, 2) {};
  mu__subrange_165 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_165 mu__subrange_165_undefined_var;

class mu__subrange_166: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_166& val) { return mu__byte::operator=((int) val); };
  mu__subrange_166 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_166 (void): mu__byte(0, 2, 2) {};
  mu__subrange_166 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_166 mu__subrange_166_undefined_var;

class mu__subrange_167: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_167& val) { return mu__byte::operator=((int) val); };
  mu__subrange_167 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_167 (void): mu__byte(0, 2, 2) {};
  mu__subrange_167 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_167 mu__subrange_167_undefined_var;

class mu__subrange_168: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_168& val) { return mu__byte::operator=((int) val); };
  mu__subrange_168 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_168 (void): mu__byte(0, 2, 2) {};
  mu__subrange_168 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_168 mu__subrange_168_undefined_var;

class mu__subrange_169: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_169& val) { return mu__byte::operator=((int) val); };
  mu__subrange_169 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_169 (void): mu__byte(0, 2, 2) {};
  mu__subrange_169 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_169 mu__subrange_169_undefined_var;

class mu__subrange_170: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_170& val) { return mu__byte::operator=((int) val); };
  mu__subrange_170 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_170 (void): mu__byte(0, 2, 2) {};
  mu__subrange_170 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_170 mu__subrange_170_undefined_var;

class mu__subrange_171: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_171& val) { return mu__byte::operator=((int) val); };
  mu__subrange_171 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_171 (void): mu__byte(0, 2, 2) {};
  mu__subrange_171 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_171 mu__subrange_171_undefined_var;

class mu__subrange_172: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_172& val) { return mu__byte::operator=((int) val); };
  mu__subrange_172 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_172 (void): mu__byte(0, 2, 2) {};
  mu__subrange_172 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_172 mu__subrange_172_undefined_var;

class mu__subrange_173: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_173& val) { return mu__byte::operator=((int) val); };
  mu__subrange_173 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_173 (void): mu__byte(0, 2, 2) {};
  mu__subrange_173 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_173 mu__subrange_173_undefined_var;

class mu__subrange_174: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_174& val) { return mu__byte::operator=((int) val); };
  mu__subrange_174 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_174 (void): mu__byte(0, 2, 2) {};
  mu__subrange_174 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_174 mu__subrange_174_undefined_var;

class mu__subrange_175: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_175& val) { return mu__byte::operator=((int) val); };
  mu__subrange_175 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_175 (void): mu__byte(0, 2, 2) {};
  mu__subrange_175 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_175 mu__subrange_175_undefined_var;

class mu__subrange_176: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_176& val) { return mu__byte::operator=((int) val); };
  mu__subrange_176 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_176 (void): mu__byte(0, 2, 2) {};
  mu__subrange_176 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_176 mu__subrange_176_undefined_var;

class mu__subrange_177: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_177& val) { return mu__byte::operator=((int) val); };
  mu__subrange_177 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_177 (void): mu__byte(0, 2, 2) {};
  mu__subrange_177 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_177 mu__subrange_177_undefined_var;

class mu__subrange_178: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_178& val) { return mu__byte::operator=((int) val); };
  mu__subrange_178 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_178 (void): mu__byte(0, 2, 2) {};
  mu__subrange_178 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_178 mu__subrange_178_undefined_var;

class mu__subrange_179: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_179& val) { return mu__byte::operator=((int) val); };
  mu__subrange_179 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_179 (void): mu__byte(0, 2, 2) {};
  mu__subrange_179 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_179 mu__subrange_179_undefined_var;

class mu__subrange_180: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_180& val) { return mu__byte::operator=((int) val); };
  mu__subrange_180 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_180 (void): mu__byte(0, 2, 2) {};
  mu__subrange_180 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_180 mu__subrange_180_undefined_var;

class mu__subrange_181: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_181& val) { return mu__byte::operator=((int) val); };
  mu__subrange_181 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_181 (void): mu__byte(0, 2, 2) {};
  mu__subrange_181 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_181 mu__subrange_181_undefined_var;

class mu__subrange_182: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_182& val) { return mu__byte::operator=((int) val); };
  mu__subrange_182 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_182 (void): mu__byte(0, 2, 2) {};
  mu__subrange_182 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_182 mu__subrange_182_undefined_var;

class mu__subrange_183: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_183& val) { return mu__byte::operator=((int) val); };
  mu__subrange_183 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_183 (void): mu__byte(0, 2, 2) {};
  mu__subrange_183 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_183 mu__subrange_183_undefined_var;

class mu__subrange_184: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_184& val) { return mu__byte::operator=((int) val); };
  mu__subrange_184 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_184 (void): mu__byte(0, 2, 2) {};
  mu__subrange_184 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_184 mu__subrange_184_undefined_var;

class mu__subrange_185: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_185& val) { return mu__byte::operator=((int) val); };
  mu__subrange_185 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_185 (void): mu__byte(0, 2, 2) {};
  mu__subrange_185 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_185 mu__subrange_185_undefined_var;

class mu__subrange_186: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_186& val) { return mu__byte::operator=((int) val); };
  mu__subrange_186 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_186 (void): mu__byte(0, 2, 2) {};
  mu__subrange_186 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_186 mu__subrange_186_undefined_var;

class mu__subrange_187: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_187& val) { return mu__byte::operator=((int) val); };
  mu__subrange_187 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_187 (void): mu__byte(0, 2, 2) {};
  mu__subrange_187 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_187 mu__subrange_187_undefined_var;

class mu__subrange_188: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_188& val) { return mu__byte::operator=((int) val); };
  mu__subrange_188 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_188 (void): mu__byte(0, 2, 2) {};
  mu__subrange_188 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_188 mu__subrange_188_undefined_var;

class mu__subrange_189: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_189& val) { return mu__byte::operator=((int) val); };
  mu__subrange_189 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_189 (void): mu__byte(0, 2, 2) {};
  mu__subrange_189 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_189 mu__subrange_189_undefined_var;

class mu__subrange_190: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_190& val) { return mu__byte::operator=((int) val); };
  mu__subrange_190 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_190 (void): mu__byte(0, 2, 2) {};
  mu__subrange_190 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_190 mu__subrange_190_undefined_var;

const int mu_NumberNodes = 3;
const int mu_BufferSpace = 3;
const int mu_empty = 1;
const int mu_response = 2;
const int mu_request = 3;
const int mu_fwd_request = 4;
const int mu_fwd_response = 5;
/*** Variable declaration ***/
mu_1__type_1 mu_IncomingQueue("IncomingQueue",0);

/*** Variable declaration ***/
mu_1__type_4 mu_TailPointers("TailPointers",189);

/*** Variable declaration ***/
mu_1__type_6 mu_RouterStatus("RouterStatus",216);

/*** Variable declaration ***/
mu_1__type_7 mu_ExitPath("ExitPath",224);

/*** Variable declaration ***/
mu_1__type_8 mu_EntryPath("EntryPath",230);

void mu_SendRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_next_hop, const mu_1_NodeIDs& mu_msg_dest)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_next_hop) == (mu_msg_dest) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
if (mu_src_nid.isundefined())
  mu_msg_to_send.mu_src_nid.undefine();
else
  mu_msg_to_send.mu_src_nid = mu_src_nid;
if (mu_msg_dest.isundefined())
  mu_msg_to_send.mu_dest_nid.undefine();
else
  mu_msg_to_send.mu_dest_nid = mu_msg_dest;
mu_IncomingQueue[mu_next_hop][mu_src_nid][mu_TailPointers[mu_next_hop][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_next_hop][mu_src_nid] = (mu_TailPointers[mu_next_hop][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessFwdRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_incom_to_src_nid, const mu_1_NodeIDs& mu_next_hop)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_dest_nid) == (mu_next_hop) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
mu_msg_to_send.mu_src_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_src_nid;
mu_msg_to_send.mu_dest_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_dest_nid;
{
int mu__ub9 = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub9; mu_i += 1) {
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_i];
};
};
mu_TailPointers[mu_src_nid][mu_incom_to_src_nid] = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]].mu_msg_type = mu_empty;
mu_IncomingQueue[mu_next_hop][mu_src_nid][mu_TailPointers[mu_next_hop][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_next_hop][mu_src_nid] = (mu_TailPointers[mu_next_hop][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_incom_to_src_nid, const mu_1_NodeIDs& mu_next_hop)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_src_nid) == (mu_next_hop) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_dest_nid;
mu_msg_to_send.mu_dest_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_src_nid;
{
int mu__ub10 = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub10; mu_i += 1) {
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_i];
};
};
mu_TailPointers[mu_src_nid][mu_incom_to_src_nid] = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]].mu_msg_type = mu_empty;
mu_IncomingQueue[mu_next_hop][mu_src_nid][mu_TailPointers[mu_next_hop][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_next_hop][mu_src_nid] = (mu_TailPointers[mu_next_hop][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessFwdResponse(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_incom_to_src_nid, const mu_1_NodeIDs& mu_next_hop)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_dest_nid) == (mu_next_hop) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_src_nid;
mu_msg_to_send.mu_dest_nid = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][0].mu_dest_nid;
{
int mu__ub11 = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub11; mu_i += 1) {
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_i];
};
};
mu_TailPointers[mu_src_nid][mu_incom_to_src_nid] = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]].mu_msg_type = mu_empty;
mu_IncomingQueue[mu_next_hop][mu_src_nid][mu_TailPointers[mu_next_hop][mu_src_nid]] = mu_msg_to_send;
mu_TailPointers[mu_next_hop][mu_src_nid] = (mu_TailPointers[mu_next_hop][mu_src_nid]) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessResponse(const mu_1_NodeIDs& mu_src_nid, const mu_1_NodeIDs& mu_incom_to_src_nid)
{
{
for(int mu_i = 1; mu_i <= 2; mu_i++) {
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][(mu_i) - (1)] = mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_i];
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][mu_i].mu_msg_type = mu_empty;
};
};
mu_IncomingQueue[mu_src_nid][mu_incom_to_src_nid][(mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1)].mu_msg_type = mu_empty;
mu_TailPointers[mu_src_nid][mu_incom_to_src_nid] = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_IncomingQueue.clear();
  mu_TailPointers.clear();
  mu_RouterStatus.clear();
  mu_ExitPath.clear();
  mu_EntryPath.clear();
}
void world_class::undefine()
{
  mu_IncomingQueue.undefine();
  mu_TailPointers.undefine();
  mu_RouterStatus.undefine();
  mu_ExitPath.undefine();
  mu_EntryPath.undefine();
}
void world_class::reset()
{
  mu_IncomingQueue.reset();
  mu_TailPointers.reset();
  mu_RouterStatus.reset();
  mu_ExitPath.reset();
  mu_EntryPath.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_IncomingQueue.print();
  mu_TailPointers.print();
  mu_RouterStatus.print();
  mu_ExitPath.print();
  mu_EntryPath.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_IncomingQueue.print_statistic();
  mu_TailPointers.print_statistic();
  mu_RouterStatus.print_statistic();
  mu_ExitPath.print_statistic();
  mu_EntryPath.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_IncomingQueue.print_diff(prevstate);
    mu_TailPointers.print_diff(prevstate);
    mu_RouterStatus.print_diff(prevstate);
    mu_ExitPath.print_diff(prevstate);
    mu_EntryPath.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_IncomingQueue.to_state( newstate );
  mu_TailPointers.to_state( newstate );
  mu_RouterStatus.to_state( newstate );
  mu_ExitPath.to_state( newstate );
  mu_EntryPath.to_state( newstate );
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
    static mu__subrange_190 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_189 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_188 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process response + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_190 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_189 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_188 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr12;
bool mu__boolexpr13;
bool mu__boolexpr14;
bool mu__boolexpr15;
bool mu__boolexpr16;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr12;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_190 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_189 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_188 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 27 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr18)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr17) {
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
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_190 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_189 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_188 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessResponse ( (int)mu_n1, mu_EntryPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr22;
bool mu__boolexpr23;
bool mu__boolexpr24;
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr22;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 27;
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 54 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr28) {
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
    r = what_rule - 27;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_184 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_183 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_182 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_184 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_183 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_182 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr34;
bool mu__boolexpr35;
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr34;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 54;
    static mu__subrange_184 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_183 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_182 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 81 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr41;
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr45)) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_n2) != (mu_n3)) ; 
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
    r = what_rule - 54;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_184 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_183 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_182 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_181 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_180 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_179 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_181 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_180 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_179 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr48;
bool mu__boolexpr49;
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
bool mu__boolexpr53;
bool mu__boolexpr54;
bool mu__boolexpr55;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr48;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 81;
    static mu__subrange_181 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_180 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_179 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 108 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_n2) != (mu_n3)) ; 
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
    r = what_rule - 81;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_181 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_180 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_179 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_178 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_177 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_176 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_178 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_177 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_176 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr64;
bool mu__boolexpr65;
bool mu__boolexpr66;
bool mu__boolexpr67;
bool mu__boolexpr68;
bool mu__boolexpr69;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr69)) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr64;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 108;
    static mu__subrange_178 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_177 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_176 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 135 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
bool mu__boolexpr73;
bool mu__boolexpr74;
bool mu__boolexpr75;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr70) {
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
    r = what_rule - 108;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_178 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_177 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_176 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_175 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_174 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_173 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_175 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_174 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_173 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr76;
bool mu__boolexpr77;
bool mu__boolexpr78;
bool mu__boolexpr79;
bool mu__boolexpr80;
bool mu__boolexpr81;
bool mu__boolexpr82;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr80)) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr79)) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr78)) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr76;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 135;
    static mu__subrange_175 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_174 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_173 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 162 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr83;
bool mu__boolexpr84;
bool mu__boolexpr85;
bool mu__boolexpr86;
bool mu__boolexpr87;
bool mu__boolexpr88;
bool mu__boolexpr89;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr88)) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr86)) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr84)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr83) {
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
    r = what_rule - 135;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_175 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_174 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_173 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr90;
bool mu__boolexpr91;
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
bool mu__boolexpr95;
bool mu__boolexpr96;
bool mu__boolexpr97;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr97)) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr92)) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr90;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 162;
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 189 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr98;
bool mu__boolexpr99;
bool mu__boolexpr100;
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
bool mu__boolexpr105;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr105 = FALSE ;
  else {
  mu__boolexpr105 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr105)) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr99)) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr98) {
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
    r = what_rule - 162;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_169 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_168 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_167 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_169 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_168 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_167 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr106;
bool mu__boolexpr107;
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
bool mu__boolexpr111;
bool mu__boolexpr112;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr112)) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr110)) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr109)) mu__boolexpr108 = FALSE ;
  else {
  mu__boolexpr108 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr108)) mu__boolexpr107 = FALSE ;
  else {
  mu__boolexpr107 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr107)) mu__boolexpr106 = FALSE ;
  else {
  mu__boolexpr106 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr106;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 189;
    static mu__subrange_169 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_168 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_167 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 216 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr113;
bool mu__boolexpr114;
bool mu__boolexpr115;
bool mu__boolexpr116;
bool mu__boolexpr117;
bool mu__boolexpr118;
bool mu__boolexpr119;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr119 = FALSE ;
  else {
  mu__boolexpr119 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr119)) mu__boolexpr118 = FALSE ;
  else {
  mu__boolexpr118 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr118)) mu__boolexpr117 = FALSE ;
  else {
  mu__boolexpr117 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr117)) mu__boolexpr116 = FALSE ;
  else {
  mu__boolexpr116 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr116)) mu__boolexpr115 = FALSE ;
  else {
  mu__boolexpr115 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr115)) mu__boolexpr114 = FALSE ;
  else {
  mu__boolexpr114 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr114)) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr113) {
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
    r = what_rule - 189;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_169 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_168 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_167 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_166 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_165 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_164 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_166 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_165 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_164 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr120;
bool mu__boolexpr121;
bool mu__boolexpr122;
bool mu__boolexpr123;
bool mu__boolexpr124;
bool mu__boolexpr125;
bool mu__boolexpr126;
bool mu__boolexpr127;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr127 = FALSE ;
  else {
  mu__boolexpr127 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr127)) mu__boolexpr126 = FALSE ;
  else {
  mu__boolexpr126 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr126)) mu__boolexpr125 = FALSE ;
  else {
  mu__boolexpr125 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr125)) mu__boolexpr124 = FALSE ;
  else {
  mu__boolexpr124 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr124)) mu__boolexpr123 = FALSE ;
  else {
  mu__boolexpr123 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr123)) mu__boolexpr122 = FALSE ;
  else {
  mu__boolexpr122 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr122)) mu__boolexpr121 = FALSE ;
  else {
  mu__boolexpr121 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr121)) mu__boolexpr120 = FALSE ;
  else {
  mu__boolexpr120 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr120;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 216;
    static mu__subrange_166 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_165 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_164 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 243 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr128;
bool mu__boolexpr129;
bool mu__boolexpr130;
bool mu__boolexpr131;
bool mu__boolexpr132;
bool mu__boolexpr133;
bool mu__boolexpr134;
bool mu__boolexpr135;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr135 = FALSE ;
  else {
  mu__boolexpr135 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr135)) mu__boolexpr134 = FALSE ;
  else {
  mu__boolexpr134 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr134)) mu__boolexpr133 = FALSE ;
  else {
  mu__boolexpr133 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr133)) mu__boolexpr132 = FALSE ;
  else {
  mu__boolexpr132 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr132)) mu__boolexpr131 = FALSE ;
  else {
  mu__boolexpr131 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr131)) mu__boolexpr130 = FALSE ;
  else {
  mu__boolexpr130 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr130)) mu__boolexpr129 = FALSE ;
  else {
  mu__boolexpr129 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr129)) mu__boolexpr128 = FALSE ;
  else {
  mu__boolexpr128 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr128) {
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
    r = what_rule - 216;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_166 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_165 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_164 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_163 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_162 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_161 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_163 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_162 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_161 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr136;
bool mu__boolexpr137;
bool mu__boolexpr138;
bool mu__boolexpr139;
bool mu__boolexpr140;
bool mu__boolexpr141;
bool mu__boolexpr142;
bool mu__boolexpr143;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr143 = FALSE ;
  else {
  mu__boolexpr143 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr143)) mu__boolexpr142 = FALSE ;
  else {
  mu__boolexpr142 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr142)) mu__boolexpr141 = FALSE ;
  else {
  mu__boolexpr141 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr141)) mu__boolexpr140 = FALSE ;
  else {
  mu__boolexpr140 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr140)) mu__boolexpr139 = FALSE ;
  else {
  mu__boolexpr139 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr139)) mu__boolexpr138 = FALSE ;
  else {
  mu__boolexpr138 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr138)) mu__boolexpr137 = FALSE ;
  else {
  mu__boolexpr137 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr137)) mu__boolexpr136 = FALSE ;
  else {
  mu__boolexpr136 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr136;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 243;
    static mu__subrange_163 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_162 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_161 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 270 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr144;
bool mu__boolexpr145;
bool mu__boolexpr146;
bool mu__boolexpr147;
bool mu__boolexpr148;
bool mu__boolexpr149;
bool mu__boolexpr150;
bool mu__boolexpr151;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr151 = FALSE ;
  else {
  mu__boolexpr151 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr151)) mu__boolexpr150 = FALSE ;
  else {
  mu__boolexpr150 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr150)) mu__boolexpr149 = FALSE ;
  else {
  mu__boolexpr149 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr149)) mu__boolexpr148 = FALSE ;
  else {
  mu__boolexpr148 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr148)) mu__boolexpr147 = FALSE ;
  else {
  mu__boolexpr147 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr147)) mu__boolexpr146 = FALSE ;
  else {
  mu__boolexpr146 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr146)) mu__boolexpr145 = FALSE ;
  else {
  mu__boolexpr145 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr145)) mu__boolexpr144 = FALSE ;
  else {
  mu__boolexpr144 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr144) {
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
    r = what_rule - 243;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_163 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_162 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_161 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_160 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_159 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_158 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_160 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_159 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_158 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr152;
bool mu__boolexpr153;
bool mu__boolexpr154;
bool mu__boolexpr155;
bool mu__boolexpr156;
bool mu__boolexpr157;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr157 = FALSE ;
  else {
  mu__boolexpr157 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr157)) mu__boolexpr156 = FALSE ;
  else {
  mu__boolexpr156 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr156)) mu__boolexpr155 = FALSE ;
  else {
  mu__boolexpr155 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr155)) mu__boolexpr154 = FALSE ;
  else {
  mu__boolexpr154 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr154)) mu__boolexpr153 = FALSE ;
  else {
  mu__boolexpr153 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr153)) mu__boolexpr152 = FALSE ;
  else {
  mu__boolexpr152 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr152;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 270;
    static mu__subrange_160 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_159 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_158 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 297 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr158;
bool mu__boolexpr159;
bool mu__boolexpr160;
bool mu__boolexpr161;
bool mu__boolexpr162;
bool mu__boolexpr163;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr163 = FALSE ;
  else {
  mu__boolexpr163 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr163)) mu__boolexpr162 = FALSE ;
  else {
  mu__boolexpr162 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr162)) mu__boolexpr161 = FALSE ;
  else {
  mu__boolexpr161 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr161)) mu__boolexpr160 = FALSE ;
  else {
  mu__boolexpr160 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr160)) mu__boolexpr159 = FALSE ;
  else {
  mu__boolexpr159 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr159)) mu__boolexpr158 = FALSE ;
  else {
  mu__boolexpr158 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr158) {
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
    r = what_rule - 270;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_160 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_159 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_158 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
  };

};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_157 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_156 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_155 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_157 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_156 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_155 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr164;
bool mu__boolexpr165;
bool mu__boolexpr166;
bool mu__boolexpr167;
bool mu__boolexpr168;
bool mu__boolexpr169;
bool mu__boolexpr170;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr170 = FALSE ;
  else {
  mu__boolexpr170 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr170)) mu__boolexpr169 = FALSE ;
  else {
  mu__boolexpr169 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr169)) mu__boolexpr168 = FALSE ;
  else {
  mu__boolexpr168 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr168)) mu__boolexpr167 = FALSE ;
  else {
  mu__boolexpr167 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr167)) mu__boolexpr166 = FALSE ;
  else {
  mu__boolexpr166 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr166)) mu__boolexpr165 = FALSE ;
  else {
  mu__boolexpr165 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr165)) mu__boolexpr164 = FALSE ;
  else {
  mu__boolexpr164 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr164;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 297;
    static mu__subrange_157 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_156 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_155 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 324 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr171;
bool mu__boolexpr172;
bool mu__boolexpr173;
bool mu__boolexpr174;
bool mu__boolexpr175;
bool mu__boolexpr176;
bool mu__boolexpr177;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr177 = FALSE ;
  else {
  mu__boolexpr177 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr177)) mu__boolexpr176 = FALSE ;
  else {
  mu__boolexpr176 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr176)) mu__boolexpr175 = FALSE ;
  else {
  mu__boolexpr175 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr175)) mu__boolexpr174 = FALSE ;
  else {
  mu__boolexpr174 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr174)) mu__boolexpr173 = FALSE ;
  else {
  mu__boolexpr173 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr173)) mu__boolexpr172 = FALSE ;
  else {
  mu__boolexpr172 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr172)) mu__boolexpr171 = FALSE ;
  else {
  mu__boolexpr171 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr171) {
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
    r = what_rule - 297;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_157 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_156 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_155 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
  };

};
/******************** RuleBase12 ********************/
class RuleBase12
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_154 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_153 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_152 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_154 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_153 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_152 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr178;
bool mu__boolexpr179;
bool mu__boolexpr180;
bool mu__boolexpr181;
bool mu__boolexpr182;
bool mu__boolexpr183;
bool mu__boolexpr184;
bool mu__boolexpr185;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr185 = FALSE ;
  else {
  mu__boolexpr185 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr185)) mu__boolexpr184 = FALSE ;
  else {
  mu__boolexpr184 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr184)) mu__boolexpr183 = FALSE ;
  else {
  mu__boolexpr183 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr183)) mu__boolexpr182 = FALSE ;
  else {
  mu__boolexpr182 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr182)) mu__boolexpr181 = FALSE ;
  else {
  mu__boolexpr181 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr181)) mu__boolexpr180 = FALSE ;
  else {
  mu__boolexpr180 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr180)) mu__boolexpr179 = FALSE ;
  else {
  mu__boolexpr179 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr179)) mu__boolexpr178 = FALSE ;
  else {
  mu__boolexpr178 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr178;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 324;
    static mu__subrange_154 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_153 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_152 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 351 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr186;
bool mu__boolexpr187;
bool mu__boolexpr188;
bool mu__boolexpr189;
bool mu__boolexpr190;
bool mu__boolexpr191;
bool mu__boolexpr192;
bool mu__boolexpr193;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr193 = FALSE ;
  else {
  mu__boolexpr193 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr193)) mu__boolexpr192 = FALSE ;
  else {
  mu__boolexpr192 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr192)) mu__boolexpr191 = FALSE ;
  else {
  mu__boolexpr191 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr191)) mu__boolexpr190 = FALSE ;
  else {
  mu__boolexpr190 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr190)) mu__boolexpr189 = FALSE ;
  else {
  mu__boolexpr189 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr189)) mu__boolexpr188 = FALSE ;
  else {
  mu__boolexpr188 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr188)) mu__boolexpr187 = FALSE ;
  else {
  mu__boolexpr187 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr187)) mu__boolexpr186 = FALSE ;
  else {
  mu__boolexpr186 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr186) {
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
    r = what_rule - 324;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_154 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_153 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_152 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase13 ********************/
class RuleBase13
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_151 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_150 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_149 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_151 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_150 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_149 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr194;
bool mu__boolexpr195;
bool mu__boolexpr196;
bool mu__boolexpr197;
bool mu__boolexpr198;
bool mu__boolexpr199;
bool mu__boolexpr200;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr200 = FALSE ;
  else {
  mu__boolexpr200 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr200)) mu__boolexpr199 = FALSE ;
  else {
  mu__boolexpr199 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr199)) mu__boolexpr198 = FALSE ;
  else {
  mu__boolexpr198 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr198)) mu__boolexpr197 = FALSE ;
  else {
  mu__boolexpr197 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr197)) mu__boolexpr196 = FALSE ;
  else {
  mu__boolexpr196 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr196)) mu__boolexpr195 = FALSE ;
  else {
  mu__boolexpr195 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr195)) mu__boolexpr194 = FALSE ;
  else {
  mu__boolexpr194 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr194;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 351;
    static mu__subrange_151 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_150 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_149 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 378 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr201;
bool mu__boolexpr202;
bool mu__boolexpr203;
bool mu__boolexpr204;
bool mu__boolexpr205;
bool mu__boolexpr206;
bool mu__boolexpr207;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr207 = FALSE ;
  else {
  mu__boolexpr207 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr207)) mu__boolexpr206 = FALSE ;
  else {
  mu__boolexpr206 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr206)) mu__boolexpr205 = FALSE ;
  else {
  mu__boolexpr205 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr205)) mu__boolexpr204 = FALSE ;
  else {
  mu__boolexpr204 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr204)) mu__boolexpr203 = FALSE ;
  else {
  mu__boolexpr203 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr203)) mu__boolexpr202 = FALSE ;
  else {
  mu__boolexpr202 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr202)) mu__boolexpr201 = FALSE ;
  else {
  mu__boolexpr201 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr201) {
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
    r = what_rule - 351;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_151 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_150 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_149 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
  };

};
/******************** RuleBase14 ********************/
class RuleBase14
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_148 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_147 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_146 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_148 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_147 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_146 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr208;
bool mu__boolexpr209;
bool mu__boolexpr210;
bool mu__boolexpr211;
bool mu__boolexpr212;
bool mu__boolexpr213;
bool mu__boolexpr214;
bool mu__boolexpr215;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr215 = FALSE ;
  else {
  mu__boolexpr215 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr215)) mu__boolexpr214 = FALSE ;
  else {
  mu__boolexpr214 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr214)) mu__boolexpr213 = FALSE ;
  else {
  mu__boolexpr213 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr213)) mu__boolexpr212 = FALSE ;
  else {
  mu__boolexpr212 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr212)) mu__boolexpr211 = FALSE ;
  else {
  mu__boolexpr211 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr211)) mu__boolexpr210 = FALSE ;
  else {
  mu__boolexpr210 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr210)) mu__boolexpr209 = FALSE ;
  else {
  mu__boolexpr209 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr209)) mu__boolexpr208 = FALSE ;
  else {
  mu__boolexpr208 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr208;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 378;
    static mu__subrange_148 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_147 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_146 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 405 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr216;
bool mu__boolexpr217;
bool mu__boolexpr218;
bool mu__boolexpr219;
bool mu__boolexpr220;
bool mu__boolexpr221;
bool mu__boolexpr222;
bool mu__boolexpr223;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr223 = FALSE ;
  else {
  mu__boolexpr223 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr223)) mu__boolexpr222 = FALSE ;
  else {
  mu__boolexpr222 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr222)) mu__boolexpr221 = FALSE ;
  else {
  mu__boolexpr221 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr221)) mu__boolexpr220 = FALSE ;
  else {
  mu__boolexpr220 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr220)) mu__boolexpr219 = FALSE ;
  else {
  mu__boolexpr219 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr219)) mu__boolexpr218 = FALSE ;
  else {
  mu__boolexpr218 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr218)) mu__boolexpr217 = FALSE ;
  else {
  mu__boolexpr217 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr217)) mu__boolexpr216 = FALSE ;
  else {
  mu__boolexpr216 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr216) {
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
    r = what_rule - 378;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_148 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_147 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_146 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase15 ********************/
class RuleBase15
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_145 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_144 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_143 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_145 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_144 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_143 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr224;
bool mu__boolexpr225;
bool mu__boolexpr226;
bool mu__boolexpr227;
bool mu__boolexpr228;
bool mu__boolexpr229;
bool mu__boolexpr230;
bool mu__boolexpr231;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr231 = FALSE ;
  else {
  mu__boolexpr231 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr231)) mu__boolexpr230 = FALSE ;
  else {
  mu__boolexpr230 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr230)) mu__boolexpr229 = FALSE ;
  else {
  mu__boolexpr229 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr229)) mu__boolexpr228 = FALSE ;
  else {
  mu__boolexpr228 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr228)) mu__boolexpr227 = FALSE ;
  else {
  mu__boolexpr227 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr227)) mu__boolexpr226 = FALSE ;
  else {
  mu__boolexpr226 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr226)) mu__boolexpr225 = FALSE ;
  else {
  mu__boolexpr225 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr225)) mu__boolexpr224 = FALSE ;
  else {
  mu__boolexpr224 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr224;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 405;
    static mu__subrange_145 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_144 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_143 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 432 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr232;
bool mu__boolexpr233;
bool mu__boolexpr234;
bool mu__boolexpr235;
bool mu__boolexpr236;
bool mu__boolexpr237;
bool mu__boolexpr238;
bool mu__boolexpr239;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr239 = FALSE ;
  else {
  mu__boolexpr239 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr239)) mu__boolexpr238 = FALSE ;
  else {
  mu__boolexpr238 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr238)) mu__boolexpr237 = FALSE ;
  else {
  mu__boolexpr237 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr237)) mu__boolexpr236 = FALSE ;
  else {
  mu__boolexpr236 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr236)) mu__boolexpr235 = FALSE ;
  else {
  mu__boolexpr235 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr235)) mu__boolexpr234 = FALSE ;
  else {
  mu__boolexpr234 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr234)) mu__boolexpr233 = FALSE ;
  else {
  mu__boolexpr233 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr233)) mu__boolexpr232 = FALSE ;
  else {
  mu__boolexpr232 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr232) {
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
    r = what_rule - 405;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_145 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_144 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_143 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase16 ********************/
class RuleBase16
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_142 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_141 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_140 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_142 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_141 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_140 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr240;
bool mu__boolexpr241;
bool mu__boolexpr242;
bool mu__boolexpr243;
bool mu__boolexpr244;
bool mu__boolexpr245;
bool mu__boolexpr246;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr246 = FALSE ;
  else {
  mu__boolexpr246 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr246)) mu__boolexpr245 = FALSE ;
  else {
  mu__boolexpr245 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr245)) mu__boolexpr244 = FALSE ;
  else {
  mu__boolexpr244 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr244)) mu__boolexpr243 = FALSE ;
  else {
  mu__boolexpr243 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr243)) mu__boolexpr242 = FALSE ;
  else {
  mu__boolexpr242 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr242)) mu__boolexpr241 = FALSE ;
  else {
  mu__boolexpr241 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr241)) mu__boolexpr240 = FALSE ;
  else {
  mu__boolexpr240 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr240;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 432;
    static mu__subrange_142 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_141 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_140 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 459 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr247;
bool mu__boolexpr248;
bool mu__boolexpr249;
bool mu__boolexpr250;
bool mu__boolexpr251;
bool mu__boolexpr252;
bool mu__boolexpr253;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr253 = FALSE ;
  else {
  mu__boolexpr253 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr253)) mu__boolexpr252 = FALSE ;
  else {
  mu__boolexpr252 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr252)) mu__boolexpr251 = FALSE ;
  else {
  mu__boolexpr251 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr251)) mu__boolexpr250 = FALSE ;
  else {
  mu__boolexpr250 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr250)) mu__boolexpr249 = FALSE ;
  else {
  mu__boolexpr249 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr249)) mu__boolexpr248 = FALSE ;
  else {
  mu__boolexpr248 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr248)) mu__boolexpr247 = FALSE ;
  else {
  mu__boolexpr247 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr247) {
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
    r = what_rule - 432;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_142 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_141 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_140 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
  };

};
/******************** RuleBase17 ********************/
class RuleBase17
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_139 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_138 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_137 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_139 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_138 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_137 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr254;
bool mu__boolexpr255;
bool mu__boolexpr256;
bool mu__boolexpr257;
bool mu__boolexpr258;
bool mu__boolexpr259;
bool mu__boolexpr260;
bool mu__boolexpr261;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr261 = FALSE ;
  else {
  mu__boolexpr261 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr261)) mu__boolexpr260 = FALSE ;
  else {
  mu__boolexpr260 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr260)) mu__boolexpr259 = FALSE ;
  else {
  mu__boolexpr259 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr259)) mu__boolexpr258 = FALSE ;
  else {
  mu__boolexpr258 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr258)) mu__boolexpr257 = FALSE ;
  else {
  mu__boolexpr257 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr257)) mu__boolexpr256 = FALSE ;
  else {
  mu__boolexpr256 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr256)) mu__boolexpr255 = FALSE ;
  else {
  mu__boolexpr255 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr255)) mu__boolexpr254 = FALSE ;
  else {
  mu__boolexpr254 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr254;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 459;
    static mu__subrange_139 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_138 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_137 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 486 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr262;
bool mu__boolexpr263;
bool mu__boolexpr264;
bool mu__boolexpr265;
bool mu__boolexpr266;
bool mu__boolexpr267;
bool mu__boolexpr268;
bool mu__boolexpr269;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr269 = FALSE ;
  else {
  mu__boolexpr269 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr269)) mu__boolexpr268 = FALSE ;
  else {
  mu__boolexpr268 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr268)) mu__boolexpr267 = FALSE ;
  else {
  mu__boolexpr267 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr267)) mu__boolexpr266 = FALSE ;
  else {
  mu__boolexpr266 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr266)) mu__boolexpr265 = FALSE ;
  else {
  mu__boolexpr265 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr265)) mu__boolexpr264 = FALSE ;
  else {
  mu__boolexpr264 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr264)) mu__boolexpr263 = FALSE ;
  else {
  mu__boolexpr263 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr263)) mu__boolexpr262 = FALSE ;
  else {
  mu__boolexpr262 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr262) {
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
    r = what_rule - 459;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_139 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_138 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_137 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase18 ********************/
class RuleBase18
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_136 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_135 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_134 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_136 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_135 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_134 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr270;
bool mu__boolexpr271;
bool mu__boolexpr272;
bool mu__boolexpr273;
bool mu__boolexpr274;
bool mu__boolexpr275;
bool mu__boolexpr276;
bool mu__boolexpr277;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr277 = FALSE ;
  else {
  mu__boolexpr277 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr277)) mu__boolexpr276 = FALSE ;
  else {
  mu__boolexpr276 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr276)) mu__boolexpr275 = FALSE ;
  else {
  mu__boolexpr275 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr275)) mu__boolexpr274 = FALSE ;
  else {
  mu__boolexpr274 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr274)) mu__boolexpr273 = FALSE ;
  else {
  mu__boolexpr273 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr273)) mu__boolexpr272 = FALSE ;
  else {
  mu__boolexpr272 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr272)) mu__boolexpr271 = FALSE ;
  else {
  mu__boolexpr271 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr271)) mu__boolexpr270 = FALSE ;
  else {
  mu__boolexpr270 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr270;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 486;
    static mu__subrange_136 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_135 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_134 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 513 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr278;
bool mu__boolexpr279;
bool mu__boolexpr280;
bool mu__boolexpr281;
bool mu__boolexpr282;
bool mu__boolexpr283;
bool mu__boolexpr284;
bool mu__boolexpr285;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr285 = FALSE ;
  else {
  mu__boolexpr285 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr285)) mu__boolexpr284 = FALSE ;
  else {
  mu__boolexpr284 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr284)) mu__boolexpr283 = FALSE ;
  else {
  mu__boolexpr283 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr283)) mu__boolexpr282 = FALSE ;
  else {
  mu__boolexpr282 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr282)) mu__boolexpr281 = FALSE ;
  else {
  mu__boolexpr281 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr281)) mu__boolexpr280 = FALSE ;
  else {
  mu__boolexpr280 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr280)) mu__boolexpr279 = FALSE ;
  else {
  mu__boolexpr279 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr279)) mu__boolexpr278 = FALSE ;
  else {
  mu__boolexpr278 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr278) {
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
    r = what_rule - 486;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_136 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_135 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_134 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase19 ********************/
class RuleBase19
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_133 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_132 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_131 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process fwd_request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_133 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_132 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_131 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr286;
bool mu__boolexpr287;
bool mu__boolexpr288;
bool mu__boolexpr289;
bool mu__boolexpr290;
bool mu__boolexpr291;
bool mu__boolexpr292;
bool mu__boolexpr293;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr293 = FALSE ;
  else {
  mu__boolexpr293 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr293)) mu__boolexpr292 = FALSE ;
  else {
  mu__boolexpr292 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr292)) mu__boolexpr291 = FALSE ;
  else {
  mu__boolexpr291 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr291)) mu__boolexpr290 = FALSE ;
  else {
  mu__boolexpr290 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr290)) mu__boolexpr289 = FALSE ;
  else {
  mu__boolexpr289 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr289)) mu__boolexpr288 = FALSE ;
  else {
  mu__boolexpr288 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr288)) mu__boolexpr287 = FALSE ;
  else {
  mu__boolexpr287 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr287)) mu__boolexpr286 = FALSE ;
  else {
  mu__boolexpr286 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr286;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 513;
    static mu__subrange_133 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_132 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_131 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 540 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr294;
bool mu__boolexpr295;
bool mu__boolexpr296;
bool mu__boolexpr297;
bool mu__boolexpr298;
bool mu__boolexpr299;
bool mu__boolexpr300;
bool mu__boolexpr301;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr301 = FALSE ;
  else {
  mu__boolexpr301 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr301)) mu__boolexpr300 = FALSE ;
  else {
  mu__boolexpr300 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr300)) mu__boolexpr299 = FALSE ;
  else {
  mu__boolexpr299 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr299)) mu__boolexpr298 = FALSE ;
  else {
  mu__boolexpr298 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr298)) mu__boolexpr297 = FALSE ;
  else {
  mu__boolexpr297 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr297)) mu__boolexpr296 = FALSE ;
  else {
  mu__boolexpr296 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr296)) mu__boolexpr295 = FALSE ;
  else {
  mu__boolexpr295 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr295)) mu__boolexpr294 = FALSE ;
  else {
  mu__boolexpr294 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr294) {
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
    r = what_rule - 513;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_133 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_132 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_131 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase20 ********************/
class RuleBase20
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_130 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_130 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr302;
bool mu__boolexpr303;
bool mu__boolexpr304;
bool mu__boolexpr305;
bool mu__boolexpr306;
bool mu__boolexpr307;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr307 = FALSE ;
  else {
  mu__boolexpr307 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr307)) mu__boolexpr306 = FALSE ;
  else {
  mu__boolexpr306 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr306)) mu__boolexpr305 = FALSE ;
  else {
  mu__boolexpr305 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr305)) mu__boolexpr304 = FALSE ;
  else {
  mu__boolexpr304 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr304)) mu__boolexpr303 = FALSE ;
  else {
  mu__boolexpr303 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr303)) mu__boolexpr302 = FALSE ;
  else {
  mu__boolexpr302 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr302;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 540;
    static mu__subrange_130 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 621 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr308;
bool mu__boolexpr309;
bool mu__boolexpr310;
bool mu__boolexpr311;
bool mu__boolexpr312;
bool mu__boolexpr313;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr313 = FALSE ;
  else {
  mu__boolexpr313 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr313)) mu__boolexpr312 = FALSE ;
  else {
  mu__boolexpr312 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr312)) mu__boolexpr311 = FALSE ;
  else {
  mu__boolexpr311 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr311)) mu__boolexpr310 = FALSE ;
  else {
  mu__boolexpr310 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr310)) mu__boolexpr309 = FALSE ;
  else {
  mu__boolexpr309 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr309)) mu__boolexpr308 = FALSE ;
  else {
  mu__boolexpr308 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr308) {
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
    r = what_rule - 540;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_130 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
  };

};
/******************** RuleBase21 ********************/
class RuleBase21
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_126 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_125 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_124 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_123 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_126 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_125 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_124 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_123 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr314;
bool mu__boolexpr315;
bool mu__boolexpr316;
bool mu__boolexpr317;
bool mu__boolexpr318;
bool mu__boolexpr319;
bool mu__boolexpr320;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr320 = FALSE ;
  else {
  mu__boolexpr320 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr320)) mu__boolexpr319 = FALSE ;
  else {
  mu__boolexpr319 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr319)) mu__boolexpr318 = FALSE ;
  else {
  mu__boolexpr318 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr318)) mu__boolexpr317 = FALSE ;
  else {
  mu__boolexpr317 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr317)) mu__boolexpr316 = FALSE ;
  else {
  mu__boolexpr316 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr316)) mu__boolexpr315 = FALSE ;
  else {
  mu__boolexpr315 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr315)) mu__boolexpr314 = FALSE ;
  else {
  mu__boolexpr314 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr314;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 621;
    static mu__subrange_126 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_125 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_124 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_123 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 702 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr321;
bool mu__boolexpr322;
bool mu__boolexpr323;
bool mu__boolexpr324;
bool mu__boolexpr325;
bool mu__boolexpr326;
bool mu__boolexpr327;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr327 = FALSE ;
  else {
  mu__boolexpr327 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr327)) mu__boolexpr326 = FALSE ;
  else {
  mu__boolexpr326 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr326)) mu__boolexpr325 = FALSE ;
  else {
  mu__boolexpr325 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr325)) mu__boolexpr324 = FALSE ;
  else {
  mu__boolexpr324 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr324)) mu__boolexpr323 = FALSE ;
  else {
  mu__boolexpr323 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr323)) mu__boolexpr322 = FALSE ;
  else {
  mu__boolexpr322 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr322)) mu__boolexpr321 = FALSE ;
  else {
  mu__boolexpr321 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr321) {
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
    r = what_rule - 621;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_126 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_125 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_124 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_123 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
  };

};
/******************** RuleBase22 ********************/
class RuleBase22
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_122 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_121 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_120 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_119 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_response + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_122 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_121 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_120 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_119 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr328;
bool mu__boolexpr329;
bool mu__boolexpr330;
bool mu__boolexpr331;
bool mu__boolexpr332;
bool mu__boolexpr333;
bool mu__boolexpr334;
bool mu__boolexpr335;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr335 = FALSE ;
  else {
  mu__boolexpr335 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr335)) mu__boolexpr334 = FALSE ;
  else {
  mu__boolexpr334 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr334)) mu__boolexpr333 = FALSE ;
  else {
  mu__boolexpr333 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr333)) mu__boolexpr332 = FALSE ;
  else {
  mu__boolexpr332 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr332)) mu__boolexpr331 = FALSE ;
  else {
  mu__boolexpr331 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr331)) mu__boolexpr330 = FALSE ;
  else {
  mu__boolexpr330 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr330)) mu__boolexpr329 = FALSE ;
  else {
  mu__boolexpr329 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr329)) mu__boolexpr328 = FALSE ;
  else {
  mu__boolexpr328 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr328;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 702;
    static mu__subrange_122 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_121 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_120 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_119 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 783 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr336;
bool mu__boolexpr337;
bool mu__boolexpr338;
bool mu__boolexpr339;
bool mu__boolexpr340;
bool mu__boolexpr341;
bool mu__boolexpr342;
bool mu__boolexpr343;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr343 = FALSE ;
  else {
  mu__boolexpr343 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr343)) mu__boolexpr342 = FALSE ;
  else {
  mu__boolexpr342 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr342)) mu__boolexpr341 = FALSE ;
  else {
  mu__boolexpr341 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr341)) mu__boolexpr340 = FALSE ;
  else {
  mu__boolexpr340 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr340)) mu__boolexpr339 = FALSE ;
  else {
  mu__boolexpr339 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr339)) mu__boolexpr338 = FALSE ;
  else {
  mu__boolexpr338 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr338)) mu__boolexpr337 = FALSE ;
  else {
  mu__boolexpr337 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr337)) mu__boolexpr336 = FALSE ;
  else {
  mu__boolexpr336 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr336) {
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
    r = what_rule - 702;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_122 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_121 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_120 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_119 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase23 ********************/
class RuleBase23
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_118 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process request + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_118 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr344;
bool mu__boolexpr345;
bool mu__boolexpr346;
bool mu__boolexpr347;
bool mu__boolexpr348;
bool mu__boolexpr349;
bool mu__boolexpr350;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr350 = FALSE ;
  else {
  mu__boolexpr350 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr350)) mu__boolexpr349 = FALSE ;
  else {
  mu__boolexpr349 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr349)) mu__boolexpr348 = FALSE ;
  else {
  mu__boolexpr348 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr348)) mu__boolexpr347 = FALSE ;
  else {
  mu__boolexpr347 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr347)) mu__boolexpr346 = FALSE ;
  else {
  mu__boolexpr346 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr346)) mu__boolexpr345 = FALSE ;
  else {
  mu__boolexpr345 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr345)) mu__boolexpr344 = FALSE ;
  else {
  mu__boolexpr344 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr344;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 783;
    static mu__subrange_118 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 864 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr351;
bool mu__boolexpr352;
bool mu__boolexpr353;
bool mu__boolexpr354;
bool mu__boolexpr355;
bool mu__boolexpr356;
bool mu__boolexpr357;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr357 = FALSE ;
  else {
  mu__boolexpr357 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr357)) mu__boolexpr356 = FALSE ;
  else {
  mu__boolexpr356 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr356)) mu__boolexpr355 = FALSE ;
  else {
  mu__boolexpr355 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr355)) mu__boolexpr354 = FALSE ;
  else {
  mu__boolexpr354 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr354)) mu__boolexpr353 = FALSE ;
  else {
  mu__boolexpr353 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr353)) mu__boolexpr352 = FALSE ;
  else {
  mu__boolexpr352 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr352)) mu__boolexpr351 = FALSE ;
  else {
  mu__boolexpr351 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr351) {
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
    r = what_rule - 783;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_118 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
  };

};
/******************** RuleBase24 ********************/
class RuleBase24
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_114 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_113 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_112 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_111 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process request + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_114 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_113 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_112 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_111 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr358;
bool mu__boolexpr359;
bool mu__boolexpr360;
bool mu__boolexpr361;
bool mu__boolexpr362;
bool mu__boolexpr363;
bool mu__boolexpr364;
bool mu__boolexpr365;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr365 = FALSE ;
  else {
  mu__boolexpr365 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr365)) mu__boolexpr364 = FALSE ;
  else {
  mu__boolexpr364 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr364)) mu__boolexpr363 = FALSE ;
  else {
  mu__boolexpr363 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr363)) mu__boolexpr362 = FALSE ;
  else {
  mu__boolexpr362 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr362)) mu__boolexpr361 = FALSE ;
  else {
  mu__boolexpr361 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr361)) mu__boolexpr360 = FALSE ;
  else {
  mu__boolexpr360 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr360)) mu__boolexpr359 = FALSE ;
  else {
  mu__boolexpr359 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr359)) mu__boolexpr358 = FALSE ;
  else {
  mu__boolexpr358 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr358;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 864;
    static mu__subrange_114 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_113 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_112 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_111 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 945 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr366;
bool mu__boolexpr367;
bool mu__boolexpr368;
bool mu__boolexpr369;
bool mu__boolexpr370;
bool mu__boolexpr371;
bool mu__boolexpr372;
bool mu__boolexpr373;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr373 = FALSE ;
  else {
  mu__boolexpr373 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr373)) mu__boolexpr372 = FALSE ;
  else {
  mu__boolexpr372 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr372)) mu__boolexpr371 = FALSE ;
  else {
  mu__boolexpr371 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr371)) mu__boolexpr370 = FALSE ;
  else {
  mu__boolexpr370 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr370)) mu__boolexpr369 = FALSE ;
  else {
  mu__boolexpr369 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr369)) mu__boolexpr368 = FALSE ;
  else {
  mu__boolexpr368 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr368)) mu__boolexpr367 = FALSE ;
  else {
  mu__boolexpr367 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr367)) mu__boolexpr366 = FALSE ;
  else {
  mu__boolexpr366 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr366) {
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
    r = what_rule - 864;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_114 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_113 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_112 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_111 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase25 ********************/
class RuleBase25
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_110 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_109 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_108 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_107 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process request + Process request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_110 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_109 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_108 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_107 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr374;
bool mu__boolexpr375;
bool mu__boolexpr376;
bool mu__boolexpr377;
bool mu__boolexpr378;
bool mu__boolexpr379;
bool mu__boolexpr380;
bool mu__boolexpr381;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr381 = FALSE ;
  else {
  mu__boolexpr381 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr381)) mu__boolexpr380 = FALSE ;
  else {
  mu__boolexpr380 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr380)) mu__boolexpr379 = FALSE ;
  else {
  mu__boolexpr379 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr379)) mu__boolexpr378 = FALSE ;
  else {
  mu__boolexpr378 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr378)) mu__boolexpr377 = FALSE ;
  else {
  mu__boolexpr377 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr377)) mu__boolexpr376 = FALSE ;
  else {
  mu__boolexpr376 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr376)) mu__boolexpr375 = FALSE ;
  else {
  mu__boolexpr375 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr375)) mu__boolexpr374 = FALSE ;
  else {
  mu__boolexpr374 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr374;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 945;
    static mu__subrange_110 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_109 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_108 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_107 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1026 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr382;
bool mu__boolexpr383;
bool mu__boolexpr384;
bool mu__boolexpr385;
bool mu__boolexpr386;
bool mu__boolexpr387;
bool mu__boolexpr388;
bool mu__boolexpr389;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr389 = FALSE ;
  else {
  mu__boolexpr389 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr389)) mu__boolexpr388 = FALSE ;
  else {
  mu__boolexpr388 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr388)) mu__boolexpr387 = FALSE ;
  else {
  mu__boolexpr387 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr387)) mu__boolexpr386 = FALSE ;
  else {
  mu__boolexpr386 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr386)) mu__boolexpr385 = FALSE ;
  else {
  mu__boolexpr385 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr385)) mu__boolexpr384 = FALSE ;
  else {
  mu__boolexpr384 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr384)) mu__boolexpr383 = FALSE ;
  else {
  mu__boolexpr383 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr383)) mu__boolexpr382 = FALSE ;
  else {
  mu__boolexpr382 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr382) {
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
    r = what_rule - 945;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_110 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_109 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_108 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_107 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase26 ********************/
class RuleBase26
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_106 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_105 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_104 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_103 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_request + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_106 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_105 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_104 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_103 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr390;
bool mu__boolexpr391;
bool mu__boolexpr392;
bool mu__boolexpr393;
bool mu__boolexpr394;
bool mu__boolexpr395;
bool mu__boolexpr396;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr396 = FALSE ;
  else {
  mu__boolexpr396 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr396)) mu__boolexpr395 = FALSE ;
  else {
  mu__boolexpr395 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr395)) mu__boolexpr394 = FALSE ;
  else {
  mu__boolexpr394 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr394)) mu__boolexpr393 = FALSE ;
  else {
  mu__boolexpr393 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr393)) mu__boolexpr392 = FALSE ;
  else {
  mu__boolexpr392 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr392)) mu__boolexpr391 = FALSE ;
  else {
  mu__boolexpr391 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr391)) mu__boolexpr390 = FALSE ;
  else {
  mu__boolexpr390 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr390;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1026;
    static mu__subrange_106 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_105 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_104 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_103 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1107 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr397;
bool mu__boolexpr398;
bool mu__boolexpr399;
bool mu__boolexpr400;
bool mu__boolexpr401;
bool mu__boolexpr402;
bool mu__boolexpr403;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr403 = FALSE ;
  else {
  mu__boolexpr403 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr403)) mu__boolexpr402 = FALSE ;
  else {
  mu__boolexpr402 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr402)) mu__boolexpr401 = FALSE ;
  else {
  mu__boolexpr401 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr401)) mu__boolexpr400 = FALSE ;
  else {
  mu__boolexpr400 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr400)) mu__boolexpr399 = FALSE ;
  else {
  mu__boolexpr399 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr399)) mu__boolexpr398 = FALSE ;
  else {
  mu__boolexpr398 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr398)) mu__boolexpr397 = FALSE ;
  else {
  mu__boolexpr397 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr397) {
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
    r = what_rule - 1026;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_106 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_105 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_104 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_103 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
  };

};
/******************** RuleBase27 ********************/
class RuleBase27
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_102 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_101 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_100 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_99 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_102 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_101 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_100 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_99 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr404;
bool mu__boolexpr405;
bool mu__boolexpr406;
bool mu__boolexpr407;
bool mu__boolexpr408;
bool mu__boolexpr409;
bool mu__boolexpr410;
bool mu__boolexpr411;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr411 = FALSE ;
  else {
  mu__boolexpr411 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr411)) mu__boolexpr410 = FALSE ;
  else {
  mu__boolexpr410 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr410)) mu__boolexpr409 = FALSE ;
  else {
  mu__boolexpr409 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr409)) mu__boolexpr408 = FALSE ;
  else {
  mu__boolexpr408 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr408)) mu__boolexpr407 = FALSE ;
  else {
  mu__boolexpr407 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr407)) mu__boolexpr406 = FALSE ;
  else {
  mu__boolexpr406 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr406)) mu__boolexpr405 = FALSE ;
  else {
  mu__boolexpr405 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr405)) mu__boolexpr404 = FALSE ;
  else {
  mu__boolexpr404 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr404;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1107;
    static mu__subrange_102 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_101 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_100 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_99 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1188 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr412;
bool mu__boolexpr413;
bool mu__boolexpr414;
bool mu__boolexpr415;
bool mu__boolexpr416;
bool mu__boolexpr417;
bool mu__boolexpr418;
bool mu__boolexpr419;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr419 = FALSE ;
  else {
  mu__boolexpr419 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr419)) mu__boolexpr418 = FALSE ;
  else {
  mu__boolexpr418 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr418)) mu__boolexpr417 = FALSE ;
  else {
  mu__boolexpr417 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr417)) mu__boolexpr416 = FALSE ;
  else {
  mu__boolexpr416 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr416)) mu__boolexpr415 = FALSE ;
  else {
  mu__boolexpr415 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr415)) mu__boolexpr414 = FALSE ;
  else {
  mu__boolexpr414 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr414)) mu__boolexpr413 = FALSE ;
  else {
  mu__boolexpr413 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr413)) mu__boolexpr412 = FALSE ;
  else {
  mu__boolexpr412 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr412) {
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
    r = what_rule - 1107;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_102 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_101 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_100 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_99 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase28 ********************/
class RuleBase28
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_98 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_97 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_96 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_95 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_request + Process request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_98 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_97 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_96 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_95 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr420;
bool mu__boolexpr421;
bool mu__boolexpr422;
bool mu__boolexpr423;
bool mu__boolexpr424;
bool mu__boolexpr425;
bool mu__boolexpr426;
bool mu__boolexpr427;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr427 = FALSE ;
  else {
  mu__boolexpr427 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr427)) mu__boolexpr426 = FALSE ;
  else {
  mu__boolexpr426 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr426)) mu__boolexpr425 = FALSE ;
  else {
  mu__boolexpr425 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr425)) mu__boolexpr424 = FALSE ;
  else {
  mu__boolexpr424 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr424)) mu__boolexpr423 = FALSE ;
  else {
  mu__boolexpr423 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr423)) mu__boolexpr422 = FALSE ;
  else {
  mu__boolexpr422 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr422)) mu__boolexpr421 = FALSE ;
  else {
  mu__boolexpr421 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr421)) mu__boolexpr420 = FALSE ;
  else {
  mu__boolexpr420 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr420;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1188;
    static mu__subrange_98 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_97 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_96 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_95 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1269 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr428;
bool mu__boolexpr429;
bool mu__boolexpr430;
bool mu__boolexpr431;
bool mu__boolexpr432;
bool mu__boolexpr433;
bool mu__boolexpr434;
bool mu__boolexpr435;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr435 = FALSE ;
  else {
  mu__boolexpr435 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr435)) mu__boolexpr434 = FALSE ;
  else {
  mu__boolexpr434 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr434)) mu__boolexpr433 = FALSE ;
  else {
  mu__boolexpr433 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr433)) mu__boolexpr432 = FALSE ;
  else {
  mu__boolexpr432 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr432)) mu__boolexpr431 = FALSE ;
  else {
  mu__boolexpr431 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr431)) mu__boolexpr430 = FALSE ;
  else {
  mu__boolexpr430 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr430)) mu__boolexpr429 = FALSE ;
  else {
  mu__boolexpr429 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr429)) mu__boolexpr428 = FALSE ;
  else {
  mu__boolexpr428 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr428) {
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
    r = what_rule - 1188;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_98 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_97 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_96 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_95 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase29 ********************/
class RuleBase29
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_94 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_93 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_92 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_91 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_94 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_93 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_92 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_91 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr436;
bool mu__boolexpr437;
bool mu__boolexpr438;
bool mu__boolexpr439;
bool mu__boolexpr440;
bool mu__boolexpr441;
bool mu__boolexpr442;
bool mu__boolexpr443;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr443 = FALSE ;
  else {
  mu__boolexpr443 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr443)) mu__boolexpr442 = FALSE ;
  else {
  mu__boolexpr442 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr442)) mu__boolexpr441 = FALSE ;
  else {
  mu__boolexpr441 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr441)) mu__boolexpr440 = FALSE ;
  else {
  mu__boolexpr440 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr440)) mu__boolexpr439 = FALSE ;
  else {
  mu__boolexpr439 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr439)) mu__boolexpr438 = FALSE ;
  else {
  mu__boolexpr438 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr438)) mu__boolexpr437 = FALSE ;
  else {
  mu__boolexpr437 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr437)) mu__boolexpr436 = FALSE ;
  else {
  mu__boolexpr436 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr436;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1269;
    static mu__subrange_94 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_93 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_92 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_91 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1350 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr444;
bool mu__boolexpr445;
bool mu__boolexpr446;
bool mu__boolexpr447;
bool mu__boolexpr448;
bool mu__boolexpr449;
bool mu__boolexpr450;
bool mu__boolexpr451;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr451 = FALSE ;
  else {
  mu__boolexpr451 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr451)) mu__boolexpr450 = FALSE ;
  else {
  mu__boolexpr450 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr450)) mu__boolexpr449 = FALSE ;
  else {
  mu__boolexpr449 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr449)) mu__boolexpr448 = FALSE ;
  else {
  mu__boolexpr448 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr448)) mu__boolexpr447 = FALSE ;
  else {
  mu__boolexpr447 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr447)) mu__boolexpr446 = FALSE ;
  else {
  mu__boolexpr446 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr446)) mu__boolexpr445 = FALSE ;
  else {
  mu__boolexpr445 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr445)) mu__boolexpr444 = FALSE ;
  else {
  mu__boolexpr444 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr444) {
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
    r = what_rule - 1269;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_94 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_93 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_92 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_91 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
  };

};
/******************** RuleBase30 ********************/
class RuleBase30
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_90 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Process response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_90 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr452;
bool mu__boolexpr453;
bool mu__boolexpr454;
bool mu__boolexpr455;
bool mu__boolexpr456;
bool mu__boolexpr457;
bool mu__boolexpr458;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr458 = FALSE ;
  else {
  mu__boolexpr458 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr458)) mu__boolexpr457 = FALSE ;
  else {
  mu__boolexpr457 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr457)) mu__boolexpr456 = FALSE ;
  else {
  mu__boolexpr456 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr456)) mu__boolexpr455 = FALSE ;
  else {
  mu__boolexpr455 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr455)) mu__boolexpr454 = FALSE ;
  else {
  mu__boolexpr454 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr454)) mu__boolexpr453 = FALSE ;
  else {
  mu__boolexpr453 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr453)) mu__boolexpr452 = FALSE ;
  else {
  mu__boolexpr452 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr452;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1350;
    static mu__subrange_90 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1593 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr459;
bool mu__boolexpr460;
bool mu__boolexpr461;
bool mu__boolexpr462;
bool mu__boolexpr463;
bool mu__boolexpr464;
bool mu__boolexpr465;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr465 = FALSE ;
  else {
  mu__boolexpr465 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr465)) mu__boolexpr464 = FALSE ;
  else {
  mu__boolexpr464 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr464)) mu__boolexpr463 = FALSE ;
  else {
  mu__boolexpr463 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr463)) mu__boolexpr462 = FALSE ;
  else {
  mu__boolexpr462 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr462)) mu__boolexpr461 = FALSE ;
  else {
  mu__boolexpr461 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr461)) mu__boolexpr460 = FALSE ;
  else {
  mu__boolexpr460 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr460)) mu__boolexpr459 = FALSE ;
  else {
  mu__boolexpr459 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr459) {
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
    r = what_rule - 1350;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_90 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessResponse ( (int)mu_n5, mu_EntryPath[mu_n5] );
  };

};
/******************** RuleBase31 ********************/
class RuleBase31
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_85 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_84 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_83 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_82 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_81 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Process fwd_response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_85 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_84 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_83 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_82 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_81 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr466;
bool mu__boolexpr467;
bool mu__boolexpr468;
bool mu__boolexpr469;
bool mu__boolexpr470;
bool mu__boolexpr471;
bool mu__boolexpr472;
bool mu__boolexpr473;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr473 = FALSE ;
  else {
  mu__boolexpr473 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr473)) mu__boolexpr472 = FALSE ;
  else {
  mu__boolexpr472 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr472)) mu__boolexpr471 = FALSE ;
  else {
  mu__boolexpr471 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr471)) mu__boolexpr470 = FALSE ;
  else {
  mu__boolexpr470 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr470)) mu__boolexpr469 = FALSE ;
  else {
  mu__boolexpr469 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr469)) mu__boolexpr468 = FALSE ;
  else {
  mu__boolexpr468 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr468)) mu__boolexpr467 = FALSE ;
  else {
  mu__boolexpr467 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr467)) mu__boolexpr466 = FALSE ;
  else {
  mu__boolexpr466 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr466;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1593;
    static mu__subrange_85 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_84 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_83 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_82 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_81 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 1836 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr474;
bool mu__boolexpr475;
bool mu__boolexpr476;
bool mu__boolexpr477;
bool mu__boolexpr478;
bool mu__boolexpr479;
bool mu__boolexpr480;
bool mu__boolexpr481;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr481 = FALSE ;
  else {
  mu__boolexpr481 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr481)) mu__boolexpr480 = FALSE ;
  else {
  mu__boolexpr480 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr480)) mu__boolexpr479 = FALSE ;
  else {
  mu__boolexpr479 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr479)) mu__boolexpr478 = FALSE ;
  else {
  mu__boolexpr478 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr478)) mu__boolexpr477 = FALSE ;
  else {
  mu__boolexpr477 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr477)) mu__boolexpr476 = FALSE ;
  else {
  mu__boolexpr476 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr476)) mu__boolexpr475 = FALSE ;
  else {
  mu__boolexpr475 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr475)) mu__boolexpr474 = FALSE ;
  else {
  mu__boolexpr474 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr474) {
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
    r = what_rule - 1593;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_85 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_84 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_83 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_82 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_81 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdResponse ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
  };

};
/******************** RuleBase32 ********************/
class RuleBase32
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_80 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_79 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_78 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_77 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_76 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Process request, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_80 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_79 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_78 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_77 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_76 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr482;
bool mu__boolexpr483;
bool mu__boolexpr484;
bool mu__boolexpr485;
bool mu__boolexpr486;
bool mu__boolexpr487;
bool mu__boolexpr488;
bool mu__boolexpr489;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr489 = FALSE ;
  else {
  mu__boolexpr489 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr489)) mu__boolexpr488 = FALSE ;
  else {
  mu__boolexpr488 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr488)) mu__boolexpr487 = FALSE ;
  else {
  mu__boolexpr487 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr487)) mu__boolexpr486 = FALSE ;
  else {
  mu__boolexpr486 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr486)) mu__boolexpr485 = FALSE ;
  else {
  mu__boolexpr485 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr485)) mu__boolexpr484 = FALSE ;
  else {
  mu__boolexpr484 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr484)) mu__boolexpr483 = FALSE ;
  else {
  mu__boolexpr483 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr483)) mu__boolexpr482 = FALSE ;
  else {
  mu__boolexpr482 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr482;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1836;
    static mu__subrange_80 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_79 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_78 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_77 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_76 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 2079 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr490;
bool mu__boolexpr491;
bool mu__boolexpr492;
bool mu__boolexpr493;
bool mu__boolexpr494;
bool mu__boolexpr495;
bool mu__boolexpr496;
bool mu__boolexpr497;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr497 = FALSE ;
  else {
  mu__boolexpr497 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr497)) mu__boolexpr496 = FALSE ;
  else {
  mu__boolexpr496 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr496)) mu__boolexpr495 = FALSE ;
  else {
  mu__boolexpr495 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr495)) mu__boolexpr494 = FALSE ;
  else {
  mu__boolexpr494 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr494)) mu__boolexpr493 = FALSE ;
  else {
  mu__boolexpr493 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr493)) mu__boolexpr492 = FALSE ;
  else {
  mu__boolexpr492 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr492)) mu__boolexpr491 = FALSE ;
  else {
  mu__boolexpr491 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr491)) mu__boolexpr490 = FALSE ;
  else {
  mu__boolexpr490 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr490) {
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
    r = what_rule - 1836;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_80 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_79 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_78 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_77 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_76 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
  };

};
/******************** RuleBase33 ********************/
class RuleBase33
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_75 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_74 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_73 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_72 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_71 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Process fwd_request, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_75 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_74 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_73 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_72 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_71 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr498;
bool mu__boolexpr499;
bool mu__boolexpr500;
bool mu__boolexpr501;
bool mu__boolexpr502;
bool mu__boolexpr503;
bool mu__boolexpr504;
bool mu__boolexpr505;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr505 = FALSE ;
  else {
  mu__boolexpr505 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr505)) mu__boolexpr504 = FALSE ;
  else {
  mu__boolexpr504 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr504)) mu__boolexpr503 = FALSE ;
  else {
  mu__boolexpr503 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr503)) mu__boolexpr502 = FALSE ;
  else {
  mu__boolexpr502 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr502)) mu__boolexpr501 = FALSE ;
  else {
  mu__boolexpr501 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr501)) mu__boolexpr500 = FALSE ;
  else {
  mu__boolexpr500 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr500)) mu__boolexpr499 = FALSE ;
  else {
  mu__boolexpr499 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr499)) mu__boolexpr498 = FALSE ;
  else {
  mu__boolexpr498 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr498;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2079;
    static mu__subrange_75 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_74 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_73 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_72 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_71 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 2322 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr506;
bool mu__boolexpr507;
bool mu__boolexpr508;
bool mu__boolexpr509;
bool mu__boolexpr510;
bool mu__boolexpr511;
bool mu__boolexpr512;
bool mu__boolexpr513;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr513 = FALSE ;
  else {
  mu__boolexpr513 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr513)) mu__boolexpr512 = FALSE ;
  else {
  mu__boolexpr512 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr512)) mu__boolexpr511 = FALSE ;
  else {
  mu__boolexpr511 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr511)) mu__boolexpr510 = FALSE ;
  else {
  mu__boolexpr510 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr510)) mu__boolexpr509 = FALSE ;
  else {
  mu__boolexpr509 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr509)) mu__boolexpr508 = FALSE ;
  else {
  mu__boolexpr508 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr508)) mu__boolexpr507 = FALSE ;
  else {
  mu__boolexpr507 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr507)) mu__boolexpr506 = FALSE ;
  else {
  mu__boolexpr506 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr506) {
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
    r = what_rule - 2079;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_75 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_74 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_73 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_72 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_71 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
  };

};
/******************** RuleBase34 ********************/
class RuleBase34
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_70 mu_n6;
    mu_n6.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_69 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_68 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_67 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_66 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_65 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Send request, n6:%s, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n6.Name(), mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_70 mu_n6;
    mu_n6.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_69 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_68 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_67 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_66 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_65 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr514;
bool mu__boolexpr515;
bool mu__boolexpr516;
bool mu__boolexpr517;
bool mu__boolexpr518;
bool mu__boolexpr519;
bool mu__boolexpr520;
bool mu__boolexpr521;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr521 = FALSE ;
  else {
  mu__boolexpr521 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr521)) mu__boolexpr520 = FALSE ;
  else {
  mu__boolexpr520 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr520)) mu__boolexpr519 = FALSE ;
  else {
  mu__boolexpr519 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr519)) mu__boolexpr518 = FALSE ;
  else {
  mu__boolexpr518 = ((mu_n5) != (mu_n6)) ; 
}
  if (!(mu__boolexpr518)) mu__boolexpr517 = FALSE ;
  else {
  mu__boolexpr517 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (2)) ; 
}
  if (!(mu__boolexpr517)) mu__boolexpr516 = FALSE ;
  else {
  mu__boolexpr516 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr516)) mu__boolexpr515 = FALSE ;
  else {
  mu__boolexpr515 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr515)) mu__boolexpr514 = FALSE ;
  else {
  mu__boolexpr514 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr514;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2322;
    static mu__subrange_70 mu_n6;
    mu_n6.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_69 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_68 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_67 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_66 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_65 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3051 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr522;
bool mu__boolexpr523;
bool mu__boolexpr524;
bool mu__boolexpr525;
bool mu__boolexpr526;
bool mu__boolexpr527;
bool mu__boolexpr528;
bool mu__boolexpr529;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr529 = FALSE ;
  else {
  mu__boolexpr529 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr529)) mu__boolexpr528 = FALSE ;
  else {
  mu__boolexpr528 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr528)) mu__boolexpr527 = FALSE ;
  else {
  mu__boolexpr527 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr527)) mu__boolexpr526 = FALSE ;
  else {
  mu__boolexpr526 = ((mu_n5) != (mu_n6)) ; 
}
  if (!(mu__boolexpr526)) mu__boolexpr525 = FALSE ;
  else {
  mu__boolexpr525 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (2)) ; 
}
  if (!(mu__boolexpr525)) mu__boolexpr524 = FALSE ;
  else {
  mu__boolexpr524 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr524)) mu__boolexpr523 = FALSE ;
  else {
  mu__boolexpr523 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr523)) mu__boolexpr522 = FALSE ;
  else {
  mu__boolexpr522 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr522) {
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
    r = what_rule - 2322;
    mu_n6.value((r % 3) + 0);
    r = r / 3;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_70 mu_n6;
    mu_n6.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_69 mu_n5;
    mu_n5.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_68 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_67 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_66 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_65 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_SendRequest ( (int)mu_n5, mu_ExitPath[mu_n5], (int)mu_n6 );
  };

};
/******************** RuleBase35 ********************/
class RuleBase35
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_64 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_63 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_64 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_63 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr530;
bool mu__boolexpr531;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr531 = FALSE ;
  else {
  mu__boolexpr531 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr531)) mu__boolexpr530 = FALSE ;
  else {
  mu__boolexpr530 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr530;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3051;
    static mu__subrange_64 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_63 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3060 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr532;
bool mu__boolexpr533;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr533 = FALSE ;
  else {
  mu__boolexpr533 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr533)) mu__boolexpr532 = FALSE ;
  else {
  mu__boolexpr532 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr532) {
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
    r = what_rule - 3051;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_64 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_63 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessResponse ( (int)mu_n1, mu_EntryPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
  };

};
/******************** RuleBase36 ********************/
class RuleBase36
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_62 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_61 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_62 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_61 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr534;
bool mu__boolexpr535;
bool mu__boolexpr536;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr536 = FALSE ;
  else {
  mu__boolexpr536 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr536)) mu__boolexpr535 = FALSE ;
  else {
  mu__boolexpr535 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr535)) mu__boolexpr534 = FALSE ;
  else {
  mu__boolexpr534 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr534;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3060;
    static mu__subrange_62 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_61 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3069 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr537;
bool mu__boolexpr538;
bool mu__boolexpr539;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr539 = FALSE ;
  else {
  mu__boolexpr539 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr539)) mu__boolexpr538 = FALSE ;
  else {
  mu__boolexpr538 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr538)) mu__boolexpr537 = FALSE ;
  else {
  mu__boolexpr537 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr537) {
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
    r = what_rule - 3060;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_62 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_61 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
  };

};
/******************** RuleBase37 ********************/
class RuleBase37
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_60 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_59 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_60 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_59 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr540;
bool mu__boolexpr541;
bool mu__boolexpr542;
bool mu__boolexpr543;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr543 = FALSE ;
  else {
  mu__boolexpr543 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr543)) mu__boolexpr542 = FALSE ;
  else {
  mu__boolexpr542 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr542)) mu__boolexpr541 = FALSE ;
  else {
  mu__boolexpr541 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr541)) mu__boolexpr540 = FALSE ;
  else {
  mu__boolexpr540 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr540;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3069;
    static mu__subrange_60 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_59 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3078 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr544;
bool mu__boolexpr545;
bool mu__boolexpr546;
bool mu__boolexpr547;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr547 = FALSE ;
  else {
  mu__boolexpr547 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr547)) mu__boolexpr546 = FALSE ;
  else {
  mu__boolexpr546 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr546)) mu__boolexpr545 = FALSE ;
  else {
  mu__boolexpr545 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr545)) mu__boolexpr544 = FALSE ;
  else {
  mu__boolexpr544 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr544) {
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
    r = what_rule - 3069;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_60 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_59 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase38 ********************/
class RuleBase38
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_58 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_57 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_58 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_57 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr548;
bool mu__boolexpr549;
bool mu__boolexpr550;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr550 = FALSE ;
  else {
  mu__boolexpr550 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr550)) mu__boolexpr549 = FALSE ;
  else {
  mu__boolexpr549 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr549)) mu__boolexpr548 = FALSE ;
  else {
  mu__boolexpr548 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr548;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3078;
    static mu__subrange_58 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_57 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3087 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr551;
bool mu__boolexpr552;
bool mu__boolexpr553;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr553 = FALSE ;
  else {
  mu__boolexpr553 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr553)) mu__boolexpr552 = FALSE ;
  else {
  mu__boolexpr552 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr552)) mu__boolexpr551 = FALSE ;
  else {
  mu__boolexpr551 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr551) {
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
    r = what_rule - 3078;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_58 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_57 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
  };

};
/******************** RuleBase39 ********************/
class RuleBase39
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_56 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_55 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_56 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_55 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr554;
bool mu__boolexpr555;
bool mu__boolexpr556;
bool mu__boolexpr557;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr557 = FALSE ;
  else {
  mu__boolexpr557 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr557)) mu__boolexpr556 = FALSE ;
  else {
  mu__boolexpr556 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr556)) mu__boolexpr555 = FALSE ;
  else {
  mu__boolexpr555 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr555)) mu__boolexpr554 = FALSE ;
  else {
  mu__boolexpr554 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr554;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3087;
    static mu__subrange_56 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_55 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3096 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr558;
bool mu__boolexpr559;
bool mu__boolexpr560;
bool mu__boolexpr561;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr561 = FALSE ;
  else {
  mu__boolexpr561 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr561)) mu__boolexpr560 = FALSE ;
  else {
  mu__boolexpr560 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr560)) mu__boolexpr559 = FALSE ;
  else {
  mu__boolexpr559 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr559)) mu__boolexpr558 = FALSE ;
  else {
  mu__boolexpr558 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr558) {
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
    r = what_rule - 3087;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_56 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_55 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase40 ********************/
class RuleBase40
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_54 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_53 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_54 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_53 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr562;
bool mu__boolexpr563;
bool mu__boolexpr564;
bool mu__boolexpr565;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr565 = FALSE ;
  else {
  mu__boolexpr565 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr565)) mu__boolexpr564 = FALSE ;
  else {
  mu__boolexpr564 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr564)) mu__boolexpr563 = FALSE ;
  else {
  mu__boolexpr563 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr563)) mu__boolexpr562 = FALSE ;
  else {
  mu__boolexpr562 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr562;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3096;
    static mu__subrange_54 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_53 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3105 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr566;
bool mu__boolexpr567;
bool mu__boolexpr568;
bool mu__boolexpr569;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr569 = FALSE ;
  else {
  mu__boolexpr569 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr569)) mu__boolexpr568 = FALSE ;
  else {
  mu__boolexpr568 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr568)) mu__boolexpr567 = FALSE ;
  else {
  mu__boolexpr567 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr567)) mu__boolexpr566 = FALSE ;
  else {
  mu__boolexpr566 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr566) {
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
    r = what_rule - 3096;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_54 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_53 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase41 ********************/
class RuleBase41
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_52 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_51 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_52 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_51 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr570;
bool mu__boolexpr571;
bool mu__boolexpr572;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr572 = FALSE ;
  else {
  mu__boolexpr572 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr572)) mu__boolexpr571 = FALSE ;
  else {
  mu__boolexpr571 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr571)) mu__boolexpr570 = FALSE ;
  else {
  mu__boolexpr570 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr570;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3105;
    static mu__subrange_52 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_51 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3114 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr573;
bool mu__boolexpr574;
bool mu__boolexpr575;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr575 = FALSE ;
  else {
  mu__boolexpr575 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr575)) mu__boolexpr574 = FALSE ;
  else {
  mu__boolexpr574 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr574)) mu__boolexpr573 = FALSE ;
  else {
  mu__boolexpr573 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr573) {
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
    r = what_rule - 3105;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_52 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_51 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
  };

};
/******************** RuleBase42 ********************/
class RuleBase42
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_50 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_49 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_50 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_49 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr576;
bool mu__boolexpr577;
bool mu__boolexpr578;
bool mu__boolexpr579;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr579 = FALSE ;
  else {
  mu__boolexpr579 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr579)) mu__boolexpr578 = FALSE ;
  else {
  mu__boolexpr578 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr578)) mu__boolexpr577 = FALSE ;
  else {
  mu__boolexpr577 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr577)) mu__boolexpr576 = FALSE ;
  else {
  mu__boolexpr576 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr576;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3114;
    static mu__subrange_50 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_49 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3123 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr580;
bool mu__boolexpr581;
bool mu__boolexpr582;
bool mu__boolexpr583;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr583 = FALSE ;
  else {
  mu__boolexpr583 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr583)) mu__boolexpr582 = FALSE ;
  else {
  mu__boolexpr582 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr582)) mu__boolexpr581 = FALSE ;
  else {
  mu__boolexpr581 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr581)) mu__boolexpr580 = FALSE ;
  else {
  mu__boolexpr580 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr580) {
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
    r = what_rule - 3114;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_50 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_49 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase43 ********************/
class RuleBase43
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_48 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_47 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_48 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_47 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr584;
bool mu__boolexpr585;
bool mu__boolexpr586;
bool mu__boolexpr587;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr587 = FALSE ;
  else {
  mu__boolexpr587 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr587)) mu__boolexpr586 = FALSE ;
  else {
  mu__boolexpr586 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr586)) mu__boolexpr585 = FALSE ;
  else {
  mu__boolexpr585 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr585)) mu__boolexpr584 = FALSE ;
  else {
  mu__boolexpr584 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr584;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3123;
    static mu__subrange_48 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_47 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3132 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr588;
bool mu__boolexpr589;
bool mu__boolexpr590;
bool mu__boolexpr591;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr591 = FALSE ;
  else {
  mu__boolexpr591 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr591)) mu__boolexpr590 = FALSE ;
  else {
  mu__boolexpr590 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr590)) mu__boolexpr589 = FALSE ;
  else {
  mu__boolexpr589 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr589)) mu__boolexpr588 = FALSE ;
  else {
  mu__boolexpr588 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr588) {
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
    r = what_rule - 3123;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_48 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_47 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase44 ********************/
class RuleBase44
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr592;
bool mu__boolexpr593;
bool mu__boolexpr594;
bool mu__boolexpr595;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr595 = FALSE ;
  else {
  mu__boolexpr595 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr595)) mu__boolexpr594 = FALSE ;
  else {
  mu__boolexpr594 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr594)) mu__boolexpr593 = FALSE ;
  else {
  mu__boolexpr593 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr593)) mu__boolexpr592 = FALSE ;
  else {
  mu__boolexpr592 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr592;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3132;
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3141 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr596;
bool mu__boolexpr597;
bool mu__boolexpr598;
bool mu__boolexpr599;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr599 = FALSE ;
  else {
  mu__boolexpr599 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr599)) mu__boolexpr598 = FALSE ;
  else {
  mu__boolexpr598 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr598)) mu__boolexpr597 = FALSE ;
  else {
  mu__boolexpr597 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr597)) mu__boolexpr596 = FALSE ;
  else {
  mu__boolexpr596 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr596) {
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
    r = what_rule - 3132;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
  };

};
/******************** RuleBase45 ********************/
class RuleBase45
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr600;
bool mu__boolexpr601;
bool mu__boolexpr602;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr602 = FALSE ;
  else {
  mu__boolexpr602 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr602)) mu__boolexpr601 = FALSE ;
  else {
  mu__boolexpr601 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr601)) mu__boolexpr600 = FALSE ;
  else {
  mu__boolexpr600 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr600;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3141;
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3168 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr603;
bool mu__boolexpr604;
bool mu__boolexpr605;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr605 = FALSE ;
  else {
  mu__boolexpr605 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr605)) mu__boolexpr604 = FALSE ;
  else {
  mu__boolexpr604 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr604)) mu__boolexpr603 = FALSE ;
  else {
  mu__boolexpr603 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr603) {
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
    r = what_rule - 3141;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
  };

};
/******************** RuleBase46 ********************/
class RuleBase46
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr606;
bool mu__boolexpr607;
bool mu__boolexpr608;
bool mu__boolexpr609;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr609 = FALSE ;
  else {
  mu__boolexpr609 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr609)) mu__boolexpr608 = FALSE ;
  else {
  mu__boolexpr608 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr608)) mu__boolexpr607 = FALSE ;
  else {
  mu__boolexpr607 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr607)) mu__boolexpr606 = FALSE ;
  else {
  mu__boolexpr606 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr606;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3168;
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3195 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr610;
bool mu__boolexpr611;
bool mu__boolexpr612;
bool mu__boolexpr613;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr613 = FALSE ;
  else {
  mu__boolexpr613 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr613)) mu__boolexpr612 = FALSE ;
  else {
  mu__boolexpr612 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr612)) mu__boolexpr611 = FALSE ;
  else {
  mu__boolexpr611 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr611)) mu__boolexpr610 = FALSE ;
  else {
  mu__boolexpr610 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr610) {
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
    r = what_rule - 3168;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase47 ********************/
class RuleBase47
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr614;
bool mu__boolexpr615;
bool mu__boolexpr616;
bool mu__boolexpr617;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr617 = FALSE ;
  else {
  mu__boolexpr617 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr617)) mu__boolexpr616 = FALSE ;
  else {
  mu__boolexpr616 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr616)) mu__boolexpr615 = FALSE ;
  else {
  mu__boolexpr615 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr615)) mu__boolexpr614 = FALSE ;
  else {
  mu__boolexpr614 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr614;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3195;
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3222 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr618;
bool mu__boolexpr619;
bool mu__boolexpr620;
bool mu__boolexpr621;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr621 = FALSE ;
  else {
  mu__boolexpr621 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr621)) mu__boolexpr620 = FALSE ;
  else {
  mu__boolexpr620 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr620)) mu__boolexpr619 = FALSE ;
  else {
  mu__boolexpr619 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr619)) mu__boolexpr618 = FALSE ;
  else {
  mu__boolexpr618 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr618) {
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
    r = what_rule - 3195;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase48 ********************/
class RuleBase48
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_35 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_34 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_33 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Process fwd_request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_35 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_34 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_33 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr622;
bool mu__boolexpr623;
bool mu__boolexpr624;
bool mu__boolexpr625;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr625 = FALSE ;
  else {
  mu__boolexpr625 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr625)) mu__boolexpr624 = FALSE ;
  else {
  mu__boolexpr624 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr624)) mu__boolexpr623 = FALSE ;
  else {
  mu__boolexpr623 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr623)) mu__boolexpr622 = FALSE ;
  else {
  mu__boolexpr622 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr622;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3222;
    static mu__subrange_35 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_34 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_33 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3249 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr626;
bool mu__boolexpr627;
bool mu__boolexpr628;
bool mu__boolexpr629;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr629 = FALSE ;
  else {
  mu__boolexpr629 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr629)) mu__boolexpr628 = FALSE ;
  else {
  mu__boolexpr628 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr628)) mu__boolexpr627 = FALSE ;
  else {
  mu__boolexpr627 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr627)) mu__boolexpr626 = FALSE ;
  else {
  mu__boolexpr626 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr626) {
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
    r = what_rule - 3222;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_35 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_34 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_33 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
  };

};
/******************** RuleBase49 ********************/
class RuleBase49
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_31 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_30 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_31 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_30 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr630;
bool mu__boolexpr631;
bool mu__boolexpr632;
bool mu__boolexpr633;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr633 = FALSE ;
  else {
  mu__boolexpr633 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr633)) mu__boolexpr632 = FALSE ;
  else {
  mu__boolexpr632 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr632)) mu__boolexpr631 = FALSE ;
  else {
  mu__boolexpr631 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr631)) mu__boolexpr630 = FALSE ;
  else {
  mu__boolexpr630 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr630;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3249;
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_31 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_30 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3330 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr634;
bool mu__boolexpr635;
bool mu__boolexpr636;
bool mu__boolexpr637;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr637 = FALSE ;
  else {
  mu__boolexpr637 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
  if (!(mu__boolexpr637)) mu__boolexpr636 = FALSE ;
  else {
  mu__boolexpr636 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr636)) mu__boolexpr635 = FALSE ;
  else {
  mu__boolexpr635 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (2)) ; 
}
  if (!(mu__boolexpr635)) mu__boolexpr634 = FALSE ;
  else {
  mu__boolexpr634 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr634) {
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
    r = what_rule - 3249;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_31 mu_n3;
    mu_n3.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_30 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
  };

};
/******************** RuleBase50 ********************/
class RuleBase50
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return (mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3330;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3333 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response)) {
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
    r = what_rule - 3330;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessResponse ( (int)mu_n1, mu_EntryPath[mu_n1] );
  };

};
/******************** RuleBase51 ********************/
class RuleBase51
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr638;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr638 = FALSE ;
  else {
  mu__boolexpr638 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr638;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3333;
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3336 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr639;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr639 = FALSE ;
  else {
  mu__boolexpr639 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr639) {
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
    r = what_rule - 3333;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase52 ********************/
class RuleBase52
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr640;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr640 = FALSE ;
  else {
  mu__boolexpr640 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr640;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3336;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3339 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr641;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr641 = FALSE ;
  else {
  mu__boolexpr641 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr641) {
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
    r = what_rule - 3336;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase53 ********************/
class RuleBase53
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr642;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr642 = FALSE ;
  else {
  mu__boolexpr642 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr642;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3339;
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3342 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr643;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr643 = FALSE ;
  else {
  mu__boolexpr643 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr643) {
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
    r = what_rule - 3339;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase54 ********************/
class RuleBase54
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Rule --> Send request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr644;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr644 = FALSE ;
  else {
  mu__boolexpr644 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
    return mu__boolexpr644;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3342;
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3351 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr645;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr645 = FALSE ;
  else {
  mu__boolexpr645 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
	      if (mu__boolexpr645) {
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
    r = what_rule - 3342;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
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
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
  RuleBase12 R12;
  RuleBase13 R13;
  RuleBase14 R14;
  RuleBase15 R15;
  RuleBase16 R16;
  RuleBase17 R17;
  RuleBase18 R18;
  RuleBase19 R19;
  RuleBase20 R20;
  RuleBase21 R21;
  RuleBase22 R22;
  RuleBase23 R23;
  RuleBase24 R24;
  RuleBase25 R25;
  RuleBase26 R26;
  RuleBase27 R27;
  RuleBase28 R28;
  RuleBase29 R29;
  RuleBase30 R30;
  RuleBase31 R31;
  RuleBase32 R32;
  RuleBase33 R33;
  RuleBase34 R34;
  RuleBase35 R35;
  RuleBase36 R36;
  RuleBase37 R37;
  RuleBase38 R38;
  RuleBase39 R39;
  RuleBase40 R40;
  RuleBase41 R41;
  RuleBase42 R42;
  RuleBase43 R43;
  RuleBase44 R44;
  RuleBase45 R45;
  RuleBase46 R46;
  RuleBase47 R47;
  RuleBase48 R48;
  RuleBase49 R49;
  RuleBase50 R50;
  RuleBase51 R51;
  RuleBase52 R52;
  RuleBase53 R53;
  RuleBase54 R54;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<27)
    { R0.NextRule(what_rule);
      if (what_rule<27) return; }
  if (what_rule>=27 && what_rule<54)
    { R1.NextRule(what_rule);
      if (what_rule<54) return; }
  if (what_rule>=54 && what_rule<81)
    { R2.NextRule(what_rule);
      if (what_rule<81) return; }
  if (what_rule>=81 && what_rule<108)
    { R3.NextRule(what_rule);
      if (what_rule<108) return; }
  if (what_rule>=108 && what_rule<135)
    { R4.NextRule(what_rule);
      if (what_rule<135) return; }
  if (what_rule>=135 && what_rule<162)
    { R5.NextRule(what_rule);
      if (what_rule<162) return; }
  if (what_rule>=162 && what_rule<189)
    { R6.NextRule(what_rule);
      if (what_rule<189) return; }
  if (what_rule>=189 && what_rule<216)
    { R7.NextRule(what_rule);
      if (what_rule<216) return; }
  if (what_rule>=216 && what_rule<243)
    { R8.NextRule(what_rule);
      if (what_rule<243) return; }
  if (what_rule>=243 && what_rule<270)
    { R9.NextRule(what_rule);
      if (what_rule<270) return; }
  if (what_rule>=270 && what_rule<297)
    { R10.NextRule(what_rule);
      if (what_rule<297) return; }
  if (what_rule>=297 && what_rule<324)
    { R11.NextRule(what_rule);
      if (what_rule<324) return; }
  if (what_rule>=324 && what_rule<351)
    { R12.NextRule(what_rule);
      if (what_rule<351) return; }
  if (what_rule>=351 && what_rule<378)
    { R13.NextRule(what_rule);
      if (what_rule<378) return; }
  if (what_rule>=378 && what_rule<405)
    { R14.NextRule(what_rule);
      if (what_rule<405) return; }
  if (what_rule>=405 && what_rule<432)
    { R15.NextRule(what_rule);
      if (what_rule<432) return; }
  if (what_rule>=432 && what_rule<459)
    { R16.NextRule(what_rule);
      if (what_rule<459) return; }
  if (what_rule>=459 && what_rule<486)
    { R17.NextRule(what_rule);
      if (what_rule<486) return; }
  if (what_rule>=486 && what_rule<513)
    { R18.NextRule(what_rule);
      if (what_rule<513) return; }
  if (what_rule>=513 && what_rule<540)
    { R19.NextRule(what_rule);
      if (what_rule<540) return; }
  if (what_rule>=540 && what_rule<621)
    { R20.NextRule(what_rule);
      if (what_rule<621) return; }
  if (what_rule>=621 && what_rule<702)
    { R21.NextRule(what_rule);
      if (what_rule<702) return; }
  if (what_rule>=702 && what_rule<783)
    { R22.NextRule(what_rule);
      if (what_rule<783) return; }
  if (what_rule>=783 && what_rule<864)
    { R23.NextRule(what_rule);
      if (what_rule<864) return; }
  if (what_rule>=864 && what_rule<945)
    { R24.NextRule(what_rule);
      if (what_rule<945) return; }
  if (what_rule>=945 && what_rule<1026)
    { R25.NextRule(what_rule);
      if (what_rule<1026) return; }
  if (what_rule>=1026 && what_rule<1107)
    { R26.NextRule(what_rule);
      if (what_rule<1107) return; }
  if (what_rule>=1107 && what_rule<1188)
    { R27.NextRule(what_rule);
      if (what_rule<1188) return; }
  if (what_rule>=1188 && what_rule<1269)
    { R28.NextRule(what_rule);
      if (what_rule<1269) return; }
  if (what_rule>=1269 && what_rule<1350)
    { R29.NextRule(what_rule);
      if (what_rule<1350) return; }
  if (what_rule>=1350 && what_rule<1593)
    { R30.NextRule(what_rule);
      if (what_rule<1593) return; }
  if (what_rule>=1593 && what_rule<1836)
    { R31.NextRule(what_rule);
      if (what_rule<1836) return; }
  if (what_rule>=1836 && what_rule<2079)
    { R32.NextRule(what_rule);
      if (what_rule<2079) return; }
  if (what_rule>=2079 && what_rule<2322)
    { R33.NextRule(what_rule);
      if (what_rule<2322) return; }
  if (what_rule>=2322 && what_rule<3051)
    { R34.NextRule(what_rule);
      if (what_rule<3051) return; }
  if (what_rule>=3051 && what_rule<3060)
    { R35.NextRule(what_rule);
      if (what_rule<3060) return; }
  if (what_rule>=3060 && what_rule<3069)
    { R36.NextRule(what_rule);
      if (what_rule<3069) return; }
  if (what_rule>=3069 && what_rule<3078)
    { R37.NextRule(what_rule);
      if (what_rule<3078) return; }
  if (what_rule>=3078 && what_rule<3087)
    { R38.NextRule(what_rule);
      if (what_rule<3087) return; }
  if (what_rule>=3087 && what_rule<3096)
    { R39.NextRule(what_rule);
      if (what_rule<3096) return; }
  if (what_rule>=3096 && what_rule<3105)
    { R40.NextRule(what_rule);
      if (what_rule<3105) return; }
  if (what_rule>=3105 && what_rule<3114)
    { R41.NextRule(what_rule);
      if (what_rule<3114) return; }
  if (what_rule>=3114 && what_rule<3123)
    { R42.NextRule(what_rule);
      if (what_rule<3123) return; }
  if (what_rule>=3123 && what_rule<3132)
    { R43.NextRule(what_rule);
      if (what_rule<3132) return; }
  if (what_rule>=3132 && what_rule<3141)
    { R44.NextRule(what_rule);
      if (what_rule<3141) return; }
  if (what_rule>=3141 && what_rule<3168)
    { R45.NextRule(what_rule);
      if (what_rule<3168) return; }
  if (what_rule>=3168 && what_rule<3195)
    { R46.NextRule(what_rule);
      if (what_rule<3195) return; }
  if (what_rule>=3195 && what_rule<3222)
    { R47.NextRule(what_rule);
      if (what_rule<3222) return; }
  if (what_rule>=3222 && what_rule<3249)
    { R48.NextRule(what_rule);
      if (what_rule<3249) return; }
  if (what_rule>=3249 && what_rule<3330)
    { R49.NextRule(what_rule);
      if (what_rule<3330) return; }
  if (what_rule>=3330 && what_rule<3333)
    { R50.NextRule(what_rule);
      if (what_rule<3333) return; }
  if (what_rule>=3333 && what_rule<3336)
    { R51.NextRule(what_rule);
      if (what_rule<3336) return; }
  if (what_rule>=3336 && what_rule<3339)
    { R52.NextRule(what_rule);
      if (what_rule<3339) return; }
  if (what_rule>=3339 && what_rule<3342)
    { R53.NextRule(what_rule);
      if (what_rule<3342) return; }
  if (what_rule>=3342 && what_rule<3351)
    { R54.NextRule(what_rule);
      if (what_rule<3351) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=26) return R0.Condition(r-0);
  if (r>=27 && r<=53) return R1.Condition(r-27);
  if (r>=54 && r<=80) return R2.Condition(r-54);
  if (r>=81 && r<=107) return R3.Condition(r-81);
  if (r>=108 && r<=134) return R4.Condition(r-108);
  if (r>=135 && r<=161) return R5.Condition(r-135);
  if (r>=162 && r<=188) return R6.Condition(r-162);
  if (r>=189 && r<=215) return R7.Condition(r-189);
  if (r>=216 && r<=242) return R8.Condition(r-216);
  if (r>=243 && r<=269) return R9.Condition(r-243);
  if (r>=270 && r<=296) return R10.Condition(r-270);
  if (r>=297 && r<=323) return R11.Condition(r-297);
  if (r>=324 && r<=350) return R12.Condition(r-324);
  if (r>=351 && r<=377) return R13.Condition(r-351);
  if (r>=378 && r<=404) return R14.Condition(r-378);
  if (r>=405 && r<=431) return R15.Condition(r-405);
  if (r>=432 && r<=458) return R16.Condition(r-432);
  if (r>=459 && r<=485) return R17.Condition(r-459);
  if (r>=486 && r<=512) return R18.Condition(r-486);
  if (r>=513 && r<=539) return R19.Condition(r-513);
  if (r>=540 && r<=620) return R20.Condition(r-540);
  if (r>=621 && r<=701) return R21.Condition(r-621);
  if (r>=702 && r<=782) return R22.Condition(r-702);
  if (r>=783 && r<=863) return R23.Condition(r-783);
  if (r>=864 && r<=944) return R24.Condition(r-864);
  if (r>=945 && r<=1025) return R25.Condition(r-945);
  if (r>=1026 && r<=1106) return R26.Condition(r-1026);
  if (r>=1107 && r<=1187) return R27.Condition(r-1107);
  if (r>=1188 && r<=1268) return R28.Condition(r-1188);
  if (r>=1269 && r<=1349) return R29.Condition(r-1269);
  if (r>=1350 && r<=1592) return R30.Condition(r-1350);
  if (r>=1593 && r<=1835) return R31.Condition(r-1593);
  if (r>=1836 && r<=2078) return R32.Condition(r-1836);
  if (r>=2079 && r<=2321) return R33.Condition(r-2079);
  if (r>=2322 && r<=3050) return R34.Condition(r-2322);
  if (r>=3051 && r<=3059) return R35.Condition(r-3051);
  if (r>=3060 && r<=3068) return R36.Condition(r-3060);
  if (r>=3069 && r<=3077) return R37.Condition(r-3069);
  if (r>=3078 && r<=3086) return R38.Condition(r-3078);
  if (r>=3087 && r<=3095) return R39.Condition(r-3087);
  if (r>=3096 && r<=3104) return R40.Condition(r-3096);
  if (r>=3105 && r<=3113) return R41.Condition(r-3105);
  if (r>=3114 && r<=3122) return R42.Condition(r-3114);
  if (r>=3123 && r<=3131) return R43.Condition(r-3123);
  if (r>=3132 && r<=3140) return R44.Condition(r-3132);
  if (r>=3141 && r<=3167) return R45.Condition(r-3141);
  if (r>=3168 && r<=3194) return R46.Condition(r-3168);
  if (r>=3195 && r<=3221) return R47.Condition(r-3195);
  if (r>=3222 && r<=3248) return R48.Condition(r-3222);
  if (r>=3249 && r<=3329) return R49.Condition(r-3249);
  if (r>=3330 && r<=3332) return R50.Condition(r-3330);
  if (r>=3333 && r<=3335) return R51.Condition(r-3333);
  if (r>=3336 && r<=3338) return R52.Condition(r-3336);
  if (r>=3339 && r<=3341) return R53.Condition(r-3339);
  if (r>=3342 && r<=3350) return R54.Condition(r-3342);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=26) { R0.Code(r-0); return; } 
  if (r>=27 && r<=53) { R1.Code(r-27); return; } 
  if (r>=54 && r<=80) { R2.Code(r-54); return; } 
  if (r>=81 && r<=107) { R3.Code(r-81); return; } 
  if (r>=108 && r<=134) { R4.Code(r-108); return; } 
  if (r>=135 && r<=161) { R5.Code(r-135); return; } 
  if (r>=162 && r<=188) { R6.Code(r-162); return; } 
  if (r>=189 && r<=215) { R7.Code(r-189); return; } 
  if (r>=216 && r<=242) { R8.Code(r-216); return; } 
  if (r>=243 && r<=269) { R9.Code(r-243); return; } 
  if (r>=270 && r<=296) { R10.Code(r-270); return; } 
  if (r>=297 && r<=323) { R11.Code(r-297); return; } 
  if (r>=324 && r<=350) { R12.Code(r-324); return; } 
  if (r>=351 && r<=377) { R13.Code(r-351); return; } 
  if (r>=378 && r<=404) { R14.Code(r-378); return; } 
  if (r>=405 && r<=431) { R15.Code(r-405); return; } 
  if (r>=432 && r<=458) { R16.Code(r-432); return; } 
  if (r>=459 && r<=485) { R17.Code(r-459); return; } 
  if (r>=486 && r<=512) { R18.Code(r-486); return; } 
  if (r>=513 && r<=539) { R19.Code(r-513); return; } 
  if (r>=540 && r<=620) { R20.Code(r-540); return; } 
  if (r>=621 && r<=701) { R21.Code(r-621); return; } 
  if (r>=702 && r<=782) { R22.Code(r-702); return; } 
  if (r>=783 && r<=863) { R23.Code(r-783); return; } 
  if (r>=864 && r<=944) { R24.Code(r-864); return; } 
  if (r>=945 && r<=1025) { R25.Code(r-945); return; } 
  if (r>=1026 && r<=1106) { R26.Code(r-1026); return; } 
  if (r>=1107 && r<=1187) { R27.Code(r-1107); return; } 
  if (r>=1188 && r<=1268) { R28.Code(r-1188); return; } 
  if (r>=1269 && r<=1349) { R29.Code(r-1269); return; } 
  if (r>=1350 && r<=1592) { R30.Code(r-1350); return; } 
  if (r>=1593 && r<=1835) { R31.Code(r-1593); return; } 
  if (r>=1836 && r<=2078) { R32.Code(r-1836); return; } 
  if (r>=2079 && r<=2321) { R33.Code(r-2079); return; } 
  if (r>=2322 && r<=3050) { R34.Code(r-2322); return; } 
  if (r>=3051 && r<=3059) { R35.Code(r-3051); return; } 
  if (r>=3060 && r<=3068) { R36.Code(r-3060); return; } 
  if (r>=3069 && r<=3077) { R37.Code(r-3069); return; } 
  if (r>=3078 && r<=3086) { R38.Code(r-3078); return; } 
  if (r>=3087 && r<=3095) { R39.Code(r-3087); return; } 
  if (r>=3096 && r<=3104) { R40.Code(r-3096); return; } 
  if (r>=3105 && r<=3113) { R41.Code(r-3105); return; } 
  if (r>=3114 && r<=3122) { R42.Code(r-3114); return; } 
  if (r>=3123 && r<=3131) { R43.Code(r-3123); return; } 
  if (r>=3132 && r<=3140) { R44.Code(r-3132); return; } 
  if (r>=3141 && r<=3167) { R45.Code(r-3141); return; } 
  if (r>=3168 && r<=3194) { R46.Code(r-3168); return; } 
  if (r>=3195 && r<=3221) { R47.Code(r-3195); return; } 
  if (r>=3222 && r<=3248) { R48.Code(r-3222); return; } 
  if (r>=3249 && r<=3329) { R49.Code(r-3249); return; } 
  if (r>=3330 && r<=3332) { R50.Code(r-3330); return; } 
  if (r>=3333 && r<=3335) { R51.Code(r-3333); return; } 
  if (r>=3336 && r<=3338) { R52.Code(r-3336); return; } 
  if (r>=3339 && r<=3341) { R53.Code(r-3339); return; } 
  if (r>=3342 && r<=3350) { R54.Code(r-3342); return; } 
}
int Priority(unsigned short r)
{
  if (r<=26) { return R0.Priority(); } 
  if (r>=27 && r<=53) { return R1.Priority(); } 
  if (r>=54 && r<=80) { return R2.Priority(); } 
  if (r>=81 && r<=107) { return R3.Priority(); } 
  if (r>=108 && r<=134) { return R4.Priority(); } 
  if (r>=135 && r<=161) { return R5.Priority(); } 
  if (r>=162 && r<=188) { return R6.Priority(); } 
  if (r>=189 && r<=215) { return R7.Priority(); } 
  if (r>=216 && r<=242) { return R8.Priority(); } 
  if (r>=243 && r<=269) { return R9.Priority(); } 
  if (r>=270 && r<=296) { return R10.Priority(); } 
  if (r>=297 && r<=323) { return R11.Priority(); } 
  if (r>=324 && r<=350) { return R12.Priority(); } 
  if (r>=351 && r<=377) { return R13.Priority(); } 
  if (r>=378 && r<=404) { return R14.Priority(); } 
  if (r>=405 && r<=431) { return R15.Priority(); } 
  if (r>=432 && r<=458) { return R16.Priority(); } 
  if (r>=459 && r<=485) { return R17.Priority(); } 
  if (r>=486 && r<=512) { return R18.Priority(); } 
  if (r>=513 && r<=539) { return R19.Priority(); } 
  if (r>=540 && r<=620) { return R20.Priority(); } 
  if (r>=621 && r<=701) { return R21.Priority(); } 
  if (r>=702 && r<=782) { return R22.Priority(); } 
  if (r>=783 && r<=863) { return R23.Priority(); } 
  if (r>=864 && r<=944) { return R24.Priority(); } 
  if (r>=945 && r<=1025) { return R25.Priority(); } 
  if (r>=1026 && r<=1106) { return R26.Priority(); } 
  if (r>=1107 && r<=1187) { return R27.Priority(); } 
  if (r>=1188 && r<=1268) { return R28.Priority(); } 
  if (r>=1269 && r<=1349) { return R29.Priority(); } 
  if (r>=1350 && r<=1592) { return R30.Priority(); } 
  if (r>=1593 && r<=1835) { return R31.Priority(); } 
  if (r>=1836 && r<=2078) { return R32.Priority(); } 
  if (r>=2079 && r<=2321) { return R33.Priority(); } 
  if (r>=2322 && r<=3050) { return R34.Priority(); } 
  if (r>=3051 && r<=3059) { return R35.Priority(); } 
  if (r>=3060 && r<=3068) { return R36.Priority(); } 
  if (r>=3069 && r<=3077) { return R37.Priority(); } 
  if (r>=3078 && r<=3086) { return R38.Priority(); } 
  if (r>=3087 && r<=3095) { return R39.Priority(); } 
  if (r>=3096 && r<=3104) { return R40.Priority(); } 
  if (r>=3105 && r<=3113) { return R41.Priority(); } 
  if (r>=3114 && r<=3122) { return R42.Priority(); } 
  if (r>=3123 && r<=3131) { return R43.Priority(); } 
  if (r>=3132 && r<=3140) { return R44.Priority(); } 
  if (r>=3141 && r<=3167) { return R45.Priority(); } 
  if (r>=3168 && r<=3194) { return R46.Priority(); } 
  if (r>=3195 && r<=3221) { return R47.Priority(); } 
  if (r>=3222 && r<=3248) { return R48.Priority(); } 
  if (r>=3249 && r<=3329) { return R49.Priority(); } 
  if (r>=3330 && r<=3332) { return R50.Priority(); } 
  if (r>=3333 && r<=3335) { return R51.Priority(); } 
  if (r>=3336 && r<=3338) { return R52.Priority(); } 
  if (r>=3339 && r<=3341) { return R53.Priority(); } 
  if (r>=3342 && r<=3350) { return R54.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=26) return R0.Name(r-0);
  if (r>=27 && r<=53) return R1.Name(r-27);
  if (r>=54 && r<=80) return R2.Name(r-54);
  if (r>=81 && r<=107) return R3.Name(r-81);
  if (r>=108 && r<=134) return R4.Name(r-108);
  if (r>=135 && r<=161) return R5.Name(r-135);
  if (r>=162 && r<=188) return R6.Name(r-162);
  if (r>=189 && r<=215) return R7.Name(r-189);
  if (r>=216 && r<=242) return R8.Name(r-216);
  if (r>=243 && r<=269) return R9.Name(r-243);
  if (r>=270 && r<=296) return R10.Name(r-270);
  if (r>=297 && r<=323) return R11.Name(r-297);
  if (r>=324 && r<=350) return R12.Name(r-324);
  if (r>=351 && r<=377) return R13.Name(r-351);
  if (r>=378 && r<=404) return R14.Name(r-378);
  if (r>=405 && r<=431) return R15.Name(r-405);
  if (r>=432 && r<=458) return R16.Name(r-432);
  if (r>=459 && r<=485) return R17.Name(r-459);
  if (r>=486 && r<=512) return R18.Name(r-486);
  if (r>=513 && r<=539) return R19.Name(r-513);
  if (r>=540 && r<=620) return R20.Name(r-540);
  if (r>=621 && r<=701) return R21.Name(r-621);
  if (r>=702 && r<=782) return R22.Name(r-702);
  if (r>=783 && r<=863) return R23.Name(r-783);
  if (r>=864 && r<=944) return R24.Name(r-864);
  if (r>=945 && r<=1025) return R25.Name(r-945);
  if (r>=1026 && r<=1106) return R26.Name(r-1026);
  if (r>=1107 && r<=1187) return R27.Name(r-1107);
  if (r>=1188 && r<=1268) return R28.Name(r-1188);
  if (r>=1269 && r<=1349) return R29.Name(r-1269);
  if (r>=1350 && r<=1592) return R30.Name(r-1350);
  if (r>=1593 && r<=1835) return R31.Name(r-1593);
  if (r>=1836 && r<=2078) return R32.Name(r-1836);
  if (r>=2079 && r<=2321) return R33.Name(r-2079);
  if (r>=2322 && r<=3050) return R34.Name(r-2322);
  if (r>=3051 && r<=3059) return R35.Name(r-3051);
  if (r>=3060 && r<=3068) return R36.Name(r-3060);
  if (r>=3069 && r<=3077) return R37.Name(r-3069);
  if (r>=3078 && r<=3086) return R38.Name(r-3078);
  if (r>=3087 && r<=3095) return R39.Name(r-3087);
  if (r>=3096 && r<=3104) return R40.Name(r-3096);
  if (r>=3105 && r<=3113) return R41.Name(r-3105);
  if (r>=3114 && r<=3122) return R42.Name(r-3114);
  if (r>=3123 && r<=3131) return R43.Name(r-3123);
  if (r>=3132 && r<=3140) return R44.Name(r-3132);
  if (r>=3141 && r<=3167) return R45.Name(r-3141);
  if (r>=3168 && r<=3194) return R46.Name(r-3168);
  if (r>=3195 && r<=3221) return R47.Name(r-3195);
  if (r>=3222 && r<=3248) return R48.Name(r-3222);
  if (r>=3249 && r<=3329) return R49.Name(r-3249);
  if (r>=3330 && r<=3332) return R50.Name(r-3330);
  if (r>=3333 && r<=3335) return R51.Name(r-3333);
  if (r>=3336 && r<=3338) return R52.Name(r-3336);
  if (r>=3339 && r<=3341) return R53.Name(r-3339);
  if (r>=3342 && r<=3350) return R54.Name(r-3342);
  return NULL;
}
};
const unsigned numrules = 3351;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 3351


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
for(int mu_nid1 = 0; mu_nid1 <= 2; mu_nid1++) {
{
for(int mu_nid2 = 0; mu_nid2 <= 2; mu_nid2++) {
{
for(int mu_s = 0; mu_s <= 2; mu_s++) {
mu_IncomingQueue[mu_nid1][mu_nid2][mu_s].mu_msg_type = mu_empty;
};
};
mu_TailPointers[mu_nid1][mu_nid2] = 0;
};
};
};
};
{
for(int mu_nid = 0; mu_nid <= 2; mu_nid++) {
if ( (mu_nid) != (2) )
{
mu_ExitPath[mu_nid] = (mu_nid) + (1);
if ( (mu_nid) == (0) )
{
mu_EntryPath[mu_nid] = 2;
}
else
{
mu_EntryPath[mu_nid] = (mu_nid) - (1);
}
}
else
{
mu_ExitPath[mu_nid] = 0;
mu_EntryPath[mu_nid] = (mu_nid) - (1);
}
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
TailPointers:NoScalarset
IncomingQueue:NoScalarset
RouterStatus:NoScalarset
ExitPath:NoScalarset
EntryPath:NoScalarset
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
        mu_TailPointers.MultisetSort();
        mu_IncomingQueue.MultisetSort();
        mu_RouterStatus.MultisetSort();
        mu_ExitPath.MultisetSort();
        mu_EntryPath.MultisetSort();
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
  for (j=0; j<3; j++)
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
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<3; j++)
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
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<3; j++)
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
  for (j=0; j<3; j++)
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
void mu__subrange_13::Permute(PermSet& Perm, int i) {};
void mu__subrange_13::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_13::Canonicalize(PermSet& Perm) {};
void mu__subrange_13::SimpleLimit(PermSet& Perm) {};
void mu__subrange_13::ArrayLimit(PermSet& Perm) {};
void mu__subrange_13::Limit(PermSet& Perm) {};
void mu__subrange_13::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
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
  for (j=0; j<4; j++)
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
  for (j=0; j<3; j++)
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
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_8::Canonicalize(PermSet& Perm){};
void mu_1__type_8::SimpleLimit(PermSet& Perm){}
void mu_1__type_8::ArrayLimit(PermSet& Perm) {}
void mu_1__type_8::Limit(PermSet& Perm){}
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
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
void mu__subrange_40::Permute(PermSet& Perm, int i) {};
void mu__subrange_40::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_40::Canonicalize(PermSet& Perm) {};
void mu__subrange_40::SimpleLimit(PermSet& Perm) {};
void mu__subrange_40::ArrayLimit(PermSet& Perm) {};
void mu__subrange_40::Limit(PermSet& Perm) {};
void mu__subrange_40::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_41::Permute(PermSet& Perm, int i) {};
void mu__subrange_41::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_41::Canonicalize(PermSet& Perm) {};
void mu__subrange_41::SimpleLimit(PermSet& Perm) {};
void mu__subrange_41::ArrayLimit(PermSet& Perm) {};
void mu__subrange_41::Limit(PermSet& Perm) {};
void mu__subrange_41::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_42::Permute(PermSet& Perm, int i) {};
void mu__subrange_42::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_42::Canonicalize(PermSet& Perm) {};
void mu__subrange_42::SimpleLimit(PermSet& Perm) {};
void mu__subrange_42::ArrayLimit(PermSet& Perm) {};
void mu__subrange_42::Limit(PermSet& Perm) {};
void mu__subrange_42::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_43::Permute(PermSet& Perm, int i) {};
void mu__subrange_43::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_43::Canonicalize(PermSet& Perm) {};
void mu__subrange_43::SimpleLimit(PermSet& Perm) {};
void mu__subrange_43::ArrayLimit(PermSet& Perm) {};
void mu__subrange_43::Limit(PermSet& Perm) {};
void mu__subrange_43::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_44::Permute(PermSet& Perm, int i) {};
void mu__subrange_44::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_44::Canonicalize(PermSet& Perm) {};
void mu__subrange_44::SimpleLimit(PermSet& Perm) {};
void mu__subrange_44::ArrayLimit(PermSet& Perm) {};
void mu__subrange_44::Limit(PermSet& Perm) {};
void mu__subrange_44::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_45::Permute(PermSet& Perm, int i) {};
void mu__subrange_45::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_45::Canonicalize(PermSet& Perm) {};
void mu__subrange_45::SimpleLimit(PermSet& Perm) {};
void mu__subrange_45::ArrayLimit(PermSet& Perm) {};
void mu__subrange_45::Limit(PermSet& Perm) {};
void mu__subrange_45::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_46::Permute(PermSet& Perm, int i) {};
void mu__subrange_46::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_46::Canonicalize(PermSet& Perm) {};
void mu__subrange_46::SimpleLimit(PermSet& Perm) {};
void mu__subrange_46::ArrayLimit(PermSet& Perm) {};
void mu__subrange_46::Limit(PermSet& Perm) {};
void mu__subrange_46::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_47::Permute(PermSet& Perm, int i) {};
void mu__subrange_47::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_47::Canonicalize(PermSet& Perm) {};
void mu__subrange_47::SimpleLimit(PermSet& Perm) {};
void mu__subrange_47::ArrayLimit(PermSet& Perm) {};
void mu__subrange_47::Limit(PermSet& Perm) {};
void mu__subrange_47::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_48::Permute(PermSet& Perm, int i) {};
void mu__subrange_48::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_48::Canonicalize(PermSet& Perm) {};
void mu__subrange_48::SimpleLimit(PermSet& Perm) {};
void mu__subrange_48::ArrayLimit(PermSet& Perm) {};
void mu__subrange_48::Limit(PermSet& Perm) {};
void mu__subrange_48::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_49::Permute(PermSet& Perm, int i) {};
void mu__subrange_49::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_49::Canonicalize(PermSet& Perm) {};
void mu__subrange_49::SimpleLimit(PermSet& Perm) {};
void mu__subrange_49::ArrayLimit(PermSet& Perm) {};
void mu__subrange_49::Limit(PermSet& Perm) {};
void mu__subrange_49::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_50::Permute(PermSet& Perm, int i) {};
void mu__subrange_50::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_50::Canonicalize(PermSet& Perm) {};
void mu__subrange_50::SimpleLimit(PermSet& Perm) {};
void mu__subrange_50::ArrayLimit(PermSet& Perm) {};
void mu__subrange_50::Limit(PermSet& Perm) {};
void mu__subrange_50::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_51::Permute(PermSet& Perm, int i) {};
void mu__subrange_51::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_51::Canonicalize(PermSet& Perm) {};
void mu__subrange_51::SimpleLimit(PermSet& Perm) {};
void mu__subrange_51::ArrayLimit(PermSet& Perm) {};
void mu__subrange_51::Limit(PermSet& Perm) {};
void mu__subrange_51::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_52::Permute(PermSet& Perm, int i) {};
void mu__subrange_52::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_52::Canonicalize(PermSet& Perm) {};
void mu__subrange_52::SimpleLimit(PermSet& Perm) {};
void mu__subrange_52::ArrayLimit(PermSet& Perm) {};
void mu__subrange_52::Limit(PermSet& Perm) {};
void mu__subrange_52::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_53::Permute(PermSet& Perm, int i) {};
void mu__subrange_53::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_53::Canonicalize(PermSet& Perm) {};
void mu__subrange_53::SimpleLimit(PermSet& Perm) {};
void mu__subrange_53::ArrayLimit(PermSet& Perm) {};
void mu__subrange_53::Limit(PermSet& Perm) {};
void mu__subrange_53::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_54::Permute(PermSet& Perm, int i) {};
void mu__subrange_54::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_54::Canonicalize(PermSet& Perm) {};
void mu__subrange_54::SimpleLimit(PermSet& Perm) {};
void mu__subrange_54::ArrayLimit(PermSet& Perm) {};
void mu__subrange_54::Limit(PermSet& Perm) {};
void mu__subrange_54::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_55::Permute(PermSet& Perm, int i) {};
void mu__subrange_55::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_55::Canonicalize(PermSet& Perm) {};
void mu__subrange_55::SimpleLimit(PermSet& Perm) {};
void mu__subrange_55::ArrayLimit(PermSet& Perm) {};
void mu__subrange_55::Limit(PermSet& Perm) {};
void mu__subrange_55::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_56::Permute(PermSet& Perm, int i) {};
void mu__subrange_56::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_56::Canonicalize(PermSet& Perm) {};
void mu__subrange_56::SimpleLimit(PermSet& Perm) {};
void mu__subrange_56::ArrayLimit(PermSet& Perm) {};
void mu__subrange_56::Limit(PermSet& Perm) {};
void mu__subrange_56::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_57::Permute(PermSet& Perm, int i) {};
void mu__subrange_57::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_57::Canonicalize(PermSet& Perm) {};
void mu__subrange_57::SimpleLimit(PermSet& Perm) {};
void mu__subrange_57::ArrayLimit(PermSet& Perm) {};
void mu__subrange_57::Limit(PermSet& Perm) {};
void mu__subrange_57::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_58::Permute(PermSet& Perm, int i) {};
void mu__subrange_58::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_58::Canonicalize(PermSet& Perm) {};
void mu__subrange_58::SimpleLimit(PermSet& Perm) {};
void mu__subrange_58::ArrayLimit(PermSet& Perm) {};
void mu__subrange_58::Limit(PermSet& Perm) {};
void mu__subrange_58::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_59::Permute(PermSet& Perm, int i) {};
void mu__subrange_59::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_59::Canonicalize(PermSet& Perm) {};
void mu__subrange_59::SimpleLimit(PermSet& Perm) {};
void mu__subrange_59::ArrayLimit(PermSet& Perm) {};
void mu__subrange_59::Limit(PermSet& Perm) {};
void mu__subrange_59::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_60::Permute(PermSet& Perm, int i) {};
void mu__subrange_60::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_60::Canonicalize(PermSet& Perm) {};
void mu__subrange_60::SimpleLimit(PermSet& Perm) {};
void mu__subrange_60::ArrayLimit(PermSet& Perm) {};
void mu__subrange_60::Limit(PermSet& Perm) {};
void mu__subrange_60::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_61::Permute(PermSet& Perm, int i) {};
void mu__subrange_61::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_61::Canonicalize(PermSet& Perm) {};
void mu__subrange_61::SimpleLimit(PermSet& Perm) {};
void mu__subrange_61::ArrayLimit(PermSet& Perm) {};
void mu__subrange_61::Limit(PermSet& Perm) {};
void mu__subrange_61::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_62::Permute(PermSet& Perm, int i) {};
void mu__subrange_62::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_62::Canonicalize(PermSet& Perm) {};
void mu__subrange_62::SimpleLimit(PermSet& Perm) {};
void mu__subrange_62::ArrayLimit(PermSet& Perm) {};
void mu__subrange_62::Limit(PermSet& Perm) {};
void mu__subrange_62::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_63::Permute(PermSet& Perm, int i) {};
void mu__subrange_63::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_63::Canonicalize(PermSet& Perm) {};
void mu__subrange_63::SimpleLimit(PermSet& Perm) {};
void mu__subrange_63::ArrayLimit(PermSet& Perm) {};
void mu__subrange_63::Limit(PermSet& Perm) {};
void mu__subrange_63::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_64::Permute(PermSet& Perm, int i) {};
void mu__subrange_64::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_64::Canonicalize(PermSet& Perm) {};
void mu__subrange_64::SimpleLimit(PermSet& Perm) {};
void mu__subrange_64::ArrayLimit(PermSet& Perm) {};
void mu__subrange_64::Limit(PermSet& Perm) {};
void mu__subrange_64::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_65::Permute(PermSet& Perm, int i) {};
void mu__subrange_65::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_65::Canonicalize(PermSet& Perm) {};
void mu__subrange_65::SimpleLimit(PermSet& Perm) {};
void mu__subrange_65::ArrayLimit(PermSet& Perm) {};
void mu__subrange_65::Limit(PermSet& Perm) {};
void mu__subrange_65::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_66::Permute(PermSet& Perm, int i) {};
void mu__subrange_66::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_66::Canonicalize(PermSet& Perm) {};
void mu__subrange_66::SimpleLimit(PermSet& Perm) {};
void mu__subrange_66::ArrayLimit(PermSet& Perm) {};
void mu__subrange_66::Limit(PermSet& Perm) {};
void mu__subrange_66::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_67::Permute(PermSet& Perm, int i) {};
void mu__subrange_67::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_67::Canonicalize(PermSet& Perm) {};
void mu__subrange_67::SimpleLimit(PermSet& Perm) {};
void mu__subrange_67::ArrayLimit(PermSet& Perm) {};
void mu__subrange_67::Limit(PermSet& Perm) {};
void mu__subrange_67::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_68::Permute(PermSet& Perm, int i) {};
void mu__subrange_68::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_68::Canonicalize(PermSet& Perm) {};
void mu__subrange_68::SimpleLimit(PermSet& Perm) {};
void mu__subrange_68::ArrayLimit(PermSet& Perm) {};
void mu__subrange_68::Limit(PermSet& Perm) {};
void mu__subrange_68::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_69::Permute(PermSet& Perm, int i) {};
void mu__subrange_69::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_69::Canonicalize(PermSet& Perm) {};
void mu__subrange_69::SimpleLimit(PermSet& Perm) {};
void mu__subrange_69::ArrayLimit(PermSet& Perm) {};
void mu__subrange_69::Limit(PermSet& Perm) {};
void mu__subrange_69::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_70::Permute(PermSet& Perm, int i) {};
void mu__subrange_70::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_70::Canonicalize(PermSet& Perm) {};
void mu__subrange_70::SimpleLimit(PermSet& Perm) {};
void mu__subrange_70::ArrayLimit(PermSet& Perm) {};
void mu__subrange_70::Limit(PermSet& Perm) {};
void mu__subrange_70::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_71::Permute(PermSet& Perm, int i) {};
void mu__subrange_71::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_71::Canonicalize(PermSet& Perm) {};
void mu__subrange_71::SimpleLimit(PermSet& Perm) {};
void mu__subrange_71::ArrayLimit(PermSet& Perm) {};
void mu__subrange_71::Limit(PermSet& Perm) {};
void mu__subrange_71::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_72::Permute(PermSet& Perm, int i) {};
void mu__subrange_72::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_72::Canonicalize(PermSet& Perm) {};
void mu__subrange_72::SimpleLimit(PermSet& Perm) {};
void mu__subrange_72::ArrayLimit(PermSet& Perm) {};
void mu__subrange_72::Limit(PermSet& Perm) {};
void mu__subrange_72::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_73::Permute(PermSet& Perm, int i) {};
void mu__subrange_73::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_73::Canonicalize(PermSet& Perm) {};
void mu__subrange_73::SimpleLimit(PermSet& Perm) {};
void mu__subrange_73::ArrayLimit(PermSet& Perm) {};
void mu__subrange_73::Limit(PermSet& Perm) {};
void mu__subrange_73::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_74::Permute(PermSet& Perm, int i) {};
void mu__subrange_74::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_74::Canonicalize(PermSet& Perm) {};
void mu__subrange_74::SimpleLimit(PermSet& Perm) {};
void mu__subrange_74::ArrayLimit(PermSet& Perm) {};
void mu__subrange_74::Limit(PermSet& Perm) {};
void mu__subrange_74::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_75::Permute(PermSet& Perm, int i) {};
void mu__subrange_75::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_75::Canonicalize(PermSet& Perm) {};
void mu__subrange_75::SimpleLimit(PermSet& Perm) {};
void mu__subrange_75::ArrayLimit(PermSet& Perm) {};
void mu__subrange_75::Limit(PermSet& Perm) {};
void mu__subrange_75::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_76::Permute(PermSet& Perm, int i) {};
void mu__subrange_76::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_76::Canonicalize(PermSet& Perm) {};
void mu__subrange_76::SimpleLimit(PermSet& Perm) {};
void mu__subrange_76::ArrayLimit(PermSet& Perm) {};
void mu__subrange_76::Limit(PermSet& Perm) {};
void mu__subrange_76::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_77::Permute(PermSet& Perm, int i) {};
void mu__subrange_77::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_77::Canonicalize(PermSet& Perm) {};
void mu__subrange_77::SimpleLimit(PermSet& Perm) {};
void mu__subrange_77::ArrayLimit(PermSet& Perm) {};
void mu__subrange_77::Limit(PermSet& Perm) {};
void mu__subrange_77::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_78::Permute(PermSet& Perm, int i) {};
void mu__subrange_78::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_78::Canonicalize(PermSet& Perm) {};
void mu__subrange_78::SimpleLimit(PermSet& Perm) {};
void mu__subrange_78::ArrayLimit(PermSet& Perm) {};
void mu__subrange_78::Limit(PermSet& Perm) {};
void mu__subrange_78::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_79::Permute(PermSet& Perm, int i) {};
void mu__subrange_79::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_79::Canonicalize(PermSet& Perm) {};
void mu__subrange_79::SimpleLimit(PermSet& Perm) {};
void mu__subrange_79::ArrayLimit(PermSet& Perm) {};
void mu__subrange_79::Limit(PermSet& Perm) {};
void mu__subrange_79::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_80::Permute(PermSet& Perm, int i) {};
void mu__subrange_80::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_80::Canonicalize(PermSet& Perm) {};
void mu__subrange_80::SimpleLimit(PermSet& Perm) {};
void mu__subrange_80::ArrayLimit(PermSet& Perm) {};
void mu__subrange_80::Limit(PermSet& Perm) {};
void mu__subrange_80::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_81::Permute(PermSet& Perm, int i) {};
void mu__subrange_81::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_81::Canonicalize(PermSet& Perm) {};
void mu__subrange_81::SimpleLimit(PermSet& Perm) {};
void mu__subrange_81::ArrayLimit(PermSet& Perm) {};
void mu__subrange_81::Limit(PermSet& Perm) {};
void mu__subrange_81::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_82::Permute(PermSet& Perm, int i) {};
void mu__subrange_82::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_82::Canonicalize(PermSet& Perm) {};
void mu__subrange_82::SimpleLimit(PermSet& Perm) {};
void mu__subrange_82::ArrayLimit(PermSet& Perm) {};
void mu__subrange_82::Limit(PermSet& Perm) {};
void mu__subrange_82::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_83::Permute(PermSet& Perm, int i) {};
void mu__subrange_83::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_83::Canonicalize(PermSet& Perm) {};
void mu__subrange_83::SimpleLimit(PermSet& Perm) {};
void mu__subrange_83::ArrayLimit(PermSet& Perm) {};
void mu__subrange_83::Limit(PermSet& Perm) {};
void mu__subrange_83::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_84::Permute(PermSet& Perm, int i) {};
void mu__subrange_84::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_84::Canonicalize(PermSet& Perm) {};
void mu__subrange_84::SimpleLimit(PermSet& Perm) {};
void mu__subrange_84::ArrayLimit(PermSet& Perm) {};
void mu__subrange_84::Limit(PermSet& Perm) {};
void mu__subrange_84::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_85::Permute(PermSet& Perm, int i) {};
void mu__subrange_85::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_85::Canonicalize(PermSet& Perm) {};
void mu__subrange_85::SimpleLimit(PermSet& Perm) {};
void mu__subrange_85::ArrayLimit(PermSet& Perm) {};
void mu__subrange_85::Limit(PermSet& Perm) {};
void mu__subrange_85::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_86::Permute(PermSet& Perm, int i) {};
void mu__subrange_86::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_86::Canonicalize(PermSet& Perm) {};
void mu__subrange_86::SimpleLimit(PermSet& Perm) {};
void mu__subrange_86::ArrayLimit(PermSet& Perm) {};
void mu__subrange_86::Limit(PermSet& Perm) {};
void mu__subrange_86::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_87::Permute(PermSet& Perm, int i) {};
void mu__subrange_87::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_87::Canonicalize(PermSet& Perm) {};
void mu__subrange_87::SimpleLimit(PermSet& Perm) {};
void mu__subrange_87::ArrayLimit(PermSet& Perm) {};
void mu__subrange_87::Limit(PermSet& Perm) {};
void mu__subrange_87::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_88::Permute(PermSet& Perm, int i) {};
void mu__subrange_88::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_88::Canonicalize(PermSet& Perm) {};
void mu__subrange_88::SimpleLimit(PermSet& Perm) {};
void mu__subrange_88::ArrayLimit(PermSet& Perm) {};
void mu__subrange_88::Limit(PermSet& Perm) {};
void mu__subrange_88::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_89::Permute(PermSet& Perm, int i) {};
void mu__subrange_89::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_89::Canonicalize(PermSet& Perm) {};
void mu__subrange_89::SimpleLimit(PermSet& Perm) {};
void mu__subrange_89::ArrayLimit(PermSet& Perm) {};
void mu__subrange_89::Limit(PermSet& Perm) {};
void mu__subrange_89::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_90::Permute(PermSet& Perm, int i) {};
void mu__subrange_90::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_90::Canonicalize(PermSet& Perm) {};
void mu__subrange_90::SimpleLimit(PermSet& Perm) {};
void mu__subrange_90::ArrayLimit(PermSet& Perm) {};
void mu__subrange_90::Limit(PermSet& Perm) {};
void mu__subrange_90::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_91::Permute(PermSet& Perm, int i) {};
void mu__subrange_91::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_91::Canonicalize(PermSet& Perm) {};
void mu__subrange_91::SimpleLimit(PermSet& Perm) {};
void mu__subrange_91::ArrayLimit(PermSet& Perm) {};
void mu__subrange_91::Limit(PermSet& Perm) {};
void mu__subrange_91::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_92::Permute(PermSet& Perm, int i) {};
void mu__subrange_92::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_92::Canonicalize(PermSet& Perm) {};
void mu__subrange_92::SimpleLimit(PermSet& Perm) {};
void mu__subrange_92::ArrayLimit(PermSet& Perm) {};
void mu__subrange_92::Limit(PermSet& Perm) {};
void mu__subrange_92::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_93::Permute(PermSet& Perm, int i) {};
void mu__subrange_93::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_93::Canonicalize(PermSet& Perm) {};
void mu__subrange_93::SimpleLimit(PermSet& Perm) {};
void mu__subrange_93::ArrayLimit(PermSet& Perm) {};
void mu__subrange_93::Limit(PermSet& Perm) {};
void mu__subrange_93::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_94::Permute(PermSet& Perm, int i) {};
void mu__subrange_94::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_94::Canonicalize(PermSet& Perm) {};
void mu__subrange_94::SimpleLimit(PermSet& Perm) {};
void mu__subrange_94::ArrayLimit(PermSet& Perm) {};
void mu__subrange_94::Limit(PermSet& Perm) {};
void mu__subrange_94::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_95::Permute(PermSet& Perm, int i) {};
void mu__subrange_95::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_95::Canonicalize(PermSet& Perm) {};
void mu__subrange_95::SimpleLimit(PermSet& Perm) {};
void mu__subrange_95::ArrayLimit(PermSet& Perm) {};
void mu__subrange_95::Limit(PermSet& Perm) {};
void mu__subrange_95::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_96::Permute(PermSet& Perm, int i) {};
void mu__subrange_96::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_96::Canonicalize(PermSet& Perm) {};
void mu__subrange_96::SimpleLimit(PermSet& Perm) {};
void mu__subrange_96::ArrayLimit(PermSet& Perm) {};
void mu__subrange_96::Limit(PermSet& Perm) {};
void mu__subrange_96::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_97::Permute(PermSet& Perm, int i) {};
void mu__subrange_97::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_97::Canonicalize(PermSet& Perm) {};
void mu__subrange_97::SimpleLimit(PermSet& Perm) {};
void mu__subrange_97::ArrayLimit(PermSet& Perm) {};
void mu__subrange_97::Limit(PermSet& Perm) {};
void mu__subrange_97::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_98::Permute(PermSet& Perm, int i) {};
void mu__subrange_98::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_98::Canonicalize(PermSet& Perm) {};
void mu__subrange_98::SimpleLimit(PermSet& Perm) {};
void mu__subrange_98::ArrayLimit(PermSet& Perm) {};
void mu__subrange_98::Limit(PermSet& Perm) {};
void mu__subrange_98::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_99::Permute(PermSet& Perm, int i) {};
void mu__subrange_99::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_99::Canonicalize(PermSet& Perm) {};
void mu__subrange_99::SimpleLimit(PermSet& Perm) {};
void mu__subrange_99::ArrayLimit(PermSet& Perm) {};
void mu__subrange_99::Limit(PermSet& Perm) {};
void mu__subrange_99::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_100::Permute(PermSet& Perm, int i) {};
void mu__subrange_100::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_100::Canonicalize(PermSet& Perm) {};
void mu__subrange_100::SimpleLimit(PermSet& Perm) {};
void mu__subrange_100::ArrayLimit(PermSet& Perm) {};
void mu__subrange_100::Limit(PermSet& Perm) {};
void mu__subrange_100::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_101::Permute(PermSet& Perm, int i) {};
void mu__subrange_101::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_101::Canonicalize(PermSet& Perm) {};
void mu__subrange_101::SimpleLimit(PermSet& Perm) {};
void mu__subrange_101::ArrayLimit(PermSet& Perm) {};
void mu__subrange_101::Limit(PermSet& Perm) {};
void mu__subrange_101::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_102::Permute(PermSet& Perm, int i) {};
void mu__subrange_102::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_102::Canonicalize(PermSet& Perm) {};
void mu__subrange_102::SimpleLimit(PermSet& Perm) {};
void mu__subrange_102::ArrayLimit(PermSet& Perm) {};
void mu__subrange_102::Limit(PermSet& Perm) {};
void mu__subrange_102::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_103::Permute(PermSet& Perm, int i) {};
void mu__subrange_103::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_103::Canonicalize(PermSet& Perm) {};
void mu__subrange_103::SimpleLimit(PermSet& Perm) {};
void mu__subrange_103::ArrayLimit(PermSet& Perm) {};
void mu__subrange_103::Limit(PermSet& Perm) {};
void mu__subrange_103::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_104::Permute(PermSet& Perm, int i) {};
void mu__subrange_104::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_104::Canonicalize(PermSet& Perm) {};
void mu__subrange_104::SimpleLimit(PermSet& Perm) {};
void mu__subrange_104::ArrayLimit(PermSet& Perm) {};
void mu__subrange_104::Limit(PermSet& Perm) {};
void mu__subrange_104::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_105::Permute(PermSet& Perm, int i) {};
void mu__subrange_105::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_105::Canonicalize(PermSet& Perm) {};
void mu__subrange_105::SimpleLimit(PermSet& Perm) {};
void mu__subrange_105::ArrayLimit(PermSet& Perm) {};
void mu__subrange_105::Limit(PermSet& Perm) {};
void mu__subrange_105::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_106::Permute(PermSet& Perm, int i) {};
void mu__subrange_106::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_106::Canonicalize(PermSet& Perm) {};
void mu__subrange_106::SimpleLimit(PermSet& Perm) {};
void mu__subrange_106::ArrayLimit(PermSet& Perm) {};
void mu__subrange_106::Limit(PermSet& Perm) {};
void mu__subrange_106::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_107::Permute(PermSet& Perm, int i) {};
void mu__subrange_107::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_107::Canonicalize(PermSet& Perm) {};
void mu__subrange_107::SimpleLimit(PermSet& Perm) {};
void mu__subrange_107::ArrayLimit(PermSet& Perm) {};
void mu__subrange_107::Limit(PermSet& Perm) {};
void mu__subrange_107::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_108::Permute(PermSet& Perm, int i) {};
void mu__subrange_108::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_108::Canonicalize(PermSet& Perm) {};
void mu__subrange_108::SimpleLimit(PermSet& Perm) {};
void mu__subrange_108::ArrayLimit(PermSet& Perm) {};
void mu__subrange_108::Limit(PermSet& Perm) {};
void mu__subrange_108::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_109::Permute(PermSet& Perm, int i) {};
void mu__subrange_109::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_109::Canonicalize(PermSet& Perm) {};
void mu__subrange_109::SimpleLimit(PermSet& Perm) {};
void mu__subrange_109::ArrayLimit(PermSet& Perm) {};
void mu__subrange_109::Limit(PermSet& Perm) {};
void mu__subrange_109::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_110::Permute(PermSet& Perm, int i) {};
void mu__subrange_110::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_110::Canonicalize(PermSet& Perm) {};
void mu__subrange_110::SimpleLimit(PermSet& Perm) {};
void mu__subrange_110::ArrayLimit(PermSet& Perm) {};
void mu__subrange_110::Limit(PermSet& Perm) {};
void mu__subrange_110::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_111::Permute(PermSet& Perm, int i) {};
void mu__subrange_111::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_111::Canonicalize(PermSet& Perm) {};
void mu__subrange_111::SimpleLimit(PermSet& Perm) {};
void mu__subrange_111::ArrayLimit(PermSet& Perm) {};
void mu__subrange_111::Limit(PermSet& Perm) {};
void mu__subrange_111::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_112::Permute(PermSet& Perm, int i) {};
void mu__subrange_112::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_112::Canonicalize(PermSet& Perm) {};
void mu__subrange_112::SimpleLimit(PermSet& Perm) {};
void mu__subrange_112::ArrayLimit(PermSet& Perm) {};
void mu__subrange_112::Limit(PermSet& Perm) {};
void mu__subrange_112::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_113::Permute(PermSet& Perm, int i) {};
void mu__subrange_113::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_113::Canonicalize(PermSet& Perm) {};
void mu__subrange_113::SimpleLimit(PermSet& Perm) {};
void mu__subrange_113::ArrayLimit(PermSet& Perm) {};
void mu__subrange_113::Limit(PermSet& Perm) {};
void mu__subrange_113::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_114::Permute(PermSet& Perm, int i) {};
void mu__subrange_114::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_114::Canonicalize(PermSet& Perm) {};
void mu__subrange_114::SimpleLimit(PermSet& Perm) {};
void mu__subrange_114::ArrayLimit(PermSet& Perm) {};
void mu__subrange_114::Limit(PermSet& Perm) {};
void mu__subrange_114::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_115::Permute(PermSet& Perm, int i) {};
void mu__subrange_115::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_115::Canonicalize(PermSet& Perm) {};
void mu__subrange_115::SimpleLimit(PermSet& Perm) {};
void mu__subrange_115::ArrayLimit(PermSet& Perm) {};
void mu__subrange_115::Limit(PermSet& Perm) {};
void mu__subrange_115::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_116::Permute(PermSet& Perm, int i) {};
void mu__subrange_116::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_116::Canonicalize(PermSet& Perm) {};
void mu__subrange_116::SimpleLimit(PermSet& Perm) {};
void mu__subrange_116::ArrayLimit(PermSet& Perm) {};
void mu__subrange_116::Limit(PermSet& Perm) {};
void mu__subrange_116::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_117::Permute(PermSet& Perm, int i) {};
void mu__subrange_117::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_117::Canonicalize(PermSet& Perm) {};
void mu__subrange_117::SimpleLimit(PermSet& Perm) {};
void mu__subrange_117::ArrayLimit(PermSet& Perm) {};
void mu__subrange_117::Limit(PermSet& Perm) {};
void mu__subrange_117::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_118::Permute(PermSet& Perm, int i) {};
void mu__subrange_118::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_118::Canonicalize(PermSet& Perm) {};
void mu__subrange_118::SimpleLimit(PermSet& Perm) {};
void mu__subrange_118::ArrayLimit(PermSet& Perm) {};
void mu__subrange_118::Limit(PermSet& Perm) {};
void mu__subrange_118::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_119::Permute(PermSet& Perm, int i) {};
void mu__subrange_119::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_119::Canonicalize(PermSet& Perm) {};
void mu__subrange_119::SimpleLimit(PermSet& Perm) {};
void mu__subrange_119::ArrayLimit(PermSet& Perm) {};
void mu__subrange_119::Limit(PermSet& Perm) {};
void mu__subrange_119::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_120::Permute(PermSet& Perm, int i) {};
void mu__subrange_120::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_120::Canonicalize(PermSet& Perm) {};
void mu__subrange_120::SimpleLimit(PermSet& Perm) {};
void mu__subrange_120::ArrayLimit(PermSet& Perm) {};
void mu__subrange_120::Limit(PermSet& Perm) {};
void mu__subrange_120::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_121::Permute(PermSet& Perm, int i) {};
void mu__subrange_121::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_121::Canonicalize(PermSet& Perm) {};
void mu__subrange_121::SimpleLimit(PermSet& Perm) {};
void mu__subrange_121::ArrayLimit(PermSet& Perm) {};
void mu__subrange_121::Limit(PermSet& Perm) {};
void mu__subrange_121::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_122::Permute(PermSet& Perm, int i) {};
void mu__subrange_122::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_122::Canonicalize(PermSet& Perm) {};
void mu__subrange_122::SimpleLimit(PermSet& Perm) {};
void mu__subrange_122::ArrayLimit(PermSet& Perm) {};
void mu__subrange_122::Limit(PermSet& Perm) {};
void mu__subrange_122::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_123::Permute(PermSet& Perm, int i) {};
void mu__subrange_123::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_123::Canonicalize(PermSet& Perm) {};
void mu__subrange_123::SimpleLimit(PermSet& Perm) {};
void mu__subrange_123::ArrayLimit(PermSet& Perm) {};
void mu__subrange_123::Limit(PermSet& Perm) {};
void mu__subrange_123::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_124::Permute(PermSet& Perm, int i) {};
void mu__subrange_124::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_124::Canonicalize(PermSet& Perm) {};
void mu__subrange_124::SimpleLimit(PermSet& Perm) {};
void mu__subrange_124::ArrayLimit(PermSet& Perm) {};
void mu__subrange_124::Limit(PermSet& Perm) {};
void mu__subrange_124::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_125::Permute(PermSet& Perm, int i) {};
void mu__subrange_125::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_125::Canonicalize(PermSet& Perm) {};
void mu__subrange_125::SimpleLimit(PermSet& Perm) {};
void mu__subrange_125::ArrayLimit(PermSet& Perm) {};
void mu__subrange_125::Limit(PermSet& Perm) {};
void mu__subrange_125::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_126::Permute(PermSet& Perm, int i) {};
void mu__subrange_126::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_126::Canonicalize(PermSet& Perm) {};
void mu__subrange_126::SimpleLimit(PermSet& Perm) {};
void mu__subrange_126::ArrayLimit(PermSet& Perm) {};
void mu__subrange_126::Limit(PermSet& Perm) {};
void mu__subrange_126::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_127::Permute(PermSet& Perm, int i) {};
void mu__subrange_127::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_127::Canonicalize(PermSet& Perm) {};
void mu__subrange_127::SimpleLimit(PermSet& Perm) {};
void mu__subrange_127::ArrayLimit(PermSet& Perm) {};
void mu__subrange_127::Limit(PermSet& Perm) {};
void mu__subrange_127::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_128::Permute(PermSet& Perm, int i) {};
void mu__subrange_128::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_128::Canonicalize(PermSet& Perm) {};
void mu__subrange_128::SimpleLimit(PermSet& Perm) {};
void mu__subrange_128::ArrayLimit(PermSet& Perm) {};
void mu__subrange_128::Limit(PermSet& Perm) {};
void mu__subrange_128::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_129::Permute(PermSet& Perm, int i) {};
void mu__subrange_129::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_129::Canonicalize(PermSet& Perm) {};
void mu__subrange_129::SimpleLimit(PermSet& Perm) {};
void mu__subrange_129::ArrayLimit(PermSet& Perm) {};
void mu__subrange_129::Limit(PermSet& Perm) {};
void mu__subrange_129::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_130::Permute(PermSet& Perm, int i) {};
void mu__subrange_130::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_130::Canonicalize(PermSet& Perm) {};
void mu__subrange_130::SimpleLimit(PermSet& Perm) {};
void mu__subrange_130::ArrayLimit(PermSet& Perm) {};
void mu__subrange_130::Limit(PermSet& Perm) {};
void mu__subrange_130::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_131::Permute(PermSet& Perm, int i) {};
void mu__subrange_131::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_131::Canonicalize(PermSet& Perm) {};
void mu__subrange_131::SimpleLimit(PermSet& Perm) {};
void mu__subrange_131::ArrayLimit(PermSet& Perm) {};
void mu__subrange_131::Limit(PermSet& Perm) {};
void mu__subrange_131::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_132::Permute(PermSet& Perm, int i) {};
void mu__subrange_132::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_132::Canonicalize(PermSet& Perm) {};
void mu__subrange_132::SimpleLimit(PermSet& Perm) {};
void mu__subrange_132::ArrayLimit(PermSet& Perm) {};
void mu__subrange_132::Limit(PermSet& Perm) {};
void mu__subrange_132::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_133::Permute(PermSet& Perm, int i) {};
void mu__subrange_133::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_133::Canonicalize(PermSet& Perm) {};
void mu__subrange_133::SimpleLimit(PermSet& Perm) {};
void mu__subrange_133::ArrayLimit(PermSet& Perm) {};
void mu__subrange_133::Limit(PermSet& Perm) {};
void mu__subrange_133::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_134::Permute(PermSet& Perm, int i) {};
void mu__subrange_134::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_134::Canonicalize(PermSet& Perm) {};
void mu__subrange_134::SimpleLimit(PermSet& Perm) {};
void mu__subrange_134::ArrayLimit(PermSet& Perm) {};
void mu__subrange_134::Limit(PermSet& Perm) {};
void mu__subrange_134::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_135::Permute(PermSet& Perm, int i) {};
void mu__subrange_135::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_135::Canonicalize(PermSet& Perm) {};
void mu__subrange_135::SimpleLimit(PermSet& Perm) {};
void mu__subrange_135::ArrayLimit(PermSet& Perm) {};
void mu__subrange_135::Limit(PermSet& Perm) {};
void mu__subrange_135::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_136::Permute(PermSet& Perm, int i) {};
void mu__subrange_136::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_136::Canonicalize(PermSet& Perm) {};
void mu__subrange_136::SimpleLimit(PermSet& Perm) {};
void mu__subrange_136::ArrayLimit(PermSet& Perm) {};
void mu__subrange_136::Limit(PermSet& Perm) {};
void mu__subrange_136::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_137::Permute(PermSet& Perm, int i) {};
void mu__subrange_137::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_137::Canonicalize(PermSet& Perm) {};
void mu__subrange_137::SimpleLimit(PermSet& Perm) {};
void mu__subrange_137::ArrayLimit(PermSet& Perm) {};
void mu__subrange_137::Limit(PermSet& Perm) {};
void mu__subrange_137::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_138::Permute(PermSet& Perm, int i) {};
void mu__subrange_138::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_138::Canonicalize(PermSet& Perm) {};
void mu__subrange_138::SimpleLimit(PermSet& Perm) {};
void mu__subrange_138::ArrayLimit(PermSet& Perm) {};
void mu__subrange_138::Limit(PermSet& Perm) {};
void mu__subrange_138::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_139::Permute(PermSet& Perm, int i) {};
void mu__subrange_139::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_139::Canonicalize(PermSet& Perm) {};
void mu__subrange_139::SimpleLimit(PermSet& Perm) {};
void mu__subrange_139::ArrayLimit(PermSet& Perm) {};
void mu__subrange_139::Limit(PermSet& Perm) {};
void mu__subrange_139::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_140::Permute(PermSet& Perm, int i) {};
void mu__subrange_140::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_140::Canonicalize(PermSet& Perm) {};
void mu__subrange_140::SimpleLimit(PermSet& Perm) {};
void mu__subrange_140::ArrayLimit(PermSet& Perm) {};
void mu__subrange_140::Limit(PermSet& Perm) {};
void mu__subrange_140::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_141::Permute(PermSet& Perm, int i) {};
void mu__subrange_141::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_141::Canonicalize(PermSet& Perm) {};
void mu__subrange_141::SimpleLimit(PermSet& Perm) {};
void mu__subrange_141::ArrayLimit(PermSet& Perm) {};
void mu__subrange_141::Limit(PermSet& Perm) {};
void mu__subrange_141::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_142::Permute(PermSet& Perm, int i) {};
void mu__subrange_142::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_142::Canonicalize(PermSet& Perm) {};
void mu__subrange_142::SimpleLimit(PermSet& Perm) {};
void mu__subrange_142::ArrayLimit(PermSet& Perm) {};
void mu__subrange_142::Limit(PermSet& Perm) {};
void mu__subrange_142::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_143::Permute(PermSet& Perm, int i) {};
void mu__subrange_143::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_143::Canonicalize(PermSet& Perm) {};
void mu__subrange_143::SimpleLimit(PermSet& Perm) {};
void mu__subrange_143::ArrayLimit(PermSet& Perm) {};
void mu__subrange_143::Limit(PermSet& Perm) {};
void mu__subrange_143::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_144::Permute(PermSet& Perm, int i) {};
void mu__subrange_144::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_144::Canonicalize(PermSet& Perm) {};
void mu__subrange_144::SimpleLimit(PermSet& Perm) {};
void mu__subrange_144::ArrayLimit(PermSet& Perm) {};
void mu__subrange_144::Limit(PermSet& Perm) {};
void mu__subrange_144::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_145::Permute(PermSet& Perm, int i) {};
void mu__subrange_145::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_145::Canonicalize(PermSet& Perm) {};
void mu__subrange_145::SimpleLimit(PermSet& Perm) {};
void mu__subrange_145::ArrayLimit(PermSet& Perm) {};
void mu__subrange_145::Limit(PermSet& Perm) {};
void mu__subrange_145::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_146::Permute(PermSet& Perm, int i) {};
void mu__subrange_146::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_146::Canonicalize(PermSet& Perm) {};
void mu__subrange_146::SimpleLimit(PermSet& Perm) {};
void mu__subrange_146::ArrayLimit(PermSet& Perm) {};
void mu__subrange_146::Limit(PermSet& Perm) {};
void mu__subrange_146::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_147::Permute(PermSet& Perm, int i) {};
void mu__subrange_147::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_147::Canonicalize(PermSet& Perm) {};
void mu__subrange_147::SimpleLimit(PermSet& Perm) {};
void mu__subrange_147::ArrayLimit(PermSet& Perm) {};
void mu__subrange_147::Limit(PermSet& Perm) {};
void mu__subrange_147::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_148::Permute(PermSet& Perm, int i) {};
void mu__subrange_148::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_148::Canonicalize(PermSet& Perm) {};
void mu__subrange_148::SimpleLimit(PermSet& Perm) {};
void mu__subrange_148::ArrayLimit(PermSet& Perm) {};
void mu__subrange_148::Limit(PermSet& Perm) {};
void mu__subrange_148::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_149::Permute(PermSet& Perm, int i) {};
void mu__subrange_149::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_149::Canonicalize(PermSet& Perm) {};
void mu__subrange_149::SimpleLimit(PermSet& Perm) {};
void mu__subrange_149::ArrayLimit(PermSet& Perm) {};
void mu__subrange_149::Limit(PermSet& Perm) {};
void mu__subrange_149::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_150::Permute(PermSet& Perm, int i) {};
void mu__subrange_150::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_150::Canonicalize(PermSet& Perm) {};
void mu__subrange_150::SimpleLimit(PermSet& Perm) {};
void mu__subrange_150::ArrayLimit(PermSet& Perm) {};
void mu__subrange_150::Limit(PermSet& Perm) {};
void mu__subrange_150::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_151::Permute(PermSet& Perm, int i) {};
void mu__subrange_151::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_151::Canonicalize(PermSet& Perm) {};
void mu__subrange_151::SimpleLimit(PermSet& Perm) {};
void mu__subrange_151::ArrayLimit(PermSet& Perm) {};
void mu__subrange_151::Limit(PermSet& Perm) {};
void mu__subrange_151::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_152::Permute(PermSet& Perm, int i) {};
void mu__subrange_152::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_152::Canonicalize(PermSet& Perm) {};
void mu__subrange_152::SimpleLimit(PermSet& Perm) {};
void mu__subrange_152::ArrayLimit(PermSet& Perm) {};
void mu__subrange_152::Limit(PermSet& Perm) {};
void mu__subrange_152::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_153::Permute(PermSet& Perm, int i) {};
void mu__subrange_153::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_153::Canonicalize(PermSet& Perm) {};
void mu__subrange_153::SimpleLimit(PermSet& Perm) {};
void mu__subrange_153::ArrayLimit(PermSet& Perm) {};
void mu__subrange_153::Limit(PermSet& Perm) {};
void mu__subrange_153::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_154::Permute(PermSet& Perm, int i) {};
void mu__subrange_154::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_154::Canonicalize(PermSet& Perm) {};
void mu__subrange_154::SimpleLimit(PermSet& Perm) {};
void mu__subrange_154::ArrayLimit(PermSet& Perm) {};
void mu__subrange_154::Limit(PermSet& Perm) {};
void mu__subrange_154::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_155::Permute(PermSet& Perm, int i) {};
void mu__subrange_155::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_155::Canonicalize(PermSet& Perm) {};
void mu__subrange_155::SimpleLimit(PermSet& Perm) {};
void mu__subrange_155::ArrayLimit(PermSet& Perm) {};
void mu__subrange_155::Limit(PermSet& Perm) {};
void mu__subrange_155::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_156::Permute(PermSet& Perm, int i) {};
void mu__subrange_156::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_156::Canonicalize(PermSet& Perm) {};
void mu__subrange_156::SimpleLimit(PermSet& Perm) {};
void mu__subrange_156::ArrayLimit(PermSet& Perm) {};
void mu__subrange_156::Limit(PermSet& Perm) {};
void mu__subrange_156::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_157::Permute(PermSet& Perm, int i) {};
void mu__subrange_157::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_157::Canonicalize(PermSet& Perm) {};
void mu__subrange_157::SimpleLimit(PermSet& Perm) {};
void mu__subrange_157::ArrayLimit(PermSet& Perm) {};
void mu__subrange_157::Limit(PermSet& Perm) {};
void mu__subrange_157::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_158::Permute(PermSet& Perm, int i) {};
void mu__subrange_158::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_158::Canonicalize(PermSet& Perm) {};
void mu__subrange_158::SimpleLimit(PermSet& Perm) {};
void mu__subrange_158::ArrayLimit(PermSet& Perm) {};
void mu__subrange_158::Limit(PermSet& Perm) {};
void mu__subrange_158::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_159::Permute(PermSet& Perm, int i) {};
void mu__subrange_159::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_159::Canonicalize(PermSet& Perm) {};
void mu__subrange_159::SimpleLimit(PermSet& Perm) {};
void mu__subrange_159::ArrayLimit(PermSet& Perm) {};
void mu__subrange_159::Limit(PermSet& Perm) {};
void mu__subrange_159::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_160::Permute(PermSet& Perm, int i) {};
void mu__subrange_160::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_160::Canonicalize(PermSet& Perm) {};
void mu__subrange_160::SimpleLimit(PermSet& Perm) {};
void mu__subrange_160::ArrayLimit(PermSet& Perm) {};
void mu__subrange_160::Limit(PermSet& Perm) {};
void mu__subrange_160::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_161::Permute(PermSet& Perm, int i) {};
void mu__subrange_161::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_161::Canonicalize(PermSet& Perm) {};
void mu__subrange_161::SimpleLimit(PermSet& Perm) {};
void mu__subrange_161::ArrayLimit(PermSet& Perm) {};
void mu__subrange_161::Limit(PermSet& Perm) {};
void mu__subrange_161::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_162::Permute(PermSet& Perm, int i) {};
void mu__subrange_162::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_162::Canonicalize(PermSet& Perm) {};
void mu__subrange_162::SimpleLimit(PermSet& Perm) {};
void mu__subrange_162::ArrayLimit(PermSet& Perm) {};
void mu__subrange_162::Limit(PermSet& Perm) {};
void mu__subrange_162::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_163::Permute(PermSet& Perm, int i) {};
void mu__subrange_163::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_163::Canonicalize(PermSet& Perm) {};
void mu__subrange_163::SimpleLimit(PermSet& Perm) {};
void mu__subrange_163::ArrayLimit(PermSet& Perm) {};
void mu__subrange_163::Limit(PermSet& Perm) {};
void mu__subrange_163::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_164::Permute(PermSet& Perm, int i) {};
void mu__subrange_164::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_164::Canonicalize(PermSet& Perm) {};
void mu__subrange_164::SimpleLimit(PermSet& Perm) {};
void mu__subrange_164::ArrayLimit(PermSet& Perm) {};
void mu__subrange_164::Limit(PermSet& Perm) {};
void mu__subrange_164::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_165::Permute(PermSet& Perm, int i) {};
void mu__subrange_165::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_165::Canonicalize(PermSet& Perm) {};
void mu__subrange_165::SimpleLimit(PermSet& Perm) {};
void mu__subrange_165::ArrayLimit(PermSet& Perm) {};
void mu__subrange_165::Limit(PermSet& Perm) {};
void mu__subrange_165::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_166::Permute(PermSet& Perm, int i) {};
void mu__subrange_166::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_166::Canonicalize(PermSet& Perm) {};
void mu__subrange_166::SimpleLimit(PermSet& Perm) {};
void mu__subrange_166::ArrayLimit(PermSet& Perm) {};
void mu__subrange_166::Limit(PermSet& Perm) {};
void mu__subrange_166::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_167::Permute(PermSet& Perm, int i) {};
void mu__subrange_167::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_167::Canonicalize(PermSet& Perm) {};
void mu__subrange_167::SimpleLimit(PermSet& Perm) {};
void mu__subrange_167::ArrayLimit(PermSet& Perm) {};
void mu__subrange_167::Limit(PermSet& Perm) {};
void mu__subrange_167::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_168::Permute(PermSet& Perm, int i) {};
void mu__subrange_168::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_168::Canonicalize(PermSet& Perm) {};
void mu__subrange_168::SimpleLimit(PermSet& Perm) {};
void mu__subrange_168::ArrayLimit(PermSet& Perm) {};
void mu__subrange_168::Limit(PermSet& Perm) {};
void mu__subrange_168::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_169::Permute(PermSet& Perm, int i) {};
void mu__subrange_169::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_169::Canonicalize(PermSet& Perm) {};
void mu__subrange_169::SimpleLimit(PermSet& Perm) {};
void mu__subrange_169::ArrayLimit(PermSet& Perm) {};
void mu__subrange_169::Limit(PermSet& Perm) {};
void mu__subrange_169::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_170::Permute(PermSet& Perm, int i) {};
void mu__subrange_170::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_170::Canonicalize(PermSet& Perm) {};
void mu__subrange_170::SimpleLimit(PermSet& Perm) {};
void mu__subrange_170::ArrayLimit(PermSet& Perm) {};
void mu__subrange_170::Limit(PermSet& Perm) {};
void mu__subrange_170::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_171::Permute(PermSet& Perm, int i) {};
void mu__subrange_171::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_171::Canonicalize(PermSet& Perm) {};
void mu__subrange_171::SimpleLimit(PermSet& Perm) {};
void mu__subrange_171::ArrayLimit(PermSet& Perm) {};
void mu__subrange_171::Limit(PermSet& Perm) {};
void mu__subrange_171::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_172::Permute(PermSet& Perm, int i) {};
void mu__subrange_172::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_172::Canonicalize(PermSet& Perm) {};
void mu__subrange_172::SimpleLimit(PermSet& Perm) {};
void mu__subrange_172::ArrayLimit(PermSet& Perm) {};
void mu__subrange_172::Limit(PermSet& Perm) {};
void mu__subrange_172::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_173::Permute(PermSet& Perm, int i) {};
void mu__subrange_173::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_173::Canonicalize(PermSet& Perm) {};
void mu__subrange_173::SimpleLimit(PermSet& Perm) {};
void mu__subrange_173::ArrayLimit(PermSet& Perm) {};
void mu__subrange_173::Limit(PermSet& Perm) {};
void mu__subrange_173::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_174::Permute(PermSet& Perm, int i) {};
void mu__subrange_174::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_174::Canonicalize(PermSet& Perm) {};
void mu__subrange_174::SimpleLimit(PermSet& Perm) {};
void mu__subrange_174::ArrayLimit(PermSet& Perm) {};
void mu__subrange_174::Limit(PermSet& Perm) {};
void mu__subrange_174::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_175::Permute(PermSet& Perm, int i) {};
void mu__subrange_175::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_175::Canonicalize(PermSet& Perm) {};
void mu__subrange_175::SimpleLimit(PermSet& Perm) {};
void mu__subrange_175::ArrayLimit(PermSet& Perm) {};
void mu__subrange_175::Limit(PermSet& Perm) {};
void mu__subrange_175::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_176::Permute(PermSet& Perm, int i) {};
void mu__subrange_176::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_176::Canonicalize(PermSet& Perm) {};
void mu__subrange_176::SimpleLimit(PermSet& Perm) {};
void mu__subrange_176::ArrayLimit(PermSet& Perm) {};
void mu__subrange_176::Limit(PermSet& Perm) {};
void mu__subrange_176::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_177::Permute(PermSet& Perm, int i) {};
void mu__subrange_177::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_177::Canonicalize(PermSet& Perm) {};
void mu__subrange_177::SimpleLimit(PermSet& Perm) {};
void mu__subrange_177::ArrayLimit(PermSet& Perm) {};
void mu__subrange_177::Limit(PermSet& Perm) {};
void mu__subrange_177::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_178::Permute(PermSet& Perm, int i) {};
void mu__subrange_178::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_178::Canonicalize(PermSet& Perm) {};
void mu__subrange_178::SimpleLimit(PermSet& Perm) {};
void mu__subrange_178::ArrayLimit(PermSet& Perm) {};
void mu__subrange_178::Limit(PermSet& Perm) {};
void mu__subrange_178::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_179::Permute(PermSet& Perm, int i) {};
void mu__subrange_179::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_179::Canonicalize(PermSet& Perm) {};
void mu__subrange_179::SimpleLimit(PermSet& Perm) {};
void mu__subrange_179::ArrayLimit(PermSet& Perm) {};
void mu__subrange_179::Limit(PermSet& Perm) {};
void mu__subrange_179::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_180::Permute(PermSet& Perm, int i) {};
void mu__subrange_180::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_180::Canonicalize(PermSet& Perm) {};
void mu__subrange_180::SimpleLimit(PermSet& Perm) {};
void mu__subrange_180::ArrayLimit(PermSet& Perm) {};
void mu__subrange_180::Limit(PermSet& Perm) {};
void mu__subrange_180::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_181::Permute(PermSet& Perm, int i) {};
void mu__subrange_181::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_181::Canonicalize(PermSet& Perm) {};
void mu__subrange_181::SimpleLimit(PermSet& Perm) {};
void mu__subrange_181::ArrayLimit(PermSet& Perm) {};
void mu__subrange_181::Limit(PermSet& Perm) {};
void mu__subrange_181::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_182::Permute(PermSet& Perm, int i) {};
void mu__subrange_182::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_182::Canonicalize(PermSet& Perm) {};
void mu__subrange_182::SimpleLimit(PermSet& Perm) {};
void mu__subrange_182::ArrayLimit(PermSet& Perm) {};
void mu__subrange_182::Limit(PermSet& Perm) {};
void mu__subrange_182::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_183::Permute(PermSet& Perm, int i) {};
void mu__subrange_183::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_183::Canonicalize(PermSet& Perm) {};
void mu__subrange_183::SimpleLimit(PermSet& Perm) {};
void mu__subrange_183::ArrayLimit(PermSet& Perm) {};
void mu__subrange_183::Limit(PermSet& Perm) {};
void mu__subrange_183::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_184::Permute(PermSet& Perm, int i) {};
void mu__subrange_184::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_184::Canonicalize(PermSet& Perm) {};
void mu__subrange_184::SimpleLimit(PermSet& Perm) {};
void mu__subrange_184::ArrayLimit(PermSet& Perm) {};
void mu__subrange_184::Limit(PermSet& Perm) {};
void mu__subrange_184::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_185::Permute(PermSet& Perm, int i) {};
void mu__subrange_185::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_185::Canonicalize(PermSet& Perm) {};
void mu__subrange_185::SimpleLimit(PermSet& Perm) {};
void mu__subrange_185::ArrayLimit(PermSet& Perm) {};
void mu__subrange_185::Limit(PermSet& Perm) {};
void mu__subrange_185::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_186::Permute(PermSet& Perm, int i) {};
void mu__subrange_186::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_186::Canonicalize(PermSet& Perm) {};
void mu__subrange_186::SimpleLimit(PermSet& Perm) {};
void mu__subrange_186::ArrayLimit(PermSet& Perm) {};
void mu__subrange_186::Limit(PermSet& Perm) {};
void mu__subrange_186::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_187::Permute(PermSet& Perm, int i) {};
void mu__subrange_187::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_187::Canonicalize(PermSet& Perm) {};
void mu__subrange_187::SimpleLimit(PermSet& Perm) {};
void mu__subrange_187::ArrayLimit(PermSet& Perm) {};
void mu__subrange_187::Limit(PermSet& Perm) {};
void mu__subrange_187::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_188::Permute(PermSet& Perm, int i) {};
void mu__subrange_188::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_188::Canonicalize(PermSet& Perm) {};
void mu__subrange_188::SimpleLimit(PermSet& Perm) {};
void mu__subrange_188::ArrayLimit(PermSet& Perm) {};
void mu__subrange_188::Limit(PermSet& Perm) {};
void mu__subrange_188::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_189::Permute(PermSet& Perm, int i) {};
void mu__subrange_189::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_189::Canonicalize(PermSet& Perm) {};
void mu__subrange_189::SimpleLimit(PermSet& Perm) {};
void mu__subrange_189::ArrayLimit(PermSet& Perm) {};
void mu__subrange_189::Limit(PermSet& Perm) {};
void mu__subrange_189::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_190::Permute(PermSet& Perm, int i) {};
void mu__subrange_190::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_190::Canonicalize(PermSet& Perm) {};
void mu__subrange_190::SimpleLimit(PermSet& Perm) {};
void mu__subrange_190::ArrayLimit(PermSet& Perm) {};
void mu__subrange_190::Limit(PermSet& Perm) {};
void mu__subrange_190::MultisetLimit(PermSet& Perm)
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
              
              mu_TailPointers.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
              mu_IncomingQueue.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_RouterStatus.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_RouterStatus.MultisetSort();
              mu_ExitPath.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ExitPath.MultisetSort();
              mu_EntryPath.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_EntryPath.MultisetSort();
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

          mu_TailPointers.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_TailPointers.MultisetSort();
          mu_IncomingQueue.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_IncomingQueue.MultisetSort();
          mu_RouterStatus.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_RouterStatus.MultisetSort();
          mu_ExitPath.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ExitPath.MultisetSort();
          mu_EntryPath.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_EntryPath.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_TailPointers.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
              mu_IncomingQueue.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_RouterStatus.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_RouterStatus.MultisetSort();
              mu_ExitPath.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ExitPath.MultisetSort();
              mu_EntryPath.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_EntryPath.MultisetSort();
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
      mu_TailPointers.MultisetSort();
      mu_IncomingQueue.MultisetSort();
      mu_RouterStatus.MultisetSort();
      mu_ExitPath.MultisetSort();
      mu_EntryPath.MultisetSort();
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
        mu_TailPointers.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_TailPointers.MultisetSort();
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
        mu_RouterStatus.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_RouterStatus.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ExitPath.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ExitPath.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_EntryPath.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_EntryPath.MultisetSort();
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
