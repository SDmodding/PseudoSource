// File Line: 65
// RVA: 0x4274D0
unsigned int __fastcall OSuite::FComputeHash<OSuite::ZRedBlackTreeBase::ZElementBase *>(OSuite::ZRedBlackTreeBase::ZElementBase *const *value)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *const *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax

  v1 = value;
  v2 = OSuite::FComputeHashBegin((_exception *)value);
  v3 = OSuite::FComputeHashAdd(v2, v1, 8ui64);
  return OSuite::FComputeHashEnd(v3);
}

