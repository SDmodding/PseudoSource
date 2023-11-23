// File Line: 514
// RVA: 0x270CC0
void __fastcall IActionTreeSerializer::PushObjectToSerialize(
        IActionTreeSerializer *this,
        Expression::IMemberMap *memberMap)
{
  const char *v4; // rax

  if ( memberMap )
  {
    v4 = memberMap->vfptr->GetClassname(memberMap);
    this->vfptr->_PushObjectToSerialize(
      this,
      memberMap,
      1u,
      (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
      v4,
      PRIORITY_MEDIUM,
      0,
      0i64,
      -1u,
      0i64);
  }
}

