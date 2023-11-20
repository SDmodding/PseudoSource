// File Line: 37
// RVA: 0x78CF20
void __fastcall Scaleform::GFx::AS3::NamespaceArray::~NamespaceArray(Scaleform::GFx::AS3::NamespaceArray *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)this);
}

// File Line: 41
// RVA: 0x7AFB20
void __fastcall Scaleform::GFx::AS3::NamespaceArray::AddUnique(Scaleform::GFx::AS3::NamespaceArray *this, Scaleform::GFx::AS3::NamespaceArray *other)
{
  Scaleform::GFx::AS3::NamespaceArray *v2; // r14
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbx
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v9; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v10; // rdx
  unsigned int v11; // eax

  v2 = other;
  v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this;
  v4 = other->Namespaces.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    do
    {
      v6 = v2->Namespaces.Data.Data[v5].pObject;
      v7 = 0i64;
      v8 = v3->Size;
      if ( v8 )
      {
        v9 = v3->Data;
        while ( v9->pObject->Text.pNode != v6->Uri.pNode
             || (*((_BYTE *)v6 + 40) ^ LOBYTE(v9->pObject->pTraits.pObject)) & 0xF )
        {
          ++v7;
          ++v9;
          if ( v7 >= v8 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v3,
          v3[1].Data,
          v3->Size + 1);
        v10 = &v3->Data[v3->Size - 1];
        if ( v10 )
        {
          v10->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v6;
          if ( v6 )
            v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v6 && !((unsigned __int8)v6 & 1) )
        {
          v11 = v6->RefCount;
          if ( v11 & 0x3FFFFF )
          {
            v6->RefCount = v11 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
          }
        }
      }
      ++v5;
    }
    while ( v5 < v4 );
  }
}

// File Line: 96
// RVA: 0x7AADA0
void __fastcall Scaleform::GFx::AS3::NamespaceArray::Add(Scaleform::GFx::AS3::NamespaceArray *this, Scaleform::GFx::AS3::Instances::fl::Namespace *other, bool checkUnique)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rbx
  Scaleform::GFx::AS3::NamespaceArray *v4; // rdi
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v8; // rdx
  unsigned int v9; // eax

  v3 = other;
  v4 = this;
  if ( checkUnique && (v5 = 0i64, (v6 = this->Namespaces.Data.Size) != 0) )
  {
    v7 = this->Namespaces.Data.Data;
    while ( v7->pObject->Uri.pNode != v3->Uri.pNode || (*((_BYTE *)v3 + 40) ^ *((_BYTE *)v7->pObject + 40)) & 0xF )
    {
      ++v5;
      ++v7;
      if ( v5 >= v6 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( v3 )
      v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this->Namespaces.Data.pHeap,
      this->Namespaces.Data.Size + 1);
    v8 = &v4->Namespaces.Data.Data[v4->Namespaces.Data.Size - 1];
    if ( v8 )
    {
      v8->pObject = v3;
      if ( v3 )
        v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( v3 && !((unsigned __int8)v3 & 1) )
    {
      v9 = v3->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v3->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
    }
  }
}

// File Line: 127
// RVA: 0x785460
void __fastcall Scaleform::GFx::AS3::XMLParser::XMLParser(Scaleform::GFx::AS3::XMLParser *this, Scaleform::GFx::AS3::InstanceTraits::fl::XML *itr)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v2; // rbx
  Scaleform::GFx::AS3::XMLParser *v3; // rdi
  Scaleform::MemoryHeap *v4; // rcx
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v6; // rbx
  Scaleform::GFx::AS3::Class *v7; // rbx
  signed __int64 v8; // [rsp+58h] [rbp+10h]
  signed __int64 v9; // [rsp+58h] [rbp+10h]

  v2 = itr;
  v3 = this;
  this->NsSep = 58;
  this->NodeKind = 0;
  this->ITr = itr;
  this->Parser = (struct XML_ParserStruct *)XML_ParserCreate(0i64);
  v3->pCurrElem.pObject = 0i64;
  v4 = v2->pVM->MHeap;
  v8 = (signed __int64)&v3->RootElements;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v3->RootElements.Data.pHeap = v4;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pVM->StringManagerRef->Builtins,
    &v3->Text);
  v5 = v2->pVM->MHeap;
  v9 = (signed __int64)&v3->KindStack;
  *(_OWORD *)v9 = 0ui64;
  *(_QWORD *)(v9 + 16) = 0i64;
  v3->KindStack.Data.pHeap = v5;
  XML_SetUserData(v3->Parser, v3);
  XML_SetElementHandler(
    v3->Parser,
    Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback,
    Scaleform::GFx::AS3::XMLParser::EndElementExpatCallback);
  XML_SetCharacterDataHandler(v3->Parser, Scaleform::GFx::AS3::XMLParser::CharacterDataExpatCallback);
  XML_SetXmlDeclHandler(v3->Parser, Scaleform::GFx::AS3::XMLParser::DeclExpatCallback);
  XML_SetDoctypeDeclHandler(
    v3->Parser,
    Scaleform::GFx::AS3::XMLParser::StartDoctypeDeclExpatCallback,
    Scaleform::GFx::AS3::XMLParser::EndDoctypeDeclExpatCallback);
  XML_SetDefaultHandler(v3->Parser, _);
  v6 = v3->ITr;
  if ( !v6->pConstructor.pObject )
    v6->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->ITr->vfptr);
  v7 = v6->pConstructor.pObject;
  if ( !LOBYTE(v7[1].vfptr) )
    XML_SetCommentHandler(v3->Parser, Scaleform::GFx::AS3::XMLParser::CommentExpatCallback);
  if ( !BYTE1(v7[1].vfptr) )
    XML_SetProcessingInstructionHandler(v3->Parser, Scaleform::GFx::AS3::XMLParser::ProcessingInstructionExpatCallback);
}

// File Line: 150
// RVA: 0x790040
void __fastcall Scaleform::GFx::AS3::XMLParser::~XMLParser(Scaleform::GFx::AS3::XMLParser *this)
{
  Scaleform::GFx::AS3::XMLParser *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  XML_ParserFree(this->Parser);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->KindStack.Data.Data);
  v2 = v1->Text.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->RootElements);
  v4 = v1->pCurrElem.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->pCurrElem.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 155
// RVA: 0x81A8B0
void __fastcall Scaleform::GFx::AS3::XMLParser::SetNodeKind(Scaleform::GFx::AS3::XMLParser *this, Scaleform::GFx::AS3::XMLParser::Kind k)
{
  Scaleform::GFx::AS3::XMLParser::Kind v2; // ebp
  Scaleform::GFx::AS3::XMLParser *v3; // rdi
  Scaleform::GFx::AS3::XMLParser::Kind v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rsi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rsi
  _QWORD *v11; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rcx
  unsigned int v15; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v20; // [rsp+98h] [rbp+20h]

  v2 = k;
  v3 = this;
  v4 = this->NodeKind;
  if ( v4 != k )
  {
    if ( v4 == 2 )
    {
      v5 = this->ITr;
      if ( !v5->pConstructor.pObject )
        v5->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->ITr->vfptr);
      if ( BYTE2(v5->pConstructor.pObject[1].vfptr) )
      {
        v6 = Scaleform::GFx::ASString::TruncateWhitespace(&v3->Text, &result)->pNode;
        ++v6->RefCount;
        v7 = v3->Text.pNode;
        v8 = v7->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        v3->Text.pNode = v6;
        v9 = result.pNode;
        v8 = result.pNode->RefCount == 1;
        --v9->RefCount;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
      if ( v3->Text.pNode->Size )
      {
        v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->pCurrElem;
        v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                             v3->ITr,
                                                             &v20,
                                                             (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v3->ITr->vfptr,
                                                             &v3->Text,
                                                             v3->pCurrElem.pObject)->pV->vfptr;
        if ( v3->pCurrElem.pObject && ((unsigned int (*)(void))v3->pCurrElem.pObject->vfptr[8].Finalize_GC)() == 1 )
        {
          ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*v10)->vfptr[7].Finalize_GC)(
            *v10,
            &v18);
        }
        else
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->RootElements.Data.Data,
            v3->RootElements.Data.pHeap,
            v3->RootElements.Data.Size + 1);
          v11 = &v3->RootElements.Data.Data[v3->RootElements.Data.Size - 1].pObject;
          if ( v11 )
          {
            *v11 = v18;
            v12 = v18;
            if ( v18 )
            {
              ++v18->RefCount;
              v12->RefCount &= 0x8FBFFFFF;
            }
          }
          if ( &v18 != v10 )
          {
            v13 = v18;
            if ( v18 )
            {
              ++v18->RefCount;
              v13->RefCount &= 0x8FBFFFFF;
              v13 = v18;
            }
            v14 = *v10;
            if ( *v10 )
            {
              if ( (unsigned __int8)v14 & 1 )
              {
                *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v14 - 1);
              }
              else
              {
                v15 = v14->RefCount;
                if ( v15 & 0x3FFFFF )
                {
                  v14->RefCount = v15 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
                  v13 = v18;
                }
              }
            }
            *v10 = v13;
          }
        }
        Scaleform::GFx::ASString::Clear(&v3->Text);
        v16 = v18;
        if ( v18 )
        {
          if ( (unsigned __int8)v18 & 1 )
          {
            v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v18 - 1);
          }
          else
          {
            v17 = v18->RefCount;
            if ( v17 & 0x3FFFFF )
            {
              v18->RefCount = v17 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
            }
          }
        }
      }
    }
    v3->NodeKind = v2;
  }
}

// File Line: 195
// RVA: 0x8060C0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLParser::Parse(Scaleform::GFx::AS3::XMLParser *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::StringDataPtr *str, unsigned __int64 *pos, bool isList)
{
  unsigned __int64 *v5; // r14
  Scaleform::StringDataPtr *v6; // r15
  Scaleform::GFx::AS3::CheckResult *v7; // r12
  Scaleform::GFx::AS3::XMLParser *v8; // rsi
  unsigned __int64 v9; // rbp
  int v10; // eax
  bool v11; // r13
  int v12; // eax
  __int64 v13; // r8
  Scaleform::GFx::AS3::VM::ErrorID v14; // edi
  unsigned __int64 v15; // rbx
  __int64 v16; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v17; // rcx
  unsigned __int64 v18; // rcx
  const char *v19; // rdx
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::AS3::VM::Error v24; // [rsp+28h] [rbp-50h]
  char v25; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+90h] [rbp+18h]

  v5 = pos;
  v6 = str;
  v7 = result;
  v8 = this;
  v9 = *pos;
  v10 = XML_Parse(this->Parser, &str->pStr[*pos], (unsigned int)str->Size - (unsigned int)*pos, 1i64, -2i64);
  v11 = v10 == 1;
  v25 = 1;
  if ( v10 == 1 )
    goto LABEL_38;
  v12 = XML_GetErrorCode(v8->Parser);
  vm = v8->ITr->pVM;
  v14 = 1090;
  v15 = 0i64;
  v16 = 0i64;
  if ( v8->KindStack.Data.Size )
    v16 = (unsigned int)v8->KindStack.Data.Data[v8->KindStack.Data.Size - 1];
  LOBYTE(v13) = 1;
  switch ( v12 )
  {
    case 0:
      if ( *v5 != v9 )
        goto LABEL_35;
      v17 = v8->pCurrElem.pObject;
      if ( !v17 )
        goto LABEL_35;
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, __int64, __int64, signed __int64))v17->vfptr[8].Finalize_GC)(
             v17,
             v16,
             v13,
             5368709120i64) != 4 )
        goto LABEL_35;
      v18 = v6->Size - v9;
      if ( v6->Size == v9 )
        goto LABEL_35;
      v19 = v6->pStr;
      break;
    case 1:
      v14 = 1000;
      goto LABEL_35;
    case 3:
      if ( isList )
      {
        v25 = 0;
        LOBYTE(v13) = 0;
      }
      if ( v8->pCurrElem.pObject )
      {
        if ( (_DWORD)v16 == 1 )
        {
          v14 = 1085;
          if ( (_BYTE)v13 )
            goto LABEL_35;
        }
      }
      goto LABEL_37;
    case 4:
      if ( !v8->pCurrElem.pObject )
        goto LABEL_38;
      goto LABEL_35;
    case 5:
      v14 = 1097;
      goto LABEL_35;
    case 7:
      if ( (_DWORD)v16 == 1 )
        v14 = 1085;
      goto LABEL_35;
    case 8:
      v14 = 1104;
      goto LABEL_35;
    case 9:
      if ( isList )
      {
        v11 = 1;
        goto LABEL_38;
      }
      if ( v8->pCurrElem.pObject && (_DWORD)v16 == 1 )
        v14 = 1085;
      else
        v14 = 1088;
      goto LABEL_35;
    case 20:
      v14 = 1091;
      goto LABEL_35;
    case 35:
      goto $LN1_37;
    default:
      goto LABEL_35;
  }
  do
  {
    if ( v19[v15] == 63 && v15 + 1 < v18 && v19[v15 + 1] == 62 )
    {
      *v5 += v15 + 2;
      v7->Result = 1;
      return v7;
    }
    ++v15;
  }
  while ( v15 < v18 );
LABEL_35:
  Scaleform::GFx::AS3::VM::Error::Error(&v24, v14, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v21 = v24.Message.pNode;
  v22 = v24.Message.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
LABEL_37:
  if ( v25 )
LABEL_38:
    *v5 += (signed int)XML_GetCurrentByteIndex(v8->Parser);
$LN1_37:
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(v8, 0);
  v7->Result = v11;
  return v7;
}

// File Line: 357
// RVA: 0x7EF020
void __fastcall Scaleform::GFx::AS3::XMLParser::GetRootNodes(Scaleform::GFx::AS3::XMLParser *this, Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *nodes)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  Scaleform::GFx::AS3::XMLParser *v3; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v6; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // rax

  v2 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)nodes;
  v3 = this;
  v4 = 0i64;
  if ( this->RootElements.Data.Size )
  {
    do
    {
      v5 = &v3->RootElements.Data.Data[v4];
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v2,
        v2,
        v2->Size + 1);
      v6 = &v2->Data[v2->Size - 1];
      if ( v6 )
      {
        v7 = v5->pObject;
        v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)v5->pObject;
        if ( v7 )
          v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
      }
      ++v4;
    }
    while ( v4 < v3->RootElements.Data.Size );
  }
}

// File Line: 374
// RVA: 0x821830
void __fastcall Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback(void *userData, const char *name, const char **atts)
{
  Scaleform::GFx::ASStringNode *v3; // rsi
  const char *v4; // r13
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  __int64 v6; // r14
  int v7; // er12
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  Scaleform::GFx::ASStringNode *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v12; // rcx
  Scaleform::GFx::ASStringManager *v13; // rax
  __int64 v14; // r15
  _BYTE *v15; // rdi
  unsigned __int64 v16; // rbx
  const char *v17; // r8
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v18; // rdi
  Scaleform::GFx::ASStringNode *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  unsigned int v23; // er15
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v24; // rcx
  unsigned int v25; // ebx
  Scaleform::GFx::ASStringNode *v26; // rdi
  Scaleform::GFx::ASStringNode *v27; // rsi
  int v28; // ecx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v32; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v33; // rdx
  unsigned int v34; // eax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::VM::Error *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  char *v39; // rbx
  Scaleform::GFx::AS3::VM::Error *v40; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v42; // rsi
  Scaleform::GFx::ASStringNode *v43; // rbx
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::ASStringNode *v45; // rdi
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASStringNode *v48; // rbx
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASStringNode *v50; // rcx
  unsigned __int64 v51; // r15
  __int64 v52; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v53; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> **v54; // rax
  bool v55; // si
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::ASStringNode *v57; // rsi
  __int64 v58; // rcx
  __int64 v59; // rax
  __int64 v60; // rcx
  __int64 v61; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v62; // r13
  Scaleform::GFx::ASStringNode *v63; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v64; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v65; // rax
  unsigned __int64 v66; // r12
  unsigned __int64 v67; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v68; // r15
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v69; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v70; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v71; // r12
  Scaleform::GFx::ASStringNode *v72; // r15
  Scaleform::GFx::ASStringNode *v73; // r13
  __int64 v74; // rdi
  unsigned __int64 v75; // rax
  unsigned int v76; // er14
  char *v77; // rsi
  Scaleform::GFx::ASStringNode *v78; // rdi
  Scaleform::GFx::ASStringNode *v79; // rcx
  Scaleform::GFx::ASStringNode *v80; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v81; // rdi
  Scaleform::GFx::ASStringNode *v82; // rdi
  Scaleform::GFx::ASStringNode *v83; // rcx
  Scaleform::GFx::ASStringNode *v84; // rcx
  Scaleform::GFx::ASStringNode *v85; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace **v86; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v87; // rsi
  Scaleform::GFx::ASStringNode *v88; // rdx
  unsigned int v89; // eax
  Scaleform::GFx::ASStringNode *v90; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v91; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v92; // rcx
  unsigned int v93; // edx
  Scaleform::GFx::ASStringNode *v94; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v95; // rcx
  unsigned int v96; // eax
  Scaleform::GFx::AS3::VM::Error *v97; // rax
  Scaleform::GFx::ASStringNode *v98; // rcx
  Scaleform::GFx::ASStringNode *v99; // rcx
  Scaleform::GFx::ASStringNode *v100; // rcx
  unsigned __int64 v101; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **i; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v103; // rcx
  unsigned int v104; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *p; // [rsp+28h] [rbp-79h]
  Scaleform::GFx::ASString n; // [rsp+30h] [rbp-71h]
  int v107; // [rsp+38h] [rbp-69h]
  Scaleform::GFx::ASString v108; // [rsp+40h] [rbp-61h]
  Scaleform::GFx::AS3::VM::Error v109; // [rsp+48h] [rbp-59h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v110; // [rsp+58h] [rbp-49h]
  void *pheapAddr; // [rsp+70h] [rbp-31h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp-29h]
  Scaleform::GFx::AS3::Value prefix; // [rsp+80h] [rbp-21h]
  Scaleform::GFx::ASString v114; // [rsp+A0h] [rbp-1h]
  Scaleform::GFx::ASString uri; // [rsp+A8h] [rbp+7h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v116; // [rsp+B0h] [rbp+Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v117; // [rsp+B8h] [rbp+17h]
  __int64 v118; // [rsp+C0h] [rbp+1Fh]
  Scaleform::GFx::ASString v119; // [rsp+108h] [rbp+67h]
  Scaleform::GFx::ASString v; // [rsp+118h] [rbp+77h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v121; // [rsp+120h] [rbp+7Fh]

  v118 = -2i64;
  v3 = (Scaleform::GFx::ASStringNode *)atts;
  v4 = name;
  v5 = (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)userData;
  LODWORD(v6) = 0;
  v7 = 0;
  v107 = 0;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kElement);
  v8 = v5[3].Size + 1;
  if ( v8 >= v5[3].Size )
  {
    if ( v8 <= v5[3].Policy.Capacity )
      goto LABEL_7;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= v5[3].Policy.Capacity >> 1 )
      goto LABEL_7;
    v9 = v5[3].Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v5 + 3,
    v5[4].Data,
    v9);
LABEL_7:
  v5[3].Size = v8;
  v5[3].Data[v8 - 1] = 1;
  v10 = v119.pNode;
  v108.pNode = (Scaleform::GFx::ASStringNode *)v119.pNode->pManager;
  v11 = (Scaleform::GFx::ASStringNode *)v108.pNode[3].pManager;
  v109.Message.pNode = v11;
  v12 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v11->pLower;
  *(_QWORD *)&v109.ID = v11->pLower;
  v13 = v11[1].pManager;
  v108.pNode = (Scaleform::GFx::ASStringNode *)&v110;
  v110.Data = 0i64;
  v110.Size = 0i64;
  v110.Policy.Capacity = 0i64;
  pheapAddr = v13;
  LODWORD(v14) = 0;
  if ( !v3->pData )
  {
LABEL_67:
    v39 = strchr(v4, SLOBYTE(v10->pData));
    if ( v39 == v4 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v109, eXMLBadQName, (Scaleform::GFx::AS3::VM *)v11);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        (Scaleform::GFx::AS3::VM *)v11,
        v40,
        &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v41 = v109.Message.pNode;
      v21 = v109.Message.pNode->RefCount == 1;
      --v41->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v41);
      XML_StopParser(v119.pNode->pLower, 0i64);
      goto LABEL_182;
    }
    v42 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID,
      (Scaleform::GFx::ASString *)&v110);
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID,
      &n);
    if ( v39 )
    {
      v45 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              v42,
              &v108,
              v4,
              v39 - v4)->pNode;
      ++v45->RefCount;
      v46 = (Scaleform::GFx::ASStringNode *)v110.Data;
      v21 = LODWORD(v110.Data[3].pObject) == 1;
      --v46->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
      v110.Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v45;
      v47 = v108.pNode;
      v21 = v108.pNode->RefCount == 1;
      --v47->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v47);
      v48 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              v42,
              &v108,
              v39 + 1)->pNode;
      ++v48->RefCount;
      v49 = n.pNode;
      v21 = n.pNode->RefCount == 1;
      --v49->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      n.pNode = v48;
    }
    else
    {
      v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              v42,
              &v108,
              v4)->pNode;
      ++v43->RefCount;
      v44 = n.pNode;
      v21 = n.pNode->RefCount == 1;
      --v44->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v44);
      n.pNode = v43;
    }
    v50 = v108.pNode;
    v21 = v108.pNode->RefCount == 1;
    --v50->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v50);
    v51 = v110.Size;
    v52 = 0i64;
    if ( v110.Size )
    {
      while ( 1 )
      {
        v53 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v110.Data[v52].pObject;
        v55 = 0;
        if ( (v53->Prefix.Flags & 0x1F) == 10 )
        {
          v54 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> **)Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
                                                                                         &v53->Prefix,
                                                                                         &v108);
          v7 |= 1u;
          v107 = v7;
          if ( *v54 == v110.Data )
            v55 = 1;
        }
        if ( v7 & 1 )
        {
          v7 &= 0xFFFFFFFE;
          v107 = v7;
          v56 = v108.pNode;
          v21 = v108.pNode->RefCount == 1;
          --v56->RefCount;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v56);
        }
        if ( v55 )
          break;
        if ( ++v52 >= v51 )
        {
          v51 = v110.Size;
          goto LABEL_96;
        }
      }
      v57 = v119.pNode;
      goto LABEL_110;
    }
LABEL_96:
    v57 = v119.pNode;
    v58 = *(_QWORD *)&v119.pNode->RefCount;
    if ( v58 )
    {
      v53 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(*(__int64 (__fastcall **)(__int64, Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD))(*(_QWORD *)v58 + 376i64))(
                                                               v58,
                                                               &v110,
                                                               0i64);
      if ( v53 )
        goto LABEL_110;
      v51 = v110.Size;
    }
    if ( LODWORD(v110.Data[4].pObject) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v109, eXMLPrefixNotBound, (Scaleform::GFx::AS3::VM *)v109.Message.pNode);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        (Scaleform::GFx::AS3::VM *)v109.Message.pNode,
        v97,
        &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v98 = v109.Message.pNode;
      v21 = v109.Message.pNode->RefCount == 1;
      --v98->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v98);
      XML_StopParser(v57->pLower, 0i64);
      goto LABEL_178;
    }
    v53 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v109.Message.pNode[16].pData;
    if ( v53 )
    {
      v59 = 0i64;
      if ( v51 )
      {
        while ( v110.Data[v59].pObject->Text.pNode != v53->Uri.pNode )
        {
          if ( ++v59 >= v51 )
            goto LABEL_106;
        }
        v53 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v110.Data[v59].pObject;
      }
      else
      {
LABEL_106:
        v60 = *(_QWORD *)&v57->RefCount;
        if ( v60 )
        {
          v61 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)v60 + 384i64))(
                  v60,
                  &v53->Uri,
                  0i64);
          if ( v61 )
            v53 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v61;
        }
      }
    }
    else
    {
      v53 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v109.Message.pNode[10].RefCount;
    }
LABEL_110:
    v62 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v57->RefCount;
    v114.pNode = (Scaleform::GFx::ASStringNode *)((char *)v57 + 24);
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
      (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v108.pNode,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v108,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)v108.pNode,
      v53,
      &n,
      *(Scaleform::GFx::AS3::Instances::fl::XML **)&v57->RefCount);
    v63 = v108.pNode;
    v121 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v108.pNode;
    if ( *(_QWORD *)&v57->RefCount && (*(unsigned int (**)(void))(**(_QWORD **)&v57->RefCount + 208i64))() == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*v62)->vfptr[7].Finalize_GC)(
        *v62,
        &v121);
    }
    else
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v57->Size,
        v57[1].pLower,
        (unsigned __int64)(v57[1].pData + 1));
      v64 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)(*(_QWORD *)&v57->Size
                                                                                 + 8 * (_QWORD)(v57[1].pData - 1));
      *(_QWORD *)&v109.ID = v64;
      v117 = v64;
      if ( v64 )
      {
        v64->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v121;
        v65 = v121;
        if ( v121 )
        {
          ++v121->RefCount;
          v65->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    v66 = v110.Size;
    v67 = 0i64;
    if ( v110.Size )
    {
      do
      {
        v68 = &v110.Data[v67];
        if ( ((_QWORD)v68->pObject[1].vfptr & 0x1F) == 10 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v63[2],
            &v63[2],
            (unsigned __int64)&v63[2].pManager->vfptr + 1);
          v69 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v63[2].pData[8 * ((_QWORD)v63[2].pManager - 1)];
          *(_QWORD *)&v109.ID = v69;
          v117 = v69;
          if ( v69 )
          {
            v70 = v68->pObject;
            v69->pObject = v68->pObject;
            if ( v70 )
              v70->RefCount = (v70->RefCount + 1) & 0x8FBFFFFF;
          }
        }
        ++v67;
      }
      while ( v67 < v66 );
    }
    v71 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID,
      (Scaleform::GFx::ASString *)&p);
    v72 = v.pNode;
    if ( v.pNode->pData )
    {
      v73 = v119.pNode;
      do
      {
        v74 = *((_QWORD *)&v72->pData + (unsigned int)v6);
        v75 = -1i64;
        do
          ++v75;
        while ( *(_BYTE *)(v74 + v75) );
        if ( v75 <= 4
          || *(_BYTE *)v74 != 120
          || *(_BYTE *)(v74 + 1) != 109
          || *(_BYTE *)(v74 + 2) != 108
          || *(_BYTE *)(v74 + 3) != 110
          || *(_BYTE *)(v74 + 4) != 115 )
        {
          v77 = strchr(*(&v72->pData + (unsigned int)v6), SLOBYTE(v73->pData));
          v76 = v6 + 1;
          Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v71,
            &v,
            *(&v72->pData + v76));
          if ( v77 )
          {
            Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              v71,
              &v119,
              (const char *)v74,
              (unsigned __int64)&v77[-v74]);
            v82 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                    v71,
                    &v108,
                    v77 + 1)->pNode;
            ++v82->RefCount;
            v83 = (Scaleform::GFx::ASStringNode *)p;
            v21 = LODWORD(p->pPrev) == 1;
            --v83->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v83);
            p = (Scaleform::GFx::AS3::Instances::fl::XML *)v82;
            v84 = v108.pNode;
            v21 = v108.pNode->RefCount == 1;
            --v84->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v84);
            v81 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::ASString *, _QWORD))v121->vfptr[15].Finalize_GC)(
                                                                     v121,
                                                                     &v119,
                                                                     0i64);
            if ( !v81 )
              v81 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v109.Message.pNode[10].RefCount;
            v85 = v119.pNode;
            v21 = v119.pNode->RefCount == 1;
            --v85->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v85);
          }
          else
          {
            v78 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                    v71,
                    &v108,
                    (const char *)v74)->pNode;
            ++v78->RefCount;
            v79 = (Scaleform::GFx::ASStringNode *)p;
            v21 = LODWORD(p->pPrev) == 1;
            --v79->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v79);
            p = (Scaleform::GFx::AS3::Instances::fl::XML *)v78;
            v80 = v108.pNode;
            v21 = v108.pNode->RefCount == 1;
            --v80->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v80);
            v81 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v109.Message.pNode[10].RefCount;
          }
          v86 = (Scaleform::GFx::AS3::Instances::fl::Namespace **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
                                                                    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v63[1].pData,
                                                                    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)&v109,
                                                                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)v63[1].pData,
                                                                    v81,
                                                                    (Scaleform::GFx::ASString *)&p,
                                                                    &v,
                                                                    (Scaleform::GFx::AS3::Instances::fl::XML *)v63);
          v87 = *v86;
          v116.pV = *v86;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v63[2].RefCount,
            &v63[2].RefCount,
            *(_QWORD *)&v63[2].Size + 1i64);
          v88 = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)&v63[2].RefCount + 8 * (*(_QWORD *)&v63[2].Size - 1i64));
          v117 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v88;
          uri.pNode = v88;
          if ( v88 )
          {
            v88->pData = (const char *)v87;
            if ( v87 )
              v87->RefCount = (v87->RefCount + 1) & 0x8FBFFFFF;
          }
          if ( v87 )
          {
            if ( (unsigned __int8)v87 & 1 )
            {
              v116.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v87 - 1);
            }
            else
            {
              v89 = v87->RefCount;
              if ( v89 & 0x3FFFFF )
              {
                v87->RefCount = v89 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v87->vfptr);
              }
            }
          }
          v90 = v.pNode;
          v21 = v.pNode->RefCount == 1;
          --v90->RefCount;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v90);
        }
        else
        {
          v76 = v6 + 1;
        }
        v6 = v76 + 1;
      }
      while ( *((_QWORD *)&v72->pData + v6) );
      v62 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v114.pNode;
    }
    if ( &v121 != v62 )
    {
      v91 = v121;
      if ( v121 )
      {
        ++v121->RefCount;
        v91->RefCount &= 0x8FBFFFFF;
        v91 = v121;
      }
      v92 = *v62;
      if ( *v62 )
      {
        if ( (unsigned __int8)v92 & 1 )
        {
          *v62 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v92 - 1);
        }
        else
        {
          v93 = v92->RefCount;
          if ( v93 & 0x3FFFFF )
          {
            v92->RefCount = v93 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v92);
            v91 = v121;
          }
        }
      }
      *v62 = v91;
    }
    v94 = (Scaleform::GFx::ASStringNode *)p;
    v21 = LODWORD(p->pPrev) == 1;
    --v94->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v94);
    v95 = v121;
    if ( v121 )
    {
      if ( (unsigned __int8)v121 & 1 )
      {
        v121 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v121 - 1);
      }
      else
      {
        v96 = v121->RefCount;
        if ( v96 & 0x3FFFFF )
        {
          v121->RefCount = v96 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v95);
        }
      }
    }
LABEL_178:
    v99 = n.pNode;
    v21 = n.pNode->RefCount == 1;
    --v99->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v99);
    v100 = (Scaleform::GFx::ASStringNode *)v110.Data;
    v21 = LODWORD(v110.Data[3].pObject) == 1;
    --v100->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v100);
    goto LABEL_182;
  }
  while ( 1 )
  {
    v15 = (_BYTE *)*((_QWORD *)&v3->pData + (unsigned int)v14);
    v16 = -1i64;
    do
      ++v16;
    while ( v15[v16] );
    if ( v16 && *v15 == LOBYTE(v10->pData) )
      break;
    if ( v16 <= 4 || *v15 != 120 || v15[1] != 109 || v15[2] != 108 || v15[3] != 110 || v15[4] != 115 )
    {
      v23 = v14 + 1;
    }
    else
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        v12,
        &result);
      if ( v16 <= 5 || v15[5] != LOBYTE(v119.pNode->pData) )
      {
        v18 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID;
      }
      else
      {
        v17 = v15 + 6;
        v18 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID;
        v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID,
                &v114,
                v17)->pNode;
        ++v19->RefCount;
        v20 = result.pNode;
        v21 = result.pNode->RefCount == 1;
        --v20->RefCount;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        result.pNode = v19;
        v22 = v114.pNode;
        v21 = v114.pNode->RefCount == 1;
        --v22->RefCount;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      }
      v23 = v14 + 1;
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        v18,
        &uri,
        *(&v3->pData + v23));
      v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)*((_QWORD *)v109.Message.pNode[12].pData + 25);
      v25 = 10;
      prefix.Flags = 10;
      prefix.Bonus.pWeakProxy = 0i64;
      v26 = result.pNode;
      *(Scaleform::GFx::ASString *)&prefix.value.VNumber = result;
      if ( result.pNode == &result.pNode->pManager->NullStringNode )
      {
        v26 = 0i64;
        prefix.value.VNumber = 0.0;
        v27 = v109.Message.pNode;
        prefix.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v109.Message.pNode;
        v25 = 12;
        prefix.Flags = 12;
      }
      else
      {
        ++result.pNode->RefCount;
        v27 = (Scaleform::GFx::ASStringNode *)prefix.value.VS._2.VObj;
      }
      Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(v24, &v116, 0, &uri, &prefix);
      v28 = v25 & 0x1F;
      if ( v28 > 9 )
      {
        if ( (v25 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          prefix.Bonus.pWeakProxy = 0i64;
          prefix.value = 0ui64;
          prefix.Flags = v25 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v28 )
          {
            case 10:
              v21 = v26->RefCount-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v26);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              if ( prefix.value.VS._1.VBool )
              {
                *(_QWORD *)&prefix.value.VNumber = (char *)v26 - 1;
              }
              else if ( v26 )
              {
                v29 = v26->Size;
                if ( v29 & 0x3FFFFF )
                {
                  v26->Size = v29 - 1;
                  v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v26;
                  goto LABEL_46;
                }
              }
              break;
            case 16:
            case 17:
              if ( (_QWORD)prefix.value.VS._2.VObj & 1 )
              {
                prefix.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v27[-1].Size + 7);
              }
              else if ( v27 )
              {
                v31 = v27->Size;
                if ( v31 & 0x3FFFFF )
                {
                  v27->Size = v31 - 1;
                  v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v27;
LABEL_46:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
                }
              }
              break;
            default:
              break;
          }
        }
      }
      v32 = v116.pV;
      v108.pNode = (Scaleform::GFx::ASStringNode *)v116.pV;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &v110,
        pheapAddr,
        v110.Size + 1);
      v33 = &v110.Data[v110.Size - 1];
      v117 = &v110.Data[v110.Size - 1];
      *(_QWORD *)&v109.ID = &v110.Data[v110.Size - 1];
      if ( v33 )
      {
        v33->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v32;
        if ( v32 )
          v32->RefCount = (v32->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v32 )
      {
        if ( (unsigned __int8)v32 & 1 )
        {
          v108.pNode = (Scaleform::GFx::ASStringNode *)((char *)&v32[-1].Prefix.value.VS._2.pTraits + 7);
        }
        else
        {
          v34 = v32->RefCount;
          if ( v34 & 0x3FFFFF )
          {
            v32->RefCount = v34 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v32->vfptr);
          }
        }
      }
      v35 = uri.pNode;
      v21 = uri.pNode->RefCount == 1;
      --v35->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      v36 = result.pNode;
      v21 = result.pNode->RefCount == 1;
      --v36->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      v10 = v119.pNode;
      v12 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v109.ID;
      v3 = v.pNode;
    }
    v14 = v23 + 1;
    if ( !*((_QWORD *)&v3->pData + v14) )
    {
      v11 = v109.Message.pNode;
      goto LABEL_67;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v109, eXMLBadQName, (Scaleform::GFx::AS3::VM *)v109.Message.pNode);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    (Scaleform::GFx::AS3::VM *)v109.Message.pNode,
    v37,
    &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v38 = v109.Message.pNode;
  v21 = v109.Message.pNode->RefCount == 1;
  --v38->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  XML_StopParser(v119.pNode->pLower, 0i64);
LABEL_182:
  v119.pNode = (Scaleform::GFx::ASStringNode *)&v110;
  v101 = v110.Size;
  for ( i = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v110.Data[v110.Size - 1]; v101; --v101 )
  {
    v103 = *i;
    if ( *i )
    {
      if ( (unsigned __int8)v103 & 1 )
      {
        *i = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v103 - 1);
      }
      else
      {
        v104 = v103->RefCount;
        if ( v104 & 0x3FFFFF )
        {
          v103->RefCount = v104 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v103);
        }
      }
    }
    --i;
  }
  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}== 1;
  --v38->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  XML_StopParser(v119.pNode->pLower, 0i64);
LABEL_182:
  v119.pNode = (Scaleform::GFx::ASStringNode *)&v110;
  v101 = v110.Size;
  for ( i = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v110.Data[v110.Size - 1]; v101; --v101 )
  {
    v103 = *i;
    if ( *i )
    {
      if ( (unsigned __int8)v103 & 1 )
      {
        *i = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v103 - 1);
      }
      else
      {
        v104 = v103->RefCount;
        i

// File Line: 628
// RVA: 0x7C8E90
void __fastcall Scaleform::GFx::AS3::XMLParser::EndElementExpatCallback(void *userData, const char *name)
{
  const char *v2; // rbp
  char *v3; // rbx
  __int64 *v4; // rdi
  __int64 v5; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int v8; // eax
  const char *v9; // rax
  signed __int64 v10; // r8
  int v11; // ecx
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int *v15; // [rsp+40h] [rbp+8h]

  v2 = name;
  v3 = (char *)userData;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kElement);
  Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataDH<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)(v3 + 72),
    *((_QWORD *)v3 + 10) - 1i64);
  v4 = (__int64 *)(v3 + 24);
  if ( *((_QWORD *)v3 + 3) )
  {
    do
    {
      v5 = *v4;
      v6 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*v4 + 64);
      if ( !v6 )
        break;
      v15 = *(unsigned int **)(*v4 + 64);
      v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      if ( &v15 != (unsigned int **)v4 )
      {
        v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v4;
        if ( *v4 )
        {
          if ( (unsigned __int8)v7 & 1 )
          {
            *v4 = (__int64)&v7[-1].RefCount + 7;
          }
          else
          {
            v8 = v7->RefCount;
            if ( v8 & 0x3FFFFF )
            {
              v7->RefCount = v8 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
            }
          }
        }
        *v4 = (__int64)v6;
      }
      v9 = **(const char ***)(v5 + 56);
      v10 = v2 - v9;
      do
      {
        v11 = (unsigned __int8)v9[v10];
        v12 = *(unsigned __int8 *)v9 - v11;
        if ( *(unsigned __int8 *)v9 != v11 )
          break;
        ++v9;
      }
      while ( v11 );
      if ( !v12 )
      {
        if ( (unsigned __int8)v6 & 1 )
        {
          v15 = (unsigned int *)((char *)&v6[-1].RefCount + 7);
        }
        else
        {
          v14 = v6->RefCount;
          if ( v14 & 0x3FFFFF )
          {
            v6->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
          }
        }
        return;
      }
      if ( (unsigned __int8)v6 & 1 )
      {
        v15 = (unsigned int *)((char *)&v6[-1].RefCount + 7);
      }
      else
      {
        v13 = v6->RefCount;
        if ( v13 & 0x3FFFFF )
        {
          v6->RefCount = v13 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
    while ( *v4 );
  }
}

// File Line: 657
// RVA: 0x7B3580
void __fastcall Scaleform::GFx::AS3::XMLParser::CharacterDataExpatCallback(void *userData, const char *s, int len)
{
  const char *v3; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::GFx::ASString *v5; // rbx

  v3 = s;
  v4 = len;
  v5 = (Scaleform::GFx::ASString *)userData;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kText);
  Scaleform::GFx::ASString::Append(v5 + 8, v3, v4);
}

// File Line: 668
// RVA: 0x7B7730
void __fastcall Scaleform::GFx::AS3::XMLParser::CommentExpatCallback(void *userData, const char *data)
{
  const char *v2; // rdi
  char *v3; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v4; // rsi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v7; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int v13; // edx
  Scaleform::GFx::ASStringNode *v14; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> v20; // [rsp+78h] [rbp+20h]

  v2 = data;
  v3 = (char *)userData;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)*((_QWORD *)userData + 1);
  v5 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->pVM->StringManagerRef->Builtins;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kComment);
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(v5, &result, v2);
  v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v3 + 24);
  v8 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
         v4,
         &v20,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v4->vfptr,
         v6,
         *((Scaleform::GFx::AS3::Instances::fl::XML **)v3 + 3))->pV;
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr;
  if ( *v7 && ((unsigned int (*)(void))(*v7)->vfptr[8].Finalize_GC)() == 1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*v7)->vfptr[7].Finalize_GC)(
      *v7,
      &v18);
  }
  else
  {
    if ( &v18 != v7 )
    {
      v11 = v18;
      if ( v18 )
      {
        ++v18->RefCount;
        v11->RefCount &= 0x8FBFFFFF;
        v11 = v18;
      }
      v12 = *v7;
      if ( *v7 )
      {
        if ( (unsigned __int8)v12 & 1 )
        {
          *v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v12 - 1);
        }
        else
        {
          v13 = v12->RefCount;
          if ( v13 & 0x3FFFFF )
          {
            v12->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
            v11 = v18;
          }
        }
      }
      *v7 = v11;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)(v3 + 32),
      *((const void **)v3 + 7),
      *((_QWORD *)v3 + 5) + 1i64);
    v14 = (Scaleform::GFx::ASStringNode *)(*((_QWORD *)v3 + 4) + 8 * (*((_QWORD *)v3 + 5) - 1i64));
    result.pNode = v14;
    v20.pV = (Scaleform::GFx::AS3::Instances::fl::XMLComment *)v14;
    if ( v14 )
    {
      v14->pData = (const char *)v18;
      v15 = v18;
      if ( v18 )
      {
        ++v18->RefCount;
        v15->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  v16 = v18;
  if ( v18 )
  {
    if ( (unsigned __int8)v18 & 1 )
    {
      v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v18 - 1);
    }
    else
    {
      v17 = v18->RefCount;
      if ( v17 & 0x3FFFFF )
      {
        v18->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
}

// File Line: 700
// RVA: 0x7C01B0
void __fastcall Scaleform::GFx::AS3::XMLParser::DeclExpatCallback(void *userData, const char *version, const char *encoding, int standalone)
{
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kInstruction);
}

// File Line: 740
// RVA: 0x8217C0
void __fastcall Scaleform::GFx::AS3::XMLParser::StartDoctypeDeclExpatCallback(void *userData, const char *doctypeName, const char *sysid, const char *pubid)
{
  unsigned __int64 v4; // rax
  __int64 *v5; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  __int64 v8; // rax

  v4 = *((_QWORD *)userData + 10);
  v5 = (__int64 *)((char *)userData + 72);
  v6 = v4 + 1;
  if ( v4 + 1 >= v4 )
  {
    if ( v6 > *((_QWORD *)userData + 11) )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < *((_QWORD *)userData + 11) >> 1 )
  {
    v7 = v4 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)userData
    + 3,
      *((const void **)userData + 12),
      v7);
    goto LABEL_7;
  }
LABEL_7:
  v8 = *v5;
  v5[1] = v6;
  *(_DWORD *)(v8 + 4 * v6 - 4) = 6;
}

// File Line: 748
// RVA: 0x7C8E80
void __fastcall Scaleform::GFx::AS3::XMLParser::EndDoctypeDeclExpatCallback(void *userData)
{
  Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataDH<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)((char *)userData + 72),
    *((_QWORD *)userData + 10) - 1i64);
}

// File Line: 758
// RVA: 0x80A290
void __fastcall Scaleform::GFx::AS3::XMLParser::ProcessingInstructionExpatCallback(void *userData, const char *target, const char *data)
{
  const char *v3; // rbx
  const char *v4; // rsi
  char *v5; // r14
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v6; // rbp
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v7; // rdi
  Scaleform::GFx::ASString *v; // rbx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int v17; // edx
  Scaleform::GFx::ASStringNode *v18; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-38h]
  __int64 v23; // [rsp+38h] [rbp-30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> v24; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString v26; // [rsp+88h] [rbp+20h]

  v23 = -2i64;
  v3 = data;
  v4 = target;
  v5 = (char *)userData;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kAttr|kText);
  v6 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)*((_QWORD *)v5 + 1);
  v7 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->pVM->StringManagerRef->Builtins;
  v = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(v7, &result, v3);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(v7, &v26, v4);
  v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v5 + 24);
  v11 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(
          v6,
          &v24,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v6->vfptr,
          v9,
          v,
          *((Scaleform::GFx::AS3::Instances::fl::XML **)v5 + 3))->pV;
  v12 = v26.pNode;
  v13 = v26.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v14 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr;
  if ( *v10 && ((unsigned int (*)(void))(*v10)->vfptr[8].Finalize_GC)() == 1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*v10)->vfptr[7].Finalize_GC)(
      *v10,
      &v25);
  }
  else
  {
    if ( &v25 != v10 )
    {
      v15 = v25;
      if ( v25 )
      {
        ++v25->RefCount;
        v15->RefCount &= 0x8FBFFFFF;
        v15 = v25;
      }
      v16 = *v10;
      if ( *v10 )
      {
        if ( (unsigned __int8)v16 & 1 )
        {
          *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v16 - 1);
        }
        else
        {
          v17 = v16->RefCount;
          if ( v17 & 0x3FFFFF )
          {
            v16->RefCount = v17 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
            v15 = v25;
          }
        }
      }
      *v10 = v15;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)(v5 + 32),
      *((const void **)v5 + 7),
      *((_QWORD *)v5 + 5) + 1i64);
    v18 = (Scaleform::GFx::ASStringNode *)(*((_QWORD *)v5 + 4) + 8 * (*((_QWORD *)v5 + 5) - 1i64));
    v26.pNode = v18;
    v24.pV = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *)v18;
    if ( v18 )
    {
      v18->pData = (const char *)v25;
      v19 = v25;
      if ( v25 )
      {
        ++v25->RefCount;
        v19->RefCount &= 0x8FBFFFFF;
      }
    }
    LOBYTE(v18) = 1;
    XML_StopParser(*((_QWORD *)v5 + 2), v18);
  }
  v20 = v25;
  if ( v25 )
  {
    if ( (unsigned __int8)v25 & 1 )
    {
      v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v25 - 1);
    }
    else
    {
      v21 = v25->RefCount;
      if ( v21 & 0x3FFFFF )
      {
        v25->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
}

// File Line: 805
// RVA: 0x78A660
void __fastcall Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::~EmptyCallBack(Scaleform::GFx::AS3::Instances::fl::EmptyCallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable';
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
}

// File Line: 820
// RVA: 0x789760
void __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::~AttrGetFirst(Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
  v2 = this->First.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
}

// File Line: 827
// RVA: 0x7B2770
char __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::Call(Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *this, unsigned __int64 ind)
{
  if ( !this->First.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->First,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->Element->Attrs.Data.Data[ind].pObject);
  return 1;
}

// File Line: 846
// RVA: 0x789EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::~ChildGetFirst(Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
  v2 = this->First.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
}

// File Line: 853
// RVA: 0x7B2820
char __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::Call(Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this, unsigned __int64 ind)
{
  if ( !this->First.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->First,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->Element->Children.Data.Data[ind].pObject);
  return 1;
}

// File Line: 872
// RVA: 0x789E90
void __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGet::~ChildGet(Scaleform::GFx::AS3::Instances::fl::ChildGet *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
}

// File Line: 880
// RVA: 0x7B27A0
char __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGet::Call(Scaleform::GFx::AS3::Instances::fl::ChildGet *this, unsigned __int64 ind)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rcx

  v2 = &this->Element->Children.Data.Data[ind];
  v3 = this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->List,
    &v3->List,
    v3->List.Data.Size + 1);
  v4 = &v3->List.Data.Data[v3->List.Data.Size - 1];
  if ( v4 )
  {
    v5 = v2->pObject;
    v4->pObject = v2->pObject;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  }
  return 1;
}

// File Line: 893
// RVA: 0x789730
void __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGet::~AttrGet(Scaleform::GFx::AS3::Instances::fl::AttrGet *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable';
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
}

// File Line: 901
// RVA: 0x7B26B0
char __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGet::Call(Scaleform::GFx::AS3::Instances::fl::AttrGet *this, unsigned __int64 ind)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  unsigned int v5; // eax

  v2 = this->Element->Attrs.Data.Data[ind].pObject;
  if ( v2 )
    v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  v3 = this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->List,
    &v3->List,
    v3->List.Data.Size + 1);
  v4 = &v3->List.Data.Data[v3->List.Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)&v2->vfptr;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v2 )
  {
    if ( !((unsigned __int8)v2 & 1) )
    {
      v5 = v2->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v2->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  return 1;
}

// File Line: 913
// RVA: 0x785310
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rcx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v10; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2,Scaleform::ArrayDefaultPolicy> *v11; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v12; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v14; // rbx
  unsigned int v15; // eax

  v5 = n;
  v6 = ns;
  v7 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v8 = v5->pNode;
  v7->Text = (Scaleform::GFx::ASString)v5->pNode;
  ++v8->RefCount;
  v9 = p;
  v7->Parent.pObject = p;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::`vftable';
  v7->Ns.pObject = 0i64;
  v10 = &v7->Namespaces;
  v10->Data.Data = 0i64;
  v10->Data.Size = 0i64;
  v10->Data.Policy.Capacity = 0i64;
  v11 = &v7->Attrs;
  v11->Data.Data = 0i64;
  v11->Data.Size = 0i64;
  v11->Data.Policy.Capacity = 0i64;
  v12 = (Scaleform::GFx::AS3::Instances::fl::XML *)&v7->Children;
  p = v12;
  v12->vfptr = 0i64;
  v12->pRCCRaw = 0i64;
  v12->pNext = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v7->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&p,
    0,
    &v6->Uri,
    &v6->Prefix);
  v13 = v7->Ns.pObject;
  v14 = p;
  if ( p != (Scaleform::GFx::AS3::Instances::fl::XML *)v13 )
  {
    if ( v13 )
    {
      if ( (unsigned __int8)v13 & 1 )
      {
        v7->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v13 - 1);
      }
      else
      {
        v15 = v13->RefCount;
        if ( v15 & 0x3FFFFF )
        {
          v13->RefCount = v15 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
        }
      }
    }
    v7->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v14;
  }
}

// File Line: 918
// RVA: 0x78FED0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::~XMLElement(Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::`vftable';
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Attrs.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Namespaces);
  v2 = v1->Ns.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::XML::~XML((Scaleform::GFx::AS3::Instances::fl::XML *)&v1->vfptr);
}

// File Line: 922
// RVA: 0x7D6F00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rsi
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v9; // rdx
  unsigned __int64 v10; // r15
  unsigned __int64 v11; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v12; // rdx
  unsigned __int64 v13; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v14; // rdx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->Parent.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->Parent);
  if ( v5->Ns.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->Ns);
  v6 = v5->Namespaces.Data.Size;
  v7 = 0i64;
  v8 = 0i64;
  if ( v6 )
  {
    do
    {
      v9 = &v5->Namespaces.Data.Data[v8];
      if ( v9->pObject )
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v9);
      ++v8;
    }
    while ( v8 < v6 );
  }
  v10 = v5->Attrs.Data.Size;
  v11 = 0i64;
  if ( v10 )
  {
    do
    {
      v12 = &v5->Attrs.Data.Data[v11];
      if ( v12->pObject )
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v12);
      ++v11;
    }
    while ( v11 < v10 );
  }
  v13 = v5->Children.Data.Size;
  if ( v13 )
  {
    do
    {
      v14 = &v5->Children.Data.Data[v7];
      if ( v14->pObject )
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v14);
      ++v7;
    }
    while ( v7 < v13 );
  }
}

// File Line: 952
// RVA: 0x7EA3A0
Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetInScopeNamespaces(Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  return &this->Namespaces;
}

// File Line: 957
// RVA: 0x7ACC80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddInScopeNamespace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // rsi
  Scaleform::GFx::AS3::Value *prefix; // r12
  Scaleform::GFx::ASString *v5; // rax
  char v6; // bl
  Scaleform::GFx::ASStringNode *v7; // r14
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned __int64 v11; // r15
  unsigned __int64 v12; // rbp
  unsigned __int64 v13; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v14; // rdi
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rdx
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // rdi
  Scaleform::GFx::AS3::Value *v19; // rbp
  unsigned int v20; // eax
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::ASStringNode *v22; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+A8h] [rbp+20h]

  v2 = ns;
  v3 = this;
  prefix = &ns->Prefix;
  if ( ns->Prefix.Flags & 0x1F )
  {
    if ( (ns->Prefix.Flags & 0x1F) == 10 )
    {
      v5 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(prefix, (Scaleform::GFx::ASString *)&v22);
      v6 = 1;
    }
    else
    {
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
             &result);
      v6 = 2;
    }
    v7 = v5->pNode;
    v23 = v7;
    ++v7->RefCount;
    if ( v6 & 2 )
    {
      v6 &= 0xFDu;
      v8 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v8->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    if ( v6 & 1 )
    {
      v10 = v22;
      v9 = v22->RefCount == 1;
      --v10->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    if ( v7->Size || v3->Ns.pObject->Uri.pNode->Size )
    {
      v11 = -1i64;
      v12 = v3->Namespaces.Data.Size;
      v13 = 0i64;
      if ( v12 )
      {
        v14 = v3->Namespaces.Data.Data;
        while ( !Scaleform::GFx::AS3::StrictEqual(prefix, &v14->pObject->Prefix) )
        {
          ++v13;
          ++v14;
          if ( v13 >= v12 )
            goto LABEL_19;
        }
        v11 = v13;
      }
LABEL_19:
      Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v3->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&result,
        0,
        &v2->Uri,
        prefix);
      v15 = result.pNode;
      v22 = result.pNode;
      if ( v11 != -1i64 && v3->Namespaces.Data.Data[v11].pObject->Uri.pNode != v2->Uri.pNode )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Namespaces,
          v11);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Namespaces,
        &v3->Namespaces,
        v3->Namespaces.Data.Size + 1);
      v16 = (Scaleform::GFx::ASStringNode *)&v3->Namespaces.Data.Data[v3->Namespaces.Data.Size - 1];
      result.pNode = v16;
      if ( v16 )
      {
        v16->pData = (const char *)v15;
        if ( v15 )
          v15->Size = (v15->Size + 1) & 0x8FBFFFFF;
      }
      if ( Scaleform::GFx::AS3::StrictEqual(&v3->Ns.pObject->Prefix, prefix) )
      {
        if ( !(_S11_12 & 1) )
        {
          _S11_12 |= 1u;
          v.Flags = 0;
          v.Bonus.pWeakProxy = 0i64;
          atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
        }
        Scaleform::GFx::AS3::Value::Assign(&v3->Ns.pObject->Prefix, &v);
      }
      v17 = v3->Attrs.Data.Size;
      v18 = 0i64;
      if ( v17 )
      {
        do
        {
          v19 = (Scaleform::GFx::AS3::Value *)(((__int64 (*)(void))v3->Attrs.Data.Data[v18].pObject->vfptr[11].~RefCountBaseGC<328>)()
                                             + 72);
          if ( Scaleform::GFx::AS3::StrictEqual(v19, prefix) )
          {
            if ( !(_S11_12 & 1) )
            {
              _S11_12 |= 1u;
              v.Flags = 0;
              v.Bonus.pWeakProxy = 0i64;
              atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
            }
            Scaleform::GFx::AS3::Value::Assign(v19, &v);
          }
          ++v18;
        }
        while ( v18 < v17 );
      }
      if ( v15 )
      {
        if ( (unsigned __int8)v15 & 1 )
        {
          v22 = (Scaleform::GFx::ASStringNode *)((char *)v15 - 1);
        }
        else
        {
          v20 = v15->Size;
          if ( v20 & 0x3FFFFF )
          {
            v15->Size = v20 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
          }
        }
      }
    }
    v9 = v7->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 1011
// RVA: 0x7B08E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *child)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML **v4; // r8
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rcx

  v2 = child;
  v3 = &this->Children;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    this->Children.Data.Size + 1);
  v4 = &v3->Data.Data[v3->Data.Size - 1].pObject;
  if ( v4 )
  {
    v5 = v2->pObject;
    *v4 = v2->pObject;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  }
}

// File Line: 1016
// RVA: 0x7B08B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *child)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, unsigned __int64, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
    this,
    result,
    this->Children.Data.Size,
    child);
  return v3;
}

// File Line: 1021
// RVA: 0x7E5FD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetAttributes(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v2; // r14
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v6; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v7; // rdx
  unsigned int v8; // eax

  v2 = this;
  v3 = this->Attrs.Data.Size;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&list->List;
    do
    {
      v6 = v2->Attrs.Data.Data[v4].pObject;
      if ( v6 )
        v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v5,
        v5,
        v5->Size + 1);
      v7 = &v5->Data[v5->Size - 1];
      if ( v7 )
      {
        v7->pObject = v6;
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v6 && !((unsigned __int8)v6 & 1) )
      {
        v8 = v6->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          v6->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
        }
      }
      ++v4;
    }
    while ( v4 < v3 );
  }
}

// File Line: 1029
// RVA: 0x7E6AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XMLList *list, Scaleform::GFx::AS3::Instances::fl::XML::Kind k, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v5; // er12
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // r15
  Scaleform::GFx::ASStringNode *v8; // rax
  bool v9; // r14
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v12; // rdi
  int v13; // eax

  v4 = name;
  v5 = k;
  v6 = list;
  v7 = this;
  if ( k )
  {
    v9 = 1;
    if ( name )
    {
      v8 = name->pNode;
      if ( name->pNode->Size )
      {
        if ( *v8->pData != pattern[0] || *((_BYTE *)v8->pData + 1) )
          v9 = 0;
      }
    }
    v10 = this->Children.Data.Size;
    v11 = 0i64;
    if ( v10 )
    {
      do
      {
        v12 = v7->Children.Data.Data[v11].pObject;
        v13 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v12->vfptr[8].Finalize_GC)(v12);
        if ( v13 == v5
          && (v13 != 4
           || !v4
           || v9
           || *(Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v12->vfptr[10].ForEachChild_GC)(v12) == v4->pNode) )
        {
          Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v6, v12);
        }
        ++v11;
      }
      while ( v11 < v10 );
    }
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)&list->List.Data,
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children.Data);
  }
}

// File Line: 1059
// RVA: 0x7E69D0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildIndex(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, unsigned __int64 *ind)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r9
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v4; // r11
  unsigned __int64 v5; // r10
  unsigned __int64 v6; // rcx
  Scaleform::GFx::AS3::CheckResult *v7; // rax

  v3 = this->Parent.pObject;
  v4 = this;
  if ( v3 && (v5 = (unsigned __int64)v3[1].Parent.pObject, *ind = 0i64, v5) )
  {
    while ( 1 )
    {
      v6 = *ind;
      if ( *((Scaleform::GFx::AS3::Instances::fl::XMLElement **)&v3[1].Text.pNode->pData + *ind) == v4 )
        break;
      *ind = v6 + 1;
      if ( v6 + 1 >= v5 )
        goto LABEL_5;
    }
    result->Result = 1;
    v7 = result;
  }
  else
  {
LABEL_5:
    result->Result = 0;
    v7 = result;
  }
  return v7;
}

// File Line: 1089
// RVA: 0x826750
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToString(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::StringBuffer *buf, int ident)
{
  unsigned int v3; // ebp
  Scaleform::StringBuffer *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // r14
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rdi

  v3 = ident;
  v4 = buf;
  v5 = this;
  v6 = 0i64;
  if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(this) )
  {
    v7 = v5->Children.Data.Size;
    if ( v7 )
    {
      do
      {
        v8 = v5->Children.Data.Data[v6].pObject;
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v8->vfptr[8].Finalize_GC)(v8) == 2 )
          v8->vfptr[8].ForEachChild_GC(
            (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr,
            (Scaleform::GFx::AS3::RefCountCollector<328> *)v4,
            (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))v3);
        ++v6;
      }
      while ( v6 < v7 );
    }
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::StringBuffer *, _QWORD, _QWORD, _QWORD))v5->vfptr[8].~RefCountBaseGC<328>)(
      v5,
      v4,
      v3,
      0i64,
      0i64);
  }
}

// File Line: 1151
// RVA: 0x826BB0
Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXMLString

// File Line: 1463
// RVA: 0x815C30
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ResolveNamespaces(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *nr, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r15
  Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > v9; // r11
  signed __int64 v10; // r8
  unsigned __int64 v11; // r9
  signed __int64 v12; // rdx
  signed __int64 v13; // rcx
  signed __int64 v14; // rax
  unsigned __int64 v15; // r10
  signed __int64 v16; // rdx
  signed __int64 v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned __int64 v19; // rbp
  unsigned __int64 v20; // rbx
  unsigned __int64 v21; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v22; // rcx
  unsigned __int64 v23; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v24; // rcx
  Scaleform::GFx::ASString key; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v3 = lp;
  v4 = nr;
  v5 = this;
  v6 = this->Ns.pObject;
  if ( (v6->Prefix.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v6->Prefix, &result);
    key.pNode = result.pNode;
    ++key.pNode->RefCount;
    v7 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( !((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))v5->vfptr[15].Finalize_GC)(
            v5,
            &key,
            v3) )
    {
      v9.pTable = v4->pTable;
      v10 = 8i64;
      v11 = 5381i64;
      if ( !v4->pTable )
        goto LABEL_26;
      v12 = 8i64;
      v13 = 5381i64;
      do
      {
        v14 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + --v12);
        v13 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + v12);
      }
      while ( v12 );
      v15 = v14 & v9.pTable->SizeMask;
      v16 = v15;
      v17 = (signed __int64)v9.pTable + 8 * (v15 + 2 * (v15 + 1));
      if ( *(_QWORD *)v17 == -2i64 || *(_QWORD *)(v17 + 8) != v15 )
        goto LABEL_26;
      while ( *(_QWORD *)(v17 + 8) != v15 || *(Scaleform::GFx::ASStringNode **)(v17 + 16) != key.pNode )
      {
        v16 = *(_QWORD *)v17;
        if ( *(_QWORD *)v17 == -1i64 )
          goto LABEL_16;
        v17 = (signed __int64)v9.pTable + 8 * (v16 + 2 * (v16 + 1));
      }
      if ( v16 < 0
        || !(Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)v9.pTable + 8 * (v16 + 2 * (v16 + 2))) )
      {
LABEL_26:
        do
LABEL_16:
          v11 = *((unsigned __int8 *)&key.pNode + --v10) + 65599 * v11;
        while ( v10 );
        Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
          (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v4->pTable,
          v4->pHeap,
          &key,
          v11);
      }
    }
    v18 = key.pNode;
    v8 = key.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  v19 = v5->Attrs.Data.Size;
  v20 = 0i64;
  v21 = 0i64;
  if ( v19 )
  {
    do
    {
      v22 = v5->Attrs.Data.Data[v21].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *, Scaleform::GFx::AS3::Instances::fl::XML *))v22->vfptr[16].~RefCountBaseGC<328>)(
        v22,
        v4,
        v3);
      ++v21;
    }
    while ( v21 < v19 );
  }
  v23 = v5->Children.Data.Size;
  if ( v23 )
  {
    do
    {
      v24 = v5->Children.Data.Data[v20].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *, Scaleform::GFx::AS3::Instances::fl::XML *))v24->vfptr[16].~RefCountBaseGC<328>)(
        v24,
        v4,
        v3);
      ++v20;
    }
    while ( v20 < v23 );
  }
}

// File Line: 1484
// RVA: 0x8120F0
Scaleform::GFx::AS3::Instances::fl::XMLElement *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::RemoveNamespace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Value *v2; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // rdi
  unsigned __int64 v4; // rbp
  long double v5; // rbx
  long double v6; // rcx
  Scaleform::GFx::ASString *v7; // rsi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  __int64 v10; // rax
  unsigned __int64 i; // rsi
  __int64 v12; // rax
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // r15
  void (__fastcall *v15)(Scaleform::GFx::AS3::RefCountBaseGC<328> *); // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v19; // rcx
  unsigned int v20; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v22; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h]

  v2 = ns;
  v3 = this;
  v4 = 0i64;
  v5 = 0.0;
  if ( (ns->Flags & 0x1F) == 11 )
  {
    v6 = ns->value.VNumber;
    if ( v6 != 0.0 )
    {
      *(_DWORD *)(*(_QWORD *)&v6 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v6 + 32i64) + 1) & 0x8FBFFFFF;
      v5 = v6;
    }
  }
  else
  {
    v7 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(ns, &result);
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
      (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v3->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
      &v22,
      NS_Private,
      v7,
      &v);
    if ( v22.pV )
      v5 = *(double *)&v22.pV;
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v10 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *))v3->vfptr[10].~RefCountBaseGC<328>)(v3);
  if ( *(_QWORD *)(v10 + 56) == *(_QWORD *)(*(_QWORD *)&v5 + 56i64)
    && !((*(_BYTE *)(*(_QWORD *)&v5 + 40i64) ^ *(_BYTE *)(v10 + 40)) & 0xF) )
  {
    goto LABEL_34;
  }
  for ( i = 0i64; i < v3->Attrs.Data.Size; ++i )
  {
    v12 = ((__int64 (*)(void))v3->Attrs.Data.Data[i].pObject->vfptr[10].~RefCountBaseGC<328>)();
    if ( *(_QWORD *)(v12 + 56) == *(_QWORD *)(*(_QWORD *)&v5 + 56i64)
      && !((*(_BYTE *)(*(_QWORD *)&v5 + 40i64) ^ *(_BYTE *)(v12 + 40)) & 0xF) )
    {
      goto LABEL_34;
    }
  }
  v13 = 0i64;
  v14 = v3->Namespaces.Data.Size;
  if ( !v14 )
    goto LABEL_32;
  v22.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Namespaces.Data.Data;
  v15 = *(void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))(*(_QWORD *)&v5 + 56i64);
  v16 = v22.pV;
  while ( v16->vfptr[2].~RefCountBaseGC<328> != v15 )
  {
LABEL_22:
    ++v13;
    v16 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v16 + 8);
    if ( v13 >= v14 )
      goto LABEL_32;
  }
  if ( *(_BYTE *)(*(_QWORD *)&v5 + 72i64) & 0x1F
    && !Scaleform::GFx::AS3::StrictEqual(
          (Scaleform::GFx::AS3::Value *)(*(_QWORD *)&v5 + 72i64),
          (Scaleform::GFx::AS3::Value *)&v16->vfptr[3]) )
  {
    v15 = *(void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))(*(_QWORD *)&v5 + 56i64);
    goto LABEL_22;
  }
  if ( v14 == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Namespaces,
      &v3->Namespaces,
      0i64);
  }
  else
  {
    v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*((_QWORD *)&v22.pV->vfptr + v13);
    if ( v17 )
    {
      if ( (unsigned __int8)v17 & 1 )
      {
        *((_QWORD *)&v22.pV->vfptr + v13) = (char *)v17 - 1;
      }
      else
      {
        v18 = v17->RefCount;
        if ( v18 & 0x3FFFFF )
        {
          v17->RefCount = v18 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
        }
      }
    }
    memmove(
      &v3->Namespaces.Data.Data[v13],
      &v3->Namespaces.Data.Data[v13 + 1],
      8 * (v3->Namespaces.Data.Size - v13) - 8);
    --v3->Namespaces.Data.Size;
  }
LABEL_32:
  if ( v3->Children.Data.Size )
  {
    do
    {
      v19 = v3->Children.Data.Data[v4].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))v19->vfptr[16].Finalize_GC)(
        v19,
        v2);
      ++v4;
    }
    while ( v4 < v3->Children.Data.Size );
  }
LABEL_34:
  if ( !(LOBYTE(v5) & 1) )
  {
    v20 = *(_DWORD *)(*(_QWORD *)&v5 + 32i64);
    if ( v20 & 0x3FFFFF )
    {
      *(_DWORD *)(*(_QWORD *)&v5 + 32i64) = v20 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5);
    }
  }
  return v3;
}

// File Line: 1521
// RVA: 0x7AB270
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *n, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v6; // rdx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> result; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v9; // [rsp+50h] [rbp-18h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v10; // [rsp+58h] [rbp-10h]

  v4 = this;
  v5 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &result,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         ns,
         n,
         v,
         (Scaleform::GFx::AS3::Instances::fl::XML *)&this->vfptr)->pV;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Attrs.Data.Data,
    &v4->Attrs,
    v4->Attrs.Data.Size + 1);
  v6 = &v4->Attrs.Data.Data[v4->Attrs.Data.Size - 1];
  v9 = v6;
  v10 = v6;
  if ( v6 )
  {
    v6->pObject = v5;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v5 && !((unsigned __int8)v5 & 1) )
  {
    v7 = v5->RefCount;
    if ( v7 & 0x3FFFFF )
    {
      v5->RefCount = v7 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
    }
  }
}

// File Line: 1528
// RVA: 0x7C94A0
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::EqualsInternal(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // r12
  signed __int64 v4; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v5; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // r9
  Scaleform::GFx::AS3::Traits *v7; // rbx
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v10; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v11; // r11
  unsigned __int64 v12; // r10
  __int64 *v13; // r9
  __int64 v14; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rbx
  Scaleform::GFx::AS3::Value::Extra v18; // rdi
  Scaleform::GFx::AS3::Value::Extra v19; // rsi
  Scaleform::GFx::ASStringNode *v20; // rax
  long double v21; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v22; // rax
  long double v23; // rcx
  int v24; // ecx
  bool v25; // zf
  Scaleform::GFx::ASStringNode *v26; // rcx
  long double v27; // rcx
  int v28; // eax
  int v29; // eax
  Scaleform::GFx::ASStringNode *v30; // rcx
  long double v31; // rcx
  int v32; // eax
  Scaleform::GFx::AS3::Value l; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS3::Value r; // [rsp+48h] [rbp-28h]
  unsigned __int64 v35; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+58h]

  v2 = other;
  v3 = this;
  v4 = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
         (Scaleform::GFx::AS3::Instances::fl::XML *)&this->vfptr,
         other);
  if ( (_DWORD)v4 )
    return v4;
  v5 = v2[1].vfptr;
  v6 = v3->Ns.pObject;
  if ( v6->Uri.pNode != (Scaleform::GFx::ASStringNode *)v5[2].~RefCountBaseGC<328> )
    return 2i64;
  if ( (LOBYTE(v5[1].Finalize_GC) ^ *((_BYTE *)v6 + 40)) & 0xF )
    return 2i64;
  v7 = (Scaleform::GFx::AS3::Traits *)v3->Attrs.Data.Size;
  if ( v7 != v2[1].pTraits.pObject )
    return 2i64;
  v8 = v3->Children.Data.Size;
  v35 = v8;
  if ( (Scaleform::GFx::AS3::Instances::fl::XML *)v8 != v2[1].Parent.pObject )
    return 2i64;
  v9 = 0i64;
  if ( !v7 )
    goto LABEL_21;
  v10 = v3->Attrs.Data.Data;
  do
  {
    v11 = v10->pObject;
    v12 = 0i64;
    v13 = *(__int64 **)&v2[1].RefCount;
    while ( 1 )
    {
      v14 = *v13;
      if ( v10->pObject->Text.pNode == *(Scaleform::GFx::ASStringNode **)(*v13 + 56) )
      {
        v15 = v11->Ns.pObject;
        if ( v15 )
        {
          v16 = *(_QWORD *)(v14 + 72);
          if ( !v16
            || v15->Uri.pNode != *(Scaleform::GFx::ASStringNode **)(v16 + 56)
            || (*(_BYTE *)(v16 + 40) ^ *((_BYTE *)v15 + 40)) & 0xF )
          {
            goto LABEL_17;
          }
        }
        else if ( *(_QWORD *)(v14 + 72) )
        {
          goto LABEL_17;
        }
        if ( v11->Data.pNode == *(Scaleform::GFx::ASStringNode **)(v14 + 80) )
          break;
      }
LABEL_17:
      ++v12;
      ++v13;
      if ( v12 >= (unsigned __int64)v7 )
        return 2i64;
    }
    ++v9;
    ++v10;
  }
  while ( v9 < (unsigned __int64)v7 );
  v8 = v35;
LABEL_21:
  v17 = 0i64;
  if ( !v8 )
    return 1i64;
  v18.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)l.Bonus;
  v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)l.Bonus;
  while ( 1 )
  {
    v20 = v2[1].Text.pNode;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0i64;
    v21 = *((double *)&v20->pData + v17);
    r.Flags = 12;
    r.value.VNumber = v21;
    r.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.pWeakProxy;
    if ( v21 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v21 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v21 + 32i64) + 1) & 0x8FBFFFFF;
    v22 = v3->Children.Data.Data;
    l.Flags = 0;
    l.Bonus.pWeakProxy = 0i64;
    v23 = *(double *)&v22[v17].pObject;
    l.Flags = 12;
    l.value.VNumber = v23;
    l.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v19.pWeakProxy;
    if ( v23 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v23 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v23 + 32i64) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::AbstractEqual(&result, (bool *)&v35, &l, &r);
    v24 = l.Flags & 0x1F;
    if ( v24 > 9 )
    {
      if ( (l.Flags >> 9) & 1 )
      {
        v25 = l.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v25 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        l.Bonus.pWeakProxy = 0i64;
        l.value = 0ui64;
        l.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v24 )
        {
          case 10:
            v26 = l.value.VS._1.VStr;
            v25 = *(_DWORD *)(*(_QWORD *)&l.value.VNumber + 24i64) == 1;
            --v26->RefCount;
            if ( v25 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v27 = l.value.VNumber;
            if ( !l.value.VS._1.VBool )
              goto LABEL_39;
            --*(_QWORD *)&l.value.VNumber;
            break;
          case 16:
          case 17:
            v27 = *(double *)&l.value.VS._2.VObj;
            if ( (_QWORD)l.value.VS._2.VObj & 1 )
            {
              --l.value.VS._2.VObj;
            }
            else
            {
LABEL_39:
              if ( v27 != 0.0 )
              {
                v28 = *(_DWORD *)(*(_QWORD *)&v27 + 32i64);
                if ( v28 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v27 + 32i64) = v28 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v27);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    v29 = r.Flags & 0x1F;
    if ( v29 > 9 )
    {
      if ( (r.Flags >> 9) & 1 )
      {
        v25 = r.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v25 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        r.Bonus.pWeakProxy = 0i64;
        r.value = 0ui64;
        r.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v29 )
        {
          case 10:
            v30 = r.value.VS._1.VStr;
            v25 = *(_DWORD *)(*(_QWORD *)&r.value.VNumber + 24i64) == 1;
            --v30->RefCount;
            if ( v25 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v31 = r.value.VNumber;
            if ( !r.value.VS._1.VBool )
              goto LABEL_54;
            --*(_QWORD *)&r.value.VNumber;
            break;
          case 16:
          case 17:
            v31 = *(double *)&r.value.VS._2.VObj;
            if ( (_QWORD)r.value.VS._2.VObj & 1 )
            {
              --r.value.VS._2.VObj;
            }
            else
            {
LABEL_54:
              if ( v31 != 0.0 )
              {
                v32 = *(_DWORD *)(*(_QWORD *)&v31 + 32i64);
                if ( v32 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v31 + 32i64) = v32 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v31);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( !(_BYTE)v35 )
      return 2i64;
    if ( ++v17 >= v8 )
      return 1i64;
  }
}

// File Line: 1590
// RVA: 0x800C50
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XML::Matches(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  unsigned __int8 v4; // bl
  Scaleform::GFx::ASStringNode **v5; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind v6; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v7; // rcx
  Scaleform::GFx::AS3::VM *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rdi
  $CBB44125B27995AEB5908B7872D4CF4F *v10; // rdi
  Scaleform::GFx::AS3::VM *v11; // r14
  __int64 v12; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rbp
  Scaleform::GFx::AS3::GASRefCountBase *v14; // rdx
  Scaleform::GFx::AS3::RefCountCollector<328> *v15; // r9
  unsigned __int64 v16; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v17; // rdx
  __int64 v18; // rax
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v2 = prop_name;
  v3 = this;
  v4 = 0;
  if ( (prop_name->Name.Flags & 0x1F) != 10 )
    return v4;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name->Name, &result);
  v5 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[10].ForEachChild_GC)(v3);
  if ( *v5 == result.pNode || Scaleform::GFx::AS3::Multiname::IsAnyType(v2) )
  {
    v6 = v2->Kind;
    if ( (v2->Kind & 3u) <= 1 )
    {
      if ( v2->Obj.pObject )
      {
        v7 = v2->Obj.pObject;
        v8 = v3->pTraits.pObject->pVM;
        v9 = v8->DefXMLNamespace.pObject;
        if ( !v9 )
          v9 = v8->PublicNamespace.pObject;
        v10 = ($CBB44125B27995AEB5908B7872D4CF4F *)&v9->Uri;
        if ( !(unsigned int)((_QWORD)v7[1].vfptr << 60 >> 60) && (((unsigned int)v6 >> 3) & 1 || v7[1].pNext->RefCount) )
          v10 = &v7[1].16;
        if ( v10->pNext == *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[10].~RefCountBaseGC<328>)(v3)
                                                                        + 56) )
          v4 = 1;
      }
      else
      {
        v4 = 1;
      }
      goto LABEL_33;
    }
    if ( Scaleform::GFx::AS3::Multiname::IsAnyType(v2) )
      goto LABEL_16;
    v11 = v3->pTraits.pObject->pVM;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[10].~RefCountBaseGC<328>)(v3);
    if ( ((unsigned int)v2->Kind >> 3) & 1 || (v13 = v11->DefXMLNamespace.pObject) == 0i64 )
      v13 = v11->PublicNamespace.pObject;
    if ( !Scaleform::GFx::AS3::Multiname::ContainsNamespace(v2, v11->PublicNamespace.pObject) )
    {
      if ( v13->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v12 + 56) )
      {
        v4 = 0;
        if ( !((*(_BYTE *)(v12 + 40) ^ *((_BYTE *)v13 + 40)) & 0xF) )
          v4 = 1;
      }
      goto LABEL_33;
    }
    v14 = v2->Obj.pObject;
    v15 = v14[1]._pRCC;
    v16 = 0i64;
    if ( v15 )
    {
      v17 = v14[1].vfptr;
      while ( 1 )
      {
        if ( !(unsigned int)(*((_QWORD *)v17->ForEachChild_GC + 5) << 60 >> 60) )
        {
          v18 = *((_QWORD *)v17->ForEachChild_GC + 7);
          v19 = *(_DWORD *)(v18 + 32) ? v18 == *(_QWORD *)(v12 + 56) : v13->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v12 + 56);
          if ( v19 )
            break;
        }
        ++v16;
        v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)v17 + 8);
        if ( v16 >= (unsigned __int64)v15 )
          goto LABEL_33;
      }
LABEL_16:
      v4 = 1;
      goto LABEL_33;
    }
  }
LABEL_33:
  v20 = result.pNode;
  v19 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  return v4;
}

// File Line: 1696
// RVA: 0x7F2B40
char __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned __int64 v1; // rdi
  __int64 v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // rsi

  v1 = this->Children.Data.Size;
  v2 = 0i64;
  v3 = this;
  if ( !v1 )
    return 1;
  while ( ((unsigned int (*)(void))v3->Children.Data.Data[v2].pObject->vfptr[8].Finalize_GC)() != 1 )
  {
    if ( ++v2 >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 1709
// RVA: 0x7F2550
bool __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasOwnProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::ASString *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v2; // r15
  unsigned int v4; // esi
  int v5; // edi
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // r8
  int v9; // er14
  const char *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  unsigned __int64 v14; // rsi
  unsigned __int64 v15; // rbx
  bool v16; // zf
  bool v17; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::AS3::Value v19; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+58h] [rbp-11h]
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::ASString v22; // [rsp+E0h] [rbp+77h]

  v2 = this;
  if ( !p->pNode->Size )
    return 0;
  cb.Element = this;
  cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable';
  v4 = 10;
  v19.Flags = 10;
  v5 = 0;
  v19.Bonus.pWeakProxy = 0i64;
  v6 = p->pNode;
  *(_QWORD *)&v19.value.VNumber = v6;
  if ( v6 == &v6->pManager->NullStringNode )
  {
    v6 = 0i64;
    v19.value.VNumber = 0.0;
    v7 = cb.Element;
    v19.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)&cb.Element->vfptr;
    v4 = 12;
    v19.Flags = 12;
  }
  else
  {
    ++v6->RefCount;
    v7 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v19.value.VS._2.VObj;
  }
  v8 = this->pTraits.pObject->pVM->PublicNamespace.pObject;
  prop_name.Kind = 0;
  prop_name.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v8->vfptr;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  prop_name.Name.Flags = 0;
  prop_name.Name.Bonus.pWeakProxy = 0i64;
  v9 = v4 & 0x1F;
  if ( (unsigned int)(v9 - 12) <= 3
    && v6
    && (v10 = v6[1].pData, *((_DWORD *)v10 + 30) == 17)
    && ~((const unsigned __int8)v10[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)&v6[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v6[1].RefCount);
    prop_name.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rbp+57h+var_88.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&prop_name.Name.Flags = *(_QWORD *)&v19.Flags;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&prop_name.Name.value.VNumber = v6;
    prop_name.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)&v7->vfptr;
    if ( v9 > 9 )
    {
      if ( (v4 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v9 == 10 )
      {
        ++v6->RefCount;
      }
      else if ( v9 > 10 )
      {
        if ( v9 <= 15 )
        {
          if ( v6 )
            v6->Size = (v6->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v9 <= 17 && v7 )
        {
          v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (prop_name.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &result);
      if ( result.pNode->Size )
      {
        if ( *result.pNode->pData == 64 )
        {
          prop_name.Kind |= 8u;
          v11 = Scaleform::GFx::ASString::Substring(&result, &v22, 1, result.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v11);
          v12 = v22.pNode;
          v16 = v22.pNode->RefCount == 1;
          --v12->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        }
      }
      v13 = result.pNode;
      v16 = result.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
  if ( v9 > 9 )
  {
    if ( (v4 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v19.Bonus.pWeakProxy = 0i64;
      v19.value = 0ui64;
      v19.Flags = v4 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
    }
  }
  if ( ((unsigned int)prop_name.Kind >> 3) & 1 )
  {
    if ( (prop_name.Name.Flags & 0x1F) == 10 )
    {
      v14 = v2->Attrs.Data.Size;
      v15 = 0i64;
      if ( v14 )
      {
        do
        {
          if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
                 (Scaleform::GFx::AS3::Instances::fl::XML *)&v2->Attrs.Data.Data[v15].pObject->vfptr,
                 &prop_name) )
          {
            ++v5;
            if ( !cb.vfptr->Call(&cb, v15) )
              break;
          }
          ++v15;
        }
        while ( v15 < v14 );
      }
    }
    v16 = v5 == 0;
  }
  else
  {
    v16 = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(v2, &prop_name, &cb) == 0;
  }
  v17 = !v16;
  Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  return v17;
}

// File Line: 1727
// RVA: 0x7C0280
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // r15
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // r14
  unsigned __int64 v5; // r13
  unsigned __int64 v6; // r12
  unsigned __int64 v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v9; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rdi
  void (__fastcall **v12)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **)); // rdx
  unsigned int v13; // eax
  unsigned __int64 v14; // r13
  unsigned __int64 v15; // rbp
  Scaleform::GFx::AS3::Class *v16; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v17; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v18; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **v20; // rdx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v22; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // rsi
  Scaleform::GFx::ASStringNode *v24; // rbp
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::Resource *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx
  int *v29; // rdx
  unsigned int v30; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v31; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v32; // [rsp+90h] [rbp+8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v33; // [rsp+98h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+A8h] [rbp+20h]

  v33 = result;
  v3 = this;
  v4 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v32,
    v4,
    this->Ns.pObject,
    &this->Text,
    parent);
  v5 = v3->Attrs.Data.Size;
  v6 = 0i64;
  v7 = 0i64;
  v8 = v32;
  if ( v5 )
  {
    do
    {
      v9 = v3->Attrs.Data.Data[v7].pObject;
      v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v9->vfptr[11].Finalize_GC)(
                                                           v9,
                                                           &resulta,
                                                           v8);
      v11 = *v10;
      v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*v10;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v8[1],
        &v8[1],
        v8[1].pRCCRaw + 1);
      v12 = &v8[1].vfptr->ForEachChild_GC + v8[1].pRCCRaw - 1;
      if ( v12 )
      {
        *v12 = (void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **)))v11;
        if ( v11 )
          v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v11 )
      {
        if ( (unsigned __int8)v11 & 1 )
        {
          v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)&v11[-1].RefCount + 7);
        }
        else
        {
          v13 = v11->RefCount;
          if ( v13 & 0x3FFFFF )
          {
            v11->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
      ++v7;
    }
    while ( v7 < v5 );
  }
  v14 = v3->Children.Data.Size;
  v15 = 0i64;
  if ( v14 )
  {
    do
    {
      if ( !v4->pConstructor.pObject )
        v4->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      v16 = v4->pConstructor.pObject;
      if ( (((unsigned int (*)(void))v3->Children.Data.Data[v15].pObject->vfptr[8].Finalize_GC)() != 3
         || !LOBYTE(v16[1].vfptr))
        && (((unsigned int (*)(void))v3->Children.Data.Data[v15].pObject->vfptr[8].Finalize_GC)() != 4
         || !BYTE1(v16[1].vfptr)) )
      {
        v17 = v3->Children.Data.Data[v15].pObject;
        v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v17->vfptr[11].Finalize_GC)(
                                                             v17,
                                                             &resulta,
                                                             v8);
        v19 = *v18;
        v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*v18;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v8[1].24,
          &v8[1].24,
          *(_QWORD *)&v8[1].RefCount + 1i64);
        v20 = &v8[1].pPrev->vfptr + *(_QWORD *)&v8[1].RefCount - 1i64;
        if ( v20 )
        {
          *v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v19;
          if ( v19 )
            v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v19 )
        {
          if ( (unsigned __int8)v19 & 1 )
          {
            v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)&v19[-1].RefCount + 7);
          }
          else
          {
            v21 = v19->RefCount;
            if ( v21 & 0x3FFFFF )
            {
              v19->RefCount = v21 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
            }
          }
        }
      }
      ++v15;
    }
    while ( v15 < v14 );
  }
  if ( v3->Namespaces.Data.Size )
  {
    do
    {
      v32 = Scaleform::GFx::AS3::VM::MakeNamespace(v3->pTraits.pObject->pVM, &resulta, 0)->pV;
      v22 = v32;
      v23 = v3->Namespaces.Data.Data[v6].pObject;
      if ( v32 != v23 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v32->Prefix, &v23->Prefix);
        v24 = v23->Uri.pNode;
        ++v24->RefCount;
        v25 = v22->Uri.pNode;
        v26 = v25->RefCount-- == 1;
        if ( v26 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        v22->Uri.pNode = v24;
        *((_QWORD *)v22 + 5) ^= (*((_DWORD *)v22 + 10) ^ *((_DWORD *)v23 + 10)) & 0xF;
        v27 = (Scaleform::GFx::Resource *)v23->pFactory.pObject;
        if ( v27 )
          Scaleform::Render::RenderBuffer::AddRef(v27);
        v28 = (Scaleform::Render::RenderBuffer *)v22->pFactory.pObject;
        if ( v28 )
          Scaleform::RefCountImpl::Release(v28);
        v22->pFactory.pObject = v23->pFactory.pObject;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v8->Prefix.Bonus,
        &v8->Prefix.Bonus,
        *(_QWORD *)&v8->Prefix.value.VNumber + 1i64);
      v29 = &v8->Prefix.Bonus.pWeakProxy->RefCount + 2 * (*(_QWORD *)&v8->Prefix.value.VNumber - 1i64);
      if ( v29 )
      {
        *(_QWORD *)v29 = v22;
        if ( v22 )
          v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v22 - 1);
        }
        else
        {
          v30 = v22->RefCount;
          if ( v30 & 0x3FFFFF )
          {
            v22->RefCount = v30 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
          }
        }
      }
      ++v6;
    }
    while ( v6 < v3->Namespaces.Data.Size );
  }
  v31 = v33;
  v33->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)v8;
  return v31;
}

// File Line: 1765
// RVA: 0x7E6A20
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XMLList *list, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rbx
  unsigned int v6; // [rsp+20h] [rbp-48h]
  __int64 v7; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+88h] [rbp+20h]

  v7 = -2i64;
  v3 = prop_name;
  v4 = list;
  v5 = this;
  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&v10, prop_name, &v6)->Result )
  {
    if ( v6 <= v5->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v4, v5->Children.Data.Data[v6].pObject);
  }
  else
  {
    cb.Element = v5;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
    v9 = v4;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(v5, v3, &cb);
  }
}

// File Line: 1781
// RVA: 0x81B070
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Multiname *v5; // r12
  Scaleform::GFx::AS3::CheckResult *v6; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // r14
  void *v8; // rsi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v9; // r15
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::CheckResult *v13; // rax
  unsigned int v14; // edi
  int v15; // edx
  Scaleform::GFx::ASStringNode *v16; // rcx
  const char *v17; // rax
  long double v18; // rcx
  unsigned int v19; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rcx
  Scaleform::GFx::AS3::Traits *v21; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int v24; // ecx
  Scaleform::GFx::ASStringNode *v25; // rcx
  int v26; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v27; // rdi
  __int64 v28; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // rsi
  unsigned __int64 v30; // rbx
  __int64 v31; // rcx
  const char *v32; // r8
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  __int64 v35; // rax
  unsigned int v36; // ecx
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v39; // rbx
  __int64 v40; // rdi
  unsigned int *v41; // rdx
  unsigned int v42; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v43; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v44; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v45; // rax
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASStringNode *v48; // rdx
  Scaleform::GFx::ASStringNode *v49; // rdi
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::ASStringNode *v51; // rcx
  unsigned int v52; // eax
  int v53; // eax
  Scaleform::GFx::ASStringNode *v54; // rcx
  long double v55; // rcx
  int v56; // eax
  Scaleform::GFx::AS3::WeakProxy *v57; // rsi
  Scaleform::GFx::ASStringNode *v58; // rcx
  int v59; // edx
  __int64 v60; // rax
  __int64 v61; // rax
  char v62; // al
  unsigned __int64 v63; // r13
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *v64; // r12
  signed __int64 v65; // r15
  Scaleform::GFx::AS3::Multiname *v66; // r14
  unsigned __int64 v67; // r12
  bool v68; // r13
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v69; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v70; // r15
  Scaleform::GFx::ASStringNode *v71; // rax
  Scaleform::GFx::ASStringNode **v72; // rax
  Scaleform::GFx::ASStringNode *v73; // rbx
  Scaleform::GFx::ASStringNode *v74; // rcx
  bool v75; // r12
  _BYTE *v76; // r14
  unsigned int v77; // eax
  Scaleform::GFx::ASStringNode *v78; // rcx
  unsigned int v79; // eax
  Scaleform::GFx::ASStringNode *v80; // rbx
  bool v81; // r14
  Scaleform::GFx::ASStringNode *v82; // rcx
  _BOOL8 v83; // r15
  unsigned int v84; // eax
  Scaleform::GFx::ASStringNode *v85; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+8h] [rbp-79h]
  Scaleform::GFx::AS3::Value valuea; // [rsp+10h] [rbp-71h]
  unsigned int ind[2]; // [rsp+30h] [rbp-51h]
  Scaleform::GFx::ASString v; // [rsp+38h] [rbp-49h]
  Scaleform::GFx::AS3::Value other; // [rsp+40h] [rbp-41h]
  Scaleform::GFx::AS3::VM::Error v91; // [rsp+70h] [rbp-11h]
  Scaleform::GFx::ASStringNode *v92; // [rsp+80h] [rbp-1h]
  __int64 v93; // [rsp+88h] [rbp+7h]
  Scaleform::GFx::ASString v94; // [rsp+90h] [rbp+Fh]
  __int64 v95; // [rsp+98h] [rbp+17h]
  Scaleform::GFx::ASString n; // [rsp+E8h] [rbp+67h]
  _BYTE *v97; // [rsp+F0h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *prop_namea; // [rsp+F8h] [rbp+77h]

  v95 = -2i64;
  v4 = value;
  v5 = prop_name;
  v6 = result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  v.pNode = (Scaleform::GFx::ASStringNode *)v8;
  v9 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)*((_QWORD *)v8 + 2);
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v91, eXMLAssignmentToIndexedXMLNotAllowed, (Scaleform::GFx::AS3::VM *)v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v8,
      v10,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v11 = v91.Message.pNode;
    v12 = v91.Message.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v6->Result = 0;
    return v6;
  }
  v14 = 0;
  valuea.Flags = 0;
  valuea.Bonus.pWeakProxy = 0i64;
  v15 = v4->Flags & 0x1F;
  if ( (unsigned int)(v15 - 12) <= 3 )
  {
    v16 = v4->value.VS._1.VStr;
    if ( v16 )
    {
      v17 = v16[1].pData;
      if ( *((_DWORD *)v17 + 30) == 18 )
      {
        if ( ~((const unsigned __int8)v17[112] >> 5) & 1 )
        {
          v18 = *(double *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, unsigned int *, _QWORD))v16->pData
                            + 35))(
                             v16,
                             ind,
                             0i64);
          other.Bonus.pWeakProxy = 0i64;
          other.Flags = 12;
          other.value.VNumber = v18;
          other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v91.Message.pNode;
          Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
          goto LABEL_10;
        }
      }
    }
  }
  if ( (unsigned int)(v15 - 12) <= 3 )
  {
    v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VStr;
    if ( v20 )
    {
      v21 = v20->pTraits.pObject;
      if ( v21->TraitsType == 19 )
      {
        if ( ~(LOBYTE(v21->Flags) >> 5) & 1 )
        {
          v22 = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(
                  v20,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)ind,
                  0i64)->pV;
          other.Bonus.pWeakProxy = 0i64;
          other.Flags = 12;
          *(_QWORD *)&other.value.VNumber = v22;
          other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v91.Message.pNode;
          Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
LABEL_10:
          v19 = other.Flags;
          if ( (other.Flags & 0x1F) > 9 )
          {
            if ( (other.Flags >> 9) & 1 )
            {
              v12 = other.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v12 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              other.Bonus.pWeakProxy = 0i64;
              other.value = 0ui64;
              other.Flags = v19 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
            }
          }
          goto LABEL_43;
        }
      }
    }
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    v9,
    (Scaleform::GFx::ASString *)ind);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v4, &resulta, (Scaleform::GFx::ASString *)ind)->Result )
  {
    v6->Result = 0;
    v23 = *(Scaleform::GFx::ASStringNode **)ind;
    v12 = *(_DWORD *)(*(_QWORD *)ind + 24i64) == 1;
    --v23->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    if ( (valuea.Flags & 0x1F) <= 9 )
      return v6;
    if ( (valuea.Flags >> 9) & 1 )
    {
      v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      valuea.Bonus.pWeakProxy = 0i64;
      valuea.value = 0ui64;
      goto LABEL_29;
    }
LABEL_30:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
    return v6;
  }
  v24 = valuea.Flags;
  if ( (valuea.Flags & 0x1F) > 9 )
  {
    if ( (valuea.Flags >> 9) & 1 )
    {
      v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      valuea.Bonus.pWeakProxy = 0i64;
      valuea.value = 0ui64;
      v24 = valuea.Flags & 0xFFFFFDE0;
      valuea.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
      v24 = valuea.Flags;
    }
  }
  v12 = *(_QWORD *)ind == *(_QWORD *)(*(_QWORD *)ind + 8i64) + 104i64;
  valuea.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v91.Message.pNode;
  if ( v12 )
  {
    valuea.value.VNumber = 0.0;
    valuea.Flags = v24 & 0xFFFFFFEC | 0xC;
  }
  else
  {
    valuea.Flags = v24 & 0xFFFFFFEA | 0xA;
    valuea.value.VNumber = *(long double *)ind;
    ++*(_DWORD *)(*(_QWORD *)ind + 24i64);
  }
  v25 = *(Scaleform::GFx::ASStringNode **)ind;
  v12 = *(_DWORD *)(*(_QWORD *)ind + 24i64) == 1;
  --v25->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
LABEL_43:
  if ( !(((unsigned int)v5->Kind >> 3) & 1) )
  {
    v57 = 0i64;
    other.Bonus.pWeakProxy = 0i64;
    other.Flags = 0;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v9, &v94);
    *(_QWORD *)ind = (char *)v5 + 16;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(&v5->Name, &resulta, &v94)->Result )
    {
      v6->Result = 0;
      v58 = v94.pNode;
      v12 = v94.pNode->RefCount == 1;
      --v58->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v58);
      if ( (valuea.Flags & 0x1F) <= 9 )
        return v6;
      if ( (valuea.Flags >> 9) & 1 )
      {
        v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        valuea.Bonus.pWeakProxy = 0i64;
        valuea.value = 0ui64;
        goto LABEL_29;
      }
      goto LABEL_30;
    }
    v59 = valuea.Flags & 0x1F;
    if ( (unsigned int)(v59 - 12) <= 3
      && *(_QWORD *)&valuea.value.VNumber
      && (v60 = *(_QWORD *)(*(_QWORD *)&valuea.value.VNumber + 40i64), *(_DWORD *)(v60 + 120) == 18)
      && ~(*(_BYTE *)(v60 + 112) >> 5) & 1
      || (unsigned int)(v59 - 12) <= 3
      && *(_QWORD *)&valuea.value.VNumber
      && (v61 = *(_QWORD *)(*(_QWORD *)&valuea.value.VNumber + 40i64), *(_DWORD *)(v61 + 120) == 19)
      && ~(*(_BYTE *)(v61 + 112) >> 5) & 1
      || (v62 = Scaleform::GFx::AS3::Multiname::IsAnyType(v5), resulta.Result = 1, v62) )
    {
      resulta.Result = 0;
    }
    v63 = v7->Children.Data.Size;
    if ( v63 )
    {
      v64 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v7->Children;
      v65 = v63 - 1;
      v66 = prop_namea;
      do
      {
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl::XML::Matches(
                                (Scaleform::GFx::AS3::Instances::fl::XML *)&v64->Data.Data[v65].pObject->vfptr,
                                v66) )
        {
          if ( v14 & 0x1F )
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
              v64,
              other.value.VS._1.VInt);
          if ( (signed int)(v14 & 0x1F) > 9 )
          {
            if ( (v14 >> 9) & 1 )
            {
              v12 = v57->RefCount-- == 1;
              if ( v12 )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v57);
              v57 = 0i64;
              other.Bonus.pWeakProxy = 0i64;
              other.value = 0ui64;
              v14 &= 0xFFFFFDE0;
              other.Flags = v14;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
              v57 = other.Bonus.pWeakProxy;
              v14 = other.Flags;
            }
          }
          v14 = v14 & 0xFFFFFFE2 | 2;
          other.Flags = v14;
          v91.ID = v65;
          other.value = (Scaleform::GFx::AS3::Value::VU)v91;
        }
        --v65;
        --v63;
      }
      while ( v63 );
      v7 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)n.pNode;
    }
    if ( v14 & 0x1F )
    {
      v68 = resulta.Result;
    }
    else
    {
      v67 = v7->Children.Data.Size;
      v14 = v14 & 0xFFFFFFE2 | 2;
      other.Flags = v14;
      v91.ID = v67;
      other.value = (Scaleform::GFx::AS3::Value::VU)v91;
      v68 = resulta.Result;
      if ( !resulta.Result )
        goto LABEL_210;
      v69 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject;
      if ( (prop_namea->Kind & 3u) <= 1 && prop_namea->Obj.pObject )
      {
        v70 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)prop_namea->Obj.pObject;
        v71 = v.pNode;
      }
      else
      {
        v71 = v.pNode;
        v70 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v.pNode[16].pData;
      }
      if ( !v70 )
        v70 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v71[10].RefCount;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(*(Scaleform::GFx::AS3::Value **)ind, &n);
      v72 = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                               v69,
                                               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v91,
                                               (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v69->vfptr,
                                               v70,
                                               &n,
                                               (Scaleform::GFx::AS3::Instances::fl::XML *)&v7->vfptr);
      v73 = *v72;
      v.pNode = *v72;
      v74 = n.pNode;
      v12 = n.pNode->RefCount == 1;
      --v74->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v74);
      v91.Message.pNode = 0i64;
      v91.ID = 12;
      v92 = v73;
      v93 = 0i64;
      if ( v73 )
        v73->Size = (v73->Size + 1) & 0x8FBFFFFF;
      v75 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
              v7,
              (Scaleform::GFx::AS3::CheckResult *)&n,
              (signed int)v67,
              (Scaleform::GFx::AS3::Value *)&v91)->Result == 0;
      if ( (v91.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v91.ID >> 9) & 1 )
        {
          v12 = v91.Message.pNode->pData-- == (const char *)1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v91.Message.pNode = 0i64;
          v92 = 0i64;
          v93 = 0i64;
          v91.ID &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v91);
        }
      }
      if ( v75 )
      {
        v76 = v97;
        *v97 = 0;
        if ( v73 )
        {
          if ( (unsigned __int8)v73 & 1 )
          {
            v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v73 - 1);
          }
          else
          {
            v77 = v73->Size;
            if ( v77 & 0x3FFFFF )
            {
              v73->Size = v77 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v73);
            }
          }
        }
        v78 = v94.pNode;
        v12 = v94.pNode->RefCount == 1;
        --v78->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v78);
        if ( (char)(v14 & 0x1F) <= 9 )
          goto LABEL_219;
        if ( (v14 >> 9) & 1 )
        {
          v12 = v57->RefCount-- == 1;
          if ( v12 )
          {
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v57);
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags = v14 & 0xFFFFFDE0;
LABEL_219:
            if ( (valuea.Flags & 0x1F) > 9 )
            {
              if ( (valuea.Flags >> 9) & 1 )
              {
                v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v12 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                valuea.Bonus.pWeakProxy = 0i64;
                valuea.value = 0ui64;
                valuea.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
              }
            }
            return (Scaleform::GFx::AS3::CheckResult *)v76;
          }
LABEL_217:
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags = v14 & 0xFFFFFDE0;
          goto LABEL_219;
        }
        goto LABEL_218;
      }
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v73->pData
       + 21))(
        v73,
        v70);
      if ( (unsigned __int8)v73 & 1 )
      {
        v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v73 - 1);
      }
      else
      {
        v79 = v73->Size;
        if ( v79 & 0x3FFFFF )
        {
          v73->Size = v79 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v73);
        }
      }
    }
    if ( v68 )
    {
      v80 = (Scaleform::GFx::ASStringNode *)v7->Children.Data.Data[other.value.VS._1.VInt].pObject;
      v.pNode = v80;
      if ( v80 )
        v80->Size = (v80->Size + 1) & 0x8FBFFFFF;
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, _QWORD))v80->pData + 42))(v80, 0i64);
      v81 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n)->pNode->Size != 0;
      v82 = n.pNode;
      v12 = n.pNode->RefCount == 1;
      --v82->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v82);
      if ( v81 && (*((unsigned int (__fastcall **)(Scaleform::GFx::ASStringNode *))v80->pData + 26))(v80) == 1 )
        v83 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
                (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v80,
                (Scaleform::GFx::AS3::CheckResult *)&n,
                0i64,
                &valuea)->Result;
      else
        LOBYTE(v83) = 1;
      if ( (unsigned __int8)v80 & 1 )
      {
        v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v80 - 1);
      }
      else
      {
        v84 = v80->Size;
        if ( v84 & 0x3FFFFF )
        {
          v80->Size = v84 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v80);
        }
      }
LABEL_211:
      v76 = v97;
      *v97 = v83;
      v85 = v94.pNode;
      v12 = v94.pNode->RefCount == 1;
      --v85->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v85);
      if ( (char)(v14 & 0x1F) <= 9 )
        goto LABEL_219;
      if ( (v14 >> 9) & 1 )
      {
        v12 = v57->RefCount-- == 1;
        if ( v12 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v57);
        goto LABEL_217;
      }
LABEL_218:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      goto LABEL_219;
    }
LABEL_210:
    v83 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
            v7,
            (Scaleform::GFx::AS3::CheckResult *)&n,
            other.value.VS._1.VInt,
            &valuea)->Result;
    goto LABEL_211;
  }
  v26 = valuea.Flags & 0x1F;
  v27 = (Scaleform::GFx::AS3::Instances::fl::XML *)valuea.value.VS._1.VStr;
  if ( (unsigned int)(v26 - 12) <= 3
    && *(_QWORD *)&valuea.value.VNumber
    && (v28 = *(_QWORD *)(*(_QWORD *)&valuea.value.VNumber + 40i64), *(_DWORD *)(v28 + 120) == 19)
    && ~(*(_BYTE *)(v28 + 112) >> 5) & 1 )
  {
    Scaleform::StringBuffer::StringBuffer((Scaleform::StringBuffer *)&other, *((Scaleform::MemoryHeap **)v8 + 6));
    v29 = v27[1].pNext;
    v30 = 0i64;
    if ( v29 )
    {
      do
      {
        if ( v30 )
          Scaleform::StringBuffer::AppendChar((Scaleform::StringBuffer *)&other, 0x20u);
        v31 = *(_QWORD *)(v27[1].pRCCRaw + 8 * v30);
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS3::Value *, _QWORD))(*(_QWORD *)v31 + 192i64))(
          v31,
          &other,
          0i64);
        ++v30;
      }
      while ( v30 < (unsigned __int64)v29 );
    }
    v32 = &customWorldMapCaption;
    if ( *(_QWORD *)&other.Flags )
      v32 = *(const char **)&other.Flags;
    v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v9,
            &n,
            v32,
            (unsigned __int64)other.Bonus.pWeakProxy);
    Scaleform::GFx::AS3::Value::Assign(&valuea, v33);
    v34 = n.pNode;
    v12 = n.pNode->RefCount == 1;
    --v34->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&other);
    v8 = v.pNode;
  }
  else
  {
    if ( (unsigned int)(v26 - 12) <= 3
      && *(_QWORD *)&valuea.value.VNumber
      && (v35 = *(_QWORD *)(*(_QWORD *)&valuea.value.VNumber + 40i64), *(_DWORD *)(v35 + 120) == 18)
      && ~(*(_BYTE *)(v35 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v9, &n);
      Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(v27, &n);
      v36 = valuea.Flags;
      if ( (valuea.Flags & 0x1F) > 9 )
      {
        if ( (valuea.Flags >> 9) & 1 )
        {
          v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          valuea.Bonus.pWeakProxy = 0i64;
          valuea.value = 0ui64;
          v36 = valuea.Flags & 0xFFFFFDE0;
          valuea.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
          v36 = valuea.Flags;
        }
      }
      v12 = n.pNode == &n.pNode->pManager->NullStringNode;
      valuea.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v91.Message.pNode;
      if ( v12 )
      {
        valuea.value.VNumber = 0.0;
        valuea.Flags = v36 & 0xFFFFFFEC | 0xC;
      }
      else
      {
        valuea.Flags = v36 & 0xFFFFFFEA | 0xA;
        *(Scaleform::GFx::ASString *)&valuea.value.VNumber = n;
        ++n.pNode->RefCount;
      }
    }
    else
    {
      v37 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n);
      Scaleform::GFx::AS3::Value::Assign(&valuea, v37);
    }
    v38 = n.pNode;
    v12 = n.pNode->RefCount == 1;
    --v38->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  }
  v39 = 0i64;
  *(_QWORD *)ind = 0i64;
  v40 = 0i64;
  if ( v7->Attrs.Data.Size > 0 )
  {
    while ( 1 )
    {
      if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl::XML::Matches(
                              (Scaleform::GFx::AS3::Instances::fl::XML *)&v7->Attrs.Data.Data[v40].pObject->vfptr,
                              v5) )
      {
        if ( v39 )
        {
          if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *))v7->vfptr[2].Finalize_GC)(
                            v7,
                            &n,
                            v5) )
          {
            v6->Result = 0;
            if ( (unsigned __int8)v39 & 1 )
            {
              *(_QWORD *)ind = (char *)v39 - 1;
            }
            else
            {
              v42 = v39->RefCount;
              if ( v42 & 0x3FFFFF )
              {
                v39->RefCount = v42 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v39->vfptr);
              }
            }
            if ( (valuea.Flags & 0x1F) <= 9 )
              return v6;
            if ( !((valuea.Flags >> 9) & 1) )
              goto LABEL_30;
LABEL_90:
            v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            valuea.Bonus.pWeakProxy = 0i64;
            valuea.value = 0ui64;
LABEL_29:
            valuea.Flags &= 0xFFFFFDE0;
            return v6;
          }
        }
        else
        {
          v41 = (unsigned int *)&v7->Attrs.Data.Data[v40];
          if ( v41 != ind )
          {
            if ( *(_QWORD *)v41 )
              *(_DWORD *)(*(_QWORD *)v41 + 32i64) = (*(_DWORD *)(*(_QWORD *)v41 + 32i64) + 1) & 0x8FBFFFFF;
            v39 = *(Scaleform::GFx::AS3::Instances::fl::XMLAttr **)v41;
            *(_QWORD *)ind = *(_QWORD *)v41;
          }
        }
      }
      if ( ++v40 >= v7->Attrs.Data.Size )
      {
        if ( v39 )
          goto LABEL_109;
        break;
      }
    }
  }
  v43 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject;
  if ( (v5->Kind & 3u) > 1 )
    v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_QWORD *)v8 + 80);
  else
    v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v5->Obj.pObject;
  if ( !v44 )
    v44 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v.pNode[10].RefCount;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &v);
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v5->Name, &n);
  v45 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
          v43,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)&v91,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v43->vfptr,
          v44,
          &n,
          &v,
          (Scaleform::GFx::AS3::Instances::fl::XML *)&v7->vfptr)->pV;
  if ( v45 )
    v39 = v45;
  *(_QWORD *)ind = v39;
  v46 = n.pNode;
  v12 = n.pNode->RefCount == 1;
  --v46->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  v47 = v.pNode;
  v12 = v.pNode->RefCount == 1;
  --v47->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Attrs.Data.Data,
    &v7->Attrs,
    v7->Attrs.Data.Size + 1);
  v48 = (Scaleform::GFx::ASStringNode *)&v7->Attrs.Data.Data[v7->Attrs.Data.Size - 1];
  n.pNode = v48;
  *(_QWORD *)&v91.ID = v48;
  if ( v48 )
  {
    v48->pData = (const char *)v39;
    if ( v39 )
      v39->RefCount = (v39->RefCount + 1) & 0x8FBFFFFF;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v7->vfptr[7].ForEachChild_GC)(
    v7,
    v44);
LABEL_109:
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n);
  v49 = n.pNode;
  ++v49->RefCount;
  v50 = v39->Data.pNode;
  v12 = v50->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  v39->Data.pNode = v49;
  v51 = n.pNode;
  v12 = n.pNode->RefCount == 1;
  --v51->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  v6->Result = 1;
  if ( v39 )
  {
    if ( (unsigned __int8)v39 & 1 )
    {
      *(_QWORD *)ind = (char *)v39 - 1;
    }
    else
    {
      v52 = v39->RefCount;
      if ( v52 & 0x3FFFFF )
      {
        v39->RefCount = v52 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v39->vfptr);
      }
    }
  }
  v53 = valuea.Flags & 0x1F;
  if ( v53 <= 9 )
    return v6;
  if ( (valuea.Flags >> 9) & 1 )
    goto LABEL_90;
  switch ( v53 )
  {
    case 10:
      v54 = valuea.value.VS._1.VStr;
      v12 = *(_DWORD *)(*(_QWORD *)&valuea.value.VNumber + 24i64) == 1;
      --v54->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v54);
      return v6;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      v55 = valuea.value.VNumber;
      if ( !valuea.value.VS._1.VBool )
        goto LABEL_127;
      --*(_QWORD *)&valuea.value.VNumber;
      return v6;
    case 16:
    case 17:
      v55 = *(double *)&valuea.value.VS._2.VObj;
      if ( (_QWORD)valuea.value.VS._2.VObj & 1 )
      {
        --valuea.value.VS._2.VObj;
        return v6;
      }
LABEL_127:
      if ( v55 == 0.0 )
        return v6;
      v56 = *(_DWORD *)(*(_QWORD *)&v55 + 32i64);
      if ( !(v56 & 0x3FFFFF) )
        return v6;
      *(_DWORD *)(*(_QWORD *)&v55 + 32i64) = v56 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v55);
      v13 = v6;
      break;
    default:
      return v6;
  }
  return v13;
}

// File Line: 1995
// RVA: 0x7EE040
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rbp
  Scaleform::GFx::AS3::Multiname *v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // rdi
  __int64 v9; // [rsp+20h] [rbp-58h]
  __int64 v10; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *v12; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack v13; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *v14; // [rsp+58h] [rbp-20h]

  v10 = -2i64;
  v4 = list;
  v5 = prop_name;
  v6 = result;
  v7 = this;
  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&v9, prop_name, (unsigned int *)&v9 + 1)->Result )
  {
    if ( HIDWORD(v9) < v7->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v4, v7->Children.Data.Data[HIDWORD(v9)].pObject);
    v6->Result = 1;
  }
  else if ( ((unsigned int)v5->Kind >> 3) & 1 )
  {
    cb.Element = v7;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable';
    v12 = v4;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(v7, v5, &cb);
    v6->Result = 1;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
  }
  else
  {
    v13.Element = v7;
    v13.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable';
    v14 = v4;
    v6->Result = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(v7, v5, &v13) != 0;
    v13.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
  }
  return v6;
}

// File Line: 2027
// RVA: 0x7EDF90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Multiname *v4; // rbp
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // rdi
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rbx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h]
  unsigned int ind; // [rsp+28h] [rbp-10h]

  v4 = prop_name;
  v5 = this;
  v6 = result;
  v7 = value;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    if ( ind )
    {
      Scaleform::GFx::AS3::Value::SetUndefined(v7);
      v6->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(v7, (Scaleform::GFx::AS3::Object *)&v5->vfptr);
      v6->Result = 1;
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
           (Scaleform::GFx::AS3::Instances::fl::XML *)&v5->vfptr,
           (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&ind,
           v4)->pV;
    Scaleform::GFx::AS3::Value::Pick(v7, (Scaleform::GFx::AS3::Object *)&v8->vfptr);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *))v5->vfptr[18].ForEachChild_GC)(
      v5,
      v6,
      v4,
      v8);
  }
  return v6;
}

// File Line: 2056
// RVA: 0x7D1CB0
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindDynamicSlot(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Multiname *v3; // r13
  Scaleform::GFx::AS3::PropRef *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rsi
  unsigned __int64 v6; // rdi
  int v7; // er15
  unsigned __int64 v8; // r12
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rcx
  unsigned int v16; // eax
  void **v18; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v19; // [rsp+38h] [rbp-28h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // [rsp+40h] [rbp-20h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+48h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // [rsp+58h] [rbp-8h]

  v3 = mn;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  if ( ((unsigned int)mn->Kind >> 3) & 1 )
  {
    v19 = this;
    v18 = &Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
    v20 = 0i64;
    v7 = 0;
    if ( (mn->Name.Flags & 0x1F) != 10 )
      goto LABEL_38;
    v8 = this->Attrs.Data.Size;
    if ( !v8 )
      goto LABEL_38;
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
             (Scaleform::GFx::AS3::Instances::fl::XML *)&v5->Attrs.Data.Data[v6].pObject->vfptr,
             v3) )
      {
        ++v7;
        if ( !((unsigned __int8 (__fastcall *)(void ***, unsigned __int64))v18[1])(&v18, v6) )
          break;
      }
      ++v6;
    }
    while ( v6 < v8 );
    if ( v7 )
    {
      v4->pSI = (Scaleform::GFx::AS3::SlotInfo *)((unsigned __int64)v20 | 2);
      v4->This.Flags = 12;
      v4->This.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v4->This.value.VNumber = v5;
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
      v18 = &Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
      v9 = v20;
      if ( v20 )
      {
        if ( (unsigned __int8)v20 & 1 )
        {
          v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
        }
        else
        {
          v10 = v20->RefCount;
          if ( v10 & 0x3FFFFF )
          {
            v20->RefCount = v10 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
          }
        }
      }
      v18 = &Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
    }
    else
    {
LABEL_38:
      v4->pSI = 0i64;
      v4->SlotIndex = 0i64;
      v4->This.Flags = 0;
      v4->This.Bonus.pWeakProxy = 0i64;
      v18 = &Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
      v11 = v20;
      if ( v20 )
      {
        if ( (unsigned __int8)v20 & 1 )
        {
          v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
        }
        else
        {
          v12 = v20->RefCount;
          if ( v12 & 0x3FFFFF )
          {
            v20->RefCount = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
      v18 = &Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
    }
  }
  else
  {
    cb.Element = this;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
    v22 = 0i64;
    if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, mn, &cb) )
    {
      v4->pSI = (Scaleform::GFx::AS3::SlotInfo *)((unsigned __int64)v22 | 2);
      v4->This.Flags = 12;
      v4->This.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v4->This.value.VNumber = v5;
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
      cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
      v13 = v22;
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
        }
        else
        {
          v14 = v22->RefCount;
          if ( v14 & 0x3FFFFF )
          {
            v22->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
    }
    else
    {
      v4->pSI = 0i64;
      v4->SlotIndex = 0i64;
      v4->This.Flags = 0;
      v4->This.Bonus.pWeakProxy = 0i64;
      cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
      v15 = v22;
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
        }
        else
        {
          v16 = v22->RefCount;
          if ( v16 & 0x3FFFFF )
          {
            v22->RefCount = v16 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
      }
    }
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
  }
  return v4;
}

// File Line: 2076
// RVA: 0x7C0E80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // r12
  Scaleform::GFx::AS3::CheckResult *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rsi
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::CheckResult *v13; // rax

  v3 = prop_name;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  if ( ((unsigned int)prop_name->Kind >> 3) & 1 )
  {
    if ( this->Attrs.Data.Size > 0 )
    {
      do
      {
        v7 = (Scaleform::GFx::AS3::Instances::fl::XML *)&v5->Attrs.Data.Data[v6].pObject->vfptr;
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(v7, v3) )
        {
          v8 = v7->Parent.pObject;
          if ( v8 )
          {
            if ( (unsigned __int8)v8 & 1 )
            {
              v7->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v8 - 1);
            }
            else
            {
              v9 = v8->RefCount;
              if ( v9 & 0x3FFFFF )
              {
                v8->RefCount = v9 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
              }
            }
            v7->Parent.pObject = 0i64;
          }
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Attrs.Data,
            v6);
        }
        else
        {
          ++v6;
        }
      }
      while ( v6 < v5->Attrs.Data.Size );
    }
  }
  else if ( this->Children.Data.Size > 0 )
  {
    do
    {
      v10 = v5->Children.Data.Data[v6].pObject;
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(v10, v3) )
      {
        v11 = v10->Parent.pObject;
        if ( v11 )
        {
          if ( (unsigned __int8)v11 & 1 )
          {
            v10->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( v12 & 0x3FFFFF )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
            }
          }
          v10->Parent.pObject = 0i64;
        }
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Children,
          v6);
      }
      else
      {
        ++v6;
      }
    }
    while ( v6 < v5->Children.Data.Size );
  }
  v13 = v4;
  v4->Result = 1;
  return v13;
}

// File Line: 2181
// RVA: 0x7D4BA0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *v4; // r14
  Scaleform::GFx::AS3::Multiname *v5; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v6; // rbp
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rbx

  v3 = 0;
  v4 = cb;
  v5 = prop_name;
  v6 = this;
  if ( (prop_name->Name.Flags & 0x1F) != 10 )
    return 0i64;
  v7 = this->Attrs.Data.Size;
  v8 = 0i64;
  if ( v7 )
  {
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
             (Scaleform::GFx::AS3::Instances::fl::XML *)&v6->Attrs.Data.Data[v8].pObject->vfptr,
             v5) )
      {
        ++v3;
        if ( !v4->vfptr->Call(v4, v8) )
          break;
      }
      ++v8;
    }
    while ( v8 < v7 );
  }
  return v3;
}

// File Line: 2207
// RVA: 0x7D4C40
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *v3; // r13
  Scaleform::GFx::AS3::Multiname *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rax
  unsigned int v6; // er12
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r15
  Scaleform::GFx::AS3::Value *v9; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rbx
  char v11; // bp
  Scaleform::GFx::ASStringNode **v12; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v13; // rcx
  Scaleform::GFx::AS3::VM *v14; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rdi
  $CBB44125B27995AEB5908B7872D4CF4F *v16; // rdi
  Scaleform::GFx::AS3::VM *v17; // rdi
  __int64 v18; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // rsi
  Scaleform::GFx::AS3::GASRefCountBase *v20; // r8
  Scaleform::GFx::AS3::RefCountCollector<328> *v21; // r9
  unsigned __int64 v22; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v23; // r8
  __int64 v24; // rax
  bool v25; // zf
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-48h]
  __int64 v29; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v30; // [rsp+70h] [rbp+8h]
  unsigned __int64 v31; // [rsp+88h] [rbp+20h]

  v30 = this;
  v29 = -2i64;
  v3 = cb;
  v4 = prop_name;
  v5 = this;
  v6 = 0;
  v7 = this->Children.Data.Size;
  v31 = v7;
  v8 = 0i64;
  if ( v7 )
  {
    v9 = &prop_name->Name;
    while ( 1 )
    {
      v10 = v5->Children.Data.Data[v8].pObject;
      v11 = 0;
      if ( (v9->Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v9, &result);
        v12 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v10->vfptr[10].ForEachChild_GC)(v10);
        if ( *v12 == result.pNode || Scaleform::GFx::AS3::Multiname::IsAnyType(v4) )
        {
          if ( (v4->Kind & 3u) > 1 )
          {
            if ( Scaleform::GFx::AS3::Multiname::IsAnyType(v4) )
            {
              v11 = 1;
            }
            else
            {
              v17 = v10->pTraits.pObject->pVM;
              v18 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v10->vfptr[10].~RefCountBaseGC<328>)(v10);
              if ( ((unsigned int)v4->Kind >> 3) & 1 || (v19 = v17->DefXMLNamespace.pObject) == 0i64 )
                v19 = v17->PublicNamespace.pObject;
              if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(v4, v17->PublicNamespace.pObject) )
              {
                v20 = v4->Obj.pObject;
                v21 = v20[1]._pRCC;
                v22 = 0i64;
                if ( v21 )
                {
                  v23 = v20[1].vfptr;
                  while ( 1 )
                  {
                    if ( !(unsigned int)(*((_QWORD *)v23->ForEachChild_GC + 5) << 60 >> 60) )
                    {
                      v24 = *((_QWORD *)v23->ForEachChild_GC + 7);
                      v25 = *(_DWORD *)(v24 + 32) ? v24 == *(_QWORD *)(v18 + 56) : v19->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v18 + 56);
                      if ( v25 )
                        break;
                    }
                    ++v22;
                    v23 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)v23 + 8);
                    if ( v22 >= (unsigned __int64)v21 )
                      goto LABEL_37;
                  }
                  v11 = 1;
                }
LABEL_37:
                v7 = v31;
              }
              else
              {
                v7 = v31;
                if ( v19->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v18 + 56) )
                {
                  v11 = 0;
                  if ( !((*(_BYTE *)(v18 + 40) ^ *((_BYTE *)v19 + 40)) & 0xF) )
                    v11 = 1;
                }
              }
            }
          }
          else if ( v4->Obj.pObject )
          {
            v13 = v4->Obj.pObject;
            v14 = v10->pTraits.pObject->pVM;
            v15 = v14->DefXMLNamespace.pObject;
            if ( !v15 )
              v15 = v14->PublicNamespace.pObject;
            v16 = ($CBB44125B27995AEB5908B7872D4CF4F *)&v15->Uri;
            if ( !(unsigned int)((_QWORD)v13[1].vfptr << 60 >> 60)
              && (((unsigned int)v4->Kind >> 3) & 1 || v13[1].pNext->RefCount) )
            {
              v16 = &v13[1].16;
            }
            v25 = v16->pNext == *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v10->vfptr[10].~RefCountBaseGC<328>)(v10)
                                                                             + 56);
            v7 = v31;
            if ( v25 )
              v11 = 1;
          }
          else
          {
            v11 = 1;
          }
        }
        v26 = result.pNode;
        v25 = result.pNode->RefCount == 1;
        --v26->RefCount;
        if ( v25 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        if ( v11 )
        {
          ++v6;
          if ( !v3->vfptr->Call(v3, v8) )
            return v6;
        }
        v9 = &v4->Name;
      }
      if ( ++v8 >= v7 )
        return v6;
      v5 = v30;
    }
  }
  return v6;
}

// File Line: 2235
// RVA: 0x81A840
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetNamespace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v6; // rcx

  v2 = this;
  v3 = ns;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)ns);
  v4 = v2->Attrs.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    do
    {
      v6 = v2->Attrs.Data.Data[v5].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v6->vfptr[10].Finalize_GC)(
        v6,
        v3);
      ++v5;
    }
    while ( v5 < v4 );
  }
}

// File Line: 2257
// RVA: 0x7E8550
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetDescendants(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XMLList *list, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rbp
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r15
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r15
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rbx
  void **v11; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v12; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // [rsp+38h] [rbp-30h]

  v3 = prop_name;
  v4 = list;
  v5 = this;
  v6 = 0i64;
  if ( ((unsigned int)prop_name->Kind >> 3) & 1 )
  {
    v12 = this;
    v11 = &Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable';
    v13 = list;
    if ( (prop_name->Name.Flags & 0x1F) == 10 )
    {
      v7 = this->Attrs.Data.Size;
      v8 = 0i64;
      if ( v7 )
      {
        do
        {
          if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
                 (Scaleform::GFx::AS3::Instances::fl::XML *)&v5->Attrs.Data.Data[v8].pObject->vfptr,
                 v3)
            && !((unsigned __int8 (__fastcall *)(void ***, unsigned __int64))v11[1])(&v11, v8) )
          {
            break;
          }
          ++v8;
        }
        while ( v8 < v7 );
      }
    }
    v11 = &Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable';
  }
  v9 = v5->Children.Data.Size;
  if ( v9 )
  {
    do
    {
      v10 = v5->Children.Data.Data[v6].pObject;
      if ( !(((unsigned int)v3->Kind >> 3) & 1)
        && Scaleform::GFx::AS3::Instances::fl::XML::Matches(v5->Children.Data.Data[v6].pObject, v3) )
      {
        Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v4, v10);
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Multiname *))v10->vfptr[2].~RefCountBaseGC<328>)(
        v10,
        v4,
        v3);
      ++v6;
    }
    while ( v6 < v9 );
  }
}

// File Line: 2283
// RVA: 0x826A60
Scaleform::GFx::AS3::Instances::fl::XML *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Value *value)
{
  unsigned int v2; // er8
  long double v3; // rcx
  __int64 v4; // rax
  long double v6; // rcx
  __int64 v7; // rax

  v2 = value->Flags & 0x1F;
  if ( v2 - 12 <= 3 )
  {
    v3 = value->value.VNumber;
    if ( v3 != 0.0 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)&v3 + 40i64);
      if ( *(_DWORD *)(v4 + 120) == 18 )
      {
        if ( ~(*(_BYTE *)(v4 + 112) >> 5) & 1 )
          return (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VStr;
      }
    }
  }
  if ( v2 - 12 <= 3 )
  {
    v6 = value->value.VNumber;
    if ( v6 != 0.0 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64);
      if ( *(_DWORD *)(v7 + 120) == 19
        && ~(*(_BYTE *)(v7 + 112) >> 5) & 1
        && *(_QWORD *)(*(_QWORD *)&v6 + 88i64) == 1i64 )
      {
        return **(Scaleform::GFx::AS3::Instances::fl::XML ***)(*(_QWORD *)&v6 + 80i64);
      }
    }
  }
  return 0i64;
}

// File Line: 2300
// RVA: 0x7F29C0
bool __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasProperty(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Multiname *prop_name, bool check_prototype)
{
  Scaleform::GFx::AS3::Multiname *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v4; // rdi
  bool v5; // al
  unsigned int ind; // [rsp+20h] [rbp-28h]
  __int64 v7; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+68h] [rbp+20h]

  v7 = -2i64;
  v3 = prop_name;
  v4 = this;
  if ( Scaleform::GFx::AS3::GetVectorInd(&result, prop_name, &ind)->Result )
    return ind == 0;
  cb.Element = v4;
  cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable';
  if ( ((unsigned int)v3->Kind >> 3) & 1 )
    v5 = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(v4, v3, &cb) != 0;
  else
    v5 = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(v4, v3, &cb) != 0;
  return v5;
}

// File Line: 2333
// RVA: 0x7F5F80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildAt(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, unsigned __int64 pos, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  unsigned __int64 v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // r13
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rdx
  char v9; // di
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::AS3::Traits *v11; // rax
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // r12
  unsigned __int64 v14; // rax
  __int64 v15; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v16; // rax
  unsigned __int64 v17; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v18; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v19; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v20; // rdi
  unsigned __int64 v21; // r8
  bool v22; // zf
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v23; // rcx
  unsigned int v24; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v25; // rdi
  unsigned __int64 v26; // r8
  __int64 *v27; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v28; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v29; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v30; // rdx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v32; // rdx
  int v33; // eax
  Scaleform::GFx::AS3::VM::Error *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v36; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v37; // rcx
  Scaleform::GFx::AS3::Traits *v38; // rax
  Scaleform::GFx::AS3::Traits *v39; // r13
  Scaleform::GFx::AS3::CheckResult *v40; // rbx
  int v42; // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v43; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v44; // rax
  unsigned __int64 v45; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // rdi
  unsigned int v47; // eax
  Scaleform::GFx::AS3::VM **v48; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v49; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v50; // rdx
  unsigned int v51; // eax
  Scaleform::GFx::AS3::VM *v52; // rdx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::VM::Error *v54; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  unsigned int v56; // eax
  Scaleform::GFx::AS3::VM::Error v57; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::Instances::fl::XML *v58; // [rsp+40h] [rbp-39h]
  __int64 v59; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v60; // [rsp+50h] [rbp-29h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v61; // [rsp+58h] [rbp-21h]
  unsigned __int64 v62; // [rsp+60h] [rbp-19h]
  unsigned __int64 v63; // [rsp+68h] [rbp-11h]
  __int64 v64; // [rsp+70h] [rbp-9h]
  __int64 v65; // [rsp+78h] [rbp-1h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v66; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v67; // [rsp+88h] [rbp+Fh]
  char v68; // [rsp+90h] [rbp+17h]
  __int64 v69; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::VM *vm; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS3::CheckResult *v71; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> val; // [rsp+F8h] [rbp+7Fh]

  v71 = result;
  v69 = -2i64;
  v4 = value;
  v5 = pos;
  v6 = result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  vm = this->pTraits.pObject->pVM;
  v9 = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 )
  {
    v10 = (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VStr;
    val.pObject = v10;
    if ( v10 )
    {
      v11 = v10->pTraits.pObject;
      if ( v11->TraitsType == 19 )
      {
        if ( ~(LOBYTE(v11->Flags) >> 5) & 1 )
        {
          v63 = (unsigned __int64)v10[1].pNext;
          v12 = 0i64;
          if ( !v63 )
            goto LABEL_50;
          v13 = pos;
          v14 = -8i64 * pos;
          v62 = -8i64 * pos;
          while ( 2 )
          {
            v15 = *(_QWORD *)(v13 * 8 + v14 + v10[1].pRCCRaw);
            v16 = v7;
            do
            {
              if ( v16 == (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v15 )
              {
                Scaleform::GFx::AS3::VM::Error::Error(&v57, eXMLIllegalCyclicalLoop, vm);
                Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v34, &Scaleform::GFx::AS3::fl::TypeErrorTI);
                v35 = v57.Message.pNode;
                v22 = v57.Message.pNode->RefCount == 1;
                --v35->RefCount;
                if ( v22 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v35);
                goto LABEL_50;
              }
              v16 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v16->Parent.pObject;
            }
            while ( v16 );
            v17 = v7->Children.Data.Size;
            if ( v5 >= v17 )
            {
              if ( v5 != v17 )
                goto LABEL_46;
              if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 208i64))(v15) == 2 )
              {
                v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS3::VM::Error *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_QWORD *)v15 + 280i64))(
                                                                     v15,
                                                                     &v57,
                                                                     v7);
                v29 = (Scaleform::GFx::AS3::Instances::fl::XML *)*v28;
                v67 = *v28;
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Children,
                  &v7->Children,
                  v7->Children.Data.Size + 1);
                v30 = &v7->Children.Data.Data[v7->Children.Data.Size - 1];
                v61 = v30;
                v60 = v30;
                if ( v30 )
                {
                  v30->pObject = v29;
                  if ( v29 )
                    v29->RefCount = (v29->RefCount + 1) & 0x8FBFFFFF;
                }
                if ( v29 )
                {
                  if ( (unsigned __int8)v29 & 1 )
                  {
                    v67 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&v29[-1].Parent.pObject + 7);
                  }
                  else
                  {
                    v31 = v29->RefCount;
                    if ( v31 & 0x3FFFFF )
                    {
                      v29->RefCount = v31 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
                    }
                  }
                }
                goto LABEL_45;
              }
              v64 = v15;
              *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Children,
                &v7->Children,
                v7->Children.Data.Size + 1);
              v32 = &v7->Children.Data.Data[v7->Children.Data.Size - 1];
              v61 = v32;
              v60 = v32;
              if ( v32 )
              {
                v32->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v15;
                *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
              }
              if ( v15 & 1 )
              {
                v64 = v15 - 1;
                goto LABEL_44;
              }
            }
            else
            {
              if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 208i64))(v15) == 2 )
              {
                v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*(__int64 (__fastcall **)(__int64, char *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_QWORD *)v15 + 280i64))(
                                                                     v15,
                                                                     &v68,
                                                                     v7);
                v19 = (Scaleform::GFx::AS3::Instances::fl::XML *)*v18;
                v66 = *v18;
                v20 = &v7->Children;
                Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                  &v7->Children.Data,
                  v7->Children.Data.Size + 1);
                v21 = v7->Children.Data.Size;
                if ( v5 < v21 - 1 )
                  memmove(&v20->Data.Data[v13 + 1], &v20->Data.Data[v13], 8 * (v21 - v5) - 8);
                v22 = &v20->Data.Data[v13] == 0;
                v23 = &v20->Data.Data[v13];
                v60 = v23;
                v61 = v23;
                if ( !v22 )
                {
                  v23->pObject = v19;
                  if ( v19 )
                    v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
                }
                if ( v19 )
                {
                  if ( (unsigned __int8)v19 & 1 )
                  {
                    v66 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&v19[-1].Parent.pObject + 7);
                  }
                  else
                  {
                    v24 = v19->RefCount;
                    if ( v24 & 0x3FFFFF )
                    {
                      v19->RefCount = v24 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
                    }
                  }
                }
                goto LABEL_45;
              }
              v65 = v15;
              *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
              v25 = &v7->Children;
              Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                &v7->Children.Data,
                v7->Children.Data.Size + 1);
              v26 = v7->Children.Data.Size;
              if ( v5 < v26 - 1 )
                memmove(&v25->Data.Data[v13 + 1], &v25->Data.Data[v13], 8 * (v26 - v5) - 8);
              v22 = &v25->Data.Data[v13] == 0;
              v27 = (__int64 *)&v25->Data.Data[v13];
              v61 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v27;
              v60 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v27;
              if ( !v22 )
              {
                *v27 = v15;
                *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
              }
              if ( v15 & 1 )
              {
                v65 = v15 - 1;
LABEL_44:
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                  (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(v15 + 64),
                  (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
LABEL_45:
                v10 = val.pObject;
                v9 = 1;
LABEL_46:
                ++v12;
                ++v13;
                ++v5;
                v14 = v62;
                if ( v12 < v63 )
                  continue;
                goto LABEL_50;
              }
            }
            break;
          }
          v33 = *(_DWORD *)(v15 + 32);
          if ( v33 & 0x3FFFFF )
          {
            *(_DWORD *)(v15 + 32) = v33 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
          }
          goto LABEL_44;
        }
      }
    }
  }
  v36 = 0i64;
  val.pObject = 0i64;
  if ( (value->Flags & 0x1F) - 12 > 3
    || (v37 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)value->value.VS._1.VStr) == 0i64
    || (v38 = v37->pTraits.pObject, v38->TraitsType != 18)
    || !(~(LOBYTE(v38->Flags) >> 5) & 1) )
  {
    v57.ID = 0;
    v57.Message.pNode = 0i64;
    v39 = v7->pTraits.pObject;
    if ( !v39->pConstructor.pObject )
      v39->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->pTraits.pObject->vfptr);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::VM::Error *, signed __int64, Scaleform::GFx::AS3::Value *, char))v39->pConstructor.pObject->vfptr[4].ForEachChild_GC)(
      v39->pConstructor.pObject,
      &v57,
      1i64,
      v4,
      1);
    if ( v7->pTraits.pObject->pVM->HandleException )
      goto LABEL_60;
    v42 = v57.ID & 0x1F;
    v43 = v58;
    if ( (unsigned int)(v42 - 12) > 3 && v42 != 10 )
    {
      if ( !v58 )
      {
LABEL_73:
        if ( (v57.ID & 0x1F) > 9 )
        {
          if ( ((unsigned int)v57.ID >> 9) & 1 )
          {
            v22 = v57.Message.pNode->pData-- == (const char *)1;
            if ( v22 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v57.Message.pNode = 0i64;
            v58 = 0i64;
            v59 = 0i64;
            v57.ID &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v57);
          }
        }
        v6 = v71;
        v8 = vm;
        goto LABEL_80;
      }
    }
    else if ( !v58 )
    {
LABEL_60:
      v40 = v71;
      v71->Result = 0;
      if ( (v57.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v57.ID >> 9) & 1 )
        {
          v22 = v57.Message.pNode->pData-- == (const char *)1;
          if ( v22 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v57.Message.pNode = 0i64;
          v58 = 0i64;
          v59 = 0i64;
          v57.ID &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v57);
        }
      }
      return v40;
    }
    ++v58->RefCount;
    v43->RefCount &= 0x8FBFFFFF;
    v36 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v43;
    val.pObject = v43;
    goto LABEL_73;
  }
  if ( v37 )
  {
    v37->RefCount = (v37->RefCount + 1) & 0x8FBFFFFF;
    v36 = v37;
    val.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)&v37->vfptr;
  }
LABEL_80:
  v44 = v7;
  do
  {
    if ( v44 == v36 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v57, eXMLIllegalCyclicalLoop, v8);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v54, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v55 = v57.Message.pNode;
      v22 = v57.Message.pNode->RefCount == 1;
      --v55->RefCount;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v55);
      v6->Result = 0;
      if ( v36 )
      {
        if ( (unsigned __int8)v36 & 1 )
        {
          val.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)&v36[-1].Children.Data.Policy.Capacity + 7);
        }
        else
        {
          v56 = v36->RefCount;
          if ( v56 & 0x3FFFFF )
          {
            v36->RefCount = v56 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v36->vfptr);
          }
        }
      }
      return v6;
    }
    v44 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v44->Parent.pObject;
  }
  while ( v44 );
  v45 = v7->Children.Data.Size;
  if ( v5 >= v45 )
  {
    if ( v5 != v45 )
      goto LABEL_105;
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **))v36->vfptr[8].Finalize_GC)(&v36->vfptr) == 2 )
    {
      v48 = (Scaleform::GFx::AS3::VM **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **, Scaleform::GFx::AS3::VM::Error *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v36->vfptr[11].Finalize_GC)(
                                          &v36->vfptr,
                                          &v57,
                                          v7);
      v49 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v48;
      vm = *v48;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Children,
        &v7->Children,
        v7->Children.Data.Size + 1);
      v50 = &v7->Children.Data.Data[v7->Children.Data.Size - 1];
      v61 = v50;
      v60 = v50;
      if ( v50 )
      {
        v50->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v49;
        if ( v49 )
          v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v49 )
      {
        if ( (unsigned __int8)v49 & 1 )
        {
          vm = (Scaleform::GFx::AS3::VM *)((char *)&v49[-1].RefCount + 7);
        }
        else
        {
          v51 = v49->RefCount;
          if ( v51 & 0x3FFFFF )
          {
            v49->RefCount = v51 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v49);
          }
        }
      }
      goto LABEL_104;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Children,
      &v7->Children,
      v7->Children.Data.Size + 1);
    v52 = (Scaleform::GFx::AS3::VM *)&v7->Children.Data.Data[v7->Children.Data.Size - 1];
    vm = v52;
    *(_QWORD *)&v57.ID = v52;
    if ( v52 )
    {
      v52->vfptr = (Scaleform::GFx::AS3::VMVtbl *)v36;
      v36->RefCount = (v36->RefCount + 1) & 0x8FBFFFFF;
    }
  }
  else
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **))v36->vfptr[8].Finalize_GC)(&v36->vfptr) == 2 )
    {
      vm = *(Scaleform::GFx::AS3::VM **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **, Scaleform::GFx::AS3::VM::Error *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v36->vfptr[11].Finalize_GC)(
                                          &v36->vfptr,
                                          &v57,
                                          v7);
      v46 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)vm;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)&v7->Children.Data,
        v5,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&vm);
      if ( v46 )
      {
        if ( (unsigned __int8)v46 & 1 )
        {
          vm = (Scaleform::GFx::AS3::VM *)((char *)&v46[-1].RefCount + 7);
        }
        else
        {
          v47 = v46->RefCount;
          if ( v47 & 0x3FFFFF )
          {
            v46->RefCount = v47 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v46);
          }
        }
      }
      goto LABEL_104;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)&v7->Children.Data,
      v5,
      &val);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v36->Parent,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
LABEL_104:
  v9 = 1;
LABEL_105:
  if ( !v36 )
    goto LABEL_50;
  if ( (unsigned __int8)v36 & 1 )
  {
    val.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)&v36[-1].Children.Data.Policy.Capacity + 7);
    goto LABEL_50;
  }
  v53 = v36->RefCount;
  if ( v53 & 0x3FFFFF )
  {
    v36->RefCount = v53 - 1;
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v36->vfptr);
    v6->Result = v9;
    return v6;
  }
LABEL_50:
  v6->Result = v9;
  return v6;
}

// File Line: 2460
// RVA: 0x7F5EB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildAfter(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *child1, Scaleform::GFx::AS3::Value *child2)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v4; // rbx
  char v5; // si
  Scaleform::GFx::AS3::Value *v6; // rbp
  Scaleform::GFx::AS3::CheckResult *v7; // rdi
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rax
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // rdx
  char *v13; // rax
  char v15; // [rsp+38h] [rbp+10h]

  v4 = this;
  v5 = 0;
  v6 = child2;
  v7 = result;
  v8 = child1->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&child1->value.VNumber )
  {
    v13 = (char *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, _QWORD))v4->vfptr[13].ForEachChild_GC)(
                    v4,
                    &v15,
                    0i64);
LABEL_13:
    v5 = *v13;
    goto LABEL_14;
  }
  v9 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(v4, child1);
  if ( v9 )
  {
    v10 = v4->Children.Data.Size;
    v11 = 0i64;
    if ( v10 )
    {
      v12 = v4->Children.Data.Data;
      while ( v12->pObject != v9 )
      {
        ++v11;
        ++v12;
        if ( v11 >= v10 )
          goto LABEL_14;
      }
      v13 = (char *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, _QWORD, Scaleform::GFx::AS3::Value *))v4->vfptr[13].ForEachChild_GC)(
                      v4,
                      &v15,
                      (unsigned int)(v11 + 1),
                      v6);
      goto LABEL_13;
    }
  }
LABEL_14:
  v7->Result = v5;
  return v7;
}

// File Line: 2488
// RVA: 0x7F67A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildBefore(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *child1, Scaleform::GFx::AS3::Value *child2)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v4; // rbx
  char v5; // si
  Scaleform::GFx::AS3::Value *v6; // rbp
  Scaleform::GFx::AS3::CheckResult *v7; // rdi
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rax
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // rdx
  __int64 v13; // r8
  char v15; // [rsp+38h] [rbp+10h]

  v4 = this;
  v5 = 0;
  v6 = child2;
  v7 = result;
  v8 = child1->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&child1->value.VNumber )
  {
    v13 = LODWORD(v4->Children.Data.Size);
LABEL_13:
    v5 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, __int64, Scaleform::GFx::AS3::Value *))v4->vfptr[13].ForEachChild_GC)(
                     v4,
                     &v15,
                     v13,
                     child2);
    goto LABEL_14;
  }
  v9 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(v4, child1);
  if ( v9 )
  {
    v10 = v4->Children.Data.Size;
    v11 = 0i64;
    if ( v10 )
    {
      v12 = v4->Children.Data.Data;
      while ( v12->pObject != v9 )
      {
        ++v11;
        ++v12;
        if ( v11 >= v10 )
          goto LABEL_14;
      }
      v13 = (unsigned int)v11;
      child2 = v6;
      goto LABEL_13;
    }
  }
LABEL_14:
  v7->Result = v5;
  return v7;
}

// File Line: 2516
// RVA: 0x7C0810
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteChildren(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Instances::fl::XML *child)
{
  unsigned __int64 v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // r14
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // rcx
  unsigned int v8; // eax
  unsigned __int64 v9; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v11; // rcx
  unsigned int v12; // eax

  v2 = this->Children.Data.Size;
  v3 = this;
  if ( child )
  {
    v4 = 0i64;
    if ( v2 )
    {
      v5 = this->Children.Data.Data;
      while ( 1 )
      {
        v6 = v5->pObject;
        if ( v5->pObject == child )
          break;
        ++v4;
        ++v5;
        if ( v4 >= v2 )
          return;
      }
      if ( v6 )
      {
        v7 = v6->Parent.pObject;
        if ( v7 )
        {
          if ( (unsigned __int8)v7 & 1 )
          {
            v6->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v7 - 1);
          }
          else
          {
            v8 = v7->RefCount;
            if ( v8 & 0x3FFFFF )
            {
              v7->RefCount = v8 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
            }
          }
          v6->Parent.pObject = 0i64;
        }
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Children,
        v4);
    }
  }
  else
  {
    v9 = 0i64;
    if ( v2 )
    {
      do
      {
        v10 = v3->Children.Data.Data[v9].pObject;
        if ( v10 )
        {
          v11 = v10->Parent.pObject;
          if ( v11 )
          {
            if ( (unsigned __int8)v11 & 1 )
            {
              v10->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v11 - 1);
            }
            else
            {
              v12 = v11->RefCount;
              if ( v12 & 0x3FFFFF )
              {
                v11->RefCount = v12 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
              }
            }
            v10->Parent.pObject = 0i64;
          }
        }
        ++v9;
      }
      while ( v9 < v2 );
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Children,
      &v3->Children,
      0i64);
  }
}

// File Line: 2551
// RVA: 0x7C0790
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteByIndex(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, unsigned __int64 ind)
{
  unsigned __int64 v2; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rcx
  unsigned int v6; // eax

  v2 = ind;
  if ( ind < this->Children.Data.Size )
  {
    v3 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
    v4 = this->Children.Data.Data[ind].pObject;
    if ( v4 )
    {
      v5 = v4->Parent.pObject;
      if ( v5 )
      {
        if ( (unsigned __int8)v5 & 1 )
        {
          v4->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v5 - 1);
        }
        else
        {
          v6 = v5->RefCount;
          if ( v6 & 0x3FFFFF )
          {
            v5->RefCount = v6 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
          }
        }
        v4->Parent.pObject = 0i64;
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      v3,
      v2);
  }
}

// File Line: 2576
// RVA: 0x802480
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Normalize(Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned __int64 v1; // rbp
  Scaleform::GFx::ASString *v2; // r14
  unsigned __int64 v3; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *v4; // r15
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rax
  unsigned int v7; // ecx
  __int64 v8; // rbx

  v1 = this->Children.Data.Size;
  v2 = 0i64;
  v3 = 0i64;
  if ( v1 )
  {
    v4 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
    do
    {
      v5 = (Scaleform::GFx::ASString *)v4->Data.Data[v3].pObject;
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v5->pNode[5].pManager)(v5) == 2 )
      {
        if ( v2 )
        {
          if ( v5[7].pNode->Size )
            Scaleform::GFx::ASString::Append(v2 + 7, v5 + 7);
        }
        else
        {
          v6 = v5[7].pNode;
          v7 = v6->Size;
          if ( v7 )
          {
            v8 = 0i64;
            if ( v7 )
            {
              while ( Scaleform::GFx::ASUtils::IsWhiteSpace(v6->pData[v8]) )
              {
                v6 = v5[7].pNode;
                v8 = (unsigned int)(v8 + 1);
                if ( (unsigned int)v8 >= v6->Size )
                  goto LABEL_7;
              }
              v2 = v5;
              goto LABEL_15;
            }
          }
        }
LABEL_7:
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          v4,
          v3--);
        --v1;
      }
      else
      {
        v2 = 0i64;
      }
LABEL_15:
      ++v3;
    }
    while ( v3 < v1 );
  }
}

// File Line: 2616
// RVA: 0x7D2CD0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByPrefix(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::ASString *prefix, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r12
  Scaleform::GFx::ASString *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rbp
  int v6; // ebx
  unsigned __int64 v7; // r14
  __int64 v8; // rdi
  Scaleform::GFx::AS3::Value *v9; // rcx
  bool v10; // si
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  signed __int64 v13; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v15; // rcx
  __int64 v16; // rcx
  char v17; // al
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v3 = lp;
  v4 = prefix;
  v5 = this;
  v6 = 0;
  v7 = this->Namespaces.Data.Size;
  v8 = 0i64;
  if ( !v7 )
    goto LABEL_14;
  while ( 1 )
  {
    v9 = &v5->Namespaces.Data.Data[v8].pObject->Prefix;
    v10 = 0;
    if ( (v9->Flags & 0x1F) == 10 )
    {
      v6 |= 1u;
      if ( Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v9, &result)->pNode == v4->pNode )
        v10 = 1;
    }
    if ( v6 & 1 )
    {
      v6 &= 0xFFFFFFFE;
      v11 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    if ( v10 )
      break;
    if ( ++v8 >= v7 )
      goto LABEL_14;
  }
  v13 = (signed __int64)&v5->Namespaces.Data.Data[v8];
  if ( v13 )
    return *(Scaleform::GFx::AS3::Instances::fl::Namespace **)v13;
LABEL_14:
  v15 = v5->Parent.pObject;
  if ( v15 != v3 )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))v15->vfptr[15].Finalize_GC)(
                                                              v15,
                                                              v4,
                                                              v3);
  v16 = 0i64;
  while ( 1 )
  {
    v17 = v4->pNode->pData[v16++];
    if ( v17 != aXml_5[v16 - 1] )
      break;
    if ( v16 == 4 )
      return v5->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 2641
// RVA: 0x7D2E60
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByURI(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::ASString *uri, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  unsigned __int64 v3; // r11
  unsigned __int64 v4; // r9
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v6; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // r10
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rcx
  signed __int64 v10; // rax
  __int64 v11; // rcx
  const char *v12; // rdx
  char v13; // al

  v3 = this->Namespaces.Data.Size;
  v4 = 0i64;
  v5 = this;
  if ( !v3 )
    goto LABEL_5;
  v6 = this->Namespaces.Data.Data;
  v7 = v6;
  while ( v7->pObject->Uri.pNode != uri->pNode )
  {
    ++v4;
    ++v7;
    if ( v4 >= v3 )
      goto LABEL_5;
  }
  v10 = (signed __int64)&v6[v4];
  if ( v10 )
    return *(Scaleform::GFx::AS3::Instances::fl::Namespace **)v10;
LABEL_5:
  v8 = v5->Parent.pObject;
  if ( v8 != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, unsigned __int64))v8->vfptr[15].Finalize_GC)(
                                                              v8,
                                                              uri,
                                                              lp,
                                                              v4);
  v11 = 0i64;
  v12 = uri->pNode->pData;
  while ( 1 )
  {
    v13 = v12[v11++];
    if ( v13 != aXml_5[v11 - 1] )
      break;
    if ( v11 == 4 )
      return v5->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 2668
// RVA: 0x79A6B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AS3Replace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Multiname *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // r12
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // r13
  Scaleform::GFx::AS3::VM *v8; // r10
  unsigned int v9; // er9
  Scaleform::GFx::ASStringNode *v10; // rcx
  const char *v11; // rax
  long double v12; // rcx
  unsigned int v13; // ebx
  bool v14; // zf
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // rcx
  Scaleform::GFx::AS3::Traits *v16; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::WeakProxy *v21; // rsi
  unsigned int v22; // ebx
  unsigned __int64 v23; // r15
  Scaleform::GFx::AS3::Value::V2U v24; // r14
  long double v25; // rdi
  signed __int64 v26; // r12
  bool v27; // al
  int v28; // er15
  unsigned int v29; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rcx
  unsigned int v31; // eax
  int v32; // eax
  Scaleform::GFx::AS3::WeakProxy *v33; // rdx
  Scaleform::GFx::ASStringNode *v34; // rcx
  long double v35; // rcx
  int v36; // eax
  Scaleform::GFx::AS3::Value::VU v38; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::AS3::Value valuea; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-11h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::AS3::CheckResult *v42; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *prop_namea; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::ASString v44; // [rsp+E8h] [rbp+7Fh]

  prop_namea = prop_name;
  v42 = result;
  v4 = value;
  v5 = prop_name;
  v6 = result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  valuea.Flags = 0;
  valuea.Bonus.pWeakProxy = 0i64;
  v9 = value->Flags & 0x1F;
  if ( v9 - 12 <= 3 )
  {
    v10 = v4->value.VS._1.VStr;
    if ( v10 )
    {
      v11 = v10[1].pData;
      if ( *((_DWORD *)v11 + 30) == 18 )
      {
        if ( ~((const unsigned __int8)v11[112] >> 5) & 1 )
        {
          v12 = *(double *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, _QWORD))v10->pData
                            + 35))(
                             v10,
                             &resulta,
                             0i64);
          other.Bonus.pWeakProxy = 0i64;
          other.Flags = 12;
          other.value.VNumber = v12;
          other.value.VS._2.VObj = v38.VS._2.VObj;
          Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
          goto LABEL_6;
        }
      }
    }
  }
  if ( v9 - 12 <= 3 )
  {
    v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VStr;
    if ( v15 )
    {
      v16 = v15->pTraits.pObject;
      if ( v16->TraitsType == 19 )
      {
        if ( ~(LOBYTE(v16->Flags) >> 5) & 1 )
        {
          v17 = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(v15, &resulta, 0i64)->pV;
          other.Bonus.pWeakProxy = 0i64;
          other.Flags = 12;
          *(_QWORD *)&other.value.VNumber = v17;
          other.value.VS._2.VObj = v38.VS._2.VObj;
          Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
LABEL_6:
          v13 = other.Flags;
          if ( (other.Flags & 0x1F) > 9 )
          {
            if ( (other.Flags >> 9) & 1 )
            {
              v14 = other.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v14 )
                ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              other.Bonus.pWeakProxy = 0i64;
              other.value = 0ui64;
              other.Flags = v13 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
            }
          }
          goto LABEL_37;
        }
      }
    }
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins,
    &v44);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v44)->Result )
  {
    v6->Result = 0;
    v18 = v44.pNode;
    v14 = v44.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
LABEL_20:
    if ( (valuea.Flags & 0x1F) > 9 )
    {
      if ( (valuea.Flags >> 9) & 1 )
      {
        v14 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        valuea.Bonus.pWeakProxy = 0i64;
        valuea.value = 0ui64;
LABEL_79:
        valuea.Flags &= 0xFFFFFDE0;
        return v6;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
    }
    return v6;
  }
  v19 = valuea.Flags;
  if ( (valuea.Flags & 0x1F) > 9 )
  {
    if ( (valuea.Flags >> 9) & 1 )
    {
      v14 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      valuea.Bonus.pWeakProxy = 0i64;
      valuea.value = 0ui64;
      v19 = valuea.Flags & 0xFFFFFDE0;
      valuea.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
      v19 = valuea.Flags;
    }
  }
  v14 = v44.pNode == &v44.pNode->pManager->NullStringNode;
  valuea.value.VS._2.VObj = v38.VS._2.VObj;
  if ( v14 )
  {
    valuea.value.VNumber = 0.0;
    valuea.Flags = v19 & 0xFFFFFFEC | 0xC;
  }
  else
  {
    valuea.Flags = v19 & 0xFFFFFFEA | 0xA;
    *(Scaleform::GFx::ASString *)&valuea.value.VNumber = v44;
    ++v44.pNode->RefCount;
  }
  v20 = v44.pNode;
  v14 = v44.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_37:
  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&resulta, v5, (unsigned int *)&v44)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(v7, v6, LODWORD(v44.pNode), &valuea);
    goto LABEL_20;
  }
  v21 = 0i64;
  other.Bonus.pWeakProxy = 0i64;
  v22 = 0;
  other.Flags = 0;
  v23 = v7->Children.Data.Size;
  v24.VObj = (Scaleform::GFx::AS3::Object *)other.value.VS._2;
  v25 = other.value.VNumber;
  if ( v23 )
  {
    v26 = v23 - 1;
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(v7->Children.Data.Data[v26].pObject, prop_namea) )
      {
        if ( v22 & 0x1F )
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, _QWORD))v7->vfptr[14].~RefCountBaseGC<328>)(
            v7,
            other.value.VS._1.VInt);
        if ( (signed int)(v22 & 0x1F) > 9 )
        {
          if ( (v22 >> 9) & 1 )
          {
            v14 = v21->RefCount-- == 1;
            if ( v14 )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
            v21 = 0i64;
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            v22 &= 0xFFFFFDE0;
            other.Flags = v22;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
            v21 = other.Bonus.pWeakProxy;
            v22 = other.Flags;
          }
        }
        v22 = v22 & 0xFFFFFFE2 | 2;
        other.Flags = v22;
        v38.VS._1.VInt = v26;
        v25 = v38.VNumber;
        other.value = v38;
        v24.VObj = (Scaleform::GFx::AS3::Object *)v38.VS._2;
      }
      --v26;
      --v23;
    }
    while ( v23 );
    v6 = v42;
  }
  v27 = 1;
  v28 = v22 & 0x1F;
  if ( v22 & 0x1F )
    v27 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
            v7,
            (Scaleform::GFx::AS3::CheckResult *)&resulta,
            other.value.VS._1.VInt,
            &valuea)->Result;
  v6->Result = v27;
  if ( v28 > 9 )
  {
    if ( (v22 >> 9) & 1 )
    {
      v14 = v21->RefCount-- == 1;
      if ( v14 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v22 & 0xFFFFFDE0;
    }
    else
    {
      switch ( v28 )
      {
        case 10:
          v14 = (*(_DWORD *)(*(_QWORD *)&v25 + 24i64))-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v25);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          if ( other.value.VS._1.VBool )
          {
            *(_QWORD *)&other.value.VNumber = *(_QWORD *)&v25 - 1i64;
          }
          else if ( v25 != 0.0 )
          {
            v29 = *(_DWORD *)(*(_QWORD *)&v25 + 32i64);
            if ( v29 & 0x3FFFFF )
            {
              *(_DWORD *)(*(_QWORD *)&v25 + 32i64) = v29 - 1;
              v30 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v25;
              goto LABEL_73;
            }
          }
          break;
        case 16:
        case 17:
          if ( (_QWORD)other.value.VS._2.VObj & 1 )
          {
            other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v24.VObj - 1);
          }
          else if ( v24.VObj )
          {
            v31 = v24.VObj->RefCount;
            if ( v31 & 0x3FFFFF )
            {
              v24.VObj->RefCount = v31 - 1;
              v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24.VObj->vfptr;
LABEL_73:
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
            }
          }
          break;
        default:
          break;
      }
    }
  }
  v32 = valuea.Flags & 0x1F;
  if ( v32 > 9 )
  {
    if ( (valuea.Flags >> 9) & 1 )
    {
      v33 = valuea.Bonus.pWeakProxy;
      v14 = valuea.Bonus.pWeakProxy->RefCount == 1;
      --v33->RefCount;
      if ( v14 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v33);
      valuea.Bonus.pWeakProxy = 0i64;
      valuea.value = 0ui64;
      goto LABEL_79;
    }
    switch ( v32 )
    {
      case 10:
        v34 = valuea.value.VS._1.VStr;
        v14 = *(_DWORD *)(*(_QWORD *)&valuea.value.VNumber + 24i64) == 1;
        --v34->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
        break;
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
        v35 = valuea.value.VNumber;
        if ( !valuea.value.VS._1.VBool )
          goto LABEL_87;
        --*(_QWORD *)&valuea.value.VNumber;
        break;
      case 16:
      case 17:
        v35 = *(double *)&valuea.value.VS._2.VObj;
        if ( (_QWORD)valuea.value.VS._2.VObj & 1 )
        {
          --valuea.value.VS._2.VObj;
        }
        else
        {
LABEL_87:
          if ( v35 != 0.0 )
          {
            v36 = *(_DWORD *)(*(_QWORD *)&v35 + 32i64);
            if ( v36 & 0x3FFFFF )
            {
              *(_DWORD *)(*(_QWORD *)&v35 + 32i64) = v36 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v35);
            }
          }
        }
        break;
      default:
        return v6;
    }
  }
  return v6;
}BaseGC<328> **)&v35);
            }
          }
        }
        break;
      default:
        return v6;
    }
  }
  return v6;
}

// File Line: 2733
// RVA: 0x8127D0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v6; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h]
  unsigned int ind; // [rsp+24h] [rbp-24h]
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h]

  v13 = -2i64;
  v4 = value;
  v5 = result;
  v6 = this;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(v6, v5, ind, v4);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eXMLAssignmentToIndexedXMLNotAllowed, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v14.Message.pNode;
    v9 = v14.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v5->Result = 0;
  }
  return v5;
}

// File Line: 2744
// RVA: 0x812500
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::CheckResult *result, unsigned __int64 i, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::GFx::AS3::CheckResult *v6; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLElement *p; // rdi
  char v8; // r15
  unsigned __int64 v9; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::ASStringNode *v13; // rcx
  const char *v14; // rax
  long double v15; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v16; // rax
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *v20; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v21; // rcx
  unsigned int v22; // eax
  long double v23; // rax
  __int64 v24; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v25; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v28; // rbx
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::AS3::VM::Error v33; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v35; // [rsp+90h] [rbp+18h]

  v4 = value;
  v5 = i;
  v6 = result;
  p = this;
  v8 = 1;
  v9 = this->Children.Data.Size;
  if ( i >= v9 )
  {
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Children.Data,
      v9 + 1);
    v5 = p->Children.Data.Size - 1;
    v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&p->Children.Data.Data[v5];
    v11 = *v10;
    if ( *v10 )
    {
      if ( (unsigned __int8)v11 & 1 )
      {
        *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
      }
      else
      {
        v12 = v11->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          v11->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
      *v10 = 0i64;
    }
  }
  if ( (v4->Flags & 0x1F) - 12 > 3
    || (v13 = v4->value.VS._1.VStr) == 0i64
    || (v14 = v13[1].pData, *((_DWORD *)v14 + 30) != 18)
    || !(~((const unsigned __int8)v14[112] >> 5) & 1)
    || (*((unsigned int (**)(void))v13->pData + 26))() == 5 )
  {
    if ( (v4->Flags & 0x1F) - 12 <= 3
      && (v23 = v4->value.VNumber, v23 != 0.0)
      && (v24 = *(_QWORD *)(*(_QWORD *)&v23 + 40i64), *(_DWORD *)(v24 + 120) == 19)
      && ~(*(_BYTE *)(v24 + 112) >> 5) & 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, unsigned __int64))p->vfptr[14].~RefCountBaseGC<328>)(
        p,
        v5);
      v8 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, unsigned __int64, Scaleform::GFx::AS3::Value *))p->vfptr[13].ForEachChild_GC)(
                       p,
                       &resulta,
                       v5,
                       v4);
    }
    else
    {
      v25 = p->Children.Data.Data[v5].pObject;
      if ( v25 )
      {
        v26 = v25->Parent.pObject;
        if ( v26 )
        {
          if ( (unsigned __int8)v26 & 1 )
          {
            v25->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v26 - 1);
          }
          else
          {
            v27 = v26->RefCount;
            if ( v27 & 0x3FFFFF )
            {
              v26->RefCount = v27 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26->vfptr);
            }
          }
          v25->Parent.pObject = 0i64;
        }
      }
      v28 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)p->pTraits.pObject;
      v29 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v4, &resulta);
      v30 = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                                                  v28,
                                                                                  &v35,
                                                                                  (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v28->vfptr,
                                                                                  v29,
                                                                                  (Scaleform::GFx::AS3::Instances::fl::XML *)&p->vfptr);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&p->Children.Data.Data[v5],
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v30->pV);
      v31 = resulta.pNode;
      v19 = resulta.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    }
    goto LABEL_43;
  }
  v15 = v4->value.VNumber;
  if ( (*(unsigned int (__fastcall **)(_QWORD))(**(_QWORD **)&v15 + 208i64))(*(_QWORD *)&v4->value.VNumber) != 1 )
  {
LABEL_21:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(_QWORD *)&v15 + 64i64),
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)p);
    v20 = p->Children.Data.Data[v5].pObject;
    if ( v20 )
    {
      v21 = v20->Parent.pObject;
      if ( v21 )
      {
        if ( (unsigned __int8)v21 & 1 )
        {
          v20->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v21 - 1);
        }
        else
        {
          v22 = v21->RefCount;
          if ( v22 & 0x3FFFFF )
          {
            v21->RefCount = v22 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
          }
        }
        v20->Parent.pObject = 0i64;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&p->Children.Data.Data[v5],
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v15);
LABEL_43:
    v6->Result = v8;
    return v6;
  }
  v16 = p;
  while ( v16 != *(Scaleform::GFx::AS3::Instances::fl::XMLElement **)&v15 )
  {
    v16 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v16->Parent.pObject;
    if ( !v16 )
      goto LABEL_21;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v33, eXMLIllegalCyclicalLoop, p->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(p->pTraits.pObject->pVM, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v18 = v33.Message.pNode;
  v19 = v33.Message.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v6->Result = 0;
  return v6;
}

// File Line: 2819
// RVA: 0x818790
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetChildren(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v2; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLElement *p; // rdi
  Scaleform::GFx::AS3::VM *v4; // r13
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *v5; // r14
  int v6; // ecx
  __int64 v7; // rbx
  __int64 v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rdx
  int v11; // eax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  long double v14; // rsi
  __int64 v15; // rax
  unsigned __int64 v16; // rbp
  __int64 v17; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v18; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v19; // rax
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v21; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLText *v23; // rdx
  unsigned int v24; // eax
  bool v25; // zf
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+38h] [rbp-50h]
  unsigned int *v27; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v29; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::AS3::Instances::fl::XMLText *v30; // [rsp+A8h] [rbp+20h]

  v2 = value;
  p = this;
  v4 = this->pTraits.pObject->pVM;
  v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    0i64);
  v6 = v2->Flags & 0x1F;
  if ( (unsigned int)(v6 - 12) <= 3
    && (v7 = (__int64)v2->value.VS._1.VStr) != 0
    && (v8 = *(_QWORD *)(v7 + 40), *(_DWORD *)(v8 + 120) == 18)
    && ~(*(_BYTE *)(v8 + 112) >> 5) & 1 )
  {
    v9 = p;
    do
    {
      if ( v9 == (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v7 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v26, eXMLIllegalCyclicalLoop, v4);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v13 = v26.Message.pNode;
        goto LABEL_41;
      }
      v9 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v9->Parent.pObject;
    }
    while ( v9 );
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(v7 + 64),
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)p);
    v27 = (unsigned int *)v7;
    if ( v7 )
      *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v5,
      v5,
      v5->Size + 1);
    v10 = (Scaleform::GFx::ASStringNode *)&v5->Data[v5->Size - 1];
    result.pNode = v10;
    v29.pV = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v10;
    if ( v10 )
    {
      v10->pData = (const char *)v7;
      if ( v7 )
        *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
    }
    if ( v7 )
    {
      if ( v7 & 1 )
      {
        v27 = (unsigned int *)(v7 - 1);
      }
      else
      {
        v11 = *(_DWORD *)(v7 + 32);
        if ( v11 & 0x3FFFFF )
        {
          *(_DWORD *)(v7 + 32) = v11 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v7);
        }
      }
    }
  }
  else if ( (unsigned int)(v6 - 12) <= 3
         && (v14 = v2->value.VNumber, v14 != 0.0)
         && (v15 = *(_QWORD *)(*(_QWORD *)&v14 + 40i64), *(_DWORD *)(v15 + 120) == 19)
         && ~(*(_BYTE *)(v15 + 112) >> 5) & 1 )
  {
    v16 = *(_QWORD *)(*(_QWORD *)&v14 + 88i64);
    v17 = 0i64;
    if ( v16 )
    {
      while ( 2 )
      {
        v18 = *(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)(*(_QWORD *)(*(_QWORD *)&v14 + 80i64)
                                                                                         + 8 * v17);
        v19 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)p;
        do
        {
          if ( v19 == v18 )
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v26, eXMLIllegalCyclicalLoop, v4);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
            v13 = v26.Message.pNode;
            goto LABEL_41;
          }
          v19 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v19[8].pObject;
        }
        while ( v19 );
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          v18 + 8,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)p);
        if ( ++v17 < v16 )
          continue;
        break;
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)v5,
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)(*(_QWORD *)&v14 + 80i64));
  }
  else
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
      &result);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v2, (Scaleform::GFx::AS3::CheckResult *)&v27, &result)->Result )
    {
      v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                           (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)p->pTraits.pObject,
                                                           &v29,
                                                           (Scaleform::GFx::AS3::InstanceTraits::Traits *)p->pTraits.pObject,
                                                           &result,
                                                           (Scaleform::GFx::AS3::Instances::fl::XML *)&p->vfptr);
      v22 = *v21;
      v27 = (unsigned int *)*v21;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v5,
        v5,
        v5->Size + 1);
      v23 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)&v5->Data[v5->Size - 1];
      v29.pV = v23;
      v30 = v23;
      if ( v23 )
      {
        v23->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v22;
        if ( v22 )
          v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v27 = (unsigned int *)((char *)&v22[-1].RefCount + 7);
        }
        else
        {
          v24 = v22->RefCount;
          if ( v24 & 0x3FFFFF )
          {
            v22->RefCount = v24 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
          }
        }
      }
    }
    v13 = result.pNode;
LABEL_41:
    v25 = v13->RefCount-- == 1;
    if ( v25 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 2883
// RVA: 0x785710
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::XMLText(Scaleform::GFx::AS3::Instances::fl::XMLText *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *txt, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLText *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rax

  v4 = p;
  v5 = txt;
  v6 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v7 = v5->pNode;
  v6->Text = (Scaleform::GFx::ASString)v5->pNode;
  ++v7->RefCount;
  v6->Parent.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable';
}

// File Line: 2897
// RVA: 0x828540
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::ToXMLString(Scaleform::GFx::AS3::Instances::fl::XMLText *this, Scaleform::StringBuffer *buf, __int64 ident, Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces)
{
  int v4; // ebp
  Scaleform::StringBuffer *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLText *v6; // rdi
  Scaleform::GFx::AS3::Traits *v7; // rbx
  Scaleform::GFx::AS3::Class *v8; // rax
  Scaleform::GFx::AS3::Traits *v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  signed __int64 v13; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v13 = -2i64;
  v4 = ident;
  v5 = buf;
  v6 = this;
  v7 = this->pTraits.pObject;
  if ( !v7->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *, signed __int64))v7->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces,
      -2i64);
  v8 = v7->pConstructor.pObject;
  if ( SHIDWORD(v8[1].vfptr) >= 0 && BYTE3(v8[1].vfptr) && v4 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(v5, v4);
  v9 = v6->pTraits.pObject;
  if ( !v9->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *, signed __int64))v9->vfptr[3].~RefCountBaseGC<328>)(
      v6->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces,
      v13);
  if ( BYTE3(v9->pConstructor.pObject[1].vfptr) )
  {
    v10 = Scaleform::GFx::ASString::TruncateWhitespace(&v6->Text, &result);
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(v5, v10);
    v11 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(v5, &v6->Text);
  }
}

// File Line: 2923
// RVA: 0x7C0750
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XMLText *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLText *v4; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v5 = v3;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)&v4->vfptr;
  return v5;
}

// File Line: 2933
// RVA: 0x785180
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *n, Scaleform::GFx::ASString *v, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // rbx
  unsigned int v14; // eax

  v6 = n;
  v7 = ns;
  v8 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v9 = v6->pNode;
  v8->Text = (Scaleform::GFx::ASString)v6->pNode;
  ++v9->RefCount;
  v10 = p;
  v8->Parent.pObject = p;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable';
  v8->Ns.pObject = 0i64;
  v11 = v->pNode;
  v8->Data = (Scaleform::GFx::ASString)v->pNode;
  ++v11->RefCount;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v8->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&p,
    0,
    &v7->Uri,
    &v7->Prefix);
  v12 = v8->Ns.pObject;
  v13 = p;
  if ( p != (Scaleform::GFx::AS3::Instances::fl::XML *)v12 )
  {
    if ( v12 )
    {
      if ( (unsigned __int8)v12 & 1 )
      {
        v8->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v12 - 1);
      }
      else
      {
        v14 = v12->RefCount;
        if ( v14 & 0x3FFFFF )
        {
          v12->RefCount = v14 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
        }
      }
    }
    v8->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v13;
  }
}

// File Line: 2938
// RVA: 0x78FE60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::~XMLAttr(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable';
  v2 = this->Data.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  v4 = v1->Ns.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::XML::~XML((Scaleform::GFx::AS3::Instances::fl::XML *)&v1->vfptr);
}

// File Line: 2951
// RVA: 0x7D6DB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v5; // rsi
  long double v6; // rcx
  int v7; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v8; // rdx
  bool v9; // zf
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-30h]

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->Parent.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  v10.Flags = 10;
  v10.Bonus.pWeakProxy = 0i64;
  v6 = *(double *)&v5->Data.pNode;
  v10.value.VNumber = v6;
  if ( *(_QWORD *)&v6 == *(_QWORD *)(*(_QWORD *)&v6 + 8i64) + 104i64 )
  {
    v10.value.VNumber = 0.0;
    v10.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v10.Bonus.pWeakProxy;
    v10.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
  }
  v7 = v10.Flags & 0x1F;
  if ( v7 > 10 && !((v10.Flags >> 9) & 1) && v7 >= 11 )
  {
    if ( v7 <= 15 )
    {
      if ( !*(_QWORD *)&v10.value.VNumber )
        goto LABEL_19;
      v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v10.value;
      if ( (unsigned int)(v7 - 11) > 4 )
        v8 = 0i64;
      goto LABEL_18;
    }
    if ( v7 <= 17 && v10.value.VS._2.VObj )
    {
      v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v10.value.VS._2.VObj;
LABEL_18:
      v3(v4, v8);
      goto LABEL_19;
    }
  }
LABEL_19:
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags >> 9) & 1 )
    {
      v9 = v10.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v10.Bonus.pWeakProxy = 0i64;
      v10.value = 0ui64;
      v10.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
}

// File Line: 2963
// RVA: 0x7E7470
char *__fastcall UFG::OsuiteGameConfig::Version(UFG::OsuiteGameConfig *this)
{
  return this->mGameVersion.mData;
}

// File Line: 2968
// RVA: 0x815AC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ResolveNamespaces(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *nr, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rdi
  Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > v9; // r11
  signed __int64 v10; // rdx
  unsigned __int64 v11; // r9
  signed __int64 v12; // r8
  signed __int64 v13; // rcx
  signed __int64 v14; // rax
  unsigned __int64 v15; // r10
  signed __int64 v16; // r8
  signed __int64 v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString key; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+20h]

  v3 = lp;
  v4 = nr;
  v5 = this;
  v6 = this->Ns.pObject;
  if ( (v6->Prefix.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v6->Prefix, &result);
    key.pNode = result.pNode;
    ++key.pNode->RefCount;
    v7 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( !((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))v5->vfptr[15].Finalize_GC)(
            v5,
            &key,
            v3) )
    {
      v9.pTable = v4->pTable;
      v10 = 8i64;
      v11 = 5381i64;
      if ( !v4->pTable )
        goto LABEL_22;
      v12 = 8i64;
      v13 = 5381i64;
      do
      {
        v14 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + --v12);
        v13 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + v12);
      }
      while ( v12 );
      v15 = v14 & v9.pTable->SizeMask;
      v16 = v15;
      v17 = (signed __int64)v9.pTable + 8 * (v15 + 2 * (v15 + 1));
      if ( *(_QWORD *)v17 == -2i64 || *(_QWORD *)(v17 + 8) != v15 )
        goto LABEL_22;
      while ( *(_QWORD *)(v17 + 8) != v15 || *(Scaleform::GFx::ASStringNode **)(v17 + 16) != key.pNode )
      {
        v16 = *(_QWORD *)v17;
        if ( *(_QWORD *)v17 == -1i64 )
          goto LABEL_16;
        v17 = (signed __int64)v9.pTable + 8 * (v16 + 2 * (v16 + 1));
      }
      if ( v16 < 0
        || !(Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)v9.pTable + 8 * (v16 + 2 * (v16 + 2))) )
      {
LABEL_22:
        do
LABEL_16:
          v11 = *((unsigned __int8 *)&key.pNode + --v10) + 65599 * v11;
        while ( v10 );
        Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
          (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v4->pTable,
          v4->pHeap,
          &key,
          v11);
      }
    }
    v18 = key.pNode;
    v8 = key.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 2987
// RVA: 0x81A830
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::SetNamespace(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)ns);
}

// File Line: 2992
// RVA: 0x7EE7D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetQName(Scaleform::GFx::AS3::Instances::fl::XMLElement *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v2; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::QName *v3; // r8
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v6; // [rsp+58h] [rbp+10h]

  v6 = result;
  v2 = result;
  v3 = (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject;
  result->pObject = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
                      v3,
                      &resulta,
                      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v3->vfptr,
                      &this->Text,
                      this->Ns.pObject)->pV;
  return v2;
}

// File Line: 3006
// RVA: 0x826710
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToString(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::StringBuffer *buf, int __formal)
{
  Scaleform::StringBuffer::AppendString(buf, this->Data.pNode->pData, this->Data.pNode->Size);
}

// File Line: 3011
// RVA: 0x826AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToXMLString(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::StringBuffer *buf, int ident, Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces, Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Instances::fl::XML::EscapeAttributeValue(buf, &this->Data);
}

// File Line: 3017
// RVA: 0x7C9440
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::EqualsInternal(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v3; // rdi
  signed __int64 result; // rax

  v2 = other;
  v3 = this;
  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
             (Scaleform::GFx::AS3::Instances::fl::XML *)&this->vfptr,
             other);
  if ( !(_DWORD)result )
    result = (unsigned int)(v3->Data.pNode != (Scaleform::GFx::ASStringNode *)v2[1]._pRCC) + 1;
  return result;
}

// File Line: 3032
// RVA: 0x7C01F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XMLAttr *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v4; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> resulta; // [rsp+50h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         this->Ns.pObject,
         &this->Text,
         &this->Data,
         parent)->pV;
  v5 = v3;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)&v4->vfptr;
  return v5;
}

// File Line: 3046
// RVA: 0x7855C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::ASString *v, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rax

  v5 = v;
  v6 = n;
  v7 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v8 = v6->pNode;
  v7->Text = (Scaleform::GFx::ASString)v6->pNode;
  ++v8->RefCount;
  v7->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::`vftable';
  v9 = v5->pNode;
  v7->Data = (Scaleform::GFx::ASString)v5->pNode;
  ++v9->RefCount;
}

// File Line: 3050
// RVA: 0x7EB6B0
signed __int64 __fastcall Scaleform::Render::DICommand_ApplyFilter::GetType(CAkSwitchCntr *this)
{
  return 4i64;
}

// File Line: 3055
// RVA: 0x7C0710
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v4; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         &this->Data,
         parent)->pV;
  v5 = v3;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)&v4->vfptr;
  return v5;
}

// File Line: 3061
// RVA: 0x7EE840
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::GetQName(Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v2; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v5; // [rsp+58h] [rbp+10h]

  v5 = result;
  v2 = result;
  result->pObject = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
                      (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
                      &resulta,
                      this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
                      &this->Text,
                      this->pTraits.pObject->pVM->PublicNamespace.pObject)->pV;
  return v2;
}

// File Line: 3067
// RVA: 0x828110
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::ToXMLString(Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this, Scaleform::StringBuffer *buf, __int64 ident, Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces, Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Traits *v5; // rbx
  int v6; // edi
  Scaleform::StringBuffer *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v8; // rbp
  Scaleform::GFx::AS3::Class *v9; // rax

  v5 = this->pTraits.pObject;
  v6 = ident;
  v7 = buf;
  v8 = this;
  if ( !v5->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *))v5->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces);
  v9 = v5->pConstructor.pObject;
  if ( SHIDWORD(v9[1].vfptr) >= 0 && BYTE3(v9[1].vfptr) && v6 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(v7, v6);
  Scaleform::StringBuffer::AppendString(v7, "<?", 2i64);
  Scaleform::StringBuffer::AppendString(v7, v8->Text.pNode->pData, v8->Text.pNode->Size);
  Scaleform::StringBuffer::AppendChar(v7, 0x20u);
  Scaleform::StringBuffer::AppendString(v7, v8->Data.pNode->pData, v8->Data.pNode->Size);
  Scaleform::StringBuffer::AppendString(v7, "?>", 2i64);
}

// File Line: 3091
// RVA: 0x7C9850
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::EqualsInternal(Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this, Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v3; // rdi
  signed __int64 result; // rax

  v2 = other;
  v3 = this;
  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
             (Scaleform::GFx::AS3::Instances::fl::XML *)&this->vfptr,
             other);
  if ( !(_DWORD)result )
    result = (unsigned int)(v3->Data.pNode != (Scaleform::GFx::ASStringNode *)v2[1].vfptr) + 1;
  return result;
}

// File Line: 3104
// RVA: 0x785290
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::XMLComment(Scaleform::GFx::AS3::Instances::fl::XMLComment *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rax

  v4 = p;
  v5 = n;
  v6 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v7 = v5->pNode;
  v6->Text = (Scaleform::GFx::ASString)v5->pNode;
  ++v7->RefCount;
  v6->Parent.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLComment::`vftable';
}

// File Line: 3113
// RVA: 0x7C0240
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XMLComment *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v4; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v5 = v3;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)&v4->vfptr;
  return v5;
}

// File Line: 3119
// RVA: 0x826730
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::ToString(Scaleform::GFx::AS3::Instances::fl::XMLComment *this, Scaleform::StringBuffer *buf, __int64 ident)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLComment *, Scaleform::StringBuffer *, __int64, _QWORD, _QWORD))this->vfptr[8].~RefCountBaseGC<328>)(
    this,
    buf,
    ident,
    0i64,
    0i64);
}

// File Line: 3124
// RVA: 0x826B00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::ToXMLString(Scaleform::GFx::AS3::Instances::fl::XMLComment *this, Scaleform::StringBuffer *buf, __int64 ident, Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces, Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Traits *v5; // rbx
  int v6; // edi
  Scaleform::StringBuffer *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v8; // rbp
  Scaleform::GFx::AS3::Class *v9; // rax

  v5 = this->pTraits.pObject;
  v6 = ident;
  v7 = buf;
  v8 = this;
  if ( !v5->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *))v5->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces);
  v9 = v5->pConstructor.pObject;
  if ( SHIDWORD(v9[1].vfptr) >= 0 && BYTE3(v9[1].vfptr) && v6 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(v7, v6);
  Scaleform::StringBuffer::AppendString(v7, "<!--", 4i64);
  Scaleform::StringBuffer::AppendString(v7, v8->Text.pNode->pData, v8->Text.pNode->Size);
  Scaleform::StringBuffer::AppendString(v7, "-->", 3i64);
}

// File Line: 3151
// RVA: 0x7C9480
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::EqualsInternal(Scaleform::GFx::AS3::Instances::fl::XMLComment *this, Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  signed __int64 result; // rax

  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
             (Scaleform::GFx::AS3::Instances::fl::XML *)&this->vfptr,
             other);
  if ( !(_DWORD)result )
    result = 1i64;
  return result;
}

// File Line: 3165
// RVA: 0x7FE040
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rax

  v5 = n;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XML *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                    this->pVM->MHeap,
                                                    72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XML::XML(v8, v6, v5, p);
  v7->pV = v8;
  return v7;
}

// File Line: 3171
// RVA: 0x7FE670
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v7; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v9; // rax

  v6 = ns;
  v7 = t;
  v8 = result;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)this->pVM->MHeap->vfptr->Alloc(this->pVM->MHeap, 152ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(v9, v7, v6, n, p);
  v8->pV = v9;
  return v8;
}

// File Line: 3177
// RVA: 0x7FE770
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *txt, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLText *v8; // rax

  v5 = txt;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                        this->pVM->MHeap,
                                                        72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XMLText::XMLText(v8, v6, v5, p);
  v7->pV = v8;
  return v7;
}

// File Line: 3183
// RVA: 0x7FE7F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::StringDataPtr *txt, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::Instance *v8; // rax
  Scaleform::GFx::ASString *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v15; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::AS3::Instance *v16; // [rsp+68h] [rbp+20h]

  v5 = t;
  v6 = result;
  v7 = t->pVM;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->StringManagerRef->Builtins,
    &resulta,
    txt->pStr,
    txt->Size);
  v8 = (Scaleform::GFx::AS3::Instance *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))v7->MHeap->vfptr->Alloc)(
                                          v7->MHeap,
                                          72i64);
  v9 = (Scaleform::GFx::ASString *)v8;
  v15 = v8;
  v16 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v8, v5);
    v9->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
    v9->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    v9[7].pNode = resulta.pNode;
    ++resulta.pNode->RefCount;
    v10 = p;
    v9[8].pNode = (Scaleform::GFx::ASStringNode *)p;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
    v9->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable';
  }
  else
  {
    v9 = 0i64;
  }
  v6->pV = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v9;
  v11 = resulta.pNode;
  v12 = resulta.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return v6;
}

// File Line: 3192
// RVA: 0x7FE560
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *n, Scaleform::GFx::ASString *v, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v10; // rax

  v7 = ns;
  v8 = t;
  v9 = result;
  v10 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                         this->pVM->MHeap,
                                                         88i64);
  if ( v10 )
    Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(v10, v8, v7, n, v, p);
  v9->pV = v10;
  return v9;
}

// File Line: 3198
// RVA: 0x7FE6F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::ASString *v, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v7; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v9; // rax

  v6 = n;
  v7 = t;
  v8 = result;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                             this->pVM->MHeap,
                                                             80i64);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(v9, v7, v6, v, p);
  v8->pV = v9;
  return v8;
}

// File Line: 3204
// RVA: 0x7FE5F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v8; // rax

  v5 = n;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLComment *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                           this->pVM->MHeap,
                                                           72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XMLComment::XMLComment(v8, v6, v5, p);
  v7->pV = v8;
  return v7;
}

// File Line: 3211
// RVA: 0x7F8830
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsNameStartChar(Scaleform::GFx::AS3::CheckResult *result, int c)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rax

  if ( c == 58
    || c == 95
    || (unsigned int)(c - 65) <= 0x19
    || (unsigned int)(c - 97) <= 0x19
    || (unsigned int)(c - 192) <= 0x16
    || (unsigned int)(c - 216) <= 0x1E
    || (unsigned int)(c - 248) <= 0x207
    || (unsigned int)(c - 880) <= 0xD
    || (unsigned int)(c - 895) <= 0x1C80
    || (unsigned int)(c - 8204) <= 1
    || (unsigned int)(c - 8304) <= 0x11F
    || (unsigned int)(c - 11264) <= 0x3EF
    || (unsigned int)(c - 12289) <= 0xA7FE
    || (unsigned int)(c - 63744) <= 0x4CF
    || (unsigned int)(c - 65008) <= 0x20D )
  {
    v2 = result;
  }
  else
  {
    v2 = result;
    if ( (unsigned int)(c - 0x10000) > 0xDFFFF )
    {
      result->Result = 0;
      return v2;
    }
  }
  result->Result = 1;
  return v2;
}

// File Line: 3276
// RVA: 0x7F87C0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsNameChar(Scaleform::GFx::AS3::CheckResult *result, int c)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rbx
  int v3; // edi
  Scaleform::GFx::AS3::CheckResult *v4; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h]

  v2 = result;
  v3 = c;
  if ( Scaleform::GFx::AS3::IsNameStartChar(&resulta, c)->Result
    || (unsigned int)(v3 - 45) <= 1
    || (unsigned int)(v3 - 48) <= 9
    || v3 == 183
    || (unsigned int)(v3 - 768) <= 0x6F )
  {
    v4 = v2;
  }
  else
  {
    v4 = v2;
    if ( (unsigned int)(v3 - 8255) > 1 )
    {
      v2->Result = 0;
      return v4;
    }
  }
  v2->Result = 1;
  return v4;
}

// File Line: 3315
// RVA: 0x7F95A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsValidName(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rdi
  Scaleform::GFx::ASString *v3; // r14
  Scaleform::GFx::AS3::CheckResult *v4; // rax
  unsigned int v5; // ebx
  unsigned int v6; // esi
  Scaleform::GFx::ASStringNode *v7; // r14
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h]

  v2 = result;
  v3 = name;
  if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
    && Scaleform::GFx::AS3::IsNameStartChar(&resulta, *v3->pNode->pData)->Result )
  {
    v5 = 1;
    v6 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v3->pNode);
    if ( v6 <= 1 )
    {
LABEL_8:
      v2->Result = 1;
    }
    else
    {
      v7 = v3->pNode;
      while ( Scaleform::GFx::AS3::IsNameChar(&resulta, v7->pData[v5])->Result )
      {
        if ( ++v5 >= v6 )
          goto LABEL_8;
      }
      v2->Result = 0;
    }
    v4 = v2;
  }
  else
  {
    v2->Result = 0;
    v4 = v2;
  }
  return v4;
}

// File Line: 3427
// RVA: 0x158E8D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ADF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::prototypeGet;
  return result;
}

// File Line: 3428
// RVA: 0x1594030
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE00 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 3429
// RVA: 0x158E840
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_2_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE10 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,2,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3toString;
  return result;
}

// File Line: 3430
// RVA: 0x1594060
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_3_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE20 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3hasOwnProperty;
  return result;
}

// File Line: 3431
// RVA: 0x1595F20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_4_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,4,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable;
  return result;
}

// File Line: 3432
// RVA: 0x1594090
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE40 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3addNamespace;
  return result;
}

// File Line: 3433
// RVA: 0x15940C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_6_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE50 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,6,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3appendChild;
  return result;
}

// File Line: 3434
// RVA: 0x15940F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_7_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE60 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,7,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3attribute;
  return result;
}

// File Line: 3435
// RVA: 0x158E870
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_8_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE70 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,8,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3attributes;
  return result;
}

// File Line: 3436
// RVA: 0x1594120
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_9_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE80 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,9,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3child;
  return result;
}

// File Line: 3437
// RVA: 0x158E8A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_10_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AE90 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,10,long>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3childIndex;
  return result;
}

// File Line: 3438
// RVA: 0x158EB70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_11_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AEA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,11,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3children;
  return result;
}

// File Line: 3439
// RVA: 0x158EBA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_12_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AEB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,12,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3comments;
  return result;
}

// File Line: 3440
// RVA: 0x1594270
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_13_bool_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AEC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,13,bool,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3contains;
  return result;
}

// File Line: 3441
// RVA: 0x158EBD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_14_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AED0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3copy;
  return result;
}

// File Line: 3442
// RVA: 0x1596070
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_15_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AEE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,15,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3descendants;
  return result;
}

// File Line: 3443
// RVA: 0x1595F50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_16_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AEF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,16,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3elements;
  return result;
}

// File Line: 3444
// RVA: 0x158E900
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_17_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF00 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,17,bool>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3hasComplexContent;
  return result;
}

// File Line: 3445
// RVA: 0x158E930
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_18_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF10 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,18,bool>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3hasSimpleContent;
  return result;
}

// File Line: 3446
// RVA: 0x158E960
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_19_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF20 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,19,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3inScopeNamespaces;
  return result;
}

// File Line: 3447
// RVA: 0x1595F80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_20_Scaleform::GFx::AS3::Value_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,20,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildAfter;
  return result;
}

// File Line: 3448
// RVA: 0x1595FB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_21_Scaleform::GFx::AS3::Value_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF40 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,21,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildBefore;
  return result;
}

// File Line: 3449
// RVA: 0x158E990
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_22_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF50 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,22,long>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, int *))Scaleform::GFx::AS3::Class::lengthGet;
  return result;
}

// File Line: 3450
// RVA: 0x158E9C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_23_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF60 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,23,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet;
  return result;
}

// File Line: 3451
// RVA: 0x158E9F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_24_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::QName___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF70 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,24,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3name;
  return result;
}

// File Line: 3452
// RVA: 0x1595FE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_25_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF80 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,25,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_;
  return result;
}

// File Line: 3453
// RVA: 0x158EA20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_26_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AF90 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,26,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3namespaceDeclarations;
  return result;
}

// File Line: 3454
// RVA: 0x158EA50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_27_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,27,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind;
  return result;
}

// File Line: 3455
// RVA: 0x158EA80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_28_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,28,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3normalize;
  return result;
}

// File Line: 3456
// RVA: 0x158EAB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_29_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,29,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3parent;
  return result;
}

// File Line: 3457
// RVA: 0x1596010
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_30_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFD0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,30,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3processingInstructions;
  return result;
}

// File Line: 3458
// RVA: 0x1594150
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_31_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,31,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3prependChild;
  return result;
}

// File Line: 3459
// RVA: 0x1594180
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_32_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AFF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3removeNamespace;
  return result;
}

// File Line: 3460
// RVA: 0x1596040
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::XML_33_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B000 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,33,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3replace;
  return result;
}

// File Line: 3461
// RVA: 0x15941B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_34_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B010 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,34,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3setChildren;
  return result;
}

// File Line: 3462
// RVA: 0x15941E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_35_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B020 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,35,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3setLocalName;
  return result;
}

// File Line: 3463
// RVA: 0x1594210
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_36_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B030 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3setName;
  return result;
}

// File Line: 3464
// RVA: 0x1594240
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::XML_37_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B040 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,37,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3setNamespace;
  return result;
}

// File Line: 3465
// RVA: 0x158EAE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_38_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XMLList___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B050 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,38,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3text;
  return result;
}

// File Line: 3466
// RVA: 0x158EB10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_39_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B060 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,39,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString;
  return result;
}

// File Line: 3467
// RVA: 0x158EB40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::XML_40_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::XML___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B070 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,40,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *))Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf;
  return result;
}

// File Line: 3484
// RVA: 0x8589A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::prototypeGet(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rdi
  __int64 v3; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rbx
  unsigned int v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v3 + 200));
  v4 = v2->pObject;
  v5 = resulta.pV;
  if ( resulta.pV != v2->pObject )
  {
    if ( v4 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v4 - 1);
        v2->pObject = v5;
        return;
      }
      v6 = v4->RefCount;
      if ( v6 & 0x3FFFFF )
      {
        v4->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v2->pObject = v5;
  }
}

// File Line: 3500
// RVA: 0x7A82E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rdi
  char *v5; // r8
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  char *pstr; // [rsp+28h] [rbp-40h]
  unsigned __int64 length; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  Scaleform::StringBuffer::StringBuffer((Scaleform::StringBuffer *)&pstr, v4->MHeap);
  v3->vfptr[8].ForEachChild_GC(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)&pstr,
    0i64);
  v5 = &customWorldMapCaption;
  if ( pstr )
    v5 = pstr;
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
         &resulta,
         v5,
         length)->pNode;
  ++v6->RefCount;
  v7 = v2->pNode;
  v8 = v2->pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v2->pNode = v6;
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pstr);
}

// File Line: 3514
// RVA: 0x79F280
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasOwnProperty(Scaleform::GFx::AS3::Instances::fl::XML *this, bool *result, Scaleform::GFx::ASString *p)
{
  *result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))this->vfptr[9].Finalize_GC)(
              this,
              p);
}

// File Line: 3525
// RVA: 0x7A1AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned int v5; // er8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rdx
  long double v7; // rdi
  __int64 v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // al
  Scaleform::GFx::ASString resulta; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASString v15; // [rsp+30h] [rbp-40h]
  __int64 v16; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v18; // [rsp+90h] [rbp+20h]

  v16 = -2i64;
  v4 = result;
  if ( argc )
  {
    v5 = argv->Flags & 0x1F;
    if ( v5 )
    {
      if ( v5 - 12 > 3 && v5 != 10 || *(_QWORD *)&argv->value.VNumber )
      {
        v6 = this->pTraits.pObject->pVM->PublicNamespace.pObject;
        prop_name.Kind = 0;
        prop_name.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v6->vfptr;
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        prop_name.Name.Flags = 0;
        prop_name.Name.Bonus.pWeakProxy = 0i64;
        if ( (argv->Flags & 0x1F) - 12 <= 3
          && (v7 = argv->value.VNumber, v7 != 0.0)
          && (v8 = *(_QWORD *)(*(_QWORD *)&v7 + 40i64), *(_DWORD *)(v8 + 120) == 17)
          && ~(*(_BYTE *)(v8 + 112) >> 5) & 1 )
        {
          Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v7 + 56i64));
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
            *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v7 + 64i64));
          prop_name.Kind &= 0xFFFFFFF9;
        }
        else
        {
          Scaleform::GFx::AS3::Value::AssignUnsafe(&prop_name.Name, argv);
          if ( (prop_name.Name.Flags & 0x1F) == 10 )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &resulta);
            if ( resulta.pNode->Size )
            {
              if ( *resulta.pNode->pData == 64 )
              {
                prop_name.Kind |= 8u;
                v9 = Scaleform::GFx::ASString::Substring(&resulta, &v15, 1, resulta.pNode->Size);
                Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v9);
                v10 = v15.pNode;
                v11 = v15.pNode->RefCount == 1;
                --v10->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v10);
              }
            }
            v12 = resulta.pNode;
            v11 = resulta.pNode->RefCount == 1;
            --v12->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          }
        }
        v13 = Scaleform::GFx::AS3::GetVectorInd(&v18, &prop_name, (unsigned int *)&resulta)->Result
           && !LODWORD(resulta.pNode);
        if ( v13 )
        {
          Scaleform::GFx::AS3::Value::SetBool(v4, 1);
          Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
          return;
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
      }
    }
  }
  Scaleform::GFx::AS3::Value::SetBool(v4, 0);
}

// File Line: 3547
// RVA: 0x79AC80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3addNamespace(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS3::VM *v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rdi
  char v9; // ST20_1
  bool v10; // zf
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h]

  v3 = ns;
  v4 = result;
  v5 = this;
  v6 = ns->Flags & 0x1F;
  if ( !v6 || (v6 - 12 <= 3 || v6 == 10) && !*(_QWORD *)&ns->value.VNumber )
  {
LABEL_20:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v5);
    return;
  }
  v7 = this->pTraits.pObject->pVM;
  v11.Flags = 0;
  v11.Bonus.pWeakProxy = 0i64;
  v8 = v7->TraitsNamespace.pObject->ITraits.pObject;
  if ( !v8->pConstructor.pObject )
    v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
  v9 = 1;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, signed __int64, Scaleform::GFx::AS3::Value *, char))v8->pConstructor.pObject->vfptr[4].ForEachChild_GC)(
    v8->pConstructor.pObject,
    &v11,
    1i64,
    v3,
    v9);
  if ( !v7->HandleException )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, _QWORD))v5->vfptr[7].ForEachChild_GC)(
      v5,
      *(_QWORD *)&v11.value.VNumber);
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags >> 9) & 1 )
      {
        v10 = v11.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11.Bonus.pWeakProxy = 0i64;
        v11.value = 0ui64;
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
    goto LABEL_20;
  }
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags >> 9) & 1 )
    {
      v10 = v11.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v11.Bonus.pWeakProxy = 0i64;
      v11.value = 0ui64;
      v11.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
    }
  }
}

// File Line: 3571
// RVA: 0x79AE80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3appendChild(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *child)
{
  char v3; // [rsp+30h] [rbp+8h]

  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *))this->vfptr[7].~RefCountBaseGC<328>)(
    this,
    &v3,
    child);
}

// File Line: 3583
// RVA: 0x79AEF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3attribute(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result, Scaleform::GFx::AS3::Value *arg)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  unsigned int v6; // er9
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+8h]

  v3 = result;
  v4 = this;
  v5 = this->pTraits.pObject->pVM;
  v6 = arg->Flags & 0x1F;
  if ( v6 && (v6 - 12 > 3 && v6 != 10 || *(_QWORD *)&arg->value.VNumber) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, v5, arg);
    mn.Kind |= 8u;
    if ( !v5->HandleException )
    {
      v7 = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(v4, &resulta, &mn);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        v3,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v7->pV);
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *, signed __int64))v4->vfptr[18].ForEachChild_GC)(
        v4,
        &resulta,
        &mn,
        v3->pObject,
        -2i64);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eInvalidArgumentError, v5);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v9 = v11.Message.pNode;
    v10 = v11.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
}

// File Line: 3608
// RVA: 0x79B200
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3attributes(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = result;
  v4 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v4 + 200));
  v5 = v3->pObject;
  v6 = resulta.pV;
  if ( resulta.pV != v3->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v3->pObject = v6;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *))v2->vfptr[14].Finalize_GC)(
    v2,
    v6);
}

// File Line: 3622
// RVA: 0x79B570
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3child(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result, Scaleform::GFx::AS3::Value *propertyName)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  unsigned int v6; // er9
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+8h]

  v3 = result;
  v4 = this;
  v5 = this->pTraits.pObject->pVM;
  v6 = propertyName->Flags & 0x1F;
  if ( v6 && (v6 - 12 > 3 && v6 != 10 || *(_QWORD *)&propertyName->value.VNumber) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM, propertyName);
    if ( !v5->HandleException )
    {
      v7 = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(v4, &resulta, &mn);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        v3,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v7->pV);
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *, signed __int64))v4->vfptr[18].ForEachChild_GC)(
        v4,
        &resulta,
        &mn,
        v3->pObject,
        -2i64);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eInvalidArgumentError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v9 = v11.Message.pNode;
    v10 = v11.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
}

// File Line: 3649
// RVA: 0x79B900
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3childIndex(Scaleform::GFx::AS3::Instances::fl::XML *this, int *result)
{
  int *v2; // rbx
  char v3; // [rsp+30h] [rbp+8h]
  int v4; // [rsp+38h] [rbp+10h]

  *result = -1;
  v2 = result;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, int *))this->vfptr[12].Finalize_GC)(
                   this,
                   &v3,
                   &v4) )
    *v2 = v4;
}

// File Line: 3664
// RVA: 0x79B9A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3children(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = result;
  v4 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v4 + 200));
  v5 = v3->pObject;
  v6 = resulta.pV;
  if ( resulta.pV != v3->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v3->pObject = v6;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, _QWORD, _QWORD))v2->vfptr[12].ForEachChild_GC)(
    v2,
    v6,
    0i64,
    0i64);
}

// File Line: 3677
// RVA: 0x79BC00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r14
  Scaleform::GFx::ASString *target_prop; // rdi
  Scaleform::GFx::AS3::VM *v5; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *target_ns; // rbx
  __int64 v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rbx
  unsigned int v12; // eax
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v14; // [rsp+68h] [rbp+10h]

  v2 = result;
  v3 = this;
  target_prop = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateNullString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
                  &resulta);
  v5 = v3->pTraits.pObject->pVM;
  target_ns = v5->PublicNamespace.pObject;
  v7 = ((__int64 (*)(void))v5->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v7 + 200),
    &v14,
    *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v7 + 200),
    (Scaleform::GFx::AS3::Instances::fl::Object *)&v3->vfptr,
    target_prop,
    target_ns);
  v8 = resulta.pNode;
  v9 = resulta.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = v2->pObject;
  v11 = v14.pV;
  if ( v14.pV != v2->pObject )
  {
    if ( v10 )
    {
      if ( (unsigned __int8)v10 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v10 - 1);
      }
      else
      {
        v12 = v10->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          v10->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
        }
      }
    }
    v2->pObject = v11;
  }
  v3->vfptr[12].ForEachChild_GC(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)v11,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))3);
}

// File Line: 3690
// RVA: 0x79C070
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3contains(Scaleform::GFx::AS3::Instances::fl::XML *this, bool *result, Scaleform::GFx::AS3::Value *value)
{
  bool *v3; // rbx
  long double v4; // rdx
  __int64 v5; // rax

  *result = 0;
  v3 = result;
  if ( (value->Flags & 0x1F) - 12 <= 3 )
  {
    v4 = value->value.VNumber;
    if ( v4 != 0.0 )
    {
      v5 = *(_QWORD *)(*(_QWORD *)&v4 + 40i64);
      if ( *(_DWORD *)(v5 + 120) == 18 )
      {
        if ( ~(*(_BYTE *)(v5 + 112) >> 5) & 1 )
          *v3 = ((unsigned int (*)(void))this->vfptr[9].ForEachChild_GC)() == 1;
      }
    }
  }
}

// File Line: 3707
// RVA: 0x79C180
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3copy(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML **v3; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx
  unsigned int v6; // eax
  char v7; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = (Scaleform::GFx::AS3::Instances::fl::XML **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, _QWORD))this->vfptr[11].Finalize_GC)(
                                                     this,
                                                     &v7,
                                                     0i64);
  v4 = v2->pObject;
  v5 = *v3;
  if ( *v3 != v2->pObject )
  {
    if ( v4 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v4 - 1);
        v2->pObject = v5;
        return;
      }
      v6 = v4->RefCount;
      if ( v6 & 0x3FFFFF )
      {
        v4->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v2->pObject = v5;
  }
}

// File Line: 3718
// RVA: 0x79C6C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3descendants(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // r13
  __int64 v8; // rax
  long double *v9; // rax
  unsigned int v10; // esi
  Scaleform::GFx::AS3::WeakProxy *v11; // r12
  long double v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // rdx
  char v14; // di
  Scaleform::GFx::AS3::WeakProxy *v15; // r15
  unsigned int v16; // er14
  int v17; // ecx
  long double v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v19; // r8
  long double v20; // r13
  __int64 v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v27; // rcx
  unsigned int v28; // eax
  Scaleform::GFx::AS3::Value v29; // [rsp+8h] [rbp-71h]
  int v30; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v31; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::Value v32; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-21h]
  Scaleform::GFx::ASString v34; // [rsp+78h] [rbp-1h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::ASString v36; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::ASString v37; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::Value::V2U v38; // [rsp+98h] [rbp+1Fh]
  __int64 v39; // [rsp+A0h] [rbp+27h]
  __int64 v40; // [rsp+E0h] [rbp+67h]

  v39 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this;
  v8 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v8 + 200));
  Scaleform::GFx::AS3::Value::Pick(v6, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  if ( v5 )
  {
    v16 = v4->Flags;
    other.Flags = v16;
    v15 = v4->Bonus.pWeakProxy;
    other.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    other.value = v4->value;
    v17 = v16 & 0x1F;
    if ( v17 > 9 )
    {
      if ( (v16 >> 9) & 1 )
      {
        ++v15->RefCount;
      }
      else
      {
        if ( v17 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
          goto LABEL_18;
        }
        if ( v17 > 10 )
        {
          if ( v17 <= 15 )
          {
            v18 = v4->value.VNumber;
          }
          else
          {
            if ( v17 > 17 )
              goto LABEL_18;
            v18 = *(double *)&v4->value.VS._2.VObj;
          }
          if ( v18 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v18 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v18 + 32i64) + 1) & 0x8FBFFFFF;
          goto LABEL_18;
        }
      }
    }
LABEL_18:
    v13 = &other;
    v14 = 4;
    v11 = v29.Bonus.pWeakProxy;
    v10 = v29.Flags;
    goto LABEL_19;
  }
  v9 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->pTraits.pObject->pVM->StringManagerRef->Builtins,
                        &v37,
                        pattern);
  v10 = 10;
  v29.Flags = 10;
  v11 = 0i64;
  v29.Bonus.pWeakProxy = 0i64;
  v12 = *v9;
  v29.value.VNumber = v12;
  if ( *(_QWORD *)&v12 == *(_QWORD *)(*(_QWORD *)&v12 + 8i64) + 104i64 )
  {
    v29.value.VNumber = 0.0;
    v29.value.VS._2 = v38;
    v10 = 12;
    v29.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
  }
  v13 = &v29;
  v14 = 3;
  v15 = other.Bonus.pWeakProxy;
  v16 = other.Flags;
LABEL_19:
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->pTraits.pObject->pVM->PublicNamespace.pObject;
  v30 = 0;
  v31.pObject = v19;
  if ( v19 )
    v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
  v32.Flags = 0;
  v32.Bonus.pWeakProxy = 0i64;
  if ( (v13->Flags & 0x1F) - 12 <= 3
    && (v20 = v13->value.VNumber, v20 != 0.0)
    && (v21 = *(_QWORD *)(*(_QWORD *)&v20 + 40i64), *(_DWORD *)(v21 + 120) == 17)
    && ~(*(_BYTE *)(v21 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v32, (Scaleform::GFx::ASString *)(*(_QWORD *)&v20 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v31,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v20 + 64i64));
    v30 &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v32, v13);
    if ( (v32.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v32, &v34);
      if ( v34.pNode->Size )
      {
        if ( *v34.pNode->pData == 64 )
        {
          v30 |= 8u;
          v22 = Scaleform::GFx::ASString::Substring(&v34, &v36, 1, v34.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v32, v22);
          v23 = v36.pNode;
          v24 = v36.pNode->RefCount == 1;
          --v23->RefCount;
          if ( v24 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        }
      }
      v25 = v34.pNode;
      v24 = v34.pNode->RefCount == 1;
      --v25->RefCount;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    v16 = other.Flags;
    v15 = other.Bonus.pWeakProxy;
    v10 = v29.Flags;
    v11 = v29.Bonus.pWeakProxy;
  }
  if ( v14 & 4 )
  {
    v14 &= 0xFBu;
    if ( (char)(v16 & 0x1F) > 9 )
    {
      if ( (v16 >> 9) & 1 )
      {
        v24 = v15->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v16 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  if ( v14 & 2 )
  {
    v14 &= 0xFDu;
    if ( (char)(v10 & 0x1F) > 9 )
    {
      if ( (v10 >> 9) & 1 )
      {
        v24 = v11->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        v29.Bonus.pWeakProxy = 0i64;
        v29.value = 0ui64;
        v29.Flags = v10 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
      }
    }
  }
  if ( v14 & 1 )
  {
    v26 = v37.pNode;
    v24 = v37.pNode->RefCount == 1;
    --v26->RefCount;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS3::Instances::fl::XMLList *, int *))(*(_QWORD *)v40 + 56i64))(
    v40,
    resulta.pV,
    &v30);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v24 = v32.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v24 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v27 = v31.pObject;
  if ( v31.pObject )
  {
    if ( (_QWORD)v31.pObject & 1 )
    {
      --v31.pObject;
    }
    else
    {
      v28 = v31.pObject->RefCount;
      if ( v28 & 0x3FFFFF )
      {
        v31.pObject->RefCount = v28 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v27->vfptr);
      }
    }
  }
}

// File Line: 3733
// RVA: 0x79CEA0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3elements(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // r13
  __int64 v8; // rax
  long double *v9; // rax
  unsigned int v10; // esi
  Scaleform::GFx::AS3::WeakProxy *v11; // r12
  long double v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // rdx
  char v14; // di
  Scaleform::GFx::AS3::WeakProxy *v15; // r15
  unsigned int v16; // er14
  int v17; // ecx
  long double v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v19; // r8
  long double v20; // r13
  __int64 v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v27; // rcx
  unsigned int v28; // eax
  Scaleform::GFx::AS3::Value v29; // [rsp+8h] [rbp-71h]
  int v30; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v31; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::Value v32; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-21h]
  Scaleform::GFx::ASString v34; // [rsp+78h] [rbp-1h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::ASString v36; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::ASString v37; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::Value::V2U v38; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::Value p; // [rsp+A0h] [rbp+27h]
  __int64 v40; // [rsp+E0h] [rbp+67h]

  *(_QWORD *)&p.Flags = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this;
  v8 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v8 + 200));
  Scaleform::GFx::AS3::Value::Pick(v6, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  if ( v5 )
  {
    v16 = v4->Flags;
    other.Flags = v16;
    v15 = v4->Bonus.pWeakProxy;
    other.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    other.value = v4->value;
    v17 = v16 & 0x1F;
    if ( v17 > 9 )
    {
      if ( (v16 >> 9) & 1 )
      {
        ++v15->RefCount;
      }
      else
      {
        if ( v17 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
          goto LABEL_18;
        }
        if ( v17 > 10 )
        {
          if ( v17 <= 15 )
          {
            v18 = v4->value.VNumber;
          }
          else
          {
            if ( v17 > 17 )
              goto LABEL_18;
            v18 = *(double *)&v4->value.VS._2.VObj;
          }
          if ( v18 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v18 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v18 + 32i64) + 1) & 0x8FBFFFFF;
          goto LABEL_18;
        }
      }
    }
LABEL_18:
    v13 = &other;
    v14 = 4;
    v11 = v29.Bonus.pWeakProxy;
    v10 = v29.Flags;
    goto LABEL_19;
  }
  v9 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->pTraits.pObject->pVM->StringManagerRef->Builtins,
                        &v37,
                        pattern);
  v10 = 10;
  v29.Flags = 10;
  v11 = 0i64;
  v29.Bonus.pWeakProxy = 0i64;
  v12 = *v9;
  v29.value.VNumber = v12;
  if ( *(_QWORD *)&v12 == *(_QWORD *)(*(_QWORD *)&v12 + 8i64) + 104i64 )
  {
    v29.value.VNumber = 0.0;
    v29.value.VS._2 = v38;
    v10 = 12;
    v29.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
  }
  v13 = &v29;
  v14 = 3;
  v15 = other.Bonus.pWeakProxy;
  v16 = other.Flags;
LABEL_19:
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->pTraits.pObject->pVM->PublicNamespace.pObject;
  v30 = 0;
  v31.pObject = v19;
  if ( v19 )
    v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
  v32.Flags = 0;
  v32.Bonus.pWeakProxy = 0i64;
  if ( (v13->Flags & 0x1F) - 12 <= 3
    && (v20 = v13->value.VNumber, v20 != 0.0)
    && (v21 = *(_QWORD *)(*(_QWORD *)&v20 + 40i64), *(_DWORD *)(v21 + 120) == 17)
    && ~(*(_BYTE *)(v21 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v32, (Scaleform::GFx::ASString *)(*(_QWORD *)&v20 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v31,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v20 + 64i64));
    v30 &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v32, v13);
    if ( (v32.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v32, &v34);
      if ( v34.pNode->Size )
      {
        if ( *v34.pNode->pData == 64 )
        {
          v30 |= 8u;
          v22 = Scaleform::GFx::ASString::Substring(&v34, &v36, 1, v34.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v32, v22);
          v23 = v36.pNode;
          v24 = v36.pNode->RefCount == 1;
          --v23->RefCount;
          if ( v24 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        }
      }
      v25 = v34.pNode;
      v24 = v34.pNode->RefCount == 1;
      --v25->RefCount;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    v16 = other.Flags;
    v15 = other.Bonus.pWeakProxy;
    v10 = v29.Flags;
    v11 = v29.Bonus.pWeakProxy;
  }
  if ( v14 & 4 )
  {
    v14 &= 0xFBu;
    if ( (char)(v16 & 0x1F) > 9 )
    {
      if ( (v16 >> 9) & 1 )
      {
        v24 = v15->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v16 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  if ( v14 & 2 )
  {
    v14 &= 0xFDu;
    if ( (char)(v10 & 0x1F) > 9 )
    {
      if ( (v10 >> 9) & 1 )
      {
        v24 = v11->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        v29.Bonus.pWeakProxy = 0i64;
        v29.value = 0ui64;
        v29.Flags = v10 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
      }
    }
  }
  if ( v14 & 1 )
  {
    v26 = v37.pNode;
    v24 = v37.pNode->RefCount == 1;
    --v26->RefCount;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS3::Instances::fl::XMLList *, int *))(*(_QWORD *)v40 + 296i64))(
    v40,
    resulta.pV,
    &v30);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v24 = v32.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v24 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v27 = v31.pObject;
  if ( v31.pObject )
  {
    if ( (_QWORD)v31.pObject & 1 )
    {
      --v31.pObject;
    }
    else
    {
      v28 = v31.pObject->RefCount;
      if ( v28 & 0x3FFFFF )
      {
        v31.pObject->RefCount = v28 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v27->vfptr);
      }
    }
  }
}

// File Line: 3748
// RVA: 0x79EFD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasComplexContent(Scaleform::GFx::AS3::Instances::fl::XML *this, bool *result)
{
  *result = ((unsigned __int8 (*)(void))this->vfptr[9].~RefCountBaseGC<328>)() == 0;
}

// File Line: 3759
// RVA: 0x79F2A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasSimpleContent(Scaleform::GFx::AS3::Instances::fl::XML *this, bool *result)
{
  *result = ((__int64 (*)(void))this->vfptr[9].~RefCountBaseGC<328>)();
}

// File Line: 3770
// RVA: 0x79F370
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3inScopeNamespaces(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rdi
  unsigned int v6; // eax
  __int64 v7; // rax
  _QWORD *v8; // rdx
  unsigned __int64 v9; // rax
  long double v10; // r13
  unsigned int v11; // er15
  Scaleform::GFx::AS3::WeakProxy *v12; // rdx
  int v13; // ecx
  __int64 v14; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> >::TableType *v15; // rbx
  signed __int64 v16; // r12
  signed __int64 v17; // rsi
  signed __int64 v18; // r14
  unsigned __int64 v19; // rcx
  int v20; // ecx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  long double v23; // rcx
  int v24; // eax
  signed __int64 v25; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // r9
  long double v27; // r8
  Scaleform::GFx::AS3::WeakProxy *v28; // rdx
  int v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // eax
  long double v32; // rdx
  int v33; // ecx
  Scaleform::GFx::ASStringNode *v34; // rcx
  long double v35; // rcx
  int v36; // eax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> >::TableType *v37; // rdx
  __int64 v38; // rsi
  unsigned __int64 v39; // r14
  Scaleform::GFx::AS3::Value *v40; // rdi
  Scaleform::GFx::AS3::WeakProxy *v41; // rdx
  Scaleform::GFx::AS3::Value v; // [rsp+20h] [rbp-79h]
  Scaleform::GFx::AS3::Value source; // [rsp+40h] [rbp-59h]
  _QWORD *v44; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *v45; // [rsp+68h] [rbp-31h]
  unsigned __int64 v46; // [rsp+70h] [rbp-29h]
  Scaleform::GFx::AS3::WeakProxy *v47; // [rsp+78h] [rbp-21h]
  long double v48; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::Value::V2U v49; // [rsp+88h] [rbp-11h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+90h] [rbp-9h]
  __int64 v51; // [rsp+A0h] [rbp+7h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+100h] [rbp+67h]
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> > pmemAddr; // [rsp+108h] [rbp+6Fh]
  unsigned __int64 v54; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::AS3::Instances::fl::XML *v55; // [rsp+118h] [rbp+7Fh]

  v51 = -2i64;
  v2 = result;
  v3 = this;
  v55 = this;
  v45 = &this->pTraits;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  v4 = v2->pObject;
  v5 = resulta.pV;
  if ( resulta.pV != v2->pObject )
  {
    if ( v4 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v4 - 1);
      }
      else
      {
        v6 = v4->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v4->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
        }
      }
    }
    v2->pObject = v5;
  }
  pmemAddr.pTable = 0i64;
  do
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[6].Finalize_GC)(v3);
    v8 = (_QWORD *)v7;
    v44 = (_QWORD *)v7;
    if ( v7 )
    {
      v46 = *(_QWORD *)(v7 + 8);
      v9 = 0i64;
      v54 = 0i64;
      if ( v46 )
      {
        while ( 1 )
        {
          v10 = *(double *)(*v8 + 8 * v9);
          v11 = *(_DWORD *)(*(_QWORD *)&v10 + 72i64);
          v.Flags = v11;
          v12 = *(Scaleform::GFx::AS3::WeakProxy **)(*(_QWORD *)&v10 + 80i64);
          v47 = v12;
          v.Bonus.pWeakProxy = v12;
          v48 = *(double *)(*(_QWORD *)&v10 + 88i64);
          v.value.VNumber = v48;
          v49.VObj = *(Scaleform::GFx::AS3::Object **)(*(_QWORD *)&v10 + 96i64);
          v.value.VS._2 = v49;
          v13 = v11 & 0x1F;
          if ( v13 > 9 )
          {
            if ( (v11 >> 9) & 1 )
            {
              ++v12->RefCount;
            }
            else
            {
              if ( v13 == 10 )
              {
                ++*(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v10 + 88i64) + 24i64);
                goto LABEL_23;
              }
              if ( v13 > 10 )
              {
                if ( v13 <= 15 )
                {
                  v14 = *(_QWORD *)(*(_QWORD *)&v10 + 88i64);
                }
                else
                {
                  if ( v13 > 17 )
                    goto LABEL_23;
                  v14 = *(_QWORD *)(*(_QWORD *)&v10 + 96i64);
                }
                if ( v14 )
                  *(_DWORD *)(v14 + 32) = (*(_DWORD *)(v14 + 32) + 1) & 0x8FBFFFFF;
              }
            }
          }
LABEL_23:
          v15 = pmemAddr.pTable;
          if ( !pmemAddr.pTable )
            goto LABEL_32;
          v16 = v15->SizeMask & Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                                  (Scaleform::GFx::AS3::Value::HashFunctor *)&resulta,
                                  &v);
          v17 = v16;
          v18 = (signed __int64)&v15[3 * v16 + 1];
          if ( *(_QWORD *)v18 == -2i64 || *(_QWORD *)(v18 + 8) != v16 )
            goto LABEL_32;
          while ( *(_QWORD *)(v18 + 8) != v16
               || !Scaleform::GFx::AS3::StrictEqual((Scaleform::GFx::AS3::Value *)(v18 + 16), &v) )
          {
            v17 = *(_QWORD *)v18;
            if ( *(_QWORD *)v18 == -1i64 )
              goto LABEL_32;
            v18 = (signed __int64)&v15[3 * v17 + 1];
          }
          if ( v17 >= 0 && &v15[3 * v17 + 2] )
          {
            v28 = v47;
            v27 = v48;
            v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v49.VObj->vfptr;
          }
          else
          {
LABEL_32:
            source.Flags = 11;
            source.Bonus.pWeakProxy = 0i64;
            source.value.VNumber = v10;
            *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
            v19 = v5->SA.Length;
            if ( v19 == v5->SA.ValueA.Data.Size )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->SA.ValueA.Data.Data,
                v5->SA.ValueA.Data.pHeap,
                v5->SA.ValueA.Data.Size + 1);
              Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
                &v5->SA.ValueA.Data.Data[v5->SA.ValueA.Data.Size - 1],
                &source);
            }
            else
            {
              v5->SA.ValueHHighInd = v19;
              key.pFirst = &v5->SA.ValueHHighInd;
              key.pSecond = &source;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
                v5->SA.ValueH.mHash.pHeap,
                &key);
            }
            ++v5->SA.Length;
            v20 = source.Flags & 0x1F;
            if ( v20 > 9 )
            {
              if ( (source.Flags >> 9) & 1 )
              {
                v21 = source.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v21 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                source.Bonus.pWeakProxy = 0i64;
                source.value = 0ui64;
                source.Flags &= 0xFFFFFDE0;
              }
              else
              {
                switch ( v20 )
                {
                  case 10:
                    v22 = source.value.VS._1.VStr;
                    v21 = *(_DWORD *)(*(_QWORD *)&source.value.VNumber + 24i64) == 1;
                    --v22->RefCount;
                    if ( v21 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
                    break;
                  case 11:
                  case 12:
                  case 13:
                  case 14:
                  case 15:
                    v23 = source.value.VNumber;
                    if ( !source.value.VS._1.VBool )
                      goto LABEL_47;
                    --*(_QWORD *)&source.value.VNumber;
                    break;
                  case 16:
                  case 17:
                    v23 = *(double *)&source.value.VS._2.VObj;
                    if ( (_QWORD)source.value.VS._2.VObj & 1 )
                    {
                      --source.value.VS._2.VObj;
                    }
                    else
                    {
LABEL_47:
                      if ( v23 != 0.0 )
                      {
                        v24 = *(_DWORD *)(*(_QWORD *)&v23 + 32i64);
                        if ( v24 & 0x3FFFFF )
                        {
                          *(_DWORD *)(*(_QWORD *)&v23 + 32i64) = v24 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v23);
                        }
                      }
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            v25 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                    (Scaleform::GFx::AS3::Value::HashFunctor *)&resulta,
                    &v);
            Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::add<Scaleform::GFx::AS3::Value>(
              &pmemAddr,
              &pmemAddr,
              &v,
              v25);
            v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v.value.VS._2.VObj->vfptr;
            v27 = v.value.VNumber;
            v28 = v.Bonus.pWeakProxy;
            v11 = v.Flags;
          }
          v29 = v11 & 0x1F;
          if ( v29 > 9 )
          {
            if ( (v11 >> 9) & 1 )
            {
              v21 = v28->RefCount-- == 1;
              if ( v21 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                  Scaleform::Memory::pGlobalHeap,
                  v28,
                  *(_QWORD *)&v27,
                  v26);
              v.Bonus.pWeakProxy = 0i64;
              v.value = 0ui64;
              v.Flags = v11 & 0xFFFFFDE0;
            }
            else
            {
              switch ( v29 )
              {
                case 10:
                  v21 = (*(_DWORD *)(*(_QWORD *)&v27 + 24i64))-- == 1;
                  if ( v21 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v27);
                  break;
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                  if ( v.value.VS._1.VBool )
                  {
                    *(_QWORD *)&v.value.VNumber = *(_QWORD *)&v27 - 1i64;
                  }
                  else if ( v27 != 0.0 )
                  {
                    v30 = *(_DWORD *)(*(_QWORD *)&v27 + 32i64);
                    if ( v30 & 0x3FFFFF )
                    {
                      *(_DWORD *)(*(_QWORD *)&v27 + 32i64) = v30 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v27);
                    }
                  }
                  break;
                case 16:
                case 17:
                  if ( (_QWORD)v.value.VS._2.VObj & 1 )
                  {
                    v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v26[-1].RefCount + 7);
                  }
                  else if ( v26 )
                  {
                    v31 = v26->RefCount;
                    if ( v31 & 0x3FFFFF )
                    {
                      v26->RefCount = v31 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
                    }
                  }
                  break;
                default:
                  break;
              }
            }
          }
          v9 = v54 + 1;
          v54 = v9;
          v8 = v44;
          if ( v9 >= v46 )
          {
            v3 = v55;
            break;
          }
        }
      }
    }
    v3 = v3->Parent.pObject;
    v55 = v3;
  }
  while ( v3 );
  if ( !v5->SA.Length )
  {
    v32 = *(double *)&v45->pObject->pVM->PublicNamespace.pObject;
    v.Flags = 11;
    v.Bonus.pWeakProxy = 0i64;
    v.value.VNumber = v32;
    if ( v32 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v32 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v32 + 32i64) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v5->SA, &v);
    v33 = v.Flags & 0x1F;
    if ( v33 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v21 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v33 )
        {
          case 10:
            v34 = v.value.VS._1.VStr;
            v21 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
            --v34->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v34);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v35 = v.value.VNumber;
            if ( !v.value.VS._1.VBool )
              goto LABEL_88;
            --*(_QWORD *)&v.value.VNumber;
            break;
          case 16:
          case 17:
            v35 = *(double *)&v.value.VS._2.VObj;
            if ( (_QWORD)v.value.VS._2.VObj & 1 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
LABEL_88:
              if ( v35 != 0.0 )
              {
                v36 = *(_DWORD *)(*(_QWORD *)&v35 + 32i64);
                if ( v36 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v35 + 32i64) = v36 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v35);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
  }
  v37 = pmemAddr.pTable;
  if ( pmemAddr.pTable )
  {
    v38 = 0i64;
    v39 = pmemAddr.pTable->SizeMask + 1;
    do
    {
      v40 = (Scaleform::GFx::AS3::Value *)&v37[v38];
      if ( v37[v38 + 1].EntryCount != -2i64 )
      {
        if ( (v40[1].Flags & 0x1F) > 9 )
        {
          if ( (v40[1].Flags >> 9) & 1 )
          {
            v41 = v40[1].Bonus.pWeakProxy;
            v21 = v41->RefCount-- == 1;
            if ( v21 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v40[1].Bonus.pWeakProxy = 0i64;
            v40[1].value.VNumber = 0.0;
            v40[1].value.VS._2.VObj = 0i64;
            v40[1].Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(v40 + 1);
          }
        }
        v40->value.VNumber = -3.595386269724631e308/*NaN*/;
        v37 = pmemAddr.pTable;
      }
      v38 += 3i64;
      --v39;
    }
    while ( v39 );
    if ( v37 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 3811
// RVA: 0x79FB30
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildAfter(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *child1, Scaleform::GFx::AS3::Value *child2)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rdi
  char v6; // [rsp+30h] [rbp+8h]

  v4 = result;
  v5 = this;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))this->vfptr[13].~RefCountBaseGC<328>)(
                   this,
                   &v6,
                   child1,
                   child2) )
    Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::AS3::Object *)&v5->vfptr);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(v4);
}

// File Line: 3825
// RVA: 0x79FC00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildBefore(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *child1, Scaleform::GFx::AS3::Value *child2)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rdi
  char v6; // [rsp+30h] [rbp+8h]

  v4 = result;
  v5 = this;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))this->vfptr[13].Finalize_GC)(
                   this,
                   &v6,
                   child1,
                   child2) )
    Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::AS3::Object *)&v5->vfptr);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(v4);
}

// File Line: 3839
// RVA: 0x851620
void __fastcall Scaleform::GFx::AS3::Class::lengthGet(Scaleform::GFx::AS3::Class *this, int *result)
{
  *result = 1;
}

// File Line: 3845
// RVA: 0x86BAA0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v2 = this->Url.pNode;
  v3 = result;
  ++v2->RefCount;
  v4 = result->pNode;
  v5 = result->pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    v3->pNode = v2;
  }
  else
  {
    result->pNode = v2;
  }
}

// File Line: 3856
// RVA: 0x7A0A50
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3name(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v2; // rbx
  __int64 v3; // rax
  Scaleform::GFx::AS3::Instances::fl::QName **v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::QName *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))this->vfptr[15].ForEachChild_GC)(
         this,
         &v9);
  v4 = (Scaleform::GFx::AS3::Instances::fl::QName **)v3;
  if ( (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *)v3 != v2 )
  {
    if ( *(_QWORD *)v3 )
      *(_DWORD *)(*(_QWORD *)v3 + 32i64) = (*(_DWORD *)(*(_QWORD *)v3 + 32i64) + 1) & 0x8FBFFFFF;
    v5 = v2->pObject;
    if ( v2->pObject )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::QName *)((char *)v5 - 1);
      }
      else
      {
        v6 = v5->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v5->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v2->pObject = *v4;
  }
  v7 = v9;
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v9 - 1);
    }
    else
    {
      v8 = v9->RefCount;
      if ( v8 & 0x3FFFFF )
      {
        v9->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
}

// File Line: 3867
// RVA: 0x7A1140
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h]
  __int64 v12; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+50h] [rbp+18h]

  v12 = -2i64;
  v4 = argv;
  v5 = result;
  v6 = this;
  if ( argc )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
      &resulta);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v4, &v13, &resulta)->Result )
    {
      v8 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, _QWORD))v6->vfptr[15].Finalize_GC)(
                                                              v6,
                                                              &resulta,
                                                              0i64);
      if ( v8 )
        Scaleform::GFx::AS3::Value::Assign(v5, v8);
      else
        Scaleform::GFx::AS3::Value::SetUndefined(v5);
    }
    v9 = resulta.pNode;
    v10 = resulta.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  else
  {
    v7 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (*)(void))this->vfptr[11].~RefCountBaseGC<328>)();
    Scaleform::GFx::AS3::Value::Assign(v5, v7);
  }
}

// File Line: 3896
// RVA: 0x7A0B40
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespaceDeclarations(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rbx
  unsigned int v7; // eax
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rcx
  __int64 v10; // rax
  _QWORD *v11; // rbx
  unsigned __int64 v12; // r13
  unsigned __int64 v13; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v14; // r15
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v15; // rdi
  int v16; // ecx
  __int64 v17; // rsi
  __int64 v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v19; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v20; // rdx
  int v21; // eax
  Scaleform::MemoryHeap *v22; // rax
  __int64 v23; // rax
  _QWORD *v24; // r14
  unsigned __int64 v25; // rsi
  __int64 v26; // rdi
  int v27; // ecx
  __int64 v28; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v29; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v30; // rdx
  int v31; // eax
  unsigned __int64 v32; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v33; // rcx
  int v34; // ecx
  bool v35; // zf
  Scaleform::GFx::ASStringNode *v36; // rcx
  long double v37; // rcx
  int v38; // eax
  unsigned __int64 v39; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **i; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v41; // rcx
  unsigned int v42; // eax
  unsigned __int64 v43; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **j; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v45; // rcx
  unsigned int v46; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v47; // [rsp+20h] [rbp-69h]
  void *pheapAddr; // [rsp+38h] [rbp-51h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v49; // [rsp+40h] [rbp-49h]
  void *v50; // [rsp+58h] [rbp-31h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS3::VM *v52; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v53; // [rsp+88h] [rbp-1h]
  __int64 v54; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v55; // [rsp+98h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::XML *v56; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::AS3::Instances::fl::XML *v57; // [rsp+F8h] [rbp+6Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+100h] [rbp+77h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v59; // [rsp+108h] [rbp+7Fh]

  v56 = this;
  v54 = -2i64;
  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  v52 = v4;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v4->TraitsArray.pObject->ITraits.pObject);
  v5 = v2->pObject;
  v6 = resulta.pV;
  if ( resulta.pV != v2->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v2->pObject = v6;
  }
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[8].Finalize_GC)(v3) - 2 > 3 )
  {
    v8 = v4->MHeap;
    v59 = &v47;
    v47.Data = 0i64;
    v47.Size = 0i64;
    v47.Policy.Capacity = 0i64;
    pheapAddr = v8;
    v9 = v3->Parent.pObject;
    v57 = v9;
    if ( v9 )
    {
      do
      {
        v10 = ((__int64 (*)(void))v9->vfptr[6].Finalize_GC)();
        v11 = (_QWORD *)v10;
        if ( v10 )
        {
          v12 = 0i64;
          if ( *(_QWORD *)(v10 + 8) )
          {
            v13 = v47.Size;
            v14 = v47.Data;
            do
            {
              v15 = *(Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> **)(*v11 + 8 * v12);
              v16 = (_QWORD)v15[3].Data & 0x1F;
              if ( v16 && ((unsigned int)(v16 - 12) > 3 && v16 != 10 || v15[3].Policy.Capacity) )
              {
                v17 = 0i64;
                if ( v13 )
                {
                  while ( !Scaleform::GFx::AS3::StrictEqual(
                             (Scaleform::GFx::AS3::Value *)&v14[v17].pObject[1],
                             (Scaleform::GFx::AS3::Value *)&v15[3]) )
                  {
                    if ( ++v17 >= v13 )
                      goto LABEL_20;
                  }
                }
                else
                {
LABEL_20:
                  v18 = 0i64;
                  if ( v13 )
                  {
                    while ( 1 )
                    {
                      v19 = v14[v18].pObject;
                      if ( v19->Text.pNode == (Scaleform::GFx::ASStringNode *)v15[2].Size
                        && !((LOBYTE(v15[1].Policy.Capacity) ^ LOBYTE(v19->pTraits.pObject)) & 0xF) )
                      {
                        break;
                      }
                      if ( ++v18 >= v13 )
                        goto LABEL_24;
                    }
                  }
                  else
                  {
LABEL_24:
                    v59 = v15;
                    if ( v15 )
                      LODWORD(v15[1].Size) = (LODWORD(v15[1].Size) + 1) & 0x8FBFFFFF;
                    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                      &v47,
                      pheapAddr,
                      v47.Size + 1);
                    v20 = &v47.Data[v47.Size - 1];
                    v55 = &v47.Data[v47.Size - 1];
                    v53 = &v47.Data[v47.Size - 1];
                    if ( v20 )
                    {
                      v20->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v15;
                      if ( v15 )
                        LODWORD(v15[1].Size) = (LODWORD(v15[1].Size) + 1) & 0x8FBFFFFF;
                    }
                    if ( v15 )
                    {
                      if ( (unsigned __int8)v15 & 1 )
                      {
                        v59 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v15 - 1);
                      }
                      else
                      {
                        v21 = v15[1].Size;
                        if ( v21 & 0x3FFFFF )
                        {
                          LODWORD(v15[1].Size) = v21 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
                        }
                      }
                    }
                    v13 = v47.Size;
                    v14 = v47.Data;
                  }
                }
              }
              ++v12;
            }
            while ( v12 < v11[1] );
          }
        }
        v9 = v57->Parent.pObject;
        v57 = v9;
      }
      while ( v9 );
      v6 = resulta.pV;
      v3 = v56;
      v4 = v52;
    }
    v22 = v4->MHeap;
    v49.Data = 0i64;
    v49.Size = 0i64;
    v49.Policy.Capacity = 0i64;
    v50 = v22;
    v23 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[6].Finalize_GC)(v3);
    v24 = (_QWORD *)v23;
    if ( v23 )
    {
      v25 = 0i64;
      if ( *(_QWORD *)(v23 + 8) )
      {
        do
        {
          v26 = *(_QWORD *)(*v24 + 8 * v25);
          v27 = *(_DWORD *)(v26 + 72) & 0x1F;
          if ( v27 && ((unsigned int)(v27 - 12) > 3 && v27 != 10 || *(_QWORD *)(v26 + 88)) )
          {
            v28 = 0i64;
            if ( v49.Size )
            {
              while ( 1 )
              {
                v29 = v49.Data[v28].pObject;
                if ( v29->Text.pNode == *(Scaleform::GFx::ASStringNode **)(v26 + 56)
                  && !((*(_BYTE *)(v26 + 40) ^ LOBYTE(v29->pTraits.pObject)) & 0xF) )
                {
                  break;
                }
                if ( ++v28 >= v49.Size )
                  goto LABEL_48;
              }
            }
            else
            {
LABEL_48:
              if ( v26 )
                *(_DWORD *)(v26 + 32) = (*(_DWORD *)(v26 + 32) + 1) & 0x8FBFFFFF;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v49,
                v50,
                v49.Size + 1);
              v30 = &v49.Data[v49.Size - 1];
              resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v49.Data[v49.Size - 1];
              if ( v30 )
              {
                v30->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v26;
                if ( v26 )
                  *(_DWORD *)(v26 + 32) = (*(_DWORD *)(v26 + 32) + 1) & 0x8FBFFFFF;
              }
              if ( v26 )
              {
                if ( !(v26 & 1) )
                {
                  v31 = *(_DWORD *)(v26 + 32);
                  if ( v31 & 0x3FFFFF )
                  {
                    *(_DWORD *)(v26 + 32) = v31 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v26);
                  }
                }
              }
            }
          }
          ++v25;
        }
        while ( v25 < v24[1] );
      }
    }
    v32 = 0i64;
    if ( v49.Size )
    {
      do
      {
        v33 = v49.Data[v32].pObject;
        v.Flags = 11;
        v.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v.value.VNumber = v33;
        if ( v33 )
          v33->RefCount = (v33->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v6->SA, &v);
        v34 = v.Flags & 0x1F;
        if ( v34 > 9 )
        {
          if ( (v.Flags >> 9) & 1 )
          {
            v35 = v.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v35 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v.Bonus.pWeakProxy = 0i64;
            v.value = 0ui64;
            v.Flags &= 0xFFFFFDE0;
          }
          else
          {
            switch ( v34 )
            {
              case 10:
                v36 = v.value.VS._1.VStr;
                v35 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
                --v36->RefCount;
                if ( v35 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v36);
                break;
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
                v37 = v.value.VNumber;
                if ( !v.value.VS._1.VBool )
                  goto LABEL_73;
                --*(_QWORD *)&v.value.VNumber;
                break;
              case 16:
              case 17:
                v37 = *(double *)&v.value.VS._2.VObj;
                if ( (_QWORD)v.value.VS._2.VObj & 1 )
                {
                  --v.value.VS._2.VObj;
                }
                else
                {
LABEL_73:
                  if ( v37 != 0.0 )
                  {
                    v38 = *(_DWORD *)(*(_QWORD *)&v37 + 32i64);
                    if ( v38 & 0x3FFFFF )
                    {
                      *(_DWORD *)(*(_QWORD *)&v37 + 32i64) = v38 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v37);
                    }
                  }
                }
                break;
              default:
                break;
            }
          }
        }
        ++v32;
      }
      while ( v32 < v49.Size );
    }
    v39 = v49.Size;
    for ( i = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v49.Data[v49.Size - 1]; v39; --v39 )
    {
      v41 = *i;
      if ( *i )
      {
        if ( (unsigned __int8)v41 & 1 )
        {
          *i = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v41 - 1);
        }
        else
        {
          v42 = v41->RefCount;
          if ( v42 & 0x3FFFFF )
          {
            v41->RefCount = v42 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
          }
        }
      }
      --i;
    }
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v43 = v47.Size;
    for ( j = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v47.Data[v47.Size - 1]; v43; --v43 )
    {
      v45 = *j;
      if ( *j )
      {
        if ( (unsigned __int8)v45 & 1 )
        {
          *j = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v45 - 1);
        }
        else
        {
          v46 = v45->RefCount;
          if ( v46 & 0x3FFFFF )
          {
            v45->RefCount = v46 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
          }
        }
      }
      --j;
    }
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 3959
// RVA: 0x7A1260
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  const char *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = result;
  v3 = 0i64;
  v4 = (unsigned __int64)((__int64 (*)(void))this->vfptr[8].Finalize_GC)() - 1;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 == 1 )
            v3 = "attribute";
        }
        else
        {
          v3 = "processing-instruction";
        }
      }
      else
      {
        v3 = "comment";
      }
    }
    else
    {
      v3 = "text";
    }
  }
  else
  {
    v3 = "element";
  }
  Scaleform::GFx::ASString::operator=(v2, v3);
}

// File Line: 3993
// RVA: 0x7A1310
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3normalize(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rbx

  v2 = result;
  v3 = this;
  ((void (*)(void))this->vfptr[15].~RefCountBaseGC<328>)();
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v2,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3);
}

// File Line: 4004
// RVA: 0x7A13A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3parent(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rdx

  v2 = result;
  v3 = this->Parent.pObject;
  JUMPOUT(v3, 0i64, Scaleform::GFx::AS3::Value::SetUndefined);
  Scaleform::GFx::AS3::Value::Assign(v2, (Scaleform::GFx::AS3::Object *)&v3->vfptr);
}

// File Line: 4018
// RVA: 0x7A15C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3processingInstructions(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // r14
  __int64 v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+20h] [rbp-28h]
  __int64 v12; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::ASString v13; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::CheckResult v14; // [rsp+60h] [rbp+18h]

  v12 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this;
  v8 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v8 + 200));
  Scaleform::GFx::AS3::Value::Pick(v6, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v13);
  if ( v5 )
    Scaleform::GFx::AS3::Value::Convert2String(v4, &v14, &v13);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, signed __int64, Scaleform::GFx::ASString *))v7->vfptr[12].ForEachChild_GC)(
    v7,
    resulta.pV,
    4i64,
    &v13);
  v9 = v13.pNode;
  v10 = v13.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 4037
// RVA: 0x7A14E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3prependChild(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v5; // rcx
  unsigned int v6; // eax
  char v7; // [rsp+30h] [rbp+8h]

  v3 = result;
  v4 = this;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, _QWORD, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
                   this,
                   &v7,
                   0i64,
                   value) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
  }
  else
  {
    v5.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pObject;
    if ( v3->pObject )
    {
      if ( (_QWORD)v5.pObject & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)&v5.pObject[-1].List.Data.Policy.Capacity + 7);
        v3->pObject = 0i64;
      }
      else
      {
        v6 = v5.pObject->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v5.pObject->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5.pObject->vfptr);
        }
        v3->pObject = 0i64;
      }
    }
  }
}

// File Line: 4051
// RVA: 0x7A1DC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3removeNamespace(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rax

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[16].Finalize_GC)(
                                                        this,
                                                        ns);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
    v4);
}

// File Line: 4062
// RVA: 0x7A22F0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3replace(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *propertyName, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::Traits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v10; // rax
  bool v11; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value v14; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS3::Multiname v15; // [rsp+40h] [rbp+Fh]
  char v16; // [rsp+98h] [rbp+67h]

  v4 = value;
  v5 = result;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this;
  v7 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::Multiname::Multiname(&v15, v7, propertyName);
  if ( !v7->HandleException )
  {
    if ( Scaleform::GFx::AS3::VM::GetValueTraits(v6->pTraits.pObject->pVM, v4)->TraitsType != 5 )
    {
      if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v6->vfptr[17].~RefCountBaseGC<328>)(
                        v6,
                        &v16,
                        &v15,
                        v4) )
        goto LABEL_21;
      goto LABEL_20;
    }
    v14.Flags = 0;
    v14.Bonus.pWeakProxy = 0i64;
    v8 = v6->pTraits.pObject;
    if ( !v8->pConstructor.pObject )
      v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->pTraits.pObject->vfptr);
    v9 = v8->pConstructor.pObject;
    v10 = v9->vfptr;
    LOBYTE(v14.Flags) = 0;
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, signed __int64, Scaleform::GFx::AS3::Value *))v10[4].ForEachChild_GC)(
      v9,
      &v14,
      1i64,
      v4);
    if ( !v6->pTraits.pObject->pVM->HandleException
      && *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v6->vfptr[17].~RefCountBaseGC<328>)(
                     v6,
                     &v16,
                     &v15,
                     &v14) )
    {
      if ( (v14.Flags & 0x1F) > 9 )
      {
        if ( (v14.Flags >> 9) & 1 )
        {
          v11 = v14.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v14.Bonus.pWeakProxy = 0i64;
          v14.value = 0ui64;
          v14.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
        }
      }
LABEL_20:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v5,
        v6);
      goto LABEL_21;
    }
    if ( (v14.Flags & 0x1F) > 9 )
    {
      if ( (v14.Flags >> 9) & 1 )
      {
        v11 = v14.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v14.Bonus.pWeakProxy = 0i64;
        v14.value = 0ui64;
        v14.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
      }
    }
  }
LABEL_21:
  if ( (v15.Name.Flags & 0x1F) > 9 )
  {
    if ( (v15.Name.Flags >> 9) & 1 )
    {
      v11 = v15.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v15.Name.Bonus.pWeakProxy = 0i64;
      v15.Name.value = 0ui64;
      v15.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15.Name);
    }
  }
  v12 = v15.Obj.pObject;
  if ( v15.Obj.pObject )
  {
    if ( (_QWORD)v15.Obj.pObject & 1 )
    {
      --v15.Obj.pObject;
    }
    else
    {
      v13 = v15.Obj.pObject->RefCount;
      if ( v13 & 0x3FFFFF )
      {
        v15.Obj.pObject->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
}

// File Line: 4099
// RVA: 0x7A28B0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setChildren(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rbx

  v3 = result;
  v4 = this;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[17].Finalize_GC)(
    this,
    value);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
}

// File Line: 4111
// RVA: 0x7A2B60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setLocalName(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *name)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rsi
  int v6; // ecx
  long double v7; // rdx
  __int64 v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+8h]

  v3 = name;
  v4 = this;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result)
     - 2 > 1 )
  {
    v5 = v4->pTraits.pObject->pVM;
    v6 = v3->Flags & 0x1F;
    if ( (unsigned int)(v6 - 12) <= 3
      && (v7 = v3->value.VNumber, v7 != 0.0)
      && (v8 = *(_QWORD *)(*(_QWORD *)&v7 + 40i64), *(_DWORD *)(v8 + 120) == 17)
      && ~(*(_BYTE *)(v8 + 112) >> 5) & 1 )
    {
      v9 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v7 + 56i64);
      ++v9->RefCount;
      v10 = v4->Text.pNode;
      v11 = v10->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v4->Text.pNode = v9;
    }
    else if ( v6 )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v3, &resulta, &v4->Text);
    }
    if ( !Scaleform::GFx::AS3::IsValidName(&resulta, &v4->Text)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v14, eXMLInvalidName, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v13 = v14.Message.pNode;
      v11 = v14.Message.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
}

// File Line: 4135
// RVA: 0x7A2EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setName(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *name)
{
  Scaleform::GFx::AS3::Value *v3; // r14
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rbx
  int v5; // ebp
  Scaleform::GFx::AS3::VM *v6; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  int v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // rsi
  const char *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rsi
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+88h] [rbp+20h]

  v3 = name;
  v4 = this;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result);
  if ( (unsigned int)(v5 - 2) > 1 )
  {
    v6 = v4->pTraits.pObject->pVM;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
      &resulta);
    v7 = 0i64;
    v8 = v3->Flags & 0x1F;
    if ( (unsigned int)(v8 - 12) <= 3
      && (v9 = v3->value.VS._1.VStr) != 0i64
      && (v10 = v9[1].pData, *((_DWORD *)v10 + 30) == 17)
      && ~((const unsigned __int8)v10[112] >> 5) & 1 )
    {
      if ( *(_QWORD *)&v9[1].RefCount )
        v4->vfptr[10].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      v11 = v9[1].pLower;
      ++v11->RefCount;
      v12 = resulta.pNode;
      v13 = resulta.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      resulta.pNode = v11;
      v7 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v9[1].RefCount;
    }
    else if ( v8 && !Scaleform::GFx::AS3::Value::Convert2String(v3, &v22, &resulta)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v21, eXMLInvalidName, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      goto LABEL_14;
    }
    if ( Scaleform::GFx::AS3::IsValidName(&v22, &resulta)->Result )
    {
      v17 = resulta.pNode;
      ++v17->RefCount;
      v18 = v4->Text.pNode;
      v13 = v18->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v4->Text.pNode = v17;
      if ( v7 )
      {
        if ( v5 == 5 )
        {
          v19 = v4->Parent.pObject;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v19->vfptr[7].ForEachChild_GC)(
              v19,
              v7);
        }
        else if ( v5 == 1 )
        {
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v4->vfptr[7].ForEachChild_GC)(
            v4,
            v7);
        }
      }
      else
      {
        v7 = v6->PublicNamespace.pObject;
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v4->vfptr[10].Finalize_GC)(
        v4,
        v7);
      goto LABEL_28;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eXMLInvalidName, v6);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v16, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_14:
    v15 = v21.Message.pNode;
    v13 = v21.Message.pNode->RefCount == 1;
    --v15->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_28:
    v20 = resulta.pNode;
    v13 = resulta.pNode->RefCount == 1;
    --v20->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
}

// File Line: 4184
// RVA: 0x7A3110
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setNamespace(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Value *v3; // rbp
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rdi
  int v5; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v8; // rax
  unsigned int v9; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+68h] [rbp+20h]

  v3 = ns;
  v4 = this;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result);
  if ( (unsigned int)(v5 - 2) <= 2 )
    return;
  v6 = Scaleform::GFx::AS3::VM::MakeNamespace(v4->pTraits.pObject->pVM, &resulta, 0)->pV;
  v6->vfptr[1].ForEachChild_GC(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)1,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))v3);
  if ( v5 == 5 )
  {
    v7 = v4->Parent.pObject;
    if ( !v7 )
      goto LABEL_9;
    v8 = v7->vfptr;
    goto LABEL_7;
  }
  if ( v5 == 1 )
  {
    v8 = v4->vfptr;
    v7 = v4;
LABEL_7:
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v8[7].ForEachChild_GC)(
      v7,
      v6);
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v4->vfptr[10].Finalize_GC)(
    v4,
    v6);
LABEL_9:
  if ( !((unsigned __int8)v6 & 1) )
  {
    v9 = v6->RefCount;
    if ( v9 & 0x3FFFFF )
    {
      v6->RefCount = v9 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
    }
  }
}

// File Line: 4235
// RVA: 0x7A70C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3text(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = result;
  v4 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v4 + 200));
  v5 = v3->pObject;
  v6 = resulta.pV;
  if ( resulta.pV != v3->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v3->pObject = v6;
  }
  v2->vfptr[12].ForEachChild_GC(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)v6,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))2);
}

// File Line: 4248
// RVA: 0x7A8BB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rdi
  char *v5; // r8
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  char *pstr; // [rsp+38h] [rbp-40h]
  unsigned __int64 length; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  Scaleform::StringBuffer::StringBuffer((Scaleform::StringBuffer *)&pstr, v4->MHeap);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char **, _QWORD, _QWORD, _QWORD))v3->vfptr[8].~RefCountBaseGC<328>)(
    v3,
    &pstr,
    0i64,
    0i64,
    0i64);
  v5 = &customWorldMapCaption;
  if ( pstr )
    v5 = pstr;
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
         &resulta,
         v5,
         length)->pNode;
  ++v6->RefCount;
  v7 = v2->pNode;
  v8 = v2->pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v2->pNode = v6;
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pstr);
}

// File Line: 4301
// RVA: 0x79BBC0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rbx

  v2 = result;
  result->pObject = 0i64;
  Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(this, result);
  return v2;
}

// File Line: 4337
// RVA: 0x785100
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::XML(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rax

  v4 = p;
  v5 = n;
  v6 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v7 = v5->pNode;
  v6->Text = (Scaleform::GFx::ASString)v5->pNode;
  ++v7->RefCount;
  v6->Parent.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 4341
// RVA: 0x78FDD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::~XML(Scaleform::GFx::AS3::Instances::fl::XML *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v2 = this->Parent.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v4 = v1->Text.pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)v1->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&v1->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 4369
// RVA: 0x800AF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // r14
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *target_ns; // rdi
  __int64 v7; // rax
  Scaleform::GFx::AS3::VM *v8; // rax
  __int64 v9; // rax
  Scaleform::GFx::ASString *target_prop; // rbx
  __int64 v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  __int64 v14; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v16; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v3 = result;
  v4 = this;
  result->pV = 0i64;
  v5 = &mn->Name;
  if ( (mn->Name.Flags & 0x1F) == 10 )
  {
    if ( (mn->Kind & 3u) <= 1 && mn->Obj.pObject )
    {
      target_ns = mn->Obj.pObject;
      if ( !(target_ns[1].RefCount & 0x1F) )
      {
        v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, $CBB44125B27995AEB5908B7872D4CF4F *, _QWORD))this->vfptr[16].ForEachChild_GC)(
               this,
               &target_ns[1].16,
               0i64);
        if ( v7 )
          target_ns = (Scaleform::GFx::AS3::GASRefCountBase *)v7;
      }
    }
    else
    {
      v8 = this->pTraits.pObject->pVM;
      target_ns = (Scaleform::GFx::AS3::GASRefCountBase *)&v8->DefXMLNamespace.pObject->vfptr;
      if ( target_ns )
      {
        if ( !(target_ns[1].RefCount & 0x1F) )
        {
          v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, $CBB44125B27995AEB5908B7872D4CF4F *, _QWORD))this->vfptr[16].ForEachChild_GC)(
                 this,
                 &target_ns[1].16,
                 0i64);
          if ( v9 )
            target_ns = (Scaleform::GFx::AS3::GASRefCountBase *)v9;
        }
      }
      else
      {
        target_ns = (Scaleform::GFx::AS3::GASRefCountBase *)&v8->PublicNamespace.pObject->vfptr;
      }
    }
    target_prop = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v5, &resulta);
    v11 = ((__int64 (*)(void))v4->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
    Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
      *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v11 + 200),
      &v16,
      *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v11 + 200),
      (Scaleform::GFx::AS3::Instances::fl::Object *)&v4->vfptr,
      target_prop,
      (Scaleform::GFx::AS3::Instances::fl::Namespace *)target_ns);
    v3->pV = v16.pV;
    v12 = resulta.pNode;
    v13 = resulta.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  else
  {
    v14 = ((__int64 (*)(void))this->pTraits.pObject->pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)();
    Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
      &v16,
      *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v14 + 200));
    v3->pV = v16.pV;
  }
  return v3;
}

// File Line: 4421
// RVA: 0x7C93C0
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  signed __int64 result; // rax
  int v5; // ebx

  v2 = other;
  v3 = this;
  if ( this == other )
    return 1i64;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))other->vfptr[8].Finalize_GC)(other);
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[8].Finalize_GC)(v3) != v5 )
    return 2i64;
  result = 0i64;
  if ( v3->Text.pNode != v2->Text.pNode )
    result = 2i64;
  return result;
}

// File Line: 4445
// RVA: 0x7EC810
UFG::RoadNetworkLocation *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetName(UFG::RoadNetworkGuide *this)
{
  return &this->m_CurrentLocation;
}

// File Line: 4455
// RVA: 0x7EC820
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNamespace(Scaleform::GFx::AS3::Instances::fl::XML *this)
{
  return this->pTraits.pObject->pVM->PublicNamespace.pObject;
}

// File Line: 4460
// RVA: 0x7C01C0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::DeepCopy(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
    result,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
    &this->Text,
    parent);
  return v3;
}

// File Line: 4471
// RVA: 0x7F6790
hkBool *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetChildIndex(hkDebugDisplayHandler *this, hkBool *result)
{
  result->m_bool = 0;
  return result;
}

// File Line: 4542
// RVA: 0x7EE7A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetQName(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 4552
// RVA: 0x7D2C70
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *prefix, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r9
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rcx
  __int64 v6; // rax
  const char *v7; // rdx
  char v8; // cl

  v3 = this;
  v4 = this->Parent.pObject;
  if ( v4 != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))v4->vfptr[15].Finalize_GC)(
                                                              v4,
                                                              prefix,
                                                              lp,
                                                              v3);
  v6 = 0i64;
  v7 = prefix->pNode->pData;
  while ( 1 )
  {
    v8 = v7[v6++];
    if ( v8 != aXml_5[v6 - 1] )
      break;
    if ( v6 == 4 )
      return v3->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 4563
// RVA: 0x7D2E00
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByURI(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *uri, Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // r9
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *result; // rax
  const char *v6; // rax
  const char *v7; // r8
  int v8; // ecx
  int v9; // edx

  v3 = this;
  v4 = this->Parent.pObject;
  if ( v4 != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))v4->vfptr[16].ForEachChild_GC)(
                                                              v4,
                                                              uri,
                                                              lp,
                                                              v3);
  v6 = uri->pNode->pData;
  v7 = (const char *)(Scaleform::GFx::AS3::NS_XML - v6);
  do
  {
    v8 = (unsigned __int8)v7[(_QWORD)v6];
    v9 = *(unsigned __int8 *)v6 - v8;
    if ( *(unsigned __int8 *)v6 != v8 )
      break;
    ++v6;
  }
  while ( v8 );
  if ( v9 )
    result = 0i64;
  else
    result = v3->pTraits.pObject->pVM->XMLNamespace.pObject;
  return result;
}

// File Line: 4601
// RVA: 0x826AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::ToXMLString(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::StringBuffer *buf, int ident, Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces, Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::StringBuffer::AppendString(buf, this->Text.pNode->pData, this->Text.pNode->Size);
}

// File Line: 4627
// RVA: 0x7B0950
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(Scaleform::StringBuffer *buf, int ident)
{
  int v2; // ebx
  Scaleform::StringBuffer *v3; // rsi
  signed int v4; // edi

  if ( ident )
  {
    v2 = ident;
    v3 = buf;
    do
    {
      v4 = 10;
      if ( v2 < 10 )
        v4 = v2;
      Scaleform::StringBuffer::AppendString(v3, offsets[v4], v4);
      v2 -= v4;
    }
    while ( v2 );
  }
}

// File Line: 4636
// RVA: 0x7C9D60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(Scaleform::StringBuffer *buf, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::ASStringNode *v2; // rax
  Scaleform::StringBuffer *v3; // rbx
  char *v4; // rdi
  unsigned int v5; // eax
  Scaleform::StringBuffer *v6; // rcx
  __int64 v7; // r8
  const char *v8; // rdx
  char *putf8Buffer; // [rsp+38h] [rbp+10h]

  v2 = v->pNode;
  v3 = buf;
  putf8Buffer = (char *)v->pNode->pData;
  v4 = &putf8Buffer[v2->Size];
  if ( putf8Buffer < v4 )
  {
    while ( 1 )
    {
      v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( v5 == 34 )
        break;
      switch ( v5 )
      {
        case 0x26u:
          v7 = 5i64;
          v8 = "&amp;";
          goto LABEL_14;
        case 0x27u:
          v8 = "&apos;";
LABEL_13:
          v7 = 6i64;
          goto LABEL_14;
        case 0x3Cu:
          v7 = 4i64;
          v8 = "&lt;";
LABEL_14:
          v6 = v3;
          goto LABEL_15;
      }
      v6 = v3;
      if ( v5 == 62 )
      {
        v7 = 4i64;
        v8 = "&gt;";
LABEL_15:
        Scaleform::StringBuffer::AppendString(v6, v8, v7);
        goto LABEL_16;
      }
      Scaleform::StringBuffer::AppendChar(v3, v5);
LABEL_16:
      if ( putf8Buffer >= v4 )
        return;
    }
    v8 = "&quot;";
    goto LABEL_13;
  }
}

// File Line: 4667
// RVA: 0x7C9BE0
Scaleform::GFx::AS3::Instances::fl::XML::EscapeAttributeValue

// File Line: 4710
// RVA: 0x7ECF60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = name;
  v4 = this->pTraits.pObject->pVM;
  if ( ind.Index )
  {
    v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
           &result,
           "0");
    Scaleform::GFx::AS3::Value::Assign(v3, v5);
    v6 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(name, (Scaleform::GFx::ASString *)&v4->StringManagerRef->Builtins[2]);
  }
}

// File Line: 4723
// RVA: 0x7ECCD0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextDynPropIndex(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v3; // rax

  v3 = result;
  if ( ind.Index )
    result->Index = 0;
  else
    result->Index = 1;
  return v3;
}

// File Line: 4731
// RVA: 0x7ED180
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyValue(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
    Scaleform::GFx::AS3::Value::Assign(value, (Scaleform::GFx::AS3::Object *)&this->vfptr);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(value);
}

// File Line: 4742
// RVA: 0x81AFE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::SetProperty(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rdi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::CheckResult *v9; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h]
  unsigned int ind; // [rsp+24h] [rbp-24h]
  __int64 v12; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-18h]

  v12 = -2i64;
  v4 = result;
  v5 = this;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eXMLAssignmentToIndexedXMLNotAllowed, v5->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  v9 = v4;
  v4->Result = 0;
  return v9;
}

// File Line: 4755
// RVA: 0x7EDF20
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdi
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h]
  unsigned int ind; // [rsp+24h] [rbp-14h]

  v4 = this;
  v5 = result;
  v6 = list;
  if ( !Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result || ind )
  {
    v5->Result = 0;
    v7 = v5;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v6, v4);
    v5->Result = 1;
    v7 = v5;
  }
  return v7;
}

// File Line: 4774
// RVA: 0x7EDEA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rsi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h]
  unsigned int ind; // [rsp+24h] [rbp-14h]

  v4 = this;
  v5 = result;
  v6 = value;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    if ( !ind )
    {
      Scaleform::GFx::AS3::Value::Assign(v6, (Scaleform::GFx::AS3::Object *)&v4->vfptr);
      v5->Result = 1;
      return v5;
    }
    Scaleform::GFx::AS3::Value::SetUndefined(v6);
  }
  v5->Result = 0;
  return v5;
}

// File Line: 4791
// RVA: 0x7C0E60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::DeleteProperty(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::Object::DeleteProperty((Scaleform::GFx::AS3::Object *)&this->vfptr, result, prop_name);
  return v3;
}

// File Line: 4861
// RVA: 0x1597280
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[5].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[6].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[7].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[8].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[9].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[10].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[11].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[12].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[13].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[14].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[15].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[16].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[17].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[18].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[19].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[20].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[21].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[22].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[23].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[24].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[25].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[26].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[27].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[28].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[29].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[30].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[31].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[32].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[33].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[34].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[35].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[36].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[37].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[38].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[39].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::ti[40].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}eform::GFx::AS3::NS_AS3;

// File Line: 4912
// RVA: 0x800450
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 4919
// RVA: 0x75E950
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbp
  _QWORD *v7; // rax
  _QWORD *v8; // rsi
  Scaleform::GFx::AS3::Object *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::AS3::Traits *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v4 = result;
  v5 = _this;
  v6 = vm;
  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_16;
  v7 = (_QWORD *)((__int64 (__cdecl *)(Scaleform::GFx::AS3::XMLSupport *))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)(vm->XMLSupport_.pObject);
  v8 = v7;
  if ( !v7[17] )
    (*(void (__fastcall **)(_QWORD *))(*v7 + 80i64))(v7);
  v9 = v5->value.VS._1.VObj;
  if ( v9 != Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v8[17]) )
  {
LABEL_16:
    if ( (v5->Flags & 0x1F) - 12 <= 3
      && (v10 = (Scaleform::GFx::AS3::Instances::fl::XML *)v5->value.VS._1.VStr) != 0i64
      && (v11 = v10->pTraits.pObject, v11->TraitsType == 18)
      && ~(LOBYTE(v11->Flags) >> 5) & 1 )
    {
      resulta.pNode = v6->StringManagerRef->Builtins[0].pNode;
      ++resulta.pNode->RefCount;
      Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(v10, &resulta);
      Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
      v12 = resulta.pNode;
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eInvokeOnIncompatibleObjectError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v12 = v15.Message.pNode;
    }
    v14 = v12->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::ASString *)v6->StringManagerRef);
  }
}

// File Line: 4942
// RVA: 0x75F4E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::PropertyIsEnumerableProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::VM *v8; // rbp
  Scaleform::GFx::AS3::ThunkInfo *v9; // r15
  _QWORD *v10; // rax
  _QWORD *v11; // rsi
  Scaleform::GFx::AS3::Object *v12; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // rcx
  Scaleform::GFx::AS3::Traits *v14; // rax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+38h] [rbp-30h]

  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = ti;
  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_15;
  v10 = (_QWORD *)((__int64 (*)(void))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)();
  v11 = v10;
  if ( !v10[17] )
    (*(void (__fastcall **)(_QWORD *))(*v10 + 80i64))(v10);
  v12 = v7->value.VS._1.VObj;
  if ( v12 != Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v11[17]) )
  {
LABEL_15:
    if ( (v7->Flags & 0x1F) - 12 <= 3
      && (v13 = (Scaleform::GFx::AS3::Instances::fl::XML *)v7->value.VS._1.VStr) != 0i64
      && (v14 = v13->pTraits.pObject, v14->TraitsType == 18)
      && ~(LOBYTE(v14->Flags) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable(v13, v6, argc, argv);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvokeOnIncompatibleObjectError, v8);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v15, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v16 = v18.Message.pNode;
      v17 = v18.Message.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(v9, v8, v7, v6, argc, argv);
  }
}

// File Line: 4961
// RVA: 0x75FA60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::HasOwnPropertyProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::VM *v8; // rbp
  Scaleform::GFx::AS3::ThunkInfo *v9; // r14
  _QWORD *v10; // rax
  _QWORD *v11; // rsi
  Scaleform::GFx::AS3::Object *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rbx
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  char v16; // al
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  bool v20; // zf
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+18h]

  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = ti;
  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    v10 = (_QWORD *)((__int64 (*)(void))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)();
    v11 = v10;
    if ( !v10[17] )
      (*(void (__fastcall **)(_QWORD *))(*v10 + 80i64))(v10);
    v12 = v7->value.VS._1.VObj;
    if ( v12 == Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v11[17]) )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(v9, v8, v7, v6, argc, argv);
      return;
    }
  }
  if ( (v7->Flags & 0x1F) - 12 <= 3
    && (v13 = v7->value.VS._1.VStr) != 0i64
    && (v14 = v13[1].pData, *((_DWORD *)v14 + 30) == 18)
    && ~((const unsigned __int8)v14[112] >> 5) & 1 )
  {
    if ( argc >= 1 && (argv->Flags & 0x1F) == 10 )
    {
      v15 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, &resulta);
      v16 = (*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASString *))v13->pData + 29))(
              v13,
              v15);
      Scaleform::GFx::AS3::Value::SetBool(v6, v16);
      v17 = resulta.pNode;
      goto LABEL_16;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eInvalidArgumentError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v18, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eInvokeOnIncompatibleObjectError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v19, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  v17 = v21.Message.pNode;
LABEL_16:
  v20 = v17->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 5006
// RVA: 0x7A3890
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3settings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v2; // rdi
  Scaleform::GFx::AS3::Classes::fl::XML *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // rax
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v5; // r14
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v7; // rbx
  unsigned int v8; // eax
  bool v9; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::WeakProxy *v14; // rdx
  bool v15; // al
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::WeakProxy *v19; // rdx
  bool v20; // al
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx
  bool v25; // al
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::WeakProxy *v29; // rdx
  int v30; // eax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::WeakProxy *v34; // rdx
  int v35; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v36; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value v38; // [rsp+48h] [rbp-28h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+90h] [rbp+20h]

  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->TraitsObject.pObject->ITraits.pObject);
  v6 = v2->pObject;
  v7 = resulta.pV;
  if ( resulta.pV != v2->pObject )
  {
    if ( v6 )
    {
      if ( (unsigned __int8)v6 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v6 - 1);
      }
      else
      {
        v8 = v6->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          v6->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
        }
      }
    }
    v2->pObject = v7;
  }
  v9 = v3->ignoreComments;
  v38.Flags = 1;
  v38.Bonus.pWeakProxy = 0i64;
  v38.value.VS._1.VBool = v9;
  v35 = 0;
  v36 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreComments")->pNode;
  ++v36->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v35;
  key.pSecond = &v38;
  v10 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v7->DynAttrs.mHash.pTable;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v10,
    v10,
    &key);
  v11 = v36;
  v12 = v36->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v13 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev) == 1;
  --v13->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v14 = v38.Bonus.pWeakProxy;
      v12 = v38.Bonus.pWeakProxy->RefCount == 1;
      --v14->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v14);
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
  v15 = v3->ignoreProcessingInstructions;
  v38.Flags = 1;
  v38.Bonus.pWeakProxy = 0i64;
  v38.value.VS._1.VBool = v15;
  v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreProcessingInstructions");
  v35 = 0;
  v36 = v16->pNode;
  ++v36->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v35;
  key.pSecond = &v38;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v10,
    v10,
    &key);
  v17 = v36;
  v12 = v36->RefCount == 1;
  --v17->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev) == 1;
  --v18->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v19 = v38.Bonus.pWeakProxy;
      v12 = v38.Bonus.pWeakProxy->RefCount == 1;
      --v19->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v19);
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
  v20 = v3->ignoreWhitespace;
  v38.Flags = 1;
  v38.Bonus.pWeakProxy = 0i64;
  v38.value.VS._1.VBool = v20;
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreWhitespace");
  v35 = 0;
  v36 = v21->pNode;
  ++v36->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v35;
  key.pSecond = &v38;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v10,
    v10,
    &key);
  v22 = v36;
  v12 = v36->RefCount == 1;
  --v22->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v23 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev) == 1;
  --v23->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v24 = v38.Bonus.pWeakProxy;
      v12 = v38.Bonus.pWeakProxy->RefCount == 1;
      --v24->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v24);
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
  v25 = v3->prettyPrinting;
  v38.Flags = 1;
  v38.Bonus.pWeakProxy = 0i64;
  v38.value.VS._1.VBool = v25;
  v26 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyPrinting");
  v35 = 0;
  v36 = v26->pNode;
  ++v36->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v35;
  key.pSecond = &v38;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v10,
    v10,
    &key);
  v27 = v36;
  v12 = v36->RefCount == 1;
  --v27->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  v28 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev) == 1;
  --v28->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v29 = v38.Bonus.pWeakProxy;
      v12 = v38.Bonus.pWeakProxy->RefCount == 1;
      --v29->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v29);
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
  v30 = v3->prettyIndent;
  v38.Flags = 2;
  v38.Bonus.pWeakProxy = 0i64;
  v38.value.VS._1.VInt = v30;
  v31 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyIndent");
  v35 = 0;
  v36 = v31->pNode;
  ++v36->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v35;
  key.pSecond = &v38;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v10,
    v10,
    &key);
  v32 = v36;
  v12 = v36->RefCount == 1;
  --v32->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  v33 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev) == 1;
  --v33->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v34 = v38.Bonus.pWeakProxy;
      v12 = v38.Bonus.pWeakProxy->RefCount == 1;
      --v34->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v34);
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
}

// File Line: 5026
// RVA: 0x85F280
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::settings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3settings(this, result);
}

// File Line: 5037
// RVA: 0x7A32E0
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *o)
{
  Scaleform::GFx::AS3::Classes::fl::XML *v3; // rdi
  unsigned int v4; // edx
  long double v5; // rbp
  Scaleform::GFx::AS3::StringManager *v6; // r14
  _DWORD *v7; // rsi
  Scaleform::GFx::ASStringNode *v8; // r8
  __int64 v9; // r10
  __int64 v10; // r9
  __int64 v11; // rdx
  __int64 *v12; // rcx
  signed __int64 v13; // rbx
  signed __int64 v14; // rbx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // r8
  __int64 v18; // r10
  __int64 v19; // r9
  __int64 v20; // rdx
  __int64 *v21; // rcx
  signed __int64 v22; // rbx
  signed __int64 v23; // rbx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // r8
  __int64 v26; // r10
  __int64 v27; // r9
  __int64 v28; // rdx
  __int64 *v29; // rcx
  signed __int64 v30; // rbx
  signed __int64 v31; // rbx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // r8
  __int64 v34; // r10
  __int64 v35; // r9
  __int64 v36; // rdx
  __int64 *v37; // rcx
  signed __int64 v38; // rbx
  signed __int64 v39; // rbx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // r8
  __int64 v42; // r10
  __int64 v43; // r9
  __int64 v44; // rdx
  __int64 *v45; // rcx
  signed __int64 v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v3 = this;
  v4 = o->Flags & 0x1F;
  if ( v4 && (v4 - 12 > 3 && v4 != 10 || *(_QWORD *)&o->value.VNumber) )
  {
    if ( v4 - 12 <= 3 )
    {
      v5 = o->value.VNumber;
      v6 = this->pTraits.pObject->pVM->StringManagerRef;
      v7 = 0i64;
      v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
             &resulta,
             "ignoreComments")->pNode;
      ++v8->RefCount;
      v9 = *(_QWORD *)(*(_QWORD *)&v5 + 48i64);
      if ( !v9 )
        goto LABEL_16;
      v10 = v8->HashFlags & *(_DWORD *)(v9 + 8) & 0xFFFFFF;
      v11 = (unsigned int)v10;
      v12 = (__int64 *)((v10 << 6) + v9 + 16);
      if ( *v12 == -2 || v12[1] != v10 )
        goto LABEL_16;
      while ( v12[1] != v10 || (Scaleform::GFx::ASStringNode *)v12[3] != v8 )
      {
        v11 = *v12;
        if ( *v12 == -1 )
          goto LABEL_16;
        v12 = (__int64 *)((v11 << 6) + v9 + 16);
      }
      if ( v11 >= 0 && (v13 = (v11 << 6) + v9 + 32) != 0 )
        v14 = v13 + 16;
      else
LABEL_16:
        v14 = 0i64;
      v15 = v8->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      v16 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( v14 && (*(_DWORD *)v14 & 0x1F) == 1 )
        v3->ignoreComments = *(_BYTE *)(v14 + 16);
      v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
              &resulta,
              "ignoreProcessingInstructions")->pNode;
      ++v17->RefCount;
      v18 = *(_QWORD *)(*(_QWORD *)&v5 + 48i64);
      if ( !v18 )
        goto LABEL_34;
      v19 = v17->HashFlags & *(_DWORD *)(v18 + 8) & 0xFFFFFF;
      v20 = (unsigned int)v19;
      v21 = (__int64 *)((v19 << 6) + v18 + 16);
      if ( *v21 == -2 || v21[1] != v19 )
        goto LABEL_34;
      while ( v21[1] != v19 || (Scaleform::GFx::ASStringNode *)v21[3] != v17 )
      {
        v20 = *v21;
        if ( *v21 == -1 )
          goto LABEL_34;
        v21 = (__int64 *)((v20 << 6) + v18 + 16);
      }
      if ( v20 >= 0 && (v22 = (v20 << 6) + v18 + 32) != 0 )
        v23 = v22 + 16;
      else
LABEL_34:
        v23 = 0i64;
      v15 = v17->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v24 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 && (*(_DWORD *)v23 & 0x1F) == 1 )
        v3->ignoreProcessingInstructions = *(_BYTE *)(v23 + 16);
      v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
              &resulta,
              "ignoreWhitespace")->pNode;
      ++v25->RefCount;
      v26 = *(_QWORD *)(*(_QWORD *)&v5 + 48i64);
      if ( !v26 )
        goto LABEL_52;
      v27 = v25->HashFlags & *(_DWORD *)(v26 + 8) & 0xFFFFFF;
      v28 = (unsigned int)v27;
      v29 = (__int64 *)((v27 << 6) + v26 + 16);
      if ( *v29 == -2 || v29[1] != v27 )
        goto LABEL_52;
      while ( v29[1] != v27 || (Scaleform::GFx::ASStringNode *)v29[3] != v25 )
      {
        v28 = *v29;
        if ( *v29 == -1 )
          goto LABEL_52;
        v29 = (__int64 *)((v28 << 6) + v26 + 16);
      }
      if ( v28 >= 0 && (v30 = (v28 << 6) + v26 + 32) != 0 )
        v31 = v30 + 16;
      else
LABEL_52:
        v31 = 0i64;
      v15 = v25->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      v32 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v32->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      if ( v31 && (*(_DWORD *)v31 & 0x1F) == 1 )
        v3->ignoreWhitespace = *(_BYTE *)(v31 + 16);
      v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
              &resulta,
              "prettyPrinting")->pNode;
      ++v33->RefCount;
      v34 = *(_QWORD *)(*(_QWORD *)&v5 + 48i64);
      if ( !v34 )
        goto LABEL_70;
      v35 = v33->HashFlags & *(_DWORD *)(v34 + 8) & 0xFFFFFF;
      v36 = (unsigned int)v35;
      v37 = (__int64 *)((v35 << 6) + v34 + 16);
      if ( *v37 == -2 || v37[1] != v35 )
        goto LABEL_70;
      while ( v37[1] != v35 || (Scaleform::GFx::ASStringNode *)v37[3] != v33 )
      {
        v36 = *v37;
        if ( *v37 == -1 )
          goto LABEL_70;
        v37 = (__int64 *)((v36 << 6) + v34 + 16);
      }
      if ( v36 >= 0 && (v38 = (v36 << 6) + v34 + 32) != 0 )
        v39 = v38 + 16;
      else
LABEL_70:
        v39 = 0i64;
      v15 = v33->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      v40 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v40->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      if ( v39 && (*(_DWORD *)v39 & 0x1F) == 1 )
        v3->prettyPrinting = *(_BYTE *)(v39 + 16);
      v41 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
              &resulta,
              "prettyIndent")->pNode;
      ++v41->RefCount;
      v42 = *(_QWORD *)(*(_QWORD *)&v5 + 48i64);
      if ( v42 )
      {
        v43 = v41->HashFlags & *(_DWORD *)(v42 + 8) & 0xFFFFFF;
        v44 = (unsigned int)v43;
        v45 = (__int64 *)((v43 << 6) + v42 + 16);
        if ( *v45 != -2 && v45[1] == v43 )
        {
          while ( v45[1] != v43 || (Scaleform::GFx::ASStringNode *)v45[3] != v41 )
          {
            v44 = *v45;
            if ( *v45 == -1 )
              goto LABEL_88;
            v45 = (__int64 *)((v44 << 6) + v42 + 16);
          }
          if ( v44 >= 0 )
          {
            v46 = (v44 << 6) + v42 + 32;
            if ( v46 )
              v7 = (_DWORD *)(v46 + 16);
          }
        }
      }
LABEL_88:
      v15 = v41->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v41);
      v47 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v47->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v47);
      if ( v7 )
      {
        if ( (*v7 & 0x1Fu) - 2 <= 1 )
          v3->prettyIndent = v7[4];
      }
    }
  }
  else
  {
    *(_DWORD *)&this->ignoreComments = 16843009;
    this->prettyIndent = 2;
  }
}

// File Line: 5078
// RVA: 0x85E9B0
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::setSettings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *o)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings(this, result, o);
}

// File Line: 5089
// RVA: 0x79C260
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rax
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rbx
  unsigned int v7; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::WeakProxy *v12; // rdx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::WeakProxy *v16; // rdx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::WeakProxy *v20; // rdx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::WeakProxy *v28; // rdx
  int v29; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v30; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value v32; // [rsp+48h] [rbp-28h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+80h] [rbp+10h]

  v2 = result;
  v3 = this->pTraits.pObject->pVM;
  v4 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v3->TraitsObject.pObject->ITraits.pObject);
  v5 = v2->pObject;
  v6 = resulta.pV;
  if ( resulta.pV != v2->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v2->pObject = v6;
  }
  v32.Flags = 1;
  v32.Bonus.pWeakProxy = 0i64;
  v32.value.VS._1.VBool = 1;
  v29 = 0;
  v30 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v4,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreComments")->pNode;
  ++v30->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
  key.pSecond = &v32;
  v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v6->DynAttrs.mHash.pTable;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v8,
    v8,
    &key);
  v9 = v30;
  v10 = v30->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v11 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev) == 1;
  --v11->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v12 = v32.Bonus.pWeakProxy;
      v10 = v32.Bonus.pWeakProxy->RefCount == 1;
      --v12->RefCount;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v12);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v32.Flags = 1;
  v32.Bonus.pWeakProxy = 0i64;
  v32.value.VS._1.VBool = 1;
  v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v4,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreProcessingInstructions");
  v29 = 0;
  v30 = v13->pNode;
  ++v30->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
  key.pSecond = &v32;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v8,
    v8,
    &key);
  v14 = v30;
  v10 = v30->RefCount == 1;
  --v14->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev) == 1;
  --v15->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v16 = v32.Bonus.pWeakProxy;
      v10 = v32.Bonus.pWeakProxy->RefCount == 1;
      --v16->RefCount;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v16);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v32.Flags = 1;
  v32.Bonus.pWeakProxy = 0i64;
  v32.value.VS._1.VBool = 1;
  v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v4,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreWhitespace");
  v29 = 0;
  v30 = v17->pNode;
  ++v30->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
  key.pSecond = &v32;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v8,
    v8,
    &key);
  v18 = v30;
  v10 = v30->RefCount == 1;
  --v18->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev) == 1;
  --v19->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v20 = v32.Bonus.pWeakProxy;
      v10 = v32.Bonus.pWeakProxy->RefCount == 1;
      --v20->RefCount;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v20);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v32.Flags = 1;
  v32.Bonus.pWeakProxy = 0i64;
  v32.value.VS._1.VBool = 1;
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v4,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyPrinting");
  v29 = 0;
  v30 = v21->pNode;
  ++v30->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
  key.pSecond = &v32;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v8,
    v8,
    &key);
  v22 = v30;
  v10 = v30->RefCount == 1;
  --v22->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v23 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev) == 1;
  --v23->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v24 = v32.Bonus.pWeakProxy;
      v10 = v32.Bonus.pWeakProxy->RefCount == 1;
      --v24->RefCount;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v24);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v32.Flags = 2;
  v32.Bonus.pWeakProxy = 0i64;
  v32.value.VS._1.VInt = 2;
  v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v4,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyIndent");
  v29 = 0;
  v30 = v25->pNode;
  ++v30->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
  key.pSecond = &v32;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    v8,
    v8,
    &key);
  v26 = v30;
  v10 = v30->RefCount == 1;
  --v26->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  v27 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev) == 1;
  --v27->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags >> 9) & 1 )
    {
      v28 = v32.Bonus.pWeakProxy;
      v10 = v32.Bonus.pWeakProxy->RefCount == 1;
      --v28->RefCount;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v28);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
}leform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v28);
      v32.

// File Line: 5109
// RVA: 0x834410
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::defaultSettings(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings(this, result);
}

// File Line: 5122
// RVA: 0x7B9150
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::Construct(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  unsigned int v5; // er14
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Classes::fl::XML *v7; // r15
  Scaleform::GFx::AS3::Traits *v8; // rax
  Scaleform::GFx::AS3::VM *v9; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v10; // r12
  Scaleform::GFx::AS3::Traits *v11; // rax
  signed int v12; // ecx
  unsigned __int64 v13; // rdx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  int v16; // er8
  long double v17; // rdx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Object **v23; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v24; // rbx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLText *v26; // rbx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::Object **v28; // rax
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::AS3::Object **v30; // rax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::AS3::Object **v32; // rax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-79h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v34; // [rsp+38h] [rbp-71h]
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+40h] [rbp-69h]
  Scaleform::GFx::ASString v36; // [rsp+50h] [rbp-59h]
  __int64 v37; // [rsp+58h] [rbp-51h]
  Scaleform::GFx::AS3::XMLParser v38; // [rsp+68h] [rbp-41h]
  Scaleform::GFx::AS3::Object *v; // [rsp+108h] [rbp+5Fh]
  Scaleform::GFx::AS3::CheckResult v40; // [rsp+118h] [rbp+6Fh]
  void *retaddr; // [rsp+128h] [rbp+7Fh]

  v37 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = _this;
  v7 = this;
  v8 = this->pTraits.pObject;
  v9 = v8->pVM;
  v10 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v8[1].vfptr;
  if ( !argc )
  {
LABEL_38:
    v31 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&v);
    v32 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                            v10,
                                            &v34,
                                            (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v10->vfptr,
                                            v31,
                                            0i64);
    Scaleform::GFx::AS3::Value::Pick(v6, *v32);
    goto LABEL_39;
  }
  v11 = Scaleform::GFx::AS3::VM::GetValueTraits(v8->pVM, argv);
  v12 = v11->TraitsType;
  v13 = (unsigned __int64)v11->Flags >> 5;
  if ( v13 & 1 )
  {
    if ( !(_BYTE)retaddr )
      Scaleform::GFx::AS3::VSBase::PopBack((Scaleform::GFx::AS3::VSBase *)&v9->OpStack.pCurrent, v5);
    Scaleform::GFx::AS3::VM::Error::Error(&v35, eInvokeOnIncompatibleObjectError, v9);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v15 = v35.Message.pNode;
    goto LABEL_40;
  }
  v16 = v4->Flags & 0x1F;
  if ( v16 && ((unsigned int)(v16 - 12) > 3 && v16 != 10 || *(_QWORD *)&v4->value.VNumber) )
  {
    if ( ~(_BYTE)v13 & 1 && v12 > 0 )
    {
      if ( v12 <= 4 )
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->StringManagerRef->Builtins,
          &result);
        Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&v, &result);
        v28 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                v10,
                                                &v34,
                                                (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v10->vfptr,
                                                &result,
                                                0i64);
        Scaleform::GFx::AS3::Value::Pick(v6, *v28);
        v15 = result.pNode;
        goto LABEL_40;
      }
      switch ( v12 )
      {
        case 5:
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v4, (Scaleform::GFx::ASString *)&v);
          if ( *Scaleform::GFx::ASUtils::SkipWhiteSpace((const char *)v->vfptr, v->RefCount) == 60 )
          {
            Scaleform::GFx::AS3::XMLParser::XMLParser(&v38, v10);
            result.pNode = 0i64;
            *(_QWORD *)&v35.ID = v->vfptr;
            v35.Message.pNode = (Scaleform::GFx::ASStringNode *)v->RefCount;
            if ( Scaleform::GFx::AS3::XMLParser::Parse(
                   &v38,
                   &v40,
                   (Scaleform::StringDataPtr *)&v35,
                   (unsigned __int64 *)&result,
                   0)->Result )
            {
              Scaleform::GFx::AS3::Value::Assign(v6, (Scaleform::GFx::AS3::Object *)&v38.pCurrElem.pObject->vfptr);
            }
            else
            {
              v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject[1].vfptr;
              v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->StringManagerRef->Builtins,
                      &v36);
              v26 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                      v24,
                      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&v35,
                      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v24->vfptr,
                      v25,
                      0i64)->pV;
              v27 = v36.pNode;
              v21 = v36.pNode->RefCount == 1;
              --v27->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v27);
              Scaleform::GFx::AS3::Value::Pick(v6, (Scaleform::GFx::AS3::Object *)&v26->vfptr);
            }
            Scaleform::GFx::AS3::XMLParser::~XMLParser(&v38);
          }
          else
          {
            if ( v7->ignoreWhitespace )
            {
              v19 = Scaleform::GFx::ASString::TruncateWhitespace((Scaleform::GFx::ASString *)&v, &result)->pNode;
              ++v19->RefCount;
              v20 = (Scaleform::GFx::ASStringNode *)v;
              v21 = LODWORD(v->pPrev) == 1;
              --v20->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              v = (Scaleform::GFx::AS3::Object *)v19;
              v22 = result.pNode;
              v21 = result.pNode->RefCount == 1;
              --v22->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            }
            v23 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject[1].vfptr,
                                                    &v34,
                                                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)v7->pTraits.pObject[1].vfptr,
                                                    (Scaleform::GFx::ASString *)&v,
                                                    0i64);
            Scaleform::GFx::AS3::Value::Pick(v6, *v23);
          }
          goto LABEL_39;
        case 18:
          (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Object **, _QWORD))v4->value.VS._1.VStr->pData + 35))(
            *(_QWORD *)&v4->value.VNumber,
            &v,
            0i64);
          Scaleform::GFx::AS3::Value::Pick(v6, v);
          return;
        case 19:
          v17 = v4->value.VNumber;
          if ( *(_QWORD *)(*(_QWORD *)&v17 + 88i64) == 1i64 )
          {
            Scaleform::GFx::AS3::Value::Assign(v6, **(Scaleform::GFx::AS3::Object ***)(*(_QWORD *)&v17 + 80i64));
            return;
          }
          if ( !(_BYTE)retaddr )
            Scaleform::GFx::AS3::VSBase::PopBack((Scaleform::GFx::AS3::VSBase *)&v9->OpStack.pCurrent, v5);
          Scaleform::GFx::AS3::VM::Error::Error(
            (Scaleform::GFx::AS3::VM::Error *)((char *)&v35 + 8),
            eInvokeOnIncompatibleObjectError,
            v9);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          v15 = v36.pNode;
          goto LABEL_40;
      }
    }
    goto LABEL_38;
  }
  v29 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->StringManagerRef->Builtins,
          (Scaleform::GFx::ASString *)&v);
  v30 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                          v10,
                                          &v34,
                                          (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v10->vfptr,
                                          v29,
                                          0i64);
  Scaleform::GFx::AS3::Value::Pick(v6, *v30);
LABEL_39:
  v15 = (Scaleform::GFx::ASStringNode *)v;
LABEL_40:
  v21 = v15->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 5242
// RVA: 0x7B2D20
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::Call(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::Value *__formal, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // ebp
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Classes::fl::XML *v7; // rdi
  Scaleform::GFx::AS3::Traits *v8; // rax

  v5 = argc;
  v6 = result;
  v7 = this;
  if ( argc
    && (v8 = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv), ~(LOBYTE(v8->Flags) >> 5) & 1)
    && v8->TraitsType == 18 )
  {
    Scaleform::GFx::AS3::Value::Assign(v6, argv);
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::XML *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const ))v7->vfptr[4].ForEachChild_GC)(
      v7,
      v6,
      v5,
      argv);
  }
}

// File Line: 5285
// RVA: 0x7F4DB0
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::InitPrototype(Scaleform::GFx::AS3::Classes::fl::XML *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Classes::fl::XML *v2; // rbp
  Scaleform::GFx::AS3::Class *v3; // rcx
  Scaleform::GFx::AS3::Object *v4; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  signed __int64 v6; // rdi
  __m128i v7; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = this->ParentClass.pObject;
  v4 = obj;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].Finalize_GC)();
  v7.m128i_i32[2] = 0;
  v7.m128i_i64[0] = (__int64)Scaleform::GFx::AS3::Class::ConvertCheckType;
  _mm_store_si128(&v7, v7);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    (Scaleform::GFx::AS3::Class *)&v2->vfptr,
    v4,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v7);
  v5 = Scaleform::GFx::AS3::Classes::fl::XML::f;
  v6 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(v4, v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  Scaleform::GFx::AS3::Class::AddConstructor((Scaleform::GFx::AS3::Class *)&v2->vfptr, v4);
}

// File Line: 5318
// RVA: 0x158E810
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::XML_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B080 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::XML,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Classes::fl::XML::AS3settings;
  return result;
}

// File Line: 5319
// RVA: 0x158E780
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::XML_1_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B090 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::XML,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Classes::fl::XML::settings;
  return result;
}

// File Line: 5320
// RVA: 0x1593FD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::XML_2_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B0A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings;
  return result;
}

// File Line: 5321
// RVA: 0x1594000
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::XML_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B0B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Classes::fl::XML::setSettings;
  return result;
}

// File Line: 5322
// RVA: 0x158E7B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::XML_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B0C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::XML,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings;
  return result;
}

// File Line: 5323
// RVA: 0x158E7E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::XML_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B0D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::XML,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Classes::fl::XML::defaultSettings;
  return result;
}

// File Line: 5347
// RVA: 0x1597260
const char *dynamic_initializer_for__Scaleform::GFx::AS3::ClassTraits::fl::XML::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::ClassTraits::fl::XML::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::ClassTraits::fl::XML::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::ClassTraits::fl::XML::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 5367
// RVA: 0x765B10
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::XML::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::XMLCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::XML::`vftable';
    v6->TraitsType = 18;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::XMLCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::XML::`vftable';
    v8.pV->TraitsType = 18;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       80i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::XML::`vftable';
    LODWORD(v10[1].vfptr) = 16843009;
    HIDWORD(v10[1].vfptr) = 2;
  }
  return v3;
}

