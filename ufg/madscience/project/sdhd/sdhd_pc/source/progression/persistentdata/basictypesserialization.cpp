// File Line: 190
// RVA: 0x4BA080
void __fastcall UFG::PersistentData::List::Serialize(UFG::PersistentData::List *this, char **ppBuffer)
{
  UFG::qArray<long,0> *mIntList; // rdx
  __int64 v4; // rdi
  UFG::PersistentData::ListType mType; // r8d
  unsigned int size; // edx
  __int32 v8; // ecx
  __int32 v9; // ecx
  _DWORD *v10; // r9
  __int64 v11; // rbp
  __int64 v12; // rbp
  _DWORD *v13; // rcx
  __int64 v14; // rbp
  __int64 v15; // rbp
  __int64 source; // [rsp+30h] [rbp+8h] BYREF

  mIntList = this->mIntList;
  v4 = 0i64;
  if ( mIntList || (mType = this->mType) != LT_NONE )
  {
    mType = this->mType;
    v8 = this->mType - 1;
    if ( v8 && (v9 = v8 - 1) != 0 && (unsigned int)(v9 - 1) >= 2 )
      size = 0;
    else
      size = mIntList->size;
  }
  else
  {
    size = 0;
  }
  *(_DWORD *)*ppBuffer = mType;
  *ppBuffer += 4;
  *(_DWORD *)*ppBuffer = size;
  *ppBuffer += 4;
  v10 = *ppBuffer;
  if ( size )
  {
    switch ( this->mType )
    {
      case LT_BOOL:
        v15 = size;
        do
        {
          LODWORD(source) = *((unsigned __int8 *)this->mIntList->p + v4);
          UFG::qMemCopy(v10, &source, 4u);
          *ppBuffer += 4;
          v10 = *ppBuffer;
          ++v4;
          --v15;
        }
        while ( v15 );
        break;
      case LT_INT:
        v14 = size;
        do
        {
          LODWORD(source) = *(int *)((char *)this->mIntList->p + v4);
          UFG::qMemCopy(v10, &source, 4u);
          *ppBuffer += 4;
          v10 = *ppBuffer;
          v4 += 4i64;
          --v14;
        }
        while ( v14 );
        break;
      case LT_INT64:
        v12 = size;
        do
        {
          v13 = *ppBuffer;
          source = *(_QWORD *)((char *)this->mIntList->p + v4);
          UFG::qMemCopy(v13, &source, 8u);
          *ppBuffer += 8;
          v4 += 8i64;
          --v12;
        }
        while ( v12 );
        break;
      case LT_FLOAT:
        v11 = size;
        do
        {
          LODWORD(source) = *(int *)((char *)this->mIntList->p + v4);
          UFG::qMemCopy(v10, &source, 4u);
          *ppBuffer += 4;
          v10 = *ppBuffer;
          v4 += 4i64;
          --v11;
        }
        while ( v11 );
        break;
    }
  }
}

// File Line: 237
// RVA: 0x49AC20
void __fastcall UFG::PersistentData::List::Deserialize(UFG::PersistentData::List *this, char *pBuffer)
{
  int v3; // ecx
  char *v4; // rdi
  __int64 v5; // rbp
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  UFG::qArray<long,0> *mIntList; // r12
  unsigned int v10; // esi
  unsigned int size; // ecx
  int v12; // eax
  unsigned int capacity; // ebx
  unsigned int v14; // r15d
  unsigned int v15; // ebx
  unsigned int v16; // eax
  __int64 v17; // rdx
  unsigned int v18; // eax
  __int64 v19; // r8
  __int64 v20; // rdx
  __int64 v21; // r8
  UFG::qArray<long,0> *v22; // r12
  __int64 v23; // rsi
  unsigned int v24; // ecx
  int v25; // eax
  unsigned int v26; // ebx
  unsigned int v27; // r15d
  unsigned int v28; // ebx
  unsigned int v29; // eax
  __int64 v30; // rdx
  UFG::qArray<long,0> *v31; // r12
  __int64 v32; // rsi
  unsigned int v33; // ecx
  int v34; // eax
  unsigned int v35; // ebx
  unsigned int v36; // r15d
  unsigned int v37; // ebx
  unsigned int v38; // eax
  __int64 v39; // rdx
  UFG::qArray<long,0> *v40; // r15
  __int64 v41; // rsi
  unsigned int v42; // ecx
  int v43; // eax
  unsigned int v44; // ebx
  unsigned int v45; // r13d
  unsigned int v46; // ebx
  UFG::allocator::free_link *v47; // rax
  int *v48; // r12
  unsigned int i; // r9d
  __int64 v50; // r8
  unsigned int v51; // eax
  __int64 v52; // r8
  bool v53; // dl

  v3 = *(_DWORD *)pBuffer;
  v4 = pBuffer + 8;
  this->mType = *(_DWORD *)pBuffer;
  v5 = *((unsigned int *)pBuffer + 1);
  if ( (_DWORD)v5 )
  {
    v6 = v3 - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        v8 = v7 - 1;
        if ( v8 )
        {
          if ( v8 == 1 )
          {
            mIntList = this->mIntList;
            v10 = 0;
            size = mIntList->size;
            v12 = v5 - mIntList->size;
            if ( v12 <= 0 )
            {
              v16 = mIntList->size - v5;
              if ( v16 )
              {
                if ( v16 < size )
                  mIntList->size = size - v16;
                else
                  mIntList->size = 0;
              }
            }
            else
            {
              capacity = mIntList->capacity;
              v14 = size + v12;
              if ( size + v12 > capacity )
              {
                if ( capacity )
                  v15 = 2 * capacity;
                else
                  v15 = 1;
                for ( ; v15 < v14; v15 *= 2 )
                  ;
                if ( v15 <= 4 )
                  v15 = 4;
                if ( v15 - v14 > 0x10000 )
                  v15 = v14 + 0x10000;
                UFG::qArray<float,0>::Reallocate(this->mFloatList, v15, "qArray.Reallocate(Resize)");
              }
              mIntList->size = v14;
            }
            v17 = 0i64;
            if ( (int)v5 >= 4 )
            {
              v18 = ((unsigned int)(v5 - 4) >> 2) + 1;
              v19 = v18;
              v10 = 4 * v18;
              do
              {
                v17 += 4i64;
                v4 += 16;
                this->mIntList->p[v17 - 4] = *((_DWORD *)v4 - 4);
                this->mIntList->p[v17 - 3] = *((_DWORD *)v4 - 3);
                this->mIntList->p[v17 - 2] = *((_DWORD *)v4 - 2);
                this->mIntList->p[v17 - 1] = *((_DWORD *)v4 - 1);
                --v19;
              }
              while ( v19 );
            }
            if ( v10 < (unsigned int)v5 )
            {
              v20 = v17;
              v21 = (unsigned int)v5 - v10;
              do
              {
                ++v20;
                v4 += 4;
                this->mIntList->p[v20 - 1] = *((_DWORD *)v4 - 1);
                --v21;
              }
              while ( v21 );
            }
          }
        }
        else
        {
          v22 = this->mIntList;
          v23 = 0i64;
          v24 = v22->size;
          v25 = v5 - v22->size;
          if ( v25 <= 0 )
          {
            v29 = v22->size - v5;
            if ( v29 )
            {
              if ( v29 < v24 )
                v22->size = v24 - v29;
              else
                v22->size = 0;
            }
          }
          else
          {
            v26 = v22->capacity;
            v27 = v24 + v25;
            if ( v24 + v25 > v26 )
            {
              if ( v26 )
                v28 = 2 * v26;
              else
                v28 = 1;
              for ( ; v28 < v27; v28 *= 2 )
                ;
              if ( v28 <= 2 )
                v28 = 2;
              if ( v28 - v27 > 0x10000 )
                v28 = v27 + 0x10000;
              UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->mIntList,
                v28,
                "qArray.Reallocate(Resize)");
            }
            v22->size = v27;
          }
          v30 = v5;
          do
          {
            v23 += 2i64;
            v4 += 8;
            *(_QWORD *)&this->mIntList->p[v23 - 2] = *((_QWORD *)v4 - 1);
            --v30;
          }
          while ( v30 );
        }
      }
      else
      {
        v31 = this->mIntList;
        v32 = 0i64;
        v33 = v31->size;
        v34 = v5 - v31->size;
        if ( v34 <= 0 )
        {
          v38 = v31->size - v5;
          if ( v38 )
          {
            if ( v38 < v33 )
              v31->size = v33 - v38;
            else
              v31->size = 0;
          }
        }
        else
        {
          v35 = v31->capacity;
          v36 = v33 + v34;
          if ( v33 + v34 > v35 )
          {
            if ( v35 )
              v37 = 2 * v35;
            else
              v37 = 1;
            for ( ; v37 < v36; v37 *= 2 )
              ;
            if ( v37 <= 4 )
              v37 = 4;
            if ( v37 - v36 > 0x10000 )
              v37 = v36 + 0x10000;
            UFG::qArray<long,0>::Reallocate(
              (UFG::qArray<unsigned long,0> *)this->mIntList,
              v37,
              "qArray.Reallocate(Resize)");
          }
          v31->size = v36;
        }
        v39 = v5;
        do
        {
          ++v32;
          v4 += 4;
          this->mIntList->p[v32 - 1] = *((_DWORD *)v4 - 1);
          --v39;
        }
        while ( v39 );
      }
    }
    else
    {
      v40 = this->mIntList;
      v41 = 0i64;
      v42 = v40->size;
      v43 = v5 - v40->size;
      if ( v43 <= 0 )
      {
        v51 = v40->size - v5;
        if ( v51 )
        {
          if ( v51 < v42 )
            v40->size = v42 - v51;
          else
            v40->size = 0;
        }
      }
      else
      {
        v44 = v40->capacity;
        v45 = v42 + v43;
        if ( v42 + v43 > v44 )
        {
          if ( v44 )
            v46 = 2 * v44;
          else
            v46 = 1;
          for ( ; v46 < v45; v46 *= 2 )
            ;
          if ( v46 <= 0x10 )
            v46 = 16;
          if ( v46 - v45 > 0x10000 )
            v46 = v45 + 0x10000;
          if ( v46 != v42 )
          {
            v47 = UFG::qMalloc(v46, "qArray.Reallocate(Resize)", 0i64);
            v48 = (int *)v47;
            if ( v40->p )
            {
              for ( i = 0; i < v40->size; *((_BYTE *)&v47->mNext + v50) = *((_BYTE *)v40->p + v50) )
                v50 = i++;
              operator delete[](v40->p);
            }
            v40->p = v48;
            v40->capacity = v46;
          }
        }
        v40->size = v45;
      }
      v52 = v5;
      do
      {
        ++v41;
        v53 = *(_DWORD *)v4 != 0;
        v4 += 4;
        *((_BYTE *)this->mIntList->p + v41 - 1) = v53;
        --v52;
      }
      while ( v52 );
    }
  }
}

