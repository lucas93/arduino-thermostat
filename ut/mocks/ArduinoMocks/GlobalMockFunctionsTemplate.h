#ifndef GLOBAL_FUNCTIONS_MOCK_TEMPLATE_H
#define GLOBAL_FUNCTIONS_MOCK_TEMPLATE_H

#define GLOBAL_FUNCTIONS_MOCK_IMPLEMENTATION_H(GLOBAL_NAME, MOCK_IMPL)\
struct GLOBAL_NAME##_MockImplementation \
    MOCK_IMPL\
;\
class GLOBAL_NAME##_MockInstanceGuard : public GLOBAL_NAME##_MockImplementation\
{\
public:\
  GLOBAL_NAME##_MockInstanceGuard();\
  ~GLOBAL_NAME##_MockInstanceGuard();\
};\
extern GLOBAL_NAME##_MockInstanceGuard* GLOBAL_NAME##InstancePointer;


#define GLOBAL_FUNCTIONS_MOCK_IMPLEMENTATION_CPP(GLOBAL_NAME)\
GLOBAL_NAME##_MockInstanceGuard* GLOBAL_NAME##InstancePointer = nullptr;\
\
GLOBAL_NAME##_MockInstanceGuard::GLOBAL_NAME##_MockInstanceGuard()\
{\
  EXPECT_EQ(nullptr, GLOBAL_NAME##InstancePointer)\
      << "Are you trying to instantiate multiple " #GLOBAL_NAME "MockWrappers in the same scope?";\
  GLOBAL_NAME##InstancePointer = this;\
}\
\
GLOBAL_NAME##_MockInstanceGuard::~GLOBAL_NAME##_MockInstanceGuard()\
{\
  GLOBAL_NAME##InstancePointer = nullptr;\
}\
\
void assert##GLOBAL_NAME##MockWrapperInstanceWasCreated()\
{\
  ASSERT_NE(nullptr, GLOBAL_NAME##InstancePointer)\
      << "Are you trying to invoke " #GLOBAL_NAME " functions without instatiating an " #GLOBAL_NAME "MockWrapper first?";\
}


#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(GLOBAL_NAME, RETURN_TYPE, FUNCTION_NAME)\
RETURN_TYPE FUNCTION_NAME() \
{\
  assert##GLOBAL_NAME##MockWrapperInstanceWasCreated();\
  return GLOBAL_NAME##InstancePointer->FUNCTION_NAME();\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(GLOBAL_NAME, RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1) \
{\
  assert##GLOBAL_NAME##MockWrapperInstanceWasCreated();\
  return GLOBAL_NAME##InstancePointer->FUNCTION_NAME(ARG1);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(GLOBAL_NAME, RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2) \
{\
  assert##GLOBAL_NAME##MockWrapperInstanceWasCreated();\
  return GLOBAL_NAME##InstancePointer->FUNCTION_NAME(ARG1, ARG2);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(GLOBAL_NAME, RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3) \
{\
  assert##GLOBAL_NAME##MockWrapperInstanceWasCreated();\
  return GLOBAL_NAME##InstancePointer->FUNCTION_NAME(ARG1, ARG2, ARG3);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_4(GLOBAL_NAME, RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4) \
{\
  assert##GLOBAL_NAME##MockWrapperInstanceWasCreated();\
  return GLOBAL_NAME##InstancePointer->FUNCTION_NAME(ARG1, ARG2, ARG3, ARG4);\
}\

#endif // GLOBAL_FUNCTIONS_MOCK_TEMPLATE_H
