/******************************
  Program "pop.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Sep  6 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Sep  6 2024"
#define PROTOCOL_NAME "pop"
#define BITS_IN_WORLD 44
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

  mu_1_NodeIDs (const char *name, int os): mu__byte(6, 7, 2, name, os) {};
  mu_1_NodeIDs (void): mu__byte(6, 7, 2) {};
  mu_1_NodeIDs (int val): mu__byte(6, 7, 2, "Parameter or function result.", 0)
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
  { "NodeIDs_1","NodeIDs_2",NULL };

/*** end scalarset declaration ***/
mu_1_NodeIDs mu_1_NodeIDs_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 2, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu_1__type_1 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 2, 2) {};
  mu_1__type_1 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  if (name) mu_src_hops.set_self_2(name, ".src_hops", os + 5 ); else mu_src_hops.set_self_2(NULL, NULL, 0);
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
  mu__subrange_8 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_8 (void): mu__byte(0, 1, 2) {};
  mu__subrange_8 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu_1_Message array[ 2 ];
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
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 7 + os);
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
  mu_1__type_3 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_3 (void): mu__byte(0, 2, 2) {};
  mu_1__type_3 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu_1__type_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_5& val) { return mu__byte::operator=((int) val); };
  mu_1__type_5 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_5 (void): mu__byte(0, 2, 2) {};
  mu_1__type_5 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu_1__type_5 mu_IntentToSendRequest;
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
    w = CompareWeight(a.mu_IntentToSendRequest, b.mu_IntentToSendRequest);
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
    w = Compare(a.mu_IntentToSendRequest, b.mu_IntentToSendRequest);
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
    mu_IntentToSendRequest.MultisetSort();
  }
  void print_statistic()
  {
    mu_IncomingQueue.print_statistic();
    mu_TailPointer.print_statistic();
    mu_FrontPointer.print_statistic();
    mu_Next.print_statistic();
    mu_IntentToSendRequest.print_statistic();
  }
  void clear() {
    mu_IncomingQueue.clear();
    mu_TailPointer.clear();
    mu_FrontPointer.clear();
    mu_Next.clear();
    mu_IntentToSendRequest.clear();
 };
  void undefine() {
    mu_IncomingQueue.undefine();
    mu_TailPointer.undefine();
    mu_FrontPointer.undefine();
    mu_Next.undefine();
    mu_IntentToSendRequest.undefine();
 };
  void reset() {
    mu_IncomingQueue.reset();
    mu_TailPointer.reset();
    mu_FrontPointer.reset();
    mu_Next.reset();
    mu_IntentToSendRequest.reset();
 };
  void print() {
    mu_IncomingQueue.print();
    mu_TailPointer.print();
    mu_FrontPointer.print();
    mu_Next.print();
    mu_IntentToSendRequest.print();
  };
  void print_diff(state *prevstate) {
    mu_IncomingQueue.print_diff(prevstate);
    mu_TailPointer.print_diff(prevstate);
    mu_FrontPointer.print_diff(prevstate);
    mu_Next.print_diff(prevstate);
    mu_IntentToSendRequest.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_IncomingQueue.to_state(thestate);
    mu_TailPointer.to_state(thestate);
    mu_FrontPointer.to_state(thestate);
    mu_Next.to_state(thestate);
    mu_IntentToSendRequest.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Node& operator= (const mu_1_Node& from) {
    mu_IncomingQueue = from.mu_IncomingQueue;
    mu_TailPointer.value(from.mu_TailPointer.value());
    mu_FrontPointer.value(from.mu_FrontPointer.value());
    mu_Next.value(from.mu_Next.value());
    mu_IntentToSendRequest.value(from.mu_IntentToSendRequest.value());
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
  if (name) mu_TailPointer.set_self_2(name, ".TailPointer", os + 14 ); else mu_TailPointer.set_self_2(NULL, NULL, 0);
  if (name) mu_FrontPointer.set_self_2(name, ".FrontPointer", os + 16 ); else mu_FrontPointer.set_self_2(NULL, NULL, 0);
  if (name) mu_Next.set_self_2(name, ".Next", os + 18 ); else mu_Next.set_self_2(NULL, NULL, 0);
  if (name) mu_IntentToSendRequest.set_self_2(name, ".IntentToSendRequest", os + 20 ); else mu_IntentToSendRequest.set_self_2(NULL, NULL, 0);
}

mu_1_Node::~mu_1_Node()
{
}

/*** end record declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1__type_6
{
 public:
  mu_1_Node array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_6 (const char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1_Node& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 7 ) )
      return array[ index - 6 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: NodeIDs is internally represented from 7 to 6.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
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
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"NodeIDs_1", i * 22 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"NodeIDs_2", i * 22 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
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
  mu_1__type_7 (const char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu_1__type_7 (void): mu__byte(1, 2, 2) {};
  mu_1__type_7 (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

class mu__subrange_16: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_16& val) { return mu__byte::operator=((int) val); };
  mu__subrange_16 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_16 (void): mu__byte(1, 1, 1) {};
  mu__subrange_16 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_18 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_18 (void): mu__byte(1, 1, 1) {};
  mu__subrange_18 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_19 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_19 (void): mu__byte(1, 1, 1) {};
  mu__subrange_19 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_20 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_20 (void): mu__byte(1, 1, 1) {};
  mu__subrange_20 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_21 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_21 (void): mu__byte(1, 1, 1) {};
  mu__subrange_21 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_22 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_22 (void): mu__byte(1, 1, 1) {};
  mu__subrange_22 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_23 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_23 (void): mu__byte(1, 1, 1) {};
  mu__subrange_23 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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
  mu__subrange_24 (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu__subrange_24 (void): mu__byte(1, 1, 1) {};
  mu__subrange_24 (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
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

const int mu_NumberNodes = 2;
const int mu_BufferSpace = 2;
const int mu_empty = 1;
const int mu_response = 2;
const int mu_request = 3;
const int mu_fwd_request = 4;
const int mu_fwd_response = 5;
const int mu_NodeIDs_1 = 6;
const int mu_NodeIDs_2 = 7;
/*** Variable declaration ***/
mu_1__type_6 mu_Nodes("Nodes",0);

void mu_SendRequest(const mu_1_NodeIDs& mu_src_nid, const mu_1__type_7& mu_next_hop_length)
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
mu_msg_to_send.mu_src_hops = 1;
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
int mu__ub10 = (mu_Nodes[mu_src_nid].mu_TailPointer) - (1);
for (int mu_i = 1; mu_i <= mu__ub10; mu_i += 1) {
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
for(int mu_i = 1; mu_i <= 1; mu_i++) {
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
for(int mu_i = 6; mu_i <= 7; mu_i++) {
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
for(int mu_i = 6; mu_i <= 7; mu_i++) {
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr11;
bool mu__boolexpr12;
bool mu__boolexpr13;
bool mu__boolexpr14;
bool mu__boolexpr15;
bool mu__boolexpr16;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr11;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr18)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_n1) != (mu_n2)) ; 
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr23;
bool mu__boolexpr24;
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr23;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 8 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr29) {
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
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
  mu__boolexpr38 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr35;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr40;
bool mu__boolexpr41;
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr40) {
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
if ( (mu_Nodes[mu_n2].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 1;
}
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
    static mu__subrange_24 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process request + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_24 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
bool mu__boolexpr48;
bool mu__boolexpr49;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr45;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu__subrange_24 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 16 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
bool mu__boolexpr53;
bool mu__boolexpr54;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr50) {
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
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_24 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessRequest ( mu_n1 );
bool mu__boolexpr55;
  if ((mu_Nodes[mu_n2].mu_IntentToSendRequest) == (1)) mu__boolexpr55 = TRUE ;
  else {
  mu__boolexpr55 = ((mu_Nodes[mu_n2].mu_TailPointer) == (mu_Nodes[mu_n2].mu_FrontPointer)) ; 
}
if ( mu__boolexpr55 )
{
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_Nodes[mu_n2].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 2;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process response + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr56;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 20 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr60) {
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessResponse ( mu_n1 );
if ( (mu_Nodes[mu_n1].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n1].mu_IntentToSendRequest = 1;
}
mu_ProcessResponse ( mu_n2 );
if ( (mu_Nodes[mu_n2].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 1;
}
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
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_response + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr64;
bool mu__boolexpr65;
bool mu__boolexpr66;
bool mu__boolexpr67;
bool mu__boolexpr68;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr64;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 24 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr69;
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
bool mu__boolexpr73;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr70)) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr69) {
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
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_23 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdResponse ( mu_n1 );
bool mu__boolexpr74;
  if ((mu_Nodes[mu_n2].mu_IntentToSendRequest) == (1)) mu__boolexpr74 = TRUE ;
  else {
  mu__boolexpr74 = ((mu_Nodes[mu_n2].mu_TailPointer) == (mu_Nodes[mu_n2].mu_FrontPointer)) ; 
}
if ( mu__boolexpr74 )
{
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_Nodes[mu_n2].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 2;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr75;
bool mu__boolexpr76;
bool mu__boolexpr77;
bool mu__boolexpr78;
bool mu__boolexpr79;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr79)) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr78)) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr76)) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr75;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 24;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 28 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr80;
bool mu__boolexpr81;
bool mu__boolexpr82;
bool mu__boolexpr83;
bool mu__boolexpr84;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr84)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr83)) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr80) {
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
if ( (mu_Nodes[mu_n2].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 1;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process request + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr85;
bool mu__boolexpr86;
bool mu__boolexpr87;
bool mu__boolexpr88;
bool mu__boolexpr89;
bool mu__boolexpr90;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr88)) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr86)) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr85;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 28;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 32 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr91;
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
bool mu__boolexpr95;
bool mu__boolexpr96;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr92)) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr91) {
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
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessRequest ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process response + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr97;
bool mu__boolexpr98;
bool mu__boolexpr99;
bool mu__boolexpr100;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr99)) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr98)) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr97;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 32;
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 36 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr101) {
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
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_22 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessResponse ( mu_n1 );
if ( (mu_Nodes[mu_n1].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n1].mu_IntentToSendRequest = 1;
}
bool mu__boolexpr105;
  if ((mu_Nodes[mu_n2].mu_IntentToSendRequest) == (1)) mu__boolexpr105 = TRUE ;
  else {
  mu__boolexpr105 = ((mu_Nodes[mu_n2].mu_TailPointer) == (mu_Nodes[mu_n2].mu_FrontPointer)) ; 
}
if ( mu__boolexpr105 )
{
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_Nodes[mu_n2].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 2;
}
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
    static mu__subrange_20 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu__subrange_21 mu_n4;
    mu_n4.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Send request + Send request, n2:%s, n4:%s, n3:%s, n1:%s", mu_n2.Name(), mu_n4.Name(), mu_n3.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_20 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu__subrange_21 mu_n4;
    mu_n4.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr106;
bool mu__boolexpr107;
bool mu__boolexpr108;
bool mu__boolexpr109;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace))) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr109)) mu__boolexpr108 = FALSE ;
  else {
  mu__boolexpr108 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr108)) mu__boolexpr107 = FALSE ;
  else {
  mu__boolexpr107 = ((mu_Nodes[mu_n3].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr107)) mu__boolexpr106 = FALSE ;
  else {
  mu__boolexpr106 = ((mu_n1) != (mu_n3)) ; 
}
    return mu__boolexpr106;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 36;
    static mu__subrange_20 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu__subrange_21 mu_n4;
    mu_n4.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 40 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr110;
bool mu__boolexpr111;
bool mu__boolexpr112;
bool mu__boolexpr113;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace))) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr113)) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_Nodes[mu_Nodes[mu_n3].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr112)) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_Nodes[mu_n3].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_n1) != (mu_n3)) ; 
}
	      if (mu__boolexpr110) {
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
    r = what_rule - 36;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    mu_n4.value((r % 1) + 1);
    r = r / 1;
    mu_n3.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_20 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu__subrange_21 mu_n4;
    mu_n4.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n3;
    mu_n3.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr114;
  if ((mu_Nodes[mu_n1].mu_IntentToSendRequest) == (1)) mu__boolexpr114 = TRUE ;
  else {
  mu__boolexpr114 = ((mu_Nodes[mu_n1].mu_TailPointer) == (mu_Nodes[mu_n1].mu_FrontPointer)) ; 
}
if ( mu__boolexpr114 )
{
mu_SendRequest ( mu_n1, (int)mu_n2 );
mu_Nodes[mu_n1].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n1].mu_IntentToSendRequest = 2;
}
bool mu__boolexpr115;
  if ((mu_Nodes[mu_n3].mu_IntentToSendRequest) == (1)) mu__boolexpr115 = TRUE ;
  else {
  mu__boolexpr115 = ((mu_Nodes[mu_n3].mu_TailPointer) == (mu_Nodes[mu_n3].mu_FrontPointer)) ; 
}
if ( mu__boolexpr115 )
{
mu_SendRequest ( mu_n3, (int)mu_n4 );
mu_Nodes[mu_n3].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n3].mu_IntentToSendRequest = 2;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_response + Process request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
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
  mu__boolexpr120 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr120)) mu__boolexpr119 = FALSE ;
  else {
  mu__boolexpr119 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr119)) mu__boolexpr118 = FALSE ;
  else {
  mu__boolexpr118 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr118)) mu__boolexpr117 = FALSE ;
  else {
  mu__boolexpr117 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr117)) mu__boolexpr116 = FALSE ;
  else {
  mu__boolexpr116 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr116;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 40;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 44 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr122;
bool mu__boolexpr123;
bool mu__boolexpr124;
bool mu__boolexpr125;
bool mu__boolexpr126;
bool mu__boolexpr127;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr127 = FALSE ;
  else {
  mu__boolexpr127 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr127)) mu__boolexpr126 = FALSE ;
  else {
  mu__boolexpr126 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr126)) mu__boolexpr125 = FALSE ;
  else {
  mu__boolexpr125 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_request)) ; 
}
  if (!(mu__boolexpr125)) mu__boolexpr124 = FALSE ;
  else {
  mu__boolexpr124 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr124)) mu__boolexpr123 = FALSE ;
  else {
  mu__boolexpr123 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr123)) mu__boolexpr122 = FALSE ;
  else {
  mu__boolexpr122 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr122) {
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
    r = what_rule - 40;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessRequest ( mu_n2 );
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
    static mu__subrange_19 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request + Send request, n3:%s, n2:%s, n1:%s", mu_n3.Name(), mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_19 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr128;
bool mu__boolexpr129;
bool mu__boolexpr130;
bool mu__boolexpr131;
bool mu__boolexpr132;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr132 = FALSE ;
  else {
  mu__boolexpr132 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr132)) mu__boolexpr131 = FALSE ;
  else {
  mu__boolexpr131 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr131)) mu__boolexpr130 = FALSE ;
  else {
  mu__boolexpr130 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr130)) mu__boolexpr129 = FALSE ;
  else {
  mu__boolexpr129 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr129)) mu__boolexpr128 = FALSE ;
  else {
  mu__boolexpr128 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr128;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 44;
    static mu__subrange_19 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 48 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr133;
bool mu__boolexpr134;
bool mu__boolexpr135;
bool mu__boolexpr136;
bool mu__boolexpr137;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr137 = FALSE ;
  else {
  mu__boolexpr137 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr137)) mu__boolexpr136 = FALSE ;
  else {
  mu__boolexpr136 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr136)) mu__boolexpr135 = FALSE ;
  else {
  mu__boolexpr135 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr135)) mu__boolexpr134 = FALSE ;
  else {
  mu__boolexpr134 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (2)) ; 
}
  if (!(mu__boolexpr134)) mu__boolexpr133 = FALSE ;
  else {
  mu__boolexpr133 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr133) {
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
    r = what_rule - 44;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_19 mu_n3;
    mu_n3.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
bool mu__boolexpr138;
  if ((mu_Nodes[mu_n2].mu_IntentToSendRequest) == (1)) mu__boolexpr138 = TRUE ;
  else {
  mu__boolexpr138 = ((mu_Nodes[mu_n2].mu_TailPointer) == (mu_Nodes[mu_n2].mu_FrontPointer)) ; 
}
if ( mu__boolexpr138 )
{
mu_SendRequest ( mu_n2, (int)mu_n3 );
mu_Nodes[mu_n2].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 2;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_response + Process fwd_response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr139;
bool mu__boolexpr140;
bool mu__boolexpr141;
bool mu__boolexpr142;
bool mu__boolexpr143;
bool mu__boolexpr144;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr144 = FALSE ;
  else {
  mu__boolexpr144 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr144)) mu__boolexpr143 = FALSE ;
  else {
  mu__boolexpr143 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr143)) mu__boolexpr142 = FALSE ;
  else {
  mu__boolexpr142 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr142)) mu__boolexpr141 = FALSE ;
  else {
  mu__boolexpr141 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr141)) mu__boolexpr140 = FALSE ;
  else {
  mu__boolexpr140 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr140)) mu__boolexpr139 = FALSE ;
  else {
  mu__boolexpr139 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr139;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 48;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 52 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr145;
bool mu__boolexpr146;
bool mu__boolexpr147;
bool mu__boolexpr148;
bool mu__boolexpr149;
bool mu__boolexpr150;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr150 = FALSE ;
  else {
  mu__boolexpr150 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr150)) mu__boolexpr149 = FALSE ;
  else {
  mu__boolexpr149 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr149)) mu__boolexpr148 = FALSE ;
  else {
  mu__boolexpr148 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_response)) ; 
}
  if (!(mu__boolexpr148)) mu__boolexpr147 = FALSE ;
  else {
  mu__boolexpr147 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr147)) mu__boolexpr146 = FALSE ;
  else {
  mu__boolexpr146 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr146)) mu__boolexpr145 = FALSE ;
  else {
  mu__boolexpr145 = ((mu_n1) != (mu_n2)) ; 
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
    r = what_rule - 48;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdResponse ( mu_n1 );
mu_ProcessFwdResponse ( mu_n2 );
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process request + Process response, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr151;
bool mu__boolexpr152;
bool mu__boolexpr153;
bool mu__boolexpr154;
bool mu__boolexpr155;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr155 = FALSE ;
  else {
  mu__boolexpr155 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr155)) mu__boolexpr154 = FALSE ;
  else {
  mu__boolexpr154 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr154)) mu__boolexpr153 = FALSE ;
  else {
  mu__boolexpr153 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr153)) mu__boolexpr152 = FALSE ;
  else {
  mu__boolexpr152 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr152)) mu__boolexpr151 = FALSE ;
  else {
  mu__boolexpr151 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr151;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 52;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 56 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr156;
bool mu__boolexpr157;
bool mu__boolexpr158;
bool mu__boolexpr159;
bool mu__boolexpr160;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr160 = FALSE ;
  else {
  mu__boolexpr160 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr160)) mu__boolexpr159 = FALSE ;
  else {
  mu__boolexpr159 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr159)) mu__boolexpr158 = FALSE ;
  else {
  mu__boolexpr158 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_response)) ; 
}
  if (!(mu__boolexpr158)) mu__boolexpr157 = FALSE ;
  else {
  mu__boolexpr157 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr157)) mu__boolexpr156 = FALSE ;
  else {
  mu__boolexpr156 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr156) {
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
    r = what_rule - 52;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessRequest ( mu_n1 );
mu_ProcessResponse ( mu_n2 );
if ( (mu_Nodes[mu_n2].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n2].mu_IntentToSendRequest = 1;
}
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
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request + Process fwd_request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr161;
bool mu__boolexpr162;
bool mu__boolexpr163;
bool mu__boolexpr164;
bool mu__boolexpr165;
bool mu__boolexpr166;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr166 = FALSE ;
  else {
  mu__boolexpr166 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr166)) mu__boolexpr165 = FALSE ;
  else {
  mu__boolexpr165 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr165)) mu__boolexpr164 = FALSE ;
  else {
  mu__boolexpr164 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr164)) mu__boolexpr163 = FALSE ;
  else {
  mu__boolexpr163 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr163)) mu__boolexpr162 = FALSE ;
  else {
  mu__boolexpr162 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr162)) mu__boolexpr161 = FALSE ;
  else {
  mu__boolexpr161 = ((mu_n1) != (mu_n2)) ; 
}
    return mu__boolexpr161;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 56;
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 60 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr167;
bool mu__boolexpr168;
bool mu__boolexpr169;
bool mu__boolexpr170;
bool mu__boolexpr171;
bool mu__boolexpr172;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr172 = FALSE ;
  else {
  mu__boolexpr172 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr172)) mu__boolexpr171 = FALSE ;
  else {
  mu__boolexpr171 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr171)) mu__boolexpr170 = FALSE ;
  else {
  mu__boolexpr170 = ((mu_Nodes[mu_n2].mu_IncomingQueue[mu_Nodes[mu_n2].mu_FrontPointer].mu_msg_type) == (mu_fwd_request)) ; 
}
  if (!(mu__boolexpr170)) mu__boolexpr169 = FALSE ;
  else {
  mu__boolexpr169 = ((mu_Nodes[mu_Nodes[mu_n2].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr169)) mu__boolexpr168 = FALSE ;
  else {
  mu__boolexpr168 = ((mu_Nodes[mu_n2].mu_IntentToSendRequest) != (1)) ; 
}
  if (!(mu__boolexpr168)) mu__boolexpr167 = FALSE ;
  else {
  mu__boolexpr167 = ((mu_n1) != (mu_n2)) ; 
}
	      if (mu__boolexpr167) {
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
    r = what_rule - 56;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n2;
    mu_n2.value((r % 2) + 6);
    r = r / 2;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
mu_ProcessFwdRequest ( mu_n2 );
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
    static mu__subrange_18 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Send request, n2:%s, n1:%s", mu_n2.Name(), mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_18 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr173;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace))) mu__boolexpr173 = FALSE ;
  else {
  mu__boolexpr173 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (2)) ; 
}
    return mu__boolexpr173;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 60;
    static mu__subrange_18 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 62 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr174;
  if (!((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace))) mu__boolexpr174 = FALSE ;
  else {
  mu__boolexpr174 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (2)) ; 
}
	      if (mu__boolexpr174) {
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
    r = what_rule - 60;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_18 mu_n2;
    mu_n2.value((r % 1) + 1);
    r = r / 1;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr175;
  if ((mu_Nodes[mu_n1].mu_IntentToSendRequest) == (1)) mu__boolexpr175 = TRUE ;
  else {
  mu__boolexpr175 = ((mu_Nodes[mu_n1].mu_TailPointer) == (mu_Nodes[mu_n1].mu_FrontPointer)) ; 
}
if ( mu__boolexpr175 )
{
mu_SendRequest ( mu_n1, (int)mu_n2 );
mu_Nodes[mu_n1].mu_IntentToSendRequest = 0;
}
else
{
mu_Nodes[mu_n1].mu_IntentToSendRequest = 2;
}
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr176;
bool mu__boolexpr177;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr177 = FALSE ;
  else {
  mu__boolexpr177 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr177)) mu__boolexpr176 = FALSE ;
  else {
  mu__boolexpr176 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
    return mu__boolexpr176;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 62;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 64 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr178;
bool mu__boolexpr179;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_request))) mu__boolexpr179 = FALSE ;
  else {
  mu__boolexpr179 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr179)) mu__boolexpr178 = FALSE ;
  else {
  mu__boolexpr178 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
	      if (mu__boolexpr178) {
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
    r = what_rule - 62;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdRequest ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process request, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr180;
bool mu__boolexpr181;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr181 = FALSE ;
  else {
  mu__boolexpr181 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr181)) mu__boolexpr180 = FALSE ;
  else {
  mu__boolexpr180 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
    return mu__boolexpr180;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 64;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 66 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr182;
bool mu__boolexpr183;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_request))) mu__boolexpr183 = FALSE ;
  else {
  mu__boolexpr183 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr183)) mu__boolexpr182 = FALSE ;
  else {
  mu__boolexpr182 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
	      if (mu__boolexpr182) {
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
    r = what_rule - 64;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessRequest ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process fwd_response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr184;
bool mu__boolexpr185;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr185 = FALSE ;
  else {
  mu__boolexpr185 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr185)) mu__boolexpr184 = FALSE ;
  else {
  mu__boolexpr184 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
    return mu__boolexpr184;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 66;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 68 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr186;
bool mu__boolexpr187;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_fwd_response))) mu__boolexpr187 = FALSE ;
  else {
  mu__boolexpr187 = ((mu_Nodes[mu_Nodes[mu_n1].mu_Next].mu_TailPointer) < (mu_BufferSpace)) ; 
}
  if (!(mu__boolexpr187)) mu__boolexpr186 = FALSE ;
  else {
  mu__boolexpr186 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
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
    r = what_rule - 66;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessFwdResponse ( mu_n1 );
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
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    return tsprintf("Rule --> Process response, n1:%s", mu_n1.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
bool mu__boolexpr188;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr188 = FALSE ;
  else {
  mu__boolexpr188 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
    return mu__boolexpr188;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 68;
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    while (what_rule < 70 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr189;
  if (!((mu_Nodes[mu_n1].mu_IncomingQueue[mu_Nodes[mu_n1].mu_FrontPointer].mu_msg_type) == (mu_response))) mu__boolexpr189 = FALSE ;
  else {
  mu__boolexpr189 = ((mu_Nodes[mu_n1].mu_IntentToSendRequest) != (1)) ; 
}
	      if (mu__boolexpr189) {
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
    r = what_rule - 68;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_NodeIDs mu_n1;
    mu_n1.value((r % 2) + 6);
    r = r / 2;
mu_ProcessResponse ( mu_n1 );
if ( (mu_Nodes[mu_n1].mu_IntentToSendRequest) == (2) )
{
mu_Nodes[mu_n1].mu_IntentToSendRequest = 1;
}
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
  if (what_rule>=36 && what_rule<40)
    { R9.NextRule(what_rule);
      if (what_rule<40) return; }
  if (what_rule>=40 && what_rule<44)
    { R10.NextRule(what_rule);
      if (what_rule<44) return; }
  if (what_rule>=44 && what_rule<48)
    { R11.NextRule(what_rule);
      if (what_rule<48) return; }
  if (what_rule>=48 && what_rule<52)
    { R12.NextRule(what_rule);
      if (what_rule<52) return; }
  if (what_rule>=52 && what_rule<56)
    { R13.NextRule(what_rule);
      if (what_rule<56) return; }
  if (what_rule>=56 && what_rule<60)
    { R14.NextRule(what_rule);
      if (what_rule<60) return; }
  if (what_rule>=60 && what_rule<62)
    { R15.NextRule(what_rule);
      if (what_rule<62) return; }
  if (what_rule>=62 && what_rule<64)
    { R16.NextRule(what_rule);
      if (what_rule<64) return; }
  if (what_rule>=64 && what_rule<66)
    { R17.NextRule(what_rule);
      if (what_rule<66) return; }
  if (what_rule>=66 && what_rule<68)
    { R18.NextRule(what_rule);
      if (what_rule<68) return; }
  if (what_rule>=68 && what_rule<70)
    { R19.NextRule(what_rule);
      if (what_rule<70) return; }
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
  if (r>=36 && r<=39) return R9.Condition(r-36);
  if (r>=40 && r<=43) return R10.Condition(r-40);
  if (r>=44 && r<=47) return R11.Condition(r-44);
  if (r>=48 && r<=51) return R12.Condition(r-48);
  if (r>=52 && r<=55) return R13.Condition(r-52);
  if (r>=56 && r<=59) return R14.Condition(r-56);
  if (r>=60 && r<=61) return R15.Condition(r-60);
  if (r>=62 && r<=63) return R16.Condition(r-62);
  if (r>=64 && r<=65) return R17.Condition(r-64);
  if (r>=66 && r<=67) return R18.Condition(r-66);
  if (r>=68 && r<=69) return R19.Condition(r-68);
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
  if (r>=36 && r<=39) { R9.Code(r-36); return; } 
  if (r>=40 && r<=43) { R10.Code(r-40); return; } 
  if (r>=44 && r<=47) { R11.Code(r-44); return; } 
  if (r>=48 && r<=51) { R12.Code(r-48); return; } 
  if (r>=52 && r<=55) { R13.Code(r-52); return; } 
  if (r>=56 && r<=59) { R14.Code(r-56); return; } 
  if (r>=60 && r<=61) { R15.Code(r-60); return; } 
  if (r>=62 && r<=63) { R16.Code(r-62); return; } 
  if (r>=64 && r<=65) { R17.Code(r-64); return; } 
  if (r>=66 && r<=67) { R18.Code(r-66); return; } 
  if (r>=68 && r<=69) { R19.Code(r-68); return; } 
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
  if (r>=36 && r<=39) { return R9.Priority(); } 
  if (r>=40 && r<=43) { return R10.Priority(); } 
  if (r>=44 && r<=47) { return R11.Priority(); } 
  if (r>=48 && r<=51) { return R12.Priority(); } 
  if (r>=52 && r<=55) { return R13.Priority(); } 
  if (r>=56 && r<=59) { return R14.Priority(); } 
  if (r>=60 && r<=61) { return R15.Priority(); } 
  if (r>=62 && r<=63) { return R16.Priority(); } 
  if (r>=64 && r<=65) { return R17.Priority(); } 
  if (r>=66 && r<=67) { return R18.Priority(); } 
  if (r>=68 && r<=69) { return R19.Priority(); } 
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
  if (r>=36 && r<=39) return R9.Name(r-36);
  if (r>=40 && r<=43) return R10.Name(r-40);
  if (r>=44 && r<=47) return R11.Name(r-44);
  if (r>=48 && r<=51) return R12.Name(r-48);
  if (r>=52 && r<=55) return R13.Name(r-52);
  if (r>=56 && r<=59) return R14.Name(r-56);
  if (r>=60 && r<=61) return R15.Name(r-60);
  if (r>=62 && r<=63) return R16.Name(r-62);
  if (r>=64 && r<=65) return R17.Name(r-64);
  if (r>=66 && r<=67) return R18.Name(r-66);
  if (r>=68 && r<=69) return R19.Name(r-68);
  return NULL;
}
};
const unsigned numrules = 70;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 70


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
for(int mu_nid1 = 6; mu_nid1 <= 7; mu_nid1++) {
{
for(int mu_s = 0; mu_s <= 1; mu_s++) {
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_msg_type = mu_empty;
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_src_hops = 0;
mu_Nodes[mu_nid1].mu_IncomingQueue[mu_s].mu_dest_hops = 0;
};
};
mu_Nodes[mu_nid1].mu_TailPointer = 0;
mu_Nodes[mu_nid1].mu_FrontPointer = 0;
mu_Nodes[mu_nid1].mu_Next = mu_GetNextNode( mu_nid1 );
mu_Nodes[mu_nid1].mu_IntentToSendRequest = 0;
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
  int class_mu_1_NodeIDs[2];
  int undefined_class_mu_1_NodeIDs;// has the highest class number

  void Print_class_mu_1_NodeIDs();
  bool OnlyOneRemain_mu_1_NodeIDs;
  bool MTO_class_mu_1_NodeIDs()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_NodeIDs)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
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
  typedef int arr_mu_1_NodeIDs[2];
  arr_mu_1_NodeIDs * perm_mu_1_NodeIDs;
  arr_mu_1_NodeIDs * revperm_mu_1_NodeIDs;

  int size_mu_1_NodeIDs[2];
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
  for (int i=0; i<2; i++)
    cout << class_mu_1_NodeIDs[i];
  cout << " " << undefined_class_mu_1_NodeIDs << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
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
    mu_1_NodeIDs Perm0[2];

  /********************
   declaration of class variables
  ********************/
  in = new bool[2];
 in_mu_1_NodeIDs = new int[2];
 perm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[2];
 revperm_mu_1_NodeIDs = new arr_mu_1_NodeIDs[2];

    // Set perm and revperm
    count = 0;
    for (i=6; i<=7; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=6; j<=7; j++)
        for (k=6; k<=7; k++)
          if (revperm_mu_1_NodeIDs[i][k-6]==j)   // k - base 
            perm_mu_1_NodeIDs[i][j-6]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_NodeIDs = 0;
    size = 2;
    count = 2;
    for (i=0; i<2; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_NodeIDs[i] = i_mu_1_NodeIDs;
      i_mu_1_NodeIDs += carry;
      if (i_mu_1_NodeIDs >= 2) { i_mu_1_NodeIDs = 0; carry = 1; } 
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
  for (i=0; i<2; i++)
    class_mu_1_NodeIDs[i]=0;
  undefined_class_mu_1_NodeIDs=0;
  OnlyOneRemain_mu_1_NodeIDs = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<2; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_NodeIDs[2];
  int size_mu_1_NodeIDs[2];
  bool should_be_in_mu_1_NodeIDs[2];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NodeIDs; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  {
	    size_mu_1_NodeIDs[k] = class_size;
	    start_mu_1_NodeIDs[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_NodeIDs[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_NodeIDs[i][k]-6 >=start_mu_1_NodeIDs[k] 
	     && perm_mu_1_NodeIDs[i][k]-6 < start_mu_1_NodeIDs[k] + size_mu_1_NodeIDs[k]) )
  	    {
	      should_be_in_mu_1_NodeIDs[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<2; i++)
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
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_NodeIDs[k]==j)
	  {
	    size_mu_1_NodeIDs[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_NodeIDs; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_NodeIDs[k]==j)
	      revperm_mu_1_NodeIDs[0][start++] = k+6;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
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
  if (size!=2)
    {
      for (i=6; i<=7; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=6; i<=7; i++)
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
  for (start = 0; start < 2; )
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
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
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
        for (i=0; i<2; i++)
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
        for (i=0; i<2; i++)
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
void mu_1__type_5::Permute(PermSet& Perm, int i) {};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_5::Canonicalize(PermSet& Perm) {};
void mu_1__type_5::SimpleLimit(PermSet& Perm) {};
void mu_1__type_5::ArrayLimit(PermSet& Perm) {};
void mu_1__type_5::Limit(PermSet& Perm) {};
void mu_1__type_5::MultisetLimit(PermSet& Perm)
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
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=6; j<=7; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_NodeIDs[Perm.in_mu_1_NodeIDs[i]][j-6]];};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_NodeIDs;
  int compare;
  static mu_1_Node value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_NodeIDs[2];
  bool pos_mu_1_NodeIDs[2][2];
  // sorting mu_1_NodeIDs
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_NodeIDs[i][j]=FALSE;
      count_mu_1_NodeIDs = 0;
      for (i=0; i<2; i++)
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
                      for (z=0; z<2; z++)
                        pos_mu_1_NodeIDs[k][z] = pos_mu_1_NodeIDs[k-1][z];
                    }
                  value[j] = (*this)[i+6];
                  for (z=0; z<2; z++)
                    pos_mu_1_NodeIDs[j][z] = FALSE;
                  pos_mu_1_NodeIDs[j][i] = TRUE;
                  count_mu_1_NodeIDs++;
                  break;
                }
            }
          if (j==count_mu_1_NodeIDs)
            {
              value[j] = (*this)[i+6];
              for (z=0; z<2; z++)
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
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_NodeIDs; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_NodeIDs[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_NodeIDs[i][k] && Perm.class_mu_1_NodeIDs[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_NodeIDs[k] = TRUE;
                    pos_mu_1_NodeIDs[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_NodeIDs[k] == j && !goodset_mu_1_NodeIDs[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
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
void mu_1__type_6::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[2];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_NodeIDs, oldcount_mu_1_NodeIDs;
  bool pos_mu_1_NodeIDs[2][2];
  bool goodset_mu_1_NodeIDs[2];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_NodeIDs[i][j]=FALSE;
  count_mu_1_NodeIDs = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_NodeIDs[i] == count_mu_1_NodeIDs)
         {
           pos_mu_1_NodeIDs[count_mu_1_NodeIDs][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_NodeIDs++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 1; i0++)
  {
  }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<2)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<2; k++) // step through class
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
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_NodeIDs[k] = FALSE;
              for (k=0; k<2; k++) // step through class
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
                  for (k=0; k<2; k++)
                    if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_NodeIDs; j>i; j--)
                        for (k=0; k<2; k++)
                          pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                      for (k=0; k<2; k++)
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
  while_guard = while_guard || (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<2);
  while ( while_guard )
    {
      oldcount_mu_1_NodeIDs = count_mu_1_NodeIDs;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 1; i0++)
  {
  }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_NodeIDs() && count_mu_1_NodeIDs<2)
        {
          exists = FALSE;
          split = FALSE;
          // if there exists non-self/undefine loop
          for (k=0; k<2; k++) // step through class
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
                      for (k=0; k<2; k++) // step through class
                        goodset_mu_1_NodeIDs[k] = FALSE;
                      for (k=0; k<2; k++) // step through class
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
                          for (k=0; k<2; k++)
                            if ( pos_mu_1_NodeIDs[i][k] && !goodset_mu_1_NodeIDs[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_NodeIDs; j>i; j--)
                                for (k=0; k<2; k++)
                                  pos_mu_1_NodeIDs[j][k] = pos_mu_1_NodeIDs[j-1][k];
                              for (k=0; k<2; k++)
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
  for (i0 = 0; i0 <= 1; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_NodeIDs!=count_mu_1_NodeIDs);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_NodeIDs<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_NodeIDs())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_NodeIDs[i][j])
            Perm.class_mu_1_NodeIDs[j] = i;
      Perm.undefined_class_mu_1_NodeIDs=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_NodeIDs[j]>Perm.undefined_class_mu_1_NodeIDs)
          Perm.undefined_class_mu_1_NodeIDs=Perm.class_mu_1_NodeIDs[j];
    }
}
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
