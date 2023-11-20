// File Line: 33
// RVA: 0x14578F0
__int64 SimpleXML::_dynamic_initializer_for__gXMLFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&SimpleXML::gXMLFileInventory.vfptr,
    "XMLFileInventory",
    0x4FF578D5u,
    0x24D0C3A0u,
    0,
    0);
  SimpleXML::gXMLFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&SimpleXML::XMLFileInventory::`vftable;
  return atexit(SimpleXML::_dynamic_atexit_destructor_for__gXMLFileInventory__);
}

// File Line: 62
// RVA: 0x8A580
char *__fastcall SimpleXML::XMLCache::ExtractFromCache(const char *filename)
{
  int v1; // edx
  unsigned int v2; // eax
  SimpleXML::XMLFileResource *v3; // rax
  SimpleXML::XMLFileResource *v4; // rsi
  __int64 v5; // rbx
  char *v6; // rdi
  UFG::qString v8; // [rsp+38h] [rbp-30h]

  while ( (unsigned __int8)(*filename - 46) <= 1u || *filename == 92 )
    ++filename;
  UFG::qString::qString(&v8, filename);
  UFG::qString::MakeLower(&v8);
  UFG::qString::ReplaceCharInPlace(&v8, 47, 92);
  v2 = v8.mStringHashUpper32;
  if ( v8.mStringHashUpper32 == -1 )
  {
    v2 = UFG::qStringHashUpper32(v8.mData, v8.mStringHashUpper32 | v1);
    v8.mStringHashUpper32 = v2;
  }
  v3 = (SimpleXML::XMLFileResource *)UFG::qResourceInventory::Get(
                                       (UFG::qResourceInventory *)&SimpleXML::gXMLFileInventory.vfptr,
                                       v2);
  v4 = v3;
  if ( v3 )
  {
    v5 = v3->mUncompressedSize;
    v6 = UFG::qMalloc((unsigned int)(v5 + 0x80), "uncompressedXMLBuffer", 0i64);
    UFG::qDecompressLZ((UFG::qCompressHeader *)&v4[1], v4->mCompressedSize, v6, (unsigned int)v5);
    v6[v5] = 0;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qString::~qString(&v8);
  return v6;
}

