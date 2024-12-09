/******************************
  Program "symmetry_skeleton_bi-uni.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "symmetry_skeleton_bi-uni"
#define BITS_IN_WORLD 198
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
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_NodeIDs& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_NodeIDs& val)
    {
      if (val.defined())
	return ( s << mu_1_NodeIDs::values[ int(val) - 6 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_NodeIDs (const char *name, int os): mu__byte(6, 8, 2, name, os) {};
  mu_1_NodeIDs (void): mu__byte(6, 8, 2) {};
  mu_1_NodeIDs (int val): mu__byte(6, 8, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -6]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 6] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_NodeIDs& a, mu_1_NodeIDs& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_NodeIDs::values[] =
  { "NodeIDs_1","NodeIDs_2","NodeIDs_3",NULL };

/*** end scalarset declaration ***/
mu_1_NodeIDs mu_1_NodeIDs_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 3, 3) {};
  mu_1__type_0 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 3, 3) {};
  mu_1__type_1 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MessageState mu_msg_type;
  mu_1__type_0 mu_dest_hops;
  mu_1__type_1 mu_src_hops;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_msg_type, b.mu_msg_type);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dest_hops, b.mu_dest_hops);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src_hops, b.mu_src_hops);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_msg_type, b.mu_msg_type);
    if (w!=0) return w;
    w = Compare(a.mu_dest_hops, b.mu_dest_hops);
    if (w!=0) return w;
    w = Compare(a.mu_src_hops, b.mu_src_hops);
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
    mu_dest_hops.MultisetSort();
    mu_src_hops.MultisetSort();
  }
  void print_statistic()
  {
    mu_msg_type.print_statistic();
    mu_dest_hops.print_statistic();
    mu_src_hops.print_statistic();
  }
  void clear() {
    mu_msg_type.clear();
    mu_dest_hops.clear();
    mu_src_hops.clear();
 };
  void undefine() {
    mu_msg_type.undefine();
    mu_dest_hops.undefine();
    mu_src_hops.undefine();
 };
  void reset() {
    mu_msg_type.reset();
    mu_dest_hops.reset();
    mu_src_hops.reset();
 };
  void print() {
    mu_msg_type.print();
    mu_dest_hops.print();
    mu_src_hops.print();
  };
  void print_diff(state *prevstate) {
    mu_msg_type.print_diff(prevstate);
    mu_dest_hops.print_diff(prevstate);
    mu_src_hops.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_msg_type.to_state(thestate);
    mu_dest_hops.to_state(thestate);
    mu_src_hops.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_msg_type.value(from.mu_msg_type.value());
    mu_dest_hops.value(from.mu_dest_hops.value());
    mu_src_hops.value(from.mu_src_hops.value());
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
  if (name) mu_dest_hops.set_self_2(name, ".dest_hops", os + 3 ); else mu_dest_hops.set_self_2(NULL, NULL, 0);
  if (name) mu_src_hops.set_self_2(name, ".src_hops", os + 6 ); else mu_src_hops.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu__subrange_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_8& val) { return mu__byte::operator=((int) val); };
  mu__subrange_8 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_8 (void): mu__byte(0, 2, 2) {};
  mu__subrange_8 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_8 mu__subrange_8_undefined_var;

class mu_1__type_2
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
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
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
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
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 9 + os);
    delete[] s;
  }
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu__subrange_10: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_10& val) { return mu__byte::operator=((int) val); };
  mu__subrange_10 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_10 (void): mu__byte(0, 2, 2) {};
  mu__subrange_10 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_10 mu__subrange_10_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
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
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
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
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 9 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_4& val) { return mu__byte::operator=((int) val); };
  mu_1__type_4 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_4 (void): mu__byte(0, 3, 3) {};
  mu_1__type_4 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_5& val) { return mu__byte::operator=((int) val); };
  mu_1__type_5 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_5 (void): mu__byte(0, 3, 3) {};
  mu_1__type_5 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu_1__type_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_6& val) { return mu__byte::operator=((int) val); };
  mu_1__type_6 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_6 (void): mu__byte(0, 1, 2) {};
  mu_1__type_6 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1_Node
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_2 mu_IncomingQueue_CC;
  mu_1__type_3 mu_IncomingQueue_AC;
  mu_1__type_4 mu_TailPointer_CC;
  mu_1__type_5 mu_TailPointer_AC;
  mu_1__type_6 mu_FrontPointer;
  mu_1_NodeIDs mu_Next_CC;
  mu_1_NodeIDs mu_Next_AC;
  mu_1_Node ( const char *n, int os ) { set_self(n,os); };
  mu_1_Node ( void ) {};

  virtual ~mu_1_Node(); 
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
  {
    int w;
    w = CompareWeight(a.mu_IncomingQueue_CC, b.mu_IncomingQueue_CC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_IncomingQueue_AC, b.mu_IncomingQueue_AC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_TailPointer_CC, b.mu_TailPointer_CC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_TailPointer_AC, b.mu_TailPointer_AC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_FrontPointer, b.mu_FrontPointer);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Next_CC, b.mu_Next_CC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Next_AC, b.mu_Next_AC);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Node& a, mu_1_Node& b)
  {
    int w;
    w = Compare(a.mu_IncomingQueue_CC, b.mu_IncomingQueue_CC);
    if (w!=0) return w;
    w = Compare(a.mu_IncomingQueue_AC, b.mu_IncomingQueue_AC);
    if (w!=0) return w;
    w = Compare(a.mu_TailPointer_CC, b.mu_TailPointer_CC);
    if (w!=0) return w;
    w = Compare(a.mu_TailPointer_AC, b.mu_TailPointer_AC);
    if (w!=0) return w;
    w = Compare(a.mu_FrontPointer, b.mu_FrontPointer);
    if (w!=0) return w;
    w = Compare(a.mu_Next_CC, b.mu_Next_CC);
    if (w!=0) return w;
    w = Compare(a.mu_Next_AC, b.mu_Next_AC);
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
    mu_IncomingQueue_CC.MultisetSort();
    mu_IncomingQueue_AC.MultisetSort();
    mu_TailPointer_CC.MultisetSort();
    mu_TailPointer_AC.MultisetSort();
    mu_FrontPointer.MultisetSort();
    mu_Next_CC.MultisetSort();
    mu_Next_AC.MultisetSort();
  }
  void print_statistic()
  {
    mu_IncomingQueue_CC.print_statistic();
    mu_IncomingQueue_AC.print_statistic();
    mu_TailPointer_CC.print_statistic();
    mu_TailPointer_AC.print_statistic();
    mu_FrontPointer.print_statistic();
    mu_Next_CC.print_statistic();
    mu_Next_AC.print_statistic();
  }
  void clear() {
    mu_IncomingQueue_CC.clear();
    mu_IncomingQueue_AC.clear();
    mu_TailPointer_CC.clear();
    mu_TailPointer_AC.clear();
    mu_FrontPointer.clear();
    mu_Next_CC.clear();
    mu_Next_AC.clear();
 };
  void undefine() {
    mu_IncomingQueue_CC.undefine();
    mu_IncomingQueue_AC.undefine();
    mu_TailPointer_CC.undefine();
    mu_TailPointer_AC.undefine();
    mu_FrontPointer.undefine();
    mu_Next_CC.undefine();
    mu_Next_AC.undefine();
 };
  void reset() {
    mu_IncomingQueue_CC.reset();
    mu_IncomingQueue_AC.reset();
    mu_TailPointer_CC.reset();
    mu_TailPointer_AC.reset();
    mu_FrontPointer.reset();
    mu_Next_CC.reset();
    mu_Next_AC.reset();
 };
  void print() {
    mu_IncomingQueue_CC.print();
    mu_IncomingQueue_AC.print();
    mu_TailPointer_CC.print();
    mu_TailPointer_AC.print();
    mu_FrontPointer.print();
    mu_Next_CC.print();
    mu_Next_AC.print();
  };
  void print_diff(state *prevstate) {
    mu_IncomingQueue_CC.print_diff(prevstate);
    mu_IncomingQueue_AC.print_diff(prevstate);
    mu_TailPointer_CC.print_diff(prevstate);
    mu_TailPointer_AC.print_diff(prevstate);
    mu_FrontPointer.print_diff(prevstate);
    mu_Next_CC.print_diff(prevstate);
    mu_Next_AC.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_IncomingQueue_CC.to_state(thestate);
    mu_IncomingQueue_AC.to_state(thestate);
    mu_TailPointer_CC.to_state(thestate);
    mu_TailPointer_AC.to_state(thestate);
    mu_FrontPointer.to_state(thestate);
    mu_Next_CC.to_state(thestate);
    mu_Next_AC.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Node& operator= (const mu_1_Node& from) {
    mu_IncomingQueue_CC = from.mu_IncomingQueue_CC;
    mu_IncomingQueue_AC = from.mu_IncomingQueue_AC;
    mu_TailPointer_CC.value(from.mu_TailPointer_CC.value());
    mu_TailPointer_AC.value(from.mu_TailPointer_AC.value());
    mu_FrontPointer.value(from.mu_FrontPointer.value());
    mu_Next_CC.value(from.mu_Next_CC.value());
    mu_Next_AC.value(from.mu_Next_AC.value());
    return *this;
  };
};

  void mu_1_Node::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Node::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Node::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_IncomingQueue_CC.set_self_2(name, ".IncomingQueue_CC", os + 0 ); else mu_IncomingQueue_CC.set_self_2(NULL, NULL, 0);
  if (name) mu_IncomingQueue_AC.set_self_2(name, ".IncomingQueue_AC", os + 27 ); else mu_IncomingQueue_AC.set_self_2(NULL, NULL, 0);
  if (name) mu_TailPointer_CC.set_self_2(name, ".TailPointer_CC", os + 54 ); else mu_TailPointer_CC.set_self_2(NULL, NULL, 0);
  if (name) mu_TailPointer_AC.set_self_2(name, ".TailPointer_AC", os + 57 ); else mu_TailPointer_AC.set_self_2(NULL, NULL, 0);
  if (name) mu_FrontPointer.set_self_2(name, ".FrontPointer", os + 60 ); else mu_FrontPointer.set_self_2(NULL, NULL, 0);
  if (name) mu_Next_CC.set_self_2(name, ".Next_CC", os + 62 ); else mu_Next_CC.set_self_2(NULL, NULL, 0);
  if (name) mu_Next_AC.set_self_2(name, ".Next_AC", os + 64 ); else mu_Next_AC.set_self_2(NULL, NULL, 0);
}

mu_1_Node::~mu_1_Node()
{
}

/*** end record declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1__type_7
{
 public:
  mu_1_Node array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_7 (const char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1_Node& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 8 ) )
      return array[ index - 6 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: NodeIDs is internally represented from 8 to 6.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
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
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"NodeIDs_1", i * 66 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"NodeIDs_2", i * 66 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"NodeIDs_3", i * 66 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_8& val) { return mu__byte::operator=((int) val); };
  mu_1__type_8 (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1__type_8 (void): mu__byte(1, 3, 2) {};
  mu_1__type_8 (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_9& val) { return mu__byte::operator=((int) val); };
  mu_1__type_9 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_9 (void): mu__byte(0, 1, 2) {};
  mu_1__type_9 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_10& val) { return mu__byte::operator=((int) val); };
  mu_1__type_10 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_10 (void): mu__byte(0, 1, 2) {};
  mu_1__type_10 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1__type_11: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_11& val) { return mu__byte::operator=((int) val); };
  mu_1__type_11 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_11 (void): mu__byte(0, 1, 2) {};
  mu_1__type_11 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_11 mu_1__type_11_undefined_var;

class mu_1__type_12: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_12& val) { return mu__byte::operator=((int) val); };
  mu_1__type_12 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_12 (void): mu__byte(0, 1, 2) {};
  mu_1__type_12 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1__type_13: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_13& val) { return mu__byte::operator=((int) val); };
  mu_1__type_13 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_13 (void): mu__byte(0, 1, 2) {};
  mu_1__type_13 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_13 mu_1__type_13_undefined_var;

class mu__subrange_23: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_23& val) { return mu__byte::operator=((int) val); };
  mu__subrange_23 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_23 (void): mu__byte(1, 2, 2) {};
  mu__subrange_23 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_24 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_24 (void): mu__byte(1, 2, 2) {};
  mu__subrange_24 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_26 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_26 (void): mu__byte(1, 2, 2) {};
  mu__subrange_26 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

const int mu_NumberNodes = 3;
const int mu_BufferSpace = 3;
const int mu_empty = 1;
const int mu_response = 2;
const int mu_request = 3;
const int mu_fwd_request = 4;
const int mu_fwd_response = 5;
const int mu_NodeIDs_1 = 6;
const int mu_NodeIDs_2 = 7;
const int mu_NodeIDs_3 = 8;
/*** Variable declaration ***/
mu_1__type_7 mu_Nodes("Nodes",0);

void mu_SendRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_8& mu_next_hop_length, const mu_1__type_9& mu_direction)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_next_hop_length) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
mu_msg_to_send.mu_src_hops = 2;
mu_msg_to_send.mu_dest_hops = (mu_next_hop_length) - (1);
if ( (mu_direction) == (0) )
{
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_IncomingQueue_CC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC) + (1);
}
else
{
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_IncomingQueue_AC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC) + (1);
}
};
/*** end procedure declaration ***/

void mu_ProcessFwdRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_10& mu_direction)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_direction) == (0) )
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) - (1);
{
int mu__ub14 = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
for (int mu_i = 1; mu_i <= mu__ub14; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_CC = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_TailPointer_CC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_IncomingQueue_CC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC) + (1);
}
else
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) - (1);
{
int mu__ub15 = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
for (int mu_i = 1; mu_i <= mu__ub15; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_AC = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_TailPointer_AC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_IncomingQueue_AC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC) + (1);
}
};
/*** end procedure declaration ***/

void mu_ProcessRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_11& mu_direction)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_direction) == (0) )
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub16 = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
for (int mu_i = 1; mu_i <= mu__ub16; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_CC = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_TailPointer_CC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_IncomingQueue_AC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC) + (1);
}
else
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub17 = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
for (int mu_i = 1; mu_i <= mu__ub17; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_AC = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_TailPointer_AC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_IncomingQueue_CC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC) + (1);
}
};
/*** end procedure declaration ***/

void mu_ProcessFwdResponse(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_12& mu_direction)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_direction) == (0) )
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub18 = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
for (int mu_i = 1; mu_i <= mu__ub18; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_CC = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_Nodes[mu_src_nid].mu_TailPointer_CC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_IncomingQueue_CC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_CC].mu_TailPointer_CC) + (1);
}
else
{
if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub19 = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
for (int mu_i = 1; mu_i <= mu__ub19; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer_AC = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_Nodes[mu_src_nid].mu_TailPointer_AC].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_IncomingQueue_AC[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next_AC].mu_TailPointer_AC) + (1);
}
};
/*** end procedure declaration ***/

void mu_ProcessResponse(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_13& mu_direction)
{
if ( (mu_direction) == (0) )
{
{
for(int mu_i = 1; mu_i <= 2; mu_i++) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_i];
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[mu_i].mu_msg_type = mu_empty;
};
};
mu_Nodes[mu_src_nid].mu_IncomingQueue_CC[(mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1)].mu_msg_type = mu_empty;
mu_Nodes[mu_src_nid].mu_TailPointer_CC = (mu_Nodes[mu_src_nid].mu_TailPointer_CC) - (1);
}
else
{
{
for(int mu_i = 1; mu_i <= 2; mu_i++) {
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_i];
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[mu_i].mu_msg_type = mu_empty;
};
};
mu_Nodes[mu_src_nid].mu_IncomingQueue_AC[(mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1)].mu_msg_type = mu_empty;
mu_Nodes[mu_src_nid].mu_TailPointer_AC = (mu_Nodes[mu_src_nid].mu_TailPointer_AC) - (1);
}
};
/*** end procedure declaration ***/

mu_1_NodeIDs mu_GetNextNode(const mu_1_NodeIDs& mu_a)
{
/*** Variable declaration ***/
mu_0_boolean mu_found("found",0);

/*** Variable declaration ***/
mu_1_NodeIDs mu_next("next",2);

mu_found = mu_false;
{
for(int mu_i = 6; mu_i <= 8; mu_i++) {
if ( mu_found )
{
return mu_i;
}
if ( (mu_i) == (mu_a) )
{
mu_found = mu_true;
}
};
};
{
for(int mu_i = 6; mu_i <= 8; mu_i++) {
return mu_i;
};
};
	Error.Error("The end of function GetNextNode reached without returning values.");
};
/*** end function declaration ***/

mu_1_NodeIDs mu_GetPrevNode(const mu_1_NodeIDs& mu_a)
{
/*** Variable declaration ***/
mu_1_NodeIDs mu_prev("prev",0);

/*** Variable declaration ***/
mu_0_boolean mu_first("first",2);

mu_first = mu_true;
{
for(int mu_i = 6; mu_i <= 8; mu_i++) {
if ( (mu_i) == (mu_a) )
{
if ( mu_first )
{
{
for(int mu_j = 6; mu_j <= 8; mu_j++) {
mu_prev = mu_j;
};
};
return mu_prev;
}
else
{
return mu_prev;
}
}
mu_prev = mu_i;
mu_first = mu_false;
};
};
	Error.Error("The end of function GetPrevNode reached without returning values.");
};
/*** end function declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_Nodes.clear();
}
void world_class::undefine()
{
  mu_Nodes.undefine();
}
void world_class::reset()
{
  mu_Nodes.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Nodes.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_Nodes.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_Nodes.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_Nodes.to_state( newstate );
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
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Send request, n2:%s, direction_1:%s, n1:%s", mu_n2.Name(), mu_direction_1.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr20;
  if (!((mu_direction_1) == (1))) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next_AC].mu_TailPointer_AC) < (2)) ; 
}
    return mu__boolexpr20;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr21;
  if (!((mu_direction_1) == (1))) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next_AC].mu_TailPointer_AC) < (2)) ; 
}
	      if (mu__boolexpr21) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 0;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_SendRequest ( mu_n1, (int)mu_n2, 1 );
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
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Send request, n2:%s, direction_1:%s, n1:%s", mu_n2.Name(), mu_direction_1.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr22;
  if (!((mu_direction_1) == (0))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next_CC].mu_TailPointer_CC) < (2)) ; 
}
    return mu__boolexpr22;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 24 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr23;
  if (!((mu_direction_1) == (0))) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next_CC].mu_TailPointer_CC) < (2)) ; 
}
	      if (mu__boolexpr23) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 12;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_26 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_27 mu_direction_1;
    mu_direction_1.value((r % 2) + 0);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_SendRequest ( mu_n1, (int)mu_n2, 0 );
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<12)
    { R0.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<24)
    { R1.NextRule(what_rule);
      if (what_rule<24) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=11) return R0.Condition(r-0);
  if (r>=12 && r<=23) return R1.Condition(r-12);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=11) { R0.Code(r-0); return; } 
  if (r>=12 && r<=23) { R1.Code(r-12); return; } 
}
int Priority(unsigned short r)
{
  if (r<=11) { return R0.Priority(); } 
  if (r>=12 && r<=23) { return R1.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=11) return R0.Name(r-0);
  if (r>=12 && r<=23) return R1.Name(r-12);
  return NULL;
}
};
const unsigned numrules = 24;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 24


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
for(int mu_nid1 = 6; mu_nid1 <= 8; mu_nid1++) {
{
for(int mu_s = 0; mu_s <= 2; mu_s++) {
mu_Nodes[mu_nid1].mu_IncomingQueue_CC[mu_s].mu_msg_type = mu_empty;
mu_Nodes[mu_nid1].mu_IncomingQueue_CC[mu_s].mu_src_hops = 0;
mu_Nodes[mu_nid1].mu_IncomingQueue_CC[mu_s].mu_dest_hops = 0;
mu_Nodes[mu_nid1].mu_IncomingQueue_AC[mu_s].mu_msg_type = mu_empty;
mu_Nodes[mu_nid1].mu_IncomingQueue_AC[mu_s].mu_src_hops = 0;
mu_Nodes[mu_nid1].mu_IncomingQueue_AC[mu_s].mu_dest_hops = 0;
};
};
mu_Nodes[mu_nid1].mu_TailPointer_AC = 0;
mu_Nodes[mu_nid1].mu_TailPointer_CC = 0;
mu_Nodes[mu_nid1].mu_FrontPointer = 0;
mu_Nodes[mu_nid1].mu_Next_CC = mu_GetNextNode( mu_nid1 );
mu_Nodes[mu_nid1].mu_Next_AC = mu_GetPrevNode( mu_nid1 );
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
Nodes:ScalarsetArrayOfScalarset
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
  int class_mu_1_NodeIDs[3];
  int undefined_class_mu_1_NodeIDs;// has the highest class number

  void Print_class_mu_1_NodeIDs();
  bool OnlyOneRemain_mu_1_NodeIDs;
  bool MTO_class_mu_1_NodeIDs()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_NodeIDs)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_NodeIDs[i]== class_mu_1_NodeIDs[j])
	    return TRUE;
    OnlyOneRemain_mu_1_NodeIDs = TRUE;
    return FALSE;
  }
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
  int * in_mu_1_NodeIDs;
  typedef int arr_mu_1_NodeIDs[3];
  arr_mu_1_NodeIDs * perm_mu_1_NodeIDs;
  arr_mu_1_NodeIDs * revperm_mu_1_NodeIDs;

  int size_mu_1_NodeIDs[3];
  bool reversed_sorted_mu_1_NodeIDs(int start, int end);
  void reverse_reversed_mu_1_NodeIDs(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_NodeIDs* perm, int size, mu_1_NodeIDs k);
  void GenPerm0(mu_1_NodeIDs* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_NodeIDs()
{
  cout << "class_mu_1_NodeIDs:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_NodeIDs[i];
  cout << " " << undefined_class_mu_1_NodeIDs << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_NodeIDs[i]== class_mu_1_NodeIDs[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_NodeIDs Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_NodeIDs = new int[6];
 perm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[6];
 revperm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[6];

    // Set perm and revperm
    count = 0;
    for (i=6; i<=8; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=6; j<=8; j++)
        for (k=6; k<=8; k++)
          if (revperm_mu_1_NodeIDs[i][k-6]==j)   // k - base 
            perm_mu_1_NodeIDs[i][j-6]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_NodeIDs = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_NodeIDs[i] = i_mu_1_NodeIDs;
      i_mu_1_NodeIDs += carry;
      if (i_mu_1_NodeIDs >= 6) { i_mu_1_NodeIDs = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_NodeIDs = new int[1];
 perm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[1];
 revperm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[1];
  in[0] = TRUE;
    in_mu_1_NodeIDs[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_NodeIDs[i]=0;
  undefined_class_mu_1_NodeIDs=0;
  OnlyOneRemain_mu_1_NodeIDs = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_NodeIDs[3];
  int size_mu_1_NodeIDs[3];
  bool should_be_in_mu_1_NodeIDs[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NodeIDs; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  {
	    size_mu_1_NodeIDs[k] = class_size;
	    start_mu_1_NodeIDs[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_NodeIDs[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_NodeIDs[i][k]-6 >=start_mu_1_NodeIDs[k] 
	     && perm_mu_1_NodeIDs[i][k]-6 < start_mu_1_NodeIDs[k] + size_mu_1_NodeIDs[k]) )
  	    {
	      should_be_in_mu_1_NodeIDs[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_NodeIDs[in_mu_1_NodeIDs[i]]) in[i] = FALSE;
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
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NodeIDs; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  {
	    size_mu_1_NodeIDs[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NodeIDs; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_NodeIDs[k]==j)
	      revperm_mu_1_NodeIDs[0][start++] = k+6;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_NodeIDs[0][k]==j+6)
        perm_mu_1_NodeIDs[0][j]=k+6;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_NodeIDs* Perm, int size, mu_1_NodeIDs k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_NodeIDs* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=6; i<=8; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=6; i<=8; i++)
        revperm_mu_1_NodeIDs[count][i-6]=Perm[i-6].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_NodeIDs(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_NodeIDs[0][i]<revperm_mu_1_NodeIDs[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_NodeIDs(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_NodeIDs[0][j];
      revperm_mu_1_NodeIDs[0][j] = revperm_mu_1_NodeIDs[0][i];
      revperm_mu_1_NodeIDs[0][i] = temp;
    }
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
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_NodeIDs[revperm_mu_1_NodeIDs[0][start]-6];
      if (reversed_sorted_mu_1_NodeIDs(start,end))
	       {
	  reverse_reversed_mu_1_NodeIDs(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_NodeIDs(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_NodeIDs[0][j]<revperm_mu_1_NodeIDs[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_NodeIDs[0][j];
			  revperm_mu_1_NodeIDs[0][j] = revperm_mu_1_NodeIDs[0][k];
			  revperm_mu_1_NodeIDs[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_NodeIDs(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_NodeIDs[0][k]==j+6)   // k - base 
	perm_mu_1_NodeIDs[0][j]=k+6; // j - base 
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
        mu_Nodes.MultisetSort();
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
void mu_1_NodeIDs::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_NodeIDs[Perm.in_mu_1_NodeIDs[i]][value()-6]); // value - base
};
void mu_1_NodeIDs::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_NodeIDs[value()-6]==Perm.undefined_class_mu_1_NodeIDs) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_NodeIDs[i] == Perm.undefined_class_mu_1_NodeIDs && i!=value()-6)
            Perm.class_mu_1_NodeIDs[i]++;
        value(6 + Perm.undefined_class_mu_1_NodeIDs++);
      }
    else 
      {
        value(Perm.class_mu_1_NodeIDs[value()-6]+6);
      }
}
void mu_1_NodeIDs::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_NodeIDs::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_NodeIDs[value()-6]==Perm.undefined_class_mu_1_NodeIDs) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_NodeIDs[i] == Perm.undefined_class_mu_1_NodeIDs && i!=value()-6)
            Perm.class_mu_1_NodeIDs[i]++;
        Perm.undefined_class_mu_1_NodeIDs++;
      }
}
void mu_1_NodeIDs::ArrayLimit(PermSet& Perm) {}
void mu_1_NodeIDs::Limit(PermSet& Perm) {}
void mu_1_NodeIDs::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
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
void mu__subrange_8::Permute(PermSet& Perm, int i) {};
void mu__subrange_8::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_8::Canonicalize(PermSet& Perm) {};
void mu__subrange_8::SimpleLimit(PermSet& Perm) {};
void mu__subrange_8::ArrayLimit(PermSet& Perm) {};
void mu__subrange_8::Limit(PermSet& Perm) {};
void mu__subrange_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<3; j++)
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
void mu__subrange_10::Permute(PermSet& Perm, int i) {};
void mu__subrange_10::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_10::Canonicalize(PermSet& Perm) {};
void mu__subrange_10::SimpleLimit(PermSet& Perm) {};
void mu__subrange_10::ArrayLimit(PermSet& Perm) {};
void mu__subrange_10::Limit(PermSet& Perm) {};
void mu__subrange_10::MultisetLimit(PermSet& Perm)
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
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i) {};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_5::Canonicalize(PermSet& Perm) {};
void mu_1__type_5::SimpleLimit(PermSet& Perm) {};
void mu_1__type_5::ArrayLimit(PermSet& Perm) {};
void mu_1__type_5::Limit(PermSet& Perm) {};
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i) {};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_6::Canonicalize(PermSet& Perm) {};
void mu_1__type_6::SimpleLimit(PermSet& Perm) {};
void mu_1__type_6::ArrayLimit(PermSet& Perm) {};
void mu_1__type_6::Limit(PermSet& Perm) {};
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  mu_Next_CC.Permute(Perm,i);
  mu_Next_AC.Permute(Perm,i);
};
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  mu_Next_CC.SimpleCanonicalize(Perm);
  mu_Next_AC.SimpleCanonicalize(Perm);
};
void mu_1_Node::Canonicalize(PermSet& Perm)
{
};
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  mu_Next_CC.SimpleLimit(Perm);
  mu_Next_AC.SimpleLimit(Perm);
};
void mu_1_Node::ArrayLimit(PermSet& Perm){}
void mu_1_Node::Limit(PermSet& Perm)
{
};
void mu_1_Node::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=6; j<=8; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_NodeIDs[Perm.in_mu_1_NodeIDs[i]][j-6]];};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_NodeIDs;
  int compare;
  static mu_1_Node value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_NodeIDs[3];
  bool pos_mu_1_NodeIDs[3][3];
  // sorting mu_1_NodeIDs
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_NodeIDs[i][j]=FALSE;
      count_mu_1_NodeIDs = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_NodeIDs; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+6]);
              if (compare==0)
                {
                  pos_mu_1_NodeIDs[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_NodeIDs; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_NodeIDs[k][z] = pos_mu_1_NodeIDs[k-1][z];
                    }
                  value[j] = (*this)[i+6];
                  for (z=0; z<3; z++)
                    pos_mu_1_NodeIDs[j][z] = FALSE;
                  pos_mu_1_NodeIDs[j][i] = TRUE;
                  count_mu_1_NodeIDs++;
                  break;
                }
            }
          if (j==count_mu_1_NodeIDs)
            {
              value[j] = (*this)[i+6];
              for (z=0; z<3; z++)
                pos_mu_1_NodeIDs[j][z] = FALSE;
              pos_mu_1_NodeIDs[j][i] = TRUE;
              count_mu_1_NodeIDs++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_NodeIDs[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_NodeIDs[i][k] && Perm.class_mu_1_NodeIDs[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_NodeIDs[k] = TRUE;
                    pos_mu_1_NodeIDs[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_NodeIDs[k] == j && !goodset_mu_1_NodeIDs[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_NodeIDs[k]>j
                            || ( Perm.class_mu_1_NodeIDs[k] == j && !goodset_mu_1_NodeIDs[k] ) )
                          Perm.class_mu_1_NodeIDs[k]++;
                      Perm.undefined_class_mu_1_NodeIDs++;
                    }
                }
            }
        }
    }
}
void mu_1__type_7::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_NodeIDs, oldcount_mu_1_NodeIDs;
  bool pos_mu_1_NodeIDs[3][3];
  bool goodset_mu_1_NodeIDs[3];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_NodeIDs[i][j]=FALSE;
  count_mu_1_NodeIDs = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_NodeIDs[i] == count_mu_1_NodeIDs)
         {
           pos_mu_1_NodeIDs[count_mu_1_NodeIDs][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_NodeIDs++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+6].mu_Next_CC.isundefined()
            ||(*this)[k+6].mu_Next_CC!=k+6)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_NodeIDs[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_NodeIDs[i][k] 
                    && !(*this)[k+6].mu_Next_CC.isundefined()
                    && (*this)[k+6].mu_Next_CC==k+6)
                  {
                    exists = TRUE;
                    goodset_mu_1_NodeIDs[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_NodeIDs; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k])
                            pos_mu_1_NodeIDs[i][k] = FALSE;
                          if (pos_mu_1_NodeIDs[i+1][k] && goodset_mu_1_NodeIDs[k])
                            pos_mu_1_NodeIDs[i+1][k] = FALSE;
                        }
                      count_mu_1_NodeIDs++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+6].mu_Next_AC.isundefined()
            ||(*this)[k+6].mu_Next_AC!=k+6)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_NodeIDs[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_NodeIDs[i][k] 
                    && !(*this)[k+6].mu_Next_AC.isundefined()
                    && (*this)[k+6].mu_Next_AC==k+6)
                  {
                    exists = TRUE;
                    goodset_mu_1_NodeIDs[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_NodeIDs; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k])
                            pos_mu_1_NodeIDs[i][k] = FALSE;
                          if (pos_mu_1_NodeIDs[i+1][k] && goodset_mu_1_NodeIDs[k])
                            pos_mu_1_NodeIDs[i+1][k] = FALSE;
                        }
                      count_mu_1_NodeIDs++; i++;
                    }
                }
            }
        }
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3);
  while ( while_guard )
    {
      oldcount_mu_1_NodeIDs = count_mu_1_NodeIDs;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+6].mu_Next_CC.isundefined()
                &&(*this)[k+6].mu_Next_CC!=k+6)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_NodeIDs; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_NodeIDs[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_NodeIDs[i][k] 
                            && !(*this)[k+6].mu_Next_CC.isundefined()
                            && (*this)[k+6].mu_Next_CC!=k+6
                            && pos_mu_1_NodeIDs[j][(*this)[k+6].mu_Next_CC-6])
                          {
                            exists = TRUE;
                            goodset_mu_1_NodeIDs[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_NodeIDs; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k])
                                    pos_mu_1_NodeIDs[i][k] = FALSE;
                                  if (pos_mu_1_NodeIDs[i+1][k] && goodset_mu_1_NodeIDs[k])
                                    pos_mu_1_NodeIDs[i+1][k] = FALSE;                  
                                }
                              count_mu_1_NodeIDs++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+6].mu_Next_AC.isundefined()
                &&(*this)[k+6].mu_Next_AC!=k+6)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_NodeIDs; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_NodeIDs[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_NodeIDs[i][k] 
                            && !(*this)[k+6].mu_Next_AC.isundefined()
                            && (*this)[k+6].mu_Next_AC!=k+6
                            && pos_mu_1_NodeIDs[j][(*this)[k+6].mu_Next_AC-6])
                          {
                            exists = TRUE;
                            goodset_mu_1_NodeIDs[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_NodeIDs; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k])
                                    pos_mu_1_NodeIDs[i][k] = FALSE;
                                  if (pos_mu_1_NodeIDs[i+1][k] && goodset_mu_1_NodeIDs[k])
                                    pos_mu_1_NodeIDs[i+1][k] = FALSE;                  
                                }
                              count_mu_1_NodeIDs++;
                            }
                        }
                    }
                }
            }
        }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_NodeIDs!=count_mu_1_NodeIDs);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_NodeIDs<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_NodeIDs())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_NodeIDs[i][j])
            Perm.class_mu_1_NodeIDs[j] = i;
      Perm.undefined_class_mu_1_NodeIDs=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_NodeIDs[j]>Perm.undefined_class_mu_1_NodeIDs)
          Perm.undefined_class_mu_1_NodeIDs=Perm.class_mu_1_NodeIDs[j];
    }
}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i) {};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_8::Canonicalize(PermSet& Perm) {};
void mu_1__type_8::SimpleLimit(PermSet& Perm) {};
void mu_1__type_8::ArrayLimit(PermSet& Perm) {};
void mu_1__type_8::Limit(PermSet& Perm) {};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i) {};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_9::Canonicalize(PermSet& Perm) {};
void mu_1__type_9::SimpleLimit(PermSet& Perm) {};
void mu_1__type_9::ArrayLimit(PermSet& Perm) {};
void mu_1__type_9::Limit(PermSet& Perm) {};
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i) {};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_10::Canonicalize(PermSet& Perm) {};
void mu_1__type_10::SimpleLimit(PermSet& Perm) {};
void mu_1__type_10::ArrayLimit(PermSet& Perm) {};
void mu_1__type_10::Limit(PermSet& Perm) {};
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_11::Permute(PermSet& Perm, int i) {};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_11::Canonicalize(PermSet& Perm) {};
void mu_1__type_11::SimpleLimit(PermSet& Perm) {};
void mu_1__type_11::ArrayLimit(PermSet& Perm) {};
void mu_1__type_11::Limit(PermSet& Perm) {};
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_12::Permute(PermSet& Perm, int i) {};
void mu_1__type_12::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_12::Canonicalize(PermSet& Perm) {};
void mu_1__type_12::SimpleLimit(PermSet& Perm) {};
void mu_1__type_12::ArrayLimit(PermSet& Perm) {};
void mu_1__type_12::Limit(PermSet& Perm) {};
void mu_1__type_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_13::Permute(PermSet& Perm, int i) {};
void mu_1__type_13::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_13::Canonicalize(PermSet& Perm) {};
void mu_1__type_13::SimpleLimit(PermSet& Perm) {};
void mu_1__type_13::ArrayLimit(PermSet& Perm) {};
void mu_1__type_13::Limit(PermSet& Perm) {};
void mu_1__type_13::MultisetLimit(PermSet& Perm)
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
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_Nodes.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Nodes.MultisetSort();
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

          mu_Nodes.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Nodes.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Nodes.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Nodes.MultisetSort();
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
      mu_Nodes.MultisetSort();
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
        mu_Nodes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Nodes.MultisetSort();
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

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Nodes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Nodes.MultisetSort();
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
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Nodes.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Nodes.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_Nodes.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Nodes.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

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

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Nodes.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Nodes.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Nodes.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
