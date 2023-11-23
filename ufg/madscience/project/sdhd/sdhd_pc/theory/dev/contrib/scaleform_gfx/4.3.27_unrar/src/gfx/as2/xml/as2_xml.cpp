// File Line: 78
// RVA: 0x6CDB00
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::GFx::Resource *pparser,
        Scaleform::GFx::XML::ObjectManager *objMgr,
        bool ignorews)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::XMLFileLoader,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoader::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::`vftable;
  if ( pparser )
    Scaleform::Render::RenderBuffer::AddRef(pparser);
  this->pParser.pObject = (Scaleform::GFx::XML::SupportBase *)pparser;
  this->pObjectManager = objMgr;
  this->pFileData = 0i64;
  this->FileLength = 0;
  this->bIgnoreWhitespace = ignorews;
}

// File Line: 90
// RVA: 0x701250
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::Load(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::String *filename,
        Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::Render::RenderBuffer *v6; // rbx
  __int64 v7; // rax
  int v8; // eax
  char *v9; // rax
  __int64 v10[5]; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  memset(v10, 0, 24);
  if ( !Scaleform::GFx::URLBuilder::IsProtocol(filename) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, __int64, __int64, __int64, __int64 *))pfo->vfptr[1].__vecDelDtor)(
           pfo,
           (filename->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
           33i64,
           438i64,
           -2i64,
           v10);
    v6 = (Scaleform::Render::RenderBuffer *)v7;
    if ( v7 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
      {
        v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *))v6->vfptr[6].__vecDelDtor)(v6);
        this->FileLength = v8;
        if ( v8 )
        {
          v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8, 0i64);
          this->pFileData = v9;
          ((void (__fastcall *)(Scaleform::Render::RenderBuffer *, char *, _QWORD))v6->vfptr[10].__vecDelDtor)(
            v6,
            v9,
            (unsigned int)this->FileLength);
        }
      }
    }
  }
  if ( v10[0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 123
// RVA: 0x6FCC50
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::InitASXml(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::XmlObject *pTarget)
{
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::GFx::XML::SupportBase *pObjectManager; // rax
  Scaleform::GFx::XML::Document *v8; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *RootNode; // r15
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pLower; // rcx
  unsigned int RefCount; // eax
  double v14; // xmm0_8
  bool v15; // r8
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  double LoadedBytes_low; // xmm0_8
  double TotalBytesToLoad_low; // xmm1_8
  Scaleform::GFx::AS2::Value v21; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v22; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::XML::DOMBuilder v23; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::Document> result; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+168h] [rbp+68h] BYREF

  v22 = -2i64;
  if ( this->pFileData )
  {
    v26.pNode = (Scaleform::GFx::ASStringNode *)&pxmlParser;
    pObject = (Scaleform::GFx::Resource *)this->pParser.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef(pObject);
    pxmlParser.pObject = this->pParser.pObject;
    Scaleform::GFx::XML::DOMBuilder::DOMBuilder(
      &v23,
      (Scaleform::Ptr<Scaleform::GFx::XML::SupportBase>)&pxmlParser,
      this->bIgnoreWhitespace);
    v26.pNode = (Scaleform::GFx::ASStringNode *)&pxmlParser;
    pObjectManager = (Scaleform::GFx::XML::SupportBase *)this->pObjectManager;
    if ( pObjectManager )
      ++pObjectManager->RefCount;
    pxmlParser.pObject = pObjectManager;
    Scaleform::GFx::XML::DOMBuilder::ParseString(
      &v23,
      &result,
      this->pFileData,
      this->FileLength,
      (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)&pxmlParser);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    this->pFileData = 0i64;
    v8 = result.pObject;
    pTarget->pRealNode = result.pObject;
    RootNode = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::XML::ObjectManager::CreateRootNode(
                                                                 this->pObjectManager,
                                                                 v8);
    v10 = pTarget->pRootNode.pObject;
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    pTarget->pRootNode.pObject = (Scaleform::GFx::XML::RootNode *)RootNode;
    pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)this->pObjectManager->pHeap;
    v11 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(v10, 24i64);
    v26.pNode = v11;
    if ( v11 )
    {
      v11->pData = (const char *)&Scaleform::GFx::XML::ShadowRefBase::`vftable;
      v11->pData = (const char *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable;
      v11->pManager = 0i64;
      v11->pLower = 0i64;
    }
    else
    {
      v11 = 0i64;
    }
    pLower = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11->pLower;
    if ( pLower )
    {
      RefCount = pLower->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pLower->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLower);
      }
    }
    v11->pLower = 0i64;
    v11->pManager = (Scaleform::GFx::ASStringManager *)pTarget;
    result.pObject->pShadow = (Scaleform::GFx::XML::ShadowRefBase *)v11;
    Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(pTarget, penv, result.pObject);
    if ( !v23.bError || v23.TotalBytesToLoad )
    {
      LOBYTE(pxmlParser.pObject) = 2;
      v21.T.Type = 2;
      v21.V.BooleanValue = 1;
      v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v26, "loaded");
      pTarget->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &pTarget->Scaleform::GFx::AS2::ObjectInterface,
        &penv->StringContext,
        v16,
        &v21,
        (Scaleform::GFx::AS2::PropFlags *)&pxmlParser);
      pNode = v26.pNode;
      if ( v26.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      LoadedBytes_low = (double)SLODWORD(v23.LoadedBytes);
      if ( (v23.LoadedBytes & 0x8000000000000000ui64) != 0i64 )
        LoadedBytes_low = LoadedBytes_low + 1.844674407370955e19;
      pTarget->BytesLoadedCurrent = LoadedBytes_low;
      TotalBytesToLoad_low = (double)SLODWORD(v23.TotalBytesToLoad);
      if ( (v23.TotalBytesToLoad & 0x8000000000000000ui64) != 0i64 )
        TotalBytesToLoad_low = TotalBytesToLoad_low + 1.844674407370955e19;
      pTarget->BytesLoadedTotal = TotalBytesToLoad_low;
      v15 = 1;
    }
    else
    {
      v14 = (double)SLODWORD(v23.LoadedBytes);
      if ( (v23.LoadedBytes & 0x8000000000000000ui64) != 0i64 )
        v14 = v14 + 1.844674407370955e19;
      pTarget->BytesLoadedCurrent = v14;
      pTarget->BytesLoadedTotal = -1.0;
      v15 = 0;
    }
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(pTarget, penv, v15);
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v23);
  }
  else
  {
    pTarget->BytesLoadedCurrent = 0.0;
    pTarget->BytesLoadedTotal = -1.0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(pTarget, penv, 0);
  }
}

// File Line: 217
// RVA: 0x701360
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderImpl::Load(
        Scaleform::GFx::AS2::XMLFileLoaderImpl *this,
        Scaleform::String *filename,
        Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::Render::RenderBuffer *v6; // rbx
  __int64 v7; // rax
  int v8; // eax
  char *v9; // rax
  __int64 v10[5]; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  memset(v10, 0, 24);
  if ( !Scaleform::GFx::URLBuilder::IsProtocol(filename) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, __int64, __int64, __int64, __int64 *))pfo->vfptr[1].__vecDelDtor)(
           pfo,
           (filename->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
           33i64,
           438i64,
           -2i64,
           v10);
    v6 = (Scaleform::Render::RenderBuffer *)v7;
    if ( v7 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
      {
        v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *))v6->vfptr[6].__vecDelDtor)(v6);
        this->FileLength = v8;
        if ( v8 )
        {
          v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8, 0i64);
          this->pFileData = v9;
          ((void (__fastcall *)(Scaleform::Render::RenderBuffer *, char *, _QWORD))v6->vfptr[10].__vecDelDtor)(
            v6,
            v9,
            (unsigned int)this->FileLength);
        }
      }
    }
  }
  if ( v10[0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 250
// RVA: 0x6FCF00
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderImpl::InitASXml(
        Scaleform::GFx::AS2::XMLFileLoaderImpl *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::XmlObject *pTarget)
{
  char *pFileData; // r8
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::Value *v12; // [rsp+70h] [rbp+18h]

  pFileData = this->pFileData;
  if ( pFileData )
  {
    v12 = &v10;
    v7 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, pFileData, this->FileLength);
    v10.T.Type = 5;
    v10.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v7->pNode;
    ++v10.V.pStringNode->RefCount;
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(pTarget, penv, &v10);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    this->pFileData = 0i64;
  }
  else
  {
    result.pNode = (Scaleform::GFx::ASStringNode *)&v10;
    v10.T.Type = 0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(pTarget, penv, &v10);
  }
}

// File Line: 279
// RVA: 0x724730
void __fastcall Scaleform::GFx::AS2::XML_LoadString(
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::XmlObject *pnode)
{
  __int64 v4; // rcx
  Scaleform::GFx::LogState *v5; // rsi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  Scaleform::GFx::ASStringNode *v7; // r14
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // rbx
  Scaleform::GFx::ASStringNode *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  Scaleform::GFx::ExternalLibPtr *v12; // rax
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v15; // r8
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::Ptr<Scaleform::GFx::XML::Document> *v17; // rax
  Scaleform::GFx::XML::Document *Document; // rdi
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::XML::DOMString *String; // rax
  Scaleform::GFx::XML::RootNode *RootNode; // rsi
  Scaleform::GFx::XML::RootNode *v23; // rcx
  Scaleform::RefCountImplCore *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rsi
  Scaleform::GFx::ASStringNode *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pLower; // rcx
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> result; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *p_pxmlParser; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS2::Value v32; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v33; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::XML::DOMBuilder v34; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser; // [rsp+170h] [rbp+70h] BYREF
  __int64 v36; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::ASString v37; // [rsp+180h] [rbp+80h] BYREF
  Scaleform::GFx::XML::Document *v38; // [rsp+188h] [rbp+88h]

  v33 = -2i64;
  v5 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v7 = 0i64;
  v36 = 0i64;
  pXMLObjectManager = pMovieImpl->pXMLObjectManager;
  if ( pXMLObjectManager )
  {
    v11 = (__int64)&pXMLObjectManager[-1];
    if ( v11 )
      ++*(_DWORD *)(v11 + 8);
    v36 = v11;
  }
  else
  {
    pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)fn->Env->StringContext.pContext->pHeap;
    v9 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))pxmlParser.pObject->vfptr[10].__vecDelDtor)(
                                           v4,
                                           120i64,
                                           0i64);
    v37.pNode = v9;
    if ( v9 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager((Scaleform::GFx::XML::ObjectManager *)v9, pMovieImpl);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    v36 = v11;
    v12 = (Scaleform::GFx::ExternalLibPtr *)(v11 + 16);
    if ( !v11 )
      v12 = 0i64;
    pMovieImpl->pXMLObjectManager = v12;
  }
  v38 = 0i64;
  v32.T.Type = 0;
  if ( fn->NArgs <= 0 )
    goto LABEL_29;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v15 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v15 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::operator=(&v32, v15);
  pObject = (Scaleform::GFx::Resource *)Scaleform::GFx::StateBag::GetXMLSupport(
                                          &fn->Env->Target->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                          &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !pObject )
  {
    if ( v5 )
    {
      LODWORD(pxmlParser.pObject) = 212992;
      Scaleform::Log::LogMessageById(v5, (Scaleform::LogMessageId)&pxmlParser, "No XML parser state set for movie!");
    }
    goto LABEL_29;
  }
  p_pxmlParser = &pxmlParser;
  Scaleform::Render::RenderBuffer::AddRef(pObject);
  pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)pObject;
  Scaleform::GFx::XML::DOMBuilder::DOMBuilder(&v34, (Scaleform::Ptr<Scaleform::GFx::XML::SupportBase>)&pxmlParser, 1);
  Scaleform::GFx::AS2::Value::ToString(&v32, &v37, fn->Env, -1);
  p_pxmlParser = &pxmlParser;
  if ( v11 )
    ++*(_DWORD *)(v11 + 8);
  pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)v11;
  v17 = Scaleform::GFx::XML::DOMBuilder::ParseString(
          &v34,
          (Scaleform::Ptr<Scaleform::GFx::XML::Document> *)&result,
          v37.pNode->pData,
          v37.pNode->Size,
          (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)&pxmlParser);
  if ( v17->pObject )
    ++v17->pObject->RefCount;
  Document = v17->pObject;
  v38 = v17->pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)result.pObject);
  Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(pnode, fn->Env, Document);
  v19 = v37.pNode;
  if ( v37.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v34);
  if ( !Document )
  {
LABEL_29:
    Document = Scaleform::GFx::XML::ObjectManager::CreateDocument((Scaleform::GFx::XML::ObjectManager *)v11);
    v38 = Document;
  }
  String = Scaleform::GFx::XML::ObjectManager::CreateString(
             (Scaleform::GFx::XML::ObjectManager *)v11,
             (Scaleform::GFx::XML::DOMString *)&pxmlParser,
             "null",
             4ui64);
  Scaleform::GFx::XML::DOMString::AssignNode(&Document->Value, String->pNode);
  Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&pxmlParser);
  pnode->pRealNode = Document;
  RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode((Scaleform::GFx::XML::ObjectManager *)v11, Document);
  v23 = pnode->pRootNode.pObject;
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
  pnode->pRootNode.pObject = RootNode;
  pxmlParser.pObject = *(Scaleform::GFx::XML::SupportBase **)(v11 + 112);
  v25 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(v23, 24i64);
  v37.pNode = v25;
  if ( v25 )
  {
    v25->pData = (const char *)&Scaleform::GFx::XML::ShadowRefBase::`vftable;
    v25->pData = (const char *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable;
    v25->pManager = 0i64;
    v25->pLower = 0i64;
  }
  else
  {
    v25 = 0i64;
  }
  Document->pShadow = (Scaleform::GFx::XML::ShadowRefBase *)v25;
  pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)fn->Env->StringContext.pContext->pHeap;
  v26 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(v24, 112i64);
  v37.pNode = v26;
  if ( v26 )
  {
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject((Scaleform::GFx::AS2::XmlNodeObject *)v26, fn->Env);
    v7 = v27;
  }
  pLower = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v25->pLower;
  if ( pLower )
  {
    RefCount = pLower->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pLower->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLower);
    }
  }
  v25->pLower = v7;
  v25->pManager = (Scaleform::GFx::ASStringManager *)pnode;
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
  Scaleform::RefCountNTSImpl::Release(Document);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v11);
}

// File Line: 334
// RVA: 0x6CE1B0
void __fastcall Scaleform::GFx::AS2::XmlObject::XmlObject(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(this, penv);
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XML);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  this->BytesLoadedCurrent = -1.0;
  this->BytesLoadedTotal = -1.0;
  if ( this != (Scaleform::GFx::AS2::XmlObject *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    &penv->StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    penv,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->Scaleform::GFx::AS2::ObjectInterface);
}

// File Line: 361
// RVA: 0x6DAC00
void __fastcall Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::Document *pdoc)
{
  char *pData; // rdi
  const char *v7; // rdx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-19h] BYREF
  __int64 v14; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS2::Value v15; // [rsp+28h] [rbp-9h] BYREF
  Scaleform::StringBuffer v16; // [rsp+48h] [rbp+17h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v18; // [rsp+B0h] [rbp+7Fh] BYREF

  v14 = -2i64;
  pData = &customCaption;
  Scaleform::StringBuffer::StringBuffer(
    (Scaleform::StringBuffer *)&v16.GrowSize,
    &customCaption,
    Scaleform::Memory::pGlobalHeap);
  if ( pdoc )
  {
    Scaleform::StringBuffer::AppendString(&v16, "<?", -1i64);
    if ( pdoc->XMLVersion.pNode->Size )
    {
      Scaleform::StringBuffer::AppendString(&v16, "xml version=\"", -1i64);
      Scaleform::StringBuffer::AppendString(&v16, pdoc->XMLVersion.pNode->pData, -1i64);
      Scaleform::StringBuffer::AppendString(&v16, "\"", -1i64);
    }
    if ( pdoc->Encoding.pNode->Size )
    {
      if ( pdoc->XMLVersion.pNode->Size )
        Scaleform::StringBuffer::AppendString(&v16, " ", -1i64);
      Scaleform::StringBuffer::AppendString(&v16, "encoding=\"", -1i64);
      Scaleform::StringBuffer::AppendString(&v16, pdoc->Encoding.pNode->pData, -1i64);
      Scaleform::StringBuffer::AppendString(&v16, "\"", -1i64);
    }
    if ( pdoc->Standalone != -1 )
    {
      if ( pdoc->XMLVersion.pNode->Size || pdoc->Encoding.pNode->Size )
        Scaleform::StringBuffer::AppendString(&v16, " ", -1i64);
      v7 = "standalone=\"yes\"";
      if ( !pdoc->Standalone )
        v7 = "standalone=\"no\"";
      Scaleform::StringBuffer::AppendString(&v16, v7, -1i64);
    }
    Scaleform::StringBuffer::AppendString(&v16, "?>", -1i64);
  }
  if ( pdoc->XMLVersion.pNode->Size || pdoc->Encoding.pNode->Size || pdoc->Standalone != -1 )
  {
    if ( v16.pData )
      pData = v16.pData;
    v8 = Scaleform::GFx::AS2::ASStringContext::CreateString(&penv->StringContext, &result, pData, v16.Size);
    v15.T.Type = 5;
    v15.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++v15.V.pStringNode->RefCount;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v18, "xmlDecl");
    LOBYTE(retaddr) = 0;
    this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      penv,
      v9,
      &v15,
      (Scaleform::GFx::AS2::PropFlags *)&retaddr);
    pNode = v18.pNode;
    v11 = v18.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    v12 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v16);
}

// File Line: 405
// RVA: 0x703B20
void __fastcall Scaleform::GFx::AS2::XmlObject::NotifyOnData(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  Scaleform::GFx::ASString *v7; // rax
  int v8; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h] BYREF
  int v13; // [rsp+30h] [rbp-38h]
  int v14; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v16; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS2::Value *v17; // [rsp+80h] [rbp+18h]

  v17 = val;
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
  result.pNode = pCurrent;
  v16 = pCurrent;
  if ( pCurrent )
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, val);
  if ( this )
    this = (Scaleform::GFx::AS2::XmlObject *)((char *)this + 32);
  v7 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onData");
  v8 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( this )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v13 = 1;
    v14 = v8;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      (Scaleform::GFx::AS2::ObjectInterface *)this,
      v7,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = penv->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
  if ( val->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(val);
}

// File Line: 452
// RVA: 0x703DB0
void __fastcall Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        bool success)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  Scaleform::GFx::ASString *v11; // rax
  int v12; // r8d
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::Value v15; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::Value *v17; // [rsp+88h] [rbp+10h]
  char v18; // [rsp+90h] [rbp+18h] BYREF

  v18 = 2;
  v15.T.Type = 2;
  v15.V.BooleanValue = success;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "loaded");
  v7 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v7->vfptr->SetMemberRaw(v7, &penv->StringContext, v6, &v15, (Scaleform::GFx::AS2::PropFlags *)&v18);
  pNode = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v15.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = penv->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
  v17 = pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 2;
    pCurrent->V.BooleanValue = success;
  }
  v11 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoad");
  v12 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    *(_QWORD *)&v15.T.Type = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v15.NV.Int32Value = 1;
    HIDWORD(v15.NV.NumberValue) = v12;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v7,
      v11,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&v15);
    *(_QWORD *)&v15.T.Type = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v13 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = penv->Stack.pCurrent;
  if ( v14->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v14);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
}

// File Line: 494
// RVA: 0x6CE280
void __fastcall Scaleform::GFx::AS2::XmlProto::XmlProto(
        Scaleform::GFx::AS2::XmlProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString v26; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h] BYREF
  __int64 v28; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+28h] BYREF

  v28 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlObject::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlObject::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::XmlProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "application/x-www-form-urlencoded");
  val.T.Type = 5;
  val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
  ++val.V.pStringNode->RefCount;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v26, "contentType");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v7,
    &val,
    &flags);
  pNode = v26.pNode;
  v9 = v26.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  flags.Flags = 2;
  val.T.Type = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "docTypeDecl");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v11,
    &val,
    &flags);
  v12 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "idMap");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v13,
    &val,
    &flags);
  v14 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 2;
  val.V.BooleanValue = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "ignoreWhite");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v15,
    &val,
    &flags);
  v16 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "loaded");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v17,
    &val,
    &flags);
  v18 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "status");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v19,
    &val,
    &flags);
  v20 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "xmlDecl");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v21,
    &val,
    &flags);
  v22 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 1;
  val.T.Type = 8;
  result.pNode = (Scaleform::GFx::ASStringNode *)psc->pContext->pHeap;
  v23 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, __int64))result.pNode->pData
                                         + 10))(
                                          v22,
                                          104i64);
  v26.pNode = v23;
  if ( v23 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
      (Scaleform::GFx::AS2::CFunctionObject *)v23,
      psc,
      Scaleform::GFx::AS2::XmlProto::DefaultOnData);
  val.V.FunctionValue.Flags = 0;
  *(_OWORD *)&val.NV.Int32Value = (unsigned __int64)v23;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "onData");
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlObject::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v24,
    &val,
    &flags);
  v25 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( val.T.T

// File Line: 587
// RVA: 0x6E1DB0
void __fastcall Scaleform::GFx::AS2::XmlProto::DefaultOnData(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx

  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 28 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 616
// RVA: 0x6AB430
void __fastcall Scaleform::GFx::AS2::XmlProto::AddRequestHeader(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
      if ( v4 )
      {
        messageType.Id = 212992;
        Scaleform::Log::LogMessageById(
          v4,
          (Scaleform::LogMessageId)&messageType,
          "XML.addRequestHeader is not implemented.");
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 637
// RVA: 0x6AB4C0
void __fastcall Scaleform::GFx::AS2::XmlProto::CreateElement(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Environment *Env; // rbx
  Scaleform::GFx::AS2::Value *v6; // rdi
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Environment *v8; // rbx
  __int64 v9; // rax
  int v10; // edi
  Scaleform::GFx::AS2::Object *v11; // rbp
  Scaleform::GFx::AS2::Environment *v12; // rbx
  Scaleform::GFx::AS2::Value *v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  __int64 v20; // [rsp+68h] [rbp+10h]
  __int64 v21; // [rsp+70h] [rbp+18h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v6 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( ++Env->Stack.pCurrent >= Env->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&Env->Stack);
      pCurrent = Env->Stack.pCurrent;
      v20 = (__int64)pCurrent;
      v21 = (__int64)pCurrent;
      if ( pCurrent )
        Scaleform::GFx::AS2::Value::Value(pCurrent, v6);
      v8 = fn->Env;
      if ( ++v8->Stack.pCurrent >= v8->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
      v9 = (__int64)v8->Stack.pCurrent;
      v20 = v9;
      v21 = v9;
      if ( v9 )
      {
        *(_BYTE *)v9 = 4;
        *(_DWORD *)(v9 + 8) = 1;
      }
      Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &result, "XMLNode");
      v10 = 2;
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              fn->Env,
              fn->Env->StringContext.pContext->pGlobal.pObject,
              &result,
              2,
              -1);
      v20 = (__int64)v11;
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v11);
      v12 = fn->Env;
      v13 = v12->Stack.pCurrent;
      if ( &v13[-2] >= v12->Stack.pPageStart )
      {
        if ( v13->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v12->Stack.pCurrent);
        v15 = --v12->Stack.pCurrent;
        if ( v15->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v15);
        --v12->Stack.pCurrent;
      }
      else
      {
        do
        {
          v14 = v12->Stack.pCurrent;
          if ( v14->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v14);
          if ( --v12->Stack.pCurrent < v12->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
          --v10;
        }
        while ( v10 );
      }
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 662
// RVA: 0x6AB6D0
void __fastcall Scaleform::GFx::AS2::XmlProto::CreateTextNode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Environment *Env; // rbx
  Scaleform::GFx::AS2::Value *v6; // rdi
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Environment *v8; // rbx
  __int64 v9; // rax
  int v10; // edi
  Scaleform::GFx::AS2::Object *v11; // rbp
  Scaleform::GFx::AS2::Environment *v12; // rbx
  Scaleform::GFx::AS2::Value *v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  __int64 v20; // [rsp+68h] [rbp+10h]
  __int64 v21; // [rsp+70h] [rbp+18h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v6 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( ++Env->Stack.pCurrent >= Env->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&Env->Stack);
      pCurrent = Env->Stack.pCurrent;
      v20 = (__int64)pCurrent;
      v21 = (__int64)pCurrent;
      if ( pCurrent )
        Scaleform::GFx::AS2::Value::Value(pCurrent, v6);
      v8 = fn->Env;
      if ( ++v8->Stack.pCurrent >= v8->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
      v9 = (__int64)v8->Stack.pCurrent;
      v20 = v9;
      v21 = v9;
      if ( v9 )
      {
        *(_BYTE *)v9 = 4;
        *(_DWORD *)(v9 + 8) = 3;
      }
      Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &result, "XMLNode");
      v10 = 2;
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              fn->Env,
              fn->Env->StringContext.pContext->pGlobal.pObject,
              &result,
              2,
              -1);
      v20 = (__int64)v11;
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v11);
      v12 = fn->Env;
      v13 = v12->Stack.pCurrent;
      if ( &v13[-2] >= v12->Stack.pPageStart )
      {
        if ( v13->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v12->Stack.pCurrent);
        v15 = --v12->Stack.pCurrent;
        if ( v15->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v15);
        --v12->Stack.pCurrent;
      }
      else
      {
        do
        {
          v14 = v12->Stack.pCurrent;
          if ( v14->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v14);
          if ( --v12->Stack.pCurrent < v12->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
          --v10;
        }
        while ( v10 );
      }
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 687
// RVA: 0x6ABAC0
void __fastcall Scaleform::GFx::AS2::XmlProto::GetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  double v6; // xmm6_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
    {
      v4 = v3 - 2;
      if ( v4 )
      {
        Result = fn->Result;
        v6 = *(double *)&v4[7].vfptr;
        if ( v6 >= 0.0 )
        {
          if ( Result->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->NV.NumberValue = v6;
          Result->T.Type = 3;
        }
        else
        {
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 712
// RVA: 0x6ABBB0
void __fastcall Scaleform::GFx::AS2::XmlProto::GetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  double v6; // xmm6_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
    {
      v4 = v3 - 2;
      if ( v4 )
      {
        Result = fn->Result;
        v6 = *(double *)&v4[7].pProto.pObject;
        if ( v6 >= 0.0 )
        {
          if ( Result->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->NV.NumberValue = v6;
          Result->T.Type = 3;
        }
        else
        {
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 735
// RVA: 0x6ABCB0
void __fastcall Scaleform::GFx::AS2::XmlProto::Load(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::MemoryHeap *v12; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::XML::ObjectManager *v16; // rax
  Scaleform::GFx::XML::ObjectManager *v17; // rbx
  Scaleform::GFx::ExternalLibPtr *v18; // rax
  Scaleform::GFx::XML::SupportBase *pObject; // r14
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // di
  Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *v23; // rax
  Scaleform::GFx::AS2::XMLFileLoader *v24; // rax
  Scaleform::GFx::AS2::XMLFileLoader *v25; // r14
  Scaleform::GFx::AS2::Value *v26; // rdi
  Scaleform::GFx::AS2::XMLFileLoader *v27; // rdi
  Scaleform::GFx::AS2::Value *v28; // rbx
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS2::FunctionRef v37; // [rsp+30h] [rbp-99h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> v38; // [rsp+48h] [rbp-81h] BYREF
  Scaleform::GFx::ASString v39; // [rsp+50h] [rbp-79h] BYREF
  Scaleform::GFx::ASString v40; // [rsp+58h] [rbp-71h] BYREF
  Scaleform::GFx::AS2::Value v41; // [rsp+60h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::Value v42; // [rsp+80h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value v43; // [rsp+A0h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::XMLFileLoader *v44; // [rsp+C0h] [rbp-9h]
  Scaleform::GFx::AS2::XMLFileLoader *v45; // [rsp+C8h] [rbp-1h]
  __int64 v46; // [rsp+D0h] [rbp+7h]
  Scaleform::GFx::AS2::XMLFileLoader *v47; // [rsp+D8h] [rbp+Fh]
  Scaleform::MemoryHeap *pHeap; // [rsp+130h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh] BYREF
  Scaleform::GFx::XML::ObjectManager *v50; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::ASString v51; // [rsp+148h] [rbp+7Fh] BYREF

  v46 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 28 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
    return;
  }
  v3 = fn->ThisPtr;
  if ( v3 )
  {
    v4 = (Scaleform::GFx::AS2::Object *)&v3[-2];
    if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      if ( !fn->NArgs )
      {
        v5 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v5);
        v5->T.Type = 2;
        v5->V.BooleanValue = 0;
        return;
      }
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
      v42.T.Type = 0;
      v9 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &v51, "onData");
      v4->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
        &v4->Scaleform::GFx::AS2::ObjectInterface,
        fn->Env,
        v9,
        &v42);
      pNode = v51.pNode;
      v11 = v51.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS2::Value::ToFunction(&v42, &v37, fn->Env);
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *))v37.Function->vfptr[4].Finalize_GC)(v37.Function) )
      {
        if ( Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *))v37.Function->vfptr[4].Finalize_GC)(v37.Function)
            && (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v37.Function[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
          {
            goto LABEL_17;
          }
        }
        else if ( (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v37.Function == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
LABEL_17:
          pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
          v50 = 0i64;
          pXMLObjectManager = pMovieImpl->pXMLObjectManager;
          if ( pXMLObjectManager )
          {
            v17 = (Scaleform::GFx::XML::ObjectManager *)&pXMLObjectManager[-1];
            if ( v17 )
              ++v17->RefCount;
            v50 = v17;
          }
          else
          {
            pHeap = fn->Env->StringContext.pContext->pHeap;
            v15 = (Scaleform::GFx::ASStringNode *)pHeap->vfptr->Alloc(v12, 120ui64, 0i64);
            v51.pNode = v15;
            if ( v15 )
            {
              Scaleform::GFx::XML::ObjectManager::ObjectManager((Scaleform::GFx::XML::ObjectManager *)v15, pMovieImpl);
              v17 = v16;
            }
            else
            {
              v17 = 0i64;
            }
            v50 = v17;
            v18 = &v17->Scaleform::GFx::ExternalLibPtr;
            if ( !v17 )
              v18 = 0i64;
            pMovieImpl->pXMLObjectManager = v18;
          }
          pObject = Scaleform::GFx::StateBag::GetXMLSupport(&pMovieImpl->Scaleform::GFx::StateBag, &v38)->pObject;
          if ( v38.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38.pObject);
          v4[1].pPrev = 0i64;
          v41.T.Type = 0;
          v20 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &v39, "ignoreWhite");
          v4->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
            &v4->Scaleform::GFx::AS2::ObjectInterface,
            fn->Env,
            v20,
            &v41);
          v21 = v39.pNode;
          v11 = v39.pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          v22 = Scaleform::GFx::AS2::Value::ToBool(&v41, fn->Env);
          v23 = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                     Scaleform::Memory::pGlobalHeap,
                                                                     48i64);
          pHeap = (Scaleform::MemoryHeap *)v23;
          if ( v23 )
          {
            Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(v23, pObject, v17, v22);
            v25 = v24;
          }
          else
          {
            v25 = 0i64;
          }
          v47 = v25;
          Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(
            (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
            v4,
            v25,
            result.pNode->pData,
            LM_None);
          v26 = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v26);
          v26->T.Type = 2;
          v26->V.BooleanValue = 1;
          if ( v25 )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25);
          if ( v41.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v41);
          if ( v17 )
            Scaleform::RefCountNTSImpl::Release(v17);
LABEL_45:
          LOBYTE(pHeap) = 2;
          v43.T.Type = 2;
          v43.V.BooleanValue = 0;
          v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&fn->Env->StringContext, &v40, "loaded");
          v4->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
            &v4->Scaleform::GFx::AS2::ObjectInterface,
            &fn->Env->StringContext,
            v29,
            &v43,
            (Scaleform::GFx::AS2::PropFlags *)&pHeap);
          v30 = v40.pNode;
          v11 = v40.pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
          if ( v43.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v43);
          Flags = v37.Flags;
          if ( (v37.Flags & 2) == 0 )
          {
            Function = v37.Function;
            if ( v37.Function )
            {
              RefCount = v37.Function->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v37.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                Flags = v37.Flags;
              }
            }
          }
          v37.Function = 0i64;
          if ( (Flags & 1) == 0 )
          {
            pLocalFrame = v37.pLocalFrame;
            if ( v37.pLocalFrame )
            {
              v35 = v37.pLocalFrame->RefCount;
              if ( (v35 & 0x3FFFFFF) != 0 )
              {
                v37.pLocalFrame->RefCount = v35 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          v37.pLocalFrame = 0i64;
          if ( v42.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v42);
          v36 = result.pNode;
          v11 = result.pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          return;
        }
      }
      v27 = (Scaleform::GFx::AS2::XMLFileLoader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    32i64);
      v44 = v27;
      if ( v27 )
      {
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
        v27->RefCount = 1;
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,326>::`vftable;
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::XMLFileLoader,326>::`vftable;
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoader::`vftable;
        v27->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoaderImpl::`vftable;
        v27[1].vfptr = 0i64;
        v27[1].RefCount = 0;
      }
      else
      {
        v27 = 0i64;
      }
      v45 = v27;
      Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        v4,
        v27,
        result.pNode->pData,
        LM_None);
      v28 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v28);
      v28->T.Type = 2;
      v28->V.BooleanValue = 1;
      if ( v27 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v27);
      goto LABEL_45;
    }
  }
}

// File Line: 817
// RVA: 0x6AC3A0
void __fastcall Scaleform::GFx::AS2::XmlProto::ParseXML(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::XmlObject *v4; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rbp
  __int64 v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::XML::ElementNode *i; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v17; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::Object *v20; // [rsp+90h] [rbp+18h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
    {
      v4 = (Scaleform::GFx::AS2::XmlObject *)&v3[-2];
      if ( v4 )
      {
        Scaleform::GFx::AS2::XML_LoadString(fn, v4);
        Env = fn->Env;
        pHeap = Env->StringContext.pContext->pHeap;
        v7 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v6, 96i64);
        result.pNode = v7;
        if ( v7 )
        {
          Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, Env);
          v9 = v8;
        }
        else
        {
          v9 = 0i64;
        }
        v20 = v9;
        for ( i = v4->pRealNode[1].Parent; i; i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
        {
          if ( i->Type == 1 )
            Scaleform::GFx::AS2::Xml_CreateIDMap(Env, i, v4->pRootNode.pObject, v9);
        }
        LOBYTE(pHeap) = 2;
        Scaleform::GFx::AS2::Value::Value(&v17, v9);
        v12 = v11;
        v13 = Scaleform::GFx::AS2::Environment::CreateConstString(Env, &result, "idMap");
        v4->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          Env,
          v13,
          v12,
          (Scaleform::GFx::AS2::PropFlags *)&pHeap);
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v17.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v17);
        if ( v9 )
        {
          RefCount = v9->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v9->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 849
// RVA: 0x6AC730
void __fastcall Scaleform::GFx::AS2::XmlProto::Send(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
      if ( v4 )
      {
        messageType.Id = 212992;
        Scaleform::Log::LogMessageById(v4, (Scaleform::LogMessageId)&messageType, "XML.send is not implemented.");
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 868
// RVA: 0x6AC990
void __fastcall Scaleform::GFx::AS2::XmlProto::SendAndLoad(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
      if ( v4 )
      {
        messageType.Id = 212992;
        Scaleform::Log::LogMessageById(v4, (Scaleform::LogMessageId)&messageType, "XML.sendAndLoad is not implemented.");
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 901
// RVA: 0x6FA980
void __fastcall Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::XmlObject *v2; // rbx
  Scaleform::MemoryHeap *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::XmlObject *v5; // rax
  Scaleform::GFx::AS2::XmlObject *v6; // rax
  unsigned int RefCount; // eax

  v2 = 0i64;
  ThisPtr = (Scaleform::MemoryHeap *)fn->ThisPtr;
  if ( ThisPtr && (*(unsigned int (__fastcall **)(Scaleform::MemoryHeap *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 28 )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
    {
      v2 = (Scaleform::GFx::AS2::XmlObject *)&v4[-2];
      if ( v4 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
        v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    }
  }
  else
  {
    v5 = (Scaleform::GFx::AS2::XmlObject *)fn->Env->StringContext.pContext->pHeap->vfptr->Alloc(ThisPtr, 128i64, 0i64);
    if ( v5 )
    {
      Scaleform::GFx::AS2::XmlObject::XmlObject(v5, fn->Env);
      v2 = v6;
    }
  }
  Scaleform::GFx::AS2::XML_LoadString(fn, v2);
  if ( v2 )
  {
    RefCount = v2->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
}

// File Line: 912
// RVA: 0x6E0960
void __fastcall Scaleform::GFx::AS2::XmlCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::XmlCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::XmlObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::XmlObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(this, 128i64, 0i64);
  if ( v3 )
    Scaleform::GFx::AS2::XmlObject::XmlObject(v3, penv);
}

// File Line: 917
// RVA: 0x70F690
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::XmlCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  char v5; // al
  int v6; // edx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v10; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int v12; // eax
  Scaleform::GFx::AS2::XmlProto *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rbx
  Scaleform::GFx::AS2::Object *v17; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v20; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value resulta[2]; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::ASString className; // [rsp+B8h] [rbp+48h] BYREF
  void *p_className; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::ASString *v26; // [rsp+C8h] [rbp+58h]

  p_className = &className;
  className.pNode = (Scaleform::GFx::ASStringNode *)pgc->pMovieRoot->pASMovieRoot.pObject[12].pASSupport.pObject;
  ++className.pNode->RefCount;
  if ( !Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(pgc, (Scaleform::GFx::ASString)&className) )
  {
    Scaleform::GFx::AS2::XmlNodeCtorFunction::Register((Scaleform::GFx::AS2::FunctionRef *)resulta, pgc);
    v5 = *((_BYTE *)&resulta[0].NV + 16);
    if ( (*(_BYTE *)(&resulta[0].NV + 1) & 2) == 0 )
    {
      pStringNode = *(Scaleform::GFx::ASStringNode **)&resulta[0].T.Type;
      if ( *(_QWORD *)&resulta[0].T.Type )
      {
        v6 = *(_DWORD *)(*(_QWORD *)&resulta[0].T.Type + 24i64);
        if ( (v6 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*(_QWORD *)&resulta[0].T.Type + 24i64) = v6 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
          v5 = *((_BYTE *)&resulta[0].NV + 16);
        }
      }
    }
    *(_QWORD *)&resulta[0].T.Type = 0i64;
    if ( (v5 & 1) == 0 )
    {
      pStringNode = resulta[0].V.pStringNode;
      if ( resulta[0].V.pStringNode )
      {
        RefCount = resulta[0].V.pStringNode->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          resulta[0].V.pStringNode->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
  }
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  p_className = pgc->pHeap;
  v8 = (Scaleform::GFx::AS2::Object *)(*(__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, __int64))(*(_QWORD *)p_className + 80i64))(
                                        pStringNode,
                                        104i64);
  v10 = (Scaleform::GFx::AS2::FunctionObject *)v8;
  v26 = (Scaleform::GFx::ASString *)v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::Object::Object(v8, &psc);
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v10->pProto.pObject )
    {
      LOBYTE(className.pNode) = 3;
      resulta[0].T.Type = 10;
      v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v10->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        resulta,
        (Scaleform::GFx::AS2::PropFlags *)&className);
      if ( resulta[0].T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(resulta);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v10->pProto.pObject;
    if ( pObject )
    {
      v12 = pObject->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v10->pProto.pObject = Prototype;
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v10 = 0i64;
  }
  result->Flags = 0;
  result->Function = v10;
  result->pLocalFrame = 0i64;
  className.pNode = (Scaleform::GFx::ASStringNode *)pgc->pHeap;
  v13 = (Scaleform::GFx::AS2::XmlProto *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))className.pNode->pData
                                          + 10))(
                                           pObject,
                                           192i64,
                                           0i64);
  p_className = v13;
  if ( v13 )
  {
    v14 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_XMLNode);
    Scaleform::GFx::AS2::XmlProto::XmlProto(v13, &psc, v14, result);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  p_className = v16;
  v26 = &className;
  if ( v16 )
    v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
  className.pNode = v16;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_XML,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&className);
  v17 = pgc->pGlobal.pObject;
  resulta[0].T.Type = 8;
  resulta[0].V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  resulta[0].V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  resulta[0].V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&resulta[0].V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(className.pNode) = 0;
  v17->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v17->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl,
    resulta,
    (Scaleform::GFx::AS2::PropFlags *)&className);
  if ( resulta[0].T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(resulta);
  if ( v16 )
  {
    v20 = v16->RefCount;
    if ( (v20 & 0x3FFFFFF) != 0 )
    {
      v16->RefCount = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v16);
    }
  }
  return result;
}

