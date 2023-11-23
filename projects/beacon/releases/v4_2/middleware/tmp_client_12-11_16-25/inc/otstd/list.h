// File Line: 174
// RVA: 0xED0958
void __fastcall OSuite::TList<OSuite::ZString>::TList<OSuite::ZString>(
        OSuite::TList<OSuite::ZString> *this,
        OSuite::ZListBase::ZListIteratorBase *that)
{
  unsigned __int64 m_nSize; // r8
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi

  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase((OSuite::ZListBase::ZListIteratorBase *)this, that);
  m_nSize = this->m_nSize;
  v5 = 0i64;
  this->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  this->m_pList = 0i64;
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  if ( m_nSize )
    this->m_pList = OSuite::TList<OSuite::ZString>::AllocList(this, 0i64, m_nSize);
  if ( this->m_nTop )
  {
    v6 = 0i64;
    do
    {
      OSuite::ZString::operator=(&this->m_pList[v6], (OSuite::ZString *)&that[1].m_pListBase[v6]);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_nTop );
  }
}

// File Line: 200
// RVA: 0xED0BC8
OSuite::TList<OSuite::ZString> *__fastcall OSuite::TList<OSuite::ZString>::operator=(
        OSuite::TList<OSuite::ZString> *this,
        OSuite::TList<OSuite::ZString> *that)
{
  OSuite::ZString *m_pList; // rcx
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi

  if ( this != that )
  {
    m_pList = this->m_pList;
    v5 = 0i64;
    if ( m_pList )
    {
      if ( LODWORD(m_pList[-1].m_pString) )
        m_pList->OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 3u);
      else
        Illusion::ShaderParam::operator delete(&m_pList[-1].m_pString);
    }
    OSuite::ZListBase::operator=(this, that);
    this->m_pList = OSuite::TList<OSuite::ZString>::AllocList(this, this->m_pList, this->m_nSize);
    if ( this->m_nTop )
    {
      v6 = 0i64;
      do
      {
        OSuite::ZString::operator=(&this->m_pList[v6], &that->m_pList[v6]);
        ++v5;
        ++v6;
      }
      while ( v5 < this->m_nTop );
    }
  }
  return this;
}

// File Line: 262
// RVA: 0xED9EB0
OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *__fastcall OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Append(
        OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *this,
        OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *element)
{
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *v4; // rbx
  unsigned __int64 m_nTop; // rcx
  OSuite::ZWebServiceClientManager::ZWebServiceClientBucket *result; // rax

  OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::Grow(this, this->m_nTop + 1);
  v4 = &this->m_pList[this->m_nTop];
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v4, element);
  v4->refCount = element->refCount;
  OSuite::ZString::operator=(&v4->name, &element->name);
  v4->pWebServiceClient = element->pWebServiceClient;
  m_nTop = this->m_nTop;
  result = &this->m_pList[m_nTop];
  this->m_nTop = m_nTop + 1;
  return result;
}

// File Line: 315
// RVA: 0xEC81A0
void __fastcall OSuite::TList<OSuite::ZConsumableInfoBase *>::RemoveIndex(
        OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *this,
        unsigned __int64 nIndex)
{
  unsigned __int64 i; // r8

  for ( i = nIndex; i < this->m_nTop - 1; ++i )
    this->m_pList[i] = this->m_pList[i + 1];
  --this->m_nTop;
}

// File Line: 341
// RVA: 0x1331188
void __fastcall OSuite::TList<OSuite::ZConsumableInfoBase *>::Insert(
        OSuite::TList<OSuite::ZConsumableInfoBase *> *this,
        unsigned __int64 nIndex,
        unsigned __int64 nCount,
        OSuite::ZConsumableInfoBase **Element)
{
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r11
  unsigned __int64 v10; // rdx

  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)this,
    nCount + this->m_nTop);
  v8 = nIndex + nCount;
  v9 = nCount + this->m_nTop - 1;
  if ( v9 >= nIndex + nCount )
  {
    do
    {
      v10 = v9--;
      this->m_pList[v10] = *(OSuite::ZConsumableInfoBase **)((char *)this->m_pList + 8 * v10 - 8 * nCount);
    }
    while ( v9 >= v8 );
  }
  while ( nIndex < v8 )
    this->m_pList[nIndex++] = *Element;
  this->m_nTop += nCount;
}

// File Line: 413
// RVA: 0xED0CAC
char __fastcall OSuite::TList<OSuite::ZString>::operator==(
        OSuite::TList<OSuite::ZString> *this,
        OSuite::TList<OSuite::ZString> *that)
{
  unsigned __int64 m_nTop; // rax
  __int64 v6; // rsi
  __int64 i; // r14
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rdi
  bool v10; // bl
  OSuite::ZString v11; // [rsp+20h] [rbp-48h] BYREF

  m_nTop = this->m_nTop;
  if ( m_nTop != that->m_nTop )
    return 0;
  v6 = 0i64;
  if ( m_nTop )
  {
    for ( i = 0i64; ; ++i )
    {
      OSuite::ZString::ZString(&v11, &that->m_pList[i]);
      v9 = v8;
      v10 = !OSuite::ZString::operator==(&this->m_pList[i], v8);
      OSuite::ZString::~ZString(v9);
      if ( v10 )
        break;
      if ( ++v6 >= this->m_nTop )
        return 1;
    }
    return 0;
  }
  return 1;
}

// File Line: 431
// RVA: 0xED0D84
bool __fastcall OSuite::TList<OSuite::ZString>::operator<(
        OSuite::TList<OSuite::ZString> *this,
        OSuite::TList<OSuite::ZString> *that)
{
  unsigned __int64 m_nTop; // rax
  __int64 v6; // r14
  __int64 i; // r15
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rdi
  bool v10; // bl
  OSuite::ZString v11; // [rsp+20h] [rbp-48h] BYREF

  m_nTop = that->m_nTop;
  if ( this->m_nTop != m_nTop )
    return this->m_nTop < m_nTop;
  v6 = 0i64;
  if ( !this->m_nTop )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    OSuite::ZString::ZString(&v11, &that->m_pList[i]);
    v9 = v8;
    v10 = !OSuite::ZString::operator==(&this->m_pList[i], v8);
    OSuite::ZString::~ZString(v9);
    if ( v10 )
      break;
    if ( ++v6 >= this->m_nTop )
      return 0;
  }
  return OSuite::ZString::operator<(&this->m_pList[v6], &that->m_pList[v6]);
}

// File Line: 467
// RVA: 0xEC4A44
unsigned int __fastcall OSuite::TList<OSuite::ZString>::ComputeHash(OSuite::TList<OSuite::ZString> *this)
{
  unsigned int v2; // r14d
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rcx
  unsigned int v7; // eax
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h] BYREF
  void **v10; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-20h] BYREF

  v11.m_pListBase = 0i64;
  v2 = OSuite::FComputeHashBegin((_exception *)this);
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::TList<OSuite::ZString> *)((char *)this - 24));
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    m_nIndex = v11.m_nIndex;
    m_pListBase = v11.m_pListBase;
    v5 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v11.m_pListBase, v11.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = m_pListBase[1].m_nSize + 24 * m_nIndex;
    if ( v6 )
      v6 += 8i64;
    v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
    v2 = OSuite::FComputeHashAdd(v2, v7);
    OSuite::ZListBase::ZListIteratorBase::Next(&v11);
  }
  v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  return OSuite::FComputeHashEnd(v2);
}

// File Line: 534
// RVA: 0xECC9B0
OSuite::IHashable *__fastcall OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket>::AllocList(
        OSuite::TList<OSuite::ZWebServiceClientManager::ZWebServiceClientBucket> *this,
        OSuite::ZObject *__formal,
        unsigned __int64 nElements)
{
  int v3; // ebx
  unsigned __int64 v4; // rax
  bool v5; // cf
  unsigned __int64 v6; // rax
  OSuite::ZString *v7; // rax
  int v8; // esi
  OSuite::IHashable *v9; // rdi
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
  LODWORD(v7->OSuite::ZObject::vfptr) = v3;
  v9 = &v7->OSuite::IHashable;
  if ( v3 - 1 >= 0 )
  {
    v10 = v7 + 1;
    do
    {
      LODWORD(v10[-1].m_pString) = 0;
      v10[-1].OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZWebServiceClientManager::ZWebServiceClientBucket::`vftable;
      OSuite::ZString::ZString(v10, &customCaption);
      v10 += 2;
      --v8;
    }
    while ( v8 >= 0 );
  }
  return v9;
}

// File Line: 576
// RVA: 0xEC58A0
void __fastcall OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *this,
        unsigned __int64 nNewSize)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase **i; // r14

  if ( nNewSize > this->m_nSize )
  {
    v3 = nNewSize + (nNewSize >> 1);
    if ( v3 < 8 )
      v3 = 8i64;
    v4 = 0i64;
    for ( i = (OSuite::ZRedBlackTreeBase::ZElementBase **)OSuite::ZObject::malloc(this, 8 * v3, 0i64);
          v4 < this->m_nTop;
          ++v4 )
    {
      i[v4] = this->m_pList[v4];
    }
    OSuite::ZObject::free(this, this->m_pList);
    this->m_pList = i;
    this->m_nSize = v3;
  }
}

