// File Line: 35
// RVA: 0x6CCD10
void __fastcall Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASString *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASString *v40; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::AS2::Value v44; // [rsp+38h] [rbp-28h] BYREF
  char v45; // [rsp+98h] [rbp+38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::Render::Text::TextFormat::TextFormat(&this->mTextFormat, penv->StringContext.pContext->pHeap);
  this->mParagraphFormat.pAllocator = 0i64;
  this->mParagraphFormat.RefCount = 1;
  this->mParagraphFormat.pTabStops = 0i64;
  *(_QWORD *)&this->mParagraphFormat.BlockIndent = 0i64;
  *(_DWORD *)&this->mParagraphFormat.RightMargin = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_TextFormat);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  v45 = 2;
  v44.T.Type = 1;
  v5 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "align");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v5,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  pNode = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "blockIndent");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v8,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v9 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "bold");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v10,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v11 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "bullet");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v12,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v13 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "color");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v14,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v15 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "font");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v16,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v17 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "indent");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v18,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v19 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "italic");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v20,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v21 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "leading");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v22,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v23 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "leftMargin");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v24,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v25 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "rightMargin");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v26,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v27 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "size");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v28,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v29 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "tabStops");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v30,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v31 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "target");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v32,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v33 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "underline");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v34,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v35 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "url");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v36,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v37 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  if ( penv->StringContext.SWFVersion >= 8u )
  {
    v45 = 2;
    v44.T.Type = 1;
    v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "kerning");
    this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      v38,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v39 = result.pNode;
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
    v45 = 2;
    v44.T.Type = 1;
    v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "letterSpacing");
    this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      v40,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v41 = result.pNode;
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v41);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
  }
  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v45 = 2;
    v44.T.Type = 1;
    v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "alpha");
    this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      v42,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v43 = result.pNode;
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
  }
}

// File Line: 66
// RVA: 0x7187B0
__int64 __fastcall Scaleform::GFx::AS2::TextFormatObject::SetMember(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::TextFormatObject *v8; // rdi
  const char *v9; // rbx
  __int64 v10; // rsi
  __int64 v11; // rcx
  char v12; // al
  const char *pData; // rdx
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  __int64 v18; // rcx
  char v19; // al
  char v20; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v23; // ebx
  __int64 v24; // rcx
  char v25; // al
  bool v26; // bl
  __int16 v27; // ax
  __int64 v28; // rcx
  char v29; // al
  bool v30; // bl
  __int64 v31; // rcx
  char v32; // al
  int v33; // ebx
  __int64 v34; // rcx
  char v35; // al
  __int64 v36; // rcx
  char v37; // al
  int v38; // ebx
  __int16 v39; // cx
  __int64 v40; // rcx
  char v41; // al
  bool v42; // bl
  __int64 v43; // rcx
  char v44; // al
  int v45; // ebx
  __int16 v46; // cx
  int v47; // ebx
  int v48; // ebx
  __int64 v49; // rcx
  char v50; // al
  int v51; // ebx
  char Type; // al
  Scaleform::GFx::AS2::Object *v53; // rax
  Scaleform::GFx::AS2::Object *v54; // r13
  __int64 v55; // rbx
  __int64 RootIndex; // r12
  double v57; // xmm0_8
  Scaleform::GFx::AS2::Value *v58; // rax
  unsigned __int8 v59; // bl
  bool v60; // bl
  __int64 v61; // rcx
  char v62; // al
  int v63; // ebx
  int v64; // ecx
  __int16 v65; // ax
  __int64 v66; // rcx
  char v67; // al
  bool v68; // bl
  __int64 v69; // rcx
  char v70; // al
  int v71; // ebx
  Scaleform::GFx::AS2::Value v73; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value vala; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+50h] BYREF

  result.pNode = name;
  v8 = this;
  Scaleform::GFx::AS2::Value::Value(&v73, val);
  v9 = *(const char **)name->pData;
  v10 = 0i64;
  v11 = 0i64;
  do
  {
    v12 = v9[v11++];
    if ( v12 != aAlign[v11 - 1] )
    {
      if ( !strcmp(*(const char **)name->pData, "blockIndent") )
      {
        if ( val->T.Type > 1u && val->T.Type != 10 )
        {
          v23 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
          if ( v73.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v73);
          v73.T.Type = 3;
          v73.NV.NumberValue = (double)v23;
          if ( v23 >= 0 )
          {
            if ( v23 > 720 )
              LOWORD(v23) = 720;
            LOWORD(v10) = v23;
          }
          v8->mTextFormat.FontSize = v10;
          WORD1(v8->mParagraphFormat.pAllocator) |= 2u;
          goto LABEL_195;
        }
        v8->mTextFormat.FontSize = 0;
        WORD1(v8->mParagraphFormat.pAllocator) &= ~2u;
      }
      else
      {
        v24 = 0i64;
        do
        {
          v25 = v9[v24++];
          if ( v25 != aBold[v24 - 1] )
          {
            v28 = 0i64;
            do
            {
              v29 = v9[v28++];
              if ( v29 != aBullet_0[v28 - 1] )
              {
                v31 = 0i64;
                do
                {
                  v32 = v9[v31++];
                  if ( v32 != aColor_0[v31 - 1] )
                  {
                    v34 = 0i64;
                    do
                    {
                      v35 = v9[v34++];
                      if ( v35 != aFont[v34 - 1] )
                      {
                        v36 = 0i64;
                        do
                        {
                          v37 = v9[v36++];
                          if ( v37 != aIndent[v36 - 1] )
                          {
                            v40 = 0i64;
                            while ( 1 )
                            {
                              v41 = v9[v40++];
                              if ( v41 != aItalic[v40 - 1] )
                                break;
                              if ( v40 == 7 )
                              {
                                if ( val->T.Type > 1u && val->T.Type != 10 )
                                {
                                  v42 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
                                  Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                  v73.T.Type = 2;
                                  v73.V.BooleanValue = v42;
                                  Scaleform::Render::Text::TextFormat::SetItalic(
                                    (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                    v42);
                                  goto LABEL_195;
                                }
                                BYTE2(v8->mTextFormat.Url.pHeap) &= ~2u;
                                v27 = -33;
                                goto LABEL_193;
                              }
                            }
                            v43 = 0i64;
                            while ( 1 )
                            {
                              v44 = v9[v43++];
                              if ( v44 != aLeading[v43 - 1] )
                                break;
                              if ( v43 == 8 )
                              {
                                if ( val->T.Type <= 1u || val->T.Type == 10 )
                                {
                                  v8->mTextFormat.PresentMask = 0;
                                  WORD1(v8->mParagraphFormat.pAllocator) &= ~8u;
                                  goto LABEL_194;
                                }
                                v45 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                                if ( v73.T.Type >= 5u )
                                  Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                v73.T.Type = 3;
                                v73.NV.NumberValue = (double)v45;
                                v46 = -720;
                                if ( v45 >= -720 )
                                {
                                  v46 = v45;
                                  if ( v45 > 720 )
                                    v46 = 720;
                                }
                                v8->mTextFormat.PresentMask = v46;
                                WORD1(v8->mParagraphFormat.pAllocator) |= 8u;
                                goto LABEL_195;
                              }
                            }
                            if ( !strcmp(v9, "leftMargin") )
                            {
                              if ( val->T.Type <= 1u || val->T.Type == 10 )
                              {
                                *(&v8->mTextFormat.PresentMask + 1) = 0;
                                WORD1(v8->mParagraphFormat.pAllocator) &= ~0x10u;
                                goto LABEL_194;
                              }
                              v47 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                              if ( v73.T.Type >= 5u )
                                Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 3;
                              v73.NV.NumberValue = (double)v47;
                              if ( v47 >= 0 )
                              {
                                if ( v47 > 720 )
                                  LOWORD(v47) = 720;
                                LOWORD(v10) = v47;
                              }
                              *(&v8->mTextFormat.PresentMask + 1) = v10;
                              WORD1(v8->mParagraphFormat.pAllocator) |= 0x10u;
                              goto LABEL_195;
                            }
                            if ( !strcmp(v9, "rightMargin") )
                            {
                              if ( val->T.Type <= 1u || val->T.Type == 10 )
                              {
                                LOWORD(v8->mParagraphFormat.pAllocator) = 0;
                                WORD1(v8->mParagraphFormat.pAllocator) &= ~0x20u;
                                goto LABEL_194;
                              }
                              v48 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                              if ( v73.T.Type >= 5u )
                                Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 3;
                              v73.NV.NumberValue = (double)v48;
                              if ( v48 >= 0 )
                              {
                                if ( v48 > 720 )
                                  LOWORD(v48) = 720;
                                LOWORD(v10) = v48;
                              }
                              LOWORD(v8->mParagraphFormat.pAllocator) = v10;
                              WORD1(v8->mParagraphFormat.pAllocator) |= 0x20u;
                              goto LABEL_195;
                            }
                            v49 = 0i64;
                            while ( 1 )
                            {
                              v50 = v9[v49++];
                              if ( v50 != aSize[v49 - 1] )
                                break;
                              if ( v49 == 5 )
                              {
                                if ( val->T.Type <= 1u || val->T.Type == 10 )
                                {
                                  LOWORD(v8->mTextFormat.Url.pHeap) = 0;
                                  v27 = -9;
                                  goto LABEL_193;
                                }
                                v51 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                                if ( v73.T.Type >= 5u )
                                  Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                v73.T.Type = 3;
                                v73.NV.NumberValue = (double)v51;
                                if ( v51 >= 0 )
                                {
                                  if ( v51 >= 128 )
                                  {
                                    LOWORD(v8->mTextFormat.Url.pHeap) = 2540;
                                    WORD2(v8->mTextFormat.Url.pHeap) |= 8u;
                                  }
                                  else
                                  {
                                    Scaleform::Render::Text::TextFormat::SetFontSize(
                                      (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                      (float)v51);
                                  }
                                }
                                goto LABEL_195;
                              }
                            }
                            if ( !strcmp(v9, "tabStops") )
                            {
                              Type = val->T.Type;
                              if ( val->T.Type <= 1u || Type == 10 )
                              {
                                Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc);
                                WORD1(v8->mParagraphFormat.pAllocator) &= ~0x40u;
                                goto LABEL_194;
                              }
                              if ( Type == 6 )
                              {
                                v53 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
                                if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v53->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v53->Scaleform::GFx::AS2::ObjectInterface) == 7 )
                                {
                                  v54 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
                                  Scaleform::Render::Text::ParagraphFormat::AllocTabStops(
                                    (Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc,
                                    v54[1].RootIndex);
                                  WORD1(v8->mParagraphFormat.pAllocator) |= 0x40u;
                                  v55 = 0i64;
                                  RootIndex = (int)v54[1].RootIndex;
                                  if ( RootIndex > 0 )
                                  {
                                    do
                                    {
                                      v57 = Scaleform::GFx::AS2::Value::ToNumber(
                                              (Scaleform::GFx::AS2::Value *)(&v54[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v55],
                                              penv);
                                      vala.T.Type = 3;
                                      vala.NV.NumberValue = (double)(int)v57;
                                      Scaleform::GFx::AS2::ArrayObject::SetElement(
                                        (Scaleform::GFx::AS2::ArrayObject *)v54,
                                        v10,
                                        &vala);
                                      if ( vala.T.Type >= 5u )
                                        Scaleform::GFx::AS2::Value::DropRefs(&vala);
                                      Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(
                                        (Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc,
                                        v10,
                                        (int)v57);
                                      LODWORD(v10) = v10 + 1;
                                      ++v55;
                                    }
                                    while ( v55 < RootIndex );
                                    v8 = this;
                                  }
                                  Scaleform::GFx::AS2::Value::Value(&vala, (Scaleform::GFx::ASStringNode *)v54);
                                  v59 = Scaleform::GFx::AS2::Object::SetMember(
                                          v8,
                                          penv,
                                          (Scaleform::GFx::ASString *)result.pNode,
                                          v58,
                                          flags);
                                  if ( vala.T.Type >= 5u )
                                    Scaleform::GFx::AS2::Value::DropRefs(&vala);
                                  goto LABEL_196;
                                }
                              }
                              goto LABEL_195;
                            }
                            if ( strcmp(v9, "underline") )
                            {
                              v61 = 0i64;
                              do
                              {
                                v62 = v9[v61++];
                                if ( v62 != aUrl[v61 - 1] )
                                {
                                  if ( penv->StringContext.SWFVersion >= 8u )
                                  {
                                    if ( !strcmp(v9, "letterSpacing") )
                                    {
                                      if ( val->T.Type <= 1u || val->T.Type == 10 )
                                      {
                                        HIDWORD(v8->mTextFormat.Url.HeapTypeBits) = 0;
                                        v65 = -3;
LABEL_178:
                                        WORD2(v8->mTextFormat.Url.pHeap) &= v65;
                                        Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                        v73.T.Type = 1;
                                      }
                                      else
                                      {
                                        v63 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                                        if ( v73.T.Type >= 5u )
                                          Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                        v73.T.Type = 3;
                                        v73.NV.NumberValue = (double)v63;
                                        v64 = -720;
                                        if ( v63 >= -720 )
                                        {
                                          v64 = v63;
                                          if ( v63 > 720 )
                                            v64 = 720;
                                        }
                                        WORD2(v8->mTextFormat.Url.pHeap) |= 2u;
                                        *((float *)&v8->mTextFormat.Url.HeapTypeBits + 1) = (float)v64 * 20.0;
                                      }
                                    }
                                    else
                                    {
                                      v66 = 0i64;
                                      while ( 1 )
                                      {
                                        v67 = v9[v66++];
                                        if ( v67 != aKerning[v66 - 1] )
                                          break;
                                        if ( v66 == 8 )
                                        {
                                          if ( val->T.Type > 1u && val->T.Type != 10 )
                                          {
                                            v68 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
                                            Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                            v73.T.Type = 2;
                                            v73.V.BooleanValue = v68;
                                            Scaleform::Render::Text::TextFormat::SetKerning(
                                              (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                              v68);
                                            break;
                                          }
                                          BYTE2(v8->mTextFormat.Url.pHeap) &= ~8u;
                                          v65 = -129;
                                          goto LABEL_178;
                                        }
                                      }
                                    }
                                  }
                                  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
                                  {
                                    v69 = 0i64;
                                    while ( 1 )
                                    {
                                      v70 = *(_BYTE *)(*(_QWORD *)name->pData + v69++);
                                      if ( v70 != aAlpha_0[v69 - 1] )
                                        break;
                                      if ( v69 == 6 )
                                      {
                                        if ( val->T.Type <= 1u || val->T.Type == 10 )
                                        {
                                          LODWORD(v8->mTextFormat.Url.pData) |= 0xFF000000;
                                          v27 = -1025;
                                          goto LABEL_193;
                                        }
                                        v71 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                                        if ( v73.T.Type >= 5u )
                                          Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                        v73.T.Type = 3;
                                        v73.NV.NumberValue = (double)v71;
                                        if ( v71 >= 0 )
                                        {
                                          if ( v71 > 100 )
                                            v71 = 100;
                                          LODWORD(v10) = v71;
                                        }
                                        LODWORD(v8->mTextFormat.Url.pData) &= 0xFFFFFFu;
                                        LODWORD(v8->mTextFormat.Url.pData) |= (unsigned __int8)(int)((double)(int)v10 * 255.0 * 0.01) << 24;
                                        WORD2(v8->mTextFormat.Url.pHeap) |= 0x400u;
                                        goto LABEL_195;
                                      }
                                    }
                                  }
                                  goto LABEL_195;
                                }
                              }
                              while ( v61 != 4 );
                              if ( val->T.Type <= 1u || val->T.Type == 10 )
                              {
                                Scaleform::String::Clear((Scaleform::String *)&v8->mTextFormat);
                                v27 = -257;
                                goto LABEL_193;
                              }
                              Scaleform::GFx::AS2::Value::ToString(val, &result, penv, -1);
                              if ( v73.T.Type >= 5u )
                                Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 5;
                              v73.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
                              ++result.pNode->RefCount;
                              Scaleform::Render::Text::TextFormat::SetUrl(
                                (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                result.pNode->pData,
                                0xFFFFFFFFFFFFFFFFui64);
                              goto LABEL_20;
                            }
                            if ( val->T.Type > 1u && val->T.Type != 10 )
                            {
                              v60 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
                              Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 2;
                              v73.V.BooleanValue = v60;
                              Scaleform::Render::Text::TextFormat::SetUnderline(
                                (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                v60);
                              goto LABEL_195;
                            }
                            BYTE2(v8->mTextFormat.Url.pHeap) &= ~4u;
                            v27 = -65;
                            goto LABEL_193;
                          }
                        }
                        while ( v36 != 7 );
                        if ( val->T.Type <= 1u || val->T.Type == 10 )
                        {
                          *(_WORD *)&v8->mTextFormat.FormatFlags = 0;
                          WORD1(v8->mParagraphFormat.pAllocator) &= ~4u;
                          goto LABEL_194;
                        }
                        v38 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                        if ( v73.T.Type >= 5u )
                          Scaleform::GFx::AS2::Value::DropRefs(&v73);
                        v73.T.Type = 3;
                        v73.NV.NumberValue = (double)v38;
                        v39 = -720;
                        if ( v38 >= -720 )
                        {
                          v39 = v38;
                          if ( v38 > 720 )
                            v39 = 720;
                        }
                        *(_WORD *)&v8->mTextFormat.FormatFlags = v39;
                        WORD1(v8->mParagraphFormat.pAllocator) |= 4u;
                        goto LABEL_195;
                      }
                    }
                    while ( v34 != 5 );
                    if ( val->T.Type <= 1u || val->T.Type == 10 )
                    {
                      v27 = -4101;
                      goto LABEL_193;
                    }
                    Scaleform::GFx::AS2::Value::ToString(val, &result, penv, -1);
                    if ( v73.T.Type >= 5u )
                      Scaleform::GFx::AS2::Value::DropRefs(&v73);
                    v73.T.Type = 5;
                    v73.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
                    ++result.pNode->RefCount;
                    Scaleform::Render::Text::TextFormat::SetFontList(
                      (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                      result.pNode->pData,
                      0xFFFFFFFFFFFFFFFFui64);
                    goto LABEL_20;
                  }
                }
                while ( v31 != 6 );
                if ( val->T.Type <= 1u || val->T.Type == 10 )
                {
                  LODWORD(v8->mTextFormat.Url.pData) = -16777216;
                  v27 = -2;
                  goto LABEL_193;
                }
                v33 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
                if ( v73.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v73);
                v73.T.Type = 3;
                v73.NV.NumberValue = (double)v33;
                LODWORD(v8->mTextFormat.Url.pData) &= 0xFF000000;
                LODWORD(v8->mTextFormat.Url.pData) |= v33 & 0xFFFFFF;
                WORD2(v8->mTextFormat.Url.pHeap) |= 1u;
                goto LABEL_195;
              }
            }
            while ( v28 != 7 );
            if ( val->T.Type <= 1u || val->T.Type == 10 )
            {
              WORD1(v8->mParagraphFormat.pAllocator) &= 0x7F7Fu;
              goto LABEL_194;
            }
            v30 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
            Scaleform::GFx::AS2::Value::DropRefs(&v73);
            v73.T.Type = 2;
            v73.V.BooleanValue = v30;
            if ( v30 )
              WORD1(v8->mParagraphFormat.pAllocator) |= 0x8000u;
            else
              WORD1(v8->mParagraphFormat.pAllocator) &= ~0x8000u;
            WORD1(v8->mParagraphFormat.pAllocator) |= 0x80u;
            goto LABEL_195;
          }
        }
        while ( v24 != 5 );
        if ( val->T.Type > 1u && val->T.Type != 10 )
        {
          v26 = Scaleform::GFx::AS2::Value::ToBool(val, penv);
          Scaleform::GFx::AS2::Value::DropRefs(&v73);
          v73.T.Type = 2;
          v73.V.BooleanValue = v26;
          Scaleform::Render::Text::TextFormat::SetBold(
            (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
            v26);
          goto LABEL_195;
        }
        BYTE2(v8->mTextFormat.Url.pHeap) &= ~1u;
        v27 = -17;
LABEL_193:
        WORD2(v8->mTextFormat.Url.pHeap) &= v27;
      }
LABEL_194:
      Scaleform::GFx::AS2::Value::DropRefs(&v73);
      v73.T.Type = 1;
      goto LABEL_195;
    }
  }
  while ( v11 != 6 );
  Scaleform::GFx::AS2::Value::ToString(val, &result, penv, -1);
  pData = result.pNode->pData;
  v14 = 0i64;
  while ( 1 )
  {
    v15 = pData[v14++];
    if ( v15 != aLeft_0[v14 - 1] )
      break;
    if ( v14 == 5 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) &= 0xF9FFu;
      WORD1(v8->mParagraphFormat.pAllocator) |= 1u;
      goto LABEL_20;
    }
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = pData[v16++];
    if ( v17 != aRight_0[v16 - 1] )
      break;
    if ( v16 == 6 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) &= ~0x400u;
      WORD1(v8->mParagraphFormat.pAllocator) |= 0x201u;
      goto LABEL_20;
    }
  }
  v18 = 0i64;
  while ( 1 )
  {
    v19 = pData[v18++];
    if ( v19 != aCenter_0[v18 - 1] )
      break;
    if ( v18 == 7 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) |= 0x601u;
      goto LABEL_20;
    }
  }
  while ( 1 )
  {
    v20 = pData[v10++];
    if ( v20 != aJustify[v10 - 1] )
      break;
    if ( v10 == 8 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) &= ~0x200u;
      WORD1(v8->mParagraphFormat.pAllocator) |= 0x401u;
      goto LABEL_20;
    }
  }
  WORD1(v8->mParagraphFormat.pAllocator) &= 0xF9FEu;
  Scaleform::GFx::AS2::Value::DropRefs(&v73);
  v73.T.Type = 1;
LABEL_20:
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_195:
  v59 = Scaleform::GFx::AS2::Object::SetMember(v8, penv, (Scaleform::GFx::ASString *)name, &v73, flags);
LABEL_196:
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  return v59;
}

// File Line: 376
// RVA: 0x71C910
void __fastcall Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::Render::Text::TextFormat *textFmt)
{
  bool v6; // al
  Scaleform::GFx::AS2::Value *v7; // r14
  int v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // r15
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  bool v14; // al
  Scaleform::GFx::AS2::Value *v15; // r14
  int v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // al
  Scaleform::GFx::AS2::Value *v21; // r14
  int v22; // ebx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  float FontSize; // xmm0_4
  Scaleform::GFx::AS2::Value *v27; // r14
  int v28; // ebx
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::StringDH *FontList; // rax
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::AS2::Value *v34; // r14
  int v35; // ebx
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  unsigned int ColorV; // eax
  Scaleform::GFx::AS2::Value *v41; // r14
  int v42; // ebx
  Scaleform::GFx::AS2::Value *v43; // rax
  Scaleform::GFx::ASString *v44; // rax
  Scaleform::GFx::ASStringNode *v45; // rcx
  float LetterSpacing; // xmm0_4
  Scaleform::GFx::AS2::Value *v47; // r14
  int v48; // ebx
  Scaleform::GFx::AS2::Value *v49; // rax
  Scaleform::GFx::ASString *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rcx
  bool v52; // al
  Scaleform::GFx::AS2::Value *v53; // r14
  int v54; // ebx
  Scaleform::GFx::AS2::Value *v55; // rax
  Scaleform::GFx::ASString *v56; // rax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::ASString *v58; // rax
  Scaleform::GFx::AS2::Value *v59; // r14
  int v60; // ebx
  Scaleform::GFx::AS2::Value *v61; // rax
  Scaleform::GFx::ASString *v62; // rax
  Scaleform::GFx::ASStringNode *v63; // rcx
  Scaleform::GFx::ASStringNode *v64; // rcx
  Scaleform::GFx::AS2::Value *v65; // rdi
  int v66; // ebx
  Scaleform::GFx::AS2::Value *v67; // rax
  Scaleform::GFx::ASString *v68; // rax
  Scaleform::GFx::ASStringNode *v69; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+40h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v71; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::GFx::AS2::Value v72; // [rsp+80h] [rbp+7h] BYREF
  char v73; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString v75; // [rsp+F0h] [rbp+77h] BYREF

  Scaleform::Render::Text::TextFormat::operator=(&this->mTextFormat, textFmt);
  v.T.Type = 1;
  if ( (textFmt->PresentMask & 0x10) != 0 )
  {
    v6 = textFmt->FormatFlags & 1;
    v71.T.Type = 2;
    v71.V.BooleanValue = v6;
    v7 = &v71;
    v8 = 1;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v7 = v9;
    v8 = 2;
  }
  v10 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "bold");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v11, v7, (Scaleform::GFx::AS2::PropFlags *)&v73);
  pNode = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v8 & 1) != 0 )
  {
    v8 &= ~1u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 0x20) != 0 )
  {
    v14 = (textFmt->FormatFlags & 2) != 0;
    v71.T.Type = 2;
    v71.V.BooleanValue = v14;
    v15 = &v71;
    v16 = v8 | 4;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v15 = v17;
    v16 = v8 | 8;
  }
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "italic");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v18, v15, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v19 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( (v16 & 8) != 0 )
  {
    v16 &= ~8u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v16 & 4) != 0 )
  {
    v16 &= ~4u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 0x40) != 0 )
  {
    v20 = (textFmt->FormatFlags & 4) != 0;
    v71.T.Type = 2;
    v71.V.BooleanValue = v20;
    v21 = &v71;
    v22 = v16 | 0x10;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v21 = v23;
    v22 = v16 | 0x20;
  }
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "underline");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v24, v21, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v25 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( (v22 & 0x20) != 0 )
  {
    v22 &= ~0x20u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v22 & 0x10) != 0 )
  {
    v22 &= ~0x10u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 8) != 0 )
  {
    FontSize = (float)textFmt->FontSize;
    v71.T.Type = 3;
    v71.NV.NumberValue = (float)(FontSize * 0.050000001);
    v27 = &v71;
    v28 = v22 | 0x40;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v27 = v29;
    v28 = v22 | 0x80;
  }
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "size");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v30, v27, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v31 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( (v28 & 0x80u) != 0 )
  {
    v28 &= ~0x80u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v28 & 0x40) != 0 )
  {
    v28 &= ~0x40u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 4) != 0 )
  {
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(textFmt);
    v33 = Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &v75, FontList);
    v71.T.Type = 5;
    v71.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v33->pNode;
    ++v71.V.pStringNode->RefCount;
    v34 = &v71;
    v35 = v28 | 0x300;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v34 = v36;
    v35 = v28 | 0x400;
  }
  v37 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "font");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v37, v34, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v38 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( (v35 & 0x400) != 0 )
  {
    v35 &= ~0x400u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v35 & 0x200) != 0 )
  {
    v35 &= ~0x200u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (v35 & 0x100) != 0 )
  {
    v35 &= ~0x100u;
    v39 = v75.pNode;
    v13 = v75.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  }
  if ( (textFmt->PresentMask & 1) != 0 )
  {
    ColorV = textFmt->ColorV;
    v71.T.Type = 3;
    v71.NV.NumberValue = (double)(ColorV & 0xFFFFFF);
    v41 = &v71;
    v42 = v35 | 0x800;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v41 = v43;
    v42 = v35 | 0x1000;
  }
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "color");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v44, v41, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v45 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( (v42 & 0x1000) != 0 )
  {
    v42 &= ~0x1000u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v42 & 0x800) != 0 )
  {
    v42 &= ~0x800u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 2) != 0 )
  {
    LetterSpacing = textFmt->LetterSpacing;
    v71.T.Type = 3;
    v71.NV.NumberValue = (float)(LetterSpacing * 0.050000001);
    v47 = &v71;
    v48 = v42 | 0x2000;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v47 = v49;
    v48 = v42 | 0x4000;
  }
  v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "letterSpacing");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v50, v47, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v51 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( (v48 & 0x4000) != 0 )
  {
    v48 &= ~0x4000u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v48 & 0x2000) != 0 )
  {
    v48 &= ~0x2000u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( SLOBYTE(textFmt->PresentMask) >= 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v53 = v55;
    v54 = v48 | 0x10000;
  }
  else
  {
    v52 = (textFmt->FormatFlags & 8) != 0;
    v71.T.Type = 2;
    v71.V.BooleanValue = v52;
    v53 = &v71;
    v54 = v48 | 0x8000;
  }
  v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "kerning");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v56, v53, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v57 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( (v54 & 0x10000) != 0 )
  {
    v54 &= ~0x10000u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v54 & 0x8000) != 0 )
  {
    v54 &= ~0x8000u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (textFmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&textFmt->Url) )
  {
    v58 = Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &v75, &textFmt->Url);
    v71.T.Type = 5;
    v71.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v58->pNode;
    ++v71.V.pStringNode->RefCount;
    v59 = &v71;
    v60 = v54 | 0x60000;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v);
    v59 = v61;
    v60 = v54 | 0x80000;
  }
  v62 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "url");
  v73 = 0;
  v10->vfptr->SetMemberRaw(v10, psc, v62, v59, (Scaleform::GFx::AS2::PropFlags *)&v73);
  v63 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  if ( (v60 & 0x80000) != 0 )
  {
    v60 &= ~0x80000u;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( (v60 & 0x40000) != 0 )
  {
    v60 &= ~0x40000u;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (v60 & 0x20000) != 0 )
  {
    v60 &= ~0x20000u;
    v64 = v75.pNode;
    v13 = v75.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  }
  if ( psc->pContext->GFxExtensions.Value == 1 )
  {
    if ( (textFmt->PresentMask & 1) != 0 )
    {
      v71.T.Type = 3;
      v71.NV.NumberValue = (double)HIBYTE(textFmt->ColorV) * 100.0 * 0.00392156862745098;
      v65 = &v71;
      v66 = v60 | 0x100000;
    }
    else
    {
      Scaleform::GFx::AS2::Value::Value(&v72, &v);
      v65 = v67;
      v66 = v60 | 0x200000;
    }
    v68 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "alpha");
    v73 = 0;
    v10->vfptr->SetMemberRaw(v10, psc, v68, v65, (Scaleform::GFx::AS2::PropFlags *)&v73);
    v69 = result.pNode;
    v13 = result.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v69);
    if ( (v66 & 0x200000) != 0 )
    {
      v66 &= ~0x200000u;
      if ( v72.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v72);
    }
    if ( (v66 & 0x100000) != 0 && v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}

// File Line: 395
// RVA: 0x71A2E0
void __fastcall Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  unsigned int v6; // edi
  const char *v7; // r8
  Scaleform::GFx::AS2::ObjectInterface *v8; // r15
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  unsigned __int16 PresentMask; // cx
  Scaleform::GFx::AS2::Value *p_val; // r12
  __int16 v16; // bx
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  int BlockIndent; // eax
  Scaleform::GFx::AS2::Value *v21; // r12
  __int16 v22; // bx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  int Indent; // eax
  Scaleform::GFx::AS2::Value *v27; // r12
  __int16 v28; // bx
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  int Leading; // eax
  Scaleform::GFx::AS2::Value *v33; // r12
  __int16 v34; // bx
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  int LeftMargin; // eax
  Scaleform::GFx::AS2::Value *v39; // r12
  __int16 v40; // bx
  Scaleform::GFx::AS2::Value *v41; // rax
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  int RightMargin; // eax
  Scaleform::GFx::AS2::Value *v45; // r12
  __int16 v46; // bx
  Scaleform::GFx::AS2::Value *v47; // rax
  Scaleform::GFx::ASString *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  const unsigned int *TabStops; // rbx
  Scaleform::MemoryHeap *v51; // rcx
  Scaleform::GFx::ASStringNode *v52; // rax
  Scaleform::GFx::AS2::ArrayObject *v53; // rax
  Scaleform::GFx::AS2::ArrayObject *v54; // rsi
  long double v55; // xmm0_8
  Scaleform::GFx::AS2::Value *v56; // rax
  Scaleform::GFx::AS2::Value *v57; // rbx
  Scaleform::GFx::ASString *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v61; // rax
  Scaleform::GFx::ASStringNode *v62; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::Value v64; // [rsp+58h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+78h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v66; // [rsp+98h] [rbp+Fh]
  __int64 v67; // [rsp+A0h] [rbp+17h]
  Scaleform::MemoryHeap *pHeap; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v69; // [rsp+100h] [rbp+77h] BYREF
  Scaleform::GFx::ASString result; // [rsp+108h] [rbp+7Fh] BYREF

  v67 = -2i64;
  v6 = 0;
  Scaleform::Render::Text::ParagraphFormat::operator=(&this->mParagraphFormat, paraFmt);
  v.T.Type = 1;
  if ( (paraFmt->PresentMask & 1) != 0 )
  {
    v7 = "left";
    switch ( (paraFmt->PresentMask >> 9) & 3 )
    {
      case 1:
        v7 = "right";
        break;
      case 2:
        v7 = "justify";
        break;
      case 3:
        v7 = "center";
        break;
    }
    val.T.Type = 5;
    val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &result, v7)->pNode;
    ++val.V.pStringNode->RefCount;
    v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "align");
    LOBYTE(pHeap) = 0;
    v8->vfptr->SetMemberRaw(v8, psc, v9, &val, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    pNode = v69.pNode;
    v11 = v69.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    v12 = result.pNode;
  }
  else
  {
    v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
    v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "align");
    LOBYTE(pHeap) = 0;
    v8->vfptr->SetMemberRaw(v8, psc, v13, &v, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v12 = v69.pNode;
  }
  v11 = v12->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  PresentMask = paraFmt->PresentMask;
  if ( (PresentMask & 0x80u) == 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    p_val = v17;
    v16 = 2;
  }
  else
  {
    val.T.Type = 2;
    val.V.BooleanValue = PresentMask >> 15;
    p_val = &val;
    v16 = 1;
  }
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "bullet");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v18, p_val, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v19 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( (v16 & 2) != 0 )
  {
    v16 &= ~2u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v16 & 1) != 0 )
  {
    v16 &= ~1u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (paraFmt->PresentMask & 2) != 0 )
  {
    BlockIndent = paraFmt->BlockIndent;
    val.T.Type = 3;
    val.NV.NumberValue = (double)BlockIndent;
    v21 = &val;
    v22 = v16 | 4;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    v21 = v23;
    v22 = v16 | 8;
  }
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "blockIndent");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v24, v21, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v25 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( (v22 & 8) != 0 )
  {
    v22 &= ~8u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v22 & 4) != 0 )
  {
    v22 &= ~4u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (paraFmt->PresentMask & 4) != 0 )
  {
    Indent = paraFmt->Indent;
    val.T.Type = 3;
    val.NV.NumberValue = (double)Indent;
    v27 = &val;
    v28 = v22 | 0x10;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    v27 = v29;
    v28 = v22 | 0x20;
  }
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "indent");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v30, v27, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v31 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( (v28 & 0x20) != 0 )
  {
    v28 &= ~0x20u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v28 & 0x10) != 0 )
  {
    v28 &= ~0x10u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (paraFmt->PresentMask & 8) != 0 )
  {
    Leading = paraFmt->Leading;
    val.T.Type = 3;
    val.NV.NumberValue = (double)Leading;
    v33 = &val;
    v34 = v28 | 0x40;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    v33 = v35;
    v34 = v28 | 0x80;
  }
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "leading");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v36, v33, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v37 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( (v34 & 0x80u) != 0 )
  {
    v34 &= ~0x80u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v34 & 0x40) != 0 )
  {
    v34 &= ~0x40u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (paraFmt->PresentMask & 0x10) != 0 )
  {
    LeftMargin = paraFmt->LeftMargin;
    val.T.Type = 3;
    val.NV.NumberValue = (double)LeftMargin;
    v39 = &val;
    v40 = v34 | 0x100;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    v39 = v41;
    v40 = v34 | 0x200;
  }
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "leftMargin");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v42, v39, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v43 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( (v40 & 0x200) != 0 )
  {
    v40 &= ~0x200u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v40 & 0x100) != 0 )
  {
    v40 &= ~0x100u;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (paraFmt->PresentMask & 0x20) != 0 )
  {
    RightMargin = paraFmt->RightMargin;
    val.T.Type = 3;
    val.NV.NumberValue = (double)RightMargin;
    v45 = &val;
    v46 = v40 | 0x400;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v);
    v45 = v47;
    v46 = v40 | 0x800;
  }
  v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "rightMargin");
  LOBYTE(pHeap) = 0;
  v8->vfptr->SetMemberRaw(v8, psc, v48, v45, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
  v49 = v69.pNode;
  v11 = v69.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( (v46 & 0x800) != 0 )
  {
    v46 &= ~0x800u;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( (v46 & 0x400) != 0 && val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( (paraFmt->PresentMask & 0x40) != 0 )
  {
    LODWORD(v69.pNode) = 0;
    TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(paraFmt, (unsigned int *)&v69);
    pHeap = psc->pContext->pHeap;
    v52 = (Scaleform::GFx::ASStringNode *)pHeap->vfptr->Alloc(v51, 144ui64, 0i64);
    result.pNode = v52;
    if ( v52 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v52, psc);
      v54 = v53;
    }
    else
    {
      v54 = 0i64;
    }
    v66 = v54;
    Scaleform::GFx::AS2::ArrayObject::Resize(v54, (int)v69.pNode);
    if ( LODWORD(v69.pNode) )
    {
      do
      {
        v55 = (double)(int)TabStops[v6];
        val.T.Type = 3;
        val.NV.NumberValue = v55;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v54, v6, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        ++v6;
      }
      while ( v6 < LODWORD(v69.pNode) );
    }
    Scaleform::GFx::AS2::Value::Value(&v64, (Scaleform::GFx::ASStringNode *)v54);
    v57 = v56;
    v58 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "tabStops");
    LOBYTE(pHeap) = 0;
    v8->vfptr->SetMemberRaw(v8, psc, v58, v57, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v59 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v59);
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
    if ( v54 )
    {
      RefCount = v54->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v54->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v54);
      }
    }
  }
  else
  {
    v61 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &v69, "tabStops");
    LOBYTE(pHeap) = 0;
    v8->vfptr->SetMemberRaw(v8, psc, v61, &v, (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v62 = v69.pNode;
    v11 = v69.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v62);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}

// File Line: 449
// RVA: 0x6A8600
void __fastcall Scaleform::GFx::AS2::TextFormatProto::GetTextExtent(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  __int64 v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // r12
  Scaleform::GFx::InteractiveObject *Target; // r15
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // r13
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v13; // r10
  Scaleform::MemoryHeap *v14; // rcx
  Scaleform::Render::Text::DocView *v15; // r14
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::Render::Text::FontManagerBase *v17; // rdi
  Scaleform::Render::Text::Allocator *TextAllocator; // rax
  Scaleform::Render::Text::DocView *v19; // rax
  Scaleform::Render::Text::DocView *v20; // r14
  Scaleform::GFx::AS2::Environment *v21; // rbx
  Scaleform::GFx::AS2::Value *v22; // rax
  double v23; // xmm6_8
  float v24; // xmm1_4
  Scaleform::Render::Text::TextFormat *v25; // rax
  Scaleform::Render::Text::ParagraphFormat *v26; // rax
  float TextWidth; // xmm0_4
  float TextHeight; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  char v31; // di
  char v32; // bl
  Scaleform::StringDH *FontList; // rax
  __int64 v34; // r9
  __int64 v35; // rax
  Scaleform::Render::RenderBuffer *v36; // rbx
  double v37; // xmm2_8
  __int64 v38; // rcx
  double v39; // xmm3_8
  double v40; // xmm1_8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value rect; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::Text::TextFormat v46; // [rsp+78h] [rbp-88h] BYREF
  __int64 v47; // [rsp+C8h] [rbp-38h]
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+180h] [rbp+80h] BYREF
  Scaleform::GFx::InteractiveObject *v50; // [rsp+188h] [rbp+88h]
  Scaleform::MemoryHeap *pHeap; // [rsp+190h] [rbp+90h]
  Scaleform::MemoryHeap *v52; // [rsp+198h] [rbp+98h]

  v47 = -2i64;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 30 )
    {
      v5 = fn->ThisPtr;
      v6 = v5 - 2;
      if ( !v5 )
        v6 = 0i64;
      Target = fn->Env->Target;
      if ( Target )
        ++Target->RefCount;
      v50 = Target;
      if ( Target )
      {
        pHeap = fn->Env->StringContext.pContext->pHeap;
        v8 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v4, 96i64);
        v52 = (Scaleform::MemoryHeap *)v8;
        if ( v8 )
        {
          Scaleform::GFx::AS2::Object::Object(v8, fn->Env);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        pHeap = (Scaleform::MemoryHeap *)v10;
        FirstArgBottomIndex = fn->FirstArgBottomIndex;
        Env = fn->Env;
        v13 = 0i64;
        if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                  + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v13 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v13, &result, Env, -1);
        v52 = fn->Env->StringContext.pContext->pHeap;
        v15 = (Scaleform::Render::Text::DocView *)v52->vfptr->Alloc(v14, 352ui64, 0i64);
        *(_QWORD *)&rect.T.Type = v15;
        if ( v15 )
        {
          pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
          v17 = (Scaleform::Render::Text::FontManagerBase *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[67].__vecDelDtor)(Target);
          TextAllocator = Scaleform::GFx::MovieImpl::GetTextAllocator(pMovieImpl);
          Scaleform::Render::Text::DocView::DocView(v15, TextAllocator, v17, 0i64);
          v20 = v19;
        }
        else
        {
          v20 = 0i64;
        }
        v52 = (Scaleform::MemoryHeap *)v20;
        v20->pDocument.pObject->RTFlags |= 2u;
        Scaleform::Render::Text::DocView::SetAutoSizeX(v20);
        Scaleform::Render::Text::DocView::SetAutoSizeY(v20);
        v21 = fn->Env;
        if ( v21->StringContext.SWFVersion >= 7u && fn->NArgs >= 2 )
        {
          v22 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v23 = Scaleform::GFx::AS2::Value::ToNumber(v22, v21);
          v20->Flags &= ~1u;
          Scaleform::Render::Text::DocView::SetWordWrap(v20);
          v24 = v23;
          *(_QWORD *)&rect.T.Type = 0i64;
          *(float *)&rect.NV.Int32Value = v24 * 20.0;
          HIDWORD(rect.NV.NumberValue) = 0;
          Scaleform::Render::Text::DocView::SetViewRect(v20, (Scaleform::Render::Rect<float> *)&rect, UseExternally);
        }
        v20->Flags |= 4u;
        Scaleform::Render::Text::TextFormat::TextFormat(&defaultTextFmt, fn->Env->StringContext.pContext->pHeap);
        defaultParagraphFmt.pAllocator = 0i64;
        defaultParagraphFmt.RefCount = 1;
        memset(&defaultParagraphFmt.pTabStops, 0, 20);
        Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
        Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&defaultParagraphFmt);
        v25 = Scaleform::Render::Text::TextFormat::Merge(
                &defaultTextFmt,
                &v46,
                (Scaleform::Render::Text::TextFormat *)&v6[6]);
        Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v25);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v46);
        v26 = Scaleform::Render::Text::ParagraphFormat::Merge(
                &defaultParagraphFmt,
                (Scaleform::Render::Text::ParagraphFormat *)&v46,
                (Scaleform::Render::Text::ParagraphFormat *)&v6[11]);
        Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, v26);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v46);
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v20->pDocument.pObject, &defaultTextFmt);
        Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(v20->pDocument.pObject, &defaultParagraphFmt);
        Scaleform::Render::Text::DocView::SetText(v20, result.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
        Scaleform::Render::Text::DocView::Format(v20);
        TextWidth = Scaleform::Render::Text::DocView::GetTextWidth(v20);
        rect.T.Type = 3;
        rect.NV.NumberValue = (TextWidth + 80.0) * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "textFieldWidth",
          &rect);
        if ( rect.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&rect);
        TextHeight = Scaleform::Render::Text::DocView::GetTextHeight(v20);
        rect.T.Type = 3;
        rect.NV.NumberValue = (TextHeight + 80.0) * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "textFieldHeight",
          &rect);
        if ( rect.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&rect);
        v29 = Scaleform::Render::Text::DocView::GetTextWidth(v20);
        rect.T.Type = 3;
        rect.NV.NumberValue = v29 * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "width",
          &rect);
        if ( rect.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&rect);
        v30 = Scaleform::Render::Text::DocView::GetTextHeight(v20);
        rect.T.Type = 3;
        rect.NV.NumberValue = v30 * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "height",
          &rect);
        if ( rect.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&rect);
        v31 = (unsigned __int8)defaultTextFmt.FormatFlags >> 1;
        v32 = defaultTextFmt.FormatFlags & 1;
        FontList = Scaleform::Render::Text::TextFormat::GetFontList(&defaultTextFmt);
        LOBYTE(v34) = 1;
        v35 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, _QWORD))v20->pFontManager.pObject->vfptr[1].__vecDelDtor)(
                v20->pFontManager.pObject,
                (FontList->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                ((v31 & 1) != 0) | (v32 != 0 ? 2 : 0) | 0x10u,
                v34,
                0i64);
        v36 = (Scaleform::Render::RenderBuffer *)v35;
        *(_QWORD *)&rect.T.Type = v35;
        v37 = 0.0;
        if ( !v35 || (v38 = *(_QWORD *)(v35 + 48), v39 = *(float *)(v38 + 16), v37 = *(float *)(v38 + 20), v39 == 0.0) )
          v39 = DOUBLE_960_0;
        if ( v37 == 0.0 )
          v37 = 1024.0 - v39;
        v40 = (float)((float)defaultTextFmt.FontSize * 0.050000001) * 20.0 * 0.0009765625;
        LOBYTE(v46.pAllocator) = 3;
        *(double *)&v46.RefCount = (double)(int)(v40 * v39 * 0.05);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "ascent",
          (Scaleform::GFx::AS2::Value *)&v46);
        if ( LOBYTE(v46.pAllocator) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v46);
        LOBYTE(v46.pAllocator) = 3;
        *(double *)&v46.RefCount = (double)(int)(v40 * v37 * 0.05);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v10->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "descent",
          (Scaleform::GFx::AS2::Value *)&v46);
        if ( LOBYTE(v46.pAllocator) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v46);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v10);
        if ( v36 )
          Scaleform::RefCountImpl::Release(v36);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&defaultParagraphFmt);
        Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v20);
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v10 )
        {
          RefCount = v10->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v10->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
          }
        }
      }
      if ( Target )
        Scaleform::RefCountNTSImpl::Release(Target);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "TextFormat");
    }
  }
}

// File Line: 535
// RVA: 0x6FA320
void __fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  __int64 v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r12
  Scaleform::GFx::ASString *v9; // r11
  unsigned int FirstArgBottomIndex; // r8d
  Scaleform::GFx::AS2::Environment *Env; // r10
  __int64 v12; // r9
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::ASString *v15; // r11
  unsigned int v16; // r8d
  Scaleform::GFx::AS2::Environment *v17; // r10
  __int64 v18; // r9
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString *v20; // r11
  unsigned int v21; // r8d
  Scaleform::GFx::AS2::Environment *v22; // r10
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v29; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *v32; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v33; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v37; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASString *v40; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v41; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASString *v44; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v45; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASString *v48; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v49; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASString *v52; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v53; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v54; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASString *v56; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v57; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASString *v60; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v61; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v62; // rax
  Scaleform::GFx::ASStringNode *v63; // rcx
  unsigned int RefCount; // eax
  Scaleform::MemoryHeap *pHeap; // [rsp+80h] [rbp+40h] BYREF
  Scaleform::GFx::AS2::Object *v66; // [rsp+88h] [rbp+48h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+50h] BYREF

  v2 = 0i64;
  v66 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 30
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::Object *)&v4[-2];
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::ASStringNode *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)ThisPtr, 216ui64, 0i64);
    result.pNode = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject((Scaleform::GFx::AS2::TextFormatObject *)v6, fn->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v66 = v5;
  if ( fn->NArgs >= 1 )
  {
    p_StringContext = &fn->Env->StringContext;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "font");
    LOBYTE(pHeap) = 0;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v12 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v12 = (__int64)&Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      Env,
      v9,
      (Scaleform::GFx::AS2::Value *)v12,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    pNode = result.pNode;
    v14 = result.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( fn->NArgs >= 2 )
    {
      v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "size");
      LOBYTE(pHeap) = 0;
      v16 = fn->FirstArgBottomIndex - 1;
      v17 = fn->Env;
      v18 = 0i64;
      if ( v16 <= 32 * ((unsigned int)v17->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v17->Stack.pCurrent - v17->Stack.pPageStart) )
        v18 = (__int64)&v17->Stack.Pages.Data.Data[v16 >> 5]->Values[v16 & 0x1F];
      v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
        &v5->Scaleform::GFx::AS2::ObjectInterface,
        v17,
        v15,
        (Scaleform::GFx::AS2::Value *)v18,
        (Scaleform::GFx::AS2::PropFlags *)&pHeap);
      v19 = result.pNode;
      v14 = result.pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( fn->NArgs >= 3 )
      {
        v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "color");
        LOBYTE(pHeap) = 0;
        v21 = fn->FirstArgBottomIndex - 2;
        v22 = fn->Env;
        if ( v21 <= 32 * ((unsigned int)v22->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v22->Stack.pCurrent - v22->Stack.pPageStart) )
          v2 = (__int64)&v22->Stack.Pages.Data.Data[v21 >> 5]->Values[v21 & 0x1F];
        v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
          &v5->Scaleform::GFx::AS2::ObjectInterface,
          v22,
          v20,
          (Scaleform::GFx::AS2::Value *)v2,
          (Scaleform::GFx::AS2::PropFlags *)&pHeap);
        v23 = result.pNode;
        v14 = result.pNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        if ( fn->NArgs >= 4 )
        {
          v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "bold");
          LOBYTE(pHeap) = 0;
          vfptr = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
          v26 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          vfptr->SetMember(
            &v5->Scaleform::GFx::AS2::ObjectInterface,
            fn->Env,
            v24,
            v26->Values,
            (Scaleform::GFx::AS2::PropFlags *)&pHeap);
          v27 = result.pNode;
          v14 = result.pNode->RefCount-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
          if ( fn->NArgs >= 5 )
          {
            v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "italic");
            LOBYTE(pHeap) = 0;
            v29 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
            v30 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
            v29->SetMember(
              &v5->Scaleform::GFx::AS2::ObjectInterface,
              fn->Env,
              v28,
              v30->Values,
              (Scaleform::GFx::AS2::PropFlags *)&pHeap);
            v31 = result.pNode;
            v14 = result.pNode->RefCount-- == 1;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
            if ( fn->NArgs >= 6 )
            {
              v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "underline");
              LOBYTE(pHeap) = 0;
              v33 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
              v34 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
              v33->SetMember(
                &v5->Scaleform::GFx::AS2::ObjectInterface,
                fn->Env,
                v32,
                v34->Values,
                (Scaleform::GFx::AS2::PropFlags *)&pHeap);
              v35 = result.pNode;
              v14 = result.pNode->RefCount-- == 1;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v35);
              if ( fn->NArgs >= 7 )
              {
                v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "url");
                LOBYTE(pHeap) = 0;
                v37 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                v38 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
                v37->SetMember(
                  &v5->Scaleform::GFx::AS2::ObjectInterface,
                  fn->Env,
                  v36,
                  v38->Values,
                  (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                v39 = result.pNode;
                v14 = result.pNode->RefCount-- == 1;
                if ( v14 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v39);
                if ( fn->NArgs >= 8 )
                {
                  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "target");
                  LOBYTE(pHeap) = 0;
                  v41 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                  v42 = Scaleform::GFx::AS2::FnCall::Arg(fn, 7);
                  v41->SetMember(
                    &v5->Scaleform::GFx::AS2::ObjectInterface,
                    fn->Env,
                    v40,
                    v42->Values,
                    (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                  v43 = result.pNode;
                  v14 = result.pNode->RefCount-- == 1;
                  if ( v14 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
                  if ( fn->NArgs >= 9 )
                  {
                    v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "align");
                    LOBYTE(pHeap) = 0;
                    v45 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                    v46 = Scaleform::GFx::AS2::FnCall::Arg(fn, 8);
                    v45->SetMember(
                      &v5->Scaleform::GFx::AS2::ObjectInterface,
                      fn->Env,
                      v44,
                      v46->Values,
                      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                    v47 = result.pNode;
                    v14 = result.pNode->RefCount-- == 1;
                    if ( v14 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v47);
                    if ( fn->NArgs >= 10 )
                    {
                      v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                              p_StringContext,
                              &result,
                              "leftMargin");
                      LOBYTE(pHeap) = 0;
                      v49 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                      v50 = Scaleform::GFx::AS2::FnCall::Arg(fn, 9);
                      v49->SetMember(
                        &v5->Scaleform::GFx::AS2::ObjectInterface,
                        fn->Env,
                        v48,
                        v50->Values,
                        (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                      v51 = result.pNode;
                      v14 = result.pNode->RefCount-- == 1;
                      if ( v14 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v51);
                      if ( fn->NArgs >= 11 )
                      {
                        v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                                p_StringContext,
                                &result,
                                "rightMargin");
                        LOBYTE(pHeap) = 0;
                        v53 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                        v54 = Scaleform::GFx::AS2::FnCall::Arg(fn, 10);
                        v53->SetMember(
                          &v5->Scaleform::GFx::AS2::ObjectInterface,
                          fn->Env,
                          v52,
                          v54->Values,
                          (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                        v55 = result.pNode;
                        v14 = result.pNode->RefCount-- == 1;
                        if ( v14 )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v55);
                        if ( fn->NArgs >= 12 )
                        {
                          v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                                  p_StringContext,
                                  &result,
                                  "indent");
                          LOBYTE(pHeap) = 0;
                          v57 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                          v58 = Scaleform::GFx::AS2::FnCall::Arg(fn, 11);
                          v57->SetMember(
                            &v5->Scaleform::GFx::AS2::ObjectInterface,
                            fn->Env,
                            v56,
                            v58->Values,
                            (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                          v59 = result.pNode;
                          v14 = result.pNode->RefCount-- == 1;
                          if ( v14 )
                            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
                          if ( fn->NArgs >= 13 )
                          {
                            v60 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                                    p_StringContext,
                                    &result,
                                    "leading");
                            LOBYTE(pHeap) = 0;
                            v61 = v5->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                            v62 = Scaleform::GFx::AS2::FnCall::Arg(fn, 12);
                            v61->SetMember(
                              &v5->Scaleform::GFx::AS2::ObjectInterface,
                              fn->Env,
                              v60,
                              v62->Values,
                              (Scaleform::GFx::AS2::PropFlags *)&pHeap);
                            v63 = result.pNode;
                            v14 = result.pNode->RefCount-- == 1;
                            if ( v14 )
                              Scaleform::GFx::ASStringNode::ReleaseNode(v63);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 599
// RVA: 0x6E0910
void __fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::TextFormatCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::TextFormatObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::TextFormatObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(this, 216i64, 0i64);
  if ( v3 )
    Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v3, penv);
}

// File Line: 604
// RVA: 0x70F280
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::Register(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *vfptr; // rax
  Scaleform::GFx::AS2::LocalFrame *pPrev; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h] BYREF
  void *pHeap; // [rsp+D8h] [rbp+58h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc(result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  pHeap = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::TextFormatCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v6->pProto.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v6->pProto.pObject = Prototype;
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFormatCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFormatCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  LOBYTE(result->pNext) = 0;
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v6;
  result->pPrev = 0i64;
  pHeap = pgc->pHeap;
  v9 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(
         pObject,
         280i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v9, &psc);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::Render::Text::TextFormat::TextFormat(
      (Scaleform::Render::Text::TextFormat *)(v9 + 96),
      psc.pContext->pHeap);
    *(_QWORD *)(v9 + 176) = 0i64;
    *(_DWORD *)(v9 + 184) = 1;
    *(_QWORD *)(v9 + 192) = 0i64;
    *(_QWORD *)(v9 + 200) = 0i64;
    *(_DWORD *)(v9 + 208) = 0;
    if ( !*(_QWORD *)(v9 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v9 + 32) + 80i64))(
        v9 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        &objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v11 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v9 + 40);
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    *(_QWORD *)(v9 + 40) = v10;
    flags = (Scaleform::MemoryHeap *)(v9 + 216);
    *(_QWORD *)(v9 + 216) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v9 + 240) = 0;
    *(_QWORD *)(v9 + 224) = 0i64;
    *(_QWORD *)(v9 + 232) = 0i64;
    *(_BYTE *)(v9 + 264) = 0;
    *(_QWORD *)(v9 + 248) = 0i64;
    *(_QWORD *)(v9 + 256) = 0i64;
    *(_QWORD *)(v9 + 272) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 216) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 216),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::TextFormatProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::TextFormatProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 216) = &Scaleform::GFx::AS2::TextFormatProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 216),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      GAS_TextFormatFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v9 = 0i64;
  }
  flags = (Scaleform::MemoryHeap *)v9;
  pHeap = &objproto;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_TextFormat,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = pgc->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  vfptr = (Scaleform::GFx::ASStringNode *)result->vfptr;
  v19.V.pStringNode = vfptr;
  if ( vfptr )
  {
    ++vfptr->RefCount;
    vfptr->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  pPrev = (Scaleform::GFx::AS2::LocalFrame *)result->pPrev;
  if ( pPrev )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v19.V.FunctionValue, pPrev, (__int64)result->pNext & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v13->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[14].RefCount,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v9 )
  {
    v16 = *(_DWORD *)(v9 + 24);
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v9 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
    }
  }
  return result;
}

