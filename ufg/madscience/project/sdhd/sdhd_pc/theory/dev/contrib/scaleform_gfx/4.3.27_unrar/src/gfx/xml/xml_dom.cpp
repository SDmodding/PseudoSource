// File Line: 131
// RVA: 0x8952D0
void __fastcall Scaleform::GFx::XML::DOMBuilder::DOMBuilder(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser, bool ignorews)
{
  bool v3; // si
  Scaleform::Render::RenderBuffer **v4; // rdi
  Scaleform::GFx::XML::DOMBuilder *v5; // rbx
  signed __int64 v6; // [rsp+68h] [rbp+20h]
  signed __int64 v7; // [rsp+68h] [rbp+20h]
  signed __int64 v8; // [rsp+68h] [rbp+20h]

  v3 = ignorews;
  v4 = (Scaleform::Render::RenderBuffer **)pxmlParser.pObject;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,326>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::XML::ParserHandler,326>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::XML::ParserHandler::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::XML::DOMBuilder::`vftable';
  if ( pxmlParser.pObject->vfptr )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pxmlParser.pObject->vfptr);
  v5->pXMLParserState.pObject = (Scaleform::GFx::XML::SupportBase *)*v4;
  v5->pAppendChainRoot.pObject = 0i64;
  Scaleform::StringBuffer::StringBuffer(&v5->AppendText, Scaleform::Memory::pGlobalHeap);
  v5->pLocator = 0i64;
  v6 = (signed __int64)&v5->ParseStack;
  *(_OWORD *)v6 = 0ui64;
  *(_QWORD *)(v6 + 16) = 0i64;
  v7 = (signed __int64)&v5->PrefixNamespaceStack;
  *(_OWORD *)v7 = 0ui64;
  *(_QWORD *)(v7 + 16) = 0i64;
  v8 = (signed __int64)&v5->DefaultNamespaceStack;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v5->pDoc.pObject = 0i64;
  v5->bIgnoreWhitespace = v3;
  v5->bError = 0;
  if ( *v4 )
    Scaleform::RefCountImpl::Release(*v4);
}

// File Line: 176
// RVA: 0x8EF4F0
Scaleform::Ptr<Scaleform::GFx::XML::Document> *__fastcall Scaleform::GFx::XML::DOMBuilder::ParseString(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::Ptr<Scaleform::GFx::XML::Document> *result, const char *pdata, unsigned __int64 len, Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> objMgr)
{
  unsigned __int64 v5; // r14
  const char *v6; // r15
  Scaleform::Ptr<Scaleform::GFx::XML::Document> *v7; // rdi
  Scaleform::GFx::XML::DOMBuilder *v8; // rbx
  Scaleform::GFx::XML::ObjectManager *v9; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v10; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v11; // rbp
  Scaleform::RefCountNTSImplCoreVtbl *v12; // rbp
  Scaleform::GFx::XML::Document *v13; // rax
  Scaleform::GFx::XML::Document *v14; // rax
  Scaleform::GFx::XML::Document *v15; // rbp
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::GFx::XML::SupportBase *v17; // rcx
  Scaleform::GFx::XML::Document *v18; // rax
  Scaleform::RefCountNTSImpl *v19; // rcx
  Scaleform::GFx::XML::Document *v21; // [rsp+30h] [rbp-38h]

  v5 = len;
  v6 = pdata;
  v7 = result;
  v8 = this;
  this->bError = 0;
  this->TotalBytesToLoad = 0i64;
  this->LoadedBytes = 0i64;
  if ( !objMgr.pObject->vfptr )
  {
    v9 = (Scaleform::GFx::XML::ObjectManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 120ui64,
                                                 0i64);
    if ( v9 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager(v9, 0i64);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    if ( objMgr.pObject->vfptr )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)objMgr.pObject->vfptr);
    objMgr.pObject->vfptr = v11;
  }
  v12 = objMgr.pObject->vfptr;
  v13 = (Scaleform::GFx::XML::Document *)(*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int), signed __int64, _QWORD))(*(_QWORD *)objMgr.pObject->vfptr[14].__vecDelDtor + 80i64))(
                                           objMgr.pObject->vfptr[14].__vecDelDtor,
                                           144i64,
                                           0i64);
  v21 = v13;
  if ( v13 )
  {
    Scaleform::GFx::XML::Document::Document(v13, (Scaleform::GFx::XML::ObjectManager *)v12);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = (Scaleform::RefCountNTSImpl *)&v8->pDoc.pObject->vfptr;
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release(v16);
  v8->pDoc.pObject = v15;
  v17 = v8->pXMLParserState.pObject;
  if ( v17 )
    v8->bError = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::XML::SupportBase *, const char *, unsigned __int64, Scaleform::GFx::XML::DOMBuilder *, _DWORD, signed __int64, Scaleform::GFx::XML::Document *))v17->vfptr[2].__vecDelDtor)(
                   v17,
                   v6,
                   v5,
                   v8,
                   0,
                   -2i64,
                   v21) == 0;
  v18 = v8->pDoc.pObject;
  if ( v18 )
    ++v18->RefCount;
  v7->pObject = (Scaleform::GFx::XML::Document *)v8->pDoc;
  v19 = (Scaleform::RefCountNTSImpl *)&v8->pDoc.pObject->vfptr;
  if ( v19 )
    Scaleform::RefCountNTSImpl::Release(v19);
  v8->pDoc.pObject = 0i64;
  if ( v7->pObject && v8->bIgnoreWhitespace )
    Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(v7->pObject);
  if ( objMgr.pObject->vfptr )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)objMgr.pObject->vfptr);
  return v7;
}

// File Line: 207
// RVA: 0x910FE0
void __fastcall Scaleform::GFx::XML::DOMBuilder::StartDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::DOMBuilder *v1; // rsi
  Scaleform::GFx::XML::Document *v2; // rax
  Scaleform::GFx::XML::Document *v3; // rdi
  _QWORD *v4; // rdx

  v1 = this;
  v2 = this->pDoc.pObject;
  if ( v2 )
    ++v2->RefCount;
  v3 = this->pDoc.pObject;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack,
    &this->ParseStack,
    this->ParseStack.Data.Size + 1);
  v4 = &v1->ParseStack.Data.Data[v1->ParseStack.Data.Size - 1].pObject;
  if ( v4 )
  {
    if ( v3 )
      ++v3->RefCount;
    *v4 = v3;
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  v1->TotalBytesToLoad = v1->pLocator->TotalBytesToLoad;
}

// File Line: 225
// RVA: 0x8C8420
void __fastcall Scaleform::GFx::XML::DOMBuilder::EndDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::DOMBuilder *v1; // rbx
  Scaleform::GFx::XML::Document *v2; // rdi
  Scaleform::GFx::XML::ObjectManager *v3; // rax
  Scaleform::GFx::XML::ObjectManager *v4; // rdi
  Scaleform::GFx::XML::DOMString *v5; // rax
  Scaleform::GFx::XML::Document *v6; // rbp
  Scaleform::GFx::XML::DOMStringNode *v7; // rsi
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString *v11; // rax
  Scaleform::GFx::XML::Document *v12; // rbp
  Scaleform::GFx::XML::DOMStringNode *v13; // rsi
  Scaleform::GFx::XML::DOMStringNode *v14; // rcx
  Scaleform::GFx::XML::DOMStringNode *v15; // rcx
  Scaleform::GFx::XML::DOMString result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::XML::ObjectManager *v17; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack,
    &this->ParseStack,
    0i64);
  v2 = v1->pDoc.pObject;
  v3 = v2->MemoryManager.pObject;
  if ( v3 )
    ++v3->RefCount;
  v4 = v2->MemoryManager.pObject;
  v17 = v4;
  v5 = Scaleform::GFx::XML::ObjectManager::CreateString(
         v4,
         &result,
         v1->pLocator->XMLVersion.pStr,
         v1->pLocator->XMLVersion.Size);
  v6 = v1->pDoc.pObject;
  v7 = v5->pNode;
  ++v7->RefCount;
  v8 = v6->XMLVersion.pNode;
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
  v6->XMLVersion.pNode = v7;
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::XML::ObjectManager::CreateString(
          v4,
          &result,
          v1->pLocator->Encoding.pStr,
          v1->pLocator->Encoding.Size);
  v12 = v1->pDoc.pObject;
  v13 = v11->pNode;
  ++v13->RefCount;
  v14 = v12->Encoding.pNode;
  v9 = v14->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v14);
  v12->Encoding.pNode = v13;
  v15 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v15);
  v1->pDoc.pObject->Standalone = v1->pLocator->StandAlone;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
}

// File Line: 275
// RVA: 0x911070
void __fastcall Scaleform::GFx::XML::DOMBuilder::StartElement(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::StringDataPtr *prefix, Scaleform::StringDataPtr *localname, Scaleform::GFx::XML::ParserAttributes *atts)
{
  Scaleform::GFx::XML::ParserAttributes *v4; // r13
  Scaleform::StringDataPtr *v5; // rsi
  char *v6; // r14
  Scaleform::GFx::XML::Document *v7; // rcx
  Scaleform::GFx::XML::ObjectManager *v8; // rax
  Scaleform::GFx::XML::ObjectManager *v9; // rdi
  signed __int64 v10; // rbx
  __int64 v11; // rax
  Scaleform::GFx::XML::DOMStringNode *v12; // rbx
  const char *v13; // r8
  Scaleform::GFx::XML::DOMString *v14; // rax
  __int64 v15; // r15
  Scaleform::GFx::XML::DOMStringNode *v16; // rdi
  Scaleform::GFx::XML::DOMStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::XML::DOMStringNode *v19; // rcx
  Scaleform::RefCountNTSImpl *v20; // rcx
  Scaleform::GFx::XML::DOMString *v21; // rax
  Scaleform::GFx::XML::ElementNode *v22; // rsi
  unsigned __int64 v23; // r15
  __int64 v24; // r12
  Scaleform::GFx::XML::ObjectManager *v25; // r14
  Scaleform::GFx::XML::ParserAttribute *v26; // rbx
  Scaleform::GFx::XML::DOMString *v27; // rdi
  Scaleform::GFx::XML::DOMString *v28; // rax
  Scaleform::GFx::XML::Attribute *v29; // rax
  __int64 v30; // rax
  int v31; // eax
  __int64 v32; // rdi
  signed __int64 v33; // r15
  __int64 v34; // rbx
  Scaleform::RefCountNTSImpl *v35; // rcx
  signed __int64 v36; // rbx
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::GFx::XML::DOMStringNode *v38; // r13
  __int64 v39; // rax
  int v40; // eax
  __int64 v41; // r12
  signed __int64 v42; // r15
  __int64 v43; // rax
  __int64 v44; // rcx
  __int64 v45; // rbx
  __int64 v46; // rcx
  Scaleform::RefCountNTSImpl *v47; // rdi
  Scaleform::GFx::XML::DOMStringNode *v48; // r12
  Scaleform::GFx::XML::DOMStringNode *v49; // r15
  __int64 v50; // r8
  __int64 v51; // r9
  Scaleform::GFx::XML::DOMStringManager *v52; // r13
  char *v53; // rdx
  Scaleform::GFx::XML::DOMStringNode *v54; // r12
  Scaleform::GFx::XML::DOMStringNode *v55; // r15
  __int64 v56; // r8
  __int64 v57; // r9
  Scaleform::GFx::XML::DOMStringManager *v58; // r13
  char *v59; // rdx
  Scaleform::RefCountNTSImpl *v60; // rcx
  Scaleform::GFx::XML::ObjectManager *v61; // r12
  Scaleform::GFx::XML::DOMStringNode *v62; // r15
  Scaleform::GFx::XML::DOMStringNode *v63; // rbx
  __int64 v64; // r8
  __int64 v65; // r9
  Scaleform::GFx::XML::DOMStringManager *v66; // rdi
  char *v67; // rdx
  Scaleform::GFx::XML::DOMStringNode *v68; // rbx
  __int64 v69; // r8
  __int64 v70; // r9
  Scaleform::GFx::XML::DOMStringManager *v71; // rdi
  char *v72; // rdx
  Scaleform::GFx::XML::DOMStringNode *v73; // r15
  Scaleform::GFx::XML::DOMStringNode *v74; // rbx
  __int64 v75; // r8
  __int64 v76; // r9
  Scaleform::GFx::XML::DOMStringManager *v77; // rdi
  char *v78; // rdx
  Scaleform::GFx::XML::DOMStringNode *v79; // rbx
  __int64 v80; // r8
  __int64 v81; // r9
  Scaleform::GFx::XML::DOMStringManager *v82; // rdi
  char *v83; // rdx
  signed __int64 v84; // rcx
  __int64 v85; // rax
  __int64 v86; // rdx
  __int64 v87; // rdi
  __int64 v88; // rdx
  Scaleform::RefCountNTSImpl *v89; // r13
  Scaleform::GFx::XML::DOMStringNode *v90; // r12
  Scaleform::GFx::XML::DOMStringNode *v91; // rbx
  __int64 v92; // r8
  __int64 v93; // r9
  Scaleform::GFx::XML::DOMStringManager *v94; // r15
  char *v95; // rdx
  Scaleform::GFx::XML::DOMStringNode *v96; // r12
  Scaleform::GFx::XML::DOMStringNode *v97; // rbx
  __int64 v98; // r8
  __int64 v99; // r9
  Scaleform::GFx::XML::DOMStringManager *v100; // r15
  char *v101; // rdx
  signed __int64 v102; // rbx
  __int64 v103; // rax
  __int64 v104; // rbx
  Scaleform::GFx::XML::Node *v105; // rax
  Scaleform::RefCountNTSImpl *v106; // rcx
  __int64 v107; // rdi
  Scaleform::RefCountNTSImpl *v108; // rcx
  Scaleform::GFx::XML::DOMStringNode *v109; // rdx
  Scaleform::GFx::XML::DOMString v110; // [rsp+20h] [rbp-38h]
  __int64 v111; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::XML::ElementNode *v112; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::XML::DOMString *v113; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::XML::DOMString *v114; // [rsp+40h] [rbp-18h]
  __int64 v115; // [rsp+48h] [rbp-10h]
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+A0h] [rbp+48h]
  Scaleform::GFx::XML::DOMString v117; // [rsp+A8h] [rbp+50h]
  Scaleform::GFx::XML::ObjectManager *v118; // [rsp+B0h] [rbp+58h]
  Scaleform::GFx::XML::DOMString result; // [rsp+B8h] [rbp+60h]

  v117.pNode = (Scaleform::GFx::XML::DOMStringNode *)prefix;
  key = (Scaleform::GFx::XML::DOMStringNode *)this;
  v111 = -2i64;
  v4 = atts;
  v5 = localname;
  v6 = (char *)this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v7 = this->pDoc.pObject;
  v8 = v7->MemoryManager.pObject;
  if ( v8 )
    ++v8->RefCount;
  v9 = v7->MemoryManager.pObject;
  v118 = v7->MemoryManager.pObject;
  if ( *((_QWORD *)v6 + 3) )
  {
    v10 = *((_QWORD *)v6 + 11) + 8i64 * *((_QWORD *)v6 + 12);
    v11 = *(_QWORD *)(v10 - 8);
    if ( v11 )
      ++*(_DWORD *)(v11 + 8);
    v12 = *(Scaleform::GFx::XML::DOMStringNode **)(v10 - 8);
    v110.pNode = v12;
    Scaleform::GFx::XML::ElementNode::AppendChild(
      (Scaleform::GFx::XML::ElementNode *)v12,
      *((Scaleform::GFx::XML::Node **)v6 + 3));
    v13 = &customWorldMapCaption;
    if ( *((_QWORD *)v6 + 4) )
      v13 = (const char *)*((_QWORD *)v6 + 4);
    v14 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, v13, *((_QWORD *)v6 + 5));
    v15 = *((_QWORD *)v6 + 3);
    v16 = v14->pNode;
    ++v16->RefCount;
    v17 = *(Scaleform::GFx::XML::DOMStringNode **)(v15 + 24);
    v18 = v17->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v17);
    *(_QWORD *)(v15 + 24) = v16;
    v19 = result.pNode;
    v18 = result.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v18 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v19);
    v20 = (Scaleform::RefCountNTSImpl *)*((_QWORD *)v6 + 3);
    if ( v20 )
      Scaleform::RefCountNTSImpl::Release(v20);
    *((_QWORD *)v6 + 3) = 0i64;
    Scaleform::StringBuffer::Clear((Scaleform::StringBuffer *)(v6 + 32));
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v12);
    v9 = v118;
  }
  v110.pNode = (Scaleform::GFx::XML::DOMStringNode *)&result;
  v21 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, v5->pStr, v5->Size);
  v22 = Scaleform::GFx::XML::ObjectManager::CreateElementNode(v9, (Scaleform::GFx::XML::DOMString)v21);
  v112 = v22;
  v23 = 0i64;
  if ( v4->Length )
  {
    v113 = &result;
    v114 = &v110;
    v24 = 0i64;
    v25 = v118;
    do
    {
      v26 = &v4->Attributes[v24];
      v27 = Scaleform::GFx::XML::ObjectManager::CreateString(v25, &result, v26->Value.pStr, v26->Value.Size);
      v28 = Scaleform::GFx::XML::ObjectManager::CreateString(v25, &v110, v26->Name.pStr, v26->Name.Size);
      v29 = Scaleform::GFx::XML::ObjectManager::CreateAttribute(
              v25,
              (Scaleform::GFx::XML::DOMString)v28,
              (Scaleform::GFx::XML::DOMString)v27);
      if ( v22->FirstAttribute )
        v22->LastAttribute->Next = v29;
      else
        v22->FirstAttribute = v29;
      v22->LastAttribute = v29;
      ++v23;
      ++v24;
    }
    while ( v23 < v4->Length );
    v6 = (char *)key;
  }
  v30 = *((_QWORD *)v6 + 15);
  if ( v30 )
  {
    v31 = v30 - 1;
    v32 = v31;
    if ( v31 >= 0 )
    {
      v33 = 16i64 * v31;
      do
      {
        v34 = *((_QWORD *)v6 + 14);
        if ( *(_QWORD *)(v34 + v33 + 8) )
          break;
        if ( v22 )
          ++v22->RefCount;
        v35 = *(Scaleform::RefCountNTSImpl **)(v34 + v33 + 8);
        if ( v35 )
          Scaleform::RefCountNTSImpl::Release(v35);
        *(_QWORD *)(v34 + v33 + 8) = v22;
        v33 -= 16i64;
        --v32;
      }
      while ( v32 >= 0 );
    }
  }
  if ( *((_QWORD *)v6 + 18) )
  {
    v36 = *((_QWORD *)v6 + 17) + 16i64 * *((_QWORD *)v6 + 18);
    if ( !*(_QWORD *)(v36 - 8) )
    {
      if ( v22 )
        ++v22->RefCount;
      v37 = *(Scaleform::RefCountNTSImpl **)(v36 - 8);
      if ( v37 )
        Scaleform::RefCountNTSImpl::Release(v37);
      *(_QWORD *)(v36 - 8) = v22;
    }
  }
  v38 = v117.pNode;
  if ( !v117.pNode->pManager )
  {
    if ( !*((_QWORD *)v6 + 18) )
    {
LABEL_121:
      v61 = v118;
      goto LABEL_122;
    }
    v84 = 2i64 * *((_QWORD *)v6 + 18);
    v85 = *((_QWORD *)v6 + 17);
    v86 = *(_QWORD *)(v85 + 16i64 * *((_QWORD *)v6 + 18) - 16);
    if ( v86 )
      ++*(_DWORD *)(v86 + 8);
    v87 = *(_QWORD *)(v85 + 8 * v84 - 16);
    v114 = *(Scaleform::GFx::XML::DOMString **)(v85 + 8 * v84 - 16);
    v88 = *(_QWORD *)(v85 + 8 * v84 - 8);
    if ( v88 )
      ++*(_DWORD *)(v88 + 8);
    v89 = *(Scaleform::RefCountNTSImpl **)(v85 + 8 * v84 - 8);
    v115 = *(_QWORD *)(v85 + 8 * v84 - 8);
    v90 = *(Scaleform::GFx::XML::DOMStringNode **)(v87 + 16);
    ++v90->RefCount;
    v91 = v22->Prefix.pNode;
    v18 = v91->RefCount-- == 1;
    if ( v18 )
    {
      key = v91;
      Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
        (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v91->pManager->StringSet.pTable,
        &key);
      v94 = v91->pManager;
      v95 = (char *)v91->pData;
      if ( v91->pData )
      {
        if ( v91->Size >= 0x10 )
        {
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v95,
            v92,
            v93,
            v110.pNode,
            v111);
        }
        else
        {
          *(_QWORD *)v95 = v94->pFreeTextBuffers;
          v94->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v95;
        }
        v91->pData = 0i64;
      }
      v91->pManager = (Scaleform::GFx::XML::DOMStringManager *)v94->pFreeStringNodes;
      v94->pFreeStringNodes = v91;
    }
    v22->Prefix.pNode = v90;
    v96 = *(Scaleform::GFx::XML::DOMStringNode **)(v87 + 24);
    ++v96->RefCount;
    v97 = v22->Namespace.pNode;
    v18 = v97->RefCount-- == 1;
    if ( v18 )
    {
      key = v97;
      Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
        (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v97->pManager->StringSet.pTable,
        &key);
      v100 = v97->pManager;
      v101 = (char *)v97->pData;
      if ( v97->pData )
      {
        if ( v97->Size >= 0x10 )
        {
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v101,
            v98,
            v99,
            v110.pNode,
            v111);
        }
        else
        {
          *(_QWORD *)v101 = v100->pFreeTextBuffers;
          v100->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v101;
        }
        v97->pData = 0i64;
      }
      v97->pManager = (Scaleform::GFx::XML::DOMStringManager *)v100->pFreeStringNodes;
      v100->pFreeStringNodes = v97;
    }
    v22->Namespace.pNode = v96;
    if ( v89 )
      Scaleform::RefCountNTSImpl::Release(v89);
    v60 = (Scaleform::RefCountNTSImpl *)v87;
LABEL_120:
    Scaleform::RefCountNTSImpl::Release(v60);
    goto LABEL_121;
  }
  v39 = *((_QWORD *)v6 + 15);
  if ( v39 )
  {
    v40 = v39 - 1;
    v41 = v40;
    if ( v40 >= 0 )
    {
      v42 = 16i64 * v40;
      while ( 1 )
      {
        v43 = *((_QWORD *)v6 + 14);
        v44 = *(_QWORD *)(v42 + v43);
        if ( v44 )
          ++*(_DWORD *)(v44 + 8);
        v45 = *(_QWORD *)(v42 + v43);
        v114 = *(Scaleform::GFx::XML::DOMString **)(v42 + v43);
        v46 = *(_QWORD *)(v42 + v43 + 8);
        if ( v46 )
          ++*(_DWORD *)(v46 + 8);
        v47 = *(Scaleform::RefCountNTSImpl **)(v42 + v43 + 8);
        v115 = *(_QWORD *)(v42 + v43 + 8);
        if ( !strncmp(**(const char ***)(v45 + 16), v38->pData, (size_t)v38->pManager) )
          break;
        if ( v47 )
          Scaleform::RefCountNTSImpl::Release(v47);
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v45);
        v42 -= 16i64;
        if ( --v41 < 0 )
          goto LABEL_70;
      }
      v48 = *(Scaleform::GFx::XML::DOMStringNode **)(v45 + 16);
      ++v48->RefCount;
      v49 = v22->Prefix.pNode;
      v18 = v49->RefCount-- == 1;
      if ( v18 )
      {
        key = v49;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v49->pManager->StringSet.pTable,
          &key);
        v52 = v49->pManager;
        v53 = (char *)v49->pData;
        if ( v49->pData )
        {
          if ( v49->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v53,
              v50,
              v51,
              v110.pNode,
              v111);
          }
          else
          {
            *(_QWORD *)v53 = v52->pFreeTextBuffers;
            v52->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v53;
          }
          v49->pData = 0i64;
        }
        v49->pManager = (Scaleform::GFx::XML::DOMStringManager *)v52->pFreeStringNodes;
        v52->pFreeStringNodes = v49;
      }
      v22->Prefix.pNode = v48;
      v54 = *(Scaleform::GFx::XML::DOMStringNode **)(v45 + 24);
      ++v54->RefCount;
      v55 = v22->Namespace.pNode;
      v18 = v55->RefCount-- == 1;
      if ( v18 )
      {
        key = v55;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v55->pManager->StringSet.pTable,
          &key);
        v58 = v55->pManager;
        v59 = (char *)v55->pData;
        if ( v55->pData )
        {
          if ( v55->Size >= 0x10 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v59,
              v56,
              v57,
              v110.pNode,
              v111);
          }
          else
          {
            *(_QWORD *)v59 = v58->pFreeTextBuffers;
            v58->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v59;
          }
          v55->pData = 0i64;
        }
        v55->pManager = (Scaleform::GFx::XML::DOMStringManager *)v58->pFreeStringNodes;
        v58->pFreeStringNodes = v55;
      }
      v22->Namespace.pNode = v54;
      if ( v47 )
        Scaleform::RefCountNTSImpl::Release(v47);
      v60 = (Scaleform::RefCountNTSImpl *)v45;
      goto LABEL_120;
    }
  }
LABEL_70:
  v61 = v118;
  v62 = Scaleform::GFx::XML::ObjectManager::CreateString(v118, &v117, v38->pData, (unsigned __int64)v38->pManager)->pNode;
  ++v62->RefCount;
  v63 = v22->Prefix.pNode;
  v18 = v63->RefCount-- == 1;
  if ( v18 )
  {
    key = v63;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v63->pManager->StringSet.pTable,
      &key);
    v66 = v63->pManager;
    v67 = (char *)v63->pData;
    if ( v63->pData )
    {
      if ( v63->Size >= 0x10 )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v67,
          v64,
          v65,
          v110.pNode,
          v111);
      }
      else
      {
        *(_QWORD *)v67 = v66->pFreeTextBuffers;
        v66->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v67;
      }
      v63->pData = 0i64;
    }
    v63->pManager = (Scaleform::GFx::XML::DOMStringManager *)v66->pFreeStringNodes;
    v66->pFreeStringNodes = v63;
  }
  v22->Prefix.pNode = v62;
  v68 = v117.pNode;
  v18 = v117.pNode->RefCount == 1;
  --v68->RefCount;
  if ( v18 )
  {
    key = v68;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v68->pManager->StringSet.pTable,
      &key);
    v71 = v68->pManager;
    v72 = (char *)v68->pData;
    if ( v68->pData )
    {
      if ( v68->Size >= 0x10 )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v72,
          v69,
          v70,
          v110.pNode,
          v111);
      }
      else
      {
        *(_QWORD *)v72 = v71->pFreeTextBuffers;
        v71->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v72;
      }
      v68->pData = 0i64;
    }
    v68->pManager = (Scaleform::GFx::XML::DOMStringManager *)v71->pFreeStringNodes;
    v71->pFreeStringNodes = v68;
  }
  v73 = Scaleform::GFx::XML::ObjectManager::EmptyString(v61, &v117)->pNode;
  ++v73->RefCount;
  v74 = v22->Namespace.pNode;
  v18 = v74->RefCount-- == 1;
  if ( v18 )
  {
    key = v74;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v74->pManager->StringSet.pTable,
      &key);
    v77 = v74->pManager;
    v78 = (char *)v74->pData;
    if ( v74->pData )
    {
      if ( v74->Size >= 0x10 )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v78,
          v75,
          v76,
          v110.pNode,
          v111);
      }
      else
      {
        *(_QWORD *)v78 = v77->pFreeTextBuffers;
        v77->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v78;
      }
      v74->pData = 0i64;
    }
    v74->pManager = (Scaleform::GFx::XML::DOMStringManager *)v77->pFreeStringNodes;
    v77->pFreeStringNodes = v74;
  }
  v22->Namespace.pNode = v73;
  v79 = v117.pNode;
  v18 = v117.pNode->RefCount == 1;
  --v79->RefCount;
  if ( v18 )
  {
    key = v79;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      (Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *)&v79->pManager->StringSet.pTable,
      &key);
    v82 = v79->pManager;
    v83 = (char *)v79->pData;
    if ( v79->pData )
    {
      if ( v79->Size >= 0x10 )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *, char *, __int64, __int64, Scaleform::GFx::XML::DOMStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v83,
          v80,
          v81,
          v110.pNode,
          v111);
      }
      else
      {
        *(_QWORD *)v83 = v82->pFreeTextBuffers;
        v82->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v83;
      }
      v79->pData = 0i64;
    }
    v79->pManager = (Scaleform::GFx::XML::DOMStringManager *)v82->pFreeStringNodes;
    v82->pFreeStringNodes = v79;
  }
LABEL_122:
  v102 = *((_QWORD *)v6 + 11) + 8i64 * *((_QWORD *)v6 + 12);
  v103 = *(_QWORD *)(v102 - 8);
  if ( v103 )
    ++*(_DWORD *)(v103 + 8);
  v104 = *(_QWORD *)(v102 - 8);
  key = (Scaleform::GFx::XML::DOMStringNode *)v104;
  v105 = *(Scaleform::GFx::XML::Node **)(v104 + 112);
  if ( v105 )
  {
    v22->PrevSibling = v105;
    v107 = *(_QWORD *)(v104 + 112);
    ++v22->RefCount;
    v108 = *(Scaleform::RefCountNTSImpl **)(v107 + 48);
    if ( v108 )
      Scaleform::RefCountNTSImpl::Release(v108);
    *(_QWORD *)(v107 + 48) = v22;
  }
  else
  {
    if ( v22 )
      ++v22->RefCount;
    v106 = *(Scaleform::RefCountNTSImpl **)(v104 + 104);
    if ( v106 )
      Scaleform::RefCountNTSImpl::Release(v106);
    *(_QWORD *)(v104 + 104) = v22;
  }
  *(_QWORD *)(v104 + 112) = v22;
  v22->Parent = (Scaleform::GFx::XML::ElementNode *)v104;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)(v6 + 88),
    v6 + 88,
    *((_QWORD *)v6 + 12) + 1i64);
  v109 = (Scaleform::GFx::XML::DOMStringNode *)(*((_QWORD *)v6 + 11) + 8 * (*((_QWORD *)v6 + 12) - 1i64));
  v117.pNode = v109;
  result.pNode = v109;
  if ( v109 )
  {
    ++v22->RefCount;
    v109->pData = (const char *)v22;
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v104);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v22->vfptr);
  if ( v61 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v61->vfptr);
}eform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v61->vfptr);
}

// File Line: 402
// RVA: 0x8C8540
void __fastcall Scaleform::GFx::XML::DOMBuilder::EndElement(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::StringDataPtr *prefix, Scaleform::StringDataPtr *localname)
{
  Scaleform::GFx::XML::DOMBuilder *v3; // rbp
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *v4; // r12
  Scaleform::GFx::XML::ElementNode *v5; // rax
  Scaleform::GFx::XML::ElementNode *v6; // r12
  Scaleform::GFx::XML::Document *v7; // rbx
  Scaleform::GFx::XML::ObjectManager *v8; // rax
  Scaleform::GFx::XML::ObjectManager *v9; // rbx
  const char *v10; // r8
  Scaleform::GFx::XML::DOMString *v11; // rax
  Scaleform::GFx::XML::TextNode *v12; // rsi
  Scaleform::GFx::XML::DOMStringNode *v13; // rdi
  Scaleform::GFx::XML::DOMStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::XML::DOMStringNode *v16; // rcx
  Scaleform::RefCountNTSImpl *v17; // rcx
  unsigned __int64 v18; // rax
  int v19; // eax
  __int64 v20; // rsi
  signed __int64 v21; // r14
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v22; // rax
  Scaleform::GFx::XML::Prefix *v23; // rcx
  Scaleform::RefCountNTSImpl *v24; // rdi
  Scaleform::GFx::XML::ElementNode *v25; // rcx
  Scaleform::RefCountNTSImpl *v26; // rbx
  signed __int64 v27; // rcx
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v28; // rax
  Scaleform::GFx::XML::Prefix *v29; // rdx
  Scaleform::RefCountNTSImpl *v30; // rdi
  __int64 v31; // rdx
  Scaleform::RefCountNTSImpl *v32; // rbx
  unsigned __int64 v33; // rdi
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *v34; // rax
  Scaleform::GFx::XML::DOMStringNode *v35; // rdx
  signed __int64 v36; // rbx
  Scaleform::GFx::XML::DOMString result; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::XML::ElementNode *v38; // [rsp+98h] [rbp+20h]

  v3 = this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v4 = &this->ParseStack.Data.Data[this->ParseStack.Data.Size];
  v5 = v4[-1].pObject;
  if ( v5 )
    ++v5->RefCount;
  v6 = v4[-1].pObject;
  v38 = v6;
  if ( this->pAppendChainRoot.pObject )
  {
    v7 = this->pDoc.pObject;
    v8 = v7->MemoryManager.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = v7->MemoryManager.pObject;
    Scaleform::GFx::XML::ElementNode::AppendChild(
      v6,
      (Scaleform::GFx::XML::Node *)&this->pAppendChainRoot.pObject->vfptr);
    v10 = &customWorldMapCaption;
    if ( v3->AppendText.pData )
      v10 = v3->AppendText.pData;
    v11 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, v10, v3->AppendText.Size);
    v12 = v3->pAppendChainRoot.pObject;
    v13 = v11->pNode;
    ++v13->RefCount;
    v14 = v12->Value.pNode;
    v15 = v14->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v14);
    v12->Value.pNode = v13;
    v16 = result.pNode;
    v15 = result.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v15 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v16);
    v17 = (Scaleform::RefCountNTSImpl *)&v3->pAppendChainRoot.pObject->vfptr;
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    v3->pAppendChainRoot.pObject = 0i64;
    Scaleform::StringBuffer::Clear(&v3->AppendText);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
  }
  v18 = v3->PrefixNamespaceStack.Data.Size;
  if ( v18 )
  {
    v19 = v18 - 1;
    v20 = v19;
    if ( v19 >= 0 )
    {
      v21 = v19;
      while ( 1 )
      {
        v22 = v3->PrefixNamespaceStack.Data.Data;
        v23 = v22[v21].mPrefix.pObject;
        if ( v23 )
          ++v23->RefCount;
        v24 = (Scaleform::RefCountNTSImpl *)&v22[v21].mPrefix.pObject->vfptr;
        v25 = v22[v21].Owner.pObject;
        if ( v25 )
          ++v25->RefCount;
        v26 = (Scaleform::RefCountNTSImpl *)&v22[v21].Owner.pObject->vfptr;
        if ( v26 != (Scaleform::RefCountNTSImpl *)v6 )
          break;
        Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &v3->PrefixNamespaceStack.Data,
          v3->PrefixNamespaceStack.Data.Size - 1);
        if ( v26 )
          Scaleform::RefCountNTSImpl::Release(v26);
        if ( v24 )
          Scaleform::RefCountNTSImpl::Release(v24);
        --v21;
        if ( --v20 < 0 )
          goto LABEL_34;
      }
      if ( v26 )
        Scaleform::RefCountNTSImpl::Release(v26);
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
    }
  }
LABEL_34:
  if ( v3->DefaultNamespaceStack.Data.Size )
  {
    v27 = v3->DefaultNamespaceStack.Data.Size;
    v28 = v3->DefaultNamespaceStack.Data.Data;
    v29 = v28[v3->DefaultNamespaceStack.Data.Size - 1].mPrefix.pObject;
    if ( v29 )
      ++v29->RefCount;
    v30 = (Scaleform::RefCountNTSImpl *)&v28[v27 - 1].mPrefix.pObject->vfptr;
    v31 = *((_QWORD *)&v28[v27] - 1);
    if ( v31 )
      ++*(_DWORD *)(v31 + 8);
    v32 = (Scaleform::RefCountNTSImpl *)*((_QWORD *)&v28[v27] - 1);
    if ( v32 == (Scaleform::RefCountNTSImpl *)v6 )
      Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v3->DefaultNamespaceStack.Data,
        v3->DefaultNamespaceStack.Data.Size - 1);
    if ( v32 )
      Scaleform::RefCountNTSImpl::Release(v32);
    if ( v30 )
      Scaleform::RefCountNTSImpl::Release(v30);
  }
  v33 = v3->ParseStack.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->ParseStack,
    &v3->ParseStack,
    v33 - 1);
  if ( v33 - 1 > v33 )
  {
    v34 = v3->ParseStack.Data.Data;
    v35 = (Scaleform::GFx::XML::DOMStringNode *)&v34[v33];
    result.pNode = (Scaleform::GFx::XML::DOMStringNode *)&v34[v33];
    v36 = -1i64;
    do
    {
      if ( v35 )
        v35->pData = 0i64;
      v35 = (Scaleform::GFx::XML::DOMStringNode *)((char *)v35 + 8);
      result.pNode = v35;
      --v36;
    }
    while ( v36 );
  }
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v6->vfptr);
}

// File Line: 471
// RVA: 0x8F0A70
void __fastcall Scaleform::GFx::XML::DOMBuilder::PrefixMapping(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::StringDataPtr *prefix, Scaleform::StringDataPtr *uri)
{
  Scaleform::StringDataPtr *v3; // r14
  Scaleform::GFx::XML::DOMBuilder *v4; // rdi
  Scaleform::GFx::XML::Document *v5; // rsi
  Scaleform::GFx::XML::ObjectManager *v6; // rax
  Scaleform::GFx::XML::ObjectManager *v7; // rsi
  Scaleform::GFx::XML::DOMString *v8; // rbx
  Scaleform::GFx::XML::DOMString *v9; // rax
  Scaleform::GFx::XML::Prefix *v10; // rbx
  Scaleform::GFx::XML::DOMStringNode *v11; // rax
  Scaleform::GFx::XML::DOMStringNode *v12; // rax
  Scaleform::GFx::XML::DOMStringNode *v13; // rax
  Scaleform::GFx::XML::DOMStringNode *v14; // rax
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership val; // [rsp+40h] [rbp-10h]
  Scaleform::GFx::XML::DOMString result; // [rsp+80h] [rbp+30h]
  Scaleform::GFx::XML::DOMString v17; // [rsp+88h] [rbp+38h]
  Scaleform::GFx::XML::ObjectManager *v18; // [rsp+90h] [rbp+40h]
  Scaleform::GFx::XML::DOMString *v19; // [rsp+98h] [rbp+48h]

  v3 = prefix;
  v4 = this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v5 = this->pDoc.pObject;
  v6 = v5->MemoryManager.pObject;
  if ( v6 )
    ++v6->RefCount;
  v7 = v5->MemoryManager.pObject;
  v18 = v7;
  v19 = &result;
  v8 = Scaleform::GFx::XML::ObjectManager::CreateString(v7, &result, uri->pStr, uri->Size);
  v9 = Scaleform::GFx::XML::ObjectManager::CreateString(v7, &v17, v3->pStr, v3->Size);
  v10 = Scaleform::GFx::XML::ObjectManager::CreatePrefix(
          v7,
          (Scaleform::GFx::XML::DOMString)v9,
          (Scaleform::GFx::XML::DOMString)v8);
  result.pNode = 0i64;
  v19 = &result;
  if ( v3->Size )
  {
    if ( v10 )
      ++v10->RefCount;
    v17.pNode = (Scaleform::GFx::XML::DOMStringNode *)v10;
    v11 = (Scaleform::GFx::XML::DOMStringNode *)v10;
    if ( v10 )
    {
      ++LODWORD(v17.pNode->pManager);
      v11 = v17.pNode;
    }
    val.mPrefix.pObject = (Scaleform::GFx::XML::Prefix *)v11;
    v12 = result.pNode;
    if ( result.pNode )
    {
      ++LODWORD(result.pNode->pManager);
      v12 = result.pNode;
    }
    val.Owner.pObject = (Scaleform::GFx::XML::ElementNode *)v12;
    if ( v17.pNode )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v17.pNode);
    if ( result.pNode )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)result.pNode);
    Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &v4->PrefixNamespaceStack.Data,
      &val);
    if ( val.Owner.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&val.Owner.pObject->vfptr);
  }
  else
  {
    if ( v10 )
      ++v10->RefCount;
    v17.pNode = (Scaleform::GFx::XML::DOMStringNode *)v10;
    v13 = (Scaleform::GFx::XML::DOMStringNode *)v10;
    if ( v10 )
    {
      ++LODWORD(v17.pNode->pManager);
      v13 = v17.pNode;
    }
    val.mPrefix.pObject = (Scaleform::GFx::XML::Prefix *)v13;
    v14 = result.pNode;
    if ( result.pNode )
    {
      ++LODWORD(result.pNode->pManager);
      v14 = result.pNode;
    }
    val.Owner.pObject = (Scaleform::GFx::XML::ElementNode *)v14;
    if ( v17.pNode )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v17.pNode);
    if ( result.pNode )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)result.pNode);
    Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &v4->DefaultNamespaceStack.Data,
      &val);
    if ( val.Owner.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&val.Owner.pObject->vfptr);
  }
  if ( val.mPrefix.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&val.mPrefix.pObject->vfptr);
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
}

// File Line: 517
// RVA: 0x8BA520
void __fastcall Scaleform::GFx::XML::DOMBuilder::Characters(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::StringDataPtr *text)
{
  Scaleform::StringDataPtr *v2; // rsi
  Scaleform::GFx::XML::DOMBuilder *v3; // rbx
  Scaleform::GFx::XML::Document *v4; // rdi
  Scaleform::GFx::XML::ObjectManager *v5; // rax
  Scaleform::GFx::XML::ObjectManager *v6; // rdi
  Scaleform::GFx::XML::DOMString *v7; // rax
  Scaleform::GFx::XML::TextNode *v8; // rbp
  Scaleform::RefCountNTSImpl *v9; // rcx
  Scaleform::StringBuffer *v10; // rcx
  __int64 v11; // r8
  const char *v12; // rdx
  Scaleform::GFx::XML::DOMString result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::XML::ObjectManager *v14; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::XML::DOMString *v15; // [rsp+68h] [rbp+20h]

  v2 = text;
  v3 = this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v4 = this->pDoc.pObject;
  v5 = v4->MemoryManager.pObject;
  if ( v5 )
    ++v5->RefCount;
  v6 = v4->MemoryManager.pObject;
  v14 = v6;
  if ( this->pAppendChainRoot.pObject )
  {
    v10 = &this->AppendText;
    v11 = text->Size;
    v12 = text->pStr;
  }
  else
  {
    v15 = &result;
    v7 = Scaleform::GFx::XML::ObjectManager::EmptyString(v6, &result);
    v8 = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v6, (Scaleform::GFx::XML::DOMString)v7);
    v9 = (Scaleform::RefCountNTSImpl *)&v3->pAppendChainRoot.pObject->vfptr;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v3->pAppendChainRoot.pObject = v8;
    v10 = &v3->AppendText;
    v11 = v2->Size;
    v12 = v2->pStr;
  }
  Scaleform::StringBuffer::AppendString(v10, v12, v11);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v6->vfptr);
}

// File Line: 610
// RVA: 0x8BD260
void __fastcall Scaleform::GFx::XML::DOMBuilder::Comment(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::GFx::XML::ParserException *exception)
{
  this->LoadedBytes = this->pLocator->LoadedBytes;
}

// File Line: 632
// RVA: 0x8C8B40
void __fastcall Scaleform::GFx::XML::DOMBuilder::FatalError(Scaleform::GFx::XML::DOMBuilder *this, Scaleform::GFx::XML::ParserException *exception)
{
  unsigned __int64 v2; // rdx

  v2 = this->pLocator->LoadedBytes;
  this->bError = 1;
  this->LoadedBytes = v2;
}

// File Line: 711
// RVA: 0x8BB1A0
char __fastcall Scaleform::GFx::XML::CheckWhiteSpaceNode(Scaleform::GFx::XML::TextNode *textNode)
{
  unsigned int v1; // eax
  unsigned __int16 v2; // cx
  int v3; // eax
  int v4; // er8
  int v5; // ecx
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  putf8Buffer = (char *)textNode->Value.pNode->pData;
  while ( 1 )
  {
    v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v2 = v1;
    if ( !v1 )
      break;
    v3 = Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)v1 >> 8];
    if ( Scaleform::UnicodeSpaceBits[(unsigned __int64)v2 >> 8] )
    {
      if ( v3 == 1 )
        continue;
      v4 = v2 & 0xF;
      v5 = Scaleform::UnicodeSpaceBits[v3 + (((unsigned int)v2 >> 4) & 0xF)];
      if ( _bittest(&v5, v4) )
        continue;
    }
    return 0;
  }
  return 1;
}

// File Line: 730
// RVA: 0x8C7EC0
void __fastcall Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(Scaleform::GFx::XML::ElementNode *elemNode)
{
  Scaleform::GFx::XML::ElementNode *v1; // rbx
  Scaleform::GFx::XML::ElementNode *v2; // rsi
  char v3; // al
  Scaleform::GFx::XML::ElementNode *v4; // rdi

  v1 = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
  v2 = elemNode;
  if ( v1 )
  {
    do
    {
      v3 = v1->Type;
      v4 = (Scaleform::GFx::XML::ElementNode *)v1->NextSibling.pObject;
      if ( v3 == 1 )
      {
        Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(v1);
      }
      else if ( v3 == 3 )
      {
        if ( Scaleform::GFx::XML::CheckWhiteSpaceNode((Scaleform::GFx::XML::TextNode *)v1) )
          Scaleform::GFx::XML::ElementNode::RemoveChild(v2, (Scaleform::GFx::XML::Node *)&v1->vfptr);
      }
      v1 = v4;
    }
    while ( v4 );
  }
}

// File Line: 757
// RVA: 0x8C7DC0
void __fastcall Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(Scaleform::GFx::XML::Document *document)
{
  Scaleform::GFx::XML::ElementNode *i; // rsi
  Scaleform::GFx::XML::Node *v2; // rbx
  char v3; // al
  Scaleform::GFx::XML::Node *v4; // rdi
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ecx
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  for ( i = (Scaleform::GFx::XML::ElementNode *)document->FirstChild.pObject;
        i;
        i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
  {
    if ( i->Type == 1 )
    {
      v2 = i->FirstChild.pObject;
      if ( v2 )
      {
        do
        {
          v3 = v2->Type;
          v4 = v2->NextSibling.pObject;
          if ( v3 == 1 )
          {
            Scaleform::GFx::XML::DropWhiteSpaceNodesHelper((Scaleform::GFx::XML::ElementNode *)v2);
          }
          else if ( v3 == 3 )
          {
            putf8Buffer = (char *)v2->Value.pNode->pData;
            while ( 1 )
            {
              v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
              if ( !v5 )
                break;
              v6 = Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)v5 >> 8];
              if ( Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)v5 >> 8] )
              {
                if ( v6 == 1 )
                  continue;
                v7 = Scaleform::UnicodeSpaceBits[v6 + ((unsigned __int8)v5 >> 4)];
                if ( _bittest(&v7, v5 & 0xF) )
                  continue;
              }
              goto LABEL_14;
            }
            --putf8Buffer;
            Scaleform::GFx::XML::ElementNode::RemoveChild(i, v2);
          }
LABEL_14:
          v2 = v4;
        }
        while ( v4 );
      }
    }
  }
}

