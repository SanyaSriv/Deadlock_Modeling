/******************************
  Program "skeleton.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "skeleton"
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
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Consume Response, n1:%s", mu_n1.Name());
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
    unsigned r = what_rule - 0;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 3 )
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
    r = what_rule - 0;
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
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Consume Fwd Response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr12;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr12;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3;
    static mu__subrange_27 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr13;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr13) {
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
    r = what_rule - 3;
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
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Consume Request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr14;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr14;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 9 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr15;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr15) {
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
    r = what_rule - 6;
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
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Consume Fwd Request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr16;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr16;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 9;
    static mu__subrange_25 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr17;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
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
    r = what_rule - 9;
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
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    return tsprintf("Send Request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
bool mu__boolexpr18;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
    return mu__boolexpr18;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu__subrange_24 mu_n2;
    mu_n2.value((r % 3) + 0);
    r = r / 3;
    static mu__subrange_23 mu_n1;
    mu_n1.value((r % 3) + 0);
    r = r / 3;
    while (what_rule < 21 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr19;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (2)) ; 
}
	      if (mu__boolexpr19) {
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
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<3)
    { R0.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<6)
    { R1.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<9)
    { R2.NextRule(what_rule);
      if (what_rule<9) return; }
  if (what_rule>=9 && what_rule<12)
    { R3.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<21)
    { R4.NextRule(what_rule);
      if (what_rule<21) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=2) return R0.Condition(r-0);
  if (r>=3 && r<=5) return R1.Condition(r-3);
  if (r>=6 && r<=8) return R2.Condition(r-6);
  if (r>=9 && r<=11) return R3.Condition(r-9);
  if (r>=12 && r<=20) return R4.Condition(r-12);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=2) { R0.Code(r-0); return; } 
  if (r>=3 && r<=5) { R1.Code(r-3); return; } 
  if (r>=6 && r<=8) { R2.Code(r-6); return; } 
  if (r>=9 && r<=11) { R3.Code(r-9); return; } 
  if (r>=12 && r<=20) { R4.Code(r-12); return; } 
}
int Priority(unsigned short r)
{
  if (r<=2) { return R0.Priority(); } 
  if (r>=3 && r<=5) { return R1.Priority(); } 
  if (r>=6 && r<=8) { return R2.Priority(); } 
  if (r>=9 && r<=11) { return R3.Priority(); } 
  if (r>=12 && r<=20) { return R4.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=2) return R0.Name(r-0);
  if (r>=3 && r<=5) return R1.Name(r-3);
  if (r>=6 && r<=8) return R2.Name(r-6);
  if (r>=9 && r<=11) return R3.Name(r-9);
  if (r>=12 && r<=20) return R4.Name(r-12);
  return NULL;
}
};
const unsigned numrules = 21;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 21


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
