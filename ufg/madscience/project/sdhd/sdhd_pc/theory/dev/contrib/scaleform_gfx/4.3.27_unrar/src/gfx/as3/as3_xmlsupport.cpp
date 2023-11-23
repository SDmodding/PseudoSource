// File Line: 88
// RVA: 0x785650
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *pV; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v7; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::XMLList *v8; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> result; // [rsp+48h] [rbp+10h] BYREF

  GC = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable;
  this->Enabled = 1;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable;
  this->VMRef = vm;
  ClassTraits = Scaleform::GFx::AS3::ClassTraits::fl::XML::MakeClassTraits(&result, vm);
  pV = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)ClassTraits->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(vm, ClassTraits->pV, vm->SystemDomain.pObject);
  this->TraitsXML.pObject = pV;
  v7 = Scaleform::GFx::AS3::ClassTraits::fl::XMLList::MakeClassTraits(&result, vm);
  v8 = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)v7->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(vm, v7->pV, vm->SystemDomain.pObject);
  this->TraitsXMLList.pObject = v8;
}

// File Line: 92
// RVA: 0x790110
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::~XMLSupportImpl(Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  Scaleform::GFx::AS3::ClassTraits::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v4; // rcx
  unsigned int v5; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable;
  pObject = this->TraitsXMLList.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TraitsXMLList.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)((char *)pObject - 1);
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
  v4 = this->TraitsXML.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->TraitsXML.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( (v5 & 0x3FFFFF) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable;
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 101
// RVA: 0x7C9A50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a3,
        Scaleform::GFx::AS3::Instances::fl::XML *l,
        Scaleform::GFx::AS3::Instances::fl::XML *r)
{
  int v8; // r14d
  int v9; // ebp
  char *v10; // rcx
  char *pData; // rdx
  bool v12; // al
  Scaleform::GFx::AS3::CheckResult *v13; // rax
  Scaleform::StringBuffer v14; // [rsp+28h] [rbp-80h] BYREF
  Scaleform::StringBuffer v15; // [rsp+58h] [rbp-50h] BYREF

  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[8].Finalize_GC)(l);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))r->vfptr[8].Finalize_GC)(r);
  if ( (v8 == 2 || v8 == 5)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))r->vfptr[9].~RefCountBaseGC<328>)(r)
    || (v9 == 2 || v9 == 5)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[9].~RefCountBaseGC<328>)(l) )
  {
    Scaleform::StringBuffer::StringBuffer(&v15, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::StringBuffer(&v14, Scaleform::Memory::pGlobalHeap);
    l->vfptr[8].ForEachChild_GC(l, (Scaleform::GFx::AS3::RefCountCollector<328> *)&v15, 0i64);
    r->vfptr[8].ForEachChild_GC(r, (Scaleform::GFx::AS3::RefCountCollector<328> *)&v14, 0i64);
    if ( v15.Size != v14.Size )
      goto LABEL_15;
    v10 = &customCaption;
    pData = &customCaption;
    if ( v14.pData )
      pData = v14.pData;
    if ( v15.pData )
      v10 = v15.pData;
    if ( !strncmp(v10, pData, v15.Size) )
      v12 = 1;
    else
LABEL_15:
      v12 = 0;
    *a3 = v12;
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  }
  else
  {
    *a3 = ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[9].ForEachChild_GC)(
            l,
            r) == 1;
  }
  v13 = result;
  result->Result = 1;
  return v13;
}

// File Line: 123
// RVA: 0x7C9910
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *stop,
        bool *a4,
        Scaleform::GFx::AS3::Instances::fl::XML *l,
        Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rdi
  char *v10; // rcx
  char *pData; // rdx
  bool v12; // al
  Scaleform::StringBuffer resulta; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::StringBuffer v15; // [rsp+58h] [rbp-40h] BYREF

  *stop = 0;
  v9 = l;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[9].~RefCountBaseGC<328>)(l) )
  {
LABEL_13:
    result->Result = 1;
    return result;
  }
  Scaleform::StringBuffer::StringBuffer(&v15, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&resulta, Scaleform::Memory::pGlobalHeap);
  v9->vfptr[8].ForEachChild_GC(v9, (Scaleform::GFx::AS3::RefCountCollector<328> *)&v15, 0i64);
  if ( Scaleform::GFx::AS3::Value::Convert2String(r, (Scaleform::GFx::AS3::CheckResult *)&l, &resulta)->Result )
  {
    if ( v15.Size != resulta.Size )
      goto LABEL_11;
    v10 = &customCaption;
    pData = &customCaption;
    if ( resulta.pData )
      pData = resulta.pData;
    if ( v15.pData )
      v10 = v15.pData;
    if ( !strncmp(v10, pData, resulta.Size) )
      v12 = 1;
    else
LABEL_11:
      v12 = 0;
    *a4 = v12;
    *stop = 1;
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&resulta);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
    goto LABEL_13;
  }
  result->Result = 0;
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&resulta);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  return result;
}

// File Line: 143
// RVA: 0x7C9BC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXMLList(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a3,
        Scaleform::GFx::AS3::Instances::fl::XMLList *l,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList::Equals(l, result, a3, v);
  return result;
}

// File Line: 148
// RVA: 0x7C98A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsQName(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a3,
        Scaleform::GFx::AS3::Instances::fl::QName *l,
        Scaleform::GFx::AS3::Instances::fl::QName *r)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r11
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rcx

  pObject = l->Ns.pObject;
  if ( pObject
    && (v6 = r->Ns.pObject) != 0i64
    && pObject->Uri.pNode == v6->Uri.pNode
    && ((*((_BYTE *)v6 + 40) ^ *((_BYTE *)pObject + 40)) & 0xF) == 0
    && l->LocalName.pNode == r->LocalName.pNode )
  {
    *a3 = 1;
    result->Result = 1;
    return result;
  }
  else
  {
    result->Result = 1;
    *a3 = 0;
    return result;
  }
}

// File Line: 159
// RVA: 0x7AB180
char __fastcall Scaleform::GFx::AS3::XMLSupportImpl::Add(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::XMLList *l,
        Scaleform::GFx::AS3::Instances::fl::XMLList *r)
{
  Scaleform::GFx::AS3::Traits *pObject; // r8
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // esi
  Scaleform::GFx::AS3::Traits *v8; // r9
  Scaleform::GFx::AS3::BuiltinTraitsType v10; // edi
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v11; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // rbx
  __int32 v13; // esi
  __int32 v14; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+50h] [rbp+18h] BYREF

  pObject = l->pTraits.pObject;
  TraitsType = pObject->TraitsType;
  v8 = r->pTraits.pObject;
  v10 = v8->TraitsType;
  if ( (unsigned int)(TraitsType - 18) > 1
    || (pObject->Flags & 0x20) != 0
    || (unsigned int)(v10 - 18) > 1
    || (v8->Flags & 0x20) != 0 )
  {
    return 0;
  }
  v11 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)((__int64 (*)(void))this->vfptr[4].~RefCountBaseGC<328>)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(&resulta, v11);
  pV = resulta.pV;
  v13 = TraitsType - 18;
  if ( v13 )
  {
    if ( v13 == 1 )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(resulta.pV, l);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(resulta.pV, (Scaleform::GFx::AS3::Instances::fl::XML *)l);
  }
  v14 = v10 - 18;
  if ( v14 )
  {
    if ( v14 == 1 )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(pV, r);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(pV, (Scaleform::GFx::AS3::Instances::fl::XML *)r);
  }
  Scaleform::GFx::AS3::Value::Pick(result, pV);
  return 1;
}

// File Line: 205
// RVA: 0x8281E0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::ToXMLString(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  char *v9; // r15
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  char *v13; // r8
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  unsigned int v16; // edx
  Scaleform::GFx::ASStringNode *VStr; // rdi
  const char *pData; // rax
  const char *v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // al
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  bool v31; // di
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult v35; // [rsp+18h] [rbp-39h] BYREF
  int v36; // [rsp+1Ch] [rbp-35h]
  Scaleform::StringBuffer buf; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::GFx::ASString v38; // [rsp+50h] [rbp-1h] BYREF
  Scaleform::GFx::ASString v39; // [rsp+58h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::VM::Error v40; // [rsp+60h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v41; // [rsp+70h] [rbp+1Fh] BYREF
  Scaleform::GFx::ASString v42; // [rsp+78h] [rbp+27h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+2Fh] BYREF
  __int64 v44; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult v45; // [rsp+D0h] [rbp+7Fh] BYREF

  v44 = -2i64;
  v36 = 0;
  v7 = v->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !v->value.VS._1.VStr )
  {
    v31 = (v7 - 12 <= 3 || v7 == 10) && !v->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v40, 1010 - v31, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v32, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v40.Message.pNode;
    v12 = v40.Message.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_52;
  }
  StringManagerRef = vm->StringManagerRef;
  v9 = &customCaption;
  if ( (v->Flags & 0x1F) == 0 )
  {
LABEL_16:
    v16 = v->Flags & 0x1F;
    if ( v16 - 12 <= 3 )
    {
      VStr = v->value.VS._1.VStr;
      if ( VStr )
      {
        pData = VStr[1].pData;
        if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
        {
          Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
          v19 = VStr->pData;
          buf.pData = 0i64;
          (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::StringBuffer *, _QWORD, _QWORD))v19 + 25))(
            VStr,
            &buf,
            0i64,
            0i64);
          if ( buf.pData )
            v9 = buf.pData;
          v20 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  StringManagerRef,
                  &v38,
                  v9,
                  buf.Size);
          Scaleform::GFx::AS3::Value::Assign(v, v20);
          v21 = v38.pNode;
          v12 = v38.pNode->RefCount-- == 1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
LABEL_43:
          Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
LABEL_44:
          result->Result = 1;
          return result;
        }
      }
    }
    if ( v16 - 12 <= 3 )
    {
      v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v->value.VS._1.VStr;
      if ( v22 )
      {
        pObject = v22->pTraits.pObject;
        if ( pObject->TraitsType == Traits_XMLList && (pObject->Flags & 0x20) == 0 )
        {
          v24 = Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(v22, &v41);
          Scaleform::GFx::AS3::Value::Assign(v, v24);
          v25 = v41.pNode;
          v12 = v41.pNode->RefCount-- == 1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
          goto LABEL_44;
        }
      }
    }
    v36 = 1;
    v26 = !Scaleform::GFx::AS3::Value::ToPrimitiveValue(v, &v45, StringManagerRef->pStringManager)->Result
       || (v->Flags & 0x1F) > 4 && (v->Flags & 0x1F) != 10;
    v36 = 0;
    if ( !v26 )
    {
      Scaleform::GFx::AS3::Value::ToStringValue(v, &v35, StringManagerRef);
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      v27 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v, &v39);
      Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v27);
      v28 = v39.pNode;
      v12 = v39.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      if ( buf.pData )
        v9 = buf.pData;
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                 StringManagerRef,
                 (Scaleform::GFx::ASString *)&v40,
                 v9,
                 buf.Size);
      Scaleform::GFx::AS3::Value::Assign(v, String);
      v30 = *(Scaleform::GFx::ASStringNode **)&v40.ID;
      v12 = (*(_DWORD *)(*(_QWORD *)&v40.ID + 24i64))-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      goto LABEL_43;
    }
LABEL_52:
    result->Result = 0;
    return result;
  }
  if ( (v->Flags & 0x1F) > 4 )
  {
    if ( v7 == 10 )
    {
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      v10 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v, &resulta);
      Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v10);
      v11 = resulta.pNode;
      v12 = resulta.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v13 = &customCaption;
      if ( buf.pData )
        v13 = buf.pData;
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              StringManagerRef,
              &v42,
              v13,
              buf.Size);
      Scaleform::GFx::AS3::Value::Assign(v, v14);
      v15 = v42.pNode;
      v12 = v42.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
    }
    goto LABEL_16;
  }
  Scaleform::GFx::AS3::Value::ToStringValue(v, result, vm->StringManagerRef);
  return result;
}

// File Line: 267
// RVA: 0x7EE9D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::ASString *p_Uri; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+10h] BYREF

  p_Uri = &ns->Uri;
  if ( ns->Uri.pNode->Size )
  {
    if ( f )
      v8 = Scaleform::GFx::ASString::operator+(p_Uri, &resulta, ".");
    else
      v8 = Scaleform::GFx::ASString::operator+(p_Uri, &resulta, "::");
    Scaleform::GFx::ASString::operator+(v8, result, name);
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v7 = name->pNode;
    result->pNode = name->pNode;
    ++v7->RefCount;
  }
  return result;
}

// File Line: 280
// RVA: 0x7C12B0
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl::XMLElement *xml,
        Scaleform::GFx::AS3::VMAbcFile *file)
{
  __int64 v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v7; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r12
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  Scaleform::GFx::AS3::Abc::File *v10; // r13
  unsigned __int64 v11; // rax
  const char *pStr; // rdi
  unsigned __int64 Size; // rsi
  bool v14; // bl
  bool v15; // zf
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pV; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Abc::MetadataInfo *v19; // rdi
  unsigned __int64 v20; // r15
  unsigned __int64 v21; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v22; // r14
  bool v23; // bl
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v27; // rbx
  const char *Data; // r8
  const char *v29; // r8
  unsigned __int64 v30; // r9
  char v31; // al
  unsigned int v32; // ecx
  char v33; // dl
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v34; // rdi
  Scaleform::GFx::ASString *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  const char *v37; // r8
  const char *v38; // r8
  unsigned __int64 v39; // r9
  char v40; // al
  unsigned int v41; // ecx
  char v42; // dl
  Scaleform::GFx::ASString *v43; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v44; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v45; // rdx
  unsigned int v46; // eax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::ASStringNode *v52; // rcx
  char v53; // [rsp+40h] [rbp-88h] BYREF
  char v54[7]; // [rsp+41h] [rbp-87h] BYREF
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::GFx::ASString v56; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v57; // [rsp+58h] [rbp-70h] BYREF
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v58; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::AS3::Value n; // [rsp+68h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v60; // [rsp+88h] [rbp-40h]
  Scaleform::GFx::AS3::Abc::MetadataInfo *v61; // [rsp+90h] [rbp-38h]
  unsigned __int64 v62; // [rsp+98h] [rbp-30h]
  unsigned __int64 v63; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::ASString v64; // [rsp+A8h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v65; // [rsp+B0h] [rbp-18h]
  Scaleform::GFx::ASString v66; // [rsp+B8h] [rbp-10h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v67; // [rsp+C0h] [rbp-8h] BYREF
  Scaleform::GFx::ASString v68; // [rsp+C8h] [rbp+0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v69; // [rsp+D0h] [rbp+8h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v70; // [rsp+D8h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> v71; // [rsp+E0h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v72; // [rsp+E8h] [rbp+20h]
  __int64 v73; // [rsp+F0h] [rbp+28h]
  __int64 v74; // [rsp+148h] [rbp+80h]
  Scaleform::GFx::AS3::VMAbcFile *v75; // [rsp+150h] [rbp+88h]
  __int64 v76; // [rsp+158h] [rbp+90h]

  v73 = -2i64;
  v6 = v76;
  if ( (*(_BYTE *)v76 & 0x40) != 0 )
  {
    v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupportImpl *))this->vfptr[3].Finalize_GC)(this);
    v60 = v7;
    pObject = vm->PublicNamespace.pObject;
    StringManagerRef = vm->StringManagerRef;
    v58 = StringManagerRef;
    v63 = *(_QWORD *)(v76 + 32);
    if ( v63 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        StringManagerRef,
        &result,
        "name");
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        StringManagerRef,
        (Scaleform::GFx::ASString *)&n.Bonus,
        "metadata");
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        StringManagerRef,
        &v56,
        "arg");
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        StringManagerRef,
        (Scaleform::GFx::ASString *)&n,
        "key");
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        StringManagerRef,
        (Scaleform::GFx::ASString *)&n.value,
        "value");
      v10 = file->File.pObject;
      LODWORD(v11) = 0;
      v62 = 0i64;
      do
      {
        v61 = file->File.pObject->Metadata.Info.Data.Data[*(int *)(*(_QWORD *)(v6 + 24) + 4i64 * (unsigned int)v11)];
        pStr = v61->Name.pStr;
        Size = v61->Name.Size;
        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
          v7,
          &v57,
          v7,
          pObject,
          (Scaleform::GFx::ASString *)&n.Bonus,
          0i64);
        n.Bonus.pWeakProxy = 0i64;
        n.Flags = 12;
        *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&n.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v57.pV;
        n.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v70;
        v14 = *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, Scaleform::GFx::AS3::Value *))(*(_QWORD *)v74
                                                                                                 + 176i64))(
                          v74,
                          v54,
                          &n) == 0;
        if ( (n.Flags & 0x1F) > 9 )
        {
          if ( (n.Flags & 0x200) != 0 )
          {
            v15 = n.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v15 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&n.Bonus, 0, 24);
            n.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&n);
          }
        }
        if ( v14 )
          break;
        v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                StringManagerRef,
                &v64,
                pStr,
                Size);
        pV = v57.pV;
        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v57.pV, pObject, &result, v16);
        pNode = v64.pNode;
        v15 = v64.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v19 = v61;
        v20 = v61->Items.Data.Size;
        v21 = 0i64;
        if ( v20 )
        {
          while ( 1 )
          {
            Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v60, &v67, v60, pObject, &v56, 0i64);
            v56.pNode = 0i64;
            LODWORD(result.pNode) = 12;
            v22 = v67.pV;
            v57.pV = v67.pV;
            v58 = v70;
            v23 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::ASString *))pV->vfptr[7].~RefCountBaseGC<328>)(
                              pV,
                              &v53,
                              &result) == 0;
            if ( (unsigned __int64)((__int64)result.pNode & 0x1F) > 9 )
            {
              if ( ((__int64)result.pNode & 0x200) != 0 )
              {
                v15 = LODWORD(v56.pNode->pData)-- == 1;
                if ( v15 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                v56.pNode = 0i64;
                v57.pV = 0i64;
                v58 = 0i64;
                LODWORD(result.pNode) &= 0xFFFFFDE0;
              }
              else
              {
                switch ( (__int64)result.pNode & 0x1F )
                {
                  case 0xAi64:
                    v24 = (Scaleform::GFx::ASStringNode *)v57.pV;
                    v15 = LODWORD(v57.pV->pPrev)-- == 1;
                    if ( v15 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
                    break;
                  case 0xBi64:
                  case 0xCi64:
                  case 0xDi64:
                  case 0xEi64:
                  case 0xFi64:
                    v25 = v57.pV;
                    if ( ((__int64)v57.pV & 1) == 0 )
                      goto LABEL_26;
                    --v57.pV;
                    break;
                  case 0x10i64:
                  case 0x11i64:
                    v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v58;
                    if ( ((unsigned __int8)v58 & 1) != 0 )
                    {
                      v58 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)((char *)v58 - 1);
                    }
                    else
                    {
LABEL_26:
                      if ( v25 )
                      {
                        RefCount = v25->RefCount;
                        if ( (RefCount & 0x3FFFFF) != 0 )
                        {
                          v25->RefCount = RefCount - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
                        }
                      }
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            if ( v23 )
              goto LABEL_59;
            v27 = &v19->Items.Data.Data[v21];
            if ( v27->KeyInd <= 0 )
            {
              v34 = v58;
            }
            else
            {
              Data = v10->Const_Pool.ConstStr.Data.Data[v27->KeyInd].Data;
              if ( Data )
              {
                v31 = *Data;
                v29 = Data + 1;
                LODWORD(v30) = v31 & 0x7F;
                v32 = 7;
                if ( v31 < 0 )
                {
                  do
                  {
                    if ( v32 >= 0x20 )
                      break;
                    v33 = *v29++;
                    LODWORD(v30) = ((v33 & 0x7F) << v32) | v30;
                    v32 += 7;
                  }
                  while ( v33 < 0 );
                }
                v30 = (int)v30;
              }
              else
              {
                v29 = &customCaption;
                v30 = 0i64;
              }
              v34 = v58;
              v35 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                      v58,
                      &v68,
                      v29,
                      v30);
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v22, pObject, (Scaleform::GFx::ASString *)&n, v35);
              v36 = v68.pNode;
              v15 = v68.pNode->RefCount-- == 1;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v36);
            }
            v37 = v10->Const_Pool.ConstStr.Data.Data[v27->ValueInd].Data;
            if ( v37 )
            {
              v40 = *v37;
              v38 = v37 + 1;
              LODWORD(v39) = v40 & 0x7F;
              v41 = 7;
              if ( v40 < 0 )
              {
                do
                {
                  if ( v41 >= 0x20 )
                    break;
                  v42 = *v38++;
                  LODWORD(v39) = ((v42 & 0x7F) << v41) | v39;
                  v41 += 7;
                }
                while ( v42 < 0 );
              }
              v39 = (int)v39;
            }
            else
            {
              v38 = &customCaption;
              v39 = 0i64;
            }
            v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                    v34,
                    &v66,
                    v38,
                    v39);
            v44 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
                    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v22->pTraits.pObject,
                    &v71,
                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)v22->pTraits.pObject,
                    pObject,
                    (Scaleform::GFx::ASString *)&n.value,
                    v43,
                    v22)->pV;
            v65 = v44;
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              &v22->Attrs.Data,
              &v22->Attrs,
              v22->Attrs.Data.Size + 1);
            v45 = &v22->Attrs.Data.Data[v22->Attrs.Data.Size - 1];
            v72 = v45;
            v69 = v45;
            if ( v45 )
            {
              v45->pObject = v44;
              if ( v44 )
                v44->RefCount = (v44->RefCount + 1) & 0x8FBFFFFF;
            }
            if ( v44 )
            {
              if ( ((unsigned __int8)v44 & 1) != 0 )
              {
                v65 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)((char *)v44 - 1);
              }
              else
              {
                v46 = v44->RefCount;
                if ( (v46 & 0x3FFFFF) != 0 )
                {
                  v44->RefCount = v46 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v44);
                }
              }
            }
            v47 = v66.pNode;
            v15 = v66.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v47);
            ++v21;
            v19 = v61;
            pV = v57.pV;
            if ( v21 >= v20 )
            {
              StringManagerRef = (Scaleform::GFx::AS3::StringManager *)v58;
              break;
            }
          }
        }
        v11 = v62 + 1;
        v62 = v11;
        v7 = v60;
        v6 = v76;
        file = v75;
      }
      while ( v11 < v63 );
LABEL_59:
      VStr = n.value.VS._1.VStr;
      v15 = n.value.VS._1.VStr->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      v49 = *(Scaleform::GFx::ASStringNode **)&n.Flags;
      v15 = (*(_DWORD *)(*(_QWORD *)&n.Flags + 24i64))-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      v50 = v56.pNode;
      v15 = v56.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v50);
      pWeakProxy = (Scaleform::GFx::ASStringNode *)n.Bonus.pWeakProxy;
      v15 = LODWORD(n.Bonus.pWeakProxy[1].pObject)-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      v52 = result.pNode;
      v15 = result.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v52);
    }
  }
}

// File Line: 336
// RVA: 0x7C1890
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl::XMLElement *xml,
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *tr)
{
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdi
  Scaleform::GFx::AS3::Traits *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pV; // rdi
  _BOOL8 v9; // rsi
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v18; // rbx
  Scaleform::MemoryHeap *MHeap; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *Capacity; // rsi
  Scaleform::GFx::ASStringNode *v22; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v23; // rbx
  Scaleform::GFx::AS3::Traits *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // r8
  Scaleform::GFx::ASStringNode *v26; // rax
  int *v27; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v28; // rsi
  Scaleform::GFx::AS3::Traits *v29; // rcx
  Scaleform::GFx::AS3::VMFile *FirstOwnSlotNum; // rsi
  Scaleform::GFx::ASString *InternedString; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  int v36; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespaceSet; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v38; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v39; // rbx
  unsigned int v40; // eax
  __int64 v41; // rdx
  __int64 v42; // rcx
  __int64 v43; // rax
  __int64 v44; // r8
  __int64 v45; // rdx
  unsigned __int64 *v46; // rcx
  __int64 v47; // rcx
  unsigned __int64 v48; // r9
  Scaleform::GFx::AS3::Instances::fl::Namespace *v49; // rdi
  bool v50; // bl
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v54; // rbx
  _QWORD *p_vfptr; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v56; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v57; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v58; // rdi
  Scaleform::GFx::AS3::Traits *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rdx
  Scaleform::GFx::AS3::VMAppDomain *pData; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rsi
  Scaleform::GFx::ASStringNode *v63; // rdi
  Scaleform::GFx::ASStringManager *pManager; // rsi
  signed __int64 v65; // rax
  __int64 v66; // rsi
  unsigned int v67; // eax
  Scaleform::GFx::ASStringNode *ClassTraits; // rax
  Scaleform::GFx::AS3::VMAppDomain *v69; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v70; // rcx
  unsigned int v71; // eax
  Scaleform::GFx::ASStringNode *v72; // rcx
  Scaleform::GFx::ASString *QualifiedName; // rax
  Scaleform::GFx::ASStringNode *v74; // rcx
  __int64 v75; // rsi
  __int64 v76; // rdx
  __int64 v77; // rcx
  __int64 v78; // rax
  __int64 v79; // r8
  __int64 v80; // rdx
  unsigned __int64 *v81; // rcx
  __int64 v82; // rcx
  unsigned __int64 v83; // r9
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v84; // rbx
  bool v85; // di
  Scaleform::GFx::ASString *v86; // rax
  Scaleform::GFx::ASStringNode *v87; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v88; // rcx
  unsigned int v89; // eax
  Scaleform::GFx::ASStringNode *v90; // rcx
  Scaleform::GFx::ASStringNode *v91; // rcx
  Scaleform::GFx::ASStringNode *v92; // rcx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::ASStringNode *v94; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v95; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pPrev; // rsi
  _BOOL8 v97; // rbx
  Scaleform::GFx::ASStringNode *v98; // rbx
  Scaleform::GFx::ASString *v99; // rax
  int v100; // edi
  Scaleform::GFx::ASString *v101; // rax
  Scaleform::GFx::ASStringNode *v102; // rsi
  Scaleform::GFx::ASStringNode *v103; // rcx
  Scaleform::GFx::ASStringNode *v104; // rcx
  Scaleform::GFx::ASStringNode *v105; // rcx
  bool v106; // bl
  char *ValueStr; // rbx
  Scaleform::GFx::AS3::StringManager *v108; // rdi
  unsigned __int64 v109; // rax
  Scaleform::GFx::ASString *v110; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v111; // rbx
  Scaleform::GFx::ASStringNode *v112; // rcx
  Scaleform::GFx::ASString *p_pNode; // r9
  Scaleform::GFx::ASStringNode *v114; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v115; // rbx
  Scaleform::MemoryHeap *v116; // rax
  Scaleform::GFx::AS3::Slots *v117; // r8
  unsigned __int64 v118; // rsi
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v120; // rdx
  Scaleform::GFx::ASStringNode *SlotNameNode; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v122; // rbx
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *v123; // rax
  bool *p_Second; // rdi
  unsigned int v125; // eax
  Scaleform::GFx::ASStringNode *v126; // rax
  Scaleform::GFx::ASStringNode *v127; // rcx
  Scaleform::GFx::AS3::SlotInfo *v128; // rbx
  int v129; // eax
  int v130; // edi
  Scaleform::GFx::ASString *v131; // rax
  _BOOL8 v132; // rbx
  Scaleform::GFx::AS3::SlotInfo *v133; // rbx
  const char *v134; // r8
  Scaleform::GFx::ASStringNode *v135; // rcx
  Scaleform::GFx::ASString *v136; // r9
  __int64 v137; // rbx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v138; // rdi
  Scaleform::GFx::AS3::VTable *VT; // rax
  __int64 v140; // rax
  Scaleform::GFx::AS3::VMAppDomain *v141; // r8
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // rbx
  Scaleform::GFx::ASString *v143; // rax
  int v144; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v145; // rdi
  Scaleform::GFx::ASStringNode *v146; // rcx
  Scaleform::GFx::ASStringNode *v147; // rcx
  Scaleform::GFx::AS3::VTable *v148; // rax
  __int64 v149; // rdx
  __int64 v150; // rbx
  Scaleform::GFx::AS3::VMFile *v151; // r9
  __int64 vfptr; // r10
  __int64 v153; // rax
  Scaleform::GFx::ASString *v154; // rax
  int v155; // ebx
  Scaleform::GFx::ASString *v156; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v157; // rbx
  unsigned int v158; // ebx
  Scaleform::GFx::ASStringNode *v159; // rcx
  Scaleform::GFx::ASStringNode *v160; // rcx
  Scaleform::GFx::ASStringNode *v161; // rcx
  Scaleform::GFx::AS3::SlotInfo *v162; // rbx
  Scaleform::GFx::ASString *p_n; // r8
  Scaleform::GFx::ASString *v164; // rax
  Scaleform::GFx::ASStringNode *v165; // rcx
  Scaleform::GFx::ASStringNode *v166; // rax
  _BOOL8 v167; // rbx
  char *v168; // rbx
  unsigned __int64 v169; // rax
  Scaleform::GFx::ASString *v170; // rax
  Scaleform::GFx::ASStringNode *v171; // rbx
  Scaleform::GFx::ASStringNode *v172; // rcx
  Scaleform::GFx::ASString *v173; // rax
  Scaleform::GFx::ASStringNode *v174; // rcx
  Scaleform::GFx::ASString *v175; // rax
  Scaleform::GFx::ASString *v176; // rax
  Scaleform::GFx::ASStringNode *v177; // rcx
  Scaleform::GFx::ASString *v178; // r9
  Scaleform::GFx::AS3::VMAbcFile *v179; // r9
  Scaleform::GFx::AS3::SlotInfo *v180; // rbx
  Scaleform::GFx::ASString *p_result; // r8
  unsigned __int64 v182; // rcx
  unsigned __int64 v183; // rdx
  unsigned __int64 v184; // rcx
  Scaleform::GFx::AS3::SlotInfo *v185; // rdx
  int v186; // eax
  bool v187; // bl
  char *v188; // rbx
  unsigned __int64 v189; // rax
  Scaleform::GFx::ASString *v190; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v191; // rbx
  Scaleform::GFx::ASStringNode *v192; // rcx
  Scaleform::GFx::ASString *v193; // r9
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  bool v195; // cl
  Scaleform::GFx::ASString *p_v; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v197; // rbx
  bool v198; // di
  Scaleform::GFx::AS3::SlotInfo *v199; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // rax
  Scaleform::GFx::ASString *v201; // rax
  Scaleform::GFx::ASStringNode *v202; // rcx
  Scaleform::GFx::ASString *v203; // r9
  Scaleform::LongFormatter *v204; // rcx
  Scaleform::GFx::ASStringNode *v205; // rcx
  Scaleform::GFx::ASStringNode *v206; // rcx
  Scaleform::GFx::ASStringNode *v207; // rcx
  Scaleform::GFx::ASStringNode *v208; // rcx
  Scaleform::GFx::ASStringNode *v209; // rcx
  Scaleform::GFx::ASStringNode *v210; // rcx
  Scaleform::GFx::ASStringNode *v211; // rcx
  Scaleform::GFx::ASStringNode *v212; // rcx
  Scaleform::GFx::ASStringNode *v213; // rcx
  Scaleform::GFx::ASStringNode *v214; // rcx
  Scaleform::GFx::ASStringNode *v215; // rcx
  Scaleform::GFx::ASStringNode *v216; // rcx
  Scaleform::GFx::ASStringNode *v217; // rcx
  Scaleform::GFx::ASStringNode *v218; // rcx
  Scaleform::GFx::ASStringNode *v219; // rcx
  Scaleform::GFx::ASStringNode *v220; // rcx
  Scaleform::GFx::ASStringNode *v221; // rcx
  Scaleform::GFx::ASStringNode *v222; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v223; // rbx
  bool v224; // di
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v225; // rdi
  Scaleform::GFx::ASString *v226; // rax
  Scaleform::GFx::ASStringNode *v227; // rcx
  Scaleform::GFx::ASStringNode *v228; // rcx
  Scaleform::GFx::ASStringNode *v229; // rcx
  Scaleform::GFx::ASStringNode *v230; // rcx
  Scaleform::GFx::ASStringNode *v231; // rcx
  Scaleform::GFx::ASStringNode *v232; // rcx
  Scaleform::GFx::ASStringNode *v233; // rcx
  unsigned int v234; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *ns; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS3::CheckResult v236; // [rsp+40h] [rbp-C0h] BYREF
  char v237[7]; // [rsp+41h] [rbp-BFh] BYREF
  Scaleform::GFx::ASString key; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLElement *xmla; // [rsp+50h] [rbp-B0h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v240; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::ASString n; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::CheckResult v242; // [rsp+68h] [rbp-98h] BYREF
  char v243; // [rsp+69h] [rbp-97h] BYREF
  char v244[6]; // [rsp+6Ah] [rbp-96h] BYREF
  Scaleform::GFx::AS3::Value v245; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::MultinameHash<bool,2> v246; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Multiname v247; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::SlotInfo *v250; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::ASString v251; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::GFx::ASString v252; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v253; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v254; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::ASString v255; // [rsp+120h] [rbp+20h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v256; // [rsp+128h] [rbp+28h] BYREF
  Scaleform::GFx::ASStringNode *v257; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v258; // [rsp+140h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v259; // [rsp+148h] [rbp+48h] BYREF
  Scaleform::GFx::ASString v260; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::GFx::ASString v261; // [rsp+158h] [rbp+58h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v262; // [rsp+160h] [rbp+60h] BYREF
  __int64 v263; // [rsp+168h] [rbp+68h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v264; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::GFx::ASString name; // [rsp+178h] [rbp+78h] BYREF
  Scaleform::GFx::AS3::Slots *pLower; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ASString v267; // [rsp+188h] [rbp+88h] BYREF
  Scaleform::GFx::ASString v268; // [rsp+190h] [rbp+90h] BYREF
  Scaleform::GFx::ASString v; // [rsp+198h] [rbp+98h] BYREF
  Scaleform::GFx::ASString v270; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v271; // [rsp+1A8h] [rbp+A8h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v272; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::ASString v273; // [rsp+1B8h] [rbp+B8h] BYREF
  Scaleform::GFx::ASString v274; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v275; // [rsp+1C8h] [rbp+C8h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+1D0h] [rbp+D0h] BYREF
  Scaleform::GFx::ASString v277; // [rsp+1D8h] [rbp+D8h] BYREF
  Scaleform::GFx::ASString v278; // [rsp+1E0h] [rbp+E0h] BYREF
  Scaleform::GFx::ASStringNode *v279; // [rsp+1E8h] [rbp+E8h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v280; // [rsp+1F0h] [rbp+F0h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v281; // [rsp+1F8h] [rbp+F8h]
  Scaleform::GFx::AS3::Value v282; // [rsp+200h] [rbp+100h] BYREF
  Scaleform::GFx::AS3::Value v283; // [rsp+220h] [rbp+120h] BYREF
  Scaleform::GFx::ASString v284; // [rsp+240h] [rbp+140h] BYREF
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key v285; // [rsp+248h] [rbp+148h] BYREF
  Scaleform::GFx::ASString v286; // [rsp+258h] [rbp+158h] BYREF
  Scaleform::GFx::ASString v287; // [rsp+260h] [rbp+160h] BYREF
  Scaleform::GFx::ASString v288; // [rsp+268h] [rbp+168h] BYREF
  Scaleform::GFx::ASString v289; // [rsp+270h] [rbp+170h] BYREF
  Scaleform::GFx::ASStringNode *v290; // [rsp+278h] [rbp+178h] BYREF
  Scaleform::GFx::ASString v291; // [rsp+280h] [rbp+180h] BYREF
  Scaleform::GFx::ASStringNode *v292; // [rsp+288h] [rbp+188h] BYREF
  Scaleform::GFx::ASString v293; // [rsp+290h] [rbp+190h]
  __int64 v294; // [rsp+298h] [rbp+198h]
  Scaleform::GFx::ASString v295; // [rsp+2A0h] [rbp+1A0h] BYREF
  Scaleform::GFx::ASString v296; // [rsp+2A8h] [rbp+1A8h] BYREF
  Scaleform::GFx::AS3::VMFile *file; // [rsp+2B0h] [rbp+1B0h]
  Scaleform::GFx::ASString v298; // [rsp+2B8h] [rbp+1B8h] BYREF
  Scaleform::LongFormatter v299; // [rsp+2C0h] [rbp+1C0h] BYREF
  __int64 v300; // [rsp+320h] [rbp+220h]
  Scaleform::GFx::AS3::Multiname v301; // [rsp+328h] [rbp+228h] BYREF
  Scaleform::LongFormatter v302; // [rsp+360h] [rbp+260h] BYREF
  Scaleform::LongFormatter v303; // [rsp+3C0h] [rbp+2C0h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v307; // [rsp+468h] [rbp+368h] BYREF

  v307 = tr;
  v300 = -2i64;
  v4 = vm;
  v234 = 0;
  StringManagerRef = vm->StringManagerRef;
  v254 = StringManagerRef;
  pObject = vm->PublicNamespace.pObject;
  ns = pObject;
  pNode = StringManagerRef->Builtins[4].pNode;
  ++pNode->RefCount;
  v274.pNode = StringManagerRef->Builtins[5].pNode;
  ++v274.pNode->RefCount;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &result,
    "type");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &v273,
    "optional");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &v278,
    "parameter");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &v277,
    "index");
  if ( (v307->Flags & 0x20) != 0 )
    v7 = v4->TraitsClassClass.pObject;
  else
    v7 = v307->pParent.pObject;
  v253 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupportImpl *))this->vfptr[3].Finalize_GC)(this);
  if ( !v7 )
    goto LABEL_30;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v254,
    &n,
    "extendsClass");
  while ( 1 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v262, v253, pObject, &n, 0i64);
    v256.pSecond = 0i64;
    LODWORD(v256.pFirst) = 12;
    pV = v262.pV;
    v257 = (Scaleform::GFx::ASStringNode *)v262.pV;
    v258 = 0i64;
    v9 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef *))xml->vfptr[7].~RefCountBaseGC<328>)(
                     xml,
                     &v236,
                     &v256) == 0;
    if ( (unsigned __int64)((__int64)v256.pFirst & 0x1F) > 9 )
    {
      if ( ((__int64)v256.pFirst & 0x200) != 0 )
      {
        v10 = (*(_DWORD *)v256.pSecond)-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v256.pSecond = 0i64;
        v257 = 0i64;
        v258 = 0i64;
        LODWORD(v256.pFirst) &= 0xFFFFFDE0;
      }
      else
      {
        switch ( (__int64)v256.pFirst & 0x1F )
        {
          case 0xAi64:
            v11 = v257;
            v10 = v257->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v11);
            break;
          case 0xBi64:
          case 0xCi64:
          case 0xDi64:
          case 0xEi64:
          case 0xFi64:
            v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v257;
            if ( ((unsigned __int8)v257 & 1) == 0 )
              goto LABEL_19;
            v257 = (Scaleform::GFx::ASStringNode *)((char *)v257 - 1);
            break;
          case 0x10i64:
          case 0x11i64:
            v12 = v258;
            if ( ((unsigned __int8)v258 & 1) != 0 )
            {
              v258 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v258 - 1);
            }
            else
            {
LABEL_19:
              if ( v12 )
              {
                RefCount = v12->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v12->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( v9 )
    {
      v17 = n.pNode;
      goto LABEL_453;
    }
    v14 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *, _QWORD))v7->vfptr[1].Finalize_GC)(
                                        v7,
                                        &v261,
                                        0i64);
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, &result, v14);
    v15 = v261.pNode;
    v10 = v261.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v7 = v7->pParent.pObject;
    if ( !v7 )
      break;
    pObject = ns;
  }
  v16 = n.pNode;
  v10 = n.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v4 = vm;
LABEL_30:
  v18 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v307;
  if ( (v307->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      v254,
      &v251,
      "implementsInterface");
    MHeap = v4->MHeap;
    pTable = 0i64;
    v246.Entries.mHash.pTable = 0i64;
    v246.Entries.mHash.pHeap = MHeap;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v254, &key);
    Capacity = v18;
    xmla = v18;
    do
    {
      if ( (Capacity->Attrs.Data.Size & 0x10) != 0 )
      {
        v22 = (Scaleform::GFx::ASStringNode *)Capacity[1].Ns.pObject;
        v252.pNode = v22;
        v23 = Capacity[1].Parent.pObject;
        if ( !LOBYTE(v23->Text.pNode) )
        {
          v23->vfptr[6].Finalize_GC(Capacity[1].Parent.pObject);
          v24 = v23->pTraits.pObject;
          if ( !v24->pVM->HandleException )
            Scaleform::GFx::AS3::VM::ExecuteCode(v24->pVM, 1u);
          v22 = v252.pNode;
        }
        v25 = *(Scaleform::GFx::ASStringNode **)(Capacity[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum + 152);
        name.pNode = v25;
        pLower = (Scaleform::GFx::AS3::Slots *)v22[1].pLower;
        LODWORD(v26) = 0;
        v260.pNode = 0i64;
        if ( pLower )
        {
          do
          {
            v27 = (int *)((char *)v25[4].pLower + 16 * *((int *)&v22[1].pManager->vfptr + (unsigned int)v26));
            v28 = Capacity[1].Parent.pObject;
            if ( !LOBYTE(v28->Text.pNode) )
            {
              v28->vfptr[6].Finalize_GC(v28);
              v29 = v28->pTraits.pObject;
              if ( !v29->pVM->HandleException )
                Scaleform::GFx::AS3::VM::ExecuteCode(v29->pVM, 1u);
            }
            FirstOwnSlotNum = (Scaleform::GFx::AS3::VMFile *)xmla[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum;
            v247.Kind = v27[3];
            v247.Obj.pObject = 0i64;
            v247.Name.Flags = 0;
            v247.Name.Bonus.pWeakProxy = 0i64;
            if ( v27[3] || v27[2] || *v27 )
            {
              InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                                 FirstOwnSlotNum,
                                 (Scaleform::GFx::ASString *)&v262,
                                 v27[2]);
              Scaleform::GFx::AS3::Value::Assign(&v247.Name, InternedString);
              v32 = (Scaleform::GFx::ASStringNode *)v262.pV;
              v10 = LODWORD(v262.pV->pPrev)-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v32);
              if ( (v247.Name.Flags & 0x1F) == 10 )
              {
                Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v247.Name, &n);
                if ( n.pNode->Size )
                {
                  if ( *n.pNode->pData == 64 )
                  {
                    v247.Kind |= 8u;
                    v33 = Scaleform::GFx::ASString::Substring(&n, &v261, 1, n.pNode->Size);
                    Scaleform::GFx::AS3::Value::Assign(&v247.Name, v33);
                    v34 = v261.pNode;
                    v10 = v261.pNode->RefCount-- == 1;
                    if ( v10 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
                  }
                }
                v35 = n.pNode;
                v10 = n.pNode->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v35);
              }
            }
            v36 = v27[3] & 3;
            if ( v36 )
            {
              if ( v36 == 2 )
              {
                InternedNamespaceSet = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                                                          FirstOwnSlotNum,
                                                                                          *v27);
LABEL_58:
                v38 = v247.Obj.pObject;
                v39 = InternedNamespaceSet;
                if ( InternedNamespaceSet != v247.Obj.pObject )
                {
                  if ( InternedNamespaceSet )
                  {
                    InternedNamespaceSet->RefCount = (InternedNamespaceSet->RefCount + 1) & 0x8FBFFFFF;
                    v38 = v247.Obj.pObject;
                  }
                  if ( v38 )
                  {
                    if ( ((__int64)v247.Obj.pObject & 1) != 0 )
                    {
                      v247.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v38 - 1);
                    }
                    else
                    {
                      v40 = v38->RefCount;
                      if ( (v40 & 0x3FFFFF) != 0 )
                      {
                        v38->RefCount = v40 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
                      }
                    }
                  }
                  v247.Obj.pObject = v39;
                }
              }
            }
            else if ( *v27 )
            {
              InternedNamespaceSet = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(FirstOwnSlotNum, *v27);
              goto LABEL_58;
            }
            if ( !Scaleform::GFx::AS3::Value::Convert2String(&v247.Name, &v236, &key)->Result )
              goto LABEL_142;
            if ( pTable )
            {
              v41 = 8i64;
              v42 = 5381i64;
              do
              {
                --v41;
                v43 = 65599 * v42 + *((unsigned __int8 *)&key.pNode + v41);
                v42 = v43;
              }
              while ( v41 );
              v44 = v43 & pTable->SizeMask;
              v45 = v44;
              v46 = &pTable[v44 + 1].EntryCount + v44;
              if ( *v46 != -2i64 && v46[1] == v44 )
              {
                while ( v46[1] != v44 || (Scaleform::GFx::ASStringNode *)v46[2] != key.pNode )
                {
                  v45 = *v46;
                  if ( *v46 == -1i64 )
                    goto LABEL_79;
                  v46 = &pTable[v45 + 1].EntryCount + v45;
                }
                if ( v45 >= 0
                  && (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)&pTable[v45 + 2] + 8 * v45) )
                {
                  goto LABEL_142;
                }
              }
            }
LABEL_79:
            v47 = 8i64;
            v48 = 5381i64;
            do
            {
              --v47;
              v48 = *((unsigned __int8 *)&key.pNode + v47) + 65599 * v48;
            }
            while ( v47 );
            Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
              (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v246,
              v246.Entries.mHash.pHeap,
              &key,
              v48);
            v49 = ns;
            Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v259, v253, ns, &v251, 0i64);
            value.Bonus.pWeakProxy = 0i64;
            value.Flags = 12;
            *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&value.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v259.pV;
            value.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
            v50 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xml->vfptr[7].~RefCountBaseGC<328>)(
                              xml,
                              &v243,
                              &value) == 0;
            if ( (value.Flags & 0x1F) > 9 )
            {
              if ( (value.Flags & 0x200) != 0 )
              {
                v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v10 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&value.Bonus, 0, 24);
                value.Flags &= 0xFFFFFDE0;
              }
              else
              {
                switch ( value.Flags & 0x1F )
                {
                  case 0xA:
                    VStr = value.value.VS._1.VStr;
                    v10 = value.value.VS._1.VStr->RefCount-- == 1;
                    if ( v10 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
                    break;
                  case 0xB:
                  case 0xC:
                  case 0xD:
                  case 0xE:
                  case 0xF:
                    VObj = value.value.VS._1.VObj;
                    if ( !value.value.VS._1.VBool )
                      goto LABEL_93;
                    --value.value.VS._1.VStr;
                    break;
                  case 0x10:
                  case 0x11:
                    VObj = value.value.VS._2.VObj;
                    if ( ((__int64)value.value.VS._2.VObj & 1) != 0 )
                    {
                      --value.value.VS._2.VObj;
                    }
                    else
                    {
LABEL_93:
                      if ( VObj )
                      {
                        v53 = VObj->RefCount;
                        if ( (v53 & 0x3FFFFF) != 0 )
                        {
                          VObj->RefCount = v53 - 1;
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
            if ( v50 )
            {
              if ( (v247.Name.Flags & 0x1F) > 9 )
              {
                if ( (v247.Name.Flags & 0x200) != 0 )
                {
                  v10 = v247.Name.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v10 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&v247.Name.Bonus, 0, 24);
                  v247.Name.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v247.Name);
                }
              }
              v88 = v247.Obj.pObject;
              if ( v247.Obj.pObject )
              {
                if ( ((__int64)v247.Obj.pObject & 1) != 0 )
                {
                  --v247.Obj.pObject;
                }
                else
                {
                  v89 = v247.Obj.pObject->RefCount;
                  if ( (v89 & 0x3FFFFF) != 0 )
                  {
                    v247.Obj.pObject->RefCount = v89 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v88);
                  }
                }
              }
              goto LABEL_185;
            }
            if ( (v247.Kind & 3u) > 1 )
            {
              p_vfptr = &v247.Obj.pObject->vfptr;
              v267.pNode = (Scaleform::GFx::ASStringNode *)v247.Obj.pObject;
              v268.pNode = (Scaleform::GFx::ASStringNode *)v247.Obj.pObject[1]._pRCC;
              v56 = 0i64;
              v240.pV = 0i64;
              if ( !v268.pNode )
                goto LABEL_138;
              while ( 1 )
              {
                v54 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(p_vfptr[5] + 8i64 * (_QWORD)v56);
                v57 = xmla;
                v58 = xmla[1].Parent.pObject;
                if ( !LOBYTE(v58->Text.pNode) )
                {
                  v58->vfptr[6].Finalize_GC(xmla[1].Parent.pObject);
                  v59 = v58->pTraits.pObject;
                  if ( !v59->pVM->HandleException )
                    Scaleform::GFx::AS3::VM::ExecuteCode(v59->pVM, 1u);
                }
                v60 = *(Scaleform::GFx::ASStringNode **)(v57[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum + 48);
                v255.pNode = v60;
                pData = (Scaleform::GFx::AS3::VMAppDomain *)v60[1].pData;
                if ( !pData )
                  goto LABEL_106;
                ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(pData, &key, v54);
                if ( !ClassTrait )
                  break;
LABEL_121:
                if ( *ClassTrait )
                  goto LABEL_134;
LABEL_122:
                ClassTraits = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                                vm->GlobalObject.pObject,
                                                                &key,
                                                                v54);
                if ( ClassTraits )
                {
                  v69 = vm->SystemDomain.pObject;
                  v255.pNode = ClassTraits;
                  v271.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)key.pNode;
                  ++key.pNode->RefCount;
                  v272 = v54;
                  if ( v54 )
                    v54->RefCount = (v54->RefCount + 1) & 0x8FBFFFFF;
                  v256.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v271;
                  v256.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v255;
                  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
                    &v69->ClassTraitsSet.Entries.mHash,
                    v69->ClassTraitsSet.Entries.mHash.pHeap,
                    &v256,
                    HIDWORD(v271.pV->pPrevRoot) & 0xFFFFFF ^ (4 * (HIDWORD(v272[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v272[1].vfptr) << 28) >> 28));
                  v70 = v272;
                  if ( v272 )
                  {
                    if ( ((unsigned __int8)v272 & 1) != 0 )
                    {
                      v272 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v272 - 1);
                    }
                    else
                    {
                      v71 = v272->RefCount;
                      if ( (v71 & 0x3FFFFF) != 0 )
                      {
                        v272->RefCount = v71 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v70);
                      }
                    }
                  }
                  v72 = (Scaleform::GFx::ASStringNode *)v271.pV;
                  v10 = LODWORD(v271.pV->pPrev)-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v72);
LABEL_134:
                  v49 = ns;
                  goto LABEL_135;
                }
                v56 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)&v240.pV->vfptr + 1);
                v240.pV = v56;
                if ( v56 >= (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v268.pNode )
                {
                  v49 = ns;
                  goto LABEL_138;
                }
                p_vfptr = v267.pNode;
              }
              v60 = v255.pNode;
LABEL_106:
              v63 = key.pNode;
              v285.Name = key;
              ++key.pNode->RefCount;
              v285.pNs.pObject = v54;
              if ( v54 )
                v54->RefCount = (v54->RefCount + 1) & 0x8FBFFFFF;
              pManager = v60[1].pManager;
              if ( pManager
                && (v65 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v60[1].pManager,
                            &v285,
                            *(_QWORD *)&pManager->RefCount & (v63->HashFlags & 0xFFFFFF ^ (4
                                                                                         * (v54->Uri.pNode->HashFlags & 0xFFFFFF)) ^ (unsigned __int64)(unsigned int)((int)(*((_DWORD *)v54 + 10) << 28) >> 28))),
                    v65 >= 0)
                && (v66 = (__int64)&(&pManager->pFreeStringNodes)[5 * v65]) != 0 )
              {
                ClassTrait = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v66 + 16);
              }
              else
              {
                ClassTrait = 0i64;
              }
              if ( v54 )
              {
                if ( ((unsigned __int8)v54 & 1) != 0 )
                {
                  v285.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v54 - 1);
                }
                else
                {
                  v67 = v54->RefCount;
                  if ( (v67 & 0x3FFFFF) != 0 )
                  {
                    v54->RefCount = v67 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v54);
                  }
                }
              }
              v10 = v63->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v63);
              if ( !ClassTrait )
                goto LABEL_122;
              goto LABEL_121;
            }
            v54 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v247.Obj.pObject;
LABEL_135:
            if ( !v54 )
LABEL_138:
              v54 = v49;
            QualifiedName = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(&v, v54, &key, qnfWithColons);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v259.pV, v49, &result, QualifiedName);
            v74 = v.pNode;
            v10 = v.pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v74);
            pTable = v246.Entries.mHash.pTable;
LABEL_142:
            Scaleform::GFx::AS3::Multiname::~Multiname(&v247);
            v26 = (Scaleform::GFx::ASStringNode *)((char *)&v260.pNode->pData + 1);
            v260.pNode = v26;
            Capacity = xmla;
            v22 = v252.pNode;
            v25 = name.pNode;
          }
          while ( v26 < (Scaleform::GFx::ASStringNode *)pLower );
        }
      }
      else
      {
        v255.pNode = (Scaleform::GFx::ASStringNode *)Capacity[1].Ns.pObject;
        v240.pV = 0i64;
        if ( v255.pNode )
        {
          v75 = 0i64;
          do
          {
            if ( Scaleform::GFx::AS3::Value::Convert2String(
                   (Scaleform::GFx::AS3::Value *)((char *)&xmla[1].Parent.pObject->16 + v75),
                   &v242,
                   &key)->Result )
            {
              if ( !pTable )
                goto LABEL_158;
              v76 = 8i64;
              v77 = 5381i64;
              do
              {
                --v76;
                v78 = 65599 * v77 + *((unsigned __int8 *)&key.pNode + v76);
                v77 = v78;
              }
              while ( v76 );
              v79 = v78 & pTable->SizeMask;
              v80 = v79;
              v81 = &pTable[v79 + 1].EntryCount + v79;
              if ( *v81 == -2i64 || v81[1] != v79 )
                goto LABEL_158;
              while ( v81[1] != v79 || (Scaleform::GFx::ASStringNode *)v81[2] != key.pNode )
              {
                v80 = *v81;
                if ( *v81 == -1i64 )
                  goto LABEL_158;
                v81 = &pTable[v80 + 1].EntryCount + v80;
              }
              if ( v80 < 0
                || !(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)&pTable[v80 + 2] + 8 * v80) )
              {
LABEL_158:
                v82 = 8i64;
                v83 = 5381i64;
                do
                {
                  --v82;
                  v83 = *((unsigned __int8 *)&key.pNode + v82) + 65599 * v83;
                }
                while ( v82 );
                Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v246,
                  v246.Entries.mHash.pHeap,
                  &key,
                  v83);
                Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v264, v253, ns, &v251, 0i64);
                v245.Bonus.pWeakProxy = 0i64;
                v245.Flags = 12;
                v84 = v264.pV;
                *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v245.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v264.pV;
                v245.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
                v85 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xml->vfptr[7].~RefCountBaseGC<328>)(
                                  xml,
                                  v237,
                                  &v245) == 0;
                if ( (v245.Flags & 0x1F) > 9 )
                {
                  if ( (v245.Flags & 0x200) != 0 )
                  {
                    v10 = v245.Bonus.pWeakProxy->RefCount-- == 1;
                    if ( v10 )
                      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                    memset(&v245.Bonus, 0, 24);
                    v245.Flags &= 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&v245);
                  }
                }
                if ( v85 )
                {
LABEL_185:
                  v90 = key.pNode;
                  v10 = key.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v90);
                  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v246);
                  v17 = v251.pNode;
                  goto LABEL_453;
                }
                v86 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                        &v270,
                        *(Scaleform::GFx::AS3::Instances::fl::Namespace **)((char *)&xmla[1].Parent.pObject->_pRCC + v75),
                        &key,
                        qnfWithColons);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v84, ns, &result, v86);
                v87 = v270.pNode;
                v10 = v270.pNode->RefCount-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v87);
                pTable = v246.Entries.mHash.pTable;
              }
            }
            ++v240.pV;
            v75 += 48i64;
          }
          while ( v240.pV < (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v255.pNode );
          Capacity = xmla;
        }
      }
      Capacity = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)Capacity->Children.Data.Policy.Capacity;
      xmla = Capacity;
    }
    while ( Capacity );
    v91 = key.pNode;
    v10 = key.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v91);
    Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&v246);
    v92 = v251.pNode;
    v10 = v251.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v92);
    v18 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v307;
  }
  Size = v18->Attrs.Data.Size;
  if ( (Size & 0x10) == 0 )
    goto LABEL_237;
  if ( (Size & 0x20) != 0 )
    goto LABEL_237;
  v94 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)v18);
  v252.pNode = v94;
  v95 = *(Scaleform::GFx::AS3::Instances::fl::XMLElement **)(*(_QWORD *)(*(_QWORD *)&v94[3].Size + 224i64)
                                                           + 8i64 * SLODWORD(v18[1].Ns.pObject->pPrev));
  v262.pV = v95;
  pPrev = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v95->pPrev;
  v264.pV = pPrev;
  if ( !pPrev )
    goto LABEL_237;
  pLower = (Scaleform::GFx::AS3::Slots *)((char *)pPrev - (char *)v95->DynAttrs.mHash.pTable);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v254,
    &n,
    "constructor");
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v240, v253, ns, &n, 0i64);
  v245.Bonus.pWeakProxy = 0i64;
  v245.Flags = 12;
  *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v245.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v240.pV;
  v245.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
  v97 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xml->vfptr[7].~RefCountBaseGC<328>)(
                    xml,
                    v237,
                    &v245) == 0;
  if ( (v245.Flags & 0x1F) > 9 )
  {
    if ( (v245.Flags & 0x200) != 0 )
    {
      v10 = v245.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v245.Bonus, 0, 24);
      v245.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v245);
    }
  }
  if ( v97 )
  {
LABEL_236:
    v17 = n.pNode;
LABEL_453:
    v10 = v17->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_455;
  }
  v98 = 0i64;
  v260.pNode = 0i64;
  do
  {
    Scaleform::GFx::AS3::Multiname::Multiname(
      &v247,
      (Scaleform::GFx::AS3::VMFile *)v94,
      (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(*(_QWORD *)&v94[3].Size + 176i64)
                                            + 16i64 * *((unsigned int *)&v262.pV->pNext->vfptr + (_QWORD)v98)));
    if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v247) )
    {
      v99 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              v254,
              &v268,
              pattern);
      v100 = v234 | 1;
    }
    else
    {
      v101 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v247.Name, &v255);
      v99 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
              &v261,
              (Scaleform::GFx::AS3::Instances::fl::Namespace *)v247.Obj.pObject,
              v101,
              qnfWithColons);
      v100 = v234 | 6;
    }
    v234 = v100;
    v102 = v99->pNode;
    v.pNode = v102;
    ++v102->RefCount;
    if ( (v100 & 4) != 0 )
    {
      v100 &= ~4u;
      v234 = v100;
      v103 = v261.pNode;
      v10 = v261.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v103);
    }
    if ( (v100 & 2) != 0 )
    {
      v100 &= ~2u;
      v234 = v100;
      v104 = v255.pNode;
      v10 = v255.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v104);
    }
    if ( (v100 & 1) != 0 )
    {
      v234 = v100 & 0xFFFFFFFE;
      v105 = v268.pNode;
      v10 = v268.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v105);
    }
    name.pNode = (Scaleform::GFx::ASStringNode *)((char *)&v98->pData + 1);
    Scaleform::LongFormatter::LongFormatter(&v299, (unsigned __int64)&v98->pData + 1);
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v259, v253, ns, &v278, 0i64);
    v245.Bonus.pWeakProxy = 0i64;
    v245.Flags = 12;
    *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v245.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v259.pV;
    v245.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
    v106 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))v240.pV->vfptr[7].~RefCountBaseGC<328>)(
                       v240.pV,
                       v237,
                       &v245) == 0;
    if ( (v245.Flags & 0x1F) > 9 )
    {
      if ( (v245.Flags & 0x200) != 0 )
      {
        v10 = v245.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v245.Bonus, 0, 24);
        v245.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v245);
      }
    }
    if ( v106 )
    {
      v299.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
      Scaleform::Formatter::~Formatter(&v299);
      v10 = v102->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v102);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v247);
      goto LABEL_236;
    }
    Scaleform::LongFormatter::Convert(&v299);
    ValueStr = v299.ValueStr;
    v108 = vm->StringManagerRef;
    v109 = Scaleform::LongFormatter::GetSize(&v299);
    v110 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
             v108,
             &v267,
             ValueStr,
             v109);
    v111 = v259.pV;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v259.pV, ns, &v277, v110);
    v112 = v267.pNode;
    v10 = v267.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v112);
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v111, ns, &result, &v);
    p_pNode = (Scaleform::GFx::ASString *)&pNode;
    if ( v260.pNode < (Scaleform::GFx::ASStringNode *)pLower )
      p_pNode = &v274;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v111, ns, &v273, p_pNode);
    v299.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v299);
    v10 = v102->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v102);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v247);
    v98 = name.pNode;
    v260.pNode = name.pNode;
    v94 = v252.pNode;
  }
  while ( name.pNode < (Scaleform::GFx::ASStringNode *)v264.pV );
  v114 = n.pNode;
  v10 = n.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v114);
LABEL_237:
  v115 = v254;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v254,
    (Scaleform::GFx::ASString *)&v240,
    "access");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    (Scaleform::GFx::ASString *)&v259,
    "accessor");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v260,
    "method");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v268,
    "declaredBy");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v267,
    "constant");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v,
    "variable");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &n,
    "returnType");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v252,
    "uri");
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v115,
    &v270,
    "name");
  v116 = vm->MHeap;
  v275.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&v246;
  v284.pNode = (Scaleform::GFx::ASStringNode *)&v246;
  v246.Entries.mHash.pTable = 0i64;
  v246.Entries.mHash.pHeap = v116;
  v117 = &v307->Scaleform::GFx::AS3::Slots;
  pLower = &v307->Scaleform::GFx::AS3::Slots;
  v118 = v307->VArray.Data.Size + v307->FirstOwnSlotNum - 1;
  while ( 2 )
  {
    if ( (__int64)v118 > -1 )
    {
      if ( v118 < v117->FirstOwnSlotNum )
      {
        SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(v117->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v118);
        v250 = SlotInfo;
        v117 = pLower;
      }
      else
      {
        SlotInfo = &v117->VArray.Data.Data[(unsigned int)v118 - v117->FirstOwnSlotNum].Value;
        v250 = SlotInfo;
      }
      v120 = SlotInfo->pNs.pObject;
      if ( v120->Uri.pNode == ns->Uri.pNode && ((*((_BYTE *)ns + 40) ^ *((_BYTE *)v120 + 40)) & 0xF) == 0 )
      {
        if ( v118 < v117->FirstOwnSlotNum )
          SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                           v117->Parent,
                           (Scaleform::GFx::AS3::AbsoluteIndex)v118);
        else
          SlotNameNode = v117->VArray.Data.Data[(unsigned int)v118 - v117->FirstOwnSlotNum].Key.pObject;
        v251.pNode = SlotNameNode;
        name.pNode = SlotNameNode;
        ++SlotNameNode->RefCount;
        v122 = SlotInfo->pNs.pObject;
        v256.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)SlotNameNode;
        ++SlotNameNode->RefCount;
        v256.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)v122;
        if ( v122 )
          v122->RefCount = (v122->RefCount + 1) & 0x8FBFFFFF;
        v123 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
                 &v246.Entries.mHash,
                 (Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *)&v256);
        if ( v123 )
          p_Second = &v123->Second;
        else
          p_Second = 0i64;
        if ( v122 )
        {
          if ( ((unsigned __int8)v122 & 1) != 0 )
          {
            v256.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)((char *)&v122[-1].Prefix.value.VS._2.pTraits
                                                                             + 7);
          }
          else
          {
            v125 = v122->RefCount;
            if ( (v125 & 0x3FFFFF) != 0 )
            {
              v122->RefCount = v125 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v122);
            }
          }
        }
        v126 = v251.pNode;
        v10 = v251.pNode->RefCount-- == 1;
        if ( v10 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(v126);
          v126 = v251.pNode;
        }
        if ( p_Second )
        {
          v10 = v126->RefCount-- == 1;
          if ( v10 )
          {
            v127 = v126;
            goto LABEL_392;
          }
        }
        else
        {
          v236.Result = 1;
          v128 = v250;
          Scaleform::GFx::AS3::MultinameHash<bool,2>::Add(&v246, &name, v250->pNs.pObject, &v236.Result);
          v129 = *(_DWORD *)v128;
          v130 = (int)(*(_DWORD *)v128 << 17) >> 27;
          LODWORD(key.pNode) = v130;
          if ( v130 <= 10 )
          {
            v195 = 1;
            if ( (v129 & 3) == 0 )
            {
              TI = v128->TI;
              if ( !TI || (TI->kind & 0xF) != 6 )
                v195 = 0;
            }
            p_v = &v267;
            if ( !v195 )
              p_v = &v;
            v197 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v253, &v271, v253, ns, p_v, 0i64)->pV;
            v247.Obj.pObject = 0i64;
            v247.Kind = 12;
            *(_QWORD *)&v247.Name.Flags = v197;
            v247.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v256.pSecond;
            v198 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Multiname *))xml->vfptr[7].~RefCountBaseGC<328>)(
                               xml,
                               v244,
                               &v247) == 0;
            if ( (v247.Kind & 0x1Fu) > 9 )
            {
              if ( (v247.Kind & 0x200) != 0 )
              {
                v10 = LODWORD(v247.Obj.pObject->vfptr)-- == 1;
                if ( v10 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&v247.Obj, 0, 24);
                v247.Kind &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v247);
              }
            }
            if ( v198 )
              goto LABEL_404;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v197, ns, &v270, &name);
            v199 = v250;
            DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(v250, vm);
            if ( DataType )
            {
              v201 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *, _QWORD))DataType->vfptr[1].Finalize_GC)(
                                                   DataType,
                                                   &v275,
                                                   0i64);
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v197, ns, &result, v201);
              v202 = (Scaleform::GFx::ASStringNode *)v275.pV;
              v10 = LODWORD(v275.pV->pPrev)-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v202);
            }
            v203 = (Scaleform::GFx::ASString *)v199->pNs.pObject;
            if ( v203[7].pNode->Size )
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v197, ns, &v252, v203 + 7);
            if ( v199->TI )
              Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(this, vm, v197, v199->File.pObject);
          }
          else
          {
            v131 = &v260;
            if ( v130 != 11 )
              v131 = (Scaleform::GFx::ASString *)&v259;
            xmla = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                     v253,
                     (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v285,
                     v253,
                     ns,
                     v131,
                     0i64)->pV;
            v245.Bonus.pWeakProxy = 0i64;
            v245.Flags = 12;
            v245.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)xmla;
            v245.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
            v132 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xml->vfptr[7].~RefCountBaseGC<328>)(
                               xml,
                               v237,
                               &v245) == 0;
            if ( (v245.Flags & 0x1F) > 9 )
            {
              if ( (v245.Flags & 0x200) != 0 )
              {
                v10 = v245.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v10 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&v245.Bonus, 0, 24);
                v245.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v245);
              }
            }
            if ( v132 )
              goto LABEL_404;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v270, &name);
            v133 = v250;
            if ( (*(_DWORD *)v250 & 0x7C00) != 11264 )
            {
              v134 = 0i64;
              switch ( v130 )
              {
                case 12:
                  v134 = "readonly";
                  break;
                case 13:
                  v134 = "writeonly";
                  break;
                case 14:
                  v134 = "readwrite";
                  break;
              }
              Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                v254,
                &v255,
                v134);
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                xmla,
                ns,
                (Scaleform::GFx::ASString *)&v240,
                &v255);
              v135 = v255.pNode;
              v10 = v255.pNode->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v135);
            }
            v136 = (Scaleform::GFx::ASString *)v133->pNs.pObject;
            if ( v136[7].pNode->Size )
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v252, v136 + 7);
            v137 = ((__int64)*(_DWORD *)v133 >> 15) + (v130 == 13);
            v138 = v307;
            VT = Scaleform::GFx::AS3::Traits::GetVT(v307);
            Scaleform::GFx::AS3::VTable::GetValue(VT, &value, (Scaleform::GFx::AS3::AbsoluteIndex)v137);
            LODWORD(v263) = value.Flags & 0x1F;
            v140 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *))v138->vfptr[2].~RefCountBaseGC<328>)(v138);
            if ( v140 )
              v141 = *(Scaleform::GFx::AS3::VMAppDomain **)(v140 + 48);
            else
              v141 = v138->pVM->SystemDomain.pObject;
            FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(vm, &value, v141);
            if ( Scaleform::GFx::AS3::InstanceTraits::Traits::IsOfType(
                   FunctReturnType,
                   vm->TraitsClassClass.pObject->ITraits.pObject) )
            {
              v143 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                       v254,
                       &v289,
                       pattern);
              v144 = v234 | 8;
            }
            else
            {
              v143 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **, _QWORD))FunctReturnType->vfptr[1].Finalize_GC)(
                                                   FunctReturnType,
                                                   &v290,
                                                   0i64);
              v144 = v234 | 0x10;
            }
            v234 = v144;
            v145 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v143->pNode;
            v264.pV = v145;
            ++LODWORD(v145->pPrev);
            if ( (v144 & 0x10) != 0 )
            {
              v144 &= ~0x10u;
              v234 = v144;
              v146 = v290;
              v10 = v290->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v146);
            }
            if ( (v144 & 8) != 0 )
            {
              v234 = v144 & 0xFFFFFFF7;
              v147 = v289.pNode;
              v10 = v289.pNode->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v147);
            }
            if ( (_DWORD)v263 == 7 )
            {
              v148 = Scaleform::GFx::AS3::Traits::GetVT(value.value.VS._2.pTraits);
              v149 = (__int64)&v148->VTMethods.Data.Data[value.value.VS._1.VUInt];
              v150 = *(int *)(v149 + 16);
              v280 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(v149 + 24);
              v151 = (Scaleform::GFx::AS3::VMFile *)((__int64 (*)(void))v280->Builtins[0].pNode[1].pLower)();
              file = v151;
              vfptr = (__int64)v151[1].vfptr;
              v294 = vfptr;
              v153 = *(_QWORD *)(*(_QWORD *)(vfptr + 224) + 8 * v150);
              v263 = v153;
              if ( LODWORD(key.pNode) == 13 )
              {
                Scaleform::GFx::AS3::Multiname::Multiname(
                  &v301,
                  v151,
                  (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(vfptr + 176)
                                                        + 16i64 * **(unsigned int **)(v153 + 16)));
                if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v301) )
                {
                  v154 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                           v254,
                           &v296,
                           pattern);
                  v155 = v234 | 0x20;
                }
                else
                {
                  v156 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v301.Name, &v288);
                  v154 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                           &v295,
                           (Scaleform::GFx::AS3::Instances::fl::Namespace *)v301.Obj.pObject,
                           v156,
                           qnfWithColons);
                  v155 = v234 | 0xC0;
                }
                v234 = v155;
                v157 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v154->pNode;
                ++v154->pNode->RefCount;
                v10 = LODWORD(v145->pPrev)-- == 1;
                if ( v10 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v145);
                v145 = v157;
                v264.pV = v157;
                v158 = v234;
                if ( (v234 & 0x80u) != 0 )
                {
                  v158 = v234 & 0xFFFFFF7F;
                  v234 &= ~0x80u;
                  v159 = v295.pNode;
                  v10 = v295.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v159);
                }
                if ( (v158 & 0x40) != 0 )
                {
                  v158 &= ~0x40u;
                  v234 = v158;
                  v160 = v288.pNode;
                  v10 = v288.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v160);
                }
                if ( (v158 & 0x20) != 0 )
                {
                  v234 = v158 & 0xFFFFFFDF;
                  v161 = v296.pNode;
                  v10 = v296.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v161);
                }
                Scaleform::GFx::AS3::Multiname::~Multiname(&v301);
              }
              v162 = v250;
              p_n = &n;
              if ( (*(_DWORD *)v250 & 0x7C00) != 11264 )
                p_n = &result;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, p_n, (Scaleform::GFx::ASString *)&v264);
              v164 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *, Scaleform::GFx::ASStringNode **, _QWORD))v280->Builtins[0].pNode[1].pData)(
                                                   v280,
                                                   &v292,
                                                   0i64);
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v268, v164);
              v165 = v292;
              v10 = v292->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v165);
              if ( (*(_DWORD *)v162 & 0x7C00) == 11264 )
              {
                v281 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(v263 + 24);
                v293.pNode = (Scaleform::GFx::ASStringNode *)((char *)v281 - *(_QWORD *)(v263 + 48));
                v166 = 0i64;
                key.pNode = 0i64;
                if ( v281 )
                {
                  while ( 1 )
                  {
                    v279 = (Scaleform::GFx::ASStringNode *)((char *)&v166->pData + 1);
                    Scaleform::LongFormatter::LongFormatter(&v302, (unsigned __int64)&v166->pData + 1);
                    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                      v253,
                      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v261,
                      v253,
                      ns,
                      &v278,
                      0i64);
                    v283.Bonus.pWeakProxy = 0i64;
                    v283.Flags = 12;
                    *(Scaleform::GFx::ASString *)&v283.value.VNumber = (Scaleform::GFx::ASString)v261.pNode;
                    v283.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
                    v167 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))xmla->vfptr[7].~RefCountBaseGC<328>)(
                                       xmla,
                                       &v242,
                                       &v283) == 0;
                    if ( (v283.Flags & 0x1F) > 9 )
                    {
                      if ( (v283.Flags & 0x200) != 0 )
                      {
                        v10 = v283.Bonus.pWeakProxy->RefCount-- == 1;
                        if ( v10 )
                          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                        memset(&v283.Bonus, 0, 24);
                        v283.Flags &= 0xFFFFFDE0;
                      }
                      else
                      {
                        Scaleform::GFx::AS3::Value::ReleaseInternal(&v283);
                      }
                    }
                    if ( v167 )
                      break;
                    Scaleform::LongFormatter::Convert(&v302);
                    v168 = v302.ValueStr;
                    v280 = vm->StringManagerRef;
                    v169 = Scaleform::LongFormatter::GetSize(&v302);
                    v170 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                             v280,
                             &v298,
                             v168,
                             v169);
                    v171 = v261.pNode;
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                      (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v261.pNode,
                      ns,
                      &v277,
                      v170);
                    v172 = v298.pNode;
                    v10 = v298.pNode->RefCount-- == 1;
                    if ( v10 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v172);
                    Scaleform::GFx::AS3::Multiname::Multiname(
                      (Scaleform::GFx::AS3::Multiname *)&v299,
                      file,
                      (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(v294 + 176)
                                                            + 16i64
                                                            * *(unsigned int *)(*(_QWORD *)(v263 + 16)
                                                                              + 4 * (__int64)key.pNode)));
                    if ( Scaleform::GFx::AS3::Multiname::IsAnyType((Scaleform::GFx::AS3::Multiname *)&v299) )
                    {
                      v173 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                               v254,
                               &v287,
                               pattern);
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                        (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v171,
                        ns,
                        &result,
                        v173);
                      v174 = v287.pNode;
                    }
                    else
                    {
                      v175 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
                               (Scaleform::GFx::AS3::Value *)&v299.IsConverted,
                               &v291);
                      v176 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                               &v286,
                               (Scaleform::GFx::AS3::Instances::fl::Namespace *)v299.pParentFmt,
                               v175,
                               qnfWithColons);
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                        (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v171,
                        ns,
                        &result,
                        v176);
                      v177 = v286.pNode;
                      v10 = v286.pNode->RefCount-- == 1;
                      if ( v10 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v177);
                      v174 = v291.pNode;
                    }
                    v10 = v174->RefCount-- == 1;
                    if ( v10 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v174);
                    v178 = (Scaleform::GFx::ASString *)&pNode;
                    if ( key.pNode < v293.pNode )
                      v178 = &v274;
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                      (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v171,
                      ns,
                      &v273,
                      v178);
                    Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v299);
                    v302.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
                    Scaleform::Formatter::~Formatter(&v302);
                    v166 = v279;
                    key.pNode = v279;
                    if ( v279 >= (Scaleform::GFx::ASStringNode *)v281 )
                    {
                      v162 = v250;
                      goto LABEL_338;
                    }
                  }
                  v302.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
                  v204 = &v302;
LABEL_396:
                  Scaleform::Formatter::~Formatter(v204);
                  v10 = LODWORD(v145->pPrev)-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v145);
                  if ( (value.Flags & 0x1F) > 9 )
                  {
                    if ( (value.Flags & 0x200) != 0 )
                    {
                      v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
                      if ( v10 )
                        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                      memset(&value.Bonus, 0, 24);
                      value.Flags &= 0xFFFFFDE0;
                    }
                    else
                    {
                      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
                    }
                  }
LABEL_404:
                  v205 = v251.pNode;
                  v10 = v251.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v205);
                  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&v246.Entries.mHash);
                  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&v246.Entries.mHash);
                  v206 = v270.pNode;
                  v10 = v270.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v206);
                  v207 = v252.pNode;
                  v10 = v252.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v207);
                  v208 = n.pNode;
                  v10 = n.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v208);
                  v209 = v.pNode;
                  v10 = v.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v209);
                  v210 = v267.pNode;
                  v10 = v267.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v210);
                  v211 = v268.pNode;
                  v10 = v268.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v211);
                  v212 = v260.pNode;
                  v10 = v260.pNode->RefCount-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v212);
                  v213 = (Scaleform::GFx::ASStringNode *)v259.pV;
                  v10 = LODWORD(v259.pV->pPrev)-- == 1;
                  if ( v10 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v213);
LABEL_452:
                  v17 = (Scaleform::GFx::ASStringNode *)v240.pV;
                  goto LABEL_453;
                }
              }
LABEL_338:
              v179 = v162->File.pObject;
              if ( v162->TI && v179 )
                Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(this, vm, xmla, v179);
            }
            else
            {
              v180 = v250;
              p_result = &n;
              if ( (*(_DWORD *)v250 & 0x7C00) != 11264 )
                p_result = &result;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                xmla,
                ns,
                p_result,
                (Scaleform::GFx::ASString *)&v264);
              if ( (*(_DWORD *)v180 & 0x7C00) == 11264 )
              {
                v279 = value.value.VS._1.VStr;
                v182 = *(_QWORD *)&value.value.VS._1.VStr->Size;
                v183 = v182 >> 6;
                if ( ((v182 >> 6) & 7) != 0 || (v182 & 0x1FFE00) != 2096640 )
                {
                  v184 = v182 >> 9;
                  v185 = (Scaleform::GFx::AS3::SlotInfo *)((v184 & 0xFFF) == 4095 ? v183 & 7 : v184 & 0xFFF);
                  v250 = v185;
                  v186 = 0;
                  LODWORD(v263) = 0;
                  if ( (_DWORD)v185 )
                  {
                    while ( 1 )
                    {
                      LODWORD(key.pNode) = v186 + 1;
                      Scaleform::LongFormatter::LongFormatter(&v303, v186 + 1);
                      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                        v253,
                        &v262,
                        v253,
                        ns,
                        &v278,
                        0i64);
                      v282.Bonus.pWeakProxy = 0i64;
                      v282.Flags = 12;
                      *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v282.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement>)v262.pV;
                      v282.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v256.pSecond;
                      v187 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xmla->vfptr[7].~RefCountBaseGC<328>)(
                                         xmla,
                                         &v243,
                                         &v282) == 0;
                      if ( (v282.Flags & 0x1F) > 9 )
                      {
                        if ( (v282.Flags & 0x200) != 0 )
                        {
                          v10 = v282.Bonus.pWeakProxy->RefCount-- == 1;
                          if ( v10 )
                            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                          memset(&v282.Bonus, 0, 24);
                          v282.Flags &= 0xFFFFFDE0;
                        }
                        else
                        {
                          Scaleform::GFx::AS3::Value::ReleaseInternal(&v282);
                        }
                      }
                      if ( v187 )
                        break;
                      Scaleform::LongFormatter::Convert(&v303);
                      v188 = v303.ValueStr;
                      v281 = vm->StringManagerRef;
                      v189 = Scaleform::LongFormatter::GetSize(&v303);
                      v190 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                               v281,
                               &v284,
                               v188,
                               v189);
                      v191 = v262.pV;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v262.pV, ns, &v277, v190);
                      v192 = v284.pNode;
                      v10 = v284.pNode->RefCount-- == 1;
                      if ( v10 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v192);
                      v193 = (Scaleform::GFx::ASString *)&pNode;
                      if ( (unsigned int)v263 < (unsigned __int64)((v279->Size >> 6) & 7) )
                        v193 = &v274;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v191, ns, &v273, v193);
                      v303.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
                      Scaleform::Formatter::~Formatter(&v303);
                      v186 = (int)key.pNode;
                      LODWORD(v263) = key.pNode;
                      if ( LODWORD(key.pNode) >= (unsigned int)v250 )
                        goto LABEL_362;
                    }
                    v303.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
                    v204 = &v303;
                    goto LABEL_396;
                  }
                }
              }
            }
LABEL_362:
            v10 = LODWORD(v145->pPrev)-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v145);
            if ( (value.Flags & 0x1F) > 9 )
            {
              if ( (value.Flags & 0x200) != 0 )
              {
                v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v10 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&value.Bonus, 0, 24);
                value.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
              }
            }
          }
          v127 = v251.pNode;
          v10 = v251.pNode->RefCount-- == 1;
          if ( v10 )
LABEL_392:
            Scaleform::GFx::ASStringNode::ReleaseNode(v127);
        }
      }
      v117 = pLower;
      --v118;
      continue;
    }
    break;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&v246.Entries.mHash);
  v271.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&v246;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&v246.Entries.mHash);
  v214 = v270.pNode;
  v10 = v270.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v214);
  v215 = v252.pNode;
  v10 = v252.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v215);
  v216 = n.pNode;
  v10 = n.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v216);
  v217 = v.pNode;
  v10 = v.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v217);
  v218 = v267.pNode;
  v10 = v267.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v218);
  v219 = v268.pNode;
  v10 = v268.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v219);
  v220 = v260.pNode;
  v10 = v260.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v220);
  v221 = (Scaleform::GFx::ASStringNode *)v259.pV;
  v10 = LODWORD(v259.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v221);
  v222 = (Scaleform::GFx::ASStringNode *)v240.pV;
  v10 = LODWORD(v240.pV->pPrev)-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v222);
  if ( (v307->Flags & 0x20) != 0 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      v254,
      (Scaleform::GFx::ASString *)&v240,
      "factory");
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
      v253,
      &v275,
      v253,
      ns,
      (Scaleform::GFx::ASString *)&v240,
      xml);
    v247.Obj.pObject = 0i64;
    v247.Kind = 12;
    v223 = v275.pV;
    *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v247.Name.Flags = v275;
    v247.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v256.pSecond;
    v224 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Multiname *))xml->vfptr[7].~RefCountBaseGC<328>)(
                       xml,
                       v244,
                       &v247) == 0;
    if ( (v247.Kind & 0x1Fu) > 9 )
    {
      if ( (v247.Kind & 0x200) != 0 )
      {
        v10 = LODWORD(v247.Obj.pObject->vfptr)-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v247.Obj, 0, 24);
        v247.Kind &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v247);
      }
    }
    if ( !v224 )
    {
      v225 = v307;
      v226 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::AS3::InstanceTraits::UserDefined **, _QWORD))v307->vfptr[1].Finalize_GC)(
                                           v307,
                                           &v307,
                                           0i64);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v223, ns, &result, v226);
      v227 = (Scaleform::GFx::ASStringNode *)v307;
      v10 = LODWORD(v307->pPrev)-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v227);
      Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
        this,
        vm,
        v223,
        (Scaleform::GFx::AS3::Traits *)v225->Ns.pObject);
    }
    goto LABEL_452;
  }
LABEL_455:
  v228 = v277.pNode;
  v10 = v277.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v228);
  v229 = v278.pNode;
  v10 = v278.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v229);
  v230 = v273.pNode;
  v10 = v273.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v230);
  v231 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v231);
  v232 = v274.pNode;
  v10 = v274.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v232);
  v233 = pNode;
  v10 = pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v233);
}Object->vfptr)-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v247.Obj, 0, 24);
        v247.Kind &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v247);
      }
    }
    if ( !v224 )
    {
      v225 = v307;
      v226 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::AS3::InstanceTraits::UserDefined **, _QWORD))v307->vfptr[1].Finalize_GC)(
                                           v307,
                                           &v307,
                                           0i64);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v223, ns, &result, v226);
      v227 = (Scaleform::GFx::ASStringNode *)v307;
      v10 = LODWORD(v307->pPrev)-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v227);
      Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
        this,
        vm,
        v223,
        (Scaleform::GFx::AS3::Traits *)v225->Ns.pObject);
    }
    goto LABEL_452;
  }
LABEL_455:
  v228 = v277.pNode;
  v10 = v277.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v228);
  v229 = v278.pNode;
  v10 = v278.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(

// File Line: 775
// RVA: 0x7C3E70
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeType(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rbx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *ValueTraits; // r14
  Scaleform::GFx::ASStringNode *pNode; // r12
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // r13
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v12; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pV; // rbx
  unsigned int RefCount; // eax
  unsigned int v16; // ecx
  Scaleform::GFx::ASString *v17; // rdi
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString *v22; // rdi
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *p_v; // rdi
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASString *v29; // rdi
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *v32; // rdi
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASString *v35; // r14
  char v36; // di
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString *v43; // rax
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::ASString *v45; // rax
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASStringNode *v48; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *ns; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp-28h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v51; // [rsp+48h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v52; // [rsp+50h] [rbp-18h] BYREF
  __int64 v53; // [rsp+58h] [rbp-10h]
  Scaleform::GFx::ASString v54; // [rsp+B0h] [rbp+48h] BYREF
  Scaleform::GFx::AS3::VM *vma; // [rsp+B8h] [rbp+50h] BYREF
  Scaleform::GFx::ASString v; // [rsp+C0h] [rbp+58h] BYREF
  Scaleform::GFx::ASString v57; // [rsp+C8h] [rbp+60h] BYREF

  vma = vm;
  v54.pNode = (Scaleform::GFx::ASStringNode *)this;
  v53 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  pObject = vm->PublicNamespace.pObject;
  ns = pObject;
  ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)Scaleform::GFx::AS3::VM::GetValueTraits(vm, value);
  pNode = StringManagerRef->Builtins[4].pNode;
  v57.pNode = pNode;
  ++pNode->RefCount;
  v.pNode = StringManagerRef->Builtins[5].pNode;
  ++v.pNode->RefCount;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &resulta,
    "type");
  if ( (value->Flags & 0x1F) == 13 )
    v11 = vm->TraitsClassClass.pObject;
  else
    v11 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)ValueTraits->pParent.pObject;
  v12 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)(*((__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *))v54.pNode->pData
                                                         + 11))(v54.pNode);
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v12, &v51, v12, pObject, &resulta, 0i64);
  v13 = result->pObject;
  pV = v51.pV;
  if ( v51.pV != result->pObject )
  {
    if ( v13 )
    {
      if ( ((unsigned __int8)v13 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v13 - 1);
      }
      else
      {
        RefCount = v13->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v13->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
        }
      }
    }
    result->pObject = pV;
  }
  v16 = value->Flags & 0x1F;
  if ( v16 && (v16 - 12 > 3 && v16 != 10 || value->value.VS._1.VStr) )
  {
    v17 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::ASString *, _QWORD))ValueTraits->vfptr[1].Finalize_GC)(
                                        ValueTraits,
                                        &v52,
                                        0i64);
    ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                    StringManagerRef,
                    (Scaleform::GFx::ASString *)&v51,
                    "name");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, ConstString, v17);
    v19 = (Scaleform::GFx::ASStringNode *)v51.pV;
    v20 = LODWORD(v51.pV->pPrev)-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v21 = v52.pNode;
    v20 = v52.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v11 )
    {
      v22 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *, _QWORD))v11->vfptr[1].Finalize_GC)(
                                          v11,
                                          &v51,
                                          0i64);
      v23 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &v52,
              "base");
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v23, v22);
      v24 = v52.pNode;
      v20 = v52.pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v25 = (Scaleform::GFx::ASStringNode *)v51.pV;
      v20 = LODWORD(v51.pV->pPrev)-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    p_v = &v57;
    if ( (ValueTraits->Flags & 2) == 0 )
      p_v = &v;
    v27 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v52,
            "isDynamic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v27, p_v);
    v28 = v52.pNode;
    v20 = v52.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    v29 = &v57;
    if ( (ValueTraits->Flags & 0x40) == 0 )
      v29 = &v;
    v30 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v52,
            "isFinal");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v30, v29);
    v31 = v52.pNode;
    v20 = v52.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    v32 = &v57;
    if ( (ValueTraits->Flags & 0x20) == 0 )
      v32 = &v;
    v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v52,
            "isStatic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v33, v32);
    v34 = v52.pNode;
    v20 = v52.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
      (Scaleform::GFx::AS3::XMLSupportImpl *)v54.pNode,
      vma,
      pV,
      ValueTraits);
  }
  else
  {
    if ( v16 - 12 > 3 && v16 != 10 || value->value.VS._1.VStr )
    {
      v35 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::AS3::VM **, _QWORD))ValueTraits->vfptr[1].Finalize_GC)(
                                          ValueTraits,
                                          &vma,
                                          0i64);
      v36 = 2;
    }
    else
    {
      v35 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &v52,
              "null");
      v36 = 1;
    }
    v37 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v54,
            "name");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v37, v35);
    v38 = v54.pNode;
    v20 = v54.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    if ( (v36 & 2) != 0 )
    {
      v36 &= ~2u;
      v39 = (Scaleform::GFx::ASStringNode *)vma;
      v20 = LODWORD(vma->GC.GC)-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    }
    if ( (v36 & 1) != 0 )
    {
      v40 = v52.pNode;
      v20 = v52.pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    }
    v41 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v54,
            "isDynamic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v41, &v);
    v42 = v54.pNode;
    v20 = v54.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v42);
    v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v54,
            "isFinal");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v43, &v57);
    v44 = v54.pNode;
    v20 = v54.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v44);
    v45 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            StringManagerRef,
            &v54,
            "isStatic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(pV, ns, v45, &v);
    v46 = v54.pNode;
    v20 = v54.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  }
  v47 = resulta.pNode;
  v20 = resulta.pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = v.pNode;
  v20 = v.pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v20 = pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 821
// RVA: 0x7EA2C0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetITraitsXML(
        Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  return this->TraitsXML.pObject->ITraits.pObject;
}

// File Line: 831
// RVA: 0x7EA2D0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetITraitsXMLList(
        Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  return this->TraitsXMLList.pObject->ITraits.pObject;
}

// File Line: 848
// RVA: 0x7C8DF0
void __fastcall Scaleform::GFx::AS3::VM::EnableXMLSupport(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::XMLSupportImpl *v2; // rax
  Scaleform::GFx::AS3::XMLSupport *v3; // rax
  Scaleform::GFx::AS3::XMLSupport *v4; // rdi
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  unsigned int RefCount; // eax

  v2 = (Scaleform::GFx::AS3::XMLSupportImpl *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VM *, __int64))this->MHeap->vfptr->Alloc)(
                                                this,
                                                72i64);
  if ( v2 )
  {
    Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(v2, this);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  pObject = this->XMLSupport_.pObject;
  if ( v4 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)pObject - 1);
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
    this->XMLSupport_.pObject = v4;
  }
}

