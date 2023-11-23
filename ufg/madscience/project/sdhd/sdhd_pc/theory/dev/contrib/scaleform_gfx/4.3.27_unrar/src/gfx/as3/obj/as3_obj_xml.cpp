// File Line: 37
// RVA: 0x78CF20
void __fastcall Scaleform::GFx::AS3::NamespaceArray::~NamespaceArray(Scaleform::GFx::AS3::NamespaceArray *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)this);
}

// File Line: 41
// RVA: 0x7AFB20
void __fastcall Scaleform::GFx::AS3::NamespaceArray::AddUnique(
        Scaleform::GFx::AS3::NamespaceArray *this,
        Scaleform::GFx::AS3::NamespaceArray *other)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rbx
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v10; // rdx
  unsigned int RefCount; // eax

  Size = other->Namespaces.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    pObject = other->Namespaces.Data.Data[i].pObject;
    v7 = 0i64;
    v8 = this->Namespaces.Data.Size;
    if ( v8 )
    {
      Data = this->Namespaces.Data.Data;
      while ( Data->pObject->Uri.pNode != pObject->Uri.pNode
           || ((*((_BYTE *)pObject + 40) ^ *((_BYTE *)Data->pObject + 40)) & 0xF) != 0 )
      {
        ++v7;
        ++Data;
        if ( v7 >= v8 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this->Namespaces.Data.pHeap,
        this->Namespaces.Data.Size + 1);
      v10 = &this->Namespaces.Data.Data[this->Namespaces.Data.Size - 1];
      if ( v10 )
      {
        v10->pObject = pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( pObject && ((unsigned __int8)pObject & 1) == 0 )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
}

// File Line: 96
// RVA: 0x7AADA0
void __fastcall Scaleform::GFx::AS3::NamespaceArray::Add(
        Scaleform::GFx::AS3::NamespaceArray *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *other,
        bool checkUnique)
{
  unsigned __int64 v5; // rdx
  unsigned __int64 Size; // r9
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v8; // rdx
  unsigned int RefCount; // eax

  if ( checkUnique && (v5 = 0i64, (Size = this->Namespaces.Data.Size) != 0) )
  {
    Data = this->Namespaces.Data.Data;
    while ( Data->pObject->Uri.pNode != other->Uri.pNode
         || ((*((_BYTE *)other + 40) ^ *((_BYTE *)Data->pObject + 40)) & 0xF) != 0 )
    {
      ++v5;
      ++Data;
      if ( v5 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( other )
      other->RefCount = (other->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this->Namespaces.Data.pHeap,
      this->Namespaces.Data.Size + 1);
    v8 = &this->Namespaces.Data.Data[this->Namespaces.Data.Size - 1];
    if ( v8 )
    {
      v8->pObject = other;
      if ( other )
        other->RefCount = (other->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( other && ((unsigned __int8)other & 1) == 0 )
    {
      RefCount = other->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        other->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(other);
      }
    }
  }
}

// File Line: 127
// RVA: 0x785460
void __fastcall Scaleform::GFx::AS3::XMLParser::XMLParser(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *itr)
{
  Scaleform::MemoryHeap *MHeap; // rcx
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v6; // rbx
  Scaleform::GFx::AS3::Class *pObject; // rbx

  this->NsSep = 58;
  this->NodeKind = kNone;
  this->ITr = itr;
  this->Parser = (struct XML_ParserStruct *)XML_ParserCreate(0i64);
  this->pCurrElem.pObject = 0i64;
  MHeap = itr->pVM->MHeap;
  this->RootElements.Data.Data = 0i64;
  this->RootElements.Data.Size = 0i64;
  this->RootElements.Data.Policy.Capacity = 0i64;
  this->RootElements.Data.pHeap = MHeap;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    itr->pVM->StringManagerRef,
    &this->Text);
  v5 = itr->pVM->MHeap;
  this->KindStack.Data.Data = 0i64;
  this->KindStack.Data.Size = 0i64;
  this->KindStack.Data.Policy.Capacity = 0i64;
  this->KindStack.Data.pHeap = v5;
  XML_SetUserData(this->Parser, this);
  XML_SetElementHandler(
    this->Parser,
    Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback,
    Scaleform::GFx::AS3::XMLParser::EndElementExpatCallback);
  XML_SetCharacterDataHandler(this->Parser, Scaleform::GFx::AS3::XMLParser::CharacterDataExpatCallback);
  XML_SetXmlDeclHandler(this->Parser, Scaleform::GFx::AS3::XMLParser::DeclExpatCallback);
  XML_SetDoctypeDeclHandler(
    this->Parser,
    Scaleform::GFx::AS3::XMLParser::StartDoctypeDeclExpatCallback,
    Scaleform::GFx::AS3::XMLParser::EndDoctypeDeclExpatCallback);
  XML_SetDefaultHandler(this->Parser, _);
  v6 = this->ITr;
  if ( !v6->pConstructor.pObject )
    v6->vfptr[3].~RefCountBaseGC<328>(this->ITr);
  pObject = v6->pConstructor.pObject;
  if ( !LOBYTE(pObject[1].vfptr) )
    XML_SetCommentHandler(this->Parser, Scaleform::GFx::AS3::XMLParser::CommentExpatCallback);
  if ( !BYTE1(pObject[1].vfptr) )
    XML_SetProcessingInstructionHandler(
      this->Parser,
      Scaleform::GFx::AS3::XMLParser::ProcessingInstructionExpatCallback);
}

// File Line: 150
// RVA: 0x790040
void __fastcall Scaleform::GFx::AS3::XMLParser::~XMLParser(Scaleform::GFx::AS3::XMLParser *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax

  XML_ParserFree(this->Parser);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->KindStack.Data.Data);
  pNode = this->Text.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->RootElements);
  pObject = this->pCurrElem.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pCurrElem.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 155
// RVA: 0x81A8B0
void __fastcall Scaleform::GFx::AS3::XMLParser::SetNodeKind(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::XMLParser::Kind k)
{
  Scaleform::GFx::AS3::XMLParser::Kind NodeKind; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *ITr; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rsi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *p_pCurrElem; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pV; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v21; // [rsp+98h] [rbp+20h] BYREF

  NodeKind = this->NodeKind;
  if ( NodeKind != k )
  {
    if ( NodeKind == kText )
    {
      ITr = this->ITr;
      if ( !ITr->pConstructor.pObject )
        ITr->vfptr[3].~RefCountBaseGC<328>(this->ITr);
      if ( BYTE2(ITr->pConstructor.pObject[1].vfptr) )
      {
        v6 = Scaleform::GFx::ASString::TruncateWhitespace(&this->Text, &result);
        pNode = v6->pNode;
        ++v6->pNode->RefCount;
        v8 = this->Text.pNode;
        v9 = v8->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        this->Text.pNode = pNode;
        v10 = result.pNode;
        v9 = result.pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      }
      if ( this->Text.pNode->Size )
      {
        p_pCurrElem = &this->pCurrElem;
        pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
               this->ITr,
               &v21,
               this->ITr,
               &this->Text,
               this->pCurrElem.pObject)->pV;
        if ( this->pCurrElem.pObject
          && ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->pCurrElem.pObject->vfptr[8].Finalize_GC)(this->pCurrElem.pObject) == 1 )
        {
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))p_pCurrElem->pObject->vfptr[7].Finalize_GC)(
            p_pCurrElem->pObject,
            &pV);
        }
        else
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->RootElements.Data,
            this->RootElements.Data.pHeap,
            this->RootElements.Data.Size + 1);
          v12 = &this->RootElements.Data.Data[this->RootElements.Data.Size - 1];
          if ( v12 )
          {
            v12->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)pV;
            v13 = pV;
            if ( pV )
            {
              ++pV->RefCount;
              v13->RefCount &= 0x8FBFFFFF;
            }
          }
          if ( &pV != (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_pCurrElem )
          {
            v14 = pV;
            if ( pV )
            {
              ++pV->RefCount;
              v14->RefCount &= 0x8FBFFFFF;
              v14 = pV;
            }
            pObject = p_pCurrElem->pObject;
            if ( p_pCurrElem->pObject )
            {
              if ( ((unsigned __int8)pObject & 1) != 0 )
              {
                p_pCurrElem->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
              }
              else
              {
                RefCount = pObject->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  pObject->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
                  v14 = pV;
                }
              }
            }
            p_pCurrElem->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v14;
          }
        }
        Scaleform::GFx::ASString::Clear(&this->Text);
        v17 = pV;
        if ( pV )
        {
          if ( ((unsigned __int8)pV & 1) != 0 )
          {
            pV = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)pV - 1);
          }
          else
          {
            v18 = pV->RefCount;
            if ( (v18 & 0x3FFFFF) != 0 )
            {
              pV->RefCount = v18 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
            }
          }
        }
      }
    }
    this->NodeKind = k;
  }
}

// File Line: 195
// RVA: 0x8060C0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLParser::Parse(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::StringDataPtr *str,
        unsigned __int64 *pos,
        bool isList)
{
  __int64 v5; // rbp
  __int64 v6; // rdi
  __int64 v7; // rsi
  __int64 v8; // r12
  __int64 v9; // r13
  __int64 v10; // r14
  __int64 v11; // r15
  __int64 v16; // rbp
  int v17; // eax
  bool v18; // r13
  int ErrorCode; // eax
  __int64 v20; // r8
  __int32 v21; // edi
  unsigned __int64 v22; // rbx
  __int64 v23; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned __int64 v25; // rcx
  const char *pStr; // rdx
  Scaleform::GFx::AS3::VM::Error *v27; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v31; // [rsp+28h] [rbp-50h] BYREF
  __int64 v32; // [rsp+40h] [rbp-38h]
  __int64 v33; // [rsp+48h] [rbp-30h]
  __int64 v34; // [rsp+50h] [rbp-28h]
  __int64 v35; // [rsp+58h] [rbp-20h]
  __int64 v36; // [rsp+60h] [rbp-18h]
  __int64 v37; // [rsp+68h] [rbp-10h]
  __int64 v38; // [rsp+70h] [rbp-8h]
  char v39; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+90h] [rbp+18h]

  v38 = v5;
  v37 = v7;
  v36 = v6;
  v35 = v8;
  v34 = v9;
  v33 = v10;
  v32 = v11;
  v16 = *pos;
  v17 = XML_Parse(this->Parser, &str->pStr[*pos], (unsigned int)str->Size - (unsigned int)*pos, 1i64, -2i64);
  v18 = v17 == 1;
  v39 = 1;
  if ( v17 == 1 )
    goto LABEL_38;
  ErrorCode = XML_GetErrorCode(this->Parser);
  vm = this->ITr->pVM;
  v21 = 1090;
  v22 = 0i64;
  v23 = 0i64;
  if ( this->KindStack.Data.Size )
    v23 = (unsigned int)this->KindStack.Data.Data[this->KindStack.Data.Size - 1];
  LOBYTE(v20) = 1;
  switch ( ErrorCode )
  {
    case 0:
      if ( *pos != v16 )
        goto LABEL_35;
      pObject = this->pCurrElem.pObject;
      if ( !pObject )
        goto LABEL_35;
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, __int64, __int64, unsigned __int64))pObject->vfptr[8].Finalize_GC)(
             pObject,
             v23,
             v20,
             0x140000000ui64) != 4 )
        goto LABEL_35;
      v25 = str->Size - v16;
      if ( !v25 )
        goto LABEL_35;
      pStr = str->pStr;
      break;
    case 1:
      v21 = 1000;
      goto LABEL_35;
    case 3:
      if ( isList )
      {
        v39 = 0;
        LOBYTE(v20) = 0;
      }
      if ( this->pCurrElem.pObject )
      {
        if ( (_DWORD)v23 == 1 )
        {
          v21 = 1085;
          if ( (_BYTE)v20 )
            goto LABEL_35;
        }
      }
      goto LABEL_37;
    case 4:
      if ( !this->pCurrElem.pObject )
        goto LABEL_38;
      goto LABEL_35;
    case 5:
      v21 = 1097;
      goto LABEL_35;
    case 7:
      if ( (_DWORD)v23 == 1 )
        v21 = 1085;
      goto LABEL_35;
    case 8:
      v21 = 1104;
      goto LABEL_35;
    case 9:
      if ( isList )
      {
        v18 = 1;
        goto LABEL_38;
      }
      if ( this->pCurrElem.pObject && (_DWORD)v23 == 1 )
        v21 = 1085;
      else
        v21 = 1088;
      goto LABEL_35;
    case 20:
      v21 = 1091;
      goto LABEL_35;
    case 35:
      goto $LN1_37;
    default:
      goto LABEL_35;
  }
  do
  {
    if ( pStr[v22] == 63 && v22 + 1 < v25 && pStr[v22 + 1] == 62 )
    {
      *pos += v22 + 2;
      result->Result = 1;
      return result;
    }
    ++v22;
  }
  while ( v22 < v25 );
LABEL_35:
  Scaleform::GFx::AS3::VM::Error::Error(&v31, v21, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v27, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v31.Message.pNode;
  if ( v31.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_37:
  if ( v39 )
LABEL_38:
    *pos += (int)XML_GetCurrentByteIndex(this->Parser);
$LN1_37:
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(this, kNone);
  result->Result = v18;
  return result;
}XML_GetCurrentByteIndex(this->Parser);
$LN1_37:
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(this, kNone);
  result->Result = v18;
  return 

// File Line: 357
// RVA: 0x7EF020
void __fastcall Scaleform::GFx::AS3::XMLParser::GetRootNodes(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *nodes)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rax

  for ( i = 0i64; i < this->RootElements.Data.Size; ++i )
  {
    v5 = &this->RootElements.Data.Data[i];
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      nodes,
      nodes,
      nodes->Size + 1);
    v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&nodes->Data[nodes->Size - 1];
    if ( v6 )
    {
      pObject = v5->pObject;
      v6->pObject = v5->pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
  }
}

// File Line: 374
// RVA: 0x821830
void __fastcall Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback(
        void *userData,
        char *name,
        Scaleform::GFx::ASStringNode *atts)
{
  __int64 v6; // r14
  int v7; // r12d
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::ASStringNode *pManager; // rdi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *pLower; // rcx
  Scaleform::GFx::ASStringManager *v13; // rax
  __int64 v14; // r15
  const char *v15; // rdi
  unsigned __int64 v16; // rbx
  const char *v17; // r8
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v18; // rdi
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rbx
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int v24; // r15d
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v25; // rcx
  char v26; // bl
  Scaleform::GFx::ASStringNode *v27; // rdi
  Scaleform::GFx::ASStringNode *VObj; // rsi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v33; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::VM::Error *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  char *v39; // rbx
  Scaleform::GFx::AS3::VM::Error *v40; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v42; // rsi
  Scaleform::GFx::ASString *v43; // rax
  Scaleform::GFx::ASStringNode *v44; // rbx
  Scaleform::GFx::ASStringNode *v45; // rcx
  Scaleform::GFx::ASString *v46; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v47; // rdi
  Scaleform::GFx::ASStringNode *Data; // rcx
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASString *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rbx
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  unsigned __int64 v54; // r15
  __int64 v55; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> **v57; // rax
  bool v58; // si
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rsi
  __int64 v61; // rcx
  __int64 v62; // rax
  __int64 v63; // rcx
  __int64 v64; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_RefCount; // r13
  Scaleform::GFx::ASStringNode *v66; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v67; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v68; // rax
  unsigned __int64 v69; // r12
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v71; // r15
  Scaleform::GFx::AS3::Instances::fl::XML **v72; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v73; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v74; // r12
  Scaleform::GFx::ASStringNode *v75; // r15
  Scaleform::GFx::ASStringNode *v76; // r13
  __int64 v77; // rdi
  unsigned __int64 v78; // rax
  unsigned int v79; // r14d
  char *v80; // rsi
  Scaleform::GFx::ASString *v81; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v82; // rdi
  Scaleform::GFx::ASStringNode *v83; // rcx
  Scaleform::GFx::ASStringNode *v84; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v85; // rdi
  Scaleform::GFx::ASString *v86; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v87; // rdi
  Scaleform::GFx::ASStringNode *v88; // rcx
  Scaleform::GFx::ASStringNode *v89; // rcx
  Scaleform::GFx::ASStringNode *v90; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v91; // rsi
  Scaleform::GFx::ASStringNode *v92; // rdx
  unsigned int v93; // eax
  Scaleform::GFx::ASStringNode *v94; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v95; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v96; // rcx
  unsigned int v97; // edx
  Scaleform::GFx::ASStringNode *v98; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v99; // rcx
  unsigned int v100; // eax
  Scaleform::GFx::AS3::VM::Error *v101; // rax
  Scaleform::GFx::ASStringNode *v102; // rcx
  Scaleform::GFx::ASStringNode *v103; // rcx
  Scaleform::GFx::ASStringNode *v104; // rcx
  unsigned __int64 v105; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *j; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v107; // rcx
  unsigned int v108; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *p; // [rsp+28h] [rbp-79h] BYREF
  Scaleform::GFx::ASString n; // [rsp+30h] [rbp-71h] BYREF
  int v111; // [rsp+38h] [rbp-69h]
  Scaleform::GFx::ASString v112; // [rsp+40h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::VM::Error v113; // [rsp+48h] [rbp-59h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v114; // [rsp+58h] [rbp-49h] BYREF
  void *pheapAddr; // [rsp+70h] [rbp-31h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::Value prefix; // [rsp+80h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v118; // [rsp+A0h] [rbp-1h] BYREF
  Scaleform::GFx::ASString uri; // [rsp+A8h] [rbp+7h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v120; // [rsp+B0h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML **p_pObject; // [rsp+B8h] [rbp+17h]
  __int64 v122; // [rsp+C0h] [rbp+1Fh]
  Scaleform::GFx::ASString v123; // [rsp+108h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v; // [rsp+118h] [rbp+77h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v125[2]; // [rsp+120h] [rbp+7Fh] BYREF

  v122 = -2i64;
  LODWORD(v6) = 0;
  v7 = 0;
  v111 = 0;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kElement);
  v8 = *((_QWORD *)userData + 10) + 1i64;
  if ( v8 >= *((_QWORD *)userData + 10) )
  {
    if ( v8 <= *((_QWORD *)userData + 11) )
      goto LABEL_7;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= *((_QWORD *)userData + 11) >> 1 )
      goto LABEL_7;
    v9 = *((_QWORD *)userData + 10) + 1i64;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)userData
  + 3,
    *((__int64 **)userData + 12),
    v9);
LABEL_7:
  *((_QWORD *)userData + 10) = v8;
  *(_DWORD *)(*((_QWORD *)userData + 9) + 4 * v8 - 4) = 1;
  pNode = v123.pNode;
  v112.pNode = (Scaleform::GFx::ASStringNode *)v123.pNode->pManager;
  pManager = (Scaleform::GFx::ASStringNode *)v112.pNode[3].pManager;
  v113.Message.pNode = pManager;
  pLower = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)pManager->pLower;
  *(_QWORD *)&v113.ID = pLower;
  v13 = pManager[1].pManager;
  v112.pNode = (Scaleform::GFx::ASStringNode *)&v114;
  memset(&v114, 0, sizeof(v114));
  pheapAddr = v13;
  LODWORD(v14) = 0;
  if ( atts->pData )
  {
    while ( 1 )
    {
      v15 = (const char *)*((_QWORD *)&atts->pData + (unsigned int)v14);
      v16 = -1i64;
      do
        ++v16;
      while ( v15[v16] );
      if ( v16 && *v15 == LOBYTE(pNode->pData) )
        break;
      if ( v16 > 4 && *v15 == 120 && v15[1] == 109 && v15[2] == 108 && v15[3] == 110 && v15[4] == 115 )
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          pLower,
          &result);
        if ( v16 > 5 && v15[5] == LOBYTE(v123.pNode->pData) )
        {
          v17 = v15 + 6;
          v18 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID;
          v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID,
                  &v118,
                  v17);
          v20 = v19->pNode;
          ++v19->pNode->RefCount;
          v21 = result.pNode;
          v22 = result.pNode->RefCount-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          result.pNode = v20;
          v23 = v118.pNode;
          v22 = v118.pNode->RefCount-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        }
        else
        {
          v18 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID;
        }
        v24 = v14 + 1;
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          v18,
          &uri,
          *(&atts->pData + v24));
        v25 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)*((_QWORD *)v113.Message.pNode[12].pData + 25);
        v26 = 10;
        prefix.Flags = 10;
        prefix.Bonus.pWeakProxy = 0i64;
        v27 = result.pNode;
        *(Scaleform::GFx::ASString *)&prefix.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
        if ( result.pNode == &result.pNode->pManager->NullStringNode )
        {
          v27 = 0i64;
          prefix.value.VS._1.VStr = 0i64;
          VObj = v113.Message.pNode;
          prefix.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v113.Message.pNode;
          v26 = 12;
          prefix.Flags = 12;
        }
        else
        {
          ++result.pNode->RefCount;
          VObj = (Scaleform::GFx::ASStringNode *)prefix.value.VS._2.VObj;
        }
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(v25, &v120, NS_Public, &uri, &prefix);
        if ( (v26 & 0x1Fu) > 9 )
        {
          switch ( v26 & 0x1F )
          {
            case 0xA:
              v22 = v27->RefCount-- == 1;
              if ( v22 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v27);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              if ( prefix.value.VS._1.VBool )
              {
                prefix.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)v27 - 1);
              }
              else if ( v27 )
              {
                Size = v27->Size;
                if ( (Size & 0x3FFFFF) != 0 )
                {
                  v27->Size = Size - 1;
                  v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v27;
                  goto LABEL_42;
                }
              }
              break;
            case 0x10:
            case 0x11:
              if ( ((__int64)prefix.value.VS._2.VObj & 1) != 0 )
              {
                prefix.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj[-1].Size + 7);
              }
              else if ( VObj )
              {
                v31 = VObj->Size;
                if ( (v31 & 0x3FFFFF) != 0 )
                {
                  VObj->Size = v31 - 1;
                  v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)VObj;
LABEL_42:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
                }
              }
              break;
            default:
              break;
          }
        }
        pV = v120.pV;
        v112.pNode = (Scaleform::GFx::ASStringNode *)v120.pV;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &v114,
          pheapAddr,
          v114.Size + 1);
        v33 = &v114.Data[v114.Size - 1];
        p_pObject = &v33->pObject;
        *(_QWORD *)&v113.ID = v33;
        if ( v33 )
        {
          v33->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)pV;
          if ( pV )
            pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( pV )
        {
          if ( ((unsigned __int8)pV & 1) != 0 )
          {
            v112.pNode = (Scaleform::GFx::ASStringNode *)((char *)&pV[-1].Prefix.value.VS._2.pTraits + 7);
          }
          else
          {
            RefCount = pV->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              pV->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
            }
          }
        }
        v35 = uri.pNode;
        v22 = uri.pNode->RefCount-- == 1;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        v36 = result.pNode;
        v22 = result.pNode->RefCount-- == 1;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        pNode = v123.pNode;
        pLower = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID;
        atts = v.pNode;
      }
      else
      {
        v24 = v14 + 1;
      }
      v14 = v24 + 1;
      if ( !*((_QWORD *)&atts->pData + v14) )
      {
        pManager = v113.Message.pNode;
        goto LABEL_63;
      }
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v113, 1084, (Scaleform::GFx::AS3::VM *)v113.Message.pNode);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v113.Message.pNode,
      v37,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v38 = v113.Message.pNode;
    v22 = v113.Message.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    goto LABEL_61;
  }
LABEL_63:
  v39 = strchr(name, SLOBYTE(pNode->pData));
  if ( v39 == name )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v113, 1084, (Scaleform::GFx::AS3::VM *)pManager);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)pManager,
      v40,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v41 = v113.Message.pNode;
    v22 = v113.Message.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v41);
LABEL_61:
    XML_StopParser(v123.pNode->pLower, 0i64);
    goto LABEL_178;
  }
  v42 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID,
    (Scaleform::GFx::ASString *)&v114);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID,
    &n);
  if ( v39 )
  {
    v46 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v42,
            &v112,
            name,
            v39 - name);
    v47 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v46->pNode;
    ++v46->pNode->RefCount;
    Data = (Scaleform::GFx::ASStringNode *)v114.Data;
    v22 = LODWORD(v114.Data[3].pObject)-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(Data);
    v114.Data = v47;
    v49 = v112.pNode;
    v22 = v112.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v49);
    v50 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v42,
            &v112,
            v39 + 1);
    v51 = v50->pNode;
    ++v50->pNode->RefCount;
    v52 = n.pNode;
    v22 = n.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v52);
    n.pNode = v51;
  }
  else
  {
    v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v42,
            &v112,
            name);
    v44 = v43->pNode;
    ++v43->pNode->RefCount;
    v45 = n.pNode;
    v22 = n.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v45);
    n.pNode = v44;
  }
  v53 = v112.pNode;
  v22 = v112.pNode->RefCount-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  v54 = v114.Size;
  v55 = 0i64;
  if ( v114.Size )
  {
    while ( 1 )
    {
      pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v114.Data[v55].pObject;
      v58 = 0;
      if ( (pObject->Prefix.Flags & 0x1F) == 10 )
      {
        v57 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> **)Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
                                                                                       &pObject->Prefix,
                                                                                       &v112);
        v7 |= 1u;
        v111 = v7;
        if ( *v57 == v114.Data )
          v58 = 1;
      }
      if ( (v7 & 1) != 0 )
      {
        v7 &= ~1u;
        v111 = v7;
        v59 = v112.pNode;
        v22 = v112.pNode->RefCount-- == 1;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v59);
      }
      if ( v58 )
        break;
      if ( ++v55 >= v54 )
      {
        v54 = v114.Size;
        goto LABEL_92;
      }
    }
    v60 = v123.pNode;
    goto LABEL_106;
  }
LABEL_92:
  v60 = v123.pNode;
  v61 = *(_QWORD *)&v123.pNode->RefCount;
  if ( v61 )
  {
    pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(*(__int64 (__fastcall **)(__int64, Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD))(*(_QWORD *)v61 + 376i64))(
                                                                 v61,
                                                                 &v114,
                                                                 0i64);
    if ( pObject )
      goto LABEL_106;
    v54 = v114.Size;
  }
  if ( LODWORD(v114.Data[4].pObject) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v113, 1083, (Scaleform::GFx::AS3::VM *)v113.Message.pNode);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v113.Message.pNode,
      v101,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v102 = v113.Message.pNode;
    v22 = v113.Message.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v102);
    XML_StopParser(v60->pLower, 0i64);
    goto LABEL_174;
  }
  pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v113.Message.pNode[16].pData;
  if ( pObject )
  {
    v62 = 0i64;
    if ( v54 )
    {
      while ( v114.Data[v62].pObject->Text.pNode != pObject->Uri.pNode )
      {
        if ( ++v62 >= v54 )
          goto LABEL_102;
      }
      pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v114.Data[v62].pObject;
    }
    else
    {
LABEL_102:
      v63 = *(_QWORD *)&v60->RefCount;
      if ( v63 )
      {
        v64 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)v63 + 384i64))(
                v63,
                &pObject->Uri,
                0i64);
        if ( v64 )
          pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v64;
      }
    }
  }
  else
  {
    pObject = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v113.Message.pNode[10].RefCount;
  }
LABEL_106:
  p_RefCount = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v60->RefCount;
  v118.pNode = (Scaleform::GFx::ASStringNode *)&v60->RefCount;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v112.pNode,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v112,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)v112.pNode,
    pObject,
    &n,
    *(Scaleform::GFx::AS3::Instances::fl::XML **)&v60->RefCount);
  v66 = v112.pNode;
  v125[0] = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v112.pNode;
  if ( *(_QWORD *)&v60->RefCount
    && (*(unsigned int (__fastcall **)(_QWORD))(**(_QWORD **)&v60->RefCount + 208i64))(*(_QWORD *)&v60->RefCount) == 1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*p_RefCount)->vfptr[7].Finalize_GC)(
      *p_RefCount,
      v125);
  }
  else
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v60->Size,
      v60[1].pLower,
      (unsigned __int64)(v60[1].pData + 1));
    v67 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*(_QWORD *)&v60->Size + 8 * (__int64)(v60[1].pData - 1));
    *(_QWORD *)&v113.ID = v67;
    p_pObject = (Scaleform::GFx::AS3::Instances::fl::XML **)v67;
    if ( v67 )
    {
      *v67 = v125[0];
      v68 = v125[0];
      if ( v125[0] )
      {
        ++v125[0]->RefCount;
        v68->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  v69 = v114.Size;
  for ( i = 0i64; i < v69; ++i )
  {
    v71 = &v114.Data[i];
    if ( ((__int64)v71->pObject[1].vfptr & 0x1F) == 10 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v66[2],
        &v66[2],
        (unsigned __int64)&v66[2].pManager->vfptr + 1);
      v72 = (Scaleform::GFx::AS3::Instances::fl::XML **)&v66[2].pData[8
                                                                    * ((__int64)&v66[2].pManager[-1].FileName.HeapTypeBits
                                                                     + 7)];
      *(_QWORD *)&v113.ID = v72;
      p_pObject = v72;
      if ( v72 )
      {
        v73 = v71->pObject;
        *v72 = v71->pObject;
        if ( v73 )
          v73->RefCount = (v73->RefCount + 1) & 0x8FBFFFFF;
      }
    }
  }
  v74 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)&v113.ID,
    (Scaleform::GFx::ASString *)&p);
  v75 = v.pNode;
  if ( v.pNode->pData )
  {
    v76 = v123.pNode;
    do
    {
      v77 = *((_QWORD *)&v75->pData + (unsigned int)v6);
      v78 = -1i64;
      do
        ++v78;
      while ( *(_BYTE *)(v77 + v78) );
      if ( v78 > 4
        && *(_BYTE *)v77 == 120
        && *(_BYTE *)(v77 + 1) == 109
        && *(_BYTE *)(v77 + 2) == 108
        && *(_BYTE *)(v77 + 3) == 110
        && *(_BYTE *)(v77 + 4) == 115 )
      {
        v79 = v6 + 1;
      }
      else
      {
        v80 = strchr(*(&v75->pData + (unsigned int)v6), SLOBYTE(v76->pData));
        v79 = v6 + 1;
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          v74,
          &v,
          *(&v75->pData + v79));
        if ( v80 )
        {
          Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v74,
            &v123,
            (const char *)v77,
            (unsigned __int64)&v80[-v77]);
          v86 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  v74,
                  &v112,
                  v80 + 1);
          v87 = (Scaleform::GFx::AS3::Instances::fl::XML *)v86->pNode;
          ++v86->pNode->RefCount;
          v88 = (Scaleform::GFx::ASStringNode *)p;
          v22 = LODWORD(p->pPrev)-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v88);
          p = v87;
          v89 = v112.pNode;
          v22 = v112.pNode->RefCount-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v89);
          v85 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::ASString *, _QWORD))v125[0]->vfptr[15].Finalize_GC)(
                                                                   v125[0],
                                                                   &v123,
                                                                   0i64);
          if ( !v85 )
            v85 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v113.Message.pNode[10].RefCount;
          v90 = v123.pNode;
          v22 = v123.pNode->RefCount-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v90);
        }
        else
        {
          v81 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  v74,
                  &v112,
                  (const char *)v77);
          v82 = (Scaleform::GFx::AS3::Instances::fl::XML *)v81->pNode;
          ++v81->pNode->RefCount;
          v83 = (Scaleform::GFx::ASStringNode *)p;
          v22 = LODWORD(p->pPrev)-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v83);
          p = v82;
          v84 = v112.pNode;
          v22 = v112.pNode->RefCount-- == 1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v84);
          v85 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v113.Message.pNode[10].RefCount;
        }
        v91 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
                                                                 (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v66[1].pData,
                                                                 (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)&v113,
                                                                 (Scaleform::GFx::AS3::InstanceTraits::Traits *)v66[1].pData,
                                                                 v85,
                                                                 (Scaleform::GFx::ASString *)&p,
                                                                 &v,
                                                                 (Scaleform::GFx::AS3::Instances::fl::XML *)v66)->pV;
        v120.pV = v91;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v66[2].RefCount,
          &v66[2].RefCount,
          *(_QWORD *)&v66[2].Size + 1i64);
        v92 = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)&v66[2].RefCount + 8 * (*(_QWORD *)&v66[2].Size - 1i64));
        p_pObject = (Scaleform::GFx::AS3::Instances::fl::XML **)v92;
        uri.pNode = v92;
        if ( v92 )
        {
          v92->pData = (const char *)v91;
          if ( v91 )
            v91->RefCount = (v91->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v91 )
        {
          if ( ((unsigned __int8)v91 & 1) != 0 )
          {
            v120.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v91 - 1);
          }
          else
          {
            v93 = v91->RefCount;
            if ( (v93 & 0x3FFFFF) != 0 )
            {
              v91->RefCount = v93 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v91);
            }
          }
        }
        v94 = v.pNode;
        v22 = v.pNode->RefCount-- == 1;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v94);
      }
      v6 = v79 + 1;
    }
    while ( *((_QWORD *)&v75->pData + v6) );
    p_RefCount = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v118.pNode;
  }
  if ( v125 != p_RefCount )
  {
    v95 = v125[0];
    if ( v125[0] )
    {
      ++v125[0]->RefCount;
      v95->RefCount &= 0x8FBFFFFF;
      v95 = v125[0];
    }
    v96 = *p_RefCount;
    if ( *p_RefCount )
    {
      if ( ((unsigned __int8)v96 & 1) != 0 )
      {
        *p_RefCount = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v96 - 1);
      }
      else
      {
        v97 = v96->RefCount;
        if ( (v97 & 0x3FFFFF) != 0 )
        {
          v96->RefCount = v97 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v96);
          v95 = v125[0];
        }
      }
    }
    *p_RefCount = v95;
  }
  v98 = (Scaleform::GFx::ASStringNode *)p;
  v22 = LODWORD(p->pPrev)-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v98);
  v99 = v125[0];
  if ( v125[0] )
  {
    if ( ((__int64)v125[0] & 1) != 0 )
    {
      --v125[0];
    }
    else
    {
      v100 = v125[0]->RefCount;
      if ( (v100 & 0x3FFFFF) != 0 )
      {
        v125[0]->RefCount = v100 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v99);
      }
    }
  }
LABEL_174:
  v103 = n.pNode;
  v22 = n.pNode->RefCount-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v103);
  v104 = (Scaleform::GFx::ASStringNode *)v114.Data;
  v22 = LODWORD(v114.Data[3].pObject)-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v104);
LABEL_178:
  v123.pNode = (Scaleform::GFx::ASStringNode *)&v114;
  v105 = v114.Size;
  for ( j = &v114.Data[v114.Size - 1]; v105; --v105 )
  {
    v107 = j->pObject;
    if ( j->pObject )
    {
      if ( ((unsigned __int8)v107 & 1) != 0 )
      {
        j->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v107 - 1);
      }
      else
      {
        v108 = v107->RefCount;
        if ( (v108 & 0x3FFFFF) != 0 )
        {
          v107->RefCount = v108 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v107);
        }
      }
    }
    --j;
  }
  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 628
// RVA: 0x7C8E90
void __fastcall Scaleform::GFx::AS3::XMLParser::EndElementExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *name)
{
  __int64 *p_pCurrElem; // rdi
  __int64 v5; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int RefCount; // eax
  const char *v9; // rax
  const char *v10; // r8
  int v11; // ecx
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kElement);
  Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &userData->KindStack.Data,
    userData->KindStack.Data.Size - 1);
  p_pCurrElem = (__int64 *)&userData->pCurrElem;
  while ( *p_pCurrElem )
  {
    v5 = *p_pCurrElem;
    v6 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*p_pCurrElem + 64);
    if ( !v6 )
      break;
    v15 = *(_QWORD *)(*p_pCurrElem + 64);
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
    if ( &v15 != p_pCurrElem )
    {
      v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*p_pCurrElem;
      if ( *p_pCurrElem )
      {
        if ( ((unsigned __int8)v7 & 1) != 0 )
        {
          *p_pCurrElem = (__int64)&v7[-1].RefCount + 7;
        }
        else
        {
          RefCount = v7->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v7->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
          }
        }
      }
      *p_pCurrElem = (__int64)v6;
    }
    v9 = **(const char ***)(v5 + 56);
    v10 = (const char *)(name - v9);
    do
    {
      v11 = (unsigned __int8)v10[(_QWORD)v9];
      v12 = *(unsigned __int8 *)v9 - v11;
      if ( v12 )
        break;
      ++v9;
    }
    while ( v11 );
    if ( !v12 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        v15 = (__int64)&v6[-1].RefCount + 7;
      }
      else
      {
        v14 = v6->RefCount;
        if ( (v14 & 0x3FFFFF) != 0 )
        {
          v6->RefCount = v14 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
      return;
    }
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      v15 = (__int64)&v6[-1].RefCount + 7;
    }
    else
    {
      v13 = v6->RefCount;
      if ( (v13 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
}

// File Line: 657
// RVA: 0x7B3580
void __fastcall Scaleform::GFx::AS3::XMLParser::CharacterDataExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *s,
        int len)
{
  unsigned __int64 v4; // rdi

  v4 = len;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kText);
  Scaleform::GFx::ASString::Append(&userData->Text, s, v4);
}

// File Line: 668
// RVA: 0x7B7730
void __fastcall Scaleform::GFx::AS3::XMLParser::CommentExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *data)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *ITr; // rsi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLComment *pV; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::ASStringNode *v14; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> v20; // [rsp+78h] [rbp+20h] BYREF

  ITr = userData->ITr;
  StringManagerRef = ITr->pVM->StringManagerRef;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kComment);
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         StringManagerRef,
         &result,
         data);
  p_pObject = &userData->pCurrElem.pObject;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
         ITr,
         &v20,
         ITr,
         v6,
         userData->pCurrElem.pObject)->pV;
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v18 = pV;
  if ( *p_pObject
    && ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))(*p_pObject)->vfptr[8].Finalize_GC)(*p_pObject) == 1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*p_pObject)->vfptr[7].Finalize_GC)(
      *p_pObject,
      &v18);
  }
  else
  {
    if ( &v18 != p_pObject )
    {
      v11 = v18;
      if ( v18 )
      {
        ++v18->RefCount;
        v11->RefCount &= 0x8FBFFFFF;
        v11 = v18;
      }
      v12 = *p_pObject;
      if ( *p_pObject )
      {
        if ( ((unsigned __int8)v12 & 1) != 0 )
        {
          *p_pObject = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v12 - 1);
        }
        else
        {
          RefCount = v12->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v12->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
            v11 = v18;
          }
        }
      }
      *p_pObject = v11;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &userData->RootElements.Data,
      userData->RootElements.Data.pHeap,
      userData->RootElements.Data.Size + 1);
    v14 = (Scaleform::GFx::ASStringNode *)&userData->RootElements.Data.Data[userData->RootElements.Data.Size - 1];
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
    if ( ((unsigned __int8)v18 & 1) != 0 )
    {
      v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v18 - 1);
    }
    else
    {
      v17 = v18->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        v18->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
}

// File Line: 700
// RVA: 0x7C01B0
void __fastcall Scaleform::GFx::AS3::XMLParser::DeclExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *version,
        const char *encoding,
        int standalone)
{
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kInstruction);
}

// File Line: 740
// RVA: 0x8217C0
void __fastcall Scaleform::GFx::AS3::XMLParser::StartDoctypeDeclExpatCallback(
        char *userData,
        const char *doctypeName,
        const char *sysid,
        const char *pubid)
{
  unsigned __int64 v4; // rax
  __int64 *v5; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  __int64 v8; // rax

  v4 = *((_QWORD *)userData + 10);
  v5 = (__int64 *)(userData + 72);
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
      *((__int64 **)userData + 12),
      v7);
  }
  v8 = *v5;
  v5[1] = v6;
  *(_DWORD *)(v8 + 4 * v6 - 4) = 6;
}

// File Line: 748
// RVA: 0x7C8E80
void __fastcall Scaleform::GFx::AS3::XMLParser::EndDoctypeDeclExpatCallback(char *userData)
{
  Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataDH<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)(userData + 72),
    *((_QWORD *)userData + 10) - 1i64);
}

// File Line: 758
// RVA: 0x80A290
void __fastcall Scaleform::GFx::AS3::XMLParser::ProcessingInstructionExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *target,
        const char *data)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *ITr; // rbp
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rdi
  Scaleform::GFx::ASString *v; // rbx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *pV; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::ASStringNode *v18; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-38h] BYREF
  __int64 v23; // [rsp+38h] [rbp-30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> v24; // [rsp+40h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+88h] [rbp+20h] BYREF

  v23 = -2i64;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kAttr|kText);
  ITr = userData->ITr;
  StringManagerRef = ITr->pVM->StringManagerRef;
  v = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        StringManagerRef,
        &result,
        data);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         StringManagerRef,
         &v26,
         target);
  p_pObject = &userData->pCurrElem.pObject;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(
         ITr,
         &v24,
         ITr,
         v9,
         v,
         userData->pCurrElem.pObject)->pV;
  pNode = v26.pNode;
  v13 = v26.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v14 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v25 = pV;
  if ( *p_pObject
    && ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))(*p_pObject)->vfptr[8].Finalize_GC)(*p_pObject) == 1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*p_pObject)->vfptr[7].Finalize_GC)(
      *p_pObject,
      &v25);
  }
  else
  {
    if ( &v25 != p_pObject )
    {
      v15 = v25;
      if ( v25 )
      {
        ++v25->RefCount;
        v15->RefCount &= 0x8FBFFFFF;
        v15 = v25;
      }
      v16 = *p_pObject;
      if ( *p_pObject )
      {
        if ( ((unsigned __int8)v16 & 1) != 0 )
        {
          *p_pObject = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v16 - 1);
        }
        else
        {
          RefCount = v16->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v16->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
            v15 = v25;
          }
        }
      }
      *p_pObject = v15;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &userData->RootElements.Data,
      userData->RootElements.Data.pHeap,
      userData->RootElements.Data.Size + 1);
    v18 = (Scaleform::GFx::ASStringNode *)&userData->RootElements.Data.Data[userData->RootElements.Data.Size - 1];
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
    XML_StopParser(userData->Parser, v18);
  }
  v20 = v25;
  if ( v25 )
  {
    if ( ((unsigned __int8)v25 & 1) != 0 )
    {
      v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v25 - 1);
    }
    else
    {
      v21 = v25->RefCount;
      if ( (v21 & 0x3FFFFF) != 0 )
      {
        v25->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
}

// File Line: 805
// RVA: 0x78A660
void __fastcall Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::~EmptyCallBack(
        Scaleform::GFx::AS3::Instances::fl::EmptyCallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

// File Line: 820
// RVA: 0x789760
void __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::~AttrGetFirst(
        Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable;
  pObject = this->First.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

// File Line: 827
// RVA: 0x7B2770
char __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::Call(
        Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *this,
        unsigned __int64 ind)
{
  if ( !this->First.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->First,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->Element->Attrs.Data.Data[ind].pObject);
  return 1;
}

// File Line: 846
// RVA: 0x789EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::~ChildGetFirst(
        Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable;
  pObject = this->First.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

// File Line: 853
// RVA: 0x7B2820
char __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::Call(
        Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this,
        unsigned __int64 ind)
{
  if ( !this->First.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->First,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->Element->Children.Data.Data[ind].pObject);
  return 1;
}

// File Line: 872
// RVA: 0x789E90
void __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGet::~ChildGet(
        Scaleform::GFx::AS3::Instances::fl::ChildGet *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

// File Line: 880
// RVA: 0x7B27A0
char __fastcall Scaleform::GFx::AS3::Instances::fl::ChildGet::Call(
        Scaleform::GFx::AS3::Instances::fl::ChildGet *this,
        unsigned __int64 ind)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *List; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx

  v2 = &this->Element->Children.Data.Data[ind];
  List = this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&List->List,
    &List->List,
    List->List.Data.Size + 1);
  v4 = &List->List.Data.Data[List->List.Data.Size - 1];
  if ( v4 )
  {
    pObject = v2->pObject;
    v4->pObject = v2->pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
  return 1;
}

// File Line: 893
// RVA: 0x789730
void __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGet::~AttrGet(
        Scaleform::GFx::AS3::Instances::fl::AttrGet *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

// File Line: 901
// RVA: 0x7B26B0
char __fastcall Scaleform::GFx::AS3::Instances::fl::AttrGet::Call(
        Scaleform::GFx::AS3::Instances::fl::AttrGet *this,
        unsigned __int64 ind)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *List; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // rdx
  unsigned int RefCount; // eax

  pObject = this->Element->Attrs.Data.Data[ind].pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  List = this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&List->List,
    &List->List,
    List->List.Data.Size + 1);
  v4 = &List->List.Data.Data[List->List.Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) == 0 )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return 1;
}

// File Line: 913
// RVA: 0x785310
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rbx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  v9 = p;
  this->Parent.pObject = p;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::`vftable;
  this->Ns.pObject = 0i64;
  this->Namespaces.Data.Data = 0i64;
  this->Namespaces.Data.Size = 0i64;
  this->Namespaces.Data.Policy.Capacity = 0i64;
  this->Attrs.Data.Data = 0i64;
  this->Attrs.Data.Size = 0i64;
  this->Attrs.Data.Policy.Capacity = 0i64;
  p = (Scaleform::GFx::AS3::Instances::fl::XML *)&this->Children;
  this->Children.Data.Data = 0i64;
  this->Children.Data.Size = 0i64;
  this->Children.Data.Policy.Capacity = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&p,
    NS_Public,
    &ns->Uri,
    &ns->Prefix);
  pObject = this->Ns.pObject;
  v11 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)p;
  if ( p != (Scaleform::GFx::AS3::Instances::fl::XML *)pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->Ns.pObject = v11;
  }
}

// File Line: 918
// RVA: 0x78FED0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::~XMLElement(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::`vftable;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>(&this->Attrs.Data);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Namespaces);
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::XML::~XML(this);
}

// File Line: 922
// RVA: 0x7D6F00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 Size; // r15
  unsigned __int64 v7; // rbx
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v9; // rdx
  unsigned __int64 v10; // r15
  unsigned __int64 j; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v12; // rdx
  unsigned __int64 v13; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v14; // rdx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->Parent.pObject )
    op(prcc, &this->Parent.pObject);
  if ( this->Ns.pObject )
    op(prcc, &this->Ns.pObject);
  Size = this->Namespaces.Data.Size;
  v7 = 0i64;
  for ( i = 0i64; i < Size; ++i )
  {
    v9 = &this->Namespaces.Data.Data[i];
    if ( v9->pObject )
      op(prcc, &v9->pObject);
  }
  v10 = this->Attrs.Data.Size;
  for ( j = 0i64; j < v10; ++j )
  {
    v12 = &this->Attrs.Data.Data[j];
    if ( v12->pObject )
      op(prcc, &v12->pObject);
  }
  v13 = this->Children.Data.Size;
  if ( v13 )
  {
    do
    {
      v14 = &this->Children.Data.Data[v7];
      if ( v14->pObject )
        op(prcc, &v14->pObject);
      ++v7;
    }
    while ( v7 < v13 );
  }
}

// File Line: 952
// RVA: 0x7EA3A0
Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetInScopeNamespaces(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  return &this->Namespaces;
}

// File Line: 957
// RVA: 0x7ACC80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddInScopeNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Value *prefix; // r12
  Scaleform::GFx::ASString *v5; // rax
  char v6; // bl
  Scaleform::GFx::ASStringNode *pNode; // r14
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned __int64 v11; // r15
  unsigned __int64 Size; // rbp
  unsigned __int64 v13; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // rdi
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rdx
  unsigned __int64 v17; // r15
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rcx
  Scaleform::GFx::AS3::Value *v20; // rbp
  unsigned int v21; // eax
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::GFx::ASStringNode *v23; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [rsp+A8h] [rbp+20h]

  prefix = &ns->Prefix;
  if ( (ns->Prefix.Flags & 0x1F) != 0 )
  {
    if ( (ns->Prefix.Flags & 0x1F) == 10 )
    {
      v5 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(prefix, (Scaleform::GFx::ASString *)&v23);
      v6 = 1;
    }
    else
    {
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &result);
      v6 = 2;
    }
    pNode = v5->pNode;
    v24 = pNode;
    ++pNode->RefCount;
    if ( (v6 & 2) != 0 )
    {
      v6 &= ~2u;
      v8 = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    if ( (v6 & 1) != 0 )
    {
      v10 = v23;
      v9 = v23->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    if ( pNode->Size || this->Ns.pObject->Uri.pNode->Size )
    {
      v11 = -1i64;
      Size = this->Namespaces.Data.Size;
      v13 = 0i64;
      if ( Size )
      {
        Data = this->Namespaces.Data.Data;
        while ( !Scaleform::GFx::AS3::StrictEqual(prefix, &Data->pObject->Prefix) )
        {
          ++v13;
          ++Data;
          if ( v13 >= Size )
            goto LABEL_19;
        }
        v11 = v13;
      }
LABEL_19:
      Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&result,
        NS_Public,
        &ns->Uri,
        prefix);
      v15 = result.pNode;
      v23 = result.pNode;
      if ( v11 != -1i64 && this->Namespaces.Data.Data[v11].pObject->Uri.pNode != ns->Uri.pNode )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Namespaces,
          v11);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Namespaces,
        &this->Namespaces,
        this->Namespaces.Data.Size + 1);
      v16 = (Scaleform::GFx::ASStringNode *)&this->Namespaces.Data.Data[this->Namespaces.Data.Size - 1];
      result.pNode = v16;
      if ( v16 )
      {
        v16->pData = (const char *)v15;
        if ( v15 )
          v15->Size = (v15->Size + 1) & 0x8FBFFFFF;
      }
      if ( Scaleform::GFx::AS3::StrictEqual(&this->Ns.pObject->Prefix, prefix) )
      {
        if ( (_S11_12 & 1) == 0 )
        {
          _S11_12 |= 1u;
          v.Flags = 0;
          v.Bonus.pWeakProxy = 0i64;
          atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
        }
        Scaleform::GFx::AS3::Value::Assign(&this->Ns.pObject->Prefix, &v);
      }
      v17 = this->Attrs.Data.Size;
      for ( i = 0i64; i < v17; ++i )
      {
        pObject = this->Attrs.Data.Data[i].pObject;
        v20 = (Scaleform::GFx::AS3::Value *)(((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *))pObject->vfptr[11].~RefCountBaseGC<328>)(pObject)
                                           + 72);
        if ( Scaleform::GFx::AS3::StrictEqual(v20, prefix) )
        {
          if ( (_S11_12 & 1) == 0 )
          {
            _S11_12 |= 1u;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0i64;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          Scaleform::GFx::AS3::Value::Assign(v20, &v);
        }
      }
      if ( v15 )
      {
        if ( ((unsigned __int8)v15 & 1) != 0 )
        {
          v23 = (Scaleform::GFx::ASStringNode *)((char *)v15 - 1);
        }
        else
        {
          v21 = v15->Size;
          if ( (v21 & 0x3FFFFF) != 0 )
          {
            v15->Size = v21 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
          }
        }
      }
    }
    v9 = pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1011
// RVA: 0x7B08E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *child)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // r8
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx

  p_Children = &this->Children;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    this->Children.Data.Size + 1);
  v4 = &p_Children->Data.Data[p_Children->Data.Size - 1];
  if ( v4 )
  {
    pObject = child->pObject;
    v4->pObject = child->pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
}

// File Line: 1016
// RVA: 0x7B08B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *child)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, unsigned __int64, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
    this,
    result,
    this->Children.Data.Size,
    child);
  return result;
}

// File Line: 1021
// RVA: 0x7E5FD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetAttributes(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 v4; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v7; // rdx
  unsigned int RefCount; // eax

  Size = this->Attrs.Data.Size;
  v4 = 0i64;
  if ( Size )
  {
    p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&list->List;
    do
    {
      pObject = this->Attrs.Data.Data[v4].pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        p_List,
        p_List,
        p_List->Size + 1);
      v7 = &p_List->Data[p_List->Size - 1];
      if ( v7 )
      {
        v7->pObject = pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( pObject && ((unsigned __int8)pObject & 1) == 0 )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      ++v4;
    }
    while ( v4 < Size );
  }
}

// File Line: 1029
// RVA: 0x7E6AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::Instances::fl::XML::Kind k,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  bool v9; // r14
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rdi
  int v13; // eax

  if ( k )
  {
    v9 = 1;
    if ( name )
    {
      pNode = name->pNode;
      if ( name->pNode->Size )
      {
        if ( *pNode->pData != pattern[0] || *((_BYTE *)pNode->pData + 1) )
          v9 = 0;
      }
    }
    Size = this->Children.Data.Size;
    for ( i = 0i64; i < Size; ++i )
    {
      pObject = this->Children.Data.Data[i].pObject;
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[8].Finalize_GC)(pObject);
      if ( v13 == k
        && (v13 != 4
         || !name
         || v9
         || *(Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[10].ForEachChild_GC)(pObject) == name->pNode) )
      {
        Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, pObject);
      }
    }
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &list->List,
      &this->Children);
  }
}

// File Line: 1059
// RVA: 0x7E69D0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildIndex(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 *ind)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // r9
  unsigned __int64 v5; // r10
  __int64 v6; // rcx

  pObject = this->Parent.pObject;
  if ( pObject && (v5 = (unsigned __int64)pObject[1].Parent.pObject, *ind = 0i64, v5) )
  {
    while ( 1 )
    {
      v6 = *ind;
      if ( *((Scaleform::GFx::AS3::Instances::fl::XMLElement **)&pObject[1].Text.pNode->pData + *ind) == this )
        break;
      *ind = v6 + 1;
      if ( v6 + 1 >= v5 )
        goto LABEL_5;
    }
    result->Result = 1;
    return result;
  }
  else
  {
LABEL_5:
    result->Result = 0;
    return result;
  }
}

// File Line: 1089
// RVA: 0x826750
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToString(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *buf,
        unsigned int ident)
{
  unsigned __int64 v6; // rbx
  unsigned __int64 Size; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rdi

  v6 = 0i64;
  if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(this) )
  {
    Size = this->Children.Data.Size;
    if ( Size )
    {
      do
      {
        pObject = this->Children.Data.Data[v6].pObject;
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[8].Finalize_GC)(pObject) == 2 )
          pObject->vfptr[8].ForEachChild_GC(
            pObject,
            buf,
            (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))ident);
        ++v6;
      }
      while ( v6 < Size );
    }
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::RefCountCollector<328> *, _QWORD, _QWORD, _QWORD))this->vfptr[8].~RefCountBaseGC<328>)(
      this,
      buf,
      ident,
      0i64,
      0i64);
  }
}

// File Line: 1151
// RVA: 0x826BB0
Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXMLString

// File Line: 1463
// RVA: 0x815C30
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ResolveNamespaces(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *nr,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *pTable; // r11
  __int64 v10; // r8
  unsigned __int64 v11; // r9
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // r10
  __int64 v16; // rdx
  unsigned __int64 *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned __int64 Size; // rbp
  unsigned __int64 v20; // rbx
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v22; // rcx
  unsigned __int64 v23; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v24; // rcx
  Scaleform::GFx::ASString key; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  pObject = this->Ns.pObject;
  if ( (pObject->Prefix.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&pObject->Prefix, &result);
    key.pNode = result.pNode;
    ++result.pNode->RefCount;
    pNode = result.pNode;
    v8 = result.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[15].Finalize_GC)(
            this,
            &key,
            lp) )
    {
      pTable = nr->pTable;
      v10 = 8i64;
      v11 = 5381i64;
      if ( !nr->pTable )
        goto LABEL_26;
      v12 = 8i64;
      v13 = 5381i64;
      do
      {
        --v12;
        v14 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + v12);
        v13 = v14;
      }
      while ( v12 );
      v15 = v14 & pTable->SizeMask;
      v16 = v15;
      v17 = &pTable[v15 + 1].EntryCount + v15;
      if ( *v17 == -2i64 || v17[1] != v15 )
        goto LABEL_26;
      while ( v17[1] != v15 || (Scaleform::GFx::ASStringNode *)v17[2] != key.pNode )
      {
        v16 = *v17;
        if ( *v17 == -1i64 )
          goto LABEL_16;
        v17 = &pTable[v16 + 1].EntryCount + v16;
      }
      if ( v16 < 0
        || !(Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)&pTable[v16 + 2] + 8 * v16) )
      {
LABEL_26:
        do
        {
LABEL_16:
          --v10;
          v11 = *((unsigned __int8 *)&key.pNode + v10) + 65599 * v11;
        }
        while ( v10 );
        Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
          nr,
          nr->pHeap,
          &key,
          v11);
      }
    }
    v18 = key.pNode;
    v8 = key.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  Size = this->Attrs.Data.Size;
  v20 = 0i64;
  for ( i = 0i64; i < Size; ++i )
  {
    v22 = this->Attrs.Data.Data[i].pObject;
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *, Scaleform::GFx::AS3::Instances::fl::XML *))v22->vfptr[16].~RefCountBaseGC<328>)(
      v22,
      nr,
      lp);
  }
  v23 = this->Children.Data.Size;
  if ( v23 )
  {
    do
    {
      v24 = this->Children.Data.Data[v20].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *, Scaleform::GFx::AS3::Instances::fl::XML *))v24->vfptr[16].~RefCountBaseGC<328>)(
        v24,
        nr,
        lp);
      ++v20;
    }
    while ( v20 < v23 );
  }
}

// File Line: 1484
// RVA: 0x8120F0
Scaleform::GFx::AS3::Instances::fl::XMLElement *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::RemoveNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Value *ns)
{
  unsigned __int64 v4; // rbp
  Scaleform::GFx::AS3::Instances::fl::Namespace *VStr; // rbx
  Scaleform::GFx::AS3::Value::V1U v6; // rcx
  Scaleform::GFx::ASString *v7; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 v10; // rax
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rcx
  __int64 v13; // rax
  unsigned __int64 v14; // rsi
  unsigned __int64 Size; // r15
  void (__fastcall *v16)(Scaleform::GFx::AS3::RefCountBaseGC<328> *); // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v20; // rcx
  unsigned int v21; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v23; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h] BYREF

  v4 = 0i64;
  VStr = 0i64;
  if ( (ns->Flags & 0x1F) == 11 )
  {
    v6 = ns->value.VS._1;
    if ( v6.VStr )
    {
      v6.VStr->Size = (v6.VStr->Size + 1) & 0x8FBFFFFF;
      VStr = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v6.VStr;
    }
  }
  else
  {
    v7 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(ns, &result);
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
      (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
      &v23,
      NS_Private,
      v7,
      &v);
    if ( v23.pV )
      VStr = v23.pV;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v10 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *))this->vfptr[10].~RefCountBaseGC<328>)(this);
  if ( *(Scaleform::GFx::ASStringNode **)(v10 + 56) == VStr->Uri.pNode
    && ((*((_BYTE *)VStr + 40) ^ *(_BYTE *)(v10 + 40)) & 0xF) == 0 )
  {
    goto LABEL_34;
  }
  for ( i = 0i64; i < this->Attrs.Data.Size; ++i )
  {
    pObject = this->Attrs.Data.Data[i].pObject;
    v13 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *))pObject->vfptr[10].~RefCountBaseGC<328>)(pObject);
    if ( *(Scaleform::GFx::ASStringNode **)(v13 + 56) == VStr->Uri.pNode
      && ((*((_BYTE *)VStr + 40) ^ *(_BYTE *)(v13 + 40)) & 0xF) == 0 )
    {
      goto LABEL_34;
    }
  }
  v14 = 0i64;
  Size = this->Namespaces.Data.Size;
  if ( !Size )
    goto LABEL_32;
  v23.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->Namespaces.Data.Data;
  v16 = (void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))VStr->Uri.pNode;
  pV = v23.pV;
  while ( pV->vfptr[2].~RefCountBaseGC<328> != v16 )
  {
LABEL_22:
    ++v14;
    pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV + 8);
    if ( v14 >= Size )
      goto LABEL_32;
  }
  if ( (VStr->Prefix.Flags & 0x1F) != 0
    && !Scaleform::GFx::AS3::StrictEqual(&VStr->Prefix, (Scaleform::GFx::AS3::Value *)&pV->vfptr[3]) )
  {
    v16 = (void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))VStr->Uri.pNode;
    goto LABEL_22;
  }
  if ( Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Namespaces,
      &this->Namespaces,
      0i64);
  }
  else
  {
    v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*((_QWORD *)&v23.pV->vfptr + v14);
    if ( v18 )
    {
      if ( ((unsigned __int8)v18 & 1) != 0 )
      {
        *((_QWORD *)&v23.pV->vfptr + v14) = (char *)v18 - 1;
      }
      else
      {
        RefCount = v18->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v18->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
        }
      }
    }
    memmove(
      &this->Namespaces.Data.Data[v14],
      &this->Namespaces.Data.Data[v14 + 1],
      8 * (this->Namespaces.Data.Size - v14) - 8);
    --this->Namespaces.Data.Size;
  }
LABEL_32:
  if ( this->Children.Data.Size )
  {
    do
    {
      v20 = this->Children.Data.Data[v4].pObject;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))v20->vfptr[16].Finalize_GC)(
        v20,
        ns);
      ++v4;
    }
    while ( v4 < this->Children.Data.Size );
  }
LABEL_34:
  if ( ((unsigned __int8)VStr & 1) == 0 )
  {
    v21 = VStr->RefCount;
    if ( (v21 & 0x3FFFFF) != 0 )
    {
      VStr->RefCount = v21 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
    }
  }
  return this;
}

// File Line: 1521
// RVA: 0x7AB270
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pV; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v6; // rdx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> result; // [rsp+48h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v9; // [rsp+50h] [rbp-18h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v10; // [rsp+58h] [rbp-10h]

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &result,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         ns,
         n,
         v,
         this)->pV;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Attrs.Data,
    &this->Attrs,
    this->Attrs.Data.Size + 1);
  v6 = &this->Attrs.Data.Data[this->Attrs.Data.Size - 1];
  v9 = v6;
  v10 = v6;
  if ( v6 )
  {
    v6->pObject = pV;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( pV && ((unsigned __int8)pV & 1) == 0 )
  {
    RefCount = pV->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pV->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}

// File Line: 1528
// RVA: 0x7C94A0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  __int64 v4; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r9
  Scaleform::GFx::AS3::Traits *Size; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // r14
  unsigned __int64 v9; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *Data; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v11; // r11
  __int64 v12; // r10
  __int64 *i; // r9
  __int64 v14; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rbx
  Scaleform::GFx::AS3::Value::Extra v18; // rdi
  Scaleform::GFx::AS3::Value::Extra v19; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::Value::V1U v21; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v22; // rax
  Scaleform::GFx::AS3::Value::V1U v23; // rcx
  bool v24; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::Value l; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value r; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *v33; // [rsp+C0h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+58h] BYREF

  v4 = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(this, other);
  if ( (_DWORD)v4 )
    return v4;
  vfptr = other[1].vfptr;
  pObject = this->Ns.pObject;
  if ( pObject->Uri.pNode != (Scaleform::GFx::ASStringNode *)vfptr[2].~RefCountBaseGC<328> )
    return 2i64;
  if ( ((LOBYTE(vfptr[1].Finalize_GC) ^ *((_BYTE *)pObject + 40)) & 0xF) != 0 )
    return 2i64;
  Size = (Scaleform::GFx::AS3::Traits *)this->Attrs.Data.Size;
  if ( Size != other[1].pTraits.pObject )
    return 2i64;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XML *)this->Children.Data.Size;
  v33 = v8;
  if ( v8 != other[1].Parent.pObject )
    return 2i64;
  v9 = 0i64;
  if ( !Size )
    goto LABEL_21;
  Data = this->Attrs.Data.Data;
  do
  {
    v11 = Data->pObject;
    v12 = 0i64;
    for ( i = *(__int64 **)&other[1].RefCount; ; ++i )
    {
      v14 = *i;
      if ( Data->pObject->Text.pNode == *(Scaleform::GFx::ASStringNode **)(*i + 56) )
      {
        v15 = v11->Ns.pObject;
        if ( v15 )
        {
          v16 = *(_QWORD *)(v14 + 72);
          if ( !v16
            || v15->Uri.pNode != *(Scaleform::GFx::ASStringNode **)(v16 + 56)
            || ((*(_BYTE *)(v16 + 40) ^ *((_BYTE *)v15 + 40)) & 0xF) != 0 )
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
      if ( ++v12 >= (unsigned __int64)Size )
        return 2i64;
    }
    ++v9;
    ++Data;
  }
  while ( v9 < (unsigned __int64)Size );
  v8 = v33;
LABEL_21:
  v17 = 0i64;
  if ( !v8 )
    return 1i64;
  v18.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)l.Bonus;
  v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)l.Bonus;
  while ( 1 )
  {
    pNode = other[1].Text.pNode;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0i64;
    v21 = (Scaleform::GFx::AS3::Value::V1U)*(&pNode->pData + v17);
    r.Flags = 12;
    r.value.VS._1 = v21;
    r.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.pWeakProxy;
    if ( v21.VStr )
      v21.VStr->Size = (v21.VStr->Size + 1) & 0x8FBFFFFF;
    v22 = this->Children.Data.Data;
    l.Flags = 0;
    l.Bonus.pWeakProxy = 0i64;
    v23 = (Scaleform::GFx::AS3::Value::V1U)v22[v17].pObject;
    l.Flags = 12;
    l.value.VS._1 = v23;
    l.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v19.pWeakProxy;
    if ( v23.VStr )
      v23.VStr->Size = (v23.VStr->Size + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::AbstractEqual(&result, (bool *)&v33, &l, &r);
    if ( (l.Flags & 0x1F) > 9 )
    {
      if ( (l.Flags & 0x200) != 0 )
      {
        v24 = l.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v24 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&l.Bonus, 0, 24);
        l.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( l.Flags & 0x1F )
        {
          case 0xA:
            VStr = l.value.VS._1.VStr;
            v24 = l.value.VS._1.VStr->RefCount-- == 1;
            if ( v24 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            VObj = l.value.VS._1.VObj;
            if ( !l.value.VS._1.VBool )
              goto LABEL_39;
            --l.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            VObj = l.value.VS._2.VObj;
            if ( ((__int64)l.value.VS._2.VObj & 1) != 0 )
            {
              --l.value.VS._2.VObj;
            }
            else
            {
LABEL_39:
              if ( VObj )
              {
                RefCount = VObj->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  VObj->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
      {
        v24 = r.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v24 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&r.Bonus, 0, 24);
        r.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( r.Flags & 0x1F )
        {
          case 0xA:
            v28 = r.value.VS._1.VStr;
            v24 = r.value.VS._1.VStr->RefCount-- == 1;
            if ( v24 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v28);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            v29 = r.value.VS._1.VObj;
            if ( !r.value.VS._1.VBool )
              goto LABEL_54;
            --r.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            v29 = r.value.VS._2.VObj;
            if ( ((__int64)r.value.VS._2.VObj & 1) != 0 )
            {
              --r.value.VS._2.VObj;
            }
            else
            {
LABEL_54:
              if ( v29 )
              {
                v30 = v29->RefCount;
                if ( (v30 & 0x3FFFFF) != 0 )
                {
                  v29->RefCount = v30 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( !(_BYTE)v33 )
      return 2i64;
    if ( ++v17 >= (unsigned __int64)v8 )
      return 1i64;
  }
}

// File Line: 1590
// RVA: 0x800C50
_BOOL8 __fastcall Scaleform::GFx::AS3::Instances::fl::XML::Matches(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  bool v4; // bl
  Scaleform::GFx::ASStringNode **v5; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rdi
  $CBB44125B27995AEB5908B7872D4CF4F *p_Uri; // rdi
  Scaleform::GFx::AS3::VM *v11; // r14
  __int64 v12; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rbp
  Scaleform::GFx::AS3::GASRefCountBase *v14; // rdx
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // r9
  unsigned __int64 v16; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rdx
  __int64 v18; // rax
  bool v19; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v4 = 0;
  if ( (prop_name->Name.Flags & 0x1F) != 10 )
    return v4;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name->Name, &result);
  v5 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[10].ForEachChild_GC)(this);
  if ( *v5 == result.pNode || Scaleform::GFx::AS3::Multiname::IsAnyType(prop_name) )
  {
    Kind = prop_name->Kind;
    if ( (prop_name->Kind & 3u) <= 1 )
    {
      if ( prop_name->Obj.pObject )
      {
        pObject = prop_name->Obj.pObject;
        pVM = this->pTraits.pObject->pVM;
        v9 = pVM->DefXMLNamespace.pObject;
        if ( !v9 )
          v9 = pVM->PublicNamespace.pObject;
        p_Uri = ($CBB44125B27995AEB5908B7872D4CF4F *)&v9->Uri;
        if ( !((int)(LODWORD(pObject[1].vfptr) << 28) >> 28) && ((Kind & 8) != 0 || pObject[1].pNext->RefCount) )
          p_Uri = &pObject[1].16;
        if ( p_Uri->pNext == *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[10].~RefCountBaseGC<328>)(this)
                                                                          + 56) )
          v4 = 1;
      }
      else
      {
        v4 = 1;
      }
      goto LABEL_32;
    }
    if ( Scaleform::GFx::AS3::Multiname::IsAnyType(prop_name) )
      goto LABEL_16;
    v11 = this->pTraits.pObject->pVM;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[10].~RefCountBaseGC<328>)(this);
    if ( (prop_name->Kind & 8) != 0 || (v13 = v11->DefXMLNamespace.pObject) == 0i64 )
      v13 = v11->PublicNamespace.pObject;
    if ( !Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, v11->PublicNamespace.pObject) )
    {
      if ( v13->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v12 + 56) )
        v4 = ((*(_BYTE *)(v12 + 40) ^ *((_BYTE *)v13 + 40)) & 0xF) == 0;
      goto LABEL_32;
    }
    v14 = prop_name->Obj.pObject;
    pRCC = v14[1]._pRCC;
    v16 = 0i64;
    if ( pRCC )
    {
      vfptr = v14[1].vfptr;
      while ( 1 )
      {
        if ( !((int)(*((_DWORD *)vfptr->ForEachChild_GC + 10) << 28) >> 28) )
        {
          v18 = *((_QWORD *)vfptr->ForEachChild_GC + 7);
          v19 = *(_DWORD *)(v18 + 32)
              ? v18 == *(_QWORD *)(v12 + 56)
              : v13->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v12 + 56);
          if ( v19 )
            break;
        }
        ++v16;
        vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)vfptr + 8);
        if ( v16 >= (unsigned __int64)pRCC )
          goto LABEL_32;
      }
LABEL_16:
      v4 = 1;
    }
  }
LABEL_32:
  pNode = result.pNode;
  v19 = result.pNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v4;
}

// File Line: 1696
// RVA: 0x7F2B40
char __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned __int64 Size; // rdi
  __int64 v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx

  Size = this->Children.Data.Size;
  v2 = 0i64;
  if ( !Size )
    return 1;
  while ( 1 )
  {
    pObject = this->Children.Data.Data[v2].pObject;
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[8].Finalize_GC)(pObject) == 1 )
      break;
    if ( ++v2 >= Size )
      return 1;
  }
  return 0;
}

// File Line: 1709
// RVA: 0x7F2550
bool __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasOwnProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::ASString *p)
{
  char v4; // si
  int v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *Element; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r8
  int v9; // r14d
  const char *pData; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  unsigned __int64 Size; // rsi
  unsigned __int64 i; // rbx
  bool v16; // zf
  bool v17; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+28h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value v19; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString v22; // [rsp+E0h] [rbp+77h] BYREF

  if ( !p->pNode->Size )
    return 0;
  cb.Element = this;
  cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable;
  v4 = 10;
  v19.Flags = 10;
  v5 = 0;
  v19.Bonus.pWeakProxy = 0i64;
  pNode = p->pNode;
  v19.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    v19.value.VS._1.VStr = 0i64;
    Element = cb.Element;
    v19.value.VS._2.VObj = cb.Element;
    v4 = 12;
    v19.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    Element = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v19.value.VS._2.VObj;
  }
  pObject = this->pTraits.pObject->pVM->PublicNamespace.pObject;
  prop_name.Kind = MN_QName;
  prop_name.Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  prop_name.Name.Flags = 0;
  prop_name.Name.Bonus.pWeakProxy = 0i64;
  v9 = v4 & 0x1F;
  if ( (unsigned int)(v9 - 12) <= 3
    && pNode
    && (pData = pNode[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    prop_name.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v19, 2);
    *(_QWORD *)&prop_name.Name.Flags = *(_QWORD *)&v19.Flags;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    prop_name.Name.value.VS._1.VStr = pNode;
    prop_name.Name.value.VS._2.VObj = Element;
    if ( (v4 & 0x1Fu) > 9 )
    {
      if ( v9 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v4 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v4 & 0x1Fu) <= 0x11 && Element )
      {
        Element->RefCount = (Element->RefCount + 1) & 0x8FBFFFFF;
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
          v16 = v22.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        }
      }
      v13 = result.pNode;
      v16 = result.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
  if ( (v4 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  if ( (prop_name.Kind & 8) != 0 )
  {
    if ( (prop_name.Name.Flags & 0x1F) == 10 )
    {
      Size = this->Attrs.Data.Size;
      for ( i = 0i64; i < Size; ++i )
      {
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[i].pObject, &prop_name) )
        {
          ++v5;
          if ( !cb.vfptr->Call(&cb, i) )
            break;
        }
      }
    }
    v16 = v5 == 0;
  }
  else
  {
    v16 = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, &prop_name, &cb) == 0;
  }
  v17 = !v16;
  Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  return v17;
}

// File Line: 1727
// RVA: 0x7C0280
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *pObject; // r14
  unsigned __int64 Size; // r13
  unsigned __int64 v6; // r12
  unsigned __int64 v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *i; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v9; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v10; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v11; // rdx
  unsigned int RefCount; // eax
  unsigned __int64 v13; // r13
  unsigned __int64 j; // rbp
  Scaleform::GFx::AS3::Class *v15; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v16; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v19; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v20; // rdx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rbp
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::Resource *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v29; // rdx
  unsigned int v30; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v31; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v32; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v33; // [rsp+98h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+A8h] [rbp+20h] BYREF

  v33 = result;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
    pObject,
    &v32,
    pObject,
    this->Ns.pObject,
    &this->Text,
    parent);
  Size = this->Attrs.Data.Size;
  v6 = 0i64;
  v7 = 0i64;
  for ( i = v32.pV; v7 < Size; ++v7 )
  {
    v9 = this->Attrs.Data.Data[v7].pObject;
    v10 = *(Scaleform::GFx::AS3::Instances::fl::XMLElement **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v9->vfptr[11].Finalize_GC)(
                                                                v9,
                                                                &resulta,
                                                                i);
    v32.pV = v10;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &i->Attrs.Data,
      &i->Attrs,
      i->Attrs.Data.Size + 1);
    v11 = &i->Attrs.Data.Data[i->Attrs.Data.Size - 1];
    if ( v11 )
    {
      v11->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)v10;
      if ( v10 )
        v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( v10 )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        v32.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v10 - 1);
      }
      else
      {
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
  }
  v13 = this->Children.Data.Size;
  for ( j = 0i64; j < v13; ++j )
  {
    if ( !pObject->pConstructor.pObject )
      pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
    v15 = pObject->pConstructor.pObject;
    v16 = this->Children.Data.Data[j].pObject;
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v16->vfptr[8].Finalize_GC)(v16) != 3
      || !LOBYTE(v15[1].vfptr) )
    {
      v17 = this->Children.Data.Data[j].pObject;
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v17->vfptr[8].Finalize_GC)(v17) != 4
        || !BYTE1(v15[1].vfptr) )
      {
        v18 = this->Children.Data.Data[j].pObject;
        v19 = *(Scaleform::GFx::AS3::Instances::fl::XMLElement **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v18->vfptr[11].Finalize_GC)(
                                                                    v18,
                                                                    &resulta,
                                                                    i);
        v32.pV = v19;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&i->Children,
          &i->Children,
          i->Children.Data.Size + 1);
        v20 = &i->Children.Data.Data[i->Children.Data.Size - 1];
        if ( v20 )
        {
          v20->pObject = v19;
          if ( v19 )
            v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v19 )
        {
          if ( ((unsigned __int8)v19 & 1) != 0 )
          {
            v32.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v19 - 1);
          }
          else
          {
            v21 = v19->RefCount;
            if ( (v21 & 0x3FFFFF) != 0 )
            {
              v19->RefCount = v21 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
            }
          }
        }
      }
    }
  }
  if ( this->Namespaces.Data.Size )
  {
    do
    {
      pV = Scaleform::GFx::AS3::VM::MakeNamespace(this->pTraits.pObject->pVM, &resulta, NS_Public)->pV;
      v32.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)pV;
      v23 = this->Namespaces.Data.Data[v6].pObject;
      if ( pV != v23 )
      {
        Scaleform::GFx::AS3::Value::Assign(&pV->Prefix, &v23->Prefix);
        pNode = v23->Uri.pNode;
        ++pNode->RefCount;
        v25 = pV->Uri.pNode;
        if ( v25->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        pV->Uri.pNode = pNode;
        *((_QWORD *)pV + 5) ^= (*((_DWORD *)pV + 10) ^ *((_DWORD *)v23 + 10)) & 0xF;
        v27 = (Scaleform::GFx::Resource *)v23->pFactory.pObject;
        if ( v27 )
          Scaleform::Render::RenderBuffer::AddRef(v27);
        v28 = (Scaleform::Render::RenderBuffer *)pV->pFactory.pObject;
        if ( v28 )
          Scaleform::RefCountImpl::Release(v28);
        pV->pFactory.pObject = v23->pFactory.pObject;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&i->Namespaces,
        &i->Namespaces,
        i->Namespaces.Data.Size + 1);
      v29 = &i->Namespaces.Data.Data[i->Namespaces.Data.Size - 1];
      if ( v29 )
      {
        v29->pObject = pV;
        if ( pV )
          pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( pV )
      {
        if ( ((unsigned __int8)pV & 1) != 0 )
        {
          v32.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)&pV[-1].Prefix.value.VS._2.pTraits + 7);
        }
        else
        {
          v30 = pV->RefCount;
          if ( (v30 & 0x3FFFFF) != 0 )
          {
            pV->RefCount = v30 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
          }
        }
      }
      ++v6;
    }
    while ( v6 < this->Namespaces.Data.Size );
  }
  v31 = v33;
  v33->pV = i;
  return v31;
}

// File Line: 1765
// RVA: 0x7E6A20
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned int v6; // [rsp+20h] [rbp-48h] BYREF
  __int64 v7; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLList *v9; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult v10; // [rsp+88h] [rbp+20h] BYREF

  v7 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&v10, prop_name, &v6)->Result )
  {
    if ( v6 <= this->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this->Children.Data.Data[v6].pObject);
  }
  else
  {
    cb.Element = this;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable;
    v9 = list;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, prop_name, &cb);
  }
}

// File Line: 1781
// RVA: 0x81B070
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v7; // r14
  void *pVM; // rsi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v9; // r15
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::CheckResult *v13; // rax
  unsigned int v14; // edi
  unsigned int v15; // edx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  const char *pData; // rax
  unsigned __int64 v18; // rcx
  int v19; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int Flags; // ecx
  Scaleform::GFx::ASStringNode *v25; // rcx
  int v26; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v27; // rdi
  const char *v28; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // rsi
  unsigned __int64 v30; // rbx
  __int64 v31; // rcx
  char *v32; // r8
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  const char *v35; // rax
  unsigned int v36; // ecx
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v39; // rbx
  __int64 v40; // rdi
  unsigned int *v41; // rdx
  unsigned int RefCount; // eax
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
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int v55; // eax
  _DWORD *v56; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v58; // edx
  const char *v59; // rax
  const char *v60; // rax
  char IsAnyType; // al
  unsigned __int64 Size; // r13
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *p_Children; // r12
  unsigned __int64 v64; // r15
  Scaleform::GFx::AS3::Multiname *v65; // r14
  unsigned __int64 v66; // r12
  bool v67; // r13
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v68; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v69; // r15
  Scaleform::GFx::ASStringNode *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rbx
  Scaleform::GFx::ASStringNode *v72; // rcx
  bool v73; // r12
  bool *v74; // r14
  unsigned int v75; // eax
  Scaleform::GFx::ASStringNode *v76; // rcx
  unsigned int v77; // eax
  Scaleform::GFx::ASStringNode *v78; // rbx
  bool v79; // r14
  Scaleform::GFx::ASStringNode *v80; // rcx
  bool v81; // r15
  unsigned int v82; // eax
  Scaleform::GFx::ASStringNode *v83; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+8h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value valuea; // [rsp+10h] [rbp-71h] BYREF
  unsigned int ind[2]; // [rsp+30h] [rbp-51h] BYREF
  Scaleform::GFx::ASString v; // [rsp+38h] [rbp-49h] BYREF
  Scaleform::StringBuffer other; // [rsp+40h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value v89; // [rsp+70h] [rbp-11h] BYREF
  Scaleform::GFx::ASString v90; // [rsp+90h] [rbp+Fh] BYREF
  __int64 v91; // [rsp+98h] [rbp+17h]
  Scaleform::GFx::ASString n; // [rsp+E8h] [rbp+67h] BYREF
  bool *v93; // [rsp+F0h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *prop_namea; // [rsp+F8h] [rbp+77h]

  v91 = -2i64;
  v7 = this;
  pVM = this->pTraits.pObject->pVM;
  v.pNode = (Scaleform::GFx::ASStringNode *)pVM;
  v9 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)*((_QWORD *)pVM + 2);
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v89, 1087, (Scaleform::GFx::AS3::VM *)pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)pVM,
      v10,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v89.Bonus.pWeakProxy;
    v12 = LODWORD(v89.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    result->Result = 0;
    return result;
  }
  v14 = 0;
  valuea.Flags = 0;
  valuea.Bonus.pWeakProxy = 0i64;
  v15 = value->Flags & 0x1F;
  if ( v15 - 12 <= 3 )
  {
    VStr = value->value.VS._1.VStr;
    if ( VStr )
    {
      pData = VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
      {
        v18 = *(_QWORD *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, unsigned int *, _QWORD))VStr->pData
                          + 35))(
                           VStr,
                           ind,
                           0i64);
        other.Size = 0i64;
        LODWORD(other.pData) = 12;
        other.BufferSize = v18;
        other.GrowSize = (unsigned __int64)v89.Bonus.pWeakProxy;
        Scaleform::GFx::AS3::Value::Assign(&valuea, (Scaleform::GFx::AS3::Value *)&other);
        goto LABEL_10;
      }
    }
  }
  if ( v15 - 12 <= 3 )
  {
    v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)value->value.VS._1.VStr;
    if ( v20 )
    {
      pObject = v20->pTraits.pObject;
      if ( pObject->TraitsType == Traits_XMLList && (pObject->Flags & 0x20) == 0 )
      {
        pV = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(
               v20,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)ind,
               0i64)->pV;
        other.Size = 0i64;
        LODWORD(other.pData) = 12;
        other.BufferSize = (unsigned __int64)pV;
        other.GrowSize = (unsigned __int64)v89.Bonus.pWeakProxy;
        Scaleform::GFx::AS3::Value::Assign(&valuea, (Scaleform::GFx::AS3::Value *)&other);
LABEL_10:
        v19 = (int)other.pData;
        if ( (unsigned __int64)((__int64)other.pData & 0x1F) > 9 )
        {
          if ( ((__int64)other.pData & 0x200) != 0 )
          {
            v12 = (*(_DWORD *)other.Size)-- == 1;
            if ( v12 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Size, 0, 24);
            LODWORD(other.pData) = v19 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other);
          }
        }
        goto LABEL_42;
      }
    }
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    v9,
    (Scaleform::GFx::ASString *)ind);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(value, &resulta, (Scaleform::GFx::ASString *)ind)->Result )
  {
    result->Result = 0;
    v23 = *(Scaleform::GFx::ASStringNode **)ind;
    v12 = (*(_DWORD *)(*(_QWORD *)ind + 24i64))-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    if ( (valuea.Flags & 0x1F) <= 9 )
      return result;
    if ( (valuea.Flags & 0x200) != 0 )
    {
      v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_28;
    }
LABEL_29:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
    return result;
  }
  Flags = valuea.Flags;
  if ( (valuea.Flags & 0x1F) > 9 )
  {
    if ( (valuea.Flags & 0x200) != 0 )
    {
      v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&valuea.Bonus, 0, 24);
      Flags = valuea.Flags & 0xFFFFFDE0;
      valuea.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
      Flags = valuea.Flags;
    }
  }
  v12 = *(_QWORD *)ind == *(_QWORD *)(*(_QWORD *)ind + 8i64) + 104i64;
  valuea.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v89.Bonus.pWeakProxy;
  if ( v12 )
  {
    valuea.value.VS._1.VStr = 0i64;
    valuea.Flags = Flags & 0xFFFFFFE0 | 0xC;
  }
  else
  {
    valuea.Flags = Flags & 0xFFFFFFE0 | 0xA;
    valuea.value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)ind;
    ++*(_DWORD *)(*(_QWORD *)ind + 24i64);
  }
  v25 = *(Scaleform::GFx::ASStringNode **)ind;
  v12 = (*(_DWORD *)(*(_QWORD *)ind + 24i64))-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
LABEL_42:
  if ( (prop_name->Kind & 8) == 0 )
  {
    v56 = 0i64;
    other.Size = 0i64;
    LODWORD(other.pData) = 0;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v9, &v90);
    *(_QWORD *)ind = &prop_name->Name;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(&prop_name->Name, &resulta, &v90)->Result )
    {
      result->Result = 0;
      pNode = v90.pNode;
      v12 = v90.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (valuea.Flags & 0x1F) <= 9 )
        return result;
      if ( (valuea.Flags & 0x200) != 0 )
      {
        v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_28;
      }
      goto LABEL_29;
    }
    v58 = valuea.Flags & 0x1F;
    if ( (unsigned int)(v58 - 12) <= 3
      && valuea.value.VS._1.VStr
      && (v59 = valuea.value.VS._1.VStr[1].pData, *((_DWORD *)v59 + 30) == 18)
      && (v59[112] & 0x20) == 0
      || (unsigned int)(v58 - 12) <= 3
      && valuea.value.VS._1.VStr
      && (v60 = valuea.value.VS._1.VStr[1].pData, *((_DWORD *)v60 + 30) == 19)
      && (v60[112] & 0x20) == 0
      || (IsAnyType = Scaleform::GFx::AS3::Multiname::IsAnyType(prop_name), resulta.Result = 1, IsAnyType) )
    {
      resulta.Result = 0;
    }
    Size = v7->Children.Data.Size;
    if ( Size )
    {
      p_Children = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&v7->Children;
      v64 = Size - 1;
      v65 = prop_namea;
      do
      {
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(p_Children->Data.Data[v64].pObject, v65) )
        {
          if ( (v14 & 0x1F) != 0 )
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
              p_Children,
              SLODWORD(other.BufferSize));
          if ( (v14 & 0x1F) > 9 )
          {
            if ( (v14 & 0x200) != 0 )
            {
              v12 = (*v56)-- == 1;
              if ( v12 )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v56);
              v56 = 0i64;
              memset(&other.Size, 0, 24);
              v14 &= 0xFFFFFDE0;
              LODWORD(other.pData) = v14;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other);
              v56 = (_DWORD *)other.Size;
              v14 = (unsigned int)other.pData;
            }
          }
          v14 = v14 & 0xFFFFFFE0 | 2;
          LODWORD(other.pData) = v14;
          v89.Flags = v64;
          *(_OWORD *)&other.BufferSize = *(_OWORD *)&v89.Flags;
        }
        --v64;
        --Size;
      }
      while ( Size );
      v7 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)n.pNode;
    }
    if ( (v14 & 0x1F) != 0 )
    {
      v67 = resulta.Result;
    }
    else
    {
      v66 = v7->Children.Data.Size;
      v14 = v14 & 0xFFFFFFE0 | 2;
      LODWORD(other.pData) = v14;
      v89.Flags = v66;
      *(_OWORD *)&other.BufferSize = *(_OWORD *)&v89.Flags;
      v67 = resulta.Result;
      if ( !resulta.Result )
        goto LABEL_208;
      v68 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject;
      if ( (prop_namea->Kind & 3u) <= 1 && prop_namea->Obj.pObject )
      {
        v69 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)prop_namea->Obj.pObject;
        v70 = v.pNode;
      }
      else
      {
        v70 = v.pNode;
        v69 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v.pNode[16].pData;
      }
      if ( !v69 )
        v69 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v70[10].RefCount;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(*(Scaleform::GFx::AS3::Value **)ind, &n);
      v71 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                              v68,
                                              (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v89,
                                              v68,
                                              v69,
                                              &n,
                                              v7)->pV;
      v.pNode = v71;
      v72 = n.pNode;
      v12 = n.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v72);
      v89.Bonus.pWeakProxy = 0i64;
      v89.Flags = 12;
      v89.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)v71;
      if ( v71 )
        v71->Size = (v71->Size + 1) & 0x8FBFFFFF;
      v73 = !Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
               v7,
               (Scaleform::GFx::AS3::CheckResult *)&n,
               (int)v66,
               &v89)->Result;
      if ( (v89.Flags & 0x1F) > 9 )
      {
        if ( (v89.Flags & 0x200) != 0 )
        {
          v12 = v89.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v89.Bonus, 0, 24);
          v89.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v89);
        }
      }
      if ( v73 )
      {
        v74 = v93;
        *v93 = 0;
        if ( v71 )
        {
          if ( ((unsigned __int8)v71 & 1) != 0 )
          {
            v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v71 - 1);
          }
          else
          {
            v75 = v71->Size;
            if ( (v75 & 0x3FFFFF) != 0 )
            {
              v71->Size = v75 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v71);
            }
          }
        }
        v76 = v90.pNode;
        v12 = v90.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v76);
        if ( (v14 & 0x1F) <= 9 )
          goto LABEL_217;
        if ( (v14 & 0x200) != 0 )
        {
          v12 = (*v56)-- == 1;
          if ( v12 )
          {
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v56);
            memset(&other.Size, 0, 24);
            LODWORD(other.pData) = v14 & 0xFFFFFDE0;
LABEL_217:
            if ( (valuea.Flags & 0x1F) > 9 )
            {
              if ( (valuea.Flags & 0x200) != 0 )
              {
                v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v12 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&valuea.Bonus, 0, 24);
                valuea.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
              }
            }
            return (Scaleform::GFx::AS3::CheckResult *)v74;
          }
LABEL_215:
          memset(&other.Size, 0, 24);
          LODWORD(other.pData) = v14 & 0xFFFFFDE0;
          goto LABEL_217;
        }
        goto LABEL_216;
      }
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v71->pData
       + 21))(
        v71,
        v69);
      if ( ((unsigned __int8)v71 & 1) != 0 )
      {
        v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v71 - 1);
      }
      else
      {
        v77 = v71->Size;
        if ( (v77 & 0x3FFFFF) != 0 )
        {
          v71->Size = v77 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v71);
        }
      }
    }
    if ( v67 )
    {
      v78 = (Scaleform::GFx::ASStringNode *)v7->Children.Data.Data[SLODWORD(other.BufferSize)].pObject;
      v.pNode = v78;
      if ( v78 )
        v78->Size = (v78->Size + 1) & 0x8FBFFFFF;
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, _QWORD))v78->pData + 42))(v78, 0i64);
      v79 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n)->pNode->Size != 0;
      v80 = n.pNode;
      v12 = n.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v80);
      v81 = !v79
         || (*((unsigned int (__fastcall **)(Scaleform::GFx::ASStringNode *))v78->pData + 26))(v78) != 1
         || Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
              (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v78,
              (Scaleform::GFx::AS3::CheckResult *)&n,
              0i64,
              &valuea)->Result;
      if ( ((unsigned __int8)v78 & 1) != 0 )
      {
        v.pNode = (Scaleform::GFx::ASStringNode *)((char *)v78 - 1);
      }
      else
      {
        v82 = v78->Size;
        if ( (v82 & 0x3FFFFF) != 0 )
        {
          v78->Size = v82 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v78);
        }
      }
LABEL_209:
      v74 = v93;
      *v93 = v81;
      v83 = v90.pNode;
      v12 = v90.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v83);
      if ( (v14 & 0x1F) <= 9 )
        goto LABEL_217;
      if ( (v14 & 0x200) != 0 )
      {
        v12 = (*v56)-- == 1;
        if ( v12 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v56);
        goto LABEL_215;
      }
LABEL_216:
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other);
      goto LABEL_217;
    }
LABEL_208:
    v81 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
            v7,
            (Scaleform::GFx::AS3::CheckResult *)&n,
            SLODWORD(other.BufferSize),
            &valuea)->Result;
    goto LABEL_209;
  }
  v26 = valuea.Flags & 0x1F;
  v27 = (Scaleform::GFx::AS3::Instances::fl::XML *)valuea.value.VS._1.VStr;
  if ( (unsigned int)(v26 - 12) <= 3
    && valuea.value.VS._1.VStr
    && (v28 = valuea.value.VS._1.VStr[1].pData, *((_DWORD *)v28 + 30) == 19)
    && (v28[112] & 0x20) == 0 )
  {
    Scaleform::StringBuffer::StringBuffer(&other, *((Scaleform::MemoryHeap **)pVM + 6));
    pNext = v27[1].pNext;
    v30 = 0i64;
    if ( pNext )
    {
      do
      {
        if ( v30 )
          Scaleform::StringBuffer::AppendChar(&other, 0x20u);
        v31 = *(_QWORD *)(v27[1].pRCCRaw + 8 * v30);
        (*(void (__fastcall **)(__int64, Scaleform::StringBuffer *, _QWORD))(*(_QWORD *)v31 + 192i64))(
          v31,
          &other,
          0i64);
        ++v30;
      }
      while ( v30 < (unsigned __int64)pNext );
    }
    v32 = &customCaption;
    if ( other.pData )
      v32 = other.pData;
    v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v9,
            &n,
            v32,
            other.Size);
    Scaleform::GFx::AS3::Value::Assign(&valuea, v33);
    v34 = n.pNode;
    v12 = n.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&other);
    pVM = v.pNode;
  }
  else
  {
    if ( (unsigned int)(v26 - 12) <= 3
      && valuea.value.VS._1.VStr
      && (v35 = valuea.value.VS._1.VStr[1].pData, *((_DWORD *)v35 + 30) == 18)
      && (v35[112] & 0x20) == 0 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v9, &n);
      Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(v27, &n);
      v36 = valuea.Flags;
      if ( (valuea.Flags & 0x1F) > 9 )
      {
        if ( (valuea.Flags & 0x200) != 0 )
        {
          v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&valuea.Bonus, 0, 24);
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
      valuea.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v89.Bonus.pWeakProxy;
      if ( v12 )
      {
        valuea.value.VS._1.VStr = 0i64;
        valuea.Flags = v36 & 0xFFFFFFE0 | 0xC;
      }
      else
      {
        valuea.Flags = v36 & 0xFFFFFFE0 | 0xA;
        *(Scaleform::GFx::ASString *)&valuea.value.VNumber = (Scaleform::GFx::ASString)n.pNode;
        ++n.pNode->RefCount;
      }
    }
    else
    {
      v37 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n);
      Scaleform::GFx::AS3::Value::Assign(&valuea, v37);
    }
    v38 = n.pNode;
    v12 = n.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  }
  v39 = 0i64;
  *(_QWORD *)ind = 0i64;
  v40 = 0i64;
  if ( v7->Attrs.Data.Size )
  {
    while ( 1 )
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(v7->Attrs.Data.Data[v40].pObject, prop_name) )
      {
        if ( v39 )
        {
          if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *))v7->vfptr[2].Finalize_GC)(
                            v7,
                            &n,
                            prop_name) )
          {
            result->Result = 0;
            if ( ((unsigned __int8)v39 & 1) != 0 )
            {
              *(_QWORD *)ind = (char *)v39 - 1;
            }
            else
            {
              RefCount = v39->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v39->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v39);
              }
            }
            if ( (valuea.Flags & 0x1F) <= 9 )
              return result;
            if ( (valuea.Flags & 0x200) == 0 )
              goto LABEL_29;
LABEL_88:
            v12 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_28:
            memset(&valuea.Bonus, 0, 24);
            valuea.Flags &= 0xFFFFFDE0;
            return result;
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
          goto LABEL_107;
        break;
      }
    }
  }
  v43 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v7->pTraits.pObject;
  if ( (prop_name->Kind & 3u) > 1 )
    v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_QWORD *)pVM + 80);
  else
    v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)prop_name->Obj.pObject;
  if ( !v44 )
    v44 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&v.pNode[10].RefCount;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &v);
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name->Name, &n);
  v45 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
          v43,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)&v89,
          v43,
          v44,
          &n,
          &v,
          v7)->pV;
  if ( v45 )
    v39 = v45;
  *(_QWORD *)ind = v39;
  v46 = n.pNode;
  v12 = n.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  v47 = v.pNode;
  v12 = v.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &v7->Attrs.Data,
    &v7->Attrs,
    v7->Attrs.Data.Size + 1);
  v48 = (Scaleform::GFx::ASStringNode *)&v7->Attrs.Data.Data[v7->Attrs.Data.Size - 1];
  n.pNode = v48;
  *(_QWORD *)&v89.Flags = v48;
  if ( v48 )
  {
    v48->pData = (const char *)v39;
    if ( v39 )
      v39->RefCount = (v39->RefCount + 1) & 0x8FBFFFFF;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::Instances::fl::Namespace *))v7->vfptr[7].ForEachChild_GC)(
    v7,
    v44);
LABEL_107:
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&valuea, &n);
  v49 = n.pNode;
  ++n.pNode->RefCount;
  v50 = v39->Data.pNode;
  v12 = v50->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  v39->Data.pNode = v49;
  v51 = n.pNode;
  v12 = n.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  result->Result = 1;
  if ( v39 )
  {
    if ( ((unsigned __int8)v39 & 1) != 0 )
    {
      *(_QWORD *)ind = (char *)v39 - 1;
    }
    else
    {
      v52 = v39->RefCount;
      if ( (v52 & 0x3FFFFF) != 0 )
      {
        v39->RefCount = v52 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v39);
      }
    }
  }
  if ( (valuea.Flags & 0x1F) <= 9 )
    return result;
  if ( (valuea.Flags & 0x200) != 0 )
    goto LABEL_88;
  switch ( valuea.Flags & 0x1F )
  {
    case 0xA:
      v53 = valuea.value.VS._1.VStr;
      v12 = valuea.value.VS._1.VStr->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v53);
      return result;
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
      VObj = valuea.value.VS._1.VObj;
      if ( !valuea.value.VS._1.VBool )
        goto LABEL_125;
      --valuea.value.VS._1.VStr;
      return result;
    case 0x10:
    case 0x11:
      VObj = valuea.value.VS._2.VObj;
      if ( ((__int64)valuea.value.VS._2.VObj & 1) != 0 )
      {
        --valuea.value.VS._2.VObj;
        return result;
      }
LABEL_125:
      if ( !VObj )
        return result;
      v55 = VObj->RefCount;
      if ( (v55 & 0x3FFFFF) == 0 )
        return result;
      VObj->RefCount = v55 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
      v13 = result;
      break;
    default:
      return result;
  }
  return v13;
}

// File Line: 1995
// RVA: 0x7EE040
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::CheckResult v9; // [rsp+20h] [rbp-58h] BYREF
  unsigned int v10; // [rsp+24h] [rbp-54h] BYREF
  __int64 v11; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack v14; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // [rsp+58h] [rbp-20h]

  v11 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&v9, prop_name, &v10)->Result )
  {
    if ( v10 < this->Children.Data.Size )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this->Children.Data.Data[v10].pObject);
    result->Result = 1;
  }
  else if ( (prop_name->Kind & 8) != 0 )
  {
    cb.Element = this;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable;
    v13 = list;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, prop_name, &cb);
    result->Result = 1;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
  }
  else
  {
    v14.Element = this;
    v14.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGet::`vftable;
    v15 = list;
    result->Result = (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, prop_name, &v14) != 0;
    v14.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
  }
  return result;
}

// File Line: 2027
// RVA: 0x7EDF90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> ind[2]; // [rsp+28h] [rbp-10h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, (unsigned int *)ind)->Result )
  {
    if ( LODWORD(ind[0].pV) )
    {
      Scaleform::GFx::AS3::Value::SetUndefined(value);
      result->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(value, this);
      result->Result = 1;
    }
  }
  else
  {
    pV = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, ind, prop_name)->pV;
    Scaleform::GFx::AS3::Value::Pick(value, pV);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *))this->vfptr[18].ForEachChild_GC)(
      this,
      result,
      prop_name,
      pV);
  }
  return result;
}

// File Line: 2056
// RVA: 0x7D1CB0
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindDynamicSlot(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *mn)
{
  unsigned __int64 v6; // rdi
  int v7; // r15d
  unsigned __int64 Size; // r12
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // rcx
  unsigned int v16; // eax
  __int64 v18[2]; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // [rsp+40h] [rbp-20h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+48h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // [rsp+58h] [rbp-8h]

  v6 = 0i64;
  if ( (mn->Kind & 8) != 0 )
  {
    v18[1] = (__int64)this;
    v18[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable;
    v19 = 0i64;
    v7 = 0;
    if ( (mn->Name.Flags & 0x1F) != 10 )
      goto LABEL_14;
    Size = this->Attrs.Data.Size;
    if ( !Size )
      goto LABEL_14;
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[v6].pObject, mn) )
      {
        ++v7;
        if ( !(*(unsigned __int8 (__fastcall **)(__int64 *, unsigned __int64))(v18[0] + 8))(v18, v6) )
          break;
      }
      ++v6;
    }
    while ( v6 < Size );
    if ( v7 )
    {
      result->pSI = (Scaleform::GFx::AS3::SlotInfo *)((unsigned __int64)v19 | 2);
      result->This.Flags = 12;
      result->This.Bonus.pWeakProxy = 0i64;
      result->This.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
      this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
      v18[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable;
      v9 = v19;
      if ( v19 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v19 - 1);
        }
        else
        {
          RefCount = v19->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v19->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
          }
        }
      }
      v18[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
    }
    else
    {
LABEL_14:
      result->pSI = 0i64;
      result->SlotIndex = 0i64;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0i64;
      v18[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable;
      v11 = v19;
      if ( v19 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v19 - 1);
        }
        else
        {
          v12 = v19->RefCount;
          if ( (v12 & 0x3FFFFF) != 0 )
          {
            v19->RefCount = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
      v18[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
    }
  }
  else
  {
    cb.Element = this;
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable;
    v21 = 0i64;
    if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, mn, &cb) )
    {
      result->pSI = (Scaleform::GFx::AS3::SlotInfo *)((unsigned __int64)v21 | 2);
      result->This.Flags = 12;
      result->This.Bonus.pWeakProxy = 0i64;
      result->This.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
      if ( this )
        this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
      cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable;
      v13 = v21;
      if ( v21 )
      {
        if ( ((unsigned __int8)v21 & 1) != 0 )
        {
          v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v21 - 1);
        }
        else
        {
          v14 = v21->RefCount;
          if ( (v14 & 0x3FFFFF) != 0 )
          {
            v21->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
    }
    else
    {
      result->pSI = 0i64;
      result->SlotIndex = 0i64;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0i64;
      cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable;
      v15 = v21;
      if ( v21 )
      {
        if ( ((unsigned __int8)v21 & 1) != 0 )
        {
          v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v21 - 1);
        }
        else
        {
          v16 = v21->RefCount;
          if ( (v16 & 0x3FFFFF) != 0 )
          {
            v21->RefCount = v16 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
      }
    }
    cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
  }
  return result;
}

// File Line: 2076
// RVA: 0x7C0E80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::CheckResult *v13; // rax

  v6 = 0i64;
  if ( (prop_name->Kind & 8) != 0 )
  {
    if ( this->Attrs.Data.Size )
    {
      do
      {
        pObject = this->Attrs.Data.Data[v6].pObject;
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(pObject, prop_name) )
        {
          v8 = pObject->Parent.pObject;
          if ( v8 )
          {
            if ( ((unsigned __int8)v8 & 1) != 0 )
            {
              pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v8 - 1);
            }
            else
            {
              RefCount = v8->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v8->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
              }
            }
            pObject->Parent.pObject = 0i64;
          }
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            &this->Attrs,
            v6);
        }
        else
        {
          ++v6;
        }
      }
      while ( v6 < this->Attrs.Data.Size );
    }
  }
  else if ( this->Children.Data.Size )
  {
    do
    {
      v10 = this->Children.Data.Data[v6].pObject;
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(v10, prop_name) )
      {
        v11 = v10->Parent.pObject;
        if ( v11 )
        {
          if ( ((unsigned __int8)v11 & 1) != 0 )
          {
            v10->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( (v12 & 0x3FFFFF) != 0 )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
            }
          }
          v10->Parent.pObject = 0i64;
        }
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
          v6);
      }
      else
      {
        ++v6;
      }
    }
    while ( v6 < this->Children.Data.Size );
  }
  v13 = result;
  result->Result = 1;
  return v13;
}

// File Line: 2181
// RVA: 0x7D4BA0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  unsigned int v3; // edi
  unsigned __int64 Size; // rsi
  unsigned __int64 i; // rbx

  v3 = 0;
  if ( (prop_name->Name.Flags & 0x1F) != 10 )
    return 0i64;
  Size = this->Attrs.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[i].pObject, prop_name) )
    {
      ++v3;
      if ( !cb->vfptr->Call(cb, i) )
        break;
    }
  }
  return v3;
}

// File Line: 2207
// RVA: 0x7D4C40
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v5; // rax
  unsigned int v6; // r12d
  unsigned __int64 Size; // rdi
  unsigned __int64 v8; // r15
  Scaleform::GFx::AS3::Value *p_Name; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rbx
  bool v11; // bp
  Scaleform::GFx::ASStringNode **v12; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v13; // rcx
  Scaleform::GFx::AS3::VM *v14; // rax
  $CBB44125B27995AEB5908B7872D4CF4F *v15; // rdi
  $CBB44125B27995AEB5908B7872D4CF4F *v16; // rdi
  Scaleform::GFx::AS3::VM *pVM; // rdi
  __int64 v18; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // rsi
  Scaleform::GFx::AS3::GASRefCountBase *v20; // r8
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // r9
  unsigned __int64 v22; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // r8
  __int64 v24; // rax
  bool v25; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-48h] BYREF
  __int64 v29; // [rsp+28h] [rbp-40h]
  unsigned __int64 v31; // [rsp+88h] [rbp+20h]

  v29 = -2i64;
  v5 = this;
  v6 = 0;
  Size = this->Children.Data.Size;
  v31 = Size;
  v8 = 0i64;
  if ( Size )
  {
    p_Name = &prop_name->Name;
    while ( 1 )
    {
      pObject = v5->Children.Data.Data[v8].pObject;
      v11 = 0;
      if ( (p_Name->Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(p_Name, &result);
        v12 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[10].ForEachChild_GC)(pObject);
        if ( *v12 == result.pNode || Scaleform::GFx::AS3::Multiname::IsAnyType(prop_name) )
        {
          if ( (prop_name->Kind & 3u) > 1 )
          {
            if ( Scaleform::GFx::AS3::Multiname::IsAnyType(prop_name) )
            {
              v11 = 1;
            }
            else
            {
              pVM = pObject->pTraits.pObject->pVM;
              v18 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[10].~RefCountBaseGC<328>)(pObject);
              if ( (prop_name->Kind & 8) != 0 || (v19 = pVM->DefXMLNamespace.pObject) == 0i64 )
                v19 = pVM->PublicNamespace.pObject;
              if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, pVM->PublicNamespace.pObject) )
              {
                v20 = prop_name->Obj.pObject;
                pRCC = v20[1]._pRCC;
                v22 = 0i64;
                if ( pRCC )
                {
                  vfptr = v20[1].vfptr;
                  while ( 1 )
                  {
                    if ( !((int)(*((_DWORD *)vfptr->ForEachChild_GC + 10) << 28) >> 28) )
                    {
                      v24 = *((_QWORD *)vfptr->ForEachChild_GC + 7);
                      v25 = *(_DWORD *)(v24 + 32)
                          ? v24 == *(_QWORD *)(v18 + 56)
                          : v19->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v18 + 56);
                      if ( v25 )
                        break;
                    }
                    ++v22;
                    vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)vfptr + 8);
                    if ( v22 >= (unsigned __int64)pRCC )
                      goto LABEL_35;
                  }
                  v11 = 1;
                }
LABEL_35:
                Size = v31;
              }
              else
              {
                Size = v31;
                if ( v19->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v18 + 56) )
                  v11 = ((*(_BYTE *)(v18 + 40) ^ *((_BYTE *)v19 + 40)) & 0xF) == 0;
              }
            }
          }
          else if ( prop_name->Obj.pObject )
          {
            v13 = prop_name->Obj.pObject;
            v14 = pObject->pTraits.pObject->pVM;
            v15 = ($CBB44125B27995AEB5908B7872D4CF4F *)v14->DefXMLNamespace.pObject;
            if ( !v15 )
              v15 = ($CBB44125B27995AEB5908B7872D4CF4F *)v14->PublicNamespace.pObject;
            v16 = v15 + 7;
            if ( !((int)(LODWORD(v13[1].vfptr) << 28) >> 28) && ((prop_name->Kind & 8) != 0 || v13[1].pNext->RefCount) )
              v16 = &v13[1].16;
            v25 = v16->pNext == *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[10].~RefCountBaseGC<328>)(pObject)
                                                                             + 56);
            Size = v31;
            if ( v25 )
              v11 = 1;
          }
          else
          {
            v11 = 1;
          }
        }
        pNode = result.pNode;
        v25 = result.pNode->RefCount-- == 1;
        if ( v25 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v11 )
        {
          ++v6;
          if ( !cb->vfptr->Call(cb, v8) )
            return v6;
        }
        p_Name = &prop_name->Name;
      }
      if ( ++v8 >= Size )
        return v6;
      v5 = this;
    }
  }
  return v6;
}

// File Line: 2235
// RVA: 0x81A840
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *ns)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // rcx

  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
    ns);
  Size = this->Attrs.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    pObject = this->Attrs.Data.Data[i].pObject;
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::GFx::AS3::Instances::fl::XMLList *))pObject->vfptr[10].Finalize_GC)(
      pObject,
      ns);
  }
}

// File Line: 2257
// RVA: 0x7E8550
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetDescendants(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned __int64 v6; // rsi
  unsigned __int64 Size; // r15
  unsigned __int64 i; // rbx
  unsigned __int64 v9; // r15
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rbx
  __int64 v11[8]; // [rsp+28h] [rbp-40h] BYREF

  v6 = 0i64;
  if ( (prop_name->Kind & 8) != 0 )
  {
    v11[1] = (__int64)this;
    v11[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::AttrGet::`vftable;
    v11[2] = (__int64)list;
    if ( (prop_name->Name.Flags & 0x1F) == 10 )
    {
      Size = this->Attrs.Data.Size;
      for ( i = 0i64; i < Size; ++i )
      {
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[i].pObject, prop_name)
          && !(*(unsigned __int8 (__fastcall **)(__int64 *, unsigned __int64))(v11[0] + 8))(v11, i) )
        {
          break;
        }
      }
    }
    v11[0] = (__int64)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
  }
  v9 = this->Children.Data.Size;
  if ( v9 )
  {
    do
    {
      pObject = this->Children.Data.Data[v6].pObject;
      if ( (prop_name->Kind & 8) == 0
        && Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Children.Data.Data[v6].pObject, prop_name) )
      {
        Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, pObject);
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Multiname *))pObject->vfptr[2].~RefCountBaseGC<328>)(
        pObject,
        list,
        prop_name);
      ++v6;
    }
    while ( v6 < v9 );
  }
}

// File Line: 2283
// RVA: 0x826A60
Scaleform::GFx::AS3::Instances::fl::XML *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Value *value)
{
  unsigned int v2; // r8d
  Scaleform::GFx::AS3::Value::V1U v3; // rcx
  const char *pData; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // rcx
  const char *v7; // rax

  v2 = value->Flags & 0x1F;
  if ( v2 - 12 <= 3 )
  {
    v3 = value->value.VS._1;
    if ( v3.VStr )
    {
      pData = v3.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
        return (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VStr;
    }
  }
  if ( v2 - 12 <= 3 )
  {
    v6 = value->value.VS._1;
    if ( v6.VStr )
    {
      v7 = v6.VStr[1].pData;
      if ( *((_DWORD *)v7 + 30) == 19
        && (v7[112] & 0x20) == 0
        && v6.VStr[2].pManager == (Scaleform::GFx::ASStringManager *)1 )
      {
        return *(Scaleform::GFx::AS3::Instances::fl::XML **)v6.VStr[2].pData;
      }
    }
  }
  return 0i64;
}

// File Line: 2300
// RVA: 0x7F29C0
bool __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        bool check_prototype)
{
  unsigned int ind; // [rsp+20h] [rbp-28h] BYREF
  __int64 v7; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack cb; // [rsp+30h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+68h] [rbp+20h] BYREF

  v7 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&result, prop_name, &ind)->Result )
    return ind == 0;
  cb.Element = this;
  cb.vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::EmptyCallBack::`vftable;
  if ( (prop_name->Kind & 8) != 0 )
    return (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(this, prop_name, &cb) != 0;
  else
    return (unsigned int)Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(this, prop_name, &cb) != 0;
}

// File Line: 2333
// RVA: 0x7F5F80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildAt(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 pos,
        Scaleform::GFx::AS3::Value *value)
{
  unsigned __int64 v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // r13
  Scaleform::GFx::AS3::VM *pVM; // rdx
  char v9; // di
  Scaleform::GFx::AS3::Instances::fl::XML *VStr; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // r12
  unsigned __int64 v14; // rax
  __int64 v15; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v16; // rax
  unsigned __int64 Size; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v18; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // rdi
  unsigned __int64 v20; // r8
  bool v21; // zf
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v22; // rcx
  unsigned int v23; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v24; // rdi
  unsigned __int64 v25; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v26; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v27; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v28; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v30; // rdx
  int v31; // eax
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v34; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v35; // rcx
  Scaleform::GFx::AS3::Traits *v36; // rax
  Scaleform::GFx::AS3::Traits *v37; // r13
  Scaleform::GFx::AS3::CheckResult *v38; // rbx
  int v40; // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v41; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v42; // rax
  unsigned __int64 v43; // rax
  __int64 v44; // rdi
  int v45; // eax
  __int64 v46; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v47; // rdx
  int v48; // eax
  Scaleform::GFx::AS3::VM *v49; // rdx
  unsigned int v50; // eax
  Scaleform::GFx::AS3::VM::Error *v51; // rax
  Scaleform::GFx::ASStringNode *v52; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::Value v54; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v55; // [rsp+50h] [rbp-29h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v56; // [rsp+58h] [rbp-21h]
  unsigned __int64 v57; // [rsp+60h] [rbp-19h]
  unsigned __int64 pNext; // [rsp+68h] [rbp-11h]
  __int64 v59; // [rsp+70h] [rbp-9h]
  __int64 v60; // [rsp+78h] [rbp-1h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v61; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS3::Instances::fl::XML *v62; // [rsp+88h] [rbp+Fh]
  char v63[8]; // [rsp+90h] [rbp+17h] BYREF
  __int64 v64; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::VM *vm; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::CheckResult *v66; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> val; // [rsp+F8h] [rbp+7Fh] BYREF

  v66 = result;
  v64 = -2i64;
  v5 = pos;
  v6 = result;
  pVM = this->pTraits.pObject->pVM;
  vm = pVM;
  v9 = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 )
  {
    VStr = (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VStr;
    val.pObject = VStr;
    if ( VStr )
    {
      pObject = VStr->pTraits.pObject;
      if ( pObject->TraitsType == Traits_XMLList && (pObject->Flags & 0x20) == 0 )
      {
        pNext = (unsigned __int64)VStr[1].pNext;
        v12 = 0i64;
        if ( !pNext )
          goto LABEL_50;
        v13 = pos;
        v14 = -8i64 * pos;
        v57 = -8i64 * pos;
        while ( 2 )
        {
          v15 = *(_QWORD *)(v13 * 8 + v14 + VStr[1].pRCCRaw);
          v16 = this;
          do
          {
            if ( v16 == (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v15 )
            {
              Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v54, 1118, vm);
              Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v32, &Scaleform::GFx::AS3::fl::TypeErrorTI);
              pWeakProxy = (Scaleform::GFx::ASStringNode *)v54.Bonus.pWeakProxy;
              v21 = LODWORD(v54.Bonus.pWeakProxy[1].pObject)-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
              goto LABEL_50;
            }
            v16 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v16->Parent.pObject;
          }
          while ( v16 );
          Size = this->Children.Data.Size;
          if ( v5 >= Size )
          {
            if ( v5 != Size )
              goto LABEL_46;
            if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 208i64))(v15) == 2 )
            {
              v27 = *(Scaleform::GFx::AS3::Instances::fl::XML **)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_QWORD *)v15 + 280i64))(
                                                                   v15,
                                                                   &v54,
                                                                   this);
              v62 = v27;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
                &this->Children,
                this->Children.Data.Size + 1);
              v28 = &this->Children.Data.Data[this->Children.Data.Size - 1];
              v56 = v28;
              v55 = v28;
              if ( v28 )
              {
                v28->pObject = v27;
                if ( v27 )
                  v27->RefCount = (v27->RefCount + 1) & 0x8FBFFFFF;
              }
              if ( v27 )
              {
                if ( ((unsigned __int8)v27 & 1) != 0 )
                {
                  v62 = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v27 - 1);
                }
                else
                {
                  RefCount = v27->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    v27->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
                  }
                }
              }
              goto LABEL_45;
            }
            v59 = v15;
            *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
              &this->Children,
              this->Children.Data.Size + 1);
            v30 = &this->Children.Data.Data[this->Children.Data.Size - 1];
            v56 = v30;
            v55 = v30;
            if ( v30 )
            {
              v30->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v15;
              *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
            }
            if ( (v15 & 1) != 0 )
            {
              v59 = v15 - 1;
              goto LABEL_44;
            }
          }
          else
          {
            if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 208i64))(v15) == 2 )
            {
              v18 = *(Scaleform::GFx::AS3::Instances::fl::XML **)(*(__int64 (__fastcall **)(__int64, char *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_QWORD *)v15 + 280i64))(
                                                                   v15,
                                                                   v63,
                                                                   this);
              v61 = v18;
              p_Children = &this->Children;
              Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                &this->Children.Data,
                this->Children.Data.Size + 1);
              v20 = this->Children.Data.Size;
              if ( v5 < v20 - 1 )
                memmove(&p_Children->Data.Data[v13 + 1], &p_Children->Data.Data[v13], 8 * (v20 - v5) - 8);
              v21 = &p_Children->Data.Data[v13] == 0;
              v22 = &p_Children->Data.Data[v13];
              v55 = v22;
              v56 = v22;
              if ( !v21 )
              {
                v22->pObject = v18;
                if ( v18 )
                  v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
              }
              if ( v18 )
              {
                if ( ((unsigned __int8)v18 & 1) != 0 )
                {
                  v61 = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v18 - 1);
                }
                else
                {
                  v23 = v18->RefCount;
                  if ( (v23 & 0x3FFFFF) != 0 )
                  {
                    v18->RefCount = v23 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
                  }
                }
              }
              goto LABEL_45;
            }
            v60 = v15;
            *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
            v24 = &this->Children;
            Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->Children.Data,
              this->Children.Data.Size + 1);
            v25 = this->Children.Data.Size;
            if ( v5 < v25 - 1 )
              memmove(&v24->Data.Data[v13 + 1], &v24->Data.Data[v13], 8 * (v25 - v5) - 8);
            v21 = &v24->Data.Data[v13] == 0;
            v26 = &v24->Data.Data[v13];
            v56 = v26;
            v55 = v26;
            if ( !v21 )
            {
              v26->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v15;
              *(_DWORD *)(v15 + 32) = (*(_DWORD *)(v15 + 32) + 1) & 0x8FBFFFFF;
            }
            if ( (v15 & 1) != 0 )
            {
              v60 = v15 - 1;
LABEL_44:
              Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(v15 + 64),
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
LABEL_45:
              VStr = val.pObject;
              v9 = 1;
LABEL_46:
              ++v12;
              ++v13;
              ++v5;
              v14 = v57;
              if ( v12 < pNext )
                continue;
              goto LABEL_50;
            }
          }
          break;
        }
        v31 = *(_DWORD *)(v15 + 32);
        if ( (v31 & 0x3FFFFF) != 0 )
        {
          *(_DWORD *)(v15 + 32) = v31 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
        }
        goto LABEL_44;
      }
    }
  }
  v34 = 0i64;
  val.pObject = 0i64;
  if ( (value->Flags & 0x1F) - 12 > 3
    || (v35 = (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VStr) == 0i64
    || (v36 = v35->pTraits.pObject, v36->TraitsType != Traits_XML)
    || (v36->Flags & 0x20) != 0 )
  {
    v54.Flags = 0;
    v54.Bonus.pWeakProxy = 0i64;
    v37 = this->pTraits.pObject;
    if ( !v37->pConstructor.pObject )
      v37->vfptr[3].~RefCountBaseGC<328>(this->pTraits.pObject);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, __int64, Scaleform::GFx::AS3::Value *, char))v37->pConstructor.pObject->vfptr[4].ForEachChild_GC)(
      v37->pConstructor.pObject,
      &v54,
      1i64,
      value,
      1);
    if ( this->pTraits.pObject->pVM->HandleException )
      goto LABEL_59;
    v40 = v54.Flags & 0x1F;
    v41 = (Scaleform::GFx::AS3::Instances::fl::XML *)v54.value.VS._1.VStr;
    if ( (unsigned int)(v40 - 12) <= 3 || v40 == 10 )
    {
      if ( !v54.value.VS._1.VStr )
      {
LABEL_59:
        v38 = v66;
        v66->Result = 0;
        if ( (v54.Flags & 0x1F) > 9 )
        {
          if ( (v54.Flags & 0x200) != 0 )
          {
            v21 = v54.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v21 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v54.Bonus, 0, 24);
            v54.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v54);
          }
        }
        return v38;
      }
    }
    else if ( !v54.value.VS._1.VStr )
    {
LABEL_72:
      if ( (v54.Flags & 0x1F) > 9 )
      {
        if ( (v54.Flags & 0x200) != 0 )
        {
          v21 = v54.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v21 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v54.Bonus, 0, 24);
          v54.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v54);
        }
      }
      v6 = v66;
      pVM = vm;
      goto LABEL_79;
    }
    ++v54.value.VS._1.VStr->Size;
    v41->RefCount &= 0x8FBFFFFF;
    v34 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v41;
    val.pObject = v41;
    goto LABEL_72;
  }
  v35->RefCount = (v35->RefCount + 1) & 0x8FBFFFFF;
  v34 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v35;
  val.pObject = v35;
LABEL_79:
  v42 = this;
  do
  {
    if ( v42 == v34 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v54, 1118, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v51, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v52 = (Scaleform::GFx::ASStringNode *)v54.Bonus.pWeakProxy;
      v21 = LODWORD(v54.Bonus.pWeakProxy[1].pObject)-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v52);
      v6->Result = 0;
      if ( v34 )
      {
        if ( ((unsigned __int8)v34 & 1) != 0 )
        {
          val.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v34 - 1);
        }
        else
        {
          v53 = v34->RefCount;
          if ( (v53 & 0x3FFFFF) != 0 )
          {
            v34->RefCount = v53 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
          }
        }
      }
      return v6;
    }
    v42 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v42->Parent.pObject;
  }
  while ( v42 );
  v43 = this->Children.Data.Size;
  if ( v5 >= v43 )
  {
    if ( v5 != v43 )
      goto LABEL_104;
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v34->vfptr[8].Finalize_GC)(v34) == 2 )
    {
      v46 = *(_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v34->vfptr[11].Finalize_GC)(
                         v34,
                         &v54,
                         this);
      vm = (Scaleform::GFx::AS3::VM *)v46;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
        &this->Children,
        this->Children.Data.Size + 1);
      v47 = &this->Children.Data.Data[this->Children.Data.Size - 1];
      v56 = v47;
      v55 = v47;
      if ( v47 )
      {
        v47->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v46;
        if ( v46 )
          *(_DWORD *)(v46 + 32) = (*(_DWORD *)(v46 + 32) + 1) & 0x8FBFFFFF;
      }
      if ( v46 )
      {
        if ( (v46 & 1) != 0 )
        {
          vm = (Scaleform::GFx::AS3::VM *)(v46 - 1);
        }
        else
        {
          v48 = *(_DWORD *)(v46 + 32);
          if ( (v48 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)(v46 + 32) = v48 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v46);
          }
        }
      }
      goto LABEL_103;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
      &this->Children,
      this->Children.Data.Size + 1);
    v49 = (Scaleform::GFx::AS3::VM *)&this->Children.Data.Data[this->Children.Data.Size - 1];
    vm = v49;
    *(_QWORD *)&v54.Flags = v49;
    if ( v49 )
    {
      v49->vfptr = (Scaleform::GFx::AS3::VMVtbl *)v34;
      v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
    }
  }
  else
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v34->vfptr[8].Finalize_GC)(v34) == 2 )
    {
      v44 = *(_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v34->vfptr[11].Finalize_GC)(
                         v34,
                         &v54,
                         this);
      vm = (Scaleform::GFx::AS3::VM *)v44;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Children,
        v5,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&vm);
      if ( v44 )
      {
        if ( (v44 & 1) != 0 )
        {
          vm = (Scaleform::GFx::AS3::VM *)(v44 - 1);
        }
        else
        {
          v45 = *(_DWORD *)(v44 + 32);
          if ( (v45 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)(v44 + 32) = v45 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v44);
          }
        }
      }
      goto LABEL_103;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Children,
      v5,
      &val);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v34->Parent,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
LABEL_103:
  v9 = 1;
LABEL_104:
  if ( !v34 )
    goto LABEL_50;
  if ( ((unsigned __int8)v34 & 1) != 0 )
  {
    val.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v34 - 1);
    goto LABEL_50;
  }
  v50 = v34->RefCount;
  if ( (v50 & 0x3FFFFF) != 0 )
  {
    v34->RefCount = v50 - 1;
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
    v6->Result = v9;
    return v6;
  }
LABEL_50:
  v6->Result = v9;
  return v6;
}

// File Line: 2460
// RVA: 0x7F5EB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildAfter(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *child1,
        Scaleform::GFx::AS3::Value *child2)
{
  char v5; // si
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rax
  unsigned __int64 Size; // r8
  unsigned __int64 v11; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // rdx
  char *v13; // rax
  char v15; // [rsp+38h] [rbp+10h] BYREF

  v5 = 0;
  v8 = child1->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !child1->value.VS._1.VStr )
  {
    v13 = (char *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, _QWORD))this->vfptr[13].ForEachChild_GC)(
                    this,
                    &v15,
                    0i64);
LABEL_13:
    v5 = *v13;
    goto LABEL_14;
  }
  v9 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(this, child1);
  if ( v9 )
  {
    Size = this->Children.Data.Size;
    v11 = 0i64;
    if ( Size )
    {
      Data = this->Children.Data.Data;
      while ( Data->pObject != v9 )
      {
        ++v11;
        ++Data;
        if ( v11 >= Size )
          goto LABEL_14;
      }
      v13 = (char *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, _QWORD, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
                      this,
                      &v15,
                      (unsigned int)(v11 + 1),
                      child2);
      goto LABEL_13;
    }
  }
LABEL_14:
  result->Result = v5;
  return result;
}

// File Line: 2488
// RVA: 0x7F67A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildBefore(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *child1,
        Scaleform::GFx::AS3::Value *child2)
{
  char v5; // si
  Scaleform::GFx::AS3::Value *v6; // rbp
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rax
  unsigned __int64 Size; // r8
  unsigned __int64 v11; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // rdx
  __int64 Size_low; // r8
  char v15; // [rsp+38h] [rbp+10h] BYREF

  v5 = 0;
  v6 = child2;
  v8 = child1->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !child1->value.VS._1.VStr )
  {
    Size_low = LODWORD(this->Children.Data.Size);
LABEL_13:
    v5 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, __int64, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
                     this,
                     &v15,
                     Size_low,
                     child2);
    goto LABEL_14;
  }
  v9 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(this, child1);
  if ( v9 )
  {
    Size = this->Children.Data.Size;
    v11 = 0i64;
    if ( Size )
    {
      Data = this->Children.Data.Data;
      while ( Data->pObject != v9 )
      {
        ++v11;
        ++Data;
        if ( v11 >= Size )
          goto LABEL_14;
      }
      Size_low = (unsigned int)v11;
      child2 = v6;
      goto LABEL_13;
    }
  }
LABEL_14:
  result->Result = v5;
  return result;
}

// File Line: 2516
// RVA: 0x7C0810
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XML *child)
{
  unsigned __int64 Size; // rsi
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *i; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 j; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v11; // rcx
  unsigned int v12; // eax

  Size = this->Children.Data.Size;
  if ( child )
  {
    v4 = 0i64;
    if ( Size )
    {
      for ( i = this->Children.Data.Data; ; ++i )
      {
        pObject = i->pObject;
        if ( i->pObject == child )
          break;
        if ( ++v4 >= Size )
          return;
      }
      if ( pObject )
      {
        v7 = pObject->Parent.pObject;
        if ( v7 )
        {
          if ( ((unsigned __int8)v7 & 1) != 0 )
          {
            pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v7 - 1);
          }
          else
          {
            RefCount = v7->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v7->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
            }
          }
          pObject->Parent.pObject = 0i64;
        }
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
        v4);
    }
  }
  else
  {
    for ( j = 0i64; j < Size; ++j )
    {
      v10 = this->Children.Data.Data[j].pObject;
      if ( v10 )
      {
        v11 = v10->Parent.pObject;
        if ( v11 )
        {
          if ( ((unsigned __int8)v11 & 1) != 0 )
          {
            v10->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( (v12 & 0x3FFFFF) != 0 )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
            }
          }
          v10->Parent.pObject = 0i64;
        }
      }
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
      &this->Children,
      0i64);
  }
}

// File Line: 2551
// RVA: 0x7C0790
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteByIndex(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        unsigned __int64 ind)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *p_Children; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rcx
  unsigned int RefCount; // eax

  if ( ind < this->Children.Data.Size )
  {
    p_Children = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
    pObject = this->Children.Data.Data[ind].pObject;
    if ( pObject )
    {
      v5 = pObject->Parent.pObject;
      if ( v5 )
      {
        if ( ((unsigned __int8)v5 & 1) != 0 )
        {
          pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v5 - 1);
        }
        else
        {
          RefCount = v5->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v5->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
          }
        }
        pObject->Parent.pObject = 0i64;
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_Children,
      ind);
  }
}

// File Line: 2576
// RVA: 0x802480
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Normalize(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned __int64 Size; // rbp
  Scaleform::GFx::ASString *v2; // r14
  unsigned __int64 v3; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *p_Children; // r15
  Scaleform::GFx::ASString *pObject; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rax
  __int64 v7; // rbx

  Size = this->Children.Data.Size;
  v2 = 0i64;
  v3 = 0i64;
  if ( Size )
  {
    p_Children = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
    do
    {
      pObject = (Scaleform::GFx::ASString *)p_Children->Data.Data[v3].pObject;
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))pObject->pNode[5].pManager)(pObject) == 2 )
      {
        if ( v2 )
        {
          if ( pObject[7].pNode->Size )
            Scaleform::GFx::ASString::Append(v2 + 7, pObject + 7);
        }
        else
        {
          pNode = pObject[7].pNode;
          if ( pNode->Size )
          {
            v7 = 0i64;
            while ( Scaleform::GFx::ASUtils::IsWhiteSpace(pNode->pData[v7]) )
            {
              pNode = pObject[7].pNode;
              v7 = (unsigned int)(v7 + 1);
              if ( (unsigned int)v7 >= pNode->Size )
                goto LABEL_7;
            }
            v2 = pObject;
            goto LABEL_15;
          }
        }
LABEL_7:
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          p_Children,
          v3--);
        --Size;
      }
      else
      {
        v2 = 0i64;
      }
LABEL_15:
      ++v3;
    }
    while ( v3 < Size );
  }
}

// File Line: 2616
// RVA: 0x7D2CD0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByPrefix(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::ASString *prefix,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  int v6; // ebx
  unsigned __int64 Size; // r14
  __int64 v8; // rdi
  Scaleform::GFx::AS3::Value *p_Prefix; // rcx
  bool v10; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v13; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  __int64 v16; // rcx
  char v17; // al
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  v6 = 0;
  Size = this->Namespaces.Data.Size;
  v8 = 0i64;
  if ( !Size )
    goto LABEL_14;
  while ( 1 )
  {
    p_Prefix = &this->Namespaces.Data.Data[v8].pObject->Prefix;
    v10 = 0;
    if ( (p_Prefix->Flags & 0x1F) == 10 )
    {
      v6 |= 1u;
      if ( Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(p_Prefix, &result)->pNode == prefix->pNode )
        v10 = 1;
    }
    if ( (v6 & 1) != 0 )
    {
      v6 &= ~1u;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( v10 )
      break;
    if ( ++v8 >= Size )
      goto LABEL_14;
  }
  v13 = &this->Namespaces.Data.Data[v8];
  if ( v13 )
    return v13->pObject;
LABEL_14:
  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[15].Finalize_GC)(
                                                              pObject,
                                                              prefix,
                                                              lp);
  v16 = 0i64;
  while ( 1 )
  {
    v17 = prefix->pNode->pData[v16++];
    if ( v17 != aXml_5[v16 - 1] )
      break;
    if ( v16 == 4 )
      return this->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 2641
// RVA: 0x7D2E60
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByURI(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  unsigned __int64 Size; // r11
  unsigned __int64 v4; // r9
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // r10
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v10; // rax
  __int64 v11; // rcx
  const char *pData; // rdx
  char v13; // al

  Size = this->Namespaces.Data.Size;
  v4 = 0i64;
  if ( !Size )
    goto LABEL_5;
  Data = this->Namespaces.Data.Data;
  v7 = Data;
  while ( v7->pObject->Uri.pNode != uri->pNode )
  {
    ++v4;
    ++v7;
    if ( v4 >= Size )
      goto LABEL_5;
  }
  v10 = &Data[v4];
  if ( v10 )
    return v10->pObject;
LABEL_5:
  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, unsigned __int64))pObject->vfptr[15].Finalize_GC)(
                                                              pObject,
                                                              uri,
                                                              lp,
                                                              v4);
  v11 = 0i64;
  pData = uri->pNode->pData;
  while ( 1 )
  {
    v13 = pData[v11++];
    if ( v13 != aXml_5[v11 - 1] )
      break;
    if ( v11 == 4 )
      return this->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 2668
// RVA: 0x79A6B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::AS3Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v6; // r12
  Scaleform::GFx::AS3::VM *pVM; // r10
  unsigned int v9; // r9d
  Scaleform::GFx::ASStringNode *VStr; // rcx
  const char *pData; // rax
  Scaleform::GFx::AS3::Value::V1U v12; // rcx
  unsigned int Flags; // ebx
  bool v14; // zf
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rsi
  unsigned int v21; // ebx
  unsigned __int64 Size; // r15
  Scaleform::GFx::AS3::Value::V2U v23; // r14
  Scaleform::GFx::ASStringNode *v24; // rdi
  unsigned __int64 v25; // r12
  bool v26; // al
  unsigned int v27; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v31; // rcx
  unsigned int v32; // eax
  Scaleform::GFx::AS3::Value::VU v34; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::AS3::Value valuea; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::CheckResult *v38; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *prop_namea; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::ASString v40; // [rsp+E8h] [rbp+7Fh] BYREF

  prop_namea = prop_name;
  v38 = result;
  v6 = result;
  pVM = this->pTraits.pObject->pVM;
  valuea.Flags = 0;
  valuea.Bonus.pWeakProxy = 0i64;
  v9 = value->Flags & 0x1F;
  if ( v9 - 12 <= 3 )
  {
    VStr = value->value.VS._1.VStr;
    if ( VStr )
    {
      pData = VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
      {
        v12 = *(Scaleform::GFx::AS3::Value::V1U *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, _QWORD))VStr->pData
                                                   + 35))(
                                                    VStr,
                                                    &resulta,
                                                    0i64);
        other.Bonus.pWeakProxy = 0i64;
        other.Flags = 12;
        other.value.VS._1 = v12;
        other.value.VS._2.VObj = v34.VS._2.VObj;
        Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
        goto LABEL_6;
      }
    }
  }
  if ( v9 - 12 <= 3 )
  {
    v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)value->value.VS._1.VStr;
    if ( v15 )
    {
      pObject = v15->pTraits.pObject;
      if ( pObject->TraitsType == Traits_XMLList && (pObject->Flags & 0x20) == 0 )
      {
        pV = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(v15, &resulta, 0i64)->pV;
        other.Bonus.pWeakProxy = 0i64;
        other.Flags = 12;
        other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pV;
        other.value.VS._2.VObj = v34.VS._2.VObj;
        Scaleform::GFx::AS3::Value::Assign(&valuea, &other);
LABEL_6:
        Flags = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v14 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v14 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags = Flags & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
        goto LABEL_31;
      }
    }
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    pVM->StringManagerRef,
    &v40);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(value, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v40)->Result )
  {
    v6->Result = 0;
    pNode = v40.pNode;
    v14 = v40.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_20:
    if ( (valuea.Flags & 0x1F) > 9 )
    {
      if ( (valuea.Flags & 0x200) != 0 )
      {
        v14 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_72:
        memset(&valuea.Bonus, 0, 24);
        valuea.Flags &= 0xFFFFFDE0;
        return v6;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&valuea);
    }
    return v6;
  }
  v14 = v40.pNode == &v40.pNode->pManager->NullStringNode;
  valuea.value.VS._2.VObj = v34.VS._2.VObj;
  if ( v14 )
  {
    valuea.value.VS._1.VStr = 0i64;
    valuea.Flags = valuea.Flags & 0xFFFFFFE0 | 0xC;
  }
  else
  {
    valuea.Flags = valuea.Flags & 0xFFFFFFE0 | 0xA;
    *(Scaleform::GFx::ASString *)&valuea.value.VNumber = (Scaleform::GFx::ASString)v40.pNode;
    ++v40.pNode->RefCount;
  }
  v19 = v40.pNode;
  v14 = v40.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
LABEL_31:
  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&resulta, prop_name, (unsigned int *)&v40)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(this, v6, LODWORD(v40.pNode), &valuea);
    goto LABEL_20;
  }
  pWeakProxy = 0i64;
  other.Bonus.pWeakProxy = 0i64;
  v21 = 0;
  other.Flags = 0;
  Size = this->Children.Data.Size;
  v23.VObj = (Scaleform::GFx::AS3::Object *)other.value.VS._2;
  v24 = other.value.VS._1.VStr;
  if ( Size )
  {
    v25 = Size - 1;
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Children.Data.Data[v25].pObject, prop_namea) )
      {
        if ( (v21 & 0x1F) != 0 )
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, _QWORD))this->vfptr[14].~RefCountBaseGC<328>)(
            this,
            other.value.VS._1.VInt);
        if ( (v21 & 0x1F) > 9 )
        {
          if ( (v21 & 0x200) != 0 )
          {
            v14 = pWeakProxy->RefCount-- == 1;
            if ( v14 )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
            pWeakProxy = 0i64;
            memset(&other.Bonus, 0, 24);
            v21 &= 0xFFFFFDE0;
            other.Flags = v21;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
            pWeakProxy = other.Bonus.pWeakProxy;
            v21 = other.Flags;
          }
        }
        v21 = v21 & 0xFFFFFFE0 | 2;
        other.Flags = v21;
        v34.VS._1.VInt = v25;
        v24 = v34.VS._1.VStr;
        other.value = v34;
        v23.VObj = (Scaleform::GFx::AS3::Object *)v34.VS._2;
      }
      --v25;
      --Size;
    }
    while ( Size );
    v6 = v38;
  }
  v26 = 1;
  if ( (v21 & 0x1F) != 0 )
    v26 = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
            this,
            (Scaleform::GFx::AS3::CheckResult *)&resulta,
            other.value.VS._1.VInt,
            &valuea)->Result;
  v6->Result = v26;
  if ( (v21 & 0x1F) > 9 )
  {
    if ( (v21 & 0x200) != 0 )
    {
      v14 = pWeakProxy->RefCount-- == 1;
      if ( v14 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      memset(&other.Bonus, 0, 24);
      other.Flags = v21 & 0xFFFFFDE0;
    }
    else
    {
      switch ( v21 & 0x1F )
      {
        case 0xAu:
          v14 = v24->RefCount-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
          break;
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0xEu:
        case 0xFu:
          if ( other.value.VS._1.VBool )
          {
            other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)v24 - 1);
          }
          else if ( v24 )
          {
            v27 = v24->Size;
            if ( (v27 & 0x3FFFFF) != 0 )
            {
              v24->Size = v27 - 1;
              VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v24;
              goto LABEL_67;
            }
          }
          break;
        case 0x10u:
        case 0x11u:
          if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
          {
            other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v23.VObj - 1);
          }
          else if ( v23.VObj )
          {
            RefCount = v23.VObj->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v23.VObj->RefCount = RefCount - 1;
              VObj = v23.VObj;
LABEL_67:
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
            }
          }
          break;
        default:
          break;
      }
    }
  }
  if ( (valuea.Flags & 0x1F) > 9 )
  {
    if ( (valuea.Flags & 0x200) != 0 )
    {
      v14 = valuea.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_72;
    }
    switch ( valuea.Flags & 0x1F )
    {
      case 0xA:
        v30 = valuea.value.VS._1.VStr;
        v14 = valuea.value.VS._1.VStr->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        break;
      case 0xB:
      case 0xC:
      case 0xD:
      case 0xE:
      case 0xF:
        v31 = valuea.value.VS._1.VObj;
        if ( !valuea.value.VS._1.VBool )
          goto LABEL_80;
        --valuea.value.VS._1.VStr;
        break;
      case 0x10:
      case 0x11:
        v31 = valuea.value.VS._2.VObj;
        if ( ((__int64)valuea.value.VS._2.VObj & 1) != 0 )
        {
          --valuea.value.VS._2.VObj;
        }
        else
        {
LABEL_80:
          if ( v31 )
          {
            v32 = v31->RefCount;
            if ( (v32 & 0x3FFFFF) != 0 )
            {
              v31->RefCount = v32 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
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
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h] BYREF
  unsigned int ind; // [rsp+24h] [rbp-24h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h] BYREF

  v13 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(this, result, ind, value);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 1087, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
  }
  return result;
}

// File Line: 2744
// RVA: 0x812500
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 i,
        Scaleform::GFx::AS3::Value *value)
{
  unsigned __int64 v5; // rbp
  char v8; // r15
  unsigned __int64 Size; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v10; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  const char *v14; // rax
  Scaleform::GFx::AS3::Value::V1U v15; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v16; // rax
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *v20; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Value::V1U v23; // rax
  const char *pData; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v25; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v28; // rbx
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InstanceText; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v33; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v35; // [rsp+90h] [rbp+18h] BYREF

  v5 = i;
  v8 = 1;
  Size = this->Children.Data.Size;
  if ( i >= Size )
  {
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Children.Data,
      Size + 1);
    v5 = this->Children.Data.Size - 1;
    v10 = &this->Children.Data.Data[v5];
    pObject = v10->pObject;
    if ( v10->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v10->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      v10->pObject = 0i64;
    }
  }
  if ( (value->Flags & 0x1F) - 12 > 3
    || (VStr = value->value.VS._1.VStr) == 0i64
    || (v14 = VStr[1].pData, *((_DWORD *)v14 + 30) != 18)
    || (v14[112] & 0x20) != 0
    || (*((unsigned int (__fastcall **)(Scaleform::GFx::ASStringNode *))VStr->pData + 26))(VStr) == 5 )
  {
    if ( (value->Flags & 0x1F) - 12 <= 3
      && (v23 = value->value.VS._1, v23.VStr)
      && (pData = v23.VStr[1].pData, *((_DWORD *)pData + 30) == 19)
      && (pData[112] & 0x20) == 0 )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, unsigned __int64))this->vfptr[14].~RefCountBaseGC<328>)(
        this,
        v5);
      v8 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::ASString *, unsigned __int64, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
                       this,
                       &resulta,
                       v5,
                       value);
    }
    else
    {
      v25 = this->Children.Data.Data[v5].pObject;
      if ( v25 )
      {
        v26 = v25->Parent.pObject;
        if ( v26 )
        {
          if ( ((unsigned __int8)v26 & 1) != 0 )
          {
            v25->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v26 - 1);
          }
          else
          {
            v27 = v26->RefCount;
            if ( (v27 & 0x3FFFFF) != 0 )
            {
              v26->RefCount = v27 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
            }
          }
          v25->Parent.pObject = 0i64;
        }
      }
      v28 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject;
      v29 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(value, &resulta);
      InstanceText = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                                                           v28,
                                                                                           &v35,
                                                                                           v28,
                                                                                           v29,
                                                                                           this);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Children.Data.Data[v5],
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InstanceText->pV);
      pNode = resulta.pNode;
      v19 = resulta.pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    goto LABEL_43;
  }
  v15 = value->value.VS._1;
  if ( (*((unsigned int (__fastcall **)(Scaleform::GFx::AS3::Value::V1U))v15.VStr->pData + 26))(v15) != 1 )
  {
LABEL_21:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v15.VStr[1].RefCount,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
    v20 = this->Children.Data.Data[v5].pObject;
    if ( v20 )
    {
      v21 = v20->Parent.pObject;
      if ( v21 )
      {
        if ( ((unsigned __int8)v21 & 1) != 0 )
        {
          v20->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v21 - 1);
        }
        else
        {
          v22 = v21->RefCount;
          if ( (v22 & 0x3FFFFF) != 0 )
          {
            v21->RefCount = v22 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
          }
        }
        v20->Parent.pObject = 0i64;
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Children.Data.Data[v5],
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v15.VStr);
LABEL_43:
    result->Result = v8;
    return result;
  }
  v16 = this;
  while ( v16 != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v15.VStr )
  {
    v16 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v16->Parent.pObject;
    if ( !v16 )
      goto LABEL_21;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v33, 1118, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v18 = v33.Message.pNode;
  v19 = v33.Message.pNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  result->Result = 0;
  return result;
}

// File Line: 2819
// RVA: 0x818790
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // r13
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *p_Children; // r14
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::Value::V1U v7; // rbx
  const char *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pObject; // rax
  Scaleform::GFx::ASStringNode *v10; // rdx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value::V1U v14; // rsi
  const char *pData; // rax
  Scaleform::GFx::ASStringManager *pManager; // rbp
  __int64 v17; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v19; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *pV; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLText *v21; // rdx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::VM::Error v24; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *VStr; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v27; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLText *v28; // [rsp+A8h] [rbp+20h]

  pVM = this->pTraits.pObject->pVM;
  p_Children = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    0i64);
  v6 = value->Flags & 0x1F;
  if ( v6 - 12 <= 3
    && (v7 = value->value.VS._1, v7.VStr)
    && (v8 = v7.VStr[1].pData, *((_DWORD *)v8 + 30) == 18)
    && (v8[112] & 0x20) == 0 )
  {
    pObject = this;
    while ( pObject != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v7.VStr )
    {
      pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)pObject->Parent.pObject;
      if ( !pObject )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v7.VStr[1].RefCount,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
        VStr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v7.VStr;
        v7.VStr->Size = (v7.VStr->Size + 1) & 0x8FBFFFFF;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          p_Children,
          p_Children,
          p_Children->Size + 1);
        v10 = (Scaleform::GFx::ASStringNode *)&p_Children->Data[p_Children->Size - 1];
        result.pNode = v10;
        v27.pV = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v10;
        if ( v10 )
        {
          v10->pData = (const char *)v7.VStr;
          v7.VStr->Size = (v7.VStr->Size + 1) & 0x8FBFFFFF;
        }
        if ( v7.VBool )
        {
          VStr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)&v7.VStr[-1].Size + 7);
        }
        else
        {
          Size = v7.VStr->Size;
          if ( (Size & 0x3FFFFF) != 0 )
          {
            v7.VStr->Size = Size - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7.VObj);
          }
        }
        return;
      }
    }
  }
  else
  {
    if ( v6 - 12 > 3
      || (v14 = value->value.VS._1, !v14.VStr)
      || (pData = v14.VStr[1].pData, *((_DWORD *)pData + 30) != 19)
      || (pData[112] & 0x20) != 0 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        pVM->StringManagerRef,
        &result);
      if ( Scaleform::GFx::AS3::Value::Convert2String(value, (Scaleform::GFx::AS3::CheckResult *)&VStr, &result)->Result )
      {
        pV = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                               (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
                                                               &v27,
                                                               (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
                                                               &result,
                                                               this)->pV;
        VStr = pV;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          p_Children,
          p_Children,
          p_Children->Size + 1);
        v21 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)&p_Children->Data[p_Children->Size - 1];
        v27.pV = v21;
        v28 = v21;
        if ( v21 )
        {
          v21->vfptr = pV;
          if ( pV )
            LODWORD(pV[1].~RefCountBaseGC<328>) = (LODWORD(pV[1].~RefCountBaseGC<328>) + 1) & 0x8FBFFFFF;
        }
        if ( pV )
        {
          if ( ((unsigned __int8)pV & 1) != 0 )
          {
            VStr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)pV - 1);
          }
          else
          {
            v22 = (unsigned int)pV[1].~RefCountBaseGC<328>;
            if ( (v22 & 0x3FFFFF) != 0 )
            {
              LODWORD(pV[1].~RefCountBaseGC<328>) = v22 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pV);
            }
          }
        }
      }
      pNode = result.pNode;
      goto LABEL_37;
    }
    pManager = v14.VStr[2].pManager;
    v17 = 0i64;
    if ( !pManager )
    {
LABEL_26:
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)p_Children,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)&v14.VStr[2]);
      return;
    }
LABEL_20:
    v18 = *(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)&v14.VStr[2].pData[8 * v17];
    v19 = this;
    while ( v19 != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v18 )
    {
      v19 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v19->Parent.pObject;
      if ( !v19 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          v18 + 8,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
        if ( ++v17 < (unsigned __int64)pManager )
          goto LABEL_20;
        goto LABEL_26;
      }
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v24, 1118, pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v24.Message.pNode;
LABEL_37:
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 2883
// RVA: 0x785710
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::XMLText(
        Scaleform::GFx::AS3::Instances::fl::XMLText *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *txt,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = txt->pNode;
  this->Text = (Scaleform::GFx::ASString)txt->pNode;
  ++pNode->RefCount;
  this->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable;
}

// File Line: 2897
// RVA: 0x828540
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLText *this,
        Scaleform::StringBuffer *buf,
        __int64 ident,
        Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces)
{
  int v4; // ebp
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Class *v8; // rax
  Scaleform::GFx::AS3::Traits *v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  v4 = ident;
  pObject = this->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *, __int64))pObject->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces,
      -2i64);
  v8 = pObject->pConstructor.pObject;
  if ( SHIDWORD(v8[1].vfptr) >= 0 && BYTE3(v8[1].vfptr) && v4 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, v4);
  v9 = this->pTraits.pObject;
  if ( !v9->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *))v9->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces);
  if ( BYTE3(v9->pConstructor.pObject[1].vfptr) )
  {
    v10 = Scaleform::GFx::ASString::TruncateWhitespace(&this->Text, &result);
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(buf, v10);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(buf, &this->Text);
  }
}

// File Line: 2923
// RVA: 0x7C0750
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLText::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLText *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLText *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> resulta; // [rsp+40h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v5 = result;
  result->pV = pV;
  return v5;
}

// File Line: 2933
// RVA: 0x785180
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rbx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  v10 = p;
  this->Parent.pObject = p;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable;
  this->Ns.pObject = 0i64;
  v11 = v->pNode;
  this->Data = (Scaleform::GFx::ASString)v->pNode;
  ++v11->RefCount;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&p,
    NS_Public,
    &ns->Uri,
    &ns->Prefix);
  pObject = this->Ns.pObject;
  v13 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)p;
  if ( p != (Scaleform::GFx::AS3::Instances::fl::XML *)pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->Ns.pObject = v13;
  }
}

// File Line: 2938
// RVA: 0x78FE60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::~XMLAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable;
  pNode = this->Data.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::XML::~XML(this);
}

// File Line: 2951
// RVA: 0x7D6DB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_value; // rdx
  Scaleform::GFx::AS3::Value v9; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->Parent.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  v9.Flags = 10;
  v9.Bonus.pWeakProxy = 0i64;
  pNode = this->Data.pNode;
  v9.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    v9.value.VS._1.VStr = 0i64;
    v9.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v9.Bonus.pWeakProxy;
    v9.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  if ( (v9.Flags & 0x1F) > 0xA && (v9.Flags & 0x200) == 0 && (v9.Flags & 0x1F) >= 0xB )
  {
    if ( (v9.Flags & 0x1F) <= 0xF )
    {
      if ( !v9.value.VS._1.VStr )
        goto LABEL_19;
      p_value = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v9.value;
      if ( (v9.Flags & 0x1F) - 11 > 4 )
        p_value = 0i64;
      goto LABEL_18;
    }
    if ( (v9.Flags & 0x1F) <= 0x11 && v9.value.VS._2.VObj )
    {
      p_value = &v9.value.VS._2.VObj;
LABEL_18:
      op(prcc, p_value);
    }
  }
LABEL_19:
  if ( (v9.Flags & 0x1F) > 9 )
  {
    if ( (v9.Flags & 0x200) != 0 )
    {
      if ( v9.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v9.Bonus, 0, 24);
      v9.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ResolveNamespaces(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::HashSetDH<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *nr,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *pTable; // r11
  __int64 v10; // rdx
  unsigned __int64 v11; // r9
  __int64 v12; // r8
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // r10
  __int64 v16; // r8
  unsigned __int64 *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString key; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+20h] BYREF

  pObject = this->Ns.pObject;
  if ( (pObject->Prefix.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&pObject->Prefix, &result);
    key.pNode = result.pNode;
    ++result.pNode->RefCount;
    pNode = result.pNode;
    v8 = result.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLAttr *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[15].Finalize_GC)(
            this,
            &key,
            lp) )
    {
      pTable = nr->pTable;
      v10 = 8i64;
      v11 = 5381i64;
      if ( !nr->pTable )
        goto LABEL_22;
      v12 = 8i64;
      v13 = 5381i64;
      do
      {
        --v12;
        v14 = 65599 * v13 + *((unsigned __int8 *)&key.pNode + v12);
        v13 = v14;
      }
      while ( v12 );
      v15 = v14 & pTable->SizeMask;
      v16 = v15;
      v17 = &pTable[v15 + 1].EntryCount + v15;
      if ( *v17 == -2i64 || v17[1] != v15 )
        goto LABEL_22;
      while ( v17[1] != v15 || (Scaleform::GFx::ASStringNode *)v17[2] != key.pNode )
      {
        v16 = *v17;
        if ( *v17 == -1i64 )
          goto LABEL_16;
        v17 = &pTable[v16 + 1].EntryCount + v16;
      }
      if ( v16 < 0
        || !(Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)&pTable[v16 + 2] + 8 * v16) )
      {
LABEL_22:
        do
        {
LABEL_16:
          --v10;
          v11 = *((unsigned __int8 *)&key.pNode + v10) + 65599 * v11;
        }
        while ( v10 );
        Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
          nr,
          nr->pHeap,
          &key,
          v11);
      }
    }
    v18 = key.pNode;
    v8 = key.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 2987
// RVA: 0x81A830
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::SetNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *ns)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
    ns);
}

// File Line: 2992
// RVA: 0x7EE7D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetQName(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::QName *pObject; // r8
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v6; // [rsp+58h] [rbp+10h]

  v6 = result;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject;
  result->pObject = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
                      pObject,
                      &resulta,
                      pObject,
                      &this->Text,
                      this->Ns.pObject)->pV;
  return result;
}

// File Line: 3006
// RVA: 0x826710
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToString(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::StringBuffer *buf,
        int __formal)
{
  Scaleform::StringBuffer::AppendString(buf, this->Data.pNode->pData, this->Data.pNode->Size);
}

// File Line: 3011
// RVA: 0x826AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::StringBuffer *buf,
        int ident,
        Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Instances::fl::XML::EscapeAttributeValue(buf, &this->Data);
}

// File Line: 3017
// RVA: 0x7C9440
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  __int64 result; // rax

  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(this, other);
  if ( !(_DWORD)result )
    return (unsigned int)(this->Data.pNode != (Scaleform::GFx::ASStringNode *)other[1]._pRCC) + 1;
  return result;
}

// File Line: 3032
// RVA: 0x7C01F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLAttr::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> resulta; // [rsp+50h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         this->Ns.pObject,
         &this->Text,
         &this->Data,
         parent)->pV;
  v5 = result;
  result->pV = pV;
  return v5;
}

// File Line: 3046
// RVA: 0x7855C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  this->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::`vftable;
  v9 = v->pNode;
  this->Data = (Scaleform::GFx::ASString)v->pNode;
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
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> resulta; // [rsp+40h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         &this->Data,
         parent)->pV;
  v5 = result;
  result->pV = pV;
  return v5;
}

// File Line: 3061
// RVA: 0x7EE840
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::GetQName(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v5; // [rsp+58h] [rbp+10h]

  v5 = result;
  result->pObject = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
                      (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
                      &resulta,
                      this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
                      &this->Text,
                      this->pTraits.pObject->pVM->PublicNamespace.pObject)->pV;
  return result;
}

// File Line: 3067
// RVA: 0x828110
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::StringBuffer *buf,
        __int64 ident,
        Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  int v6; // edi
  Scaleform::GFx::AS3::Class *v9; // rax

  pObject = this->pTraits.pObject;
  v6 = ident;
  if ( !pObject->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *))pObject->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces);
  v9 = pObject->pConstructor.pObject;
  if ( SHIDWORD(v9[1].vfptr) >= 0 && BYTE3(v9[1].vfptr) && v6 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, v6);
  Scaleform::StringBuffer::AppendString(buf, "<?", 2i64);
  Scaleform::StringBuffer::AppendString(buf, this->Text.pNode->pData, this->Text.pNode->Size);
  Scaleform::StringBuffer::AppendChar(buf, 0x20u);
  Scaleform::StringBuffer::AppendString(buf, this->Data.pNode->pData, this->Data.pNode->Size);
  Scaleform::StringBuffer::AppendString(buf, "?>", 2i64);
}

// File Line: 3091
// RVA: 0x7C9850
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  __int64 result; // rax

  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(this, other);
  if ( !(_DWORD)result )
    return (unsigned int)(this->Data.pNode != (Scaleform::GFx::ASStringNode *)other[1].vfptr) + 1;
  return result;
}

// File Line: 3104
// RVA: 0x785290
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::XMLComment(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  this->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLComment::`vftable;
}

// File Line: 3113
// RVA: 0x7C0240
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLComment *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> resulta; // [rsp+40h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v5 = result;
  result->pV = pV;
  return v5;
}

// File Line: 3119
// RVA: 0x826730
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::ToString(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::StringBuffer *buf,
        __int64 ident)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::StringBuffer *buf,
        __int64 ident,
        Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  int v6; // edi
  Scaleform::GFx::AS3::Class *v9; // rax

  pObject = this->pTraits.pObject;
  v6 = ident;
  if ( !pObject->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::StringBuffer *, __int64, Scaleform::GFx::AS3::NamespaceArray *))pObject->vfptr[3].~RefCountBaseGC<328>)(
      this->pTraits.pObject,
      buf,
      ident,
      ancestorNamespaces);
  v9 = pObject->pConstructor.pObject;
  if ( SHIDWORD(v9[1].vfptr) >= 0 && BYTE3(v9[1].vfptr) && v6 > 0 )
    Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, v6);
  Scaleform::StringBuffer::AppendString(buf, "<!--", 4i64);
  Scaleform::StringBuffer::AppendString(buf, this->Text.pNode->pData, this->Text.pNode->Size);
  Scaleform::StringBuffer::AppendString(buf, "-->", 3i64);
}

// File Line: 3151
// RVA: 0x7C9480
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XMLComment::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  __int64 result; // rax

  result = Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(this, other);
  if ( !(_DWORD)result )
    return 1i64;
  return result;
}

// File Line: 3165
// RVA: 0x7FE040
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl::XML *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                    this->pVM->MHeap,
                                                    72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XML::XML(v8, t, n, p);
  result->pV = v8;
  return result;
}

// File Line: 3171
// RVA: 0x7FE670
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v9; // rax

  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)this->pVM->MHeap->vfptr->Alloc(this->pVM->MHeap, 152i64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(v9, t, ns, n, p);
  result->pV = v9;
  return result;
}

// File Line: 3177
// RVA: 0x7FE770
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *txt,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLText *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                        this->pVM->MHeap,
                                                        72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XMLText::XMLText(v8, t, txt, p);
  result->pV = v8;
  return result;
}

// File Line: 3183
// RVA: 0x7FE7F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::StringDataPtr *txt,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::Instance *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLText *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Instance *v15; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::AS3::Instance *v16; // [rsp+68h] [rbp+20h]

  pVM = t->pVM;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    pVM->StringManagerRef,
    &resulta,
    txt->pStr,
    txt->Size);
  v8 = (Scaleform::GFx::AS3::Instance *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))pVM->MHeap->vfptr->Alloc)(
                                          pVM->MHeap,
                                          72i64);
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v8;
  v15 = v8;
  v16 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v8, t);
    v9->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v9->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
    v9->Text = resulta;
    ++resulta.pNode->RefCount;
    v10 = p;
    v9->Parent.pObject = p;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
    v9->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable;
  }
  else
  {
    v9 = 0i64;
  }
  result->pV = v9;
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 3192
// RVA: 0x7FE560
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v10; // rax

  v10 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                         this->pVM->MHeap,
                                                         88i64);
  if ( v10 )
    Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(v10, t, ns, n, v, p);
  result->pV = v10;
  return result;
}

// File Line: 3198
// RVA: 0x7FE6F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceProcInstr(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLProcInstr> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::ASString *v,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v9; // rax

  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                             this->pVM->MHeap,
                                                             80i64);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(v9, t, n, v, p);
  result->pV = v9;
  return result;
}

// File Line: 3204
// RVA: 0x7FE5F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLComment *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLComment *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pVM->MHeap->vfptr->Alloc)(
                                                           this->pVM->MHeap,
                                                           72i64);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::XMLComment::XMLComment(v8, t, n, p);
  result->pV = v8;
  return result;
}

// File Line: 3211
// RVA: 0x7F8830
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsNameStartChar(
        Scaleform::GFx::AS3::CheckResult *result,
        int c)
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
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsNameChar(
        Scaleform::GFx::AS3::CheckResult *result,
        int c)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS3::IsNameStartChar(&resulta, c)->Result
    || (unsigned int)(c - 45) <= 1
    || (unsigned int)(c - 48) <= 9
    || c == 183
    || (unsigned int)(c - 768) <= 0x6F )
  {
    v4 = result;
  }
  else
  {
    v4 = result;
    if ( (unsigned int)(c - 8255) > 1 )
    {
      result->Result = 0;
      return v4;
    }
  }
  result->Result = 1;
  return v4;
}

// File Line: 3315
// RVA: 0x7F95A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::IsValidName(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *name)
{
  unsigned int v5; // ebx
  unsigned int Length; // esi
  Scaleform::GFx::ASStringNode *pNode; // r14
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h] BYREF

  if ( Scaleform::GFx::ASConstString::GetLength(name)
    && Scaleform::GFx::AS3::IsNameStartChar(&resulta, *name->pNode->pData)->Result )
  {
    v5 = 1;
    Length = Scaleform::GFx::ASConstString::GetLength(name);
    if ( Length <= 1 )
    {
LABEL_8:
      result->Result = 1;
    }
    else
    {
      pNode = name->pNode;
      while ( Scaleform::GFx::AS3::IsNameChar(&resulta, pNode->pData[v5])->Result )
      {
        if ( ++v5 >= Length )
          goto LABEL_8;
      }
      result->Result = 0;
    }
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))_;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,4,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3addNamespace;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,15,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3descendants;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,16,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3elements;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,22,long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, int *))Scaleform::GFx::AS3::Class::lengthGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,23,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,25,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,28,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *))Scaleform::GFx::AS3::Instances::fl::XML::AS3normalize;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,30,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3processingInstructions;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,31,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3prependChild;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3removeNamespace;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::XML,33,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3replace;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,34,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::XML::AS3setChildren;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,40,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *))Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf;
  return result;
}

// File Line: 3484
// RVA: 0x8589A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::prototypeGet(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v4 + 200));
  v5 = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( v5 )
    {
      if ( ((unsigned __int8)v5 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v5 - 1);
        result->pObject = pV;
        return;
      }
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
    result->pObject = pV;
  }
}

// File Line: 3500
// RVA: 0x7A82E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  char *pData; // r8
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::StringBuffer pstr; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::StringBuffer::StringBuffer(&pstr, pVM->MHeap);
  this->vfptr[8].ForEachChild_GC(this, (Scaleform::GFx::AS3::RefCountCollector<328> *)&pstr, 0i64);
  pData = &customCaption;
  if ( pstr.pData )
    pData = pstr.pData;
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         pVM->StringManagerRef,
         &resulta,
         pData,
         pstr.Size);
  pNode = v6->pNode;
  ++v6->pNode->RefCount;
  v8 = result->pNode;
  v9 = result->pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  result->pNode = pNode;
  v10 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pstr);
}

// File Line: 3514
// RVA: 0x79F280
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasOwnProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        bool *result,
        Scaleform::GFx::ASString *p)
{
  *result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))this->vfptr[9].Finalize_GC)(
              this,
              p);
}

// File Line: 3525
// RVA: 0x7A1AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // r8d
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // rdi
  const char *pData; // rax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASString v15; // [rsp+30h] [rbp-40h] BYREF
  __int64 v16; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v18; // [rsp+90h] [rbp+20h] BYREF

  v16 = -2i64;
  if ( argc )
  {
    v5 = argv->Flags & 0x1F;
    if ( v5 )
    {
      if ( v5 - 12 > 3 && v5 != 10 || argv->value.VS._1.VStr )
      {
        pObject = this->pTraits.pObject->pVM->PublicNamespace.pObject;
        prop_name.Kind = MN_QName;
        prop_name.Obj.pObject = pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
        prop_name.Name.Flags = 0;
        prop_name.Name.Bonus.pWeakProxy = 0i64;
        if ( (argv->Flags & 0x1F) - 12 <= 3
          && (v7 = argv->value.VS._1, v7.VStr)
          && (pData = v7.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
          && (pData[112] & 0x20) == 0 )
        {
          Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)&v7.VStr[1].16);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
            *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v7.VStr[1].RefCount);
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
                pNode = v15.pNode;
                v11 = v15.pNode->RefCount-- == 1;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              }
            }
            v12 = resulta.pNode;
            v11 = resulta.pNode->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          }
        }
        if ( Scaleform::GFx::AS3::GetVectorInd(&v18, &prop_name, (unsigned int *)&resulta)->Result
          && !LODWORD(resulta.pNode) )
        {
          Scaleform::GFx::AS3::Value::SetBool(result, 1);
          Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
          return;
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
      }
    }
  }
  Scaleform::GFx::AS3::Value::SetBool(result, 0);
}

// File Line: 3547
// RVA: 0x79AC80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3addNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *ns)
{
  unsigned int v6; // r9d
  Scaleform::GFx::AS3::VM *pVM; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdi
  bool v9; // zf
  Scaleform::GFx::AS3::Value v10; // [rsp+38h] [rbp-40h] BYREF

  v6 = ns->Flags & 0x1F;
  if ( !v6 || (v6 - 12 <= 3 || v6 == 10) && !ns->value.VS._1.VStr )
  {
LABEL_20:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      result,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
    return;
  }
  pVM = this->pTraits.pObject->pVM;
  v10.Flags = 0;
  v10.Bonus.pWeakProxy = 0i64;
  pObject = pVM->TraitsNamespace.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, __int64, Scaleform::GFx::AS3::Value *, char))pObject->pConstructor.pObject->Scaleform::GFx::AS3::Traits::vfptr[4].ForEachChild_GC)(
    pObject->pConstructor.pObject,
    &v10,
    1i64,
    ns,
    1);
  if ( !pVM->HandleException )
  {
    ((void (__fastcall *)(_QWORD, _QWORD))this->vfptr[7].ForEachChild_GC)(
      this,
      (Scaleform::GFx::AS3::Value::V1U)v10.value.VS._1.VStr);
    if ( (v10.Flags & 0x1F) > 9 )
    {
      if ( (v10.Flags & 0x200) != 0 )
      {
        v9 = v10.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v10.Bonus, 0, 24);
        v10.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
      }
    }
    goto LABEL_20;
  }
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
    {
      v9 = v10.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v10.Bonus, 0, 24);
      v10.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
}

// File Line: 3571
// RVA: 0x79AE80
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3appendChild(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Value *child)
{
  char v3; // [rsp+30h] [rbp+8h] BYREF

  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *))this->vfptr[7].~RefCountBaseGC<328>)(
    this,
    &v3,
    child);
}

// File Line: 3583
// RVA: 0x79AEF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3attribute(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *arg)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  unsigned int v6; // r9d
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *XMLListInstance; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v6 = arg->Flags & 0x1F;
  if ( v6 && (v6 - 12 > 3 && v6 != 10 || arg->value.VS._1.VStr) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, pVM, arg);
    mn.Kind |= 8u;
    if ( !pVM->HandleException )
    {
      XMLListInstance = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, &resulta, &mn);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        result,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)XMLListInstance->pV);
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *, __int64))this->vfptr[18].ForEachChild_GC)(
        this,
        &resulta,
        &mn,
        result->pObject,
        -2i64);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1508, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v11.Message.pNode;
    if ( v11.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 3608
// RVA: 0x79B200
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3attributes(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v5 + 200));
  v6 = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( v6 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v6 - 1);
      }
      else
      {
        RefCount = v6->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
    result->pObject = pV;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *))this->vfptr[14].Finalize_GC)(
    this,
    pV);
}

// File Line: 3622
// RVA: 0x79B570
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3child(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *propertyName)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  unsigned int v6; // r9d
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *XMLListInstance; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v6 = propertyName->Flags & 0x1F;
  if ( v6 && (v6 - 12 > 3 && v6 != 10 || propertyName->value.VS._1.VStr) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM, propertyName);
    if ( !pVM->HandleException )
    {
      XMLListInstance = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, &resulta, &mn);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        result,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)XMLListInstance->pV);
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Instances::fl::XMLList *, __int64))this->vfptr[18].ForEachChild_GC)(
        this,
        &resulta,
        &mn,
        result->pObject,
        -2i64);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1508, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v11.Message.pNode;
    if ( v11.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 3649
// RVA: 0x79B900
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3childIndex(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        int *result)
{
  char v3; // [rsp+30h] [rbp+8h] BYREF
  int v4; // [rsp+38h] [rbp+10h] BYREF

  *result = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, int *))this->vfptr[12].Finalize_GC)(
                   this,
                   &v3,
                   &v4) )
    *result = v4;
}

// File Line: 3664
// RVA: 0x79B9A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3children(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v5 + 200));
  v6 = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( v6 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v6 - 1);
      }
      else
      {
        RefCount = v6->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
    result->pObject = pV;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, _QWORD, _QWORD))this->vfptr[12].ForEachChild_GC)(
    this,
    pV,
    0i64,
    0i64);
}

// File Line: 3677
// RVA: 0x79BC00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::ASString *target_prop; // rdi
  Scaleform::GFx::AS3::VM *pVM; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *target_ns; // rbx
  __int64 v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v14; // [rsp+68h] [rbp+10h] BYREF

  target_prop = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateNullString(
                  this->pTraits.pObject->pVM->StringManagerRef,
                  &resulta);
  pVM = this->pTraits.pObject->pVM;
  target_ns = pVM->PublicNamespace.pObject;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pVM->XMLSupport_.pObject->vfptr[4].ForEachChild_GC)(pVM->XMLSupport_.pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v7 + 200),
    &v14,
    *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v7 + 200),
    this,
    target_prop,
    target_ns);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pObject = result->pObject;
  pV = v14.pV;
  if ( v14.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  this->vfptr[12].ForEachChild_GC(
    this,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)pV,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))3);
}

// File Line: 3690
// RVA: 0x79C070
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3contains(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        bool *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v4; // rdx
  const char *pData; // rax

  *result = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 )
  {
    v4 = value->value.VS._1;
    if ( v4.VStr )
    {
      pData = v4.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
        *result = ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[9].ForEachChild_GC)(this) == 1;
    }
  }
}

// File Line: 3707
// RVA: 0x79C180
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3copy(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML **v3; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx
  unsigned int RefCount; // eax
  char v7; // [rsp+30h] [rbp+8h] BYREF

  v3 = (Scaleform::GFx::AS3::Instances::fl::XML **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, _QWORD))this->vfptr[11].Finalize_GC)(
                                                     this,
                                                     &v7,
                                                     0i64);
  pObject = result->pObject;
  v5 = *v3;
  if ( *v3 != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
        result->pObject = v5;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = v5;
  }
}

// File Line: 3718
// RVA: 0x79C6C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3descendants(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v9; // rax
  Scaleform::GFx::AS3::Value::Extra *v10; // rax
  int v11; // esi
  _DWORD *v12; // r12
  Scaleform::GFx::AS3::Value::Extra v13; // rcx
  Scaleform::GFx::AS3::Value *p_resulta; // rdx
  char v15; // di
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r15
  unsigned int Flags; // r14d
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // r8
  Scaleform::GFx::AS3::Value::V1U v20; // r13
  const char *pData; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v27; // rcx
  int v28; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v29; // [rsp+30h] [rbp-71h] BYREF
  Scaleform::GFx::AS3::Value v30; // [rsp+38h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-49h] BYREF
  Scaleform::GFx::ASString v32; // [rsp+78h] [rbp-29h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+80h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v34; // [rsp+A0h] [rbp-1h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v35; // [rsp+A8h] [rbp+7h] BYREF
  Scaleform::GFx::ASString v36; // [rsp+B0h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v37; // [rsp+B8h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value::V1U v38; // [rsp+C0h] [rbp+1Fh]
  __int64 v39; // [rsp+C8h] [rbp+27h]

  v39 = -2i64;
  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &v35,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v9 + 200));
  Scaleform::GFx::AS3::Value::Pick(result, v35.pV);
  if ( argc )
  {
    Flags = argv->Flags;
    resulta.Flags = Flags;
    pWeakProxy = argv->Bonus.pWeakProxy;
    resulta.Bonus.pWeakProxy = pWeakProxy;
    resulta.value = argv->value;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        ++pWeakProxy->RefCount;
      }
      else
      {
        if ( (Flags & 0x1F) == 10 )
        {
          ++argv->value.VS._1.VStr->RefCount;
          goto LABEL_18;
        }
        if ( (Flags & 0x1F) > 0xA )
        {
          if ( (Flags & 0x1F) <= 0xF )
          {
            VObj = argv->value.VS._1;
          }
          else
          {
            if ( (Flags & 0x1F) > 0x11 )
              goto LABEL_18;
            VObj = (Scaleform::GFx::AS3::Value::V1U)argv->value.VS._2.VObj;
          }
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        }
      }
    }
LABEL_18:
    p_resulta = &resulta;
    v15 = 4;
    v12 = *(_DWORD **)&v30.Flags;
    v11 = (int)v29.pObject;
    goto LABEL_19;
  }
  v10 = (Scaleform::GFx::AS3::Value::Extra *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                               this->pTraits.pObject->pVM->StringManagerRef,
                                               &v37,
                                               pattern);
  v11 = 10;
  LODWORD(v29.pObject) = 10;
  v12 = 0i64;
  *(_QWORD *)&v30.Flags = 0i64;
  v13.pWeakProxy = v10->pWeakProxy;
  v30.Bonus = v13;
  if ( v13.pWeakProxy == (Scaleform::GFx::AS3::WeakProxy *)&v13.pWeakProxy->pObject[2].24 )
  {
    v30.Bonus.pWeakProxy = 0i64;
    v30.value.VS._1 = v38;
    v11 = 12;
    LODWORD(v29.pObject) = 12;
  }
  else
  {
    ++LODWORD(v13.pWeakProxy[1].pObject);
  }
  p_resulta = (Scaleform::GFx::AS3::Value *)&v29;
  v15 = 3;
  pWeakProxy = resulta.Bonus.pWeakProxy;
  Flags = resulta.Flags;
LABEL_19:
  v19 = this->pTraits.pObject->pVM->PublicNamespace.pObject;
  LODWORD(v30.value.VS._2.VObj) = 0;
  *(_QWORD *)&other.Flags = v19;
  if ( v19 )
    v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
  LODWORD(other.Bonus.pWeakProxy) = 0;
  other.value.VS._1.VStr = 0i64;
  if ( (p_resulta->Flags & 0x1F) - 12 <= 3
    && (v20 = p_resulta->value.VS._1, v20.VStr)
    && (pData = v20.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(
      (Scaleform::GFx::AS3::Value *)&other.Bonus,
      (Scaleform::GFx::ASString *)&v20.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v20.VStr[1].RefCount);
    LODWORD(v30.value.VS._2.VObj) &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe((Scaleform::GFx::AS3::Value *)&other.Bonus, p_resulta);
    if ( ((__int64)other.Bonus.pWeakProxy & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString((Scaleform::GFx::AS3::Value *)&other.Bonus, &v34);
      if ( v34.pNode->Size )
      {
        if ( *v34.pNode->pData == 64 )
        {
          LODWORD(v30.value.VS._2.VObj) |= 8u;
          v22 = Scaleform::GFx::ASString::Substring(&v34, &v36, 1, v34.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&other.Bonus, v22);
          pNode = v36.pNode;
          v24 = v36.pNode->RefCount-- == 1;
          if ( v24 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v25 = v34.pNode;
      v24 = v34.pNode->RefCount-- == 1;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    Flags = resulta.Flags;
    pWeakProxy = resulta.Bonus.pWeakProxy;
    v11 = (int)v29.pObject;
    v12 = *(_DWORD **)&v30.Flags;
  }
  if ( (v15 & 4) != 0 )
  {
    v15 &= ~4u;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v24 = pWeakProxy->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        memset(&resulta.Bonus, 0, 24);
        resulta.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
  }
  if ( (v15 & 2) != 0 )
  {
    v15 &= ~2u;
    if ( (v11 & 0x1Fu) > 9 )
    {
      if ( (v11 & 0x200) != 0 )
      {
        v24 = (*v12)-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
        memset(&v30, 0, 24);
        LODWORD(v29.pObject) = v11 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v29);
      }
    }
  }
  if ( (v15 & 1) != 0 )
  {
    v26 = v37.pNode;
    v24 = v37.pNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Value::V2U *))this->vfptr[2].~RefCountBaseGC<328>)(
    this,
    v35.pV,
    &v30.value.VS._2);
  if ( (unsigned __int64)((__int64)other.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)other.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v24 = LODWORD(other.value.VS._1.VStr->pData)-- == 1;
      if ( v24 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.value = 0ui64;
      v32.pNode = 0i64;
      LODWORD(other.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other.Bonus);
    }
  }
  v27 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&other.Flags;
  if ( *(_QWORD *)&other.Flags )
  {
    if ( (other.Flags & 1) != 0 )
    {
      --*(_QWORD *)&other.Flags;
    }
    else
    {
      v28 = *(_DWORD *)(*(_QWORD *)&other.Flags + 32i64);
      if ( (v28 & 0x3FFFFF) != 0 )
      {
        *(_DWORD *)(*(_QWORD *)&other.Flags + 32i64) = v28 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
      }
    }
  }
}

// File Line: 3733
// RVA: 0x79CEA0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3elements(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v9; // rax
  Scaleform::GFx::AS3::Value::V1U *v10; // rax
  unsigned int v11; // esi
  Scaleform::GFx::AS3::WeakProxy *v12; // r12
  Scaleform::GFx::AS3::Value::V1U v13; // rcx
  Scaleform::GFx::AS3::Value *p_other; // rdx
  char v15; // di
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r15
  unsigned int Flags; // r14d
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v19; // r8
  Scaleform::GFx::AS3::Value::V1U v20; // r13
  const char *pData; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v27; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v29; // [rsp+8h] [rbp-71h] BYREF
  int v30; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v31; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value v32; // [rsp+38h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v34; // [rsp+78h] [rbp-1h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+80h] [rbp+7h] BYREF
  Scaleform::GFx::ASString v36; // [rsp+88h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v37; // [rsp+90h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value::V2U v38; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::Value p; // [rsp+A0h] [rbp+27h]
  __int64 v40; // [rsp+E0h] [rbp+67h]

  *(_QWORD *)&p.Flags = -2i64;
  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v9 + 200));
  Scaleform::GFx::AS3::Value::Pick(result, resulta.pV);
  if ( argc )
  {
    Flags = argv->Flags;
    other.Flags = Flags;
    pWeakProxy = argv->Bonus.pWeakProxy;
    other.Bonus.pWeakProxy = pWeakProxy;
    other.value = argv->value;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        ++pWeakProxy->RefCount;
      }
      else
      {
        if ( (Flags & 0x1F) == 10 )
        {
          ++argv->value.VS._1.VStr->RefCount;
          goto LABEL_18;
        }
        if ( (Flags & 0x1F) > 0xA )
        {
          if ( (Flags & 0x1F) <= 0xF )
          {
            VObj = argv->value.VS._1;
          }
          else
          {
            if ( (Flags & 0x1F) > 0x11 )
              goto LABEL_18;
            VObj = (Scaleform::GFx::AS3::Value::V1U)argv->value.VS._2.VObj;
          }
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        }
      }
    }
LABEL_18:
    p_other = &other;
    v15 = 4;
    v12 = v29.Bonus.pWeakProxy;
    v11 = v29.Flags;
    goto LABEL_19;
  }
  v10 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                             this->pTraits.pObject->pVM->StringManagerRef,
                                             &v37,
                                             pattern);
  v11 = 10;
  v29.Flags = 10;
  v12 = 0i64;
  v29.Bonus.pWeakProxy = 0i64;
  v13 = *v10;
  v29.value.VS._1 = v13;
  if ( v13.VStr == &v13.VStr->pManager->NullStringNode )
  {
    v29.value.VS._1.VStr = 0i64;
    v29.value.VS._2 = v38;
    v11 = 12;
    v29.Flags = 12;
  }
  else
  {
    ++v13.VStr->RefCount;
  }
  p_other = &v29;
  v15 = 3;
  pWeakProxy = other.Bonus.pWeakProxy;
  Flags = other.Flags;
LABEL_19:
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->PublicNamespace.pObject;
  v30 = 0;
  v31.pObject = v19;
  if ( v19 )
    v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
  v32.Flags = 0;
  v32.Bonus.pWeakProxy = 0i64;
  if ( (p_other->Flags & 0x1F) - 12 <= 3
    && (v20 = p_other->value.VS._1, v20.VStr)
    && (pData = v20.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v32, (Scaleform::GFx::ASString *)&v20.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v31,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v20.VStr[1].RefCount);
    v30 &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v32, p_other);
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
          pNode = v36.pNode;
          v24 = v36.pNode->RefCount-- == 1;
          if ( v24 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v25 = v34.pNode;
      v24 = v34.pNode->RefCount-- == 1;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    Flags = other.Flags;
    pWeakProxy = other.Bonus.pWeakProxy;
    v11 = v29.Flags;
    v12 = v29.Bonus.pWeakProxy;
  }
  if ( (v15 & 4) != 0 )
  {
    v15 &= ~4u;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v24 = pWeakProxy->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        memset(&other.Bonus, 0, 24);
        other.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  if ( (v15 & 2) != 0 )
  {
    v15 &= ~2u;
    if ( (v11 & 0x1F) > 9 )
    {
      if ( (v11 & 0x200) != 0 )
      {
        v24 = v12->RefCount-- == 1;
        if ( v24 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
        memset(&v29.Bonus, 0, 24);
        v29.Flags = v11 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
      }
    }
  }
  if ( (v15 & 1) != 0 )
  {
    v26 = v37.pNode;
    v24 = v37.pNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS3::Instances::fl::XMLList *, int *))(*(_QWORD *)v40 + 296i64))(
    v40,
    resulta.pV,
    &v30);
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags & 0x200) != 0 )
    {
      v24 = v32.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v24 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v32.Bonus, 0, 24);
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
    if ( ((__int64)v31.pObject & 1) != 0 )
    {
      --v31.pObject;
    }
    else
    {
      RefCount = v31.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v31.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
      }
    }
  }
}

// File Line: 3748
// RVA: 0x79EFD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasComplexContent(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        bool *result)
{
  *result = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[9].~RefCountBaseGC<328>)(this) == 0;
}

// File Line: 3759
// RVA: 0x79F2A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3hasSimpleContent(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        bool *result)
{
  *result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[9].~RefCountBaseGC<328>)(this);
}

// File Line: 3770
// RVA: 0x79F370
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3inScopeNamespaces(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rdi
  unsigned int RefCount; // eax
  __int64 v7; // rax
  _QWORD *v8; // rdx
  unsigned __int64 v9; // rax
  Scaleform::GFx::AS3::Value::V1U v10; // r13
  unsigned int Size; // r15d
  const char *pData; // rdx
  _DWORD *pLower; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> >::TableType *pTable; // rbx
  __int64 v15; // r12
  __int64 v16; // rsi
  __int64 v17; // r14
  unsigned __int64 Length; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int v22; // eax
  __int64 v23; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // r9
  Scaleform::GFx::ASStringNode *VStr; // r8
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned int v27; // eax
  unsigned int v28; // eax
  Scaleform::GFx::AS3::Value::V1U v29; // rdx
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v31; // rcx
  unsigned int v32; // eax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> >::TableType *v33; // rdx
  __int64 v34; // rsi
  unsigned __int64 v35; // r14
  Scaleform::GFx::AS3::Value *v36; // rdi
  Scaleform::GFx::AS3::WeakProxy *v37; // rdx
  Scaleform::GFx::AS3::Value v; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value source; // [rsp+40h] [rbp-59h] BYREF
  _QWORD *v40; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *p_pTraits; // [rsp+68h] [rbp-31h]
  unsigned __int64 v42; // [rsp+70h] [rbp-29h]
  const char *v43; // [rsp+78h] [rbp-21h]
  Scaleform::GFx::AS3::Value::V1U pManager; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::Value::V2U v45; // [rsp+88h] [rbp-11h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+90h] [rbp-9h] BYREF
  __int64 v47; // [rsp+A0h] [rbp+7h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> > pmemAddr; // [rsp+108h] [rbp+6Fh] BYREF
  unsigned __int64 v50; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::AS3::Instances::fl::XML *v51; // [rsp+118h] [rbp+7Fh]

  v47 = -2i64;
  v3 = this;
  v51 = this;
  p_pTraits = &this->pTraits;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  pmemAddr.pTable = 0i64;
  do
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[6].Finalize_GC)(v3);
    v8 = (_QWORD *)v7;
    v40 = (_QWORD *)v7;
    if ( v7 )
    {
      v42 = *(_QWORD *)(v7 + 8);
      v9 = 0i64;
      v50 = 0i64;
      if ( v42 )
      {
        while ( 1 )
        {
          v10 = *(Scaleform::GFx::AS3::Value::V1U *)(*v8 + 8 * v9);
          Size = v10.VStr[1].Size;
          v.Flags = Size;
          pData = v10.VStr[2].pData;
          v43 = pData;
          v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pData;
          pManager = (Scaleform::GFx::AS3::Value::V1U)v10.VStr[2].pManager;
          v.value.VS._1 = pManager;
          v45.VObj = (Scaleform::GFx::AS3::Object *)v10.VStr[2].pLower;
          v.value.VS._2 = v45;
          if ( (Size & 0x1F) > 9 )
          {
            if ( (Size & 0x200) != 0 )
            {
              ++*(_DWORD *)pData;
            }
            else
            {
              if ( (Size & 0x1F) == 10 )
              {
                ++LODWORD(v10.VStr[2].pManager->pHeap);
                goto LABEL_23;
              }
              if ( (Size & 0x1F) > 0xA )
              {
                if ( (Size & 0x1F) <= 0xF )
                {
                  pLower = v10.VStr[2].pManager;
                }
                else
                {
                  if ( (Size & 0x1F) > 0x11 )
                    goto LABEL_23;
                  pLower = v10.VStr[2].pLower;
                }
                if ( pLower )
                  pLower[8] = (pLower[8] + 1) & 0x8FBFFFFF;
              }
            }
          }
LABEL_23:
          pTable = pmemAddr.pTable;
          if ( !pmemAddr.pTable )
            goto LABEL_32;
          v15 = pTable->SizeMask & Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                                     (Scaleform::GFx::AS3::Value::HashFunctor *)&resulta,
                                     &v);
          v16 = v15;
          v17 = (__int64)&pTable[3 * v15 + 1];
          if ( *(_QWORD *)v17 == -2i64 || *(_QWORD *)(v17 + 8) != v15 )
            goto LABEL_32;
          while ( *(_QWORD *)(v17 + 8) != v15
               || !Scaleform::GFx::AS3::StrictEqual((Scaleform::GFx::AS3::Value *)(v17 + 16), &v) )
          {
            v16 = *(_QWORD *)v17;
            if ( *(_QWORD *)v17 == -1i64 )
              goto LABEL_32;
            v17 = (__int64)&pTable[3 * v16 + 1];
          }
          if ( v16 >= 0 && &pTable[3 * v16 + 2] )
          {
            pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v43;
            VStr = pManager.VStr;
            VObj = v45.VObj;
          }
          else
          {
LABEL_32:
            source.Flags = 11;
            source.Bonus.pWeakProxy = 0i64;
            source.value.VS._1 = v10;
            v10.VStr->Size = (v10.VStr->Size + 1) & 0x8FBFFFFF;
            Length = pV->SA.Length;
            if ( Length == pV->SA.ValueA.Data.Size )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &pV->SA.ValueA.Data,
                pV->SA.ValueA.Data.pHeap,
                pV->SA.ValueA.Data.Size + 1);
              Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
                &pV->SA.ValueA.Data.Data[pV->SA.ValueA.Data.Size - 1],
                &source);
            }
            else
            {
              pV->SA.ValueHHighInd = Length;
              key.pFirst = &pV->SA.ValueHHighInd;
              key.pSecond = &source;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                &pV->SA.ValueH.mHash,
                pV->SA.ValueH.mHash.pHeap,
                &key);
            }
            ++pV->SA.Length;
            if ( (source.Flags & 0x1F) > 9 )
            {
              if ( (source.Flags & 0x200) != 0 )
              {
                v19 = source.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v19 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&source.Bonus, 0, 24);
                source.Flags &= 0xFFFFFDE0;
              }
              else
              {
                switch ( source.Flags & 0x1F )
                {
                  case 0xA:
                    v20 = source.value.VS._1.VStr;
                    v19 = source.value.VS._1.VStr->RefCount-- == 1;
                    if ( v19 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
                    break;
                  case 0xB:
                  case 0xC:
                  case 0xD:
                  case 0xE:
                  case 0xF:
                    v21 = source.value.VS._1.VObj;
                    if ( !source.value.VS._1.VBool )
                      goto LABEL_47;
                    --source.value.VS._1.VStr;
                    break;
                  case 0x10:
                  case 0x11:
                    v21 = source.value.VS._2.VObj;
                    if ( ((__int64)source.value.VS._2.VObj & 1) != 0 )
                    {
                      --source.value.VS._2.VObj;
                    }
                    else
                    {
LABEL_47:
                      if ( v21 )
                      {
                        v22 = v21->RefCount;
                        if ( (v22 & 0x3FFFFF) != 0 )
                        {
                          v21->RefCount = v22 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
                        }
                      }
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            v23 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                    (Scaleform::GFx::AS3::Value::HashFunctor *)&resulta,
                    &v);
            Scaleform::HashSetBase<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>::add<Scaleform::GFx::AS3::Value>(
              &pmemAddr,
              &pmemAddr,
              &v,
              v23);
            VObj = v.value.VS._2.VObj;
            VStr = v.value.VS._1.VStr;
            pWeakProxy = v.Bonus.pWeakProxy;
            Size = v.Flags;
          }
          if ( (Size & 0x1F) > 9 )
          {
            if ( (Size & 0x200) != 0 )
            {
              v19 = pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                  Scaleform::Memory::pGlobalHeap,
                  pWeakProxy,
                  VStr,
                  VObj);
              memset(&v.Bonus, 0, 24);
              v.Flags = Size & 0xFFFFFDE0;
            }
            else
            {
              switch ( Size & 0x1F )
              {
                case 0xAu:
                  v19 = VStr->RefCount-- == 1;
                  if ( v19 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
                  break;
                case 0xBu:
                case 0xCu:
                case 0xDu:
                case 0xEu:
                case 0xFu:
                  if ( v.value.VS._1.VBool )
                  {
                    v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)VStr - 1);
                  }
                  else if ( VStr )
                  {
                    v27 = VStr->Size;
                    if ( (v27 & 0x3FFFFF) != 0 )
                    {
                      VStr->Size = v27 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VStr);
                    }
                  }
                  break;
                case 0x10u:
                case 0x11u:
                  if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
                  {
                    v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj[-1].RefCount + 7);
                  }
                  else if ( VObj )
                  {
                    v28 = VObj->RefCount;
                    if ( (v28 & 0x3FFFFF) != 0 )
                    {
                      VObj->RefCount = v28 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                    }
                  }
                  break;
                default:
                  break;
              }
            }
          }
          v9 = v50 + 1;
          v50 = v9;
          v8 = v40;
          if ( v9 >= v42 )
          {
            v3 = v51;
            break;
          }
        }
      }
    }
    v3 = v3->Parent.pObject;
    v51 = v3;
  }
  while ( v3 );
  if ( !pV->SA.Length )
  {
    v29 = (Scaleform::GFx::AS3::Value::V1U)p_pTraits->pObject->pVM->PublicNamespace.pObject;
    v.Flags = 11;
    v.Bonus.pWeakProxy = 0i64;
    v.value.VS._1 = v29;
    if ( v29.VStr )
      v29.VStr->Size = (v29.VStr->Size + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&pV->SA, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v.Bonus, 0, 24);
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v.Flags & 0x1F )
        {
          case 0xA:
            v30 = v.value.VS._1.VStr;
            v19 = v.value.VS._1.VStr->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            v31 = v.value.VS._1.VObj;
            if ( !v.value.VS._1.VBool )
              goto LABEL_88;
            --v.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            v31 = v.value.VS._2.VObj;
            if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
LABEL_88:
              if ( v31 )
              {
                v32 = v31->RefCount;
                if ( (v32 & 0x3FFFFF) != 0 )
                {
                  v31->RefCount = v32 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
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
  v33 = pmemAddr.pTable;
  if ( pmemAddr.pTable )
  {
    v34 = 0i64;
    v35 = pmemAddr.pTable->SizeMask + 1;
    do
    {
      v36 = (Scaleform::GFx::AS3::Value *)&v33[v34];
      if ( v33[v34 + 1].EntryCount != -2i64 )
      {
        if ( (v36[1].Flags & 0x1F) > 9 )
        {
          if ( (v36[1].Flags & 0x200) != 0 )
          {
            v37 = v36[1].Bonus.pWeakProxy;
            v19 = v37->RefCount-- == 1;
            if ( v19 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v36[1].Bonus.pWeakProxy = 0i64;
            v36[1].value.VS._1.VStr = 0i64;
            v36[1].value.VS._2.VObj = 0i64;
            v36[1].Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(v36 + 1);
          }
        }
        v36->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)-2i64;
        v33 = pmemAddr.pTable;
      }
      v34 += 3i64;
      --v35;
    }
    while ( v35 );
    if ( v33 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 3811
// RVA: 0x79FB30
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildAfter(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *child1,
        Scaleform::GFx::AS3::Value *child2)
{
  char v6; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))this->vfptr[13].~RefCountBaseGC<328>)(
                   this,
                   &v6,
                   child1,
                   child2) )
    Scaleform::GFx::AS3::Value::Assign(result, this);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(result);
}

// File Line: 3825
// RVA: 0x79FC00
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildBefore(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *child1,
        Scaleform::GFx::AS3::Value *child2)
{
  char v6; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))this->vfptr[13].Finalize_GC)(
                   this,
                   &v6,
                   child1,
                   child2) )
    Scaleform::GFx::AS3::Value::Assign(result, this);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(result);
}

// File Line: 3839
// RVA: 0x851620
void __fastcall Scaleform::GFx::AS3::Class::lengthGet(Scaleform::GFx::AS3::Class *this, int *result)
{
  *result = 1;
}

// File Line: 3845
// RVA: 0x86BAA0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = this->Url.pNode;
  ++pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    result->pNode = pNode;
  }
  else
  {
    result->pNode = pNode;
  }
}

// File Line: 3856
// RVA: 0x7A0A50
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3name(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v3; // rax
  Scaleform::GFx::AS3::Instances::fl::QName **p_pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::QName *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // [rsp+40h] [rbp+8h] BYREF

  v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))this->vfptr[15].ForEachChild_GC)(
                                                                                 this,
                                                                                 &v9);
  p_pObject = &v3->pObject;
  if ( v3 != result )
  {
    if ( v3->pObject )
      v3->pObject->RefCount = (v3->pObject->RefCount + 1) & 0x8FBFFFFF;
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::QName *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = *p_pObject;
  }
  v7 = v9;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v9 - 1);
    }
    else
    {
      v8 = v9->RefCount;
      if ( (v8 & 0x3FFFFF) != 0 )
      {
        v9->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
}

// File Line: 3867
// RVA: 0x7A1140
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h] BYREF
  __int64 v12; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+50h] [rbp+18h] BYREF

  v12 = -2i64;
  if ( argc )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      this->pTraits.pObject->pVM->StringManagerRef,
      &resulta);
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v13, &resulta)->Result )
    {
      v8 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, _QWORD))this->vfptr[15].Finalize_GC)(
                                                              this,
                                                              &resulta,
                                                              0i64);
      if ( v8 )
        Scaleform::GFx::AS3::Value::Assign(result, v8);
      else
        Scaleform::GFx::AS3::Value::SetUndefined(result);
    }
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v7 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[11].~RefCountBaseGC<328>)(this);
    Scaleform::GFx::AS3::Value::Assign(result, v7);
  }
}

// File Line: 3896
// RVA: 0x7A0B40
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespaceDeclarations(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rsi
  Scaleform::GFx::AS3::VM *pVM; // r14
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::MemoryHeap *MHeap; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rcx
  __int64 v10; // rax
  _QWORD *v11; // rbx
  unsigned __int64 v12; // r13
  unsigned __int64 Size; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // r15
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
  Scaleform::GFx::AS3::Instances::fl::Array *v30; // rdx
  int v31; // eax
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v33; // rcx
  bool v34; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int v37; // eax
  unsigned __int64 v38; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *j; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v40; // rcx
  unsigned int v41; // eax
  unsigned __int64 v42; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *k; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v44; // rcx
  unsigned int v45; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v46; // [rsp+20h] [rbp-69h] BYREF
  void *pheapAddr; // [rsp+38h] [rbp-51h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v48; // [rsp+40h] [rbp-49h] BYREF
  void *v49; // [rsp+58h] [rbp-31h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::VM *v51; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v52; // [rsp+88h] [rbp-1h]
  __int64 v53; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v54; // [rsp+98h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::XML *v56; // [rsp+F8h] [rbp+6Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+100h] [rbp+77h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v58; // [rsp+108h] [rbp+7Fh]

  v53 = -2i64;
  v3 = this;
  pVM = this->pTraits.pObject->pVM;
  v51 = pVM;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)pVM->TraitsArray.pObject->ITraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v3->vfptr[8].Finalize_GC)(v3) - 2 > 3 )
  {
    MHeap = pVM->MHeap;
    v58 = &v46;
    memset(&v46, 0, sizeof(v46));
    pheapAddr = MHeap;
    v9 = v3->Parent.pObject;
    v56 = v9;
    if ( v9 )
    {
      do
      {
        v10 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v9->vfptr[6].Finalize_GC)(v9);
        v11 = (_QWORD *)v10;
        if ( v10 )
        {
          v12 = 0i64;
          if ( *(_QWORD *)(v10 + 8) )
          {
            Size = v46.Size;
            Data = v46.Data;
            do
            {
              v15 = *(Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> **)(*v11 + 8 * v12);
              v16 = (__int64)v15[3].Data & 0x1F;
              if ( v16 && ((unsigned int)(v16 - 12) > 3 && v16 != 10 || v15[3].Policy.Capacity) )
              {
                v17 = 0i64;
                if ( Size )
                {
                  while ( !Scaleform::GFx::AS3::StrictEqual(
                             (Scaleform::GFx::AS3::Value *)&Data[v17].pObject[1],
                             (Scaleform::GFx::AS3::Value *)&v15[3]) )
                  {
                    if ( ++v17 >= Size )
                      goto LABEL_20;
                  }
                }
                else
                {
LABEL_20:
                  v18 = 0i64;
                  if ( Size )
                  {
                    while ( 1 )
                    {
                      v19 = Data[v18].pObject;
                      if ( v19->Text.pNode == (Scaleform::GFx::ASStringNode *)v15[2].Size
                        && ((LOBYTE(v15[1].Policy.Capacity) ^ LOBYTE(v19->pTraits.pObject)) & 0xF) == 0 )
                      {
                        break;
                      }
                      if ( ++v18 >= Size )
                        goto LABEL_24;
                    }
                  }
                  else
                  {
LABEL_24:
                    v58 = v15;
                    if ( v15 )
                      LODWORD(v15[1].Size) = (LODWORD(v15[1].Size) + 1) & 0x8FBFFFFF;
                    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                      &v46,
                      pheapAddr,
                      v46.Size + 1);
                    v20 = &v46.Data[v46.Size - 1];
                    v54 = v20;
                    v52 = v20;
                    if ( v20 )
                    {
                      v20->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v15;
                      if ( v15 )
                        LODWORD(v15[1].Size) = (LODWORD(v15[1].Size) + 1) & 0x8FBFFFFF;
                    }
                    if ( v15 )
                    {
                      if ( ((unsigned __int8)v15 & 1) != 0 )
                      {
                        v58 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v15 - 1);
                      }
                      else
                      {
                        v21 = v15[1].Size;
                        if ( (v21 & 0x3FFFFF) != 0 )
                        {
                          LODWORD(v15[1].Size) = v21 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v15);
                        }
                      }
                    }
                    Size = v46.Size;
                    Data = v46.Data;
                  }
                }
              }
              ++v12;
            }
            while ( v12 < v11[1] );
          }
        }
        v9 = v56->Parent.pObject;
        v56 = v9;
      }
      while ( v9 );
      pV = resulta.pV;
      v3 = this;
      pVM = v51;
    }
    v22 = pVM->MHeap;
    memset(&v48, 0, sizeof(v48));
    v49 = v22;
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
            if ( v48.Size )
            {
              while ( 1 )
              {
                v29 = v48.Data[v28].pObject;
                if ( v29->Text.pNode == *(Scaleform::GFx::ASStringNode **)(v26 + 56)
                  && ((*(_BYTE *)(v26 + 40) ^ LOBYTE(v29->pTraits.pObject)) & 0xF) == 0 )
                {
                  break;
                }
                if ( ++v28 >= v48.Size )
                  goto LABEL_48;
              }
            }
            else
            {
LABEL_48:
              if ( v26 )
                *(_DWORD *)(v26 + 32) = (*(_DWORD *)(v26 + 32) + 1) & 0x8FBFFFFF;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v48,
                v49,
                v48.Size + 1);
              v30 = (Scaleform::GFx::AS3::Instances::fl::Array *)&v48.Data[v48.Size - 1];
              resulta.pV = v30;
              if ( v30 )
              {
                v30->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v26;
                if ( v26 )
                  *(_DWORD *)(v26 + 32) = (*(_DWORD *)(v26 + 32) + 1) & 0x8FBFFFFF;
              }
              if ( v26 )
              {
                if ( (v26 & 1) == 0 )
                {
                  v31 = *(_DWORD *)(v26 + 32);
                  if ( (v31 & 0x3FFFFF) != 0 )
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
    for ( i = 0i64; i < v48.Size; ++i )
    {
      v33 = v48.Data[i].pObject;
      v.Flags = 11;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v33;
      if ( v33 )
        v33->RefCount = (v33->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&pV->SA, &v);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          v34 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v34 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v.Bonus, 0, 24);
          v.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v.Flags & 0x1F )
          {
            case 0xA:
              VStr = v.value.VS._1.VStr;
              v34 = v.value.VS._1.VStr->RefCount-- == 1;
              if ( v34 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              VObj = v.value.VS._1.VObj;
              if ( !v.value.VS._1.VBool )
                goto LABEL_73;
              --v.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              VObj = v.value.VS._2.VObj;
              if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
              {
                --v.value.VS._2.VObj;
              }
              else
              {
LABEL_73:
                if ( VObj )
                {
                  v37 = VObj->RefCount;
                  if ( (v37 & 0x3FFFFF) != 0 )
                  {
                    VObj->RefCount = v37 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                  }
                }
              }
              break;
            default:
              continue;
          }
        }
      }
    }
    v38 = v48.Size;
    for ( j = &v48.Data[v48.Size - 1]; v38; --v38 )
    {
      v40 = j->pObject;
      if ( j->pObject )
      {
        if ( ((unsigned __int8)v40 & 1) != 0 )
        {
          j->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v40 - 1);
        }
        else
        {
          v41 = v40->RefCount;
          if ( (v41 & 0x3FFFFF) != 0 )
          {
            v40->RefCount = v41 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v40);
          }
        }
      }
      --j;
    }
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v42 = v46.Size;
    for ( k = &v46.Data[v46.Size - 1]; v42; --v42 )
    {
      v44 = k->pObject;
      if ( k->pObject )
      {
        if ( ((unsigned __int8)v44 & 1) != 0 )
        {
          k->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v44 - 1);
        }
        else
        {
          v45 = v44->RefCount;
          if ( (v45 & 0x3FFFFF) != 0 )
          {
            v44->RefCount = v45 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v44);
          }
        }
      }
      --k;
    }
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 3959
// RVA: 0x7A1260
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  const char *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v3 = 0i64;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[8].Finalize_GC)(this) - 1;
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
  Scaleform::GFx::ASString::operator=(result, v3);
}

// File Line: 3993
// RVA: 0x7A1310
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3normalize(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  this->vfptr[15].~RefCountBaseGC<328>(this);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
}

// File Line: 4004
// RVA: 0x7A13A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3parent(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rdx

  pObject = this->Parent.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Value::Assign(result, pObject);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(result);
}

// File Line: 4018
// RVA: 0x7A15C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3processingInstructions(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+20h] [rbp-28h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::ASString v14; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+60h] [rbp+18h] BYREF

  v13 = -2i64;
  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v9 + 200));
  Scaleform::GFx::AS3::Value::Pick(result, resulta.pV);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &v14);
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2String(argv, &v15, &v14);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XMLList *, __int64, Scaleform::GFx::ASString *))this->vfptr[12].ForEachChild_GC)(
    this,
    resulta.pV,
    4i64,
    &v14);
  pNode = v14.pNode;
  if ( v14.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 4037
// RVA: 0x7A14E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3prependChild(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  char v7; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, _QWORD, Scaleform::GFx::AS3::Value *))this->vfptr[13].ForEachChild_GC)(
                   this,
                   &v7,
                   0i64,
                   value) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      result,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
  }
  else
  {
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        result->pObject = 0i64;
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
        result->pObject = 0i64;
      }
    }
  }
}

// File Line: 4051
// RVA: 0x7A1DC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3removeNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[16].Finalize_GC)(
                                                        this,
                                                        ns);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v4);
}

// File Line: 4062
// RVA: 0x7A22F0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3replace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *propertyName,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Class *v9; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rax
  bool v11; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v14; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::Multiname v15; // [rsp+40h] [rbp+Fh] BYREF
  char v16[8]; // [rsp+98h] [rbp+67h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::Multiname::Multiname(&v15, pVM, propertyName);
  if ( !pVM->HandleException )
  {
    if ( Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, value)->TraitsType != Traits_String )
    {
      if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))this->vfptr[17].~RefCountBaseGC<328>)(
                        this,
                        v16,
                        &v15,
                        value) )
        goto LABEL_21;
      goto LABEL_20;
    }
    v14.Flags = 0;
    v14.Bonus.pWeakProxy = 0i64;
    pObject = this->pTraits.pObject;
    if ( !pObject->pConstructor.pObject )
      pObject->vfptr[3].~RefCountBaseGC<328>(this->pTraits.pObject);
    v9 = pObject->pConstructor.pObject;
    vfptr = v9->vfptr;
    LOBYTE(v14.Flags) = 0;
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, __int64, Scaleform::GFx::AS3::Value *))vfptr[4].ForEachChild_GC)(
      v9,
      &v14,
      1i64,
      value);
    if ( !this->pTraits.pObject->pVM->HandleException
      && *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))this->vfptr[17].~RefCountBaseGC<328>)(
                     this,
                     v16,
                     &v15,
                     &v14) )
    {
      if ( (v14.Flags & 0x1F) > 9 )
      {
        if ( (v14.Flags & 0x200) != 0 )
        {
          v11 = v14.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v14.Bonus, 0, 24);
          v14.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
        }
      }
LABEL_20:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        result,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
      goto LABEL_21;
    }
    if ( (v14.Flags & 0x1F) > 9 )
    {
      if ( (v14.Flags & 0x200) != 0 )
      {
        v11 = v14.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v14.Bonus, 0, 24);
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
    if ( (v15.Name.Flags & 0x200) != 0 )
    {
      v11 = v15.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v15.Name.Bonus, 0, 24);
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
    if ( ((__int64)v15.Obj.pObject & 1) != 0 )
    {
      --v15.Obj.pObject;
    }
    else
    {
      RefCount = v15.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v15.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
}

// File Line: 4099
// RVA: 0x7A28B0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setChildren(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *value)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[17].Finalize_GC)(
    this,
    value);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
}

// File Line: 4111
// RVA: 0x7A2B60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setLocalName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *name)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::Value::V1U v7; // rdx
  const char *pData; // rax
  Scaleform::GFx::ASStringNode *pLower; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+8h] BYREF

  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result)
     - 2 > 1 )
  {
    pVM = this->pTraits.pObject->pVM;
    v6 = name->Flags & 0x1F;
    if ( v6 - 12 <= 3
      && (v7 = name->value.VS._1, v7.VStr)
      && (pData = v7.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      pLower = v7.VStr[1].pLower;
      ++pLower->RefCount;
      pNode = this->Text.pNode;
      v11 = pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      this->Text.pNode = pLower;
    }
    else if ( v6 )
    {
      Scaleform::GFx::AS3::Value::Convert2String(name, &resulta, &this->Text);
    }
    if ( !Scaleform::GFx::AS3::IsValidName(&resulta, &this->Text)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v14, 1117, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v13 = v14.Message.pNode;
      v11 = v14.Message.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
}

// File Line: 4135
// RVA: 0x7A2EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *name)
{
  int v5; // ebp
  Scaleform::GFx::AS3::VM *pVM; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  unsigned int v8; // ecx
  Scaleform::GFx::ASStringNode *VStr; // rsi
  const char *pData; // rax
  Scaleform::GFx::ASStringNode *pLower; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rsi
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+88h] [rbp+20h] BYREF

  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result);
  if ( (unsigned int)(v5 - 2) > 1 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      pVM->StringManagerRef,
      &resulta);
    v7 = 0i64;
    v8 = name->Flags & 0x1F;
    if ( v8 - 12 <= 3
      && (VStr = name->value.VS._1.VStr) != 0i64
      && (pData = VStr[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      if ( *(_QWORD *)&VStr[1].RefCount )
        this->vfptr[10].Finalize_GC(this);
      pLower = VStr[1].pLower;
      ++pLower->RefCount;
      pNode = resulta.pNode;
      v13 = resulta.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      resulta.pNode = pLower;
      v7 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)&VStr[1].RefCount;
    }
    else if ( v8 && !Scaleform::GFx::AS3::Value::Convert2String(name, &v21, &resulta)->Result )
    {
      goto LABEL_13;
    }
    if ( Scaleform::GFx::AS3::IsValidName(&v21, &resulta)->Result )
    {
      v16 = resulta.pNode;
      ++resulta.pNode->RefCount;
      v17 = this->Text.pNode;
      v13 = v17->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      this->Text.pNode = v16;
      if ( v7 )
      {
        if ( v5 == 5 )
        {
          pObject = this->Parent.pObject;
          if ( pObject )
            ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))pObject->vfptr[7].ForEachChild_GC)(
              pObject,
              v7);
        }
        else if ( v5 == 1 )
        {
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))this->vfptr[7].ForEachChild_GC)(
            this,
            v7);
        }
      }
      else
      {
        v7 = pVM->PublicNamespace.pObject;
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))this->vfptr[10].Finalize_GC)(
        this,
        v7);
LABEL_26:
      v19 = resulta.pNode;
      v13 = resulta.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      return;
    }
LABEL_13:
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 1117, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v15 = v20.Message.pNode;
    v13 = v20.Message.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    goto LABEL_26;
  }
}

// File Line: 4184
// RVA: 0x7A3110
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3setNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *ns)
{
  int v5; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rax
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+68h] [rbp+20h] BYREF

  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))this->vfptr[8].Finalize_GC)(
         this,
         result);
  if ( (unsigned int)(v5 - 2) <= 2 )
    return;
  pV = Scaleform::GFx::AS3::VM::MakeNamespace(this->pTraits.pObject->pVM, &resulta, NS_Public)->pV;
  pV->vfptr[1].ForEachChild_GC(
    pV,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)1,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))ns);
  if ( v5 == 5 )
  {
    pObject = this->Parent.pObject;
    if ( !pObject )
      goto LABEL_9;
    vfptr = pObject->vfptr;
    goto LABEL_7;
  }
  if ( v5 == 1 )
  {
    vfptr = this->vfptr;
    pObject = this;
LABEL_7:
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))vfptr[7].ForEachChild_GC)(
      pObject,
      pV);
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::Namespace *))this->vfptr[10].Finalize_GC)(
    this,
    pV);
LABEL_9:
  if ( ((unsigned __int8)pV & 1) == 0 )
  {
    RefCount = pV->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pV->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
    }
  }
}

// File Line: 4235
// RVA: 0x7A70C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3text(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    &resulta,
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v5 + 200));
  v6 = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( v6 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v6 - 1);
      }
      else
      {
        RefCount = v6->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
    result->pObject = pV;
  }
  this->vfptr[12].ForEachChild_GC(
    this,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)pV,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))2);
}

// File Line: 4248
// RVA: 0x7A8BB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  char *pData; // r8
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::StringBuffer pstr; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::StringBuffer::StringBuffer(&pstr, pVM->MHeap);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::StringBuffer *, _QWORD, _QWORD, _QWORD))this->vfptr[8].~RefCountBaseGC<328>)(
    this,
    &pstr,
    0i64,
    0i64,
    0i64);
  pData = &customCaption;
  if ( pstr.pData )
    pData = pstr.pData;
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         pVM->StringManagerRef,
         &resulta,
         pData,
         pstr.Size);
  pNode = v6->pNode;
  ++v6->pNode->RefCount;
  v8 = result->pNode;
  v9 = result->pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  result->pNode = pNode;
  v10 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pstr);
}

// File Line: 4301
// RVA: 0x79BBC0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  result->pObject = 0i64;
  Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(this, result);
  return result;
}

// File Line: 4337
// RVA: 0x785100
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::XML(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pNode = n->pNode;
  this->Text = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  this->Parent.pObject = p;
  if ( p )
    p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 4341
// RVA: 0x78FDD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::~XML(Scaleform::GFx::AS3::Instances::fl::XML *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
  pObject = this->Parent.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  pNode = this->Text.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 4369
// RVA: 0x800AF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *p_Name; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *target_ns; // rdi
  __int64 v7; // rax
  Scaleform::GFx::AS3::VM *pVM; // rax
  __int64 v9; // rax
  Scaleform::GFx::ASString *target_prop; // rbx
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  __int64 v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::XMLSupport *v15; // rcx
  __int64 v16; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v18; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  result->pV = 0i64;
  p_Name = &mn->Name;
  if ( (mn->Name.Flags & 0x1F) == 10 )
  {
    if ( (mn->Kind & 3u) <= 1 && mn->Obj.pObject )
    {
      target_ns = mn->Obj.pObject;
      if ( (target_ns[1].RefCount & 0x1F) == 0 )
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
      pVM = this->pTraits.pObject->pVM;
      target_ns = pVM->DefXMLNamespace.pObject;
      if ( target_ns )
      {
        if ( (target_ns[1].RefCount & 0x1F) == 0 )
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
        target_ns = pVM->PublicNamespace.pObject;
      }
    }
    target_prop = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(p_Name, &resulta);
    pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].ForEachChild_GC)(pObject);
    Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
      *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v12 + 200),
      &v18,
      *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v12 + 200),
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this,
      target_prop,
      (Scaleform::GFx::AS3::Instances::fl::Namespace *)target_ns);
    result->pV = v18.pV;
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v15 = this->pTraits.pObject->pVM->XMLSupport_.pObject;
    v16 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))v15->vfptr[4].ForEachChild_GC)(v15);
    Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
      &v18,
      *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v16 + 200));
    result->pV = v18.pV;
  }
  return result;
}

// File Line: 4421
// RVA: 0x7C93C0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  __int64 result; // rax
  int v5; // ebx

  if ( this == other )
    return 1i64;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))other->vfptr[8].Finalize_GC)(other);
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))this->vfptr[8].Finalize_GC)(this) != v5 )
    return 2i64;
  result = 0i64;
  if ( this->Text.pNode != other->Text.pNode )
    return 2i64;
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
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this)
{
  return this->pTraits.pObject->pVM->PublicNamespace.pObject;
}

// File Line: 4460
// RVA: 0x7C01C0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
    result,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
    &this->Text,
    parent);
  return result;
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
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetQName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 4552
// RVA: 0x7D2C70
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *prefix,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  __int64 v6; // rax
  const char *pData; // rdx
  char v8; // cl

  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[15].Finalize_GC)(
                                                              pObject,
                                                              prefix,
                                                              lp,
                                                              this);
  v6 = 0i64;
  pData = prefix->pNode->pData;
  while ( 1 )
  {
    v8 = pData[v6++];
    if ( v8 != aXml_5[v6 - 1] )
      break;
    if ( v6 == 4 )
      return this->pTraits.pObject->pVM->XMLNamespace.pObject;
  }
  return 0i64;
}

// File Line: 4563
// RVA: 0x7D2E00
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByURI(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  const char *pData; // rax
  const char *v7; // r8
  int v8; // ecx
  int v9; // edx

  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))pObject->vfptr[16].ForEachChild_GC)(
                                                              pObject,
                                                              uri,
                                                              lp,
                                                              this);
  pData = uri->pNode->pData;
  v7 = (const char *)(Scaleform::GFx::AS3::NS_XML - pData);
  do
  {
    v8 = (unsigned __int8)v7[(_QWORD)pData];
    v9 = *(unsigned __int8 *)pData - v8;
    if ( v9 )
      break;
    ++pData;
  }
  while ( v8 );
  if ( v9 )
    return 0i64;
  else
    return this->pTraits.pObject->pVM->XMLNamespace.pObject;
}

// File Line: 4601
// RVA: 0x826AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::StringBuffer *buf,
        int ident,
        Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        Scaleform::GFx::AS3::NamespaceArray *usedNotDeclared)
{
  Scaleform::StringBuffer::AppendString(buf, this->Text.pNode->pData, this->Text.pNode->Size);
}

// File Line: 4627
// RVA: 0x7B0950
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(Scaleform::StringBuffer *buf, int ident)
{
  int v2; // ebx
  int v4; // edi

  if ( ident )
  {
    v2 = ident;
    do
    {
      v4 = 10;
      if ( v2 < 10 )
        v4 = v2;
      Scaleform::StringBuffer::AppendString(buf, offsets[v4], v4);
      v2 -= v4;
    }
    while ( v2 );
  }
}

// File Line: 4636
// RVA: 0x7C9D60
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(
        Scaleform::StringBuffer *buf,
        Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  char *v4; // rdi
  unsigned int Char_Advance0; // eax
  Scaleform::StringBuffer *v6; // rcx
  __int64 v7; // r8
  const char *v8; // rdx
  char *putf8Buffer; // [rsp+38h] [rbp+10h] BYREF

  pNode = v->pNode;
  putf8Buffer = (char *)v->pNode->pData;
  v4 = &putf8Buffer[pNode->Size];
  if ( putf8Buffer < v4 )
  {
    while ( 1 )
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( Char_Advance0 == 34 )
        break;
      switch ( Char_Advance0 )
      {
        case &:
          v7 = 5i64;
          v8 = "&amp;";
          goto LABEL_14;
        case \:
          v8 = "&apos;";
LABEL_13:
          v7 = 6i64;
          goto LABEL_14;
        case <:
          v7 = 4i64;
          v8 = "&lt;";
LABEL_14:
          v6 = buf;
          goto LABEL_15;
      }
      v6 = buf;
      if ( Char_Advance0 == 62 )
      {
        v7 = 4i64;
        v8 = "&gt;";
LABEL_15:
        Scaleform::StringBuffer::AppendString(v6, v8, v7);
        goto LABEL_16;
      }
      Scaleform::StringBuffer::AppendChar(buf, Char_Advance0);
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::VM *pVM; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( ind.Index )
  {
    v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           pVM->StringManagerRef,
           &result,
           "0");
    Scaleform::GFx::AS3::Value::Assign(name, v5);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(name, (Scaleform::GFx::ASString *)&pVM->StringManagerRef->Builtins[2]);
  }
}

// File Line: 4723
// RVA: 0x7ECCD0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
    Scaleform::GFx::AS3::Value::Assign(value, this);
  else
    Scaleform::GFx::AS3::Value::SetUndefined(value);
}

// File Line: 4742
// RVA: 0x81AFE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult *v9; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h] BYREF
  unsigned int ind; // [rsp+24h] [rbp-24h] BYREF
  __int64 v12; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-18h] BYREF

  v12 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1087, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    if ( v13.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v9 = result;
  result->Result = 0;
  return v9;
}

// File Line: 4755
// RVA: 0x7EDF20
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h] BYREF
  unsigned int ind[5]; // [rsp+24h] [rbp-14h] BYREF

  if ( !Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result || ind[0] )
  {
    result->Result = 0;
    return result;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this);
    result->Result = 1;
    return result;
  }
}

// File Line: 4774
// RVA: 0x7EDEA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h] BYREF
  unsigned int ind[5]; // [rsp+24h] [rbp-14h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result )
  {
    if ( !ind[0] )
    {
      Scaleform::GFx::AS3::Value::Assign(value, this);
      result->Result = 1;
      return result;
    }
    Scaleform::GFx::AS3::Value::SetUndefined(value);
  }
  result->Result = 0;
  return result;
}

// File Line: 4791
// RVA: 0x7C0E60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Object::DeleteProperty(this, result, prop_name);
  return result;
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 4919
// RVA: 0x75E950
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  _QWORD *v7; // rax
  _QWORD *v8; // rsi
  Scaleform::GFx::AS3::Object *VObj; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *VStr; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_9;
  v7 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)(vm->XMLSupport_.pObject);
  v8 = v7;
  if ( !v7[17] )
    (*(void (__fastcall **)(_QWORD *))(*v7 + 80i64))(v7);
  VObj = _this->value.VS._1.VObj;
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v8[17]) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else
  {
LABEL_9:
    if ( (_this->Flags & 0x1F) - 12 <= 3
      && (VStr = (Scaleform::GFx::AS3::Instances::fl::XML *)_this->value.VS._1.VStr) != 0i64
      && (pObject = VStr->pTraits.pObject, pObject->TraitsType == Traits_XML)
      && (pObject->Flags & 0x20) == 0 )
    {
      resulta.pNode = vm->StringManagerRef->Builtins[0].pNode;
      ++resulta.pNode->RefCount;
      Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(VStr, &resulta);
      Scaleform::GFx::AS3::Value::Assign(result, &resulta);
      pNode = resulta.pNode;
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v15.Message.pNode;
    }
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 4942
// RVA: 0x75F4E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::PropertyIsEnumerableProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  _QWORD *v10; // rax
  _QWORD *v11; // rsi
  Scaleform::GFx::AS3::Object *VObj; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *VStr; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+38h] [rbp-30h] BYREF

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_9;
  v10 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)(vm->XMLSupport_.pObject);
  v11 = v10;
  if ( !v10[17] )
    (*(void (__fastcall **)(_QWORD *))(*v10 + 80i64))(v10);
  VObj = _this->value.VS._1.VObj;
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v11[17]) )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);
  }
  else
  {
LABEL_9:
    if ( (_this->Flags & 0x1F) - 12 <= 3
      && (VStr = (Scaleform::GFx::AS3::Instances::fl::XML *)_this->value.VS._1.VStr) != 0i64
      && (pObject = VStr->pTraits.pObject, pObject->TraitsType == Traits_XML)
      && (pObject->Flags & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Instances::fl::XML::AS3propertyIsEnumerable(VStr, result, argc, argv);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v15, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v18.Message.pNode;
      if ( v18.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 4961
// RVA: 0x75FA60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::HasOwnPropertyProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  _QWORD *v10; // rax
  _QWORD *v11; // rsi
  Scaleform::GFx::AS3::Object *VObj; // rbx
  Scaleform::GFx::ASStringNode *VStr; // rbx
  const char *pData; // rax
  Scaleform::GFx::ASString *v15; // rax
  char v16; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+18h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    v10 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))vm->XMLSupport_.pObject->vfptr[3].Finalize_GC)(vm->XMLSupport_.pObject);
    v11 = v10;
    if ( !v10[17] )
      (*(void (__fastcall **)(_QWORD *))(*v10 + 80i64))(v10);
    VObj = _this->value.VS._1.VObj;
    if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)v11[17]) )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
      return;
    }
  }
  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VStr = _this->value.VS._1.VStr) != 0i64
    && (pData = VStr[1].pData, *((_DWORD *)pData + 30) == 18)
    && (pData[112] & 0x20) == 0 )
  {
    if ( argc && (argv->Flags & 0x1F) == 10 )
    {
      v15 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, &resulta);
      v16 = (*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASString *))VStr->pData + 29))(
              VStr,
              v15);
      Scaleform::GFx::AS3::Value::SetBool(result, v16);
      pNode = resulta.pNode;
      goto LABEL_16;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eInvalidArgumentError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v18, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v19, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  pNode = v21.Message.pNode;
LABEL_16:
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 5006
// RVA: 0x7A3890
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3settings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // r14
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // rbx
  unsigned int RefCount; // eax
  bool ignoreComments; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_mHash; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool ignoreProcessingInstructions; // al
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool ignoreWhitespace; // al
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool prettyPrinting; // al
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  int prettyIndent; // eax
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  int v30; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v33; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+90h] [rbp+20h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)pVM->TraitsObject.pObject->ITraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  ignoreComments = this->ignoreComments;
  v33.Flags = 1;
  v33.Bonus.pWeakProxy = 0i64;
  v33.value.VS._1.VBool = ignoreComments;
  v30 = 0;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            (Scaleform::GFx::ASString *)&resulta,
            "ignoreComments")->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v30;
  key.pSecond = &v33;
  p_mHash = &pV->DynAttrs.mHash;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v11 = pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v13 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( (v33.Flags & 0x1F) > 9 )
  {
    if ( (v33.Flags & 0x200) != 0 )
    {
      v12 = v33.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.Bonus, 0, 24);
      v33.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
    }
  }
  ignoreProcessingInstructions = this->ignoreProcessingInstructions;
  v33.Flags = 1;
  v33.Bonus.pWeakProxy = 0i64;
  v33.value.VS._1.VBool = ignoreProcessingInstructions;
  ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  StringManagerRef,
                  (Scaleform::GFx::ASString *)&resulta,
                  "ignoreProcessingInstructions");
  v30 = 0;
  pNode = ConstString->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v30;
  key.pSecond = &v33;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v16 = pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( (v33.Flags & 0x1F) > 9 )
  {
    if ( (v33.Flags & 0x200) != 0 )
    {
      v12 = v33.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.Bonus, 0, 24);
      v33.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
    }
  }
  ignoreWhitespace = this->ignoreWhitespace;
  v33.Flags = 1;
  v33.Bonus.pWeakProxy = 0i64;
  v33.value.VS._1.VBool = ignoreWhitespace;
  v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreWhitespace");
  v30 = 0;
  pNode = v19->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v30;
  key.pSecond = &v33;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v20 = pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( (v33.Flags & 0x1F) > 9 )
  {
    if ( (v33.Flags & 0x200) != 0 )
    {
      v12 = v33.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.Bonus, 0, 24);
      v33.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
    }
  }
  prettyPrinting = this->prettyPrinting;
  v33.Flags = 1;
  v33.Bonus.pWeakProxy = 0i64;
  v33.value.VS._1.VBool = prettyPrinting;
  v23 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyPrinting");
  v30 = 0;
  pNode = v23->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v30;
  key.pSecond = &v33;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v24 = pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  v25 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( (v33.Flags & 0x1F) > 9 )
  {
    if ( (v33.Flags & 0x200) != 0 )
    {
      v12 = v33.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.Bonus, 0, 24);
      v33.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
    }
  }
  prettyIndent = this->prettyIndent;
  v33.Flags = 2;
  v33.Bonus.pWeakProxy = 0i64;
  v33.value.VS._1.VInt = prettyIndent;
  v27 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyIndent");
  v30 = 0;
  pNode = v27->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v30;
  key.pSecond = &v33;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v28 = pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  v29 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v12 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( (v33.Flags & 0x1F) > 9 )
  {
    if ( (v33.Flags & 0x200) != 0 )
    {
      v12 = v33.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.Bonus, 0, 24);
      v33.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
    }
  }
}

// File Line: 5026
// RVA: 0x85F280
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::settings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3settings(this, result);
}

// File Line: 5037
// RVA: 0x7A32E0
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *o)
{
  unsigned int v4; // edx
  Scaleform::GFx::AS3::Value::V1U v5; // rbp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  _DWORD *v7; // rsi
  Scaleform::GFx::ASStringNode *pNode; // r8
  Scaleform::GFx::ASStringManager *pManager; // r10
  __int64 v10; // r9
  __int64 v11; // rdx
  __int64 *v12; // rcx
  __int64 v13; // rbx
  __int64 v14; // rbx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // r8
  Scaleform::GFx::ASStringManager *v18; // r10
  __int64 v19; // r9
  __int64 v20; // rdx
  __int64 *v21; // rcx
  __int64 v22; // rbx
  __int64 v23; // rbx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // r8
  Scaleform::GFx::ASStringManager *v26; // r10
  __int64 v27; // r9
  __int64 v28; // rdx
  __int64 *v29; // rcx
  __int64 v30; // rbx
  __int64 v31; // rbx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // r8
  Scaleform::GFx::ASStringManager *v34; // r10
  __int64 v35; // r9
  __int64 v36; // rdx
  __int64 *v37; // rcx
  __int64 v38; // rbx
  __int64 v39; // rbx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // r8
  Scaleform::GFx::ASStringManager *v42; // r10
  __int64 v43; // r9
  __int64 v44; // rdx
  __int64 *v45; // rcx
  __int64 v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  v4 = o->Flags & 0x1F;
  if ( v4 && (v4 - 12 > 3 && v4 != 10 || o->value.VS._1.VStr) )
  {
    if ( v4 - 12 <= 3 )
    {
      v5 = o->value.VS._1;
      StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
      v7 = 0i64;
      pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                StringManagerRef,
                &resulta,
                "ignoreComments")->pNode;
      ++pNode->RefCount;
      pManager = v5.VStr[1].pManager;
      if ( !pManager )
        goto LABEL_16;
      v10 = pNode->HashFlags & pManager->RefCount & 0xFFFFFF;
      v11 = (unsigned int)v10;
      v12 = (__int64 *)(&pManager->StringSet + 8 * v10);
      if ( *v12 == -2 || v12[1] != v10 )
        goto LABEL_16;
      while ( v12[1] != v10 || (Scaleform::GFx::ASStringNode *)v12[3] != pNode )
      {
        v11 = *v12;
        if ( *v12 == -1 )
          goto LABEL_16;
        v12 = (__int64 *)(&pManager->StringSet + 8 * v11);
      }
      if ( v11 >= 0 && (v13 = (__int64)(&pManager->pFreeStringNodes + 8 * v11)) != 0 )
        v14 = v13 + 16;
      else
LABEL_16:
        v14 = 0i64;
      v15 = pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v16 = resulta.pNode;
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( v14 && (*(_DWORD *)v14 & 0x1F) == 1 )
        this->ignoreComments = *(_BYTE *)(v14 + 16);
      v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &resulta,
              "ignoreProcessingInstructions")->pNode;
      ++v17->RefCount;
      v18 = v5.VStr[1].pManager;
      if ( !v18 )
        goto LABEL_34;
      v19 = v17->HashFlags & v18->RefCount & 0xFFFFFF;
      v20 = (unsigned int)v19;
      v21 = (__int64 *)(&v18->StringSet + 8 * v19);
      if ( *v21 == -2 || v21[1] != v19 )
        goto LABEL_34;
      while ( v21[1] != v19 || (Scaleform::GFx::ASStringNode *)v21[3] != v17 )
      {
        v20 = *v21;
        if ( *v21 == -1 )
          goto LABEL_34;
        v21 = (__int64 *)(&v18->StringSet + 8 * v20);
      }
      if ( v20 >= 0 && (v22 = (__int64)(&v18->pFreeStringNodes + 8 * v20)) != 0 )
        v23 = v22 + 16;
      else
LABEL_34:
        v23 = 0i64;
      v15 = v17->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v24 = resulta.pNode;
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 && (*(_DWORD *)v23 & 0x1F) == 1 )
        this->ignoreProcessingInstructions = *(_BYTE *)(v23 + 16);
      v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &resulta,
              "ignoreWhitespace")->pNode;
      ++v25->RefCount;
      v26 = v5.VStr[1].pManager;
      if ( !v26 )
        goto LABEL_52;
      v27 = v25->HashFlags & v26->RefCount & 0xFFFFFF;
      v28 = (unsigned int)v27;
      v29 = (__int64 *)(&v26->StringSet + 8 * v27);
      if ( *v29 == -2 || v29[1] != v27 )
        goto LABEL_52;
      while ( v29[1] != v27 || (Scaleform::GFx::ASStringNode *)v29[3] != v25 )
      {
        v28 = *v29;
        if ( *v29 == -1 )
          goto LABEL_52;
        v29 = (__int64 *)(&v26->StringSet + 8 * v28);
      }
      if ( v28 >= 0 && (v30 = (__int64)(&v26->pFreeStringNodes + 8 * v28)) != 0 )
        v31 = v30 + 16;
      else
LABEL_52:
        v31 = 0i64;
      v15 = v25->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      v32 = resulta.pNode;
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      if ( v31 && (*(_DWORD *)v31 & 0x1F) == 1 )
        this->ignoreWhitespace = *(_BYTE *)(v31 + 16);
      v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &resulta,
              "prettyPrinting")->pNode;
      ++v33->RefCount;
      v34 = v5.VStr[1].pManager;
      if ( !v34 )
        goto LABEL_70;
      v35 = v33->HashFlags & v34->RefCount & 0xFFFFFF;
      v36 = (unsigned int)v35;
      v37 = (__int64 *)(&v34->StringSet + 8 * v35);
      if ( *v37 == -2 || v37[1] != v35 )
        goto LABEL_70;
      while ( v37[1] != v35 || (Scaleform::GFx::ASStringNode *)v37[3] != v33 )
      {
        v36 = *v37;
        if ( *v37 == -1 )
          goto LABEL_70;
        v37 = (__int64 *)(&v34->StringSet + 8 * v36);
      }
      if ( v36 >= 0 && (v38 = (__int64)(&v34->pFreeStringNodes + 8 * v36)) != 0 )
        v39 = v38 + 16;
      else
LABEL_70:
        v39 = 0i64;
      v15 = v33->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      v40 = resulta.pNode;
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      if ( v39 && (*(_DWORD *)v39 & 0x1F) == 1 )
        this->prettyPrinting = *(_BYTE *)(v39 + 16);
      v41 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &resulta,
              "prettyIndent")->pNode;
      ++v41->RefCount;
      v42 = v5.VStr[1].pManager;
      if ( v42 )
      {
        v43 = v41->HashFlags & v42->RefCount & 0xFFFFFF;
        v44 = (unsigned int)v43;
        v45 = (__int64 *)(&v42->StringSet + 8 * v43);
        if ( *v45 != -2 && v45[1] == v43 )
        {
          while ( v45[1] != v43 || (Scaleform::GFx::ASStringNode *)v45[3] != v41 )
          {
            v44 = *v45;
            if ( *v45 == -1 )
              goto LABEL_88;
            v45 = (__int64 *)(&v42->StringSet + 8 * v44);
          }
          if ( v44 >= 0 )
          {
            v46 = (__int64)(&v42->pFreeStringNodes + 8 * v44);
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
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v47);
      if ( v7 )
      {
        if ( (*v7 & 0x1Fu) - 2 <= 1 )
          this->prettyIndent = v7[4];
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
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::setSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *o)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings(this, result, o);
}

// File Line: 5089
// RVA: 0x79C260
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rsi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_mHash; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  int v24; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v27; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+80h] [rbp+10h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)pVM->TraitsObject.pObject->ITraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  v27.Flags = 1;
  v27.Bonus.pWeakProxy = 0i64;
  v27.value.VS._1.VBool = 1;
  v24 = 0;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            (Scaleform::GFx::ASString *)&resulta,
            "ignoreComments")->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v24;
  key.pSecond = &v27;
  p_mHash = &pV->DynAttrs.mHash;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v9 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v11 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v10 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  v27.Flags = 1;
  v27.Bonus.pWeakProxy = 0i64;
  v27.value.VS._1.VBool = 1;
  ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  StringManagerRef,
                  (Scaleform::GFx::ASString *)&resulta,
                  "ignoreProcessingInstructions");
  v24 = 0;
  pNode = ConstString->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v24;
  key.pSecond = &v27;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v13 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v10 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  v27.Flags = 1;
  v27.Bonus.pWeakProxy = 0i64;
  v27.value.VS._1.VBool = 1;
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "ignoreWhitespace");
  v24 = 0;
  pNode = v15->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v24;
  key.pSecond = &v27;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v16 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v10 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  v27.Flags = 1;
  v27.Bonus.pWeakProxy = 0i64;
  v27.value.VS._1.VBool = 1;
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyPrinting");
  v24 = 0;
  pNode = v18->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v24;
  key.pSecond = &v27;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v19 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v20 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v10 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  v27.Flags = 2;
  v27.Bonus.pWeakProxy = 0i64;
  v27.value.VS._1.VInt = 2;
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "prettyIndent");
  v24 = 0;
  pNode = v21->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v24;
  key.pSecond = &v27;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    p_mHash,
    p_mHash,
    &key);
  v22 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v23 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v10 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v10 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
}

// File Line: 5109
// RVA: 0x834410
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::defaultSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings(this, result);
}

// File Line: 5122
// RVA: 0x7B9150
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::Construct(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *vfptr; // r12
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  int TraitsType; // ecx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v15; // r8d
  Scaleform::GFx::AS3::Value::V1U v16; // rdx
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::AS3::Object *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v23; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v24; // rbx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLText *pV; // rbx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *InstanceText; // rax
  Scaleform::GFx::ASString *EmptyString; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v30; // rax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v32; // [rsp+38h] [rbp-71h] BYREF
  Scaleform::GFx::AS3::VM::Error v33; // [rsp+40h] [rbp-69h] BYREF
  Scaleform::GFx::ASString v34; // [rsp+50h] [rbp-59h] BYREF
  __int64 v35; // [rsp+58h] [rbp-51h]
  Scaleform::GFx::AS3::XMLParser v36; // [rsp+68h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Object *v[2]; // [rsp+108h] [rbp+5Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v38; // [rsp+118h] [rbp+6Fh] BYREF
  void *retaddr; // [rsp+128h] [rbp+7Fh]

  v35 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  vfptr = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)pObject[1].vfptr;
  if ( argc )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv);
    TraitsType = ValueTraits->TraitsType;
    if ( (ValueTraits->Flags & 0x20) != 0 )
    {
      if ( !(_BYTE)retaddr )
        Scaleform::GFx::AS3::VSBase::PopBack(&pVM->OpStack, argc);
      Scaleform::GFx::AS3::VM::Error::Error(&v33, 1004, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v33.Message.pNode;
      goto LABEL_38;
    }
    v15 = argv->Flags & 0x1F;
    if ( v15
      && (v15 - 12 > 3 && v15 != 10 || argv->value.VS._1.VStr)
      && (ValueTraits->Flags & 0x20) == 0
      && TraitsType > 0 )
    {
      if ( TraitsType <= 4 )
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          pVM->StringManagerRef,
          &result);
        Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)v, &result);
        InstanceText = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(vfptr, &v32, vfptr, &result, 0i64);
        Scaleform::GFx::AS3::Value::Pick(_this, InstanceText->pV);
        pNode = result.pNode;
        goto LABEL_38;
      }
      switch ( TraitsType )
      {
        case 5:
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, (Scaleform::GFx::ASString *)v);
          if ( *Scaleform::GFx::ASUtils::SkipWhiteSpace((const char *)v[0]->vfptr, v[0]->RefCount) == 60 )
          {
            Scaleform::GFx::AS3::XMLParser::XMLParser(&v36, vfptr);
            result.pNode = 0i64;
            *(_QWORD *)&v33.ID = v[0]->vfptr;
            v33.Message.pNode = (Scaleform::GFx::ASStringNode *)v[0]->RefCount;
            if ( Scaleform::GFx::AS3::XMLParser::Parse(
                   &v36,
                   &v38,
                   (Scaleform::StringDataPtr *)&v33,
                   (unsigned __int64 *)&result,
                   0)->Result )
            {
              Scaleform::GFx::AS3::Value::Assign(_this, v36.pCurrElem.pObject);
            }
            else
            {
              v24 = this->pTraits.pObject[1].vfptr;
              v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                      pVM->StringManagerRef,
                      &v34);
              pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                     (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v24,
                     (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&v33,
                     (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24,
                     v25,
                     0i64)->pV;
              v27 = v34.pNode;
              v21 = v34.pNode->RefCount-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v27);
              Scaleform::GFx::AS3::Value::Pick(_this, pV);
            }
            Scaleform::GFx::AS3::XMLParser::~XMLParser(&v36);
          }
          else
          {
            if ( this->ignoreWhitespace )
            {
              v18 = Scaleform::GFx::ASString::TruncateWhitespace((Scaleform::GFx::ASString *)v, &result);
              v19 = (Scaleform::GFx::AS3::Object *)v18->pNode;
              ++v18->pNode->RefCount;
              v20 = (Scaleform::GFx::ASStringNode *)v[0];
              v21 = LODWORD(v[0]->pPrev)-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              v[0] = v19;
              v22 = result.pNode;
              v21 = result.pNode->RefCount-- == 1;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            }
            v23 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject[1].vfptr,
                    &v32,
                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].vfptr,
                    (Scaleform::GFx::ASString *)v,
                    0i64);
            Scaleform::GFx::AS3::Value::Pick(_this, v23->pV);
          }
          goto LABEL_37;
        case 18:
          (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Object **, _QWORD))argv->value.VS._1.VStr->pData
           + 35))(
            argv->value.VS._1,
            v,
            0i64);
          Scaleform::GFx::AS3::Value::Pick(_this, v[0]);
          return;
        case 19:
          v16 = argv->value.VS._1;
          if ( v16.VStr[2].pManager == (Scaleform::GFx::ASStringManager *)1 )
          {
            Scaleform::GFx::AS3::Value::Assign(_this, *(Scaleform::GFx::AS3::Object **)v16.VStr[2].pData);
            return;
          }
          if ( !(_BYTE)retaddr )
            Scaleform::GFx::AS3::VSBase::PopBack(&pVM->OpStack, argc);
          Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v33.Message, 1004, pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          pNode = v34.pNode;
          goto LABEL_38;
      }
    }
  }
  EmptyString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                  pVM->StringManagerRef,
                  (Scaleform::GFx::ASString *)v);
  v30 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(vfptr, &v32, vfptr, EmptyString, 0i64);
  Scaleform::GFx::AS3::Value::Pick(_this, v30->pV);
LABEL_37:
  pNode = (Scaleform::GFx::ASStringNode *)v[0];
LABEL_38:
  v21 = pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 5242
// RVA: 0x7B2D20
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::Call(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax

  if ( argc
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv),
        (ValueTraits->Flags & 0x20) == 0)
    && ValueTraits->TraitsType == Traits_XML )
  {
    Scaleform::GFx::AS3::Value::Assign(result, argv);
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::XML *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const))this->vfptr[4].ForEachChild_GC)(
      this,
      result,
      argc,
      argv);
  }
}

// File Line: 5285
// RVA: 0x7F4DB0
void __fastcall Scaleform::GFx::AS3::Classes::fl::XML::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::AS3::Value *(__fastcall *v7)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *); // [rsp+20h] [rbp-18h] BYREF
  int v8; // [rsp+28h] [rbp-10h]

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v8 = 0;
  v7 = Scaleform::GFx::AS3::Class::ConvertCheckType;
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v7);
  v5 = Scaleform::GFx::AS3::Classes::fl::XML::f;
  v6 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v5++);
    --v6;
  }
  while ( v6 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::XML::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::XMLCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::XML::`vftable;
    v6->TraitsType = Traits_XML;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::XMLCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::XML::`vftable;
    v8.pV->TraitsType = Traits_XML;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       80i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::XML::`vftable;
    LODWORD(v10[1].vfptr) = 16843009;
    HIDWORD(v10[1].vfptr) = 2;
  }
  return result;
}

