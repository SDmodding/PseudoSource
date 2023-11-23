// File Line: 54
// RVA: 0x4AD020
bool __fastcall UFG::PersistentData::MapBool::Iterator::IsValid(UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool *mList; // rcx

  mList = this->mList;
  if ( mList->mKeepType == KEEP_BOTH )
    return this->mIndex < mList->mValues.size;
  if ( (unsigned int)(mList->mKeepType - 1) > 1 )
    return 0;
  return this->mIndex < mList->mNames.size;
}

// File Line: 99
// RVA: 0x4A5440
UFG::PersistentData::KeyValue *__fastcall UFG::PersistentData::MapBool::Iterator::GetName(
        UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool *mList; // rdx

  mList = this->mList;
  if ( mList->mKeepType == KEEP_BOTH )
    return &mList->mValues.p[this->mIndex];
  if ( (unsigned int)(mList->mKeepType - 1) > 1 )
    return (UFG::PersistentData::KeyValue *)&UFG::gNullQSymbol;
  return (UFG::PersistentData::KeyValue *)&mList->mNames.p[this->mIndex];
}

// File Line: 126
// RVA: 0x4A67B0
bool __fastcall UFG::PersistentData::MapBool::Iterator::GetStatus(UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool *mList; // r8

  mList = this->mList;
  if ( mList->mKeepType )
    return mList->mKeepType == KEEP_TRUE;
  else
    return mList->mValues.p[this->mIndex].mBoolValue;
}

// File Line: 195
// RVA: 0x490AE0
void __fastcall UFG::PersistentData::MapBool::~MapBool(UFG::PersistentData::MapBool *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::PersistentData::KeyValue *v4; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v5; // rbx

  this->mValues.size = 0;
  this->mNames.size = 0;
  p = this->mNames.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->mNames.p = 0i64;
  *(_QWORD *)&this->mNames.size = 0i64;
  v4 = this->mValues.p;
  if ( v4 )
  {
    v5 = &v4[-1].4;
    `eh vector destructor iterator(v4, 8ui64, v4[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  this->mValues.p = 0i64;
  *(_QWORD *)&this->mValues.size = 0i64;
}

// File Line: 206
// RVA: 0x4A2270
__int64 __fastcall UFG::PersistentData::MapBool::GetCount(UFG::PersistentData::MapBool *this)
{
  if ( this->mKeepType == KEEP_BOTH )
    return this->mValues.size;
  if ( (unsigned int)(this->mKeepType - 1) > 1 )
    return 0i64;
  return this->mNames.size;
}

// File Line: 230
// RVA: 0x4A71D0
__int64 __fastcall UFG::PersistentData::MapBool::GetTrueCount(UFG::PersistentData::MapBool *this)
{
  __int64 result; // rax
  __int64 size; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v3; // rcx

  if ( this->mKeepType == KEEP_FALSE )
    return 0i64;
  if ( this->mKeepType == KEEP_TRUE )
    return this->mNames.size;
  size = this->mValues.size;
  result = 0i64;
  if ( (_DWORD)size )
  {
    v3 = &this->mValues.p->4;
    do
    {
      if ( v3->mBoolValue )
        result = (unsigned int)(result + 1);
      v3 += 2;
      --size;
    }
    while ( size );
  }
  return result;
}

// File Line: 254
// RVA: 0x48A7B0
char __fastcall UFG::PersistentData::RemoveArrayElementPreserveOrder<UFG::qSymbol>(
        UFG::qArray<UFG::qSymbol,0> *_array,
        int index)
{
  __int64 i; // rax
  UFG::qSymbol *p; // r10
  __int64 v4; // r8
  unsigned int mUID; // edx

  for ( i = (unsigned int)(index + 1); (unsigned int)i < _array->size; p[v4].mUID = mUID )
  {
    p = _array->p;
    v4 = (unsigned int)(i - 1);
    mUID = p[i].mUID;
    i = (unsigned int)(i + 1);
  }
  if ( _array->size > 1 )
    --_array->size;
  else
    _array->size = 0;
  return 1;
}

// File Line: 266
// RVA: 0x4BD8B0
void __fastcall UFG::PersistentData::MapBool::SetStatus(
        UFG::PersistentData::MapBool *this,
        UFG::qSymbol *name,
        bool status)
{
  unsigned int v6; // edx
  unsigned int v7; // eax
  UFG::qSymbol *v8; // rcx
  unsigned int size; // edx
  UFG::qSymbol *p; // rcx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *p_mValues; // rsi
  __int64 v12; // rdi
  unsigned int v13; // eax
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *v15; // rcx
  unsigned int capacity; // edx
  unsigned int v17; // ebx
  unsigned int v18; // r14d
  unsigned int v19; // edx
  UFG::PersistentData::KeyValue *v20; // rcx
  int v21; // [rsp+44h] [rbp+Ch]

  if ( this->mKeepType )
  {
    if ( this->mKeepType == KEEP_TRUE )
    {
      size = this->mNames.size;
      v7 = 0;
      if ( size )
      {
        p = this->mNames.p;
        while ( name->mUID != p->mUID )
        {
          ++v7;
          ++p;
          if ( v7 >= size )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        v7 = -1;
      }
      if ( status )
      {
LABEL_10:
        if ( v7 == -1 )
          UFG::qArray<UFG::qSymbol,0>::Add(&this->mNames, name, "qArray.Add");
        return;
      }
    }
    else
    {
      if ( this->mKeepType != KEEP_FALSE )
        return;
      v6 = this->mNames.size;
      v7 = 0;
      if ( v6 )
      {
        v8 = this->mNames.p;
        while ( name->mUID != v8->mUID )
        {
          ++v7;
          ++v8;
          if ( v7 >= v6 )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        v7 = -1;
      }
      if ( !status )
        goto LABEL_10;
    }
    if ( v7 != -1 )
      UFG::PersistentData::RemoveArrayElementPreserveOrder<UFG::qSymbol>(&this->mNames, v7);
  }
  else
  {
    p_mValues = &this->mValues;
    v12 = this->mValues.size;
    v13 = 0;
    if ( !(_DWORD)v12 )
      goto LABEL_24;
    mUID = name->mUID;
    v15 = this->mValues.p;
    while ( v15->mKey.mUID != mUID )
    {
      ++v13;
      ++v15;
      if ( v13 >= (unsigned int)v12 )
        goto LABEL_24;
    }
    if ( v13 == -1 )
    {
LABEL_24:
      capacity = p_mValues->capacity;
      v17 = v12 + 1;
      v18 = name->mUID;
      LOBYTE(v21) = status;
      if ( (int)v12 + 1 > capacity )
      {
        if ( capacity )
          v19 = 2 * capacity;
        else
          v19 = 1;
        for ( ; v19 < v17; v19 *= 2 )
          ;
        if ( v19 <= 2 )
          v19 = 2;
        if ( v19 - v17 > 0x10000 )
          v19 = v12 + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(p_mValues, v19, "MapTypes");
      }
      v20 = p_mValues->p;
      p_mValues->size = v17;
      v20[v12].mKey.mUID = v18;
      v20[v12].mIntValue = v21;
      v20[v12].mBoolValue = status;
    }
    else
    {
      this->mValues.p[v13].mBoolValue = status;
    }
  }
}

// File Line: 330
// RVA: 0x4A6800
bool __fastcall UFG::PersistentData::MapBool::GetStatus(UFG::PersistentData::MapBool *this, UFG::qSymbol *name)
{
  UFG::PersistentData::MapBool::KeepType mKeepType; // ecx
  __int32 v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // r9d
  UFG::qSymbol *p; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // r9d
  UFG::qSymbol *v14; // rcx
  unsigned int size; // edx
  int v16; // eax
  unsigned int mUID; // r9d
  UFG::PersistentData::KeyValue *i; // rcx

  mKeepType = this->mKeepType;
  if ( mKeepType == KEEP_BOTH )
  {
    size = this->mValues.size;
    v16 = 0;
    if ( size )
    {
      mUID = name->mUID;
      for ( i = this->mValues.p; i->mKey.mUID != mUID; ++i )
      {
        if ( ++v16 >= size )
          return 0;
      }
      if ( v16 != -1 )
        return this->mValues.p[v16].mBoolValue;
    }
    return 0;
  }
  v5 = mKeepType - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      v6 = this->mNames.size;
      v7 = 0;
      if ( v6 )
      {
        v8 = name->mUID;
        p = this->mNames.p;
        while ( v8 != p->mUID )
        {
          ++v7;
          ++p;
          if ( v7 >= v6 )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        v7 = -1;
      }
      return v7 == -1;
    }
    return 0;
  }
  v11 = this->mNames.size;
  v12 = 0;
  if ( v11 )
  {
    v13 = name->mUID;
    v14 = this->mNames.p;
    while ( v13 != v14->mUID )
    {
      ++v12;
      ++v14;
      if ( v12 >= v11 )
        goto LABEL_14;
    }
  }
  else
  {
LABEL_14:
    v12 = -1;
  }
  return v12 != -1;
}

// File Line: 367
// RVA: 0x4A6920
bool __fastcall UFG::PersistentData::MapBool::GetStatusByIndex(UFG::PersistentData::MapBool *this, unsigned int index)
{
  if ( this->mKeepType )
    return this->mKeepType == KEEP_TRUE;
  else
    return this->mValues.p[index].mBoolValue;
}

// File Line: 476
// RVA: 0x4A2290
__int64 __fastcall UFG::qSymbolUC::as_uint32(UFG::qArray<unsigned long,0> *this)
{
  return this->size;
}

// File Line: 481
// RVA: 0x4BDB30
void __fastcall UFG::PersistentData::MapInt::SetStatus(
        UFG::PersistentData::MapInt *this,
        UFG::qSymbol *name,
        int status)
{
  __int64 size; // rdi
  __int64 v4; // rax
  UFG::PersistentData::KeyValue *p; // rcx
  UFG::PersistentData::KeyValue *v8; // r9
  unsigned int mUID; // r14d
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::PersistentData::KeyValue *v13; // rax

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  v8 = p;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    v11 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 2 )
        v12 = 2;
      if ( v12 - v11 > 0x10000 )
        v12 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v12, "MapTypes");
    }
    v13 = this->mValues.p;
    this->mValues.size = v11;
    v13[size].mKey.mUID = mUID;
    v13[size].mIntValue = status;
    v13[size].mBoolValue = status;
  }
  else
  {
    p[v4].mIntValue = status;
  }
}

// File Line: 494
// RVA: 0x4A68F0
__int64 __fastcall UFG::PersistentData::MapInt::GetStatus(UFG::PersistentData::MapInt *this, UFG::qSymbol *name)
{
  unsigned int size; // r8d
  __int64 v3; // rax
  UFG::PersistentData::KeyValue *p; // r9
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *i; // rcx

  size = this->mValues.size;
  v3 = 0i64;
  if ( !this->mValues.size )
    return 0i64;
  p = this->mValues.p;
  mUID = name->mUID;
  for ( i = p; i->mKey.mUID != mUID; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= size )
      return 0i64;
  }
  if ( (_DWORD)v3 == -1 )
    return 0i64;
  else
    return (unsigned int)p[v3].mIntValue;
}

// File Line: 507
// RVA: 0x4A41D0
__int64 __fastcall UFG::PersistentData::MapInt::GetInt(UFG::PersistentData::MapInt *this, unsigned int index)
{
  if ( index >= this->mValues.size )
    return 0i64;
  else
    return (unsigned int)this->mValues.p[index].mIntValue;
}

// File Line: 520
// RVA: 0x494360
void __fastcall UFG::PersistentData::MapInt::ApplyDelta(
        UFG::PersistentData::MapInt *this,
        UFG::qSymbol *name,
        int delta)
{
  __int64 size; // rdi
  __int64 v4; // rax
  UFG::PersistentData::KeyValue *p; // r9
  unsigned int mUID; // r14d
  unsigned int capacity; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PersistentData::KeyValue *v12; // rax

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  while ( p->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++p;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    v10 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v11 = 2 * capacity;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 2 )
        v11 = 2;
      if ( v11 - v10 > 0x10000 )
        v11 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v11, "MapTypes");
    }
    v12 = this->mValues.p;
    this->mValues.size = v10;
    v12[size].mKey.mUID = mUID;
    v12[size].mIntValue = delta;
    v12[size].mBoolValue = delta;
  }
  else
  {
    this->mValues.p[v4].mIntValue += delta;
  }
}

// File Line: 533
// RVA: 0x4A6E30
__int64 __fastcall UFG::PersistentData::MapInt::GetTotal(UFG::PersistentData::MapInt *this)
{
  signed int size; // r11d
  int v2; // edx
  int v4; // r8d
  int mIntValue; // ebx
  unsigned int v6; // edi
  __int64 v7; // rcx
  int *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // r9

  size = this->mValues.size;
  v2 = 0;
  v4 = 0;
  mIntValue = 0;
  v6 = 0;
  v7 = 0i64;
  if ( size >= 2 )
  {
    v8 = (int *)&this->mValues.p[1].4;
    v9 = ((unsigned int)(size - 2) >> 1) + 1;
    v10 = (unsigned int)v9;
    v6 = 2 * v9;
    v7 = 2 * v9;
    do
    {
      v2 += *(v8 - 2);
      v4 += *v8;
      v8 += 4;
      --v10;
    }
    while ( v10 );
  }
  if ( v6 < size )
    mIntValue = this->mValues.p[v7].mIntValue;
  return (unsigned int)(mIntValue + v4 + v2);
}

// File Line: 546
// RVA: 0x4A5300
void __fastcall UFG::PersistentData::MapInt::GetMaxMin(
        UFG::PersistentData::MapInt *this,
        UFG::PersistentData::KeyValue **max,
        UFG::PersistentData::KeyValue **min)
{
  unsigned int size; // r10d
  UFG::PersistentData::KeyValue *p; // rax
  int mIntValue; // r11d
  unsigned int v9; // edx
  int v10; // esi
  __int64 v11; // r8
  UFG::PersistentData::KeyValue *v12; // rcx
  UFG::PersistentData::KeyValue *v13; // rcx

  size = this->mValues.size;
  if ( this->mValues.size )
  {
    p = this->mValues.p;
    if ( size == 1 )
    {
      *max = p;
      *min = 0i64;
    }
    else
    {
      mIntValue = p->mIntValue;
      *min = p;
      *max = p;
      v9 = 1;
      v10 = mIntValue;
      if ( size > 1 )
      {
        v11 = 1i64;
        do
        {
          v12 = this->mValues.p;
          if ( v10 < v12[v11].mIntValue )
          {
            v10 = v12[v11].mIntValue;
            *max = &v12[v9];
          }
          v13 = this->mValues.p;
          if ( mIntValue > v13[v11].mIntValue )
          {
            mIntValue = v13[v11].mIntValue;
            *min = &v13[v9];
          }
          ++v9;
          ++v11;
        }
        while ( v9 < size );
      }
    }
  }
  else
  {
    *min = 0i64;
    *max = 0i64;
  }
}

// File Line: 643
// RVA: 0x4BDC00
void __fastcall UFG::PersistentData::MapUInt64::SetStatus(
        UFG::PersistentData::MapUInt64 *this,
        UFG::qSymbol *name,
        unsigned __int64 status)
{
  __int64 size; // rdi
  __int64 v4; // rax
  UFG::PersistentData::KeyValue64 *p; // rcx
  UFG::PersistentData::KeyValue64 *v8; // r9
  unsigned int mUID; // ebp
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::PersistentData::KeyValue64 *v13; // rax

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  v8 = p;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    v11 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 - v11 > 0x10000 )
        v12 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue64,0>::Reallocate(&this->mValues, v12, "MapTypes");
    }
    this->mValues.size = v11;
    v13 = &this->mValues.p[size];
    v13->mKey.mUID = mUID;
    v13->mIntValue = status;
  }
  else
  {
    p[v4].mIntValue = status;
  }
}

// File Line: 737
// RVA: 0x4A5470
UFG::PersistentData::KeyValue *__fastcall UFG::PersistentData::MapFloat::Iterator::GetName(
        UFG::PersistentData::MapFloat::Iterator *this)
{
  return &this->mList->mValues.p[this->mIndex];
}

// File Line: 744
// RVA: 0x4A67E0
float __fastcall UFG::PersistentData::MapFloat::Iterator::GetStatus(UFG::PersistentData::MapFloat::Iterator *this)
{
  return this->mList->mValues.p[this->mIndex].mFloatValue;
}

// File Line: 779
// RVA: 0x4BDA50
void __fastcall UFG::PersistentData::MapFloat::SetStatus(
        UFG::PersistentData::MapFloat *this,
        UFG::qSymbol *name,
        float status)
{
  __int64 size; // rdi
  __int64 v4; // rax
  UFG::PersistentData::KeyValue *p; // rcx
  UFG::PersistentData::KeyValue *v7; // r8
  unsigned int mUID; // ebp
  unsigned int capacity; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PersistentData::KeyValue *v12; // rcx

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  v7 = p;
  while ( v7->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v7;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    v10 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v11 = 2 * capacity;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 2 )
        v11 = 2;
      if ( v11 - v10 > 0x10000 )
        v11 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v11, "MapTypes");
    }
    v12 = this->mValues.p;
    this->mValues.size = v10;
    v12[size].mKey.mUID = mUID;
    v12[size].mFloatValue = status;
    v12[size].mBoolValue = LOBYTE(status);
  }
  else
  {
    p[v4].mFloatValue = status;
  }
}

// File Line: 792
// RVA: 0x4A68B0
float __fastcall UFG::PersistentData::MapFloat::GetStatus(UFG::PersistentData::MapFloat *this, UFG::qSymbol *name)
{
  unsigned int size; // r8d
  __int64 v3; // rax
  UFG::PersistentData::KeyValue *p; // r9
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *i; // rcx

  size = this->mValues.size;
  v3 = 0i64;
  if ( !this->mValues.size )
    return 0.0;
  p = this->mValues.p;
  mUID = name->mUID;
  for ( i = p; i->mKey.mUID != mUID; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= size )
      return 0.0;
  }
  if ( (_DWORD)v3 == -1 )
    return 0.0;
  else
    return p[v3].mFloatValue;
}

// File Line: 805
// RVA: 0x494270
void __fastcall UFG::PersistentData::MapFloat::ApplyDelta(
        UFG::PersistentData::MapFloat *this,
        UFG::qSymbol *name,
        float delta)
{
  __int64 size; // rdi
  __int64 v4; // rax
  UFG::PersistentData::KeyValue *p; // r8
  unsigned int mUID; // ebp
  unsigned int capacity; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  UFG::PersistentData::KeyValue *v11; // rcx

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  while ( p->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++p;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    v9 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v9 > 0x10000 )
        v10 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v10, "MapTypes");
    }
    v11 = this->mValues.p;
    this->mValues.size = v9;
    v11[size].mKey.mUID = mUID;
    v11[size].mFloatValue = delta;
    v11[size].mBoolValue = LOBYTE(delta);
  }
  else
  {
    this->mValues.p[v4].mFloatValue = delta + this->mValues.p[v4].mFloatValue;
  }
}

// File Line: 818
// RVA: 0x4A5120
void __fastcall UFG::PersistentData::MapFloat::GetMaxMin(
        UFG::PersistentData::MapFloat *this,
        UFG::PersistentData::KeyValue **max,
        UFG::PersistentData::KeyValue **min)
{
  unsigned int size; // esi
  UFG::PersistentData::KeyValue *p; // rax
  float mFloatValue; // xmm0_4
  unsigned int v9; // edx
  __int64 v10; // r8
  float v11; // xmm1_4
  unsigned int v12; // r10d
  UFG::PersistentData::KeyValue *v13; // rcx
  UFG::PersistentData::KeyValue *v14; // rcx
  UFG::PersistentData::KeyValue *v15; // r11
  UFG::PersistentData::KeyValue *v16; // r11
  UFG::PersistentData::KeyValue *v17; // rcx
  UFG::PersistentData::KeyValue *v18; // rcx
  UFG::PersistentData::KeyValue *v19; // r11
  UFG::PersistentData::KeyValue *v20; // r11
  __int64 v21; // r8
  UFG::PersistentData::KeyValue *v22; // rcx
  UFG::PersistentData::KeyValue *v23; // rcx

  size = this->mValues.size;
  if ( this->mValues.size )
  {
    p = this->mValues.p;
    if ( size == 1 )
    {
      *max = p;
      *min = 0i64;
    }
    else
    {
      mFloatValue = p->mFloatValue;
      *min = p;
      *max = p;
      v9 = 1;
      v10 = 1i64;
      v11 = mFloatValue;
      if ( size > 1 )
      {
        if ( (int)(size - 1) >= 4 )
        {
          v12 = 3;
          do
          {
            v13 = this->mValues.p;
            if ( v11 < v13[v10].mFloatValue )
            {
              v11 = v13[v10].mFloatValue;
              *max = &v13[v9];
            }
            v14 = this->mValues.p;
            if ( mFloatValue > v14[v10].mFloatValue )
            {
              mFloatValue = v14[v10].mFloatValue;
              *min = &v14[v9];
            }
            v15 = this->mValues.p;
            if ( v11 < v15[v10 + 1].mFloatValue )
            {
              v11 = v15[v10 + 1].mFloatValue;
              *max = &v15[v12 - 1];
            }
            v16 = this->mValues.p;
            if ( mFloatValue > v16[v10 + 1].mFloatValue )
            {
              mFloatValue = v16[v10 + 1].mFloatValue;
              *min = &v16[v12 - 1];
            }
            v17 = this->mValues.p;
            if ( v11 < v17[v10 + 2].mFloatValue )
            {
              v11 = v17[v10 + 2].mFloatValue;
              *max = &v17[v12];
            }
            v18 = this->mValues.p;
            if ( mFloatValue > v18[v10 + 2].mFloatValue )
            {
              mFloatValue = v18[v10 + 2].mFloatValue;
              *min = &v18[v12];
            }
            v19 = this->mValues.p;
            if ( v11 < v19[v10 + 3].mFloatValue )
            {
              v11 = v19[v10 + 3].mFloatValue;
              *max = &v19[v12 + 1];
            }
            v20 = this->mValues.p;
            if ( mFloatValue > v20[v10 + 3].mFloatValue )
            {
              mFloatValue = v20[v10 + 3].mFloatValue;
              *min = &v20[v12 + 1];
            }
            v9 += 4;
            v10 += 4i64;
            v12 += 4;
          }
          while ( v9 < size - 3 );
        }
        if ( v9 < size )
        {
          v21 = v10;
          do
          {
            v22 = this->mValues.p;
            if ( v11 < v22[v21].mFloatValue )
            {
              v11 = v22[v21].mFloatValue;
              *max = &v22[v9];
            }
            v23 = this->mValues.p;
            if ( mFloatValue > v23[v21].mFloatValue )
            {
              mFloatValue = v23[v21].mFloatValue;
              *min = &v23[v9];
            }
            ++v9;
            ++v21;
          }
          while ( v9 < size );
        }
      }
    }
  }
  else
  {
    *min = 0i64;
    *max = 0i64;
  }
}

// File Line: 858
// RVA: 0x4AD010
bool __fastcall UFG::PersistentData::MapBinary::Iterator::IsValid(UFG::PersistentData::MapFloat::Iterator *this)
{
  return this->mIndex < this->mList->mValues.size;
}

// File Line: 868
// RVA: 0x4B1370
void __fastcall UFG::PersistentData::MapFloat::Iterator::Next(ARefCountMix<SSInstance> *this)
{
  ++this->i_ref_count;
}

// File Line: 873
// RVA: 0x4A5420
UFG::PersistentData::KeyBinary *__fastcall UFG::PersistentData::MapBinary::Iterator::GetName(
        UFG::PersistentData::MapBinary::Iterator *this)
{
  return &this->mList->mValues.p[this->mIndex];
}

// File Line: 880
// RVA: 0x4A1940
UFG::PersistentData::Binary *__fastcall UFG::PersistentData::MapBinary::Iterator::GetBinary(
        UFG::PersistentData::MapBinary::Iterator *this)
{
  return &this->mList->mValues.p[this->mIndex].mBinary;
}

// File Line: 894
// RVA: 0x48CE70
void __fastcall UFG::PersistentData::MapBinary::MapBinary(
        UFG::PersistentData::MapBinary *this,
        UFG::PersistentData::MapBinary *src)
{
  __int64 v4; // r15
  __int64 size; // r12
  UFG::PersistentData::KeyBinary *v6; // rsi
  unsigned int mSize; // edi
  UFG::allocator::free_link *v8; // rbx
  UFG::PersistentData::Binary binary; // [rsp+28h] [rbp-40h] BYREF

  v4 = 0i64;
  this->mValues.p = 0i64;
  *(_QWORD *)&this->mValues.size = 0i64;
  UFG::PersistentData::MapBinary::Clear(this);
  this->mPersistentDataType = src->mPersistentDataType;
  if ( src->mValues.size )
  {
    size = src->mValues.size;
    do
    {
      v6 = &src->mValues.p[v4];
      mSize = v6->mBinary.mSize;
      v8 = UFG::qMalloc(mSize, "MapBinary", 0i64);
      UFG::qMemCopy(v8, v6->mBinary.mpBuffer, mSize);
      binary.mpBuffer = v8;
      binary.mSize = mSize;
      UFG::PersistentData::MapBinary::SetBinary(this, &v6->mKey, &binary);
      ++v4;
      --size;
    }
    while ( size );
  }
}

// File Line: 916
// RVA: 0x4978A0
void __fastcall UFG::PersistentData::MapBinary::Clear(UFG::PersistentData::MapBinary *this)
{
  __int64 v2; // rdi
  __int64 size; // rbp
  UFG::PersistentData::KeyBinary *p; // rbx
  UFG::PersistentData::KeyBinary *v5; // rcx
  unsigned int *p_mSize; // rbx

  if ( this->mValues.size )
  {
    v2 = 0i64;
    size = this->mValues.size;
    do
    {
      p = this->mValues.p;
      if ( p[v2].mBinary.mSize )
        operator delete[](p[v2].mBinary.mpBuffer);
      p[v2].mBinary.mpBuffer = 0i64;
      p[v2++].mBinary.mSize = 0;
      --size;
    }
    while ( size );
  }
  v5 = this->mValues.p;
  if ( v5 )
  {
    p_mSize = &v5[-1].mBinary.mSize;
    `eh vector destructor iterator(v5, 0x18ui64, v5[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
    operator delete[](p_mSize);
  }
  this->mValues.p = 0i64;
  *(_QWORD *)&this->mValues.size = 0i64;
}

// File Line: 926
// RVA: 0x4AD3F0
void __fastcall UFG::PersistentData::MapBinary::KeepLatest(UFG::PersistentData::MapBinary *this, unsigned int newsize)
{
  int v3; // eax
  __int64 v4; // rsi
  UFG::PersistentData::KeyBinary *p; // rdi
  int v6; // r8d
  __int64 v7; // rdx
  UFG::PersistentData::KeyBinary *v8; // rcx

  v3 = this->mValues.size - newsize;
  if ( v3 >= 1 )
  {
    v4 = (unsigned int)v3;
    do
    {
      p = this->mValues.p;
      if ( p->mBinary.mSize )
        operator delete[](p->mBinary.mpBuffer);
      v6 = 1;
      p->mBinary.mpBuffer = 0i64;
      p->mBinary.mSize = 0;
      if ( this->mValues.size != 1 )
      {
        v7 = 1i64;
        do
        {
          ++v6;
          v8 = &this->mValues.p[v7++];
          v8[-1].mKey.mUID = v8->mKey.mUID;
          v8[-1].mBinary.mpBuffer = v8->mBinary.mpBuffer;
          v8[-1].mBinary.mSize = v8->mBinary.mSize;
        }
        while ( v6 != this->mValues.size );
      }
      if ( this->mValues.size > 1 )
        --this->mValues.size;
      else
        this->mValues.size = 0;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 947
// RVA: 0x4BBBB0
void __fastcall UFG::PersistentData::MapBinary::SetBinary(
        UFG::PersistentData::MapBinary *this,
        UFG::qSymbol *name,
        UFG::PersistentData::Binary *binary)
{
  __int64 size; // rdi
  unsigned __int64 v4; // rax
  UFG::PersistentData::KeyBinary *p; // r15
  UFG::PersistentData::KeyBinary *v8; // r9
  unsigned int mUID; // ebp
  unsigned int capacity; // edx
  void *mpBuffer; // r14
  unsigned int mSize; // r15d
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // ebp
  void *v16; // r14
  unsigned __int64 v17; // rdi
  UFG::PersistentData::KeyBinary *v18; // rbx
  UFG::PersistentData::KeyBinary *v19; // rax
  __int64 v20; // rcx

  size = this->mValues.size;
  v4 = 0i64;
  if ( !(_DWORD)size )
    goto LABEL_5;
  p = this->mValues.p;
  v8 = p;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)size )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 == -1 )
  {
LABEL_5:
    mUID = name->mUID;
    capacity = this->mValues.capacity;
    mpBuffer = binary->mpBuffer;
    mSize = binary->mSize;
    v13 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v14 = 2 * capacity;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 - v13 > 0x10000 )
        v14 = size + 65537;
      UFG::qArray<UFG::PersistentData::KeyBinary,0>::Reallocate(&this->mValues, v14, "qArray.Add");
    }
    v19 = this->mValues.p;
    v20 = size;
    this->mValues.size = v13;
    v19[v20].mKey.mUID = mUID;
    v19[v20].mBinary.mpBuffer = mpBuffer;
    v19[v20].mBinary.mSize = mSize;
  }
  else
  {
    v15 = binary->mSize;
    v16 = binary->mpBuffer;
    v17 = v4;
    if ( p[v4].mBinary.mSize )
      operator delete[](p[v17].mBinary.mpBuffer);
    p[v17].mBinary.mpBuffer = v16;
    p[v17].mBinary.mSize = v15;
    if ( !binary->mpBuffer )
    {
      v18 = &this->mValues.p[v17];
      if ( v18->mBinary.mSize )
        operator delete[](v18->mBinary.mpBuffer);
      v18->mBinary.mpBuffer = 0i64;
      v18->mBinary.mSize = 0;
    }
  }
}

