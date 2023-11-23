// File Line: 48
// RVA: 0x6D2080
void __fastcall Scaleform::GFx::AS2::MouseListener::~MouseListener(Scaleform::GFx::AS2::MouseListener *this)
{
  this->vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable;
}

// File Line: 76
// RVA: 0x6D2AF0
void __fastcall Scaleform::GFx::AS2::XMLFileLoader::~XMLFileLoader(Scaleform::GFx::AS2::XMLFileLoader *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoader::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 144
// RVA: 0x6C8A50
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this,
        Scaleform::GFx::CharacterHandle *pchar,
        Scaleform::String *url,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool loadingVars,
        bool quietOpen)
{
  Scaleform::GFx::CharacterHandle *pObject; // rbx

  Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(this, url, method, loadingVars, quietOpen);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable;
  this->pCharacter.pObject = 0i64;
  this->MovieClipLoaderHolder.T.Type = 0;
  this->LoadVarsHolder.T.Type = 0;
  this->XMLHolder.ASObj.T.Type = 0;
  this->XMLHolder.Loader.pObject = 0i64;
  if ( pchar )
    ++pchar->RefCount;
  pObject = this->pCharacter.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pCharacter.pObject = pchar;
  this->Level = -1;
}

// File Line: 150
// RVA: 0x6C8970
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this,
        int level,
        Scaleform::String *url,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool loadingVars,
        bool quietOpen)
{
  int v9; // ebx
  Scaleform::GFx::CharacterHandle *pObject; // rsi

  Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(this, url, method, loadingVars, quietOpen);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable;
  v9 = 0;
  this->pCharacter.pObject = 0i64;
  this->MovieClipLoaderHolder.T.Type = 0;
  this->LoadVarsHolder.T.Type = 0;
  this->XMLHolder.ASObj.T.Type = 0;
  this->XMLHolder.Loader.pObject = 0i64;
  pObject = this->pCharacter.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pCharacter.pObject = 0i64;
  this->Level = level;
  if ( loadingVars )
    v9 = 4;
  else
    LOBYTE(v9) = (url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  this->Type = v9 | 2;
}

// File Line: 465
// RVA: 0x6DABA0
void __fastcall Scaleform::GFx::AS2::MovieRoot::StickyVarNode::Assign(
        Scaleform::GFx::AS2::MovieRoot::StickyVarNode *this,
        Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *pNode; // rsi
  Scaleform::GFx::ASStringNode *v5; // rcx

  pNode = node->Name.pNode;
  ++pNode->RefCount;
  v5 = this->Name.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->Name.pNode = pNode;
  this->Permanent = node->Permanent;
  Scaleform::GFx::AS2::Value::operator=(&this->mValue, (Scaleform::GFx::AS2::Value *)&node[1]);
}

// File Line: 628
// RVA: 0x6F5390
Scaleform::GFx::DisplayObjContainer *__fastcall Scaleform::GFx::AS2::MovieRoot::GetRootMovie(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::DisplayObject *dobj)
{
  return (Scaleform::GFx::DisplayObjContainer *)this->pMovieImpl->pMainMovie;
}

// File Line: 700
// RVA: 0x6F65F0
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::AS2::MovieRoot::GetStringManager(
        Scaleform::GFx::AS2::MovieRoot *this)
{
  return this->MemContext.pObject->StringMgr.pObject;
}

