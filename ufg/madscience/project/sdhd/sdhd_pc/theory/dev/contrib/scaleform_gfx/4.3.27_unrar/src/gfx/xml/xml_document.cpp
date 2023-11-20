// File Line: 35
// RVA: 0x89BD60
void __fastcall Scaleform::GFx::XML::Node::Node(Scaleform::GFx::XML::Node *this, Scaleform::GFx::XML::ObjectManager *memMgr, char type)
{
  char v3; // di
  Scaleform::GFx::XML::Node *v4; // rbx

  v3 = type;
  v4 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::Node,326>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  Scaleform::GFx::XML::ObjectManager::EmptyString(this->MemoryManager.pObject, &this->Value);
  v4->Parent = 0i64;
  v4->PrevSibling = 0i64;
  v4->NextSibling.pObject = 0i64;
  v4->pShadow = 0i64;
  v4->Type = v3;
}

// File Line: 40
// RVA: 0x89BE00
void __fastcall Scaleform::GFx::XML::Node::Node(Scaleform::GFx::XML::Node *this, Scaleform::GFx::XML::ObjectManager *memMgr, char type, Scaleform::GFx::XML::DOMString value)
{
  const char *v4; // rax
  Scaleform::GFx::XML::DOMStringNode *v5; // rcx
  bool v6; // zf

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::Node,326>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( memMgr )
    ++memMgr->RefCount;
  this->MemoryManager.pObject = memMgr;
  v4 = value.pNode->pData;
  this->Value.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++*((_DWORD *)v4 + 6);
  this->Parent = 0i64;
  this->PrevSibling = 0i64;
  this->NextSibling.pObject = 0i64;
  this->pShadow = 0i64;
  this->Type = type;
  v5 = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  v6 = *((_DWORD *)value.pNode->pData + 6) == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v5);
}

// File Line: 46
// RVA: 0x8A6FB0
void __fastcall Scaleform::GFx::XML::Node::~Node(Scaleform::GFx::XML::Node *this)
{
  Scaleform::GFx::XML::Node *v1; // rbx
  Scaleform::GFx::XML::ShadowRefBase *v2; // rcx
  Scaleform::RefCountNTSImpl *v3; // rcx
  Scaleform::GFx::XML::DOMStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::RefCountNTSImpl *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Node::`vftable';
  v2 = this->pShadow;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = (Scaleform::RefCountNTSImpl *)&v1->NextSibling.pObject->vfptr;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  v4 = v1->Value.pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v4);
  v6 = (Scaleform::RefCountNTSImpl *)&v1->MemoryManager.pObject->vfptr;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->vfptr);
}

// File Line: 69
// RVA: 0x896180
void __fastcall Scaleform::GFx::XML::ElementNode::ElementNode(Scaleform::GFx::XML::ElementNode *this, Scaleform::GFx::XML::ObjectManager *memMgr, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *v3; // rdi
  Scaleform::GFx::XML::ObjectManager *v4; // rbx
  Scaleform::GFx::XML::ElementNode *v5; // rsi
  Scaleform::GFx::XML::DOMStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::XML::DOMString valuea; // [rsp+68h] [rbp+20h]

  v3 = value.pNode;
  v4 = memMgr;
  v5 = this;
  valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++valuea.pNode->RefCount;
  Scaleform::GFx::XML::Node::Node(
    (Scaleform::GFx::XML::Node *)&this->vfptr,
    memMgr,
    1,
    (Scaleform::GFx::XML::DOMString)&valuea);
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  Scaleform::GFx::XML::ObjectManager::EmptyString(v4, &v5->Prefix);
  Scaleform::GFx::XML::ObjectManager::EmptyString(v4, &v5->Namespace);
  v5->FirstAttribute = 0i64;
  v5->LastAttribute = 0i64;
  v5->FirstChild.pObject = 0i64;
  v5->LastChild = 0i64;
  v6 = (Scaleform::GFx::XML::DOMStringNode *)v3->pData;
  v7 = *((_DWORD *)v3->pData + 6) == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v6);
}

// File Line: 75
// RVA: 0x8A4350
void __fastcall Scaleform::GFx::XML::ElementNode::~ElementNode(Scaleform::GFx::XML::ElementNode *this)
{
  Scaleform::GFx::XML::ElementNode *v1; // r14
  Scaleform::GFx::XML::Node *i; // rbx
  Scaleform::RefCountNTSImpl *v3; // rcx
  Scaleform::RefCountNTSImpl *v4; // rcx
  Scaleform::GFx::XML::Attribute *v5; // rdi
  Scaleform::GFx::XML::Attribute *v6; // rbp
  Scaleform::GFx::XML::DOMStringNode *v7; // rbx
  bool v8; // zf
  Scaleform::GFx::XML::DOMStringManager *v9; // rsi
  char *v10; // rdx
  Scaleform::GFx::XML::DOMStringNode *v11; // rbx
  Scaleform::GFx::XML::DOMStringManager *v12; // rsi
  char *v13; // rdx
  Scaleform::RefCountNTSImpl *v14; // rcx
  Scaleform::GFx::XML::DOMStringNode *v15; // rcx
  Scaleform::GFx::XML::DOMStringNode *v16; // rcx
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::XML::Attribute *v18; // [rsp+70h] [rbp+18h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  for ( i = this->LastChild; i; i->NextSibling.pObject = 0i64 )
  {
    i->Parent = 0i64;
    i = i->PrevSibling;
    if ( !i )
      break;
    v3 = (Scaleform::RefCountNTSImpl *)&i->NextSibling.pObject->vfptr;
    if ( v3 )
      Scaleform::RefCountNTSImpl::Release(v3);
  }
  if ( v1->FirstChild.pObject )
  {
    v4 = (Scaleform::RefCountNTSImpl *)&v1->FirstChild.pObject->vfptr;
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    v1->FirstChild.pObject = 0i64;
  }
  v5 = v1->FirstAttribute;
  if ( v5 )
  {
    do
    {
      v6 = v5->Next;
      v18 = v5;
      v7 = v5->Value.pNode;
      v8 = v7->RefCount-- == 1;
      if ( v8 )
      {
        key = v7;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v7->pManager->StringSet.pTable,
          &key);
        v9 = v7->pManager;
        v10 = (char *)v7->pData;
        if ( v7->pData )
        {
          if ( v7->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v10 = v9->pFreeTextBuffers;
            v9->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v10;
          }
          v7->pData = 0i64;
        }
        v7->pManager = (Scaleform::GFx::XML::DOMStringManager *)v9->pFreeStringNodes;
        v9->pFreeStringNodes = v7;
      }
      v11 = v5->Name.pNode;
      v8 = v5->Name.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v8 )
      {
        key = v11;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v11->pManager->StringSet.pTable,
          &key);
        v12 = v11->pManager;
        v13 = (char *)v11->pData;
        if ( v11->pData )
        {
          if ( v11->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      v5 = v6;
    }
    while ( v6 );
  }
  v14 = (Scaleform::RefCountNTSImpl *)&v1->FirstChild.pObject->vfptr;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  v15 = v1->Namespace.pNode;
  v8 = v15->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v15);
  v16 = v1->Prefix.pNode;
  v8 = v16->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v16);
  Scaleform::GFx::XML::Node::~Node((Scaleform::GFx::XML::Node *)&v1->vfptr);
}

// File Line: 110
// RVA: 0x8BCCB0
Scaleform::GFx::XML::ElementNode *__fastcall Scaleform::GFx::XML::ElementNode::Clone(Scaleform::GFx::XML::ElementNode *this, bool deep)
{
  bool v2; // di
  Scaleform::GFx::XML::ElementNode *v3; // rsi
  Scaleform::GFx::XML::ElementNode *v4; // rbx
  Scaleform::GFx::XML::DOMString value; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::XML::DOMString *v7; // [rsp+50h] [rbp+18h]

  v2 = deep;
  v3 = this;
  v7 = &value;
  value.pNode = this->Value.pNode;
  ++value.pNode->RefCount;
  v4 = Scaleform::GFx::XML::ObjectManager::CreateElementNode(
         this->MemoryManager.pObject,
         (Scaleform::GFx::XML::DOMString)&value);
  Scaleform::GFx::XML::ElementNode::CloneHelper(v3, v4, v2);
  v4->Type = v3->Type;
  return v4;
}

// File Line: 122
// RVA: 0x8BCFA0
void __fastcall Scaleform::GFx::XML::ElementNode::CloneHelper(Scaleform::GFx::XML::ElementNode *this, Scaleform::GFx::XML::ElementNode *clone, bool deep)
{
  bool v3; // bp
  Scaleform::GFx::XML::ElementNode *v4; // rdi
  Scaleform::GFx::XML::ElementNode *v5; // rsi
  Scaleform::GFx::XML::DOMStringNode *v6; // rbx
  Scaleform::GFx::XML::DOMStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::XML::Attribute *v9; // rbx
  Scaleform::GFx::XML::Attribute *v10; // rax
  Scaleform::GFx::XML::Node *i; // rsi
  Scaleform::GFx::XML::DOMStringNode *v12; // rax
  Scaleform::GFx::XML::Node *v13; // rbx
  Scaleform::GFx::XML::Node *v14; // rax
  Scaleform::RefCountNTSImpl *v15; // rcx
  Scaleform::GFx::XML::Node *v16; // r14
  Scaleform::RefCountNTSImpl *v17; // rcx
  Scaleform::GFx::XML::DOMString value; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::XML::DOMString name; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::XML::DOMString *v20; // [rsp+78h] [rbp+20h]

  v3 = deep;
  v4 = clone;
  v5 = this;
  v6 = this->Prefix.pNode;
  ++v6->RefCount;
  v7 = clone->Prefix.pNode;
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v7);
  v4->Prefix.pNode = v6;
  v9 = v5->FirstAttribute;
  if ( v9 )
  {
    v20 = &value;
    do
    {
      value.pNode = v9->Value.pNode;
      ++value.pNode->RefCount;
      name.pNode = v9->Name.pNode;
      ++name.pNode->RefCount;
      v10 = Scaleform::GFx::XML::ObjectManager::CreateAttribute(
              v5->MemoryManager.pObject,
              (Scaleform::GFx::XML::DOMString)&name,
              (Scaleform::GFx::XML::DOMString)&value);
      if ( v4->FirstAttribute )
        v4->LastAttribute->Next = v10;
      else
        v4->FirstAttribute = v10;
      v4->LastAttribute = v10;
      v9 = v9->Next;
    }
    while ( v9 );
  }
  if ( v3 )
  {
    for ( i = v5->FirstChild.pObject; i; i = i->NextSibling.pObject )
    {
      v12 = (Scaleform::GFx::XML::DOMStringNode *)i->vfptr[1].__vecDelDtor(
                                                    (Scaleform::RefCountNTSImplCore *)&i->vfptr,
                                                    v3);
      v13 = (Scaleform::GFx::XML::Node *)v12;
      value.pNode = v12;
      v14 = v4->LastChild;
      if ( v14 )
      {
        v13->PrevSibling = v14;
        v16 = v4->LastChild;
        ++v13->RefCount;
        v17 = (Scaleform::RefCountNTSImpl *)&v16->NextSibling.pObject->vfptr;
        if ( v17 )
          Scaleform::RefCountNTSImpl::Release(v17);
        v16->NextSibling.pObject = v13;
      }
      else
      {
        if ( v13 )
          ++v13->RefCount;
        v15 = (Scaleform::RefCountNTSImpl *)&v4->FirstChild.pObject->vfptr;
        if ( v15 )
          Scaleform::RefCountNTSImpl::Release(v15);
        v4->FirstChild.pObject = v13;
      }
      v4->LastChild = v13;
      v13->Parent = v4;
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
    }
  }
}

// File Line: 149
// RVA: 0x8B6420
void __fastcall Scaleform::GFx::XML::ElementNode::AppendChild(Scaleform::GFx::XML::ElementNode *this, Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *v2; // rax
  Scaleform::GFx::XML::Node *v3; // rbx
  Scaleform::GFx::XML::ElementNode *v4; // rdi
  Scaleform::GFx::XML::Node *v5; // rcx
  Scaleform::GFx::XML::Node *v6; // rsi
  Scaleform::RefCountNTSImpl *v7; // rcx

  v2 = this->LastChild;
  v3 = xmlNode;
  v4 = this;
  if ( v2 )
  {
    xmlNode->PrevSibling = v2;
    v6 = this->LastChild;
    ++xmlNode->RefCount;
    v7 = (Scaleform::RefCountNTSImpl *)&v6->NextSibling.pObject->vfptr;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    v6->NextSibling.pObject = v3;
    v4->LastChild = v3;
    v3->Parent = v4;
  }
  else
  {
    if ( xmlNode )
      ++xmlNode->RefCount;
    v5 = this->FirstChild.pObject;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
    v4->FirstChild.pObject = v3;
    v4->LastChild = v3;
    v3->Parent = v4;
  }
}

// File Line: 179
// RVA: 0x8E6270
void __fastcall Scaleform::GFx::XML::ElementNode::InsertBefore(Scaleform::GFx::XML::ElementNode *this, Scaleform::GFx::XML::Node *child, Scaleform::GFx::XML::Node *insert)
{
  Scaleform::GFx::XML::Node *v3; // rbp
  Scaleform::GFx::XML::ElementNode *v4; // rdi
  Scaleform::GFx::XML::Node *v5; // rcx
  Scaleform::GFx::XML::Node *v6; // rsi
  Scaleform::GFx::XML::Node *v7; // rbx
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::RefCountNTSImpl *v9; // rcx

  v3 = insert->PrevSibling;
  insert->PrevSibling = child;
  v4 = this;
  child->PrevSibling = v3;
  ++insert->RefCount;
  v5 = child->NextSibling.pObject;
  v6 = insert;
  v7 = child;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
  v7->NextSibling.pObject = v6;
  if ( v3 )
  {
    ++v7->RefCount;
    v8 = (Scaleform::RefCountNTSImpl *)&v3->NextSibling.pObject->vfptr;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    v3->NextSibling.pObject = v7;
  }
  if ( v6 == v4->FirstChild.pObject )
  {
    ++v7->RefCount;
    v9 = (Scaleform::RefCountNTSImpl *)&v4->FirstChild.pObject->vfptr;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v4->FirstChild.pObject = v7;
  }
  v7->Parent = v4;
}

// File Line: 208
// RVA: 0x8FF010
void __fastcall Scaleform::GFx::XML::ElementNode::RemoveChild(Scaleform::GFx::XML::ElementNode *this, Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *v2; // rbx
  Scaleform::GFx::XML::ElementNode *v3; // rdi
  Scaleform::GFx::XML::Node *v4; // rax
  Scaleform::GFx::XML::Node *v5; // rcx
  Scaleform::GFx::XML::Node *v6; // rcx
  Scaleform::GFx::XML::Node *v7; // rdi
  Scaleform::GFx::XML::Node *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // rcx
  Scaleform::RefCountNTSImpl *v10; // rcx

  v2 = xmlNode;
  v3 = this;
  if ( xmlNode )
    ++xmlNode->RefCount;
  if ( xmlNode == this->FirstChild.pObject )
  {
    v4 = xmlNode->NextSibling.pObject;
    if ( v4 )
      ++v4->RefCount;
    v5 = this->FirstChild.pObject;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
    v3->FirstChild.pObject = v2->NextSibling.pObject;
  }
  if ( v2 == v3->LastChild )
    v3->LastChild = v2->PrevSibling;
  v6 = v2->NextSibling.pObject;
  if ( v6 )
    v6->PrevSibling = v2->PrevSibling;
  v7 = v2->PrevSibling;
  if ( v7 )
  {
    v8 = v2->NextSibling.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = (Scaleform::RefCountNTSImpl *)&v7->NextSibling.pObject->vfptr;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v7->NextSibling.pObject = v2->NextSibling.pObject;
  }
  v2->Parent = 0i64;
  v10 = (Scaleform::RefCountNTSImpl *)&v2->NextSibling.pObject->vfptr;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v2->NextSibling.pObject = 0i64;
  v2->PrevSibling = 0i64;
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
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
  Scaleform::GFx::XML::ElementNode *v1; // r15
  Scaleform::GFx::XML::Attribute *v2; // rdi
  Scaleform::GFx::XML::Attribute *v3; // r14
  Scaleform::GFx::XML::DOMStringNode *v4; // rbx
  bool v5; // zf
  Scaleform::GFx::XML::DOMStringManager *v6; // rsi
  char *v7; // rdx
  Scaleform::GFx::XML::DOMStringNode *v8; // rbx
  Scaleform::GFx::XML::DOMStringManager *v9; // rsi
  char *v10; // rdx
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::XML::Attribute *v12; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = this->FirstAttribute;
  if ( v2 )
  {
    do
    {
      v3 = v2->Next;
      v12 = v2;
      v4 = v2->Value.pNode;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
      {
        key = v4;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v4->pManager->StringSet.pTable,
          &key);
        v6 = v4->pManager;
        v7 = (char *)v4->pData;
        if ( v4->pData )
        {
          if ( v4->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v7 = v6->pFreeTextBuffers;
            v6->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v7;
          }
          v4->pData = 0i64;
        }
        v4->pManager = (Scaleform::GFx::XML::DOMStringManager *)v6->pFreeStringNodes;
        v6->pFreeStringNodes = v4;
      }
      v8 = v2->Name.pNode;
      v5 = v2->Name.pNode->RefCount == 1;
      --v8->RefCount;
      if ( v5 )
      {
        key = v8;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v8->pManager->StringSet.pTable,
          &key);
        v9 = v8->pManager;
        v10 = (char *)v8->pData;
        if ( v8->pData )
        {
          if ( v8->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
      v2 = v3;
    }
    while ( v3 );
    v1->FirstAttribute = 0i64;
    v1->LastAttribute = 0i64;
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
void __fastcall Scaleform::GFx::XML::TextNode::TextNode(Scaleform::GFx::XML::TextNode *this, Scaleform::GFx::XML::ObjectManager *memMgr, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *v3; // rbx
  Scaleform::GFx::XML::TextNode *v4; // rdi
  Scaleform::GFx::XML::DOMStringNode *v5; // rcx
  bool v6; // zf
  const char *v7; // [rsp+58h] [rbp+20h]

  v3 = value.pNode;
  v4 = this;
  v7 = value.pNode->pData;
  ++*((_DWORD *)v7 + 6);
  Scaleform::GFx::XML::Node::Node(
    (Scaleform::GFx::XML::Node *)&this->vfptr,
    memMgr,
    3,
    (Scaleform::GFx::XML::DOMString)&v7);
  v4->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::TextNode::`vftable';
  v5 = (Scaleform::GFx::XML::DOMStringNode *)v3->pData;
  v6 = *((_DWORD *)v3->pData + 6) == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v5);
}

// File Line: 353
// RVA: 0x8BCD20
Scaleform::GFx::XML::TextNode *__fastcall Scaleform::GFx::XML::TextNode::Clone(Scaleform::GFx::XML::TextNode *this, bool deep)
{
  Scaleform::GFx::XML::TextNode *v2; // rbx
  Scaleform::GFx::XML::TextNode *result; // rax
  Scaleform::GFx::XML::DOMString value; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::XML::DOMString *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v5 = &value;
  value.pNode = this->Value.pNode;
  ++value.pNode->RefCount;
  result = Scaleform::GFx::XML::ObjectManager::CreateTextNode(
             this->MemoryManager.pObject,
             (Scaleform::GFx::XML::DOMString)&value);
  result->Type = v2->Type;
  return result;
}

// File Line: 370
// RVA: 0x8956A0
void __fastcall Scaleform::GFx::XML::Document::Document(Scaleform::GFx::XML::Document *this, Scaleform::GFx::XML::ObjectManager *memMgr)
{
  Scaleform::GFx::XML::ObjectManager *v2; // rbx
  Scaleform::GFx::XML::Document *v3; // rdi

  v2 = memMgr;
  v3 = this;
  Scaleform::GFx::XML::Node::Node((Scaleform::GFx::XML::Node *)&this->vfptr, memMgr, 1);
  v3->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  Scaleform::GFx::XML::ObjectManager::EmptyString(v2, &v3->Prefix);
  Scaleform::GFx::XML::ObjectManager::EmptyString(v2, &v3->Namespace);
  v3->FirstAttribute = 0i64;
  v3->LastAttribute = 0i64;
  v3->FirstChild.pObject = 0i64;
  v3->LastChild = 0i64;
  v3->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Document::`vftable';
  Scaleform::GFx::XML::ObjectManager::EmptyString(v3->MemoryManager.pObject, &v3->XMLVersion);
  Scaleform::GFx::XML::ObjectManager::EmptyString(v3->MemoryManager.pObject, &v3->Encoding);
  v3->Standalone = -1;
}

// File Line: 384
// RVA: 0x8BCBE0
Scaleform::GFx::XML::Node *__fastcall Scaleform::GFx::XML::Document::Clone(Scaleform::GFx::XML::Document *this, bool deep)
{
  bool v2; // si
  Scaleform::GFx::XML::Document *v3; // rdi
  Scaleform::GFx::XML::ObjectManager *v4; // rbx
  Scaleform::GFx::XML::Document *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *v8; // rsi
  Scaleform::GFx::XML::DOMStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::XML::DOMStringNode *v11; // rsi
  Scaleform::GFx::XML::DOMStringNode *v12; // rcx

  v2 = deep;
  v3 = this;
  v4 = this->MemoryManager.pObject;
  v5 = (Scaleform::GFx::XML::Document *)v4->pHeap->vfptr->Alloc(v4->pHeap, 144ui64, 0i64);
  if ( v5 )
  {
    Scaleform::GFx::XML::Document::Document(v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  Scaleform::GFx::XML::ElementNode::CloneHelper(
    (Scaleform::GFx::XML::ElementNode *)&v3->vfptr,
    (Scaleform::GFx::XML::ElementNode *)v7,
    v2);
  v8 = v3->Encoding.pNode;
  ++v8->RefCount;
  v9 = *(Scaleform::GFx::XML::DOMStringNode **)(v7 + 128);
  v10 = v9->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v9);
  *(_QWORD *)(v7 + 128) = v8;
  *(_BYTE *)(v7 + 136) = v3->Standalone;
  v11 = v3->XMLVersion.pNode;
  ++v11->RefCount;
  v12 = *(Scaleform::GFx::XML::DOMStringNode **)(v7 + 120);
  v10 = v12->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v12);
  *(_QWORD *)(v7 + 120) = v11;
  *(_BYTE *)(v7 + 64) = v3->Type;
  return (Scaleform::GFx::XML::Node *)v7;
}

