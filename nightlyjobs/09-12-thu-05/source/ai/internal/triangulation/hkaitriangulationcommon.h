// File Line: 51
// RVA: 0x12ECEF0
void *__fastcall hkNullAllocator::blockAlloc(hkNullAllocator *this, int numBytes)
{
  if ( numBytes )
    __debugbreak();
  return 0i64;
}

// File Line: 58
// RVA: 0x12ECF00
void __fastcall hkNullAllocator::blockFree(hkNullAllocator *this, void *p, int numBytes)
{
  __debugbreak();
}

