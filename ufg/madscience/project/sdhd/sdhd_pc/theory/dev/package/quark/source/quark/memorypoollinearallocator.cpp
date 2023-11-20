// File Line: 52
// RVA: 0x1615C0
void __fastcall UFG::qLinearAllocator::qLinearAllocator(UFG::qLinearAllocator *this)
{
  UFG::qLinearAllocator *v1; // rbx
  volatile unsigned int v2; // et1
  unsigned int v3; // er8
  char *v4; // rcx
  char *v5; // rax

  v1 = this;
  this->mMainMemoryAddress = this;
  this->mCurrentPos = 0;
  this->mBuffer0Start = 0i64;
  this->mBuffer0End = 0i64;
  this->mBuffer1Start = 0i64;
  this->mBuffer1End = 0i64;
  UFG::qMemSet(this->pad, 0, 0x3Cu);
  v2 = v1->mCurrentPos;
  v3 = v1->mCurrentPos & 0x80000000;
  v4 = &v1->mBuffer0End[v1->mBuffer1End - v1->mBuffer1Start - (unsigned __int64)v1->mBuffer0Start];
  LODWORD(v5) = v1->mCurrentPos & 0x7FFFFFFF;
  if ( (v1->mCurrentPos & 0x80000000) == 0 )
    v5 = &v1->mBuffer1End[(v1->mCurrentPos & 0x7FFFFFFF) - (unsigned __int64)v1->mBuffer1Start];
  v1->mLastFrameNumFreeBytes = (unsigned int)v5;
  v1->mLastFrameNumBytes = (unsigned int)v4;
  v1->mLastFrameNumAllocBytes = (_DWORD)v4 - (_DWORD)v5;
  v1->mBuffer0Start = 0i64;
  v1->mBuffer0End = 0i64;
  v1->mLastFrameOverflowed = v3 != 0;
  v1->mBuffer1Start = 0i64;
  v1->mBuffer1End = 0i64;
  v1->mCurrentPos = 0;
}

// File Line: 72
// RVA: 0x173120
void __fastcall UFG::qLinearAllocator::Init(UFG::qLinearAllocator *this, char *buffer0, __int64 byte_size0, char *buffer1, __int64 byte_size1)
{
  volatile unsigned int v5; // et1
  UFG::qLinearAllocator *v6; // r10
  char *v7; // r11
  unsigned int v8; // ebx
  unsigned int v9; // edx
  char *v10; // rcx
  char *v11; // rax

  v5 = this->mCurrentPos;
  v6 = this;
  v7 = buffer0;
  v8 = this->mCurrentPos & 0x80000000;
  v9 = this->mCurrentPos & 0x7FFFFFFF;
  v10 = &this->mBuffer0End[this->mBuffer1End - this->mBuffer1Start - (unsigned __int64)this->mBuffer0Start];
  LODWORD(v11) = v9;
  if ( (v6->mCurrentPos & 0x80000000) == 0 )
    v11 = &v6->mBuffer1End[v9 - (unsigned __int64)v6->mBuffer1Start];
  v6->mLastFrameNumBytes = (unsigned int)v10;
  v6->mLastFrameNumFreeBytes = (unsigned int)v11;
  v6->mLastFrameNumAllocBytes = (_DWORD)v10 - (_DWORD)v11;
  v6->mBuffer0Start = v7;
  v6->mBuffer1Start = buffer1;
  v6->mLastFrameOverflowed = v8 != 0;
  v6->mCurrentPos = byte_size0;
  v6->mBuffer0End = &v7[byte_size0];
  v6->mBuffer1End = &buffer1[byte_size1];
}

// File Line: 100
// RVA: 0x17ACC0
void __fastcall UFG::qLinearAllocator::Reset(UFG::qLinearAllocator *this)
{
  this->mCurrentPos = LODWORD(this->mBuffer0End) - LODWORD(this->mBuffer0Start);
}

// File Line: 105
// RVA: 0x172FC0
__int64 __fastcall UFG::qLinearAllocator::InFrame(UFG::qLinearAllocator *this, void *address)
{
  return ((signed __int64)address >= (_QWORD)this->mBuffer0Start && (signed __int64)address < (_QWORD)this->mBuffer0End) | (unsigned int)((signed __int64)address >= (_QWORD)this->mBuffer1Start && (signed __int64)address < (_QWORD)this->mBuffer1End);
}

// File Line: 161
// RVA: 0x1775D0
char *__fastcall UFG::qLinearAllocator::Malloc(UFG::qLinearAllocator *this, unsigned int size, unsigned int alignment)
{
  UFG::qLinearAllocator *v3; // r9
  unsigned int v4; // ebp
  unsigned int v5; // esi
  signed __int32 v6; // er10
  char *v7; // rdi
  __int64 v8; // rdx
  int v9; // er8
  unsigned int v10; // er11
  char *v11; // rdi

  v3 = this->mMainMemoryAddress;
  v4 = size;
  v5 = ~(alignment - 1);
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = v3->mCurrentPos;
      v7 = this->mBuffer1End;
      v8 = v3->mCurrentPos & v5;
      LODWORD(v8) = v8 & 0x7FFFFFFF;
      v9 = v8 - v4;
      v10 = v3->mCurrentPos & 0x80000000;
      if ( (v3->mCurrentPos & 0x80000000) == 0 )
        v7 = this->mBuffer0End;
      v11 = &v7[-v8];
      if ( v9 < 0 )
        break;
      if ( v6 == _InterlockedCompareExchange((volatile signed __int32 *)v3, v10 | v9 & 0x7FFFFFFF, v6) )
        return v11;
    }
    if ( v10 )
      break;
    _InterlockedCompareExchange(
      (volatile signed __int32 *)v3,
      (_QWORD)&this->mBuffer1End[-LODWORD(this->mBuffer1Start)] | 0x80000000,
      v6);
  }
  return 0i64;
}

