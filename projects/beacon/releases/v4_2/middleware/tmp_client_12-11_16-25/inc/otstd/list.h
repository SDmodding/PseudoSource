// File Line: 174
// RVA: 0xED0958
void __fastcall OSuite::TList<OSuite::ZString>::TList<OSuite::ZString>(OSuite::TList<OSuite::ZString> *this, OSuite::TList<OSuite::ZString> *that)
{
  OSuite::TList<OSuite::ZString> *v2; // rbp
  OSuite::TList<OSuite::ZString> *v3; // rbx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi

  v2 = that;
  v3 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)this,
    (OSuite::ZListBase::ZListIteratorBase *)that);
  v4 = v3->m_nSize;
  v5 = 0i64;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  v3->m_pList = 0i64;
  v3->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  if ( v4 )
    v3->m_pList = OSuite::TList<OSuite::ZString>::AllocList(v3, 0i64, v4);
  if ( v3->m_nTop > 0 )
  {
    v6 = 0i64;
    do
    {
      OSuite::ZString::operator=(&v3->m_pList[v6], &v2->m_pList[v6]);
      ++v5;
      ++v6;
    }
    while ( v5 < v3->m_nTop );
  }
}

// File Line: 200
// RVA: 0xED0BC8
OSuite::TList<OSuite::ZString> *__fastcall OSuite::TList<OSuite::ZString>::operator=(OSuite::TList<OSuite::ZString> *this, OSuite::TList<OSuite::ZString> *that)
{
  OSuite::TList<OSuite::ZString> *v2; // rbp
  OSuite::TList<OSuite::ZString> *v3; // rbx
  OSuite::ZString *v4; // rcx
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    v4 = this->m_pList;
    v5 = 0i64;
    if ( v4 )
    {
      if ( LODWORD(v4[-1].m_pString) )
        v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 3u);
      else
        Illusion::ShaderParam::operator delete(&v4[-1].m_pString);
    }
    OSuite::ZListBase::operator=((OSuite::ZListBase *)&v3->vfptr, (OSuite::ZListBase *)&v2->vfptr);
    v3->m_pList = OSuite::TList<OSuite::ZString>::AllocList(v3, (OSuite::ZObject *)&v3->m_pList->vfptr, v3->m_nSize);
    if ( v3->m_nTop > 0 )
    {
      v6 = 0i64;
      do
      {
        OSuite::ZString::operator=(&v3->m_pList[v6], &v2->m_pList[v6]);
        ++v5;
        ++v6;
      }
      while ( v5 < v3->m_nTop );
    }
  }
  return v3;
}

// File Line: 262
// RVA: 0xED9EB0
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Append(OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *this, OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *element)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v2; // rdi
  OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *v3; // rsi
  signed __int64 v4; // rbx
  unsigned __int64 v5; // rcx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *result; // rax

  v2 = element;
  v3 = this;
  OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(this, this->m_nTop + 1);
  v4 = (signed __int64)&v3->m_pList[v3->m_nTop];
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)v4, (OSuite::ZObject *)&v2->vfptr);
  *(_DWORD *)(v4 + 8) = v2->refCount;
  OSuite::ZString::operator=((OSuite::ZString *)(v4 + 16), &v2->name);
  *(_QWORD *)(v4 + 40) = v2->pWebServiceClient;
  v5 = v3->m_nTop;
  result = &v3->m_pList[v5];
  v3->m_nTop = v5 + 1;
  return result;
}

// File Line: 315
// RVA: 0xEC81A0
void __fastcall OSuite::TList<OSuite::ZConsumableInfoBase *>::RemoveIndex(OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *this, unsigned __int64 nIndex)
{
  unsigned __int64 i; // r8

  for ( i = nIndex; i < this->m_nTop - 1; ++i )
    this->m_pList[i] = this->m_pList[i + 1];
  --this->m_nTop;
}

// File Line: 341
// RVA: 0x1331188
void __fastcall OSuite::TList<OSuite::ZConsumableInfoBase *>::Insert(OSuite::TList<OSuite::ZConsumableInfoBase *> *this, unsigned __int64 nIndex, unsigned __int64 nCount, OSuite::ZConsumableInfoBase *const *Element)
{
  unsigned __int64 v4; // rdi
  OSuite::ZConsumableInfoBase *const *v5; // r14
  unsigned __int64 v6; // rsi
  OSuite::TList<OSuite::ZConsumableInfoBase *> *v7; // rbx
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r11
  unsigned __int64 v10; // rdx

  v4 = nIndex;
  v5 = Element;
  v6 = nCount;
  v7 = this;
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)this,
    nCount + this->m_nTop);
  v8 = v4 + v6;
  v9 = v6 + v7->m_nTop - 1;
  if ( v9 >= v4 + v6 )
  {
    do
    {
      v10 = v9--;
      v7->m_pList[v10] = *(OSuite::ZConsumableInfoBase **)((char *)v7->m_pList + 8 * v10 - 8 * v6);
    }
    while ( v9 >= v8 );
  }
  while ( v4 < v8 )
    v7->m_pList[v4++] = *v5;
  v7->m_nTop += v6;
}

// File Line: 413
// RVA: 0xED0CAC
char __fastcall OSuite::TList<OSuite::ZString>::operator==(OSuite::TList<OSuite::ZString> *this, OSuite::TList<OSuite::ZString> *that)
{
  unsigned __int64 v2; // rax
  OSuite::TList<OSuite::ZString> *v3; // r15
  OSuite::TList<OSuite::ZString> *v4; // rbp
  unsigned __int64 v6; // rsi
  __int64 v7; // r14
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rdi
  bool v10; // bl
  OSuite::ZString v11; // [rsp+20h] [rbp-48h]

  v2 = this->m_nTop;
  v3 = that;
  v4 = this;
  if ( v2 != that->m_nTop )
    return 0;
  v6 = 0i64;
  if ( v2 )
  {
    v7 = 0i64;
    while ( 1 )
    {
      OSuite::ZString::ZString(&v11, &v3->m_pList[v7]);
      v9 = v8;
      v10 = OSuite::ZString::operator==(&v4->m_pList[v7], v8) == 0;
      OSuite::ZString::~ZString(v9);
      if ( v10 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= v4->m_nTop )
        return 1;
    }
    return 0;
  }
  return 1;
}

// File Line: 431
// RVA: 0xED0D84
bool __fastcall OSuite::TList<OSuite::ZString>::operator<(OSuite::TList<OSuite::ZString> *this, OSuite::TList<OSuite::ZString> *that)
{
  unsigned __int64 v2; // rax
  OSuite::TList<OSuite::ZString> *v3; // r13
  OSuite::TList<OSuite::ZString> *v4; // rbp
  unsigned __int64 v6; // r14
  __int64 v7; // r15
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rdi
  bool v10; // bl
  OSuite::ZString v11; // [rsp+20h] [rbp-48h]

  v2 = that->m_nTop;
  v3 = that;
  v4 = this;
  if ( this->m_nTop != v2 )
    return this->m_nTop < v2;
  v6 = 0i64;
  if ( !this->m_nTop )
    return 0;
  v7 = 0i64;
  while ( 1 )
  {
    OSuite::ZString::ZString(&v11, &v3->m_pList[v7]);
    v9 = v8;
    v10 = OSuite::ZString::operator==(&v4->m_pList[v7], v8) == 0;
    OSuite::ZString::~ZString(v9);
    if ( v10 )
      break;
    ++v6;
    ++v7;
    if ( v6 >= v4->m_nTop )
      return 0;
  }
  return OSuite::ZString::operator<(&v4->m_pList[v6], &v3->m_pList[v6]);
}

// File Line: 467
// RVA: 0xEC4A44
unsigned int __fastcall OSuite::TList<OSuite::ZString>::ComputeHash(OSuite::TList<OSuite::ZString> *this)
{
  OSuite::TList<OSuite::ZString> *v1; // rbx
  unsigned int v2; // er14
  unsigned __int64 v3; // rdi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rsi
  signed __int64 v6; // rcx
  unsigned int v7; // eax
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h]
  void **v10; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-20h]

  v1 = this;
  v11.m_pListBase = 0i64;
  v2 = OSuite::FComputeHashBegin((_exception *)this);
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v1[-1].m_nTop);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v3 = v11.m_nIndex;
    v4 = v11.m_pListBase;
    v5 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v11.m_pListBase, v11.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = v4[1].m_nSize + 24 * v3;
    if ( v6 )
      v6 += 8i64;
    v7 = (*(__int64 (**)(void))(*(_QWORD *)v6 + 8i64))();
    v2 = OSuite::FComputeHashAdd(v2, v7);
    OSuite::ZListBase::ZListIteratorBase::Next(&v11);
  }
  v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  return OSuite::FComputeHashEnd(v2);
}

// File Line: 534
// RVA: 0xECC9B0
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *this, OSuite::ZObject *__formal, unsigned __int64 nElements)
{
  int v3; // ebx
  unsigned __int64 v4; // rax
  unsigned __int8 v5; // cf
  unsigned __int64 v6; // rax
  OSuite::ZString *v7; // rax
  int v8; // esi
  signed __int64 v9; // rdi
  OSuite::ZString *v10; // rbx

  v3 = nElements;
  if ( !nElements )
    return 0i64;
  v4 = 48 * nElements;
  if ( !is_mul_ok(nElements, 0x30ui64) )
    v4 = -1i64;
  v5 = __CFADD__(v4, 8i64);
  v6 = v4 + 8;
  if ( v5 )
    v6 = -1i64;
  v7 = (OSuite::ZString *)OSuite::ZObject::operator new(v6);
  if ( !v7 )
    return 0i64;
  v8 = v3 - 1;
  LODWORD(v7->vfptr) = v3;
  v9 = (signed __int64)&v7->vfptr;
  if ( v3 - 1 >= 0 )
  {
    v10 = v7 + 1;
    do
    {
      LODWORD(v10[-1].m_pString) = 0;
      v10[-1].vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::`vftable;
      OSuite::ZString::ZString(v10, &customWorldMapCaption);
      v10 += 2;
      --v8;
    }
    while ( v8 >= 0 );
  }
  return (OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *)v9;
}

// File Line: 576
// RVA: 0xEC58A0
void __fastcall OSuite::TList<OSuite::ZONavigationProperty *>::Grow(OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *this, unsigned __int64 nNewSize)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rbx
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase **v5; // r14

  v2 = this;
  if ( nNewSize > this->m_nSize )
  {
    v3 = nNewSize + (nNewSize >> 1);
    if ( v3 < 8 )
      v3 = 8i64;
    v4 = 0i64;
    if ( v3 )
      v5 = (OSuite::ZRedBlackTreeBase::ZElementBase **)OSuite::ZObject::malloc(
                                                         (OSuite::ZObject *)&this->vfptr,
                                                         8 * v3,
                                                         0i64);
    else
      v5 = 0i64;
    if ( v2->m_nTop > 0 )
    {
      do
      {
        v5[v4] = v2->m_pList[v4];
        ++v4;
      }
      while ( v4 < v2->m_nTop );
    }
    OSuite::ZObject::free((OSuite::ZObject *)&v2->vfptr, v2->m_pList);
    v2->m_pList = v5;
    v2->m_nSize = v3;
  }
}

