/******************************
  Program "QueueClearFirst_router_fullyconnected.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "QueueClearFirst_router_fullyconnected"
#define BITS_IN_WORLD 522
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
  mu_1_NodeIDs (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_NodeIDs (void): mu__byte(0, 3, 3) {};
  mu_1_NodeIDs (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  if (name) mu_src_nid.set_self_2(name, ".src_nid", os + 6 ); else mu_src_nid.set_self_2(NULL, NULL, 0);
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
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 9 + os);
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
  mu_1_Queue array[ 4 ];
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 27 + os);
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
  mu_1__type_0 array[ 4 ];
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
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 108 + os);
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
  mu_1__type_2 array[ 4 ];
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
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
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
  for(int i = 0; i < 4; i++) {
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
  mu_1__type_3 array[ 4 ];
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
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 12 + os);
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
  mu__subrange_13 (const char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_13 (void): mu__byte(0, 4, 3) {};
  mu__subrange_13 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
  mu_1__type_5 array[ 5 ];
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
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
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
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_7& val) { return mu__byte::operator=((int) val); };
  mu_1__type_7 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_7 (void): mu__byte(0, 1, 2) {};
  mu_1__type_7 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
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
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8
{
 public:
  mu_1__type_7 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_8 (const char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1__type_7& operator[] (int index) /* const */
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
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
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
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 2 + os);
    delete[] s;
  }
};
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9
{
 public:
  mu_1_NodeIDs array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_9 (const char *n, int os) { set_self(n, os); };
  mu_1__type_9 ( void ) {};
  virtual ~mu_1__type_9 ();
  mu_1_NodeIDs& operator[] (int index) /* const */
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
  mu_1__type_9& operator= (const mu_1__type_9& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_9& a, mu_1__type_9& b)
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

  void mu_1__type_9::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_9::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_9::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_9::~mu_1__type_9()
{
}
/*** end array declaration ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10
{
 public:
  mu_1_NodeIDs array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_10 (const char *n, int os) { set_self(n, os); };
  mu_1__type_10 ( void ) {};
  virtual ~mu_1__type_10 ();
  mu_1_NodeIDs& operator[] (int index) /* const */
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
  mu_1__type_10& operator= (const mu_1__type_10& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_10& a, mu_1__type_10& b)
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

  void mu_1__type_10::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_10::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_10::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_10::~mu_1__type_10()
{
}
/*** end array declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu__subrange_20: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_20& val) { return mu__byte::operator=((int) val); };
  mu__subrange_20 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_20 (void): mu__byte(1, 2, 2) {};
  mu__subrange_20 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
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
  mu__subrange_21 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_21 (void): mu__byte(0, 3, 3) {};
  mu__subrange_21 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_22 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_22 (void): mu__byte(0, 3, 3) {};
  mu__subrange_22 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_24 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_24 (void): mu__byte(0, 3, 3) {};
  mu__subrange_24 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_25 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_25 (void): mu__byte(0, 3, 3) {};
  mu__subrange_25 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_26 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_26 (void): mu__byte(0, 3, 3) {};
  mu__subrange_26 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_27 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_27 (void): mu__byte(0, 3, 3) {};
  mu__subrange_27 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_28 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_28 (void): mu__byte(0, 3, 3) {};
  mu__subrange_28 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_29 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_29 (void): mu__byte(0, 3, 3) {};
  mu__subrange_29 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_30 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_30 (void): mu__byte(0, 3, 3) {};
  mu__subrange_30 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_31 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_31 (void): mu__byte(0, 3, 3) {};
  mu__subrange_31 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_32 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_32 (void): mu__byte(0, 3, 3) {};
  mu__subrange_32 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_33 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_33 (void): mu__byte(0, 3, 3) {};
  mu__subrange_33 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_34 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_34 (void): mu__byte(0, 3, 3) {};
  mu__subrange_34 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_35 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_35 (void): mu__byte(0, 3, 3) {};
  mu__subrange_35 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_36 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_36 (void): mu__byte(0, 3, 3) {};
  mu__subrange_36 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_37 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_37 (void): mu__byte(0, 3, 3) {};
  mu__subrange_37 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_38 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 3, 3) {};
  mu__subrange_38 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_39 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_39 (void): mu__byte(0, 3, 3) {};
  mu__subrange_39 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_40 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_40 (void): mu__byte(0, 3, 3) {};
  mu__subrange_40 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_41 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_41 (void): mu__byte(0, 3, 3) {};
  mu__subrange_41 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_42 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_42 (void): mu__byte(0, 3, 3) {};
  mu__subrange_42 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_43 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_43 (void): mu__byte(0, 3, 3) {};
  mu__subrange_43 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_44 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_44 (void): mu__byte(0, 3, 3) {};
  mu__subrange_44 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_45 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_45 (void): mu__byte(0, 3, 3) {};
  mu__subrange_45 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_46 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_46 (void): mu__byte(0, 3, 3) {};
  mu__subrange_46 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_47 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_47 (void): mu__byte(0, 3, 3) {};
  mu__subrange_47 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_48 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_48 (void): mu__byte(0, 3, 3) {};
  mu__subrange_48 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_49 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_49 (void): mu__byte(0, 3, 3) {};
  mu__subrange_49 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_50 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_50 (void): mu__byte(0, 3, 3) {};
  mu__subrange_50 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_51 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_51 (void): mu__byte(0, 3, 3) {};
  mu__subrange_51 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_52 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_52 (void): mu__byte(0, 3, 3) {};
  mu__subrange_52 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_53 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_53 (void): mu__byte(0, 3, 3) {};
  mu__subrange_53 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_54 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_54 (void): mu__byte(0, 3, 3) {};
  mu__subrange_54 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_55 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_55 (void): mu__byte(0, 3, 3) {};
  mu__subrange_55 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_56 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_56 (void): mu__byte(0, 3, 3) {};
  mu__subrange_56 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_57 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_57 (void): mu__byte(0, 3, 3) {};
  mu__subrange_57 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_58 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_58 (void): mu__byte(0, 3, 3) {};
  mu__subrange_58 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_59 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_59 (void): mu__byte(0, 3, 3) {};
  mu__subrange_59 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_60 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_60 (void): mu__byte(0, 3, 3) {};
  mu__subrange_60 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_61 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_61 (void): mu__byte(0, 3, 3) {};
  mu__subrange_61 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_62 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_62 (void): mu__byte(0, 3, 3) {};
  mu__subrange_62 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_63 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_63 (void): mu__byte(0, 3, 3) {};
  mu__subrange_63 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_64 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_64 (void): mu__byte(0, 3, 3) {};
  mu__subrange_64 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_65 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_65 (void): mu__byte(0, 3, 3) {};
  mu__subrange_65 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_66 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_66 (void): mu__byte(0, 3, 3) {};
  mu__subrange_66 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_67 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_67 (void): mu__byte(0, 3, 3) {};
  mu__subrange_67 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_68 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_68 (void): mu__byte(0, 3, 3) {};
  mu__subrange_68 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_69 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_69 (void): mu__byte(0, 3, 3) {};
  mu__subrange_69 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_70 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_70 (void): mu__byte(0, 3, 3) {};
  mu__subrange_70 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_71 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_71 (void): mu__byte(0, 3, 3) {};
  mu__subrange_71 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_72 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_72 (void): mu__byte(0, 3, 3) {};
  mu__subrange_72 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_73 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_73 (void): mu__byte(0, 3, 3) {};
  mu__subrange_73 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_74 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_74 (void): mu__byte(0, 3, 3) {};
  mu__subrange_74 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_75 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_75 (void): mu__byte(0, 3, 3) {};
  mu__subrange_75 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_76 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_76 (void): mu__byte(0, 3, 3) {};
  mu__subrange_76 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_77 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_77 (void): mu__byte(0, 3, 3) {};
  mu__subrange_77 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_78 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_78 (void): mu__byte(0, 3, 3) {};
  mu__subrange_78 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_79 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_79 (void): mu__byte(0, 3, 3) {};
  mu__subrange_79 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_80 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_80 (void): mu__byte(0, 3, 3) {};
  mu__subrange_80 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_81 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_81 (void): mu__byte(0, 3, 3) {};
  mu__subrange_81 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_82 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_82 (void): mu__byte(0, 3, 3) {};
  mu__subrange_82 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_83 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_83 (void): mu__byte(0, 3, 3) {};
  mu__subrange_83 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_84 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_84 (void): mu__byte(0, 3, 3) {};
  mu__subrange_84 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_85 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_85 (void): mu__byte(0, 3, 3) {};
  mu__subrange_85 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_86 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_86 (void): mu__byte(0, 3, 3) {};
  mu__subrange_86 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_87 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_87 (void): mu__byte(0, 3, 3) {};
  mu__subrange_87 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_88 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_88 (void): mu__byte(0, 3, 3) {};
  mu__subrange_88 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_89 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_89 (void): mu__byte(0, 3, 3) {};
  mu__subrange_89 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_90 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_90 (void): mu__byte(0, 3, 3) {};
  mu__subrange_90 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_91 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_91 (void): mu__byte(0, 3, 3) {};
  mu__subrange_91 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_92 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_92 (void): mu__byte(0, 3, 3) {};
  mu__subrange_92 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_93 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_93 (void): mu__byte(0, 3, 3) {};
  mu__subrange_93 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_94 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_94 (void): mu__byte(0, 3, 3) {};
  mu__subrange_94 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_95 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_95 (void): mu__byte(0, 3, 3) {};
  mu__subrange_95 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_96 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_96 (void): mu__byte(0, 3, 3) {};
  mu__subrange_96 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_97 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_97 (void): mu__byte(0, 3, 3) {};
  mu__subrange_97 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_98 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_98 (void): mu__byte(0, 3, 3) {};
  mu__subrange_98 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_99 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_99 (void): mu__byte(0, 3, 3) {};
  mu__subrange_99 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_100 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_100 (void): mu__byte(0, 3, 3) {};
  mu__subrange_100 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_101 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_101 (void): mu__byte(0, 3, 3) {};
  mu__subrange_101 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_102 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_102 (void): mu__byte(0, 3, 3) {};
  mu__subrange_102 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_103 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_103 (void): mu__byte(0, 3, 3) {};
  mu__subrange_103 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_104 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_104 (void): mu__byte(0, 3, 3) {};
  mu__subrange_104 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_105 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_105 (void): mu__byte(0, 3, 3) {};
  mu__subrange_105 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_106 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_106 (void): mu__byte(0, 3, 3) {};
  mu__subrange_106 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_107 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_107 (void): mu__byte(0, 3, 3) {};
  mu__subrange_107 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_108 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_108 (void): mu__byte(0, 3, 3) {};
  mu__subrange_108 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_109 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_109 (void): mu__byte(0, 3, 3) {};
  mu__subrange_109 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_110 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_110 (void): mu__byte(0, 3, 3) {};
  mu__subrange_110 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_111 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_111 (void): mu__byte(0, 3, 3) {};
  mu__subrange_111 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_112 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_112 (void): mu__byte(0, 3, 3) {};
  mu__subrange_112 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_113 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_113 (void): mu__byte(0, 3, 3) {};
  mu__subrange_113 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_114 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_114 (void): mu__byte(0, 3, 3) {};
  mu__subrange_114 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_115 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_115 (void): mu__byte(0, 3, 3) {};
  mu__subrange_115 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_116 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_116 (void): mu__byte(0, 3, 3) {};
  mu__subrange_116 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_117 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_117 (void): mu__byte(0, 3, 3) {};
  mu__subrange_117 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_118 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_118 (void): mu__byte(0, 3, 3) {};
  mu__subrange_118 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_119 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_119 (void): mu__byte(0, 3, 3) {};
  mu__subrange_119 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_120 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_120 (void): mu__byte(0, 3, 3) {};
  mu__subrange_120 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_121 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_121 (void): mu__byte(0, 3, 3) {};
  mu__subrange_121 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_122 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_122 (void): mu__byte(0, 3, 3) {};
  mu__subrange_122 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_123 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_123 (void): mu__byte(0, 3, 3) {};
  mu__subrange_123 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_124 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_124 (void): mu__byte(0, 3, 3) {};
  mu__subrange_124 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_125 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_125 (void): mu__byte(0, 3, 3) {};
  mu__subrange_125 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_126 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_126 (void): mu__byte(0, 3, 3) {};
  mu__subrange_126 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_127 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_127 (void): mu__byte(0, 3, 3) {};
  mu__subrange_127 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_128 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_128 (void): mu__byte(0, 3, 3) {};
  mu__subrange_128 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_129 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_129 (void): mu__byte(0, 3, 3) {};
  mu__subrange_129 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_130 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_130 (void): mu__byte(0, 3, 3) {};
  mu__subrange_130 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_131 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_131 (void): mu__byte(0, 3, 3) {};
  mu__subrange_131 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_132 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_132 (void): mu__byte(0, 3, 3) {};
  mu__subrange_132 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_133 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_133 (void): mu__byte(0, 3, 3) {};
  mu__subrange_133 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_134 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_134 (void): mu__byte(0, 3, 3) {};
  mu__subrange_134 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_135 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_135 (void): mu__byte(0, 3, 3) {};
  mu__subrange_135 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_136 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_136 (void): mu__byte(0, 3, 3) {};
  mu__subrange_136 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_137 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_137 (void): mu__byte(0, 3, 3) {};
  mu__subrange_137 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_138 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_138 (void): mu__byte(0, 3, 3) {};
  mu__subrange_138 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_139 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_139 (void): mu__byte(0, 3, 3) {};
  mu__subrange_139 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_140 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_140 (void): mu__byte(0, 3, 3) {};
  mu__subrange_140 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_141 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_141 (void): mu__byte(0, 3, 3) {};
  mu__subrange_141 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_142 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_142 (void): mu__byte(0, 3, 3) {};
  mu__subrange_142 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_143 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_143 (void): mu__byte(0, 3, 3) {};
  mu__subrange_143 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_144 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_144 (void): mu__byte(0, 3, 3) {};
  mu__subrange_144 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_145 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_145 (void): mu__byte(0, 3, 3) {};
  mu__subrange_145 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_146 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_146 (void): mu__byte(0, 3, 3) {};
  mu__subrange_146 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_147 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_147 (void): mu__byte(0, 3, 3) {};
  mu__subrange_147 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_148 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_148 (void): mu__byte(0, 3, 3) {};
  mu__subrange_148 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_149 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_149 (void): mu__byte(0, 3, 3) {};
  mu__subrange_149 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_150 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_150 (void): mu__byte(0, 3, 3) {};
  mu__subrange_150 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_151 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_151 (void): mu__byte(0, 3, 3) {};
  mu__subrange_151 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_152 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_152 (void): mu__byte(0, 3, 3) {};
  mu__subrange_152 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_153 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_153 (void): mu__byte(0, 3, 3) {};
  mu__subrange_153 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_154 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_154 (void): mu__byte(0, 3, 3) {};
  mu__subrange_154 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_155 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_155 (void): mu__byte(0, 3, 3) {};
  mu__subrange_155 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_156 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_156 (void): mu__byte(0, 3, 3) {};
  mu__subrange_156 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_157 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_157 (void): mu__byte(0, 3, 3) {};
  mu__subrange_157 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_158 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_158 (void): mu__byte(0, 3, 3) {};
  mu__subrange_158 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_159 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_159 (void): mu__byte(0, 3, 3) {};
  mu__subrange_159 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_160 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_160 (void): mu__byte(0, 3, 3) {};
  mu__subrange_160 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_161 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_161 (void): mu__byte(0, 3, 3) {};
  mu__subrange_161 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_162 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_162 (void): mu__byte(0, 3, 3) {};
  mu__subrange_162 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_163 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_163 (void): mu__byte(0, 3, 3) {};
  mu__subrange_163 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_164 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_164 (void): mu__byte(0, 3, 3) {};
  mu__subrange_164 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_165 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_165 (void): mu__byte(0, 3, 3) {};
  mu__subrange_165 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_166 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_166 (void): mu__byte(0, 3, 3) {};
  mu__subrange_166 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_167 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_167 (void): mu__byte(0, 3, 3) {};
  mu__subrange_167 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_168 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_168 (void): mu__byte(0, 3, 3) {};
  mu__subrange_168 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_169 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_169 (void): mu__byte(0, 3, 3) {};
  mu__subrange_169 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_170 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_170 (void): mu__byte(0, 3, 3) {};
  mu__subrange_170 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_171 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_171 (void): mu__byte(0, 3, 3) {};
  mu__subrange_171 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_172 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_172 (void): mu__byte(0, 3, 3) {};
  mu__subrange_172 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_173 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_173 (void): mu__byte(0, 3, 3) {};
  mu__subrange_173 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_174 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_174 (void): mu__byte(0, 3, 3) {};
  mu__subrange_174 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_175 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_175 (void): mu__byte(0, 3, 3) {};
  mu__subrange_175 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_176 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_176 (void): mu__byte(0, 3, 3) {};
  mu__subrange_176 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_177 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_177 (void): mu__byte(0, 3, 3) {};
  mu__subrange_177 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_178 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_178 (void): mu__byte(0, 3, 3) {};
  mu__subrange_178 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_179 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_179 (void): mu__byte(0, 3, 3) {};
  mu__subrange_179 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_180 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_180 (void): mu__byte(0, 3, 3) {};
  mu__subrange_180 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_181 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_181 (void): mu__byte(0, 3, 3) {};
  mu__subrange_181 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_182 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_182 (void): mu__byte(0, 3, 3) {};
  mu__subrange_182 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_183 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_183 (void): mu__byte(0, 3, 3) {};
  mu__subrange_183 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_184 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_184 (void): mu__byte(0, 3, 3) {};
  mu__subrange_184 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_185 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_185 (void): mu__byte(0, 3, 3) {};
  mu__subrange_185 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_186 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_186 (void): mu__byte(0, 3, 3) {};
  mu__subrange_186 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_187 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_187 (void): mu__byte(0, 3, 3) {};
  mu__subrange_187 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_188 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_188 (void): mu__byte(0, 3, 3) {};
  mu__subrange_188 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_189 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_189 (void): mu__byte(0, 3, 3) {};
  mu__subrange_189 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
  mu__subrange_190 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_190 (void): mu__byte(0, 3, 3) {};
  mu__subrange_190 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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

class mu__subrange_191: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_191& val) { return mu__byte::operator=((int) val); };
  mu__subrange_191 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_191 (void): mu__byte(0, 3, 3) {};
  mu__subrange_191 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_191 mu__subrange_191_undefined_var;

class mu__subrange_192: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_192& val) { return mu__byte::operator=((int) val); };
  mu__subrange_192 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_192 (void): mu__byte(0, 3, 3) {};
  mu__subrange_192 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_192 mu__subrange_192_undefined_var;

class mu__subrange_193: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_193& val) { return mu__byte::operator=((int) val); };
  mu__subrange_193 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_193 (void): mu__byte(0, 3, 3) {};
  mu__subrange_193 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_193 mu__subrange_193_undefined_var;

class mu__subrange_194: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_194& val) { return mu__byte::operator=((int) val); };
  mu__subrange_194 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_194 (void): mu__byte(0, 3, 3) {};
  mu__subrange_194 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_194 mu__subrange_194_undefined_var;

class mu__subrange_195: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_195& val) { return mu__byte::operator=((int) val); };
  mu__subrange_195 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_195 (void): mu__byte(0, 3, 3) {};
  mu__subrange_195 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_195 mu__subrange_195_undefined_var;

class mu__subrange_196: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_196& val) { return mu__byte::operator=((int) val); };
  mu__subrange_196 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_196 (void): mu__byte(0, 3, 3) {};
  mu__subrange_196 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_196 mu__subrange_196_undefined_var;

class mu__subrange_197: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_197& val) { return mu__byte::operator=((int) val); };
  mu__subrange_197 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_197 (void): mu__byte(0, 3, 3) {};
  mu__subrange_197 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_197 mu__subrange_197_undefined_var;

class mu__subrange_198: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_198& val) { return mu__byte::operator=((int) val); };
  mu__subrange_198 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_198 (void): mu__byte(0, 3, 3) {};
  mu__subrange_198 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_198 mu__subrange_198_undefined_var;

class mu__subrange_199: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_199& val) { return mu__byte::operator=((int) val); };
  mu__subrange_199 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_199 (void): mu__byte(0, 3, 3) {};
  mu__subrange_199 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_199 mu__subrange_199_undefined_var;

class mu__subrange_200: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_200& val) { return mu__byte::operator=((int) val); };
  mu__subrange_200 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_200 (void): mu__byte(0, 3, 3) {};
  mu__subrange_200 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_200 mu__subrange_200_undefined_var;

class mu__subrange_201: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_201& val) { return mu__byte::operator=((int) val); };
  mu__subrange_201 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_201 (void): mu__byte(0, 3, 3) {};
  mu__subrange_201 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_201 mu__subrange_201_undefined_var;

class mu__subrange_202: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_202& val) { return mu__byte::operator=((int) val); };
  mu__subrange_202 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_202 (void): mu__byte(0, 3, 3) {};
  mu__subrange_202 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_202 mu__subrange_202_undefined_var;

class mu__subrange_203: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_203& val) { return mu__byte::operator=((int) val); };
  mu__subrange_203 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_203 (void): mu__byte(0, 3, 3) {};
  mu__subrange_203 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_203 mu__subrange_203_undefined_var;

class mu__subrange_204: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_204& val) { return mu__byte::operator=((int) val); };
  mu__subrange_204 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_204 (void): mu__byte(0, 3, 3) {};
  mu__subrange_204 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_204 mu__subrange_204_undefined_var;

class mu__subrange_205: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_205& val) { return mu__byte::operator=((int) val); };
  mu__subrange_205 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_205 (void): mu__byte(0, 3, 3) {};
  mu__subrange_205 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_205 mu__subrange_205_undefined_var;

class mu__subrange_206: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_206& val) { return mu__byte::operator=((int) val); };
  mu__subrange_206 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_206 (void): mu__byte(0, 3, 3) {};
  mu__subrange_206 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_206 mu__subrange_206_undefined_var;

class mu__subrange_207: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_207& val) { return mu__byte::operator=((int) val); };
  mu__subrange_207 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_207 (void): mu__byte(0, 3, 3) {};
  mu__subrange_207 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_207 mu__subrange_207_undefined_var;

class mu__subrange_208: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_208& val) { return mu__byte::operator=((int) val); };
  mu__subrange_208 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_208 (void): mu__byte(0, 3, 3) {};
  mu__subrange_208 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_208 mu__subrange_208_undefined_var;

class mu__subrange_209: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_209& val) { return mu__byte::operator=((int) val); };
  mu__subrange_209 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_209 (void): mu__byte(0, 3, 3) {};
  mu__subrange_209 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_209 mu__subrange_209_undefined_var;

class mu__subrange_210: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_210& val) { return mu__byte::operator=((int) val); };
  mu__subrange_210 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_210 (void): mu__byte(0, 3, 3) {};
  mu__subrange_210 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_210 mu__subrange_210_undefined_var;

class mu__subrange_211: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_211& val) { return mu__byte::operator=((int) val); };
  mu__subrange_211 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_211 (void): mu__byte(0, 3, 3) {};
  mu__subrange_211 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_211 mu__subrange_211_undefined_var;

class mu__subrange_212: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_212& val) { return mu__byte::operator=((int) val); };
  mu__subrange_212 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_212 (void): mu__byte(0, 3, 3) {};
  mu__subrange_212 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_212 mu__subrange_212_undefined_var;

class mu__subrange_213: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_213& val) { return mu__byte::operator=((int) val); };
  mu__subrange_213 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_213 (void): mu__byte(0, 3, 3) {};
  mu__subrange_213 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_213 mu__subrange_213_undefined_var;

class mu__subrange_214: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_214& val) { return mu__byte::operator=((int) val); };
  mu__subrange_214 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_214 (void): mu__byte(0, 3, 3) {};
  mu__subrange_214 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_214 mu__subrange_214_undefined_var;

class mu__subrange_215: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_215& val) { return mu__byte::operator=((int) val); };
  mu__subrange_215 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_215 (void): mu__byte(0, 3, 3) {};
  mu__subrange_215 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_215 mu__subrange_215_undefined_var;

class mu__subrange_216: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_216& val) { return mu__byte::operator=((int) val); };
  mu__subrange_216 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_216 (void): mu__byte(0, 3, 3) {};
  mu__subrange_216 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_216 mu__subrange_216_undefined_var;

class mu__subrange_217: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_217& val) { return mu__byte::operator=((int) val); };
  mu__subrange_217 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_217 (void): mu__byte(0, 3, 3) {};
  mu__subrange_217 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_217 mu__subrange_217_undefined_var;

class mu__subrange_218: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_218& val) { return mu__byte::operator=((int) val); };
  mu__subrange_218 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_218 (void): mu__byte(0, 3, 3) {};
  mu__subrange_218 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_218 mu__subrange_218_undefined_var;

class mu__subrange_219: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_219& val) { return mu__byte::operator=((int) val); };
  mu__subrange_219 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_219 (void): mu__byte(0, 3, 3) {};
  mu__subrange_219 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_219 mu__subrange_219_undefined_var;

class mu__subrange_220: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_220& val) { return mu__byte::operator=((int) val); };
  mu__subrange_220 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_220 (void): mu__byte(0, 3, 3) {};
  mu__subrange_220 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_220 mu__subrange_220_undefined_var;

class mu__subrange_221: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_221& val) { return mu__byte::operator=((int) val); };
  mu__subrange_221 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_221 (void): mu__byte(0, 3, 3) {};
  mu__subrange_221 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_221 mu__subrange_221_undefined_var;

class mu__subrange_222: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_222& val) { return mu__byte::operator=((int) val); };
  mu__subrange_222 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_222 (void): mu__byte(0, 3, 3) {};
  mu__subrange_222 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_222 mu__subrange_222_undefined_var;

class mu__subrange_223: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_223& val) { return mu__byte::operator=((int) val); };
  mu__subrange_223 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_223 (void): mu__byte(0, 3, 3) {};
  mu__subrange_223 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_223 mu__subrange_223_undefined_var;

class mu__subrange_224: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_224& val) { return mu__byte::operator=((int) val); };
  mu__subrange_224 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_224 (void): mu__byte(0, 3, 3) {};
  mu__subrange_224 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_224 mu__subrange_224_undefined_var;

class mu__subrange_225: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_225& val) { return mu__byte::operator=((int) val); };
  mu__subrange_225 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_225 (void): mu__byte(0, 3, 3) {};
  mu__subrange_225 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu__subrange_225 mu__subrange_225_undefined_var;

const int mu_NumberNodes = 4;
const int mu_BufferSpace = 3;
const int mu_empty = 1;
const int mu_response = 2;
const int mu_request = 3;
const int mu_fwd_request = 4;
const int mu_fwd_response = 5;
/*** Variable declaration ***/
mu_1__type_1 mu_IncomingQueue("IncomingQueue",0);

/*** Variable declaration ***/
mu_1__type_4 mu_TailPointers("TailPointers",432);

/*** Variable declaration ***/
mu_1__type_6 mu_RouterStatus("RouterStatus",480);

/*** Variable declaration ***/
mu_1__type_8 mu_Routers("Routers",490);

/*** Variable declaration ***/
mu_1__type_9 mu_ExitPath("ExitPath",498);

/*** Variable declaration ***/
mu_1__type_10 mu_EntryPath("EntryPath",510);

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
int mu__ub12 = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub12; mu_i += 1) {
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
int mu__ub13 = (mu_TailPointers[mu_src_nid][mu_incom_to_src_nid]) - (1);
for (int mu_i = 1; mu_i <= mu__ub13; mu_i += 1) {
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
  mu_Routers.clear();
  mu_ExitPath.clear();
  mu_EntryPath.clear();
}
void world_class::undefine()
{
  mu_IncomingQueue.undefine();
  mu_TailPointers.undefine();
  mu_RouterStatus.undefine();
  mu_Routers.undefine();
  mu_ExitPath.undefine();
  mu_EntryPath.undefine();
}
void world_class::reset()
{
  mu_IncomingQueue.reset();
  mu_TailPointers.reset();
  mu_RouterStatus.reset();
  mu_Routers.reset();
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
  mu_Routers.print();
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
  mu_Routers.print_statistic();
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
    mu_Routers.print_diff(prevstate);
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
  mu_Routers.to_state( newstate );
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
    static mu__subrange_225 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_224 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_223 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_222 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_225 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_224 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_223 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_222 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr14;
bool mu__boolexpr15;
bool mu__boolexpr16;
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
bool mu__boolexpr24;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
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
  mu__boolexpr17 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr14;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_225 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_224 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_223 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_222 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 256 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
bool mu__boolexpr35;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
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
  mu__boolexpr28 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_n3) != (mu_n4)) ; 
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
    r = what_rule - 0;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_225 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_224 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_223 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_222 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_221 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_220 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_219 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_218 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process fwd_response + Process fwd_response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_221 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_220 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_219 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_218 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
bool mu__boolexpr39;
bool mu__boolexpr40;
bool mu__boolexpr41;
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr47 = FALSE ;
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
  mu__boolexpr44 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr36;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 256;
    static mu__subrange_221 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_220 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_219 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_218 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 512 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr48;
bool mu__boolexpr49;
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
bool mu__boolexpr53;
bool mu__boolexpr54;
bool mu__boolexpr55;
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr48) {
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
    r = what_rule - 256;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_221 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_220 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_219 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_218 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_217 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_216 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_215 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_214 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process request + Process fwd_response + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_217 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_216 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_215 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_214 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
bool mu__boolexpr65;
bool mu__boolexpr66;
bool mu__boolexpr67;
bool mu__boolexpr68;
bool mu__boolexpr69;
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr70)) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr69)) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr64)) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr60;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 512;
    static mu__subrange_217 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_216 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_215 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_214 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 768 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr73;
bool mu__boolexpr74;
bool mu__boolexpr75;
bool mu__boolexpr76;
bool mu__boolexpr77;
bool mu__boolexpr78;
bool mu__boolexpr79;
bool mu__boolexpr80;
bool mu__boolexpr81;
bool mu__boolexpr82;
bool mu__boolexpr83;
bool mu__boolexpr84;
bool mu__boolexpr85;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr84)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr83)) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr80)) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
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
  mu__boolexpr76 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr76)) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr73) {
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
    r = what_rule - 512;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_217 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_216 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_215 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_214 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_213 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_212 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_211 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_210 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_213 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_212 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_211 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_210 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr86;
bool mu__boolexpr87;
bool mu__boolexpr88;
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
bool mu__boolexpr95;
bool mu__boolexpr96;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr92)) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr88)) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr86;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 768;
    static mu__subrange_213 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_212 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_211 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_210 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 1024 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr97;
bool mu__boolexpr98;
bool mu__boolexpr99;
bool mu__boolexpr100;
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
bool mu__boolexpr105;
bool mu__boolexpr106;
bool mu__boolexpr107;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr107 = FALSE ;
  else {
  mu__boolexpr107 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr107)) mu__boolexpr106 = FALSE ;
  else {
  mu__boolexpr106 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr106)) mu__boolexpr105 = FALSE ;
  else {
  mu__boolexpr105 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr105)) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr99)) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr98)) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr97) {
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
    r = what_rule - 768;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_213 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_212 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_211 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_210 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_209 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_208 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_207 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_206 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request + Process fwd_response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_209 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_208 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_207 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_206 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
bool mu__boolexpr111;
bool mu__boolexpr112;
bool mu__boolexpr113;
bool mu__boolexpr114;
bool mu__boolexpr115;
bool mu__boolexpr116;
bool mu__boolexpr117;
bool mu__boolexpr118;
bool mu__boolexpr119;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr119 = FALSE ;
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
  mu__boolexpr116 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr116)) mu__boolexpr115 = FALSE ;
  else {
  mu__boolexpr115 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr115)) mu__boolexpr114 = FALSE ;
  else {
  mu__boolexpr114 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr114)) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr113)) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr112)) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr110)) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr109)) mu__boolexpr108 = FALSE ;
  else {
  mu__boolexpr108 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr108;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1024;
    static mu__subrange_209 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_208 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_207 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_206 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 1280 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr120;
bool mu__boolexpr121;
bool mu__boolexpr122;
bool mu__boolexpr123;
bool mu__boolexpr124;
bool mu__boolexpr125;
bool mu__boolexpr126;
bool mu__boolexpr127;
bool mu__boolexpr128;
bool mu__boolexpr129;
bool mu__boolexpr130;
bool mu__boolexpr131;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr131 = FALSE ;
  else {
  mu__boolexpr131 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr131)) mu__boolexpr130 = FALSE ;
  else {
  mu__boolexpr130 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr130)) mu__boolexpr129 = FALSE ;
  else {
  mu__boolexpr129 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr129)) mu__boolexpr128 = FALSE ;
  else {
  mu__boolexpr128 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr128)) mu__boolexpr127 = FALSE ;
  else {
  mu__boolexpr127 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr127)) mu__boolexpr126 = FALSE ;
  else {
  mu__boolexpr126 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr126)) mu__boolexpr125 = FALSE ;
  else {
  mu__boolexpr125 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr125)) mu__boolexpr124 = FALSE ;
  else {
  mu__boolexpr124 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr124)) mu__boolexpr123 = FALSE ;
  else {
  mu__boolexpr123 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr123)) mu__boolexpr122 = FALSE ;
  else {
  mu__boolexpr122 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr122)) mu__boolexpr121 = FALSE ;
  else {
  mu__boolexpr121 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr121)) mu__boolexpr120 = FALSE ;
  else {
  mu__boolexpr120 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr120) {
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
    r = what_rule - 1024;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_209 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_208 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_207 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_206 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_205 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_204 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_203 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_202 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request + Process request + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_205 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_204 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_203 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_202 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr132;
bool mu__boolexpr133;
bool mu__boolexpr134;
bool mu__boolexpr135;
bool mu__boolexpr136;
bool mu__boolexpr137;
bool mu__boolexpr138;
bool mu__boolexpr139;
bool mu__boolexpr140;
bool mu__boolexpr141;
bool mu__boolexpr142;
bool mu__boolexpr143;
bool mu__boolexpr144;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr144 = FALSE ;
  else {
  mu__boolexpr144 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr144)) mu__boolexpr143 = FALSE ;
  else {
  mu__boolexpr143 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr143)) mu__boolexpr142 = FALSE ;
  else {
  mu__boolexpr142 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr142)) mu__boolexpr141 = FALSE ;
  else {
  mu__boolexpr141 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr141)) mu__boolexpr140 = FALSE ;
  else {
  mu__boolexpr140 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr140)) mu__boolexpr139 = FALSE ;
  else {
  mu__boolexpr139 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr139)) mu__boolexpr138 = FALSE ;
  else {
  mu__boolexpr138 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr138)) mu__boolexpr137 = FALSE ;
  else {
  mu__boolexpr137 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr137)) mu__boolexpr136 = FALSE ;
  else {
  mu__boolexpr136 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr136)) mu__boolexpr135 = FALSE ;
  else {
  mu__boolexpr135 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr135)) mu__boolexpr134 = FALSE ;
  else {
  mu__boolexpr134 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr134)) mu__boolexpr133 = FALSE ;
  else {
  mu__boolexpr133 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr133)) mu__boolexpr132 = FALSE ;
  else {
  mu__boolexpr132 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr132;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1280;
    static mu__subrange_205 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_204 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_203 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_202 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 1536 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr145;
bool mu__boolexpr146;
bool mu__boolexpr147;
bool mu__boolexpr148;
bool mu__boolexpr149;
bool mu__boolexpr150;
bool mu__boolexpr151;
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
  mu__boolexpr156 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr156)) mu__boolexpr155 = FALSE ;
  else {
  mu__boolexpr155 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr155)) mu__boolexpr154 = FALSE ;
  else {
  mu__boolexpr154 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr154)) mu__boolexpr153 = FALSE ;
  else {
  mu__boolexpr153 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr153)) mu__boolexpr152 = FALSE ;
  else {
  mu__boolexpr152 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr152)) mu__boolexpr151 = FALSE ;
  else {
  mu__boolexpr151 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr151)) mu__boolexpr150 = FALSE ;
  else {
  mu__boolexpr150 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr150)) mu__boolexpr149 = FALSE ;
  else {
  mu__boolexpr149 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr149)) mu__boolexpr148 = FALSE ;
  else {
  mu__boolexpr148 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr148)) mu__boolexpr147 = FALSE ;
  else {
  mu__boolexpr147 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr147)) mu__boolexpr146 = FALSE ;
  else {
  mu__boolexpr146 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr146)) mu__boolexpr145 = FALSE ;
  else {
  mu__boolexpr145 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr145) {
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
    r = what_rule - 1280;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_205 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_204 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_203 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_202 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_201 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_200 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_199 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_198 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_201 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_200 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_199 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_198 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr158;
bool mu__boolexpr159;
bool mu__boolexpr160;
bool mu__boolexpr161;
bool mu__boolexpr162;
bool mu__boolexpr163;
bool mu__boolexpr164;
bool mu__boolexpr165;
bool mu__boolexpr166;
bool mu__boolexpr167;
bool mu__boolexpr168;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr168 = FALSE ;
  else {
  mu__boolexpr168 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr168)) mu__boolexpr167 = FALSE ;
  else {
  mu__boolexpr167 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr167)) mu__boolexpr166 = FALSE ;
  else {
  mu__boolexpr166 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr166)) mu__boolexpr165 = FALSE ;
  else {
  mu__boolexpr165 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr165)) mu__boolexpr164 = FALSE ;
  else {
  mu__boolexpr164 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr164)) mu__boolexpr163 = FALSE ;
  else {
  mu__boolexpr163 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr163)) mu__boolexpr162 = FALSE ;
  else {
  mu__boolexpr162 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr162)) mu__boolexpr161 = FALSE ;
  else {
  mu__boolexpr161 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr161)) mu__boolexpr160 = FALSE ;
  else {
  mu__boolexpr160 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr160)) mu__boolexpr159 = FALSE ;
  else {
  mu__boolexpr159 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr159)) mu__boolexpr158 = FALSE ;
  else {
  mu__boolexpr158 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr158;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1536;
    static mu__subrange_201 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_200 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_199 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_198 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 1792 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr169;
bool mu__boolexpr170;
bool mu__boolexpr171;
bool mu__boolexpr172;
bool mu__boolexpr173;
bool mu__boolexpr174;
bool mu__boolexpr175;
bool mu__boolexpr176;
bool mu__boolexpr177;
bool mu__boolexpr178;
bool mu__boolexpr179;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr179 = FALSE ;
  else {
  mu__boolexpr179 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr179)) mu__boolexpr178 = FALSE ;
  else {
  mu__boolexpr178 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr178)) mu__boolexpr177 = FALSE ;
  else {
  mu__boolexpr177 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr177)) mu__boolexpr176 = FALSE ;
  else {
  mu__boolexpr176 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr176)) mu__boolexpr175 = FALSE ;
  else {
  mu__boolexpr175 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr175)) mu__boolexpr174 = FALSE ;
  else {
  mu__boolexpr174 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr174)) mu__boolexpr173 = FALSE ;
  else {
  mu__boolexpr173 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr173)) mu__boolexpr172 = FALSE ;
  else {
  mu__boolexpr172 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr172)) mu__boolexpr171 = FALSE ;
  else {
  mu__boolexpr171 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr171)) mu__boolexpr170 = FALSE ;
  else {
  mu__boolexpr170 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr170)) mu__boolexpr169 = FALSE ;
  else {
  mu__boolexpr169 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr169) {
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
    r = what_rule - 1536;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_201 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_200 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_199 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_198 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_197 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_196 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_195 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_194 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process request + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_197 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_196 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_195 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_194 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr180;
bool mu__boolexpr181;
bool mu__boolexpr182;
bool mu__boolexpr183;
bool mu__boolexpr184;
bool mu__boolexpr185;
bool mu__boolexpr186;
bool mu__boolexpr187;
bool mu__boolexpr188;
bool mu__boolexpr189;
bool mu__boolexpr190;
bool mu__boolexpr191;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr191 = FALSE ;
  else {
  mu__boolexpr191 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr191)) mu__boolexpr190 = FALSE ;
  else {
  mu__boolexpr190 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr190)) mu__boolexpr189 = FALSE ;
  else {
  mu__boolexpr189 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr189)) mu__boolexpr188 = FALSE ;
  else {
  mu__boolexpr188 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr188)) mu__boolexpr187 = FALSE ;
  else {
  mu__boolexpr187 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr187)) mu__boolexpr186 = FALSE ;
  else {
  mu__boolexpr186 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr186)) mu__boolexpr185 = FALSE ;
  else {
  mu__boolexpr185 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr185)) mu__boolexpr184 = FALSE ;
  else {
  mu__boolexpr184 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr184)) mu__boolexpr183 = FALSE ;
  else {
  mu__boolexpr183 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr183)) mu__boolexpr182 = FALSE ;
  else {
  mu__boolexpr182 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr182)) mu__boolexpr181 = FALSE ;
  else {
  mu__boolexpr181 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr181)) mu__boolexpr180 = FALSE ;
  else {
  mu__boolexpr180 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr180;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1792;
    static mu__subrange_197 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_196 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_195 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_194 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 2048 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr192;
bool mu__boolexpr193;
bool mu__boolexpr194;
bool mu__boolexpr195;
bool mu__boolexpr196;
bool mu__boolexpr197;
bool mu__boolexpr198;
bool mu__boolexpr199;
bool mu__boolexpr200;
bool mu__boolexpr201;
bool mu__boolexpr202;
bool mu__boolexpr203;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr203 = FALSE ;
  else {
  mu__boolexpr203 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr203)) mu__boolexpr202 = FALSE ;
  else {
  mu__boolexpr202 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr202)) mu__boolexpr201 = FALSE ;
  else {
  mu__boolexpr201 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr201)) mu__boolexpr200 = FALSE ;
  else {
  mu__boolexpr200 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr200)) mu__boolexpr199 = FALSE ;
  else {
  mu__boolexpr199 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr199)) mu__boolexpr198 = FALSE ;
  else {
  mu__boolexpr198 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr198)) mu__boolexpr197 = FALSE ;
  else {
  mu__boolexpr197 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr197)) mu__boolexpr196 = FALSE ;
  else {
  mu__boolexpr196 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr196)) mu__boolexpr195 = FALSE ;
  else {
  mu__boolexpr195 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr195)) mu__boolexpr194 = FALSE ;
  else {
  mu__boolexpr194 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr194)) mu__boolexpr193 = FALSE ;
  else {
  mu__boolexpr193 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr193)) mu__boolexpr192 = FALSE ;
  else {
  mu__boolexpr192 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr192) {
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
    r = what_rule - 1792;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_197 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_196 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_195 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_194 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_193 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_192 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_191 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_190 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process request + Process request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_193 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_192 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_191 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_190 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr204;
bool mu__boolexpr205;
bool mu__boolexpr206;
bool mu__boolexpr207;
bool mu__boolexpr208;
bool mu__boolexpr209;
bool mu__boolexpr210;
bool mu__boolexpr211;
bool mu__boolexpr212;
bool mu__boolexpr213;
bool mu__boolexpr214;
bool mu__boolexpr215;
bool mu__boolexpr216;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr216 = FALSE ;
  else {
  mu__boolexpr216 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr216)) mu__boolexpr215 = FALSE ;
  else {
  mu__boolexpr215 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr215)) mu__boolexpr214 = FALSE ;
  else {
  mu__boolexpr214 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr214)) mu__boolexpr213 = FALSE ;
  else {
  mu__boolexpr213 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr213)) mu__boolexpr212 = FALSE ;
  else {
  mu__boolexpr212 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr212)) mu__boolexpr211 = FALSE ;
  else {
  mu__boolexpr211 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr211)) mu__boolexpr210 = FALSE ;
  else {
  mu__boolexpr210 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr210)) mu__boolexpr209 = FALSE ;
  else {
  mu__boolexpr209 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr209)) mu__boolexpr208 = FALSE ;
  else {
  mu__boolexpr208 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr208)) mu__boolexpr207 = FALSE ;
  else {
  mu__boolexpr207 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr207)) mu__boolexpr206 = FALSE ;
  else {
  mu__boolexpr206 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr206)) mu__boolexpr205 = FALSE ;
  else {
  mu__boolexpr205 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr205)) mu__boolexpr204 = FALSE ;
  else {
  mu__boolexpr204 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr204;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2048;
    static mu__subrange_193 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_192 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_191 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_190 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 2304 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr217;
bool mu__boolexpr218;
bool mu__boolexpr219;
bool mu__boolexpr220;
bool mu__boolexpr221;
bool mu__boolexpr222;
bool mu__boolexpr223;
bool mu__boolexpr224;
bool mu__boolexpr225;
bool mu__boolexpr226;
bool mu__boolexpr227;
bool mu__boolexpr228;
bool mu__boolexpr229;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr229 = FALSE ;
  else {
  mu__boolexpr229 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr229)) mu__boolexpr228 = FALSE ;
  else {
  mu__boolexpr228 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr228)) mu__boolexpr227 = FALSE ;
  else {
  mu__boolexpr227 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr227)) mu__boolexpr226 = FALSE ;
  else {
  mu__boolexpr226 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr226)) mu__boolexpr225 = FALSE ;
  else {
  mu__boolexpr225 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr225)) mu__boolexpr224 = FALSE ;
  else {
  mu__boolexpr224 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr224)) mu__boolexpr223 = FALSE ;
  else {
  mu__boolexpr223 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr223)) mu__boolexpr222 = FALSE ;
  else {
  mu__boolexpr222 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr222)) mu__boolexpr221 = FALSE ;
  else {
  mu__boolexpr221 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr221)) mu__boolexpr220 = FALSE ;
  else {
  mu__boolexpr220 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr220)) mu__boolexpr219 = FALSE ;
  else {
  mu__boolexpr219 = ((mu_n2) != (mu_n3)) ; 
}
  if (!(mu__boolexpr219)) mu__boolexpr218 = FALSE ;
  else {
  mu__boolexpr218 = ((mu_n2) != (mu_n4)) ; 
}
  if (!(mu__boolexpr218)) mu__boolexpr217 = FALSE ;
  else {
  mu__boolexpr217 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr217) {
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
    r = what_rule - 2048;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_193 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_192 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_191 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_190 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_189 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_188 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_response + Process fwd_response + Process response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_189 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_188 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr230;
bool mu__boolexpr231;
bool mu__boolexpr232;
bool mu__boolexpr233;
bool mu__boolexpr234;
bool mu__boolexpr235;
bool mu__boolexpr236;
bool mu__boolexpr237;
bool mu__boolexpr238;
bool mu__boolexpr239;
bool mu__boolexpr240;
bool mu__boolexpr241;
bool mu__boolexpr242;
bool mu__boolexpr243;
bool mu__boolexpr244;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr244 = FALSE ;
  else {
  mu__boolexpr244 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr244)) mu__boolexpr243 = FALSE ;
  else {
  mu__boolexpr243 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr243)) mu__boolexpr242 = FALSE ;
  else {
  mu__boolexpr242 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr242)) mu__boolexpr241 = FALSE ;
  else {
  mu__boolexpr241 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr241)) mu__boolexpr240 = FALSE ;
  else {
  mu__boolexpr240 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr240)) mu__boolexpr239 = FALSE ;
  else {
  mu__boolexpr239 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr239)) mu__boolexpr238 = FALSE ;
  else {
  mu__boolexpr238 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr238)) mu__boolexpr237 = FALSE ;
  else {
  mu__boolexpr237 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr237)) mu__boolexpr236 = FALSE ;
  else {
  mu__boolexpr236 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr236)) mu__boolexpr235 = FALSE ;
  else {
  mu__boolexpr235 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr235)) mu__boolexpr234 = FALSE ;
  else {
  mu__boolexpr234 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr234)) mu__boolexpr233 = FALSE ;
  else {
  mu__boolexpr233 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr233)) mu__boolexpr232 = FALSE ;
  else {
  mu__boolexpr232 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr232)) mu__boolexpr231 = FALSE ;
  else {
  mu__boolexpr231 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr231)) mu__boolexpr230 = FALSE ;
  else {
  mu__boolexpr230 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr230;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2304;
    static mu__subrange_189 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_188 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 3328 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr245;
bool mu__boolexpr246;
bool mu__boolexpr247;
bool mu__boolexpr248;
bool mu__boolexpr249;
bool mu__boolexpr250;
bool mu__boolexpr251;
bool mu__boolexpr252;
bool mu__boolexpr253;
bool mu__boolexpr254;
bool mu__boolexpr255;
bool mu__boolexpr256;
bool mu__boolexpr257;
bool mu__boolexpr258;
bool mu__boolexpr259;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr259 = FALSE ;
  else {
  mu__boolexpr259 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr259)) mu__boolexpr258 = FALSE ;
  else {
  mu__boolexpr258 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr258)) mu__boolexpr257 = FALSE ;
  else {
  mu__boolexpr257 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr257)) mu__boolexpr256 = FALSE ;
  else {
  mu__boolexpr256 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr256)) mu__boolexpr255 = FALSE ;
  else {
  mu__boolexpr255 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr255)) mu__boolexpr254 = FALSE ;
  else {
  mu__boolexpr254 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr254)) mu__boolexpr253 = FALSE ;
  else {
  mu__boolexpr253 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr253)) mu__boolexpr252 = FALSE ;
  else {
  mu__boolexpr252 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr252)) mu__boolexpr251 = FALSE ;
  else {
  mu__boolexpr251 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr251)) mu__boolexpr250 = FALSE ;
  else {
  mu__boolexpr250 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr250)) mu__boolexpr249 = FALSE ;
  else {
  mu__boolexpr249 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr249)) mu__boolexpr248 = FALSE ;
  else {
  mu__boolexpr248 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr248)) mu__boolexpr247 = FALSE ;
  else {
  mu__boolexpr247 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr247)) mu__boolexpr246 = FALSE ;
  else {
  mu__boolexpr246 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr246)) mu__boolexpr245 = FALSE ;
  else {
  mu__boolexpr245 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr245) {
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
    r = what_rule - 2304;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_189 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_188 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_187 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_186 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_185 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessResponse ( (int)mu_n5, mu_EntryPath[mu_n5] );
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
    static mu__subrange_184 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_183 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_182 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_181 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_180 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process request + Process fwd_response + Process fwd_response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_184 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_183 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_182 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_181 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_180 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr260;
bool mu__boolexpr261;
bool mu__boolexpr262;
bool mu__boolexpr263;
bool mu__boolexpr264;
bool mu__boolexpr265;
bool mu__boolexpr266;
bool mu__boolexpr267;
bool mu__boolexpr268;
bool mu__boolexpr269;
bool mu__boolexpr270;
bool mu__boolexpr271;
bool mu__boolexpr272;
bool mu__boolexpr273;
bool mu__boolexpr274;
bool mu__boolexpr275;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr275 = FALSE ;
  else {
  mu__boolexpr275 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr275)) mu__boolexpr274 = FALSE ;
  else {
  mu__boolexpr274 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr274)) mu__boolexpr273 = FALSE ;
  else {
  mu__boolexpr273 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr273)) mu__boolexpr272 = FALSE ;
  else {
  mu__boolexpr272 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr272)) mu__boolexpr271 = FALSE ;
  else {
  mu__boolexpr271 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr271)) mu__boolexpr270 = FALSE ;
  else {
  mu__boolexpr270 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr270)) mu__boolexpr269 = FALSE ;
  else {
  mu__boolexpr269 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr269)) mu__boolexpr268 = FALSE ;
  else {
  mu__boolexpr268 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr268)) mu__boolexpr267 = FALSE ;
  else {
  mu__boolexpr267 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr267)) mu__boolexpr266 = FALSE ;
  else {
  mu__boolexpr266 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr266)) mu__boolexpr265 = FALSE ;
  else {
  mu__boolexpr265 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr265)) mu__boolexpr264 = FALSE ;
  else {
  mu__boolexpr264 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr264)) mu__boolexpr263 = FALSE ;
  else {
  mu__boolexpr263 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr263)) mu__boolexpr262 = FALSE ;
  else {
  mu__boolexpr262 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr262)) mu__boolexpr261 = FALSE ;
  else {
  mu__boolexpr261 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr261)) mu__boolexpr260 = FALSE ;
  else {
  mu__boolexpr260 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr260;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3328;
    static mu__subrange_184 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_183 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_182 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_181 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_180 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 4352 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr276;
bool mu__boolexpr277;
bool mu__boolexpr278;
bool mu__boolexpr279;
bool mu__boolexpr280;
bool mu__boolexpr281;
bool mu__boolexpr282;
bool mu__boolexpr283;
bool mu__boolexpr284;
bool mu__boolexpr285;
bool mu__boolexpr286;
bool mu__boolexpr287;
bool mu__boolexpr288;
bool mu__boolexpr289;
bool mu__boolexpr290;
bool mu__boolexpr291;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr291 = FALSE ;
  else {
  mu__boolexpr291 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr291)) mu__boolexpr290 = FALSE ;
  else {
  mu__boolexpr290 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr290)) mu__boolexpr289 = FALSE ;
  else {
  mu__boolexpr289 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr289)) mu__boolexpr288 = FALSE ;
  else {
  mu__boolexpr288 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr288)) mu__boolexpr287 = FALSE ;
  else {
  mu__boolexpr287 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr287)) mu__boolexpr286 = FALSE ;
  else {
  mu__boolexpr286 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr286)) mu__boolexpr285 = FALSE ;
  else {
  mu__boolexpr285 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr285)) mu__boolexpr284 = FALSE ;
  else {
  mu__boolexpr284 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr284)) mu__boolexpr283 = FALSE ;
  else {
  mu__boolexpr283 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr283)) mu__boolexpr282 = FALSE ;
  else {
  mu__boolexpr282 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr282)) mu__boolexpr281 = FALSE ;
  else {
  mu__boolexpr281 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr281)) mu__boolexpr280 = FALSE ;
  else {
  mu__boolexpr280 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr280)) mu__boolexpr279 = FALSE ;
  else {
  mu__boolexpr279 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr279)) mu__boolexpr278 = FALSE ;
  else {
  mu__boolexpr278 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr278)) mu__boolexpr277 = FALSE ;
  else {
  mu__boolexpr277 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr277)) mu__boolexpr276 = FALSE ;
  else {
  mu__boolexpr276 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr276) {
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
    r = what_rule - 3328;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_184 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_183 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_182 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_181 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_180 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessFwdResponse ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
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
    static mu__subrange_179 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_178 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_177 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_176 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_175 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_response + Process response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_179 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_178 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_177 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_176 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_175 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr292;
bool mu__boolexpr293;
bool mu__boolexpr294;
bool mu__boolexpr295;
bool mu__boolexpr296;
bool mu__boolexpr297;
bool mu__boolexpr298;
bool mu__boolexpr299;
bool mu__boolexpr300;
bool mu__boolexpr301;
bool mu__boolexpr302;
bool mu__boolexpr303;
bool mu__boolexpr304;
bool mu__boolexpr305;
bool mu__boolexpr306;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr306 = FALSE ;
  else {
  mu__boolexpr306 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr306)) mu__boolexpr305 = FALSE ;
  else {
  mu__boolexpr305 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr305)) mu__boolexpr304 = FALSE ;
  else {
  mu__boolexpr304 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr304)) mu__boolexpr303 = FALSE ;
  else {
  mu__boolexpr303 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr303)) mu__boolexpr302 = FALSE ;
  else {
  mu__boolexpr302 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr302)) mu__boolexpr301 = FALSE ;
  else {
  mu__boolexpr301 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr301)) mu__boolexpr300 = FALSE ;
  else {
  mu__boolexpr300 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr300)) mu__boolexpr299 = FALSE ;
  else {
  mu__boolexpr299 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr299)) mu__boolexpr298 = FALSE ;
  else {
  mu__boolexpr298 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr298)) mu__boolexpr297 = FALSE ;
  else {
  mu__boolexpr297 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr297)) mu__boolexpr296 = FALSE ;
  else {
  mu__boolexpr296 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr296)) mu__boolexpr295 = FALSE ;
  else {
  mu__boolexpr295 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr295)) mu__boolexpr294 = FALSE ;
  else {
  mu__boolexpr294 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr294)) mu__boolexpr293 = FALSE ;
  else {
  mu__boolexpr293 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr293)) mu__boolexpr292 = FALSE ;
  else {
  mu__boolexpr292 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr292;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4352;
    static mu__subrange_179 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_178 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_177 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_176 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_175 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 5376 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr307;
bool mu__boolexpr308;
bool mu__boolexpr309;
bool mu__boolexpr310;
bool mu__boolexpr311;
bool mu__boolexpr312;
bool mu__boolexpr313;
bool mu__boolexpr314;
bool mu__boolexpr315;
bool mu__boolexpr316;
bool mu__boolexpr317;
bool mu__boolexpr318;
bool mu__boolexpr319;
bool mu__boolexpr320;
bool mu__boolexpr321;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr321 = FALSE ;
  else {
  mu__boolexpr321 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr321)) mu__boolexpr320 = FALSE ;
  else {
  mu__boolexpr320 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr320)) mu__boolexpr319 = FALSE ;
  else {
  mu__boolexpr319 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr319)) mu__boolexpr318 = FALSE ;
  else {
  mu__boolexpr318 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr318)) mu__boolexpr317 = FALSE ;
  else {
  mu__boolexpr317 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr317)) mu__boolexpr316 = FALSE ;
  else {
  mu__boolexpr316 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr316)) mu__boolexpr315 = FALSE ;
  else {
  mu__boolexpr315 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr315)) mu__boolexpr314 = FALSE ;
  else {
  mu__boolexpr314 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr314)) mu__boolexpr313 = FALSE ;
  else {
  mu__boolexpr313 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr313)) mu__boolexpr312 = FALSE ;
  else {
  mu__boolexpr312 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr312)) mu__boolexpr311 = FALSE ;
  else {
  mu__boolexpr311 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr311)) mu__boolexpr310 = FALSE ;
  else {
  mu__boolexpr310 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr310)) mu__boolexpr309 = FALSE ;
  else {
  mu__boolexpr309 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr309)) mu__boolexpr308 = FALSE ;
  else {
  mu__boolexpr308 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr308)) mu__boolexpr307 = FALSE ;
  else {
  mu__boolexpr307 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr307) {
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
    r = what_rule - 4352;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_179 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_178 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_177 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_176 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_175 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessResponse ( (int)mu_n5, mu_EntryPath[mu_n5] );
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
    static mu__subrange_174 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_173 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process request + Process fwd_response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_174 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_173 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr322;
bool mu__boolexpr323;
bool mu__boolexpr324;
bool mu__boolexpr325;
bool mu__boolexpr326;
bool mu__boolexpr327;
bool mu__boolexpr328;
bool mu__boolexpr329;
bool mu__boolexpr330;
bool mu__boolexpr331;
bool mu__boolexpr332;
bool mu__boolexpr333;
bool mu__boolexpr334;
bool mu__boolexpr335;
bool mu__boolexpr336;
bool mu__boolexpr337;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr337 = FALSE ;
  else {
  mu__boolexpr337 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr337)) mu__boolexpr336 = FALSE ;
  else {
  mu__boolexpr336 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr336)) mu__boolexpr335 = FALSE ;
  else {
  mu__boolexpr335 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr335)) mu__boolexpr334 = FALSE ;
  else {
  mu__boolexpr334 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr334)) mu__boolexpr333 = FALSE ;
  else {
  mu__boolexpr333 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr333)) mu__boolexpr332 = FALSE ;
  else {
  mu__boolexpr332 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr332)) mu__boolexpr331 = FALSE ;
  else {
  mu__boolexpr331 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr331)) mu__boolexpr330 = FALSE ;
  else {
  mu__boolexpr330 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr330)) mu__boolexpr329 = FALSE ;
  else {
  mu__boolexpr329 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr329)) mu__boolexpr328 = FALSE ;
  else {
  mu__boolexpr328 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr328)) mu__boolexpr327 = FALSE ;
  else {
  mu__boolexpr327 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr327)) mu__boolexpr326 = FALSE ;
  else {
  mu__boolexpr326 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr326)) mu__boolexpr325 = FALSE ;
  else {
  mu__boolexpr325 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr325)) mu__boolexpr324 = FALSE ;
  else {
  mu__boolexpr324 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr324)) mu__boolexpr323 = FALSE ;
  else {
  mu__boolexpr323 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr323)) mu__boolexpr322 = FALSE ;
  else {
  mu__boolexpr322 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr322;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5376;
    static mu__subrange_174 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_173 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 6400 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr338;
bool mu__boolexpr339;
bool mu__boolexpr340;
bool mu__boolexpr341;
bool mu__boolexpr342;
bool mu__boolexpr343;
bool mu__boolexpr344;
bool mu__boolexpr345;
bool mu__boolexpr346;
bool mu__boolexpr347;
bool mu__boolexpr348;
bool mu__boolexpr349;
bool mu__boolexpr350;
bool mu__boolexpr351;
bool mu__boolexpr352;
bool mu__boolexpr353;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr353 = FALSE ;
  else {
  mu__boolexpr353 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr353)) mu__boolexpr352 = FALSE ;
  else {
  mu__boolexpr352 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr352)) mu__boolexpr351 = FALSE ;
  else {
  mu__boolexpr351 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr351)) mu__boolexpr350 = FALSE ;
  else {
  mu__boolexpr350 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr350)) mu__boolexpr349 = FALSE ;
  else {
  mu__boolexpr349 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr349)) mu__boolexpr348 = FALSE ;
  else {
  mu__boolexpr348 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr348)) mu__boolexpr347 = FALSE ;
  else {
  mu__boolexpr347 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr347)) mu__boolexpr346 = FALSE ;
  else {
  mu__boolexpr346 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr346)) mu__boolexpr345 = FALSE ;
  else {
  mu__boolexpr345 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr345)) mu__boolexpr344 = FALSE ;
  else {
  mu__boolexpr344 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr344)) mu__boolexpr343 = FALSE ;
  else {
  mu__boolexpr343 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr343)) mu__boolexpr342 = FALSE ;
  else {
  mu__boolexpr342 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr342)) mu__boolexpr341 = FALSE ;
  else {
  mu__boolexpr341 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr341)) mu__boolexpr340 = FALSE ;
  else {
  mu__boolexpr340 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr340)) mu__boolexpr339 = FALSE ;
  else {
  mu__boolexpr339 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr339)) mu__boolexpr338 = FALSE ;
  else {
  mu__boolexpr338 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr338) {
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
    r = what_rule - 5376;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_174 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_173 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_172 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_171 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_170 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessFwdResponse ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
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
    static mu__subrange_169 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_168 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_167 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_166 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_165 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_request + Process response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_169 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_168 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_167 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_166 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_165 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr354;
bool mu__boolexpr355;
bool mu__boolexpr356;
bool mu__boolexpr357;
bool mu__boolexpr358;
bool mu__boolexpr359;
bool mu__boolexpr360;
bool mu__boolexpr361;
bool mu__boolexpr362;
bool mu__boolexpr363;
bool mu__boolexpr364;
bool mu__boolexpr365;
bool mu__boolexpr366;
bool mu__boolexpr367;
bool mu__boolexpr368;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr368 = FALSE ;
  else {
  mu__boolexpr368 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr368)) mu__boolexpr367 = FALSE ;
  else {
  mu__boolexpr367 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr367)) mu__boolexpr366 = FALSE ;
  else {
  mu__boolexpr366 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr366)) mu__boolexpr365 = FALSE ;
  else {
  mu__boolexpr365 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr365)) mu__boolexpr364 = FALSE ;
  else {
  mu__boolexpr364 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr364)) mu__boolexpr363 = FALSE ;
  else {
  mu__boolexpr363 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr363)) mu__boolexpr362 = FALSE ;
  else {
  mu__boolexpr362 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr362)) mu__boolexpr361 = FALSE ;
  else {
  mu__boolexpr361 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr361)) mu__boolexpr360 = FALSE ;
  else {
  mu__boolexpr360 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr360)) mu__boolexpr359 = FALSE ;
  else {
  mu__boolexpr359 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr359)) mu__boolexpr358 = FALSE ;
  else {
  mu__boolexpr358 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr358)) mu__boolexpr357 = FALSE ;
  else {
  mu__boolexpr357 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr357)) mu__boolexpr356 = FALSE ;
  else {
  mu__boolexpr356 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr356)) mu__boolexpr355 = FALSE ;
  else {
  mu__boolexpr355 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr355)) mu__boolexpr354 = FALSE ;
  else {
  mu__boolexpr354 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr354;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6400;
    static mu__subrange_169 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_168 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_167 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_166 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_165 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 7424 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr369;
bool mu__boolexpr370;
bool mu__boolexpr371;
bool mu__boolexpr372;
bool mu__boolexpr373;
bool mu__boolexpr374;
bool mu__boolexpr375;
bool mu__boolexpr376;
bool mu__boolexpr377;
bool mu__boolexpr378;
bool mu__boolexpr379;
bool mu__boolexpr380;
bool mu__boolexpr381;
bool mu__boolexpr382;
bool mu__boolexpr383;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr383 = FALSE ;
  else {
  mu__boolexpr383 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr383)) mu__boolexpr382 = FALSE ;
  else {
  mu__boolexpr382 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr382)) mu__boolexpr381 = FALSE ;
  else {
  mu__boolexpr381 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr381)) mu__boolexpr380 = FALSE ;
  else {
  mu__boolexpr380 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr380)) mu__boolexpr379 = FALSE ;
  else {
  mu__boolexpr379 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr379)) mu__boolexpr378 = FALSE ;
  else {
  mu__boolexpr378 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr378)) mu__boolexpr377 = FALSE ;
  else {
  mu__boolexpr377 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr377)) mu__boolexpr376 = FALSE ;
  else {
  mu__boolexpr376 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr376)) mu__boolexpr375 = FALSE ;
  else {
  mu__boolexpr375 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr375)) mu__boolexpr374 = FALSE ;
  else {
  mu__boolexpr374 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr374)) mu__boolexpr373 = FALSE ;
  else {
  mu__boolexpr373 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr373)) mu__boolexpr372 = FALSE ;
  else {
  mu__boolexpr372 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr372)) mu__boolexpr371 = FALSE ;
  else {
  mu__boolexpr371 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr371)) mu__boolexpr370 = FALSE ;
  else {
  mu__boolexpr370 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr370)) mu__boolexpr369 = FALSE ;
  else {
  mu__boolexpr369 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr369) {
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
    r = what_rule - 6400;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_169 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_168 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_167 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_166 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_165 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessResponse ( (int)mu_n5, mu_EntryPath[mu_n5] );
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
    static mu__subrange_164 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_163 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_162 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_161 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_160 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_request + Process request, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_164 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_163 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_162 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_161 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_160 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr384;
bool mu__boolexpr385;
bool mu__boolexpr386;
bool mu__boolexpr387;
bool mu__boolexpr388;
bool mu__boolexpr389;
bool mu__boolexpr390;
bool mu__boolexpr391;
bool mu__boolexpr392;
bool mu__boolexpr393;
bool mu__boolexpr394;
bool mu__boolexpr395;
bool mu__boolexpr396;
bool mu__boolexpr397;
bool mu__boolexpr398;
bool mu__boolexpr399;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr399 = FALSE ;
  else {
  mu__boolexpr399 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr399)) mu__boolexpr398 = FALSE ;
  else {
  mu__boolexpr398 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr398)) mu__boolexpr397 = FALSE ;
  else {
  mu__boolexpr397 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr397)) mu__boolexpr396 = FALSE ;
  else {
  mu__boolexpr396 = ((mu_Routers[mu_n2]) == (0)) ; 
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
  mu__boolexpr393 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr393)) mu__boolexpr392 = FALSE ;
  else {
  mu__boolexpr392 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr392)) mu__boolexpr391 = FALSE ;
  else {
  mu__boolexpr391 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr391)) mu__boolexpr390 = FALSE ;
  else {
  mu__boolexpr390 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr390)) mu__boolexpr389 = FALSE ;
  else {
  mu__boolexpr389 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr389)) mu__boolexpr388 = FALSE ;
  else {
  mu__boolexpr388 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr388)) mu__boolexpr387 = FALSE ;
  else {
  mu__boolexpr387 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr387)) mu__boolexpr386 = FALSE ;
  else {
  mu__boolexpr386 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr386)) mu__boolexpr385 = FALSE ;
  else {
  mu__boolexpr385 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr385)) mu__boolexpr384 = FALSE ;
  else {
  mu__boolexpr384 = ((mu_n4) != (mu_n5)) ; 
}
    return mu__boolexpr384;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 7424;
    static mu__subrange_164 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_163 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_162 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_161 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_160 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 8448 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr400;
bool mu__boolexpr401;
bool mu__boolexpr402;
bool mu__boolexpr403;
bool mu__boolexpr404;
bool mu__boolexpr405;
bool mu__boolexpr406;
bool mu__boolexpr407;
bool mu__boolexpr408;
bool mu__boolexpr409;
bool mu__boolexpr410;
bool mu__boolexpr411;
bool mu__boolexpr412;
bool mu__boolexpr413;
bool mu__boolexpr414;
bool mu__boolexpr415;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr415 = FALSE ;
  else {
  mu__boolexpr415 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr415)) mu__boolexpr414 = FALSE ;
  else {
  mu__boolexpr414 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr414)) mu__boolexpr413 = FALSE ;
  else {
  mu__boolexpr413 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr413)) mu__boolexpr412 = FALSE ;
  else {
  mu__boolexpr412 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr412)) mu__boolexpr411 = FALSE ;
  else {
  mu__boolexpr411 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr411)) mu__boolexpr410 = FALSE ;
  else {
  mu__boolexpr410 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr410)) mu__boolexpr409 = FALSE ;
  else {
  mu__boolexpr409 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr409)) mu__boolexpr408 = FALSE ;
  else {
  mu__boolexpr408 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr408)) mu__boolexpr407 = FALSE ;
  else {
  mu__boolexpr407 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr407)) mu__boolexpr406 = FALSE ;
  else {
  mu__boolexpr406 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr406)) mu__boolexpr405 = FALSE ;
  else {
  mu__boolexpr405 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr405)) mu__boolexpr404 = FALSE ;
  else {
  mu__boolexpr404 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr404)) mu__boolexpr403 = FALSE ;
  else {
  mu__boolexpr403 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr403)) mu__boolexpr402 = FALSE ;
  else {
  mu__boolexpr402 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr402)) mu__boolexpr401 = FALSE ;
  else {
  mu__boolexpr401 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr401)) mu__boolexpr400 = FALSE ;
  else {
  mu__boolexpr400 = ((mu_n4) != (mu_n5)) ; 
}
	      if (mu__boolexpr400) {
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
    r = what_rule - 7424;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_164 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_163 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_162 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_161 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_160 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
mu_ProcessRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
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
    static mu__subrange_159 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_158 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_157 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_156 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_155 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_154 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request + Process fwd_response + Process fwd_response, n6:%s, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n6.Name(), mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_159 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_158 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_157 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_156 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_155 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_154 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr416;
bool mu__boolexpr417;
bool mu__boolexpr418;
bool mu__boolexpr419;
bool mu__boolexpr420;
bool mu__boolexpr421;
bool mu__boolexpr422;
bool mu__boolexpr423;
bool mu__boolexpr424;
bool mu__boolexpr425;
bool mu__boolexpr426;
bool mu__boolexpr427;
bool mu__boolexpr428;
bool mu__boolexpr429;
bool mu__boolexpr430;
bool mu__boolexpr431;
bool mu__boolexpr432;
bool mu__boolexpr433;
bool mu__boolexpr434;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr434 = FALSE ;
  else {
  mu__boolexpr434 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr434)) mu__boolexpr433 = FALSE ;
  else {
  mu__boolexpr433 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr433)) mu__boolexpr432 = FALSE ;
  else {
  mu__boolexpr432 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr432)) mu__boolexpr431 = FALSE ;
  else {
  mu__boolexpr431 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr431)) mu__boolexpr430 = FALSE ;
  else {
  mu__boolexpr430 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr430)) mu__boolexpr429 = FALSE ;
  else {
  mu__boolexpr429 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr429)) mu__boolexpr428 = FALSE ;
  else {
  mu__boolexpr428 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr428)) mu__boolexpr427 = FALSE ;
  else {
  mu__boolexpr427 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr427)) mu__boolexpr426 = FALSE ;
  else {
  mu__boolexpr426 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr426)) mu__boolexpr425 = FALSE ;
  else {
  mu__boolexpr425 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr425)) mu__boolexpr424 = FALSE ;
  else {
  mu__boolexpr424 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr424)) mu__boolexpr423 = FALSE ;
  else {
  mu__boolexpr423 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr423)) mu__boolexpr422 = FALSE ;
  else {
  mu__boolexpr422 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr422)) mu__boolexpr421 = FALSE ;
  else {
  mu__boolexpr421 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr421)) mu__boolexpr420 = FALSE ;
  else {
  mu__boolexpr420 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr420)) mu__boolexpr419 = FALSE ;
  else {
  mu__boolexpr419 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr419)) mu__boolexpr418 = FALSE ;
  else {
  mu__boolexpr418 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr418)) mu__boolexpr417 = FALSE ;
  else {
  mu__boolexpr417 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr417)) mu__boolexpr416 = FALSE ;
  else {
  mu__boolexpr416 = ((mu_n5) != (mu_n6)) ; 
}
    return mu__boolexpr416;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8448;
    static mu__subrange_159 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_158 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_157 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_156 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_155 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_154 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 12544 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr435;
bool mu__boolexpr436;
bool mu__boolexpr437;
bool mu__boolexpr438;
bool mu__boolexpr439;
bool mu__boolexpr440;
bool mu__boolexpr441;
bool mu__boolexpr442;
bool mu__boolexpr443;
bool mu__boolexpr444;
bool mu__boolexpr445;
bool mu__boolexpr446;
bool mu__boolexpr447;
bool mu__boolexpr448;
bool mu__boolexpr449;
bool mu__boolexpr450;
bool mu__boolexpr451;
bool mu__boolexpr452;
bool mu__boolexpr453;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr453 = FALSE ;
  else {
  mu__boolexpr453 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr453)) mu__boolexpr452 = FALSE ;
  else {
  mu__boolexpr452 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr452)) mu__boolexpr451 = FALSE ;
  else {
  mu__boolexpr451 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr451)) mu__boolexpr450 = FALSE ;
  else {
  mu__boolexpr450 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr450)) mu__boolexpr449 = FALSE ;
  else {
  mu__boolexpr449 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr449)) mu__boolexpr448 = FALSE ;
  else {
  mu__boolexpr448 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr448)) mu__boolexpr447 = FALSE ;
  else {
  mu__boolexpr447 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr447)) mu__boolexpr446 = FALSE ;
  else {
  mu__boolexpr446 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr446)) mu__boolexpr445 = FALSE ;
  else {
  mu__boolexpr445 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr445)) mu__boolexpr444 = FALSE ;
  else {
  mu__boolexpr444 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr444)) mu__boolexpr443 = FALSE ;
  else {
  mu__boolexpr443 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr443)) mu__boolexpr442 = FALSE ;
  else {
  mu__boolexpr442 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr442)) mu__boolexpr441 = FALSE ;
  else {
  mu__boolexpr441 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr441)) mu__boolexpr440 = FALSE ;
  else {
  mu__boolexpr440 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr440)) mu__boolexpr439 = FALSE ;
  else {
  mu__boolexpr439 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr439)) mu__boolexpr438 = FALSE ;
  else {
  mu__boolexpr438 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr438)) mu__boolexpr437 = FALSE ;
  else {
  mu__boolexpr437 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr437)) mu__boolexpr436 = FALSE ;
  else {
  mu__boolexpr436 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr436)) mu__boolexpr435 = FALSE ;
  else {
  mu__boolexpr435 = ((mu_n5) != (mu_n6)) ; 
}
	      if (mu__boolexpr435) {
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
    r = what_rule - 8448;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_159 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_158 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_157 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_156 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_155 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_154 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdResponse ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
mu_ProcessFwdResponse ( (int)mu_n6, mu_EntryPath[mu_n6], mu_ExitPath[mu_n6] );
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
    static mu__subrange_153 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_152 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_151 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_150 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_149 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_148 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request + Process fwd_request + Process fwd_response, n6:%s, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n6.Name(), mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_153 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_152 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_151 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_150 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_149 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_148 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr454;
bool mu__boolexpr455;
bool mu__boolexpr456;
bool mu__boolexpr457;
bool mu__boolexpr458;
bool mu__boolexpr459;
bool mu__boolexpr460;
bool mu__boolexpr461;
bool mu__boolexpr462;
bool mu__boolexpr463;
bool mu__boolexpr464;
bool mu__boolexpr465;
bool mu__boolexpr466;
bool mu__boolexpr467;
bool mu__boolexpr468;
bool mu__boolexpr469;
bool mu__boolexpr470;
bool mu__boolexpr471;
bool mu__boolexpr472;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr472 = FALSE ;
  else {
  mu__boolexpr472 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr472)) mu__boolexpr471 = FALSE ;
  else {
  mu__boolexpr471 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr471)) mu__boolexpr470 = FALSE ;
  else {
  mu__boolexpr470 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr470)) mu__boolexpr469 = FALSE ;
  else {
  mu__boolexpr469 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr469)) mu__boolexpr468 = FALSE ;
  else {
  mu__boolexpr468 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr468)) mu__boolexpr467 = FALSE ;
  else {
  mu__boolexpr467 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr467)) mu__boolexpr466 = FALSE ;
  else {
  mu__boolexpr466 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr466)) mu__boolexpr465 = FALSE ;
  else {
  mu__boolexpr465 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr465)) mu__boolexpr464 = FALSE ;
  else {
  mu__boolexpr464 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr464)) mu__boolexpr463 = FALSE ;
  else {
  mu__boolexpr463 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr463)) mu__boolexpr462 = FALSE ;
  else {
  mu__boolexpr462 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr462)) mu__boolexpr461 = FALSE ;
  else {
  mu__boolexpr461 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr461)) mu__boolexpr460 = FALSE ;
  else {
  mu__boolexpr460 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr460)) mu__boolexpr459 = FALSE ;
  else {
  mu__boolexpr459 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr459)) mu__boolexpr458 = FALSE ;
  else {
  mu__boolexpr458 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr458)) mu__boolexpr457 = FALSE ;
  else {
  mu__boolexpr457 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr457)) mu__boolexpr456 = FALSE ;
  else {
  mu__boolexpr456 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr456)) mu__boolexpr455 = FALSE ;
  else {
  mu__boolexpr455 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr455)) mu__boolexpr454 = FALSE ;
  else {
  mu__boolexpr454 = ((mu_n5) != (mu_n6)) ; 
}
    return mu__boolexpr454;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12544;
    static mu__subrange_153 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_152 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_151 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_150 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_149 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_148 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 16640 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr473;
bool mu__boolexpr474;
bool mu__boolexpr475;
bool mu__boolexpr476;
bool mu__boolexpr477;
bool mu__boolexpr478;
bool mu__boolexpr479;
bool mu__boolexpr480;
bool mu__boolexpr481;
bool mu__boolexpr482;
bool mu__boolexpr483;
bool mu__boolexpr484;
bool mu__boolexpr485;
bool mu__boolexpr486;
bool mu__boolexpr487;
bool mu__boolexpr488;
bool mu__boolexpr489;
bool mu__boolexpr490;
bool mu__boolexpr491;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr491 = FALSE ;
  else {
  mu__boolexpr491 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr491)) mu__boolexpr490 = FALSE ;
  else {
  mu__boolexpr490 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr490)) mu__boolexpr489 = FALSE ;
  else {
  mu__boolexpr489 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr489)) mu__boolexpr488 = FALSE ;
  else {
  mu__boolexpr488 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr488)) mu__boolexpr487 = FALSE ;
  else {
  mu__boolexpr487 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr487)) mu__boolexpr486 = FALSE ;
  else {
  mu__boolexpr486 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr486)) mu__boolexpr485 = FALSE ;
  else {
  mu__boolexpr485 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr485)) mu__boolexpr484 = FALSE ;
  else {
  mu__boolexpr484 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr484)) mu__boolexpr483 = FALSE ;
  else {
  mu__boolexpr483 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr483)) mu__boolexpr482 = FALSE ;
  else {
  mu__boolexpr482 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr482)) mu__boolexpr481 = FALSE ;
  else {
  mu__boolexpr481 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr481)) mu__boolexpr480 = FALSE ;
  else {
  mu__boolexpr480 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr480)) mu__boolexpr479 = FALSE ;
  else {
  mu__boolexpr479 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr479)) mu__boolexpr478 = FALSE ;
  else {
  mu__boolexpr478 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr478)) mu__boolexpr477 = FALSE ;
  else {
  mu__boolexpr477 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr477)) mu__boolexpr476 = FALSE ;
  else {
  mu__boolexpr476 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr476)) mu__boolexpr475 = FALSE ;
  else {
  mu__boolexpr475 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr475)) mu__boolexpr474 = FALSE ;
  else {
  mu__boolexpr474 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr474)) mu__boolexpr473 = FALSE ;
  else {
  mu__boolexpr473 = ((mu_n5) != (mu_n6)) ; 
}
	      if (mu__boolexpr473) {
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
    r = what_rule - 12544;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_153 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_152 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_151 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_150 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_149 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_148 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
mu_ProcessFwdResponse ( (int)mu_n6, mu_EntryPath[mu_n6], mu_ExitPath[mu_n6] );
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
    static mu__subrange_147 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_146 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_145 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_144 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_143 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_142 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request + Process fwd_request + Process fwd_request, n6:%s, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n6.Name(), mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_147 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_146 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_145 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_144 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_143 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_142 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr492;
bool mu__boolexpr493;
bool mu__boolexpr494;
bool mu__boolexpr495;
bool mu__boolexpr496;
bool mu__boolexpr497;
bool mu__boolexpr498;
bool mu__boolexpr499;
bool mu__boolexpr500;
bool mu__boolexpr501;
bool mu__boolexpr502;
bool mu__boolexpr503;
bool mu__boolexpr504;
bool mu__boolexpr505;
bool mu__boolexpr506;
bool mu__boolexpr507;
bool mu__boolexpr508;
bool mu__boolexpr509;
bool mu__boolexpr510;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr510 = FALSE ;
  else {
  mu__boolexpr510 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr510)) mu__boolexpr509 = FALSE ;
  else {
  mu__boolexpr509 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr509)) mu__boolexpr508 = FALSE ;
  else {
  mu__boolexpr508 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr508)) mu__boolexpr507 = FALSE ;
  else {
  mu__boolexpr507 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr507)) mu__boolexpr506 = FALSE ;
  else {
  mu__boolexpr506 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr506)) mu__boolexpr505 = FALSE ;
  else {
  mu__boolexpr505 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr505)) mu__boolexpr504 = FALSE ;
  else {
  mu__boolexpr504 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr504)) mu__boolexpr503 = FALSE ;
  else {
  mu__boolexpr503 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr503)) mu__boolexpr502 = FALSE ;
  else {
  mu__boolexpr502 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr502)) mu__boolexpr501 = FALSE ;
  else {
  mu__boolexpr501 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr501)) mu__boolexpr500 = FALSE ;
  else {
  mu__boolexpr500 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr500)) mu__boolexpr499 = FALSE ;
  else {
  mu__boolexpr499 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr499)) mu__boolexpr498 = FALSE ;
  else {
  mu__boolexpr498 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr498)) mu__boolexpr497 = FALSE ;
  else {
  mu__boolexpr497 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr497)) mu__boolexpr496 = FALSE ;
  else {
  mu__boolexpr496 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr496)) mu__boolexpr495 = FALSE ;
  else {
  mu__boolexpr495 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr495)) mu__boolexpr494 = FALSE ;
  else {
  mu__boolexpr494 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr494)) mu__boolexpr493 = FALSE ;
  else {
  mu__boolexpr493 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr493)) mu__boolexpr492 = FALSE ;
  else {
  mu__boolexpr492 = ((mu_n5) != (mu_n6)) ; 
}
    return mu__boolexpr492;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16640;
    static mu__subrange_147 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_146 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_145 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_144 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_143 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_142 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20736 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr511;
bool mu__boolexpr512;
bool mu__boolexpr513;
bool mu__boolexpr514;
bool mu__boolexpr515;
bool mu__boolexpr516;
bool mu__boolexpr517;
bool mu__boolexpr518;
bool mu__boolexpr519;
bool mu__boolexpr520;
bool mu__boolexpr521;
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
  mu__boolexpr529 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr529)) mu__boolexpr528 = FALSE ;
  else {
  mu__boolexpr528 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr528)) mu__boolexpr527 = FALSE ;
  else {
  mu__boolexpr527 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr527)) mu__boolexpr526 = FALSE ;
  else {
  mu__boolexpr526 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr526)) mu__boolexpr525 = FALSE ;
  else {
  mu__boolexpr525 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr525)) mu__boolexpr524 = FALSE ;
  else {
  mu__boolexpr524 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr524)) mu__boolexpr523 = FALSE ;
  else {
  mu__boolexpr523 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr523)) mu__boolexpr522 = FALSE ;
  else {
  mu__boolexpr522 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr522)) mu__boolexpr521 = FALSE ;
  else {
  mu__boolexpr521 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr521)) mu__boolexpr520 = FALSE ;
  else {
  mu__boolexpr520 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr520)) mu__boolexpr519 = FALSE ;
  else {
  mu__boolexpr519 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr519)) mu__boolexpr518 = FALSE ;
  else {
  mu__boolexpr518 = ((mu_IncomingQueue[mu_n6][mu_EntryPath[mu_n6]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr518)) mu__boolexpr517 = FALSE ;
  else {
  mu__boolexpr517 = ((mu_TailPointers[mu_ExitPath[mu_n6]][mu_n6]) < (mu_BufferSpace)) ; 
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
  mu__boolexpr514 = ((mu_n1) != (mu_n6)) ; 
}
  if (!(mu__boolexpr514)) mu__boolexpr513 = FALSE ;
  else {
  mu__boolexpr513 = ((mu_n3) != (mu_n5)) ; 
}
  if (!(mu__boolexpr513)) mu__boolexpr512 = FALSE ;
  else {
  mu__boolexpr512 = ((mu_n3) != (mu_n6)) ; 
}
  if (!(mu__boolexpr512)) mu__boolexpr511 = FALSE ;
  else {
  mu__boolexpr511 = ((mu_n5) != (mu_n6)) ; 
}
	      if (mu__boolexpr511) {
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
    r = what_rule - 16640;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_147 mu_n6;
    mu_n6.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_146 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_145 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_144 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_143 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_142 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
mu_ProcessFwdRequest ( (int)mu_n6, mu_EntryPath[mu_n6], mu_ExitPath[mu_n6] );
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
    static mu__subrange_141 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_140 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_139 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_141 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_140 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_139 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr530;
bool mu__boolexpr531;
bool mu__boolexpr532;
bool mu__boolexpr533;
bool mu__boolexpr534;
bool mu__boolexpr535;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr535 = FALSE ;
  else {
  mu__boolexpr535 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr535)) mu__boolexpr534 = FALSE ;
  else {
  mu__boolexpr534 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr534)) mu__boolexpr533 = FALSE ;
  else {
  mu__boolexpr533 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr533)) mu__boolexpr532 = FALSE ;
  else {
  mu__boolexpr532 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr532)) mu__boolexpr531 = FALSE ;
  else {
  mu__boolexpr531 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr531)) mu__boolexpr530 = FALSE ;
  else {
  mu__boolexpr530 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr530;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20736;
    static mu__subrange_141 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_140 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_139 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20800 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr536;
bool mu__boolexpr537;
bool mu__boolexpr538;
bool mu__boolexpr539;
bool mu__boolexpr540;
bool mu__boolexpr541;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr541 = FALSE ;
  else {
  mu__boolexpr541 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr541)) mu__boolexpr540 = FALSE ;
  else {
  mu__boolexpr540 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr540)) mu__boolexpr539 = FALSE ;
  else {
  mu__boolexpr539 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr539)) mu__boolexpr538 = FALSE ;
  else {
  mu__boolexpr538 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr538)) mu__boolexpr537 = FALSE ;
  else {
  mu__boolexpr537 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr537)) mu__boolexpr536 = FALSE ;
  else {
  mu__boolexpr536 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr536) {
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
    r = what_rule - 20736;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_141 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_140 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_139 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_138 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_137 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_136 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_138 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_137 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_136 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr542;
bool mu__boolexpr543;
bool mu__boolexpr544;
bool mu__boolexpr545;
bool mu__boolexpr546;
bool mu__boolexpr547;
bool mu__boolexpr548;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr548 = FALSE ;
  else {
  mu__boolexpr548 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr548)) mu__boolexpr547 = FALSE ;
  else {
  mu__boolexpr547 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr547)) mu__boolexpr546 = FALSE ;
  else {
  mu__boolexpr546 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr546)) mu__boolexpr545 = FALSE ;
  else {
  mu__boolexpr545 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr545)) mu__boolexpr544 = FALSE ;
  else {
  mu__boolexpr544 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr544)) mu__boolexpr543 = FALSE ;
  else {
  mu__boolexpr543 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr543)) mu__boolexpr542 = FALSE ;
  else {
  mu__boolexpr542 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr542;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20800;
    static mu__subrange_138 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_137 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_136 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20864 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr549;
bool mu__boolexpr550;
bool mu__boolexpr551;
bool mu__boolexpr552;
bool mu__boolexpr553;
bool mu__boolexpr554;
bool mu__boolexpr555;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr555 = FALSE ;
  else {
  mu__boolexpr555 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr555)) mu__boolexpr554 = FALSE ;
  else {
  mu__boolexpr554 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr554)) mu__boolexpr553 = FALSE ;
  else {
  mu__boolexpr553 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr553)) mu__boolexpr552 = FALSE ;
  else {
  mu__boolexpr552 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr552)) mu__boolexpr551 = FALSE ;
  else {
  mu__boolexpr551 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr551)) mu__boolexpr550 = FALSE ;
  else {
  mu__boolexpr550 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr550)) mu__boolexpr549 = FALSE ;
  else {
  mu__boolexpr549 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr549) {
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
    r = what_rule - 20800;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_138 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_137 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_136 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_135 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_134 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_133 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_135 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_134 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_133 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr556;
bool mu__boolexpr557;
bool mu__boolexpr558;
bool mu__boolexpr559;
bool mu__boolexpr560;
bool mu__boolexpr561;
bool mu__boolexpr562;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr562 = FALSE ;
  else {
  mu__boolexpr562 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr562)) mu__boolexpr561 = FALSE ;
  else {
  mu__boolexpr561 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr561)) mu__boolexpr560 = FALSE ;
  else {
  mu__boolexpr560 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr560)) mu__boolexpr559 = FALSE ;
  else {
  mu__boolexpr559 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr559)) mu__boolexpr558 = FALSE ;
  else {
  mu__boolexpr558 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr558)) mu__boolexpr557 = FALSE ;
  else {
  mu__boolexpr557 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr557)) mu__boolexpr556 = FALSE ;
  else {
  mu__boolexpr556 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr556;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20864;
    static mu__subrange_135 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_134 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_133 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20928 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr563;
bool mu__boolexpr564;
bool mu__boolexpr565;
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
  mu__boolexpr568 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr568)) mu__boolexpr567 = FALSE ;
  else {
  mu__boolexpr567 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr567)) mu__boolexpr566 = FALSE ;
  else {
  mu__boolexpr566 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr566)) mu__boolexpr565 = FALSE ;
  else {
  mu__boolexpr565 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr565)) mu__boolexpr564 = FALSE ;
  else {
  mu__boolexpr564 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr564)) mu__boolexpr563 = FALSE ;
  else {
  mu__boolexpr563 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr563) {
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
    r = what_rule - 20864;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_135 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_134 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_133 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_132 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_131 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_130 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_132 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_131 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_130 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr570;
bool mu__boolexpr571;
bool mu__boolexpr572;
bool mu__boolexpr573;
bool mu__boolexpr574;
bool mu__boolexpr575;
bool mu__boolexpr576;
bool mu__boolexpr577;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr577 = FALSE ;
  else {
  mu__boolexpr577 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr577)) mu__boolexpr576 = FALSE ;
  else {
  mu__boolexpr576 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr576)) mu__boolexpr575 = FALSE ;
  else {
  mu__boolexpr575 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr575)) mu__boolexpr574 = FALSE ;
  else {
  mu__boolexpr574 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr574)) mu__boolexpr573 = FALSE ;
  else {
  mu__boolexpr573 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr573)) mu__boolexpr572 = FALSE ;
  else {
  mu__boolexpr572 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr572)) mu__boolexpr571 = FALSE ;
  else {
  mu__boolexpr571 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr571)) mu__boolexpr570 = FALSE ;
  else {
  mu__boolexpr570 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr570;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20928;
    static mu__subrange_132 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_131 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_130 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 20992 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr578;
bool mu__boolexpr579;
bool mu__boolexpr580;
bool mu__boolexpr581;
bool mu__boolexpr582;
bool mu__boolexpr583;
bool mu__boolexpr584;
bool mu__boolexpr585;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr585 = FALSE ;
  else {
  mu__boolexpr585 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr585)) mu__boolexpr584 = FALSE ;
  else {
  mu__boolexpr584 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr584)) mu__boolexpr583 = FALSE ;
  else {
  mu__boolexpr583 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr583)) mu__boolexpr582 = FALSE ;
  else {
  mu__boolexpr582 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr582)) mu__boolexpr581 = FALSE ;
  else {
  mu__boolexpr581 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr581)) mu__boolexpr580 = FALSE ;
  else {
  mu__boolexpr580 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr580)) mu__boolexpr579 = FALSE ;
  else {
  mu__boolexpr579 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr579)) mu__boolexpr578 = FALSE ;
  else {
  mu__boolexpr578 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr578) {
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
    r = what_rule - 20928;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_132 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_131 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_130 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr586;
bool mu__boolexpr587;
bool mu__boolexpr588;
bool mu__boolexpr589;
bool mu__boolexpr590;
bool mu__boolexpr591;
bool mu__boolexpr592;
bool mu__boolexpr593;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr593 = FALSE ;
  else {
  mu__boolexpr593 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr593)) mu__boolexpr592 = FALSE ;
  else {
  mu__boolexpr592 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr592)) mu__boolexpr591 = FALSE ;
  else {
  mu__boolexpr591 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr591)) mu__boolexpr590 = FALSE ;
  else {
  mu__boolexpr590 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr590)) mu__boolexpr589 = FALSE ;
  else {
  mu__boolexpr589 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr589)) mu__boolexpr588 = FALSE ;
  else {
  mu__boolexpr588 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr588)) mu__boolexpr587 = FALSE ;
  else {
  mu__boolexpr587 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr587)) mu__boolexpr586 = FALSE ;
  else {
  mu__boolexpr586 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr586;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20992;
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21056 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr594;
bool mu__boolexpr595;
bool mu__boolexpr596;
bool mu__boolexpr597;
bool mu__boolexpr598;
bool mu__boolexpr599;
bool mu__boolexpr600;
bool mu__boolexpr601;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr601 = FALSE ;
  else {
  mu__boolexpr601 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr601)) mu__boolexpr600 = FALSE ;
  else {
  mu__boolexpr600 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr600)) mu__boolexpr599 = FALSE ;
  else {
  mu__boolexpr599 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr599)) mu__boolexpr598 = FALSE ;
  else {
  mu__boolexpr598 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr598)) mu__boolexpr597 = FALSE ;
  else {
  mu__boolexpr597 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr597)) mu__boolexpr596 = FALSE ;
  else {
  mu__boolexpr596 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr596)) mu__boolexpr595 = FALSE ;
  else {
  mu__boolexpr595 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr595)) mu__boolexpr594 = FALSE ;
  else {
  mu__boolexpr594 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr594) {
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
    r = what_rule - 20992;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_129 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_128 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_127 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_126 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_125 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_124 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_126 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_125 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_124 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr602;
bool mu__boolexpr603;
bool mu__boolexpr604;
bool mu__boolexpr605;
bool mu__boolexpr606;
bool mu__boolexpr607;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr607 = FALSE ;
  else {
  mu__boolexpr607 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr607)) mu__boolexpr606 = FALSE ;
  else {
  mu__boolexpr606 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr606)) mu__boolexpr605 = FALSE ;
  else {
  mu__boolexpr605 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr605)) mu__boolexpr604 = FALSE ;
  else {
  mu__boolexpr604 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr604)) mu__boolexpr603 = FALSE ;
  else {
  mu__boolexpr603 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr603)) mu__boolexpr602 = FALSE ;
  else {
  mu__boolexpr602 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr602;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21056;
    static mu__subrange_126 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_125 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_124 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21120 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr608;
bool mu__boolexpr609;
bool mu__boolexpr610;
bool mu__boolexpr611;
bool mu__boolexpr612;
bool mu__boolexpr613;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr613 = FALSE ;
  else {
  mu__boolexpr613 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr613)) mu__boolexpr612 = FALSE ;
  else {
  mu__boolexpr612 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr612)) mu__boolexpr611 = FALSE ;
  else {
  mu__boolexpr611 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr611)) mu__boolexpr610 = FALSE ;
  else {
  mu__boolexpr610 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr610)) mu__boolexpr609 = FALSE ;
  else {
  mu__boolexpr609 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr609)) mu__boolexpr608 = FALSE ;
  else {
  mu__boolexpr608 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr608) {
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
    r = what_rule - 21056;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_126 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_125 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_124 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_123 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_122 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_121 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_123 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_122 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_121 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr614;
bool mu__boolexpr615;
bool mu__boolexpr616;
bool mu__boolexpr617;
bool mu__boolexpr618;
bool mu__boolexpr619;
bool mu__boolexpr620;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr620 = FALSE ;
  else {
  mu__boolexpr620 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr620)) mu__boolexpr619 = FALSE ;
  else {
  mu__boolexpr619 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr619)) mu__boolexpr618 = FALSE ;
  else {
  mu__boolexpr618 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr618)) mu__boolexpr617 = FALSE ;
  else {
  mu__boolexpr617 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr617)) mu__boolexpr616 = FALSE ;
  else {
  mu__boolexpr616 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr616)) mu__boolexpr615 = FALSE ;
  else {
  mu__boolexpr615 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr615)) mu__boolexpr614 = FALSE ;
  else {
  mu__boolexpr614 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr614;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21120;
    static mu__subrange_123 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_122 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_121 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21184 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr621;
bool mu__boolexpr622;
bool mu__boolexpr623;
bool mu__boolexpr624;
bool mu__boolexpr625;
bool mu__boolexpr626;
bool mu__boolexpr627;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr627 = FALSE ;
  else {
  mu__boolexpr627 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr627)) mu__boolexpr626 = FALSE ;
  else {
  mu__boolexpr626 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr626)) mu__boolexpr625 = FALSE ;
  else {
  mu__boolexpr625 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr625)) mu__boolexpr624 = FALSE ;
  else {
  mu__boolexpr624 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr624)) mu__boolexpr623 = FALSE ;
  else {
  mu__boolexpr623 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr623)) mu__boolexpr622 = FALSE ;
  else {
  mu__boolexpr622 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr622)) mu__boolexpr621 = FALSE ;
  else {
  mu__boolexpr621 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr621) {
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
    r = what_rule - 21120;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_123 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_122 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_121 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_120 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_119 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_118 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_120 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_119 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_118 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr628;
bool mu__boolexpr629;
bool mu__boolexpr630;
bool mu__boolexpr631;
bool mu__boolexpr632;
bool mu__boolexpr633;
bool mu__boolexpr634;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr634 = FALSE ;
  else {
  mu__boolexpr634 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr634)) mu__boolexpr633 = FALSE ;
  else {
  mu__boolexpr633 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr633)) mu__boolexpr632 = FALSE ;
  else {
  mu__boolexpr632 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr632)) mu__boolexpr631 = FALSE ;
  else {
  mu__boolexpr631 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr631)) mu__boolexpr630 = FALSE ;
  else {
  mu__boolexpr630 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr630)) mu__boolexpr629 = FALSE ;
  else {
  mu__boolexpr629 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr629)) mu__boolexpr628 = FALSE ;
  else {
  mu__boolexpr628 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr628;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21184;
    static mu__subrange_120 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_119 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_118 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21248 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr635;
bool mu__boolexpr636;
bool mu__boolexpr637;
bool mu__boolexpr638;
bool mu__boolexpr639;
bool mu__boolexpr640;
bool mu__boolexpr641;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr641 = FALSE ;
  else {
  mu__boolexpr641 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr641)) mu__boolexpr640 = FALSE ;
  else {
  mu__boolexpr640 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr640)) mu__boolexpr639 = FALSE ;
  else {
  mu__boolexpr639 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr639)) mu__boolexpr638 = FALSE ;
  else {
  mu__boolexpr638 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr638)) mu__boolexpr637 = FALSE ;
  else {
  mu__boolexpr637 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr637)) mu__boolexpr636 = FALSE ;
  else {
  mu__boolexpr636 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr636)) mu__boolexpr635 = FALSE ;
  else {
  mu__boolexpr635 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr635) {
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
    r = what_rule - 21184;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_120 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_119 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_118 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr642;
bool mu__boolexpr643;
bool mu__boolexpr644;
bool mu__boolexpr645;
bool mu__boolexpr646;
bool mu__boolexpr647;
bool mu__boolexpr648;
bool mu__boolexpr649;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr649 = FALSE ;
  else {
  mu__boolexpr649 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr649)) mu__boolexpr648 = FALSE ;
  else {
  mu__boolexpr648 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr648)) mu__boolexpr647 = FALSE ;
  else {
  mu__boolexpr647 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr647)) mu__boolexpr646 = FALSE ;
  else {
  mu__boolexpr646 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr646)) mu__boolexpr645 = FALSE ;
  else {
  mu__boolexpr645 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr645)) mu__boolexpr644 = FALSE ;
  else {
  mu__boolexpr644 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr644)) mu__boolexpr643 = FALSE ;
  else {
  mu__boolexpr643 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr643)) mu__boolexpr642 = FALSE ;
  else {
  mu__boolexpr642 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr642;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21248;
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21312 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr650;
bool mu__boolexpr651;
bool mu__boolexpr652;
bool mu__boolexpr653;
bool mu__boolexpr654;
bool mu__boolexpr655;
bool mu__boolexpr656;
bool mu__boolexpr657;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr657 = FALSE ;
  else {
  mu__boolexpr657 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr657)) mu__boolexpr656 = FALSE ;
  else {
  mu__boolexpr656 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr656)) mu__boolexpr655 = FALSE ;
  else {
  mu__boolexpr655 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr655)) mu__boolexpr654 = FALSE ;
  else {
  mu__boolexpr654 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr654)) mu__boolexpr653 = FALSE ;
  else {
  mu__boolexpr653 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr653)) mu__boolexpr652 = FALSE ;
  else {
  mu__boolexpr652 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr652)) mu__boolexpr651 = FALSE ;
  else {
  mu__boolexpr651 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr651)) mu__boolexpr650 = FALSE ;
  else {
  mu__boolexpr650 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr650) {
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
    r = what_rule - 21248;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_117 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_116 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_115 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_114 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_113 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_112 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_114 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_113 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_112 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr658;
bool mu__boolexpr659;
bool mu__boolexpr660;
bool mu__boolexpr661;
bool mu__boolexpr662;
bool mu__boolexpr663;
bool mu__boolexpr664;
bool mu__boolexpr665;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr665 = FALSE ;
  else {
  mu__boolexpr665 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr665)) mu__boolexpr664 = FALSE ;
  else {
  mu__boolexpr664 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr664)) mu__boolexpr663 = FALSE ;
  else {
  mu__boolexpr663 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr663)) mu__boolexpr662 = FALSE ;
  else {
  mu__boolexpr662 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr662)) mu__boolexpr661 = FALSE ;
  else {
  mu__boolexpr661 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr661)) mu__boolexpr660 = FALSE ;
  else {
  mu__boolexpr660 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr660)) mu__boolexpr659 = FALSE ;
  else {
  mu__boolexpr659 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr659)) mu__boolexpr658 = FALSE ;
  else {
  mu__boolexpr658 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr658;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21312;
    static mu__subrange_114 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_113 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_112 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21376 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr666;
bool mu__boolexpr667;
bool mu__boolexpr668;
bool mu__boolexpr669;
bool mu__boolexpr670;
bool mu__boolexpr671;
bool mu__boolexpr672;
bool mu__boolexpr673;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr673 = FALSE ;
  else {
  mu__boolexpr673 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr673)) mu__boolexpr672 = FALSE ;
  else {
  mu__boolexpr672 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr672)) mu__boolexpr671 = FALSE ;
  else {
  mu__boolexpr671 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr671)) mu__boolexpr670 = FALSE ;
  else {
  mu__boolexpr670 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr670)) mu__boolexpr669 = FALSE ;
  else {
  mu__boolexpr669 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr669)) mu__boolexpr668 = FALSE ;
  else {
  mu__boolexpr668 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr668)) mu__boolexpr667 = FALSE ;
  else {
  mu__boolexpr667 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr667)) mu__boolexpr666 = FALSE ;
  else {
  mu__boolexpr666 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr666) {
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
    r = what_rule - 21312;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_114 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_113 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_112 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_111 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_110 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_109 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_111 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_110 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_109 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr674;
bool mu__boolexpr675;
bool mu__boolexpr676;
bool mu__boolexpr677;
bool mu__boolexpr678;
bool mu__boolexpr679;
bool mu__boolexpr680;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr680 = FALSE ;
  else {
  mu__boolexpr680 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr680)) mu__boolexpr679 = FALSE ;
  else {
  mu__boolexpr679 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr679)) mu__boolexpr678 = FALSE ;
  else {
  mu__boolexpr678 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr678)) mu__boolexpr677 = FALSE ;
  else {
  mu__boolexpr677 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr677)) mu__boolexpr676 = FALSE ;
  else {
  mu__boolexpr676 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr676)) mu__boolexpr675 = FALSE ;
  else {
  mu__boolexpr675 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr675)) mu__boolexpr674 = FALSE ;
  else {
  mu__boolexpr674 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr674;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21376;
    static mu__subrange_111 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_110 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_109 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21440 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr681;
bool mu__boolexpr682;
bool mu__boolexpr683;
bool mu__boolexpr684;
bool mu__boolexpr685;
bool mu__boolexpr686;
bool mu__boolexpr687;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr687 = FALSE ;
  else {
  mu__boolexpr687 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr687)) mu__boolexpr686 = FALSE ;
  else {
  mu__boolexpr686 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr686)) mu__boolexpr685 = FALSE ;
  else {
  mu__boolexpr685 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr685)) mu__boolexpr684 = FALSE ;
  else {
  mu__boolexpr684 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr684)) mu__boolexpr683 = FALSE ;
  else {
  mu__boolexpr683 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr683)) mu__boolexpr682 = FALSE ;
  else {
  mu__boolexpr682 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr682)) mu__boolexpr681 = FALSE ;
  else {
  mu__boolexpr681 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr681) {
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
    r = what_rule - 21376;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_111 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_110 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_109 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_108 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_107 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_106 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_108 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_107 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_106 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr688;
bool mu__boolexpr689;
bool mu__boolexpr690;
bool mu__boolexpr691;
bool mu__boolexpr692;
bool mu__boolexpr693;
bool mu__boolexpr694;
bool mu__boolexpr695;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr695 = FALSE ;
  else {
  mu__boolexpr695 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr695)) mu__boolexpr694 = FALSE ;
  else {
  mu__boolexpr694 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr694)) mu__boolexpr693 = FALSE ;
  else {
  mu__boolexpr693 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr693)) mu__boolexpr692 = FALSE ;
  else {
  mu__boolexpr692 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr692)) mu__boolexpr691 = FALSE ;
  else {
  mu__boolexpr691 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr691)) mu__boolexpr690 = FALSE ;
  else {
  mu__boolexpr690 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr690)) mu__boolexpr689 = FALSE ;
  else {
  mu__boolexpr689 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr689)) mu__boolexpr688 = FALSE ;
  else {
  mu__boolexpr688 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr688;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21440;
    static mu__subrange_108 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_107 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_106 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21504 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr696;
bool mu__boolexpr697;
bool mu__boolexpr698;
bool mu__boolexpr699;
bool mu__boolexpr700;
bool mu__boolexpr701;
bool mu__boolexpr702;
bool mu__boolexpr703;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr703 = FALSE ;
  else {
  mu__boolexpr703 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr703)) mu__boolexpr702 = FALSE ;
  else {
  mu__boolexpr702 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr702)) mu__boolexpr701 = FALSE ;
  else {
  mu__boolexpr701 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr701)) mu__boolexpr700 = FALSE ;
  else {
  mu__boolexpr700 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr700)) mu__boolexpr699 = FALSE ;
  else {
  mu__boolexpr699 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr699)) mu__boolexpr698 = FALSE ;
  else {
  mu__boolexpr698 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr698)) mu__boolexpr697 = FALSE ;
  else {
  mu__boolexpr697 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr697)) mu__boolexpr696 = FALSE ;
  else {
  mu__boolexpr696 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr696) {
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
    r = what_rule - 21440;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_108 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_107 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_106 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_105 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_104 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_103 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_102 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_response + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_105 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_104 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_103 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_102 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr704;
bool mu__boolexpr705;
bool mu__boolexpr706;
bool mu__boolexpr707;
bool mu__boolexpr708;
bool mu__boolexpr709;
bool mu__boolexpr710;
bool mu__boolexpr711;
bool mu__boolexpr712;
bool mu__boolexpr713;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr713 = FALSE ;
  else {
  mu__boolexpr713 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr713)) mu__boolexpr712 = FALSE ;
  else {
  mu__boolexpr712 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr712)) mu__boolexpr711 = FALSE ;
  else {
  mu__boolexpr711 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr711)) mu__boolexpr710 = FALSE ;
  else {
  mu__boolexpr710 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr710)) mu__boolexpr709 = FALSE ;
  else {
  mu__boolexpr709 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr709)) mu__boolexpr708 = FALSE ;
  else {
  mu__boolexpr708 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr708)) mu__boolexpr707 = FALSE ;
  else {
  mu__boolexpr707 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr707)) mu__boolexpr706 = FALSE ;
  else {
  mu__boolexpr706 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr706)) mu__boolexpr705 = FALSE ;
  else {
  mu__boolexpr705 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr705)) mu__boolexpr704 = FALSE ;
  else {
  mu__boolexpr704 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr704;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21504;
    static mu__subrange_105 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_104 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_103 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_102 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 21760 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr714;
bool mu__boolexpr715;
bool mu__boolexpr716;
bool mu__boolexpr717;
bool mu__boolexpr718;
bool mu__boolexpr719;
bool mu__boolexpr720;
bool mu__boolexpr721;
bool mu__boolexpr722;
bool mu__boolexpr723;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr723 = FALSE ;
  else {
  mu__boolexpr723 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr723)) mu__boolexpr722 = FALSE ;
  else {
  mu__boolexpr722 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr722)) mu__boolexpr721 = FALSE ;
  else {
  mu__boolexpr721 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr721)) mu__boolexpr720 = FALSE ;
  else {
  mu__boolexpr720 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr720)) mu__boolexpr719 = FALSE ;
  else {
  mu__boolexpr719 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr719)) mu__boolexpr718 = FALSE ;
  else {
  mu__boolexpr718 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr718)) mu__boolexpr717 = FALSE ;
  else {
  mu__boolexpr717 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr717)) mu__boolexpr716 = FALSE ;
  else {
  mu__boolexpr716 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr716)) mu__boolexpr715 = FALSE ;
  else {
  mu__boolexpr715 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr715)) mu__boolexpr714 = FALSE ;
  else {
  mu__boolexpr714 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr714) {
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
    r = what_rule - 21504;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_105 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_104 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_103 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_102 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_101 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_100 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_99 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_98 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_response + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_101 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_100 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_99 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_98 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr724;
bool mu__boolexpr725;
bool mu__boolexpr726;
bool mu__boolexpr727;
bool mu__boolexpr728;
bool mu__boolexpr729;
bool mu__boolexpr730;
bool mu__boolexpr731;
bool mu__boolexpr732;
bool mu__boolexpr733;
bool mu__boolexpr734;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr734 = FALSE ;
  else {
  mu__boolexpr734 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr734)) mu__boolexpr733 = FALSE ;
  else {
  mu__boolexpr733 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr733)) mu__boolexpr732 = FALSE ;
  else {
  mu__boolexpr732 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr732)) mu__boolexpr731 = FALSE ;
  else {
  mu__boolexpr731 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr731)) mu__boolexpr730 = FALSE ;
  else {
  mu__boolexpr730 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr730)) mu__boolexpr729 = FALSE ;
  else {
  mu__boolexpr729 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr729)) mu__boolexpr728 = FALSE ;
  else {
  mu__boolexpr728 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr728)) mu__boolexpr727 = FALSE ;
  else {
  mu__boolexpr727 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr727)) mu__boolexpr726 = FALSE ;
  else {
  mu__boolexpr726 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr726)) mu__boolexpr725 = FALSE ;
  else {
  mu__boolexpr725 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr725)) mu__boolexpr724 = FALSE ;
  else {
  mu__boolexpr724 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr724;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21760;
    static mu__subrange_101 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_100 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_99 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_98 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 22016 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr735;
bool mu__boolexpr736;
bool mu__boolexpr737;
bool mu__boolexpr738;
bool mu__boolexpr739;
bool mu__boolexpr740;
bool mu__boolexpr741;
bool mu__boolexpr742;
bool mu__boolexpr743;
bool mu__boolexpr744;
bool mu__boolexpr745;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr745 = FALSE ;
  else {
  mu__boolexpr745 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr745)) mu__boolexpr744 = FALSE ;
  else {
  mu__boolexpr744 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr744)) mu__boolexpr743 = FALSE ;
  else {
  mu__boolexpr743 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr743)) mu__boolexpr742 = FALSE ;
  else {
  mu__boolexpr742 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr742)) mu__boolexpr741 = FALSE ;
  else {
  mu__boolexpr741 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr741)) mu__boolexpr740 = FALSE ;
  else {
  mu__boolexpr740 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr740)) mu__boolexpr739 = FALSE ;
  else {
  mu__boolexpr739 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr739)) mu__boolexpr738 = FALSE ;
  else {
  mu__boolexpr738 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr738)) mu__boolexpr737 = FALSE ;
  else {
  mu__boolexpr737 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr737)) mu__boolexpr736 = FALSE ;
  else {
  mu__boolexpr736 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr736)) mu__boolexpr735 = FALSE ;
  else {
  mu__boolexpr735 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr735) {
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
    r = what_rule - 21760;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_101 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_100 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_99 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_98 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_97 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_96 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_95 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_94 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process request + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_97 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_96 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_95 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_94 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr746;
bool mu__boolexpr747;
bool mu__boolexpr748;
bool mu__boolexpr749;
bool mu__boolexpr750;
bool mu__boolexpr751;
bool mu__boolexpr752;
bool mu__boolexpr753;
bool mu__boolexpr754;
bool mu__boolexpr755;
bool mu__boolexpr756;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr756 = FALSE ;
  else {
  mu__boolexpr756 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr756)) mu__boolexpr755 = FALSE ;
  else {
  mu__boolexpr755 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr755)) mu__boolexpr754 = FALSE ;
  else {
  mu__boolexpr754 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr754)) mu__boolexpr753 = FALSE ;
  else {
  mu__boolexpr753 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr753)) mu__boolexpr752 = FALSE ;
  else {
  mu__boolexpr752 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr752)) mu__boolexpr751 = FALSE ;
  else {
  mu__boolexpr751 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr751)) mu__boolexpr750 = FALSE ;
  else {
  mu__boolexpr750 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr750)) mu__boolexpr749 = FALSE ;
  else {
  mu__boolexpr749 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr749)) mu__boolexpr748 = FALSE ;
  else {
  mu__boolexpr748 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr748)) mu__boolexpr747 = FALSE ;
  else {
  mu__boolexpr747 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr747)) mu__boolexpr746 = FALSE ;
  else {
  mu__boolexpr746 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr746;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 22016;
    static mu__subrange_97 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_96 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_95 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_94 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 22272 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr757;
bool mu__boolexpr758;
bool mu__boolexpr759;
bool mu__boolexpr760;
bool mu__boolexpr761;
bool mu__boolexpr762;
bool mu__boolexpr763;
bool mu__boolexpr764;
bool mu__boolexpr765;
bool mu__boolexpr766;
bool mu__boolexpr767;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr767 = FALSE ;
  else {
  mu__boolexpr767 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr767)) mu__boolexpr766 = FALSE ;
  else {
  mu__boolexpr766 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr766)) mu__boolexpr765 = FALSE ;
  else {
  mu__boolexpr765 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr765)) mu__boolexpr764 = FALSE ;
  else {
  mu__boolexpr764 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr764)) mu__boolexpr763 = FALSE ;
  else {
  mu__boolexpr763 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr763)) mu__boolexpr762 = FALSE ;
  else {
  mu__boolexpr762 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr762)) mu__boolexpr761 = FALSE ;
  else {
  mu__boolexpr761 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr761)) mu__boolexpr760 = FALSE ;
  else {
  mu__boolexpr760 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr760)) mu__boolexpr759 = FALSE ;
  else {
  mu__boolexpr759 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr759)) mu__boolexpr758 = FALSE ;
  else {
  mu__boolexpr758 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr758)) mu__boolexpr757 = FALSE ;
  else {
  mu__boolexpr757 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr757) {
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
    r = what_rule - 22016;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_97 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_96 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_95 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_94 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_93 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_92 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_91 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_90 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_93 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_92 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_91 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_90 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr768;
bool mu__boolexpr769;
bool mu__boolexpr770;
bool mu__boolexpr771;
bool mu__boolexpr772;
bool mu__boolexpr773;
bool mu__boolexpr774;
bool mu__boolexpr775;
bool mu__boolexpr776;
bool mu__boolexpr777;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr777 = FALSE ;
  else {
  mu__boolexpr777 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr777)) mu__boolexpr776 = FALSE ;
  else {
  mu__boolexpr776 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr776)) mu__boolexpr775 = FALSE ;
  else {
  mu__boolexpr775 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr775)) mu__boolexpr774 = FALSE ;
  else {
  mu__boolexpr774 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr774)) mu__boolexpr773 = FALSE ;
  else {
  mu__boolexpr773 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr773)) mu__boolexpr772 = FALSE ;
  else {
  mu__boolexpr772 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr772)) mu__boolexpr771 = FALSE ;
  else {
  mu__boolexpr771 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr771)) mu__boolexpr770 = FALSE ;
  else {
  mu__boolexpr770 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr770)) mu__boolexpr769 = FALSE ;
  else {
  mu__boolexpr769 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr769)) mu__boolexpr768 = FALSE ;
  else {
  mu__boolexpr768 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr768;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 22272;
    static mu__subrange_93 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_92 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_91 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_90 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 22528 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr778;
bool mu__boolexpr779;
bool mu__boolexpr780;
bool mu__boolexpr781;
bool mu__boolexpr782;
bool mu__boolexpr783;
bool mu__boolexpr784;
bool mu__boolexpr785;
bool mu__boolexpr786;
bool mu__boolexpr787;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr787 = FALSE ;
  else {
  mu__boolexpr787 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr787)) mu__boolexpr786 = FALSE ;
  else {
  mu__boolexpr786 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr786)) mu__boolexpr785 = FALSE ;
  else {
  mu__boolexpr785 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr785)) mu__boolexpr784 = FALSE ;
  else {
  mu__boolexpr784 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr784)) mu__boolexpr783 = FALSE ;
  else {
  mu__boolexpr783 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr783)) mu__boolexpr782 = FALSE ;
  else {
  mu__boolexpr782 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr782)) mu__boolexpr781 = FALSE ;
  else {
  mu__boolexpr781 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr781)) mu__boolexpr780 = FALSE ;
  else {
  mu__boolexpr780 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr780)) mu__boolexpr779 = FALSE ;
  else {
  mu__boolexpr779 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr779)) mu__boolexpr778 = FALSE ;
  else {
  mu__boolexpr778 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr778) {
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
    r = what_rule - 22272;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_93 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_92 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_91 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_90 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessResponse ( (int)mu_n4, mu_EntryPath[mu_n4] );
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
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_response, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr788;
bool mu__boolexpr789;
bool mu__boolexpr790;
bool mu__boolexpr791;
bool mu__boolexpr792;
bool mu__boolexpr793;
bool mu__boolexpr794;
bool mu__boolexpr795;
bool mu__boolexpr796;
bool mu__boolexpr797;
bool mu__boolexpr798;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr798 = FALSE ;
  else {
  mu__boolexpr798 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr798)) mu__boolexpr797 = FALSE ;
  else {
  mu__boolexpr797 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr797)) mu__boolexpr796 = FALSE ;
  else {
  mu__boolexpr796 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr796)) mu__boolexpr795 = FALSE ;
  else {
  mu__boolexpr795 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr795)) mu__boolexpr794 = FALSE ;
  else {
  mu__boolexpr794 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr794)) mu__boolexpr793 = FALSE ;
  else {
  mu__boolexpr793 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr793)) mu__boolexpr792 = FALSE ;
  else {
  mu__boolexpr792 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr792)) mu__boolexpr791 = FALSE ;
  else {
  mu__boolexpr791 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr791)) mu__boolexpr790 = FALSE ;
  else {
  mu__boolexpr790 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr790)) mu__boolexpr789 = FALSE ;
  else {
  mu__boolexpr789 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr789)) mu__boolexpr788 = FALSE ;
  else {
  mu__boolexpr788 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr788;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 22528;
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 22784 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr799;
bool mu__boolexpr800;
bool mu__boolexpr801;
bool mu__boolexpr802;
bool mu__boolexpr803;
bool mu__boolexpr804;
bool mu__boolexpr805;
bool mu__boolexpr806;
bool mu__boolexpr807;
bool mu__boolexpr808;
bool mu__boolexpr809;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr809 = FALSE ;
  else {
  mu__boolexpr809 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr809)) mu__boolexpr808 = FALSE ;
  else {
  mu__boolexpr808 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr808)) mu__boolexpr807 = FALSE ;
  else {
  mu__boolexpr807 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr807)) mu__boolexpr806 = FALSE ;
  else {
  mu__boolexpr806 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr806)) mu__boolexpr805 = FALSE ;
  else {
  mu__boolexpr805 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr805)) mu__boolexpr804 = FALSE ;
  else {
  mu__boolexpr804 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr804)) mu__boolexpr803 = FALSE ;
  else {
  mu__boolexpr803 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr803)) mu__boolexpr802 = FALSE ;
  else {
  mu__boolexpr802 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr802)) mu__boolexpr801 = FALSE ;
  else {
  mu__boolexpr801 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr801)) mu__boolexpr800 = FALSE ;
  else {
  mu__boolexpr800 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr800)) mu__boolexpr799 = FALSE ;
  else {
  mu__boolexpr799 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr799) {
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
    r = what_rule - 22528;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_89 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_88 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_87 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_86 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdResponse ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_85 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_84 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_83 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_82 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_85 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_84 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_83 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_82 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr810;
bool mu__boolexpr811;
bool mu__boolexpr812;
bool mu__boolexpr813;
bool mu__boolexpr814;
bool mu__boolexpr815;
bool mu__boolexpr816;
bool mu__boolexpr817;
bool mu__boolexpr818;
bool mu__boolexpr819;
bool mu__boolexpr820;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr820 = FALSE ;
  else {
  mu__boolexpr820 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr820)) mu__boolexpr819 = FALSE ;
  else {
  mu__boolexpr819 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr819)) mu__boolexpr818 = FALSE ;
  else {
  mu__boolexpr818 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr818)) mu__boolexpr817 = FALSE ;
  else {
  mu__boolexpr817 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr817)) mu__boolexpr816 = FALSE ;
  else {
  mu__boolexpr816 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr816)) mu__boolexpr815 = FALSE ;
  else {
  mu__boolexpr815 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr815)) mu__boolexpr814 = FALSE ;
  else {
  mu__boolexpr814 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr814)) mu__boolexpr813 = FALSE ;
  else {
  mu__boolexpr813 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr813)) mu__boolexpr812 = FALSE ;
  else {
  mu__boolexpr812 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr812)) mu__boolexpr811 = FALSE ;
  else {
  mu__boolexpr811 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr811)) mu__boolexpr810 = FALSE ;
  else {
  mu__boolexpr810 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr810;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 22784;
    static mu__subrange_85 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_84 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_83 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_82 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 23040 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr821;
bool mu__boolexpr822;
bool mu__boolexpr823;
bool mu__boolexpr824;
bool mu__boolexpr825;
bool mu__boolexpr826;
bool mu__boolexpr827;
bool mu__boolexpr828;
bool mu__boolexpr829;
bool mu__boolexpr830;
bool mu__boolexpr831;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr831 = FALSE ;
  else {
  mu__boolexpr831 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr831)) mu__boolexpr830 = FALSE ;
  else {
  mu__boolexpr830 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr830)) mu__boolexpr829 = FALSE ;
  else {
  mu__boolexpr829 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr829)) mu__boolexpr828 = FALSE ;
  else {
  mu__boolexpr828 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr828)) mu__boolexpr827 = FALSE ;
  else {
  mu__boolexpr827 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr827)) mu__boolexpr826 = FALSE ;
  else {
  mu__boolexpr826 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr826)) mu__boolexpr825 = FALSE ;
  else {
  mu__boolexpr825 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr825)) mu__boolexpr824 = FALSE ;
  else {
  mu__boolexpr824 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr824)) mu__boolexpr823 = FALSE ;
  else {
  mu__boolexpr823 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr823)) mu__boolexpr822 = FALSE ;
  else {
  mu__boolexpr822 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr822)) mu__boolexpr821 = FALSE ;
  else {
  mu__boolexpr821 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr821) {
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
    r = what_rule - 22784;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_85 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_84 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_83 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_82 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_81 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_80 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_79 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_78 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request + Process fwd_request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_81 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_80 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_79 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_78 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr832;
bool mu__boolexpr833;
bool mu__boolexpr834;
bool mu__boolexpr835;
bool mu__boolexpr836;
bool mu__boolexpr837;
bool mu__boolexpr838;
bool mu__boolexpr839;
bool mu__boolexpr840;
bool mu__boolexpr841;
bool mu__boolexpr842;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr842 = FALSE ;
  else {
  mu__boolexpr842 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr842)) mu__boolexpr841 = FALSE ;
  else {
  mu__boolexpr841 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr841)) mu__boolexpr840 = FALSE ;
  else {
  mu__boolexpr840 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr840)) mu__boolexpr839 = FALSE ;
  else {
  mu__boolexpr839 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr839)) mu__boolexpr838 = FALSE ;
  else {
  mu__boolexpr838 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr838)) mu__boolexpr837 = FALSE ;
  else {
  mu__boolexpr837 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr837)) mu__boolexpr836 = FALSE ;
  else {
  mu__boolexpr836 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr836)) mu__boolexpr835 = FALSE ;
  else {
  mu__boolexpr835 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr835)) mu__boolexpr834 = FALSE ;
  else {
  mu__boolexpr834 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr834)) mu__boolexpr833 = FALSE ;
  else {
  mu__boolexpr833 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr833)) mu__boolexpr832 = FALSE ;
  else {
  mu__boolexpr832 = ((mu_n3) != (mu_n4)) ; 
}
    return mu__boolexpr832;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 23040;
    static mu__subrange_81 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_80 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_79 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_78 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 23296 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr843;
bool mu__boolexpr844;
bool mu__boolexpr845;
bool mu__boolexpr846;
bool mu__boolexpr847;
bool mu__boolexpr848;
bool mu__boolexpr849;
bool mu__boolexpr850;
bool mu__boolexpr851;
bool mu__boolexpr852;
bool mu__boolexpr853;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr853 = FALSE ;
  else {
  mu__boolexpr853 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr853)) mu__boolexpr852 = FALSE ;
  else {
  mu__boolexpr852 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr852)) mu__boolexpr851 = FALSE ;
  else {
  mu__boolexpr851 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr851)) mu__boolexpr850 = FALSE ;
  else {
  mu__boolexpr850 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr850)) mu__boolexpr849 = FALSE ;
  else {
  mu__boolexpr849 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr849)) mu__boolexpr848 = FALSE ;
  else {
  mu__boolexpr848 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr848)) mu__boolexpr847 = FALSE ;
  else {
  mu__boolexpr847 = ((mu_IncomingQueue[mu_n4][mu_EntryPath[mu_n4]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr847)) mu__boolexpr846 = FALSE ;
  else {
  mu__boolexpr846 = ((mu_TailPointers[mu_ExitPath[mu_n4]][mu_n4]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr846)) mu__boolexpr845 = FALSE ;
  else {
  mu__boolexpr845 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr845)) mu__boolexpr844 = FALSE ;
  else {
  mu__boolexpr844 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr844)) mu__boolexpr843 = FALSE ;
  else {
  mu__boolexpr843 = ((mu_n3) != (mu_n4)) ; 
}
	      if (mu__boolexpr843) {
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
    r = what_rule - 23040;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_81 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_80 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_79 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_78 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
mu_ProcessFwdRequest ( (int)mu_n4, mu_EntryPath[mu_n4], mu_ExitPath[mu_n4] );
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
    static mu__subrange_77 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_76 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_75 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_74 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_73 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request + Process fwd_response, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_77 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_76 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_75 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_74 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_73 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr854;
bool mu__boolexpr855;
bool mu__boolexpr856;
bool mu__boolexpr857;
bool mu__boolexpr858;
bool mu__boolexpr859;
bool mu__boolexpr860;
bool mu__boolexpr861;
bool mu__boolexpr862;
bool mu__boolexpr863;
bool mu__boolexpr864;
bool mu__boolexpr865;
bool mu__boolexpr866;
bool mu__boolexpr867;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr867 = FALSE ;
  else {
  mu__boolexpr867 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr867)) mu__boolexpr866 = FALSE ;
  else {
  mu__boolexpr866 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr866)) mu__boolexpr865 = FALSE ;
  else {
  mu__boolexpr865 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr865)) mu__boolexpr864 = FALSE ;
  else {
  mu__boolexpr864 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr864)) mu__boolexpr863 = FALSE ;
  else {
  mu__boolexpr863 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr863)) mu__boolexpr862 = FALSE ;
  else {
  mu__boolexpr862 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr862)) mu__boolexpr861 = FALSE ;
  else {
  mu__boolexpr861 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr861)) mu__boolexpr860 = FALSE ;
  else {
  mu__boolexpr860 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr860)) mu__boolexpr859 = FALSE ;
  else {
  mu__boolexpr859 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr859)) mu__boolexpr858 = FALSE ;
  else {
  mu__boolexpr858 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr858)) mu__boolexpr857 = FALSE ;
  else {
  mu__boolexpr857 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr857)) mu__boolexpr856 = FALSE ;
  else {
  mu__boolexpr856 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr856)) mu__boolexpr855 = FALSE ;
  else {
  mu__boolexpr855 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr855)) mu__boolexpr854 = FALSE ;
  else {
  mu__boolexpr854 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr854;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 23296;
    static mu__subrange_77 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_76 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_75 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_74 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_73 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 24320 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr868;
bool mu__boolexpr869;
bool mu__boolexpr870;
bool mu__boolexpr871;
bool mu__boolexpr872;
bool mu__boolexpr873;
bool mu__boolexpr874;
bool mu__boolexpr875;
bool mu__boolexpr876;
bool mu__boolexpr877;
bool mu__boolexpr878;
bool mu__boolexpr879;
bool mu__boolexpr880;
bool mu__boolexpr881;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr881 = FALSE ;
  else {
  mu__boolexpr881 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr881)) mu__boolexpr880 = FALSE ;
  else {
  mu__boolexpr880 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr880)) mu__boolexpr879 = FALSE ;
  else {
  mu__boolexpr879 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr879)) mu__boolexpr878 = FALSE ;
  else {
  mu__boolexpr878 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr878)) mu__boolexpr877 = FALSE ;
  else {
  mu__boolexpr877 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr877)) mu__boolexpr876 = FALSE ;
  else {
  mu__boolexpr876 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr876)) mu__boolexpr875 = FALSE ;
  else {
  mu__boolexpr875 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr875)) mu__boolexpr874 = FALSE ;
  else {
  mu__boolexpr874 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr874)) mu__boolexpr873 = FALSE ;
  else {
  mu__boolexpr873 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr873)) mu__boolexpr872 = FALSE ;
  else {
  mu__boolexpr872 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr872)) mu__boolexpr871 = FALSE ;
  else {
  mu__boolexpr871 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr871)) mu__boolexpr870 = FALSE ;
  else {
  mu__boolexpr870 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr870)) mu__boolexpr869 = FALSE ;
  else {
  mu__boolexpr869 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr869)) mu__boolexpr868 = FALSE ;
  else {
  mu__boolexpr868 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr868) {
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
    r = what_rule - 23296;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_77 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_76 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_75 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_74 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_73 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdResponse ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
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
    static mu__subrange_72 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_71 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_70 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_69 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_68 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request + Process fwd_request, n5:%s, n4:%s, n3:%s, n2:%s, n1:%s", mu_n5.Name(), mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_72 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_71 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_70 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_69 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_68 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr882;
bool mu__boolexpr883;
bool mu__boolexpr884;
bool mu__boolexpr885;
bool mu__boolexpr886;
bool mu__boolexpr887;
bool mu__boolexpr888;
bool mu__boolexpr889;
bool mu__boolexpr890;
bool mu__boolexpr891;
bool mu__boolexpr892;
bool mu__boolexpr893;
bool mu__boolexpr894;
bool mu__boolexpr895;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr895 = FALSE ;
  else {
  mu__boolexpr895 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr895)) mu__boolexpr894 = FALSE ;
  else {
  mu__boolexpr894 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr894)) mu__boolexpr893 = FALSE ;
  else {
  mu__boolexpr893 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr893)) mu__boolexpr892 = FALSE ;
  else {
  mu__boolexpr892 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr892)) mu__boolexpr891 = FALSE ;
  else {
  mu__boolexpr891 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr891)) mu__boolexpr890 = FALSE ;
  else {
  mu__boolexpr890 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr890)) mu__boolexpr889 = FALSE ;
  else {
  mu__boolexpr889 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr889)) mu__boolexpr888 = FALSE ;
  else {
  mu__boolexpr888 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr888)) mu__boolexpr887 = FALSE ;
  else {
  mu__boolexpr887 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr887)) mu__boolexpr886 = FALSE ;
  else {
  mu__boolexpr886 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr886)) mu__boolexpr885 = FALSE ;
  else {
  mu__boolexpr885 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr885)) mu__boolexpr884 = FALSE ;
  else {
  mu__boolexpr884 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr884)) mu__boolexpr883 = FALSE ;
  else {
  mu__boolexpr883 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr883)) mu__boolexpr882 = FALSE ;
  else {
  mu__boolexpr882 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr882;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 24320;
    static mu__subrange_72 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_71 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_70 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_69 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_68 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25344 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr896;
bool mu__boolexpr897;
bool mu__boolexpr898;
bool mu__boolexpr899;
bool mu__boolexpr900;
bool mu__boolexpr901;
bool mu__boolexpr902;
bool mu__boolexpr903;
bool mu__boolexpr904;
bool mu__boolexpr905;
bool mu__boolexpr906;
bool mu__boolexpr907;
bool mu__boolexpr908;
bool mu__boolexpr909;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr909 = FALSE ;
  else {
  mu__boolexpr909 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr909)) mu__boolexpr908 = FALSE ;
  else {
  mu__boolexpr908 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr908)) mu__boolexpr907 = FALSE ;
  else {
  mu__boolexpr907 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr907)) mu__boolexpr906 = FALSE ;
  else {
  mu__boolexpr906 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr906)) mu__boolexpr905 = FALSE ;
  else {
  mu__boolexpr905 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr905)) mu__boolexpr904 = FALSE ;
  else {
  mu__boolexpr904 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr904)) mu__boolexpr903 = FALSE ;
  else {
  mu__boolexpr903 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr903)) mu__boolexpr902 = FALSE ;
  else {
  mu__boolexpr902 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr902)) mu__boolexpr901 = FALSE ;
  else {
  mu__boolexpr901 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr901)) mu__boolexpr900 = FALSE ;
  else {
  mu__boolexpr900 = ((mu_IncomingQueue[mu_n5][mu_EntryPath[mu_n5]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr900)) mu__boolexpr899 = FALSE ;
  else {
  mu__boolexpr899 = ((mu_TailPointers[mu_ExitPath[mu_n5]][mu_n5]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr899)) mu__boolexpr898 = FALSE ;
  else {
  mu__boolexpr898 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr898)) mu__boolexpr897 = FALSE ;
  else {
  mu__boolexpr897 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr897)) mu__boolexpr896 = FALSE ;
  else {
  mu__boolexpr896 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr896) {
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
    r = what_rule - 24320;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_72 mu_n5;
    mu_n5.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_71 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_70 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_69 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_68 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
mu_ProcessFwdRequest ( (int)mu_n5, mu_EntryPath[mu_n5], mu_ExitPath[mu_n5] );
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
    static mu__subrange_67 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_66 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_67 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_66 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr910;
bool mu__boolexpr911;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr911 = FALSE ;
  else {
  mu__boolexpr911 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr911)) mu__boolexpr910 = FALSE ;
  else {
  mu__boolexpr910 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr910;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25344;
    static mu__subrange_67 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_66 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25360 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr912;
bool mu__boolexpr913;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response))) mu__boolexpr913 = FALSE ;
  else {
  mu__boolexpr913 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr913)) mu__boolexpr912 = FALSE ;
  else {
  mu__boolexpr912 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr912) {
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
    r = what_rule - 25344;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_67 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_66 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessResponse ( (int)mu_n1, mu_EntryPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
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
    static mu__subrange_65 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_64 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_65 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_64 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr914;
bool mu__boolexpr915;
bool mu__boolexpr916;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr916 = FALSE ;
  else {
  mu__boolexpr916 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr916)) mu__boolexpr915 = FALSE ;
  else {
  mu__boolexpr915 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr915)) mu__boolexpr914 = FALSE ;
  else {
  mu__boolexpr914 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr914;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25360;
    static mu__subrange_65 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_64 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25376 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr917;
bool mu__boolexpr918;
bool mu__boolexpr919;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr919 = FALSE ;
  else {
  mu__boolexpr919 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr919)) mu__boolexpr918 = FALSE ;
  else {
  mu__boolexpr918 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr918)) mu__boolexpr917 = FALSE ;
  else {
  mu__boolexpr917 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr917) {
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
    r = what_rule - 25360;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_65 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_64 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
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
    static mu__subrange_63 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_62 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_63 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_62 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr920;
bool mu__boolexpr921;
bool mu__boolexpr922;
bool mu__boolexpr923;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr923 = FALSE ;
  else {
  mu__boolexpr923 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr923)) mu__boolexpr922 = FALSE ;
  else {
  mu__boolexpr922 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr922)) mu__boolexpr921 = FALSE ;
  else {
  mu__boolexpr921 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr921)) mu__boolexpr920 = FALSE ;
  else {
  mu__boolexpr920 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr920;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25376;
    static mu__subrange_63 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_62 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25392 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr924;
bool mu__boolexpr925;
bool mu__boolexpr926;
bool mu__boolexpr927;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr927 = FALSE ;
  else {
  mu__boolexpr927 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr927)) mu__boolexpr926 = FALSE ;
  else {
  mu__boolexpr926 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr926)) mu__boolexpr925 = FALSE ;
  else {
  mu__boolexpr925 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr925)) mu__boolexpr924 = FALSE ;
  else {
  mu__boolexpr924 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr924) {
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
    r = what_rule - 25376;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_63 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_62 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_61 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_60 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_61 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_60 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr928;
bool mu__boolexpr929;
bool mu__boolexpr930;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr930 = FALSE ;
  else {
  mu__boolexpr930 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr930)) mu__boolexpr929 = FALSE ;
  else {
  mu__boolexpr929 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr929)) mu__boolexpr928 = FALSE ;
  else {
  mu__boolexpr928 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr928;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25392;
    static mu__subrange_61 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_60 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25408 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr931;
bool mu__boolexpr932;
bool mu__boolexpr933;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr933 = FALSE ;
  else {
  mu__boolexpr933 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr933)) mu__boolexpr932 = FALSE ;
  else {
  mu__boolexpr932 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr932)) mu__boolexpr931 = FALSE ;
  else {
  mu__boolexpr931 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr931) {
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
    r = what_rule - 25392;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_61 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_60 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
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
    static mu__subrange_59 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_58 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_59 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_58 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr934;
bool mu__boolexpr935;
bool mu__boolexpr936;
bool mu__boolexpr937;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr937 = FALSE ;
  else {
  mu__boolexpr937 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr937)) mu__boolexpr936 = FALSE ;
  else {
  mu__boolexpr936 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr936)) mu__boolexpr935 = FALSE ;
  else {
  mu__boolexpr935 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr935)) mu__boolexpr934 = FALSE ;
  else {
  mu__boolexpr934 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr934;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25408;
    static mu__subrange_59 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_58 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25424 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr938;
bool mu__boolexpr939;
bool mu__boolexpr940;
bool mu__boolexpr941;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr941 = FALSE ;
  else {
  mu__boolexpr941 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr941)) mu__boolexpr940 = FALSE ;
  else {
  mu__boolexpr940 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr940)) mu__boolexpr939 = FALSE ;
  else {
  mu__boolexpr939 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr939)) mu__boolexpr938 = FALSE ;
  else {
  mu__boolexpr938 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr938) {
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
    r = what_rule - 25408;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_59 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_58 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_57 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_56 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_57 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_56 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr942;
bool mu__boolexpr943;
bool mu__boolexpr944;
bool mu__boolexpr945;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr945 = FALSE ;
  else {
  mu__boolexpr945 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr945)) mu__boolexpr944 = FALSE ;
  else {
  mu__boolexpr944 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr944)) mu__boolexpr943 = FALSE ;
  else {
  mu__boolexpr943 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr943)) mu__boolexpr942 = FALSE ;
  else {
  mu__boolexpr942 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr942;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25424;
    static mu__subrange_57 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_56 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25440 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr946;
bool mu__boolexpr947;
bool mu__boolexpr948;
bool mu__boolexpr949;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr949 = FALSE ;
  else {
  mu__boolexpr949 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr949)) mu__boolexpr948 = FALSE ;
  else {
  mu__boolexpr948 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr948)) mu__boolexpr947 = FALSE ;
  else {
  mu__boolexpr947 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr947)) mu__boolexpr946 = FALSE ;
  else {
  mu__boolexpr946 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr946) {
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
    r = what_rule - 25424;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_57 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_56 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_55 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_54 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_55 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_54 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr950;
bool mu__boolexpr951;
bool mu__boolexpr952;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr952 = FALSE ;
  else {
  mu__boolexpr952 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr952)) mu__boolexpr951 = FALSE ;
  else {
  mu__boolexpr951 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr951)) mu__boolexpr950 = FALSE ;
  else {
  mu__boolexpr950 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr950;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25440;
    static mu__subrange_55 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_54 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25456 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr953;
bool mu__boolexpr954;
bool mu__boolexpr955;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr955 = FALSE ;
  else {
  mu__boolexpr955 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr955)) mu__boolexpr954 = FALSE ;
  else {
  mu__boolexpr954 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr954)) mu__boolexpr953 = FALSE ;
  else {
  mu__boolexpr953 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr953) {
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
    r = what_rule - 25440;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_55 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_54 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessResponse ( (int)mu_n2, mu_EntryPath[mu_n2] );
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
    static mu__subrange_53 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_52 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_53 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_52 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr956;
bool mu__boolexpr957;
bool mu__boolexpr958;
bool mu__boolexpr959;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr959 = FALSE ;
  else {
  mu__boolexpr959 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr959)) mu__boolexpr958 = FALSE ;
  else {
  mu__boolexpr958 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr958)) mu__boolexpr957 = FALSE ;
  else {
  mu__boolexpr957 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr957)) mu__boolexpr956 = FALSE ;
  else {
  mu__boolexpr956 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr956;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25456;
    static mu__subrange_53 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_52 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25472 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr960;
bool mu__boolexpr961;
bool mu__boolexpr962;
bool mu__boolexpr963;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr963 = FALSE ;
  else {
  mu__boolexpr963 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr963)) mu__boolexpr962 = FALSE ;
  else {
  mu__boolexpr962 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr962)) mu__boolexpr961 = FALSE ;
  else {
  mu__boolexpr961 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr961)) mu__boolexpr960 = FALSE ;
  else {
  mu__boolexpr960 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr960) {
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
    r = what_rule - 25456;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_53 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_52 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdResponse ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_51 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_50 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_51 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_50 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr964;
bool mu__boolexpr965;
bool mu__boolexpr966;
bool mu__boolexpr967;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr967 = FALSE ;
  else {
  mu__boolexpr967 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr967)) mu__boolexpr966 = FALSE ;
  else {
  mu__boolexpr966 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr966)) mu__boolexpr965 = FALSE ;
  else {
  mu__boolexpr965 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr965)) mu__boolexpr964 = FALSE ;
  else {
  mu__boolexpr964 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr964;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25472;
    static mu__subrange_51 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_50 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25488 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr968;
bool mu__boolexpr969;
bool mu__boolexpr970;
bool mu__boolexpr971;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr971 = FALSE ;
  else {
  mu__boolexpr971 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr971)) mu__boolexpr970 = FALSE ;
  else {
  mu__boolexpr970 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr970)) mu__boolexpr969 = FALSE ;
  else {
  mu__boolexpr969 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr969)) mu__boolexpr968 = FALSE ;
  else {
  mu__boolexpr968 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr968) {
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
    r = what_rule - 25472;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_51 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_50 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_49 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_48 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_49 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_48 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr972;
bool mu__boolexpr973;
bool mu__boolexpr974;
bool mu__boolexpr975;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr975 = FALSE ;
  else {
  mu__boolexpr975 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr975)) mu__boolexpr974 = FALSE ;
  else {
  mu__boolexpr974 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr974)) mu__boolexpr973 = FALSE ;
  else {
  mu__boolexpr973 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr973)) mu__boolexpr972 = FALSE ;
  else {
  mu__boolexpr972 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr972;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25488;
    static mu__subrange_49 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_48 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25504 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr976;
bool mu__boolexpr977;
bool mu__boolexpr978;
bool mu__boolexpr979;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr979 = FALSE ;
  else {
  mu__boolexpr979 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr979)) mu__boolexpr978 = FALSE ;
  else {
  mu__boolexpr978 = ((mu_IncomingQueue[mu_n2][mu_EntryPath[mu_n2]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr978)) mu__boolexpr977 = FALSE ;
  else {
  mu__boolexpr977 = ((mu_TailPointers[mu_ExitPath[mu_n2]][mu_n2]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr977)) mu__boolexpr976 = FALSE ;
  else {
  mu__boolexpr976 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr976) {
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
    r = what_rule - 25488;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_49 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_48 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
mu_ProcessFwdRequest ( (int)mu_n2, mu_EntryPath[mu_n2], mu_ExitPath[mu_n2] );
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
    static mu__subrange_47 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_47 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr980;
bool mu__boolexpr981;
bool mu__boolexpr982;
bool mu__boolexpr983;
bool mu__boolexpr984;
bool mu__boolexpr985;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr985 = FALSE ;
  else {
  mu__boolexpr985 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr985)) mu__boolexpr984 = FALSE ;
  else {
  mu__boolexpr984 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr984)) mu__boolexpr983 = FALSE ;
  else {
  mu__boolexpr983 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr983)) mu__boolexpr982 = FALSE ;
  else {
  mu__boolexpr982 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr982)) mu__boolexpr981 = FALSE ;
  else {
  mu__boolexpr981 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr981)) mu__boolexpr980 = FALSE ;
  else {
  mu__boolexpr980 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr980;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25504;
    static mu__subrange_47 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25568 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr986;
bool mu__boolexpr987;
bool mu__boolexpr988;
bool mu__boolexpr989;
bool mu__boolexpr990;
bool mu__boolexpr991;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr991 = FALSE ;
  else {
  mu__boolexpr991 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr991)) mu__boolexpr990 = FALSE ;
  else {
  mu__boolexpr990 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr990)) mu__boolexpr989 = FALSE ;
  else {
  mu__boolexpr989 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr989)) mu__boolexpr988 = FALSE ;
  else {
  mu__boolexpr988 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr988)) mu__boolexpr987 = FALSE ;
  else {
  mu__boolexpr987 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr987)) mu__boolexpr986 = FALSE ;
  else {
  mu__boolexpr986 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr986) {
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
    r = what_rule - 25504;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_47 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_46 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_45 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessResponse ( (int)mu_n3, mu_EntryPath[mu_n3] );
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
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr992;
bool mu__boolexpr993;
bool mu__boolexpr994;
bool mu__boolexpr995;
bool mu__boolexpr996;
bool mu__boolexpr997;
bool mu__boolexpr998;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr998 = FALSE ;
  else {
  mu__boolexpr998 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr998)) mu__boolexpr997 = FALSE ;
  else {
  mu__boolexpr997 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr997)) mu__boolexpr996 = FALSE ;
  else {
  mu__boolexpr996 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr996)) mu__boolexpr995 = FALSE ;
  else {
  mu__boolexpr995 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr995)) mu__boolexpr994 = FALSE ;
  else {
  mu__boolexpr994 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr994)) mu__boolexpr993 = FALSE ;
  else {
  mu__boolexpr993 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr993)) mu__boolexpr992 = FALSE ;
  else {
  mu__boolexpr992 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr992;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25568;
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25632 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr999;
bool mu__boolexpr1000;
bool mu__boolexpr1001;
bool mu__boolexpr1002;
bool mu__boolexpr1003;
bool mu__boolexpr1004;
bool mu__boolexpr1005;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1005 = FALSE ;
  else {
  mu__boolexpr1005 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1005)) mu__boolexpr1004 = FALSE ;
  else {
  mu__boolexpr1004 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1004)) mu__boolexpr1003 = FALSE ;
  else {
  mu__boolexpr1003 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1003)) mu__boolexpr1002 = FALSE ;
  else {
  mu__boolexpr1002 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1002)) mu__boolexpr1001 = FALSE ;
  else {
  mu__boolexpr1001 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr1001)) mu__boolexpr1000 = FALSE ;
  else {
  mu__boolexpr1000 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1000)) mu__boolexpr999 = FALSE ;
  else {
  mu__boolexpr999 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr999) {
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
    r = what_rule - 25568;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_44 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_43 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_42 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdResponse ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1006;
bool mu__boolexpr1007;
bool mu__boolexpr1008;
bool mu__boolexpr1009;
bool mu__boolexpr1010;
bool mu__boolexpr1011;
bool mu__boolexpr1012;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1012 = FALSE ;
  else {
  mu__boolexpr1012 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1012)) mu__boolexpr1011 = FALSE ;
  else {
  mu__boolexpr1011 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1011)) mu__boolexpr1010 = FALSE ;
  else {
  mu__boolexpr1010 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1010)) mu__boolexpr1009 = FALSE ;
  else {
  mu__boolexpr1009 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1009)) mu__boolexpr1008 = FALSE ;
  else {
  mu__boolexpr1008 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr1008)) mu__boolexpr1007 = FALSE ;
  else {
  mu__boolexpr1007 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1007)) mu__boolexpr1006 = FALSE ;
  else {
  mu__boolexpr1006 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr1006;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25632;
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25696 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1013;
bool mu__boolexpr1014;
bool mu__boolexpr1015;
bool mu__boolexpr1016;
bool mu__boolexpr1017;
bool mu__boolexpr1018;
bool mu__boolexpr1019;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1019 = FALSE ;
  else {
  mu__boolexpr1019 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1019)) mu__boolexpr1018 = FALSE ;
  else {
  mu__boolexpr1018 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1018)) mu__boolexpr1017 = FALSE ;
  else {
  mu__boolexpr1017 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1017)) mu__boolexpr1016 = FALSE ;
  else {
  mu__boolexpr1016 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1016)) mu__boolexpr1015 = FALSE ;
  else {
  mu__boolexpr1015 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr1015)) mu__boolexpr1014 = FALSE ;
  else {
  mu__boolexpr1014 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1014)) mu__boolexpr1013 = FALSE ;
  else {
  mu__boolexpr1013 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr1013) {
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
    r = what_rule - 25632;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_40 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_39 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Process fwd_request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1020;
bool mu__boolexpr1021;
bool mu__boolexpr1022;
bool mu__boolexpr1023;
bool mu__boolexpr1024;
bool mu__boolexpr1025;
bool mu__boolexpr1026;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1026 = FALSE ;
  else {
  mu__boolexpr1026 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1026)) mu__boolexpr1025 = FALSE ;
  else {
  mu__boolexpr1025 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1025)) mu__boolexpr1024 = FALSE ;
  else {
  mu__boolexpr1024 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1024)) mu__boolexpr1023 = FALSE ;
  else {
  mu__boolexpr1023 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1023)) mu__boolexpr1022 = FALSE ;
  else {
  mu__boolexpr1022 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr1022)) mu__boolexpr1021 = FALSE ;
  else {
  mu__boolexpr1021 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1021)) mu__boolexpr1020 = FALSE ;
  else {
  mu__boolexpr1020 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr1020;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25696;
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 25760 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1027;
bool mu__boolexpr1028;
bool mu__boolexpr1029;
bool mu__boolexpr1030;
bool mu__boolexpr1031;
bool mu__boolexpr1032;
bool mu__boolexpr1033;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1033 = FALSE ;
  else {
  mu__boolexpr1033 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1033)) mu__boolexpr1032 = FALSE ;
  else {
  mu__boolexpr1032 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1032)) mu__boolexpr1031 = FALSE ;
  else {
  mu__boolexpr1031 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1031)) mu__boolexpr1030 = FALSE ;
  else {
  mu__boolexpr1030 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1030)) mu__boolexpr1029 = FALSE ;
  else {
  mu__boolexpr1029 = ((mu_IncomingQueue[mu_n3][mu_EntryPath[mu_n3]][0].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr1029)) mu__boolexpr1028 = FALSE ;
  else {
  mu__boolexpr1028 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1028)) mu__boolexpr1027 = FALSE ;
  else {
  mu__boolexpr1027 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr1027) {
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
    r = what_rule - 25696;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_38 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_37 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_36 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_ProcessFwdRequest ( (int)mu_n3, mu_EntryPath[mu_n3], mu_ExitPath[mu_n3] );
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
    static mu__subrange_35 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_34 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_35 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_34 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1034;
bool mu__boolexpr1035;
bool mu__boolexpr1036;
bool mu__boolexpr1037;
bool mu__boolexpr1038;
bool mu__boolexpr1039;
bool mu__boolexpr1040;
bool mu__boolexpr1041;
bool mu__boolexpr1042;
bool mu__boolexpr1043;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1043 = FALSE ;
  else {
  mu__boolexpr1043 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1043)) mu__boolexpr1042 = FALSE ;
  else {
  mu__boolexpr1042 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1042)) mu__boolexpr1041 = FALSE ;
  else {
  mu__boolexpr1041 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1041)) mu__boolexpr1040 = FALSE ;
  else {
  mu__boolexpr1040 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1040)) mu__boolexpr1039 = FALSE ;
  else {
  mu__boolexpr1039 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr1039)) mu__boolexpr1038 = FALSE ;
  else {
  mu__boolexpr1038 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1038)) mu__boolexpr1037 = FALSE ;
  else {
  mu__boolexpr1037 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr1037)) mu__boolexpr1036 = FALSE ;
  else {
  mu__boolexpr1036 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr1036)) mu__boolexpr1035 = FALSE ;
  else {
  mu__boolexpr1035 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr1035)) mu__boolexpr1034 = FALSE ;
  else {
  mu__boolexpr1034 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr1034;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25760;
    static mu__subrange_35 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_34 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26016 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1044;
bool mu__boolexpr1045;
bool mu__boolexpr1046;
bool mu__boolexpr1047;
bool mu__boolexpr1048;
bool mu__boolexpr1049;
bool mu__boolexpr1050;
bool mu__boolexpr1051;
bool mu__boolexpr1052;
bool mu__boolexpr1053;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1053 = FALSE ;
  else {
  mu__boolexpr1053 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1053)) mu__boolexpr1052 = FALSE ;
  else {
  mu__boolexpr1052 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1052)) mu__boolexpr1051 = FALSE ;
  else {
  mu__boolexpr1051 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1051)) mu__boolexpr1050 = FALSE ;
  else {
  mu__boolexpr1050 = ((mu_Routers[mu_n2]) == (0)) ; 
}
  if (!(mu__boolexpr1050)) mu__boolexpr1049 = FALSE ;
  else {
  mu__boolexpr1049 = ((mu_n3) != (mu_n4)) ; 
}
  if (!(mu__boolexpr1049)) mu__boolexpr1048 = FALSE ;
  else {
  mu__boolexpr1048 = ((mu_TailPointers[mu_ExitPath[mu_n3]][mu_n3]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1048)) mu__boolexpr1047 = FALSE ;
  else {
  mu__boolexpr1047 = ((mu_TailPointers[mu_n3][mu_EntryPath[mu_n3]]) == (0)) ; 
}
  if (!(mu__boolexpr1047)) mu__boolexpr1046 = FALSE ;
  else {
  mu__boolexpr1046 = ((mu_Routers[mu_n3]) == (0)) ; 
}
  if (!(mu__boolexpr1046)) mu__boolexpr1045 = FALSE ;
  else {
  mu__boolexpr1045 = ((mu_Routers[mu_n4]) == (0)) ; 
}
  if (!(mu__boolexpr1045)) mu__boolexpr1044 = FALSE ;
  else {
  mu__boolexpr1044 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr1044) {
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
    r = what_rule - 25760;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_35 mu_n4;
    mu_n4.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_34 mu_n3;
    mu_n3.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_33 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_32 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_SendRequest ( (int)mu_n1, mu_ExitPath[mu_n1], (int)mu_n2 );
mu_SendRequest ( (int)mu_n3, mu_ExitPath[mu_n3], (int)mu_n4 );
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
    static mu__subrange_31 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_31 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return (mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_response);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26016;
    static mu__subrange_31 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26020 )
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
    r = what_rule - 26016;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_31 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessResponse ( (int)mu_n1, mu_EntryPath[mu_n1] );
  };

};
/******************** RuleBase55 ********************/
class RuleBase55
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1054;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr1054 = FALSE ;
  else {
  mu__boolexpr1054 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr1054;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26020;
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26024 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1055;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_response))) mu__boolexpr1055 = FALSE ;
  else {
  mu__boolexpr1055 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr1055) {
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
    r = what_rule - 26020;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_30 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdResponse ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase56 ********************/
class RuleBase56
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1056;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr1056 = FALSE ;
  else {
  mu__boolexpr1056 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr1056;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26024;
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26028 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1057;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_request))) mu__boolexpr1057 = FALSE ;
  else {
  mu__boolexpr1057 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr1057) {
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
    r = what_rule - 26024;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_29 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase57 ********************/
class RuleBase57
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Process fwd_request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1058;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr1058 = FALSE ;
  else {
  mu__boolexpr1058 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr1058;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26028;
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26032 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1059;
  if (!((mu_IncomingQueue[mu_n1][mu_EntryPath[mu_n1]][0].mu_msg_type) == (mu_fwd_request))) mu__boolexpr1059 = FALSE ;
  else {
  mu__boolexpr1059 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr1059) {
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
    r = what_rule - 26028;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_28 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
mu_ProcessFwdRequest ( (int)mu_n1, mu_EntryPath[mu_n1], mu_ExitPath[mu_n1] );
  };

};
/******************** RuleBase58 ********************/
class RuleBase58
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    return tsprintf("Rule --> Send request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
bool mu__boolexpr1060;
bool mu__boolexpr1061;
bool mu__boolexpr1062;
bool mu__boolexpr1063;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1063 = FALSE ;
  else {
  mu__boolexpr1063 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1063)) mu__boolexpr1062 = FALSE ;
  else {
  mu__boolexpr1062 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1062)) mu__boolexpr1061 = FALSE ;
  else {
  mu__boolexpr1061 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1061)) mu__boolexpr1060 = FALSE ;
  else {
  mu__boolexpr1060 = ((mu_Routers[mu_n2]) == (0)) ; 
}
    return mu__boolexpr1060;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 26032;
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    while (what_rule < 26048 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1064;
bool mu__boolexpr1065;
bool mu__boolexpr1066;
bool mu__boolexpr1067;
  if (!((mu_n1) != (mu_n2))) mu__boolexpr1067 = FALSE ;
  else {
  mu__boolexpr1067 = ((mu_TailPointers[mu_ExitPath[mu_n1]][mu_n1]) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr1067)) mu__boolexpr1066 = FALSE ;
  else {
  mu__boolexpr1066 = ((mu_TailPointers[mu_n1][mu_EntryPath[mu_n1]]) == (0)) ; 
}
  if (!(mu__boolexpr1066)) mu__boolexpr1065 = FALSE ;
  else {
  mu__boolexpr1065 = ((mu_Routers[mu_n1]) == (0)) ; 
}
  if (!(mu__boolexpr1065)) mu__boolexpr1064 = FALSE ;
  else {
  mu__boolexpr1064 = ((mu_Routers[mu_n2]) == (0)) ; 
}
	      if (mu__boolexpr1064) {
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
    r = what_rule - 26032;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_27 mu_n2;
    mu_n2.value((r % 4) + 0);
    r = r / 4;
    static mu__subrange_26 mu_n1;
    mu_n1.value((r % 4) + 0);
    r = r / 4;
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
  RuleBase55 R55;
  RuleBase56 R56;
  RuleBase57 R57;
  RuleBase58 R58;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<256)
    { R0.NextRule(what_rule);
      if (what_rule<256) return; }
  if (what_rule>=256 && what_rule<512)
    { R1.NextRule(what_rule);
      if (what_rule<512) return; }
  if (what_rule>=512 && what_rule<768)
    { R2.NextRule(what_rule);
      if (what_rule<768) return; }
  if (what_rule>=768 && what_rule<1024)
    { R3.NextRule(what_rule);
      if (what_rule<1024) return; }
  if (what_rule>=1024 && what_rule<1280)
    { R4.NextRule(what_rule);
      if (what_rule<1280) return; }
  if (what_rule>=1280 && what_rule<1536)
    { R5.NextRule(what_rule);
      if (what_rule<1536) return; }
  if (what_rule>=1536 && what_rule<1792)
    { R6.NextRule(what_rule);
      if (what_rule<1792) return; }
  if (what_rule>=1792 && what_rule<2048)
    { R7.NextRule(what_rule);
      if (what_rule<2048) return; }
  if (what_rule>=2048 && what_rule<2304)
    { R8.NextRule(what_rule);
      if (what_rule<2304) return; }
  if (what_rule>=2304 && what_rule<3328)
    { R9.NextRule(what_rule);
      if (what_rule<3328) return; }
  if (what_rule>=3328 && what_rule<4352)
    { R10.NextRule(what_rule);
      if (what_rule<4352) return; }
  if (what_rule>=4352 && what_rule<5376)
    { R11.NextRule(what_rule);
      if (what_rule<5376) return; }
  if (what_rule>=5376 && what_rule<6400)
    { R12.NextRule(what_rule);
      if (what_rule<6400) return; }
  if (what_rule>=6400 && what_rule<7424)
    { R13.NextRule(what_rule);
      if (what_rule<7424) return; }
  if (what_rule>=7424 && what_rule<8448)
    { R14.NextRule(what_rule);
      if (what_rule<8448) return; }
  if (what_rule>=8448 && what_rule<12544)
    { R15.NextRule(what_rule);
      if (what_rule<12544) return; }
  if (what_rule>=12544 && what_rule<16640)
    { R16.NextRule(what_rule);
      if (what_rule<16640) return; }
  if (what_rule>=16640 && what_rule<20736)
    { R17.NextRule(what_rule);
      if (what_rule<20736) return; }
  if (what_rule>=20736 && what_rule<20800)
    { R18.NextRule(what_rule);
      if (what_rule<20800) return; }
  if (what_rule>=20800 && what_rule<20864)
    { R19.NextRule(what_rule);
      if (what_rule<20864) return; }
  if (what_rule>=20864 && what_rule<20928)
    { R20.NextRule(what_rule);
      if (what_rule<20928) return; }
  if (what_rule>=20928 && what_rule<20992)
    { R21.NextRule(what_rule);
      if (what_rule<20992) return; }
  if (what_rule>=20992 && what_rule<21056)
    { R22.NextRule(what_rule);
      if (what_rule<21056) return; }
  if (what_rule>=21056 && what_rule<21120)
    { R23.NextRule(what_rule);
      if (what_rule<21120) return; }
  if (what_rule>=21120 && what_rule<21184)
    { R24.NextRule(what_rule);
      if (what_rule<21184) return; }
  if (what_rule>=21184 && what_rule<21248)
    { R25.NextRule(what_rule);
      if (what_rule<21248) return; }
  if (what_rule>=21248 && what_rule<21312)
    { R26.NextRule(what_rule);
      if (what_rule<21312) return; }
  if (what_rule>=21312 && what_rule<21376)
    { R27.NextRule(what_rule);
      if (what_rule<21376) return; }
  if (what_rule>=21376 && what_rule<21440)
    { R28.NextRule(what_rule);
      if (what_rule<21440) return; }
  if (what_rule>=21440 && what_rule<21504)
    { R29.NextRule(what_rule);
      if (what_rule<21504) return; }
  if (what_rule>=21504 && what_rule<21760)
    { R30.NextRule(what_rule);
      if (what_rule<21760) return; }
  if (what_rule>=21760 && what_rule<22016)
    { R31.NextRule(what_rule);
      if (what_rule<22016) return; }
  if (what_rule>=22016 && what_rule<22272)
    { R32.NextRule(what_rule);
      if (what_rule<22272) return; }
  if (what_rule>=22272 && what_rule<22528)
    { R33.NextRule(what_rule);
      if (what_rule<22528) return; }
  if (what_rule>=22528 && what_rule<22784)
    { R34.NextRule(what_rule);
      if (what_rule<22784) return; }
  if (what_rule>=22784 && what_rule<23040)
    { R35.NextRule(what_rule);
      if (what_rule<23040) return; }
  if (what_rule>=23040 && what_rule<23296)
    { R36.NextRule(what_rule);
      if (what_rule<23296) return; }
  if (what_rule>=23296 && what_rule<24320)
    { R37.NextRule(what_rule);
      if (what_rule<24320) return; }
  if (what_rule>=24320 && what_rule<25344)
    { R38.NextRule(what_rule);
      if (what_rule<25344) return; }
  if (what_rule>=25344 && what_rule<25360)
    { R39.NextRule(what_rule);
      if (what_rule<25360) return; }
  if (what_rule>=25360 && what_rule<25376)
    { R40.NextRule(what_rule);
      if (what_rule<25376) return; }
  if (what_rule>=25376 && what_rule<25392)
    { R41.NextRule(what_rule);
      if (what_rule<25392) return; }
  if (what_rule>=25392 && what_rule<25408)
    { R42.NextRule(what_rule);
      if (what_rule<25408) return; }
  if (what_rule>=25408 && what_rule<25424)
    { R43.NextRule(what_rule);
      if (what_rule<25424) return; }
  if (what_rule>=25424 && what_rule<25440)
    { R44.NextRule(what_rule);
      if (what_rule<25440) return; }
  if (what_rule>=25440 && what_rule<25456)
    { R45.NextRule(what_rule);
      if (what_rule<25456) return; }
  if (what_rule>=25456 && what_rule<25472)
    { R46.NextRule(what_rule);
      if (what_rule<25472) return; }
  if (what_rule>=25472 && what_rule<25488)
    { R47.NextRule(what_rule);
      if (what_rule<25488) return; }
  if (what_rule>=25488 && what_rule<25504)
    { R48.NextRule(what_rule);
      if (what_rule<25504) return; }
  if (what_rule>=25504 && what_rule<25568)
    { R49.NextRule(what_rule);
      if (what_rule<25568) return; }
  if (what_rule>=25568 && what_rule<25632)
    { R50.NextRule(what_rule);
      if (what_rule<25632) return; }
  if (what_rule>=25632 && what_rule<25696)
    { R51.NextRule(what_rule);
      if (what_rule<25696) return; }
  if (what_rule>=25696 && what_rule<25760)
    { R52.NextRule(what_rule);
      if (what_rule<25760) return; }
  if (what_rule>=25760 && what_rule<26016)
    { R53.NextRule(what_rule);
      if (what_rule<26016) return; }
  if (what_rule>=26016 && what_rule<26020)
    { R54.NextRule(what_rule);
      if (what_rule<26020) return; }
  if (what_rule>=26020 && what_rule<26024)
    { R55.NextRule(what_rule);
      if (what_rule<26024) return; }
  if (what_rule>=26024 && what_rule<26028)
    { R56.NextRule(what_rule);
      if (what_rule<26028) return; }
  if (what_rule>=26028 && what_rule<26032)
    { R57.NextRule(what_rule);
      if (what_rule<26032) return; }
  if (what_rule>=26032 && what_rule<26048)
    { R58.NextRule(what_rule);
      if (what_rule<26048) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=255) return R0.Condition(r-0);
  if (r>=256 && r<=511) return R1.Condition(r-256);
  if (r>=512 && r<=767) return R2.Condition(r-512);
  if (r>=768 && r<=1023) return R3.Condition(r-768);
  if (r>=1024 && r<=1279) return R4.Condition(r-1024);
  if (r>=1280 && r<=1535) return R5.Condition(r-1280);
  if (r>=1536 && r<=1791) return R6.Condition(r-1536);
  if (r>=1792 && r<=2047) return R7.Condition(r-1792);
  if (r>=2048 && r<=2303) return R8.Condition(r-2048);
  if (r>=2304 && r<=3327) return R9.Condition(r-2304);
  if (r>=3328 && r<=4351) return R10.Condition(r-3328);
  if (r>=4352 && r<=5375) return R11.Condition(r-4352);
  if (r>=5376 && r<=6399) return R12.Condition(r-5376);
  if (r>=6400 && r<=7423) return R13.Condition(r-6400);
  if (r>=7424 && r<=8447) return R14.Condition(r-7424);
  if (r>=8448 && r<=12543) return R15.Condition(r-8448);
  if (r>=12544 && r<=16639) return R16.Condition(r-12544);
  if (r>=16640 && r<=20735) return R17.Condition(r-16640);
  if (r>=20736 && r<=20799) return R18.Condition(r-20736);
  if (r>=20800 && r<=20863) return R19.Condition(r-20800);
  if (r>=20864 && r<=20927) return R20.Condition(r-20864);
  if (r>=20928 && r<=20991) return R21.Condition(r-20928);
  if (r>=20992 && r<=21055) return R22.Condition(r-20992);
  if (r>=21056 && r<=21119) return R23.Condition(r-21056);
  if (r>=21120 && r<=21183) return R24.Condition(r-21120);
  if (r>=21184 && r<=21247) return R25.Condition(r-21184);
  if (r>=21248 && r<=21311) return R26.Condition(r-21248);
  if (r>=21312 && r<=21375) return R27.Condition(r-21312);
  if (r>=21376 && r<=21439) return R28.Condition(r-21376);
  if (r>=21440 && r<=21503) return R29.Condition(r-21440);
  if (r>=21504 && r<=21759) return R30.Condition(r-21504);
  if (r>=21760 && r<=22015) return R31.Condition(r-21760);
  if (r>=22016 && r<=22271) return R32.Condition(r-22016);
  if (r>=22272 && r<=22527) return R33.Condition(r-22272);
  if (r>=22528 && r<=22783) return R34.Condition(r-22528);
  if (r>=22784 && r<=23039) return R35.Condition(r-22784);
  if (r>=23040 && r<=23295) return R36.Condition(r-23040);
  if (r>=23296 && r<=24319) return R37.Condition(r-23296);
  if (r>=24320 && r<=25343) return R38.Condition(r-24320);
  if (r>=25344 && r<=25359) return R39.Condition(r-25344);
  if (r>=25360 && r<=25375) return R40.Condition(r-25360);
  if (r>=25376 && r<=25391) return R41.Condition(r-25376);
  if (r>=25392 && r<=25407) return R42.Condition(r-25392);
  if (r>=25408 && r<=25423) return R43.Condition(r-25408);
  if (r>=25424 && r<=25439) return R44.Condition(r-25424);
  if (r>=25440 && r<=25455) return R45.Condition(r-25440);
  if (r>=25456 && r<=25471) return R46.Condition(r-25456);
  if (r>=25472 && r<=25487) return R47.Condition(r-25472);
  if (r>=25488 && r<=25503) return R48.Condition(r-25488);
  if (r>=25504 && r<=25567) return R49.Condition(r-25504);
  if (r>=25568 && r<=25631) return R50.Condition(r-25568);
  if (r>=25632 && r<=25695) return R51.Condition(r-25632);
  if (r>=25696 && r<=25759) return R52.Condition(r-25696);
  if (r>=25760 && r<=26015) return R53.Condition(r-25760);
  if (r>=26016 && r<=26019) return R54.Condition(r-26016);
  if (r>=26020 && r<=26023) return R55.Condition(r-26020);
  if (r>=26024 && r<=26027) return R56.Condition(r-26024);
  if (r>=26028 && r<=26031) return R57.Condition(r-26028);
  if (r>=26032 && r<=26047) return R58.Condition(r-26032);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=255) { R0.Code(r-0); return; } 
  if (r>=256 && r<=511) { R1.Code(r-256); return; } 
  if (r>=512 && r<=767) { R2.Code(r-512); return; } 
  if (r>=768 && r<=1023) { R3.Code(r-768); return; } 
  if (r>=1024 && r<=1279) { R4.Code(r-1024); return; } 
  if (r>=1280 && r<=1535) { R5.Code(r-1280); return; } 
  if (r>=1536 && r<=1791) { R6.Code(r-1536); return; } 
  if (r>=1792 && r<=2047) { R7.Code(r-1792); return; } 
  if (r>=2048 && r<=2303) { R8.Code(r-2048); return; } 
  if (r>=2304 && r<=3327) { R9.Code(r-2304); return; } 
  if (r>=3328 && r<=4351) { R10.Code(r-3328); return; } 
  if (r>=4352 && r<=5375) { R11.Code(r-4352); return; } 
  if (r>=5376 && r<=6399) { R12.Code(r-5376); return; } 
  if (r>=6400 && r<=7423) { R13.Code(r-6400); return; } 
  if (r>=7424 && r<=8447) { R14.Code(r-7424); return; } 
  if (r>=8448 && r<=12543) { R15.Code(r-8448); return; } 
  if (r>=12544 && r<=16639) { R16.Code(r-12544); return; } 
  if (r>=16640 && r<=20735) { R17.Code(r-16640); return; } 
  if (r>=20736 && r<=20799) { R18.Code(r-20736); return; } 
  if (r>=20800 && r<=20863) { R19.Code(r-20800); return; } 
  if (r>=20864 && r<=20927) { R20.Code(r-20864); return; } 
  if (r>=20928 && r<=20991) { R21.Code(r-20928); return; } 
  if (r>=20992 && r<=21055) { R22.Code(r-20992); return; } 
  if (r>=21056 && r<=21119) { R23.Code(r-21056); return; } 
  if (r>=21120 && r<=21183) { R24.Code(r-21120); return; } 
  if (r>=21184 && r<=21247) { R25.Code(r-21184); return; } 
  if (r>=21248 && r<=21311) { R26.Code(r-21248); return; } 
  if (r>=21312 && r<=21375) { R27.Code(r-21312); return; } 
  if (r>=21376 && r<=21439) { R28.Code(r-21376); return; } 
  if (r>=21440 && r<=21503) { R29.Code(r-21440); return; } 
  if (r>=21504 && r<=21759) { R30.Code(r-21504); return; } 
  if (r>=21760 && r<=22015) { R31.Code(r-21760); return; } 
  if (r>=22016 && r<=22271) { R32.Code(r-22016); return; } 
  if (r>=22272 && r<=22527) { R33.Code(r-22272); return; } 
  if (r>=22528 && r<=22783) { R34.Code(r-22528); return; } 
  if (r>=22784 && r<=23039) { R35.Code(r-22784); return; } 
  if (r>=23040 && r<=23295) { R36.Code(r-23040); return; } 
  if (r>=23296 && r<=24319) { R37.Code(r-23296); return; } 
  if (r>=24320 && r<=25343) { R38.Code(r-24320); return; } 
  if (r>=25344 && r<=25359) { R39.Code(r-25344); return; } 
  if (r>=25360 && r<=25375) { R40.Code(r-25360); return; } 
  if (r>=25376 && r<=25391) { R41.Code(r-25376); return; } 
  if (r>=25392 && r<=25407) { R42.Code(r-25392); return; } 
  if (r>=25408 && r<=25423) { R43.Code(r-25408); return; } 
  if (r>=25424 && r<=25439) { R44.Code(r-25424); return; } 
  if (r>=25440 && r<=25455) { R45.Code(r-25440); return; } 
  if (r>=25456 && r<=25471) { R46.Code(r-25456); return; } 
  if (r>=25472 && r<=25487) { R47.Code(r-25472); return; } 
  if (r>=25488 && r<=25503) { R48.Code(r-25488); return; } 
  if (r>=25504 && r<=25567) { R49.Code(r-25504); return; } 
  if (r>=25568 && r<=25631) { R50.Code(r-25568); return; } 
  if (r>=25632 && r<=25695) { R51.Code(r-25632); return; } 
  if (r>=25696 && r<=25759) { R52.Code(r-25696); return; } 
  if (r>=25760 && r<=26015) { R53.Code(r-25760); return; } 
  if (r>=26016 && r<=26019) { R54.Code(r-26016); return; } 
  if (r>=26020 && r<=26023) { R55.Code(r-26020); return; } 
  if (r>=26024 && r<=26027) { R56.Code(r-26024); return; } 
  if (r>=26028 && r<=26031) { R57.Code(r-26028); return; } 
  if (r>=26032 && r<=26047) { R58.Code(r-26032); return; } 
}
int Priority(unsigned short r)
{
  if (r<=255) { return R0.Priority(); } 
  if (r>=256 && r<=511) { return R1.Priority(); } 
  if (r>=512 && r<=767) { return R2.Priority(); } 
  if (r>=768 && r<=1023) { return R3.Priority(); } 
  if (r>=1024 && r<=1279) { return R4.Priority(); } 
  if (r>=1280 && r<=1535) { return R5.Priority(); } 
  if (r>=1536 && r<=1791) { return R6.Priority(); } 
  if (r>=1792 && r<=2047) { return R7.Priority(); } 
  if (r>=2048 && r<=2303) { return R8.Priority(); } 
  if (r>=2304 && r<=3327) { return R9.Priority(); } 
  if (r>=3328 && r<=4351) { return R10.Priority(); } 
  if (r>=4352 && r<=5375) { return R11.Priority(); } 
  if (r>=5376 && r<=6399) { return R12.Priority(); } 
  if (r>=6400 && r<=7423) { return R13.Priority(); } 
  if (r>=7424 && r<=8447) { return R14.Priority(); } 
  if (r>=8448 && r<=12543) { return R15.Priority(); } 
  if (r>=12544 && r<=16639) { return R16.Priority(); } 
  if (r>=16640 && r<=20735) { return R17.Priority(); } 
  if (r>=20736 && r<=20799) { return R18.Priority(); } 
  if (r>=20800 && r<=20863) { return R19.Priority(); } 
  if (r>=20864 && r<=20927) { return R20.Priority(); } 
  if (r>=20928 && r<=20991) { return R21.Priority(); } 
  if (r>=20992 && r<=21055) { return R22.Priority(); } 
  if (r>=21056 && r<=21119) { return R23.Priority(); } 
  if (r>=21120 && r<=21183) { return R24.Priority(); } 
  if (r>=21184 && r<=21247) { return R25.Priority(); } 
  if (r>=21248 && r<=21311) { return R26.Priority(); } 
  if (r>=21312 && r<=21375) { return R27.Priority(); } 
  if (r>=21376 && r<=21439) { return R28.Priority(); } 
  if (r>=21440 && r<=21503) { return R29.Priority(); } 
  if (r>=21504 && r<=21759) { return R30.Priority(); } 
  if (r>=21760 && r<=22015) { return R31.Priority(); } 
  if (r>=22016 && r<=22271) { return R32.Priority(); } 
  if (r>=22272 && r<=22527) { return R33.Priority(); } 
  if (r>=22528 && r<=22783) { return R34.Priority(); } 
  if (r>=22784 && r<=23039) { return R35.Priority(); } 
  if (r>=23040 && r<=23295) { return R36.Priority(); } 
  if (r>=23296 && r<=24319) { return R37.Priority(); } 
  if (r>=24320 && r<=25343) { return R38.Priority(); } 
  if (r>=25344 && r<=25359) { return R39.Priority(); } 
  if (r>=25360 && r<=25375) { return R40.Priority(); } 
  if (r>=25376 && r<=25391) { return R41.Priority(); } 
  if (r>=25392 && r<=25407) { return R42.Priority(); } 
  if (r>=25408 && r<=25423) { return R43.Priority(); } 
  if (r>=25424 && r<=25439) { return R44.Priority(); } 
  if (r>=25440 && r<=25455) { return R45.Priority(); } 
  if (r>=25456 && r<=25471) { return R46.Priority(); } 
  if (r>=25472 && r<=25487) { return R47.Priority(); } 
  if (r>=25488 && r<=25503) { return R48.Priority(); } 
  if (r>=25504 && r<=25567) { return R49.Priority(); } 
  if (r>=25568 && r<=25631) { return R50.Priority(); } 
  if (r>=25632 && r<=25695) { return R51.Priority(); } 
  if (r>=25696 && r<=25759) { return R52.Priority(); } 
  if (r>=25760 && r<=26015) { return R53.Priority(); } 
  if (r>=26016 && r<=26019) { return R54.Priority(); } 
  if (r>=26020 && r<=26023) { return R55.Priority(); } 
  if (r>=26024 && r<=26027) { return R56.Priority(); } 
  if (r>=26028 && r<=26031) { return R57.Priority(); } 
  if (r>=26032 && r<=26047) { return R58.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=255) return R0.Name(r-0);
  if (r>=256 && r<=511) return R1.Name(r-256);
  if (r>=512 && r<=767) return R2.Name(r-512);
  if (r>=768 && r<=1023) return R3.Name(r-768);
  if (r>=1024 && r<=1279) return R4.Name(r-1024);
  if (r>=1280 && r<=1535) return R5.Name(r-1280);
  if (r>=1536 && r<=1791) return R6.Name(r-1536);
  if (r>=1792 && r<=2047) return R7.Name(r-1792);
  if (r>=2048 && r<=2303) return R8.Name(r-2048);
  if (r>=2304 && r<=3327) return R9.Name(r-2304);
  if (r>=3328 && r<=4351) return R10.Name(r-3328);
  if (r>=4352 && r<=5375) return R11.Name(r-4352);
  if (r>=5376 && r<=6399) return R12.Name(r-5376);
  if (r>=6400 && r<=7423) return R13.Name(r-6400);
  if (r>=7424 && r<=8447) return R14.Name(r-7424);
  if (r>=8448 && r<=12543) return R15.Name(r-8448);
  if (r>=12544 && r<=16639) return R16.Name(r-12544);
  if (r>=16640 && r<=20735) return R17.Name(r-16640);
  if (r>=20736 && r<=20799) return R18.Name(r-20736);
  if (r>=20800 && r<=20863) return R19.Name(r-20800);
  if (r>=20864 && r<=20927) return R20.Name(r-20864);
  if (r>=20928 && r<=20991) return R21.Name(r-20928);
  if (r>=20992 && r<=21055) return R22.Name(r-20992);
  if (r>=21056 && r<=21119) return R23.Name(r-21056);
  if (r>=21120 && r<=21183) return R24.Name(r-21120);
  if (r>=21184 && r<=21247) return R25.Name(r-21184);
  if (r>=21248 && r<=21311) return R26.Name(r-21248);
  if (r>=21312 && r<=21375) return R27.Name(r-21312);
  if (r>=21376 && r<=21439) return R28.Name(r-21376);
  if (r>=21440 && r<=21503) return R29.Name(r-21440);
  if (r>=21504 && r<=21759) return R30.Name(r-21504);
  if (r>=21760 && r<=22015) return R31.Name(r-21760);
  if (r>=22016 && r<=22271) return R32.Name(r-22016);
  if (r>=22272 && r<=22527) return R33.Name(r-22272);
  if (r>=22528 && r<=22783) return R34.Name(r-22528);
  if (r>=22784 && r<=23039) return R35.Name(r-22784);
  if (r>=23040 && r<=23295) return R36.Name(r-23040);
  if (r>=23296 && r<=24319) return R37.Name(r-23296);
  if (r>=24320 && r<=25343) return R38.Name(r-24320);
  if (r>=25344 && r<=25359) return R39.Name(r-25344);
  if (r>=25360 && r<=25375) return R40.Name(r-25360);
  if (r>=25376 && r<=25391) return R41.Name(r-25376);
  if (r>=25392 && r<=25407) return R42.Name(r-25392);
  if (r>=25408 && r<=25423) return R43.Name(r-25408);
  if (r>=25424 && r<=25439) return R44.Name(r-25424);
  if (r>=25440 && r<=25455) return R45.Name(r-25440);
  if (r>=25456 && r<=25471) return R46.Name(r-25456);
  if (r>=25472 && r<=25487) return R47.Name(r-25472);
  if (r>=25488 && r<=25503) return R48.Name(r-25488);
  if (r>=25504 && r<=25567) return R49.Name(r-25504);
  if (r>=25568 && r<=25631) return R50.Name(r-25568);
  if (r>=25632 && r<=25695) return R51.Name(r-25632);
  if (r>=25696 && r<=25759) return R52.Name(r-25696);
  if (r>=25760 && r<=26015) return R53.Name(r-25760);
  if (r>=26016 && r<=26019) return R54.Name(r-26016);
  if (r>=26020 && r<=26023) return R55.Name(r-26020);
  if (r>=26024 && r<=26027) return R56.Name(r-26024);
  if (r>=26028 && r<=26031) return R57.Name(r-26028);
  if (r>=26032 && r<=26047) return R58.Name(r-26032);
  return NULL;
}
};
const unsigned numrules = 26048;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 26048


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
for(int mu_nid1 = 0; mu_nid1 <= 3; mu_nid1++) {
{
for(int mu_nid2 = 0; mu_nid2 <= 3; mu_nid2++) {
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
for(int mu_nid = 0; mu_nid <= 3; mu_nid++) {
if ( (mu_nid) != (3) )
{
mu_ExitPath[mu_nid] = (mu_nid) + (1);
if ( (mu_nid) == (0) )
{
mu_EntryPath[mu_nid] = 3;
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
{
for(int mu_nid = 0; mu_nid <= 3; mu_nid++) {
mu_Routers[mu_nid] = 0;
};
};
mu_Routers[1] = 1;
mu_Routers[3] = 1;
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
RouterStatus:NoScalarset
IncomingQueue:NoScalarset
TailPointers:NoScalarset
Routers:NoScalarset
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
        mu_RouterStatus.MultisetSort();
        mu_IncomingQueue.MultisetSort();
        mu_TailPointers.MultisetSort();
        mu_Routers.MultisetSort();
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
  for (j=0; j<4; j++)
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
  for (j=0; j<4; j++)
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
  for (j=0; j<4; j++)
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
  for (j=0; j<4; j++)
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
  for (j=0; j<5; j++)
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
void mu_1__type_7::Permute(PermSet& Perm, int i) {};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_7::Canonicalize(PermSet& Perm) {};
void mu_1__type_7::SimpleLimit(PermSet& Perm) {};
void mu_1__type_7::ArrayLimit(PermSet& Perm) {};
void mu_1__type_7::Limit(PermSet& Perm) {};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<4; j++)
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
void mu_1__type_9::Permute(PermSet& Perm, int i)
{
  static mu_1__type_9 temp("Permute_mu_1__type_9",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_9::Canonicalize(PermSet& Perm){};
void mu_1__type_9::SimpleLimit(PermSet& Perm){}
void mu_1__type_9::ArrayLimit(PermSet& Perm) {}
void mu_1__type_9::Limit(PermSet& Perm){}
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i)
{
  static mu_1__type_10 temp("Permute_mu_1__type_10",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_10::Canonicalize(PermSet& Perm){};
void mu_1__type_10::SimpleLimit(PermSet& Perm){}
void mu_1__type_10::ArrayLimit(PermSet& Perm) {}
void mu_1__type_10::Limit(PermSet& Perm){}
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
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
void mu__subrange_191::Permute(PermSet& Perm, int i) {};
void mu__subrange_191::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_191::Canonicalize(PermSet& Perm) {};
void mu__subrange_191::SimpleLimit(PermSet& Perm) {};
void mu__subrange_191::ArrayLimit(PermSet& Perm) {};
void mu__subrange_191::Limit(PermSet& Perm) {};
void mu__subrange_191::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_192::Permute(PermSet& Perm, int i) {};
void mu__subrange_192::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_192::Canonicalize(PermSet& Perm) {};
void mu__subrange_192::SimpleLimit(PermSet& Perm) {};
void mu__subrange_192::ArrayLimit(PermSet& Perm) {};
void mu__subrange_192::Limit(PermSet& Perm) {};
void mu__subrange_192::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_193::Permute(PermSet& Perm, int i) {};
void mu__subrange_193::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_193::Canonicalize(PermSet& Perm) {};
void mu__subrange_193::SimpleLimit(PermSet& Perm) {};
void mu__subrange_193::ArrayLimit(PermSet& Perm) {};
void mu__subrange_193::Limit(PermSet& Perm) {};
void mu__subrange_193::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_194::Permute(PermSet& Perm, int i) {};
void mu__subrange_194::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_194::Canonicalize(PermSet& Perm) {};
void mu__subrange_194::SimpleLimit(PermSet& Perm) {};
void mu__subrange_194::ArrayLimit(PermSet& Perm) {};
void mu__subrange_194::Limit(PermSet& Perm) {};
void mu__subrange_194::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_195::Permute(PermSet& Perm, int i) {};
void mu__subrange_195::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_195::Canonicalize(PermSet& Perm) {};
void mu__subrange_195::SimpleLimit(PermSet& Perm) {};
void mu__subrange_195::ArrayLimit(PermSet& Perm) {};
void mu__subrange_195::Limit(PermSet& Perm) {};
void mu__subrange_195::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_196::Permute(PermSet& Perm, int i) {};
void mu__subrange_196::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_196::Canonicalize(PermSet& Perm) {};
void mu__subrange_196::SimpleLimit(PermSet& Perm) {};
void mu__subrange_196::ArrayLimit(PermSet& Perm) {};
void mu__subrange_196::Limit(PermSet& Perm) {};
void mu__subrange_196::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_197::Permute(PermSet& Perm, int i) {};
void mu__subrange_197::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_197::Canonicalize(PermSet& Perm) {};
void mu__subrange_197::SimpleLimit(PermSet& Perm) {};
void mu__subrange_197::ArrayLimit(PermSet& Perm) {};
void mu__subrange_197::Limit(PermSet& Perm) {};
void mu__subrange_197::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_198::Permute(PermSet& Perm, int i) {};
void mu__subrange_198::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_198::Canonicalize(PermSet& Perm) {};
void mu__subrange_198::SimpleLimit(PermSet& Perm) {};
void mu__subrange_198::ArrayLimit(PermSet& Perm) {};
void mu__subrange_198::Limit(PermSet& Perm) {};
void mu__subrange_198::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_199::Permute(PermSet& Perm, int i) {};
void mu__subrange_199::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_199::Canonicalize(PermSet& Perm) {};
void mu__subrange_199::SimpleLimit(PermSet& Perm) {};
void mu__subrange_199::ArrayLimit(PermSet& Perm) {};
void mu__subrange_199::Limit(PermSet& Perm) {};
void mu__subrange_199::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_200::Permute(PermSet& Perm, int i) {};
void mu__subrange_200::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_200::Canonicalize(PermSet& Perm) {};
void mu__subrange_200::SimpleLimit(PermSet& Perm) {};
void mu__subrange_200::ArrayLimit(PermSet& Perm) {};
void mu__subrange_200::Limit(PermSet& Perm) {};
void mu__subrange_200::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_201::Permute(PermSet& Perm, int i) {};
void mu__subrange_201::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_201::Canonicalize(PermSet& Perm) {};
void mu__subrange_201::SimpleLimit(PermSet& Perm) {};
void mu__subrange_201::ArrayLimit(PermSet& Perm) {};
void mu__subrange_201::Limit(PermSet& Perm) {};
void mu__subrange_201::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_202::Permute(PermSet& Perm, int i) {};
void mu__subrange_202::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_202::Canonicalize(PermSet& Perm) {};
void mu__subrange_202::SimpleLimit(PermSet& Perm) {};
void mu__subrange_202::ArrayLimit(PermSet& Perm) {};
void mu__subrange_202::Limit(PermSet& Perm) {};
void mu__subrange_202::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_203::Permute(PermSet& Perm, int i) {};
void mu__subrange_203::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_203::Canonicalize(PermSet& Perm) {};
void mu__subrange_203::SimpleLimit(PermSet& Perm) {};
void mu__subrange_203::ArrayLimit(PermSet& Perm) {};
void mu__subrange_203::Limit(PermSet& Perm) {};
void mu__subrange_203::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_204::Permute(PermSet& Perm, int i) {};
void mu__subrange_204::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_204::Canonicalize(PermSet& Perm) {};
void mu__subrange_204::SimpleLimit(PermSet& Perm) {};
void mu__subrange_204::ArrayLimit(PermSet& Perm) {};
void mu__subrange_204::Limit(PermSet& Perm) {};
void mu__subrange_204::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_205::Permute(PermSet& Perm, int i) {};
void mu__subrange_205::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_205::Canonicalize(PermSet& Perm) {};
void mu__subrange_205::SimpleLimit(PermSet& Perm) {};
void mu__subrange_205::ArrayLimit(PermSet& Perm) {};
void mu__subrange_205::Limit(PermSet& Perm) {};
void mu__subrange_205::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_206::Permute(PermSet& Perm, int i) {};
void mu__subrange_206::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_206::Canonicalize(PermSet& Perm) {};
void mu__subrange_206::SimpleLimit(PermSet& Perm) {};
void mu__subrange_206::ArrayLimit(PermSet& Perm) {};
void mu__subrange_206::Limit(PermSet& Perm) {};
void mu__subrange_206::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_207::Permute(PermSet& Perm, int i) {};
void mu__subrange_207::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_207::Canonicalize(PermSet& Perm) {};
void mu__subrange_207::SimpleLimit(PermSet& Perm) {};
void mu__subrange_207::ArrayLimit(PermSet& Perm) {};
void mu__subrange_207::Limit(PermSet& Perm) {};
void mu__subrange_207::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_208::Permute(PermSet& Perm, int i) {};
void mu__subrange_208::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_208::Canonicalize(PermSet& Perm) {};
void mu__subrange_208::SimpleLimit(PermSet& Perm) {};
void mu__subrange_208::ArrayLimit(PermSet& Perm) {};
void mu__subrange_208::Limit(PermSet& Perm) {};
void mu__subrange_208::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_209::Permute(PermSet& Perm, int i) {};
void mu__subrange_209::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_209::Canonicalize(PermSet& Perm) {};
void mu__subrange_209::SimpleLimit(PermSet& Perm) {};
void mu__subrange_209::ArrayLimit(PermSet& Perm) {};
void mu__subrange_209::Limit(PermSet& Perm) {};
void mu__subrange_209::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_210::Permute(PermSet& Perm, int i) {};
void mu__subrange_210::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_210::Canonicalize(PermSet& Perm) {};
void mu__subrange_210::SimpleLimit(PermSet& Perm) {};
void mu__subrange_210::ArrayLimit(PermSet& Perm) {};
void mu__subrange_210::Limit(PermSet& Perm) {};
void mu__subrange_210::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_211::Permute(PermSet& Perm, int i) {};
void mu__subrange_211::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_211::Canonicalize(PermSet& Perm) {};
void mu__subrange_211::SimpleLimit(PermSet& Perm) {};
void mu__subrange_211::ArrayLimit(PermSet& Perm) {};
void mu__subrange_211::Limit(PermSet& Perm) {};
void mu__subrange_211::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_212::Permute(PermSet& Perm, int i) {};
void mu__subrange_212::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_212::Canonicalize(PermSet& Perm) {};
void mu__subrange_212::SimpleLimit(PermSet& Perm) {};
void mu__subrange_212::ArrayLimit(PermSet& Perm) {};
void mu__subrange_212::Limit(PermSet& Perm) {};
void mu__subrange_212::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_213::Permute(PermSet& Perm, int i) {};
void mu__subrange_213::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_213::Canonicalize(PermSet& Perm) {};
void mu__subrange_213::SimpleLimit(PermSet& Perm) {};
void mu__subrange_213::ArrayLimit(PermSet& Perm) {};
void mu__subrange_213::Limit(PermSet& Perm) {};
void mu__subrange_213::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_214::Permute(PermSet& Perm, int i) {};
void mu__subrange_214::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_214::Canonicalize(PermSet& Perm) {};
void mu__subrange_214::SimpleLimit(PermSet& Perm) {};
void mu__subrange_214::ArrayLimit(PermSet& Perm) {};
void mu__subrange_214::Limit(PermSet& Perm) {};
void mu__subrange_214::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_215::Permute(PermSet& Perm, int i) {};
void mu__subrange_215::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_215::Canonicalize(PermSet& Perm) {};
void mu__subrange_215::SimpleLimit(PermSet& Perm) {};
void mu__subrange_215::ArrayLimit(PermSet& Perm) {};
void mu__subrange_215::Limit(PermSet& Perm) {};
void mu__subrange_215::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_216::Permute(PermSet& Perm, int i) {};
void mu__subrange_216::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_216::Canonicalize(PermSet& Perm) {};
void mu__subrange_216::SimpleLimit(PermSet& Perm) {};
void mu__subrange_216::ArrayLimit(PermSet& Perm) {};
void mu__subrange_216::Limit(PermSet& Perm) {};
void mu__subrange_216::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_217::Permute(PermSet& Perm, int i) {};
void mu__subrange_217::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_217::Canonicalize(PermSet& Perm) {};
void mu__subrange_217::SimpleLimit(PermSet& Perm) {};
void mu__subrange_217::ArrayLimit(PermSet& Perm) {};
void mu__subrange_217::Limit(PermSet& Perm) {};
void mu__subrange_217::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_218::Permute(PermSet& Perm, int i) {};
void mu__subrange_218::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_218::Canonicalize(PermSet& Perm) {};
void mu__subrange_218::SimpleLimit(PermSet& Perm) {};
void mu__subrange_218::ArrayLimit(PermSet& Perm) {};
void mu__subrange_218::Limit(PermSet& Perm) {};
void mu__subrange_218::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_219::Permute(PermSet& Perm, int i) {};
void mu__subrange_219::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_219::Canonicalize(PermSet& Perm) {};
void mu__subrange_219::SimpleLimit(PermSet& Perm) {};
void mu__subrange_219::ArrayLimit(PermSet& Perm) {};
void mu__subrange_219::Limit(PermSet& Perm) {};
void mu__subrange_219::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_220::Permute(PermSet& Perm, int i) {};
void mu__subrange_220::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_220::Canonicalize(PermSet& Perm) {};
void mu__subrange_220::SimpleLimit(PermSet& Perm) {};
void mu__subrange_220::ArrayLimit(PermSet& Perm) {};
void mu__subrange_220::Limit(PermSet& Perm) {};
void mu__subrange_220::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_221::Permute(PermSet& Perm, int i) {};
void mu__subrange_221::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_221::Canonicalize(PermSet& Perm) {};
void mu__subrange_221::SimpleLimit(PermSet& Perm) {};
void mu__subrange_221::ArrayLimit(PermSet& Perm) {};
void mu__subrange_221::Limit(PermSet& Perm) {};
void mu__subrange_221::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_222::Permute(PermSet& Perm, int i) {};
void mu__subrange_222::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_222::Canonicalize(PermSet& Perm) {};
void mu__subrange_222::SimpleLimit(PermSet& Perm) {};
void mu__subrange_222::ArrayLimit(PermSet& Perm) {};
void mu__subrange_222::Limit(PermSet& Perm) {};
void mu__subrange_222::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_223::Permute(PermSet& Perm, int i) {};
void mu__subrange_223::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_223::Canonicalize(PermSet& Perm) {};
void mu__subrange_223::SimpleLimit(PermSet& Perm) {};
void mu__subrange_223::ArrayLimit(PermSet& Perm) {};
void mu__subrange_223::Limit(PermSet& Perm) {};
void mu__subrange_223::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_224::Permute(PermSet& Perm, int i) {};
void mu__subrange_224::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_224::Canonicalize(PermSet& Perm) {};
void mu__subrange_224::SimpleLimit(PermSet& Perm) {};
void mu__subrange_224::ArrayLimit(PermSet& Perm) {};
void mu__subrange_224::Limit(PermSet& Perm) {};
void mu__subrange_224::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_225::Permute(PermSet& Perm, int i) {};
void mu__subrange_225::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_225::Canonicalize(PermSet& Perm) {};
void mu__subrange_225::SimpleLimit(PermSet& Perm) {};
void mu__subrange_225::ArrayLimit(PermSet& Perm) {};
void mu__subrange_225::Limit(PermSet& Perm) {};
void mu__subrange_225::MultisetLimit(PermSet& Perm)
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
              
              mu_RouterStatus.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_RouterStatus.MultisetSort();
              mu_IncomingQueue.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_TailPointers.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
              mu_Routers.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Routers.MultisetSort();
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

          mu_RouterStatus.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_RouterStatus.MultisetSort();
          mu_IncomingQueue.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_IncomingQueue.MultisetSort();
          mu_TailPointers.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_TailPointers.MultisetSort();
          mu_Routers.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Routers.MultisetSort();
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
              
              mu_RouterStatus.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_RouterStatus.MultisetSort();
              mu_IncomingQueue.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_IncomingQueue.MultisetSort();
              mu_TailPointers.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_TailPointers.MultisetSort();
              mu_Routers.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Routers.MultisetSort();
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
      mu_RouterStatus.MultisetSort();
      mu_IncomingQueue.MultisetSort();
      mu_TailPointers.MultisetSort();
      mu_Routers.MultisetSort();
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

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Routers.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Routers.MultisetSort();
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
