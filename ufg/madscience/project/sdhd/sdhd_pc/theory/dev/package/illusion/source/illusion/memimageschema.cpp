// File Line: 24
// RVA: 0x1457F80
__int64 Illusion::_dynamic_initializer_for__gMemImageSchema__()
{
  UFG::qMemSet(Illusion::gMemImageSchema.mMemStructure, 0, 0xBB80u);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gMemImageSchema__);
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
void __fastcall Illusion::MemImageSchema::Allocate(
        Illusion::MemImageSchema *this,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v3; // r10
  char *v5; // rdi
  __int64 i; // r8
  void **mPointer; // r9
  unsigned __int64 mFixupOffset; // rcx

  v3 = memory_pool;
  if ( !memory_pool )
    v3 = UFG::gMainMemoryPool;
  if ( (unsigned int)allocation_params >> 8 < 0x10 )
    allocation_params = allocation_params & 0xFFFFFFFF000000FFui64 | 0x1000;
  v5 = UFG::qMemoryPool::Allocate(
         v3,
         (this->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64,
         this->mMemStructure[0].mName,
         allocation_params,
         1u);
  UFG::qMemSet(v5, 0, this->mCurrSize);
  for ( i = 0i64; (unsigned int)i < this->mNumMemStructures; i = (unsigned int)(i + 1) )
  {
    mPointer = this->mMemStructure[i].mPointer;
    if ( mPointer )
      *mPointer = &v5[this->mMemStructure[i].mBaseOffset];
    mFixupOffset = this->mMemStructure[i].mFixupOffset;
    if ( mFixupOffset )
      *(_QWORD *)&v5[this->mMemStructure[i].mFixupOffsetPointer] = mFixupOffset;
  }
  this->mAllocatedMemory = v5;
}

