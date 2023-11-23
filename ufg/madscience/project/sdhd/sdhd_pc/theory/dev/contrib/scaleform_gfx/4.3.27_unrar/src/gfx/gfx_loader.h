// File Line: 204
// RVA: 0x5C9230
void __fastcall Scaleform::GFx::State::~State(Scaleform::GFx::State *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 831
// RVA: 0x896C70
void __fastcall Scaleform::GFx::FontProvider::FontProvider(
        Scaleform::GFx::FontProvider *this,
        Scaleform::GFx::Resource *fp)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_ProjectionMatrix3D|0x10;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProvider::`vftable;
  if ( fp )
    Scaleform::Render::RenderBuffer::AddRef(fp);
  this->pFontProvider.pObject = (Scaleform::Render::FontProvider *)fp;
}

// File Line: 832
// RVA: 0x8A4B50
void __fastcall Scaleform::GFx::FontProvider::~FontProvider(Scaleform::GFx::FontProvider *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProvider::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 984
// RVA: 0x8BDCD0
_BOOL8 __fastcall Scaleform::GFx::Clipboard::ContainsRichText(Scaleform::GFx::Clipboard *this)
{
  return this->pStyledText != 0i64;
}

// File Line: 1233
// RVA: 0x8A7BF0
void __fastcall Scaleform::GFx::StateBag::~StateBag(Scaleform::GFx::StateBag *this)
{
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
}

// File Line: 1238
// RVA: 0x90C200
void __fastcall Scaleform::GFx::StateBag::SetState(
        Scaleform::GFx::StateBag *this,
        unsigned int state,
        Scaleform::GFx::State *pstate)
{
  __int64 v5; // rax

  v5 = this->vfptr->GetStateBagImpl(this);
  if ( v5 )
    (*(void (__fastcall **)(__int64, _QWORD, Scaleform::GFx::State *))(*(_QWORD *)v5 + 16i64))(v5, state, pstate);
}

// File Line: 1247
// RVA: 0x8DE2D0
Scaleform::GFx::State *__fastcall Scaleform::GFx::StateBag::GetStateAddRef(
        Scaleform::GFx::StateBag *this,
        unsigned int state)
{
  Scaleform::GFx::State *result; // rax

  result = (Scaleform::GFx::State *)this->vfptr->GetStateBagImpl(this);
  if ( result )
    return (Scaleform::GFx::State *)result->vfptr[3].__vecDelDtor(result, state);
  return result;
}

// File Line: 1256
// RVA: 0x8DE440
void __fastcall Scaleform::GFx::StateBag::GetStatesAddRef(
        Scaleform::GFx::StateBag *this,
        Scaleform::GFx::State **pstateList,
        Scaleform::GFx::State::StateType *pstates,
        unsigned int count)
{
  __int64 v7; // rax

  v7 = this->vfptr->GetStateBagImpl(this);
  if ( v7 )
    (*(void (__fastcall **)(__int64, Scaleform::GFx::State **, Scaleform::GFx::State::StateType *, _QWORD))(*(_QWORD *)v7 + 32i64))(
      v7,
      pstateList,
      pstates,
      count);
}

// File Line: 1276
// RVA: 0x8E1150
Scaleform::Ptr<Scaleform::GFx::Translator> *__fastcall Scaleform::GFx::StateBag::GetTranslator(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::Translator> *result)
{
  result->pObject = (Scaleform::GFx::Translator *)this->vfptr->GetStateAddRef(this, 1i64);
  return result;
}

// File Line: 1284
// RVA: 0x7E5B40
Scaleform::Ptr<Scaleform::GFx::ActionControl> *__fastcall Scaleform::GFx::StateBag::GetActionControl(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ActionControl> *result)
{
  result->pObject = (Scaleform::GFx::ActionControl *)this->vfptr->GetStateAddRef(this, 3i64);
  return result;
}

// File Line: 1296
// RVA: 0x6F6640
Scaleform::Ptr<Scaleform::GFx::TestStream> *__fastcall Scaleform::GFx::StateBag::GetTestStream(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::TestStream> *result)
{
  result->pObject = (Scaleform::GFx::TestStream *)this->vfptr->GetStateAddRef(this, 34i64);
  return result;
}

// File Line: 1326
// RVA: 0x8D7B00
Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *__fastcall Scaleform::GFx::StateBag::GetFileOpener(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *result)
{
  result->pObject = (Scaleform::GFx::FileOpenerBase *)this->vfptr->GetStateAddRef(this, 12i64);
  return result;
}

// File Line: 1346
// RVA: 0x8DC0A0
Scaleform::Ptr<Scaleform::GFx::ParseControl> *__fastcall Scaleform::GFx::StateBag::GetParseControl(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ParseControl> *result)
{
  result->pObject = (Scaleform::GFx::ParseControl *)this->vfptr->GetStateAddRef(this, 16i64);
  return result;
}

// File Line: 1349
// RVA: 0x8DC3D0
Scaleform::Ptr<Scaleform::GFx::ProgressHandler> *__fastcall Scaleform::GFx::StateBag::GetProgressHandler(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ProgressHandler> *result)
{
  result->pObject = (Scaleform::GFx::ProgressHandler *)this->vfptr->GetStateAddRef(this, 17i64);
  return result;
}

// File Line: 1366
// RVA: 0x6EFAE0
Scaleform::Ptr<Scaleform::GFx::FontProvider> *__fastcall Scaleform::GFx::StateBag::GetFontProvider(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::FontProvider> *result)
{
  result->pObject = (Scaleform::GFx::FontProvider *)this->vfptr->GetStateAddRef(this, 22i64);
  return result;
}

// File Line: 1369
// RVA: 0x8D84A0
Scaleform::Ptr<Scaleform::GFx::FontMap> *__fastcall Scaleform::GFx::StateBag::GetFontMap(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::FontMap> *result)
{
  result->pObject = (Scaleform::GFx::FontMap *)this->vfptr->GetStateAddRef(this, 23i64);
  return result;
}

// File Line: 1381
// RVA: 0x7E7280
Scaleform::Ptr<Scaleform::GFx::Clipboard> *__fastcall Scaleform::GFx::StateBag::GetClipboard(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::Clipboard> *result)
{
  result->pObject = (Scaleform::GFx::Clipboard *)this->vfptr->GetStateAddRef(this, 25i64);
  return result;
}

// File Line: 1384
// RVA: 0x8DF190
Scaleform::Ptr<Scaleform::GFx::TextKeyMap> *__fastcall Scaleform::GFx::StateBag::GetTextKeyMap(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::TextKeyMap> *result)
{
  result->pObject = (Scaleform::GFx::TextKeyMap *)this->vfptr->GetStateAddRef(this, 26i64);
  return result;
}

// File Line: 1395
// RVA: 0x8E2040
Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *__fastcall Scaleform::GFx::StateBag::GetZlibSupport(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *result)
{
  result->pObject = (Scaleform::GFx::ZlibSupportBase *)this->vfptr->GetStateAddRef(this, 29i64);
  return result;
}

// File Line: 1411
// RVA: 0x7F0BD0
Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *__fastcall Scaleform::GFx::StateBag::GetUrlNavigator(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *result)
{
  result->pObject = (Scaleform::GFx::UrlNavigator *)this->vfptr->GetStateAddRef(this, 36i64);
  return result;
}

// File Line: 1414
// RVA: 0x8D4930
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::StateBag::GetAS2Support(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  result->pObject = (Scaleform::GFx::ASSupport *)this->vfptr->GetStateAddRef(this, 38i64);
  return result;
}

// File Line: 1417
// RVA: 0x8D4970
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::StateBag::GetAS3Support(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  result->pObject = (Scaleform::GFx::ASSupport *)this->vfptr->GetStateAddRef(this, 39i64);
  return result;
}

// File Line: 1676
// RVA: 0x50AB0
void __fastcall Scaleform::GFx::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::MemoryHeap::HeapDesc v1; // [rsp+20h] [rbp-48h] BYREF

  v1.Flags = 0;
  v1.MinAlign = 16i64;
  v1.Granularity = 0x4000i64;
  v1.Reserve = 0x4000i64;
  v1.Threshold = 0x40000i64;
  v1.Limit = 0i64;
  v1.HeapId = 1i64;
  v1.Arena = 0i64;
  Scaleform::GFx::System::Init(&v1, psysAlloc);
}

