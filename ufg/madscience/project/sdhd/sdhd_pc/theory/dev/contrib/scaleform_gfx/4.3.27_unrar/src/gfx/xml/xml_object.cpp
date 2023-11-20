// File Line: 40
// RVA: 0x8FEA90
void __fastcall Scaleform::GFx::XML::DOMStringNode::ReleaseNode(Scaleform::GFx::XML::DOMStringNode *this)
{
  Scaleform::GFx::XML::DOMStringNode *v1; // rbx
  char *v2; // rdx
  Scaleform::GFx::XML::DOMStringManager *v3; // rdi
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+30h] [rbp+8h]

  v1 = this;
  key = this;
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
    (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&this->pManager->StringSet.pTable,
    &key);
  v2 = (char *)v1->pData;
  v3 = v1->pManager;
  if ( v1->pData )
  {
    if ( v1->Size >= 0x10 )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    else
    {
      *(_QWORD *)v2 = v3->pFreeTextBuffers;
      v3->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v2;
    }
    v1->pData = 0i64;
  }
  v1->pManager = (Scaleform::GFx::XML::DOMStringManager *)v3->pFreeStringNodes;
  v3->pFreeStringNodes = v1;
}

// File Line: 53
// RVA: 0x895400
void __fastcall Scaleform::GFx::XML::DOMString::DOMString(Scaleform::GFx::XML::DOMString *this, Scaleform::GFx::XML::DOMStringNode *pnode)
{
  this->pNode = pnode;
  ++pnode->RefCount;
}

// File Line: 59
// RVA: 0x8953F0
void __fastcall Scaleform::GFx::XML::DOMString::DOMString(Scaleform::GFx::XML::DOMString *this, Scaleform::GFx::XML::DOMString *src)
{
  Scaleform::GFx::XML::DOMStringNode *v2; // rax

  v2 = src->pNode;
  this->pNode = src->pNode;
  ++v2->RefCount;
}

// File Line: 64
// RVA: 0x8A38A0
void __fastcall Scaleform::GFx::XML::DOMString::~DOMString(Scaleform::GFx::XML::DOMString *this)
{
  Scaleform::GFx::XML::DOMStringNode *v1; // rcx
  bool v2; // zf

  v1 = this->pNode;
  v2 = v1->RefCount-- == 1;
  JUMPOUT(v2, Scaleform::GFx::XML::DOMStringNode::ReleaseNode);
}

// File Line: 69
// RVA: 0x8B6940
void __fastcall Scaleform::GFx::XML::DOMString::AssignNode(Scaleform::GFx::XML::DOMString *this, Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMString *v2; // rdi
  Scaleform::GFx::XML::DOMStringNode *v3; // rcx
  bool v4; // zf
  Scaleform::GFx::XML::DOMStringNode *v5; // rbx

  ++pnode->RefCount;
  v2 = this;
  v3 = this->pNode;
  v4 = v3->RefCount-- == 1;
  v5 = pnode;
  if ( v4 )
  {
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v3);
    v2->pNode = v5;
  }
  else
  {
    v2->pNode = pnode;
  }
}

// File Line: 85
// RVA: 0x895410
void __fastcall Scaleform::GFx::XML::DOMStringManager::DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager *v1; // rbx
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+48h] [rbp+10h]

  v1 = this;
  key = (Scaleform::GFx::XML::DOMStringNode *)this;
  this->StringSet.pTable = 0i64;
  this->pHeap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v1->pStringNodePages = 0i64;
  v1->pFreeStringNodes = 0i64;
  v1->pFreeTextBuffers = 0i64;
  v1->pTextBufferPages = 0i64;
  v1->EmptyStringNode.RefCount = 1;
  v1->EmptyStringNode.Size = 0;
  v1->EmptyStringNode.HashFlags = Scaleform::String::BernsteinHashFunction(&customWorldMapCaption, 0i64, 0x1505ui64) & 0xFFFFFF;
  v1->EmptyStringNode.pData = &customWorldMapCaption;
  v1->EmptyStringNode.pManager = v1;
  key = &v1->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
    (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v1->StringSet.pTable,
    v1,
    &key,
    v1->EmptyStringNode.HashFlags);
}

// File Line: 106
// RVA: 0x8A38B0
void __fastcall Scaleform::GFx::XML::DOMStringManager::~DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager *v1; // rdi
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v2; // rbp
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v3; // rbx
  signed __int64 v4; // rsi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v5; // rdx
  Scaleform::GFx::XML::DOMStringManager::TextPage *v6; // rax
  void *v7; // rdx
  __int64 v8; // rcx
  signed __int64 v9; // rdx

  v1 = this;
  while ( v1->pStringNodePages )
  {
    v2 = v1->pStringNodePages;
    v1->pStringNodePages = v2->pNext;
    v3 = v2;
    v4 = 127i64;
    do
    {
      v5 = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v3->Nodes[0].pData;
      if ( v3->Nodes[0].pData )
      {
        if ( v3->Nodes[0].Size >= 0x10 )
        {
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          v5->pNextAlloc = v1->pFreeTextBuffers;
          v1->pFreeTextBuffers = v5;
        }
      }
      v3 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)((char *)v3 + 32);
      --v4;
    }
    while ( v4 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  while ( v1->pTextBufferPages )
  {
    v6 = v1->pTextBufferPages;
    v7 = v6->pMem;
    v1->pTextBufferPages = v6->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
  if ( v1->StringSet.pTable )
  {
    v8 = 0i64;
    v9 = v1->StringSet.pTable->SizeMask + 1;
    do
    {
      if ( v1->StringSet.pTable[v8 + 1].EntryCount != -2i64 )
        v1->StringSet.pTable[v8 + 1].EntryCount = -2i64;
      ++v8;
      --v9;
    }
    while ( v9 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->StringSet.pTable);
    v1->StringSet.pTable = 0i64;
  }
}

// File Line: 140
// RVA: 0x8B5EB0
void __fastcall Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager *v1; // rbx
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v2; // rax
  signed __int64 v3; // rdx

  v1 = this;
  v2 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)this->pHeap->vfptr->Alloc(this->pHeap, 4072ui64, 0i64);
  if ( v2 )
  {
    v2->pNext = v1->pStringNodePages;
    v1->pStringNodePages = v2;
    v3 = 127i64;
    do
    {
      v2->Nodes[0].pData = 0i64;
      v2->Nodes[0].pManager = (Scaleform::GFx::XML::DOMStringManager *)v1->pFreeStringNodes;
      v1->pFreeStringNodes = (Scaleform::GFx::XML::DOMStringNode *)v2;
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
  Scaleform::GFx::XML::DOMStringManager *v1; // rbx
  void *v2; // rax
  unsigned __int64 v3; // rcx
  signed __int64 v4; // r8
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v5; // rax
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v6; // rdx
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v7; // rcx

  v1 = this;
  v2 = this->pHeap->vfptr->Alloc(this->pHeap, 2040ui64, 0i64);
  v3 = ((unsigned __int64)v2 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  if ( v3 )
  {
    *(_QWORD *)(v3 + 2024) = v2;
    v4 = 21i64;
    *(_QWORD *)(v3 + 2016) = v1->pTextBufferPages;
    v1->pTextBufferPages = (Scaleform::GFx::XML::DOMStringManager::TextPage *)v3;
    v5 = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)(v3 + 32);
    do
    {
      v5[-2].pNextAlloc = v1->pFreeTextBuffers;
      v5[-1].pNextAlloc = v5 - 2;
      v5->pNextAlloc = v5 - 1;
      v5[1].pNextAlloc = v5;
      v6 = v5 + 2;
      v6->pNextAlloc = v5 + 1;
      v7 = v5 + 3;
      v5 += 6;
      v7->pNextAlloc = v6;
      v1->pFreeTextBuffers = v7;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 216
// RVA: 0x8B5DB0
Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *__fastcall Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(Scaleform::GFx::XML::DOMStringManager *this, const char *pbuffer, unsigned __int64 length)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbp
  Scaleform::GFx::XML::DOMStringManager *v5; // rdi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v6; // rax
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v7; // rbx

  v3 = length;
  v4 = pbuffer;
  v5 = this;
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
    v6 = v5->pFreeTextBuffers;
    v7 = 0i64;
    if ( v6 )
    {
      v7 = v5->pFreeTextBuffers;
      v5->pFreeTextBuffers = v6->pNextAlloc;
    }
  }
  if ( v7 )
  {
    memmove(v7, v4, v3);
    v7->Buff[v3] = 0;
  }
  return v7;
}

// File Line: 255
// RVA: 0x8C3EA0
Scaleform::GFx::XML::DOMStringNode *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateStringNode(Scaleform::GFx::XML::DOMStringManager *this, const char *pstr, unsigned __int64 length)
{
  unsigned __int64 v3; // rsi
  const char *v4; // r14
  Scaleform::GFx::XML::DOMStringManager *v5; // rbx
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > v7; // r8
  unsigned __int64 v8; // rbp
  signed __int64 v9; // rax
  Scaleform::GFx::XML::DOMStringNode *result; // rax
  Scaleform::GFx::XML::DOMStringNode *v11; // rdi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v12; // rax
  Scaleform::GFx::XML::DOMStringKey key; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::XML::DOMStringNode *v14; // [rsp+60h] [rbp+8h]

  v3 = length;
  v4 = pstr;
  v5 = this;
  key.pStr = pstr;
  v6 = Scaleform::String::BernsteinHashFunction(pstr, length, 0x1505ui64);
  v7.pTable = v5->StringSet.pTable;
  key.Length = v3;
  v8 = v6 & 0xFFFFFF;
  key.HashValue = v6 & 0xFFFFFF;
  if ( v7.pTable )
  {
    v9 = Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::findIndexCore<Scaleform::GFx::XML::DOMStringKey>(
           (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v5->StringSet.pTable,
           &key,
           v8 & v7.pTable->SizeMask);
    if ( v9 >= 0 )
      return (Scaleform::GFx::XML::DOMStringNode *)v5->StringSet.pTable[v9 + 1].SizeMask;
  }
  if ( !v3 )
    return &v5->EmptyStringNode;
  if ( !v5->pFreeStringNodes )
    Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(v5);
  v11 = v5->pFreeStringNodes;
  if ( v11 )
    v5->pFreeStringNodes = v11->pNextAlloc;
  v11->pManager = v5;
  v14 = v11;
  v12 = Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(v5, v4, v3);
  v11->pData = (const char *)v12;
  if ( v12 )
  {
    v11->RefCount = 0;
    v11->Size = v3;
    v11->HashFlags = v8;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
      (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v5->StringSet.pTable,
      v5,
      &v14,
      (unsigned int)v8);
    result = v11;
  }
  else
  {
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(v5, v11);
    result = &v5->EmptyStringNode;
  }
  return result;
}

// File Line: 343
// RVA: 0x89C040
void __fastcall Scaleform::GFx::XML::ObjectManager::ObjectManager(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::MovieImpl *powner)
{
  Scaleform::GFx::XML::ObjectManager *v2; // rbx

  v2 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::`vftable;
  this->vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable;
  this->pOwner = powner;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>};
  this->vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::XML::ObjectManager::`vftable{for `Scaleform::GFx::ExternalLibPtr};
  Scaleform::GFx::XML::DOMStringManager::DOMStringManager(&this->StringPool);
  v2->pHeap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v2);
}

// File Line: 363
// RVA: 0x8BF350
void __fastcall Scaleform::GFx::XML::ObjectManager::CreateDocument(Scaleform::GFx::XML::ObjectManager *this)
{
  Scaleform::GFx::XML::ObjectManager *v1; // rbx
  Scaleform::GFx::XML::Document *v2; // rax

  v1 = this;
  v2 = (Scaleform::GFx::XML::Document *)this->pHeap->vfptr->Alloc(this->pHeap, 144ui64, 0i64);
  if ( v2 )
    Scaleform::GFx::XML::Document::Document(v2, v1);
}

// File Line: 367
// RVA: 0x8BF640
Scaleform::GFx::XML::ElementNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateElementNode(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode **v2; // rdi
  Scaleform::GFx::XML::ObjectManager *v3; // rbx
  Scaleform::GFx::XML::ElementNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::XML::DOMStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::XML::DOMString valuea; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::XML::ElementNode *v11; // [rsp+68h] [rbp+20h]

  v2 = (Scaleform::GFx::XML::DOMStringNode **)value.pNode;
  v3 = this;
  v4 = (Scaleform::GFx::XML::ElementNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                             this->pHeap,
                                             120i64);
  v11 = v4;
  if ( v4 )
  {
    valuea.pNode = *v2;
    ++valuea.pNode->RefCount;
    Scaleform::GFx::XML::ElementNode::ElementNode(v4, v3, (Scaleform::GFx::XML::DOMString)&valuea);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = *v2;
  v8 = (*v2)->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v7);
  return (Scaleform::GFx::XML::ElementNode *)v6;
}

// File Line: 371
// RVA: 0x8C4070
Scaleform::GFx::XML::TextNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateTextNode(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode **v2; // rdi
  Scaleform::GFx::XML::ObjectManager *v3; // rbx
  Scaleform::GFx::XML::TextNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  Scaleform::GFx::XML::DOMStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::XML::DOMString valuea; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::XML::TextNode *v11; // [rsp+68h] [rbp+20h]

  v2 = (Scaleform::GFx::XML::DOMStringNode **)value.pNode;
  v3 = this;
  v4 = (Scaleform::GFx::XML::TextNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                          this->pHeap,
                                          72i64);
  v11 = v4;
  if ( v4 )
  {
    valuea.pNode = *v2;
    ++valuea.pNode->RefCount;
    Scaleform::GFx::XML::TextNode::TextNode(v4, v3, (Scaleform::GFx::XML::DOMString)&valuea);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = *v2;
  v8 = (*v2)->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v7);
  return (Scaleform::GFx::XML::TextNode *)v6;
}

// File Line: 375
// RVA: 0x8BE800
Scaleform::GFx::XML::Attribute *__fastcall Scaleform::GFx::XML::ObjectManager::CreateAttribute(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString name, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode **v3; // rsi
  Scaleform::GFx::XML::DOMStringNode **v4; // rdi
  Scaleform::GFx::XML::Attribute *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString namea; // [rsp+20h] [rbp-48h]
  __int64 v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::XML::Attribute *v14; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::XML::DOMString *v15; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::XML::DOMString *v16; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::XML::DOMString valuea; // [rsp+88h] [rbp+20h]

  v13 = -2i64;
  v3 = (Scaleform::GFx::XML::DOMStringNode **)value.pNode;
  v4 = (Scaleform::GFx::XML::DOMStringNode **)name.pNode;
  v5 = (Scaleform::GFx::XML::Attribute *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                           this->pHeap,
                                           24i64);
  v14 = v5;
  if ( v5 )
  {
    v15 = &valuea;
    v16 = &namea;
    valuea.pNode = *v3;
    ++valuea.pNode->RefCount;
    namea.pNode = *v4;
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
  v8 = *v4;
  v9 = (*v4)->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
  v10 = *v3;
  v9 = (*v3)->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  return (Scaleform::GFx::XML::Attribute *)v7;
}

// File Line: 379
// RVA: 0x8C2860
Scaleform::GFx::XML::Prefix *__fastcall Scaleform::GFx::XML::ObjectManager::CreatePrefix(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString name, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode **v3; // rsi
  Scaleform::GFx::XML::DOMStringNode **v4; // rdi
  Scaleform::GFx::XML::Prefix *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString namea; // [rsp+20h] [rbp-48h]
  __int64 v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::XML::Prefix *v14; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::XML::DOMString *v15; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::XML::DOMString *v16; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::XML::DOMString valuea; // [rsp+88h] [rbp+20h]

  v13 = -2i64;
  v3 = (Scaleform::GFx::XML::DOMStringNode **)value.pNode;
  v4 = (Scaleform::GFx::XML::DOMStringNode **)name.pNode;
  v5 = (Scaleform::GFx::XML::Prefix *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                        this->pHeap,
                                        32i64);
  v14 = v5;
  if ( v5 )
  {
    v15 = &valuea;
    v16 = &namea;
    valuea.pNode = *v3;
    ++valuea.pNode->RefCount;
    namea.pNode = *v4;
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
  v8 = *v4;
  v9 = (*v4)->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
  v10 = *v3;
  v9 = (*v3)->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  return (Scaleform::GFx::XML::Prefix *)v7;
}

// File Line: 383
// RVA: 0x8C3640
Scaleform::GFx::XML::RootNode *__fastcall Scaleform::GFx::XML::ObjectManager::CreateRootNode(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::Node *pdom)
{
  Scaleform::GFx::XML::Node *v2; // rbx
  Scaleform::GFx::XML::RootNode *result; // rax

  v2 = pdom;
  result = (Scaleform::GFx::XML::RootNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
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
  if ( v2 )
    ++v2->RefCount;
  result->pDOMTree.pObject = v2;
  return result;
}

