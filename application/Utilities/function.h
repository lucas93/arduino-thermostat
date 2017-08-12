#pragma once

#include<forward.h>

namespace util
{

// a simple non-optimal std::function alternative
// found at https://stackoverflow.com/questions/14739902/is-there-a-standalone-implementation-of-stdfunction
template<typename Result,typename ...Args>
struct abstract_function
{
  virtual Result operator()(Args... args)=0;
  virtual abstract_function *clone() const =0;
  virtual ~abstract_function() = default;
};

template< typename T >
T returnIfNotVoid()
{
  return T{};
}

template<>
inline void returnIfNotVoid<void>()
{
}

template<typename Func,typename Result,typename ...Args>
class concrete_function: public abstract_function<Result,Args...>
{
  Func f;
public:
  concrete_function(const Func &x)
      : f(x)
  {}
  Result operator()(Args... args) override
  {
      return f(args...);
  }
  concrete_function *clone() const override
  {
      return new concrete_function{f};
  }
};

template<typename Func>
struct func_filter
{
  typedef Func type;
};
template<typename Result,typename ...Args>
struct func_filter<Result(Args...)>
{
  typedef Result (*type)(Args...);
};

template<typename signature>
class function;

template<typename Result,typename ...Args>
class function<Result(Args...)>
{
  abstract_function<Result,Args...> *f;
public:
  function()
      : f(nullptr)
  {}
  template<typename Func> function(const Func &x)
      : f(new concrete_function<typename func_filter<Func>::type,Result,Args...>(x))
  {}
  function(const function &rhs)
      : f(rhs.f ? rhs.f->clone() : nullptr)
  {}
  function &operator=(const function &rhs)
  {
      if( (&rhs != this ) && (rhs.f) )
      {
          auto *temp = rhs.f->clone();
          delete f;
          f = temp;
      }
      return *this;
  }
  template<typename Func> function &operator=(const Func &x)
  {
      auto *temp = new concrete_function<typename func_filter<Func>::type,Result,Args...>(x);
      delete f;
      f = temp;
      return *this;
  }

  template< typename... FunArgs>
  Result operator()(FunArgs&&... funArgs)
  {
      if(f)
          return (*f)(forward<FunArgs>(funArgs)...);
      else
          return returnIfNotVoid<Result>();
  }
  ~function()
  {
      delete f;
  }
};


// a move-only util::function implementation
template<typename ...Args>
class unique_function
{
  using ThisType =  unique_function<Args...> ;
  using FunType = util::function< Args...>;


  FunType* funPtr;

public:
  unique_function() = delete;
  unique_function(FunType& fun) = delete;

  template< typename... Args_>
  unique_function(Args_&&... args)
    : funPtr(new FunType{ util::forward<Args_>(args)... } )
  {}

  unique_function(const ThisType& other) = delete;
  unique_function(ThisType&& other)
  {
    funPtr = other.funPtr;
    other.funPtr = nullptr;
  }

  ~unique_function()
  {
    if (funPtr) delete funPtr;
  }

  ThisType& operator=(const ThisType& other) = delete;
  ThisType& operator=(ThisType&& other)
  {
    if(funPtr) delete funPtr;
    funPtr = other.funPtr;
    other.funPtr = nullptr;

    return *this;
  }

  template<typename... Args_>
  auto operator()(Args_... args) -> decltype((*funPtr)(args...))
  {
    if(funPtr)
      return (*funPtr)(args...);
    else
      return decltype((*funPtr)(args...)){};
  }
};


//template<typename T, typename... Args>
//auto make_unique_function(Args&&... args)
//{
//  return unique_function<>
//}


//// a move-only function implementation
//template<typename ...Args>
//class unique_function
//{
//  using thisType =  unique_function<Args...> ;
//  using funType = util::function< Args...>;
//  using funPtrType = util::scoped_owner< funType >;

//  funPtrType funPtr;

//public:
//  unique_function() = delete;
//  unique_function(funType& fun)
//    : funPtr(&fun) {}
//  unique_function(funType&& fun)
//    : funPtr(&fun) {}

//  unique_function(const thisType& other) = delete;
//  unique_function(thisType&& other)
//    : funPtr(other.funPtr.release())
//  {
//  }

//  thisType& operator=(const thisType& other) = delete;
//  thisType& operator=(thisType&& other)
//  {
//    funPtr.reassign( other.funPtr.release() );

//    return *this;
//  }

//  template<typename... Args_>
//  auto operator()(Args_... args) -> decltype(funPtr.get()(args...))
//  {
//    return funPtr.get()(args...);
//  }
//};

} // namespace util
