// File Line: 56
// RVA: 0x49B0E0
void __fastcall UFG::PersistentData::MapBool::Deserialize(UFG::PersistentData::MapBool *this, char *pBuffer)
{
  UFG::PersistentData::MapBool::KeepType v2; // eax
  char *v3; // rdi
  bool v4; // zf
  unsigned int v5; // eax
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v6; // rsi
  __int64 v7; // r14
  __int64 v8; // rbp
  unsigned int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::PersistentData::KeyValue *v13; // rcx
  UFG::qArray<UFG::qSymbol,0> *v14; // rsi
  __int64 v15; // r14
  __int64 v16; // rbp
  unsigned int v17; // edx
  unsigned int v18; // er15
  unsigned int v19; // ebx
  unsigned int v20; // edx
  UFG::qSymbol *v21; // rax
  unsigned int dest; // [rsp+50h] [rbp+8h]
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
      v6 = &this->mValues;
      v7 = v5;
      do
      {
        v23 = 0;
        dest = UFG::gNullQSymbol.mUID;
        UFG::qMemCopy(&dest, v3, 8u);
        v8 = v6->size;
        v9 = v6->capacity;
        v10 = v8 + 1;
        if ( (signed int)v8 + 1 > v9 )
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
            v11 = v8 + 65537;
          UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(v6, v11, "MapTypes");
        }
        v12 = dest;
        v13 = v6->p;
        v6->size = v10;
        v13[v8].mKey.mUID = v12;
        v3 += 8;
        v13[v8].mIntValue = v23;
        v13[v8].mIntValue = v23;
        v13[v8].mBoolValue = v23;
        --v7;
      }
      while ( v7 );
    }
  }
  else if ( v5 )
  {
    v14 = &this->mNames;
    v15 = *((unsigned int *)pBuffer + 1);
    do
    {
      v16 = v14->size;
      v17 = v14->capacity;
      v18 = *(_DWORD *)v3;
      v19 = v16 + 1;
      if ( (signed int)v16 + 1 > v17 )
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
        UFG::qArray<UFG::qSymbol,0>::Reallocate(v14, v20, "MapTypes");
      }
      v21 = v14->p;
      v3 += 4;
      v14->size = v19;
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
  UFG::PersistentData::MapUInt64 *v2; // rsi
  char *v3; // rdi
  __int64 v4; // r14
  __int64 v5; // rbp
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // eax
  signed __int64 v10; // rcx
  unsigned int dest; // [rsp+20h] [rbp-28h]
  __int64 v12; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = pBuffer + 8;
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      v12 = 0i64;
      dest = UFG::gNullQSymbol.mUID;
      UFG::qMemCopy(&dest, v3, 0x10u);
      v5 = v2->mValues.size;
      v6 = v2->mValues.capacity;
      v7 = v5 + 1;
      if ( (signed int)v5 + 1 > v6 )
      {
        if ( v6 )
          v8 = 2 * v6;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 - v7 > 0x10000 )
          v8 = v5 + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue64,0>::Reallocate(&v2->mValues, v8, "MapTypes");
      }
      v9 = dest;
      v2->mValues.size = v7;
      v3 += 16;
      v10 = (signed __int64)&v2->mValues.p[v5];
      *(_DWORD *)v10 = v9;
      *(_QWORD *)(v10 + 8) = v12;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 180
// RVA: 0x49B260
void __fastcall UFG::PersistentData::MapInt::Deserialize(UFG::PersistentData::MapInt *this, char *pBuffer)
{
  UFG::PersistentData::MapInt *v2; // rdi
  char *v3; // rsi
  __int64 v4; // r14
  __int64 v5; // rbp
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // eax
  UFG::PersistentData::KeyValue *v10; // rcx
  unsigned int dest; // [rsp+58h] [rbp+10h]
  int v12; // [rsp+5Ch] [rbp+14h]

  v2 = this;
  v3 = pBuffer + 4;
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      v12 = 0;
      dest = UFG::gNullQSymbol.mUID;
      UFG::qMemCopy(&dest, v3, 8u);
      v5 = v2->mValues.size;
      v6 = v2->mValues.capacity;
      v7 = v5 + 1;
      if ( (signed int)v5 + 1 > v6 )
      {
        if ( v6 )
          v8 = 2 * v6;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 <= 2 )
          v8 = 2;
        if ( v8 - v7 > 0x10000 )
          v8 = v5 + 65537;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Reallocate(&v2->mValues, v8, "MapTypes");
      }
      v9 = dest;
      v10 = v2->mValues.p;
      v2->mValues.size = v7;
      v10[v5].mKey.mUID = v9;
      v3 += 8;
      v10[v5].mIntValue = v12;
      v10[v5].mIntValue = v12;
      v10[v5].mBoolValue = v12;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 208
// RVA: 0x4BA230
void __fastcall UFG::PersistentData::MapBinary::Serialize(UFG::PersistentData::MapBinary *this, char **ppBuffer)
{
  void **v2; // rbx
  UFG::PersistentData::MapBinary *v3; // r14
  __int64 v4; // rdi
  __int64 v5; // rsi
  UFG::PersistentData::KeyBinary *v6; // rax
  unsigned int v7; // ebp

  v2 = (void **)ppBuffer;
  *(_DWORD *)*ppBuffer = this->mValues.size;
  *v2 = (char *)*v2 + 4;
  v3 = this;
  if ( this->mValues.size )
  {
    v4 = 0i64;
    v5 = this->mValues.size;
    do
    {
      *(_DWORD *)*v2 = v3->mValues.p[v4].mKey.mUID;
      *v2 = (char *)*v2 + 4;
      v6 = v3->mValues.p;
      v7 = v6[v4].mBinary.mSize;
      *(_DWORD *)*v2 = v7;
      *v2 = (char *)*v2 + 4;
      if ( v7 )
      {
        UFG::qMemCopy(*v2, v6[v4].mBinary.mpBuffer, v7);
        *v2 = (char *)*v2 + ((v7 + 3) & 0xFFFFFFFC);
      }
      ++v4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 222
// RVA: 0x49B010
void __fastcall UFG::PersistentData::MapBinary::Deserialize(UFG::PersistentData::MapBinary *this, char *pBuffer)
{
  UFG::PersistentData::MapBinary *v2; // r14
  unsigned int *v3; // rbx
  __int64 v4; // rbp
  unsigned int v5; // esi
  signed __int64 v6; // rbx
  unsigned int v7; // edi
  UFG::allocator::free_link *v8; // rdi
  UFG::PersistentData::Binary binary; // [rsp+20h] [rbp-28h]
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]

  v2 = this;
  v3 = (unsigned int *)(pBuffer + 4);
  if ( *(_DWORD *)pBuffer )
  {
    v4 = *(unsigned int *)pBuffer;
    do
    {
      UFG::qSymbol::qSymbol(&result, *v3);
      v5 = v3[1];
      v6 = (signed __int64)(v3 + 1);
      binary.mpBuffer = 0i64;
      v7 = 0;
      binary.mSize = 0;
      if ( v5 )
      {
        v8 = UFG::qMalloc(v5, "Binary", 0i64);
        UFG::qMemCopy(v8, (const void *)(v6 + 4), v5);
        binary.mpBuffer = v8;
        v7 = v5;
        binary.mSize = v5;
      }
      UFG::PersistentData::MapBinary::SetBinary(v2, (UFG::qSymbol *)&result, &binary);
      v3 = (unsigned int *)(((v7 + 3) & 0xFFFFFFFC) + 4 + v6);
      --v4;
    }
    while ( v4 );
  }
}

