// File Line: 130
// RVA: 0x259C20
UFG::allocator::free_link *__fastcall antlr3HashTableNew(unsigned int sizeHint)
{
  __int64 v1; // rsi
  UFG::allocator::free_link *result; // rax
  ANTLR3_HASH_TABLE_struct *v3; // rbx
  __int64 v4; // rdi
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rcx

  v1 = sizeHint;
  result = antlrMalloc(0x68ui64);
  v3 = (ANTLR3_HASH_TABLE_struct *)result;
  if ( result )
  {
    v4 = v1;
    v5 = antlrMalloc(8 * v1);
    v3->buckets = (ANTLR3_HASH_BUCKET_struct *)v5;
    if ( v5 )
    {
      v3->modulo = v1;
      v3->count = 0;
      if ( (_DWORD)v1 )
      {
        v6 = 0i64;
        do
        {
          ++v6;
          v3->buckets[v6 - 1].entries = 0i64;
          --v4;
        }
        while ( v4 );
      }
      v3->allowDups = 0;
      v3->get = antlr3HashGet;
      v3->doStrdup = 1;
      v3->put = (int (__fastcall *)(ANTLR3_HASH_TABLE_struct *, void *, void *, void (__fastcall *)(void *)))antlr3HashPut;
      v3->del = antlr3HashDelete;
      v3->remove = antlr3HashRemove;
      v3->getI = antlr3HashGetI;
      v3->putI = (int (__fastcall *)(ANTLR3_HASH_TABLE_struct *, unsigned __int64, void *, void (__fastcall *)(void *)))antlr3HashPutI;
      v3->delI = antlr3HashDeleteI;
      v3->removeI = antlr3HashRemoveI;
      v3->size = (unsigned int (__fastcall *)(ANTLR3_HASH_TABLE_struct *))hkaMatrix<float>::Height;
      v3->free = antlr3HashFree;
      result = (UFG::allocator::free_link *)v3;
    }
    else
    {
      antlrFree(v3);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 199
// RVA: 0x2586E0
void __fastcall antlr3HashFree(ANTLR3_HASH_TABLE_struct *table)
{
  ANTLR3_HASH_TABLE_struct *v1; // rbp
  unsigned int v2; // esi
  void **v3; // r14
  _QWORD *v4; // rbx
  void (__fastcall *v5)(_QWORD); // rax
  _QWORD *v6; // rdi
  void *v7; // rcx

  v1 = table;
  if ( table )
  {
    v2 = 0;
    if ( table->modulo )
    {
      do
      {
        v3 = (void **)&v1->buckets[v2].entries;
        if ( v3 )
        {
          v4 = *v3;
          if ( *v3 )
          {
            do
            {
              v5 = (void (__fastcall *)(_QWORD))v4[3];
              v6 = (_QWORD *)v4[4];
              if ( v5 )
                v5(v4[2]);
              if ( *(_BYTE *)v4 == 1 )
              {
                v7 = (void *)v4[1];
                if ( v7 )
                  antlrFree(v7);
              }
              antlrFree(v4);
              v4 = v6;
            }
            while ( v6 );
          }
          *v3 = 0i64;
        }
        ++v2;
      }
      while ( v2 < v1->modulo );
    }
    antlrFree(v1->buckets);
  }
  antlrFree(v1);
}

// File Line: 270
// RVA: 0x258BB0
__int64 __fastcall hkaMatrix<float>::Height(hkaMatrix<float> *this)
{
  return (unsigned int)this->m_m;
}

// File Line: 278
// RVA: 0x258B60
ANTLR3_HASH_ENTRY_struct *__fastcall antlr3HashRemoveI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key)
{
  ANTLR3_HASH_BUCKET_struct *v2; // r9
  ANTLR3_HASH_ENTRY_struct *result; // rax

  v2 = &table->buckets[key % table->modulo];
  result = v2->entries;
  if ( !v2->entries )
    return 0i64;
  while ( result->keybase.key.iKey != key )
  {
    v2 = (ANTLR3_HASH_BUCKET_struct *)&result->nextEntry;
    result = result->nextEntry;
    if ( !result )
      return 0i64;
  }
  v2->entries = result->nextEntry;
  --table->count;
  return result;
}

// File Line: 335
// RVA: 0x258A80
ANTLR3_HASH_ENTRY_struct *__fastcall antlr3HashRemove(ANTLR3_HASH_TABLE_struct *table, void *key)
{
  unsigned __int8 *v2; // r10
  ANTLR3_HASH_TABLE_struct *v3; // rdi
  signed __int64 v4; // r8
  unsigned int i; // er9
  int v6; // eax
  __int64 v7; // rdx
  ANTLR3_HASH_BUCKET_struct *v8; // rax
  ANTLR3_HASH_ENTRY_struct *v9; // rbx
  ANTLR3_HASH_BUCKET_struct *v10; // r9
  unsigned __int8 *v11; // rax
  int v12; // ecx
  int v13; // edx

  v2 = (unsigned __int8 *)key;
  v3 = table;
  v4 = -1i64;
  do
    ++v4;
  while ( *((_BYTE *)key + v4) );
  for ( i = 0; (_DWORD)v4; LODWORD(v4) = v4 - 1 )
  {
    v6 = *(unsigned __int8 *)key;
    key = (char *)key + 1;
    i = v6 + 16 * i;
    if ( i & 0xF0000000 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  v7 = i % table->modulo;
  v8 = table->buckets;
  v9 = v8[v7].entries;
  v10 = &v8[(unsigned int)v7];
  if ( !v9 )
    return 0i64;
  while ( 1 )
  {
    v11 = v2;
    do
    {
      v12 = v11[v9->keybase.key.iKey - (_QWORD)v2];
      v13 = *v11 - v12;
      if ( *v11 != v12 )
        break;
      ++v11;
    }
    while ( v12 );
    if ( !v13 )
      break;
    v10 = (ANTLR3_HASH_BUCKET_struct *)&v9->nextEntry;
    v9 = v9->nextEntry;
    if ( !v9 )
      return 0i64;
  }
  v10->entries = v9->nextEntry;
  if ( v3->doStrdup == 1 )
    antlrFree(v9->keybase.key.sKey);
  v9->keybase.key.iKey = 0i64;
  --v3->count;
  return v9;
}

// File Line: 400
// RVA: 0x258660
void __fastcall antlr3HashDeleteI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key)
{
  ANTLR3_HASH_BUCKET_struct *v2; // r9
  ANTLR3_HASH_ENTRY_struct *v3; // rbx
  void (__fastcall *v4)(void *); // rax

  v2 = &table->buckets[key % table->modulo];
  v3 = v2->entries;
  if ( !v2->entries )
  {
LABEL_4:
    v3 = 0i64;
LABEL_5:
    antlrFree(v3);
    return;
  }
  while ( v3->keybase.key.iKey != key )
  {
    v2 = (ANTLR3_HASH_BUCKET_struct *)&v3->nextEntry;
    v3 = v3->nextEntry;
    if ( !v3 )
      goto LABEL_4;
  }
  v2->entries = v3->nextEntry;
  --table->count;
  v4 = v3->free;
  if ( !v4 )
    goto LABEL_5;
  v4(v3->data);
  v3->data = 0i64;
  antlrFree(v3);
}

// File Line: 424
// RVA: 0x258620
void __fastcall antlr3HashDelete(ANTLR3_HASH_TABLE_struct *table, void *key)
{
  ANTLR3_HASH_ENTRY_struct *v2; // rax
  ANTLR3_HASH_ENTRY_struct *v3; // rbx
  void (__fastcall *v4)(void *); // rax

  v2 = antlr3HashRemove(table, key);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2->free;
    if ( v4 )
    {
      v4(v3->data);
      v3->data = 0i64;
    }
  }
  antlrFree(v3);
}

// File Line: 448
// RVA: 0x258850
void *__fastcall antlr3HashGetI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key)
{
  ANTLR3_HASH_ENTRY_struct *v2; // rax

  v2 = table->buckets[key % table->modulo].entries;
  if ( !v2 )
    return 0i64;
  while ( v2->keybase.key.iKey != key )
  {
    v2 = v2->nextEntry;
    if ( !v2 )
      return 0i64;
  }
  return v2->data;
}

// File Line: 487
// RVA: 0x2587B0
void *__fastcall antlr3HashGet(ANTLR3_HASH_TABLE_struct *table, void *key)
{
  unsigned __int8 *v2; // r10
  signed __int64 v3; // r8
  unsigned int i; // er9
  int v5; // eax
  ANTLR3_HASH_ENTRY_struct *v6; // r9
  unsigned __int8 *v7; // rax
  int v8; // ecx
  int v9; // edx

  v2 = (unsigned __int8 *)key;
  v3 = -1i64;
  do
    ++v3;
  while ( *((_BYTE *)key + v3) );
  for ( i = 0; (_DWORD)v3; LODWORD(v3) = v3 - 1 )
  {
    v5 = *(unsigned __int8 *)key;
    key = (char *)key + 1;
    i = v5 + 16 * i;
    if ( i & 0xF0000000 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  v6 = table->buckets[i % table->modulo].entries;
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v7 = v2;
    do
    {
      v8 = v7[v6->keybase.key.iKey - (_QWORD)v2];
      v9 = *v7 - v8;
      if ( *v7 != v8 )
        break;
      ++v7;
    }
    while ( v8 );
    if ( !v9 )
      break;
    v6 = v6->nextEntry;
    if ( !v6 )
      return 0i64;
  }
  return v6->data;
}

// File Line: 527
// RVA: 0x2589C0
signed __int64 __fastcall antlr3HashPutI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key, void *element, void (__fastcall *freeptr)(void *))
{
  unsigned __int128 v4; // di
  void (__fastcall *v5)(void *); // rbp
  UFG::allocator::free_link *v6; // r14
  ANTLR3_HASH_BUCKET_struct *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  signed __int64 result; // rax

  v4 = __PAIR__((unsigned __int64)table, key);
  v5 = freeptr;
  v6 = (UFG::allocator::free_link *)element;
  v7 = &table->buckets[key % table->modulo];
  if ( v7->entries )
  {
    while ( table->allowDups || v7->entries->keybase.key.iKey != key )
    {
      v7 = (ANTLR3_HASH_BUCKET_struct *)&v7->entries->nextEntry;
      if ( !v7->entries )
        goto LABEL_5;
    }
    result = 3i64;
  }
  else
  {
LABEL_5:
    v8 = antlrMalloc(0x28ui64);
    if ( v8 )
    {
      v8[2].mNext = v6;
      v8[3].mNext = (UFG::allocator::free_link *)v5;
      LOBYTE(v8->mNext) = 0;
      v8[1].mNext = (UFG::allocator::free_link *)v4;
      v8[4].mNext = 0i64;
      v7->entries = (ANTLR3_HASH_ENTRY_struct *)v8;
      ++*(_DWORD *)(*((_QWORD *)&v4 + 1) + 16i64);
      result = 0i64;
    }
    else
    {
      result = 1i64;
    }
  }
  return result;
}

// File Line: 598
// RVA: 0x258890
signed __int64 __fastcall antlr3HashPut(ANTLR3_HASH_TABLE_struct *table, void *key, void *element, void (__fastcall *freeptr)(void *))
{
  void (__fastcall *v4)(void *); // rbp
  UFG::allocator::free_link *v5; // r15
  const char *v6; // rsi
  ANTLR3_HASH_TABLE_struct *v7; // r14
  signed __int64 v8; // r10
  unsigned int i; // er8
  int v10; // eax
  ANTLR3_HASH_BUCKET_struct *v11; // rbx
  int v12; // er9
  const char *v13; // rax
  int v14; // ecx
  int v15; // edx
  UFG::allocator::free_link *v16; // rax
  ANTLR3_HASH_ENTRY_struct *v17; // rdi
  signed __int64 result; // rax

  v4 = freeptr;
  v5 = (UFG::allocator::free_link *)element;
  v6 = (const char *)key;
  v7 = table;
  v8 = -1i64;
  do
    ++v8;
  while ( *((_BYTE *)key + v8) );
  for ( i = 0; (_DWORD)v8; LODWORD(v8) = v8 - 1 )
  {
    v10 = *(unsigned __int8 *)key;
    key = (char *)key + 1;
    i = v10 + 16 * i;
    if ( i & 0xF0000000 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  v11 = &table->buckets[i % table->modulo];
  if ( v11->entries )
  {
    v12 = table->allowDups;
    while ( 1 )
    {
      if ( !v12 )
      {
        v13 = v6;
        do
        {
          v14 = (unsigned __int8)v13[v11->entries->keybase.key.iKey - (_QWORD)v6];
          v15 = *(unsigned __int8 *)v13 - v14;
          if ( *(unsigned __int8 *)v13 != v14 )
            break;
          ++v13;
        }
        while ( v14 );
        if ( !v15 )
          break;
      }
      v11 = (ANTLR3_HASH_BUCKET_struct *)&v11->entries->nextEntry;
      if ( !v11->entries )
        goto LABEL_15;
    }
    result = 3i64;
  }
  else
  {
LABEL_15:
    v16 = antlrMalloc(0x28ui64);
    v17 = (ANTLR3_HASH_ENTRY_struct *)v16;
    if ( v16 )
    {
      v16[2].mNext = v5;
      v16[3].mNext = (UFG::allocator::free_link *)v4;
      LOBYTE(v16->mNext) = 1;
      if ( v7->doStrdup == 1 )
        v16[1].mNext = antlrStrdup(v6);
      else
        v16[1].mNext = (UFG::allocator::free_link *)v6;
      v17->nextEntry = 0i64;
      v11->entries = v17;
      ++v7->count;
      result = 0i64;
    }
    else
    {
      result = 1i64;
    }
  }
  return result;
}

// File Line: 677
// RVA: 0x259B70
ANTLR3_HASH_ENUM_struct *__fastcall antlr3EnumNew(ANTLR3_HASH_TABLE_struct *table)
{
  ANTLR3_HASH_TABLE_struct *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  ANTLR3_HASH_ENUM_struct *v3; // r11
  ANTLR3_HASH_BUCKET_struct *v5; // rax
  ANTLR3_HASH_ENTRY_struct *v6; // rcx

  v1 = table;
  v2 = antlrMalloc(0x28ui64);
  v3 = (ANTLR3_HASH_ENUM_struct *)v2;
  if ( !v2 )
    return (ANTLR3_HASH_ENUM_struct *)1;
  v2->mNext = (UFG::allocator::free_link *)v1;
  LODWORD(v2[1].mNext) = 0;
  v5 = v1->buckets;
  v6 = v5->entries;
  v3->entry = v5->entries;
  if ( !v6 )
    antlr3EnumNextEntry(v3);
  v3->free = antlr3EnumFree;
  v3->next = (int (__fastcall *)(ANTLR3_HASH_ENUM_struct *, ANTLR3_HASH_KEY_struct **, void **))antlr3EnumNext;
  return v3;
}

// File Line: 733
// RVA: 0x258540
signed __int64 __fastcall antlr3EnumNext(ANTLR3_HASH_ENUM_struct *en, ANTLR3_HASH_KEY_struct **key, void **data)
{
  ANTLR3_HASH_ENUM_struct *v3; // r10
  ANTLR3_HASH_ENTRY_struct *v5; // rax
  ANTLR3_HASH_ENTRY_struct *v6; // rax
  ANTLR3_HASH_TABLE_struct *v7; // r8
  unsigned int v8; // eax
  ANTLR3_HASH_BUCKET_struct *v9; // rcx

  v3 = en;
  if ( en->bucket >= en->table->modulo )
    return 1i64;
  *key = &en->entry->keybase;
  *data = en->entry->data;
  v5 = en->entry;
  if ( v5 )
  {
    v6 = v5->nextEntry;
    if ( v6 )
      goto LABEL_10;
  }
  ++en->bucket;
  v7 = en->table;
  v8 = en->bucket;
  if ( v8 < en->table->modulo )
  {
    while ( 1 )
    {
      v9 = v7->buckets;
      if ( v9[v8].entries )
        break;
      v3->bucket = ++v8;
      if ( v8 >= v7->modulo )
        return 0i64;
    }
    v6 = v9[v8].entries;
LABEL_10:
    v3->entry = v6;
  }
  return 0i64;
}

// File Line: 769
// RVA: 0x2585C0
void __fastcall antlr3EnumNextEntry(ANTLR3_HASH_ENUM_struct *en)
{
  ANTLR3_HASH_ENTRY_struct *v1; // rax
  ANTLR3_HASH_ENTRY_struct *v2; // rax
  ANTLR3_HASH_TABLE_struct *v3; // r9
  unsigned int v4; // eax
  ANTLR3_HASH_ENTRY_struct **v5; // r10

  v1 = en->entry;
  if ( v1 && (v2 = v1->nextEntry) != 0i64 )
  {
    en->entry = v2;
  }
  else
  {
    ++en->bucket;
    v3 = en->table;
    v4 = en->bucket;
    if ( v4 < en->table->modulo )
    {
      while ( 1 )
      {
        v5 = &v3->buckets[v4].entries;
        if ( *v5 )
          break;
        en->bucket = ++v4;
        if ( v4 >= v3->modulo )
          return;
      }
      en->entry = *v5;
    }
  }
}

// File Line: 838
// RVA: 0x259BE0
__int64 __fastcall antlr3Hash(void *key, unsigned int keylen)
{
  __int64 result; // rax
  unsigned int v3; // er8
  unsigned __int8 *i; // r9
  int v5; // edx

  result = 0i64;
  v3 = keylen;
  for ( i = (unsigned __int8 *)key; v3; --v3 )
  {
    v5 = *i++;
    result = (unsigned int)(v5 + 16 * result);
    if ( result & 0xF0000000 )
      result = result & 0xF0000000 ^ (((unsigned int)result & 0xF0000000) >> 24) ^ (unsigned int)result;
  }
  return result;
}

// File Line: 867
// RVA: 0x259DD0
UFG::allocator::free_link *__fastcall antlr3ListNew(unsigned int sizeHint)
{
  unsigned int v1; // edi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v4; // rax

  v1 = sizeHint;
  v2 = antlrMalloc(0x40ui64);
  if ( !v2 )
    return (UFG::allocator::free_link *)1;
  v4 = antlr3HashTableNew(v1);
  v2->mNext = v4;
  if ( v4 == (UFG::allocator::free_link *)1 )
    return (UFG::allocator::free_link *)1;
  v2[1].mNext = (UFG::allocator::free_link *)antlr3ListFree;
  v2[2].mNext = (UFG::allocator::free_link *)antlr3ListDelete;
  v2[3].mNext = (UFG::allocator::free_link *)antlr3ListGet;
  v2[5].mNext = (UFG::allocator::free_link *)antlr3ListAdd;
  v2[4].mNext = (UFG::allocator::free_link *)antlr3ListRemove;
  v2[6].mNext = (UFG::allocator::free_link *)antlr3ListPut;
  v2[7].mNext = (UFG::allocator::free_link *)antlr3ListSize;
  return v2;
}

// File Line: 902
// RVA: 0x258C80
__int64 __fastcall antlr3ListSize(ANTLR3_LIST_struct *list)
{
  return list->table->size(list->table);
}

// File Line: 908
// RVA: 0x258C20
void __fastcall antlr3ListFree(ANTLR3_LIST_struct *list)
{
  ANTLR3_LIST_struct *v1; // rbx

  v1 = list;
  list->table->free(list->table);
  antlrFree(v1);
}

// File Line: 920
// RVA: 0x258C10
void __fastcall antlr3ListDelete(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  list->table->delI(list->table, key);
}

// File Line: 926
// RVA: 0x258C40
__int64 __fastcall antlr3ListGet(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  return list->table->getI(list->table, key);
}

// File Line: 933
// RVA: 0x258BC0
__int64 __fastcall antlr3ListAdd(ANTLR3_LIST_struct *list, void *element, void (__fastcall *freeptr)(void *))
{
  ANTLR3_LIST_struct *v3; // rsi
  void (__fastcall *v4)(void *); // rbx
  void *v5; // rdi
  unsigned int v6; // eax

  v3 = list;
  v4 = freeptr;
  v5 = element;
  v6 = list->table->size(list->table);
  return v3->put(v3, v6 + 1, v5, v4);
}

// File Line: 945
// RVA: 0x258C60
ANTLR3_HASH_ENTRY_struct *__fastcall antlr3ListRemove(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  ANTLR3_HASH_ENTRY_struct *result; // rax

  result = list->table->removeI(list->table, key);
  if ( result )
    result = (ANTLR3_HASH_ENTRY_struct *)result->data;
  return result;
}

// File Line: 962
// RVA: 0x258C50
__int64 __fastcall antlr3ListPut(ANTLR3_LIST_struct *list, unsigned __int64 key, void *element, void (__fastcall *freeptr)(void *))
{
  return list->table->putI(list->table, key, element, freeptr);
}

// File Line: 968
// RVA: 0x259F60
UFG::allocator::free_link *__fastcall antlr3StackNew(unsigned int sizeHint)
{
  unsigned int v1; // esi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v4; // rax
  signed __int64 v5; // rdi

  v1 = sizeHint;
  v2 = antlrMalloc(0x40ui64);
  if ( !v2 )
    return (UFG::allocator::free_link *)1;
  v4 = antlrMalloc(0x160ui64);
  v5 = (signed __int64)v4;
  if ( v4 )
    antlr3SetVectorApi((ANTLR3_VECTOR_struct *)v4, v1);
  else
    v5 = 1i64;
  v2->mNext = (UFG::allocator::free_link *)v5;
  v2[1].mNext = 0i64;
  if ( v5 == 1 )
    return (UFG::allocator::free_link *)1;
  v2[4].mNext = (UFG::allocator::free_link *)antlr3StackGet;
  v2[2].mNext = (UFG::allocator::free_link *)antlr3StackFree;
  v2[3].mNext = (UFG::allocator::free_link *)antlr3StackPop;
  v2[5].mNext = (UFG::allocator::free_link *)antlr3StackPush;
  v2[6].mNext = (UFG::allocator::free_link *)antlr3StackSize;
  v2[7].mNext = (UFG::allocator::free_link *)Scaleform::GFx::Stream::GetLog;
  return v2;
}

// File Line: 1003
// RVA: 0x258D30
__int64 __fastcall antlr3StackSize(ANTLR3_STACK_struct *stack)
{
  return stack->vector->count;
}

// File Line: 1010
// RVA: 0x258C90
void __fastcall antlr3StackFree(ANTLR3_STACK_struct *stack)
{
  ANTLR3_STACK_struct *v1; // rbx

  v1 = stack;
  stack->vector->free(stack->vector);
  v1->vector = 0i64;
  v1->top = 0i64;
  antlrFree(v1);
}

// File Line: 1022
// RVA: 0x258CD0
void *__fastcall antlr3StackPop(ANTLR3_STACK_struct *stack)
{
  ANTLR3_STACK_struct *v1; // rbx
  void *result; // rax

  v1 = stack;
  stack->vector->del(stack->vector, stack->vector->count - 1);
  result = v1->vector->get(v1->vector, v1->vector->count - 1);
  v1->top = result;
  return result;
}

// File Line: 1039
// RVA: 0x258CC0
__int64 __fastcall antlr3StackGet(ANTLR3_STACK_struct *stack, unsigned __int64 key)
{
  return stack->vector->get(stack->vector, key);
}

// File Line: 1051
// RVA: 0x258D10
__int64 __fastcall antlr3StackPush(ANTLR3_STACK_struct *stack, void *element, void (__fastcall *freeptr)(void *))
{
  ANTLR3_VECTOR_struct *v3; // rax

  v3 = stack->vector;
  stack->top = element;
  return v3->add(v3, element, freeptr);
}

// File Line: 1058
// RVA: 0x25A1E0
UFG::allocator::free_link *__fastcall antlr3VectorNew(unsigned int sizeHint)
{
  unsigned int v1; // edi
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx

  v1 = sizeHint;
  v2 = antlrMalloc(0x160ui64);
  v3 = v2;
  if ( !v2 )
    return (UFG::allocator::free_link *)1;
  antlr3SetVectorApi((ANTLR3_VECTOR_struct *)v2, v1);
  return v3;
}

// File Line: 1082
// RVA: 0x259E70
void __fastcall antlr3SetVectorApi(ANTLR3_VECTOR_struct *vector, unsigned int sizeHint)
{
  unsigned int v2; // edi
  ANTLR3_VECTOR_struct *v3; // rbx

  v2 = 16;
  v3 = vector;
  if ( sizeHint > 0x10 )
    v2 = sizeHint;
  if ( sizeHint <= 0x10 )
    vector->elements = vector->internal;
  else
    vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)antlrMalloc(16i64 * v2);
  if ( v3->elements )
  {
    v3->count = 0;
    v3->elementsSize = v2;
    v3->add = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, void *, void (__fastcall *)(void *)))antlr3VectorAdd;
    v3->factoryMade = 0;
    v3->del = antlr3VectorDel;
    v3->get = antlr3VectorGet;
    v3->free = antlr3VectorFree;
    v3->set = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, unsigned int, void *, void (__fastcall *)(void *), char))antlr3VectorSet;
    v3->remove = antrl3VectorRemove;
    v3->clear = antlr3VectorClear;
    v3->size = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *))UFG::DUIIntArray::Count;
    v3->swap = antlr3VectorSwap;
  }
  else
  {
    antlrFree(v3);
  }
}

// File Line: 1140
// RVA: 0x258DE0
void __fastcall antlr3VectorClear(ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_struct *v1; // rbx
  unsigned int v2; // esi
  signed __int64 v3; // rdi
  void (__fastcall *v4)(void *); // rdx

  v1 = vector;
  v2 = 0;
  if ( vector->count )
  {
    do
    {
      v3 = v2;
      v4 = v1->elements[v2].freeptr;
      if ( v4 )
        v4(v1->elements[v2].element);
      ++v2;
      v1->elements[v3].freeptr = 0i64;
      v1->elements[v3].element = 0i64;
    }
    while ( v2 < v1->count );
    v1->count = 0;
  }
  else
  {
    vector->count = 0;
  }
}

// File Line: 1165
// RVA: 0x258F00
void __fastcall antlr3VectorFree(ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_struct *v1; // rbx
  unsigned int i; // esi
  signed __int64 v3; // rdi
  void (__fastcall *v4)(void *); // rdx

  v1 = vector;
  for ( i = 0; i < v1->count; v1->elements[v3].element = 0i64 )
  {
    v3 = i;
    v4 = v1->elements[i].freeptr;
    if ( v4 )
      v4(v1->elements[i].element);
    ++i;
    v1->elements[v3].freeptr = 0i64;
  }
  if ( !v1->factoryMade )
  {
    if ( v1->elementsSize > 0x10 )
      antlrFree(v1->elements);
    v1->elements = 0i64;
    antlrFree(v1);
  }
}

// File Line: 1199
// RVA: 0x258E60
void __fastcall antlr3VectorDel(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  unsigned int v2; // esi
  ANTLR3_VECTOR_struct *v3; // rbx
  unsigned __int64 v4; // rdi
  void (__fastcall *v5)(void *); // rdx
  unsigned int v6; // er8

  v2 = entry;
  v3 = vector;
  if ( entry < vector->count )
  {
    v4 = entry;
    v5 = vector->elements[v4].freeptr;
    if ( v5 )
    {
      v5(vector->elements[v4].element);
      v3->elements[v4].freeptr = 0i64;
    }
    v6 = v3->count;
    if ( v2 == v6 - 1 )
      v3->elements[v4].element = 0i64;
    else
      UFG::qMemMove(&v3->elements[v4], &v3->elements[v4 + 1], 16 * (v6 - v2 - 1));
    --v3->count;
  }
}

// File Line: 1235
// RVA: 0x258F90
void *__fastcall antlr3VectorGet(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  void *result; // rax

  if ( entry >= vector->count )
    result = 0i64;
  else
    result = vector->elements[entry].element;
  return result;
}

// File Line: 1254
// RVA: 0x259150
void *__fastcall antrl3VectorRemove(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  unsigned int v2; // er8
  ANTLR3_VECTOR_struct *v3; // rbx
  ANTLR3_VECTOR_ELEMENT_struct *v5; // r9
  signed __int64 v6; // rcx
  ANTLR3_VECTOR_ELEMENT_struct *v7; // r9
  void *v8; // rdi

  v2 = vector->count;
  v3 = vector;
  if ( entry >= v2 )
    return 0i64;
  v5 = vector->elements;
  v6 = entry;
  v7 = &v5[v6];
  v8 = v7->element;
  if ( entry == v2 - 1 )
  {
    v7->element = 0i64;
    v3->elements[v6].freeptr = 0i64;
  }
  else
  {
    UFG::qMemMove(v7, &v7[1], 16 * (v2 - entry - 1));
  }
  --v3->count;
  return v8;
}

// File Line: 1293
// RVA: 0x258FB0
void __fastcall antlr3VectorResize(ANTLR3_VECTOR_struct *vector, unsigned int hint)
{
  ANTLR3_VECTOR_struct *v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // edi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rax

  v2 = vector;
  if ( hint && (v3 = vector->elementsSize, hint >= v3) )
  {
    v4 = 2 * hint;
  }
  else
  {
    v3 = vector->elementsSize;
    v4 = 2 * v3;
  }
  if ( v3 <= 0x10 )
  {
    v6 = antlrMalloc(16i64 * v4);
    v2->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v6;
    UFG::qMemCopy(v6, v2->internal, 0x100u);
    v2->elementsSize = v4;
  }
  else
  {
    v5 = antlrRealloc(vector->elements, 16i64 * v4);
    v2->elementsSize = v4;
    v2->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v5;
  }
}

// File Line: 1336
// RVA: 0x258D40
__int64 __fastcall antlr3VectorAdd(ANTLR3_VECTOR_struct *vector, void *element, void (__fastcall *freeptr)(void *))
{
  unsigned int v3; // eax
  void (__fastcall *v4)(void *); // rsi
  void *v5; // rbp
  ANTLR3_VECTOR_struct *v6; // rbx
  unsigned int v7; // edi
  UFG::allocator::free_link *v8; // rax

  v3 = vector->elementsSize;
  v4 = freeptr;
  v5 = element;
  v6 = vector;
  if ( vector->count == v3 )
  {
    v7 = 2 * v3;
    if ( v3 <= 0x10 )
    {
      v8 = antlrMalloc(16i64 * v7);
      v6->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v8;
      UFG::qMemCopy(v8, v6->internal, 0x100u);
    }
    else
    {
      vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)antlrRealloc(vector->elements, 16i64 * v7);
    }
    v6->elementsSize = v7;
  }
  v6->elements[v6->count].element = v5;
  v6->elements[v6->count++].freeptr = v4;
  return v6->count;
}

// File Line: 1360
// RVA: 0x259040
__int64 __fastcall antlr3VectorSet(ANTLR3_VECTOR_struct *vector, unsigned int entry, void *element, void (__fastcall *freeptr)(void *), char freeExisting)
{
  void (__fastcall *v5)(void *); // rsi
  void *v6; // rbp
  signed __int64 v7; // rbx
  ANTLR3_VECTOR_struct *v8; // rdi
  void (__fastcall *v9)(void *); // rdx
  signed __int64 v10; // rcx

  v5 = freeptr;
  v6 = element;
  v7 = entry;
  v8 = vector;
  if ( entry >= vector->elementsSize )
    antlr3VectorResize(vector, entry);
  if ( (unsigned int)v7 < v8->count )
  {
    if ( freeExisting )
    {
      v9 = v8->elements[v7].freeptr;
      if ( v9 )
        v9(v8->elements[v7].element);
    }
  }
  v10 = v7;
  v8->elements[v10].freeptr = v5;
  v8->elements[v10].element = v6;
  if ( (unsigned int)v7 >= v8->count )
    v8->count = v7 + 1;
  return (unsigned int)v7;
}

// File Line: 1397
// RVA: 0x2590E0
char __fastcall antlr3VectorSwap(ANTLR3_VECTOR_struct *vector, unsigned int entry1, unsigned int entry2)
{
  unsigned int v3; // eax
  __int64 v4; // r11
  __int64 v5; // r9
  ANTLR3_VECTOR_ELEMENT_struct *v6; // rdx
  void *v7; // r10
  void (__fastcall *v8)(void *); // r8

  v3 = vector->elementsSize;
  if ( entry1 >= v3 || entry2 >= v3 )
    return 0;
  v4 = entry1;
  v5 = entry2;
  v6 = &vector->elements[entry1];
  v7 = v6->element;
  v8 = v6->freeptr;
  v6->freeptr = vector->elements[v5].freeptr;
  vector->elements[v4].element = vector->elements[v5].element;
  vector->elements[v5].freeptr = v8;
  vector->elements[v5].element = v7;
  return 1;
}

// File Line: 1427
// RVA: 0x2590D0
__int64 __fastcall UFG::DUIIntArray::Count(UFG::DUIIntArray *this)
{
  return this->mData.size;
}

// File Line: 1435
// RVA: 0x25A090
UFG::allocator::free_link *__fastcall antlr3VectorFactoryNew(unsigned int sizeHint)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_VECTOR_FACTORY_struct *v2; // rbx

  result = antlrMalloc(0x190ui64);
  v2 = (ANTLR3_VECTOR_FACTORY_struct *)result;
  if ( result )
  {
    result->mNext = 0i64;
    LODWORD(result[1].mNext) = 0;
    result->mNext = antlrRealloc(0i64, 8ui64);
    v2->pools[v2->thisPool] = (ANTLR3_VECTOR_struct *)antlrMalloc(0x16000ui64);
    v2->nextVector = 0;
    v2->unTruc.elements = v2->unTruc.internal;
    if ( v2 == (ANTLR3_VECTOR_FACTORY_struct *)-32i64 )
    {
      antlrFree((void *)0xFFFFFFFFFFFFFFF0i64);
    }
    else
    {
      v2->unTruc.count = 0;
      v2->unTruc.elementsSize = 16;
      v2->unTruc.add = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, void *, void (__fastcall *)(void *)))antlr3VectorAdd;
      v2->unTruc.factoryMade = 0;
      v2->unTruc.del = antlr3VectorDel;
      v2->unTruc.get = antlr3VectorGet;
      v2->unTruc.free = antlr3VectorFree;
      v2->unTruc.set = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, unsigned int, void *, void (__fastcall *)(void *), char))antlr3VectorSet;
      v2->unTruc.remove = antrl3VectorRemove;
      v2->unTruc.clear = antlr3VectorClear;
      v2->unTruc.size = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *))UFG::DUIIntArray::Count;
      v2->unTruc.swap = antlr3VectorSwap;
    }
    v2->unTruc.factoryMade = 1;
    v2->close = closeVectorFactory;
    v2->newVector = newVector;
    v2->returnVector = returnVector;
    v2->freeStack = (ANTLR3_STACK_struct *)antlr3StackNew(0x10u);
    result = (UFG::allocator::free_link *)v2;
  }
  return result;
}

// File Line: 1476
// RVA: 0x259890
void __fastcall returnVector(ANTLR3_VECTOR_FACTORY_struct *factory, ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_FACTORY_struct *v2; // rbx
  ANTLR3_VECTOR_struct *v3; // rdi

  v2 = factory;
  v3 = vector;
  vector->clear(vector);
  v2->freeStack->push(v2->freeStack, v3, 0i64);
}

// File Line: 1523
// RVA: 0x2591D0
void __fastcall closeVectorFactory(ANTLR3_VECTOR_FACTORY_struct *factory)
{
  ANTLR3_STACK_struct *v1; // rax
  ANTLR3_VECTOR_FACTORY_struct *v2; // rsi
  int v3; // edx
  int v4; // ebp
  __int64 v5; // r14
  ANTLR3_VECTOR_struct *v6; // rbx
  unsigned int v7; // eax
  __int64 v8; // rdi
  int v9; // eax
  int v10; // ebp
  __int64 v11; // r14
  ANTLR3_VECTOR_struct *v12; // rbx
  unsigned int v13; // eax
  __int64 v14; // rdi

  v1 = factory->freeStack;
  v2 = factory;
  if ( v1 )
    v1->free(factory->freeStack);
  v3 = v2->thisPool;
  v4 = 0;
  if ( v3 >= 0 )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = v2->pools[v5];
      if ( v4 != v3 )
        break;
      v7 = v2->nextVector;
      if ( v7 )
        goto LABEL_9;
LABEL_11:
      v3 = v2->thisPool;
      ++v4;
      ++v5;
      if ( v4 > v3 )
        goto LABEL_12;
    }
    v7 = 256;
LABEL_9:
    v8 = v7;
    do
    {
      v6->free(v6);
      ++v6;
      --v8;
    }
    while ( v8 );
    goto LABEL_11;
  }
LABEL_12:
  v9 = v2->thisPool;
  v10 = 0;
  if ( v9 >= 0 )
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v2->pools[v11];
      if ( v10 != v9 )
        break;
      v13 = v2->nextVector;
      if ( v13 )
        goto LABEL_18;
LABEL_23:
      antlrFree(v2->pools[v11]);
      ++v10;
      v2->pools[v11] = 0i64;
      v9 = v2->thisPool;
      ++v11;
      if ( v10 > v9 )
        goto LABEL_24;
    }
    v13 = 256;
LABEL_18:
    v14 = v13;
    do
    {
      if ( v12->factoryMade == 1 && v12->elementsSize > 0x10 )
      {
        antlrFree(v12->elements);
        v12->elements = 0i64;
      }
      ++v12;
      --v14;
    }
    while ( v14 );
    goto LABEL_23;
  }
LABEL_24:
  antlrFree(v2->pools);
  antlrFree(v2);
}

// File Line: 1636
// RVA: 0x259730
ANTLR3_VECTOR_struct *__fastcall newVector(ANTLR3_VECTOR_FACTORY_struct *factory)
{
  ANTLR3_VECTOR_FACTORY_struct *v1; // rdi
  ANTLR3_VECTOR_struct *v2; // rbx
  ANTLR3_VECTOR_struct *result; // rax
  ANTLR3_VECTOR_struct *v4; // rbx

  v1 = factory;
  v2 = (ANTLR3_VECTOR_struct *)factory->freeStack->peek(factory->freeStack);
  if ( v2 )
  {
    v1->freeStack->pop(v1->freeStack);
    result = v2;
  }
  else
  {
    if ( v1->nextVector >= 0x100 )
    {
      v1->pools = (ANTLR3_VECTOR_struct **)antlrRealloc(v1->pools, (unsigned int)(8 * ++v1->thisPool + 8));
      v1->pools[v1->thisPool] = (ANTLR3_VECTOR_struct *)antlrMalloc(0x16000ui64);
      v1->nextVector = 0;
    }
    v4 = &v1->pools[v1->thisPool][v1->nextVector++];
    v4->elements = v4->internal;
    if ( v4 == (ANTLR3_VECTOR_struct *)-16i64 )
    {
      antlrFree((void *)0xFFFFFFFFFFFFFFF0i64);
    }
    else
    {
      v4->count = 0;
      v4->elementsSize = 16;
      v4->add = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, void *, void (__fastcall *)(void *)))antlr3VectorAdd;
      v4->factoryMade = 0;
      v4->del = antlr3VectorDel;
      v4->get = antlr3VectorGet;
      v4->free = antlr3VectorFree;
      v4->set = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, unsigned int, void *, void (__fastcall *)(void *), char))antlr3VectorSet;
      v4->remove = antrl3VectorRemove;
      v4->clear = antlr3VectorClear;
      v4->size = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *))UFG::DUIIntArray::Count;
      v4->swap = antlr3VectorSwap;
    }
    v4->factoryMade = 1;
    v4->elements = v4->internal;
    result = v4;
  }
  return result;
}

// File Line: 1766
// RVA: 0x259D30
UFG::allocator::free_link *__fastcall antlr3IntTrieNew(unsigned int depth)
{
  unsigned int v1; // edi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v1 = depth;
  v2 = antlrCalloc(1u, 0x38u);
  if ( !v2 )
    return (UFG::allocator::free_link *)1;
  v3 = antlrCalloc(1u, 0x38u);
  v2->mNext = v3;
  if ( !v3 )
  {
    antlrFree(v2);
    return (UFG::allocator::free_link *)1;
  }
  v2[5].mNext = (UFG::allocator::free_link *)intTrieAdd;
  v2[4].mNext = (UFG::allocator::free_link *)Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat;
  v2[6].mNext = (UFG::allocator::free_link *)intTrieFree;
  v2[3].mNext = (UFG::allocator::free_link *)intTrieGet;
  LODWORD(v3->mNext) = v1;
  v2->mNext[3].mNext = v2->mNext;
  v2->mNext[4].mNext = v2->mNext;
  LODWORD(v2[2].mNext) = 0;
  return v2;
}

// File Line: 1819
// RVA: 0x2596E0
ANTLR3_TRIE_ENTRY_struct *__fastcall intTrieGet(ANTLR3_INT_TRIE_struct *trie, unsigned __int64 key)
{
  unsigned __int64 v2; // r9
  ANTLR3_INT_TRIE_NODE_struct *v3; // rcx
  ANTLR3_INT_TRIE_NODE_struct *v4; // rax
  unsigned int v5; // edx
  ANTLR3_INT_TRIE_NODE_struct *v6; // r8
  ANTLR3_TRIE_ENTRY_struct *result; // rax

  v2 = key;
  if ( !trie->count )
    goto LABEL_12;
  v3 = trie->root;
  v4 = v3->leftN;
  v5 = v4->bitNum;
  if ( v3->bitNum > v4->bitNum )
  {
    do
    {
      v6 = v4;
      if ( v2 & bitMask[v5] )
        v4 = v4->rightN;
      else
        v4 = v4->leftN;
      v5 = v4->bitNum;
    }
    while ( v6->bitNum > v4->bitNum );
  }
  if ( v4->key == v2 )
    result = v4->buckets;
  else
LABEL_12:
    result = 0i64;
  return result;
}

// File Line: 1911
// RVA: 0x259410
char __fastcall intTrieAdd(ANTLR3_INT_TRIE_struct *trie, unsigned __int64 key, unsigned int type, unsigned __int64 intVal, void *data, void (__fastcall *freeptr)(void *))
{
  ANTLR3_INT_TRIE_NODE_struct *v6; // rbp
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r12
  ANTLR3_INT_TRIE_NODE_struct *v9; // rdi
  unsigned int v10; // er13
  ANTLR3_INT_TRIE_struct *v11; // r15
  __int64 v12; // rax
  ANTLR3_INT_TRIE_NODE_struct *v13; // rbx
  ANTLR3_INT_TRIE_NODE_struct *v14; // r9
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rdx
  char result; // al
  ANTLR3_TRIE_ENTRY_struct *v19; // rcx
  signed __int64 v20; // rax
  bool v21; // zf
  unsigned __int64 v22; // rax
  __int64 v23; // rbx
  __int64 i; // rax
  UFG::allocator::free_link *v25; // rsi
  UFG::allocator::free_link *v26; // rax

  v6 = trie->root;
  v7 = key;
  v8 = intVal;
  v9 = trie->root->leftN;
  v10 = type;
  v11 = trie;
  v12 = v9->bitNum;
  v13 = trie->root->leftN;
  if ( trie->root->bitNum > (unsigned int)v12 )
  {
    do
    {
      v14 = v13;
      if ( key & bitMask[v12] )
        v13 = v13->rightN;
      else
        v13 = v13->leftN;
      v12 = v13->bitNum;
    }
    while ( v14->bitNum > (unsigned int)v12 );
  }
  v15 = v13->key;
  if ( v15 == key )
  {
    if ( trie->allowDups == 1 && (v16 = antlrCalloc(1u, 0x20u), (v17 = v16) != 0i64) )
    {
      LODWORD(v16->mNext) = v10;
      if ( v10 == 1 )
        v8 = (unsigned __int64)data;
      v16[1].mNext = (UFG::allocator::free_link *)freeptr;
      v16[2].mNext = (UFG::allocator::free_link *)v8;
      v19 = v13->buckets;
      v20 = (signed __int64)&v19->next;
      if ( v19->next )
      {
        do
        {
          v19 = *(ANTLR3_TRIE_ENTRY_struct **)v20;
          v21 = *(_QWORD *)(*(_QWORD *)v20 + 24i64) == 0i64;
          v20 = *(_QWORD *)v20 + 24i64;
        }
        while ( !v21 );
      }
      v19->next = (ANTLR3_TRIE_ENTRY_struct *)v17;
      ++v11->count;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v22 = key ^ v15;
    if ( v22 & 0xFFFFFFFF00000000ui64 )
    {
      if ( v22 & 0xFFFF000000000000ui64 )
      {
        if ( v22 & 0xFF00000000000000ui64 )
          v23 = (unsigned int)(unsigned __int8)bitIndex[v22 >> 56] + 56;
        else
          v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE6(v22)] + 48;
      }
      else if ( v22 & 0xFF0000000000i64 )
      {
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE5(v22)] + 40;
      }
      else
      {
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE4(v22)] + 32;
      }
    }
    else if ( v22 & 0xFFFF0000 )
    {
      if ( v22 & 0xFF000000 )
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE3(v22)] + 24;
      else
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE2(v22)] + 16;
    }
    else if ( v22 & 0xFF00 )
    {
      v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE1(v22)] + 8;
    }
    else
    {
      v23 = (unsigned __int8)bitIndex[(unsigned __int8)v22];
    }
    for ( i = v9->bitNum; v6->bitNum > (unsigned int)i; i = v9->bitNum )
    {
      if ( (unsigned int)i <= (unsigned int)v23 )
        break;
      v6 = v9;
      v9 = key & bitMask[i] ? v9->rightN : v9->leftN;
    }
    v25 = antlrCalloc(1u, 0x28u);
    if ( v25 && (v26 = antlrCalloc(1u, 0x20u)) != 0i64 )
    {
      LODWORD(v26->mNext) = v10;
      if ( v10 == 1 )
        v8 = (unsigned __int64)data;
      v26[1].mNext = (UFG::allocator::free_link *)freeptr;
      v26[2].mNext = (UFG::allocator::free_link *)v8;
      v25[2].mNext = v26;
      v25[1].mNext = (UFG::allocator::free_link *)v7;
      LODWORD(v25->mNext) = v23;
      if ( v7 & bitMask[v23] )
      {
        v25[3].mNext = (UFG::allocator::free_link *)v9;
        v25[4].mNext = v25;
      }
      else
      {
        v25[4].mNext = (UFG::allocator::free_link *)v9;
        v25[3].mNext = v25;
      }
      if ( v7 & bitMask[v6->bitNum] )
        v6->rightN = (ANTLR3_INT_TRIE_NODE_struct *)v25;
      else
        v6->leftN = (ANTLR3_INT_TRIE_NODE_struct *)v25;
      ++v11->count;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 2188
// RVA: 0x2592F0
void __fastcall freeIntNode(ANTLR3_INT_TRIE_NODE_struct *node)
{
  ANTLR3_INT_TRIE_NODE_struct *v1; // rsi
  ANTLR3_INT_TRIE_NODE_struct *v2; // rcx
  ANTLR3_INT_TRIE_NODE_struct *v3; // rcx
  ANTLR3_TRIE_ENTRY_struct *v4; // rbx
  ANTLR3_TRIE_ENTRY_struct *v5; // rdi
  void (__fastcall *v6)(void *); // rax

  v1 = node;
  v2 = node->leftN;
  if ( v1->bitNum > v2->bitNum )
    freeIntNode(v2);
  v3 = v1->rightN;
  if ( v1->bitNum > v3->bitNum )
    freeIntNode(v3);
  v4 = v1->buckets;
  if ( v4 )
  {
    do
    {
      v5 = v4->next;
      if ( v4->type == 1 )
      {
        v6 = v4->freeptr;
        if ( v6 )
          v6(v4->data.ptr);
      }
      antlrFree(v4);
      v4 = v5;
    }
    while ( v5 );
  }
  antlrFree(v1);
}

// File Line: 2247
// RVA: 0x2596C0
void __fastcall intTrieFree(ANTLR3_INT_TRIE_struct *trie)
{
  ANTLR3_INT_TRIE_struct *v1; // rbx

  v1 = trie;
  freeIntNode(trie->root);
  antlrFree(v1);
}

// File Line: 2282
// RVA: 0x25A020
UFG::allocator::free_link *__fastcall antlr3TopoNew()
{
  UFG::allocator::free_link *result; // rax

  result = antlrMalloc(0x50ui64);
  if ( result )
  {
    LODWORD(result[4].mNext) = 1;
    result[5].mNext = 0i64;
    result->mNext = 0i64;
    result[1].mNext = 0i64;
    result[2].mNext = 0i64;
    HIDWORD(result[3].mNext) = 0;
    LOBYTE(result[3].mNext) = 0;
    result[6].mNext = (UFG::allocator::free_link *)addEdge;
    result[7].mNext = (UFG::allocator::free_link *)sortToArray;
    result[8].mNext = (UFG::allocator::free_link *)sortVector;
    result[9].mNext = (UFG::allocator::free_link *)freeTopo;
  }
  return result;
}

// File Line: 2314
// RVA: 0x258440
void __fastcall addEdge(ANTLR3_TOPO_struct *topo, unsigned int edge, unsigned int dependency)
{
  ANTLR3_TOPO_struct *v3; // rbx
  ANTLR3_BITSET_struct **v4; // rcx
  unsigned int v5; // edi
  unsigned int v6; // esi
  __int64 v7; // rbp
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rax
  unsigned int v10; // eax
  signed __int64 v11; // rcx
  __int64 v12; // rdx
  ANTLR3_BITSET_struct *v13; // rax

  v3 = topo;
  v4 = topo->edges;
  v5 = dependency;
  v6 = dependency;
  v7 = edge;
  if ( edge > dependency )
    v5 = edge;
  if ( v4 )
  {
    if ( v3->limit <= v5 )
    {
      v9 = antlrRealloc(v4, 8i64 * (v5 + 1));
      v3->edges = (ANTLR3_BITSET_struct **)v9;
      if ( !v9 )
        return;
      v10 = v3->limit;
      if ( v10 <= v5 )
      {
        v11 = v10;
        v12 = v5 - v10 + 1;
        do
        {
          ++v11;
          v3->edges[v11 - 1] = 0i64;
          --v12;
        }
        while ( v12 );
      }
      v3->limit = v5 + 1;
    }
  }
  else
  {
    v8 = antlrCalloc(8 * v5 + 8, 1u);
    v3->edges = (ANTLR3_BITSET_struct **)v8;
    if ( !v8 )
      return;
    v3->limit = v5 + 1;
  }
  if ( (_DWORD)v7 != v6 )
  {
    v13 = v3->edges[v7];
    if ( v13 || (v13 = antlr3BitsetNew(0), (v3->edges[v7] = v13) != 0i64) )
      v13->add(v13, v6);
  }
}

// File Line: 2413
// RVA: 0x258320
void __fastcall DFS(ANTLR3_TOPO_struct *topo, unsigned int node)
{
  __int64 v2; // rsi
  ANTLR3_TOPO_struct *v3; // rbx
  unsigned int v4; // edx
  __int64 v5; // rdi
  unsigned int v6; // er9
  unsigned int *v7; // r8
  unsigned int v8; // eax
  __int64 v9; // rcx
  ANTLR3_BITSET_struct *v10; // rax
  ANTLR3_BITSET_struct *v11; // rbp
  unsigned int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // [rsp+40h] [rbp+8h]
  unsigned int v15; // [rsp+48h] [rbp+10h]

  v15 = node;
  v2 = node;
  v3 = topo;
  if ( topo->hasCycle != 1 )
  {
    if ( topo->visited->isMember(topo->visited, v2) )
    {
      v4 = v3->cycleMark;
      v5 = 0i64;
      if ( v4 )
      {
        do
        {
          if ( v3->cycle[v5] == (_DWORD)v2 )
          {
            v6 = v5;
            if ( (unsigned int)v5 < v4 )
            {
              do
              {
                v7 = v3->cycle;
                v8 = v7[v6];
                v9 = v6++ - (unsigned int)v5;
                v7[v9] = v8;
              }
              while ( v6 < v3->cycleMark );
            }
            v3->cycleMark -= v5;
            v3->hasCycle = 1;
          }
          v4 = v3->cycleMark;
          v5 = (unsigned int)(v5 + 1);
        }
        while ( (unsigned int)v5 < v4 );
      }
    }
    else
    {
      v3->cycle[v3->cycleMark] = v2;
      v10 = v3->visited;
      ++v3->cycleMark;
      v10->add(v10, v2);
      v11 = v3->edges[v2];
      if ( v11 )
      {
        v14 = v11->numBits(v3->edges[v2]);
        v12 = 0;
        v13 = v11->size(v11);
        do
        {
          if ( !v13 )
            break;
          if ( v11->isMember(v11, v12) )
          {
            --v13;
            DFS(v3, v12);
          }
          ++v12;
        }
        while ( v12 <= v14 );
        LODWORD(v2) = v15;
      }
      v3->sorted[v3->limit++] = v2;
      if ( !v3->hasCycle )
        --v3->cycleMark;
    }
  }
}

// File Line: 2521
// RVA: 0x2598D0
unsigned int *__fastcall sortToArray(ANTLR3_TOPO_struct *topo)
{
  ANTLR3_TOPO_struct *v1; // rbx
  unsigned int *result; // rax
  UFG::allocator::free_link *v3; // rax
  unsigned __int64 v4; // rcx
  ANTLR3_BITSET_struct *v5; // rax
  unsigned int v6; // er13
  unsigned int v7; // er15
  __int64 v8; // r12
  unsigned int v9; // edx
  __int64 v10; // r10
  unsigned int v11; // er9
  unsigned int *v12; // r8
  unsigned int v13; // eax
  __int64 v14; // rcx
  ANTLR3_BITSET_struct *v15; // rax
  ANTLR3_BITSET_struct *v16; // rbp
  unsigned int v17; // er14
  unsigned int v18; // edi
  unsigned int v19; // esi

  v1 = topo;
  if ( !topo->edges )
    return 0i64;
  v3 = antlrMalloc(4i64 * topo->limit);
  v4 = 4i64 * v1->limit;
  v1->sorted = (unsigned int *)v3;
  v1->cycle = (unsigned int *)antlrMalloc(v4);
  v5 = antlr3BitsetNew(0);
  v6 = v1->limit;
  v7 = 0;
  v1->visited = v5;
  v1->limit = 0;
  if ( v6 )
  {
    v8 = 0i64;
    do
    {
      if ( !v1->visited->isMember(v1->visited, v7) )
      {
        if ( v1->hasCycle == 1 )
          break;
        if ( v1->visited->isMember(v1->visited, v7) )
        {
          v9 = v1->cycleMark;
          v10 = 0i64;
          if ( v9 )
          {
            do
            {
              if ( v1->cycle[v10] == v7 )
              {
                v11 = v10;
                if ( (unsigned int)v10 < v9 )
                {
                  do
                  {
                    v12 = v1->cycle;
                    v13 = v12[v11];
                    v14 = v11++ - (unsigned int)v10;
                    v12[v14] = v13;
                  }
                  while ( v11 < v1->cycleMark );
                }
                v1->cycleMark -= v10;
                v1->hasCycle = 1;
              }
              v9 = v1->cycleMark;
              v10 = (unsigned int)(v10 + 1);
            }
            while ( (unsigned int)v10 < v9 );
          }
        }
        else
        {
          v1->cycle[v1->cycleMark] = v7;
          v15 = v1->visited;
          ++v1->cycleMark;
          v15->add(v15, v7);
          v16 = v1->edges[v8];
          if ( v16 )
          {
            v17 = v16->numBits(v1->edges[v8]);
            v18 = 0;
            v19 = v16->size(v16);
            do
            {
              if ( !v19 )
                break;
              if ( v16->isMember(v16, v18) )
              {
                --v19;
                DFS(v1, v18);
              }
              ++v18;
            }
            while ( v18 <= v17 );
          }
          v1->sorted[v1->limit++] = v7;
          if ( !v1->hasCycle )
            --v1->cycleMark;
        }
      }
      if ( v1->hasCycle == 1 )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < v6 );
  }
  result = v1->sorted;
  v1->limit = v6;
  return result;
}

// File Line: 2589
// RVA: 0x259AA0
void __fastcall sortVector(ANTLR3_TOPO_struct *topo, ANTLR3_VECTOR_struct *v)
{
  ANTLR3_VECTOR_struct *v2; // r15
  ANTLR3_TOPO_struct *v3; // rdi
  unsigned int v4; // eax
  UFG::allocator::free_link *v5; // rax
  signed __int64 v6; // rbx
  UFG::allocator::free_link *v7; // rsi
  unsigned int v8; // edx
  signed __int64 v9; // r14
  unsigned int v10; // ebp

  v2 = v;
  v3 = topo;
  if ( ((__int64 (*)(void))topo->sortToArray)() && v3->hasCycle != 1 )
  {
    v4 = v2->count;
    if ( v3->limit > v4 )
      v3->limit = v4;
    v5 = antlrMalloc(4i64 * v3->limit);
    v6 = 0i64;
    v7 = v5;
    v8 = 0;
    if ( v3->limit )
    {
      do
      {
        *((_DWORD *)&v5->mNext + v8) = v8;
        ++v8;
      }
      while ( v8 < v3->limit );
    }
    if ( v3->limit > 0 )
    {
      do
      {
        v9 = v6;
        v10 = *((_DWORD *)&v7->mNext + v3->sorted[v6]);
        if ( v10 != (_DWORD)v6 )
        {
          v2->swap(v2, v6, v10);
          *((_DWORD *)&v7->mNext + v3->sorted[v9]) = v6;
          *(_DWORD *)((char *)&v7->mNext + v9 * 4) = v10;
        }
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < v3->limit );
    }
    antlrFree(v7);
  }
}

// File Line: 2690
// RVA: 0x259370
void __fastcall freeTopo(ANTLR3_TOPO_struct *topo)
{
  ANTLR3_TOPO_struct *v1; // rbx
  unsigned int *v2; // rcx
  ANTLR3_BITSET_struct *v3; // rax
  __int64 v4; // rdi
  ANTLR3_BITSET_struct *v5; // rdx
  unsigned int *v6; // rcx

  v1 = topo;
  v2 = topo->sorted;
  if ( v2 )
  {
    antlrFree(v2);
    v1->sorted = 0i64;
  }
  v3 = v1->visited;
  if ( v3 )
  {
    v3->free(v1->visited);
    v1->visited = 0i64;
  }
  if ( v1->edges )
  {
    v4 = 0i64;
    if ( v1->limit )
    {
      do
      {
        v5 = v1->edges[v4];
        if ( v5 )
          v5->free(v1->edges[v4]);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < v1->limit );
    }
    antlrFree(v1->edges);
  }
  v6 = v1->cycle;
  v1->edges = 0i64;
  if ( v6 )
    antlrFree(v6);
  antlrFree(v1);
}

