// File Line: 33
// RVA: 0x14578F0
__int64 SimpleXML::_dynamic_initializer_for__gXMLFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &SimpleXML::gXMLFileInventory,
    "XMLFileInventory",
    0x4FF578D5u,
    0x24D0C3A0u,
    0,
    0);
  SimpleXML::gXMLFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&SimpleXML::XMLFileInventory::`vftable;
  return atexit((int (__fastcall *)())SimpleXML::_dynamic_atexit_destructor_for__gXMLFileInventory__);
}

// File Line: 62
// RVA: 0x8A580
char *__fastcall SimpleXML::XMLCache::ExtractFromCache(const char *filename)
{
  unsigned int mStringHashUpper32; // eax
  SimpleXML::XMLFileResource *v2; // rax
  SimpleXML::XMLFileResource *v3; // rsi
  __int64 mUncompressedSize; // rbx
  char *v5; // rdi
  UFG::qString v7; // [rsp+38h] [rbp-30h] BYREF

  while ( (unsigned __int8)(*filename - 46) <= 1u || *filename == 92 )
    ++filename;
  UFG::qString::qString(&v7, filename);
  UFG::qString::MakeLower(&v7);
  UFG::qString::ReplaceCharInPlace(&v7, 47, 92);
  mStringHashUpper32 = v7.mStringHashUpper32;
  if ( v7.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(v7.mData, 0xFFFFFFFF);
    v7.mStringHashUpper32 = mStringHashUpper32;
  }
  v2 = (SimpleXML::XMLFileResource *)UFG::qResourceInventory::Get(&SimpleXML::gXMLFileInventory, mStringHashUpper32);
  v3 = v2;
  if ( v2 )
  {
    mUncompressedSize = v2->mUncompressedSize;
    v5 = UFG::qMalloc((unsigned int)(mUncompressedSize + 0x80), "uncompressedXMLBuffer", 0i64);
    UFG::qDecompressLZ((UFG::qCompressHeader *)&v3[1], v3->mCompressedSize, v5, (unsigned int)mUncompressedSize);
    v5[mUncompressedSize] = 0;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qString::~qString(&v7);
  return v5;
}

