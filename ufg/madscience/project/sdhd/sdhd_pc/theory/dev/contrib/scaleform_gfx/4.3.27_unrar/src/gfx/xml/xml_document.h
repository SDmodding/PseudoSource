// File Line: 34
// RVA: 0x6D2580
void __fastcall Scaleform::GFx::XML::ShadowRefBase::~ShadowRefBase(Scaleform::GFx::XML::ShadowRefBase *this)
{
  this->vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)&Scaleform::GFx::XML::ShadowRefBase::`vftable;
}

// File Line: 59
// RVA: 0x894870
void __fastcall Scaleform::GFx::XML::Attribute::Attribute(Scaleform::GFx::XML::Attribute *this, Scaleform::GFx::XML::DOMString name, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *v3; // rdi
  const char *v4; // rax
  const char *v5; // rax
  Scaleform::GFx::XML::DOMStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx

  v3 = value.pNode;
  v4 = name.pNode->pData;
  this->Name.pNode = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  ++*((_DWORD *)v4 + 6);
  v5 = value.pNode->pData;
  this->Value.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++*((_DWORD *)v5 + 6);
  this->Next = 0i64;
  v6 = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  v7 = *((_DWORD *)name.pNode->pData + 6) == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v6);
  v8 = (Scaleform::GFx::XML::DOMStringNode *)v3->pData;
  v7 = *((_DWORD *)v3->pData + 6) == 1;
  --v8->RefCount;
  if ( v7 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
}

// File Line: 81
// RVA: 0x89C3F0
void __fastcall Scaleform::GFx::XML::Prefix::Prefix(Scaleform::GFx::XML::Prefix *this, Scaleform::GFx::XML::DOMString name, Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringNode *v3; // rdi
  const char *v4; // rax
  const char *v5; // rax
  Scaleform::GFx::XML::DOMStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::XML::DOMStringNode *v8; // rcx

  v3 = value.pNode;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::Prefix,326>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::XML::Prefix::`vftable;
  v4 = name.pNode->pData;
  this->Name.pNode = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  ++*((_DWORD *)v4 + 6);
  v5 = value.pNode->pData;
  this->Value.pNode = (Scaleform::GFx::XML::DOMStringNode *)value.pNode->pData;
  ++*((_DWORD *)v5 + 6);
  v6 = (Scaleform::GFx::XML::DOMStringNode *)name.pNode->pData;
  v7 = *((_DWORD *)name.pNode->pData + 6) == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v6);
  v8 = (Scaleform::GFx::XML::DOMStringNode *)v3->pData;
  v7 = *((_DWORD *)v3->pData + 6) == 1;
  --v8->RefCount;
  if ( v7 )
    Scaleform::GFx::XML::DOMStringNode::ReleaseNode(v8);
}

