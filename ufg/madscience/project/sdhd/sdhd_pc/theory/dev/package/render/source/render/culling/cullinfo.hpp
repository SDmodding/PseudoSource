// File Line: 121
// RVA: 0x1990
UFG::qMatrix44 *__fastcall CullInfo::GetLocalWorld(CullInfo *this)
{
  UFG::qMatrix44 *result; // rax

  result = (UFG::qMatrix44 *)this->mpLocalWorld;
  if ( !result )
    result = &UFG::qMatrix44::msIdentity;
  return result;
}

