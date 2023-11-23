// File Line: 13
// RVA: 0xC55FB0
void __fastcall HK_ASSERT_OBJECT_SIZE_OK_FUNC(unsigned __int64 nbytes)
{
  ;
}

// File Line: 19
// RVA: 0xC55E20
void __fastcall hkMemoryAllocator::~hkMemoryAllocator(hkMemoryAllocator *this)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkMemoryAllocator::`vftable;
}

// File Line: 23
// RVA: 0xC55E40
__int64 __fastcall hkMemoryAllocator::bufAlloc(hkMemoryAllocator *this, unsigned int *reqBytesInOut)
{
  return (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->vfptr->__vecDelDtor + 1))(this, *reqBytesInOut);
}

// File Line: 27
// RVA: 0xC55E50
void __fastcall hkMemoryAllocator::bufFree(hkMemoryAllocator *this, void *p, __int64 numBytes)
{
  this->vfptr->blockFree(this, p, numBytes);
}

// File Line: 31
// RVA: 0xC55E60
void *__fastcall hkMemoryAllocator::bufRealloc(
        hkMemoryAllocator *this,
        void *pold,
        int oldNumBytes,
        int *reqBytesInOut)
{
  void *v8; // rax
  void *v9; // rsi
  int v10; // r8d

  v8 = this->vfptr->bufAlloc(this, reqBytesInOut);
  v9 = v8;
  if ( v8 )
  {
    v10 = *reqBytesInOut;
    if ( oldNumBytes < *reqBytesInOut )
      v10 = oldNumBytes;
    hkMemUtil::memCpy(v8, pold, v10);
  }
  this->vfptr->bufFree(this, pold, oldNumBytes);
  return v9;
}

// File Line: 42
// RVA: 0xC55EE0
void __fastcall hkMemoryAllocator::blockAllocBatch(
        hkMemoryAllocator *this,
        void **ptrsOut,
        int numPtrs,
        unsigned int blockSize)
{
  __int64 v7; // rbx
  __int64 v8; // rsi

  if ( numPtrs > 0 )
  {
    v7 = 0i64;
    v8 = numPtrs;
    do
      ptrsOut[v7++] = (void *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->vfptr->__vecDelDtor + 1))(
                                this,
                                blockSize);
    while ( v7 < v8 );
  }
}

// File Line: 49
// RVA: 0xC55F50
void __fastcall hkMemoryAllocator::blockFreeBatch(
        hkMemoryAllocator *this,
        void **ptrsIn,
        unsigned int numPtrs,
        int blockSize)
{
  __int64 v6; // rdi

  if ( (int)numPtrs > 0 )
  {
    v6 = numPtrs;
    do
    {
      if ( *ptrsIn )
        this->vfptr->blockFree(this, *ptrsIn, blockSize);
      ++ptrsIn;
      --v6;
    }
    while ( v6 );
  }
}

