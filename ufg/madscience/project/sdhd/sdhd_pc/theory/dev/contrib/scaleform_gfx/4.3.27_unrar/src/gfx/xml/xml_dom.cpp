// File Line: 131
// RVA: 0x8952D0
void __fastcall Scaleform::GFx::XML::DOMBuilder::DOMBuilder(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser,
        bool ignorews)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::XML::ParserHandler,326>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::XML::ParserHandler::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::XML::DOMBuilder::`vftable;
  if ( pxmlParser.pObject->vfptr )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pxmlParser.pObject->vfptr);
  this->pXMLParserState.pObject = (Scaleform::GFx::XML::SupportBase *)pxmlParser.pObject->vfptr;
  this->pAppendChainRoot.pObject = 0i64;
  Scaleform::StringBuffer::StringBuffer(&this->AppendText, Scaleform::Memory::pGlobalHeap);
  this->pLocator = 0i64;
  this->ParseStack.Data.Data = 0i64;
  this->ParseStack.Data.Size = 0i64;
  this->ParseStack.Data.Policy.Capacity = 0i64;
  this->PrefixNamespaceStack.Data.Data = 0i64;
  this->PrefixNamespaceStack.Data.Size = 0i64;
  this->PrefixNamespaceStack.Data.Policy.Capacity = 0i64;
  this->DefaultNamespaceStack.Data.Data = 0i64;
  this->DefaultNamespaceStack.Data.Size = 0i64;
  this->DefaultNamespaceStack.Data.Policy.Capacity = 0i64;
  this->pDoc.pObject = 0i64;
  this->bIgnoreWhitespace = ignorews;
  this->bError = 0;
  if ( pxmlParser.pObject->vfptr )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pxmlParser.pObject->vfptr);
}

// File Line: 176
// RVA: 0x8EF4F0
Scaleform::Ptr<Scaleform::GFx::XML::Document> *__fastcall Scaleform::GFx::XML::DOMBuilder::ParseString(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::Ptr<Scaleform::GFx::XML::Document> *result,
        const char *pdata,
        unsigned __int64 len,
        Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> objMgr)
{
  Scaleform::GFx::XML::ObjectManager *v9; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v10; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v11; // rbp
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbp
  Scaleform::GFx::XML::Document *v13; // rax
  Scaleform::GFx::XML::Document *v14; // rax
  Scaleform::GFx::XML::Document *v15; // rbp
  Scaleform::GFx::XML::Document *pObject; // rcx
  Scaleform::GFx::XML::SupportBase *v17; // rcx
  Scaleform::GFx::XML::Document *v18; // rax
  Scaleform::GFx::XML::Document *v19; // rcx
  Scaleform::GFx::XML::Document *v21; // [rsp+30h] [rbp-38h]

  this->bError = 0;
  this->TotalBytesToLoad = 0i64;
  this->LoadedBytes = 0i64;
  if ( !objMgr.pObject->vfptr )
  {
    v9 = (Scaleform::GFx::XML::ObjectManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 120i64,
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
  vfptr = objMgr.pObject->vfptr;
  v13 = (Scaleform::GFx::XML::Document *)(*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int), __int64, _QWORD))(*(_QWORD *)objMgr.pObject->vfptr[14].__vecDelDtor + 80i64))(
                                           objMgr.pObject->vfptr[14].__vecDelDtor,
                                           144i64,
                                           0i64);
  v21 = v13;
  if ( v13 )
  {
    Scaleform::GFx::XML::Document::Document(v13, (Scaleform::GFx::XML::ObjectManager *)vfptr);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  pObject = this->pDoc.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pDoc.pObject = v15;
  v17 = this->pXMLParserState.pObject;
  if ( v17 )
    this->bError = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::XML::SupportBase *, const char *, unsigned __int64, Scaleform::GFx::XML::DOMBuilder *, _DWORD, __int64, Scaleform::GFx::XML::Document *))v17->vfptr[2].__vecDelDtor)(
                     v17,
                     pdata,
                     len,
                     this,
                     0,
                     -2i64,
                     v21) == 0;
  v18 = this->pDoc.pObject;
  if ( v18 )
    ++v18->RefCount;
  result->pObject = (Scaleform::GFx::XML::Document *)this->pDoc;
  v19 = this->pDoc.pObject;
  if ( v19 )
    Scaleform::RefCountNTSImpl::Release(v19);
  this->pDoc.pObject = 0i64;
  if ( result->pObject && this->bIgnoreWhitespace )
    Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(result->pObject);
  if ( objMgr.pObject->vfptr )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)objMgr.pObject->vfptr);
  return result;
}

// File Line: 207
// RVA: 0x910FE0
void __fastcall Scaleform::GFx::XML::DOMBuilder::StartDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::Document *pObject; // rax
  Scaleform::GFx::XML::Document *v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *v4; // rdx

  pObject = this->pDoc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v3 = this->pDoc.pObject;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack,
    &this->ParseStack,
    this->ParseStack.Data.Size + 1);
  v4 = &this->ParseStack.Data.Data[this->ParseStack.Data.Size - 1];
  if ( v4 )
  {
    if ( v3 )
      ++v3->RefCount;
    v4->pObject = v3;
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  this->TotalBytesToLoad = this->pLocator->TotalBytesToLoad;
}

// File Line: 225
// RVA: 0x8C8420
void __fastcall Scaleform::GFx::XML::DOMBuilder::EndDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::Document *pObject; // rdi
  Scaleform::GFx::XML::ObjectManager *v3; // rax
  Scaleform::GFx::XML::ObjectManager *v4; // rdi
  Scaleform::GFx::XML::DOMString *v5; // rax
  Scaleform::GFx::XML::Document *v6; // rbp
  Scaleform::GFx::XML::DOMStringNode *pNode; // rsi
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::XML::DOMStringNode *v10; // rcx
  Scaleform::GFx::XML::DOMString *v11; // rax
  Scaleform::GFx::XML::Document *v12; // rbp
  Scaleform::GFx::XML::DOMStringNode *v13; // rsi
  Scaleform::GFx::XML::DOMStringNode *v14; // rcx
  Scaleform::GFx::XML::DOMStringNode *v15; // rcx
  Scaleform::GFx::XML::DOMString result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::XML::ObjectManager *v17; // [rsp+58h] [rbp+10h]

  this->LoadedBytes = this->pLocator->LoadedBytes;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack,
    &this->ParseStack,
    0i64);
  pObject = this->pDoc.pObject;
  v3 = pObject->MemoryManager.pObject;
  if ( v3 )
    ++v3->RefCount;
  v4 = pObject->MemoryManager.pObject;
  v17 = v4;
  v5 = Scaleform::GFx::XML::ObjectManager::CreateString(
         v4,
         &result,
         this->pLocator->XMLVersion.pStr,
         this->pLocator->XMLVersion.Size);
  v6 = this->pDoc.pObject;
  pNode = v5->pNode;
  ++v5->pNode->RefCount;
  v8 = v6->XMLVersion.pNode;
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
  v6->XMLVersion.pNode = pNode;
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v10);
  v11 = Scaleform::GFx::XML::ObjectManager::CreateString(
          v4,
          &result,
          this->pLocator->Encoding.pStr,
          this->pLocator->Encoding.Size);
  v12 = this->pDoc.pObject;
  v13 = v11->pNode;
  ++v11->pNode->RefCount;
  v14 = v12->Encoding.pNode;
  v9 = v14->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v14);
  v12->Encoding.pNode = v13;
  v15 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v15);
  this->pDoc.pObject->Standalone = this->pLocator->StandAlone;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
}

// File Line: 275
// RVA: 0x911070
void __fastcall Scaleform::GFx::XML::DOMBuilder::StartElement(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::GFx::XML::DOMStringNode *prefix,
        Scaleform::StringDataPtr *localname,
        Scaleform::GFx::XML::ParserAttributes *atts)
{
  char *v6; // r14
  Scaleform::GFx::XML::Document *pObject; // rcx
  Scaleform::GFx::XML::ObjectManager *v8; // rax
  Scaleform::GFx::XML::ObjectManager *v9; // rdi
  __int64 v10; // rbx
  __int64 v11; // rax
  Scaleform::GFx::XML::DOMStringNode *v12; // rbx
  const char *v13; // r8
  Scaleform::GFx::XML::DOMString *v14; // rax
  __int64 v15; // r15
  Scaleform::GFx::XML::DOMStringNode *pNode; // rdi
  Scaleform::GFx::XML::DOMStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::XML::DOMStringNode *v19; // rcx
  Scaleform::RefCountNTSImpl *v20; // rcx
  Scaleform::GFx::XML::DOMString *v21; // rax
  Scaleform::GFx::XML::ElementNode *ElementNode; // rsi
  unsigned __int64 v23; // r15
  __int64 v24; // r12
  Scaleform::GFx::XML::ObjectManager *v25; // r14
  Scaleform::GFx::XML::ParserAttribute *v26; // rbx
  Scaleform::GFx::XML::DOMString *v27; // rdi
  Scaleform::GFx::XML::DOMString *v28; // rax
  Scaleform::GFx::XML::Attribute *Attribute; // rax
  __int64 v30; // rax
  int v31; // eax
  __int64 v32; // rdi
  __int64 v33; // r15
  __int64 v34; // rbx
  Scaleform::RefCountNTSImpl *v35; // rcx
  __int64 v36; // rbx
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::GFx::XML::DOMStringNode *v38; // r13
  __int64 v39; // rax
  int v40; // eax
  __int64 v41; // r12
  __int64 v42; // r15
  __int64 v43; // rax
  __int64 v44; // rcx
  Scaleform::GFx::XML::DOMString *v45; // rbx
  __int64 v46; // rcx
  Scaleform::RefCountNTSImpl *v47; // rdi
  Scaleform::GFx::XML::DOMStringNode *v48; // r12
  Scaleform::GFx::XML::DOMStringNode *v49; // r15
  Scaleform::GFx::XML::DOMStringManager *v50; // r13
  char *v51; // rdx
  Scaleform::GFx::XML::DOMStringNode *v52; // r12
  Scaleform::GFx::XML::DOMStringNode *v53; // r15
  Scaleform::GFx::XML::DOMStringManager *v54; // r13
  char *v55; // rdx
  Scaleform::RefCountNTSImpl *v56; // rcx
  Scaleform::GFx::XML::ObjectManager *v57; // r12
  Scaleform::GFx::XML::DOMString *v58; // rax
  Scaleform::GFx::XML::DOMStringNode *v59; // r15
  Scaleform::GFx::XML::DOMStringNode *v60; // rbx
  Scaleform::GFx::XML::DOMStringManager *v61; // rdi
  char *v62; // rdx
  Scaleform::GFx::XML::DOMStringNode *v63; // rbx
  Scaleform::GFx::XML::DOMStringManager *v64; // rdi
  char *v65; // rdx
  Scaleform::GFx::XML::DOMString *v66; // rax
  Scaleform::GFx::XML::DOMStringNode *v67; // r15
  Scaleform::GFx::XML::DOMStringNode *v68; // rbx
  Scaleform::GFx::XML::DOMStringManager *v69; // rdi
  char *v70; // rdx
  Scaleform::GFx::XML::DOMStringNode *v71; // rbx
  Scaleform::GFx::XML::DOMStringManager *v72; // rdi
  char *v73; // rdx
  __int64 v74; // rcx
  __int64 v75; // rax
  __int64 v76; // rdx
  Scaleform::GFx::XML::DOMString *v77; // rdi
  __int64 v78; // rdx
  Scaleform::RefCountNTSImpl *v79; // r13
  Scaleform::GFx::XML::DOMStringNode *v80; // r12
  Scaleform::GFx::XML::DOMStringNode *v81; // rbx
  Scaleform::GFx::XML::DOMStringManager *pManager; // r15
  char *pData; // rdx
  Scaleform::GFx::XML::DOMStringNode *v84; // r12
  Scaleform::GFx::XML::DOMStringNode *v85; // rbx
  Scaleform::GFx::XML::DOMStringManager *v86; // r15
  char *v87; // rdx
  __int64 v88; // rbx
  __int64 v89; // rax
  __int64 v90; // rbx
  Scaleform::GFx::XML::Node *v91; // rax
  Scaleform::RefCountNTSImpl *v92; // rcx
  __int64 v93; // rdi
  Scaleform::RefCountNTSImpl *v94; // rcx
  Scaleform::GFx::XML::DOMStringNode *v95; // rdx
  Scaleform::GFx::XML::DOMString v96; // [rsp+20h] [rbp-38h] BYREF
  __int64 v97; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::XML::ElementNode *v98; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::XML::DOMString *p_result; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::XML::DOMString *v100; // [rsp+40h] [rbp-18h]
  Scaleform::RefCountNTSImpl *v101; // [rsp+48h] [rbp-10h]
  Scaleform::GFx::XML::DOMStringNode *key; // [rsp+A0h] [rbp+48h] BYREF
  Scaleform::GFx::XML::DOMString v103; // [rsp+A8h] [rbp+50h] BYREF
  Scaleform::GFx::XML::ObjectManager *v104; // [rsp+B0h] [rbp+58h]
  Scaleform::GFx::XML::DOMString result; // [rsp+B8h] [rbp+60h] BYREF

  v103.pNode = prefix;
  key = (Scaleform::GFx::XML::DOMStringNode *)this;
  v97 = -2i64;
  v6 = (char *)this;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  pObject = this->pDoc.pObject;
  v8 = pObject->MemoryManager.pObject;
  if ( v8 )
    ++v8->RefCount;
  v9 = pObject->MemoryManager.pObject;
  v104 = v9;
  if ( *((_QWORD *)v6 + 3) )
  {
    v10 = *((_QWORD *)v6 + 11) + 8i64 * *((_QWORD *)v6 + 12);
    v11 = *(_QWORD *)(v10 - 8);
    if ( v11 )
      ++*(_DWORD *)(v11 + 8);
    v12 = *(Scaleform::GFx::XML::DOMStringNode **)(v10 - 8);
    v96.pNode = v12;
    Scaleform::GFx::XML::ElementNode::AppendChild(
      (Scaleform::GFx::XML::ElementNode *)v12,
      *((Scaleform::GFx::XML::Node **)v6 + 3));
    v13 = &customCaption;
    if ( *((_QWORD *)v6 + 4) )
      v13 = (const char *)*((_QWORD *)v6 + 4);
    v14 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, v13, *((_QWORD *)v6 + 5));
    v15 = *((_QWORD *)v6 + 3);
    pNode = v14->pNode;
    ++v14->pNode->RefCount;
    v17 = *(Scaleform::GFx::XML::DOMStringNode **)(v15 + 24);
    v18 = v17->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v17);
    *(_QWORD *)(v15 + 24) = pNode;
    v19 = result.pNode;
    v18 = result.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v19);
    v20 = (Scaleform::RefCountNTSImpl *)*((_QWORD *)v6 + 3);
    if ( v20 )
      Scaleform::RefCountNTSImpl::Release(v20);
    *((_QWORD *)v6 + 3) = 0i64;
    Scaleform::StringBuffer::Clear((Scaleform::StringBuffer *)(v6 + 32));
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v12);
    v9 = v104;
  }
  v96.pNode = (Scaleform::GFx::XML::DOMStringNode *)&result;
  v21 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, localname->pStr, localname->Size);
  ElementNode = Scaleform::GFx::XML::ObjectManager::CreateElementNode(v9, (Scaleform::GFx::XML::DOMString)v21);
  v98 = ElementNode;
  v23 = 0i64;
  if ( atts->Length )
  {
    p_result = &result;
    v100 = &v96;
    v24 = 0i64;
    v25 = v104;
    do
    {
      v26 = &atts->Attributes[v24];
      v27 = Scaleform::GFx::XML::ObjectManager::CreateString(v25, &result, v26->Value.pStr, v26->Value.Size);
      v28 = Scaleform::GFx::XML::ObjectManager::CreateString(v25, &v96, v26->Name.pStr, v26->Name.Size);
      Attribute = Scaleform::GFx::XML::ObjectManager::CreateAttribute(
                    v25,
                    (Scaleform::GFx::XML::DOMString)v28,
                    (Scaleform::GFx::XML::DOMString)v27);
      if ( ElementNode->FirstAttribute )
        ElementNode->LastAttribute->Next = Attribute;
      else
        ElementNode->FirstAttribute = Attribute;
      ElementNode->LastAttribute = Attribute;
      ++v23;
      ++v24;
    }
    while ( v23 < atts->Length );
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
        if ( ElementNode )
          ++ElementNode->RefCount;
        v35 = *(Scaleform::RefCountNTSImpl **)(v34 + v33 + 8);
        if ( v35 )
          Scaleform::RefCountNTSImpl::Release(v35);
        *(_QWORD *)(v34 + v33 + 8) = ElementNode;
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
      if ( ElementNode )
        ++ElementNode->RefCount;
      v37 = *(Scaleform::RefCountNTSImpl **)(v36 - 8);
      if ( v37 )
        Scaleform::RefCountNTSImpl::Release(v37);
      *(_QWORD *)(v36 - 8) = ElementNode;
    }
  }
  v38 = v103.pNode;
  if ( !v103.pNode->pManager )
  {
    if ( !*((_QWORD *)v6 + 18) )
    {
LABEL_121:
      v57 = v104;
      goto LABEL_122;
    }
    v74 = 2i64 * *((_QWORD *)v6 + 18);
    v75 = *((_QWORD *)v6 + 17);
    v76 = *(_QWORD *)(v75 + 16i64 * *((_QWORD *)v6 + 18) - 16);
    if ( v76 )
      ++*(_DWORD *)(v76 + 8);
    v77 = *(Scaleform::GFx::XML::DOMString **)(v75 + 8 * v74 - 16);
    v100 = v77;
    v78 = *(_QWORD *)(v75 + 8 * v74 - 8);
    if ( v78 )
      ++*(_DWORD *)(v78 + 8);
    v79 = *(Scaleform::RefCountNTSImpl **)(v75 + 8 * v74 - 8);
    v101 = v79;
    v80 = v77[2].pNode;
    ++v80->RefCount;
    v81 = ElementNode->Prefix.pNode;
    v18 = v81->RefCount-- == 1;
    if ( v18 )
    {
      key = v81;
      Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
        &v81->pManager->StringSet,
        &key);
      pManager = v81->pManager;
      pData = (char *)v81->pData;
      if ( v81->pData )
      {
        if ( v81->Size >= 0x10 )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          *(_QWORD *)pData = pManager->pFreeTextBuffers;
          pManager->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pData;
        }
        v81->pData = 0i64;
      }
      v81->pManager = (Scaleform::GFx::XML::DOMStringManager *)pManager->pFreeStringNodes;
      pManager->pFreeStringNodes = v81;
    }
    ElementNode->Prefix.pNode = v80;
    v84 = v77[3].pNode;
    ++v84->RefCount;
    v85 = ElementNode->Namespace.pNode;
    v18 = v85->RefCount-- == 1;
    if ( v18 )
    {
      key = v85;
      Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
        &v85->pManager->StringSet,
        &key);
      v86 = v85->pManager;
      v87 = (char *)v85->pData;
      if ( v85->pData )
      {
        if ( v85->Size >= 0x10 )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          *(_QWORD *)v87 = v86->pFreeTextBuffers;
          v86->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v87;
        }
        v85->pData = 0i64;
      }
      v85->pManager = (Scaleform::GFx::XML::DOMStringManager *)v86->pFreeStringNodes;
      v86->pFreeStringNodes = v85;
    }
    ElementNode->Namespace.pNode = v84;
    if ( v79 )
      Scaleform::RefCountNTSImpl::Release(v79);
    v56 = (Scaleform::RefCountNTSImpl *)v77;
LABEL_120:
    Scaleform::RefCountNTSImpl::Release(v56);
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
        v45 = *(Scaleform::GFx::XML::DOMString **)(v42 + v43);
        v100 = v45;
        v46 = *(_QWORD *)(v42 + v43 + 8);
        if ( v46 )
          ++*(_DWORD *)(v46 + 8);
        v47 = *(Scaleform::RefCountNTSImpl **)(v42 + v43 + 8);
        v101 = v47;
        if ( !strncmp(v45[2].pNode->pData, v38->pData, (size_t)v38->pManager) )
          break;
        if ( v47 )
          Scaleform::RefCountNTSImpl::Release(v47);
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v45);
        v42 -= 16i64;
        if ( --v41 < 0 )
          goto LABEL_70;
      }
      v48 = v45[2].pNode;
      ++v48->RefCount;
      v49 = ElementNode->Prefix.pNode;
      v18 = v49->RefCount-- == 1;
      if ( v18 )
      {
        key = v49;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &v49->pManager->StringSet,
          &key);
        v50 = v49->pManager;
        v51 = (char *)v49->pData;
        if ( v49->pData )
        {
          if ( v49->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v51 = v50->pFreeTextBuffers;
            v50->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v51;
          }
          v49->pData = 0i64;
        }
        v49->pManager = (Scaleform::GFx::XML::DOMStringManager *)v50->pFreeStringNodes;
        v50->pFreeStringNodes = v49;
      }
      ElementNode->Prefix.pNode = v48;
      v52 = v45[3].pNode;
      ++v52->RefCount;
      v53 = ElementNode->Namespace.pNode;
      v18 = v53->RefCount-- == 1;
      if ( v18 )
      {
        key = v53;
        Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
          &v53->pManager->StringSet,
          &key);
        v54 = v53->pManager;
        v55 = (char *)v53->pData;
        if ( v53->pData )
        {
          if ( v53->Size >= 0x10 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          else
          {
            *(_QWORD *)v55 = v54->pFreeTextBuffers;
            v54->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v55;
          }
          v53->pData = 0i64;
        }
        v53->pManager = (Scaleform::GFx::XML::DOMStringManager *)v54->pFreeStringNodes;
        v54->pFreeStringNodes = v53;
      }
      ElementNode->Namespace.pNode = v52;
      if ( v47 )
        Scaleform::RefCountNTSImpl::Release(v47);
      v56 = (Scaleform::RefCountNTSImpl *)v45;
      goto LABEL_120;
    }
  }
LABEL_70:
  v57 = v104;
  v58 = Scaleform::GFx::XML::ObjectManager::CreateString(v104, &v103, v38->pData, (unsigned __int64)v38->pManager);
  v59 = v58->pNode;
  ++v58->pNode->RefCount;
  v60 = ElementNode->Prefix.pNode;
  v18 = v60->RefCount-- == 1;
  if ( v18 )
  {
    key = v60;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v60->pManager->StringSet,
      &key);
    v61 = v60->pManager;
    v62 = (char *)v60->pData;
    if ( v60->pData )
    {
      if ( v60->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        *(_QWORD *)v62 = v61->pFreeTextBuffers;
        v61->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v62;
      }
      v60->pData = 0i64;
    }
    v60->pManager = (Scaleform::GFx::XML::DOMStringManager *)v61->pFreeStringNodes;
    v61->pFreeStringNodes = v60;
  }
  ElementNode->Prefix.pNode = v59;
  v63 = v103.pNode;
  v18 = v103.pNode->RefCount-- == 1;
  if ( v18 )
  {
    key = v63;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v63->pManager->StringSet,
      &key);
    v64 = v63->pManager;
    v65 = (char *)v63->pData;
    if ( v63->pData )
    {
      if ( v63->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        *(_QWORD *)v65 = v64->pFreeTextBuffers;
        v64->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v65;
      }
      v63->pData = 0i64;
    }
    v63->pManager = (Scaleform::GFx::XML::DOMStringManager *)v64->pFreeStringNodes;
    v64->pFreeStringNodes = v63;
  }
  v66 = Scaleform::GFx::XML::ObjectManager::EmptyString(v57, &v103);
  v67 = v66->pNode;
  ++v66->pNode->RefCount;
  v68 = ElementNode->Namespace.pNode;
  v18 = v68->RefCount-- == 1;
  if ( v18 )
  {
    key = v68;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v68->pManager->StringSet,
      &key);
    v69 = v68->pManager;
    v70 = (char *)v68->pData;
    if ( v68->pData )
    {
      if ( v68->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        *(_QWORD *)v70 = v69->pFreeTextBuffers;
        v69->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v70;
      }
      v68->pData = 0i64;
    }
    v68->pManager = (Scaleform::GFx::XML::DOMStringManager *)v69->pFreeStringNodes;
    v69->pFreeStringNodes = v68;
  }
  ElementNode->Namespace.pNode = v67;
  v71 = v103.pNode;
  v18 = v103.pNode->RefCount-- == 1;
  if ( v18 )
  {
    key = v71;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v71->pManager->StringSet,
      &key);
    v72 = v71->pManager;
    v73 = (char *)v71->pData;
    if ( v71->pData )
    {
      if ( v71->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        *(_QWORD *)v73 = v72->pFreeTextBuffers;
        v72->pFreeTextBuffers = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v73;
      }
      v71->pData = 0i64;
    }
    v71->pManager = (Scaleform::GFx::XML::DOMStringManager *)v72->pFreeStringNodes;
    v72->pFreeStringNodes = v71;
  }
LABEL_122:
  v88 = *((_QWORD *)v6 + 11) + 8i64 * *((_QWORD *)v6 + 12);
  v89 = *(_QWORD *)(v88 - 8);
  if ( v89 )
    ++*(_DWORD *)(v89 + 8);
  v90 = *(_QWORD *)(v88 - 8);
  key = (Scaleform::GFx::XML::DOMStringNode *)v90;
  v91 = *(Scaleform::GFx::XML::Node **)(v90 + 112);
  if ( v91 )
  {
    ElementNode->PrevSibling = v91;
    v93 = *(_QWORD *)(v90 + 112);
    ++ElementNode->RefCount;
    v94 = *(Scaleform::RefCountNTSImpl **)(v93 + 48);
    if ( v94 )
      Scaleform::RefCountNTSImpl::Release(v94);
    *(_QWORD *)(v93 + 48) = ElementNode;
  }
  else
  {
    if ( ElementNode )
      ++ElementNode->RefCount;
    v92 = *(Scaleform::RefCountNTSImpl **)(v90 + 104);
    if ( v92 )
      Scaleform::RefCountNTSImpl::Release(v92);
    *(_QWORD *)(v90 + 104) = ElementNode;
  }
  *(_QWORD *)(v90 + 112) = ElementNode;
  ElementNode->Parent = (Scaleform::GFx::XML::ElementNode *)v90;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)(v6 + 88),
    v6 + 88,
    *((_QWORD *)v6 + 12) + 1i64);
  v95 = (Scaleform::GFx::XML::DOMStringNode *)(*((_QWORD *)v6 + 11) + 8 * (*((_QWORD *)v6 + 12) - 1i64));
  v103.pNode = v95;
  result.pNode = v95;
  if ( v95 )
  {
    ++ElementNode->RefCount;
    v95->pData = (const char *)ElementNode;
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v90);
  Scaleform::RefCountNTSImpl::Release(ElementNode);
  if ( v57 )
    Scaleform::RefCountNTSImpl::Release(v57);
}

// File Line: 402
// RVA: 0x8C8540
void __fastcall Scaleform::GFx::XML::DOMBuilder::EndElement(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::StringDataPtr *prefix,
        Scaleform::StringDataPtr *localname)
{
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *v4; // r12
  Scaleform::GFx::XML::ElementNode *pObject; // rax
  Scaleform::GFx::XML::ElementNode *v6; // r12
  Scaleform::GFx::XML::Document *v7; // rbx
  Scaleform::GFx::XML::ObjectManager *v8; // rax
  Scaleform::GFx::XML::ObjectManager *v9; // rbx
  char *pData; // r8
  Scaleform::GFx::XML::DOMString *v11; // rax
  Scaleform::GFx::XML::TextNode *v12; // rsi
  Scaleform::GFx::XML::DOMStringNode *pNode; // rdi
  Scaleform::GFx::XML::DOMStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::XML::DOMStringNode *v16; // rcx
  Scaleform::GFx::XML::TextNode *v17; // rcx
  unsigned __int64 Size; // rax
  int v19; // eax
  __int64 v20; // rsi
  __int64 v21; // r14
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *Data; // rax
  Scaleform::GFx::XML::Prefix *v23; // rcx
  Scaleform::RefCountNTSImpl *v24; // rdi
  Scaleform::GFx::XML::ElementNode *v25; // rcx
  Scaleform::RefCountNTSImpl *v26; // rbx
  unsigned __int64 v27; // rcx
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v28; // rax
  Scaleform::GFx::XML::Prefix *v29; // rdx
  Scaleform::RefCountNTSImpl *v30; // rdi
  Scaleform::GFx::XML::ElementNode *v31; // rdx
  Scaleform::RefCountNTSImpl *v32; // rbx
  unsigned __int64 v33; // rdi
  Scaleform::GFx::XML::DOMStringNode *v34; // rdx
  __int64 v35; // rbx
  Scaleform::GFx::XML::DOMString result; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::XML::ElementNode *v37; // [rsp+98h] [rbp+20h]

  this->LoadedBytes = this->pLocator->LoadedBytes;
  v4 = &this->ParseStack.Data.Data[this->ParseStack.Data.Size];
  pObject = v4[-1].pObject;
  if ( pObject )
    ++pObject->RefCount;
  v6 = v4[-1].pObject;
  v37 = v6;
  if ( this->pAppendChainRoot.pObject )
  {
    v7 = this->pDoc.pObject;
    v8 = v7->MemoryManager.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = v7->MemoryManager.pObject;
    Scaleform::GFx::XML::ElementNode::AppendChild(v6, this->pAppendChainRoot.pObject);
    pData = &customCaption;
    if ( this->AppendText.pData )
      pData = this->AppendText.pData;
    v11 = Scaleform::GFx::XML::ObjectManager::CreateString(v9, &result, pData, this->AppendText.Size);
    v12 = this->pAppendChainRoot.pObject;
    pNode = v11->pNode;
    ++v11->pNode->RefCount;
    v14 = v12->Value.pNode;
    v15 = v14->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v14);
    v12->Value.pNode = pNode;
    v16 = result.pNode;
    v15 = result.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v16);
    v17 = this->pAppendChainRoot.pObject;
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    this->pAppendChainRoot.pObject = 0i64;
    Scaleform::StringBuffer::Clear(&this->AppendText);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
  Size = this->PrefixNamespaceStack.Data.Size;
  if ( Size )
  {
    v19 = Size - 1;
    v20 = v19;
    if ( v19 >= 0 )
    {
      v21 = v19;
      while ( 1 )
      {
        Data = this->PrefixNamespaceStack.Data.Data;
        v23 = Data[v21].mPrefix.pObject;
        if ( v23 )
          ++v23->RefCount;
        v24 = Data[v21].mPrefix.pObject;
        v25 = Data[v21].Owner.pObject;
        if ( v25 )
          ++v25->RefCount;
        v26 = Data[v21].Owner.pObject;
        if ( v26 != v6 )
          break;
        Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->PrefixNamespaceStack.Data,
          this->PrefixNamespaceStack.Data.Size - 1);
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
  if ( this->DefaultNamespaceStack.Data.Size )
  {
    v27 = this->DefaultNamespaceStack.Data.Size;
    v28 = this->DefaultNamespaceStack.Data.Data;
    v29 = v28[this->DefaultNamespaceStack.Data.Size - 1].mPrefix.pObject;
    if ( v29 )
      ++v29->RefCount;
    v30 = v28[v27 - 1].mPrefix.pObject;
    v31 = v28[v27 - 1].Owner.pObject;
    if ( v31 )
      ++v31->RefCount;
    v32 = v28[v27 - 1].Owner.pObject;
    if ( v32 == v6 )
      Scaleform::ArrayData<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->DefaultNamespaceStack.Data,
        this->DefaultNamespaceStack.Data.Size - 1);
    if ( v32 )
      Scaleform::RefCountNTSImpl::Release(v32);
    if ( v30 )
      Scaleform::RefCountNTSImpl::Release(v30);
  }
  v33 = this->ParseStack.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack,
    &this->ParseStack,
    v33 - 1);
  if ( v33 - 1 > v33 )
  {
    v34 = (Scaleform::GFx::XML::DOMStringNode *)&this->ParseStack.Data.Data[v33];
    result.pNode = v34;
    v35 = -1i64;
    do
    {
      if ( v34 )
        v34->pData = 0i64;
      v34 = (Scaleform::GFx::XML::DOMStringNode *)((char *)v34 + 8);
      result.pNode = v34;
      --v35;
    }
    while ( v35 );
  }
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
}

// File Line: 471
// RVA: 0x8F0A70
void __fastcall Scaleform::GFx::XML::DOMBuilder::PrefixMapping(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::StringDataPtr *prefix,
        Scaleform::StringDataPtr *uri)
{
  Scaleform::GFx::XML::Document *pObject; // rsi
  Scaleform::GFx::XML::ObjectManager *v6; // rax
  Scaleform::GFx::XML::ObjectManager *v7; // rsi
  Scaleform::GFx::XML::DOMString *v8; // rbx
  Scaleform::GFx::XML::DOMString *v9; // rax
  Scaleform::GFx::XML::Prefix *v10; // rbx
  Scaleform::GFx::XML::DOMStringNode *pNode; // rax
  Scaleform::GFx::XML::DOMStringNode *v12; // rax
  Scaleform::GFx::XML::DOMStringNode *v13; // rax
  Scaleform::GFx::XML::DOMStringNode *v14; // rax
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership val; // [rsp+40h] [rbp-10h] BYREF
  Scaleform::GFx::XML::DOMString result; // [rsp+80h] [rbp+30h] BYREF
  Scaleform::GFx::XML::DOMString v17; // [rsp+88h] [rbp+38h] BYREF
  Scaleform::GFx::XML::ObjectManager *v18; // [rsp+90h] [rbp+40h]
  Scaleform::GFx::XML::DOMString *p_result; // [rsp+98h] [rbp+48h]

  this->LoadedBytes = this->pLocator->LoadedBytes;
  pObject = this->pDoc.pObject;
  v6 = pObject->MemoryManager.pObject;
  if ( v6 )
    ++v6->RefCount;
  v7 = pObject->MemoryManager.pObject;
  v18 = v7;
  p_result = &result;
  v8 = Scaleform::GFx::XML::ObjectManager::CreateString(v7, &result, uri->pStr, uri->Size);
  v9 = Scaleform::GFx::XML::ObjectManager::CreateString(v7, &v17, prefix->pStr, prefix->Size);
  v10 = Scaleform::GFx::XML::ObjectManager::CreatePrefix(
          v7,
          (Scaleform::GFx::XML::DOMString)v9,
          (Scaleform::GFx::XML::DOMString)v8);
  result.pNode = 0i64;
  p_result = &result;
  if ( prefix->Size )
  {
    if ( v10 )
      ++v10->RefCount;
    v17.pNode = (Scaleform::GFx::XML::DOMStringNode *)v10;
    pNode = (Scaleform::GFx::XML::DOMStringNode *)v10;
    if ( v10 )
    {
      ++LODWORD(v17.pNode->pManager);
      pNode = v17.pNode;
    }
    val.mPrefix.pObject = (Scaleform::GFx::XML::Prefix *)pNode;
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
      &this->PrefixNamespaceStack.Data,
      &val);
    if ( val.Owner.pObject )
      Scaleform::RefCountNTSImpl::Release(val.Owner.pObject);
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
      &this->DefaultNamespaceStack.Data,
      &val);
    if ( val.Owner.pObject )
      Scaleform::RefCountNTSImpl::Release(val.Owner.pObject);
  }
  if ( val.mPrefix.pObject )
    Scaleform::RefCountNTSImpl::Release(val.mPrefix.pObject);
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
}aleform::RefCountNTSImpl::Release(v10);
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(

// File Line: 517
// RVA: 0x8BA520
void __fastcall Scaleform::GFx::XML::DOMBuilder::Characters(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::StringDataPtr *text)
{
  Scaleform::GFx::XML::Document *pObject; // rdi
  Scaleform::GFx::XML::ObjectManager *v5; // rax
  Scaleform::GFx::XML::ObjectManager *v6; // rdi
  Scaleform::GFx::XML::DOMString *v7; // rax
  Scaleform::GFx::XML::TextNode *TextNode; // rbp
  Scaleform::GFx::XML::TextNode *v9; // rcx
  Scaleform::StringBuffer *p_AppendText; // rcx
  __int64 Size; // r8
  const char *pStr; // rdx
  Scaleform::GFx::XML::DOMString result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::XML::ObjectManager *v14; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::XML::DOMString *p_result; // [rsp+68h] [rbp+20h]

  this->LoadedBytes = this->pLocator->LoadedBytes;
  pObject = this->pDoc.pObject;
  v5 = pObject->MemoryManager.pObject;
  if ( v5 )
    ++v5->RefCount;
  v6 = pObject->MemoryManager.pObject;
  v14 = v6;
  if ( this->pAppendChainRoot.pObject )
  {
    p_AppendText = &this->AppendText;
    Size = text->Size;
    pStr = text->pStr;
  }
  else
  {
    p_result = &result;
    v7 = Scaleform::GFx::XML::ObjectManager::EmptyString(v6, &result);
    TextNode = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v6, (Scaleform::GFx::XML::DOMString)v7);
    v9 = this->pAppendChainRoot.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    this->pAppendChainRoot.pObject = TextNode;
    p_AppendText = &this->AppendText;
    Size = text->Size;
    pStr = text->pStr;
  }
  Scaleform::StringBuffer::AppendString(p_AppendText, pStr, Size);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
}

// File Line: 610
// RVA: 0x8BD260
void __fastcall Scaleform::GFx::XML::DOMBuilder::Comment(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::GFx::XML::ParserException *exception)
{
  this->LoadedBytes = this->pLocator->LoadedBytes;
}

// File Line: 632
// RVA: 0x8C8B40
void __fastcall Scaleform::GFx::XML::DOMBuilder::FatalError(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::GFx::XML::ParserException *exception)
{
  unsigned __int64 LoadedBytes; // rdx

  LoadedBytes = this->pLocator->LoadedBytes;
  this->bError = 1;
  this->LoadedBytes = LoadedBytes;
}

// File Line: 711
// RVA: 0x8BB1A0
char __fastcall Scaleform::GFx::XML::CheckWhiteSpaceNode(Scaleform::GFx::XML::TextNode *textNode)
{
  unsigned int Char_Advance0; // eax
  unsigned __int16 v2; // cx
  int v3; // eax
  int v4; // r8d
  int v5; // ecx
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  putf8Buffer = (char *)textNode->Value.pNode->pData;
  while ( 1 )
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v2 = Char_Advance0;
    if ( !Char_Advance0 )
      break;
    v3 = Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)Char_Advance0 >> 8];
    if ( Scaleform::UnicodeSpaceBits[(unsigned __int64)v2 >> 8] )
    {
      if ( v3 == 1 )
        continue;
      v4 = v2 & 0xF;
      v5 = Scaleform::UnicodeSpaceBits[v3 + ((v2 >> 4) & 0xF)];
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
  Scaleform::GFx::XML::ElementNode *pObject; // rbx
  char Type; // al
  Scaleform::GFx::XML::ElementNode *v4; // rdi

  pObject = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
  if ( pObject )
  {
    do
    {
      Type = pObject->Type;
      v4 = (Scaleform::GFx::XML::ElementNode *)pObject->NextSibling.pObject;
      if ( Type == 1 )
      {
        Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(pObject);
      }
      else if ( Type == 3 )
      {
        if ( Scaleform::GFx::XML::CheckWhiteSpaceNode((Scaleform::GFx::XML::TextNode *)pObject) )
          Scaleform::GFx::XML::ElementNode::RemoveChild(elemNode, pObject);
      }
      pObject = v4;
    }
    while ( v4 );
  }
}

// File Line: 757
// RVA: 0x8C7DC0
void __fastcall Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(Scaleform::GFx::XML::Document *document)
{
  Scaleform::GFx::XML::ElementNode *i; // rsi
  Scaleform::GFx::XML::ElementNode *pObject; // rbx
  char Type; // al
  Scaleform::GFx::XML::ElementNode *v4; // rdi
  unsigned int Char_Advance0; // eax
  int v6; // ecx
  int v7; // ecx
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  for ( i = (Scaleform::GFx::XML::ElementNode *)document->FirstChild.pObject;
        i;
        i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
  {
    if ( i->Type == 1 )
    {
      pObject = (Scaleform::GFx::XML::ElementNode *)i->FirstChild.pObject;
      if ( pObject )
      {
        do
        {
          Type = pObject->Type;
          v4 = (Scaleform::GFx::XML::ElementNode *)pObject->NextSibling.pObject;
          if ( Type == 1 )
          {
            Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(pObject);
          }
          else if ( Type == 3 )
          {
            putf8Buffer = (char *)pObject->Value.pNode->pData;
            while ( 1 )
            {
              Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
              if ( !Char_Advance0 )
                break;
              v6 = Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)Char_Advance0 >> 8];
              if ( Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)Char_Advance0 >> 8] )
              {
                if ( v6 == 1 )
                  continue;
                v7 = Scaleform::UnicodeSpaceBits[v6 + ((unsigned __int8)Char_Advance0 >> 4)];
                if ( _bittest(&v7, Char_Advance0 & 0xF) )
                  continue;
              }
              goto LABEL_14;
            }
            --putf8Buffer;
            Scaleform::GFx::XML::ElementNode::RemoveChild(i, pObject);
          }
LABEL_14:
          pObject = v4;
        }
        while ( v4 );
      }
    }
  }
}

