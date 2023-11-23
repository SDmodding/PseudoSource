// File Line: 40
// RVA: 0x8FEA90
void __fastcall Scaleform::GFx::XML::DOMStringNode::ReleaseNode(Scaleform::GFx::XML::DOMStringNode *this)
{
  char *pData; // rdx
  Scaleform::GFx::XML::DOMStringManager *pManager; // rdi
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+30h] [rbp+8h] BYREF

  key = this;
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
    &this->pManager->StringSet,
    &key);
  pData = (char *)this->pData;
  pManager = this->pManager;
  if ( this->pData )
  {
    if ( this->Size >= 0x10 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    else
    {
      *(_QWORD *)pData = pManager->pFreeTextBuffers;
      pManager->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pData;
    }
    this->pData = 0i64;
  }
  this->pManager = (Scaleform::GFx::XML::DOMStringManager *)pManager->pFreeStringNodes;
  pManager->pFreeStringNodes = this;
}

// File Line: 53
// RVA: 0x895400
void __fastcall Scaleform::GFx::XML::DOMString::DOMString(
        Scaleform::GFx::XML::DOMString *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  this->pNode = pnode;
  ++pnode->RefCount;
}

// File Line: 59
// RVA: 0x8953F0
void __fastcall Scaleform::GFx::XML::DOMString::DOMString(
        Scaleform::GFx::XML::DOMString *this,
        Scaleform::GFx::XML::DOMString *src)
{
  Scaleform::GFx::XML::DOMStringNode *pNode; // rax

  pNode = src->pNode;
  this->pNode = src->pNode;
  ++pNode->RefCount;
}

// File Line: 64
// RVA: 0x8A38A0
void __fastcall Scaleform::GFx::XML::DOMString::~DOMString(Scaleform::GFx::XML::DOMString *this)
{
  Scaleform::GFx::XML::DOMStringNode *pNode; // rcx

  pNode = this->pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pNode);
}

// File Line: 69
// RVA: 0x8B6940
void __fastcall Scaleform::GFx::XML::DOMString::AssignNode(
        Scaleform::GFx::XML::DOMString *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMStringNode *v3; // rcx

  ++pnode->RefCount;
  v3 = this->pNode;
  if ( v3->RefCount-- == 1 )
  {
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v3);
    this->pNode = pnode;
  }
  else
  {
    this->pNode = pnode;
  }
}

// File Line: 85
// RVA: 0x895410
void __fastcall Scaleform::GFx::XML::DOMStringManager::DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+48h] [rbp+10h] BYREF

  key = (Scaleform::GFx::XML::DOMStringNode *)this;
  this->StringSet.pTable = 0i64;
  this->pHeap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->pStringNodePages = 0i64;
  this->pFreeStringNodes = 0i64;
  this->pFreeTextBuffers = 0i64;
  this->pTextBufferPages = 0i64;
  this->EmptyStringNode.RefCount = 1;
  this->EmptyStringNode.Size = 0;
  this->EmptyStringNode.HashFlags = Scaleform::String::BernsteinHashFunction(&customCaption, 0i64, 0x1505ui64) & 0xFFFFFF;
  this->EmptyStringNode.pData = &customCaption;
  this->EmptyStringNode.pManager = this;
  key = &this->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
    &this->StringSet,
    this,
    &key,
    this->EmptyStringNode.HashFlags);
}

// File Line: 106
// RVA: 0x8A38B0
void __fastcall Scaleform::GFx::XML::DOMStringManager::~DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *pStringNodePages; // rbp
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v3; // rbx
  __int64 v4; // rsi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pData; // rdx
  Scaleform::GFx::XML::DOMStringManager::TextPage *pTextBufferPages; // rax
  void *pMem; // rdx
  __int64 v8; // rcx
  unsigned __int64 v9; // rdx

  while ( this->pStringNodePages )
  {
    pStringNodePages = this->pStringNodePages;
    this->pStringNodePages = pStringNodePages->pNext;
    v3 = pStringNodePages;
    v4 = 127i64;
    do
    {
      pData = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v3->Nodes[0].pData;
      if ( v3->Nodes[0].pData )
      {
        if ( v3->Nodes[0].Size >= 0x10 )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          pData->pNextAlloc = this->pFreeTextBuffers;
          this->pFreeTextBuffers = pData;
        }
      }
      v3 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)((char *)v3 + 32);
      --v4;
    }
    while ( v4 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pStringNodePages);
  }
  while ( this->pTextBufferPages )
  {
    pTextBufferPages = this->pTextBufferPages;
    pMem = pTextBufferPages->pMem;
    this->pTextBufferPages = pTextBufferPages->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pMem);
  }
  if ( this->StringSet.pTable )
  {
    v8 = 0i64;
    v9 = this->StringSet.pTable->SizeMask + 1;
    do
    {
      if ( this->StringSet.pTable[v8 + 1].EntryCount != -2i64 )
        this->StringSet.pTable[v8 + 1].EntryCount = -2i64;
      ++v8;
      --v9;
    }
    while ( v9 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->StringSet.pTable);
    this->StringSet.pTable = 0i64;
  }
}

// File Line: 140
// RVA: 0x8B5EB0
void __fastcall Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v2; // rax
  __int64 v3; // rdx

  v2 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)this->pHeap->vfptr->Alloc(this->pHeap, 4072i64, 0i64);
  if ( v2 )
  {
    v2->pNext = this->pStringNodePages;
    this->pStringNodePages = v2;
    v3 = 127i64;
    do
    {
      v2->Nodes[0].pData = 0i64;
      v2->Nodes[0].pManager = (Scaleform::GFx::XML::DOMStringManager *)this->pFreeStringNodes;
      this->pFreeStringNodes = (Scaleform::GFx::XML::DOMStringNode *)v2;
      v2 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)((char *)v2 + 32);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 166
// RVA: 0x8B5FA0
void __fastcall Scaleform::GFx::XML::DOMStringManager::AllocateTextBuffers(Scaleform::GFx::XML::DOMStringManager *this)
{
  void *v2; // rax
  Scaleform::GFx::XML::DOMStringManager::TextPage *v3; // rcx
  __int64 v4; // r8
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v5; // rax
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v6; // rdx
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v7; // rcx

  v2 = this->pHeap->vfptr->Alloc(this->pHeap, 2040i64, 0i64);
  v3 = (Scaleform::GFx::XML::DOMStringManager::TextPage *)(((unsigned __int64)v2 + 7) & 0xFFFFFFFFFFFFFFF8ui64);
  if ( v3 )
  {
    v3->pMem = v2;
    v4 = 21i64;
    v3->pNext = this->pTextBufferPages;
    this->pTextBufferPages = v3;
    v5 = &v3->Entries[2];
    do
    {
      v5[-2].pNextAlloc = this->pFreeTextBuffers;
      v5[-1].pNextAlloc = v5 - 2;
      v5->pNextAlloc = v5 - 1;
      v5[1].pNextAlloc = v5;
      v6 = v5 + 2;
      v5[2].pNextAlloc = v5 + 1;
      v7 = v5 + 3;
      v5 += 6;
      v7->pNextAlloc = v6;
      this->pFreeTextBuffers = v7;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 216
// RVA: 0x8B5DB0
Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *__fastcall Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(
        Scaleform::GFx::XML::DOMStringManager *this,
        const char *pbuffer,
        size_t length)
{
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pFreeTextBuffers; // rax
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v7; // rbx

  if ( length >= 0x10 )
  {
    v7 = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)this->pHeap->vfptr->Alloc(
                                                                     this->pHeap,
                                                                     length + 1,
                                                                     0i64);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::XML::DOMStringManager::AllocateTextBuffers(this);
    pFreeTextBuffers = this->pFreeTextBuffers;
    v7 = 0i64;
    if ( pFreeTextBuffers )
    {
      v7 = this->pFreeTextBuffers;
      this->pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
    }
  }
  if ( v7 )
  {
    memmove(v7, pbuffer, length);
    v7->Buff[length] = 0;
  }
  return v7;
}

// File Line: 255
// RVA: 0x8C3EA0
Scaleform::GFx::XML::DOMStringNode *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
        Scaleform::GFx::XML::DOMStringManager *this,
        const char *pstr,
        unsigned __int64 length)
{
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > >::TableType *pTable; // r8
  unsigned __int64 v8; // rbp
  signed __int64 v9; // rax
  Scaleform::GFx::XML::DOMStringNode *pFreeStringNodes; // rdi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v12; // rax
  Scaleform::GFx::XML::DOMStringKey key; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::XML::DOMStringNode *v14; // [rsp+60h] [rbp+8h] BYREF

  key.pStr = pstr;
  v6 = Scaleform::String::BernsteinHashFunction(pstr, length, 0x1505ui64);
  pTable = this->StringSet.pTable;
  key.Length = length;
  v8 = v6 & 0xFFFFFF;
  key.HashValue = v8;
  if ( pTable )
  {
    v9 = Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::findIndexCore<Scaleform::GFx::XML::DOMStringKey>(
           &this->StringSet,
           &key,
           v8 & pTable->SizeMask);
    if ( v9 >= 0 )
      return (Scaleform::GFx::XML::DOMStringNode *)this->StringSet.pTable[v9 + 1].SizeMask;
  }
  if ( !length )
    return &this->EmptyStringNode;
  if ( !this->pFreeStringNodes )
    Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(this);
  pFreeStringNodes = this->pFreeStringNodes;
  if ( pFreeStringNodes )
    this->pFreeStringNodes = pFreeStringNodes->pNextAlloc;
  pFreeStringNodes->pManager = this;
  v14 = pFreeStringNodes;
  v12 = Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(this, pstr, length);
  pFreeStringNodes->pData = (const char *)v12;
  if ( v12 )
  {
    pFreeStringNodes->RefCount = 0;
    pFreeStringNodes->Size = length;
    pFreeStringNodes->HashFlags = v8;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
      &this->StringSet,
      this,
      &v14,
      (unsigned int)v8);
    return pFreeStringNodes;
  }
  else
  {
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(this, pFreeStringNodes);
    return &this->EmptyStringNode;
  }
}

// File Line: 343
// RVA: 0x89C040
void __fastcall Scaleform::GFx::XML::ObjectManager::ObjectManager(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::MovieImpl *powner)
{
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::`vftable;
  this->Scaleform::GFx::ExternalLibPtr::vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable;
  this->pOwner = powner;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>};
  this->Scaleform::GFx::ExternalLibPtr::vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable{for `Scaleform::GFx::ExternalLibPtr};
  Scaleform::GFx::XML::DOMStringManager::DOMStringManager(&this->StringPool);
  this->pHeap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
}

// File Line: 363
// RVA: 0x8BF350
void __fastcall Scaleform::GFx::XML::ObjectManager::CreateDocument(Scaleform::GFx::XML::ObjectManager *this)
{
  Scaleform::GFx::XML::Document *v2; // rax

  v2 = (Scaleform::GFx::XML::Document *)this->pHeap->vfptr->Alloc(this->pHeap, 144i64, 0i64);
  if ( v2 )
    Scaleform::GFx::XML::Document::Document(v2, this);
}

// File Line: 367
// RVA: 0x8BF640
Scaleform::GFx::XML::ElementNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateElementNode(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::ElementNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::XML::DOMStringNode *pData; // rcx
  Scaleform::GFx::XML::DOMString valuea; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::GFx::XML::ElementNode *v11; // [rsp+68h] [rbp+20h]

  v4 = (Scaleform::GFx::XML::ElementNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                             this->pHeap,
                                             120i64);
  v11 = v4;
  if ( v4 )
  {
    valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
    ++valuea.pNode->RefCount;
    Scaleform::GFx::XML::ElementNode::ElementNode(v4, this, (Scaleform::GFx::XML::DOMString)&valuea);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pData = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  if ( (*((_DWORD *)value.pNode->pData + 6))-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pData);
  return (Scaleform::GFx::XML::ElementNode *)v6;
}

// File Line: 371
// RVA: 0x8C4070
Scaleform::GFx::XML::TextNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateTextNode(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::TextNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::XML::DOMStringNode *pData; // rcx
  Scaleform::GFx::XML::DOMString valuea; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::GFx::XML::TextNode *v11; // [rsp+68h] [rbp+20h]

  v4 = (Scaleform::GFx::XML::TextNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                          this->pHeap,
                                          72i64);
  v11 = v4;
  if ( v4 )
  {
    valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
    ++valuea.pNode->RefCount;
    Scaleform::GFx::XML::TextNode::TextNode(v4, this, (Scaleform::GFx::XML::DOMString)&valuea);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pData = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  if ( (*((_DWORD *)value.pNode->pData + 6))-- == 1 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pData);
  return (Scaleform::GFx::XML::TextNode *)v6;
}

// File Line: 375
// RVA: 0x8BE800
Scaleform::GFx::XML::Attribute *__fastcall Scaleform::GFx::XML::ObjectManager::CreateAttribute(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString name,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::Attribute *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *pData; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString namea; // [rsp+20h] [rbp-48h] BYREF
  __int64 v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::XML::Attribute *v14; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::XML::DOMString *p_valuea; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::XML::DOMString *p_namea; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::XML::DOMString valuea; // [rsp+88h] [rbp+20h] BYREF

  v13 = -2i64;
  v5 = (Scaleform::GFx::XML::Attribute *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                           this->pHeap,
                                           24i64);
  v14 = v5;
  if ( v5 )
  {
    p_valuea = &valuea;
    p_namea = &namea;
    valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
    ++valuea.pNode->RefCount;
    namea.pNode = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
    ++namea.pNode->RefCount;
    Scaleform::GFx::XML::Attribute::Attribute(
      v5,
      (Scaleform::GFx::XML::DOMString)&namea,
      (Scaleform::GFx::XML::DOMString)&valuea);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  pData = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  v9 = (*((_DWORD *)name.pNode->pData + 6))-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pData);
  v10 = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  v9 = (*((_DWORD *)value.pNode->pData + 6))-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  return (Scaleform::GFx::XML::Attribute *)v7;
}

// File Line: 379
// RVA: 0x8C2860
Scaleform::GFx::XML::Prefix *__fastcall Scaleform::GFx::XML::ObjectManager::CreatePrefix(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString name,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::Prefix *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *pData; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString namea; // [rsp+20h] [rbp-48h] BYREF
  __int64 v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::XML::Prefix *v14; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::XML::DOMString *p_valuea; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::XML::DOMString *p_namea; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::XML::DOMString valuea; // [rsp+88h] [rbp+20h] BYREF

  v13 = -2i64;
  v5 = (Scaleform::GFx::XML::Prefix *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                        this->pHeap,
                                        32i64);
  v14 = v5;
  if ( v5 )
  {
    p_valuea = &valuea;
    p_namea = &namea;
    valuea.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
    ++valuea.pNode->RefCount;
    namea.pNode = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
    ++namea.pNode->RefCount;
    Scaleform::GFx::XML::Prefix::Prefix(
      v5,
      (Scaleform::GFx::XML::DOMString)&namea,
      (Scaleform::GFx::XML::DOMString)&valuea);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  pData = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  v9 = (*((_DWORD *)name.pNode->pData + 6))-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(pData);
  v10 = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  v9 = (*((_DWORD *)value.pNode->pData + 6))-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  return (Scaleform::GFx::XML::Prefix *)v7;
}

// File Line: 383
// RVA: 0x8C3640
Scaleform::GFx::XML::RootNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateRootNode(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::Node *pdom)
{
  Scaleform::GFx::XML::RootNode *result; // rax

  result = (Scaleform::GFx::XML::RootNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                              this->pHeap,
                                              24i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  result->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  result->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::RootNode,326>::`vftable;
  result->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::RootNode::`vftable;
  if ( pdom )
    ++pdom->RefCount;
  result->pDOMTree.pObject = pdom;
  return result;
}

