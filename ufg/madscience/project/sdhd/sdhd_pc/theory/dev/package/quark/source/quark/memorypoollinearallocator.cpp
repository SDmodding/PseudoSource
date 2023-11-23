// File Line: 52
// RVA: 0x1615C0
void __fastcall UFG::qLinearAllocator::qLinearAllocator(UFG::qLinearAllocator *this)
{
  unsigned int v2; // r8d
  char *v3; // rcx
  char *v4; // rax

  this->mMainMemoryAddress = this;
  this->mCurrentPos = 0;
  this->mBuffer0Start = 0i64;
  this->mBuffer0End = 0i64;
  this->mBuffer1Start = 0i64;
  this->mBuffer1End = 0i64;
  UFG::qMemSet(this->pad, 0, 0x3Cu);
  v2 = this->mCurrentPos & 0x80000000;
  v3 = &this->mBuffer0End[this->mBuffer1End - this->mBuffer1Start - (unsigned __int64)this->mBuffer0Start];
  LODWORD(v4) = this->mCurrentPos & 0x7FFFFFFF;
  if ( (this->mCurrentPos & 0x80000000) == 0 )
    v4 = &this->mBuffer1End[(this->mCurrentPos & 0x7FFFFFFF) - (unsigned __int64)this->mBuffer1Start];
  this->mLastFrameNumFreeBytes = (unsigned int)v4;
  this->mLastFrameNumBytes = (unsigned int)v3;
  this->mLastFrameNumAllocBytes = (_DWORD)v3 - (_DWORD)v4;
  this->mBuffer0Start = 0i64;
  this->mBuffer0End = 0i64;
  this->mLastFrameOverflowed = v2 != 0;
  this->mBuffer1Start = 0i64;
  this->mBuffer1End = 0i64;
  this->mCurrentPos = 0;
}

// File Line: 72
// RVA: 0x173120
void __fastcall UFG::qLinearAllocator::Init(
        UFG::qLinearAllocator *this,
        char *buffer0,
        __int64 byte_size0,
        char *buffer1,
        __int64 byte_size1)
{
  unsigned int v7; // ebx
  unsigned int v8; // edx
  char *v9; // rcx
  char *v10; // rax

  v7 = this->mCurrentPos & 0x80000000;
  v8 = this->mCurrentPos & 0x7FFFFFFF;
  v9 = &this->mBuffer0End[this->mBuffer1End - this->mBuffer1Start - (unsigned __int64)this->mBuffer0Start];
  LODWORD(v10) = v8;
  if ( (this->mCurrentPos & 0x80000000) == 0 )
    v10 = &this->mBuffer1End[v8 - (unsigned __int64)this->mBuffer1Start];
  this->mLastFrameNumBytes = (unsigned int)v9;
  this->mLastFrameNumFreeBytes = (unsigned int)v10;
  this->mLastFrameNumAllocBytes = (_DWORD)v9 - (_DWORD)v10;
  this->mBuffer0Start = buffer0;
  this->mBuffer1Start = buffer1;
  this->mLastFrameOverflowed = v7 != 0;
  this->mCurrentPos = byte_size0;
  this->mBuffer0End = &buffer0[byte_size0];
  this->mBuffer1End = &buffer1[byte_size1];
}

// File Line: 100
// RVA: 0x17ACC0
void __fastcall UFG::qLinearAllocator::Reset(UFG::qLinearAllocator *this)
{
  this->mCurrentPos = LODWORD(this->mBuffer0End) - LODWORD(this->mBuffer0Start);
}

// File Line: 105
// RVA: 0x172FC0
__int64 __fastcall UFG::qLinearAllocator::InFrame(UFG::qLinearAllocator *this, __int64 address)
{
  return (address >= (__int64)this->mBuffer0Start && address < (__int64)this->mBuffer0End) | (unsigned int)(address >= (__int64)this->mBuffer1Start && address < (__int64)this->mBuffer1End);
}

// File Line: 161
// RVA: 0x1775D0
char *__fastcall UFG::qLinearAllocator::Malloc(UFG::qLinearAllocator *this, unsigned int size, unsigned int alignment)
{
  UFG::qLinearAllocator *mMainMemoryAddress; // r9
  unsigned int v5; // esi
  signed __int32 mCurrentPos; // r10d
  char *mBuffer1End; // rcx
  char *mBuffer0End; // rdi
  __int64 v10; // rdx
  int v11; // r8d
  unsigned int v12; // r11d
  char *v13; // rdi

  mMainMemoryAddress = this->mMainMemoryAddress;
  v5 = ~(alignment - 1);
  while ( 1 )
  {
    while ( 1 )
    {
      mCurrentPos = mMainMemoryAddress->mCurrentPos;
      mBuffer1End = this->mBuffer1End;
      mBuffer0End = mBuffer1End;
      v10 = mMainMemoryAddress->mCurrentPos & v5;
      LODWORD(v10) = v10 & 0x7FFFFFFF;
      v11 = v10 - size;
      v12 = mMainMemoryAddress->mCurrentPos & 0x80000000;
      if ( (mMainMemoryAddress->mCurrentPos & 0x80000000) == 0 )
        mBuffer0End = this->mBuffer0End;
      v13 = &mBuffer0End[-v10];
      if ( v11 < 0 )
        break;
      if ( mCurrentPos == _InterlockedCompareExchange(
                            (volatile signed __int32 *)mMainMemoryAddress,
                            v12 | v11 & 0x7FFFFFFF,
                            mCurrentPos) )
        return v13;
    }
    if ( v12 )
      break;
    _InterlockedCompareExchange(
      (volatile signed __int32 *)mMainMemoryAddress,
      ((_DWORD)mBuffer1End - LODWORD(this->mBuffer1Start)) | 0x80000000,
      mCurrentPos);
  }
  return 0i64;
}

