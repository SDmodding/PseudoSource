// File Line: 7
// RVA: 0x15D8B38
__int64 dynamic_initializer_for__OSuite::ZORaw::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZORaw::s_nClassId = result;
  return result;
}

