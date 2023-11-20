// File Line: 17
// RVA: 0xAFCAE0
void __fastcall PooledMemoryAllocator::PooledMemoryAllocator(PooledMemoryAllocator *this)
{
  this->mPoolSize = 0;
  this->mStartPointer = 0i64;
  this->mCurrentPointer = 0i64;
  this->mLastPointer = 0i64;
}

// File Line: 23
// RVA: 0xAFCB00
void __fastcall PooledMemoryAllocator::~PooledMemoryAllocator(PooledMemoryAllocator *this)
{
  ;
}

// File Line: 29
// RVA: 0xAFCB10
signed __int64 __fastcall PooledMemoryAllocator::Init(PooledMemoryAllocator *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned __int64 size)
{
  PooledMemoryAllocator *v3; // rbx
  unsigned __int64 v4; // rdi
  char *v5; // rax

  v3 = this;
  v4 = size;
  v5 = (char *)in_pAllocator->vfptr->Malloc(in_pAllocator, size);
  v3->mCurrentPointer = v5;
  v3->mStartPointer = v5;
  if ( !v5 )
    return 52i64;
  memset(v5, 0, v4);
  v3->mPoolSize = v4;
  v3->mLastPointer = &v3->mCurrentPointer[(unsigned int)v4];
  return 1i64;
}

// File Line: 49
// RVA: 0xAFCB80
void __fastcall PooledMemoryAllocator::Term(PooledMemoryAllocator *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  PooledMemoryAllocator *v2; // rbx

  v2 = this;
  if ( this->mStartPointer )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->mPoolSize = 0;
    v2->mLastPointer = 0i64;
    v2->mCurrentPointer = 0i64;
    v2->mStartPointer = 0i64;
  }
}

// File Line: 62
// RVA: 0xAFCBC0
char *__fastcall PooledMemoryAllocator::GetPointerToPooledMemory(PooledMemoryAllocator *this, unsigned int *size)
{
  if ( size )
    *size = this->mPoolSize;
  return this->mStartPointer;
}

// File Line: 71
// RVA: 0xAFCBE0
void __fastcall PooledMemoryAllocator::Reset(PooledMemoryAllocator *this)
{
  PooledMemoryAllocator *v1; // rbx

  v1 = this;
  if ( this->mPoolSize )
  {
    memset(this->mStartPointer, 0, this->mPoolSize);
    v1->mCurrentPointer = v1->mStartPointer;
  }
}

// File Line: 84
// RVA: 0xAFCC20
char *__fastcall PooledMemoryAllocator::Malloc(PooledMemoryAllocator *this, unsigned __int64 size)
{
  char *result; // rax

  result = this->mCurrentPointer;
  this->mCurrentPointer = &result[size];
  return result;
}

