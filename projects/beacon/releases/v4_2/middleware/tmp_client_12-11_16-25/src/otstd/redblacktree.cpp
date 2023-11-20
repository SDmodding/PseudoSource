// File Line: 43
// RVA: 0xEE525C
void __fastcall OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom(OSuite::ZRedBlackTreeBase::ZElementBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pElement)
{
  __int64 v2; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rcx
  __int64 v6; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rcx

  v2 = 0i64;
  v3 = pElement;
  v4 = this;
  if ( pElement )
  {
    this->m_eColour = pElement->m_eColour;
    v5 = pElement->m_pLeft;
    if ( v5 )
      v6 = ((__int64 (*)(void))v5->vfptr[2].__vecDelDtor)();
    else
      v6 = 0i64;
    v4->m_pLeft = (OSuite::ZRedBlackTreeBase::ZElementBase *)v6;
    v7 = v3->m_pRight;
    if ( v7 )
      v2 = ((__int64 (*)(void))v7->vfptr[2].__vecDelDtor)();
    v4->m_pRight = (OSuite::ZRedBlackTreeBase::ZElementBase *)v2;
  }
  else
  {
    this->m_eColour = 1;
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
  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
}

// File Line: 69
// RVA: 0xEE4D2C
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(OSuite::ZRedBlackTreeBase::ZIteratorBase *this, OSuite::ZRedBlackTreeBase::ZIteratorBase *other)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rcx

  v2 = &this->m_parents;
  v2[-1].m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)other->m_pList;
  v2[-1].m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)other->m_pElement;
  v2->m_nFree = 0i64;
  v2->m_pList = 0i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(v2, &other->m_parents);
}

// File Line: 77
// RVA: 0xEE4DC0
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(OSuite::ZRedBlackTreeBase::ZIteratorBase *this, OSuite::ZRedBlackTreeBase *pList, OSuite::ZRedBlackTreeBase::ZElementBase *pElement, OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pParents)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v4; // rcx
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rbx

  this->m_pList = pList;
  this->m_pElement = pElement;
  this->m_parents.m_nFree = 0i64;
  this->m_parents.m_pList = 0i64;
  v4 = &this->m_parents;
  v5 = pParents;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v4->vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( pParents )
  {
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(v4, pParents);
    v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
  }
}

// File Line: 89
// RVA: 0xEE4D7C
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(OSuite::ZRedBlackTreeBase::ZIteratorBase *this, OSuite::ZRedBlackTreeBase *pList)
{
  this->m_pList = pList;
  this->m_pElement = 0i64;
  this->m_parents.m_nFree = 0i64;
  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  this->m_parents.m_pList = 0i64;
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(this);
}

// File Line: 94
// RVA: 0xEE4F14
OSuite::ZRedBlackTreeBase::ZIteratorBase *__fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(OSuite::ZRedBlackTreeBase::ZIteratorBase *this, OSuite::ZRedBlackTreeBase::ZIteratorBase *that)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v2; // rdi
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v3; // rbx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
      (OSuite::ZObject *)&this->vfptr,
      (OSuite::ZObject *)&that->vfptr);
    v3->m_pList = v2->m_pList;
    v3->m_pElement = v2->m_pElement;
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(&v3->m_parents, &v2->m_parents);
  }
  return v3;
}

// File Line: 114
// RVA: 0xEE50A0
_BOOL8 __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  return this->m_pElement != 0i64;
}

// File Line: 120
// RVA: 0xEE6654
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase **v1; // rbx
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v2; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rax
  bool v5; // zf
  OSuite::ZRedBlackTreeBase::ZElementBase *i; // rcx

  v1 = &this->m_pElement;
  v2 = this;
  v3 = this->m_pElement;
  if ( !v3 )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(this);
    return;
  }
  if ( v3->m_pRight )
    goto LABEL_8;
  if ( !this->m_parents.m_nFree )
  {
LABEL_6:
    if ( *v1 == v2->m_pList->m_pTop )
    {
      *v1 = 0i64;
      return;
    }
LABEL_8:
    OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&v2->m_parents, v1);
    for ( i = (*v1)->m_pRight; ; i = (*v1)->m_pLeft )
    {
      *v1 = i;
      if ( !i->m_pLeft )
        break;
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&v2->m_parents, v1);
    }
    return;
  }
  while ( 1 )
  {
    v4 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(&v2->m_parents);
    v5 = *v1 == v4->m_pLeft;
    *v1 = v4;
    if ( v5 )
      break;
    if ( !v2->m_parents.m_nFree )
      goto LABEL_6;
  }
}

// File Line: 196
// RVA: 0xEE68CC
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v1; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rcx

  v1 = this;
  v2 = OSuite::ZRedBlackTreeBase::DeleteElement(this->m_pList, this);
  v1->m_pElement = v2;
  if ( v2 )
  {
    OSuite::ZRedBlackTreeBase::FindExactElement(v1->m_pList, v2, &v1->m_parents);
  }
  else
  {
    v3 = v1->m_parents.m_pList;
    if ( v3 )
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
    v1->m_parents.m_pList = 0i64;
    v1->m_parents.m_nFree = 0i64;
  }
}

// File Line: 221
// RVA: 0xEE66F8
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(OSuite::ZRedBlackTreeBase::ZIteratorBase *this, int nAncestor)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v2; // r8
  unsigned __int64 v4; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  signed __int64 v8; // rax

  v2 = this;
  if ( !this->m_parents.m_nFree )
    return 0i64;
  v4 = this->m_parents.m_nFree - nAncestor - 1;
  if ( v4 < 5 )
  {
    v8 = (signed __int64)&v2->m_parents.m_staticList[v4];
  }
  else
  {
    v5 = v2->m_parents.m_pList;
    v6 = v4 - 5;
    v7 = v4 - 5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v2->m_parents.m_pList, v7);
    if ( v6 >= v5->m_nTop )
      v5->m_nTop = v7;
    v8 = (signed __int64)&v5->m_pList[v6];
  }
  return *(OSuite::ZRedBlackTreeBase::ZElementBase **)v8;
}

// File Line: 235
// RVA: 0xEE65E0
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::MoveToFirst(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v1; // rsi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rcx
  signed __int64 v4; // rdi

  v1 = this;
  v2 = this->m_parents.m_pList;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v1->m_parents.m_pList = 0i64;
  v1->m_parents.m_nFree = 0i64;
  v3 = v1->m_pList->m_pTop;
  v4 = (signed __int64)&v1->m_pElement;
  v1->m_pElement = v3;
  if ( v3 )
  {
    while ( v3->m_pLeft )
    {
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&v1->m_parents, &v1->m_pElement);
      v3 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v4 + 8i64);
      *(_QWORD *)v4 = v3;
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
  OSuite::ZRedBlackTreeBase::ZElementBase *v1; // rdx

  v1 = this->m_pTop;
  if ( v1 )
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, v1);
}

// File Line: 297
// RVA: 0xEE4F5C
OSuite::ZRedBlackTreeBase *__fastcall OSuite::ZRedBlackTreeBase::operator=(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase *that)
{
  OSuite::ZRedBlackTreeBase *v2; // rdi
  OSuite::ZRedBlackTreeBase *v3; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rdx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    v4 = this->m_pTop;
    if ( v4 )
      OSuite::ZRedBlackTreeBase::DeleteSubTree(this, v4);
    OSuite::ZRedBlackTreeBase::CopyFrom(v3, v2);
  }
  return v3;
}

// File Line: 312
// RVA: 0xEE4F98
char __fastcall OSuite::ZRedBlackTreeBase::operator==(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase *that)
{
  OSuite::ZRedBlackTreeBase *v2; // rdi
  OSuite::ZRedBlackTreeBase *v3; // rbx
  char v5; // bl
  OSuite::ZRedBlackTreeBase::ZIteratorBase v6; // [rsp+20h] [rbp-79h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+80h] [rbp-19h]

  v2 = that;
  v3 = this;
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
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, v2);
  while ( 1 )
  {
    if ( !v6.m_pElement || !v7.m_pElement )
    {
      v5 = 1;
      goto LABEL_10;
    }
    if ( !(unsigned __int8)v3->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, (unsigned int)v6.m_pElement) )
      break;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v6);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v5 = 0;
LABEL_10:
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v7.m_parents.m_pList, 1u);
  if ( v6.m_parents.m_pList )
    v6.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v6.m_parents.m_pList, 1u);
  return v5;
}

// File Line: 349
// RVA: 0xEE5100
void __fastcall OSuite::ZRedBlackTreeBase::Clear(OSuite::ZRedBlackTreeBase *this)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v1; // rdx
  OSuite::ZRedBlackTreeBase *v2; // rbx

  v1 = this->m_pTop;
  v2 = this;
  if ( v1 )
  {
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, v1);
    v2->m_pTop = 0i64;
  }
  v2->m_nTotalElements = 0i64;
}

// File Line: 374
// RVA: 0xEE65D4
_BOOL8 __fastcall OSuite::ZRedBlackTreeBase::IsEmpty(OSuite::ZRedBlackTreeBase *this)
{
  return this->m_pTop == 0i64;
}

// File Line: 380
// RVA: 0xEE543C
void __fastcall OSuite::ZRedBlackTreeBase::DeleteFixUp(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pX, OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pXParents)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rdi
  OSuite::ZRedBlackTreeBase *v5; // r15
  unsigned __int64 v6; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // rsi
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  signed __int64 v10; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v11; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *v12; // rsi
  unsigned __int64 v13; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v14; // rdi
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rbp
  signed __int64 v17; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v19; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v20; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v21; // rax
  unsigned __int64 v22; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v23; // rdi
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // rbp
  signed __int64 v26; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v27; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v28; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v29; // rax
  unsigned __int64 v30; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v31; // rdi
  unsigned __int64 v32; // rsi
  unsigned __int64 v33; // rbp
  signed __int64 v34; // rax
  unsigned __int64 v35; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v36; // rdi
  unsigned __int64 v37; // rbp
  unsigned __int64 v38; // r14
  signed __int64 v39; // rax
  unsigned __int64 v40; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v41; // rdi
  unsigned __int64 v42; // rbp
  unsigned __int64 v43; // r14
  signed __int64 v44; // rax
  unsigned __int64 v45; // rax
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
  signed __int64 v68; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v69; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v70; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v71; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v72; // rax
  unsigned __int64 v73; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v74; // rdi
  unsigned __int64 v75; // rsi
  unsigned __int64 v76; // rbp
  signed __int64 v77; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v78; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v79; // rcx
  unsigned __int64 v80; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v81; // rdi
  unsigned __int64 v82; // rsi
  unsigned __int64 v83; // rbp
  signed __int64 v84; // rax
  unsigned __int64 v85; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v86; // rdi
  unsigned __int64 v87; // rbp
  unsigned __int64 v88; // r14
  signed __int64 v89; // rax
  unsigned __int64 v90; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v91; // rdi
  unsigned __int64 v92; // rbp
  unsigned __int64 v93; // r14
  signed __int64 v94; // rax
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
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+60h] [rbp+8h]
  OSuite::ZRedBlackTreeBase::ZElementBase *v114; // [rsp+68h] [rbp+10h]

  v3 = pXParents;
  v4 = pX;
  v5 = this;
  while ( v4 != v5->m_pTop )
  {
    if ( v4 && v4->m_eColour != 1 )
      break;
    v6 = v3->m_nFree - 1;
    if ( v6 < 5 )
    {
      v10 = (signed __int64)&v3->m_staticList[v6];
    }
    else
    {
      v7 = v3->m_pList;
      v8 = v3->m_nFree - 6;
      v9 = v3->m_nFree - 5;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v9);
      if ( v8 >= v7->m_nTop )
        v7->m_nTop = v9;
      v10 = (signed __int64)&v7->m_pList[v8];
    }
    v11 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)v10;
    v12 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v10 + 8i64);
    if ( v4 == v12 )
    {
      v12 = v11->m_pRight;
      if ( v12 )
      {
        if ( v12->m_eColour == COLOUR_RED )
        {
          v12->m_eColour = 1;
          v13 = v3->m_nFree - 1;
          if ( v13 < 5 )
          {
            v17 = (signed __int64)v3 + 8 * (v13 + 3);
          }
          else
          {
            v14 = v3->m_pList;
            v15 = v3->m_nFree - 6;
            v16 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v16);
            if ( v15 >= v14->m_nTop )
              v14->m_nTop = v16;
            v17 = (signed __int64)&v14->m_pList[v15];
          }
          *(_DWORD *)(*(_QWORD *)v17 + 24i64) = 0;
          v18 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v3);
          v19 = v18->m_pRight;
          v20 = v18;
          v114 = v18;
          element = v19;
          if ( v3->m_nFree <= 0 )
          {
            v18->m_pRight = v19->m_pLeft;
            v5->m_pTop = v19;
            v19->m_pLeft = v18;
          }
          else
          {
            v21 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v3);
            OSuite::ZRedBlackTreeBase::RotateLeft(v5, v20, v21);
          }
          OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v3, &element);
          OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v3, &v114);
          v22 = v3->m_nFree - 1;
          if ( v22 < 5 )
          {
            v26 = (signed __int64)v3 + 8 * (v22 + 3);
          }
          else
          {
            v23 = v3->m_pList;
            v24 = v3->m_nFree - 6;
            v25 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v25);
            if ( v24 >= v23->m_nTop )
              v23->m_nTop = v25;
            v26 = (signed __int64)&v23->m_pList[v24];
          }
          v12 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v26 + 16i64);
        }
        if ( !v12
          || (v27 = v12->m_pLeft) != 0i64 && v27->m_eColour != 1
          || (v28 = v12->m_pRight) != 0i64 && v28->m_eColour != 1 )
        {
          v29 = v12->m_pRight;
          if ( !v29 || v29->m_eColour == 1 )
          {
            v12->m_pLeft->m_eColour = 1;
            v12->m_eColour = 0;
            OSuite::ZRedBlackTreeBase::RotateRight(v5, v12, v11);
            v30 = v3->m_nFree - 1;
            if ( v30 < 5 )
            {
              v34 = (signed __int64)v3 + 8 * (v30 + 3);
            }
            else
            {
              v31 = v3->m_pList;
              v32 = v3->m_nFree - 6;
              v33 = v3->m_nFree - 5;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v33);
              if ( v32 >= v31->m_nTop )
                v31->m_nTop = v33;
              v34 = (signed __int64)&v31->m_pList[v32];
            }
            v12 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v34 + 16i64);
          }
          v35 = v3->m_nFree - 1;
          if ( v35 < 5 )
          {
            v39 = (signed __int64)v3 + 8 * (v35 + 3);
          }
          else
          {
            v36 = v3->m_pList;
            v37 = v3->m_nFree - 6;
            v38 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v38);
            if ( v37 >= v36->m_nTop )
              v36->m_nTop = v38;
            v39 = (signed __int64)&v36->m_pList[v37];
          }
          v12->m_eColour = *(_DWORD *)(*(_QWORD *)v39 + 24i64);
          v40 = v3->m_nFree - 1;
          if ( v40 < 5 )
          {
            v44 = (signed __int64)v3 + 8 * (v40 + 3);
          }
          else
          {
            v41 = v3->m_pList;
            v42 = v3->m_nFree - 6;
            v43 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v43);
            if ( v42 >= v41->m_nTop )
              v41->m_nTop = v43;
            v44 = (signed __int64)&v41->m_pList[v42];
          }
          *(_DWORD *)(*(_QWORD *)v44 + 24i64) = 1;
          v12->m_pRight->m_eColour = 1;
          v45 = v3->m_nFree;
          if ( v45 <= 1 )
          {
            v56 = v45 - 1;
            if ( v56 < 5 )
            {
              v60 = &v3->m_staticList[v56];
            }
            else
            {
              v57 = v3->m_pList;
              v58 = v56 - 5;
              v59 = v56 - 5 + 1;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v59);
              if ( v58 >= v57->m_nTop )
                v57->m_nTop = v59;
              v60 = &v57->m_pList[v58];
            }
            v61 = *v60;
            v62 = v61->m_pRight;
            v61->m_pRight = v62->m_pLeft;
            v5->m_pTop = v62;
            v62->m_pLeft = v61;
          }
          else
          {
            v46 = v45 - 2;
            if ( v46 < 5 )
            {
              v50 = &v3->m_staticList[v46];
            }
            else
            {
              v47 = v3->m_pList;
              v48 = v46 - 5;
              v49 = v46 - 5 + 1;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v49);
              if ( v48 >= v47->m_nTop )
                v47->m_nTop = v49;
              v50 = &v47->m_pList[v48];
            }
            v51 = v3->m_nFree - 1;
            if ( v51 < 5 )
            {
              v55 = &v3->m_staticList[v51];
            }
            else
            {
              v52 = v3->m_pList;
              v53 = v3->m_nFree - 6;
              v54 = v3->m_nFree - 5;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v54);
              if ( v53 >= v52->m_nTop )
                v52->m_nTop = v54;
              v55 = &v52->m_pList[v53];
            }
            OSuite::ZRedBlackTreeBase::RotateLeft(v5, *v55, *v50);
          }
LABEL_67:
          v63 = v3->m_pList;
          v4 = v5->m_pTop;
          if ( v63 )
            v63->vfptr->__vecDelDtor((OSuite::ZObject *)&v63->vfptr, 1u);
          v3->m_pList = 0i64;
          v3->m_nFree = 0i64;
          continue;
        }
LABEL_126:
        v12->m_eColour = 0;
        v4 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v3);
        continue;
      }
    }
    else if ( v12 )
    {
      if ( v12->m_eColour == COLOUR_RED )
      {
        v12->m_eColour = 1;
        v64 = v3->m_nFree - 1;
        if ( v64 < 5 )
        {
          v68 = (signed __int64)v3 + 8 * (v64 + 3);
        }
        else
        {
          v65 = v3->m_pList;
          v66 = v3->m_nFree - 6;
          v67 = v3->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v67);
          if ( v66 >= v65->m_nTop )
            v65->m_nTop = v67;
          v68 = (signed __int64)&v65->m_pList[v66];
        }
        *(_DWORD *)(*(_QWORD *)v68 + 24i64) = 0;
        v69 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v3);
        v70 = v69->m_pLeft;
        v71 = v69;
        v114 = v69;
        element = v70;
        if ( v3->m_nFree <= 0 )
        {
          v69->m_pLeft = v70->m_pRight;
          v5->m_pTop = v70;
          v70->m_pRight = v69;
        }
        else
        {
          v72 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v3);
          OSuite::ZRedBlackTreeBase::RotateRight(v5, v71, v72);
        }
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v3, &element);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v3, &v114);
        v73 = v3->m_nFree - 1;
        if ( v73 < 5 )
        {
          v77 = (signed __int64)v3 + 8 * (v73 + 3);
        }
        else
        {
          v74 = v3->m_pList;
          v75 = v3->m_nFree - 6;
          v76 = v3->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v76);
          if ( v75 >= v74->m_nTop )
            v74->m_nTop = v76;
          v77 = (signed __int64)&v74->m_pList[v75];
        }
        v12 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v77 + 8i64);
      }
      v78 = v12->m_pLeft;
      if ( v78 && v78->m_eColour != 1 || (v79 = v12->m_pRight) != 0i64 && v79->m_eColour != 1 )
      {
        if ( !v78 || v78->m_eColour == 1 )
        {
          v12->m_pRight->m_eColour = 1;
          v12->m_eColour = 0;
          OSuite::ZRedBlackTreeBase::RotateLeft(v5, v12, v11);
          v80 = v3->m_nFree - 1;
          if ( v80 < 5 )
          {
            v84 = (signed __int64)v3 + 8 * (v80 + 3);
          }
          else
          {
            v81 = v3->m_pList;
            v82 = v3->m_nFree - 6;
            v83 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v83);
            if ( v82 >= v81->m_nTop )
              v81->m_nTop = v83;
            v84 = (signed __int64)&v81->m_pList[v82];
          }
          v12 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v84 + 8i64);
        }
        v85 = v3->m_nFree - 1;
        if ( v85 < 5 )
        {
          v89 = (signed __int64)v3 + 8 * (v85 + 3);
        }
        else
        {
          v86 = v3->m_pList;
          v87 = v3->m_nFree - 6;
          v88 = v3->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v88);
          if ( v87 >= v86->m_nTop )
            v86->m_nTop = v88;
          v89 = (signed __int64)&v86->m_pList[v87];
        }
        v12->m_eColour = *(_DWORD *)(*(_QWORD *)v89 + 24i64);
        v90 = v3->m_nFree - 1;
        if ( v90 < 5 )
        {
          v94 = (signed __int64)v3 + 8 * (v90 + 3);
        }
        else
        {
          v91 = v3->m_pList;
          v92 = v3->m_nFree - 6;
          v93 = v3->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v93);
          if ( v92 >= v91->m_nTop )
            v91->m_nTop = v93;
          v94 = (signed __int64)&v91->m_pList[v92];
        }
        *(_DWORD *)(*(_QWORD *)v94 + 24i64) = 1;
        v12->m_pLeft->m_eColour = 1;
        v95 = v3->m_nFree;
        if ( v95 <= 1 )
        {
          v106 = v95 - 1;
          if ( v106 < 5 )
          {
            v110 = &v3->m_staticList[v106];
          }
          else
          {
            v107 = v3->m_pList;
            v108 = v106 - 5;
            v109 = v106 - 5 + 1;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v109);
            if ( v108 >= v107->m_nTop )
              v107->m_nTop = v109;
            v110 = &v107->m_pList[v108];
          }
          v111 = *v110;
          v112 = v111->m_pLeft;
          v111->m_pLeft = v112->m_pRight;
          v5->m_pTop = v112;
          v112->m_pRight = v111;
        }
        else
        {
          v96 = v95 - 2;
          if ( v96 < 5 )
          {
            v100 = &v3->m_staticList[v96];
          }
          else
          {
            v97 = v3->m_pList;
            v98 = v96 - 5;
            v99 = v96 - 5 + 1;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v99);
            if ( v98 >= v97->m_nTop )
              v97->m_nTop = v99;
            v100 = &v97->m_pList[v98];
          }
          v101 = v3->m_nFree - 1;
          if ( v101 < 5 )
          {
            v105 = &v3->m_staticList[v101];
          }
          else
          {
            v102 = v3->m_pList;
            v103 = v3->m_nFree - 6;
            v104 = v3->m_nFree - 5;
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3->m_pList, v104);
            if ( v103 >= v102->m_nTop )
              v102->m_nTop = v104;
            v105 = &v102->m_pList[v103];
          }
          OSuite::ZRedBlackTreeBase::RotateRight(v5, *v105, *v100);
        }
        goto LABEL_67;
      }
      goto LABEL_126;
    }
  }
  if ( v4 )
    v4->m_eColour = 1;
}

// File Line: 506
// RVA: 0xEE5ED4
void __fastcall OSuite::ZRedBlackTreeBase::InsertFixUp(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pZ, OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *zParents)
{
  unsigned __int64 v3; // rax
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v4; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r15
  OSuite::ZRedBlackTreeBase *v6; // r13
  unsigned __int64 v7; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rdi
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  signed __int64 v11; // rax
  unsigned __int64 v12; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v13; // rdi
  unsigned __int64 v14; // rsi
  unsigned __int64 v15; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v16; // rsi
  unsigned __int64 v17; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v18; // rdi
  unsigned __int64 v19; // rbp
  signed __int64 v20; // r14
  signed __int64 v21; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v22; // rcx
  unsigned __int64 v23; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v24; // rdi
  unsigned __int64 v25; // rsi
  signed __int64 v26; // rbp
  signed __int64 v27; // rax
  __int64 v28; // rsi
  unsigned __int64 v29; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v30; // rdi
  unsigned __int64 v31; // rsi
  unsigned __int64 v32; // rbp
  signed __int64 v33; // rax
  unsigned __int64 v34; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v35; // rdi
  unsigned __int64 v36; // rsi
  unsigned __int64 v37; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v38; // r8
  unsigned __int64 v39; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v40; // rdi
  unsigned __int64 v41; // rsi
  unsigned __int64 v42; // rbp
  signed __int64 v43; // rax
  unsigned __int64 v44; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v45; // rdi
  unsigned __int64 v46; // rsi
  signed __int64 v47; // rbp
  signed __int64 v48; // rax
  unsigned __int64 v49; // rax
  unsigned __int64 v50; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v51; // rdi
  unsigned __int64 v52; // rsi
  unsigned __int64 v53; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v54; // r14
  unsigned __int64 v55; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v56; // rdi
  unsigned __int64 v57; // rsi
  signed __int64 v58; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v59; // rdx
  unsigned __int64 v60; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v61; // rdi
  unsigned __int64 v62; // rsi
  unsigned __int64 v63; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v64; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v65; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v66; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v67; // rdi
  unsigned __int64 v68; // rsi
  signed __int64 v69; // rbp
  signed __int64 v70; // rax
  unsigned __int64 v71; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v72; // rdi
  unsigned __int64 v73; // rbp
  unsigned __int64 v74; // r14
  signed __int64 v75; // rax
  unsigned __int64 v76; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v77; // rdi
  unsigned __int64 v78; // rsi
  signed __int64 v79; // rbp
  signed __int64 v80; // rax
  unsigned __int64 v81; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v82; // rdi
  unsigned __int64 v83; // rsi
  unsigned __int64 v84; // rbp
  signed __int64 v85; // rax
  unsigned __int64 v86; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v87; // rdi
  unsigned __int64 v88; // rsi
  unsigned __int64 v89; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v90; // r8
  unsigned __int64 v91; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v92; // rdi
  unsigned __int64 v93; // rsi
  unsigned __int64 v94; // rbp
  signed __int64 v95; // rax
  unsigned __int64 v96; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v97; // rdi
  unsigned __int64 v98; // rsi
  signed __int64 v99; // rbp
  signed __int64 v100; // rax
  unsigned __int64 v101; // rax
  unsigned __int64 v102; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v103; // rdi
  unsigned __int64 v104; // rsi
  unsigned __int64 v105; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v106; // r14
  unsigned __int64 v107; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v108; // rdi
  unsigned __int64 v109; // rsi
  signed __int64 v110; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v111; // rdx
  unsigned __int64 v112; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v113; // rdi
  unsigned __int64 v114; // rsi
  unsigned __int64 v115; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase **v116; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v117; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v118; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+68h] [rbp+10h]

  element = pZ;
  v3 = zParents->m_nFree;
  v4 = zParents;
  v5 = pZ;
  v6 = this;
  if ( v3 > 1 )
  {
    while ( 1 )
    {
      v7 = v3 - 1;
      if ( v7 < 5 )
      {
        v11 = (signed __int64)v4 + 8 * (v7 + 3);
      }
      else
      {
        v8 = v4->m_pList;
        v9 = v7 - 5;
        v10 = v7 - 5 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v10);
        if ( v9 >= v8->m_nTop )
          v8->m_nTop = v10;
        v11 = (signed __int64)&v8->m_pList[v9];
      }
      if ( *(_DWORD *)(*(_QWORD *)v11 + 24i64) )
        goto LABEL_125;
      v12 = v4->m_nFree - 1;
      if ( v12 < 5 )
      {
        v16 = &v4->m_staticList[v12];
      }
      else
      {
        v13 = v4->m_pList;
        v14 = v4->m_nFree - 6;
        v15 = v4->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v15);
        if ( v14 >= v13->m_nTop )
          v13->m_nTop = v15;
        v16 = &v13->m_pList[v14];
      }
      v17 = v4->m_nFree - 2;
      if ( v17 < 5 )
      {
        v21 = (signed __int64)v4 + 8 * (v17 + 3);
      }
      else
      {
        v18 = v4->m_pList;
        v19 = v4->m_nFree - 7;
        v20 = v19 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v19 + 1);
        if ( v19 >= v18->m_nTop )
          v18->m_nTop = v20;
        v21 = (signed __int64)&v18->m_pList[v19];
      }
      v22 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v21 + 8i64);
      v23 = v4->m_nFree - 2;
      if ( *v16 != v22 )
        break;
      if ( v23 < 5 )
      {
        v27 = (signed __int64)v4 + 8 * (v23 + 3);
      }
      else
      {
        v24 = v4->m_pList;
        v25 = v4->m_nFree - 7;
        v26 = v25 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v25 + 1);
        if ( v25 >= v24->m_nTop )
          v24->m_nTop = v26;
        v27 = (signed __int64)&v24->m_pList[v25];
      }
      v28 = *(_QWORD *)(*(_QWORD *)v27 + 16i64);
      if ( v28 && !*(_DWORD *)(v28 + 24) )
        goto LABEL_73;
      v29 = v4->m_nFree - 1;
      if ( v29 < 5 )
      {
        v33 = (signed __int64)v4 + 8 * (v29 + 3);
      }
      else
      {
        v30 = v4->m_pList;
        v31 = v4->m_nFree - 6;
        v32 = v4->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v32);
        if ( v31 >= v30->m_nTop )
          v30->m_nTop = v32;
        v33 = (signed __int64)&v30->m_pList[v31];
      }
      if ( v5 == *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v33 + 16i64) )
      {
        v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v4);
        v34 = v4->m_nFree - 1;
        if ( v34 < 5 )
        {
          v38 = &v4->m_staticList[v34];
        }
        else
        {
          v35 = v4->m_pList;
          v36 = v4->m_nFree - 6;
          v37 = v4->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v37);
          if ( v36 >= v35->m_nTop )
            v35->m_nTop = v37;
          v38 = &v35->m_pList[v36];
        }
        OSuite::ZRedBlackTreeBase::RotateLeft(v6, v5, *v38);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v4, &element);
        element = v5;
      }
      v39 = v4->m_nFree - 1;
      if ( v39 < 5 )
      {
        v43 = (signed __int64)v4 + 8 * (v39 + 3);
      }
      else
      {
        v40 = v4->m_pList;
        v41 = v4->m_nFree - 6;
        v42 = v4->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v42);
        if ( v41 >= v40->m_nTop )
          v40->m_nTop = v42;
        v43 = (signed __int64)&v40->m_pList[v41];
      }
      *(_DWORD *)(*(_QWORD *)v43 + 24i64) = 1;
      v44 = v4->m_nFree - 2;
      if ( v44 < 5 )
      {
        v48 = (signed __int64)v4 + 8 * (v44 + 3);
      }
      else
      {
        v45 = v4->m_pList;
        v46 = v4->m_nFree - 7;
        v47 = v46 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v46 + 1);
        if ( v46 >= v45->m_nTop )
          v45->m_nTop = v47;
        v48 = (signed __int64)&v45->m_pList[v46];
      }
      *(_DWORD *)(*(_QWORD *)v48 + 24i64) = 0;
      v49 = v4->m_nFree;
      if ( v49 < 3 )
      {
        v60 = v49 - 2;
        if ( v60 < 5 )
        {
          v64 = &v4->m_staticList[v60];
        }
        else
        {
          v61 = v4->m_pList;
          v62 = v60 - 5;
          v63 = v60 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v63);
          if ( v62 >= v61->m_nTop )
            v61->m_nTop = v63;
          v64 = &v61->m_pList[v62];
        }
        v65 = *v64;
        v66 = v65->m_pLeft;
        v65->m_pLeft = v66->m_pRight;
        v6->m_pTop = v66;
        v66->m_pRight = v65;
      }
      else
      {
        v50 = v49 - 3;
        if ( v50 < 5 )
        {
          v54 = &v4->m_staticList[v50];
        }
        else
        {
          v51 = v4->m_pList;
          v52 = v50 - 5;
          v53 = v50 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v53);
          if ( v52 >= v51->m_nTop )
            v51->m_nTop = v53;
          v54 = &v51->m_pList[v52];
        }
        v55 = v4->m_nFree - 2;
        if ( v55 < 5 )
        {
          v59 = &v4->m_staticList[v55];
        }
        else
        {
          v56 = v4->m_pList;
          v57 = v4->m_nFree - 7;
          v58 = v57 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v57 + 1);
          if ( v57 >= v56->m_nTop )
            v56->m_nTop = v58;
          v59 = &v56->m_pList[v57];
        }
        OSuite::ZRedBlackTreeBase::RotateRight(v6, *v59, *v54);
      }
LABEL_124:
      v3 = v4->m_nFree;
      if ( v3 <= 1 )
        goto LABEL_125;
    }
    if ( v23 < 5 )
    {
      v70 = (signed __int64)v4 + 8 * (v23 + 3);
    }
    else
    {
      v67 = v4->m_pList;
      v68 = v4->m_nFree - 7;
      v69 = v68 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v68 + 1);
      if ( v68 >= v67->m_nTop )
        v67->m_nTop = v69;
      v70 = (signed __int64)&v67->m_pList[v68];
    }
    v28 = *(_QWORD *)(*(_QWORD *)v70 + 8i64);
    if ( !v28 || *(_DWORD *)(v28 + 24) )
    {
      v81 = v4->m_nFree - 1;
      if ( v81 < 5 )
      {
        v85 = (signed __int64)v4 + 8 * (v81 + 3);
      }
      else
      {
        v82 = v4->m_pList;
        v83 = v4->m_nFree - 6;
        v84 = v4->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v84);
        if ( v83 >= v82->m_nTop )
          v82->m_nTop = v84;
        v85 = (signed __int64)&v82->m_pList[v83];
      }
      if ( v5 == *(OSuite::ZRedBlackTreeBase::ZElementBase **)(*(_QWORD *)v85 + 8i64) )
      {
        v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v4);
        v86 = v4->m_nFree - 1;
        if ( v86 < 5 )
        {
          v90 = &v4->m_staticList[v86];
        }
        else
        {
          v87 = v4->m_pList;
          v88 = v4->m_nFree - 6;
          v89 = v4->m_nFree - 5;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v89);
          if ( v88 >= v87->m_nTop )
            v87->m_nTop = v89;
          v90 = &v87->m_pList[v88];
        }
        OSuite::ZRedBlackTreeBase::RotateRight(v6, v5, *v90);
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v4, &element);
        element = v5;
      }
      v91 = v4->m_nFree - 1;
      if ( v91 < 5 )
      {
        v95 = (signed __int64)v4 + 8 * (v91 + 3);
      }
      else
      {
        v92 = v4->m_pList;
        v93 = v4->m_nFree - 6;
        v94 = v4->m_nFree - 5;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v94);
        if ( v93 >= v92->m_nTop )
          v92->m_nTop = v94;
        v95 = (signed __int64)&v92->m_pList[v93];
      }
      *(_DWORD *)(*(_QWORD *)v95 + 24i64) = 1;
      v96 = v4->m_nFree - 2;
      if ( v96 < 5 )
      {
        v100 = (signed __int64)v4 + 8 * (v96 + 3);
      }
      else
      {
        v97 = v4->m_pList;
        v98 = v4->m_nFree - 7;
        v99 = v98 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v98 + 1);
        if ( v98 >= v97->m_nTop )
          v97->m_nTop = v99;
        v100 = (signed __int64)&v97->m_pList[v98];
      }
      *(_DWORD *)(*(_QWORD *)v100 + 24i64) = 0;
      v101 = v4->m_nFree;
      if ( v101 < 3 )
      {
        v112 = v101 - 2;
        if ( v112 < 5 )
        {
          v116 = &v4->m_staticList[v112];
        }
        else
        {
          v113 = v4->m_pList;
          v114 = v112 - 5;
          v115 = v112 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v115);
          if ( v114 >= v113->m_nTop )
            v113->m_nTop = v115;
          v116 = &v113->m_pList[v114];
        }
        v117 = *v116;
        v118 = v117->m_pRight;
        v117->m_pRight = v118->m_pLeft;
        v6->m_pTop = v118;
        v118->m_pLeft = v117;
      }
      else
      {
        v102 = v101 - 3;
        if ( v102 < 5 )
        {
          v106 = &v4->m_staticList[v102];
        }
        else
        {
          v103 = v4->m_pList;
          v104 = v102 - 5;
          v105 = v102 - 5 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v105);
          if ( v104 >= v103->m_nTop )
            v103->m_nTop = v105;
          v106 = &v103->m_pList[v104];
        }
        v107 = v4->m_nFree - 2;
        if ( v107 < 5 )
        {
          v111 = &v4->m_staticList[v107];
        }
        else
        {
          v108 = v4->m_pList;
          v109 = v4->m_nFree - 7;
          v110 = v109 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v109 + 1);
          if ( v109 >= v108->m_nTop )
            v108->m_nTop = v110;
          v111 = &v108->m_pList[v109];
        }
        OSuite::ZRedBlackTreeBase::RotateLeft(v6, *v111, *v106);
      }
      goto LABEL_124;
    }
LABEL_73:
    v71 = v4->m_nFree - 1;
    if ( v71 < 5 )
    {
      v75 = (signed __int64)v4 + 8 * (v71 + 3);
    }
    else
    {
      v72 = v4->m_pList;
      v73 = v4->m_nFree - 6;
      v74 = v4->m_nFree - 5;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v74);
      if ( v73 >= v72->m_nTop )
        v72->m_nTop = v74;
      v75 = (signed __int64)&v72->m_pList[v73];
    }
    *(_DWORD *)(*(_QWORD *)v75 + 24i64) = 1;
    *(_DWORD *)(v28 + 24) = 1;
    v76 = v4->m_nFree - 2;
    if ( v76 < 5 )
    {
      v80 = (signed __int64)v4 + 8 * (v76 + 3);
    }
    else
    {
      v77 = v4->m_pList;
      v78 = v4->m_nFree - 7;
      v79 = v78 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v78 + 1);
      if ( v78 >= v77->m_nTop )
        v77->m_nTop = v79;
      v80 = (signed __int64)&v77->m_pList[v78];
    }
    *(_DWORD *)(*(_QWORD *)v80 + 24i64) = 0;
    OSuite::TStack<OSuite::ZJsonObject *>::Pop(v4);
    v5 = OSuite::TStack<OSuite::ZJsonObject *>::Pop(v4);
    element = v5;
    goto LABEL_124;
  }
LABEL_125:
  v6->m_pTop->m_eColour = 1;
}v77 = v4->m_pList;
      v78 = v4->m_nFree - 7;
      v79 = v78 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v4->m_pList, v78 + 1);
 

// File Line: 585
// RVA: 0xEE6924
void __fastcall OSuite::ZRedBlackTreeBase::RotateLeft(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pX, OSuite::ZRedBlackTreeBase::ZElementBase *pXParent)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // r9

  v3 = pX->m_pRight;
  pX->m_pRight = v3->m_pLeft;
  if ( pXParent )
  {
    if ( pX == pXParent->m_pLeft )
      pXParent->m_pLeft = v3;
    else
      pXParent->m_pRight = v3;
  }
  else
  {
    this->m_pTop = v3;
  }
  v3->m_pLeft = pX;
}

// File Line: 609
// RVA: 0xEE6950
void __fastcall OSuite::ZRedBlackTreeBase::RotateRight(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pY, OSuite::ZRedBlackTreeBase::ZElementBase *pYParent)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // r9

  v3 = pY->m_pLeft;
  pY->m_pLeft = v3->m_pRight;
  if ( pYParent )
  {
    if ( pY == pYParent->m_pRight )
      pYParent->m_pRight = v3;
    else
      pYParent->m_pLeft = v3;
  }
  else
  {
    this->m_pTop = v3;
  }
  v3->m_pRight = pY;
}

// File Line: 639
// RVA: 0xEE5B74
void __fastcall OSuite::ZRedBlackTreeBase::DeleteSubTree(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pNode)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::ZRedBlackTreeBase *v3; // rdi

  if ( pNode )
  {
    v2 = pNode;
    v3 = this;
    OSuite::ZRedBlackTreeBase::DeleteSubTree(this, pNode->m_pLeft);
    OSuite::ZRedBlackTreeBase::DeleteSubTree(v3, v2->m_pRight);
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  }
}

// File Line: 652
// RVA: 0xEE5224
void __fastcall OSuite::ZRedBlackTreeBase::CopyFrom(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase *that)
{
  OSuite::ZRedBlackTreeBase *v2; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rcx
  __int64 v4; // rax
  OSuite::ZRedBlackTreeBase *v5; // rdi

  v2 = this;
  v3 = that->m_pTop;
  v4 = 0i64;
  v5 = that;
  if ( v3 )
    v4 = ((__int64 (*)(void))v3->vfptr[2].__vecDelDtor)();
  v2->m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)v4;
  v2->m_nTotalElements = v5->m_nTotalElements;
}

// File Line: 659
// RVA: 0xEE52D0
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::DeleteElement(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZIteratorBase *pY)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rdi
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v3; // rbx
  OSuite::ZRedBlackTreeBase *v4; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v8; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rdi
  OSuite::ZRedBlackTreeBase::ZIteratorBase v11; // [rsp+20h] [rbp-88h]

  v2 = pY->m_pElement;
  v3 = pY;
  v4 = this;
  if ( v2->m_pLeft && v2->m_pRight )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(pY);
    v2->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, (unsigned int)v3->m_pElement);
    v5 = v3->m_pElement;
    v6 = v2;
  }
  else
  {
    v11.m_pList = 0i64;
    v11.m_pElement = 0i64;
    v11.m_parents.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v11, pY);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v11);
    v6 = v11.m_pElement;
    v5 = v2;
    if ( v11.m_parents.m_pList )
      v11.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v11.m_parents.m_pList, 1u);
  }
  v7 = v3->m_pElement;
  if ( v7 )
    v8 = v7->m_pLeft;
  else
    v8 = 0i64;
  if ( v8 )
  {
    if ( v7 )
    {
      v9 = v7->m_pLeft;
      goto LABEL_15;
    }
  }
  else if ( v7 )
  {
    v9 = v7->m_pRight;
    goto LABEL_15;
  }
  v9 = 0i64;
LABEL_15:
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(v3, 0) )
  {
    if ( v3->m_pElement == OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(v3, 0)->m_pLeft )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(v3, 0)->m_pLeft = v9;
    else
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Parent(v3, 0)->m_pRight = v9;
  }
  else
  {
    v4->m_pTop = v9;
  }
  if ( v3->m_pElement->m_eColour == 1 )
    OSuite::ZRedBlackTreeBase::DeleteFixUp(v4, v9, &v3->m_parents);
  if ( v5 )
    v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
  --v4->m_nTotalElements;
  return v6;
}

// File Line: 727
// RVA: 0xEE5BB8
char __fastcall OSuite::ZRedBlackTreeBase::FindExactElement(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pElement, OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *pParents)
{
  OSuite::ZRedBlackTreeBase *v3; // rsi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v4; // rcx
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rbx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = pParents->m_pList;
  v5 = pParents;
  v6 = pElement;
  if ( v4 )
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  v5->m_pList = 0i64;
  v5->m_nFree = 0i64;
  v7 = v3->m_pTop;
  element = v7;
  if ( v7 )
  {
    do
    {
      if ( v6 == v7 )
        return 1;
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v5, &element);
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v3->vfptr[3].__vecDelDtor)(
             v3,
             v6,
             v7) )
      {
        v7 = v7->m_pLeft;
      }
      else
      {
        v7 = v7->m_pRight;
      }
      element = v7;
    }
    while ( v7 );
    v8 = v5->m_pList;
    if ( v8 )
      v8->vfptr->__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 1u);
    v5->m_pList = 0i64;
    v5->m_nFree = 0i64;
  }
  return 0;
}

// File Line: 756
// RVA: 0xEE5C70
OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> *__fastcall OSuite::ZRedBlackTreeBase::FindKeyElement(OSuite::ZRedBlackTreeBase *this, OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> *result, OSuite::ZRedBlackTreeBase::ZElementBase *dataElement)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rbp
  OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> *v5; // rsi
  OSuite::ZRedBlackTreeBase *v6; // r14
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // rax
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+40h] [rbp+8h]

  v3 = this->m_pTop;
  v4 = dataElement;
  v5 = result;
  v6 = this;
  element = v3;
  if ( v3 )
  {
    v7 = (OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)OSuite::ZObject::operator new(0x48ui64);
    v8 = v7;
    if ( v7 )
    {
      v7->m_nFree = 0i64;
      v7->m_pList = 0i64;
      v7->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
      v7->vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    }
    else
    {
      v8 = 0i64;
    }
    do
    {
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v6->vfptr[2].__vecDelDtor)(
             v6,
             v4,
             v3) )
      {
        v5->m_First = v3;
        v5->m_Second = v8;
        goto LABEL_13;
      }
      OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(v8, &element);
      if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v6->vfptr[3].__vecDelDtor)(
             v6,
             v4,
             v3) )
      {
        v3 = v3->m_pLeft;
      }
      else
      {
        v3 = v3->m_pRight;
      }
      element = v3;
    }
    while ( v3 );
    if ( v8 )
      v8->vfptr->__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 1u);
  }
  v5->m_First = 0i64;
  v5->m_Second = 0i64;
LABEL_13:
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *>::`vftable';
  return v5;
}

// File Line: 878
// RVA: 0xEE5D60
void __fastcall OSuite::ZRedBlackTreeBase::InsertElementSet(OSuite::ZRedBlackTreeBase *this, OSuite::ZRedBlackTreeBase::ZElementBase *pData)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rdi
  OSuite::ZRedBlackTreeBase *v4; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *element; // [rsp+20h] [rbp-29h]
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> zParents; // [rsp+30h] [rbp-19h]

  if ( pData )
  {
    v2 = this->m_pTop;
    v3 = pData;
    v4 = this;
    if ( v2 )
    {
      zParents.m_nFree = 0i64;
      zParents.m_pList = 0i64;
      zParents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
      element = v2;
      zParents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
      while ( !((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v4->vfptr[2].__vecDelDtor)(
                 v4,
                 v3,
                 v2) )
      {
        v5 = v2;
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::Push(&zParents, &element);
        if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v4->vfptr[3].__vecDelDtor)(
               v4,
               v3,
               v2) )
        {
          v2 = v2->m_pLeft;
        }
        else
        {
          v2 = v2->m_pRight;
        }
        element = v2;
        if ( !v2 )
        {
          if ( ((unsigned __int8 (__fastcall *)(OSuite::ZRedBlackTreeBase *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))v4->vfptr[3].__vecDelDtor)(
                 v4,
                 v3,
                 v5) )
          {
            v5->m_pLeft = v3;
          }
          else
          {
            v5->m_pRight = v3;
          }
          v3->m_pLeft = 0i64;
          v3->m_pRight = 0i64;
          v3->m_eColour = 0;
          OSuite::ZRedBlackTreeBase::InsertFixUp(v4, v3, &zParents);
          if ( zParents.m_pList )
            zParents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)zParents.m_pList, 1u);
          goto LABEL_15;
        }
      }
      v2->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, (unsigned int)v3);
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
      if ( zParents.m_pList )
        zParents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)zParents.m_pList, 1u);
    }
    else
    {
      this->m_pTop = pData;
      pData->m_pLeft = 0i64;
      this->m_pTop->m_pRight = 0i64;
      this->m_pTop->m_eColour = 1;
LABEL_15:
      ++v4->m_nTotalElements;
    }
  }
}

