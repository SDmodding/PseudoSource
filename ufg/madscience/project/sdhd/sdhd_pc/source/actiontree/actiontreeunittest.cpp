// File Line: 27
// RVA: 0x1493F70
__int64 dynamic_initializer_for__TestClassB::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TestClassB", 0xFFFFFFFF);
  TestClassB::sClassNameUID = result;
  return result;
}

// File Line: 38
// RVA: 0x1493F90
__int64 dynamic_initializer_for__TestClassC::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TestClassC", 0xFFFFFFFF);
  TestClassC::sClassNameUID = result;
  return result;
}

