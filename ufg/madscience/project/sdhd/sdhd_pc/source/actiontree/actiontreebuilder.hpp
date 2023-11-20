// File Line: 514
// RVA: 0x270CC0
void __fastcall IActionTreeSerializer::PushObjectToSerialize(IActionTreeSerializer *this, Expression::IMemberMap *memberMap)
{
  IActionTreeSerializer *v2; // rdi
  Expression::IMemberMap *v3; // rbx
  const char *v4; // rax
  signed int v5; // ST40_4
  unsigned int v6; // ST30_4
  signed int v7; // ST28_4

  if ( memberMap )
  {
    v2 = this;
    v3 = memberMap;
    v4 = memberMap->vfptr->GetClassname(memberMap);
    v5 = -1;
    v6 = 0;
    v7 = 1;
    v2->vfptr->_PushObjectToSerialize(
      v2,
      v3,
      1u,
      (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
      v4,
      (QUEUE_PRIORITY)v7,
      v6,
      0i64,
      v5,
      0i64);
  }
}

