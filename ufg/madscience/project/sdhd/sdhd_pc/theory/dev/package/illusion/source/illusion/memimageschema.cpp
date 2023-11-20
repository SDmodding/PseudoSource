// File Line: 24
// RVA: 0x1457F80
__int64 Illusion::_dynamic_initializer_for__gMemImageSchema__()
{
  UFG::qMemSet(Illusion::gMemImageSchema.mMemStructure, 0, 0xBB80u);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gMemImageSchema__);
}

// File Line: 38
// RVA: 0x92850
void __fastcall Illusion::MemImageSchema::Init(Illusion::MemImageSchema *this)
{
  this->mNumMemStructures = 0;
  this->mCurrSize = 0i64;
  this->mCurrSerializeIndex = 0;
  this->mBaseFilePosition = 0i64;
}

// File Line: 50
// RVA: 0x8E390
void __fastcall Illusion::MemImageSchema::Align16(Illusion::MemImageSchema *this)
{
  this->mCurrSize = (this->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
}

// File Line: 56
// RVA: 0x8E3B0
void __fastcall Illusion::MemImageSchema::Allocate(Illusion::MemImageSchema *this, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v3; // r10
  Illusion::MemImageSchema *v4; // rbx
  char *v5; // rdi
  __int64 v6; // r8
  void **v7; // r9
  unsigned __int64 v8; // rcx

  v3 = memory_pool;
  if ( !memory_pool )
    v3 = UFG::gMainMemoryPool;
  v4 = this;
  if ( (signed int)((unsigned int)allocation_params >> 8) < 16 )
    allocation_params = allocation_params & 0xFFFFFFFF000010FFui64 | 0x1000;
  v5 = UFG::qMemoryPool::Allocate(
         v3,
         (this->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64,
         this->mMemStructure[0].mName,
         allocation_params,
         1u);
  UFG::qMemSet(v5, 0, v4->mCurrSize);
  v6 = 0i64;
  if ( v4->mNumMemStructures )
  {
    do
    {
      v7 = v4->mMemStructure[v6].mPointer;
      if ( v7 )
        *v7 = &v5[v4->mMemStructure[v6].mBaseOffset];
      v8 = v4->mMemStructure[v6].mFixupOffset;
      if ( v8 )
        *(_QWORD *)&v5[v4->mMemStructure[v6].mFixupOffsetPointer] = v8;
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < v4->mNumMemStructures );
  }
  v4->mAllocatedMemory = v5;
}

