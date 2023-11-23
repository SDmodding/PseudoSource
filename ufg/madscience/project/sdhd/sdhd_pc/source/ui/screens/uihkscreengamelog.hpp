// File Line: 33
// RVA: 0x5C8CB0
void __fastcall UFG::GameLogManager::cGameLogCircularArray::cGameLogCircularArray(
        UFG::GameLogManager::cGameLogCircularArray *this)
{
  `eh vector constructor iterator(this, 8ui64, 100, (void (__fastcall *)(void *))BackInfo::BackInfo);
  this->mCapacity = 100;
  *(_QWORD *)&this->mHeadIndex = -1i64;
}

// File Line: 46
// RVA: 0x5CF030
UFG::GameLogManager::cGameLogCircularArray *__fastcall UFG::GameLogManager::cGameLogCircularArray::operator[](
        UFG::GameLogManager::cGameLogCircularArray *this,
        int index)
{
  unsigned int mHeadIndex; // ecx
  int v4; // r8d
  unsigned int mTailIndex; // r8d
  int v6; // edx
  unsigned int v7; // r8d
  unsigned int v8; // edx

  mHeadIndex = this->mHeadIndex;
  if ( mHeadIndex == -1 )
  {
    v4 = 0;
  }
  else
  {
    mTailIndex = this->mTailIndex;
    if ( mHeadIndex <= mTailIndex )
      v4 = mTailIndex - mHeadIndex + 1;
    else
      v4 = this->mCapacity - mHeadIndex + mTailIndex + 1;
  }
  v6 = index % v4;
  if ( v6 >= 0 )
    return (UFG::GameLogManager::cGameLogCircularArray *)((char *)this + 8 * (int)((mHeadIndex + v6) % this->mCapacity));
  v7 = this->mTailIndex;
  if ( -v6 <= v7 + 1 )
    v8 = v7 + v6 + 1;
  else
    v8 = v7 + this->mCapacity + 1 + v6;
  return (UFG::GameLogManager::cGameLogCircularArray *)((char *)this + 8 * (int)v8);
}

// File Line: 133
// RVA: 0x5D2D60
UFG::GameLogManager::sGameLogEntry *__fastcall UFG::GameLogManager::cGameLogCircularArray::AddTail(
        UFG::GameLogManager::cGameLogCircularArray *this,
        UFG::GameLogManager::sGameLogEntry *obj)
{
  unsigned int mHeadIndex; // r9d
  int v3; // r8d
  unsigned int mTailIndex; // r8d
  int mCapacity; // r9d
  UFG::GameLogManager::sGameLogEntry *v6; // rcx

  mHeadIndex = this->mHeadIndex;
  if ( mHeadIndex == -1 )
  {
    v3 = 0;
  }
  else
  {
    mTailIndex = this->mTailIndex;
    if ( mHeadIndex <= mTailIndex )
      v3 = mTailIndex - mHeadIndex + 1;
    else
      v3 = this->mCapacity - mHeadIndex + mTailIndex + 1;
  }
  mCapacity = this->mCapacity;
  if ( v3 >= mCapacity )
    return 0i64;
  if ( v3 )
    this->mTailIndex = (this->mTailIndex + 1) % mCapacity;
  else
    *(_QWORD *)&this->mHeadIndex = 0i64;
  v6 = &this->mData[this->mTailIndex];
  *v6 = *obj;
  return v6;
}

// File Line: 157
// RVA: 0x600E20
UFG::GameLogManager::sGameLogEntry *__fastcall UFG::GameLogManager::cGameLogCircularArray::RemoveHead(
        UFG::GameLogManager::cGameLogCircularArray *this)
{
  __int64 mHeadIndex; // rdx
  unsigned int mTailIndex; // r8d
  int v3; // r8d
  UFG::GameLogManager::sGameLogEntry *result; // rax

  mHeadIndex = this->mHeadIndex;
  if ( (_DWORD)mHeadIndex == -1 )
    return 0i64;
  mTailIndex = this->mTailIndex;
  v3 = (unsigned int)mHeadIndex <= mTailIndex
     ? mTailIndex - mHeadIndex + 1
     : this->mCapacity - mHeadIndex + mTailIndex + 1;
  if ( v3 <= 0 )
    return 0i64;
  result = &this->mData[mHeadIndex];
  this->mHeadIndex = (unsigned int)(mHeadIndex + 1) % this->mCapacity;
  if ( v3 == 1 )
    *(_QWORD *)&this->mHeadIndex = -1i64;
  return result;
}

// File Line: 221
// RVA: 0x5D5E00
__int64 __fastcall UFG::GameLogManager::cGameLogCircularArray::Count(UFG::GameLogManager::cGameLogCircularArray *this)
{
  unsigned int mHeadIndex; // edx
  unsigned int mTailIndex; // ecx

  mHeadIndex = this->mHeadIndex;
  if ( mHeadIndex == -1 )
    return 0i64;
  mTailIndex = this->mTailIndex;
  if ( mHeadIndex <= mTailIndex )
    return mTailIndex - mHeadIndex + 1;
  else
    return mTailIndex + this->mCapacity - mHeadIndex + 1;
}

