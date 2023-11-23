// File Line: 43
// RVA: 0xEE525C
void __fastcall OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom(
        OSuite::ZRedBlackTreeBase::ZElementBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pElement)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pLeft; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rcx

  v2 = 0i64;
  if ( pElement )
  {
    this->m_eColour = pElement->m_eColour;
    m_pLeft = pElement->m_pLeft;
    if ( m_pLeft )
      v6 = (OSuite::ZRedBlackTreeBase::ZElementBase *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))m_pLeft->vfptr[2].__vecDelDtor)(m_pLeft);
    else
      v6 = 0i64;
    this->m_pLeft = v6;
    m_pRight = pElement->m_pRight;
    if ( m_pRight )
      v2 = (OSuite::ZRedBlackTreeBase::ZElementBase *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))m_pRight->vfptr[2].__vecDelDtor)(m_pRight);
    this->m_pRight = v2;
  }
  else
  {
    this->m_eColour = COLOUR_BLACK;
    this->m_pLeft = 0i64;
    this->m_pRight = 0i64;
  }
}

// File Line: 62
// RVA: 0xEE4E24
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  this->m_parents.m_nFree = 0i64;
  this->m_parents.m_pList = 0i64;
  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
}

// File Line: 69
// RVA: 0xEE4D2C
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this,
        OSuite::ZRedBlackTreeBase::ZIteratorBase *other)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_parents; // rcx

  p_m_parents = &this->m_parents;
  p_m_parents[-1].m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)other->m_pList;
  p_m_parents[-1].m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)other->m_pElement;
  p_m_parents->m_nFree = 0i64;
  p_m_parents->m_pList = 0i64;
  p_m_parents->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  p_m_parents->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(p_m_parents, &other->m_parents);
}

// File Line: 77
// RVA: 0xEE4DC0
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this,
        OSuite::ZRedBlackTreeBase *pList,
        OSuite::ZRedBlackTreeBase::ZElementBase *pElement,
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pParents)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_parents; // rcx

  this->m_pList = pList;
  this->m_pElement = pElement;
  this->m_parents.m_nFree = 0i64;
  this->m_parents.m_pList = 0i64;
  p_m_parents = &this->m_parents;
  p_m_parents->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  p_m_parents->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( pParents )
  {
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(p_m_parents, pParents);
    pParents->OSuite::ZObject::vfptr->__vecDelDtor(pParents, 1i64);
  }
}

// File Line: 89
// RVA: 0xEE4D7C
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this,
        OSuite::ZRedBlackTreeBase *pList)
{
  this->m_pList = pList;
  this->m_pElement = 0i64;
  this->m_parents.m_nFree = 0i64;
  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.m_pList = 0i64;
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(this);
}

// File Line: 94
// RVA: 0xEE4F14
OSuite::ZRedBlackTreeBase::ZIteratorBase *__fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this,
        OSuite::ZRedBlackTreeBase::ZIteratorBase *that)
{
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, that);
    this->m_pList = that->m_pList;
    this->m_pElement = that->m_pElement;
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(&this->m_parents, &that->m_parents);
  }
  return this;
}

// File Line: 114
// RVA: 0xEE50A0
_BOOL8 __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  return this->m_pElement != 0i64;
}

// File Line: 120
// RVA: 0xEE6654
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase **p_m_pElement; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rax
  bool v5; // zf
  OSuite::ZRedBlackTreeBase::ZElementBase *i; // rcx

  p_m_pElement = &this->m_pElement;
  m_pElement = this->m_pElement;
  if ( !m_pElement )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(this);
    return;
  }
  if ( m_pElement->m_pRight )
    goto LABEL_8;
  if ( !this->m_parents.m_nFree )
  {
LABEL_6:
    if ( *p_m_pElement == this->m_pList->m_pTop )
    {
      *p_m_pElement = 0i64;
      return;
    }
LABEL_8:
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&this->m_parents, p_m_pElement);
    for ( i = (*p_m_pElement)->m_pRight; ; i = (*p_m_pElement)->m_pLeft )
    {
      *p_m_pElement = i;
      if ( !i->m_pLeft )
        break;
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&this->m_parents, p_m_pElement);
    }
    return;
  }
  while ( 1 )
  {
    v4 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(&this->m_parents);
    v5 = *p_m_pElement == v4->m_pLeft;
    *p_m_pElement = v4;
    if ( v5 )
      break;
    if ( !this->m_parents.m_nFree )
      goto LABEL_6;
  }
}

// File Line: 196
// RVA: 0xEE68CC
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  v2 = OSuite::ZRedBlackTreeBase::DeleteElement(this->m_pList, this);
  this->m_pElement = v2;
  if ( v2 )
  {
    OSuite::ZRedBlackTreeBase::FindExactElement(this->m_pList, v2, &this->m_parents);
  }
  else
  {
    m_pList = this->m_parents.m_pList;
    if ( m_pList )
      m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
    this->m_parents.m_pList = 0i64;
    this->m_parents.m_nFree = 0i64;
  }
}

// File Line: 221
// RVA: 0xEE66F8
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this,
        int nAncestor)
{
  unsigned __int64 v4; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v8; // rax

  if ( !this->m_parents.m_nFree )
    return 0i64;
  v4 = this->m_parents.m_nFree - nAncestor - 1;
  if ( v4 < 5 )
  {
    v8 = &this->m_parents.m_staticList[v4];
  }
  else
  {
    m_pList = this->m_parents.m_pList;
    v6 = v4 - 5;
    v7 = v4 - 5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(m_pList, v7);
    if ( v6 >= m_pList->m_nTop )
      m_pList->m_nTop = v7;
    v8 = &m_pList->m_pList[v6];
  }
  return *v8;
}

// File Line: 235
// RVA: 0xEE65E0
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase **p_m_pElement; // rdi

  m_pList = this->m_parents.m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  this->m_parents.m_pList = 0i64;
  this->m_parents.m_nFree = 0i64;
  m_pTop = this->m_pList->m_pTop;
  p_m_pElement = &this->m_pElement;
  this->m_pElement = m_pTop;
  if ( m_pTop )
  {
    while ( m_pTop->m_pLeft )
    {
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&this->m_parents, &this->m_pElement);
      m_pTop = (*p_m_pElement)->m_pLeft;
      *p_m_pElement = m_pTop;
    }
  }
}

// File Line: 283
// RVA: 0xEE4E48
void __fastcall OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(OSuite::ZRedBlackTreeBase *this)
{
  this->m_pTop = 0i64;
  this->m_nTotalElements = 0i64;
}

// File Line: 288
// RVA: 0xEE4E58
void __fastcall OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(OSuite::ZRedBlackTreeBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rdx

  m_pTop = this->m_pTop;
  if ( m_pTop )
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, m_pTop);
}

// File Line: 297
// RVA: 0xEE4F5C
OSuite::ZRedBlackTreeBase *__fastcall OSuite::ZRedBlackTreeBase::operator=(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rdx

  if ( this != that )
  {
    m_pTop = this->m_pTop;
    if ( m_pTop )
      OSuite::ZRedBlackTreeBase::DeleteSubTree(this, m_pTop);
    OSuite::ZRedBlackTreeBase::CopyFrom(this, that);
  }
  return this;
}

// File Line: 312
// RVA: 0xEE4F98
char __fastcall OSuite::ZRedBlackTreeBase::operator==(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase *that)
{
  char v5; // bl
  OSuite::ZRedBlackTreeBase::ZIteratorBase v6; // [rsp+20h] [rbp-79h] BYREF
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+80h] [rbp-19h] BYREF

  if ( this == that )
    return 1;
  if ( this->m_nTotalElements != that->m_nTotalElements )
    return 0;
  v6.m_pList = 0i64;
  v6.m_pElement = 0i64;
  v6.m_parents.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v6, this);
  v7.m_pList = 0i64;
  v7.m_pElement = 0i64;
  v7.m_parents.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, that);
  while ( 1 )
  {
    if ( !v6.m_pElement || !v7.m_pElement )
    {
      v5 = 1;
      goto LABEL_10;
    }
    if ( !this->vfptr[1].__vecDelDtor(this, v6.m_pElement) )
      break;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v6);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v5 = 0;
LABEL_10:
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor(v7.m_parents.m_pList, 1u);
  if ( v6.m_parents.m_pList )
    v6.m_parents.m_pList->vfptr->__vecDelDtor(v6.m_parents.m_pList, 1u);
  return v5;
}

// File Line: 349
// RVA: 0xEE5100
void __fastcall OSuite::ZRedBlackTreeBase::Clear(OSuite::ZRedBlackTreeBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rdx

  m_pTop = this->m_pTop;
  if ( m_pTop )
  {
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, m_pTop);
    this->m_pTop = 0i64;
  }
  this->m_nTotalElements = 0i64;
}

// File Line: 374
// RVA: 0xEE65D4
_BOOL8 __fastcall OSuite::ZRedBlackTreeBase::IsEmpty(OSuite::ZRedBlackTreeBase *this)
{
  return this->m_pTop == 0i64;
}

// File Line: 380
// RVA: 0xEE543C
void __fastcall OSuite::ZRedBlackTreeBase::DeleteFixUp(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pX,
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pXParents)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rdi
  unsigned __int64 v6; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rsi
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v10; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v11; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pLeft; // rsi
  unsigned __int64 v13; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v14; // rdi
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v17; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v20; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v21; // rax
  unsigned __int64 v22; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v23; // rdi
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v26; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v27; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v28; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v29; // rax
  unsigned __int64 v30; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v31; // rdi
  unsigned __int64 v32; // rsi
  unsigned __int64 v33; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v34; // rax
  unsigned __int64 v35; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v36; // rdi
  unsigned __int64 v37; // rbp
  unsigned __int64 v38; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v39; // rax
  unsigned __int64 v40; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v41; // rdi
  unsigned __int64 v42; // rbp
  unsigned __int64 v43; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v44; // rax
  unsigned __int64 m_nFree; // rax
  unsigned __int64 v46; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v47; // rdi
  unsigned __int64 v48; // rsi
  unsigned __int64 v49; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v50; // rsi
  unsigned __int64 v51; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v52; // rdi
  unsigned __int64 v53; // rbp
  unsigned __int64 v54; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v55; // rdx
  unsigned __int64 v56; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v57; // rdi
  unsigned __int64 v58; // rsi
  unsigned __int64 v59; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v60; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v61; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v62; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v63; // rcx
  unsigned __int64 v64; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v65; // rdi
  unsigned __int64 v66; // rsi
  unsigned __int64 v67; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v68; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v69; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v70; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v71; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v72; // rax
  unsigned __int64 v73; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v74; // rdi
  unsigned __int64 v75; // rsi
  unsigned __int64 v76; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v77; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v78; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v79; // rcx
  unsigned __int64 v80; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v81; // rdi
  unsigned __int64 v82; // rsi
  unsigned __int64 v83; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v84; // rax
  unsigned __int64 v85; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v86; // rdi
  unsigned __int64 v87; // rbp
  unsigned __int64 v88; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v89; // rax
  unsigned __int64 v90; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v91; // rdi
  unsigned __int64 v92; // rbp
  unsigned __int64 v93; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v94; // rax
  unsigned __int64 v95; // rax
  unsigned __int64 v96; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v97; // rdi
  unsigned __int64 v98; // rsi
  unsigned __int64 v99; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v100; // rsi
  unsigned __int64 v101; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v102; // rdi
  unsigned __int64 v103; // rbp
  unsigned __int64 v104; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v105; // rdx
  unsigned __int64 v106; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v107; // rdi
  unsigned __int64 v108; // rsi
  unsigned __int64 v109; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v110; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v111; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v112; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+60h] [rbp+8h] BYREF
  OSuite::ZRedBlackTreeBase::ZElementBase *v114; // [rsp+68h] [rbp+10h] BYREF

  m_pTop = pX;
  while ( m_pTop != this->m_pTop )
  {
    if ( m_pTop && m_pTop->m_eColour != COLOUR_BLACK )
      break;
    v6 = pXParents->m_nFree - 1;
    if ( v6 < 5 )
    {
      v10 = &pXParents->m_staticList[v6];
    }
    else
    {
      m_pList = pXParents->m_pList;
      v8 = pXParents->m_nFree - 6;
      v9 = pXParents->m_nFree - 5;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(m_pList, v9);
      if ( v8 >= m_pList->m_nTop )
        m_pList->m_nTop = v9;
      v10 = &m_pList->m_pList[v8];
    }
    v11 = *v10;
    m_pLeft = (*v10)->m_pLeft;
    if ( m_pTop == m_pLeft )
    {
      m_pLeft = v11->m_pRight;
      if ( m_pLeft )
      {
        if ( m_pLeft->m_eColour == COLOUR_RED )
        {
          m_pLeft->m_eColour = COLOUR_BLACK;
          v13 = pXParents->m_nFree - 1;
          if ( v13 < 5 )
          {
            v17 = &pXParents->m_staticList[v13];
          }
          else
          {
            v14 = pXParents->m_pList;
            v15 = pXParents->m_nFree - 6;
            v16 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v14, v16);
            if ( v15 >= v14->m_nTop )
              v14->m_nTop = v16;
            v17 = &v14->m_pList[v15];
          }
          (*v17)->m_eColour = COLOUR_RED;
          v18 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(pXParents);
          m_pRight = v18->m_pRight;
          v20 = v18;
          v114 = v18;
          element = m_pRight;
          if ( pXParents->m_nFree )
          {
            v21 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(pXParents);
            OSuite::ZRedBlackTreeBase::RotateLeft(this, v20, v21);
          }
          else
          {
            v18->m_pRight = m_pRight->m_pLeft;
            this->m_pTop = m_pRight;
            m_pRight->m_pLeft = v18;
          }
          OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(pXParents, &element);
          OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(pXParents, &v114);
          v22 = pXParents->m_nFree - 1;
          if ( v22 < 5 )
          {
            v26 = &pXParents->m_staticList[v22];
          }
          else
          {
            v23 = pXParents->m_pList;
            v24 = pXParents->m_nFree - 6;
            v25 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v23, v25);
            if ( v24 >= v23->m_nTop )
              v23->m_nTop = v25;
            v26 = &v23->m_pList[v24];
          }
          m_pLeft = (*v26)->m_pRight;
        }
        if ( !m_pLeft
          || (v27 = m_pLeft->m_pLeft) != 0i64 && v27->m_eColour != COLOUR_BLACK
          || (v28 = m_pLeft->m_pRight) != 0i64 && v28->m_eColour != COLOUR_BLACK )
        {
          v29 = m_pLeft->m_pRight;
          if ( !v29 || v29->m_eColour == COLOUR_BLACK )
          {
            m_pLeft->m_pLeft->m_eColour = COLOUR_BLACK;
            m_pLeft->m_eColour = COLOUR_RED;
            OSuite::ZRedBlackTreeBase::RotateRight(this, m_pLeft, v11);
            v30 = pXParents->m_nFree - 1;
            if ( v30 < 5 )
            {
              v34 = &pXParents->m_staticList[v30];
            }
            else
            {
              v31 = pXParents->m_pList;
              v32 = pXParents->m_nFree - 6;
              v33 = pXParents->m_nFree - 5;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v31, v33);
              if ( v32 >= v31->m_nTop )
                v31->m_nTop = v33;
              v34 = &v31->m_pList[v32];
            }
            m_pLeft = (*v34)->m_pRight;
          }
          v35 = pXParents->m_nFree - 1;
          if ( v35 < 5 )
          {
            v39 = &pXParents->m_staticList[v35];
          }
          else
          {
            v36 = pXParents->m_pList;
            v37 = pXParents->m_nFree - 6;
            v38 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v36, v38);
            if ( v37 >= v36->m_nTop )
              v36->m_nTop = v38;
            v39 = &v36->m_pList[v37];
          }
          m_pLeft->m_eColour = (*v39)->m_eColour;
          v40 = pXParents->m_nFree - 1;
          if ( v40 < 5 )
          {
            v44 = &pXParents->m_staticList[v40];
          }
          else
          {
            v41 = pXParents->m_pList;
            v42 = pXParents->m_nFree - 6;
            v43 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v41, v43);
            if ( v42 >= v41->m_nTop )
              v41->m_nTop = v43;
            v44 = &v41->m_pList[v42];
          }
          (*v44)->m_eColour = COLOUR_BLACK;
          m_pLeft->m_pRight->m_eColour = COLOUR_BLACK;
          m_nFree = pXParents->m_nFree;
          if ( m_nFree <= 1 )
          {
            v56 = m_nFree - 1;
            if ( v56 < 5 )
            {
              v60 = &pXParents->m_staticList[v56];
            }
            else
            {
              v57 = pXParents->m_pList;
              v58 = v56 - 5;
              v59 = v56 - 5 + 1;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v57, v59);
              if ( v58 >= v57->m_nTop )
                v57->m_nTop = v59;
              v60 = &v57->m_pList[v58];
            }
            v61 = *v60;
            v62 = v61->m_pRight;
            v61->m_pRight = v62->m_pLeft;
            this->m_pTop = v62;
            v62->m_pLeft = v61;
          }
          else
          {
            v46 = m_nFree - 2;
            if ( v46 < 5 )
            {
              v50 = &pXParents->m_staticList[v46];
            }
            else
            {
              v47 = pXParents->m_pList;
              v48 = v46 - 5;
              v49 = v46 - 5 + 1;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v47, v49);
              if ( v48 >= v47->m_nTop )
                v47->m_nTop = v49;
              v50 = &v47->m_pList[v48];
            }
            v51 = pXParents->m_nFree - 1;
            if ( v51 < 5 )
            {
              v55 = &pXParents->m_staticList[v51];
            }
            else
            {
              v52 = pXParents->m_pList;
              v53 = pXParents->m_nFree - 6;
              v54 = pXParents->m_nFree - 5;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v52, v54);
              if ( v53 >= v52->m_nTop )
                v52->m_nTop = v54;
              v55 = &v52->m_pList[v53];
            }
            OSuite::ZRedBlackTreeBase::RotateLeft(this, *v55, *v50);
          }
LABEL_67:
          v63 = pXParents->m_pList;
          m_pTop = this->m_pTop;
          if ( v63 )
            v63->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(v63, 1u);
          pXParents->m_pList = 0i64;
          pXParents->m_nFree = 0i64;
          continue;
        }
LABEL_126:
        m_pLeft->m_eColour = COLOUR_RED;
        m_pTop = OSuite::TStack<OSuite::ZJsonObject *>::Pop(pXParents);
      }
    }
    else if ( m_pLeft )
    {
      if ( m_pLeft->m_eColour == COLOUR_RED )
      {
        m_pLeft->m_eColour = COLOUR_BLACK;
        v64 = pXParents->m_nFree - 1;
        if ( v64 < 5 )
        {
          v68 = &pXParents->m_staticList[v64];
        }
        else
        {
          v65 = pXParents->m_pList;
          v66 = pXParents->m_nFree - 6;
          v67 = pXParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v65, v67);
          if ( v66 >= v65->m_nTop )
            v65->m_nTop = v67;
          v68 = &v65->m_pList[v66];
        }
        (*v68)->m_eColour = COLOUR_RED;
        v69 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(pXParents);
        v70 = v69->m_pLeft;
        v71 = v69;
        v114 = v69;
        element = v70;
        if ( pXParents->m_nFree )
        {
          v72 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(pXParents);
          OSuite::ZRedBlackTreeBase::RotateRight(this, v71, v72);
        }
        else
        {
          v69->m_pLeft = v70->m_pRight;
          this->m_pTop = v70;
          v70->m_pRight = v69;
        }
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(pXParents, &element);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(pXParents, &v114);
        v73 = pXParents->m_nFree - 1;
        if ( v73 < 5 )
        {
          v77 = &pXParents->m_staticList[v73];
        }
        else
        {
          v74 = pXParents->m_pList;
          v75 = pXParents->m_nFree - 6;
          v76 = pXParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v74, v76);
          if ( v75 >= v74->m_nTop )
            v74->m_nTop = v76;
          v77 = &v74->m_pList[v75];
        }
        m_pLeft = (*v77)->m_pLeft;
      }
      v78 = m_pLeft->m_pLeft;
      if ( v78 && v78->m_eColour != COLOUR_BLACK || (v79 = m_pLeft->m_pRight) != 0i64 && v79->m_eColour != COLOUR_BLACK )
      {
        if ( !v78 || v78->m_eColour == COLOUR_BLACK )
        {
          m_pLeft->m_pRight->m_eColour = COLOUR_BLACK;
          m_pLeft->m_eColour = COLOUR_RED;
          OSuite::ZRedBlackTreeBase::RotateLeft(this, m_pLeft, v11);
          v80 = pXParents->m_nFree - 1;
          if ( v80 < 5 )
          {
            v84 = &pXParents->m_staticList[v80];
          }
          else
          {
            v81 = pXParents->m_pList;
            v82 = pXParents->m_nFree - 6;
            v83 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v81, v83);
            if ( v82 >= v81->m_nTop )
              v81->m_nTop = v83;
            v84 = &v81->m_pList[v82];
          }
          m_pLeft = (*v84)->m_pLeft;
        }
        v85 = pXParents->m_nFree - 1;
        if ( v85 < 5 )
        {
          v89 = &pXParents->m_staticList[v85];
        }
        else
        {
          v86 = pXParents->m_pList;
          v87 = pXParents->m_nFree - 6;
          v88 = pXParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v86, v88);
          if ( v87 >= v86->m_nTop )
            v86->m_nTop = v88;
          v89 = &v86->m_pList[v87];
        }
        m_pLeft->m_eColour = (*v89)->m_eColour;
        v90 = pXParents->m_nFree - 1;
        if ( v90 < 5 )
        {
          v94 = &pXParents->m_staticList[v90];
        }
        else
        {
          v91 = pXParents->m_pList;
          v92 = pXParents->m_nFree - 6;
          v93 = pXParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v91, v93);
          if ( v92 >= v91->m_nTop )
            v91->m_nTop = v93;
          v94 = &v91->m_pList[v92];
        }
        (*v94)->m_eColour = COLOUR_BLACK;
        m_pLeft->m_pLeft->m_eColour = COLOUR_BLACK;
        v95 = pXParents->m_nFree;
        if ( v95 <= 1 )
        {
          v106 = v95 - 1;
          if ( v106 < 5 )
          {
            v110 = &pXParents->m_staticList[v106];
          }
          else
          {
            v107 = pXParents->m_pList;
            v108 = v106 - 5;
            v109 = v106 - 5 + 1;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v107, v109);
            if ( v108 >= v107->m_nTop )
              v107->m_nTop = v109;
            v110 = &v107->m_pList[v108];
          }
          v111 = *v110;
          v112 = v111->m_pLeft;
          v111->m_pLeft = v112->m_pRight;
          this->m_pTop = v112;
          v112->m_pRight = v111;
        }
        else
        {
          v96 = v95 - 2;
          if ( v96 < 5 )
          {
            v100 = &pXParents->m_staticList[v96];
          }
          else
          {
            v97 = pXParents->m_pList;
            v98 = v96 - 5;
            v99 = v96 - 5 + 1;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v97, v99);
            if ( v98 >= v97->m_nTop )
              v97->m_nTop = v99;
            v100 = &v97->m_pList[v98];
          }
          v101 = pXParents->m_nFree - 1;
          if ( v101 < 5 )
          {
            v105 = &pXParents->m_staticList[v101];
          }
          else
          {
            v102 = pXParents->m_pList;
            v103 = pXParents->m_nFree - 6;
            v104 = pXParents->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v102, v104);
            if ( v103 >= v102->m_nTop )
              v102->m_nTop = v104;
            v105 = &v102->m_pList[v103];
          }
          OSuite::ZRedBlackTreeBase::RotateRight(this, *v105, *v100);
        }
        goto LABEL_67;
      }
      goto LABEL_126;
    }
  }
  if ( m_pTop )
    m_pTop->m_eColour = COLOUR_BLACK;
}

// File Line: 506
// RVA: 0xEE5ED4
void __fastcall OSuite::ZRedBlackTreeBase::InsertFixUp(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pZ,
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *zParents)
{
  unsigned __int64 m_nFree; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r15
  unsigned __int64 v7; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rdi
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v11; // rax
  unsigned __int64 v12; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v13; // rdi
  unsigned __int64 v14; // rsi
  unsigned __int64 v15; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v16; // rsi
  unsigned __int64 v17; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v18; // rdi
  unsigned __int64 v19; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v20; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pLeft; // rcx
  unsigned __int64 v22; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v23; // rdi
  unsigned __int64 v24; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v25; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rsi
  unsigned __int64 v27; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v28; // rdi
  unsigned __int64 v29; // rsi
  unsigned __int64 v30; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v31; // rax
  unsigned __int64 v32; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v33; // rdi
  unsigned __int64 v34; // rsi
  unsigned __int64 v35; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v36; // r8
  unsigned __int64 v37; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v38; // rdi
  unsigned __int64 v39; // rsi
  unsigned __int64 v40; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v41; // rax
  unsigned __int64 v42; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v43; // rdi
  unsigned __int64 v44; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v45; // rax
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v48; // rdi
  unsigned __int64 v49; // rsi
  unsigned __int64 v50; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v51; // r14
  unsigned __int64 v52; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v53; // rdi
  unsigned __int64 v54; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v55; // rdx
  unsigned __int64 v56; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v57; // rdi
  unsigned __int64 v58; // rsi
  unsigned __int64 v59; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v60; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v61; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v62; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v63; // rdi
  unsigned __int64 v64; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v65; // rax
  unsigned __int64 v66; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v67; // rdi
  unsigned __int64 v68; // rbp
  unsigned __int64 v69; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase **v70; // rax
  unsigned __int64 v71; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v72; // rdi
  unsigned __int64 v73; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v74; // rax
  unsigned __int64 v75; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v76; // rdi
  unsigned __int64 v77; // rsi
  unsigned __int64 v78; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v79; // rax
  unsigned __int64 v80; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v81; // rdi
  unsigned __int64 v82; // rsi
  unsigned __int64 v83; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v84; // r8
  unsigned __int64 v85; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v86; // rdi
  unsigned __int64 v87; // rsi
  unsigned __int64 v88; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v89; // rax
  unsigned __int64 v90; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v91; // rdi
  unsigned __int64 v92; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v93; // rax
  unsigned __int64 v94; // rax
  unsigned __int64 v95; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v96; // rdi
  unsigned __int64 v97; // rsi
  unsigned __int64 v98; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v99; // r14
  unsigned __int64 v100; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v101; // rdi
  unsigned __int64 v102; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase **v103; // rdx
  unsigned __int64 v104; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v105; // rdi
  unsigned __int64 v106; // rsi
  unsigned __int64 v107; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v108; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v109; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v110; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+68h] [rbp+10h] BYREF

  element = pZ;
  m_nFree = zParents->m_nFree;
  v5 = pZ;
  if ( m_nFree > 1 )
  {
    while ( 1 )
    {
      v7 = m_nFree - 1;
      if ( v7 < 5 )
      {
        v11 = &zParents->m_staticList[v7];
      }
      else
      {
        m_pList = zParents->m_pList;
        v9 = v7 - 5;
        v10 = v7 - 5 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(m_pList, v10);
        if ( v9 >= m_pList->m_nTop )
          m_pList->m_nTop = v10;
        v11 = &m_pList->m_pList[v9];
      }
      if ( (*v11)->m_eColour )
        goto LABEL_125;
      v12 = zParents->m_nFree - 1;
      if ( v12 < 5 )
      {
        v16 = &zParents->m_staticList[v12];
      }
      else
      {
        v13 = zParents->m_pList;
        v14 = zParents->m_nFree - 6;
        v15 = zParents->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v13, v15);
        if ( v14 >= v13->m_nTop )
          v13->m_nTop = v15;
        v16 = &v13->m_pList[v14];
      }
      v17 = zParents->m_nFree - 2;
      if ( v17 < 5 )
      {
        v20 = &zParents->m_staticList[v17];
      }
      else
      {
        v18 = zParents->m_pList;
        v19 = zParents->m_nFree - 7;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v18, v19 + 1);
        if ( v19 >= v18->m_nTop )
          v18->m_nTop = v19 + 1;
        v20 = &v18->m_pList[v19];
      }
      m_pLeft = (*v20)->m_pLeft;
      v22 = zParents->m_nFree - 2;
      if ( *v16 != m_pLeft )
        break;
      if ( v22 < 5 )
      {
        v25 = &zParents->m_staticList[v22];
      }
      else
      {
        v23 = zParents->m_pList;
        v24 = zParents->m_nFree - 7;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v23, v24 + 1);
        if ( v24 >= v23->m_nTop )
          v23->m_nTop = v24 + 1;
        v25 = &v23->m_pList[v24];
      }
      m_pRight = (*v25)->m_pRight;
      if ( m_pRight && m_pRight->m_eColour == COLOUR_RED )
        goto LABEL_73;
      v27 = zParents->m_nFree - 1;
      if ( v27 < 5 )
      {
        v31 = &zParents->m_staticList[v27];
      }
      else
      {
        v28 = zParents->m_pList;
        v29 = zParents->m_nFree - 6;
        v30 = zParents->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v28, v30);
        if ( v29 >= v28->m_nTop )
          v28->m_nTop = v30;
        v31 = &v28->m_pList[v29];
      }
      if ( v5 == (*v31)->m_pRight )
      {
        v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
        v32 = zParents->m_nFree - 1;
        if ( v32 < 5 )
        {
          v36 = &zParents->m_staticList[v32];
        }
        else
        {
          v33 = zParents->m_pList;
          v34 = zParents->m_nFree - 6;
          v35 = zParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v33, v35);
          if ( v34 >= v33->m_nTop )
            v33->m_nTop = v35;
          v36 = &v33->m_pList[v34];
        }
        OSuite::ZRedBlackTreeBase::RotateLeft(this, v5, *v36);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(zParents, &element);
        element = v5;
      }
      v37 = zParents->m_nFree - 1;
      if ( v37 < 5 )
      {
        v41 = &zParents->m_staticList[v37];
      }
      else
      {
        v38 = zParents->m_pList;
        v39 = zParents->m_nFree - 6;
        v40 = zParents->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v38, v40);
        if ( v39 >= v38->m_nTop )
          v38->m_nTop = v40;
        v41 = &v38->m_pList[v39];
      }
      (*v41)->m_eColour = COLOUR_BLACK;
      v42 = zParents->m_nFree - 2;
      if ( v42 < 5 )
      {
        v45 = &zParents->m_staticList[v42];
      }
      else
      {
        v43 = zParents->m_pList;
        v44 = zParents->m_nFree - 7;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v43, v44 + 1);
        if ( v44 >= v43->m_nTop )
          v43->m_nTop = v44 + 1;
        v45 = &v43->m_pList[v44];
      }
      (*v45)->m_eColour = COLOUR_RED;
      v46 = zParents->m_nFree;
      if ( v46 < 3 )
      {
        v56 = v46 - 2;
        if ( v56 < 5 )
        {
          v60 = &zParents->m_staticList[v56];
        }
        else
        {
          v57 = zParents->m_pList;
          v58 = v56 - 5;
          v59 = v56 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v57, v59);
          if ( v58 >= v57->m_nTop )
            v57->m_nTop = v59;
          v60 = &v57->m_pList[v58];
        }
        v61 = *v60;
        v62 = v61->m_pLeft;
        v61->m_pLeft = v62->m_pRight;
        this->m_pTop = v62;
        v62->m_pRight = v61;
      }
      else
      {
        v47 = v46 - 3;
        if ( v47 < 5 )
        {
          v51 = &zParents->m_staticList[v47];
        }
        else
        {
          v48 = zParents->m_pList;
          v49 = v47 - 5;
          v50 = v47 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v48, v50);
          if ( v49 >= v48->m_nTop )
            v48->m_nTop = v50;
          v51 = &v48->m_pList[v49];
        }
        v52 = zParents->m_nFree - 2;
        if ( v52 < 5 )
        {
          v55 = &zParents->m_staticList[v52];
        }
        else
        {
          v53 = zParents->m_pList;
          v54 = zParents->m_nFree - 7;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v53, v54 + 1);
          if ( v54 >= v53->m_nTop )
            v53->m_nTop = v54 + 1;
          v55 = &v53->m_pList[v54];
        }
        OSuite::ZRedBlackTreeBase::RotateRight(this, *v55, *v51);
      }
LABEL_124:
      m_nFree = zParents->m_nFree;
      if ( m_nFree <= 1 )
        goto LABEL_125;
    }
    if ( v22 < 5 )
    {
      v65 = &zParents->m_staticList[v22];
    }
    else
    {
      v63 = zParents->m_pList;
      v64 = zParents->m_nFree - 7;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v63, v64 + 1);
      if ( v64 >= v63->m_nTop )
        v63->m_nTop = v64 + 1;
      v65 = &v63->m_pList[v64];
    }
    m_pRight = (*v65)->m_pLeft;
    if ( !m_pRight || m_pRight->m_eColour )
    {
      v75 = zParents->m_nFree - 1;
      if ( v75 < 5 )
      {
        v79 = &zParents->m_staticList[v75];
      }
      else
      {
        v76 = zParents->m_pList;
        v77 = zParents->m_nFree - 6;
        v78 = zParents->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v76, v78);
        if ( v77 >= v76->m_nTop )
          v76->m_nTop = v78;
        v79 = &v76->m_pList[v77];
      }
      if ( v5 == (*v79)->m_pLeft )
      {
        v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
        v80 = zParents->m_nFree - 1;
        if ( v80 < 5 )
        {
          v84 = &zParents->m_staticList[v80];
        }
        else
        {
          v81 = zParents->m_pList;
          v82 = zParents->m_nFree - 6;
          v83 = zParents->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v81, v83);
          if ( v82 >= v81->m_nTop )
            v81->m_nTop = v83;
          v84 = &v81->m_pList[v82];
        }
        OSuite::ZRedBlackTreeBase::RotateRight(this, v5, *v84);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(zParents, &element);
        element = v5;
      }
      v85 = zParents->m_nFree - 1;
      if ( v85 < 5 )
      {
        v89 = &zParents->m_staticList[v85];
      }
      else
      {
        v86 = zParents->m_pList;
        v87 = zParents->m_nFree - 6;
        v88 = zParents->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v86, v88);
        if ( v87 >= v86->m_nTop )
          v86->m_nTop = v88;
        v89 = &v86->m_pList[v87];
      }
      (*v89)->m_eColour = COLOUR_BLACK;
      v90 = zParents->m_nFree - 2;
      if ( v90 < 5 )
      {
        v93 = &zParents->m_staticList[v90];
      }
      else
      {
        v91 = zParents->m_pList;
        v92 = zParents->m_nFree - 7;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v91, v92 + 1);
        if ( v92 >= v91->m_nTop )
          v91->m_nTop = v92 + 1;
        v93 = &v91->m_pList[v92];
      }
      (*v93)->m_eColour = COLOUR_RED;
      v94 = zParents->m_nFree;
      if ( v94 < 3 )
      {
        v104 = v94 - 2;
        if ( v104 < 5 )
        {
          v108 = &zParents->m_staticList[v104];
        }
        else
        {
          v105 = zParents->m_pList;
          v106 = v104 - 5;
          v107 = v104 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v105, v107);
          if ( v106 >= v105->m_nTop )
            v105->m_nTop = v107;
          v108 = &v105->m_pList[v106];
        }
        v109 = *v108;
        v110 = v109->m_pRight;
        v109->m_pRight = v110->m_pLeft;
        this->m_pTop = v110;
        v110->m_pLeft = v109;
      }
      else
      {
        v95 = v94 - 3;
        if ( v95 < 5 )
        {
          v99 = &zParents->m_staticList[v95];
        }
        else
        {
          v96 = zParents->m_pList;
          v97 = v95 - 5;
          v98 = v95 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v96, v98);
          if ( v97 >= v96->m_nTop )
            v96->m_nTop = v98;
          v99 = &v96->m_pList[v97];
        }
        v100 = zParents->m_nFree - 2;
        if ( v100 < 5 )
        {
          v103 = &zParents->m_staticList[v100];
        }
        else
        {
          v101 = zParents->m_pList;
          v102 = zParents->m_nFree - 7;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v101, v102 + 1);
          if ( v102 >= v101->m_nTop )
            v101->m_nTop = v102 + 1;
          v103 = &v101->m_pList[v102];
        }
        OSuite::ZRedBlackTreeBase::RotateLeft(this, *v103, *v99);
      }
      goto LABEL_124;
    }
LABEL_73:
    v66 = zParents->m_nFree - 1;
    if ( v66 < 5 )
    {
      v70 = &zParents->m_staticList[v66];
    }
    else
    {
      v67 = zParents->m_pList;
      v68 = zParents->m_nFree - 6;
      v69 = zParents->m_nFree - 5;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v67, v69);
      if ( v68 >= v67->m_nTop )
        v67->m_nTop = v69;
      v70 = &v67->m_pList[v68];
    }
    (*v70)->m_eColour = COLOUR_BLACK;
    m_pRight->m_eColour = COLOUR_BLACK;
    v71 = zParents->m_nFree - 2;
    if ( v71 < 5 )
    {
      v74 = &zParents->m_staticList[v71];
    }
    else
    {
      v72 = zParents->m_pList;
      v73 = zParents->m_nFree - 7;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v72, v73 + 1);
      if ( v73 >= v72->m_nTop )
        v72->m_nTop = v73 + 1;
      v74 = &v72->m_pList[v73];
    }
    (*v74)->m_eColour = COLOUR_RED;
    OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
    v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
    element = v5;
    goto LABEL_124;
  }
LABEL_125:
  this->m_pTop->m_eColour = COLOUR_BLACK;
} = zParents->m_pList;
      v73 = zParents->m_nFree - 7;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v72, v73 + 1);
      if ( v73 >= v72->m_nTop )
        v72->m_nTop = v73 + 1;
      v74 = &v72->m_pList[v73];
    }
    (*v74)->m_eColour = COLOUR_RED;
    OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
    v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(zParents);
    element = v5

// File Line: 585
// RVA: 0xEE6924
void __fastcall OSuite::ZRedBlackTreeBase::RotateLeft(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pX,
        OSuite::ZRedBlackTreeBase::ZElementBase *pXParent)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // r9

  m_pRight = pX->m_pRight;
  pX->m_pRight = m_pRight->m_pLeft;
  if ( pXParent )
  {
    if ( pX == pXParent->m_pLeft )
      pXParent->m_pLeft = m_pRight;
    else
      pXParent->m_pRight = m_pRight;
  }
  else
  {
    this->m_pTop = m_pRight;
  }
  m_pRight->m_pLeft = pX;
}

// File Line: 609
// RVA: 0xEE6950
void __fastcall OSuite::ZRedBlackTreeBase::RotateRight(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pY,
        OSuite::ZRedBlackTreeBase::ZElementBase *pYParent)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pLeft; // r9

  m_pLeft = pY->m_pLeft;
  pY->m_pLeft = m_pLeft->m_pRight;
  if ( pYParent )
  {
    if ( pY == pYParent->m_pRight )
      pYParent->m_pRight = m_pLeft;
    else
      pYParent->m_pLeft = m_pLeft;
  }
  else
  {
    this->m_pTop = m_pLeft;
  }
  m_pLeft->m_pRight = pY;
}

// File Line: 639
// RVA: 0xEE5B74
void __fastcall OSuite::ZRedBlackTreeBase::DeleteSubTree(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pNode)
{
  if ( pNode )
  {
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, pNode->m_pLeft);
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, pNode->m_pRight);
    pNode->vfptr->__vecDelDtor(pNode, 1i64);
  }
}

// File Line: 652
// RVA: 0xEE5224
void __fastcall OSuite::ZRedBlackTreeBase::CopyFrom(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rax

  m_pTop = that->m_pTop;
  v4 = 0i64;
  if ( m_pTop )
    v4 = (OSuite::ZRedBlackTreeBase::ZElementBase *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))m_pTop->vfptr[2].__vecDelDtor)(m_pTop);
  this->m_pTop = v4;
  this->m_nTotalElements = that->m_nTotalElements;
}

// File Line: 659
// RVA: 0xEE52D0
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::DeleteElement(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZIteratorBase *pY)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pLeft; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rdi
  OSuite::ZRedBlackTreeBase::ZIteratorBase v11; // [rsp+20h] [rbp-88h] BYREF

  m_pElement = pY->m_pElement;
  if ( m_pElement->m_pLeft && m_pElement->m_pRight )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(pY);
    m_pElement->vfptr[1].__vecDelDtor(m_pElement, (unsigned int)pY->m_pElement);
    v5 = pY->m_pElement;
    v6 = m_pElement;
  }
  else
  {
    v11.m_pList = 0i64;
    v11.m_pElement = 0i64;
    v11.m_parents.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v11, pY);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v11);
    v6 = v11.m_pElement;
    v5 = m_pElement;
    if ( v11.m_parents.m_pList )
      v11.m_parents.m_pList->vfptr->__vecDelDtor(v11.m_parents.m_pList, 1u);
  }
  v7 = pY->m_pElement;
  if ( v7 )
    m_pLeft = v7->m_pLeft;
  else
    m_pLeft = 0i64;
  if ( m_pLeft )
  {
    if ( v7 )
    {
      m_pRight = v7->m_pLeft;
      goto LABEL_15;
    }
  }
  else if ( v7 )
  {
    m_pRight = v7->m_pRight;
    goto LABEL_15;
  }
  m_pRight = 0i64;
LABEL_15:
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(pY, 0) )
  {
    if ( pY->m_pElement == OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(pY, 0)->m_pLeft )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(pY, 0)->m_pLeft = m_pRight;
    else
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(pY, 0)->m_pRight = m_pRight;
  }
  else
  {
    this->m_pTop = m_pRight;
  }
  if ( pY->m_pElement->m_eColour == COLOUR_BLACK )
    OSuite::ZRedBlackTreeBase::DeleteFixUp(this, m_pRight, &pY->m_parents);
  if ( v5 )
    v5->vfptr->__vecDelDtor(v5, 1u);
  --this->m_nTotalElements;
  return v6;
}

// File Line: 727
// RVA: 0xEE5BB8
char __fastcall OSuite::ZRedBlackTreeBase::FindExactElement(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pElement,
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pParents)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rbx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+30h] [rbp+8h] BYREF

  m_pList = pParents->m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  pParents->m_pList = 0i64;
  pParents->m_nFree = 0i64;
  m_pTop = this->m_pTop;
  element = m_pTop;
  if ( m_pTop )
  {
    do
    {
      if ( pElement == m_pTop )
        return 1;
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(pParents, &element);
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[3].__vecDelDtor)(
             this,
             pElement,
             m_pTop) )
      {
        m_pTop = m_pTop->m_pLeft;
      }
      else
      {
        m_pTop = m_pTop->m_pRight;
      }
      element = m_pTop;
    }
    while ( m_pTop );
    v8 = pParents->m_pList;
    if ( v8 )
      v8->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(v8, 1u);
    pParents->m_pList = 0i64;
    pParents->m_nFree = 0i64;
  }
  return 0;
}

// File Line: 756
// RVA: 0xEE5C70
OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> *__fastcall OSuite::ZRedBlackTreeBase::FindKeyElement(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> *result,
        OSuite::ZRedBlackTreeBase::ZElementBase *dataElement)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rbx
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // rax
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+40h] [rbp+8h] BYREF

  m_pTop = this->m_pTop;
  element = m_pTop;
  if ( m_pTop )
  {
    v7 = (OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)OSuite::ZObject::operator new(0x48ui64);
    v8 = v7;
    if ( v7 )
    {
      v7->m_nFree = 0i64;
      v7->m_pList = 0i64;
      v7->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      v7->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    }
    else
    {
      v8 = 0i64;
    }
    do
    {
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[2].__vecDelDtor)(
             this,
             dataElement,
             m_pTop) )
      {
        result->m_First = m_pTop;
        result->m_Second = v8;
        goto LABEL_13;
      }
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v8, &element);
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[3].__vecDelDtor)(
             this,
             dataElement,
             m_pTop) )
      {
        m_pTop = m_pTop->m_pLeft;
      }
      else
      {
        m_pTop = m_pTop->m_pRight;
      }
      element = m_pTop;
    }
    while ( m_pTop );
    if ( v8 )
      v8->OSuite::ZObject::vfptr->__vecDelDtor(v8, 1u);
  }
  result->m_First = 0i64;
  result->m_Second = 0i64;
LABEL_13:
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *>::`vftable;
  return result;
}

// File Line: 878
// RVA: 0xEE5D60
void __fastcall OSuite::ZRedBlackTreeBase::InsertElementSet(
        OSuite::ZRedBlackTreeBase *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *pData)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pTop; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+20h] [rbp-29h] BYREF
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> zParents; // [rsp+30h] [rbp-19h] BYREF

  if ( pData )
  {
    m_pTop = this->m_pTop;
    if ( m_pTop )
    {
      zParents.m_nFree = 0i64;
      zParents.m_pList = 0i64;
      zParents.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      element = m_pTop;
      zParents.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      while ( !((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[2].__vecDelDtor)(
                 this,
                 pData,
                 m_pTop) )
      {
        v5 = m_pTop;
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&zParents, &element);
        if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[3].__vecDelDtor)(
               this,
               pData,
               m_pTop) )
        {
          m_pTop = m_pTop->m_pLeft;
        }
        else
        {
          m_pTop = m_pTop->m_pRight;
        }
        element = m_pTop;
        if ( !m_pTop )
        {
          if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->vfptr[3].__vecDelDtor)(
                 this,
                 pData,
                 v5) )
          {
            v5->m_pLeft = pData;
          }
          else
          {
            v5->m_pRight = pData;
          }
          pData->m_pLeft = 0i64;
          pData->m_pRight = 0i64;
          pData->m_eColour = COLOUR_RED;
          OSuite::ZRedBlackTreeBase::InsertFixUp(this, pData, &zParents);
          if ( zParents.m_pList )
            zParents.m_pList->vfptr->__vecDelDtor(zParents.m_pList, 1u);
          goto LABEL_15;
        }
      }
      m_pTop->vfptr[1].__vecDelDtor(m_pTop, (unsigned int)pData);
      pData->vfptr->__vecDelDtor(pData, 1i64);
      if ( zParents.m_pList )
        zParents.m_pList->vfptr->__vecDelDtor(zParents.m_pList, 1u);
    }
    else
    {
      this->m_pTop = pData;
      pData->m_pLeft = 0i64;
      this->m_pTop->m_pRight = 0i64;
      this->m_pTop->m_eColour = COLOUR_BLACK;
LABEL_15:
      ++this->m_nTotalElements;
    }
  }
}

