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
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkMemoryAllocator::`vftable';
}

// File Line: 23
// RVA: 0xC55E40
__int64 __fastcall hkMemoryAllocator::bufAlloc(hkMemoryAllocator *this, int *reqBytesInOut)
{
  return (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->vfptr->__vecDelDtor + 1))(
           this,
           (unsigned int)*reqBytesInOut);
}

// File Line: 27
// RVA: 0xC55E50
void __fastcall hkMemoryAllocator::bufFree(hkMemoryAllocator *this, void *p, __int64 numBytes)
{
  this->vfptr->blockFree(this, p, numBytes);
}

// File Line: 31
// RVA: 0xC55E60
void *__fastcall hkMemoryAllocator::bufRealloc(hkMemoryAllocator *this, void *pold, int oldNumBytes, int *reqBytesInOut)
{
  void *v4; // rbp
  int *v5; // r14
  int v6; // edi
  hkMemoryAllocator *v7; // rbx
  void *v8; // rax
  void *v9; // rsi
  int v10; // er8

  v4 = pold;
  v5 = reqBytesInOut;
  v6 = oldNumBytes;
  v7 = this;
  v8 = this->vfptr->bufAlloc(this, reqBytesInOut);
  v9 = v8;
  if ( v8 )
  {
    v10 = *v5;
    if ( v6 < *v5 )
      v10 = v6;
    hkMemUtil::memCpy(v8, v4, v10);
  }
  v7->vfptr->bufFree(v7, v4, v6);
  return v9;
}

// File Line: 42
// RVA: 0xC55EE0
void __fastcall hkMemoryAllocator::blockAllocBatch(hkMemoryAllocator *this, void **ptrsOut, int numPtrs, int blockSize)
{
  unsigned int v4; // ebp
  void **v5; // r14
  hkMemoryAllocator *v6; // rdi
  __int64 v7; // rbx
  __int64 v8; // rsi

  if ( numPtrs > 0 )
  {
    v4 = blockSize;
    v5 = ptrsOut;
    v6 = this;
    v7 = 0i64;
    v8 = numPtrs;
    do
      v5[++v7 - 1] = (void *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v6->vfptr->__vecDelDtor + 1))(
                               v6,
                               v4);
    while ( v7 < v8 );
  }
}

// File Line: 49
// RVA: 0xC55F50
void __fastcall hkMemoryAllocator::blockFreeBatch(hkMemoryAllocator *this, void **ptrsIn, int numPtrs, int blockSize)
{
  unsigned int v4; // ebp
  void **v5; // rbx
  __int64 v6; // rdi
  hkMemoryAllocator *v7; // rsi

  if ( numPtrs > 0 )
  {
    v4 = blockSize;
    v5 = ptrsIn;
    v6 = (unsigned int)numPtrs;
    v7 = this;
    do
    {
      if ( *v5 )
        v7->vfptr->blockFree(v7, *v5, v4);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
}

