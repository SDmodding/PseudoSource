// File Line: 48
// RVA: 0x6D2080
void __fastcall Scaleform::GFx::AS2::MouseListener::~MouseListener(Scaleform::GFx::AS2::MouseListener *this)
{
  this->vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable';
}

// File Line: 76
// RVA: 0x6D2AF0
void __fastcall Scaleform::GFx::AS2::XMLFileLoader::~XMLFileLoader(Scaleform::GFx::AS2::XMLFileLoader *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 144
// RVA: 0x6C8A50
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this, Scaleform::GFx::CharacterHandle *pchar, Scaleform::String *url, Scaleform::GFx::LoadQueueEntry::LoadMethod method, bool loadingVars, bool quietOpen)
{
  Scaleform::GFx::CharacterHandle *v6; // rsi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v7; // rdi
  Scaleform::GFx::CharacterHandle *v8; // rbx

  v6 = pchar;
  v7 = this;
  Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(
    (Scaleform::GFx::LoadQueueEntry *)&this->vfptr,
    url,
    method,
    loadingVars,
    quietOpen);
  v7->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
  v7->pCharacter.pObject = 0i64;
  v7->MovieClipLoaderHolder.T.Type = 0;
  v7->LoadVarsHolder.T.Type = 0;
  v7->XMLHolder.ASObj.T.Type = 0;
  v7->XMLHolder.Loader.pObject = 0i64;
  if ( v6 )
    ++v6->RefCount;
  v8 = v7->pCharacter.pObject;
  if ( v8 )
  {
    if ( --v8->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v8);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  v7->pCharacter.pObject = v6;
  v7->Level = -1;
}

// File Line: 150
// RVA: 0x6C8970
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this, int level, Scaleform::String *url, Scaleform::GFx::LoadQueueEntry::LoadMethod method, bool loadingVars, bool quietOpen)
{
  Scaleform::String *v6; // r14
  int v7; // er15
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v8; // rdi
  signed int v9; // ebx
  Scaleform::GFx::CharacterHandle *v10; // rsi

  v6 = url;
  v7 = level;
  v8 = this;
  Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(
    (Scaleform::GFx::LoadQueueEntry *)&this->vfptr,
    url,
    method,
    loadingVars,
    quietOpen);
  v8->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
  v9 = 0;
  v8->pCharacter.pObject = 0i64;
  v8->MovieClipLoaderHolder.T.Type = 0;
  v8->LoadVarsHolder.T.Type = 0;
  v8->XMLHolder.ASObj.T.Type = 0;
  v8->XMLHolder.Loader.pObject = 0i64;
  v10 = v8->pCharacter.pObject;
  if ( v10 )
  {
    if ( --v10->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v10);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
    }
  }
  v8->pCharacter.pObject = 0i64;
  v8->Level = v7;
  if ( loadingVars )
    v9 = 4;
  else
    LOBYTE(v9) = (v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v8->Type = v9 | 2;
}

// File Line: 465
// RVA: 0x6DABA0
void __fastcall Scaleform::GFx::AS2::MovieRoot::StickyVarNode::Assign(Scaleform::GFx::AS2::MovieRoot::StickyVarNode *this, Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *v2; // rsi
  Scaleform::GFx::AS2::MovieRoot::StickyVarNode *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = node->Name.pNode;
  v3 = this;
  v4 = (Scaleform::GFx::AS2::Value *)node;
  ++v2->RefCount;
  v5 = this->Name.pNode;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->Name.pNode = v2;
  v3->Permanent = v4->V.FunctionValue.Flags;
  Scaleform::GFx::AS2::Value::operator=(&v3->mValue, v4 + 1, (__int64)v4);
}

// File Line: 628
// RVA: 0x6F5390
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::MovieRoot::GetRootMovie(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::DisplayObject *dobj)
{
  return this->pMovieImpl->pMainMovie;
}

// File Line: 700
// RVA: 0x6F65F0
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::AS2::MovieRoot::GetStringManager(Scaleform::GFx::AS2::MovieRoot *this)
{
  return this->MemContext.pObject->StringMgr.pObject;
}

