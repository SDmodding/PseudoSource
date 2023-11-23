// File Line: 35
// RVA: 0x89BD60
void __fastcall Scaleform::GFx::XML::Node::Node(
        Scaleform::GFx::XML::Node *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        char type)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::Node,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable;
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  Scaleform::GFx::XML::ObjectManager::EmptyString(this->MemoryManager.pObject, &this->Value);
  this->Parent = 0i64;
  this->PrevSibling = 0i64;
  this->NextSibling.pObject = 0i64;
  this->pShadow = 0i64;
  this->Type = type;
}

// File Line: 40
// RVA: 0x89BE00
void __fastcall Scaleform::GFx::XML::Node::Node(
        Scaleform::GFx::XML::Node *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        char type,
        Scaleform::GFx::XML::DOMString value)
{
  const char *pData; // rax
  Scaleform::GFx::XML::DOMStringNode *v5; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::Node,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable;
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  pData = value.pNode->pData;
  this->Value.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++*((_DWORD *)pData + 6);
  this->Parent = 0i64;
  this->PrevSibling = 0i64;
  this->NextSibling.pObject = 0i64;
  this->pShadow = 0i64;
  this->Type = type;
  v5 = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  if ( (*((_DWORD *)value.pNode->pData + 6))-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v5);
}

// File Line: 46
// RVA: 0x8A6FB0
void __fastcall Scaleform::GFx::XML::Node::~Node(Scaleform::GFx::XML::Node *this)
{
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rcx
  Scaleform::GFx::XML::Node *pObject; // rcx
  Scaleform::GFx::XML::DOMStringNode *pNode; // rcx
  Scaleform::GFx::XML::ObjectManager *v6; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable;
  pShadow = this->pShadow;
  if ( pShadow )
    pShadow->vfptr->__vecDelDtor(pShadow, 1u);
  pObject = this->NextSibling.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pNode = this->Value.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pNode);
  v6 = this->MemoryManager.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

// File Line: 69
// RVA: 0x896180
void __fastcall Scaleform::GFx::XML::ElementNode::ElementNode(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *pData; // rcx
  Scaleform::GFx::XML::DOMString valuea; // [rsp+68h] [rbp+20h] BYREF

  valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++valuea.pNode->RefCount;
  Scaleform::GFx::XML::Node::Node(this, memMgr, 1, (Scaleform::GFx::XML::DOMString)&valuea);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable;
  Scaleform::GFx::XML::ObjectManager::EmptyString(memMgr, &this->Prefix);
  Scaleform::GFx::XML::ObjectManager::EmptyString(memMgr, &this->Namespace);
  this->FirstAttribute = 0i64;
  this->LastAttribute = 0i64;
  this->FirstChild.pObject = 0i64;
  this->LastChild = 0i64;
  pData = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  if ( (*((_DWORD *)value.pNode->pData + 6))-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pData);
}

// File Line: 75
// RVA: 0x8A4350
void __fastcall Scaleform::GFx::XML::ElementNode::~ElementNode(Scaleform::GFx::XML::ElementNode *this)
{
  Scaleform::GFx::XML::Node *LastChild; // rbx
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::XML::Node *v4; // rcx
  Scaleform::GFx::XML::Attribute *FirstAttribute; // rdi
  Scaleform::GFx::XML::Attribute *Next; // rbp
  Scaleform::GFx::XML::DOMStringNode *pNode; // rbx
  bool v8; // zf
  Scaleform::GFx::XML::DOMStringManager *pManager; // rsi
  char *pData; // rdx
  Scaleform::GFx::XML::DOMStringNode *v11; // rbx
  Scaleform::GFx::XML::DOMStringManager *v12; // rsi
  char *v13; // rdx
  Scaleform::GFx::XML::Node *v14; // rcx
  Scaleform::GFx::XML::DOMStringNode *v15; // rcx
  Scaleform::GFx::XML::DOMStringNode *v16; // rcx
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::XML::Attribute *v18; // [rsp+70h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable;
  LastChild = this->LastChild;
  if ( LastChild )
  {
    while ( 1 )
    {
      LastChild->Parent = 0i64;
      LastChild = LastChild->PrevSibling;
      if ( !LastChild )
        break;
      pObject = LastChild->NextSibling.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      LastChild->NextSibling.pObject = 0i64;
    }
  }
  if ( this->FirstChild.pObject )
  {
    v4 = this->FirstChild.pObject;
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    this->FirstChild.pObject = 0i64;
  }
  FirstAttribute = this->FirstAttribute;
  if ( FirstAttribute )
  {
    do
    {
      Next = FirstAttribute->Next;
      v18 = FirstAttribute;
      pNode = FirstAttribute->Value.pNode;
      v8 = pNode->RefCount-- == 1;
      if ( v8 )
      {
        key = pNode;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &pNode->pManager->StringSet,
          &key);
        pManager = pNode->pManager;
        pData = (char *)pNode->pData;
        if ( pNode->pData )
        {
          if ( pNode->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)pData = pManager->pFreeTextBuffers;
            pManager->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pData;
          }
          pNode->pData = 0i64;
        }
        pNode->pManager = (Scaleform::GFx::XML::DOMStringManager *)pManager->pFreeStringNodes;
        pManager->pFreeStringNodes = pNode;
      }
      v11 = FirstAttribute->Name.pNode;
      v8 = FirstAttribute->Name.pNode->RefCount-- == 1;
      if ( v8 )
      {
        key = v11;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &v11->pManager->StringSet,
          &key);
        v12 = v11->pManager;
        v13 = (char *)v11->pData;
        if ( v11->pData )
        {
          if ( v11->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v13 = v12->pFreeTextBuffers;
            v12->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v13;
          }
          v11->pData = 0i64;
        }
        v11->pManager = (Scaleform::GFx::XML::DOMStringManager *)v12->pFreeStringNodes;
        v12->pFreeStringNodes = v11;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, FirstAttribute);
      FirstAttribute = Next;
    }
    while ( Next );
  }
  v14 = this->FirstChild.pObject;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  v15 = this->Namespace.pNode;
  v8 = v15->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v15);
  v16 = this->Prefix.pNode;
  v8 = v16->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v16);
  Scaleform::GFx::XML::Node::~Node(this);
}

// File Line: 110
// RVA: 0x8BCCB0
Scaleform::GFx::XML::ElementNode *__fastcall Scaleform::GFx::XML::ElementNode::Clone(
        Scaleform::GFx::XML::ElementNode *this,
        bool deep)
{
  Scaleform::GFx::XML::ElementNode *ElementNode; // rbx
  Scaleform::GFx::XML::DOMString value; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::XML::DOMString *p_value; // [rsp+50h] [rbp+18h]

  p_value = &value;
  value.pNode = this->Value.pNode;
  ++value.pNode->RefCount;
  ElementNode = Scaleform::GFx::XML::ObjectManager::CreateElementNode(
                  this->MemoryManager.pObject,
                  (Scaleform::GFx::XML::DOMString)&value);
  Scaleform::GFx::XML::ElementNode::CloneHelper(this, ElementNode, deep);
  ElementNode->Type = this->Type;
  return ElementNode;
}

// File Line: 122
// RVA: 0x8BCFA0
void __fastcall Scaleform::GFx::XML::ElementNode::CloneHelper(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::ElementNode *clone,
        bool deep)
{
  Scaleform::GFx::XML::DOMStringNode *pNode; // rbx
  Scaleform::GFx::XML::DOMStringNode *v7; // rcx
  Scaleform::GFx::XML::Attribute *FirstAttribute; // rbx
  Scaleform::GFx::XML::Attribute *Attribute; // rax
  Scaleform::GFx::XML::Node *i; // rsi
  __int64 v12; // rbx
  Scaleform::GFx::XML::Node *LastChild; // rax
  Scaleform::GFx::XML::Node *v14; // rcx
  Scaleform::GFx::XML::Node *v15; // r14
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::XML::DOMString value; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::XML::DOMString name; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::XML::DOMString *p_value; // [rsp+78h] [rbp+20h]

  pNode = this->Prefix.pNode;
  ++pNode->RefCount;
  v7 = clone->Prefix.pNode;
  if ( v7->RefCount-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v7);
  clone->Prefix.pNode = pNode;
  FirstAttribute = this->FirstAttribute;
  if ( FirstAttribute )
  {
    p_value = &value;
    do
    {
      value.pNode = FirstAttribute->Value.pNode;
      ++value.pNode->RefCount;
      name.pNode = FirstAttribute->Name.pNode;
      ++name.pNode->RefCount;
      Attribute = Scaleform::GFx::XML::ObjectManager::CreateAttribute(
                    this->MemoryManager.pObject,
                    (Scaleform::GFx::XML::DOMString)&name,
                    (Scaleform::GFx::XML::DOMString)&value);
      if ( clone->FirstAttribute )
        clone->LastAttribute->Next = Attribute;
      else
        clone->FirstAttribute = Attribute;
      clone->LastAttribute = Attribute;
      FirstAttribute = FirstAttribute->Next;
    }
    while ( FirstAttribute );
  }
  if ( deep )
  {
    for ( i = this->FirstChild.pObject; i; i = i->NextSibling.pObject )
    {
      v12 = (__int64)i->vfptr[1].__vecDelDtor(i, deep);
      value.pNode = (Scaleform::GFx::XML::DOMStringNode *)v12;
      LastChild = clone->LastChild;
      if ( LastChild )
      {
        *(_QWORD *)(v12 + 40) = LastChild;
        v15 = clone->LastChild;
        ++*(_DWORD *)(v12 + 8);
        pObject = v15->NextSibling.pObject;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        v15->NextSibling.pObject = (Scaleform::GFx::XML::Node *)v12;
      }
      else
      {
        if ( v12 )
          ++*(_DWORD *)(v12 + 8);
        v14 = clone->FirstChild.pObject;
        if ( v14 )
          Scaleform::RefCountNTSImpl::Release(v14);
        clone->FirstChild.pObject = (Scaleform::GFx::XML::Node *)v12;
      }
      clone->LastChild = (Scaleform::GFx::XML::Node *)v12;
      *(_QWORD *)(v12 + 32) = clone;
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v12);
    }
  }
}

// File Line: 149
// RVA: 0x8B6420
void __fastcall Scaleform::GFx::XML::ElementNode::AppendChild(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *LastChild; // rax
  Scaleform::GFx::XML::Node *v5; // rcx
  Scaleform::GFx::XML::Node *v6; // rsi
  Scaleform::RefCountNTSImpl *pObject; // rcx

  LastChild = this->LastChild;
  if ( LastChild )
  {
    xmlNode->PrevSibling = LastChild;
    v6 = this->LastChild;
    ++xmlNode->RefCount;
    pObject = v6->NextSibling.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    v6->NextSibling.pObject = xmlNode;
    this->LastChild = xmlNode;
    xmlNode->Parent = this;
  }
  else
  {
    if ( xmlNode )
      ++xmlNode->RefCount;
    v5 = this->FirstChild.pObject;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    this->FirstChild.pObject = xmlNode;
    this->LastChild = xmlNode;
    xmlNode->Parent = this;
  }
}

// File Line: 179
// RVA: 0x8E6270
void __fastcall Scaleform::GFx::XML::ElementNode::InsertBefore(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *child,
        Scaleform::GFx::XML::Node *insert)
{
  Scaleform::GFx::XML::Node *PrevSibling; // rbp
  Scaleform::GFx::XML::Node *pObject; // rcx
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::GFx::XML::Node *v9; // rcx

  PrevSibling = insert->PrevSibling;
  insert->PrevSibling = child;
  child->PrevSibling = PrevSibling;
  ++insert->RefCount;
  pObject = child->NextSibling.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  child->NextSibling.pObject = insert;
  if ( PrevSibling )
  {
    ++child->RefCount;
    v8 = PrevSibling->NextSibling.pObject;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    PrevSibling->NextSibling.pObject = child;
  }
  if ( insert == this->FirstChild.pObject )
  {
    ++child->RefCount;
    v9 = this->FirstChild.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    this->FirstChild.pObject = child;
  }
  child->Parent = this;
}

// File Line: 208
// RVA: 0x8FF010
void __fastcall Scaleform::GFx::XML::ElementNode::RemoveChild(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *pObject; // rax
  Scaleform::GFx::XML::Node *v5; // rcx
  Scaleform::GFx::XML::Node *v6; // rcx
  Scaleform::GFx::XML::Node *PrevSibling; // rdi
  Scaleform::GFx::XML::Node *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // rcx
  Scaleform::GFx::XML::Node *v10; // rcx

  if ( xmlNode )
    ++xmlNode->RefCount;
  if ( xmlNode == this->FirstChild.pObject )
  {
    pObject = xmlNode->NextSibling.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v5 = this->FirstChild.pObject;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    this->FirstChild.pObject = xmlNode->NextSibling.pObject;
  }
  if ( xmlNode == this->LastChild )
    this->LastChild = xmlNode->PrevSibling;
  v6 = xmlNode->NextSibling.pObject;
  if ( v6 )
    v6->PrevSibling = xmlNode->PrevSibling;
  PrevSibling = xmlNode->PrevSibling;
  if ( PrevSibling )
  {
    v8 = xmlNode->NextSibling.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = PrevSibling->NextSibling.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    PrevSibling->NextSibling.pObject = xmlNode->NextSibling.pObject;
  }
  xmlNode->Parent = 0i64;
  v10 = xmlNode->NextSibling.pObject;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  xmlNode->NextSibling.pObject = 0i64;
  xmlNode->PrevSibling = 0i64;
  Scaleform::RefCountNTSImpl::Release(xmlNode);
}

// File Line: 236
// RVA: 0x8E2E00
_BOOL8 __fastcall Scaleform::GFx::XML::ElementNode::HasChildren(Scaleform::GFx::XML::ElementNode *this)
{
  return this->FirstChild.pObject != 0i64;
}

// File Line: 307
// RVA: 0x8BC230
void __fastcall Scaleform::GFx::XML::ElementNode::ClearAttributes(Scaleform::GFx::XML::ElementNode *this)
{
  Scaleform::GFx::XML::Attribute *FirstAttribute; // rdi
  Scaleform::GFx::XML::Attribute *Next; // r14
  Scaleform::GFx::XML::DOMStringNode *pNode; // rbx
  bool v5; // zf
  Scaleform::GFx::XML::DOMStringManager *pManager; // rsi
  char *pData; // rdx
  Scaleform::GFx::XML::DOMStringNode *v8; // rbx
  Scaleform::GFx::XML::DOMStringManager *v9; // rsi
  char *v10; // rdx
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::XML::Attribute *v12; // [rsp+68h] [rbp+10h]

  FirstAttribute = this->FirstAttribute;
  if ( FirstAttribute )
  {
    do
    {
      Next = FirstAttribute->Next;
      v12 = FirstAttribute;
      pNode = FirstAttribute->Value.pNode;
      v5 = pNode->RefCount-- == 1;
      if ( v5 )
      {
        key = pNode;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &pNode->pManager->StringSet,
          &key);
        pManager = pNode->pManager;
        pData = (char *)pNode->pData;
        if ( pNode->pData )
        {
          if ( pNode->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)pData = pManager->pFreeTextBuffers;
            pManager->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pData;
          }
          pNode->pData = 0i64;
        }
        pNode->pManager = (Scaleform::GFx::XML::DOMStringManager *)pManager->pFreeStringNodes;
        pManager->pFreeStringNodes = pNode;
      }
      v8 = FirstAttribute->Name.pNode;
      v5 = FirstAttribute->Name.pNode->RefCount-- == 1;
      if ( v5 )
      {
        key = v8;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &v8->pManager->StringSet,
          &key);
        v9 = v8->pManager;
        v10 = (char *)v8->pData;
        if ( v8->pData )
        {
          if ( v8->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v10 = v9->pFreeTextBuffers;
            v9->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v10;
          }
          v8->pData = 0i64;
        }
        v8->pManager = (Scaleform::GFx::XML::DOMStringManager *)v9->pFreeStringNodes;
        v9->pFreeStringNodes = v8;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, FirstAttribute);
      FirstAttribute = Next;
    }
    while ( Next );
    this->FirstAttribute = 0i64;
    this->LastAttribute = 0i64;
  }
  else
  {
    this->FirstAttribute = 0i64;
    this->LastAttribute = 0i64;
  }
}

// File Line: 324
// RVA: 0x8E2DF0
_BOOL8 __fastcall UFG::UIGfxTexture::IsValid(Scaleform::GFx::XML::ElementNode *this)
{
  return this->FirstAttribute != 0i64;
}

// File Line: 337
// RVA: 0x89EBA0
void __fastcall Scaleform::GFx::XML::TextNode::TextNode(
        Scaleform::GFx::XML::TextNode *this,
        Scaleform::GFx::XML::ObjectManager *memMgr,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *v5; // rcx
  const char *pData; // [rsp+58h] [rbp+20h] BYREF

  pData = value.pNode->pData;
  ++*((_DWORD *)pData + 6);
  Scaleform::GFx::XML::Node::Node(this, memMgr, 3, (Scaleform::GFx::XML::DOMString)&pData);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::TextNode::`vftable;
  v5 = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  if ( (*((_DWORD *)value.pNode->pData + 6))-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v5);
}

// File Line: 353
// RVA: 0x8BCD20
Scaleform::GFx::XML::TextNode *__fastcall Scaleform::GFx::XML::TextNode::Clone(
        Scaleform::GFx::XML::TextNode *this,
        bool deep)
{
  Scaleform::GFx::XML::TextNode *result; // rax
  Scaleform::GFx::XML::DOMString value; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::XML::DOMString *p_value; // [rsp+50h] [rbp+18h]

  p_value = &value;
  value.pNode = this->Value.pNode;
  ++value.pNode->RefCount;
  result = Scaleform::GFx::XML::ObjectManager::CreateTextNode(
             this->MemoryManager.pObject,
             (Scaleform::GFx::XML::DOMString)&value);
  result->Type = this->Type;
  return result;
}

// File Line: 370
// RVA: 0x8956A0
void __fastcall Scaleform::GFx::XML::Document::Document(
        Scaleform::GFx::XML::Document *this,
        Scaleform::GFx::XML::ObjectManager *memMgr)
{
  Scaleform::GFx::XML::Node::Node(this, memMgr, 1);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable;
  Scaleform::GFx::XML::ObjectManager::EmptyString(memMgr, &this->Prefix);
  Scaleform::GFx::XML::ObjectManager::EmptyString(memMgr, &this->Namespace);
  this->FirstAttribute = 0i64;
  this->LastAttribute = 0i64;
  this->FirstChild.pObject = 0i64;
  this->LastChild = 0i64;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Document::`vftable;
  Scaleform::GFx::XML::ObjectManager::EmptyString(this->MemoryManager.pObject, &this->XMLVersion);
  Scaleform::GFx::XML::ObjectManager::EmptyString(this->MemoryManager.pObject, &this->Encoding);
  this->Standalone = -1;
}

// File Line: 384
// RVA: 0x8BCBE0
Scaleform::GFx::XML::Node *__fastcall Scaleform::GFx::XML::Document::Clone(
        Scaleform::GFx::XML::Document *this,
        bool deep)
{
  Scaleform::GFx::XML::ObjectManager *pObject; // rbx
  Scaleform::GFx::XML::Document *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *pNode; // rsi
  Scaleform::GFx::XML::DOMStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::XML::DOMStringNode *v11; // rsi
  Scaleform::GFx::XML::DOMStringNode *v12; // rcx

  pObject = this->MemoryManager.pObject;
  v5 = (Scaleform::GFx::XML::Document *)pObject->pHeap->vfptr->Alloc(pObject->pHeap, 144ui64, 0i64);
  if ( v5 )
  {
    Scaleform::GFx::XML::Document::Document(v5, pObject);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  Scaleform::GFx::XML::ElementNode::CloneHelper(this, (Scaleform::GFx::XML::ElementNode *)v7, deep);
  pNode = this->Encoding.pNode;
  ++pNode->RefCount;
  v9 = *(Scaleform::GFx::XML::DOMStringNode **)(v7 + 128);
  v10 = v9->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v9);
  *(_QWORD *)(v7 + 128) = pNode;
  *(_BYTE *)(v7 + 136) = this->Standalone;
  v11 = this->XMLVersion.pNode;
  ++v11->RefCount;
  v12 = *(Scaleform::GFx::XML::DOMStringNode **)(v7 + 120);
  v10 = v12->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v12);
  *(_QWORD *)(v7 + 120) = v11;
  *(_BYTE *)(v7 + 64) = this->Type;
  return (Scaleform::GFx::XML::Node *)v7;
}

