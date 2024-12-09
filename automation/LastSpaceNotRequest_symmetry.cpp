/******************************
  Program "LastSpaceNotRequest_symmetry.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Dec  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Dec  6 2024"
#define PROTOCOL_NAME "LastSpaceNotRequest_symmetry"
#define BITS_IN_WORLD 102
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

class mu_1__type_3: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_3& val) { return mu__byte::operator=((int) val); };
  mu_1__type_3 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_3 (void): mu__byte(0, 3, 3) {};
  mu_1__type_3 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_4& val) { return mu__byte::operator=((int) val); };
  mu_1__type_4 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_4 (void): mu__byte(0, 1, 2) {};
  mu_1__type_4 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu_1_Node
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_2 mu_IncomingQueue;
  mu_1__type_3 mu_TailPointer;
  mu_1__type_4 mu_FrontPointer;
  mu_1_NodeIDs mu_Next;
  mu_1_Node ( const char *n, int os ) { set_self(n,os); };
  mu_1_Node ( void ) {};

  virtual ~mu_1_Node(); 
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
  {
    int w;
    w = CompareWeight(a.mu_IncomingQueue, b.mu_IncomingQueue);
    if (w!=0) return w;
    w = CompareWeight(a.mu_TailPointer, b.mu_TailPointer);
    if (w!=0) return w;
    w = CompareWeight(a.mu_FrontPointer, b.mu_FrontPointer);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Next, b.mu_Next);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Node& a, mu_1_Node& b)
  {
    int w;
    w = Compare(a.mu_IncomingQueue, b.mu_IncomingQueue);
    if (w!=0) return w;
    w = Compare(a.mu_TailPointer, b.mu_TailPointer);
    if (w!=0) return w;
    w = Compare(a.mu_FrontPointer, b.mu_FrontPointer);
    if (w!=0) return w;
    w = Compare(a.mu_Next, b.mu_Next);
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
    mu_IncomingQueue.MultisetSort();
    mu_TailPointer.MultisetSort();
    mu_FrontPointer.MultisetSort();
    mu_Next.MultisetSort();
  }
  void print_statistic()
  {
    mu_IncomingQueue.print_statistic();
    mu_TailPointer.print_statistic();
    mu_FrontPointer.print_statistic();
    mu_Next.print_statistic();
  }
  void clear() {
    mu_IncomingQueue.clear();
    mu_TailPointer.clear();
    mu_FrontPointer.clear();
    mu_Next.clear();
 };
  void undefine() {
    mu_IncomingQueue.undefine();
    mu_TailPointer.undefine();
    mu_FrontPointer.undefine();
    mu_Next.undefine();
 };
  void reset() {
    mu_IncomingQueue.reset();
    mu_TailPointer.reset();
    mu_FrontPointer.reset();
    mu_Next.reset();
 };
  void print() {
    mu_IncomingQueue.print();
    mu_TailPointer.print();
    mu_FrontPointer.print();
    mu_Next.print();
  };
  void print_diff(state *prevstate) {
    mu_IncomingQueue.print_diff(prevstate);
    mu_TailPointer.print_diff(prevstate);
    mu_FrontPointer.print_diff(prevstate);
    mu_Next.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_IncomingQueue.to_state(thestate);
    mu_TailPointer.to_state(thestate);
    mu_FrontPointer.to_state(thestate);
    mu_Next.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Node& operator= (const mu_1_Node& from) {
    mu_IncomingQueue = from.mu_IncomingQueue;
    mu_TailPointer.value(from.mu_TailPointer.value());
    mu_FrontPointer.value(from.mu_FrontPointer.value());
    mu_Next.value(from.mu_Next.value());
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

  if (name) mu_IncomingQueue.set_self_2(name, ".IncomingQueue", os + 0 ); else mu_IncomingQueue.set_self_2(NULL, NULL, 0);
  if (name) mu_TailPointer.set_self_2(name, ".TailPointer", os + 27 ); else mu_TailPointer.set_self_2(NULL, NULL, 0);
  if (name) mu_FrontPointer.set_self_2(name, ".FrontPointer", os + 30 ); else mu_FrontPointer.set_self_2(NULL, NULL, 0);
  if (name) mu_Next.set_self_2(name, ".Next", os + 32 ); else mu_Next.set_self_2(NULL, NULL, 0);
}

mu_1_Node::~mu_1_Node()
{
}

/*** end record declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1__type_5
{
 public:
  mu_1_Node array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
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
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
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

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"NodeIDs_1", i * 34 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"NodeIDs_2", i * 34 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"NodeIDs_3", i * 34 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_6& val) { return mu__byte::operator=((int) val); };
  mu_1__type_6 (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1__type_6 (void): mu__byte(1, 3, 2) {};
  mu_1__type_6 (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu__subrange_15: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_15& val) { return mu__byte::operator=((int) val); };
  mu__subrange_15 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_15 (void): mu__byte(1, 2, 2) {};
  mu__subrange_15 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_15 mu__subrange_15_undefined_var;

class mu__subrange_16: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_16& val) { return mu__byte::operator=((int) val); };
  mu__subrange_16 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_16 (void): mu__byte(0, 2, 2) {};
  mu__subrange_16 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_17 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_17 (void): mu__byte(1, 2, 2) {};
  mu__subrange_17 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_19 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_19 (void): mu__byte(1, 2, 2) {};
  mu__subrange_19 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_21 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_21 (void): mu__byte(1, 2, 2) {};
  mu__subrange_21 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_22 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_22 (void): mu__byte(1, 2, 2) {};
  mu__subrange_22 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_25 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_25 (void): mu__byte(1, 2, 2) {};
  mu__subrange_25 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_27 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_27 (void): mu__byte(1, 2, 2) {};
  mu__subrange_27 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_28 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_28 (void): mu__byte(1, 2, 2) {};
  mu__subrange_28 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_29 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_29 (void): mu__byte(1, 2, 2) {};
  mu__subrange_29 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_30 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_30 (void): mu__byte(1, 2, 2) {};
  mu__subrange_30 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_31 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_31 (void): mu__byte(1, 2, 2) {};
  mu__subrange_31 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_32 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_32 (void): mu__byte(1, 2, 2) {};
  mu__subrange_32 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_33 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_33 (void): mu__byte(1, 2, 2) {};
  mu__subrange_33 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_34 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_34 (void): mu__byte(1, 2, 2) {};
  mu__subrange_34 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_35 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_35 (void): mu__byte(1, 2, 2) {};
  mu__subrange_35 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_36 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_36 (void): mu__byte(1, 2, 2) {};
  mu__subrange_36 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_37 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_37 (void): mu__byte(1, 2, 2) {};
  mu__subrange_37 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_38 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_38 (void): mu__byte(1, 2, 2) {};
  mu__subrange_38 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_39 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_39 (void): mu__byte(1, 2, 2) {};
  mu__subrange_39 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_40 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_40 (void): mu__byte(1, 2, 2) {};
  mu__subrange_40 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_41 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_41 (void): mu__byte(1, 2, 2) {};
  mu__subrange_41 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_42 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_42 (void): mu__byte(1, 2, 2) {};
  mu__subrange_42 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_43 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_43 (void): mu__byte(1, 2, 2) {};
  mu__subrange_43 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_44 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu__subrange_44 (void): mu__byte(1, 2, 2) {};
  mu__subrange_44 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
mu_1__type_5 mu_Nodes("Nodes",0);

void mu_SendRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_6& mu_next_hop_length)
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
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_IncomingQueue[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessFwdRequest(const mu_1_NodeIDs& mu_src_nid)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_request;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_request;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops) - (1);
{
int mu__ub7 = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
for (int mu_i = 1; mu_i <= mu__ub7; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_TailPointer].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_IncomingQueue[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessRequest(const mu_1_NodeIDs& mu_src_nid)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub8 = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
for (int mu_i = 1; mu_i <= mu__ub8; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_TailPointer].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_IncomingQueue[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessFwdResponse(const mu_1_NodeIDs& mu_src_nid)
{
/*** Variable declaration ***/
mu_1_Message mu_msg_to_send("msg_to_send",0);

if ( (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) == (1) )
{
mu_msg_to_send.mu_msg_type = mu_response;
}
else
{
mu_msg_to_send.mu_msg_type = mu_fwd_response;
}
mu_msg_to_send.mu_src_hops = (mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_src_hops) - (1);
mu_msg_to_send.mu_dest_hops = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_FrontPointer].mu_dest_hops;
{
int mu__ub9 = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
for (int mu_i = 1; mu_i <= mu__ub9; mu_i += 1) {
mu_Nodes[mu_src_nid].mu_IncomingQueue[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_i];
};
};
mu_Nodes[mu_src_nid].mu_TailPointer = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_Nodes[mu_src_nid].mu_TailPointer].mu_msg_type = mu_empty;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_IncomingQueue[mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer] = mu_msg_to_send;
mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer = (mu_Nodes[mu_Nodes[mu_src_nid].mu_Next].mu_TailPointer) + (1);
};
/*** end procedure declaration ***/

void mu_ProcessResponse(const mu_1_NodeIDs& mu_src_nid)
{
{
for(int mu_i = 1; mu_i <= 2; mu_i++) {
mu_Nodes[mu_src_nid].mu_IncomingQueue[(mu_i) - (1)] = mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_i];
mu_Nodes[mu_src_nid].mu_IncomingQueue[mu_i].mu_msg_type = mu_empty;
};
};
mu_Nodes[mu_src_nid].mu_IncomingQueue[(mu_Nodes[mu_src_nid].mu_TailPointer) - (1)].mu_msg_type = mu_empty;
mu_Nodes[mu_src_nid].mu_TailPointer = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
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
    static mu__subrange_44 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_44 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr10;
bool mu__boolexpr11;
bool mu__boolexpr12;
bool mu__boolexpr13;
bool mu__boolexpr14;
bool mu__boolexpr15;
bool mu__boolexpr16;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr10;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_44 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 54 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
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
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 0;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_44 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr24;
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr24;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 54;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 81 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
bool mu__boolexpr35;
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
bool mu__boolexpr39;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr32) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process fwd_request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr40;
bool mu__boolexpr41;
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr45)) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr40;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 81;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 108 )
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
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
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
    r = what_rule - 81;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
mu_ProcessFwdRequest ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
bool mu__boolexpr60;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
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
    return mu__boolexpr56;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 108;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 135 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
bool mu__boolexpr65;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr64)) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr61) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_43 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_43 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr66;
bool mu__boolexpr67;
bool mu__boolexpr68;
bool mu__boolexpr69;
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr70)) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr69)) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr66;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 135;
    static mu__subrange_43 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 189 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr73;
bool mu__boolexpr74;
bool mu__boolexpr75;
bool mu__boolexpr76;
bool mu__boolexpr77;
bool mu__boolexpr78;
bool mu__boolexpr79;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr79)) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr78)) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr76)) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr73) {
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
    r = what_rule - 135;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_43 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr80;
bool mu__boolexpr81;
bool mu__boolexpr82;
bool mu__boolexpr83;
bool mu__boolexpr84;
bool mu__boolexpr85;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr84)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr83)) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr80;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 189;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 216 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr86;
bool mu__boolexpr87;
bool mu__boolexpr88;
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr88)) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr86) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
bool mu__boolexpr95;
bool mu__boolexpr96;
bool mu__boolexpr97;
bool mu__boolexpr98;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr98)) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr97)) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr92;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 216;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 243 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr99;
bool mu__boolexpr100;
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
bool mu__boolexpr105;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr105 = FALSE ;
  else {
  mu__boolexpr105 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr105)) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr99) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr106;
bool mu__boolexpr107;
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
bool mu__boolexpr111;
bool mu__boolexpr112;
bool mu__boolexpr113;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr113)) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr112)) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr110)) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
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
    unsigned r = what_rule - 243;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 270 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr114;
bool mu__boolexpr115;
bool mu__boolexpr116;
bool mu__boolexpr117;
bool mu__boolexpr118;
bool mu__boolexpr119;
bool mu__boolexpr120;
bool mu__boolexpr121;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr121 = FALSE ;
  else {
  mu__boolexpr121 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr121)) mu__boolexpr120 = FALSE ;
  else {
  mu__boolexpr120 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr120)) mu__boolexpr119 = FALSE ;
  else {
  mu__boolexpr119 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr119)) mu__boolexpr118 = FALSE ;
  else {
  mu__boolexpr118 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr118)) mu__boolexpr117 = FALSE ;
  else {
  mu__boolexpr117 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr117)) mu__boolexpr116 = FALSE ;
  else {
  mu__boolexpr116 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr116)) mu__boolexpr115 = FALSE ;
  else {
  mu__boolexpr115 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr115)) mu__boolexpr114 = FALSE ;
  else {
  mu__boolexpr114 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr114) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessFwdResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr122;
bool mu__boolexpr123;
bool mu__boolexpr124;
bool mu__boolexpr125;
bool mu__boolexpr126;
bool mu__boolexpr127;
bool mu__boolexpr128;
bool mu__boolexpr129;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr129 = FALSE ;
  else {
  mu__boolexpr129 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr129)) mu__boolexpr128 = FALSE ;
  else {
  mu__boolexpr128 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr128)) mu__boolexpr127 = FALSE ;
  else {
  mu__boolexpr127 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr127)) mu__boolexpr126 = FALSE ;
  else {
  mu__boolexpr126 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr126)) mu__boolexpr125 = FALSE ;
  else {
  mu__boolexpr125 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr125)) mu__boolexpr124 = FALSE ;
  else {
  mu__boolexpr124 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr124)) mu__boolexpr123 = FALSE ;
  else {
  mu__boolexpr123 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr123)) mu__boolexpr122 = FALSE ;
  else {
  mu__boolexpr122 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr122;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 270;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 297 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr130;
bool mu__boolexpr131;
bool mu__boolexpr132;
bool mu__boolexpr133;
bool mu__boolexpr134;
bool mu__boolexpr135;
bool mu__boolexpr136;
bool mu__boolexpr137;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr137 = FALSE ;
  else {
  mu__boolexpr137 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr137)) mu__boolexpr136 = FALSE ;
  else {
  mu__boolexpr136 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr136)) mu__boolexpr135 = FALSE ;
  else {
  mu__boolexpr135 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr135)) mu__boolexpr134 = FALSE ;
  else {
  mu__boolexpr134 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr134)) mu__boolexpr133 = FALSE ;
  else {
  mu__boolexpr133 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr133)) mu__boolexpr132 = FALSE ;
  else {
  mu__boolexpr132 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr132)) mu__boolexpr131 = FALSE ;
  else {
  mu__boolexpr131 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr131)) mu__boolexpr130 = FALSE ;
  else {
  mu__boolexpr130 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr130) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_42 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response + Send request + Send request, n3:%s, n5:%s, n4:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n5.Name(), mu_n4.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_42 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr138;
bool mu__boolexpr139;
bool mu__boolexpr140;
bool mu__boolexpr141;
bool mu__boolexpr142;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr142 = FALSE ;
  else {
  mu__boolexpr142 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr142)) mu__boolexpr141 = FALSE ;
  else {
  mu__boolexpr141 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr141)) mu__boolexpr140 = FALSE ;
  else {
  mu__boolexpr140 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr140)) mu__boolexpr139 = FALSE ;
  else {
  mu__boolexpr139 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr139)) mu__boolexpr138 = FALSE ;
  else {
  mu__boolexpr138 = ((mu_n2) != (mu_n4)) ; 
}
    return mu__boolexpr138;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 297;
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_42 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 405 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr143;
bool mu__boolexpr144;
bool mu__boolexpr145;
bool mu__boolexpr146;
bool mu__boolexpr147;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr147 = FALSE ;
  else {
  mu__boolexpr147 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr147)) mu__boolexpr146 = FALSE ;
  else {
  mu__boolexpr146 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr146)) mu__boolexpr145 = FALSE ;
  else {
  mu__boolexpr145 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr145)) mu__boolexpr144 = FALSE ;
  else {
  mu__boolexpr144 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr144)) mu__boolexpr143 = FALSE ;
  else {
  mu__boolexpr143 = ((mu_n2) != (mu_n4)) ; 
}
	      if (mu__boolexpr143) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 297;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_41 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_42 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_SendRequest ( mu_n4, (int)mu_n5 );
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
    static mu__subrange_39 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_40 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Send request + Send request, n3:%s, n5:%s, n4:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n5.Name(), mu_n4.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_39 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_40 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr148;
bool mu__boolexpr149;
bool mu__boolexpr150;
bool mu__boolexpr151;
bool mu__boolexpr152;
bool mu__boolexpr153;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr153 = FALSE ;
  else {
  mu__boolexpr153 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr153)) mu__boolexpr152 = FALSE ;
  else {
  mu__boolexpr152 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr152)) mu__boolexpr151 = FALSE ;
  else {
  mu__boolexpr151 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr151)) mu__boolexpr150 = FALSE ;
  else {
  mu__boolexpr150 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr150)) mu__boolexpr149 = FALSE ;
  else {
  mu__boolexpr149 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr149)) mu__boolexpr148 = FALSE ;
  else {
  mu__boolexpr148 = ((mu_n2) != (mu_n4)) ; 
}
    return mu__boolexpr148;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 405;
    static mu__subrange_39 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_40 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 513 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr154;
bool mu__boolexpr155;
bool mu__boolexpr156;
bool mu__boolexpr157;
bool mu__boolexpr158;
bool mu__boolexpr159;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr159 = FALSE ;
  else {
  mu__boolexpr159 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr159)) mu__boolexpr158 = FALSE ;
  else {
  mu__boolexpr158 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr158)) mu__boolexpr157 = FALSE ;
  else {
  mu__boolexpr157 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr157)) mu__boolexpr156 = FALSE ;
  else {
  mu__boolexpr156 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr156)) mu__boolexpr155 = FALSE ;
  else {
  mu__boolexpr155 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr155)) mu__boolexpr154 = FALSE ;
  else {
  mu__boolexpr154 = ((mu_n2) != (mu_n4)) ; 
}
	      if (mu__boolexpr154) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 405;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_39 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_40 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_SendRequest ( mu_n4, (int)mu_n5 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr160;
bool mu__boolexpr161;
bool mu__boolexpr162;
bool mu__boolexpr163;
bool mu__boolexpr164;
bool mu__boolexpr165;
bool mu__boolexpr166;
bool mu__boolexpr167;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr167 = FALSE ;
  else {
  mu__boolexpr167 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr167)) mu__boolexpr166 = FALSE ;
  else {
  mu__boolexpr166 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr166)) mu__boolexpr165 = FALSE ;
  else {
  mu__boolexpr165 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr165)) mu__boolexpr164 = FALSE ;
  else {
  mu__boolexpr164 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr164)) mu__boolexpr163 = FALSE ;
  else {
  mu__boolexpr163 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr163)) mu__boolexpr162 = FALSE ;
  else {
  mu__boolexpr162 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr162)) mu__boolexpr161 = FALSE ;
  else {
  mu__boolexpr161 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr161)) mu__boolexpr160 = FALSE ;
  else {
  mu__boolexpr160 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr160;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 513;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 540 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr168;
bool mu__boolexpr169;
bool mu__boolexpr170;
bool mu__boolexpr171;
bool mu__boolexpr172;
bool mu__boolexpr173;
bool mu__boolexpr174;
bool mu__boolexpr175;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr175 = FALSE ;
  else {
  mu__boolexpr175 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr175)) mu__boolexpr174 = FALSE ;
  else {
  mu__boolexpr174 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr174)) mu__boolexpr173 = FALSE ;
  else {
  mu__boolexpr173 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr173)) mu__boolexpr172 = FALSE ;
  else {
  mu__boolexpr172 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr172)) mu__boolexpr171 = FALSE ;
  else {
  mu__boolexpr171 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr171)) mu__boolexpr170 = FALSE ;
  else {
  mu__boolexpr170 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr170)) mu__boolexpr169 = FALSE ;
  else {
  mu__boolexpr169 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr169)) mu__boolexpr168 = FALSE ;
  else {
  mu__boolexpr168 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr168) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr176;
bool mu__boolexpr177;
bool mu__boolexpr178;
bool mu__boolexpr179;
bool mu__boolexpr180;
bool mu__boolexpr181;
bool mu__boolexpr182;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr182 = FALSE ;
  else {
  mu__boolexpr182 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr182)) mu__boolexpr181 = FALSE ;
  else {
  mu__boolexpr181 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr181)) mu__boolexpr180 = FALSE ;
  else {
  mu__boolexpr180 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr180)) mu__boolexpr179 = FALSE ;
  else {
  mu__boolexpr179 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr179)) mu__boolexpr178 = FALSE ;
  else {
  mu__boolexpr178 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr178)) mu__boolexpr177 = FALSE ;
  else {
  mu__boolexpr177 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr177)) mu__boolexpr176 = FALSE ;
  else {
  mu__boolexpr176 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr176;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 540;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 567 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr183;
bool mu__boolexpr184;
bool mu__boolexpr185;
bool mu__boolexpr186;
bool mu__boolexpr187;
bool mu__boolexpr188;
bool mu__boolexpr189;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr189 = FALSE ;
  else {
  mu__boolexpr189 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr189)) mu__boolexpr188 = FALSE ;
  else {
  mu__boolexpr188 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr188)) mu__boolexpr187 = FALSE ;
  else {
  mu__boolexpr187 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr187)) mu__boolexpr186 = FALSE ;
  else {
  mu__boolexpr186 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
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
  mu__boolexpr183 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr183) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_38 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_38 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr190;
bool mu__boolexpr191;
bool mu__boolexpr192;
bool mu__boolexpr193;
bool mu__boolexpr194;
bool mu__boolexpr195;
bool mu__boolexpr196;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr196 = FALSE ;
  else {
  mu__boolexpr196 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr196)) mu__boolexpr195 = FALSE ;
  else {
  mu__boolexpr195 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr195)) mu__boolexpr194 = FALSE ;
  else {
  mu__boolexpr194 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr194)) mu__boolexpr193 = FALSE ;
  else {
  mu__boolexpr193 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr193)) mu__boolexpr192 = FALSE ;
  else {
  mu__boolexpr192 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr192)) mu__boolexpr191 = FALSE ;
  else {
  mu__boolexpr191 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr191)) mu__boolexpr190 = FALSE ;
  else {
  mu__boolexpr190 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr190;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 567;
    static mu__subrange_38 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 621 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr197;
bool mu__boolexpr198;
bool mu__boolexpr199;
bool mu__boolexpr200;
bool mu__boolexpr201;
bool mu__boolexpr202;
bool mu__boolexpr203;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr203 = FALSE ;
  else {
  mu__boolexpr203 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr203)) mu__boolexpr202 = FALSE ;
  else {
  mu__boolexpr202 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr202)) mu__boolexpr201 = FALSE ;
  else {
  mu__boolexpr201 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr201)) mu__boolexpr200 = FALSE ;
  else {
  mu__boolexpr200 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr200)) mu__boolexpr199 = FALSE ;
  else {
  mu__boolexpr199 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr199)) mu__boolexpr198 = FALSE ;
  else {
  mu__boolexpr198 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr198)) mu__boolexpr197 = FALSE ;
  else {
  mu__boolexpr197 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr197) {
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
    r = what_rule - 567;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_38 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_36 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n6;
    mu_n6.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n5;
    mu_n5.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request + Send request, n2:%s, n4:%s, n6:%s, n5:%s, n3:%s, n1:%s", mu_n2.Name(), mu_n4.Name(), mu_n6.Name(), mu_n5.Name(), mu_n3.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_36 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n6;
    mu_n6.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n5;
    mu_n5.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr204;
bool mu__boolexpr205;
bool mu__boolexpr206;
bool mu__boolexpr207;
bool mu__boolexpr208;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2))) mu__boolexpr208 = FALSE ;
  else {
  mu__boolexpr208 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr208)) mu__boolexpr207 = FALSE ;
  else {
  mu__boolexpr207 = ((mu_Nodes[mu_Nodes[mu_n5].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr207)) mu__boolexpr206 = FALSE ;
  else {
  mu__boolexpr206 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr206)) mu__boolexpr205 = FALSE ;
  else {
  mu__boolexpr205 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr205)) mu__boolexpr204 = FALSE ;
  else {
  mu__boolexpr204 = ((mu_n3) != (mu_n5)) ; 
}
    return mu__boolexpr204;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 621;
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_36 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n6;
    mu_n6.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n5;
    mu_n5.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 837 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr209;
bool mu__boolexpr210;
bool mu__boolexpr211;
bool mu__boolexpr212;
bool mu__boolexpr213;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2))) mu__boolexpr213 = FALSE ;
  else {
  mu__boolexpr213 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr213)) mu__boolexpr212 = FALSE ;
  else {
  mu__boolexpr212 = ((mu_Nodes[mu_Nodes[mu_n5].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr212)) mu__boolexpr211 = FALSE ;
  else {
  mu__boolexpr211 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr211)) mu__boolexpr210 = FALSE ;
  else {
  mu__boolexpr210 = ((mu_n1) != (mu_n5)) ; 
}
  if (!(mu__boolexpr210)) mu__boolexpr209 = FALSE ;
  else {
  mu__boolexpr209 = ((mu_n3) != (mu_n5)) ; 
}
	      if (mu__boolexpr209) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 8;
	}
	else
	  what_rule += 8;
    r = what_rule - 621;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n6.value((r % 2) + 1);
    r = r / 2;
    mu_n5.value((r % 3) + 6);
    r = r / 3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_35 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_36 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n6;
    mu_n6.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n5;
    mu_n5.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_SendRequest ( mu_n1, (int)mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
mu_SendRequest ( mu_n5, (int)mu_n6 );
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
    static mu__subrange_34 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_34 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr214;
bool mu__boolexpr215;
bool mu__boolexpr216;
bool mu__boolexpr217;
bool mu__boolexpr218;
bool mu__boolexpr219;
bool mu__boolexpr220;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr220 = FALSE ;
  else {
  mu__boolexpr220 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr220)) mu__boolexpr219 = FALSE ;
  else {
  mu__boolexpr219 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr219)) mu__boolexpr218 = FALSE ;
  else {
  mu__boolexpr218 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr218)) mu__boolexpr217 = FALSE ;
  else {
  mu__boolexpr217 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr217)) mu__boolexpr216 = FALSE ;
  else {
  mu__boolexpr216 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr216)) mu__boolexpr215 = FALSE ;
  else {
  mu__boolexpr215 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr215)) mu__boolexpr214 = FALSE ;
  else {
  mu__boolexpr214 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr214;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 837;
    static mu__subrange_34 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 891 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr221;
bool mu__boolexpr222;
bool mu__boolexpr223;
bool mu__boolexpr224;
bool mu__boolexpr225;
bool mu__boolexpr226;
bool mu__boolexpr227;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr227 = FALSE ;
  else {
  mu__boolexpr227 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr227)) mu__boolexpr226 = FALSE ;
  else {
  mu__boolexpr226 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr226)) mu__boolexpr225 = FALSE ;
  else {
  mu__boolexpr225 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr225)) mu__boolexpr224 = FALSE ;
  else {
  mu__boolexpr224 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr224)) mu__boolexpr223 = FALSE ;
  else {
  mu__boolexpr223 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr223)) mu__boolexpr222 = FALSE ;
  else {
  mu__boolexpr222 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr222)) mu__boolexpr221 = FALSE ;
  else {
  mu__boolexpr221 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr221) {
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
    r = what_rule - 837;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_34 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu__subrange_33 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_33 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr228;
bool mu__boolexpr229;
bool mu__boolexpr230;
bool mu__boolexpr231;
bool mu__boolexpr232;
bool mu__boolexpr233;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr233 = FALSE ;
  else {
  mu__boolexpr233 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr233)) mu__boolexpr232 = FALSE ;
  else {
  mu__boolexpr232 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr232)) mu__boolexpr231 = FALSE ;
  else {
  mu__boolexpr231 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr231)) mu__boolexpr230 = FALSE ;
  else {
  mu__boolexpr230 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr230)) mu__boolexpr229 = FALSE ;
  else {
  mu__boolexpr229 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr229)) mu__boolexpr228 = FALSE ;
  else {
  mu__boolexpr228 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr228;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 891;
    static mu__subrange_33 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 945 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr234;
bool mu__boolexpr235;
bool mu__boolexpr236;
bool mu__boolexpr237;
bool mu__boolexpr238;
bool mu__boolexpr239;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr239 = FALSE ;
  else {
  mu__boolexpr239 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr239)) mu__boolexpr238 = FALSE ;
  else {
  mu__boolexpr238 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr238)) mu__boolexpr237 = FALSE ;
  else {
  mu__boolexpr237 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr237)) mu__boolexpr236 = FALSE ;
  else {
  mu__boolexpr236 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr236)) mu__boolexpr235 = FALSE ;
  else {
  mu__boolexpr235 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr235)) mu__boolexpr234 = FALSE ;
  else {
  mu__boolexpr234 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr234) {
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
    r = what_rule - 891;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_33 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr240;
bool mu__boolexpr241;
bool mu__boolexpr242;
bool mu__boolexpr243;
bool mu__boolexpr244;
bool mu__boolexpr245;
bool mu__boolexpr246;
bool mu__boolexpr247;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr247 = FALSE ;
  else {
  mu__boolexpr247 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr247)) mu__boolexpr246 = FALSE ;
  else {
  mu__boolexpr246 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr246)) mu__boolexpr245 = FALSE ;
  else {
  mu__boolexpr245 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr245)) mu__boolexpr244 = FALSE ;
  else {
  mu__boolexpr244 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr244)) mu__boolexpr243 = FALSE ;
  else {
  mu__boolexpr243 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
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
    unsigned r = what_rule - 945;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 972 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr248;
bool mu__boolexpr249;
bool mu__boolexpr250;
bool mu__boolexpr251;
bool mu__boolexpr252;
bool mu__boolexpr253;
bool mu__boolexpr254;
bool mu__boolexpr255;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr255 = FALSE ;
  else {
  mu__boolexpr255 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr255)) mu__boolexpr254 = FALSE ;
  else {
  mu__boolexpr254 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr254)) mu__boolexpr253 = FALSE ;
  else {
  mu__boolexpr253 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr253)) mu__boolexpr252 = FALSE ;
  else {
  mu__boolexpr252 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr252)) mu__boolexpr251 = FALSE ;
  else {
  mu__boolexpr251 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr251)) mu__boolexpr250 = FALSE ;
  else {
  mu__boolexpr250 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr250)) mu__boolexpr249 = FALSE ;
  else {
  mu__boolexpr249 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr249)) mu__boolexpr248 = FALSE ;
  else {
  mu__boolexpr248 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr248) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessFwdResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr256;
bool mu__boolexpr257;
bool mu__boolexpr258;
bool mu__boolexpr259;
bool mu__boolexpr260;
bool mu__boolexpr261;
bool mu__boolexpr262;
bool mu__boolexpr263;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr263 = FALSE ;
  else {
  mu__boolexpr263 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr263)) mu__boolexpr262 = FALSE ;
  else {
  mu__boolexpr262 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr262)) mu__boolexpr261 = FALSE ;
  else {
  mu__boolexpr261 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr261)) mu__boolexpr260 = FALSE ;
  else {
  mu__boolexpr260 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr260)) mu__boolexpr259 = FALSE ;
  else {
  mu__boolexpr259 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr259)) mu__boolexpr258 = FALSE ;
  else {
  mu__boolexpr258 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr258)) mu__boolexpr257 = FALSE ;
  else {
  mu__boolexpr257 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr257)) mu__boolexpr256 = FALSE ;
  else {
  mu__boolexpr256 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr256;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 972;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 999 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr264;
bool mu__boolexpr265;
bool mu__boolexpr266;
bool mu__boolexpr267;
bool mu__boolexpr268;
bool mu__boolexpr269;
bool mu__boolexpr270;
bool mu__boolexpr271;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr271 = FALSE ;
  else {
  mu__boolexpr271 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr271)) mu__boolexpr270 = FALSE ;
  else {
  mu__boolexpr270 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr270)) mu__boolexpr269 = FALSE ;
  else {
  mu__boolexpr269 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr269)) mu__boolexpr268 = FALSE ;
  else {
  mu__boolexpr268 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr268)) mu__boolexpr267 = FALSE ;
  else {
  mu__boolexpr267 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr267)) mu__boolexpr266 = FALSE ;
  else {
  mu__boolexpr266 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr266)) mu__boolexpr265 = FALSE ;
  else {
  mu__boolexpr265 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr265)) mu__boolexpr264 = FALSE ;
  else {
  mu__boolexpr264 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr264) {
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
    r = what_rule - 972;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr272;
bool mu__boolexpr273;
bool mu__boolexpr274;
bool mu__boolexpr275;
bool mu__boolexpr276;
bool mu__boolexpr277;
bool mu__boolexpr278;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr278 = FALSE ;
  else {
  mu__boolexpr278 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr278)) mu__boolexpr277 = FALSE ;
  else {
  mu__boolexpr277 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr277)) mu__boolexpr276 = FALSE ;
  else {
  mu__boolexpr276 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr276)) mu__boolexpr275 = FALSE ;
  else {
  mu__boolexpr275 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr275)) mu__boolexpr274 = FALSE ;
  else {
  mu__boolexpr274 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr274)) mu__boolexpr273 = FALSE ;
  else {
  mu__boolexpr273 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr273)) mu__boolexpr272 = FALSE ;
  else {
  mu__boolexpr272 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr272;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 999;
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1053 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr279;
bool mu__boolexpr280;
bool mu__boolexpr281;
bool mu__boolexpr282;
bool mu__boolexpr283;
bool mu__boolexpr284;
bool mu__boolexpr285;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr285 = FALSE ;
  else {
  mu__boolexpr285 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr285)) mu__boolexpr284 = FALSE ;
  else {
  mu__boolexpr284 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr284)) mu__boolexpr283 = FALSE ;
  else {
  mu__boolexpr283 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr283)) mu__boolexpr282 = FALSE ;
  else {
  mu__boolexpr282 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr282)) mu__boolexpr281 = FALSE ;
  else {
  mu__boolexpr281 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr281)) mu__boolexpr280 = FALSE ;
  else {
  mu__boolexpr280 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr280)) mu__boolexpr279 = FALSE ;
  else {
  mu__boolexpr279 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr279) {
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
    r = what_rule - 999;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_32 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr286;
bool mu__boolexpr287;
bool mu__boolexpr288;
bool mu__boolexpr289;
bool mu__boolexpr290;
bool mu__boolexpr291;
bool mu__boolexpr292;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr292 = FALSE ;
  else {
  mu__boolexpr292 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr292)) mu__boolexpr291 = FALSE ;
  else {
  mu__boolexpr291 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr291)) mu__boolexpr290 = FALSE ;
  else {
  mu__boolexpr290 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr290)) mu__boolexpr289 = FALSE ;
  else {
  mu__boolexpr289 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
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
    unsigned r = what_rule - 1053;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1080 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr293;
bool mu__boolexpr294;
bool mu__boolexpr295;
bool mu__boolexpr296;
bool mu__boolexpr297;
bool mu__boolexpr298;
bool mu__boolexpr299;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr299 = FALSE ;
  else {
  mu__boolexpr299 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr299)) mu__boolexpr298 = FALSE ;
  else {
  mu__boolexpr298 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr298)) mu__boolexpr297 = FALSE ;
  else {
  mu__boolexpr297 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr297)) mu__boolexpr296 = FALSE ;
  else {
  mu__boolexpr296 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr296)) mu__boolexpr295 = FALSE ;
  else {
  mu__boolexpr295 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr295)) mu__boolexpr294 = FALSE ;
  else {
  mu__boolexpr294 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr294)) mu__boolexpr293 = FALSE ;
  else {
  mu__boolexpr293 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr293) {
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
    r = what_rule - 1053;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr300;
bool mu__boolexpr301;
bool mu__boolexpr302;
bool mu__boolexpr303;
bool mu__boolexpr304;
bool mu__boolexpr305;
bool mu__boolexpr306;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr306 = FALSE ;
  else {
  mu__boolexpr306 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr306)) mu__boolexpr305 = FALSE ;
  else {
  mu__boolexpr305 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr305)) mu__boolexpr304 = FALSE ;
  else {
  mu__boolexpr304 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr304)) mu__boolexpr303 = FALSE ;
  else {
  mu__boolexpr303 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr303)) mu__boolexpr302 = FALSE ;
  else {
  mu__boolexpr302 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr302)) mu__boolexpr301 = FALSE ;
  else {
  mu__boolexpr301 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr301)) mu__boolexpr300 = FALSE ;
  else {
  mu__boolexpr300 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr300;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1080;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1107 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr307;
bool mu__boolexpr308;
bool mu__boolexpr309;
bool mu__boolexpr310;
bool mu__boolexpr311;
bool mu__boolexpr312;
bool mu__boolexpr313;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr313 = FALSE ;
  else {
  mu__boolexpr313 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr313)) mu__boolexpr312 = FALSE ;
  else {
  mu__boolexpr312 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr312)) mu__boolexpr311 = FALSE ;
  else {
  mu__boolexpr311 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr311)) mu__boolexpr310 = FALSE ;
  else {
  mu__boolexpr310 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr310)) mu__boolexpr309 = FALSE ;
  else {
  mu__boolexpr309 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr309)) mu__boolexpr308 = FALSE ;
  else {
  mu__boolexpr308 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr308)) mu__boolexpr307 = FALSE ;
  else {
  mu__boolexpr307 = ((mu_n2) != (mu_n3)) ; 
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
    r = what_rule - 1080;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr314;
bool mu__boolexpr315;
bool mu__boolexpr316;
bool mu__boolexpr317;
bool mu__boolexpr318;
bool mu__boolexpr319;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr319 = FALSE ;
  else {
  mu__boolexpr319 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr319)) mu__boolexpr318 = FALSE ;
  else {
  mu__boolexpr318 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr318)) mu__boolexpr317 = FALSE ;
  else {
  mu__boolexpr317 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr317)) mu__boolexpr316 = FALSE ;
  else {
  mu__boolexpr316 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr316)) mu__boolexpr315 = FALSE ;
  else {
  mu__boolexpr315 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr315)) mu__boolexpr314 = FALSE ;
  else {
  mu__boolexpr314 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr314;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1107;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1134 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr320;
bool mu__boolexpr321;
bool mu__boolexpr322;
bool mu__boolexpr323;
bool mu__boolexpr324;
bool mu__boolexpr325;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr325 = FALSE ;
  else {
  mu__boolexpr325 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr325)) mu__boolexpr324 = FALSE ;
  else {
  mu__boolexpr324 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr324)) mu__boolexpr323 = FALSE ;
  else {
  mu__boolexpr323 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr323)) mu__boolexpr322 = FALSE ;
  else {
  mu__boolexpr322 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr322)) mu__boolexpr321 = FALSE ;
  else {
  mu__boolexpr321 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr321)) mu__boolexpr320 = FALSE ;
  else {
  mu__boolexpr320 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr320) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_30 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_31 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Send request + Send request, n3:%s, n5:%s, n4:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n5.Name(), mu_n4.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_30 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_31 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr326;
bool mu__boolexpr327;
bool mu__boolexpr328;
bool mu__boolexpr329;
bool mu__boolexpr330;
bool mu__boolexpr331;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr331 = FALSE ;
  else {
  mu__boolexpr331 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr331)) mu__boolexpr330 = FALSE ;
  else {
  mu__boolexpr330 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr330)) mu__boolexpr329 = FALSE ;
  else {
  mu__boolexpr329 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr329)) mu__boolexpr328 = FALSE ;
  else {
  mu__boolexpr328 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr328)) mu__boolexpr327 = FALSE ;
  else {
  mu__boolexpr327 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr327)) mu__boolexpr326 = FALSE ;
  else {
  mu__boolexpr326 = ((mu_n2) != (mu_n4)) ; 
}
    return mu__boolexpr326;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1134;
    static mu__subrange_30 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_31 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1242 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr332;
bool mu__boolexpr333;
bool mu__boolexpr334;
bool mu__boolexpr335;
bool mu__boolexpr336;
bool mu__boolexpr337;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr337 = FALSE ;
  else {
  mu__boolexpr337 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr337)) mu__boolexpr336 = FALSE ;
  else {
  mu__boolexpr336 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr336)) mu__boolexpr335 = FALSE ;
  else {
  mu__boolexpr335 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr335)) mu__boolexpr334 = FALSE ;
  else {
  mu__boolexpr334 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr334)) mu__boolexpr333 = FALSE ;
  else {
  mu__boolexpr333 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr333)) mu__boolexpr332 = FALSE ;
  else {
  mu__boolexpr332 = ((mu_n2) != (mu_n4)) ; 
}
	      if (mu__boolexpr332) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 1134;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_30 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_31 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_SendRequest ( mu_n4, (int)mu_n5 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process fwd_response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr338;
bool mu__boolexpr339;
bool mu__boolexpr340;
bool mu__boolexpr341;
bool mu__boolexpr342;
bool mu__boolexpr343;
bool mu__boolexpr344;
bool mu__boolexpr345;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr345 = FALSE ;
  else {
  mu__boolexpr345 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr345)) mu__boolexpr344 = FALSE ;
  else {
  mu__boolexpr344 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr344)) mu__boolexpr343 = FALSE ;
  else {
  mu__boolexpr343 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr343)) mu__boolexpr342 = FALSE ;
  else {
  mu__boolexpr342 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr342)) mu__boolexpr341 = FALSE ;
  else {
  mu__boolexpr341 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr341)) mu__boolexpr340 = FALSE ;
  else {
  mu__boolexpr340 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr340)) mu__boolexpr339 = FALSE ;
  else {
  mu__boolexpr339 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr339)) mu__boolexpr338 = FALSE ;
  else {
  mu__boolexpr338 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr338;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1242;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1269 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr346;
bool mu__boolexpr347;
bool mu__boolexpr348;
bool mu__boolexpr349;
bool mu__boolexpr350;
bool mu__boolexpr351;
bool mu__boolexpr352;
bool mu__boolexpr353;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr353 = FALSE ;
  else {
  mu__boolexpr353 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr353)) mu__boolexpr352 = FALSE ;
  else {
  mu__boolexpr352 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr352)) mu__boolexpr351 = FALSE ;
  else {
  mu__boolexpr351 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr351)) mu__boolexpr350 = FALSE ;
  else {
  mu__boolexpr350 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr350)) mu__boolexpr349 = FALSE ;
  else {
  mu__boolexpr349 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr349)) mu__boolexpr348 = FALSE ;
  else {
  mu__boolexpr348 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr348)) mu__boolexpr347 = FALSE ;
  else {
  mu__boolexpr347 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr347)) mu__boolexpr346 = FALSE ;
  else {
  mu__boolexpr346 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr346) {
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
    r = what_rule - 1242;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
mu_ProcessFwdResponse ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr354;
bool mu__boolexpr355;
bool mu__boolexpr356;
bool mu__boolexpr357;
bool mu__boolexpr358;
bool mu__boolexpr359;
bool mu__boolexpr360;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr360 = FALSE ;
  else {
  mu__boolexpr360 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr360)) mu__boolexpr359 = FALSE ;
  else {
  mu__boolexpr359 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr359)) mu__boolexpr358 = FALSE ;
  else {
  mu__boolexpr358 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr358)) mu__boolexpr357 = FALSE ;
  else {
  mu__boolexpr357 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr357)) mu__boolexpr356 = FALSE ;
  else {
  mu__boolexpr356 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr356)) mu__boolexpr355 = FALSE ;
  else {
  mu__boolexpr355 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr355)) mu__boolexpr354 = FALSE ;
  else {
  mu__boolexpr354 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr354;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1269;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1296 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr361;
bool mu__boolexpr362;
bool mu__boolexpr363;
bool mu__boolexpr364;
bool mu__boolexpr365;
bool mu__boolexpr366;
bool mu__boolexpr367;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr367 = FALSE ;
  else {
  mu__boolexpr367 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr367)) mu__boolexpr366 = FALSE ;
  else {
  mu__boolexpr366 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr366)) mu__boolexpr365 = FALSE ;
  else {
  mu__boolexpr365 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr365)) mu__boolexpr364 = FALSE ;
  else {
  mu__boolexpr364 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr364)) mu__boolexpr363 = FALSE ;
  else {
  mu__boolexpr363 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr363)) mu__boolexpr362 = FALSE ;
  else {
  mu__boolexpr362 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr362)) mu__boolexpr361 = FALSE ;
  else {
  mu__boolexpr361 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr361) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_29 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_29 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr368;
bool mu__boolexpr369;
bool mu__boolexpr370;
bool mu__boolexpr371;
bool mu__boolexpr372;
bool mu__boolexpr373;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr373 = FALSE ;
  else {
  mu__boolexpr373 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr373)) mu__boolexpr372 = FALSE ;
  else {
  mu__boolexpr372 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr372)) mu__boolexpr371 = FALSE ;
  else {
  mu__boolexpr371 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr371)) mu__boolexpr370 = FALSE ;
  else {
  mu__boolexpr370 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr370)) mu__boolexpr369 = FALSE ;
  else {
  mu__boolexpr369 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr369)) mu__boolexpr368 = FALSE ;
  else {
  mu__boolexpr368 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr368;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1296;
    static mu__subrange_29 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1350 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr374;
bool mu__boolexpr375;
bool mu__boolexpr376;
bool mu__boolexpr377;
bool mu__boolexpr378;
bool mu__boolexpr379;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr379 = FALSE ;
  else {
  mu__boolexpr379 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr379)) mu__boolexpr378 = FALSE ;
  else {
  mu__boolexpr378 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr378)) mu__boolexpr377 = FALSE ;
  else {
  mu__boolexpr377 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr377)) mu__boolexpr376 = FALSE ;
  else {
  mu__boolexpr376 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr376)) mu__boolexpr375 = FALSE ;
  else {
  mu__boolexpr375 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr375)) mu__boolexpr374 = FALSE ;
  else {
  mu__boolexpr374 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr374) {
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
    r = what_rule - 1296;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_29 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr380;
bool mu__boolexpr381;
bool mu__boolexpr382;
bool mu__boolexpr383;
bool mu__boolexpr384;
bool mu__boolexpr385;
bool mu__boolexpr386;
bool mu__boolexpr387;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr387 = FALSE ;
  else {
  mu__boolexpr387 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr387)) mu__boolexpr386 = FALSE ;
  else {
  mu__boolexpr386 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr386)) mu__boolexpr385 = FALSE ;
  else {
  mu__boolexpr385 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr385)) mu__boolexpr384 = FALSE ;
  else {
  mu__boolexpr384 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr384)) mu__boolexpr383 = FALSE ;
  else {
  mu__boolexpr383 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr383)) mu__boolexpr382 = FALSE ;
  else {
  mu__boolexpr382 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr382)) mu__boolexpr381 = FALSE ;
  else {
  mu__boolexpr381 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr381)) mu__boolexpr380 = FALSE ;
  else {
  mu__boolexpr380 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr380;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1350;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1377 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr388;
bool mu__boolexpr389;
bool mu__boolexpr390;
bool mu__boolexpr391;
bool mu__boolexpr392;
bool mu__boolexpr393;
bool mu__boolexpr394;
bool mu__boolexpr395;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr395 = FALSE ;
  else {
  mu__boolexpr395 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr395)) mu__boolexpr394 = FALSE ;
  else {
  mu__boolexpr394 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr394)) mu__boolexpr393 = FALSE ;
  else {
  mu__boolexpr393 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr393)) mu__boolexpr392 = FALSE ;
  else {
  mu__boolexpr392 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr392)) mu__boolexpr391 = FALSE ;
  else {
  mu__boolexpr391 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr391)) mu__boolexpr390 = FALSE ;
  else {
  mu__boolexpr390 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr390)) mu__boolexpr389 = FALSE ;
  else {
  mu__boolexpr389 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr389)) mu__boolexpr388 = FALSE ;
  else {
  mu__boolexpr388 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr388) {
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
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr396;
bool mu__boolexpr397;
bool mu__boolexpr398;
bool mu__boolexpr399;
bool mu__boolexpr400;
bool mu__boolexpr401;
bool mu__boolexpr402;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr402 = FALSE ;
  else {
  mu__boolexpr402 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr402)) mu__boolexpr401 = FALSE ;
  else {
  mu__boolexpr401 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr401)) mu__boolexpr400 = FALSE ;
  else {
  mu__boolexpr400 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr400)) mu__boolexpr399 = FALSE ;
  else {
  mu__boolexpr399 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr399)) mu__boolexpr398 = FALSE ;
  else {
  mu__boolexpr398 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr398)) mu__boolexpr397 = FALSE ;
  else {
  mu__boolexpr397 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr397)) mu__boolexpr396 = FALSE ;
  else {
  mu__boolexpr396 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr396;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1377;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1404 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr403;
bool mu__boolexpr404;
bool mu__boolexpr405;
bool mu__boolexpr406;
bool mu__boolexpr407;
bool mu__boolexpr408;
bool mu__boolexpr409;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr409 = FALSE ;
  else {
  mu__boolexpr409 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr409)) mu__boolexpr408 = FALSE ;
  else {
  mu__boolexpr408 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr408)) mu__boolexpr407 = FALSE ;
  else {
  mu__boolexpr407 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr407)) mu__boolexpr406 = FALSE ;
  else {
  mu__boolexpr406 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr406)) mu__boolexpr405 = FALSE ;
  else {
  mu__boolexpr405 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr405)) mu__boolexpr404 = FALSE ;
  else {
  mu__boolexpr404 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr404)) mu__boolexpr403 = FALSE ;
  else {
  mu__boolexpr403 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr403) {
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
    r = what_rule - 1377;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_28 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_28 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr410;
bool mu__boolexpr411;
bool mu__boolexpr412;
bool mu__boolexpr413;
bool mu__boolexpr414;
bool mu__boolexpr415;
bool mu__boolexpr416;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr416 = FALSE ;
  else {
  mu__boolexpr416 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr416)) mu__boolexpr415 = FALSE ;
  else {
  mu__boolexpr415 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr415)) mu__boolexpr414 = FALSE ;
  else {
  mu__boolexpr414 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr414)) mu__boolexpr413 = FALSE ;
  else {
  mu__boolexpr413 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr413)) mu__boolexpr412 = FALSE ;
  else {
  mu__boolexpr412 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr412)) mu__boolexpr411 = FALSE ;
  else {
  mu__boolexpr411 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr411)) mu__boolexpr410 = FALSE ;
  else {
  mu__boolexpr410 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr410;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1404;
    static mu__subrange_28 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1458 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr417;
bool mu__boolexpr418;
bool mu__boolexpr419;
bool mu__boolexpr420;
bool mu__boolexpr421;
bool mu__boolexpr422;
bool mu__boolexpr423;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr423 = FALSE ;
  else {
  mu__boolexpr423 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr423)) mu__boolexpr422 = FALSE ;
  else {
  mu__boolexpr422 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr422)) mu__boolexpr421 = FALSE ;
  else {
  mu__boolexpr421 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr421)) mu__boolexpr420 = FALSE ;
  else {
  mu__boolexpr420 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr420)) mu__boolexpr419 = FALSE ;
  else {
  mu__boolexpr419 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr419)) mu__boolexpr418 = FALSE ;
  else {
  mu__boolexpr418 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr418)) mu__boolexpr417 = FALSE ;
  else {
  mu__boolexpr417 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr417) {
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
    r = what_rule - 1404;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_28 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request + Process request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr424;
bool mu__boolexpr425;
bool mu__boolexpr426;
bool mu__boolexpr427;
bool mu__boolexpr428;
bool mu__boolexpr429;
bool mu__boolexpr430;
bool mu__boolexpr431;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr431 = FALSE ;
  else {
  mu__boolexpr431 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr431)) mu__boolexpr430 = FALSE ;
  else {
  mu__boolexpr430 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr430)) mu__boolexpr429 = FALSE ;
  else {
  mu__boolexpr429 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr429)) mu__boolexpr428 = FALSE ;
  else {
  mu__boolexpr428 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr428)) mu__boolexpr427 = FALSE ;
  else {
  mu__boolexpr427 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr427)) mu__boolexpr426 = FALSE ;
  else {
  mu__boolexpr426 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr426)) mu__boolexpr425 = FALSE ;
  else {
  mu__boolexpr425 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr425)) mu__boolexpr424 = FALSE ;
  else {
  mu__boolexpr424 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr424;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1458;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1485 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr432;
bool mu__boolexpr433;
bool mu__boolexpr434;
bool mu__boolexpr435;
bool mu__boolexpr436;
bool mu__boolexpr437;
bool mu__boolexpr438;
bool mu__boolexpr439;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr439 = FALSE ;
  else {
  mu__boolexpr439 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr439)) mu__boolexpr438 = FALSE ;
  else {
  mu__boolexpr438 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr438)) mu__boolexpr437 = FALSE ;
  else {
  mu__boolexpr437 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr437)) mu__boolexpr436 = FALSE ;
  else {
  mu__boolexpr436 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr436)) mu__boolexpr435 = FALSE ;
  else {
  mu__boolexpr435 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr435)) mu__boolexpr434 = FALSE ;
  else {
  mu__boolexpr434 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr434)) mu__boolexpr433 = FALSE ;
  else {
  mu__boolexpr433 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr433)) mu__boolexpr432 = FALSE ;
  else {
  mu__boolexpr432 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr432) {
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
    r = what_rule - 1458;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
mu_ProcessRequest ( mu_n3 );
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
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process response + Process response, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr440;
bool mu__boolexpr441;
bool mu__boolexpr442;
bool mu__boolexpr443;
bool mu__boolexpr444;
bool mu__boolexpr445;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr445 = FALSE ;
  else {
  mu__boolexpr445 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr445)) mu__boolexpr444 = FALSE ;
  else {
  mu__boolexpr444 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr444)) mu__boolexpr443 = FALSE ;
  else {
  mu__boolexpr443 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr443)) mu__boolexpr442 = FALSE ;
  else {
  mu__boolexpr442 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr442)) mu__boolexpr441 = FALSE ;
  else {
  mu__boolexpr441 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr441)) mu__boolexpr440 = FALSE ;
  else {
  mu__boolexpr440 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr440;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1485;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1512 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr446;
bool mu__boolexpr447;
bool mu__boolexpr448;
bool mu__boolexpr449;
bool mu__boolexpr450;
bool mu__boolexpr451;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr451 = FALSE ;
  else {
  mu__boolexpr451 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr451)) mu__boolexpr450 = FALSE ;
  else {
  mu__boolexpr450 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr450)) mu__boolexpr449 = FALSE ;
  else {
  mu__boolexpr449 = ((mu_Nodes[mu_n3].mu_IncomingQueue[mu_Nodes[mu_n3].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr449)) mu__boolexpr448 = FALSE ;
  else {
  mu__boolexpr448 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr448)) mu__boolexpr447 = FALSE ;
  else {
  mu__boolexpr447 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr447)) mu__boolexpr446 = FALSE ;
  else {
  mu__boolexpr446 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr446) {
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
    r = what_rule - 1485;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_ProcessResponse ( mu_n3 );
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
    static mu__subrange_27 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response + Process response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_27 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr452;
bool mu__boolexpr453;
bool mu__boolexpr454;
bool mu__boolexpr455;
bool mu__boolexpr456;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr456 = FALSE ;
  else {
  mu__boolexpr456 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr456)) mu__boolexpr455 = FALSE ;
  else {
  mu__boolexpr455 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr455)) mu__boolexpr454 = FALSE ;
  else {
  mu__boolexpr454 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr454)) mu__boolexpr453 = FALSE ;
  else {
  mu__boolexpr453 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr453)) mu__boolexpr452 = FALSE ;
  else {
  mu__boolexpr452 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr452;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1512;
    static mu__subrange_27 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1566 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr457;
bool mu__boolexpr458;
bool mu__boolexpr459;
bool mu__boolexpr460;
bool mu__boolexpr461;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr461 = FALSE ;
  else {
  mu__boolexpr461 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr461)) mu__boolexpr460 = FALSE ;
  else {
  mu__boolexpr460 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr460)) mu__boolexpr459 = FALSE ;
  else {
  mu__boolexpr459 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr459)) mu__boolexpr458 = FALSE ;
  else {
  mu__boolexpr458 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr458)) mu__boolexpr457 = FALSE ;
  else {
  mu__boolexpr457 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr457) {
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
    r = what_rule - 1512;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_27 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu__subrange_25 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_26 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Send request + Send request, n3:%s, n5:%s, n4:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n5.Name(), mu_n4.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_25 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_26 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr462;
bool mu__boolexpr463;
bool mu__boolexpr464;
bool mu__boolexpr465;
bool mu__boolexpr466;
bool mu__boolexpr467;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr467 = FALSE ;
  else {
  mu__boolexpr467 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr467)) mu__boolexpr466 = FALSE ;
  else {
  mu__boolexpr466 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr466)) mu__boolexpr465 = FALSE ;
  else {
  mu__boolexpr465 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr465)) mu__boolexpr464 = FALSE ;
  else {
  mu__boolexpr464 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr464)) mu__boolexpr463 = FALSE ;
  else {
  mu__boolexpr463 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr463)) mu__boolexpr462 = FALSE ;
  else {
  mu__boolexpr462 = ((mu_n2) != (mu_n4)) ; 
}
    return mu__boolexpr462;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1566;
    static mu__subrange_25 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_26 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1674 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr468;
bool mu__boolexpr469;
bool mu__boolexpr470;
bool mu__boolexpr471;
bool mu__boolexpr472;
bool mu__boolexpr473;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr473 = FALSE ;
  else {
  mu__boolexpr473 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr473)) mu__boolexpr472 = FALSE ;
  else {
  mu__boolexpr472 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr472)) mu__boolexpr471 = FALSE ;
  else {
  mu__boolexpr471 = ((mu_Nodes[mu_Nodes[mu_n4].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr471)) mu__boolexpr470 = FALSE ;
  else {
  mu__boolexpr470 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr470)) mu__boolexpr469 = FALSE ;
  else {
  mu__boolexpr469 = ((mu_n1) != (mu_n4)) ; 
}
  if (!(mu__boolexpr469)) mu__boolexpr468 = FALSE ;
  else {
  mu__boolexpr468 = ((mu_n2) != (mu_n4)) ; 
}
	      if (mu__boolexpr468) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 1566;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_25 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_26 mu_n5;
    mu_n5.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n4;
    mu_n4.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_SendRequest ( mu_n4, (int)mu_n5 );
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
    static mu__subrange_24 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process response + Send request, n4:%s, n3:%s, n2:%s, n1:%s", mu_n4.Name(), mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_24 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr474;
bool mu__boolexpr475;
bool mu__boolexpr476;
bool mu__boolexpr477;
bool mu__boolexpr478;
bool mu__boolexpr479;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr479 = FALSE ;
  else {
  mu__boolexpr479 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr479)) mu__boolexpr478 = FALSE ;
  else {
  mu__boolexpr478 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr478)) mu__boolexpr477 = FALSE ;
  else {
  mu__boolexpr477 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr477)) mu__boolexpr476 = FALSE ;
  else {
  mu__boolexpr476 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr476)) mu__boolexpr475 = FALSE ;
  else {
  mu__boolexpr475 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr475)) mu__boolexpr474 = FALSE ;
  else {
  mu__boolexpr474 = ((mu_n2) != (mu_n3)) ; 
}
    return mu__boolexpr474;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1674;
    static mu__subrange_24 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1728 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr480;
bool mu__boolexpr481;
bool mu__boolexpr482;
bool mu__boolexpr483;
bool mu__boolexpr484;
bool mu__boolexpr485;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr485 = FALSE ;
  else {
  mu__boolexpr485 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr485)) mu__boolexpr484 = FALSE ;
  else {
  mu__boolexpr484 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr484)) mu__boolexpr483 = FALSE ;
  else {
  mu__boolexpr483 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr483)) mu__boolexpr482 = FALSE ;
  else {
  mu__boolexpr482 = ((mu_n1) != (mu_n2)) ; 
}
  if (!(mu__boolexpr482)) mu__boolexpr481 = FALSE ;
  else {
  mu__boolexpr481 = ((mu_n1) != (mu_n3)) ; 
}
  if (!(mu__boolexpr481)) mu__boolexpr480 = FALSE ;
  else {
  mu__boolexpr480 = ((mu_n2) != (mu_n3)) ; 
}
	      if (mu__boolexpr480) {
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
    r = what_rule - 1674;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_24 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr486;
bool mu__boolexpr487;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr487 = FALSE ;
  else {
  mu__boolexpr487 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr487)) mu__boolexpr486 = FALSE ;
  else {
  mu__boolexpr486 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr486;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1728;
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1746 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr488;
bool mu__boolexpr489;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr489 = FALSE ;
  else {
  mu__boolexpr489 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr489)) mu__boolexpr488 = FALSE ;
  else {
  mu__boolexpr488 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr488) {
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
    r = what_rule - 1728;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr490;
bool mu__boolexpr491;
bool mu__boolexpr492;
bool mu__boolexpr493;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr493 = FALSE ;
  else {
  mu__boolexpr493 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr493)) mu__boolexpr492 = FALSE ;
  else {
  mu__boolexpr492 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr492)) mu__boolexpr491 = FALSE ;
  else {
  mu__boolexpr491 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr491)) mu__boolexpr490 = FALSE ;
  else {
  mu__boolexpr490 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr490;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1746;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1755 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr494;
bool mu__boolexpr495;
bool mu__boolexpr496;
bool mu__boolexpr497;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr497 = FALSE ;
  else {
  mu__boolexpr497 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr497)) mu__boolexpr496 = FALSE ;
  else {
  mu__boolexpr496 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr496)) mu__boolexpr495 = FALSE ;
  else {
  mu__boolexpr495 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr495)) mu__boolexpr494 = FALSE ;
  else {
  mu__boolexpr494 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr494) {
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
    r = what_rule - 1746;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr498;
bool mu__boolexpr499;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr499 = FALSE ;
  else {
  mu__boolexpr499 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr499)) mu__boolexpr498 = FALSE ;
  else {
  mu__boolexpr498 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr498;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1755;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1764 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr500;
bool mu__boolexpr501;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr501 = FALSE ;
  else {
  mu__boolexpr501 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr501)) mu__boolexpr500 = FALSE ;
  else {
  mu__boolexpr500 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr500) {
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
    r = what_rule - 1755;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr502;
bool mu__boolexpr503;
bool mu__boolexpr504;
bool mu__boolexpr505;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr505 = FALSE ;
  else {
  mu__boolexpr505 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr505)) mu__boolexpr504 = FALSE ;
  else {
  mu__boolexpr504 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr504)) mu__boolexpr503 = FALSE ;
  else {
  mu__boolexpr503 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr503)) mu__boolexpr502 = FALSE ;
  else {
  mu__boolexpr502 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr502;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1764;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1773 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr506;
bool mu__boolexpr507;
bool mu__boolexpr508;
bool mu__boolexpr509;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr509 = FALSE ;
  else {
  mu__boolexpr509 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr509)) mu__boolexpr508 = FALSE ;
  else {
  mu__boolexpr508 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr508)) mu__boolexpr507 = FALSE ;
  else {
  mu__boolexpr507 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr507)) mu__boolexpr506 = FALSE ;
  else {
  mu__boolexpr506 = ((mu_n1) != (mu_n2)) ; 
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
    r = what_rule - 1764;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr510;
bool mu__boolexpr511;
bool mu__boolexpr512;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr512 = FALSE ;
  else {
  mu__boolexpr512 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr512)) mu__boolexpr511 = FALSE ;
  else {
  mu__boolexpr511 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr511)) mu__boolexpr510 = FALSE ;
  else {
  mu__boolexpr510 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr510;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1773;
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1791 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr513;
bool mu__boolexpr514;
bool mu__boolexpr515;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr515 = FALSE ;
  else {
  mu__boolexpr515 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr515)) mu__boolexpr514 = FALSE ;
  else {
  mu__boolexpr514 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr514)) mu__boolexpr513 = FALSE ;
  else {
  mu__boolexpr513 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr513) {
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
    r = what_rule - 1773;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
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
    static mu__subrange_21 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_21 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr516;
bool mu__boolexpr517;
bool mu__boolexpr518;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr518 = FALSE ;
  else {
  mu__boolexpr518 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr518)) mu__boolexpr517 = FALSE ;
  else {
  mu__boolexpr517 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr517)) mu__boolexpr516 = FALSE ;
  else {
  mu__boolexpr516 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr516;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1791;
    static mu__subrange_21 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1809 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr519;
bool mu__boolexpr520;
bool mu__boolexpr521;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr521 = FALSE ;
  else {
  mu__boolexpr521 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr521)) mu__boolexpr520 = FALSE ;
  else {
  mu__boolexpr520 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr520)) mu__boolexpr519 = FALSE ;
  else {
  mu__boolexpr519 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr519) {
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
    r = what_rule - 1791;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_21 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
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
    static mu__subrange_19 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_20 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Send request + Send request, n2:%s, n4:%s, n3:%s, n1:%s", mu_n2.Name(), mu_n4.Name(), mu_n3.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_19 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_20 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr522;
bool mu__boolexpr523;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2))) mu__boolexpr523 = FALSE ;
  else {
  mu__boolexpr523 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr523)) mu__boolexpr522 = FALSE ;
  else {
  mu__boolexpr522 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr522;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1809;
    static mu__subrange_19 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_20 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1845 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr524;
bool mu__boolexpr525;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2))) mu__boolexpr525 = FALSE ;
  else {
  mu__boolexpr525 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr525)) mu__boolexpr524 = FALSE ;
  else {
  mu__boolexpr524 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr524) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 1809;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_19 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_20 mu_n4;
    mu_n4.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_SendRequest ( mu_n1, (int)mu_n2 );
mu_SendRequest ( mu_n3, (int)mu_n4 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr526;
bool mu__boolexpr527;
bool mu__boolexpr528;
bool mu__boolexpr529;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr529 = FALSE ;
  else {
  mu__boolexpr529 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr529)) mu__boolexpr528 = FALSE ;
  else {
  mu__boolexpr528 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr528)) mu__boolexpr527 = FALSE ;
  else {
  mu__boolexpr527 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr527)) mu__boolexpr526 = FALSE ;
  else {
  mu__boolexpr526 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr526;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1845;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1854 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr530;
bool mu__boolexpr531;
bool mu__boolexpr532;
bool mu__boolexpr533;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr533 = FALSE ;
  else {
  mu__boolexpr533 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr533)) mu__boolexpr532 = FALSE ;
  else {
  mu__boolexpr532 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr532)) mu__boolexpr531 = FALSE ;
  else {
  mu__boolexpr531 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr531)) mu__boolexpr530 = FALSE ;
  else {
  mu__boolexpr530 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr530) {
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
    r = what_rule - 1845;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr534;
bool mu__boolexpr535;
bool mu__boolexpr536;
bool mu__boolexpr537;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr537 = FALSE ;
  else {
  mu__boolexpr537 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr537)) mu__boolexpr536 = FALSE ;
  else {
  mu__boolexpr536 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr536)) mu__boolexpr535 = FALSE ;
  else {
  mu__boolexpr535 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr535)) mu__boolexpr534 = FALSE ;
  else {
  mu__boolexpr534 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr534;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1854;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1863 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr538;
bool mu__boolexpr539;
bool mu__boolexpr540;
bool mu__boolexpr541;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr541 = FALSE ;
  else {
  mu__boolexpr541 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr541)) mu__boolexpr540 = FALSE ;
  else {
  mu__boolexpr540 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr540)) mu__boolexpr539 = FALSE ;
  else {
  mu__boolexpr539 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr539)) mu__boolexpr538 = FALSE ;
  else {
  mu__boolexpr538 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr538) {
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
    r = what_rule - 1854;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr542;
bool mu__boolexpr543;
bool mu__boolexpr544;
bool mu__boolexpr545;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr545 = FALSE ;
  else {
  mu__boolexpr545 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr545)) mu__boolexpr544 = FALSE ;
  else {
  mu__boolexpr544 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr544)) mu__boolexpr543 = FALSE ;
  else {
  mu__boolexpr543 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr543)) mu__boolexpr542 = FALSE ;
  else {
  mu__boolexpr542 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr542;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1863;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1872 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr546;
bool mu__boolexpr547;
bool mu__boolexpr548;
bool mu__boolexpr549;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr549 = FALSE ;
  else {
  mu__boolexpr549 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr549)) mu__boolexpr548 = FALSE ;
  else {
  mu__boolexpr548 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr548)) mu__boolexpr547 = FALSE ;
  else {
  mu__boolexpr547 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr547)) mu__boolexpr546 = FALSE ;
  else {
  mu__boolexpr546 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr546) {
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
    r = what_rule - 1863;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr550;
bool mu__boolexpr551;
bool mu__boolexpr552;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr552 = FALSE ;
  else {
  mu__boolexpr552 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr552)) mu__boolexpr551 = FALSE ;
  else {
  mu__boolexpr551 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr551)) mu__boolexpr550 = FALSE ;
  else {
  mu__boolexpr550 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr550;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1872;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1881 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr553;
bool mu__boolexpr554;
bool mu__boolexpr555;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr555 = FALSE ;
  else {
  mu__boolexpr555 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr555)) mu__boolexpr554 = FALSE ;
  else {
  mu__boolexpr554 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr554)) mu__boolexpr553 = FALSE ;
  else {
  mu__boolexpr553 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr553) {
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
    r = what_rule - 1872;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr556;
bool mu__boolexpr557;
bool mu__boolexpr558;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr558 = FALSE ;
  else {
  mu__boolexpr558 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr558)) mu__boolexpr557 = FALSE ;
  else {
  mu__boolexpr557 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr557)) mu__boolexpr556 = FALSE ;
  else {
  mu__boolexpr556 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr556;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1881;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1890 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr559;
bool mu__boolexpr560;
bool mu__boolexpr561;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr561 = FALSE ;
  else {
  mu__boolexpr561 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr561)) mu__boolexpr560 = FALSE ;
  else {
  mu__boolexpr560 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr560)) mu__boolexpr559 = FALSE ;
  else {
  mu__boolexpr559 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr559) {
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
    r = what_rule - 1881;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
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
    static mu__subrange_18 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_18 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr562;
bool mu__boolexpr563;
bool mu__boolexpr564;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr564 = FALSE ;
  else {
  mu__boolexpr564 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr564)) mu__boolexpr563 = FALSE ;
  else {
  mu__boolexpr563 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr563)) mu__boolexpr562 = FALSE ;
  else {
  mu__boolexpr562 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr562;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1890;
    static mu__subrange_18 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1908 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr565;
bool mu__boolexpr566;
bool mu__boolexpr567;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr567 = FALSE ;
  else {
  mu__boolexpr567 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr567)) mu__boolexpr566 = FALSE ;
  else {
  mu__boolexpr566 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (2)) ; 
}
  if (!(mu__boolexpr566)) mu__boolexpr565 = FALSE ;
  else {
  mu__boolexpr565 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr565) {
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
    r = what_rule - 1890;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_18 mu_n3;
    mu_n3.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_SendRequest ( mu_n2, (int)mu_n3 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr568;
bool mu__boolexpr569;
bool mu__boolexpr570;
bool mu__boolexpr571;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr571 = FALSE ;
  else {
  mu__boolexpr571 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr571)) mu__boolexpr570 = FALSE ;
  else {
  mu__boolexpr570 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr570)) mu__boolexpr569 = FALSE ;
  else {
  mu__boolexpr569 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr569)) mu__boolexpr568 = FALSE ;
  else {
  mu__boolexpr568 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr568;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1908;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1917 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr572;
bool mu__boolexpr573;
bool mu__boolexpr574;
bool mu__boolexpr575;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr575 = FALSE ;
  else {
  mu__boolexpr575 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr575)) mu__boolexpr574 = FALSE ;
  else {
  mu__boolexpr574 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr574)) mu__boolexpr573 = FALSE ;
  else {
  mu__boolexpr573 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr573)) mu__boolexpr572 = FALSE ;
  else {
  mu__boolexpr572 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr572) {
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
    r = what_rule - 1908;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr576;
bool mu__boolexpr577;
bool mu__boolexpr578;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr578 = FALSE ;
  else {
  mu__boolexpr578 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr578)) mu__boolexpr577 = FALSE ;
  else {
  mu__boolexpr577 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr577)) mu__boolexpr576 = FALSE ;
  else {
  mu__boolexpr576 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr576;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1917;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1926 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr579;
bool mu__boolexpr580;
bool mu__boolexpr581;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr581 = FALSE ;
  else {
  mu__boolexpr581 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr581)) mu__boolexpr580 = FALSE ;
  else {
  mu__boolexpr580 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr580)) mu__boolexpr579 = FALSE ;
  else {
  mu__boolexpr579 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr579) {
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
    r = what_rule - 1917;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 3) + 6);
    r = r / 3;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
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
    static mu__subrange_17 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Send request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_17 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return (mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1926;
    static mu__subrange_17 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1932 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (2)) {
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
    r = what_rule - 1926;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_17 mu_n2;
    mu_n2.value((r % 2) + 1);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_SendRequest ( mu_n1, (int)mu_n2 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr582;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr582 = FALSE ;
  else {
  mu__boolexpr582 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr582;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1932;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1935 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr583;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr583 = FALSE ;
  else {
  mu__boolexpr583 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr583) {
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
    r = what_rule - 1932;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdResponse ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return (mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1935;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1938 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response)) {
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
    r = what_rule - 1935;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessResponse ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process fwd_request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr584;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr584 = FALSE ;
  else {
  mu__boolexpr584 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr584;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1938;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1941 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr585;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr585 = FALSE ;
  else {
  mu__boolexpr585 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr585) {
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
    r = what_rule - 1938;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessFwdRequest ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    return tsprintf("Rule --> Process request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
bool mu__boolexpr586;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr586 = FALSE ;
  else {
  mu__boolexpr586 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
    return mu__boolexpr586;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1941;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    while (what_rule < 1944 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr587;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr587 = FALSE ;
  else {
  mu__boolexpr587 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
	      if (mu__boolexpr587) {
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
    r = what_rule - 1941;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 3) + 6);
    r = r / 3;
mu_ProcessRequest ( mu_n1 );
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
  if (what_rule<54)
    { R0.NextRule(what_rule);
      if (what_rule<54) return; }
  if (what_rule>=54 && what_rule<81)
    { R1.NextRule(what_rule);
      if (what_rule<81) return; }
  if (what_rule>=81 && what_rule<108)
    { R2.NextRule(what_rule);
      if (what_rule<108) return; }
  if (what_rule>=108 && what_rule<135)
    { R3.NextRule(what_rule);
      if (what_rule<135) return; }
  if (what_rule>=135 && what_rule<189)
    { R4.NextRule(what_rule);
      if (what_rule<189) return; }
  if (what_rule>=189 && what_rule<216)
    { R5.NextRule(what_rule);
      if (what_rule<216) return; }
  if (what_rule>=216 && what_rule<243)
    { R6.NextRule(what_rule);
      if (what_rule<243) return; }
  if (what_rule>=243 && what_rule<270)
    { R7.NextRule(what_rule);
      if (what_rule<270) return; }
  if (what_rule>=270 && what_rule<297)
    { R8.NextRule(what_rule);
      if (what_rule<297) return; }
  if (what_rule>=297 && what_rule<405)
    { R9.NextRule(what_rule);
      if (what_rule<405) return; }
  if (what_rule>=405 && what_rule<513)
    { R10.NextRule(what_rule);
      if (what_rule<513) return; }
  if (what_rule>=513 && what_rule<540)
    { R11.NextRule(what_rule);
      if (what_rule<540) return; }
  if (what_rule>=540 && what_rule<567)
    { R12.NextRule(what_rule);
      if (what_rule<567) return; }
  if (what_rule>=567 && what_rule<621)
    { R13.NextRule(what_rule);
      if (what_rule<621) return; }
  if (what_rule>=621 && what_rule<837)
    { R14.NextRule(what_rule);
      if (what_rule<837) return; }
  if (what_rule>=837 && what_rule<891)
    { R15.NextRule(what_rule);
      if (what_rule<891) return; }
  if (what_rule>=891 && what_rule<945)
    { R16.NextRule(what_rule);
      if (what_rule<945) return; }
  if (what_rule>=945 && what_rule<972)
    { R17.NextRule(what_rule);
      if (what_rule<972) return; }
  if (what_rule>=972 && what_rule<999)
    { R18.NextRule(what_rule);
      if (what_rule<999) return; }
  if (what_rule>=999 && what_rule<1053)
    { R19.NextRule(what_rule);
      if (what_rule<1053) return; }
  if (what_rule>=1053 && what_rule<1080)
    { R20.NextRule(what_rule);
      if (what_rule<1080) return; }
  if (what_rule>=1080 && what_rule<1107)
    { R21.NextRule(what_rule);
      if (what_rule<1107) return; }
  if (what_rule>=1107 && what_rule<1134)
    { R22.NextRule(what_rule);
      if (what_rule<1134) return; }
  if (what_rule>=1134 && what_rule<1242)
    { R23.NextRule(what_rule);
      if (what_rule<1242) return; }
  if (what_rule>=1242 && what_rule<1269)
    { R24.NextRule(what_rule);
      if (what_rule<1269) return; }
  if (what_rule>=1269 && what_rule<1296)
    { R25.NextRule(what_rule);
      if (what_rule<1296) return; }
  if (what_rule>=1296 && what_rule<1350)
    { R26.NextRule(what_rule);
      if (what_rule<1350) return; }
  if (what_rule>=1350 && what_rule<1377)
    { R27.NextRule(what_rule);
      if (what_rule<1377) return; }
  if (what_rule>=1377 && what_rule<1404)
    { R28.NextRule(what_rule);
      if (what_rule<1404) return; }
  if (what_rule>=1404 && what_rule<1458)
    { R29.NextRule(what_rule);
      if (what_rule<1458) return; }
  if (what_rule>=1458 && what_rule<1485)
    { R30.NextRule(what_rule);
      if (what_rule<1485) return; }
  if (what_rule>=1485 && what_rule<1512)
    { R31.NextRule(what_rule);
      if (what_rule<1512) return; }
  if (what_rule>=1512 && what_rule<1566)
    { R32.NextRule(what_rule);
      if (what_rule<1566) return; }
  if (what_rule>=1566 && what_rule<1674)
    { R33.NextRule(what_rule);
      if (what_rule<1674) return; }
  if (what_rule>=1674 && what_rule<1728)
    { R34.NextRule(what_rule);
      if (what_rule<1728) return; }
  if (what_rule>=1728 && what_rule<1746)
    { R35.NextRule(what_rule);
      if (what_rule<1746) return; }
  if (what_rule>=1746 && what_rule<1755)
    { R36.NextRule(what_rule);
      if (what_rule<1755) return; }
  if (what_rule>=1755 && what_rule<1764)
    { R37.NextRule(what_rule);
      if (what_rule<1764) return; }
  if (what_rule>=1764 && what_rule<1773)
    { R38.NextRule(what_rule);
      if (what_rule<1773) return; }
  if (what_rule>=1773 && what_rule<1791)
    { R39.NextRule(what_rule);
      if (what_rule<1791) return; }
  if (what_rule>=1791 && what_rule<1809)
    { R40.NextRule(what_rule);
      if (what_rule<1809) return; }
  if (what_rule>=1809 && what_rule<1845)
    { R41.NextRule(what_rule);
      if (what_rule<1845) return; }
  if (what_rule>=1845 && what_rule<1854)
    { R42.NextRule(what_rule);
      if (what_rule<1854) return; }
  if (what_rule>=1854 && what_rule<1863)
    { R43.NextRule(what_rule);
      if (what_rule<1863) return; }
  if (what_rule>=1863 && what_rule<1872)
    { R44.NextRule(what_rule);
      if (what_rule<1872) return; }
  if (what_rule>=1872 && what_rule<1881)
    { R45.NextRule(what_rule);
      if (what_rule<1881) return; }
  if (what_rule>=1881 && what_rule<1890)
    { R46.NextRule(what_rule);
      if (what_rule<1890) return; }
  if (what_rule>=1890 && what_rule<1908)
    { R47.NextRule(what_rule);
      if (what_rule<1908) return; }
  if (what_rule>=1908 && what_rule<1917)
    { R48.NextRule(what_rule);
      if (what_rule<1917) return; }
  if (what_rule>=1917 && what_rule<1926)
    { R49.NextRule(what_rule);
      if (what_rule<1926) return; }
  if (what_rule>=1926 && what_rule<1932)
    { R50.NextRule(what_rule);
      if (what_rule<1932) return; }
  if (what_rule>=1932 && what_rule<1935)
    { R51.NextRule(what_rule);
      if (what_rule<1935) return; }
  if (what_rule>=1935 && what_rule<1938)
    { R52.NextRule(what_rule);
      if (what_rule<1938) return; }
  if (what_rule>=1938 && what_rule<1941)
    { R53.NextRule(what_rule);
      if (what_rule<1941) return; }
  if (what_rule>=1941 && what_rule<1944)
    { R54.NextRule(what_rule);
      if (what_rule<1944) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=53) return R0.Condition(r-0);
  if (r>=54 && r<=80) return R1.Condition(r-54);
  if (r>=81 && r<=107) return R2.Condition(r-81);
  if (r>=108 && r<=134) return R3.Condition(r-108);
  if (r>=135 && r<=188) return R4.Condition(r-135);
  if (r>=189 && r<=215) return R5.Condition(r-189);
  if (r>=216 && r<=242) return R6.Condition(r-216);
  if (r>=243 && r<=269) return R7.Condition(r-243);
  if (r>=270 && r<=296) return R8.Condition(r-270);
  if (r>=297 && r<=404) return R9.Condition(r-297);
  if (r>=405 && r<=512) return R10.Condition(r-405);
  if (r>=513 && r<=539) return R11.Condition(r-513);
  if (r>=540 && r<=566) return R12.Condition(r-540);
  if (r>=567 && r<=620) return R13.Condition(r-567);
  if (r>=621 && r<=836) return R14.Condition(r-621);
  if (r>=837 && r<=890) return R15.Condition(r-837);
  if (r>=891 && r<=944) return R16.Condition(r-891);
  if (r>=945 && r<=971) return R17.Condition(r-945);
  if (r>=972 && r<=998) return R18.Condition(r-972);
  if (r>=999 && r<=1052) return R19.Condition(r-999);
  if (r>=1053 && r<=1079) return R20.Condition(r-1053);
  if (r>=1080 && r<=1106) return R21.Condition(r-1080);
  if (r>=1107 && r<=1133) return R22.Condition(r-1107);
  if (r>=1134 && r<=1241) return R23.Condition(r-1134);
  if (r>=1242 && r<=1268) return R24.Condition(r-1242);
  if (r>=1269 && r<=1295) return R25.Condition(r-1269);
  if (r>=1296 && r<=1349) return R26.Condition(r-1296);
  if (r>=1350 && r<=1376) return R27.Condition(r-1350);
  if (r>=1377 && r<=1403) return R28.Condition(r-1377);
  if (r>=1404 && r<=1457) return R29.Condition(r-1404);
  if (r>=1458 && r<=1484) return R30.Condition(r-1458);
  if (r>=1485 && r<=1511) return R31.Condition(r-1485);
  if (r>=1512 && r<=1565) return R32.Condition(r-1512);
  if (r>=1566 && r<=1673) return R33.Condition(r-1566);
  if (r>=1674 && r<=1727) return R34.Condition(r-1674);
  if (r>=1728 && r<=1745) return R35.Condition(r-1728);
  if (r>=1746 && r<=1754) return R36.Condition(r-1746);
  if (r>=1755 && r<=1763) return R37.Condition(r-1755);
  if (r>=1764 && r<=1772) return R38.Condition(r-1764);
  if (r>=1773 && r<=1790) return R39.Condition(r-1773);
  if (r>=1791 && r<=1808) return R40.Condition(r-1791);
  if (r>=1809 && r<=1844) return R41.Condition(r-1809);
  if (r>=1845 && r<=1853) return R42.Condition(r-1845);
  if (r>=1854 && r<=1862) return R43.Condition(r-1854);
  if (r>=1863 && r<=1871) return R44.Condition(r-1863);
  if (r>=1872 && r<=1880) return R45.Condition(r-1872);
  if (r>=1881 && r<=1889) return R46.Condition(r-1881);
  if (r>=1890 && r<=1907) return R47.Condition(r-1890);
  if (r>=1908 && r<=1916) return R48.Condition(r-1908);
  if (r>=1917 && r<=1925) return R49.Condition(r-1917);
  if (r>=1926 && r<=1931) return R50.Condition(r-1926);
  if (r>=1932 && r<=1934) return R51.Condition(r-1932);
  if (r>=1935 && r<=1937) return R52.Condition(r-1935);
  if (r>=1938 && r<=1940) return R53.Condition(r-1938);
  if (r>=1941 && r<=1943) return R54.Condition(r-1941);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=53) { R0.Code(r-0); return; } 
  if (r>=54 && r<=80) { R1.Code(r-54); return; } 
  if (r>=81 && r<=107) { R2.Code(r-81); return; } 
  if (r>=108 && r<=134) { R3.Code(r-108); return; } 
  if (r>=135 && r<=188) { R4.Code(r-135); return; } 
  if (r>=189 && r<=215) { R5.Code(r-189); return; } 
  if (r>=216 && r<=242) { R6.Code(r-216); return; } 
  if (r>=243 && r<=269) { R7.Code(r-243); return; } 
  if (r>=270 && r<=296) { R8.Code(r-270); return; } 
  if (r>=297 && r<=404) { R9.Code(r-297); return; } 
  if (r>=405 && r<=512) { R10.Code(r-405); return; } 
  if (r>=513 && r<=539) { R11.Code(r-513); return; } 
  if (r>=540 && r<=566) { R12.Code(r-540); return; } 
  if (r>=567 && r<=620) { R13.Code(r-567); return; } 
  if (r>=621 && r<=836) { R14.Code(r-621); return; } 
  if (r>=837 && r<=890) { R15.Code(r-837); return; } 
  if (r>=891 && r<=944) { R16.Code(r-891); return; } 
  if (r>=945 && r<=971) { R17.Code(r-945); return; } 
  if (r>=972 && r<=998) { R18.Code(r-972); return; } 
  if (r>=999 && r<=1052) { R19.Code(r-999); return; } 
  if (r>=1053 && r<=1079) { R20.Code(r-1053); return; } 
  if (r>=1080 && r<=1106) { R21.Code(r-1080); return; } 
  if (r>=1107 && r<=1133) { R22.Code(r-1107); return; } 
  if (r>=1134 && r<=1241) { R23.Code(r-1134); return; } 
  if (r>=1242 && r<=1268) { R24.Code(r-1242); return; } 
  if (r>=1269 && r<=1295) { R25.Code(r-1269); return; } 
  if (r>=1296 && r<=1349) { R26.Code(r-1296); return; } 
  if (r>=1350 && r<=1376) { R27.Code(r-1350); return; } 
  if (r>=1377 && r<=1403) { R28.Code(r-1377); return; } 
  if (r>=1404 && r<=1457) { R29.Code(r-1404); return; } 
  if (r>=1458 && r<=1484) { R30.Code(r-1458); return; } 
  if (r>=1485 && r<=1511) { R31.Code(r-1485); return; } 
  if (r>=1512 && r<=1565) { R32.Code(r-1512); return; } 
  if (r>=1566 && r<=1673) { R33.Code(r-1566); return; } 
  if (r>=1674 && r<=1727) { R34.Code(r-1674); return; } 
  if (r>=1728 && r<=1745) { R35.Code(r-1728); return; } 
  if (r>=1746 && r<=1754) { R36.Code(r-1746); return; } 
  if (r>=1755 && r<=1763) { R37.Code(r-1755); return; } 
  if (r>=1764 && r<=1772) { R38.Code(r-1764); return; } 
  if (r>=1773 && r<=1790) { R39.Code(r-1773); return; } 
  if (r>=1791 && r<=1808) { R40.Code(r-1791); return; } 
  if (r>=1809 && r<=1844) { R41.Code(r-1809); return; } 
  if (r>=1845 && r<=1853) { R42.Code(r-1845); return; } 
  if (r>=1854 && r<=1862) { R43.Code(r-1854); return; } 
  if (r>=1863 && r<=1871) { R44.Code(r-1863); return; } 
  if (r>=1872 && r<=1880) { R45.Code(r-1872); return; } 
  if (r>=1881 && r<=1889) { R46.Code(r-1881); return; } 
  if (r>=1890 && r<=1907) { R47.Code(r-1890); return; } 
  if (r>=1908 && r<=1916) { R48.Code(r-1908); return; } 
  if (r>=1917 && r<=1925) { R49.Code(r-1917); return; } 
  if (r>=1926 && r<=1931) { R50.Code(r-1926); return; } 
  if (r>=1932 && r<=1934) { R51.Code(r-1932); return; } 
  if (r>=1935 && r<=1937) { R52.Code(r-1935); return; } 
  if (r>=1938 && r<=1940) { R53.Code(r-1938); return; } 
  if (r>=1941 && r<=1943) { R54.Code(r-1941); return; } 
}
int Priority(unsigned short r)
{
  if (r<=53) { return R0.Priority(); } 
  if (r>=54 && r<=80) { return R1.Priority(); } 
  if (r>=81 && r<=107) { return R2.Priority(); } 
  if (r>=108 && r<=134) { return R3.Priority(); } 
  if (r>=135 && r<=188) { return R4.Priority(); } 
  if (r>=189 && r<=215) { return R5.Priority(); } 
  if (r>=216 && r<=242) { return R6.Priority(); } 
  if (r>=243 && r<=269) { return R7.Priority(); } 
  if (r>=270 && r<=296) { return R8.Priority(); } 
  if (r>=297 && r<=404) { return R9.Priority(); } 
  if (r>=405 && r<=512) { return R10.Priority(); } 
  if (r>=513 && r<=539) { return R11.Priority(); } 
  if (r>=540 && r<=566) { return R12.Priority(); } 
  if (r>=567 && r<=620) { return R13.Priority(); } 
  if (r>=621 && r<=836) { return R14.Priority(); } 
  if (r>=837 && r<=890) { return R15.Priority(); } 
  if (r>=891 && r<=944) { return R16.Priority(); } 
  if (r>=945 && r<=971) { return R17.Priority(); } 
  if (r>=972 && r<=998) { return R18.Priority(); } 
  if (r>=999 && r<=1052) { return R19.Priority(); } 
  if (r>=1053 && r<=1079) { return R20.Priority(); } 
  if (r>=1080 && r<=1106) { return R21.Priority(); } 
  if (r>=1107 && r<=1133) { return R22.Priority(); } 
  if (r>=1134 && r<=1241) { return R23.Priority(); } 
  if (r>=1242 && r<=1268) { return R24.Priority(); } 
  if (r>=1269 && r<=1295) { return R25.Priority(); } 
  if (r>=1296 && r<=1349) { return R26.Priority(); } 
  if (r>=1350 && r<=1376) { return R27.Priority(); } 
  if (r>=1377 && r<=1403) { return R28.Priority(); } 
  if (r>=1404 && r<=1457) { return R29.Priority(); } 
  if (r>=1458 && r<=1484) { return R30.Priority(); } 
  if (r>=1485 && r<=1511) { return R31.Priority(); } 
  if (r>=1512 && r<=1565) { return R32.Priority(); } 
  if (r>=1566 && r<=1673) { return R33.Priority(); } 
  if (r>=1674 && r<=1727) { return R34.Priority(); } 
  if (r>=1728 && r<=1745) { return R35.Priority(); } 
  if (r>=1746 && r<=1754) { return R36.Priority(); } 
  if (r>=1755 && r<=1763) { return R37.Priority(); } 
  if (r>=1764 && r<=1772) { return R38.Priority(); } 
  if (r>=1773 && r<=1790) { return R39.Priority(); } 
  if (r>=1791 && r<=1808) { return R40.Priority(); } 
  if (r>=1809 && r<=1844) { return R41.Priority(); } 
  if (r>=1845 && r<=1853) { return R42.Priority(); } 
  if (r>=1854 && r<=1862) { return R43.Priority(); } 
  if (r>=1863 && r<=1871) { return R44.Priority(); } 
  if (r>=1872 && r<=1880) { return R45.Priority(); } 
  if (r>=1881 && r<=1889) { return R46.Priority(); } 
  if (r>=1890 && r<=1907) { return R47.Priority(); } 
  if (r>=1908 && r<=1916) { return R48.Priority(); } 
  if (r>=1917 && r<=1925) { return R49.Priority(); } 
  if (r>=1926 && r<=1931) { return R50.Priority(); } 
  if (r>=1932 && r<=1934) { return R51.Priority(); } 
  if (r>=1935 && r<=1937) { return R52.Priority(); } 
  if (r>=1938 && r<=1940) { return R53.Priority(); } 
  if (r>=1941 && r<=1943) { return R54.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=53) return R0.Name(r-0);
  if (r>=54 && r<=80) return R1.Name(r-54);
  if (r>=81 && r<=107) return R2.Name(r-81);
  if (r>=108 && r<=134) return R3.Name(r-108);
  if (r>=135 && r<=188) return R4.Name(r-135);
  if (r>=189 && r<=215) return R5.Name(r-189);
  if (r>=216 && r<=242) return R6.Name(r-216);
  if (r>=243 && r<=269) return R7.Name(r-243);
  if (r>=270 && r<=296) return R8.Name(r-270);
  if (r>=297 && r<=404) return R9.Name(r-297);
  if (r>=405 && r<=512) return R10.Name(r-405);
  if (r>=513 && r<=539) return R11.Name(r-513);
  if (r>=540 && r<=566) return R12.Name(r-540);
  if (r>=567 && r<=620) return R13.Name(r-567);
  if (r>=621 && r<=836) return R14.Name(r-621);
  if (r>=837 && r<=890) return R15.Name(r-837);
  if (r>=891 && r<=944) return R16.Name(r-891);
  if (r>=945 && r<=971) return R17.Name(r-945);
  if (r>=972 && r<=998) return R18.Name(r-972);
  if (r>=999 && r<=1052) return R19.Name(r-999);
  if (r>=1053 && r<=1079) return R20.Name(r-1053);
  if (r>=1080 && r<=1106) return R21.Name(r-1080);
  if (r>=1107 && r<=1133) return R22.Name(r-1107);
  if (r>=1134 && r<=1241) return R23.Name(r-1134);
  if (r>=1242 && r<=1268) return R24.Name(r-1242);
  if (r>=1269 && r<=1295) return R25.Name(r-1269);
  if (r>=1296 && r<=1349) return R26.Name(r-1296);
  if (r>=1350 && r<=1376) return R27.Name(r-1350);
  if (r>=1377 && r<=1403) return R28.Name(r-1377);
  if (r>=1404 && r<=1457) return R29.Name(r-1404);
  if (r>=1458 && r<=1484) return R30.Name(r-1458);
  if (r>=1485 && r<=1511) return R31.Name(r-1485);
  if (r>=1512 && r<=1565) return R32.Name(r-1512);
  if (r>=1566 && r<=1673) return R33.Name(r-1566);
  if (r>=1674 && r<=1727) return R34.Name(r-1674);
  if (r>=1728 && r<=1745) return R35.Name(r-1728);
  if (r>=1746 && r<=1754) return R36.Name(r-1746);
  if (r>=1755 && r<=1763) return R37.Name(r-1755);
  if (r>=1764 && r<=1772) return R38.Name(r-1764);
  if (r>=1773 && r<=1790) return R39.Name(r-1773);
  if (r>=1791 && r<=1808) return R40.Name(r-1791);
  if (r>=1809 && r<=1844) return R41.Name(r-1809);
  if (r>=1845 && r<=1853) return R42.Name(r-1845);
  if (r>=1854 && r<=1862) return R43.Name(r-1854);
  if (r>=1863 && r<=1871) return R44.Name(r-1863);
  if (r>=1872 && r<=1880) return R45.Name(r-1872);
  if (r>=1881 && r<=1889) return R46.Name(r-1881);
  if (r>=1890 && r<=1907) return R47.Name(r-1890);
  if (r>=1908 && r<=1916) return R48.Name(r-1908);
  if (r>=1917 && r<=1925) return R49.Name(r-1917);
  if (r>=1926 && r<=1931) return R50.Name(r-1926);
  if (r>=1932 && r<=1934) return R51.Name(r-1932);
  if (r>=1935 && r<=1937) return R52.Name(r-1935);
  if (r>=1938 && r<=1940) return R53.Name(r-1938);
  if (r>=1941 && r<=1943) return R54.Name(r-1941);
  return NULL;
}
};
const unsigned numrules = 1944;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 1944


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
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_msg_type = mu_empty;
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_src_hops = 0;
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_dest_hops = 0;
};
};
mu_Nodes[mu_nid1].mu_TailPointer = 0;
mu_Nodes[mu_nid1].mu_FrontPointer = 0;
mu_Nodes[mu_nid1].mu_Next = mu_GetNextNode( mu_nid1 );
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
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  mu_Next.Permute(Perm,i);
};
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  mu_Next.SimpleCanonicalize(Perm);
};
void mu_1_Node::Canonicalize(PermSet& Perm)
{
};
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  mu_Next.SimpleLimit(Perm);
};
void mu_1_Node::ArrayLimit(PermSet& Perm){}
void mu_1_Node::Limit(PermSet& Perm)
{
};
void mu_1_Node::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=6; j<=8; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_NodeIDs[Perm.in_mu_1_NodeIDs[i]][j-6]];};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
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
void mu_1__type_5::Limit(PermSet& Perm)
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

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+6].mu_Next.isundefined()
            ||(*this)[k+6].mu_Next!=k+6)
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
                    && !(*this)[k+6].mu_Next.isundefined()
                    && (*this)[k+6].mu_Next==k+6)
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

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<3)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+6].mu_Next.isundefined()
                &&(*this)[k+6].mu_Next!=k+6)
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
                            && !(*this)[k+6].mu_Next.isundefined()
                            && (*this)[k+6].mu_Next!=k+6
                            && pos_mu_1_NodeIDs[j][(*this)[k+6].mu_Next-6])
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
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i) {};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_6::Canonicalize(PermSet& Perm) {};
void mu_1__type_6::SimpleLimit(PermSet& Perm) {};
void mu_1__type_6::ArrayLimit(PermSet& Perm) {};
void mu_1__type_6::Limit(PermSet& Perm) {};
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_15::Permute(PermSet& Perm, int i) {};
void mu__subrange_15::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_15::Canonicalize(PermSet& Perm) {};
void mu__subrange_15::SimpleLimit(PermSet& Perm) {};
void mu__subrange_15::ArrayLimit(PermSet& Perm) {};
void mu__subrange_15::Limit(PermSet& Perm) {};
void mu__subrange_15::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
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
