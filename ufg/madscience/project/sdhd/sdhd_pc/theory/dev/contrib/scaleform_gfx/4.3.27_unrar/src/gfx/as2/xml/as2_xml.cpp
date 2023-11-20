// File Line: 78
// RVA: 0x6CDB00
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this, Scaleform::GFx::XML::SupportBase *pparser, Scaleform::GFx::XML::ObjectManager *objMgr, bool ignorews)
{
  bool v4; // si
  Scaleform::GFx::XML::ObjectManager *v5; // rbp
  Scaleform::GFx::XML::SupportBase *v6; // rdi
  Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *v7; // rbx

  v4 = ignorews;
  v5 = objMgr;
  v6 = pparser;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::XMLFileLoader,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoader::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::`vftable;
  if ( pparser )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pparser);
  v7->pParser.pObject = v6;
  v7->pObjectManager = v5;
  v7->pFileData = 0i64;
  v7->FileLength = 0;
  v7->bIgnoreWhitespace = v4;
}

// File Line: 90
// RVA: 0x701250
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::Load(Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this, Scaleform::String *filename, Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::GFx::FileOpener *v3; // r14
  Scaleform::String *v4; // rsi
  Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rbx
  __int64 v7; // rax
  int v8; // eax
  char *v9; // rax
  __int64 v10; // [rsp+30h] [rbp-28h]
  __int64 v11; // [rsp+38h] [rbp-20h]
  __int64 v12; // [rsp+40h] [rbp-18h]

  v3 = pfo;
  v4 = filename;
  v5 = this;
  v6 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  if ( !Scaleform::GFx::URLBuilder::IsProtocol(filename) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, signed __int64, signed __int64, signed __int64, __int64 *))v3->vfptr[1].__vecDelDtor)(
           v3,
           (v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
           33i64,
           438i64,
           -2i64,
           &v10);
    v6 = (Scaleform::Render::RenderBuffer *)v7;
    if ( v7 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
      {
        v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *))v6->vfptr[6].__vecDelDtor)(v6);
        v5->FileLength = v8;
        if ( v8 )
        {
          v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8, 0i64);
          v5->pFileData = v9;
          ((void (__fastcall *)(Scaleform::Render::RenderBuffer *, char *, _QWORD))v6->vfptr[10].__vecDelDtor)(
            v6,
            v9,
            (unsigned int)v5->FileLength);
        }
      }
    }
  }
  if ( v10 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v10);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 123
// RVA: 0x6FCC50
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::InitASXml(Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *pTarget)
{
  Scaleform::GFx::AS2::Object *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // r14
  Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *v5; // rbx
  Scaleform::GFx::Resource *v6; // rcx
  Scaleform::GFx::XML::SupportBase *v7; // rax
  Scaleform::GFx::XML::Document *v8; // rdx
  Scaleform::GFx::XML::RootNode *v9; // r15
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  unsigned int v13; // eax
  double v14; // xmm0_8
  bool v15; // r8
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  double v19; // xmm0_8
  double v20; // xmm1_8
  Scaleform::GFx::AS2::Value v21; // [rsp+30h] [rbp-D0h]
  __int64 v22; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::XML::DOMBuilder v23; // [rsp+60h] [rbp-A0h]
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser; // [rsp+150h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::XML::Document> result; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::ASString v26; // [rsp+168h] [rbp+68h]

  v22 = -2i64;
  v3 = pTarget;
  v4 = penv;
  v5 = this;
  if ( this->pFileData )
  {
    v26.pNode = (Scaleform::GFx::ASStringNode *)&pxmlParser;
    v6 = (Scaleform::GFx::Resource *)this->pParser.pObject;
    if ( v6 )
      Scaleform::Render::RenderBuffer::AddRef(v6);
    pxmlParser.pObject = v5->pParser.pObject;
    Scaleform::GFx::XML::DOMBuilder::DOMBuilder(
      &v23,
      (Scaleform::Ptr<Scaleform::GFx::XML::SupportBase>)&pxmlParser,
      v5->bIgnoreWhitespace);
    v26.pNode = (Scaleform::GFx::ASStringNode *)&pxmlParser;
    v7 = (Scaleform::GFx::XML::SupportBase *)v5->pObjectManager;
    if ( v7 )
      ++v7->RefCount;
    pxmlParser.pObject = v7;
    Scaleform::GFx::XML::DOMBuilder::ParseString(
      &v23,
      &result,
      v5->pFileData,
      v5->FileLength,
      (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)&pxmlParser);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5->pFileData);
    v5->pFileData = 0i64;
    v8 = result.pObject;
    v3[1].pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)result.pObject;
    v9 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v5->pObjectManager, (Scaleform::GFx::XML::Node *)&v8->vfptr);
    v10 = (Scaleform::RefCountNTSImpl *)v3[1].vfptr;
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    v3[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)v9;
    pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)v5->pObjectManager->pHeap;
    v11 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)v10,
                                            24u);
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
    v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11->pLower;
    if ( v12 )
    {
      v13 = v12->RefCount;
      if ( v13 & 0x3FFFFFF )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
      }
    }
    v11->pLower = 0i64;
    v11->pManager = (Scaleform::GFx::ASStringManager *)v3;
    result.pObject->pShadow = (Scaleform::GFx::XML::ShadowRefBase *)v11;
    Scaleform::GFx::AS2::XmlObject::AssignXMLDecl((Scaleform::GFx::AS2::XmlObject *)v3, v4, result.pObject);
    if ( !v23.bError || v23.TotalBytesToLoad )
    {
      LOBYTE(pxmlParser.pObject) = 2;
      v21.T.Type = 2;
      v21.V.BooleanValue = 1;
      v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v4->StringContext, &v26, "loaded");
      v3->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
        &v4->StringContext,
        v16,
        &v21,
        (Scaleform::GFx::AS2::PropFlags *)&pxmlParser);
      v17 = v26.pNode;
      v18 = v26.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      v19 = (double)SLODWORD(v23.LoadedBytes);
      if ( (v23.LoadedBytes & 0x8000000000000000ui64) != 0i64 )
        v19 = v19 + 1.844674407370955e19;
      *(double *)&v3[1].16 = v19;
      v20 = (double)SLODWORD(v23.TotalBytesToLoad);
      if ( (v23.TotalBytesToLoad & 0x8000000000000000ui64) != 0i64 )
        v20 = v20 + 1.844674407370955e19;
      *(double *)&v3[1].RefCount = v20;
      v15 = 1;
    }
    else
    {
      v14 = (double)SLODWORD(v23.LoadedBytes);
      if ( (v23.LoadedBytes & 0x8000000000000000ui64) != 0i64 )
        v14 = v14 + 1.844674407370955e19;
      *(double *)&v3[1].16 = v14;
      *(_QWORD *)&v3[1].RefCount = -4616189618054758400i64;
      v15 = 0;
    }
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad((Scaleform::GFx::AS2::XmlObject *)v3, v4, v15);
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v23);
  }
  else
  {
    pTarget[1].pPrev = 0i64;
    *(_QWORD *)&pTarget[1].RefCount = -4616189618054758400i64;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad((Scaleform::GFx::AS2::XmlObject *)pTarget, penv, 0);
  }
}

// File Line: 217
// RVA: 0x701360
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderImpl::Load(Scaleform::GFx::AS2::XMLFileLoaderImpl *this, Scaleform::String *filename, Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::GFx::FileOpener *v3; // r14
  Scaleform::String *v4; // rsi
  Scaleform::GFx::AS2::XMLFileLoaderImpl *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rbx
  __int64 v7; // rax
  int v8; // eax
  char *v9; // rax
  __int64 v10; // [rsp+30h] [rbp-28h]
  __int64 v11; // [rsp+38h] [rbp-20h]
  __int64 v12; // [rsp+40h] [rbp-18h]

  v3 = pfo;
  v4 = filename;
  v5 = this;
  v6 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  if ( !Scaleform::GFx::URLBuilder::IsProtocol(filename) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, signed __int64, signed __int64, signed __int64, __int64 *))v3->vfptr[1].__vecDelDtor)(
           v3,
           (v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
           33i64,
           438i64,
           -2i64,
           &v10);
    v6 = (Scaleform::Render::RenderBuffer *)v7;
    if ( v7 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
      {
        v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *))v6->vfptr[6].__vecDelDtor)(v6);
        v5->FileLength = v8;
        if ( v8 )
        {
          v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8, 0i64);
          v5->pFileData = v9;
          ((void (__fastcall *)(Scaleform::Render::RenderBuffer *, char *, _QWORD))v6->vfptr[10].__vecDelDtor)(
            v6,
            v9,
            (unsigned int)v5->FileLength);
        }
      }
    }
  }
  if ( v10 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v10);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 250
// RVA: 0x6FCF00
void __fastcall Scaleform::GFx::AS2::XMLFileLoaderImpl::InitASXml(Scaleform::GFx::AS2::XMLFileLoaderImpl *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *pTarget)
{
  Scaleform::GFx::AS2::XmlObject *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::AS2::XMLFileLoaderImpl *v5; // rbx
  char *v6; // r8
  __int64 *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char v10; // [rsp+28h] [rbp-30h]
  __int64 v11; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  char *v13; // [rsp+70h] [rbp+18h]

  v3 = (Scaleform::GFx::AS2::XmlObject *)pTarget;
  v4 = penv;
  v5 = this;
  v6 = this->pFileData;
  if ( v6 )
  {
    v13 = &v10;
    v7 = (__int64 *)Scaleform::GFx::AS2::Environment::CreateString(penv, &result, v6, this->FileLength);
    v10 = 5;
    v11 = *v7;
    ++*(_DWORD *)(v11 + 24);
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(v3, v4, (Scaleform::GFx::AS2::Value *)&v10);
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5->pFileData);
    v5->pFileData = 0i64;
  }
  else
  {
    result.pNode = (Scaleform::GFx::ASStringNode *)&v10;
    v10 = 0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(v3, penv, (Scaleform::GFx::AS2::Value *)&v10);
  }
}

// File Line: 279
// RVA: 0x724730
void __fastcall Scaleform::GFx::AS2::XML_LoadString(Scaleform::GFx::AS2::FnCall *fn, Scaleform::GFx::AS2::XmlObject *pnode)
{
  Scaleform::GFx::AS2::XmlObject *v2; // r13
  Scaleform::GFx::AS2::FnCall *v3; // r15
  __int64 v4; // rcx
  Scaleform::GFx::LogState *v5; // rsi
  Scaleform::GFx::MovieImpl *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // r14
  Scaleform::GFx::ExternalLibPtr *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rax
  signed __int64 v10; // rax
  signed __int64 v11; // rbx
  signed __int64 v12; // rax
  unsigned int v13; // er9
  Scaleform::GFx::AS2::Environment *v14; // rdx
  Scaleform::GFx::AS2::Value *v15; // r8
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::Ptr<Scaleform::GFx::XML::Document> *v17; // rax
  Scaleform::GFx::XML::Document *v18; // rdi
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::XML::DOMString *v21; // rax
  Scaleform::GFx::XML::RootNode *v22; // rsi
  Scaleform::RefCountNTSImpl *v23; // rcx
  Scaleform::RefCountImplCore *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rsi
  Scaleform::GFx::ASStringNode *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // rcx
  unsigned int v29; // eax
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> result; // [rsp+30h] [rbp-D0h]
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *v31; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS2::Value v32; // [rsp+40h] [rbp-C0h]
  __int64 v33; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::XML::DOMBuilder v34; // [rsp+70h] [rbp-90h]
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser; // [rsp+170h] [rbp+70h]
  __int64 v36; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::ASString v37; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::XML::Document *v38; // [rsp+188h] [rbp+88h]

  v33 = -2i64;
  v2 = pnode;
  v3 = fn;
  v5 = (Scaleform::GFx::LogState *)((__int64 (*)(void))fn->Env->Target->vfptr[76].__vecDelDtor)();
  v6 = v3->Env->Target->pASRoot->pMovieImpl;
  v7 = 0i64;
  v36 = 0i64;
  v8 = v6->pXMLObjectManager;
  if ( v8 )
  {
    v11 = (signed __int64)&v8[-1];
    if ( v11 )
      ++*(_DWORD *)(v11 + 8);
    v36 = v11;
  }
  else
  {
    pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)v3->Env->StringContext.pContext->pHeap;
    v9 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))pxmlParser.pObject->vfptr[10].__vecDelDtor)(
                                           v4,
                                           120i64,
                                           0i64);
    v37.pNode = v9;
    if ( v9 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager((Scaleform::GFx::XML::ObjectManager *)v9, v6);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    v36 = v11;
    v12 = v11 + 16;
    if ( !v11 )
      v12 = 0i64;
    v6->pXMLObjectManager = (Scaleform::GFx::ExternalLibPtr *)v12;
  }
  v38 = 0i64;
  v32.T.Type = 0;
  if ( v3->NArgs <= 0 )
    goto LABEL_29;
  v13 = v3->FirstArgBottomIndex;
  v14 = v3->Env;
  v15 = 0i64;
  if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
            + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
    v15 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
  Scaleform::GFx::AS2::Value::operator=(&v32, v15, (__int64)v6);
  v16 = (Scaleform::GFx::Resource *)Scaleform::GFx::StateBag::GetXMLSupport(
                                      (Scaleform::GFx::StateBag *)&v3->Env->Target->pASRoot->pMovieImpl->vfptr,
                                      &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !v16 )
  {
    if ( v5 )
    {
      LODWORD(pxmlParser.pObject) = 212992;
      Scaleform::Log::LogMessageById(v5, (Scaleform::LogMessageId)&pxmlParser, "No XML parser state set for movie!");
    }
    goto LABEL_29;
  }
  v31 = &pxmlParser;
  Scaleform::Render::RenderBuffer::AddRef(v16);
  pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)v16;
  Scaleform::GFx::XML::DOMBuilder::DOMBuilder(&v34, (Scaleform::Ptr<Scaleform::GFx::XML::SupportBase>)&pxmlParser, 1);
  Scaleform::GFx::AS2::Value::ToString(&v32, &v37, v3->Env, -1);
  v31 = &pxmlParser;
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
  v18 = v17->pObject;
  v38 = v17->pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)result.pObject);
  Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(v2, v3->Env, v18);
  v19 = v37.pNode;
  v20 = v37.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v34);
  if ( !v18 )
  {
LABEL_29:
    v18 = Scaleform::GFx::XML::ObjectManager::CreateDocument((Scaleform::GFx::XML::ObjectManager *)v11);
    v38 = v18;
  }
  v21 = Scaleform::GFx::XML::ObjectManager::CreateString(
          (Scaleform::GFx::XML::ObjectManager *)v11,
          (Scaleform::GFx::XML::DOMString *)&pxmlParser,
          "null",
          4ui64);
  Scaleform::GFx::XML::DOMString::AssignNode(&v18->Value, v21->pNode);
  Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&pxmlParser);
  v2->pRealNode = (Scaleform::GFx::XML::Node *)&v18->vfptr;
  v22 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(
          (Scaleform::GFx::XML::ObjectManager *)v11,
          (Scaleform::GFx::XML::Node *)&v18->vfptr);
  v23 = (Scaleform::RefCountNTSImpl *)&v2->pRootNode.pObject->vfptr;
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
  v2->pRootNode.pObject = v22;
  pxmlParser.pObject = *(Scaleform::GFx::XML::SupportBase **)(v11 + 112);
  v25 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(
                                          (Scaleform::RefCountImplCore *)v23,
                                          24u);
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
  v18->pShadow = (Scaleform::GFx::XML::ShadowRefBase *)v25;
  pxmlParser.pObject = (Scaleform::GFx::XML::SupportBase *)v3->Env->StringContext.pContext->pHeap;
  v26 = (Scaleform::GFx::ASStringNode *)pxmlParser.pObject->vfptr[10].__vecDelDtor(v24, 112u);
  v37.pNode = v26;
  if ( v26 )
  {
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject((Scaleform::GFx::AS2::XmlNodeObject *)v26, v3->Env);
    v7 = v27;
  }
  v28 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v25->pLower;
  if ( v28 )
  {
    v29 = v28->RefCount;
    if ( v29 & 0x3FFFFFF )
    {
      v28->RefCount = v29 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
    }
  }
  v25->pLower = v7;
  v25->pManager = (Scaleform::GFx::ASStringManager *)v2;
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v18->vfptr);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v11);
}

// File Line: 334
// RVA: 0x6CE1B0
void __fastcall Scaleform::GFx::AS2::XmlObject::XmlObject(Scaleform::GFx::AS2::XmlObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbp
  Scaleform::GFx::AS2::XmlObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject((Scaleform::GFx::AS2::XmlNodeObject *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_XML);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
  v3->BytesLoadedCurrent = -1.0;
  v3->BytesLoadedTotal = -1.0;
  if ( v3 != (Scaleform::GFx::AS2::XmlObject *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      &v2->StringContext,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    &v2->StringContext,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    v2,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
}

// File Line: 361
// RVA: 0x6DAC00
void __fastcall Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(Scaleform::GFx::AS2::XmlObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::Document *pdoc)
{
  Scaleform::GFx::XML::Document *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::XmlObject *v5; // r14
  char *v6; // rdi
  const char *v7; // rdx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v10; // r10
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-19h]
  char *v15; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS2::Value v16; // [rsp+28h] [rbp-9h]
  Scaleform::StringBuffer v17; // [rsp+48h] [rbp+17h]
  char retaddr; // [rsp+A8h] [rbp+77h]
  Scaleform::GFx::ASString v19; // [rsp+B0h] [rbp+7Fh]

  v15 = (char *)-2i64;
  v3 = pdoc;
  v4 = penv;
  v5 = this;
  v6 = &customWorldMapCaption;
  Scaleform::StringBuffer::StringBuffer(
    (Scaleform::StringBuffer *)((char *)&v17 + 24),
    &customWorldMapCaption,
    Scaleform::Memory::pGlobalHeap);
  if ( v3 )
  {
    Scaleform::StringBuffer::AppendString(&v17, "<?", -1i64);
    if ( v3->XMLVersion.pNode->Size )
    {
      Scaleform::StringBuffer::AppendString(&v17, "xml version=\"", -1i64);
      Scaleform::StringBuffer::AppendString(&v17, v3->XMLVersion.pNode->pData, -1i64);
      Scaleform::StringBuffer::AppendString(&v17, "\"", -1i64);
    }
    if ( v3->Encoding.pNode->Size )
    {
      if ( v3->XMLVersion.pNode->Size )
        Scaleform::StringBuffer::AppendString(&v17, " ", -1i64);
      Scaleform::StringBuffer::AppendString(&v17, "encoding=\"", -1i64);
      Scaleform::StringBuffer::AppendString(&v17, v3->Encoding.pNode->pData, -1i64);
      Scaleform::StringBuffer::AppendString(&v17, "\"", -1i64);
    }
    if ( v3->Standalone != -1 )
    {
      if ( v3->XMLVersion.pNode->Size || v3->Encoding.pNode->Size )
        Scaleform::StringBuffer::AppendString(&v17, " ", -1i64);
      v7 = "standalone=\"yes\"";
      if ( !v3->Standalone )
        v7 = "standalone=\"no\"";
      Scaleform::StringBuffer::AppendString(&v17, v7, -1i64);
    }
    Scaleform::StringBuffer::AppendString(&v17, "?>", -1i64);
  }
  if ( v3->XMLVersion.pNode->Size || v3->Encoding.pNode->Size || v3->Standalone != -1 )
  {
    if ( v17.pData )
      v6 = v17.pData;
    v8 = Scaleform::GFx::AS2::ASStringContext::CreateString(&v4->StringContext, &result, v6, v17.Size);
    v16.T.Type = 5;
    v16.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++v16.V.pStringNode->RefCount;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v4->StringContext, &v19, "xmlDecl");
    retaddr = 0;
    v10 = v5->vfptr;
    v15 = &retaddr;
    v10->SetMember(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v4,
      v9,
      &v16,
      (Scaleform::GFx::AS2::PropFlags *)&retaddr);
    v11 = v19.pNode;
    v12 = v19.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
    v13 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v17);
}

// File Line: 405
// RVA: 0x703B20
void __fastcall Scaleform::GFx::AS2::XmlObject::NotifyOnData(Scaleform::GFx::AS2::XmlObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASString *v7; // rax
  int v8; // er8
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h]
  int v13; // [rsp+30h] [rbp-38h]
  int v14; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v16; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS2::Value *v17; // [rsp+80h] [rbp+18h]

  v17 = val;
  v3 = val;
  v4 = penv;
  v5 = (Scaleform::GFx::AS2::ObjectInterface *)this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v6 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v6;
  v16 = v6;
  if ( v6 )
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v6, v3, (__int64)v3);
  if ( v5 )
    v5 += 2;
  v7 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onData");
  v8 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v5 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v13 = 1;
    v14 = v8;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v4, v5, v7, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v11 = v4->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
}

// File Line: 452
// RVA: 0x703DB0
void __fastcall Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(Scaleform::GFx::AS2::XmlObject *this, Scaleform::GFx::AS2::Environment *penv, bool success)
{
  bool v3; // bp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::XmlObject *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  __int64 v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  int v12; // er8
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::Value v15; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]
  __int64 v17; // [rsp+88h] [rbp+10h]
  char v18; // [rsp+90h] [rbp+18h]

  v3 = success;
  v4 = penv;
  v5 = this;
  v18 = 2;
  v15.T.Type = 2;
  v15.V.BooleanValue = success;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "loaded");
  v7 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
  v7->vfptr->SetMemberRaw(v7, &v4->StringContext, v6, &v15, (Scaleform::GFx::AS2::PropFlags *)&v18);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v15.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  ++v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent >= v4->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
  v10 = (__int64)v4->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)v10;
  v17 = v10;
  if ( v10 )
  {
    *(_BYTE *)v10 = 2;
    *(_BYTE *)(v10 + 8) = v3;
  }
  v11 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onLoad");
  v12 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    *(_QWORD *)&v15.T.Type = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v15.NV.Int32Value = 1;
    HIDWORD(v15.NV.NumberValue) = v12;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v4,
      v7,
      v11,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&v15);
    *(_QWORD *)&v15.T.Type = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v13 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = v4->Stack.pCurrent;
  if ( v14->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v14);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
}

// File Line: 494
// RVA: 0x6CE280
void __fastcall Scaleform::GFx::AS2::XmlProto::XmlProto(Scaleform::GFx::AS2::XmlProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *prototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::XmlProto *v5; // rsi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
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
  Scaleform::GFx::ASString v26; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h]
  __int64 v28; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value val; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+28h]

  v28 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    prototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::XmlProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "application/x-www-form-urlencoded");
  val.T.Type = 5;
  val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
  ++val.V.pStringNode->RefCount;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v26, "contentType");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v7, &val, &flags);
  v8 = v26.pNode;
  v9 = v26.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  flags.Flags = 2;
  val.T.Type = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "docTypeDecl");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v11, &val, &flags);
  v12 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "idMap");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v13, &val, &flags);
  v14 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 2;
  val.V.BooleanValue = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "ignoreWhite");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v15, &val, &flags);
  v16 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "loaded");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v17, &val, &flags);
  v18 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "status");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v19, &val, &flags);
  v20 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "xmlDecl");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v21, &val, &flags);
  v22 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 1;
  val.T.Type = 8;
  result.pNode = (Scaleform::GFx::ASStringNode *)v4->pContext->pHeap;
  v23 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, signed __int64))result.pNode->pData
                                         + 10))(
                                          v22,
                                          104i64);
  v26.pNode = v23;
  if ( v23 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
      (Scaleform::GFx::AS2::CFunctionObject *)v23,
      v4,
      Scaleform::GFx::AS2::XmlProto::DefaultOnData);
  val.V.FunctionValue.Flags = 0;
  *(_OWORD *)&val.NV.Int32Value = (unsigned __int64)v23;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "onData");
  v5->vfptr->SetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr, v4, v24, &val, &flags);
  v25 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 587
// RVA: 0x6E1DB0
void __fastcall Scaleform::GFx::AS2::XmlProto::DefaultOnData(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2 || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 28 )
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
}

// File Line: 616
// RVA: 0x6AB430
void __fastcall Scaleform::GFx::AS2::XmlProto::AddRequestHeader(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
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
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 637
// RVA: 0x6AB4C0
void __fastcall Scaleform::GFx::AS2::XmlProto::CreateElement(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  unsigned int v4; // edx
  Scaleform::GFx::AS2::Environment *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rcx
  Scaleform::GFx::AS2::Environment *v8; // rbx
  __int64 v9; // rax
  signed int v10; // edi
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rbp
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  __int64 v21; // [rsp+68h] [rbp+10h]
  __int64 v22; // [rsp+70h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = v1->FirstArgBottomIndex;
      v5 = v1->Env;
      v6 = 0i64;
      if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
        v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
      ++v5->Stack.pCurrent;
      if ( v5->Stack.pCurrent >= v5->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v5->Stack);
      v7 = v5->Stack.pCurrent;
      v21 = (__int64)v7;
      v22 = (__int64)v7;
      if ( v7 )
        Scaleform::GFx::AS2::Value::Value(v7, v6);
      v8 = v1->Env;
      ++v8->Stack.pCurrent;
      if ( v8->Stack.pCurrent >= v8->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
      v9 = (__int64)v8->Stack.pCurrent;
      v21 = v9;
      v22 = v9;
      if ( v9 )
      {
        *(_BYTE *)v9 = 4;
        *(_DWORD *)(v9 + 8) = 1;
      }
      Scaleform::GFx::AS2::Environment::CreateConstString(v1->Env, &result, "XMLNode");
      v10 = 2;
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              v1->Env,
              v1->Env->StringContext.pContext->pGlobal.pObject,
              &result,
              2,
              -1);
      v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr;
      v21 = (__int64)v11;
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v11);
      v13 = v1->Env;
      v14 = v13->Stack.pCurrent;
      if ( &v14[-2] >= v13->Stack.pPageStart )
      {
        if ( v14->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v13->Stack.pCurrent);
        --v13->Stack.pCurrent;
        v16 = v13->Stack.pCurrent;
        if ( v16->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v16);
        --v13->Stack.pCurrent;
      }
      else
      {
        do
        {
          v15 = v13->Stack.pCurrent;
          if ( v15->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v15);
          --v13->Stack.pCurrent;
          if ( v13->Stack.pCurrent < v13->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
          --v10;
        }
        while ( v10 );
      }
      if ( v12 )
      {
        v17 = v12->RefCount;
        if ( v17 & 0x3FFFFFF )
        {
          v12->RefCount = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
        }
      }
      v18 = result.pNode;
      v19 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}or(
      v1->Env,
      "Error: Null or invalid this

// File Line: 662
// RVA: 0x6AB6D0
void __fastcall Scaleform::GFx::AS2::XmlProto::CreateTextNode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  unsigned int v4; // edx
  Scaleform::GFx::AS2::Environment *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rcx
  Scaleform::GFx::AS2::Environment *v8; // rbx
  __int64 v9; // rax
  signed int v10; // edi
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rbp
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  __int64 v21; // [rsp+68h] [rbp+10h]
  __int64 v22; // [rsp+70h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = v1->FirstArgBottomIndex;
      v5 = v1->Env;
      v6 = 0i64;
      if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
        v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
      ++v5->Stack.pCurrent;
      if ( v5->Stack.pCurrent >= v5->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v5->Stack);
      v7 = v5->Stack.pCurrent;
      v21 = (__int64)v7;
      v22 = (__int64)v7;
      if ( v7 )
        Scaleform::GFx::AS2::Value::Value(v7, v6);
      v8 = v1->Env;
      ++v8->Stack.pCurrent;
      if ( v8->Stack.pCurrent >= v8->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
      v9 = (__int64)v8->Stack.pCurrent;
      v21 = v9;
      v22 = v9;
      if ( v9 )
      {
        *(_BYTE *)v9 = 4;
        *(_DWORD *)(v9 + 8) = 3;
      }
      Scaleform::GFx::AS2::Environment::CreateConstString(v1->Env, &result, "XMLNode");
      v10 = 2;
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              v1->Env,
              v1->Env->StringContext.pContext->pGlobal.pObject,
              &result,
              2,
              -1);
      v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr;
      v21 = (__int64)v11;
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v11);
      v13 = v1->Env;
      v14 = v13->Stack.pCurrent;
      if ( &v14[-2] >= v13->Stack.pPageStart )
      {
        if ( v14->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v13->Stack.pCurrent);
        --v13->Stack.pCurrent;
        v16 = v13->Stack.pCurrent;
        if ( v16->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v16);
        --v13->Stack.pCurrent;
      }
      else
      {
        do
        {
          v15 = v13->Stack.pCurrent;
          if ( v15->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v15);
          --v13->Stack.pCurrent;
          if ( v13->Stack.pCurrent < v13->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
          --v10;
        }
        while ( v10 );
      }
      if ( v12 )
      {
        v17 = v12->RefCount;
        if ( v17 & 0x3FFFFFF )
        {
          v12->RefCount = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
        }
      }
      v18 = result.pNode;
      v19 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}or(
      v1->Env,
      "Error: Null or invalid thi

// File Line: 687
// RVA: 0x6ABAC0
void __fastcall Scaleform::GFx::AS2::XmlProto::GetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rbx
  double v6; // xmm6_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      v4 = (signed __int64)&v3[-2];
      if ( v4 )
      {
        v5 = v1->Result;
        v6 = *(double *)(v4 + 112);
        if ( v6 >= 0.0 )
        {
          if ( v5->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->NV.NumberValue = v6;
          v5->T.Type = 3;
        }
        else
        {
          Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->T.Type = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 712
// RVA: 0x6ABBB0
void __fastcall Scaleform::GFx::AS2::XmlProto::GetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rbx
  double v6; // xmm6_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      v4 = (signed __int64)&v3[-2];
      if ( v4 )
      {
        v5 = v1->Result;
        v6 = *(double *)(v4 + 120);
        if ( v6 >= 0.0 )
        {
          if ( v5->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->NV.NumberValue = v6;
          v5->T.Type = 3;
        }
        else
        {
          Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->T.Type = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 735
// RVA: 0x6ABCB0
void __fastcall Scaleform::GFx::AS2::XmlProto::Load(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  __int64 v12; // rcx
  Scaleform::GFx::MovieImpl *v13; // rdi
  Scaleform::GFx::ExternalLibPtr *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::XML::ObjectManager *v16; // rax
  Scaleform::GFx::XML::ObjectManager *v17; // rbx
  signed __int64 v18; // rax
  Scaleform::GFx::XML::SupportBase *v19; // r14
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
  char v31; // al
  Scaleform::GFx::AS2::FunctionObject *v32; // rcx
  unsigned int v33; // edx
  Scaleform::GFx::AS2::LocalFrame *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS2::FunctionRef v37; // [rsp+30h] [rbp-99h]
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> v38; // [rsp+48h] [rbp-81h]
  Scaleform::GFx::ASString v39; // [rsp+50h] [rbp-79h]
  Scaleform::GFx::ASString v40; // [rsp+58h] [rbp-71h]
  Scaleform::GFx::AS2::Value v41; // [rsp+60h] [rbp-69h]
  Scaleform::GFx::AS2::Value v42; // [rsp+80h] [rbp-49h]
  Scaleform::GFx::AS2::Value v43; // [rsp+A0h] [rbp-29h]
  Scaleform::GFx::AS2::XMLFileLoader *v44; // [rsp+C0h] [rbp-9h]
  Scaleform::GFx::AS2::XMLFileLoader *v45; // [rsp+C8h] [rbp-1h]
  __int64 v46; // [rsp+D0h] [rbp+7h]
  Scaleform::GFx::AS2::XMLFileLoader *v47; // [rsp+D8h] [rbp+Fh]
  void *v48; // [rsp+130h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh]
  Scaleform::GFx::XML::ObjectManager *v50; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::ASString v51; // [rsp+148h] [rbp+7Fh]

  v46 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2 || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 28 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
    return;
  }
  v3 = v1->ThisPtr;
  if ( v3 )
  {
    v4 = (Scaleform::GFx::AS2::Object *)&v3[-2];
    if ( v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      if ( !v1->NArgs )
      {
        v5 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v5->T.Type = 2;
        v5->V.BooleanValue = 0;
        return;
      }
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
      v42.T.Type = 0;
      v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v1->Env, &v51, "onData");
      v4->vfptr->GetMember((Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr, v1->Env, v9, &v42);
      v10 = v51.pNode;
      v11 = v51.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      Scaleform::GFx::AS2::Value::ToFunction(&v42, &v37, v1->Env);
      if ( ((unsigned __int8 (*)(void))v37.Function->vfptr[4].Finalize_GC)() )
      {
        if ( Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
          if ( ((unsigned __int8 (*)(void))v37.Function->vfptr[4].Finalize_GC)()
            && (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v37.Function[1].vfptr == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
          {
            goto LABEL_17;
          }
        }
        else if ( (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v37.Function == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
LABEL_17:
          v13 = v1->Env->Target->pASRoot->pMovieImpl;
          v50 = 0i64;
          v14 = v13->pXMLObjectManager;
          if ( v14 )
          {
            v17 = (Scaleform::GFx::XML::ObjectManager *)&v14[-1];
            if ( v17 )
              ++v17->RefCount;
            v50 = v17;
          }
          else
          {
            v48 = v1->Env->StringContext.pContext->pHeap;
            v15 = (Scaleform::GFx::ASStringNode *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v48 + 80i64))(
                                                    v12,
                                                    120i64,
                                                    0i64);
            v51.pNode = v15;
            if ( v15 )
            {
              Scaleform::GFx::XML::ObjectManager::ObjectManager((Scaleform::GFx::XML::ObjectManager *)v15, v13);
              v17 = v16;
            }
            else
            {
              v17 = 0i64;
            }
            v50 = v17;
            v18 = (signed __int64)&v17->vfptr;
            if ( !v17 )
              v18 = 0i64;
            v13->pXMLObjectManager = (Scaleform::GFx::ExternalLibPtr *)v18;
          }
          v19 = Scaleform::GFx::StateBag::GetXMLSupport((Scaleform::GFx::StateBag *)&v13->vfptr, &v38)->pObject;
          if ( v38.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38.pObject);
          v4[1].pPrev = 0i64;
          v41.T.Type = 0;
          v20 = Scaleform::GFx::AS2::Environment::CreateConstString(v1->Env, &v39, "ignoreWhite");
          v4->vfptr->GetMember((Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr, v1->Env, v20, &v41);
          v21 = v39.pNode;
          v11 = v39.pNode->RefCount == 1;
          --v21->RefCount;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          v22 = Scaleform::GFx::AS2::Value::ToBool(&v41, v1->Env);
          v23 = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                     Scaleform::Memory::pGlobalHeap,
                                                                     48i64);
          v48 = v23;
          if ( v23 )
          {
            Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(v23, v19, v17, v22);
            v25 = v24;
          }
          else
          {
            v25 = 0i64;
          }
          v47 = v25;
          Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(
            (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
            v4,
            v25,
            result.pNode->pData,
            0);
          v26 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
          v26->T.Type = 2;
          v26->V.BooleanValue = 1;
          if ( v25 )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25);
          if ( v41.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v41);
          if ( v17 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v17->vfptr);
LABEL_45:
          LOBYTE(v48) = 2;
          v43.T.Type = 2;
          v43.V.BooleanValue = 0;
          v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v1->Env->StringContext, &v40, "loaded");
          v4->vfptr->SetMemberRaw(
            (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
            &v1->Env->StringContext,
            v29,
            &v43,
            (Scaleform::GFx::AS2::PropFlags *)&v48);
          v30 = v40.pNode;
          v11 = v40.pNode->RefCount == 1;
          --v30->RefCount;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
          if ( v43.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v43);
          v31 = v37.Flags;
          if ( !(v37.Flags & 2) )
          {
            v32 = v37.Function;
            if ( v37.Function )
            {
              v33 = v37.Function->RefCount;
              if ( v33 & 0x3FFFFFF )
              {
                v37.Function->RefCount = v33 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
                v31 = v37.Flags;
              }
            }
          }
          v37.Function = 0i64;
          if ( !(v31 & 1) )
          {
            v34 = v37.pLocalFrame;
            if ( v37.pLocalFrame )
            {
              v35 = v37.pLocalFrame->RefCount;
              if ( v35 & 0x3FFFFFF )
              {
                v37.pLocalFrame->RefCount = v35 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v34->vfptr);
              }
            }
          }
          v37.pLocalFrame = 0i64;
          if ( v42.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v42);
          v36 = result.pNode;
          v11 = result.pNode->RefCount == 1;
          --v36->RefCount;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          return;
        }
      }
      v27 = (Scaleform::GFx::AS2::XMLFileLoader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
        (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        v4,
        v27,
        result.pNode->pData,
        0);
      v28 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::XmlObject *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rbp
  __int64 v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rdi
  Scaleform::GFx::XML::ElementNode *i; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value v17; // [rsp+38h] [rbp-40h]
  Scaleform::MemoryHeap *v18; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::AS2::Object *v20; // [rsp+90h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      v4 = (Scaleform::GFx::AS2::XmlObject *)&v3[-2];
      if ( v4 )
      {
        Scaleform::GFx::AS2::XML_LoadString(v1, v4);
        v5 = v1->Env;
        v18 = v5->StringContext.pContext->pHeap;
        v7 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(__int64, signed __int64))v18->vfptr->Alloc)(
                                               v6,
                                               96i64);
        result.pNode = v7;
        if ( v7 )
        {
          Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, v5);
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
            Scaleform::GFx::AS2::Xml_CreateIDMap(v5, i, v4->pRootNode.pObject, v9);
        }
        LOBYTE(v18) = 2;
        Scaleform::GFx::AS2::Value::Value(&v17, v9);
        v12 = v11;
        v13 = Scaleform::GFx::AS2::Environment::CreateConstString(v5, &result, "idMap");
        v4->vfptr->SetMember(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          v5,
          v13,
          v12,
          (Scaleform::GFx::AS2::PropFlags *)&v18);
        v14 = result.pNode;
        v15 = result.pNode->RefCount == 1;
        --v14->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        if ( v17.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v17);
        if ( v9 )
        {
          v16 = v9->RefCount;
          if ( v16 & 0x3FFFFFF )
          {
            v9->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 849
// RVA: 0x6AC730
void __fastcall Scaleform::GFx::AS2::XmlProto::Send(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
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
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 868
// RVA: 0x6AC990
void __fastcall Scaleform::GFx::AS2::XmlProto::SendAndLoad(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 28 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v4 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
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
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XML");
  }
}

// File Line: 901
// RVA: 0x6FA980
void __fastcall Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::XmlObject *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::XmlObject *v5; // rax
  Scaleform::GFx::AS2::XmlObject *v6; // rax
  unsigned int v7; // eax

  v1 = fn;
  v2 = 0i64;
  v3 = fn->ThisPtr;
  if ( v3 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) == 28 )
  {
    v4 = v1->ThisPtr;
    if ( v4 )
    {
      v2 = (Scaleform::GFx::AS2::XmlObject *)&v4[-2];
      if ( v4 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
        v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    }
  }
  else
  {
    v5 = (Scaleform::GFx::AS2::XmlObject *)v1->Env->StringContext.pContext->pHeap->vfptr->Alloc(
                                             (Scaleform::MemoryHeap *)v3,
                                             128ui64,
                                             0i64);
    if ( v5 )
    {
      Scaleform::GFx::AS2::XmlObject::XmlObject(v5, v1->Env);
      v2 = v6;
    }
  }
  Scaleform::GFx::AS2::XML_LoadString(v1, v2);
  if ( v2 )
  {
    v7 = v2->RefCount;
    if ( v7 & 0x3FFFFFF )
    {
      v2->RefCount = v7 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
    }
  }
}

// File Line: 912
// RVA: 0x6E0960
void __fastcall Scaleform::GFx::AS2::XmlCtorFunction::CreateNewObject(Scaleform::GFx::AS2::XmlCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::XmlObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::XmlObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                           (Scaleform::MemoryHeap *)this,
                                           128ui64,
                                           0i64);
  if ( v3 )
    Scaleform::GFx::AS2::XmlObject::XmlObject(v3, v2);
}

// File Line: 917
// RVA: 0x70F690
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::XmlCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rcx
  char v5; // al
  unsigned int v6; // edx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  Scaleform::GFx::AS2::FunctionObject *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // r15
  unsigned int v12; // eax
  Scaleform::GFx::AS2::XmlProto *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rbx
  Scaleform::GFx::AS2::Object *v17; // r14
  Scaleform::GFx::AS2::LocalFrame *v18; // rax
  Scaleform::GFx::AS2::LocalFrame *v19; // rdx
  unsigned int v20; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::FunctionRef resulta; // [rsp+50h] [rbp-20h]
  char v24; // [rsp+68h] [rbp-8h]
  Scaleform::GFx::ASString className; // [rsp+B8h] [rbp+48h]
  Scaleform::GFx::ASString *v26; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::ASString *v27; // [rsp+C8h] [rbp+58h]

  v2 = pgc;
  v3 = result;
  v26 = &className;
  className.pNode = (Scaleform::GFx::ASStringNode *)pgc->pMovieRoot->pASMovieRoot.pObject[12].pASSupport.pObject;
  ++className.pNode->RefCount;
  if ( !Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(pgc, (Scaleform::GFx::ASString)&className) )
  {
    Scaleform::GFx::AS2::XmlNodeCtorFunction::Register(&resulta, v2);
    v5 = resulta.Flags;
    if ( !(resulta.Flags & 2) )
    {
      v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&resulta.Function->vfptr;
      if ( resulta.Function )
      {
        v6 = resulta.Function->RefCount;
        if ( v6 & 0x3FFFFFF )
        {
          resulta.Function->RefCount = v6 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          v5 = resulta.Flags;
        }
      }
    }
    resulta.Function = 0i64;
    if ( !(v5 & 1) )
    {
      v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&resulta.pLocalFrame->vfptr;
      if ( resulta.pLocalFrame )
      {
        v7 = resulta.pLocalFrame->RefCount;
        if ( v7 & 0x3FFFFFF )
        {
          resulta.pLocalFrame->RefCount = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
        }
      }
    }
  }
  psc.pContext = v2;
  psc.SWFVersion = 8;
  v26 = (Scaleform::GFx::ASString *)v2->pHeap;
  v8 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64))v26->pNode[2].pData)(
                                        v4,
                                        104i64);
  v10 = (Scaleform::GFx::AS2::FunctionObject *)v8;
  v27 = (Scaleform::GFx::ASString *)v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::Object::Object(v8, &psc);
    v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor;
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v10->pProto.pObject )
    {
      LOBYTE(className.pNode) = 3;
      LOBYTE(resulta.Function) = 10;
      v10->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        (Scaleform::GFx::AS2::Value *)&resulta,
        (Scaleform::GFx::AS2::PropFlags *)&className);
      if ( LOBYTE(resulta.Function) >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&resulta);
    }
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->pProto.pObject->vfptr;
    if ( v9 )
    {
      v12 = v9->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v9->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
    v10->pProto.pObject = v11;
    v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v10 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v10;
  v3->pLocalFrame = 0i64;
  className.pNode = (Scaleform::GFx::ASStringNode *)v2->pHeap;
  v13 = (Scaleform::GFx::AS2::XmlProto *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))className.pNode->pData
                                          + 10))(
                                           v9,
                                           192i64,
                                           0i64);
  v26 = (Scaleform::GFx::ASString *)v13;
  if ( v13 )
  {
    v14 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_XMLNode);
    Scaleform::GFx::AS2::XmlProto::XmlProto(v13, &psc, v14, v3);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v26 = (Scaleform::GFx::ASString *)v16;
  v27 = &className;
  if ( v16 )
    v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
  className.pNode = v16;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_XML,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&className);
  v17 = v2->pGlobal.pObject;
  LOBYTE(resulta.Function) = 8;
  v24 = 0;
  v18 = (Scaleform::GFx::AS2::LocalFrame *)v3->Function;
  resulta.pLocalFrame = v18;
  if ( v18 )
  {
    ++v18->RefCount;
    v18->RefCount &= 0x8FFFFFFF;
  }
  *(_QWORD *)&resulta.Flags = 0i64;
  v19 = v3->pLocalFrame;
  if ( v19 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&resulta.pLocalFrame,
      v19,
      v3->Flags & 1);
  LOBYTE(className.pNode) = 0;
  v17->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v17->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl,
    (Scaleform::GFx::AS2::Value *)&resulta,
    (Scaleform::GFx::AS2::PropFlags *)&className);
  if ( LOBYTE(resulta.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&resulta);
  if ( v16 )
  {
    v20 = v16->RefCount;
    if ( v20 & 0x3FFFFFF )
    {
      v16->RefCount = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v16);
    }
  }
  return v3;
}

