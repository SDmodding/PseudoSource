// File Line: 65
// RVA: 0x4274D0
unsigned int __fastcall OSuite::FComputeHash<OSuite::ZRedBlackTreeBase::ZElementBase *>(
        OSuite::ZRedBlackTreeBase::ZElementBase **value)
{
  unsigned int v2; // eax
  unsigned int v3; // eax

  v2 = OSuite::FComputeHashBegin((_exception *)value);
  v3 = OSuite::FComputeHashAdd(v2, value, 8ui64);
  return OSuite::FComputeHashEnd(v3);
}

