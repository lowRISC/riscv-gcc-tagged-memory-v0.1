
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_beans_decoder_AbstractObjectContext__
#define __gnu_java_beans_decoder_AbstractObjectContext__

#pragma interface

#include <gnu/java/beans/decoder/AbstractContext.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace beans
      {
        namespace decoder
        {
            class AbstractObjectContext;
        }
      }
    }
  }
}

class gnu::java::beans::decoder::AbstractObjectContext : public ::gnu::java::beans::decoder::AbstractContext
{

public: // actually package-private
  AbstractObjectContext();
public: // actually protected
  virtual void setObject(::java::lang::Object *);
public:
  virtual void set(jint, ::java::lang::Object *);
  virtual ::java::lang::Object * get(jint);
  virtual ::java::lang::Object * getResult();
public: // actually protected
  ::java::lang::Object * __attribute__((aligned(__alignof__( ::gnu::java::beans::decoder::AbstractContext)))) object;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_beans_decoder_AbstractObjectContext__
