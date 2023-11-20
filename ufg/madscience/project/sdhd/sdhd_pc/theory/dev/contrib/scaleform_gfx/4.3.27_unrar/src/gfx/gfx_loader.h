// File Line: 204
// RVA: 0x5C9230
void __fastcall Scaleform::GFx::State::~State(Scaleform::GFx::State *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 831
// RVA: 0x896C70
void __fastcall Scaleform::GFx::FontProvider::FontProvider(Scaleform::GFx::FontProvider *this, Scaleform::Render::FontProvider *fp)
{
  Scaleform::Render::FontProvider *v2; // rdi
  Scaleform::GFx::FontProvider *v3; // rbx

  v2 = fp;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 22;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProvider::`vftable;
  if ( fp )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)fp);
  v3->pFontProvider.pObject = v2;
}

// File Line: 832
// RVA: 0x8A4B50
void __fastcall Scaleform::GFx::FontProvider::~FontProvider(Scaleform::GFx::FontProvider *this)
{
  Scaleform::GFx::FontProvider *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProvider::`vftable;
  v2 = (Scaleform::Render::RenderBuffer *)this->pFontProvider.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
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
void __fastcall Scaleform::GFx::StateBag::SetState(Scaleform::GFx::StateBag *this, Scaleform::GFx::State::StateType state, Scaleform::GFx::State *pstate)
{
  Scaleform::GFx::State *v3; // rbx
  Scaleform::GFx::State::StateType v4; // edi
  __int64 v5; // rax

  v3 = pstate;
  v4 = state;
  v5 = ((__int64 (*)(void))this->vfptr->GetStateBagImpl)();
  if ( v5 )
    (*(void (__fastcall **)(__int64, _QWORD, Scaleform::GFx::State *))(*(_QWORD *)v5 + 16i64))(v5, (unsigned int)v4, v3);
}

// File Line: 1247
// RVA: 0x8DE2D0
Scaleform::GFx::State *__fastcall Scaleform::GFx::StateBag::GetStateAddRef(Scaleform::GFx::StateBag *this, Scaleform::GFx::State::StateType state)
{
  unsigned int v2; // ebx
  Scaleform::GFx::State *result; // rax

  v2 = state;
  result = (Scaleform::GFx::State *)((__int64 (*)(void))this->vfptr->GetStateBagImpl)();
  if ( result )
    result = (Scaleform::GFx::State *)result->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)result, v2);
  return result;
}

// File Line: 1256
// RVA: 0x8DE440
void __fastcall Scaleform::GFx::StateBag::GetStatesAddRef(Scaleform::GFx::StateBag *this, Scaleform::GFx::State **pstateList, Scaleform::GFx::State::StateType *pstates, unsigned int count)
{
  unsigned int v4; // ebx
  Scaleform::GFx::State::StateType *v5; // rdi
  Scaleform::GFx::State **v6; // rsi
  __int64 v7; // rax

  v4 = count;
  v5 = pstates;
  v6 = pstateList;
  v7 = ((__int64 (*)(void))this->vfptr->GetStateBagImpl)();
  if ( v7 )
    (*(void (__fastcall **)(__int64, Scaleform::GFx::State **, Scaleform::GFx::State::StateType *, _QWORD))(*(_QWORD *)v7 + 32i64))(
      v7,
      v6,
      v5,
      v4);
}

// File Line: 1276
// RVA: 0x8E1150
Scaleform::Ptr<Scaleform::GFx::Translator> *__fastcall Scaleform::GFx::StateBag::GetTranslator(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::Translator> *result)
{
  Scaleform::Ptr<Scaleform::GFx::Translator> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::Translator *)this->vfptr->GetStateAddRef(this, State_BlendMode);
  return v2;
}

// File Line: 1284
// RVA: 0x7E5B40
Scaleform::Ptr<Scaleform::GFx::ActionControl> *__fastcall Scaleform::GFx::StateBag::GetActionControl(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ActionControl> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ActionControl> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ActionControl *)this->vfptr->GetStateAddRef(this, State_Filter);
  return v2;
}

// File Line: 1296
// RVA: 0x6F6640
Scaleform::Ptr<Scaleform::GFx::TestStream> *__fastcall Scaleform::GFx::StateBag::GetTestStream(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::TestStream> *result)
{
  Scaleform::Ptr<Scaleform::GFx::TestStream> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::TestStream *)this->vfptr->GetStateAddRef(
                                                    this,
                                                    (Scaleform::GFx::State::StateType)34i64);
  return v2;
}

// File Line: 1326
// RVA: 0x8D7B00
Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *__fastcall Scaleform::GFx::StateBag::GetFileOpener(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *result)
{
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::FileOpenerBase *)this->vfptr->GetStateAddRef(
                                                        this,
                                                        State_OrigScale9Parent|State_MaskNode);
  return v2;
}

// File Line: 1346
// RVA: 0x8DC0A0
Scaleform::Ptr<Scaleform::GFx::ParseControl> *__fastcall Scaleform::GFx::StateBag::GetParseControl(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ParseControl> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ParseControl> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ParseControl *)this->vfptr->GetStateAddRef(
                                                      this,
                                                      (Scaleform::GFx::State::StateType)16i64);
  return v2;
}

// File Line: 1349
// RVA: 0x8DC3D0
Scaleform::Ptr<Scaleform::GFx::ProgressHandler> *__fastcall Scaleform::GFx::StateBag::GetProgressHandler(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ProgressHandler> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ProgressHandler> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ProgressHandler *)this->vfptr->GetStateAddRef(
                                                         this,
                                                         (Scaleform::GFx::State::StateType)17i64);
  return v2;
}

// File Line: 1366
// RVA: 0x6EFAE0
Scaleform::Ptr<Scaleform::GFx::FontProvider> *__fastcall Scaleform::GFx::StateBag::GetFontProvider(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::FontProvider> *result)
{
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::FontProvider *)this->vfptr->GetStateAddRef(this, State_ProjectionMatrix3D|0x10);
  return v2;
}

// File Line: 1369
// RVA: 0x8D84A0
Scaleform::Ptr<Scaleform::GFx::FontMap> *__fastcall Scaleform::GFx::StateBag::GetFontMap(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::FontMap> *result)
{
  Scaleform::Ptr<Scaleform::GFx::FontMap> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::FontMap *)this->vfptr->GetStateAddRef(this, State_UserData|0x10);
  return v2;
}

// File Line: 1381
// RVA: 0x7E7280
Scaleform::Ptr<Scaleform::GFx::Clipboard> *__fastcall Scaleform::GFx::StateBag::GetClipboard(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::Clipboard> *result)
{
  Scaleform::Ptr<Scaleform::GFx::Clipboard> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::Clipboard *)this->vfptr->GetStateAddRef(this, State_Internal_MaskOwner|0x10);
  return v2;
}

// File Line: 1384
// RVA: 0x8DF190
Scaleform::Ptr<Scaleform::GFx::TextKeyMap> *__fastcall Scaleform::GFx::StateBag::GetTextKeyMap(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::TextKeyMap> *result)
{
  Scaleform::Ptr<Scaleform::GFx::TextKeyMap> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::TextKeyMap *)this->vfptr->GetStateAddRef(this, State_OrigNodeBounds|0x10);
  return v2;
}

// File Line: 1395
// RVA: 0x8E2040
Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *__fastcall Scaleform::GFx::StateBag::GetZlibSupport(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ZlibSupportBase *)this->vfptr->GetStateAddRef(
                                                         this,
                                                         State_Internal_MaskOwner|State_MaskNode|0x10);
  return v2;
}

// File Line: 1411
// RVA: 0x7F0BD0
Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *__fastcall Scaleform::GFx::StateBag::GetUrlNavigator(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *result)
{
  Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::UrlNavigator *)this->vfptr->GetStateAddRef(
                                                      this,
                                                      (Scaleform::GFx::State::StateType)36i64);
  return v2;
}

// File Line: 1414
// RVA: 0x8D4930
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::StateBag::GetAS2Support(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ASSupport *)this->vfptr->GetStateAddRef(this, State_ProjectionMatrix3D|0x20);
  return v2;
}

// File Line: 1417
// RVA: 0x8D4970
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::StateBag::GetAS3Support(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ASSupport *)this->vfptr->GetStateAddRef(this, State_UserData|0x20);
  return v2;
}

// File Line: 1676
// RVA: 0x50AB0
void __fastcall Scaleform::GFx::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  int v1; // [rsp+20h] [rbp-48h]
  __int64 v2; // [rsp+28h] [rbp-40h]
  __int64 v3; // [rsp+30h] [rbp-38h]
  __int64 v4; // [rsp+38h] [rbp-30h]
  __int64 v5; // [rsp+40h] [rbp-28h]
  __int64 v6; // [rsp+48h] [rbp-20h]
  __int64 v7; // [rsp+50h] [rbp-18h]
  __int64 v8; // [rsp+58h] [rbp-10h]

  v1 = 0;
  v2 = 16i64;
  v3 = 0x4000i64;
  v4 = 0x4000i64;
  v5 = 0x40000i64;
  v6 = 0i64;
  v7 = 1i64;
  v8 = 0i64;
  Scaleform::GFx::System::Init((Scaleform::MemoryHeap::HeapDesc *)&v1, psysAlloc);
}

