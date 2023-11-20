// File Line: 88
// RVA: 0x785650
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::GFx::AS3::XMLSupportImpl *v3; // rsi
  Scaleform::GFx::AS3::ASRefCountCollector *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v7; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> result; // [rsp+48h] [rbp+10h]

  v2 = vm;
  v3 = this;
  v4 = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v4;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable';
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
  this->Enabled = 1;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable';
  this->VMRef = vm;
  v5 = Scaleform::GFx::AS3::ClassTraits::fl::XML::MakeClassTraits(&result, vm);
  v6 = v5->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v2, v5->pV, v2->SystemDomain.pObject);
  v3->TraitsXML.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)v6;
  v7 = Scaleform::GFx::AS3::ClassTraits::fl::XMLList::MakeClassTraits(&result, v2);
  v8 = v7->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v2, v7->pV, v2->SystemDomain.pObject);
  v3->TraitsXMLList.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)v8;
}

// File Line: 92
// RVA: 0x790110
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::~XMLSupportImpl(Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  Scaleform::GFx::AS3::XMLSupportImpl *v1; // rbx
  Scaleform::GFx::AS3::ClassTraits::fl::XMLList *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable';
  v2 = this->TraitsXMLList.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->TraitsXMLList.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)((char *)v2 - 1);
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
  v4 = v1->TraitsXML.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->TraitsXML.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)((char *)v4 - 1);
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
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x7C9A50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::CheckResult *result, bool *a3, Scaleform::GFx::AS3::Instances::fl::XML *l, Scaleform::GFx::AS3::Instances::fl::XML *r)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx
  bool *v6; // r15
  Scaleform::GFx::AS3::CheckResult *v7; // rsi
  int v8; // er14
  int v9; // ebp
  char *v10; // rcx
  char *v11; // rdx
  char v12; // al
  Scaleform::GFx::AS3::CheckResult *v13; // rax
  Scaleform::StringBuffer v14; // [rsp+28h] [rbp-80h]
  Scaleform::StringBuffer v15; // [rsp+58h] [rbp-50h]

  v5 = l;
  v6 = a3;
  v7 = result;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[8].Finalize_GC)(l);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))r->vfptr[8].Finalize_GC)(r);
  if ( (v8 == 2 || v8 == 5)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))r->vfptr[9].~RefCountBaseGC<328>)(r)
    || (v9 == 2 || v9 == 5)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v5->vfptr[9].~RefCountBaseGC<328>)(v5) )
  {
    Scaleform::StringBuffer::StringBuffer(&v15, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::StringBuffer(&v14, Scaleform::Memory::pGlobalHeap);
    v5->vfptr[8].ForEachChild_GC(
      (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr,
      (Scaleform::GFx::AS3::RefCountCollector<328> *)&v15,
      0i64);
    r->vfptr[8].ForEachChild_GC(
      (Scaleform::GFx::AS3::RefCountBaseGC<328> *)r,
      (Scaleform::GFx::AS3::RefCountCollector<328> *)&v14,
      0i64);
    if ( v15.Size != v14.Size )
      goto LABEL_20;
    v10 = &customWorldMapCaption;
    v11 = &customWorldMapCaption;
    if ( v14.pData )
      v11 = v14.pData;
    if ( v15.pData )
      v10 = v15.pData;
    if ( !strncmp(v10, v11, v15.Size) )
      v12 = 1;
    else
LABEL_20:
      v12 = 0;
    *v6 = v12;
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v14);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  }
  else
  {
    *v6 = ((unsigned int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Instances::fl::XML *))v5->vfptr[9].ForEachChild_GC)(
            v5,
            r) == 1;
  }
  v13 = v7;
  v7->Result = 1;
  return v13;
}

// File Line: 123
// RVA: 0x7C9910
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::CheckResult *result, bool *stop, bool *a4, Scaleform::GFx::AS3::Instances::fl::XML *l, Scaleform::GFx::AS3::Value *r)
{
  bool *v6; // r14
  bool *v7; // rsi
  Scaleform::GFx::AS3::CheckResult *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rdi
  char *v10; // rcx
  char *v11; // rdx
  char v12; // al
  Scaleform::StringBuffer resulta; // [rsp+28h] [rbp-70h]
  Scaleform::StringBuffer v15; // [rsp+58h] [rbp-40h]

  v6 = a4;
  v7 = stop;
  v8 = result;
  *stop = 0;
  v9 = l;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XML *))l->vfptr[9].~RefCountBaseGC<328>)(l) )
  {
LABEL_13:
    v8->Result = 1;
    return v8;
  }
  Scaleform::StringBuffer::StringBuffer(&v15, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&resulta, Scaleform::Memory::pGlobalHeap);
  v9->vfptr[8].ForEachChild_GC(
    (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr,
    (Scaleform::GFx::AS3::RefCountCollector<328> *)&v15,
    0i64);
  if ( Scaleform::GFx::AS3::Value::Convert2String(r, (Scaleform::GFx::AS3::CheckResult *)&l, &resulta)->Result )
  {
    if ( v15.Size != resulta.Size )
      goto LABEL_17;
    v10 = &customWorldMapCaption;
    v11 = &customWorldMapCaption;
    if ( resulta.pData )
      v11 = resulta.pData;
    if ( v15.pData )
      v10 = v15.pData;
    if ( !strncmp(v10, v11, resulta.Size) )
      v12 = 1;
    else
LABEL_17:
      v12 = 0;
    *v6 = v12;
    *v7 = 1;
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&resulta);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
    goto LABEL_13;
  }
  v8->Result = 0;
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&resulta);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v15);
  return v8;
}

// File Line: 143
// RVA: 0x7C9BC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXMLList(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::CheckResult *result, bool *a3, Scaleform::GFx::AS3::Instances::fl::XMLList *l, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx

  v5 = result;
  Scaleform::GFx::AS3::Instances::fl::XMLList::Equals(l, result, a3, v);
  return v5;
}

// File Line: 148
// RVA: 0x7C98A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::EqualsQName(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::CheckResult *result, bool *a3, Scaleform::GFx::AS3::Instances::fl::QName *l, Scaleform::GFx::AS3::Instances::fl::QName *r)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // r11
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rcx
  Scaleform::GFx::AS3::CheckResult *v7; // rax

  v5 = l->Ns.pObject;
  if ( v5
    && (v6 = r->Ns.pObject) != 0i64
    && v5->Uri.pNode == v6->Uri.pNode
    && !((*((_BYTE *)v6 + 40) ^ *((_BYTE *)v5 + 40)) & 0xF)
    && l->LocalName.pNode == r->LocalName.pNode )
  {
    *a3 = 1;
    result->Result = 1;
    v7 = result;
  }
  else
  {
    result->Result = 1;
    *a3 = 0;
    v7 = result;
  }
  return v7;
}

// File Line: 159
// RVA: 0x7AB180
char __fastcall Scaleform::GFx::AS3::XMLSupportImpl::Add(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Object *l, Scaleform::GFx::AS3::Object *r)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // r14
  Scaleform::GFx::AS3::Traits *v5; // r8
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rbp
  Scaleform::GFx::AS3::BuiltinTraitsType v7; // esi
  Scaleform::GFx::AS3::Traits *v8; // r9
  Scaleform::GFx::AS3::Value *v9; // r15
  Scaleform::GFx::AS3::BuiltinTraitsType v10; // edi
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v11; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v12; // rbx
  int v13; // esi
  int v14; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> resulta; // [rsp+50h] [rbp+18h]

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)l;
  v5 = l->pTraits.pObject;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)r;
  v7 = v5->TraitsType;
  v8 = r->pTraits.pObject;
  v9 = result;
  v10 = v8->TraitsType;
  if ( (unsigned int)(v7 - 18) > 1
    || !(~(LOBYTE(v5->Flags) >> 5) & 1)
    || (unsigned int)(v10 - 18) > 1
    || !(~(LOBYTE(v8->Flags) >> 5) & 1) )
  {
    return 0;
  }
  v11 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)((__int64 (*)(void))this->vfptr[4].~RefCountBaseGC<328>)();
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(&resulta, v11);
  v12 = resulta.pV;
  v13 = v7 - 18;
  if ( v13 )
  {
    if ( v13 == 1 )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(resulta.pV, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(resulta.pV, (Scaleform::GFx::AS3::Instances::fl::XML *)v4);
  }
  v14 = v10 - 18;
  if ( v14 )
  {
    if ( v14 == 1 )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v12, v6);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v12, (Scaleform::GFx::AS3::Instances::fl::XML *)v6);
  }
  Scaleform::GFx::AS3::Value::Pick(v9, (Scaleform::GFx::AS3::Object *)&v12->vfptr);
  return 1;
}

// File Line: 205
// RVA: 0x8281E0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::ToXMLString(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // rsi
  signed int v7; // ecx
  Scaleform::GFx::AS3::StringManager *v8; // r14
  char *v9; // r15
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  char *v13; // r8
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  int v16; // edx
  Scaleform::GFx::ASStringNode *v17; // rdi
  const char *v18; // rax
  const char *v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  Scaleform::GFx::AS3::Traits *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  int v26; // eax
  bool v27; // al
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  bool v32; // di
  Scaleform::GFx::AS3::VM::Error *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::AS3::CheckResult v36; // [rsp+18h] [rbp-39h]
  int v37; // [rsp+1Ch] [rbp-35h]
  Scaleform::StringBuffer buf; // [rsp+20h] [rbp-31h]
  Scaleform::GFx::ASString v39; // [rsp+50h] [rbp-1h]
  Scaleform::GFx::ASString v40; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::ASString v41; // [rsp+60h] [rbp+Fh]
  Scaleform::GFx::ASStringNode *v42; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::ASString v43; // [rsp+70h] [rbp+1Fh]
  Scaleform::GFx::ASString v44; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+2Fh]
  __int64 v46; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult v47; // [rsp+D0h] [rbp+7Fh]

  v46 = -2i64;
  v4 = v;
  v5 = vm;
  v6 = result;
  v37 = 0;
  v7 = v->Flags & 0x1F;
  if ( !v7 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*(_QWORD *)&v->value.VNumber )
  {
    v32 = ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*(_QWORD *)&v->value.VNumber;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v41,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v32 != 0)),
      vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v33, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v34 = v42;
    v12 = v42->RefCount == 1;
    --v34->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    goto LABEL_52;
  }
  v8 = vm->StringManagerRef;
  v9 = &customWorldMapCaption;
  if ( v7 <= 0 )
  {
LABEL_16:
    v16 = v4->Flags & 0x1F;
    if ( (unsigned int)(v16 - 12) <= 3 )
    {
      v17 = v4->value.VS._1.VStr;
      if ( v17 )
      {
        v18 = v17[1].pData;
        if ( *((_DWORD *)v18 + 30) == 18 )
        {
          if ( ~((const unsigned __int8)v18[112] >> 5) & 1 )
          {
            Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
            v19 = v17->pData;
            buf.pData = 0i64;
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::StringBuffer *, _QWORD, _QWORD))v19 + 25))(
              v17,
              &buf,
              0i64,
              0i64);
            if ( buf.pData )
              v9 = buf.pData;
            v20 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
                    &v39,
                    v9,
                    buf.Size);
            Scaleform::GFx::AS3::Value::Assign(v4, v20);
            v21 = v39.pNode;
            v12 = v39.pNode->RefCount == 1;
            --v21->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v21);
LABEL_43:
            Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
LABEL_44:
            v6->Result = 1;
            return v6;
          }
        }
      }
    }
    if ( (unsigned int)(v16 - 12) <= 3 )
    {
      v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VStr;
      if ( v22 )
      {
        v23 = v22->pTraits.pObject;
        if ( v23->TraitsType == 19 )
        {
          if ( ~(LOBYTE(v23->Flags) >> 5) & 1 )
          {
            v24 = Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(v22, &v43);
            Scaleform::GFx::AS3::Value::Assign(v4, v24);
            v25 = v43.pNode;
            v12 = v43.pNode->RefCount == 1;
            --v25->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v25);
            goto LABEL_44;
          }
        }
      }
    }
    v37 = 1;
    v27 = 1;
    if ( Scaleform::GFx::AS3::Value::ToPrimitiveValue(v4, &v47, v8->pStringManager)->Result )
    {
      v26 = v4->Flags & 0x1F;
      if ( v26 <= 4 || v26 == 10 )
        v27 = 0;
    }
    v37 = 0;
    if ( !v27 )
    {
      Scaleform::GFx::AS3::Value::ToStringValue(v4, &v36, v8);
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      v28 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v4, &v40);
      Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v28);
      v29 = v40.pNode;
      v12 = v40.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( buf.pData )
        v9 = buf.pData;
      v30 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
              &v41,
              v9,
              buf.Size);
      Scaleform::GFx::AS3::Value::Assign(v4, v30);
      v31 = v41.pNode;
      v12 = v41.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      goto LABEL_43;
    }
LABEL_52:
    v6->Result = 0;
    return v6;
  }
  if ( v7 > 4 )
  {
    if ( v7 == 10 )
    {
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      v10 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v4, &resulta);
      Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v10);
      v11 = resulta.pNode;
      v12 = resulta.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v13 = &customWorldMapCaption;
      if ( buf.pData )
        v13 = buf.pData;
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
              &v44,
              v13,
              buf.Size);
      Scaleform::GFx::AS3::Value::Assign(v4, v14);
      v15 = v44.pNode;
      v12 = v44.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
    }
    goto LABEL_16;
  }
  Scaleform::GFx::AS3::Value::ToStringValue(v, result, vm->StringManagerRef);
  return v6;
}Base<int,Scaleform::AllocatorGH<int,2>,Scaleform::A

// File Line: 267
// RVA: 0x7EE9D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::ASString *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+10h]

  v4 = name;
  v5 = result;
  v6 = &ns->Uri;
  if ( ns->Uri.pNode->Size )
  {
    if ( f )
      v8 = Scaleform::GFx::ASString::operator+(v6, &resulta, ".");
    else
      v8 = Scaleform::GFx::ASString::operator+(v6, &resulta, "::");
    Scaleform::GFx::ASString::operator+(v8, v5, v4);
    v9 = resulta.pNode;
    v10 = resulta.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  else
  {
    v7 = name->pNode;
    v5->pNode = name->pNode;
    ++v7->RefCount;
  }
  return v5;
}

// File Line: 280
// RVA: 0x7C12B0
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Instances::fl::XMLElement *xml, Scaleform::GFx::AS3::VMAbcFile *file)
{
  Scaleform::GFx::AS3::VMAbcFile *v4; // rsi
  Scaleform::GFx::AS3::VM *v5; // rbx
  _BYTE *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v7; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // r12
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v9; // r14
  unsigned __int64 v10; // rbx
  Scaleform::GFx::AS3::Abc::File *v11; // r13
  unsigned __int64 v12; // rax
  __int64 v13; // rsi
  const char *v14; // rdi
  unsigned __int64 v15; // rsi
  bool v16; // bl
  bool v17; // zf
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  __int64 v21; // rdi
  unsigned __int64 v22; // r15
  unsigned __int64 v23; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v24; // r14
  bool v25; // bl
  int v26; // ecx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v28; // rcx
  unsigned int v29; // eax
  signed int *v30; // rbx
  const char *v31; // r8
  const char *v32; // r8
  unsigned __int64 v33; // r9
  char v34; // al
  unsigned int v35; // ecx
  char v36; // dl
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v37; // rdi
  Scaleform::GFx::ASString *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  const char *v40; // r8
  const char *v41; // r8
  unsigned __int64 v42; // r9
  char v43; // al
  unsigned int v44; // ecx
  char v45; // dl
  Scaleform::GFx::ASString *v46; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v47; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v48; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v49; // rdx
  unsigned int v50; // eax
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::ASStringNode *v54; // rcx
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASStringNode *v56; // rcx
  char v57; // [rsp+40h] [rbp-88h]
  char v58; // [rsp+41h] [rbp-87h]
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::ASString v60; // [rsp+50h] [rbp-78h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v61; // [rsp+58h] [rbp-70h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v62; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::ASString v63; // [rsp+68h] [rbp-60h]
  Scaleform::GFx::ASString n; // [rsp+70h] [rbp-58h]
  Scaleform::GFx::ASString v65; // [rsp+78h] [rbp-50h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v66; // [rsp+80h] [rbp-48h]
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v67; // [rsp+88h] [rbp-40h]
  __int64 v68; // [rsp+90h] [rbp-38h]
  unsigned __int64 v69; // [rsp+98h] [rbp-30h]
  unsigned __int64 v70; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::ASString v71; // [rsp+A8h] [rbp-20h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v72; // [rsp+B0h] [rbp-18h]
  Scaleform::GFx::ASString v73; // [rsp+B8h] [rbp-10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v74; // [rsp+C0h] [rbp-8h]
  Scaleform::GFx::ASString v75; // [rsp+C8h] [rbp+0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v76; // [rsp+D0h] [rbp+8h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v77; // [rsp+D8h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> v78; // [rsp+E0h] [rbp+18h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v79; // [rsp+E8h] [rbp+20h]
  __int64 v80; // [rsp+F0h] [rbp+28h]
  __int64 v81; // [rsp+148h] [rbp+80h]
  Scaleform::GFx::AS3::VMAbcFile *v82; // [rsp+150h] [rbp+88h]
  _BYTE *v83; // [rsp+158h] [rbp+90h]

  v80 = -2i64;
  v4 = file;
  v5 = vm;
  v6 = v83;
  if ( *v83 & 0x40 )
  {
    v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)((__int64 (*)(void))this->vfptr[3].Finalize_GC)();
    v67 = v7;
    v8 = v5->PublicNamespace.pObject;
    v9 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins;
    v62 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins;
    v10 = *((_QWORD *)v6 + 4);
    v70 = v10;
    if ( v10 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        v9,
        &result,
        "name");
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        v9,
        &n,
        "metadata");
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        v9,
        &v60,
        "arg");
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        v9,
        &v63,
        "key");
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        v9,
        &v65,
        "value");
      v11 = v4->File.pObject;
      LODWORD(v12) = 0;
      v69 = 0i64;
      if ( v10 )
      {
        do
        {
          v13 = (__int64)v4->File.pObject->Metadata.Info.Data.Data[*(signed int *)(*((_QWORD *)v6 + 3)
                                                                                 + 4i64 * (unsigned int)v12)];
          v68 = v13;
          v14 = *(const char **)v13;
          v15 = *(_QWORD *)(v13 + 8);
          Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
            v7,
            &v61,
            (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr,
            v8,
            &n,
            0i64);
          n.pNode = 0i64;
          LODWORD(v63.pNode) = 12;
          v65.pNode = (Scaleform::GFx::ASStringNode *)v61.pV;
          v66 = v77;
          v16 = *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, Scaleform::GFx::ASString *))(*(_QWORD *)v81
                                                                                                 + 176i64))(
                            v81,
                            &v58,
                            &v63) == 0;
          if ( ((_QWORD)v63.pNode & 0x1F) > 9 )
          {
            if ( (LODWORD(v63.pNode) >> 9) & 1 )
            {
              v17 = LODWORD(n.pNode->pData)-- == 1;
              if ( v17 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              n.pNode = 0i64;
              v65.pNode = 0i64;
              v66 = 0i64;
              LODWORD(v63.pNode) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v63);
            }
          }
          if ( v16 )
            break;
          v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  v9,
                  &v71,
                  v14,
                  v15);
          v19 = v61.pV;
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v61.pV, v8, &result, v18);
          v20 = v71.pNode;
          v17 = v71.pNode->RefCount == 1;
          --v20->RefCount;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v20);
          v21 = v68;
          v22 = *(_QWORD *)(v68 + 24);
          v23 = 0i64;
          if ( v22 )
          {
            while ( 1 )
            {
              Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                v67,
                &v74,
                (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v67->vfptr,
                v8,
                &v60,
                0i64);
              v60.pNode = 0i64;
              LODWORD(result.pNode) = 12;
              v24 = v74.pV;
              v61.pV = v74.pV;
              v62 = v77;
              v25 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::ASString *))v19->vfptr[7].~RefCountBaseGC<328>)(
                                v19,
                                &v57,
                                &result) == 0;
              v26 = (_QWORD)result.pNode & 0x1F;
              if ( v26 > 9 )
              {
                if ( (LODWORD(result.pNode) >> 9) & 1 )
                {
                  v17 = LODWORD(v60.pNode->pData)-- == 1;
                  if ( v17 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v60.pNode = 0i64;
                  v61.pV = 0i64;
                  v62 = 0i64;
                  LODWORD(result.pNode) &= 0xFFFFFDE0;
                }
                else
                {
                  switch ( v26 )
                  {
                    case 10:
                      v27 = (Scaleform::GFx::ASStringNode *)v61.pV;
                      v17 = LODWORD(v61.pV->pPrev) == 1;
                      --v27->RefCount;
                      if ( v17 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
                      break;
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    case 15:
                      v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v61.pV;
                      if ( !((_QWORD)v61.pV & 1) )
                        goto LABEL_26;
                      --v61.pV;
                      break;
                    case 16:
                    case 17:
                      v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v62;
                      if ( (unsigned __int8)v62 & 1 )
                      {
                        v62 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)((char *)v62 - 1);
                      }
                      else
                      {
LABEL_26:
                        if ( v28 )
                        {
                          v29 = v28->RefCount;
                          if ( v29 & 0x3FFFFF )
                          {
                            v28->RefCount = v29 - 1;
                            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
                          }
                        }
                      }
                      break;
                    default:
                      break;
                  }
                }
              }
              if ( v25 )
                goto LABEL_59;
              v30 = (signed int *)(*(_QWORD *)(v21 + 16) + 8 * v23);
              if ( *v30 <= 0 )
              {
                v37 = v62;
              }
              else
              {
                v31 = v11->Const_Pool.ConstStr.Data.Data[*v30].Data;
                if ( v31 )
                {
                  v34 = *v31;
                  v32 = v31 + 1;
                  LODWORD(v33) = v34 & 0x7F;
                  v35 = 7;
                  if ( v34 < 0 )
                  {
                    do
                    {
                      if ( v35 >= 0x20 )
                        break;
                      v36 = *v32++;
                      LODWORD(v33) = ((v36 & 0x7F) << v35) | v33;
                      v35 += 7;
                    }
                    while ( v36 < 0 );
                  }
                  v33 = (signed int)v33;
                }
                else
                {
                  v32 = &customWorldMapCaption;
                  v33 = 0i64;
                }
                v37 = v62;
                v38 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                        v62,
                        &v75,
                        v32,
                        v33);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v24, v8, &v63, v38);
                v39 = v75.pNode;
                v17 = v75.pNode->RefCount == 1;
                --v39->RefCount;
                if ( v17 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v39);
              }
              v40 = v11->Const_Pool.ConstStr.Data.Data[v30[1]].Data;
              if ( v40 )
              {
                v43 = *v40;
                v41 = v40 + 1;
                LODWORD(v42) = v43 & 0x7F;
                v44 = 7;
                if ( v43 < 0 )
                {
                  do
                  {
                    if ( v44 >= 0x20 )
                      break;
                    v45 = *v41++;
                    LODWORD(v42) = ((v45 & 0x7F) << v44) | v42;
                    v44 += 7;
                  }
                  while ( v45 < 0 );
                }
                v42 = (signed int)v42;
              }
              else
              {
                v41 = &customWorldMapCaption;
                v42 = 0i64;
              }
              v46 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                      v37,
                      &v73,
                      v41,
                      v42);
              v47 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
                                                                   (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v24->pTraits.pObject,
                                                                   &v78,
                                                                   (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24->pTraits.pObject,
                                                                   v8,
                                                                   &v65,
                                                                   v46,
                                                                   (Scaleform::GFx::AS3::Instances::fl::XML *)&v24->vfptr);
              v48 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)*v47;
              v72 = *v47;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v24->Attrs.Data.Data,
                &v24->Attrs,
                v24->Attrs.Data.Size + 1);
              v49 = &v24->Attrs.Data.Data[v24->Attrs.Data.Size - 1];
              v79 = v49;
              v76 = v49;
              if ( v49 )
              {
                v49->pObject = v48;
                if ( v48 )
                  v48->RefCount = (v48->RefCount + 1) & 0x8FBFFFFF;
              }
              if ( v48 )
              {
                if ( (unsigned __int8)v48 & 1 )
                {
                  v72 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&v48[-1].Data.pNode + 7);
                }
                else
                {
                  v50 = v48->RefCount;
                  if ( v50 & 0x3FFFFF )
                  {
                    v48->RefCount = v50 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v48->vfptr);
                  }
                }
              }
              v51 = v73.pNode;
              v17 = v73.pNode->RefCount == 1;
              --v51->RefCount;
              if ( v17 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v51);
              ++v23;
              v21 = v68;
              v19 = v61.pV;
              if ( v23 >= v22 )
              {
                v9 = v62;
                break;
              }
            }
          }
          v12 = v69 + 1;
          v69 = v12;
          v7 = v67;
          v6 = v83;
          v4 = v82;
        }
        while ( v12 < v70 );
      }
LABEL_59:
      v52 = v65.pNode;
      v17 = v65.pNode->RefCount == 1;
      --v52->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v52);
      v53 = v63.pNode;
      v17 = v63.pNode->RefCount == 1;
      --v53->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v53);
      v54 = v60.pNode;
      v17 = v60.pNode->RefCount == 1;
      --v54->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v54);
      v55 = n.pNode;
      v17 = n.pNode->RefCount == 1;
      --v55->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v55);
      v56 = result.pNode;
      v17 = result.pNode->RefCount == 1;
      --v56->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v56);
    }
  }
}

// File Line: 336
// RVA: 0x7C1890
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Instances::fl::XMLElement *xml, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::StringManager *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rdi
  Scaleform::GFx::AS3::Traits *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v8; // rdi
  _BOOL8 v9; // rsi
  int v10; // ecx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v19; // rbx
  Scaleform::MemoryHeap *v20; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *v21; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v22; // rsi
  Scaleform::GFx::ASStringNode *v23; // rdx
  Scaleform::GFx::AS3::Instances::fl::XML *v24; // rbx
  Scaleform::GFx::AS3::Traits *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // r8
  Scaleform::GFx::ASStringNode *v27; // rax
  signed int *v28; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v29; // rsi
  Scaleform::GFx::AS3::Traits *v30; // rcx
  Scaleform::GFx::AS3::VMFile *v31; // rsi
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  unsigned int v37; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v38; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v39; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v40; // rbx
  unsigned int v41; // eax
  signed __int64 v42; // rdx
  signed __int64 v43; // rcx
  signed __int64 v44; // rax
  unsigned __int64 v45; // r8
  signed __int64 v46; // rdx
  signed __int64 v47; // rcx
  signed __int64 v48; // rcx
  unsigned __int64 v49; // r9
  Scaleform::GFx::AS3::Instances::fl::Namespace *v50; // rdi
  bool v51; // bl
  int v52; // ecx
  Scaleform::GFx::ASStringNode *v53; // rcx
  long double v54; // rcx
  int v55; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v56; // rbx
  _QWORD *v57; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v58; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v59; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v60; // rdi
  Scaleform::GFx::AS3::Traits *v61; // rcx
  Scaleform::GFx::ASStringNode *v62; // rdx
  Scaleform::GFx::AS3::VMAppDomain *v63; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v64; // rsi
  Scaleform::GFx::ASStringNode *v65; // rdi
  Scaleform::GFx::ASStringManager *v66; // rsi
  signed __int64 v67; // rax
  signed __int64 v68; // rsi
  unsigned int v69; // eax
  Scaleform::GFx::ASStringNode *v70; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v71; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v72; // rcx
  unsigned int v73; // eax
  Scaleform::GFx::ASStringNode *v74; // rcx
  Scaleform::GFx::ASString *v75; // rax
  Scaleform::GFx::ASStringNode *v76; // rcx
  __int64 v77; // rsi
  signed __int64 v78; // rdx
  signed __int64 v79; // rcx
  signed __int64 v80; // rax
  unsigned __int64 v81; // r8
  signed __int64 v82; // rdx
  signed __int64 v83; // rcx
  signed __int64 v84; // rcx
  unsigned __int64 v85; // r9
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v86; // rbx
  bool v87; // di
  Scaleform::GFx::ASString *v88; // rax
  Scaleform::GFx::ASStringNode *v89; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v90; // rcx
  unsigned int v91; // eax
  Scaleform::GFx::ASStringNode *v92; // rcx
  Scaleform::GFx::ASStringNode *v93; // rcx
  Scaleform::GFx::ASStringNode *v94; // rcx
  unsigned __int64 v95; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v96; // rax
  Scaleform::GFx::AS3::VMFile *v97; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v98; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v99; // rsi
  _BOOL8 v100; // rbx
  Scaleform::GFx::ASStringNode *v101; // rbx
  Scaleform::GFx::ASString *v102; // rax
  int v103; // edi
  Scaleform::GFx::ASString *v104; // rax
  Scaleform::GFx::ASStringNode *v105; // rsi
  Scaleform::GFx::ASStringNode *v106; // rcx
  Scaleform::GFx::ASStringNode *v107; // rcx
  Scaleform::GFx::ASStringNode *v108; // rcx
  bool v109; // bl
  char *v110; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v111; // rdi
  unsigned __int64 v112; // rax
  Scaleform::GFx::ASString *v113; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v114; // rbx
  Scaleform::GFx::ASStringNode *v115; // rcx
  Scaleform::GFx::ASString *v116; // r9
  Scaleform::GFx::ASStringNode *v117; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v118; // rbx
  Scaleform::MemoryHeap *v119; // rax
  Scaleform::GFx::AS3::Slots *v120; // r8
  signed __int64 v121; // rsi
  Scaleform::GFx::AS3::SlotInfo *v122; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v123; // rdx
  Scaleform::GFx::ASStringNode *v124; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v125; // rbx
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *v126; // rax
  signed __int64 v127; // rdi
  unsigned int v128; // eax
  Scaleform::GFx::ASStringNode *v129; // rax
  Scaleform::GFx::ASStringNode *v130; // rcx
  Scaleform::GFx::AS3::SlotInfo *v131; // rbx
  int v132; // eax
  signed int v133; // edi
  Scaleform::GFx::ASString *v134; // rax
  _BOOL8 v135; // rbx
  Scaleform::GFx::AS3::SlotInfo *v136; // rbx
  const char *v137; // r8
  Scaleform::GFx::ASStringNode *v138; // rcx
  Scaleform::GFx::ASString *v139; // r9
  signed __int64 v140; // rbx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v141; // rdi
  Scaleform::GFx::AS3::VTable *v142; // rax
  __int64 v143; // rax
  Scaleform::GFx::AS3::VMAppDomain *v144; // r8
  Scaleform::GFx::AS3::InstanceTraits::Traits *v145; // rbx
  Scaleform::GFx::ASString *v146; // rax
  int v147; // ebx
  Scaleform::GFx::ASStringNode *v148; // rdi
  Scaleform::GFx::ASStringNode *v149; // rcx
  Scaleform::GFx::ASStringNode *v150; // rcx
  Scaleform::GFx::AS3::VTable *v151; // rax
  signed __int64 v152; // rdx
  __int64 v153; // rbx
  Scaleform::GFx::AS3::VMFile *v154; // rax
  Scaleform::GFx::AS3::VMFile *v155; // r9
  __int64 v156; // r10
  __int64 v157; // rcx
  __int64 v158; // rax
  Scaleform::GFx::ASString *v159; // rax
  int v160; // ebx
  Scaleform::GFx::ASString *v161; // rax
  Scaleform::GFx::ASStringNode *v162; // rbx
  unsigned int v163; // ebx
  Scaleform::GFx::ASStringNode *v164; // rcx
  Scaleform::GFx::ASStringNode *v165; // rcx
  Scaleform::GFx::ASStringNode *v166; // rcx
  Scaleform::GFx::AS3::SlotInfo *v167; // rbx
  Scaleform::GFx::ASString *v168; // r8
  Scaleform::GFx::ASString *v169; // rax
  Scaleform::GFx::ASStringNode *v170; // rcx
  Scaleform::GFx::ASStringNode *v171; // rax
  _BOOL8 v172; // rbx
  char *v173; // rbx
  unsigned __int64 v174; // rax
  Scaleform::GFx::ASString *v175; // rax
  Scaleform::GFx::ASStringNode *v176; // rbx
  Scaleform::GFx::ASStringNode *v177; // rcx
  Scaleform::GFx::ASString *v178; // rax
  Scaleform::GFx::ASStringNode *v179; // rcx
  Scaleform::GFx::ASString *v180; // rax
  Scaleform::GFx::ASString *v181; // rax
  Scaleform::GFx::ASStringNode *v182; // rcx
  Scaleform::GFx::ASString *v183; // r9
  Scaleform::GFx::AS3::VMAbcFile *v184; // r9
  Scaleform::GFx::AS3::SlotInfo *v185; // rbx
  Scaleform::GFx::ASString *v186; // r8
  __int64 v187; // rcx
  Scaleform::GFx::AS3::SlotInfo *v188; // rdx
  int v189; // eax
  bool v190; // bl
  char *v191; // rbx
  unsigned __int64 v192; // rax
  Scaleform::GFx::ASString *v193; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v194; // rbx
  Scaleform::GFx::ASStringNode *v195; // rcx
  Scaleform::GFx::ASString *v196; // r9
  Scaleform::GFx::AS3::Abc::TraitInfo *v197; // rax
  bool v198; // cl
  Scaleform::GFx::ASString *v199; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v200; // rbx
  bool v201; // di
  Scaleform::GFx::AS3::SlotInfo *v202; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v203; // rax
  Scaleform::GFx::ASString *v204; // rax
  Scaleform::GFx::ASStringNode *v205; // rcx
  Scaleform::GFx::ASString *v206; // r9
  Scaleform::LongFormatter *v207; // rcx
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
  Scaleform::GFx::ASStringNode *v223; // rcx
  Scaleform::GFx::ASStringNode *v224; // rcx
  Scaleform::GFx::ASStringNode *v225; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v226; // rbx
  bool v227; // di
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v228; // rdi
  Scaleform::GFx::ASString *v229; // rax
  Scaleform::GFx::ASStringNode *v230; // rcx
  Scaleform::GFx::ASStringNode *v231; // rcx
  Scaleform::GFx::ASStringNode *v232; // rcx
  Scaleform::GFx::ASStringNode *v233; // rcx
  Scaleform::GFx::ASStringNode *v234; // rcx
  Scaleform::GFx::ASStringNode *v235; // rcx
  Scaleform::GFx::ASStringNode *v236; // rcx
  unsigned int v237; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *ns; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS3::CheckResult v239; // [rsp+40h] [rbp-C0h]
  char v240; // [rsp+41h] [rbp-BFh]
  Scaleform::GFx::ASString key; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *xmla; // [rsp+50h] [rbp-B0h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v243; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::ASString n; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::CheckResult v245; // [rsp+68h] [rbp-98h]
  char v246; // [rsp+69h] [rbp-97h]
  char v247; // [rsp+6Ah] [rbp-96h]
  Scaleform::GFx::AS3::Value v248; // [rsp+70h] [rbp-90h]
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > v249; // [rsp+90h] [rbp-70h]
  void *pmemAddr; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS3::Multiname v251; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::AS3::Value value; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS3::SlotInfo *v254; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::ASString v255; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::ASString v256; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v257; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v258; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::ASString v259; // [rsp+120h] [rbp+20h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v260; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::ASStringNode *v261; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v262; // [rsp+140h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v263; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::ASString v264; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::ASString v265; // [rsp+158h] [rbp+58h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v266; // [rsp+160h] [rbp+60h]
  __int64 v267; // [rsp+168h] [rbp+68h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v268; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::ASString name; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::AS3::Slots *v270; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ASString v271; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::ASString v272; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ASString v; // [rsp+198h] [rbp+98h]
  Scaleform::GFx::ASString v274; // [rsp+1A0h] [rbp+A0h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v275; // [rsp+1A8h] [rbp+A8h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v276; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::ASString v277; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::ASString v278; // [rsp+1C0h] [rbp+C0h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v279; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::ASStringNode *v280; // [rsp+1D0h] [rbp+D0h]
  Scaleform::GFx::ASString v281; // [rsp+1D8h] [rbp+D8h]
  Scaleform::GFx::ASString v282; // [rsp+1E0h] [rbp+E0h]
  Scaleform::GFx::ASStringNode *v283; // [rsp+1E8h] [rbp+E8h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v284; // [rsp+1F0h] [rbp+F0h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v285; // [rsp+1F8h] [rbp+F8h]
  Scaleform::GFx::AS3::Value v286; // [rsp+200h] [rbp+100h]
  Scaleform::GFx::AS3::Value v287; // [rsp+220h] [rbp+120h]
  Scaleform::GFx::ASString v288; // [rsp+240h] [rbp+140h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key v289; // [rsp+248h] [rbp+148h]
  Scaleform::GFx::ASString v290; // [rsp+258h] [rbp+158h]
  Scaleform::GFx::ASString v291; // [rsp+260h] [rbp+160h]
  Scaleform::GFx::ASString v292; // [rsp+268h] [rbp+168h]
  Scaleform::GFx::ASString v293; // [rsp+270h] [rbp+170h]
  Scaleform::GFx::ASStringNode *v294; // [rsp+278h] [rbp+178h]
  Scaleform::GFx::ASString v295; // [rsp+280h] [rbp+180h]
  Scaleform::GFx::ASStringNode *v296; // [rsp+288h] [rbp+188h]
  Scaleform::GFx::ASString v297; // [rsp+290h] [rbp+190h]
  __int64 v298; // [rsp+298h] [rbp+198h]
  Scaleform::GFx::ASString v299; // [rsp+2A0h] [rbp+1A0h]
  Scaleform::GFx::ASString v300; // [rsp+2A8h] [rbp+1A8h]
  Scaleform::GFx::AS3::VMFile *file; // [rsp+2B0h] [rbp+1B0h]
  Scaleform::GFx::ASString v302; // [rsp+2B8h] [rbp+1B8h]
  Scaleform::LongFormatter v303; // [rsp+2C0h] [rbp+1C0h]
  __int64 v304; // [rsp+320h] [rbp+220h]
  Scaleform::GFx::AS3::Multiname v305; // [rsp+328h] [rbp+228h]
  Scaleform::LongFormatter v306; // [rsp+360h] [rbp+260h]
  Scaleform::LongFormatter v307; // [rsp+3C0h] [rbp+2C0h]
  Scaleform::GFx::AS3::XMLSupportImpl *v308; // [rsp+450h] [rbp+350h]
  Scaleform::GFx::AS3::VM *vma; // [rsp+458h] [rbp+358h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *p; // [rsp+460h] [rbp+360h]
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v311; // [rsp+468h] [rbp+368h]

  v311 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)tr;
  p = xml;
  vma = vm;
  v308 = this;
  v304 = -2i64;
  v4 = vm;
  v237 = 0;
  v5 = vm->StringManagerRef;
  v258 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins;
  v6 = vm->PublicNamespace.pObject;
  ns = vm->PublicNamespace.pObject;
  v280 = v5->Builtins[4].pNode;
  ++v280->RefCount;
  v278.pNode = v5->Builtins[5].pNode;
  ++v278.pNode->RefCount;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
    &result,
    "type");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
    &v277,
    "optional");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
    &v282,
    "parameter");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
    &v281,
    "index");
  if ( (LOBYTE(v311->Flags) >> 5) & 1 )
    v7 = (Scaleform::GFx::AS3::Traits *)&v4->TraitsClassClass.pObject->vfptr;
  else
    v7 = v311->pParent.pObject;
  v257 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)((__int64 (*)(void))v308->vfptr[3].Finalize_GC)();
  if ( !v7 )
    goto LABEL_30;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v258,
    &n,
    "extendsClass");
  while ( 1 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
      v257,
      &v266,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
      v6,
      &n,
      0i64);
    v260.pSecond = 0i64;
    LODWORD(v260.pFirst) = 12;
    v8 = v266.pV;
    v261 = (Scaleform::GFx::ASStringNode *)v266.pV;
    v262 = 0i64;
    v9 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef *))p->vfptr[7].~RefCountBaseGC<328>)(
                     p,
                     &v239,
                     &v260) == 0;
    v10 = (_QWORD)v260.pFirst & 0x1F;
    if ( v10 > 9 )
    {
      if ( (LODWORD(v260.pFirst) >> 9) & 1 )
      {
        v11 = (*(_DWORD *)v260.pSecond)-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v260.pSecond = 0i64;
        v261 = 0i64;
        v262 = 0i64;
        LODWORD(v260.pFirst) &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v10 )
        {
          case 10:
            v12 = v261;
            v11 = v261->RefCount == 1;
            --v12->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v13 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v261;
            if ( !((unsigned __int8)v261 & 1) )
              goto LABEL_19;
            v261 = (Scaleform::GFx::ASStringNode *)((char *)v261 - 1);
            break;
          case 16:
          case 17:
            v13 = v262;
            if ( (unsigned __int8)v262 & 1 )
            {
              v262 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v262 - 1);
            }
            else
            {
LABEL_19:
              if ( v13 )
              {
                v14 = v13->RefCount;
                if ( v14 & 0x3FFFFF )
                {
                  v13->RefCount = v14 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( (_BYTE)v9 )
    {
      v18 = n.pNode;
      goto LABEL_457;
    }
    v15 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *, _QWORD))v7->vfptr[1].Finalize_GC)(
                                        v7,
                                        &v265,
                                        0i64);
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v8, ns, &result, v15);
    v16 = v265.pNode;
    v11 = v265.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    v7 = v7->pParent.pObject;
    if ( !v7 )
      break;
    v6 = ns;
  }
  v17 = n.pNode;
  v11 = n.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v4 = vma;
LABEL_30:
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v311;
  if ( ~(LOBYTE(v311->Flags) >> 5) & 1 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      v258,
      &v255,
      "implementsInterface");
    v20 = v4->MHeap;
    v21 = 0i64;
    v249.pTable = 0i64;
    pmemAddr = v20;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v258, &key);
    v22 = v19;
    xmla = v19;
    do
    {
      if ( (LOBYTE(v22->Attrs.Data.Size) >> 4) & 1 )
      {
        v23 = (Scaleform::GFx::ASStringNode *)v22[1].Ns.pObject;
        v256.pNode = (Scaleform::GFx::ASStringNode *)v22[1].Ns.pObject;
        v24 = v22[1].Parent.pObject;
        if ( !LOBYTE(v24->Text.pNode) )
        {
          v24->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22[1].Parent.pObject->vfptr);
          v25 = v24->pTraits.pObject;
          if ( !v25->pVM->HandleException )
            Scaleform::GFx::AS3::VM::ExecuteCode(v25->pVM, 1u);
          v23 = v256.pNode;
        }
        v26 = *(Scaleform::GFx::ASStringNode **)(v22[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum + 152);
        name.pNode = *(Scaleform::GFx::ASStringNode **)(v22[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum + 152);
        v270 = (Scaleform::GFx::AS3::Slots *)v23[1].pLower;
        LODWORD(v27) = 0;
        v264.pNode = 0i64;
        if ( v270 )
        {
          do
          {
            v28 = (signed int *)((char *)v26[4].pLower
                               + 16 * *((signed int *)&v23[1].pManager->vfptr + (unsigned int)v27));
            v29 = v22[1].Parent.pObject;
            if ( !LOBYTE(v29->Text.pNode) )
            {
              v29->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
              v30 = v29->pTraits.pObject;
              if ( !v30->pVM->HandleException )
                Scaleform::GFx::AS3::VM::ExecuteCode(v30->pVM, 1u);
            }
            v31 = (Scaleform::GFx::AS3::VMFile *)xmla[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum;
            v251.Kind = v28[3];
            v251.Obj.pObject = 0i64;
            v251.Name.Flags = 0;
            v251.Name.Bonus.pWeakProxy = 0i64;
            if ( v28[3] || v28[2] || *v28 )
            {
              v32 = Scaleform::GFx::AS3::VMFile::GetInternedString(v31, (Scaleform::GFx::ASString *)&v266, v28[2]);
              Scaleform::GFx::AS3::Value::Assign(&v251.Name, v32);
              v33 = (Scaleform::GFx::ASStringNode *)v266.pV;
              v11 = LODWORD(v266.pV->pPrev) == 1;
              --v33->RefCount;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v33);
              if ( (v251.Name.Flags & 0x1F) == 10 )
              {
                Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v251.Name, &n);
                if ( n.pNode->Size )
                {
                  if ( *n.pNode->pData == 64 )
                  {
                    v251.Kind |= 8u;
                    v34 = Scaleform::GFx::ASString::Substring(&n, &v265, 1, n.pNode->Size);
                    Scaleform::GFx::AS3::Value::Assign(&v251.Name, v34);
                    v35 = v265.pNode;
                    v11 = v265.pNode->RefCount == 1;
                    --v35->RefCount;
                    if ( v11 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v35);
                  }
                }
                v36 = n.pNode;
                v11 = n.pNode->RefCount == 1;
                --v36->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v36);
              }
            }
            v37 = v28[3] & 3;
            if ( v37 > 1 || v37 == 1 )
            {
              if ( v37 == 2 )
              {
                v38 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                                         v31,
                                                                         *v28);
LABEL_59:
                v39 = v251.Obj.pObject;
                v40 = (Scaleform::GFx::AS3::GASRefCountBase *)&v38->vfptr;
                if ( v38 != (Scaleform::GFx::AS3::Instances::fl::Namespace *)v251.Obj.pObject )
                {
                  if ( v38 )
                  {
                    v38->RefCount = (v38->RefCount + 1) & 0x8FBFFFFF;
                    v39 = v251.Obj.pObject;
                  }
                  if ( v39 )
                  {
                    if ( (_QWORD)v251.Obj.pObject & 1 )
                    {
                      v251.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v39 - 1);
                    }
                    else
                    {
                      v41 = v39->RefCount;
                      if ( v41 & 0x3FFFFF )
                      {
                        v39->RefCount = v41 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v39->vfptr);
                      }
                    }
                  }
                  v251.Obj.pObject = v40;
                }
                goto LABEL_68;
              }
            }
            else if ( *v28 )
            {
              v38 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v31, *v28);
              goto LABEL_59;
            }
LABEL_68:
            if ( !Scaleform::GFx::AS3::Value::Convert2String(&v251.Name, &v239, &key)->Result )
              goto LABEL_143;
            if ( v21 )
            {
              v42 = 8i64;
              v43 = 5381i64;
              do
              {
                v44 = 65599 * v43 + *((unsigned __int8 *)&key.pNode + --v42);
                v43 = 65599 * v43 + *((unsigned __int8 *)&key.pNode + v42);
              }
              while ( v42 );
              v45 = v44 & v21->SizeMask;
              v46 = v45;
              v47 = (signed __int64)v21 + 8 * (v45 + 2 * (v45 + 1));
              if ( *(_QWORD *)v47 != -2i64 && *(_QWORD *)(v47 + 8) == v45 )
              {
                while ( *(_QWORD *)(v47 + 8) != v45 || *(Scaleform::GFx::ASStringNode **)(v47 + 16) != key.pNode )
                {
                  v46 = *(_QWORD *)v47;
                  if ( *(_QWORD *)v47 == -1i64 )
                    goto LABEL_80;
                  v47 = (signed __int64)v21 + 8 * (v46 + 2 * (v46 + 1));
                }
                if ( v46 >= 0
                  && (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)v21 + 8 * (v46 + 2 * (v46 + 2))) )
                {
                  goto LABEL_143;
                }
              }
            }
LABEL_80:
            v48 = 8i64;
            v49 = 5381i64;
            do
              v49 = *((unsigned __int8 *)&key.pNode + --v48) + 65599 * v49;
            while ( v48 );
            Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
              &v249,
              pmemAddr,
              &key,
              v49);
            v50 = ns;
            Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
              v257,
              &v263,
              (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
              ns,
              &v255,
              0i64);
            value.Bonus.pWeakProxy = 0i64;
            value.Flags = 12;
            *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&value.value.VNumber = v263;
            value.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
            v51 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))p->vfptr[7].~RefCountBaseGC<328>)(
                              p,
                              &v246,
                              &value) == 0;
            v52 = value.Flags & 0x1F;
            if ( v52 > 9 )
            {
              if ( (value.Flags >> 9) & 1 )
              {
                v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v11 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                value.Bonus.pWeakProxy = 0i64;
                value.value = 0ui64;
                value.Flags &= 0xFFFFFDE0;
              }
              else
              {
                switch ( v52 )
                {
                  case 10:
                    v53 = value.value.VS._1.VStr;
                    v11 = *(_DWORD *)(*(_QWORD *)&value.value.VNumber + 24i64) == 1;
                    --v53->RefCount;
                    if ( v11 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v53);
                    break;
                  case 11:
                  case 12:
                  case 13:
                  case 14:
                  case 15:
                    v54 = value.value.VNumber;
                    if ( !value.value.VS._1.VBool )
                      goto LABEL_94;
                    --*(_QWORD *)&value.value.VNumber;
                    break;
                  case 16:
                  case 17:
                    v54 = *(double *)&value.value.VS._2.VObj;
                    if ( (_QWORD)value.value.VS._2.VObj & 1 )
                    {
                      --value.value.VS._2.VObj;
                    }
                    else
                    {
LABEL_94:
                      if ( v54 != 0.0 )
                      {
                        v55 = *(_DWORD *)(*(_QWORD *)&v54 + 32i64);
                        if ( v55 & 0x3FFFFF )
                        {
                          *(_DWORD *)(*(_QWORD *)&v54 + 32i64) = v55 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v54);
                        }
                      }
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            if ( v51 )
            {
              if ( (v251.Name.Flags & 0x1F) > 9 )
              {
                if ( (v251.Name.Flags >> 9) & 1 )
                {
                  v11 = v251.Name.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v11 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v251.Name.Bonus.pWeakProxy = 0i64;
                  v251.Name.value = 0ui64;
                  v251.Name.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v251.Name);
                }
              }
              v90 = v251.Obj.pObject;
              if ( v251.Obj.pObject )
              {
                if ( (_QWORD)v251.Obj.pObject & 1 )
                {
                  --v251.Obj.pObject;
                }
                else
                {
                  v91 = v251.Obj.pObject->RefCount;
                  if ( v91 & 0x3FFFFF )
                  {
                    v251.Obj.pObject->RefCount = v91 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v90->vfptr);
                  }
                }
              }
              goto LABEL_186;
            }
            if ( (v251.Kind & 3u) > 1 )
            {
              v57 = &v251.Obj.pObject->vfptr;
              v271.pNode = (Scaleform::GFx::ASStringNode *)v251.Obj.pObject;
              v272.pNode = (Scaleform::GFx::ASStringNode *)v251.Obj.pObject[1]._pRCC;
              v58 = 0i64;
              v243.pV = 0i64;
              if ( !v272.pNode )
                goto LABEL_139;
              while ( 1 )
              {
                v56 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(v57[5] + 8i64 * (_QWORD)v58);
                v59 = xmla;
                v60 = xmla[1].Parent.pObject;
                if ( !LOBYTE(v60->Text.pNode) )
                {
                  v60->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&xmla[1].Parent.pObject->vfptr);
                  v61 = v60->pTraits.pObject;
                  if ( !v61->pVM->HandleException )
                    Scaleform::GFx::AS3::VM::ExecuteCode(v61->pVM, 1u);
                }
                v62 = *(Scaleform::GFx::ASStringNode **)(v59[1].Parent.pObject->pTraits.pObject[1].FirstOwnSlotNum + 48);
                v259.pNode = v62;
                v63 = (Scaleform::GFx::AS3::VMAppDomain *)v62[1].pData;
                if ( !v63 )
                  goto LABEL_107;
                v64 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v63, &key, v56);
                if ( !v64 )
                  break;
LABEL_122:
                if ( *v64 )
                  goto LABEL_135;
LABEL_123:
                v70 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                        vma->GlobalObject.pObject,
                                                        &key,
                                                        v56);
                if ( v70 )
                {
                  v71 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)vma->SystemDomain.pObject;
                  v259.pNode = v70;
                  v275.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)key.pNode;
                  ++LODWORD(v275.pV->pPrev);
                  v276 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v56->vfptr;
                  if ( v56 )
                    v56->RefCount = (v56->RefCount + 1) & 0x8FBFFFFF;
                  v260.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v275;
                  v260.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v259;
                  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
                    v71 + 6,
                    v71[7].pTable,
                    &v260,
                    HIDWORD(v275.pV->pPrevRoot) & 0xFFFFFF ^ 4 * (HIDWORD(v276[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v276[1].vfptr << 60 >> 60));
                  v72 = v276;
                  if ( v276 )
                  {
                    if ( (unsigned __int8)v276 & 1 )
                    {
                      v276 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v276 - 1);
                    }
                    else
                    {
                      v73 = v276->RefCount;
                      if ( v73 & 0x3FFFFF )
                      {
                        v276->RefCount = v73 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v72);
                      }
                    }
                  }
                  v74 = (Scaleform::GFx::ASStringNode *)v275.pV;
                  v11 = LODWORD(v275.pV->pPrev) == 1;
                  --v74->RefCount;
                  if ( v11 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v74);
LABEL_135:
                  v50 = ns;
                  goto LABEL_136;
                }
                v58 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v243.pV + 1);
                v243.pV = v58;
                if ( v58 >= (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v272.pNode )
                {
                  v50 = ns;
                  goto LABEL_139;
                }
                v57 = v271.pNode;
              }
              v62 = v259.pNode;
LABEL_107:
              v65 = key.pNode;
              v289.Name = key;
              ++v289.Name.pNode->RefCount;
              v289.pNs.pObject = v56;
              if ( v56 )
                v56->RefCount = (v56->RefCount + 1) & 0x8FBFFFFF;
              v66 = v62[1].pManager;
              if ( v66
                && (v67 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v62[1].pManager,
                            &v289,
                            *(_QWORD *)&v62[1].pManager->RefCount & (v65->HashFlags & 0xFFFFFF ^ 4
                                                                                               * (v56->Uri.pNode->HashFlags & 0xFFFFFF) ^ (unsigned __int64)(unsigned int)(*((_QWORD *)v56 + 5) << 60 >> 60))),
                    v67 >= 0)
                && (v68 = (signed __int64)&(&v66->pFreeStringNodes)[5 * v67]) != 0 )
              {
                v64 = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v68 + 16);
              }
              else
              {
                v64 = 0i64;
              }
              if ( v56 )
              {
                if ( (unsigned __int8)v56 & 1 )
                {
                  v289.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v56 - 1);
                }
                else
                {
                  v69 = v56->RefCount;
                  if ( v69 & 0x3FFFFF )
                  {
                    v56->RefCount = v69 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v56->vfptr);
                  }
                }
              }
              v11 = v65->RefCount-- == 1;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v65);
              if ( !v64 )
                goto LABEL_123;
              goto LABEL_122;
            }
            v56 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v251.Obj.pObject;
LABEL_136:
            if ( !v56 )
LABEL_139:
              v56 = v50;
            v75 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(&v, v56, &key, 0);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v263.pV, v50, &result, v75);
            v76 = v.pNode;
            v11 = v.pNode->RefCount == 1;
            --v76->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v76);
            v21 = v249.pTable;
LABEL_143:
            Scaleform::GFx::AS3::Multiname::~Multiname(&v251);
            v27 = (Scaleform::GFx::ASStringNode *)((char *)v264.pNode + 1);
            v264.pNode = v27;
            v22 = xmla;
            v23 = v256.pNode;
            v26 = name.pNode;
          }
          while ( v27 < (Scaleform::GFx::ASStringNode *)v270 );
        }
      }
      else
      {
        v259.pNode = (Scaleform::GFx::ASStringNode *)v22[1].Ns.pObject;
        v243.pV = 0i64;
        if ( v259.pNode )
        {
          v77 = 0i64;
          do
          {
            if ( Scaleform::GFx::AS3::Value::Convert2String(
                   (Scaleform::GFx::AS3::Value *)((char *)&xmla[1].Parent.pObject->16 + v77),
                   &v245,
                   &key)->Result )
            {
              if ( !v21 )
                goto LABEL_159;
              v78 = 8i64;
              v79 = 5381i64;
              do
              {
                v80 = 65599 * v79 + *((unsigned __int8 *)&key.pNode + --v78);
                v79 = 65599 * v79 + *((unsigned __int8 *)&key.pNode + v78);
              }
              while ( v78 );
              v81 = v80 & v21->SizeMask;
              v82 = v81;
              v83 = (signed __int64)v21 + 8 * (v81 + 2 * (v81 + 1));
              if ( *(_QWORD *)v83 == -2i64 || *(_QWORD *)(v83 + 8) != v81 )
                goto LABEL_159;
              while ( *(_QWORD *)(v83 + 8) != v81 || *(Scaleform::GFx::ASStringNode **)(v83 + 16) != key.pNode )
              {
                v82 = *(_QWORD *)v83;
                if ( *(_QWORD *)v83 == -1i64 )
                  goto LABEL_159;
                v83 = (signed __int64)v21 + 8 * (v82 + 2 * (v82 + 1));
              }
              if ( v82 < 0
                || !(Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > >::TableType *)((char *)v21 + 8 * (v82 + 2 * (v82 + 2))) )
              {
LABEL_159:
                v84 = 8i64;
                v85 = 5381i64;
                do
                  v85 = *((unsigned __int8 *)&key.pNode + --v84) + 65599 * v85;
                while ( v84 );
                Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
                  &v249,
                  pmemAddr,
                  &key,
                  v85);
                Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                  v257,
                  &v268,
                  (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
                  ns,
                  &v255,
                  0i64);
                v248.Bonus.pWeakProxy = 0i64;
                v248.Flags = 12;
                v86 = v268.pV;
                *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v248.value.VNumber = v268;
                v248.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
                v87 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))p->vfptr[7].~RefCountBaseGC<328>)(
                                  p,
                                  &v240,
                                  &v248) == 0;
                if ( (v248.Flags & 0x1F) > 9 )
                {
                  if ( (v248.Flags >> 9) & 1 )
                  {
                    v11 = v248.Bonus.pWeakProxy->RefCount-- == 1;
                    if ( v11 )
                      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                    v248.Bonus.pWeakProxy = 0i64;
                    v248.value = 0ui64;
                    v248.Flags &= 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&v248);
                  }
                }
                if ( v87 )
                {
LABEL_186:
                  v92 = key.pNode;
                  v11 = key.pNode->RefCount == 1;
                  --v92->RefCount;
                  if ( v11 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v92);
                  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>(&v249);
                  v18 = v255.pNode;
                  goto LABEL_457;
                }
                v88 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                        &v274,
                        *(Scaleform::GFx::AS3::Instances::fl::Namespace **)((char *)&xmla[1].Parent.pObject->_pRCC + v77),
                        &key,
                        0);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v86, ns, &result, v88);
                v89 = v274.pNode;
                v11 = v274.pNode->RefCount == 1;
                --v89->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v89);
                v21 = v249.pTable;
              }
            }
            ++v243.pV;
            v77 += 48i64;
          }
          while ( v243.pV < (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v259.pNode );
          v22 = xmla;
        }
      }
      v22 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v22->Children.Data.Policy.Capacity;
      xmla = v22;
    }
    while ( v22 );
    v93 = key.pNode;
    v11 = key.pNode->RefCount == 1;
    --v93->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v93);
    Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>(&v249);
    v94 = v255.pNode;
    v11 = v255.pNode->RefCount == 1;
    --v94->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v94);
    v19 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v311;
  }
  v95 = v19->Attrs.Data.Size;
  if ( ((unsigned __int8)v95 >> 4) & 1 )
  {
    if ( ~((unsigned __int8)v95 >> 5) & 1 )
    {
      v96 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)v19);
      v97 = (Scaleform::GFx::AS3::VMFile *)&v96->vfptr;
      v256.pNode = (Scaleform::GFx::ASStringNode *)v96;
      v98 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v96->File.pObject->Methods.Info.Data.Data[SLODWORD(v19[1].Ns.pObject->pPrev)];
      v266.pV = v98;
      v99 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v98->pPrev;
      v268.pV = v99;
      if ( v99 )
      {
        v270 = (Scaleform::GFx::AS3::Slots *)((char *)v99 - (char *)v98->DynAttrs.mHash.pTable);
        Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          v258,
          &n,
          "constructor");
        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
          v257,
          &v243,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
          ns,
          &n,
          0i64);
        v248.Bonus.pWeakProxy = 0i64;
        v248.Flags = 12;
        *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v248.value.VNumber = v243;
        v248.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
        v100 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))p->vfptr[7].~RefCountBaseGC<328>)(
                           p,
                           &v240,
                           &v248) == 0;
        if ( (v248.Flags & 0x1F) > 9 )
        {
          if ( (v248.Flags >> 9) & 1 )
          {
            v11 = v248.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v248.Bonus.pWeakProxy = 0i64;
            v248.value = 0ui64;
            v248.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v248);
          }
        }
        if ( (_BYTE)v100 )
          goto LABEL_237;
        v101 = 0i64;
        v264.pNode = 0i64;
        if ( v99 )
        {
          while ( 1 )
          {
            Scaleform::GFx::AS3::Multiname::Multiname(
              &v251,
              v97,
              (Scaleform::GFx::AS3::Abc::Multiname *)v97[1].vfptr[7].~RefCountBaseGC<328>
            + *((unsigned int *)&v266.pV->pNext->vfptr + (_QWORD)v101));
            if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v251) )
            {
              v102 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                       v258,
                       &v272,
                       pattern);
              v103 = v237 | 1;
            }
            else
            {
              v104 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v251.Name, &v259);
              v102 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                       &v265,
                       (Scaleform::GFx::AS3::Instances::fl::Namespace *)v251.Obj.pObject,
                       v104,
                       0);
              v103 = v237 | 6;
            }
            v237 = v103;
            v105 = v102->pNode;
            v.pNode = v105;
            ++v105->RefCount;
            if ( v103 & 4 )
            {
              v103 &= 0xFFFFFFFB;
              v237 = v103;
              v106 = v265.pNode;
              v11 = v265.pNode->RefCount == 1;
              --v106->RefCount;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v106);
            }
            if ( v103 & 2 )
            {
              v103 &= 0xFFFFFFFD;
              v237 = v103;
              v107 = v259.pNode;
              v11 = v259.pNode->RefCount == 1;
              --v107->RefCount;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v107);
            }
            if ( v103 & 1 )
            {
              v237 = v103 & 0xFFFFFFFE;
              v108 = v272.pNode;
              v11 = v272.pNode->RefCount == 1;
              --v108->RefCount;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v108);
            }
            name.pNode = (Scaleform::GFx::ASStringNode *)((char *)v101 + 1);
            Scaleform::LongFormatter::LongFormatter(&v303, (unsigned __int64)&v101->pData + 1);
            Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
              v257,
              &v263,
              (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
              ns,
              &v282,
              0i64);
            v248.Bonus.pWeakProxy = 0i64;
            v248.Flags = 12;
            *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v248.value.VNumber = v263;
            v248.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
            v109 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))v243.pV->vfptr[7].~RefCountBaseGC<328>)(
                               v243.pV,
                               &v240,
                               &v248) == 0;
            if ( (v248.Flags & 0x1F) > 9 )
            {
              if ( (v248.Flags >> 9) & 1 )
              {
                v11 = v248.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v11 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v248.Bonus.pWeakProxy = 0i64;
                v248.value = 0ui64;
                v248.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v248);
              }
            }
            if ( v109 )
              break;
            Scaleform::LongFormatter::Convert(&v303);
            v110 = v303.ValueStr;
            v111 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vma->StringManagerRef->Builtins;
            v112 = Scaleform::LongFormatter::GetSize(&v303);
            v113 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                     v111,
                     &v271,
                     v110,
                     v112);
            v114 = v263.pV;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v263.pV, ns, &v281, v113);
            v115 = v271.pNode;
            v11 = v271.pNode->RefCount == 1;
            --v115->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v115);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v114, ns, &result, &v);
            v116 = (Scaleform::GFx::ASString *)&v280;
            if ( v264.pNode < (Scaleform::GFx::ASStringNode *)v270 )
              v116 = &v278;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v114, ns, &v277, v116);
            v303.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
            Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v303.vfptr);
            v11 = v105->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v105);
            Scaleform::GFx::AS3::Multiname::~Multiname(&v251);
            v101 = name.pNode;
            v264.pNode = name.pNode;
            v97 = (Scaleform::GFx::AS3::VMFile *)v256.pNode;
            if ( name.pNode >= (Scaleform::GFx::ASStringNode *)v268.pV )
              goto LABEL_235;
          }
          v303.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
          Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v303.vfptr);
          v11 = v105->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v105);
          Scaleform::GFx::AS3::Multiname::~Multiname(&v251);
LABEL_237:
          v18 = n.pNode;
LABEL_457:
          v11 = v18->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          goto LABEL_459;
        }
LABEL_235:
        v117 = n.pNode;
        v11 = n.pNode->RefCount == 1;
        --v117->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v117);
      }
    }
  }
  v118 = v258;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v258,
    (Scaleform::GFx::ASString *)&v243,
    "access");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    (Scaleform::GFx::ASString *)&v263,
    "accessor");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v264,
    "method");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v272,
    "declaredBy");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v271,
    "constant");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v,
    "variable");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &n,
    "returnType");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v256,
    "uri");
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v118,
    &v274,
    "name");
  v119 = vma->MHeap;
  v279.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&v249;
  v288.pNode = (Scaleform::GFx::ASStringNode *)&v249;
  v249.pTable = 0i64;
  pmemAddr = v119;
  v120 = (Scaleform::GFx::AS3::Slots *)&v311->FirstOwnSlotNum;
  v270 = (Scaleform::GFx::AS3::Slots *)&v311->FirstOwnSlotNum;
  v121 = v311->VArray.Data.Size + v311->FirstOwnSlotNum - 1;
  while ( v121 > -1 )
  {
    if ( v121 < 0 || v121 < v120->FirstOwnSlotNum )
    {
      v122 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v120->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v121);
      v254 = v122;
      v120 = v270;
    }
    else
    {
      v122 = &v120->VArray.Data.Data[(unsigned int)v121 - v120->FirstOwnSlotNum].Value;
      v254 = &v120->VArray.Data.Data[(unsigned int)v121 - v120->FirstOwnSlotNum].Value;
    }
    v123 = v122->pNs.pObject;
    if ( v123->Uri.pNode == ns->Uri.pNode && !((*((_BYTE *)ns + 40) ^ *((_BYTE *)v123 + 40)) & 0xF) )
    {
      if ( v121 < 0 || v121 < v120->FirstOwnSlotNum )
        v124 = Scaleform::GFx::AS3::Slots::GetSlotNameNode(v120->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v121);
      else
        v124 = v120->VArray.Data.Data[(unsigned int)v121 - v120->FirstOwnSlotNum].Key.pObject;
      v255.pNode = v124;
      name.pNode = v124;
      ++v124->RefCount;
      v125 = v122->pNs.pObject;
      v260.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)v124;
      ++v124->RefCount;
      v260.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)v125;
      if ( v125 )
        v125->RefCount = (v125->RefCount + 1) & 0x8FBFFFFF;
      v126 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v249,
               (Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *)&v260);
      if ( v126 )
        v127 = (signed __int64)&v126->Second;
      else
        v127 = 0i64;
      if ( v125 )
      {
        if ( (unsigned __int8)v125 & 1 )
        {
          v260.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)((char *)&v125[-1].Prefix.value.VS._2.pTraits
                                                                           + 7);
        }
        else
        {
          v128 = v125->RefCount;
          if ( v128 & 0x3FFFFF )
          {
            v125->RefCount = v128 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v125->vfptr);
          }
        }
      }
      v129 = v255.pNode;
      v11 = v255.pNode->RefCount == 1;
      --v129->RefCount;
      if ( v11 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(v129);
        v129 = v255.pNode;
      }
      if ( v127 )
      {
        v11 = v129->RefCount-- == 1;
        if ( v11 )
        {
          v130 = v129;
LABEL_395:
          Scaleform::GFx::ASStringNode::ReleaseNode(v130);
          goto LABEL_396;
        }
      }
      else
      {
        v239.Result = 1;
        v131 = v254;
        Scaleform::GFx::AS3::MultinameHash<bool,2>::Add(
          (Scaleform::GFx::AS3::MultinameHash<bool,2> *)&v249,
          &name,
          v254->pNs.pObject,
          &v239.Result);
        v132 = *(_DWORD *)v131;
        v133 = *(_DWORD *)v131 << 17 >> 27;
        LODWORD(key.pNode) = v133;
        if ( v133 <= 10 )
        {
          v198 = 1;
          if ( !(v132 & 3) )
          {
            v197 = v131->TI;
            if ( !v197 || (v197->kind & 0xF) != 6 )
              v198 = 0;
          }
          v199 = &v271;
          if ( !v198 )
            v199 = &v;
          v200 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                   v257,
                   &v275,
                   (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
                   ns,
                   v199,
                   0i64)->pV;
          v251.Obj.pObject = 0i64;
          v251.Kind = 12;
          *(_QWORD *)&v251.Name.Flags = v200;
          v251.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v260.pSecond;
          v201 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Multiname *))p->vfptr[7].~RefCountBaseGC<328>)(
                             p,
                             &v247,
                             &v251) == 0;
          if ( (v251.Kind & 0x1F) > 9 )
          {
            if ( ((unsigned int)v251.Kind >> 9) & 1 )
            {
              v11 = v251.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
              if ( v11 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v251.Obj.pObject = 0i64;
              *(_QWORD *)&v251.Name.Flags = 0i64;
              v251.Name.Bonus.pWeakProxy = 0i64;
              v251.Kind &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v251);
            }
          }
          if ( v201 )
            goto LABEL_408;
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v200, ns, &v274, &name);
          v202 = v254;
          v203 = Scaleform::GFx::AS3::SlotInfo::GetDataType(v254, vma);
          if ( v203 )
          {
            v204 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *, _QWORD))v203->vfptr[1].Finalize_GC)(
                                                 v203,
                                                 &v279,
                                                 0i64);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v200, ns, &result, v204);
            v205 = (Scaleform::GFx::ASStringNode *)v279.pV;
            v11 = LODWORD(v279.pV->pPrev) == 1;
            --v205->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v205);
          }
          v206 = (Scaleform::GFx::ASString *)v202->pNs.pObject;
          if ( v206[7].pNode->Size )
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v200, ns, &v256, v206 + 7);
          if ( v202->TI )
            Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(v308, vma, v200, v202->File.pObject);
        }
        else
        {
          v134 = &v264;
          if ( v133 != 11 )
            v134 = (Scaleform::GFx::ASString *)&v263;
          xmla = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                   v257,
                   (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v289,
                   (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
                   ns,
                   v134,
                   0i64)->pV;
          v248.Bonus.pWeakProxy = 0i64;
          v248.Flags = 12;
          *(_QWORD *)&v248.value.VNumber = xmla;
          v248.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
          v135 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))p->vfptr[7].~RefCountBaseGC<328>)(
                             p,
                             &v240,
                             &v248) == 0;
          if ( (v248.Flags & 0x1F) > 9 )
          {
            if ( (v248.Flags >> 9) & 1 )
            {
              v11 = v248.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v11 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v248.Bonus.pWeakProxy = 0i64;
              v248.value = 0ui64;
              v248.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v248);
            }
          }
          if ( (_BYTE)v135 )
            goto LABEL_408;
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v274, &name);
          v136 = v254;
          if ( (*(_DWORD *)v254 & 0x7C00) != 11264 )
          {
            v137 = 0i64;
            switch ( v133 )
            {
              case 12:
                v137 = "readonly";
                break;
              case 13:
                v137 = "writeonly";
                break;
              case 14:
                v137 = "readwrite";
                break;
            }
            Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              v258,
              &v259,
              v137);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, (Scaleform::GFx::ASString *)&v243, &v259);
            v138 = v259.pNode;
            v11 = v259.pNode->RefCount == 1;
            --v138->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v138);
          }
          v139 = (Scaleform::GFx::ASString *)v136->pNs.pObject;
          if ( v139[7].pNode->Size )
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v256, v139 + 7);
          v140 = ((signed __int64)*(_DWORD *)v136 >> 15) + (v133 == 13);
          v141 = v311;
          v142 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v311->vfptr);
          Scaleform::GFx::AS3::VTable::GetValue(v142, &value, (Scaleform::GFx::AS3::AbsoluteIndex)v140);
          LODWORD(v267) = value.Flags & 0x1F;
          v143 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *))v141->vfptr[2].~RefCountBaseGC<328>)(v141);
          if ( v143 )
            v144 = *(Scaleform::GFx::AS3::VMAppDomain **)(v143 + 48);
          else
            v144 = v141->pVM->SystemDomain.pObject;
          v145 = Scaleform::GFx::AS3::VM::GetFunctReturnType(vma, &value, v144);
          if ( Scaleform::GFx::AS3::InstanceTraits::Traits::IsOfType(
                 v145,
                 vma->TraitsClassClass.pObject->ITraits.pObject) )
          {
            v146 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                     v258,
                     &v293,
                     pattern);
            v147 = v237 | 8;
          }
          else
          {
            v146 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **, _QWORD))v145->vfptr[1].Finalize_GC)(
                                                 v145,
                                                 &v294,
                                                 0i64);
            v147 = v237 | 0x10;
          }
          v237 = v147;
          v148 = v146->pNode;
          v268.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v148;
          ++v148->RefCount;
          if ( v147 & 0x10 )
          {
            v147 &= 0xFFFFFFEF;
            v237 = v147;
            v149 = v294;
            v11 = v294->RefCount == 1;
            --v149->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v149);
          }
          if ( v147 & 8 )
          {
            v237 = v147 & 0xFFFFFFF7;
            v150 = v293.pNode;
            v11 = v293.pNode->RefCount == 1;
            --v150->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v150);
          }
          if ( (_DWORD)v267 == 7 )
          {
            v151 = Scaleform::GFx::AS3::Traits::GetVT(value.value.VS._2.pTraits);
            v152 = (signed __int64)&v151->VTMethods.Data.Data[value.value.VS._1.VUInt];
            v153 = *(signed int *)(v152 + 16);
            v284 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(v152 + 24);
            v154 = (Scaleform::GFx::AS3::VMFile *)((__int64 (*)(void))v284->Builtins[0].pNode[1].pLower)();
            v155 = v154;
            file = v154;
            v156 = (__int64)v154[1].vfptr;
            v298 = v156;
            v157 = *(_QWORD *)(v156 + 224);
            v158 = *(_QWORD *)(v157 + 8 * v153);
            v267 = *(_QWORD *)(v157 + 8 * v153);
            if ( LODWORD(key.pNode) == 13 )
            {
              Scaleform::GFx::AS3::Multiname::Multiname(
                &v305,
                v155,
                (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(v156 + 176) + 16i64 * **(unsigned int **)(v158 + 16)));
              if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v305) )
              {
                v159 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                         v258,
                         &v300,
                         pattern);
                v160 = v237 | 0x20;
              }
              else
              {
                v161 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v305.Name, &v292);
                v159 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                         &v299,
                         (Scaleform::GFx::AS3::Instances::fl::Namespace *)v305.Obj.pObject,
                         v161,
                         0);
                v160 = v237 | 0xC0;
              }
              v237 = v160;
              v162 = v159->pNode;
              ++v162->RefCount;
              v11 = v148->RefCount-- == 1;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v148);
              v148 = v162;
              v268.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v162;
              v163 = v237;
              if ( (v237 & 0x80u) != 0 )
              {
                v163 = v237 & 0xFFFFFF7F;
                v237 &= 0xFFFFFF7F;
                v164 = v299.pNode;
                v11 = v299.pNode->RefCount == 1;
                --v164->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v164);
              }
              if ( v163 & 0x40 )
              {
                v163 &= 0xFFFFFFBF;
                v237 = v163;
                v165 = v292.pNode;
                v11 = v292.pNode->RefCount == 1;
                --v165->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v165);
              }
              if ( v163 & 0x20 )
              {
                v237 = v163 & 0xFFFFFFDF;
                v166 = v300.pNode;
                v11 = v300.pNode->RefCount == 1;
                --v166->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v166);
              }
              Scaleform::GFx::AS3::Multiname::~Multiname(&v305);
            }
            v167 = v254;
            v168 = &n;
            if ( (*(_DWORD *)v254 & 0x7C00) != 11264 )
              v168 = &result;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, v168, (Scaleform::GFx::ASString *)&v268);
            v169 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *, Scaleform::GFx::ASStringNode **, _QWORD))v284->Builtins[0].pNode[1].pData)(
                                                 v284,
                                                 &v296,
                                                 0i64);
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, &v272, v169);
            v170 = v296;
            v11 = v296->RefCount == 1;
            --v170->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v170);
            if ( (*(_DWORD *)v167 & 0x7C00) == 11264 )
            {
              v285 = *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(v267 + 24);
              v297.pNode = (Scaleform::GFx::ASStringNode *)((char *)v285 - *(_QWORD *)(v267 + 48));
              v171 = 0i64;
              key.pNode = 0i64;
              if ( v285 )
              {
                while ( 1 )
                {
                  v283 = (Scaleform::GFx::ASStringNode *)((char *)v171 + 1);
                  Scaleform::LongFormatter::LongFormatter(&v306, (unsigned __int64)&v171->pData + 1);
                  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                    v257,
                    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v265,
                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
                    ns,
                    &v282,
                    0i64);
                  v287.Bonus.pWeakProxy = 0i64;
                  v287.Flags = 12;
                  *(Scaleform::GFx::ASString *)&v287.value.VNumber = v265;
                  v287.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
                  v172 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))xmla->vfptr[7].~RefCountBaseGC<328>)(
                                     xmla,
                                     &v245,
                                     &v287) == 0;
                  if ( (v287.Flags & 0x1F) > 9 )
                  {
                    if ( (v287.Flags >> 9) & 1 )
                    {
                      v11 = v287.Bonus.pWeakProxy->RefCount-- == 1;
                      if ( v11 )
                        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                      v287.Bonus.pWeakProxy = 0i64;
                      v287.value = 0ui64;
                      v287.Flags &= 0xFFFFFDE0;
                    }
                    else
                    {
                      Scaleform::GFx::AS3::Value::ReleaseInternal(&v287);
                    }
                  }
                  if ( (_BYTE)v172 )
                    break;
                  Scaleform::LongFormatter::Convert(&v306);
                  v173 = v306.ValueStr;
                  v284 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vma->StringManagerRef->Builtins;
                  v174 = Scaleform::LongFormatter::GetSize(&v306);
                  v175 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                           v284,
                           &v302,
                           v173,
                           v174);
                  v176 = v265.pNode;
                  Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                    (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v265.pNode,
                    ns,
                    &v281,
                    v175);
                  v177 = v302.pNode;
                  v11 = v302.pNode->RefCount == 1;
                  --v177->RefCount;
                  if ( v11 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v177);
                  Scaleform::GFx::AS3::Multiname::Multiname(
                    (Scaleform::GFx::AS3::Multiname *)&v303,
                    file,
                    (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(v298 + 176)
                                                          + 16i64
                                                          * *(unsigned int *)(*(_QWORD *)(v267 + 16)
                                                                            + 4i64 * (_QWORD)key.pNode)));
                  if ( Scaleform::GFx::AS3::Multiname::IsAnyType((Scaleform::GFx::AS3::Multiname *)&v303) )
                  {
                    v178 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                             v258,
                             &v291,
                             pattern);
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                      (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v176,
                      ns,
                      &result,
                      v178);
                    v179 = v291.pNode;
                  }
                  else
                  {
                    v180 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
                             (Scaleform::GFx::AS3::Value *)&v303.IsConverted,
                             &v295);
                    v181 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                             &v290,
                             (Scaleform::GFx::AS3::Instances::fl::Namespace *)v303.pParentFmt,
                             v180,
                             0);
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                      (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v176,
                      ns,
                      &result,
                      v181);
                    v182 = v290.pNode;
                    v11 = v290.pNode->RefCount == 1;
                    --v182->RefCount;
                    if ( v11 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v182);
                    v179 = v295.pNode;
                  }
                  v11 = v179->RefCount-- == 1;
                  if ( v11 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v179);
                  v183 = (Scaleform::GFx::ASString *)&v280;
                  if ( key.pNode < v297.pNode )
                    v183 = &v278;
                  Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                    (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v176,
                    ns,
                    &v277,
                    v183);
                  Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v303);
                  v306.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
                  Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v306.vfptr);
                  v171 = v283;
                  key.pNode = v283;
                  if ( v283 >= (Scaleform::GFx::ASStringNode *)v285 )
                  {
                    v167 = v254;
                    goto LABEL_341;
                  }
                }
                v306.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
                v207 = &v306;
LABEL_400:
                Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v207->vfptr);
                v11 = v148->RefCount-- == 1;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v148);
                if ( (value.Flags & 0x1F) > 9 )
                {
                  if ( (value.Flags >> 9) & 1 )
                  {
                    v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
                    if ( v11 )
                      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                    value.Bonus.pWeakProxy = 0i64;
                    value.value = 0ui64;
                    value.Flags &= 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
                  }
                }
LABEL_408:
                v208 = v255.pNode;
                v11 = v255.pNode->RefCount == 1;
                --v208->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v208);
                Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v249);
                Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v249);
                v209 = v274.pNode;
                v11 = v274.pNode->RefCount == 1;
                --v209->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v209);
                v210 = v256.pNode;
                v11 = v256.pNode->RefCount == 1;
                --v210->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v210);
                v211 = n.pNode;
                v11 = n.pNode->RefCount == 1;
                --v211->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v211);
                v212 = v.pNode;
                v11 = v.pNode->RefCount == 1;
                --v212->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v212);
                v213 = v271.pNode;
                v11 = v271.pNode->RefCount == 1;
                --v213->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v213);
                v214 = v272.pNode;
                v11 = v272.pNode->RefCount == 1;
                --v214->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v214);
                v215 = v264.pNode;
                v11 = v264.pNode->RefCount == 1;
                --v215->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v215);
                v216 = (Scaleform::GFx::ASStringNode *)v263.pV;
                v11 = LODWORD(v263.pV->pPrev) == 1;
                --v216->RefCount;
                if ( v11 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v216);
LABEL_456:
                v18 = (Scaleform::GFx::ASStringNode *)v243.pV;
                goto LABEL_457;
              }
            }
LABEL_341:
            v184 = v167->File.pObject;
            if ( v167->TI && v184 )
              Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(v308, vma, xmla, v184);
          }
          else
          {
            v185 = v254;
            v186 = &n;
            if ( (*(_DWORD *)v254 & 0x7C00) != 11264 )
              v186 = &result;
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(xmla, ns, v186, (Scaleform::GFx::ASString *)&v268);
            if ( (*(_DWORD *)v185 & 0x7C00) == 11264 )
            {
              v283 = value.value.VS._1.VStr;
              if ( (*(_QWORD *)(*(_QWORD *)&value.value.VNumber + 32i64) >> 6) & 7
                || (*(_QWORD *)(*(_QWORD *)&value.value.VNumber + 32i64) & 0x1FFE00i64) != 2096640 )
              {
                v187 = *(_QWORD *)(*(_QWORD *)&value.value.VNumber + 32i64) >> 9;
                v188 = (Scaleform::GFx::AS3::SlotInfo *)((v187 & 0xFFF) == 4095 ? (*(_QWORD *)(*(_QWORD *)&value.value.VNumber
                                                                                             + 32i64) >> 6) & 7i64 : (unsigned __int64)(v187 & 0xFFF));
                v254 = v188;
                v189 = 0;
                LODWORD(v267) = 0;
                if ( (_DWORD)v188 )
                {
                  while ( 1 )
                  {
                    LODWORD(key.pNode) = v189 + 1;
                    Scaleform::LongFormatter::LongFormatter(&v307, v189 + 1);
                    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                      v257,
                      &v266,
                      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
                      ns,
                      &v282,
                      0i64);
                    v286.Bonus.pWeakProxy = 0i64;
                    v286.Flags = 12;
                    *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v286.value.VNumber = v266;
                    v286.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v260.pSecond;
                    v190 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Value *))xmla->vfptr[7].~RefCountBaseGC<328>)(
                                       xmla,
                                       &v246,
                                       &v286) == 0;
                    if ( (v286.Flags & 0x1F) > 9 )
                    {
                      if ( (v286.Flags >> 9) & 1 )
                      {
                        v11 = v286.Bonus.pWeakProxy->RefCount-- == 1;
                        if ( v11 )
                          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                        v286.Bonus.pWeakProxy = 0i64;
                        v286.value = 0ui64;
                        v286.Flags &= 0xFFFFFDE0;
                      }
                      else
                      {
                        Scaleform::GFx::AS3::Value::ReleaseInternal(&v286);
                      }
                    }
                    if ( v190 )
                      break;
                    Scaleform::LongFormatter::Convert(&v307);
                    v191 = v307.ValueStr;
                    v285 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vma->StringManagerRef->Builtins;
                    v192 = Scaleform::LongFormatter::GetSize(&v307);
                    v193 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                             v285,
                             &v288,
                             v191,
                             v192);
                    v194 = v266.pV;
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v266.pV, ns, &v281, v193);
                    v195 = v288.pNode;
                    v11 = v288.pNode->RefCount == 1;
                    --v195->RefCount;
                    if ( v11 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v195);
                    v196 = (Scaleform::GFx::ASString *)&v280;
                    if ( (unsigned int)v267 < (unsigned __int64)((v283->Size >> 6) & 7) )
                      v196 = &v278;
                    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v194, ns, &v277, v196);
                    v307.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
                    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v307.vfptr);
                    v189 = (int)key.pNode;
                    LODWORD(v267) = key.pNode;
                    if ( LODWORD(key.pNode) >= (unsigned int)v254 )
                      goto LABEL_365;
                  }
                  v307.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
                  v207 = &v307;
                  goto LABEL_400;
                }
              }
            }
          }
LABEL_365:
          v11 = v148->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v148);
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags >> 9) & 1 )
            {
              v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v11 )
                ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              value.Bonus.pWeakProxy = 0i64;
              value.value = 0ui64;
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
        }
        v130 = v255.pNode;
        v11 = v255.pNode->RefCount == 1;
        --v130->RefCount;
        if ( v11 )
          goto LABEL_395;
      }
    }
LABEL_396:
    v120 = v270;
    if ( v121 >= 0 )
      --v121;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v249);
  v275.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&v249;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v249);
  v217 = v274.pNode;
  v11 = v274.pNode->RefCount == 1;
  --v217->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v217);
  v218 = v256.pNode;
  v11 = v256.pNode->RefCount == 1;
  --v218->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v218);
  v219 = n.pNode;
  v11 = n.pNode->RefCount == 1;
  --v219->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v219);
  v220 = v.pNode;
  v11 = v.pNode->RefCount == 1;
  --v220->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v220);
  v221 = v271.pNode;
  v11 = v271.pNode->RefCount == 1;
  --v221->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v221);
  v222 = v272.pNode;
  v11 = v272.pNode->RefCount == 1;
  --v222->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v222);
  v223 = v264.pNode;
  v11 = v264.pNode->RefCount == 1;
  --v223->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v223);
  v224 = (Scaleform::GFx::ASStringNode *)v263.pV;
  v11 = LODWORD(v263.pV->pPrev) == 1;
  --v224->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v224);
  v225 = (Scaleform::GFx::ASStringNode *)v243.pV;
  v11 = LODWORD(v243.pV->pPrev) == 1;
  --v225->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v225);
  if ( (LOBYTE(v311->Flags) >> 5) & 1 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      v258,
      (Scaleform::GFx::ASString *)&v243,
      "factory");
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
      v257,
      &v279,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v257->vfptr,
      ns,
      (Scaleform::GFx::ASString *)&v243,
      (Scaleform::GFx::AS3::Instances::fl::XML *)&p->vfptr);
    v251.Obj.pObject = 0i64;
    v251.Kind = 12;
    v226 = v279.pV;
    *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v251.Name.Flags = v279;
    v251.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v260.pSecond;
    v227 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLElement *, char *, Scaleform::GFx::AS3::Multiname *))p->vfptr[7].~RefCountBaseGC<328>)(
                       p,
                       &v247,
                       &v251) == 0;
    if ( (v251.Kind & 0x1F) > 9 )
    {
      if ( ((unsigned int)v251.Kind >> 9) & 1 )
      {
        v11 = v251.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v251.Obj.pObject = 0i64;
        *(_QWORD *)&v251.Name.Flags = 0i64;
        v251.Name.Bonus.pWeakProxy = 0i64;
        v251.Kind &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v251);
      }
    }
    if ( !v227 )
    {
      v228 = v311;
      v229 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::AS3::InstanceTraits::UserDefined **, _QWORD))v311->vfptr[1].Finalize_GC)(
                                           v311,
                                           &v311,
                                           0i64);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v226, ns, &result, v229);
      v230 = (Scaleform::GFx::ASStringNode *)v311;
      v11 = LODWORD(v311->pPrev) == 1;
      --v230->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v230);
      Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
        v308,
        vma,
        v226,
        (Scaleform::GFx::AS3::Traits *)v228->Ns.pObject);
    }
    goto LABEL_456;
  }
LABEL_459:
  v231 = v281.pNode;
  v11 = v281.pNode->RefCount == 1;
  --v231->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v231);
  v232 = v282.pNode;
  v11 = v282.pNode->RefCount == 1;
  --v232->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v232);
  v233 = v277.pNode;
  v11 = v277.pNode->RefCount == 1;
  --v233->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v233);
  v234 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v234->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v234);
  v235 = v278.pNode;
  v11 = v278.pNode->RefCount == 1;
  --v235->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v235);
  v236 = v280;
  v11 = v280->RefCount == 1;
  --v236->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v236);
}== 1;
  --v236->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v236);
}

// File Line: 775
// RVA: 0x7C3E70
void __fastcall Scaleform::GFx::AS3::XMLSupportImpl::DescribeType(Scaleform::GFx::AS3::XMLSupportImpl *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v5; // r15
  Scaleform::GFx::AS3::VM *v6; // r13
  Scaleform::GFx::AS3::StringManager *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rbx
  Scaleform::GFx::AS3::Traits *v9; // r14
  Scaleform::GFx::ASStringNode *v10; // r12
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // r13
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v12; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v14; // rbx
  unsigned int v15; // eax
  int v16; // ecx
  Scaleform::GFx::ASString *v17; // rdi
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString *v22; // rdi
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rdi
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
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp-28h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v51; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::ASString v52; // [rsp+50h] [rbp-18h]
  __int64 v53; // [rsp+58h] [rbp-10h]
  Scaleform::GFx::ASString v54; // [rsp+B0h] [rbp+48h]
  Scaleform::GFx::AS3::VM *vma; // [rsp+B8h] [rbp+50h]
  Scaleform::GFx::ASString v; // [rsp+C0h] [rbp+58h]
  Scaleform::GFx::ASString v57; // [rsp+C8h] [rbp+60h]

  vma = vm;
  v54.pNode = (Scaleform::GFx::ASStringNode *)this;
  v53 = -2i64;
  v4 = value;
  v5 = result;
  v6 = vm;
  v7 = vm->StringManagerRef;
  v8 = vm->PublicNamespace.pObject;
  ns = vm->PublicNamespace.pObject;
  v9 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, value);
  v10 = v7->Builtins[4].pNode;
  v57.pNode = v10;
  ++v10->RefCount;
  v.pNode = v7->Builtins[5].pNode;
  ++v.pNode->RefCount;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
    &resulta,
    "type");
  if ( (v4->Flags & 0x1F) == 13 )
    v11 = v6->TraitsClassClass.pObject;
  else
    v11 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v9->pParent.pObject;
  v12 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)(*((__int64 (**)(void))v54.pNode->pData + 11))();
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
    v12,
    &v51,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v12->vfptr,
    v8,
    &resulta,
    0i64);
  v13 = v5->pObject;
  v14 = v51.pV;
  if ( v51.pV != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v5->pObject )
  {
    if ( v13 )
    {
      if ( (unsigned __int8)v13 & 1 )
      {
        v5->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v13 - 1);
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
    v5->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)&v14->vfptr;
  }
  v16 = v4->Flags & 0x1F;
  if ( v16 && ((unsigned int)(v16 - 12) > 3 && v16 != 10 || *(_QWORD *)&v4->value.VNumber) )
  {
    v17 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *, _QWORD))v9->vfptr[1].Finalize_GC)(
                                        v9,
                                        &v52,
                                        0i64);
    v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            (Scaleform::GFx::ASString *)&v51,
            "name");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v18, v17);
    v19 = (Scaleform::GFx::ASStringNode *)v51.pV;
    v20 = LODWORD(v51.pV->pPrev) == 1;
    --v19->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v21 = v52.pNode;
    v20 = v52.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v11 )
    {
      v22 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *, _QWORD))v11->vfptr[1].Finalize_GC)(
                                          v11,
                                          &v51,
                                          0i64);
      v23 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
              &v52,
              "base");
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v23, v22);
      v24 = v52.pNode;
      v20 = v52.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v25 = (Scaleform::GFx::ASStringNode *)v51.pV;
      v20 = LODWORD(v51.pV->pPrev) == 1;
      --v25->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    v26 = &v57;
    if ( !((LOBYTE(v9->Flags) >> 1) & 1) )
      v26 = &v;
    v27 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v52,
            "isDynamic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v27, v26);
    v28 = v52.pNode;
    v20 = v52.pNode->RefCount == 1;
    --v28->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    v29 = &v57;
    if ( !((LOBYTE(v9->Flags) >> 6) & 1) )
      v29 = &v;
    v30 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v52,
            "isFinal");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v30, v29);
    v31 = v52.pNode;
    v20 = v52.pNode->RefCount == 1;
    --v31->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    v32 = &v57;
    if ( !((LOBYTE(v9->Flags) >> 5) & 1) )
      v32 = &v;
    v33 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v52,
            "isStatic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v33, v32);
    v34 = v52.pNode;
    v20 = v52.pNode->RefCount == 1;
    --v34->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits((Scaleform::GFx::AS3::XMLSupportImpl *)v54.pNode, vma, v14, v9);
  }
  else
  {
    if ( (unsigned int)(v16 - 12) > 3 && v16 != 10 || *(_QWORD *)&v4->value.VNumber )
    {
      v35 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::VM **, _QWORD))v9->vfptr[1].Finalize_GC)(
                                          v9,
                                          &vma,
                                          0i64);
      v36 = 2;
    }
    else
    {
      v35 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
              &v52,
              "null");
      v36 = 1;
    }
    v37 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v54,
            "name");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v37, v35);
    v38 = v54.pNode;
    v20 = v54.pNode->RefCount == 1;
    --v38->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    if ( v36 & 2 )
    {
      v36 &= 0xFDu;
      v39 = (Scaleform::GFx::ASStringNode *)vma;
      v20 = LODWORD(vma->GC.GC) == 1;
      --v39->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    }
    if ( v36 & 1 )
    {
      v40 = v52.pNode;
      v20 = v52.pNode->RefCount == 1;
      --v40->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    }
    v41 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v54,
            "isDynamic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v41, &v);
    v42 = v54.pNode;
    v20 = v54.pNode->RefCount == 1;
    --v42->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v42);
    v43 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v54,
            "isFinal");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v43, &v57);
    v44 = v54.pNode;
    v20 = v54.pNode->RefCount == 1;
    --v44->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v44);
    v45 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
            &v54,
            "isStatic");
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v14, ns, v45, &v);
    v46 = v54.pNode;
    v20 = v54.pNode->RefCount == 1;
    --v46->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  }
  v47 = resulta.pNode;
  v20 = resulta.pNode->RefCount == 1;
  --v47->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = v.pNode;
  v20 = v.pNode->RefCount == 1;
  --v48->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v20 = v10->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}
  v20 = v10->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 821
// RVA: 0x7EA2C0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetITraitsXML(Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  return this->TraitsXML.pObject->ITraits.pObject;
}

// File Line: 831
// RVA: 0x7EA2D0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::XMLSupportImpl::GetITraitsXMLList(Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  return this->TraitsXMLList.pObject->ITraits.pObject;
}

// File Line: 848
// RVA: 0x7C8DF0
void __fastcall Scaleform::GFx::AS3::VM::EnableXMLSupport(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rbx
  Scaleform::GFx::AS3::XMLSupportImpl *v2; // rax
  Scaleform::GFx::AS3::XMLSupport *v3; // rax
  Scaleform::GFx::AS3::XMLSupport *v4; // rdi
  Scaleform::GFx::AS3::XMLSupport *v5; // rcx
  unsigned int v6; // eax

  v1 = this;
  v2 = (Scaleform::GFx::AS3::XMLSupportImpl *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VM *, signed __int64))this->MHeap->vfptr->Alloc)(
                                                this,
                                                72i64);
  if ( v2 )
  {
    Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(v2, v1);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = v1->XMLSupport_.pObject;
  if ( v4 != v5 )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v1->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)v5 - 1);
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
    v1->XMLSupport_.pObject = v4;
  }
}

