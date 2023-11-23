// File Line: 47
// RVA: 0xF5790
__int64 __fastcall hkaiSingleCharacterBehavior::getSavedCharacterState(hkaiSingleCharacterBehavior *this)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h] BYREF
  __int64 v3; // [rsp+38h] [rbp-210h]
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v3 = -2i64;
  hkErrStream::hkErrStream(&v2, buf, 512);
  hkOstream::operator<<(&v2, "Not implemented");
  if ( hkError::messageError(
         1131803005,
         buf,
         "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\"
         "ai\\pathfinding\\character\\behavior\\hkaisinglecharacterbehavior.h",
         48) )
  {
    __debugbreak();
  }
  hkOstream::~hkOstream(&v2);
  return 7i64;
}

