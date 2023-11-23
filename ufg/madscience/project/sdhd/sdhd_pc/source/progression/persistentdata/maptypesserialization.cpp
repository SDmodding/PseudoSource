// File Line: 56
// RVA: 0x49B0E0
void __fastcall UFG::PersistentData::MapBool::Deserialize(UFG::PersistentData::MapBool *this, char *pBuffer)
{
  int v2; // eax
  char *v3; // rdi
  bool v4; // zf
  unsigned int v5; // eax
  UFG::qArray<UFG::PersistentData::KeyValue,0> *p_mValues; // rsi
  __int64 v7; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::PersistentData::KeyValue *p; // rcx
  UFG::qArray<UFG::qSymbol,0> *p_mNames; // rsi
  __int64 v15; // r14
  __int64 v16; // rbp
  unsigned int v17; // edx
  unsigned int v18; // r15d
  unsigned int v19; // ebx
  unsigned int v20; // edx
  UFG::qSymbol *v21; // rax
  unsigned int dest; // [rsp+50h] [rbp+8h] BYREF
  int v23; // [rsp+54h] [rbp+Ch]

  v2 = *(_DWORD *)pBuffer;
  v3 = pBuffer + 8;
  this->mKeepType = *(_DWORD *)pBuffer;
  v4 = v2 == 0;
  v5 = *((_DWORD *)pBuffer + 1);
  if ( v4 )
  {
    if ( v5 )
    {
      p_mValues = &this->mValues;
      v7 = v5;
      do
      {
        v23 = 0;
        dest = UFG::gNullQSymbol.mUID;
        UFG::qMemCopy(&dest, v3, 8u);
        size = p_mValues->size;
        capacity = p_mValues->capacity;
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
          UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(p_mValues, v11, "MapTypes");
        }
        v12 = dest;
        p = p_mValues->p;
        p_mValues->size = v10;
        p[size].mKey.mUID = v12;
        v3 += 8;
        p[size].mIntValue = v23;
        p[size].mIntValue = v23;
        p[size].mBoolValue = v23;
        --v7;
      }
      while ( v7 );
    }
  }
  else if ( v5 )
  {
    p_mNames = &this->mNames;
    v15 = *((unsigned int *)pBuffer + 1);
    do
    {
      v16 = p_mNames->size;
      v17 = p_mNames->capacity;
      v18 = *(_DWORD *)v3;
      v19 = v16 + 1;
      if ( (int)v16 + 1 > v17 )
      {
        if ( v17 )
          v20 = 2 * v17;
        else
          v20 = 1;
        for ( ; v20 < v19; v20 *= 2 )
          ;
        if ( v20 <= 4 )
          v20 = 4;
        if ( v20 - v19 > 0x10000 )
          v20 = v16 + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mNames, v20, "MapTypes");
      }
      v21 = p_mNames->p;
      v3 += 4;
      p_mNames->size = v19;
      v21[v16].mUID = v18;
      --v15;
    }
    while ( v15 );
  }
}

// File Line: 145
// RVA: 0x49B370
void __fastcall UFG::PersistentData::MapUInt64::Deserialize(UFG::PersistentData::MapUInt64 *this, char *pBuffer)
{
  char *v3; // rdi
  __int64 v4; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // eax
  UFG::PersistentData::KeyValue64 *v10; // rcx
  unsigned int dest; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int64 v12; // [rsp+28h] [rbp-20h]

  v3 = pBuffer + 8;
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      v12 = 0i64;
      dest = UFG::gNullQSymbol.mUID;
      UFG::qMemCopy(&dest, v3, 0x10u);
      size = this->mValues.size;
      capacity = this->mValues.capacity;
      v7 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v8 = 2 * capacity;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 - v7 > 0x10000 )
          v8 = size + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue64,0>::Reallocate(&this->mValues, v8, "MapTypes");
      }
      v9 = dest;
      this->mValues.size = v7;
      v3 += 16;
      v10 = &this->mValues.p[size];
      v10->mKey.mUID = v9;
      v10->mIntValue = v12;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 180
// RVA: 0x49B260
void __fastcall UFG::PersistentData::MapInt::Deserialize(UFG::PersistentData::MapInt *this, char *pBuffer)
{
  char *v3; // rsi
  __int64 v4; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // eax
  UFG::PersistentData::KeyValue *p; // rcx
  unsigned int dest; // [rsp+58h] [rbp+10h] BYREF
  int v12; // [rsp+5Ch] [rbp+14h]

  v3 = pBuffer + 4;
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      v12 = 0;
      dest = UFG::gNullQSymbol.mUID;
      UFG::qMemCopy(&dest, v3, 8u);
      size = this->mValues.size;
      capacity = this->mValues.capacity;
      v7 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v8 = 2 * capacity;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 <= 2 )
          v8 = 2;
        if ( v8 - v7 > 0x10000 )
          v8 = size + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&this->mValues, v8, "MapTypes");
      }
      v9 = dest;
      p = this->mValues.p;
      this->mValues.size = v7;
      p[size].mKey.mUID = v9;
      v3 += 8;
      p[size].mIntValue = v12;
      p[size].mIntValue = v12;
      p[size].mBoolValue = v12;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 208
// RVA: 0x4BA230
void __fastcall UFG::PersistentData::MapBinary::Serialize(UFG::PersistentData::MapBinary *this, char **ppBuffer)
{
  __int64 v4; // rdi
  __int64 size; // rsi
  UFG::PersistentData::KeyBinary *p; // rax
  unsigned int mSize; // ebp

  *(_DWORD *)*ppBuffer = this->mValues.size;
  *ppBuffer += 4;
  if ( this->mValues.size )
  {
    v4 = 0i64;
    size = this->mValues.size;
    do
    {
      *(_DWORD *)*ppBuffer = this->mValues.p[v4].mKey.mUID;
      *ppBuffer += 4;
      p = this->mValues.p;
      mSize = p[v4].mBinary.mSize;
      *(_DWORD *)*ppBuffer = mSize;
      *ppBuffer += 4;
      if ( mSize )
      {
        UFG::qMemCopy(*ppBuffer, p[v4].mBinary.mpBuffer, mSize);
        *ppBuffer += (mSize + 3) & 0xFFFFFFFC;
      }
      ++v4;
      --size;
    }
    while ( size );
  }
}

// File Line: 222
// RVA: 0x49B010
void __fastcall UFG::PersistentData::MapBinary::Deserialize(UFG::PersistentData::MapBinary *this, char *pBuffer)
{
  unsigned int *v3; // rbx
  __int64 v4; // rbp
  unsigned int v5; // esi
  unsigned int *v6; // rbx
  unsigned int v7; // edi
  UFG::allocator::free_link *v8; // rdi
  UFG::PersistentData::Binary binary; // [rsp+20h] [rbp-28h] BYREF
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF

  v3 = (unsigned int *)(pBuffer + 4);
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      UFG::qSymbol::qSymbol(&result, *v3);
      v5 = v3[1];
      v6 = v3 + 1;
      binary.mpBuffer = 0i64;
      v7 = 0;
      binary.mSize = 0;
      if ( v5 )
      {
        v8 = UFG::qMalloc(v5, "Binary", 0i64);
        UFG::qMemCopy(v8, v6 + 1, v5);
        binary.mpBuffer = v8;
        v7 = v5;
        binary.mSize = v5;
      }
      UFG::PersistentData::MapBinary::SetBinary(this, (UFG::qSymbol *)&result, &binary);
      v3 = (unsigned int *)((char *)v6 + ((v7 + 3) & 0xFFFFFFFC) + 4);
      --v4;
    }
    while ( v4 );
  }
}

