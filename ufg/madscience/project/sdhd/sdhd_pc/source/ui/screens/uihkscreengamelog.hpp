// File Line: 33
// RVA: 0x5C8CB0
void __fastcall UFG::GameLogManager::cGameLogCircularArray::cGameLogCircularArray(UFG::GameLogManager::cGameLogCircularArray *this)
{
  UFG::GameLogManager::cGameLogCircularArray *v1; // rbx

  v1 = this;
  `eh vector constructor iterator'(this, 8ui64, 100, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v1->mCapacity = 100;
  *(_QWORD *)&v1->mHeadIndex = -1i64;
}

// File Line: 46
// RVA: 0x5CF030
UFG::GameLogManager::sGameLogEntry *__fastcall UFG::GameLogManager::cGameLogCircularArray::operator[](UFG::GameLogManager::cGameLogCircularArray *this, int index)
{
  UFG::GameLogManager::cGameLogCircularArray *v2; // r9
  unsigned int v3; // ecx
  int v4; // er8
  unsigned int v5; // er8
  int v6; // edx
  unsigned int v7; // er8
  int v8; // edx

  v2 = this;
  v3 = this->mHeadIndex;
  if ( v3 == -1 )
  {
    v4 = 0;
  }
  else
  {
    v5 = v2->mTailIndex;
    if ( v3 <= v5 )
      v4 = v5 - v3 + 1;
    else
      v4 = v2->mCapacity - v3 + v5 + 1;
  }
  v6 = index % v4;
  if ( v6 >= 0 )
    return (UFG::GameLogManager::sGameLogEntry *)((char *)v2 + 8 * (signed int)((v3 + v6) % v2->mCapacity));
  v7 = v2->mTailIndex;
  if ( -v6 <= v7 + 1 )
    v8 = v7 + v6 + 1;
  else
    v8 = v7 + v2->mCapacity + 1 + v6;
  return (UFG::GameLogManager::sGameLogEntry *)((char *)v2 + 8 * v8);
}

// File Line: 133
// RVA: 0x5D2D60
UFG::GameLogManager::sGameLogEntry *__fastcall UFG::GameLogManager::cGameLogCircularArray::AddTail(UFG::GameLogManager::cGameLogCircularArray *this, UFG::GameLogManager::sGameLogEntry *obj)
{
  unsigned int v2; // er9
  int v3; // er8
  unsigned int v4; // er8
  int v5; // er9
  UFG::GameLogManager::sGameLogEntry *v6; // rcx

  v2 = this->mHeadIndex;
  if ( v2 == -1 )
  {
    v3 = 0;
  }
  else
  {
    v4 = this->mTailIndex;
    if ( v2 <= v4 )
      v3 = v4 - v2 + 1;
    else
      v3 = this->mCapacity - v2 + v4 + 1;
  }
  v5 = this->mCapacity;
  if ( v3 >= v5 )
    return 0i64;
  if ( v3 )
    this->mTailIndex = (this->mTailIndex + 1) % v5;
  else
    *(_QWORD *)&this->mHeadIndex = 0i64;
  v6 = &this->mData[this->mTailIndex];
  v6->type.mUID = obj->type.mUID;
  v6->string_hash = obj->string_hash;
  return v6;
}

// File Line: 157
// RVA: 0x600E20
UFG::GameLogManager::sGameLogEntry *__fastcall UFG::GameLogManager::cGameLogCircularArray::RemoveHead(UFG::GameLogManager::cGameLogCircularArray *this)
{
  __int64 v1; // rdx
  unsigned int v2; // er8
  int v3; // er8
  UFG::GameLogManager::sGameLogEntry *result; // rax

  v1 = this->mHeadIndex;
  if ( (_DWORD)v1 == -1 )
    return 0i64;
  v2 = this->mTailIndex;
  v3 = (unsigned int)v1 <= v2 ? v2 - v1 + 1 : this->mCapacity - v1 + v2 + 1;
  if ( v3 <= 0 )
    return 0i64;
  result = &this->mData[v1];
  this->mHeadIndex = (unsigned int)(v1 + 1) % this->mCapacity;
  if ( v3 == 1 )
    *(_QWORD *)&this->mHeadIndex = -1i64;
  return result;
}

// File Line: 221
// RVA: 0x5D5E00
__int64 __fastcall UFG::GameLogManager::cGameLogCircularArray::Count(UFG::GameLogManager::cGameLogCircularArray *this)
{
  unsigned int v1; // edx
  UFG::GameLogManager::cGameLogCircularArray *v2; // rax
  __int64 result; // rax
  unsigned int v4; // ecx

  v1 = this->mHeadIndex;
  v2 = this;
  if ( v1 == -1 )
    return 0i64;
  v4 = this->mTailIndex;
  if ( v1 <= v4 )
    result = v4 - v1 + 1;
  else
    result = v4 + v2->mCapacity - v1 + 1;
  return result;
}

