// File Line: 54
// RVA: 0x4AD020
bool __fastcall UFG::PersistentData::MapBool::Iterator::IsValid(UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool::Iterator *v1; // r8
  UFG::PersistentData::MapBool *v2; // rcx

  v1 = this;
  v2 = this->mList;
  if ( v2->mKeepType == KEEP_BOTH )
    return v1->mIndex < v2->mValues.size;
  if ( (unsigned int)(v2->mKeepType - 1) > 1 )
    return 0;
  return v1->mIndex < v2->mNames.size;
}

// File Line: 99
// RVA: 0x4A5440
UFG::PersistentData::KeyValue *__fastcall UFG::PersistentData::MapBool::Iterator::GetName(UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool *v1; // rdx

  v1 = this->mList;
  if ( v1->mKeepType == KEEP_BOTH )
    return &v1->mValues.p[this->mIndex];
  if ( (unsigned int)(v1->mKeepType - 1) > 1 )
    return (UFG::PersistentData::KeyValue *)&UFG::gNullQSymbol;
  return (UFG::PersistentData::KeyValue *)&v1->mNames.p[this->mIndex];
}

// File Line: 126
// RVA: 0x4A67B0
bool __fastcall UFG::PersistentData::MapBool::Iterator::GetStatus(UFG::PersistentData::MapBool::Iterator *this)
{
  UFG::PersistentData::MapBool *v1; // r8
  bool result; // al

  v1 = this->mList;
  if ( v1->mKeepType )
    result = v1->mKeepType == 1;
  else
    result = v1->mValues.p[this->mIndex].mBoolValue;
  return result;
}

// File Line: 195
// RVA: 0x490AE0
void __fastcall UFG::PersistentData::MapBool::~MapBool(UFG::PersistentData::MapBool *this)
{
  UFG::PersistentData::MapBool *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::PersistentData::KeyValue *v4; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v5; // rbx

  v1 = this;
  this->mValues.size = 0;
  this->mNames.size = 0;
  v2 = this->mNames.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->mNames.p = 0i64;
  *(_QWORD *)&v1->mNames.size = 0i64;
  v4 = v1->mValues.p;
  if ( v4 )
  {
    v5 = &v4[-1].4;
    `eh vector destructor iterator'(v4, 8ui64, v4[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  v1->mValues.p = 0i64;
  *(_QWORD *)&v1->mValues.size = 0i64;
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
  __int64 v2; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v3; // rcx

  if ( this->mKeepType == 2 )
    return 0i64;
  if ( this->mKeepType == 1 )
    return this->mNames.size;
  v2 = this->mValues.size;
  result = 0i64;
  if ( (_DWORD)v2 )
  {
    v3 = &this->mValues.p->4;
    do
    {
      if ( LOBYTE(v3->mFloatValue) )
        result = (unsigned int)(result + 1);
      v3 += 2;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

// File Line: 254
// RVA: 0x48A7B0
char __fastcall UFG::PersistentData::RemoveArrayElementPreserveOrder<UFG::qSymbol>(UFG::qArray<UFG::qSymbol,0> *_array, int index)
{
  __int64 i; // rax
  UFG::qSymbol *v3; // r10
  __int64 v4; // r8
  unsigned int v5; // edx

  for ( i = (unsigned int)(index + 1); (unsigned int)i < _array->size; v3[v4].mUID = v5 )
  {
    v3 = _array->p;
    v4 = (unsigned int)(i - 1);
    v5 = v3[i].mUID;
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
void __fastcall UFG::PersistentData::MapBool::SetStatus(UFG::PersistentData::MapBool *this, UFG::qSymbol *name, bool status)
{
  bool v3; // bp
  UFG::qSymbol *v4; // r11
  UFG::PersistentData::MapBool *v5; // r10
  unsigned int v6; // edx
  unsigned int v7; // eax
  UFG::qSymbol *v8; // rcx
  unsigned int v9; // edx
  UFG::qSymbol *v10; // rcx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v11; // rsi
  __int64 v12; // rdi
  unsigned int v13; // eax
  unsigned int v14; // edx
  UFG::PersistentData::KeyValue *v15; // rcx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  UFG::qSymbol v18; // er14
  unsigned int v19; // edx
  UFG::PersistentData::KeyValue *v20; // rcx
  int v21; // [rsp+44h] [rbp+Ch]

  v3 = status;
  v4 = name;
  v5 = this;
  if ( this->mKeepType )
  {
    if ( this->mKeepType == 1 )
    {
      v9 = this->mNames.size;
      v7 = 0;
      if ( v9 )
      {
        v10 = this->mNames.p;
        while ( v4->mUID != v10->mUID )
        {
          ++v7;
          ++v10;
          if ( v7 >= v9 )
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
          UFG::qArray<UFG::qSymbol,0>::Add(&v5->mNames, v4, "qArray.Add");
        return;
      }
    }
    else
    {
      if ( this->mKeepType != 2 )
        return;
      v6 = this->mNames.size;
      v7 = 0;
      if ( v6 )
      {
        v8 = this->mNames.p;
        while ( v4->mUID != v8->mUID )
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
      UFG::PersistentData::RemoveArrayElementPreserveOrder<UFG::qSymbol>(&v5->mNames, v7);
  }
  else
  {
    v11 = &this->mValues;
    v12 = this->mValues.size;
    v13 = 0;
    if ( !(_DWORD)v12 )
      goto LABEL_24;
    v14 = name->mUID;
    v15 = this->mValues.p;
    while ( v15->mKey.mUID != v14 )
    {
      ++v13;
      ++v15;
      if ( v13 >= (unsigned int)v12 )
        goto LABEL_24;
    }
    if ( v13 != -1 )
    {
      v5->mValues.p[v13].mBoolValue = status;
    }
    else
    {
LABEL_24:
      v16 = v11->capacity;
      v17 = v12 + 1;
      v18.mUID = v4->mUID;
      LOBYTE(v21) = status;
      if ( (signed int)v12 + 1 > v16 )
      {
        if ( v16 )
          v19 = 2 * v16;
        else
          v19 = 1;
        for ( ; v19 < v17; v19 *= 2 )
          ;
        if ( v19 <= 2 )
          v19 = 2;
        if ( v19 - v17 > 0x10000 )
          v19 = v12 + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(v11, v19, "MapTypes");
      }
      v20 = v11->p;
      v11->size = v17;
      v20[v12].mKey = v18;
      v20[v12].mIntValue = v21;
      v20[v12].mBoolValue = v3;
    }
  }
}

// File Line: 330
// RVA: 0x4A6800
bool __fastcall UFG::PersistentData::MapBool::GetStatus(UFG::PersistentData::MapBool *this, UFG::qSymbol *name)
{
  UFG::PersistentData::MapBool *v2; // r8
  UFG::PersistentData::MapBool::KeepType v3; // ecx
  UFG::qSymbol *v4; // r9
  int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // er9
  UFG::qSymbol *v9; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // er9
  UFG::qSymbol *v14; // rcx
  unsigned int v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // er9
  UFG::PersistentData::KeyValue *v18; // rcx

  v2 = this;
  v3 = this->mKeepType;
  v4 = name;
  if ( v3 == KEEP_BOTH )
  {
    v15 = v2->mValues.size;
    v16 = 0;
    if ( v15 )
    {
      v17 = v4->mUID;
      v18 = v2->mValues.p;
      while ( v18->mKey.mUID != v17 )
      {
        ++v16;
        ++v18;
        if ( v16 >= v15 )
          return 0;
      }
      if ( v16 != -1 )
        return v2->mValues.p[v16].mBoolValue;
    }
    return 0;
  }
  v5 = v3 - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      v6 = v2->mNames.size;
      v7 = 0;
      if ( v6 )
      {
        v8 = v4->mUID;
        v9 = v2->mNames.p;
        while ( v8 != v9->mUID )
        {
          ++v7;
          ++v9;
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
  v11 = v2->mNames.size;
  v12 = 0;
  if ( v11 )
  {
    v13 = v4->mUID;
    v14 = v2->mNames.p;
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
  bool result; // al

  if ( this->mKeepType )
    result = this->mKeepType == 1;
  else
    result = this->mValues.p[index].mBoolValue;
  return result;
}

// File Line: 476
// RVA: 0x4A2290
__int64 __fastcall UFG::qSymbolUC::as_uint32(UFG::qArray<unsigned long,0> *this)
{
  return this->size;
}

// File Line: 481
// RVA: 0x4BDB30
void __fastcall UFG::PersistentData::MapInt::SetStatus(UFG::PersistentData::MapInt *this, UFG::qSymbol *name, int status)
{
  __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebp
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::PersistentData::KeyValue *v7; // rcx
  UFG::PersistentData::KeyValue *v8; // r9
  unsigned int v9; // er14
  unsigned int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::PersistentData::KeyValue *v13; // rax

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = status;
  v6 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v7 = this->mValues.p;
  v8 = v7;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    v7[v4].mIntValue = status;
  }
  else
  {
LABEL_5:
    v9 = name->mUID;
    v10 = v6->mValues.capacity;
    v11 = v3 + 1;
    if ( (signed int)v3 + 1 > v10 )
    {
      if ( v10 )
        v12 = 2 * v10;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 2 )
        v12 = 2;
      if ( v12 - v11 > 0x10000 )
        v12 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&v6->mValues, v12, "MapTypes");
    }
    v13 = v6->mValues.p;
    v6->mValues.size = v11;
    v13[v3].mKey.mUID = v9;
    v13[v3].mIntValue = v5;
    v13[v3].mBoolValue = v5;
  }
}

// File Line: 494
// RVA: 0x4A68F0
__int64 __fastcall UFG::PersistentData::MapInt::GetStatus(UFG::PersistentData::MapInt *this, UFG::qSymbol *name)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::PersistentData::KeyValue *v4; // r9
  unsigned int v5; // edx
  UFG::PersistentData::KeyValue *v6; // rcx
  __int64 result; // rax

  v2 = this->mValues.size;
  v3 = 0i64;
  if ( !this->mValues.size )
    goto LABEL_5;
  v4 = this->mValues.p;
  v5 = name->mUID;
  v6 = this->mValues.p;
  while ( v6->mKey.mUID != v5 )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v6;
    if ( (unsigned int)v3 >= v2 )
      goto LABEL_5;
  }
  if ( (_DWORD)v3 != -1 )
    result = (unsigned int)v4[v3].mIntValue;
  else
LABEL_5:
    result = 0i64;
  return result;
}

// File Line: 507
// RVA: 0x4A41D0
__int64 __fastcall UFG::PersistentData::MapInt::GetInt(UFG::PersistentData::MapInt *this, unsigned int index)
{
  __int64 result; // rax

  if ( index >= this->mValues.size )
    result = 0i64;
  else
    result = (unsigned int)this->mValues.p[index].mIntValue;
  return result;
}

// File Line: 520
// RVA: 0x494360
void __fastcall UFG::PersistentData::MapInt::ApplyDelta(UFG::PersistentData::MapInt *this, UFG::qSymbol *name, int delta)
{
  __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebp
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::PersistentData::KeyValue *v7; // r9
  unsigned int v8; // er14
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PersistentData::KeyValue *v12; // rax

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = delta;
  v6 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v7 = this->mValues.p;
  while ( v7->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v7;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    this->mValues.p[v4].mIntValue += delta;
  }
  else
  {
LABEL_5:
    v8 = name->mUID;
    v9 = this->mValues.capacity;
    v10 = v3 + 1;
    if ( (signed int)v3 + 1 > v9 )
    {
      if ( v9 )
        v11 = 2 * v9;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 2 )
        v11 = 2;
      if ( v11 - v10 > 0x10000 )
        v11 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v11, "MapTypes");
    }
    v12 = v6->mValues.p;
    v6->mValues.size = v10;
    v12[v3].mKey.mUID = v8;
    v12[v3].mIntValue = v5;
    v12[v3].mBoolValue = v5;
  }
}

// File Line: 533
// RVA: 0x4A6E30
__int64 __fastcall UFG::PersistentData::MapInt::GetTotal(UFG::PersistentData::MapInt *this)
{
  unsigned int v1; // er11
  int v2; // edx
  UFG::PersistentData::MapInt *v3; // r10
  int v4; // er8
  float v5; // ebx
  unsigned int v6; // edi
  signed __int64 v7; // rcx
  int *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // r9

  v1 = this->mValues.size;
  v2 = 0;
  v3 = this;
  v4 = 0;
  v5 = 0.0;
  v6 = 0;
  v7 = 0i64;
  if ( (signed int)v1 >= 2 )
  {
    v8 = (int *)&v3->mValues.p[1].4;
    v9 = ((v1 - 2) >> 1) + 1;
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
  if ( v6 < v1 )
    v5 = v3->mValues.p[v7].mFloatValue;
  return (unsigned int)(LODWORD(v5) + v4 + v2);
}

// File Line: 546
// RVA: 0x4A5300
void __fastcall UFG::PersistentData::MapInt::GetMaxMin(UFG::PersistentData::MapInt *this, UFG::qSymbol **max, UFG::qSymbol **min)
{
  unsigned int v3; // er10
  UFG::qSymbol **v4; // rbx
  UFG::qSymbol **v5; // rdi
  UFG::PersistentData::MapInt *v6; // r9
  UFG::PersistentData::KeyValue *v7; // rax
  float v8; // er11
  unsigned int v9; // edx
  int v10; // esi
  signed __int64 v11; // r8
  UFG::PersistentData::KeyValue *v12; // rcx
  UFG::PersistentData::KeyValue *v13; // rcx

  v3 = this->mValues.size;
  v4 = min;
  v5 = max;
  v6 = this;
  if ( this->mValues.size )
  {
    v7 = this->mValues.p;
    if ( v3 == 1 )
    {
      *max = (UFG::qSymbol *)v7;
      *min = 0i64;
    }
    else
    {
      v8 = v7->mFloatValue;
      *min = (UFG::qSymbol *)v7;
      *max = (UFG::qSymbol *)v7;
      v9 = 1;
      v10 = LODWORD(v8);
      if ( v3 > 1 )
      {
        v11 = 1i64;
        do
        {
          v12 = v6->mValues.p;
          if ( v10 < v12[v11].mIntValue )
          {
            v10 = v12[v11].mIntValue;
            *v5 = (UFG::qSymbol *)&v12[v9];
          }
          v13 = v6->mValues.p;
          if ( SLODWORD(v8) > v13[v11].mIntValue )
          {
            v8 = v13[v11].mFloatValue;
            *v4 = (UFG::qSymbol *)&v13[v9];
          }
          ++v9;
          ++v11;
        }
        while ( v9 < v3 );
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
void __fastcall UFG::PersistentData::MapUInt64::SetStatus(UFG::PersistentData::MapUInt64 *this, UFG::qSymbol *name, unsigned __int64 status)
{
  __int64 v3; // rdi
  __int64 v4; // rax
  unsigned __int64 v5; // r14
  UFG::PersistentData::MapUInt64 *v6; // rsi
  UFG::PersistentData::KeyValue64 *v7; // rcx
  UFG::PersistentData::KeyValue64 *v8; // r9
  unsigned int v9; // ebp
  unsigned int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  signed __int64 v13; // rax

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = status;
  v6 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v7 = this->mValues.p;
  v8 = v7;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    v7[v4].mIntValue = status;
  }
  else
  {
LABEL_5:
    v9 = name->mUID;
    v10 = v6->mValues.capacity;
    v11 = v3 + 1;
    if ( (signed int)v3 + 1 > v10 )
    {
      if ( v10 )
        v12 = 2 * v10;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 - v11 > 0x10000 )
        v12 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue64,0>::Reallocate(&v6->mValues, v12, "MapTypes");
    }
    v6->mValues.size = v11;
    v13 = (signed __int64)&v6->mValues.p[v3];
    *(_DWORD *)v13 = v9;
    *(_QWORD *)(v13 + 8) = v5;
  }
}

// File Line: 737
// RVA: 0x4A5470
UFG::PersistentData::KeyValue *__fastcall UFG::PersistentData::MapFloat::Iterator::GetName(UFG::PersistentData::MapFloat::Iterator *this)
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
void __fastcall UFG::PersistentData::MapFloat::SetStatus(UFG::PersistentData::MapFloat *this, UFG::qSymbol *name, float status)
{
  __int64 v3; // rdi
  __int64 v4; // rax
  UFG::PersistentData::MapFloat *v5; // rsi
  UFG::PersistentData::KeyValue *v6; // rcx
  UFG::PersistentData::KeyValue *v7; // r8
  unsigned int v8; // ebp
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PersistentData::KeyValue *v12; // rcx

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v6 = this->mValues.p;
  v7 = v6;
  while ( v7->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v7;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    v6[v4].mFloatValue = status;
  }
  else
  {
LABEL_5:
    v8 = name->mUID;
    v9 = v5->mValues.capacity;
    v10 = v3 + 1;
    if ( (signed int)v3 + 1 > v9 )
    {
      if ( v9 )
        v11 = 2 * v9;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 <= 2 )
        v11 = 2;
      if ( v11 - v10 > 0x10000 )
        v11 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&v5->mValues, v11, "MapTypes");
    }
    v12 = v5->mValues.p;
    v5->mValues.size = v10;
    v12[v3].mKey.mUID = v8;
    v12[v3].mFloatValue = status;
    v12[v3].mBoolValue = LOBYTE(status);
  }
}

// File Line: 792
// RVA: 0x4A68B0
float __fastcall UFG::PersistentData::MapFloat::GetStatus(UFG::PersistentData::MapFloat *this, UFG::qSymbol *name)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::PersistentData::KeyValue *v4; // r9
  unsigned int v5; // edx
  UFG::PersistentData::KeyValue *v6; // rcx
  float result; // xmm0_4

  v2 = this->mValues.size;
  v3 = 0i64;
  if ( !this->mValues.size )
    goto LABEL_5;
  v4 = this->mValues.p;
  v5 = name->mUID;
  v6 = this->mValues.p;
  while ( v6->mKey.mUID != v5 )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v6;
    if ( (unsigned int)v3 >= v2 )
      goto LABEL_5;
  }
  if ( (_DWORD)v3 != -1 )
    result = v4[v3].mFloatValue;
  else
LABEL_5:
    result = 0.0;
  return result;
}

// File Line: 805
// RVA: 0x494270
void __fastcall UFG::PersistentData::MapFloat::ApplyDelta(UFG::PersistentData::MapFloat *this, UFG::qSymbol *name, float delta)
{
  __int64 v3; // rdi
  __int64 v4; // rax
  UFG::PersistentData::MapFloat *v5; // rsi
  UFG::PersistentData::KeyValue *v6; // r8
  unsigned int v7; // ebp
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  UFG::PersistentData::KeyValue *v11; // rcx

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v6 = this->mValues.p;
  while ( v6->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v6;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    this->mValues.p[v4].mFloatValue = delta + this->mValues.p[v4].mFloatValue;
  }
  else
  {
LABEL_5:
    v7 = name->mUID;
    v8 = this->mValues.capacity;
    v9 = v3 + 1;
    if ( (signed int)v3 + 1 > v8 )
    {
      if ( v8 )
        v10 = 2 * v8;
      else
        v10 = 1;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v9 > 0x10000 )
        v10 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v10, "MapTypes");
    }
    v11 = v5->mValues.p;
    v5->mValues.size = v9;
    v11[v3].mKey.mUID = v7;
    v11[v3].mFloatValue = delta;
    v11[v3].mBoolValue = LOBYTE(delta);
  }
}

// File Line: 818
// RVA: 0x4A5120
void __fastcall UFG::PersistentData::MapFloat::GetMaxMin(UFG::PersistentData::MapFloat *this, UFG::qSymbol **max, UFG::qSymbol **min)
{
  unsigned int v3; // esi
  UFG::qSymbol **v4; // rbx
  UFG::qSymbol **v5; // rdi
  UFG::PersistentData::MapFloat *v6; // r9
  UFG::PersistentData::KeyValue *v7; // rax
  float v8; // xmm0_4
  unsigned int v9; // edx
  signed __int64 v10; // r8
  float v11; // xmm1_4
  unsigned int v12; // er10
  UFG::PersistentData::KeyValue *v13; // rcx
  UFG::PersistentData::KeyValue *v14; // rcx
  UFG::PersistentData::KeyValue *v15; // r11
  UFG::PersistentData::KeyValue *v16; // r11
  UFG::PersistentData::KeyValue *v17; // rcx
  UFG::PersistentData::KeyValue *v18; // rcx
  UFG::PersistentData::KeyValue *v19; // r11
  UFG::PersistentData::KeyValue *v20; // r11
  signed __int64 v21; // r8
  UFG::PersistentData::KeyValue *v22; // rcx
  UFG::PersistentData::KeyValue *v23; // rcx

  v3 = this->mValues.size;
  v4 = min;
  v5 = max;
  v6 = this;
  if ( this->mValues.size >= 1 )
  {
    v7 = this->mValues.p;
    if ( v3 == 1 )
    {
      *max = (UFG::qSymbol *)v7;
      *min = 0i64;
    }
    else
    {
      v8 = v7->mFloatValue;
      *min = (UFG::qSymbol *)v7;
      *max = (UFG::qSymbol *)v7;
      v9 = 1;
      v10 = 1i64;
      v11 = v8;
      if ( v3 > 1 )
      {
        if ( (signed int)(v3 - 1) >= 4 )
        {
          v12 = 3;
          do
          {
            v13 = v6->mValues.p;
            if ( v11 < v13[v10].mFloatValue )
            {
              v11 = v13[v10].mFloatValue;
              *v5 = (UFG::qSymbol *)&v13[v9];
            }
            v14 = v6->mValues.p;
            if ( v8 > v14[v10].mFloatValue )
            {
              v8 = v14[v10].mFloatValue;
              *v4 = (UFG::qSymbol *)&v14[v9];
            }
            v15 = v6->mValues.p;
            if ( v11 < v15[v10 + 1].mFloatValue )
            {
              v11 = v15[v10 + 1].mFloatValue;
              *v5 = (UFG::qSymbol *)&v15[v12 - 1];
            }
            v16 = v6->mValues.p;
            if ( v8 > v16[v10 + 1].mFloatValue )
            {
              v8 = v16[v10 + 1].mFloatValue;
              *v4 = (UFG::qSymbol *)&v16[v12 - 1];
            }
            v17 = v6->mValues.p;
            if ( v11 < v17[v10 + 2].mFloatValue )
            {
              v11 = v17[v10 + 2].mFloatValue;
              *v5 = (UFG::qSymbol *)&v17[v12];
            }
            v18 = v6->mValues.p;
            if ( v8 > v18[v10 + 2].mFloatValue )
            {
              v8 = v18[v10 + 2].mFloatValue;
              *v4 = (UFG::qSymbol *)&v18[v12];
            }
            v19 = v6->mValues.p;
            if ( v11 < v19[v10 + 3].mFloatValue )
            {
              v11 = v19[v10 + 3].mFloatValue;
              *v5 = (UFG::qSymbol *)&v19[v12 + 1];
            }
            v20 = v6->mValues.p;
            if ( v8 > v20[v10 + 3].mFloatValue )
            {
              v8 = v20[v10 + 3].mFloatValue;
              *v4 = (UFG::qSymbol *)&v20[v12 + 1];
            }
            v9 += 4;
            v10 += 4i64;
            v12 += 4;
          }
          while ( v9 < v3 - 3 );
        }
        if ( v9 < v3 )
        {
          v21 = v10;
          do
          {
            v22 = v6->mValues.p;
            if ( v11 < v22[v21].mFloatValue )
            {
              v11 = v22[v21].mFloatValue;
              *v5 = (UFG::qSymbol *)&v22[v9];
            }
            v23 = v6->mValues.p;
            if ( v8 > v23[v21].mFloatValue )
            {
              v8 = v23[v21].mFloatValue;
              *v4 = (UFG::qSymbol *)&v23[v9];
            }
            ++v9;
            ++v21;
          }
          while ( v9 < v3 );
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
UFG::PersistentData::KeyBinary *__fastcall UFG::PersistentData::MapBinary::Iterator::GetName(UFG::PersistentData::MapBinary::Iterator *this)
{
  return &this->mList->mValues.p[this->mIndex];
}

// File Line: 880
// RVA: 0x4A1940
UFG::PersistentData::Binary *__fastcall UFG::PersistentData::MapBinary::Iterator::GetBinary(UFG::PersistentData::MapBinary::Iterator *this)
{
  return (UFG::PersistentData::Binary *)((char *)this->mList->mValues.p + 8 * (3i64 * this->mIndex + 1));
}

// File Line: 894
// RVA: 0x48CE70
void __fastcall UFG::PersistentData::MapBinary::MapBinary(UFG::PersistentData::MapBinary *this, UFG::PersistentData::MapBinary *src)
{
  UFG::PersistentData::MapBinary *v2; // rbp
  UFG::PersistentData::MapBinary *v3; // r14
  __int64 v4; // r15
  __int64 v5; // r12
  UFG::PersistentData::KeyBinary *v6; // rsi
  unsigned int v7; // edi
  UFG::allocator::free_link *v8; // rbx
  UFG::PersistentData::Binary binary; // [rsp+28h] [rbp-40h]

  v2 = src;
  v3 = this;
  v4 = 0i64;
  this->mValues.p = 0i64;
  *(_QWORD *)&this->mValues.size = 0i64;
  UFG::PersistentData::MapBinary::Clear(this);
  v3->mPersistentDataType = v2->mPersistentDataType;
  if ( v2->mValues.size )
  {
    v5 = v2->mValues.size;
    do
    {
      v6 = &v2->mValues.p[v4];
      v7 = v6->mBinary.mSize;
      v8 = UFG::qMalloc(v6->mBinary.mSize, "MapBinary", 0i64);
      UFG::qMemCopy(v8, v6->mBinary.mpBuffer, v7);
      binary.mpBuffer = v8;
      binary.mSize = v7;
      UFG::PersistentData::MapBinary::SetBinary(v3, &v6->mKey, &binary);
      ++v4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 916
// RVA: 0x4978A0
void __fastcall UFG::PersistentData::MapBinary::Clear(UFG::PersistentData::MapBinary *this)
{
  UFG::PersistentData::MapBinary *v1; // rsi
  __int64 v2; // rdi
  __int64 v3; // rbp
  UFG::PersistentData::KeyBinary *v4; // rbx
  UFG::PersistentData::KeyBinary *v5; // rcx
  unsigned int *v6; // rbx

  v1 = this;
  if ( this->mValues.size )
  {
    v2 = 0i64;
    v3 = this->mValues.size;
    do
    {
      v4 = v1->mValues.p;
      if ( v4[v2].mBinary.mSize > 0 )
        operator delete[](v4[v2].mBinary.mpBuffer);
      v4[v2].mBinary.mpBuffer = 0i64;
      v4[v2].mBinary.mSize = 0;
      ++v2;
      --v3;
    }
    while ( v3 );
  }
  v5 = v1->mValues.p;
  if ( v5 )
  {
    v6 = &v5[-1].mBinary.mSize;
    `eh vector destructor iterator'(v5, 0x18ui64, v5[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
    operator delete[](v6);
  }
  v1->mValues.p = 0i64;
  *(_QWORD *)&v1->mValues.size = 0i64;
}

// File Line: 926
// RVA: 0x4AD3F0
void __fastcall UFG::PersistentData::MapBinary::KeepLatest(UFG::PersistentData::MapBinary *this, unsigned int newsize)
{
  UFG::PersistentData::MapBinary *v2; // rbx
  unsigned int v3; // eax
  __int64 v4; // rsi
  UFG::PersistentData::KeyBinary *v5; // rdi
  signed int v6; // er8
  signed __int64 v7; // rdx
  UFG::PersistentData::KeyBinary *v8; // rcx

  v2 = this;
  v3 = this->mValues.size - newsize;
  if ( (signed int)v3 >= 1 )
  {
    v4 = v3;
    do
    {
      v5 = v2->mValues.p;
      if ( v5->mBinary.mSize > 0 )
        operator delete[](v5->mBinary.mpBuffer);
      v6 = 1;
      v5->mBinary.mpBuffer = 0i64;
      v5->mBinary.mSize = 0;
      if ( v2->mValues.size != 1 )
      {
        v7 = 1i64;
        do
        {
          ++v6;
          v8 = &v2->mValues.p[v7];
          ++v7;
          v8[-1].mKey.mUID = v8->mKey.mUID;
          v8[-1].mBinary.mpBuffer = v8->mBinary.mpBuffer;
          v8[-1].mBinary.mSize = v8->mBinary.mSize;
        }
        while ( v6 != v2->mValues.size );
      }
      if ( v2->mValues.size > 1 )
        --v2->mValues.size;
      else
        v2->mValues.size = 0;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 947
// RVA: 0x4BBBB0
void __fastcall UFG::PersistentData::MapBinary::SetBinary(UFG::PersistentData::MapBinary *this, UFG::qSymbol *name, UFG::PersistentData::Binary *binary)
{
  signed __int64 v3; // rdi
  signed __int64 v4; // rax
  UFG::PersistentData::Binary *v5; // rbx
  UFG::PersistentData::MapBinary *v6; // rsi
  UFG::PersistentData::KeyBinary *v7; // r15
  UFG::PersistentData::KeyBinary *v8; // r9
  unsigned int v9; // ebp
  unsigned int v10; // edx
  void *v11; // r14
  unsigned int v12; // er15
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // ebp
  void *v16; // r14
  signed __int64 v17; // rdi
  UFG::PersistentData::KeyBinary *v18; // rbx
  UFG::PersistentData::KeyBinary *v19; // rax
  signed __int64 v20; // rcx

  v3 = this->mValues.size;
  v4 = 0i64;
  v5 = binary;
  v6 = this;
  if ( !(_DWORD)v3 )
    goto LABEL_5;
  v7 = this->mValues.p;
  v8 = this->mValues.p;
  while ( v8->mKey.mUID != name->mUID )
  {
    v4 = (unsigned int)(v4 + 1);
    ++v8;
    if ( (unsigned int)v4 >= (unsigned int)v3 )
      goto LABEL_5;
  }
  if ( (_DWORD)v4 != -1 )
  {
    v15 = binary->mSize;
    v16 = binary->mpBuffer;
    v17 = v4;
    if ( v7[v4].mBinary.mSize )
      operator delete[](v7[v17].mBinary.mpBuffer);
    v7[v17].mBinary.mpBuffer = v16;
    v7[v17].mBinary.mSize = v15;
    if ( !v5->mpBuffer )
    {
      v18 = &v6->mValues.p[v17];
      if ( v18->mBinary.mSize )
        operator delete[](v18->mBinary.mpBuffer);
      v18->mBinary.mpBuffer = 0i64;
      v18->mBinary.mSize = 0;
    }
  }
  else
  {
LABEL_5:
    v9 = name->mUID;
    v10 = this->mValues.capacity;
    v11 = binary->mpBuffer;
    v12 = binary->mSize;
    v13 = v3 + 1;
    if ( (signed int)v3 + 1 > v10 )
    {
      if ( v10 )
        v14 = 2 * v10;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 - v13 > 0x10000 )
        v14 = v3 + 65537;
      UFG::qArray<UFG::PersistentData::KeyBinary,0>::Reallocate(&this->mValues, v14, "qArray.Add");
    }
    v19 = v6->mValues.p;
    v20 = v3;
    v6->mValues.size = v13;
    v19[v20].mKey.mUID = v9;
    v19[v20].mBinary.mpBuffer = v11;
    v19[v20].mBinary.mSize = v12;
  }
}

