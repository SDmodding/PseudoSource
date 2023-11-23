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
          v3->buckets[v6++].entries = 0i64;
          --v4;
        }
        while ( v4 );
      }
      v3->allowDups = 0;
      v3->get = (void *(__fastcall *)(ANTLR3_HASH_TABLE_struct *, void *))antlr3HashGet;
      v3->doStrdup = 1;
      v3->put = (int (__fastcall *)(ANTLR3_HASH_TABLE_struct *, void *, void *, void (__fastcall *)(void *)))antlr3HashPut;
      v3->del = antlr3HashDelete;
      v3->remove = (ANTLR3_HASH_ENTRY_struct *(__fastcall *)(ANTLR3_HASH_TABLE_struct *, void *))antlr3HashRemove;
      v3->getI = antlr3HashGetI;
      v3->putI = (int (__fastcall *)(ANTLR3_HASH_TABLE_struct *, unsigned __int64, void *, void (__fastcall *)(void *)))antlr3HashPutI;
      v3->delI = antlr3HashDeleteI;
      v3->removeI = antlr3HashRemoveI;
      v3->size = (unsigned int (__fastcall *)(ANTLR3_HASH_TABLE_struct *))hkaMatrix<float>::Height;
      v3->free = antlr3HashFree;
      return (UFG::allocator::free_link *)v3;
    }
    else
    {
      antlrFree((char *)v3);
      return 0i64;
    }
  }
  return result;
}

// File Line: 199
// RVA: 0x2586E0
void __fastcall antlr3HashFree(ANTLR3_HASH_TABLE_struct *table)
{
  unsigned int i; // esi
  ANTLR3_HASH_BUCKET_struct *v3; // r14
  ANTLR3_HASH_ENTRY_struct *entries; // rbx
  void (__fastcall *free)(void *); // rax
  ANTLR3_HASH_ENTRY_struct *nextEntry; // rdi
  char *sKey; // rcx

  if ( table )
  {
    for ( i = 0; i < table->modulo; ++i )
    {
      v3 = &table->buckets[i];
      if ( v3 )
      {
        entries = v3->entries;
        if ( v3->entries )
        {
          do
          {
            free = entries->free;
            nextEntry = entries->nextEntry;
            if ( free )
              free(entries->data);
            if ( entries->keybase.type == 1 )
            {
              sKey = entries->keybase.key.sKey;
              if ( sKey )
                antlrFree(sKey);
            }
            antlrFree(&entries->keybase.type);
            entries = nextEntry;
          }
          while ( nextEntry );
        }
        v3->entries = 0i64;
      }
    }
    antlrFree((char *)table->buckets);
  }
  antlrFree((char *)table);
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
  ANTLR3_HASH_BUCKET_struct *p_nextEntry; // r9
  ANTLR3_HASH_ENTRY_struct *result; // rax

  p_nextEntry = &table->buckets[key % table->modulo];
  result = p_nextEntry->entries;
  if ( !p_nextEntry->entries )
    return 0i64;
  while ( result->keybase.key.iKey != key )
  {
    p_nextEntry = (ANTLR3_HASH_BUCKET_struct *)&result->nextEntry;
    result = result->nextEntry;
    if ( !result )
      return 0i64;
  }
  p_nextEntry->entries = result->nextEntry;
  --table->count;
  return result;
}

// File Line: 335
// RVA: 0x258A80
ANTLR3_HASH_ENTRY_struct *__fastcall antlr3HashRemove(ANTLR3_HASH_TABLE_struct *table, const char *key)
{
  const char *v2; // r10
  __int64 v4; // r8
  unsigned int i; // r9d
  int v6; // eax
  __int64 v7; // rdx
  ANTLR3_HASH_BUCKET_struct *buckets; // rax
  ANTLR3_HASH_ENTRY_struct *entries; // rbx
  ANTLR3_HASH_BUCKET_struct *p_nextEntry; // r9

  v2 = key;
  v4 = -1i64;
  do
    ++v4;
  while ( key[v4] );
  for ( i = 0; (_DWORD)v4; LODWORD(v4) = v4 - 1 )
  {
    v6 = *(unsigned __int8 *)key++;
    i = v6 + 16 * i;
    if ( (i & 0xF0000000) != 0 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  v7 = i % table->modulo;
  buckets = table->buckets;
  entries = buckets[v7].entries;
  p_nextEntry = &buckets[(unsigned int)v7];
  if ( !entries )
    return 0i64;
  while ( strcmp(v2, entries->keybase.key.sKey) )
  {
    p_nextEntry = (ANTLR3_HASH_BUCKET_struct *)&entries->nextEntry;
    entries = entries->nextEntry;
    if ( !entries )
      return 0i64;
  }
  p_nextEntry->entries = entries->nextEntry;
  if ( table->doStrdup == 1 )
    antlrFree(entries->keybase.key.sKey);
  entries->keybase.key.iKey = 0i64;
  --table->count;
  return entries;
}

// File Line: 400
// RVA: 0x258660
void __fastcall antlr3HashDeleteI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key)
{
  ANTLR3_HASH_BUCKET_struct *p_nextEntry; // r9
  ANTLR3_HASH_ENTRY_struct *entries; // rbx
  void (__fastcall *free)(void *); // rax

  p_nextEntry = &table->buckets[key % table->modulo];
  entries = p_nextEntry->entries;
  if ( !p_nextEntry->entries )
  {
LABEL_4:
    entries = 0i64;
LABEL_5:
    antlrFree(&entries->keybase.type);
    return;
  }
  while ( entries->keybase.key.iKey != key )
  {
    p_nextEntry = (ANTLR3_HASH_BUCKET_struct *)&entries->nextEntry;
    entries = entries->nextEntry;
    if ( !entries )
      goto LABEL_4;
  }
  p_nextEntry->entries = entries->nextEntry;
  --table->count;
  free = entries->free;
  if ( !free )
    goto LABEL_5;
  free(entries->data);
  entries->data = 0i64;
  antlrFree(&entries->keybase.type);
}

// File Line: 424
// RVA: 0x258620
void __fastcall antlr3HashDelete(ANTLR3_HASH_TABLE_struct *table, void *key)
{
  ANTLR3_HASH_ENTRY_struct *v2; // rax
  ANTLR3_HASH_ENTRY_struct *v3; // rbx
  void (__fastcall *free)(void *); // rax

  v2 = antlr3HashRemove(table, key);
  v3 = v2;
  if ( v2 )
  {
    free = v2->free;
    if ( free )
    {
      free(v3->data);
      v3->data = 0i64;
    }
  }
  antlrFree(&v3->keybase.type);
}

// File Line: 448
// RVA: 0x258850
void *__fastcall antlr3HashGetI(ANTLR3_HASH_TABLE_struct *table, unsigned __int64 key)
{
  ANTLR3_HASH_ENTRY_struct *entries; // rax

  entries = table->buckets[key % table->modulo].entries;
  if ( !entries )
    return 0i64;
  while ( entries->keybase.key.iKey != key )
  {
    entries = entries->nextEntry;
    if ( !entries )
      return 0i64;
  }
  return entries->data;
}

// File Line: 487
// RVA: 0x2587B0
void *__fastcall antlr3HashGet(ANTLR3_HASH_TABLE_struct *table, const char *key)
{
  const char *v2; // r10
  __int64 v3; // r8
  unsigned int i; // r9d
  int v5; // eax
  ANTLR3_HASH_ENTRY_struct *entries; // r9

  v2 = key;
  v3 = -1i64;
  do
    ++v3;
  while ( key[v3] );
  for ( i = 0; (_DWORD)v3; LODWORD(v3) = v3 - 1 )
  {
    v5 = *(unsigned __int8 *)key++;
    i = v5 + 16 * i;
    if ( (i & 0xF0000000) != 0 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  entries = table->buckets[i % table->modulo].entries;
  if ( !entries )
    return 0i64;
  while ( strcmp(v2, entries->keybase.key.sKey) )
  {
    entries = entries->nextEntry;
    if ( !entries )
      return 0i64;
  }
  return entries->data;
}

// File Line: 527
// RVA: 0x2589C0
__int64 __fastcall antlr3HashPutI(
        ANTLR3_HASH_TABLE_struct *table,
        UFG::allocator::free_link *key,
        UFG::allocator::free_link *element,
        UFG::allocator::free_link *freeptr)
{
  ANTLR3_HASH_BUCKET_struct *p_nextEntry; // rbx
  UFG::allocator::free_link *v9; // rax

  p_nextEntry = &table->buckets[(unsigned __int64)key % table->modulo];
  if ( p_nextEntry->entries )
  {
    while ( table->allowDups || (UFG::allocator::free_link *)p_nextEntry->entries->keybase.key.sKey != key )
    {
      p_nextEntry = (ANTLR3_HASH_BUCKET_struct *)&p_nextEntry->entries->nextEntry;
      if ( !p_nextEntry->entries )
        goto LABEL_5;
    }
    return 3i64;
  }
  else
  {
LABEL_5:
    v9 = antlrMalloc(0x28ui64);
    if ( v9 )
    {
      v9[2].mNext = element;
      v9[3].mNext = freeptr;
      LOBYTE(v9->mNext) = 0;
      v9[1].mNext = key;
      v9[4].mNext = 0i64;
      p_nextEntry->entries = (ANTLR3_HASH_ENTRY_struct *)v9;
      ++table->count;
      return 0i64;
    }
    else
    {
      return 1i64;
    }
  }
}

// File Line: 598
// RVA: 0x258890
__int64 __fastcall antlr3HashPut(
        ANTLR3_HASH_TABLE_struct *table,
        const char *key,
        UFG::allocator::free_link *element,
        UFG::allocator::free_link *freeptr)
{
  const char *v6; // rsi
  __int64 v8; // r10
  unsigned int i; // r8d
  int v10; // eax
  ANTLR3_HASH_BUCKET_struct *p_nextEntry; // rbx
  int allowDups; // r9d
  UFG::allocator::free_link *v13; // rax
  ANTLR3_HASH_ENTRY_struct *v14; // rdi

  v6 = key;
  v8 = -1i64;
  do
    ++v8;
  while ( key[v8] );
  for ( i = 0; (_DWORD)v8; LODWORD(v8) = v8 - 1 )
  {
    v10 = *(unsigned __int8 *)key++;
    i = v10 + 16 * i;
    if ( (i & 0xF0000000) != 0 )
      i ^= i & 0xF0000000 ^ ((i & 0xF0000000) >> 24);
  }
  p_nextEntry = &table->buckets[i % table->modulo];
  if ( p_nextEntry->entries )
  {
    allowDups = table->allowDups;
    while ( allowDups || strcmp(v6, p_nextEntry->entries->keybase.key.sKey) )
    {
      p_nextEntry = (ANTLR3_HASH_BUCKET_struct *)&p_nextEntry->entries->nextEntry;
      if ( !p_nextEntry->entries )
        goto LABEL_12;
    }
    return 3i64;
  }
  else
  {
LABEL_12:
    v13 = antlrMalloc(0x28ui64);
    v14 = (ANTLR3_HASH_ENTRY_struct *)v13;
    if ( v13 )
    {
      v13[2].mNext = element;
      v13[3].mNext = freeptr;
      LOBYTE(v13->mNext) = 1;
      if ( table->doStrdup == 1 )
        v13[1].mNext = antlrStrdup(v6);
      else
        v13[1].mNext = (UFG::allocator::free_link *)v6;
      v14->nextEntry = 0i64;
      p_nextEntry->entries = v14;
      ++table->count;
      return 0i64;
    }
    else
    {
      return 1i64;
    }
  }
}

// File Line: 677
// RVA: 0x259B70
__int64 __fastcall antlr3EnumNew(UFG::allocator::free_link *table)
{
  UFG::allocator::free_link *v2; // rax
  ANTLR3_HASH_ENUM_struct *v3; // r11
  ANTLR3_HASH_BUCKET_struct *mNext; // rax
  ANTLR3_HASH_ENTRY_struct *entries; // rcx

  v2 = antlrMalloc(0x28ui64);
  v3 = (ANTLR3_HASH_ENUM_struct *)v2;
  if ( !v2 )
    return 1i64;
  v2->mNext = table;
  LODWORD(v2[1].mNext) = 0;
  mNext = (ANTLR3_HASH_BUCKET_struct *)table[1].mNext;
  entries = mNext->entries;
  v3->entry = mNext->entries;
  if ( !entries )
    antlr3EnumNextEntry(v3);
  v3->free = antlr3EnumFree;
  v3->next = (int (__fastcall *)(ANTLR3_HASH_ENUM_struct *, ANTLR3_HASH_KEY_struct **, void **))antlr3EnumNext;
  return (__int64)v3;
}

// File Line: 733
// RVA: 0x258540
__int64 __fastcall antlr3EnumNext(ANTLR3_HASH_ENUM_struct *en, ANTLR3_HASH_KEY_struct **key, void **data)
{
  ANTLR3_HASH_ENTRY_struct *entry; // rax
  ANTLR3_HASH_ENTRY_struct *nextEntry; // rax
  ANTLR3_HASH_TABLE_struct *table; // r8
  unsigned int bucket; // eax
  ANTLR3_HASH_BUCKET_struct *buckets; // rcx

  if ( en->bucket >= en->table->modulo )
    return 1i64;
  *key = &en->entry->keybase;
  *data = en->entry->data;
  entry = en->entry;
  if ( entry )
  {
    nextEntry = entry->nextEntry;
    if ( nextEntry )
      goto LABEL_10;
  }
  ++en->bucket;
  table = en->table;
  bucket = en->bucket;
  if ( bucket < en->table->modulo )
  {
    while ( 1 )
    {
      buckets = table->buckets;
      if ( buckets[bucket].entries )
        break;
      en->bucket = ++bucket;
      if ( bucket >= table->modulo )
        return 0i64;
    }
    nextEntry = buckets[bucket].entries;
LABEL_10:
    en->entry = nextEntry;
  }
  return 0i64;
}

// File Line: 769
// RVA: 0x2585C0
void __fastcall antlr3EnumNextEntry(ANTLR3_HASH_ENUM_struct *en)
{
  ANTLR3_HASH_ENTRY_struct *entry; // rax
  ANTLR3_HASH_ENTRY_struct *nextEntry; // rax
  ANTLR3_HASH_TABLE_struct *table; // r9
  unsigned int bucket; // eax
  ANTLR3_HASH_ENTRY_struct **p_entries; // r10

  entry = en->entry;
  if ( entry && (nextEntry = entry->nextEntry) != 0i64 )
  {
    en->entry = nextEntry;
  }
  else
  {
    ++en->bucket;
    table = en->table;
    bucket = en->bucket;
    if ( bucket < en->table->modulo )
    {
      while ( 1 )
      {
        p_entries = &table->buckets[bucket].entries;
        if ( *p_entries )
          break;
        en->bucket = ++bucket;
        if ( bucket >= table->modulo )
          return;
      }
      en->entry = *p_entries;
    }
  }
}

// File Line: 838
// RVA: 0x259BE0
__int64 __fastcall antlr3Hash(unsigned __int8 *key, unsigned int keylen)
{
  __int64 result; // rax
  unsigned int i; // r8d
  int v5; // edx

  result = 0i64;
  for ( i = keylen; i; --i )
  {
    v5 = *key++;
    result = (unsigned int)(v5 + 16 * result);
    if ( (result & 0xF0000000) != 0 )
      result = result & 0xF0000000 ^ (((unsigned int)result & 0xF0000000) >> 24) ^ (unsigned int)result;
  }
  return result;
}

// File Line: 867
// RVA: 0x259DD0
__int64 __fastcall antlr3ListNew(unsigned int sizeHint)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v4; // rax

  v2 = antlrMalloc(0x40ui64);
  if ( !v2 )
    return 1i64;
  v4 = antlr3HashTableNew(sizeHint);
  v2->mNext = v4;
  if ( v4 == (UFG::allocator::free_link *)1 )
    return 1i64;
  v2[1].mNext = (UFG::allocator::free_link *)antlr3ListFree;
  v2[2].mNext = (UFG::allocator::free_link *)antlr3ListDelete;
  v2[3].mNext = (UFG::allocator::free_link *)antlr3ListGet;
  v2[5].mNext = (UFG::allocator::free_link *)antlr3ListAdd;
  v2[4].mNext = (UFG::allocator::free_link *)antlr3ListRemove;
  v2[6].mNext = (UFG::allocator::free_link *)antlr3ListPut;
  v2[7].mNext = (UFG::allocator::free_link *)antlr3ListSize;
  return (__int64)v2;
}

// File Line: 902
// RVA: 0x258C80
__int64 __fastcall antlr3ListSize(ANTLR3_LIST_struct *list)
{
  return ((__int64 (__fastcall *)(ANTLR3_HASH_TABLE_struct *))list->table->size)(list->table);
}

// File Line: 908
// RVA: 0x258C20
void __fastcall antlr3ListFree(ANTLR3_LIST_struct *list)
{
  list->table->free(list->table);
  antlrFree((char *)list);
}

// File Line: 920
// RVA: 0x258C10
void __fastcall antlr3ListDelete(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  list->table->delI(list->table, key);
}

// File Line: 926
// RVA: 0x258C40
void *__fastcall antlr3ListGet(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  return list->table->getI(list->table, key);
}

// File Line: 933
// RVA: 0x258BC0
__int64 __fastcall antlr3ListAdd(ANTLR3_LIST_struct *list, void *element, void (__fastcall *freeptr)(void *))
{
  unsigned int v6; // eax

  v6 = list->table->size(list->table);
  return ((__int64 (__fastcall *)(ANTLR3_LIST_struct *, _QWORD, void *, void (__fastcall *)(void *)))list->put)(
           list,
           v6 + 1,
           element,
           freeptr);
}

// File Line: 945
// RVA: 0x258C60
ANTLR3_HASH_ENTRY_struct *__fastcall antlr3ListRemove(ANTLR3_LIST_struct *list, unsigned __int64 key)
{
  ANTLR3_HASH_ENTRY_struct *result; // rax

  result = list->table->removeI(list->table, key);
  if ( result )
    return (ANTLR3_HASH_ENTRY_struct *)result->data;
  return result;
}

// File Line: 962
// RVA: 0x258C50
__int64 __fastcall antlr3ListPut(
        ANTLR3_LIST_struct *list,
        unsigned __int64 key,
        void *element,
        void (__fastcall *freeptr)(void *))
{
  return ((__int64 (__fastcall *)(ANTLR3_HASH_TABLE_struct *, unsigned __int64, void *, void (__fastcall *)(void *)))list->table->putI)(
           list->table,
           key,
           element,
           freeptr);
}

// File Line: 968
// RVA: 0x259F60
__int64 __fastcall antlr3StackNew(unsigned int sizeHint)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rdi

  v2 = antlrMalloc(0x40ui64);
  if ( !v2 )
    return 1i64;
  v4 = antlrMalloc(0x160ui64);
  v5 = (__int64)v4;
  if ( v4 )
    antlr3SetVectorApi((ANTLR3_VECTOR_struct *)v4, sizeHint);
  else
    v5 = 1i64;
  v2->mNext = (UFG::allocator::free_link *)v5;
  v2[1].mNext = 0i64;
  if ( v5 == 1 )
    return 1i64;
  v2[4].mNext = (UFG::allocator::free_link *)antlr3StackGet;
  v2[2].mNext = (UFG::allocator::free_link *)antlr3StackFree;
  v2[3].mNext = (UFG::allocator::free_link *)antlr3StackPop;
  v2[5].mNext = (UFG::allocator::free_link *)antlr3StackPush;
  v2[6].mNext = (UFG::allocator::free_link *)antlr3StackSize;
  v2[7].mNext = (UFG::allocator::free_link *)Scaleform::GFx::Stream::GetLog;
  return (__int64)v2;
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
  stack->vector->free(stack->vector);
  stack->vector = 0i64;
  stack->top = 0i64;
  antlrFree((char *)stack);
}

// File Line: 1022
// RVA: 0x258CD0
void *__fastcall antlr3StackPop(ANTLR3_STACK_struct *stack)
{
  void *result; // rax

  stack->vector->del(stack->vector, stack->vector->count - 1);
  result = stack->vector->get(stack->vector, stack->vector->count - 1);
  stack->top = result;
  return result;
}

// File Line: 1039
// RVA: 0x258CC0
void *__fastcall antlr3StackGet(ANTLR3_STACK_struct *stack, unsigned __int64 key)
{
  return stack->vector->get(stack->vector, key);
}

// File Line: 1051
// RVA: 0x258D10
__int64 __fastcall antlr3StackPush(ANTLR3_STACK_struct *stack, void *element, void (__fastcall *freeptr)(void *))
{
  ANTLR3_VECTOR_struct *vector; // rax

  vector = stack->vector;
  stack->top = element;
  return ((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *, void *, void (__fastcall *)(void *)))vector->add)(
           vector,
           element,
           freeptr);
}

// File Line: 1058
// RVA: 0x25A1E0
__int64 __fastcall antlr3VectorNew(unsigned int sizeHint)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx

  v2 = antlrMalloc(0x160ui64);
  v3 = v2;
  if ( !v2 )
    return 1i64;
  antlr3SetVectorApi((ANTLR3_VECTOR_struct *)v2, sizeHint);
  return (__int64)v3;
}

// File Line: 1082
// RVA: 0x259E70
void __fastcall antlr3SetVectorApi(ANTLR3_VECTOR_struct *vector, unsigned int sizeHint)
{
  unsigned int v2; // edi

  v2 = 16;
  if ( sizeHint > 0x10 )
    v2 = sizeHint;
  if ( sizeHint <= 0x10 )
    vector->elements = vector->internal;
  else
    vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)antlrMalloc(16i64 * v2);
  if ( vector->elements )
  {
    vector->count = 0;
    vector->elementsSize = v2;
    vector->add = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, void *, void (__fastcall *)(void *)))antlr3VectorAdd;
    vector->factoryMade = 0;
    vector->del = antlr3VectorDel;
    vector->get = antlr3VectorGet;
    vector->free = antlr3VectorFree;
    vector->set = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *, unsigned int, void *, void (__fastcall *)(void *), char))antlr3VectorSet;
    vector->remove = antrl3VectorRemove;
    vector->clear = antlr3VectorClear;
    vector->size = (unsigned int (__fastcall *)(ANTLR3_VECTOR_struct *))UFG::DUIIntArray::Count;
    vector->swap = antlr3VectorSwap;
  }
  else
  {
    antlrFree((char *)vector);
  }
}

// File Line: 1140
// RVA: 0x258DE0
void __fastcall antlr3VectorClear(ANTLR3_VECTOR_struct *vector)
{
  unsigned int v2; // esi
  __int64 v3; // rdi
  void (__fastcall *freeptr)(void *); // rdx

  v2 = 0;
  if ( vector->count )
  {
    do
    {
      v3 = v2;
      freeptr = vector->elements[v2].freeptr;
      if ( freeptr )
        freeptr(vector->elements[v2].element);
      ++v2;
      vector->elements[v3].freeptr = 0i64;
      vector->elements[v3].element = 0i64;
    }
    while ( v2 < vector->count );
    vector->count = 0;
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
  unsigned int i; // esi
  __int64 v3; // rdi
  void (__fastcall *freeptr)(void *); // rdx

  for ( i = 0; i < vector->count; vector->elements[v3].element = 0i64 )
  {
    v3 = i;
    freeptr = vector->elements[i].freeptr;
    if ( freeptr )
      freeptr(vector->elements[i].element);
    ++i;
    vector->elements[v3].freeptr = 0i64;
  }
  if ( !vector->factoryMade )
  {
    if ( vector->elementsSize > 0x10 )
      antlrFree((char *)vector->elements);
    vector->elements = 0i64;
    antlrFree((char *)vector);
  }
}

// File Line: 1199
// RVA: 0x258E60
void __fastcall antlr3VectorDel(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  __int64 v4; // rdi
  void (__fastcall *freeptr)(void *); // rdx
  unsigned int count; // r8d

  if ( entry < vector->count )
  {
    v4 = entry;
    freeptr = vector->elements[v4].freeptr;
    if ( freeptr )
    {
      freeptr(vector->elements[entry].element);
      vector->elements[v4].freeptr = 0i64;
    }
    count = vector->count;
    if ( entry == count - 1 )
      vector->elements[v4].element = 0i64;
    else
      UFG::qMemMove(&vector->elements[v4], (char *)&vector->elements[v4 + 1], 16 * (count - entry - 1));
    --vector->count;
  }
}

// File Line: 1235
// RVA: 0x258F90
void *__fastcall antlr3VectorGet(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  if ( entry >= vector->count )
    return 0i64;
  else
    return vector->elements[entry].element;
}

// File Line: 1254
// RVA: 0x259150
void *__fastcall antrl3VectorRemove(ANTLR3_VECTOR_struct *vector, unsigned int entry)
{
  unsigned int count; // r8d
  ANTLR3_VECTOR_ELEMENT_struct *elements; // r9
  __int64 v6; // rcx
  ANTLR3_VECTOR_ELEMENT_struct *v7; // r9
  void *element; // rdi

  count = vector->count;
  if ( entry >= count )
    return 0i64;
  elements = vector->elements;
  v6 = entry;
  v7 = &elements[v6];
  element = v7->element;
  if ( entry == count - 1 )
  {
    v7->element = 0i64;
    vector->elements[v6].freeptr = 0i64;
  }
  else
  {
    UFG::qMemMove(v7, (char *)&v7[1], 16 * (count - entry - 1));
  }
  --vector->count;
  return element;
}

// File Line: 1293
// RVA: 0x258FB0
void __fastcall antlr3VectorResize(ANTLR3_VECTOR_struct *vector, unsigned int hint)
{
  unsigned int elementsSize; // eax
  unsigned int v4; // edi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rax

  if ( hint && (elementsSize = vector->elementsSize, hint >= elementsSize) )
  {
    v4 = 2 * hint;
  }
  else
  {
    elementsSize = vector->elementsSize;
    v4 = 2 * elementsSize;
  }
  if ( elementsSize <= 0x10 )
  {
    v6 = antlrMalloc(16i64 * v4);
    vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v6;
    UFG::qMemCopy(v6, vector->internal, 0x100u);
    vector->elementsSize = v4;
  }
  else
  {
    v5 = antlrRealloc(vector->elements, 16i64 * v4);
    vector->elementsSize = v4;
    vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v5;
  }
}

// File Line: 1336
// RVA: 0x258D40
__int64 __fastcall antlr3VectorAdd(ANTLR3_VECTOR_struct *vector, void *element, void (__fastcall *freeptr)(void *))
{
  unsigned int elementsSize; // eax
  unsigned int v7; // edi
  UFG::allocator::free_link *v8; // rax

  elementsSize = vector->elementsSize;
  if ( vector->count == elementsSize )
  {
    v7 = 2 * elementsSize;
    if ( elementsSize <= 0x10 )
    {
      v8 = antlrMalloc(16i64 * v7);
      vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)v8;
      UFG::qMemCopy(v8, vector->internal, 0x100u);
    }
    else
    {
      vector->elements = (ANTLR3_VECTOR_ELEMENT_struct *)antlrRealloc(vector->elements, 16i64 * v7);
    }
    vector->elementsSize = v7;
  }
  vector->elements[vector->count].element = element;
  vector->elements[vector->count++].freeptr = freeptr;
  return vector->count;
}

// File Line: 1360
// RVA: 0x259040
__int64 __fastcall antlr3VectorSet(
        ANTLR3_VECTOR_struct *vector,
        unsigned int entry,
        void *element,
        void (__fastcall *freeptr)(void *),
        char freeExisting)
{
  __int64 v7; // rbx
  void (__fastcall *v9)(void *); // rdx
  __int64 v10; // rcx

  v7 = entry;
  if ( entry >= vector->elementsSize )
    antlr3VectorResize(vector, entry);
  if ( (unsigned int)v7 < vector->count )
  {
    if ( freeExisting )
    {
      v9 = vector->elements[v7].freeptr;
      if ( v9 )
        v9(vector->elements[v7].element);
    }
  }
  v10 = v7;
  vector->elements[v10].freeptr = freeptr;
  vector->elements[v10].element = element;
  if ( (unsigned int)v7 >= vector->count )
    vector->count = v7 + 1;
  return (unsigned int)v7;
}

// File Line: 1397
// RVA: 0x2590E0
char __fastcall antlr3VectorSwap(ANTLR3_VECTOR_struct *vector, unsigned int entry1, unsigned int entry2)
{
  unsigned int elementsSize; // eax
  __int64 v4; // r11
  __int64 v5; // r9
  ANTLR3_VECTOR_ELEMENT_struct *v6; // rdx
  void *element; // r10
  void (__fastcall *freeptr)(void *); // r8

  elementsSize = vector->elementsSize;
  if ( entry1 >= elementsSize || entry2 >= elementsSize )
    return 0;
  v4 = entry1;
  v5 = entry2;
  v6 = &vector->elements[entry1];
  element = v6->element;
  freeptr = v6->freeptr;
  v6->freeptr = vector->elements[v5].freeptr;
  vector->elements[v4].element = vector->elements[v5].element;
  vector->elements[v5].freeptr = freeptr;
  vector->elements[v5].element = element;
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
      antlrFree((char *)0xFFFFFFFFFFFFFFF0i64);
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
    return (UFG::allocator::free_link *)v2;
  }
  return result;
}

// File Line: 1476
// RVA: 0x259890
void __fastcall returnVector(ANTLR3_VECTOR_FACTORY_struct *factory, ANTLR3_VECTOR_struct *vector)
{
  vector->clear(vector);
  factory->freeStack->push(factory->freeStack, vector, 0i64);
}

// File Line: 1523
// RVA: 0x2591D0
void __fastcall closeVectorFactory(ANTLR3_VECTOR_FACTORY_struct *factory)
{
  ANTLR3_STACK_struct *freeStack; // rax
  int thisPool; // edx
  int v4; // ebp
  __int64 v5; // r14
  ANTLR3_VECTOR_struct *v6; // rbx
  unsigned int nextVector; // eax
  __int64 v8; // rdi
  int v9; // eax
  int v10; // ebp
  __int64 v11; // r14
  ANTLR3_VECTOR_struct *v12; // rbx
  unsigned int v13; // eax
  __int64 v14; // rdi

  freeStack = factory->freeStack;
  if ( freeStack )
    freeStack->free(factory->freeStack);
  thisPool = factory->thisPool;
  v4 = 0;
  if ( thisPool >= 0 )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = factory->pools[v5];
      if ( v4 != thisPool )
        break;
      nextVector = factory->nextVector;
      if ( nextVector )
        goto LABEL_9;
LABEL_11:
      thisPool = factory->thisPool;
      ++v4;
      ++v5;
      if ( v4 > thisPool )
        goto LABEL_12;
    }
    nextVector = 256;
LABEL_9:
    v8 = nextVector;
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
  v9 = factory->thisPool;
  v10 = 0;
  if ( v9 >= 0 )
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = factory->pools[v11];
      if ( v10 != v9 )
        break;
      v13 = factory->nextVector;
      if ( v13 )
        goto LABEL_18;
LABEL_23:
      antlrFree((char *)factory->pools[v11]);
      ++v10;
      factory->pools[v11] = 0i64;
      v9 = factory->thisPool;
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
        antlrFree((char *)v12->elements);
        v12->elements = 0i64;
      }
      ++v12;
      --v14;
    }
    while ( v14 );
    goto LABEL_23;
  }
LABEL_24:
  antlrFree((char *)factory->pools);
  antlrFree((char *)factory);
}

// File Line: 1636
// RVA: 0x259730
ANTLR3_VECTOR_struct *__fastcall newVector(ANTLR3_VECTOR_FACTORY_struct *factory)
{
  void *v2; // rbx
  ANTLR3_VECTOR_struct *v4; // rbx

  v2 = factory->freeStack->peek(factory->freeStack);
  if ( v2 )
  {
    factory->freeStack->pop(factory->freeStack);
    return (ANTLR3_VECTOR_struct *)v2;
  }
  else
  {
    if ( factory->nextVector >= 0x100 )
    {
      ++factory->thisPool;
      factory->pools = (ANTLR3_VECTOR_struct **)antlrRealloc(factory->pools, (unsigned int)(8 * factory->thisPool + 8));
      factory->pools[factory->thisPool] = (ANTLR3_VECTOR_struct *)antlrMalloc(0x16000ui64);
      factory->nextVector = 0;
    }
    v4 = &factory->pools[factory->thisPool][factory->nextVector++];
    v4->elements = v4->internal;
    if ( v4 == (ANTLR3_VECTOR_struct *)-16i64 )
    {
      antlrFree((char *)0xFFFFFFFFFFFFFFF0i64);
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
    return v4;
  }
}

// File Line: 1766
// RVA: 0x259D30
__int64 __fastcall antlr3IntTrieNew(unsigned int depth)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v2 = antlrCalloc(1u, 0x38u);
  if ( !v2 )
    return 1i64;
  v3 = antlrCalloc(1u, 0x38u);
  v2->mNext = v3;
  if ( !v3 )
  {
    antlrFree((char *)v2);
    return 1i64;
  }
  v2[5].mNext = (UFG::allocator::free_link *)intTrieAdd;
  v2[4].mNext = (UFG::allocator::free_link *)Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat;
  v2[6].mNext = (UFG::allocator::free_link *)intTrieFree;
  v2[3].mNext = (UFG::allocator::free_link *)intTrieGet;
  LODWORD(v3->mNext) = depth;
  v2->mNext[3].mNext = v2->mNext;
  v2->mNext[4].mNext = v2->mNext;
  LODWORD(v2[2].mNext) = 0;
  return (__int64)v2;
}

// File Line: 1819
// RVA: 0x2596E0
ANTLR3_TRIE_ENTRY_struct *__fastcall intTrieGet(ANTLR3_INT_TRIE_struct *trie, unsigned __int64 key)
{
  ANTLR3_INT_TRIE_NODE_struct *root; // rcx
  ANTLR3_INT_TRIE_NODE_struct *leftN; // rax
  unsigned int bitNum; // edx
  ANTLR3_INT_TRIE_NODE_struct *v6; // r8

  if ( !trie->count )
    return 0i64;
  root = trie->root;
  leftN = root->leftN;
  bitNum = leftN->bitNum;
  if ( root->bitNum > leftN->bitNum )
  {
    do
    {
      v6 = leftN;
      if ( (key & bitMask[bitNum]) != 0 )
        leftN = leftN->rightN;
      else
        leftN = leftN->leftN;
      bitNum = leftN->bitNum;
    }
    while ( v6->bitNum > leftN->bitNum );
  }
  if ( leftN->key == key )
    return leftN->buckets;
  else
    return 0i64;
}

// File Line: 1911
// RVA: 0x259410
char __fastcall intTrieAdd(
        ANTLR3_INT_TRIE_struct *trie,
        UFG::allocator::free_link *key,
        unsigned int type,
        UFG::allocator::free_link *intVal,
        UFG::allocator::free_link *data,
        void (__fastcall *freeptr)(void *))
{
  ANTLR3_INT_TRIE_NODE_struct *root; // rbp
  ANTLR3_INT_TRIE_NODE_struct *leftN; // rdi
  __int64 bitNum; // rax
  ANTLR3_INT_TRIE_NODE_struct *v13; // rbx
  ANTLR3_INT_TRIE_NODE_struct *v14; // r9
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rdx
  ANTLR3_TRIE_ENTRY_struct *buckets; // rcx
  __int64 p_next; // rax
  bool v21; // zf
  unsigned __int64 v22; // rax
  __int64 v23; // rbx
  __int64 i; // rax
  UFG::allocator::free_link *v25; // rsi
  UFG::allocator::free_link *v26; // rax

  root = trie->root;
  leftN = trie->root->leftN;
  bitNum = leftN->bitNum;
  v13 = leftN;
  if ( trie->root->bitNum > (unsigned int)bitNum )
  {
    do
    {
      v14 = v13;
      if ( ((unsigned __int64)key & bitMask[bitNum]) != 0 )
        v13 = v13->rightN;
      else
        v13 = v13->leftN;
      bitNum = v13->bitNum;
    }
    while ( v14->bitNum > (unsigned int)bitNum );
  }
  v15 = v13->key;
  if ( (UFG::allocator::free_link *)v15 == key )
  {
    if ( trie->allowDups == 1 && (v16 = antlrCalloc(1u, 0x20u), (v17 = v16) != 0i64) )
    {
      LODWORD(v16->mNext) = type;
      if ( type == 1 )
        intVal = data;
      v16[1].mNext = (UFG::allocator::free_link *)freeptr;
      v16[2].mNext = intVal;
      buckets = v13->buckets;
      p_next = (__int64)&buckets->next;
      if ( buckets->next )
      {
        do
        {
          buckets = *(ANTLR3_TRIE_ENTRY_struct **)p_next;
          v21 = *(_QWORD *)(*(_QWORD *)p_next + 24i64) == 0i64;
          p_next = *(_QWORD *)p_next + 24i64;
        }
        while ( !v21 );
      }
      buckets->next = (ANTLR3_TRIE_ENTRY_struct *)v17;
      ++trie->count;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v22 = (unsigned __int64)key ^ v15;
    if ( (v22 & 0xFFFFFFFF00000000ui64) != 0 )
    {
      if ( (v22 & 0xFFFF000000000000ui64) != 0 )
      {
        if ( (v22 & 0xFF00000000000000ui64) != 0 )
          v23 = (unsigned int)(unsigned __int8)bitIndex[HIBYTE(v22)] + 56;
        else
          v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE6(v22)] + 48;
      }
      else if ( (v22 & 0xFF0000000000i64) != 0 )
      {
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE5(v22)] + 40;
      }
      else
      {
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE4(v22)] + 32;
      }
    }
    else if ( (v22 & 0xFFFF0000) != 0 )
    {
      if ( (v22 & 0xFF000000) != 0 )
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE3(v22)] + 24;
      else
        v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE2(v22)] + 16;
    }
    else if ( (v22 & 0xFF00) != 0 )
    {
      v23 = (unsigned int)(unsigned __int8)bitIndex[BYTE1(v22)] + 8;
    }
    else
    {
      v23 = (unsigned __int8)bitIndex[(unsigned __int8)v22];
    }
    for ( i = leftN->bitNum; root->bitNum > (unsigned int)i; i = leftN->bitNum )
    {
      if ( (unsigned int)i <= (unsigned int)v23 )
        break;
      root = leftN;
      leftN = ((unsigned __int64)key & bitMask[i]) != 0 ? leftN->rightN : leftN->leftN;
    }
    v25 = antlrCalloc(1u, 0x28u);
    if ( v25 && (v26 = antlrCalloc(1u, 0x20u)) != 0i64 )
    {
      LODWORD(v26->mNext) = type;
      if ( type == 1 )
        intVal = data;
      v26[1].mNext = (UFG::allocator::free_link *)freeptr;
      v26[2].mNext = intVal;
      v25[2].mNext = v26;
      v25[1].mNext = key;
      LODWORD(v25->mNext) = v23;
      if ( ((unsigned __int64)key & bitMask[v23]) != 0 )
      {
        v25[3].mNext = (UFG::allocator::free_link *)leftN;
        v25[4].mNext = v25;
      }
      else
      {
        v25[4].mNext = (UFG::allocator::free_link *)leftN;
        v25[3].mNext = v25;
      }
      if ( ((unsigned __int64)key & bitMask[root->bitNum]) != 0 )
        root->rightN = (ANTLR3_INT_TRIE_NODE_struct *)v25;
      else
        root->leftN = (ANTLR3_INT_TRIE_NODE_struct *)v25;
      ++trie->count;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 2188
// RVA: 0x2592F0
void __fastcall freeIntNode(ANTLR3_INT_TRIE_NODE_struct *node)
{
  ANTLR3_INT_TRIE_NODE_struct *leftN; // rcx
  ANTLR3_INT_TRIE_NODE_struct *rightN; // rcx
  ANTLR3_TRIE_ENTRY_struct *buckets; // rbx
  ANTLR3_TRIE_ENTRY_struct *next; // rdi
  void (__fastcall *freeptr)(void *); // rax

  leftN = node->leftN;
  if ( node->bitNum > leftN->bitNum )
    freeIntNode(leftN);
  rightN = node->rightN;
  if ( node->bitNum > rightN->bitNum )
    freeIntNode(rightN);
  buckets = node->buckets;
  if ( buckets )
  {
    do
    {
      next = buckets->next;
      if ( buckets->type == 1 )
      {
        freeptr = buckets->freeptr;
        if ( freeptr )
          freeptr(buckets->data.ptr);
      }
      antlrFree((char *)buckets);
      buckets = next;
    }
    while ( next );
  }
  antlrFree((char *)node);
}

// File Line: 2247
// RVA: 0x2596C0
void __fastcall intTrieFree(ANTLR3_INT_TRIE_struct *trie)
{
  freeIntNode(trie->root);
  antlrFree((char *)trie);
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
  ANTLR3_BITSET_struct **edges; // rcx
  unsigned int v5; // edi
  __int64 v7; // rbp
  ANTLR3_BITSET_struct **v8; // rax
  ANTLR3_BITSET_struct **v9; // rax
  unsigned int limit; // eax
  __int64 v11; // rcx
  __int64 v12; // rdx
  UFG::allocator::free_link *v13; // rax

  edges = topo->edges;
  v5 = dependency;
  v7 = edge;
  if ( edge > dependency )
    v5 = edge;
  if ( edges )
  {
    if ( topo->limit <= v5 )
    {
      v9 = (ANTLR3_BITSET_struct **)antlrRealloc(edges, 8i64 * (v5 + 1));
      topo->edges = v9;
      if ( !v9 )
        return;
      limit = topo->limit;
      if ( limit <= v5 )
      {
        v11 = limit;
        v12 = v5 - limit + 1;
        do
        {
          topo->edges[v11++] = 0i64;
          --v12;
        }
        while ( v12 );
      }
      topo->limit = v5 + 1;
    }
  }
  else
  {
    v8 = (ANTLR3_BITSET_struct **)antlrCalloc(8 * v5 + 8, 1u);
    topo->edges = v8;
    if ( !v8 )
      return;
    topo->limit = v5 + 1;
  }
  if ( (_DWORD)v7 != dependency )
  {
    v13 = (UFG::allocator::free_link *)topo->edges[v7];
    if ( v13 || (v13 = antlr3BitsetNew(0), (topo->edges[v7] = (ANTLR3_BITSET_struct *)v13) != 0i64) )
      ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v13[6].mNext)(v13, dependency);
  }
}

// File Line: 2413
// RVA: 0x258320
void __fastcall DFS(ANTLR3_TOPO_struct *topo, unsigned int node)
{
  __int64 v2; // rsi
  unsigned int cycleMark; // edx
  __int64 i; // rdi
  unsigned int v6; // r9d
  unsigned int *cycle; // r8
  unsigned int v8; // eax
  __int64 v9; // rcx
  ANTLR3_BITSET_struct *visited; // rax
  ANTLR3_BITSET_struct *v11; // rbp
  unsigned int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // [rsp+40h] [rbp+8h]

  v2 = node;
  if ( topo->hasCycle != 1 )
  {
    if ( topo->visited->isMember(topo->visited, node) )
    {
      cycleMark = topo->cycleMark;
      for ( i = 0i64; (unsigned int)i < cycleMark; i = (unsigned int)(i + 1) )
      {
        if ( topo->cycle[i] == (_DWORD)v2 )
        {
          v6 = i;
          if ( (unsigned int)i < cycleMark )
          {
            do
            {
              cycle = topo->cycle;
              v8 = cycle[v6];
              v9 = v6 - (unsigned int)i;
              ++v6;
              cycle[v9] = v8;
            }
            while ( v6 < topo->cycleMark );
          }
          topo->cycleMark -= i;
          topo->hasCycle = 1;
        }
        cycleMark = topo->cycleMark;
      }
    }
    else
    {
      topo->cycle[topo->cycleMark] = v2;
      visited = topo->visited;
      ++topo->cycleMark;
      visited->add(visited, v2);
      v11 = topo->edges[v2];
      if ( v11 )
      {
        v14 = v11->numBits(topo->edges[v2]);
        v12 = 0;
        v13 = v11->size(v11);
        do
        {
          if ( !v13 )
            break;
          if ( v11->isMember(v11, v12) )
          {
            --v13;
            DFS(topo, v12);
          }
          ++v12;
        }
        while ( v12 <= v14 );
        LODWORD(v2) = node;
      }
      topo->sorted[topo->limit++] = v2;
      if ( !topo->hasCycle )
        --topo->cycleMark;
    }
  }
}

// File Line: 2521
// RVA: 0x2598D0
unsigned int *__fastcall sortToArray(ANTLR3_TOPO_struct *topo)
{
  unsigned int *result; // rax
  unsigned int *v3; // rax
  unsigned __int64 v4; // rcx
  UFG::allocator::free_link *v5; // rax
  unsigned int limit; // r13d
  unsigned int v7; // r15d
  __int64 v8; // r12
  unsigned int cycleMark; // edx
  __int64 i; // r10
  unsigned int v11; // r9d
  unsigned int *cycle; // r8
  unsigned int v13; // eax
  __int64 v14; // rcx
  ANTLR3_BITSET_struct *visited; // rax
  ANTLR3_BITSET_struct *v16; // rbp
  unsigned int v17; // r14d
  unsigned int v18; // edi
  unsigned int v19; // esi

  if ( !topo->edges )
    return 0i64;
  v3 = (unsigned int *)antlrMalloc(4i64 * topo->limit);
  v4 = 4i64 * topo->limit;
  topo->sorted = v3;
  topo->cycle = (unsigned int *)antlrMalloc(v4);
  v5 = antlr3BitsetNew(0);
  limit = topo->limit;
  v7 = 0;
  topo->visited = (ANTLR3_BITSET_struct *)v5;
  topo->limit = 0;
  if ( limit )
  {
    v8 = 0i64;
    do
    {
      if ( !topo->visited->isMember(topo->visited, v7) )
      {
        if ( topo->hasCycle == 1 )
          break;
        if ( topo->visited->isMember(topo->visited, v7) )
        {
          cycleMark = topo->cycleMark;
          for ( i = 0i64; (unsigned int)i < cycleMark; i = (unsigned int)(i + 1) )
          {
            if ( topo->cycle[i] == v7 )
            {
              v11 = i;
              if ( (unsigned int)i < cycleMark )
              {
                do
                {
                  cycle = topo->cycle;
                  v13 = cycle[v11];
                  v14 = v11 - (unsigned int)i;
                  ++v11;
                  cycle[v14] = v13;
                }
                while ( v11 < topo->cycleMark );
              }
              topo->cycleMark -= i;
              topo->hasCycle = 1;
            }
            cycleMark = topo->cycleMark;
          }
        }
        else
        {
          topo->cycle[topo->cycleMark] = v7;
          visited = topo->visited;
          ++topo->cycleMark;
          visited->add(visited, v7);
          v16 = topo->edges[v8];
          if ( v16 )
          {
            v17 = v16->numBits(topo->edges[v8]);
            v18 = 0;
            v19 = v16->size(v16);
            do
            {
              if ( !v19 )
                break;
              if ( v16->isMember(v16, v18) )
              {
                --v19;
                DFS(topo, v18);
              }
              ++v18;
            }
            while ( v18 <= v17 );
          }
          topo->sorted[topo->limit++] = v7;
          if ( !topo->hasCycle )
            --topo->cycleMark;
        }
      }
      if ( topo->hasCycle == 1 )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < limit );
  }
  result = topo->sorted;
  topo->limit = limit;
  return result;
}

// File Line: 2589
// RVA: 0x259AA0
void __fastcall sortVector(ANTLR3_TOPO_struct *topo, ANTLR3_VECTOR_struct *v)
{
  unsigned int count; // eax
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rbx
  char *v7; // rsi
  unsigned int i; // edx
  unsigned int v9; // ebp

  if ( ((__int64 (*)(void))topo->sortToArray)() && topo->hasCycle != 1 )
  {
    count = v->count;
    if ( topo->limit > count )
      topo->limit = count;
    v5 = antlrMalloc(4i64 * topo->limit);
    v6 = 0i64;
    v7 = (char *)v5;
    for ( i = 0; i < topo->limit; ++i )
      *((_DWORD *)&v5->mNext + i) = i;
    if ( topo->limit )
    {
      do
      {
        v9 = *(_DWORD *)&v7[4 * topo->sorted[v6]];
        if ( v9 != (_DWORD)v6 )
        {
          v->swap(v, v6, v9);
          *(_DWORD *)&v7[4 * topo->sorted[v6]] = v6;
          *(_DWORD *)&v7[4 * v6] = v9;
        }
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < topo->limit );
    }
    antlrFree(v7);
  }
}

// File Line: 2690
// RVA: 0x259370
void __fastcall freeTopo(ANTLR3_TOPO_struct *topo)
{
  unsigned int *sorted; // rcx
  ANTLR3_BITSET_struct *visited; // rax
  __int64 i; // rdi
  ANTLR3_BITSET_struct *v5; // rdx
  unsigned int *cycle; // rcx

  sorted = topo->sorted;
  if ( sorted )
  {
    antlrFree((char *)sorted);
    topo->sorted = 0i64;
  }
  visited = topo->visited;
  if ( visited )
  {
    visited->free(topo->visited);
    topo->visited = 0i64;
  }
  if ( topo->edges )
  {
    for ( i = 0i64; (unsigned int)i < topo->limit; i = (unsigned int)(i + 1) )
    {
      v5 = topo->edges[i];
      if ( v5 )
        v5->free(topo->edges[i]);
    }
    antlrFree((char *)topo->edges);
  }
  cycle = topo->cycle;
  topo->edges = 0i64;
  if ( cycle )
    antlrFree((char *)cycle);
  antlrFree((char *)topo);
}

