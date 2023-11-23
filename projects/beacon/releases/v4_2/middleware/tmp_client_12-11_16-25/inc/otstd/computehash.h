// File Line: 65
// RVA: 0xED2E78
unsigned int __fastcall OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>(_exception *value)
{
  unsigned int v2; // eax
  unsigned int v3; // eax

  v2 = OSuite::FComputeHashBegin(value);
  v3 = OSuite::FComputeHashAdd(v2, value, 8ui64);
  return OSuite::FComputeHashEnd(v3);
}

