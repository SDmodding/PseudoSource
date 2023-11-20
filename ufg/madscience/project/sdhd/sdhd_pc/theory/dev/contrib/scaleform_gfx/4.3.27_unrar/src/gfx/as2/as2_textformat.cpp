// File Line: 35
// RVA: 0x6CCD10
void __fastcall Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(Scaleform::GFx::AS2::TextFormatObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // r14
  Scaleform::GFx::AS2::TextFormatObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
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
  Scaleform::GFx::AS2::Value v44; // [rsp+38h] [rbp-28h]
  char v45; // [rsp+98h] [rbp+38h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h]

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFormatObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::Render::Text::TextFormat::TextFormat(&v3->mTextFormat, v2->StringContext.pContext->pHeap);
  v3->mParagraphFormat.pAllocator = 0i64;
  v3->mParagraphFormat.RefCount = 1;
  v3->mParagraphFormat.pTabStops = 0i64;
  *(_QWORD *)&v3->mParagraphFormat.BlockIndent = 0i64;
  *(_DWORD *)&v3->mParagraphFormat.RightMargin = 0;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_TextFormat);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
  v45 = 2;
  v44.T.Type = 1;
  v5 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "align");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v5,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "blockIndent");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v8,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v9 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "bold");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v10,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v11 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "bullet");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v12,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v13 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "color");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v14,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v15 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "font");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v16,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v17 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "indent");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v18,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v19 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "italic");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v20,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v21 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "leading");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v22,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v23 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "leftMargin");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v24,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v25 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "rightMargin");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v26,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v27 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "size");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v28,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v29 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "tabStops");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v30,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v31 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v31->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "target");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v32,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v33 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v33->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "underline");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v34,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v35 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v35->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  v45 = 2;
  v44.T.Type = 1;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "url");
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    &v2->StringContext,
    v36,
    &v44,
    (Scaleform::GFx::AS2::PropFlags *)&v45);
  v37 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v37->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v44.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v44);
  if ( v2->StringContext.SWFVersion >= 8u )
  {
    v45 = 2;
    v44.T.Type = 1;
    v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "kerning");
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      &v2->StringContext,
      v38,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v39 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v39->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
    v45 = 2;
    v44.T.Type = 1;
    v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "letterSpacing");
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      &v2->StringContext,
      v40,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v41 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v41->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v41);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
  }
  if ( v2->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v45 = 2;
    v44.T.Type = 1;
    v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v2->StringContext, &result, "alpha");
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      &v2->StringContext,
      v42,
      &v44,
      (Scaleform::GFx::AS2::PropFlags *)&v45);
    v43 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v43->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
    if ( v44.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v44);
  }
}

// File Line: 66
// RVA: 0x7187B0
__int64 __fastcall Scaleform::GFx::AS2::TextFormatObject::SetMember(Scaleform::GFx::AS2::TextFormatObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r14
  const char ***v6; // r12
  Scaleform::GFx::AS2::Environment *v7; // r15
  Scaleform::GFx::AS2::TextFormatObject *v8; // rdi
  const char *v9; // rbx
  __int64 v10; // rsi
  __int64 v11; // rcx
  char v12; // al
  const char *v13; // rdx
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  __int64 v18; // rcx
  char v19; // al
  char v20; // al
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  signed int v23; // ebx
  __int64 v24; // rcx
  char v25; // al
  bool v26; // bl
  signed __int16 v27; // ax
  __int64 v28; // rcx
  char v29; // al
  bool v30; // bl
  __int64 v31; // rcx
  char v32; // al
  signed int v33; // ebx
  __int64 v34; // rcx
  char v35; // al
  __int64 v36; // rcx
  char v37; // al
  signed int v38; // ebx
  signed __int16 v39; // cx
  __int64 v40; // rcx
  char v41; // al
  bool v42; // bl
  __int64 v43; // rcx
  char v44; // al
  signed int v45; // ebx
  signed __int16 v46; // cx
  signed int v47; // ebx
  signed int v48; // ebx
  __int64 v49; // rcx
  char v50; // al
  signed int v51; // ebx
  char v52; // al
  Scaleform::GFx::AS2::Object *v53; // rax
  Scaleform::GFx::AS2::Object *v54; // r13
  __int64 v55; // rbx
  __int64 v56; // r12
  double v57; // xmm0_8
  Scaleform::GFx::AS2::Value *v58; // rax
  unsigned __int8 v59; // bl
  bool v60; // bl
  __int64 v61; // rcx
  char v62; // al
  signed int v63; // ebx
  signed int v64; // ecx
  signed __int16 v65; // ax
  __int64 v66; // rcx
  char v67; // al
  bool v68; // bl
  __int64 v69; // rcx
  char v70; // al
  signed int v71; // ebx
  Scaleform::GFx::AS2::Value v73; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::AS2::Value vala; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS2::TextFormatObject *v75; // [rsp+C0h] [rbp+40h]
  Scaleform::GFx::AS2::Environment *penva; // [rsp+C8h] [rbp+48h]
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+50h]

  result.pNode = (Scaleform::GFx::ASStringNode *)name;
  penva = penv;
  v75 = this;
  v5 = val;
  v6 = (const char ***)name;
  v7 = penv;
  v8 = this;
  Scaleform::GFx::AS2::Value::Value(&v73, val, (__int64)this);
  v9 = **v6;
  v10 = 0i64;
  v11 = 0i64;
  do
  {
    v12 = v9[v11++];
    if ( v12 != aAlign[v11 - 1] )
    {
      if ( !strcmp(**v6, "blockIndent") )
      {
        if ( v5->T.Type > 1u && v5->T.Type != 10 )
        {
          v23 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
        WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFFDu;
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
                                if ( v5->T.Type > 1u && v5->T.Type != 10 )
                                {
                                  v42 = Scaleform::GFx::AS2::Value::ToBool(v5, v7);
                                  Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                  v73.T.Type = 2;
                                  v73.V.BooleanValue = v42;
                                  Scaleform::Render::Text::TextFormat::SetItalic(
                                    (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                    v42);
                                  goto LABEL_195;
                                }
                                BYTE2(v8->mTextFormat.Url.pHeap) &= 0xFDu;
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
                                if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                                {
                                  v8->mTextFormat.PresentMask = 0;
                                  WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFF7u;
                                  goto LABEL_194;
                                }
                                v45 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                              if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                              {
                                *(&v8->mTextFormat.PresentMask + 1) = 0;
                                WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFEFu;
                                goto LABEL_194;
                              }
                              v47 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                              if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                              {
                                LOWORD(v8->mParagraphFormat.pAllocator) = 0;
                                WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFDFu;
                                goto LABEL_194;
                              }
                              v48 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                                if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                                {
                                  LOWORD(v8->mTextFormat.Url.pHeap) = 0;
                                  v27 = -9;
                                  goto LABEL_193;
                                }
                                v51 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                              v52 = v5->T.Type;
                              if ( v5->T.Type <= 1u || v52 == 10 )
                              {
                                Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc);
                                WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFBFu;
                                goto LABEL_194;
                              }
                              if ( v52 == 6 )
                              {
                                v53 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
                                if ( (*(unsigned int (**)(void))&v53->vfptr->gap8[8])() == 7 )
                                {
                                  v54 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
                                  Scaleform::Render::Text::ParagraphFormat::AllocTabStops(
                                    (Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc,
                                    v54[1].RootIndex);
                                  WORD1(v8->mParagraphFormat.pAllocator) |= 0x40u;
                                  v55 = 0i64;
                                  v56 = (signed int)v54[1].RootIndex;
                                  if ( v56 > 0 )
                                  {
                                    do
                                    {
                                      v57 = Scaleform::GFx::AS2::Value::ToNumber(
                                              (Scaleform::GFx::AS2::Value *)(&v54[1].pRCC->vfptr)[v55],
                                              penva);
                                      vala.T.Type = 3;
                                      vala.NV.NumberValue = (double)(signed int)v57;
                                      Scaleform::GFx::AS2::ArrayObject::SetElement(
                                        (Scaleform::GFx::AS2::ArrayObject *)v54,
                                        v10,
                                        &vala);
                                      if ( vala.T.Type >= 5u )
                                        Scaleform::GFx::AS2::Value::DropRefs(&vala);
                                      Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(
                                        (Scaleform::Render::Text::ParagraphFormat *)&v8->mTextFormat.pImageDesc,
                                        v10,
                                        (signed int)v57);
                                      LODWORD(v10) = v10 + 1;
                                      ++v55;
                                    }
                                    while ( v55 < v56 );
                                    v8 = v75;
                                  }
                                  Scaleform::GFx::AS2::Value::Value(&vala, v54);
                                  v59 = Scaleform::GFx::AS2::Object::SetMember(
                                          (Scaleform::GFx::AS2::Object *)&v8->vfptr,
                                          penva,
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
                                  if ( v7->StringContext.SWFVersion >= 8u )
                                  {
                                    if ( !strcmp(v9, "letterSpacing") )
                                    {
                                      if ( v5->T.Type <= 1u || v5->T.Type == 10 )
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
                                        v63 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                                          if ( v5->T.Type > 1u && v5->T.Type != 10 )
                                          {
                                            v68 = Scaleform::GFx::AS2::Value::ToBool(v5, v7);
                                            Scaleform::GFx::AS2::Value::DropRefs(&v73);
                                            v73.T.Type = 2;
                                            v73.V.BooleanValue = v68;
                                            Scaleform::Render::Text::TextFormat::SetKerning(
                                              (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                              v68);
                                            break;
                                          }
                                          BYTE2(v8->mTextFormat.Url.pHeap) &= 0xF7u;
                                          v65 = -129;
                                          goto LABEL_178;
                                        }
                                      }
                                    }
                                  }
                                  if ( v7->StringContext.pContext->GFxExtensions.Value == 1 )
                                  {
                                    v69 = 0i64;
                                    while ( 1 )
                                    {
                                      v70 = (**v6)[v69++];
                                      if ( v70 != aAlpha_0[v69 - 1] )
                                        break;
                                      if ( v69 == 6 )
                                      {
                                        if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                                        {
                                          LODWORD(v8->mTextFormat.Url.pData) |= 0xFF000000;
                                          v27 = -1025;
                                          goto LABEL_193;
                                        }
                                        v71 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                                        LODWORD(v8->mTextFormat.Url.pData) |= (unsigned __int8)(signed int)((double)(signed int)v10 * 255.0 * 0.01) << 24;
                                        WORD2(v8->mTextFormat.Url.pHeap) |= 0x400u;
                                        goto LABEL_195;
                                      }
                                    }
                                  }
                                  goto LABEL_195;
                                }
                              }
                              while ( v61 != 4 );
                              if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                              {
                                Scaleform::String::Clear((Scaleform::String *)&v8->mTextFormat);
                                v27 = -257;
                                goto LABEL_193;
                              }
                              Scaleform::GFx::AS2::Value::ToString(v5, &result, v7, -1);
                              if ( v73.T.Type >= 5u )
                                Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 5;
                              v73.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
                              ++v73.V.pStringNode->RefCount;
                              Scaleform::Render::Text::TextFormat::SetUrl(
                                (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                result.pNode->pData,
                                0xFFFFFFFFFFFFFFFFui64);
                              goto LABEL_20;
                            }
                            if ( v5->T.Type > 1u && v5->T.Type != 10 )
                            {
                              v60 = Scaleform::GFx::AS2::Value::ToBool(v5, v7);
                              Scaleform::GFx::AS2::Value::DropRefs(&v73);
                              v73.T.Type = 2;
                              v73.V.BooleanValue = v60;
                              Scaleform::Render::Text::TextFormat::SetUnderline(
                                (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                                v60);
                              goto LABEL_195;
                            }
                            BYTE2(v8->mTextFormat.Url.pHeap) &= 0xFBu;
                            v27 = -65;
                            goto LABEL_193;
                          }
                        }
                        while ( v36 != 7 );
                        if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                        {
                          *(_WORD *)&v8->mTextFormat.FormatFlags = 0;
                          WORD1(v8->mParagraphFormat.pAllocator) &= 0xFFFBu;
                          goto LABEL_194;
                        }
                        v38 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
                    if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                    {
                      v27 = -4101;
                      goto LABEL_193;
                    }
                    Scaleform::GFx::AS2::Value::ToString(v5, &result, v7, -1);
                    if ( v73.T.Type >= 5u )
                      Scaleform::GFx::AS2::Value::DropRefs(&v73);
                    v73.T.Type = 5;
                    v73.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
                    ++v73.V.pStringNode->RefCount;
                    Scaleform::Render::Text::TextFormat::SetFontList(
                      (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
                      result.pNode->pData,
                      0xFFFFFFFFFFFFFFFFui64);
                    goto LABEL_20;
                  }
                }
                while ( v31 != 6 );
                if ( v5->T.Type <= 1u || v5->T.Type == 10 )
                {
                  LODWORD(v8->mTextFormat.Url.pData) = -16777216;
                  v27 = -2;
                  goto LABEL_193;
                }
                v33 = Scaleform::GFx::AS2::Value::ToInt32(v5, v7);
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
            if ( v5->T.Type <= 1u || v5->T.Type == 10 )
            {
              WORD1(v8->mParagraphFormat.pAllocator) &= 0x7F7Fu;
              goto LABEL_194;
            }
            v30 = Scaleform::GFx::AS2::Value::ToBool(v5, v7);
            Scaleform::GFx::AS2::Value::DropRefs(&v73);
            v73.T.Type = 2;
            v73.V.BooleanValue = v30;
            if ( v30 )
              WORD1(v8->mParagraphFormat.pAllocator) |= 0x8000u;
            else
              WORD1(v8->mParagraphFormat.pAllocator) &= 0x7FFFu;
            WORD1(v8->mParagraphFormat.pAllocator) |= 0x80u;
            goto LABEL_195;
          }
        }
        while ( v24 != 5 );
        if ( v5->T.Type > 1u && v5->T.Type != 10 )
        {
          v26 = Scaleform::GFx::AS2::Value::ToBool(v5, v7);
          Scaleform::GFx::AS2::Value::DropRefs(&v73);
          v73.T.Type = 2;
          v73.V.BooleanValue = v26;
          Scaleform::Render::Text::TextFormat::SetBold(
            (Scaleform::Render::Text::TextFormat *)&v8->ResolveHandler.pLocalFrame,
            v26);
          goto LABEL_195;
        }
        BYTE2(v8->mTextFormat.Url.pHeap) &= 0xFEu;
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
  Scaleform::GFx::AS2::Value::ToString(v5, &result, v7, -1);
  v13 = result.pNode->pData;
  v14 = 0i64;
  while ( 1 )
  {
    v15 = v13[v14++];
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
    v17 = v13[v16++];
    if ( v17 != aRight_0[v16 - 1] )
      break;
    if ( v16 == 6 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) &= 0xFBFFu;
      WORD1(v8->mParagraphFormat.pAllocator) |= 0x201u;
      goto LABEL_20;
    }
  }
  v18 = 0i64;
  while ( 1 )
  {
    v19 = v13[v18++];
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
    v20 = v13[v10++];
    if ( v20 != aJustify[v10 - 1] )
      break;
    if ( v10 == 8 )
    {
      WORD1(v8->mParagraphFormat.pAllocator) &= 0xFDFFu;
      WORD1(v8->mParagraphFormat.pAllocator) |= 0x401u;
      goto LABEL_20;
    }
  }
  WORD1(v8->mParagraphFormat.pAllocator) &= 0xF9FEu;
  Scaleform::GFx::AS2::Value::DropRefs(&v73);
  v73.T.Type = 1;
LABEL_20:
  v21 = result.pNode;
  v22 = result.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
LABEL_195:
  v59 = Scaleform::GFx::AS2::Object::SetMember(
          (Scaleform::GFx::AS2::Object *)&v8->vfptr,
          v7,
          (Scaleform::GFx::ASString *)v6,
          &v73,
          flags);
LABEL_196:
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  return v59;
}

// File Line: 376
// RVA: 0x71C910
void __fastcall Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(Scaleform::GFx::AS2::TextFormatObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::Render::Text::TextFormat *textFmt)
{
  Scaleform::Render::Text::TextFormat *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::TextFormatObject *v5; // r15
  bool v6; // al
  Scaleform::GFx::AS2::Value *v7; // r14
  signed int v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // rax
  signed __int64 v10; // r15
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
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
  float v26; // xmm0_4
  Scaleform::GFx::AS2::Value *v27; // r14
  int v28; // ebx
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::StringDH *v32; // rax
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::AS2::Value *v34; // r14
  int v35; // ebx
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  unsigned int v40; // eax
  Scaleform::GFx::AS2::Value *v41; // r14
  int v42; // ebx
  Scaleform::GFx::AS2::Value *v43; // rax
  Scaleform::GFx::ASString *v44; // rax
  Scaleform::GFx::ASStringNode *v45; // rcx
  float v46; // xmm0_4
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
  Scaleform::GFx::AS2::Value v; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS2::Value v71; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v72; // [rsp+80h] [rbp+7h]
  char v73; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::ASString v75; // [rsp+F0h] [rbp+77h]

  v3 = textFmt;
  v4 = psc;
  v5 = this;
  Scaleform::Render::Text::TextFormat::operator=(&this->mTextFormat, textFmt);
  v.T.Type = 1;
  if ( (LOBYTE(v3->PresentMask) >> 4) & 1 )
  {
    v6 = v3->FormatFlags & 1;
    v71.T.Type = 2;
    v71.V.BooleanValue = v6;
    v7 = &v71;
    v8 = 1;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v7 = v9;
    v8 = 2;
  }
  v10 = (signed __int64)&v5->vfptr;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "bold");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v11,
    v7,
    &v73);
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v8 & 2 )
  {
    v8 &= 0xFFFFFFFD;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( v8 & 1 )
  {
    v8 &= 0xFFFFFFFE;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (LOBYTE(v3->PresentMask) >> 5) & 1 )
  {
    v14 = ((unsigned __int8)v3->FormatFlags >> 1) & 1;
    v71.T.Type = 2;
    v71.V.BooleanValue = v14;
    v15 = &v71;
    v16 = v8 | 4;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v15 = v17;
    v16 = v8 | 8;
  }
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "italic");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v18,
    v15,
    &v73);
  v19 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v16 & 8 )
  {
    v16 &= 0xFFFFFFF7;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( v16 & 4 )
  {
    v16 &= 0xFFFFFFFB;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (LOBYTE(v3->PresentMask) >> 6) & 1 )
  {
    v20 = ((unsigned __int8)v3->FormatFlags >> 2) & 1;
    v71.T.Type = 2;
    v71.V.BooleanValue = v20;
    v21 = &v71;
    v22 = v16 | 0x10;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v21 = v23;
    v22 = v16 | 0x20;
  }
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "underline");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v24,
    v21,
    &v73);
  v25 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v22 & 0x20 )
  {
    v22 &= 0xFFFFFFDF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( v22 & 0x10 )
  {
    v22 &= 0xFFFFFFEF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (LOBYTE(v3->PresentMask) >> 3) & 1 )
  {
    v26 = (float)v3->FontSize;
    v71.T.Type = 3;
    v71.NV.NumberValue = (float)(v26 * 0.050000001);
    v27 = &v71;
    v28 = v22 | 0x40;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v27 = v29;
    v28 = v22 | 0x80;
  }
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "size");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v30,
    v27,
    &v73);
  v31 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v31->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( (v28 & 0x80u) != 0 )
  {
    v28 &= 0xFFFFFF7F;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( v28 & 0x40 )
  {
    v28 &= 0xFFFFFFBF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (LOBYTE(v3->PresentMask) >> 2) & 1 )
  {
    v32 = Scaleform::Render::Text::TextFormat::GetFontList(v3);
    v33 = Scaleform::GFx::AS2::ASStringContext::CreateString(v4, &v75, (Scaleform::String *)&v32->0);
    v71.T.Type = 5;
    v71.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v33->pNode;
    ++v71.V.pStringNode->RefCount;
    v34 = &v71;
    v35 = v28 | 0x300;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v34 = v36;
    v35 = v28 | 0x400;
  }
  v37 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "font");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v37,
    v34,
    &v73);
  v38 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v38->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( _bittest(&v35, 0xAu) )
  {
    v35 &= 0xFFFFFBFF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( _bittest(&v35, 9u) )
  {
    v35 &= 0xFFFFFDFF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( v35 & 0x100 )
  {
    v35 &= 0xFFFFFEFF;
    v39 = v75.pNode;
    v13 = v75.pNode->RefCount == 1;
    --v39->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  }
  if ( v3->PresentMask & 1 )
  {
    v40 = v3->ColorV;
    v71.T.Type = 3;
    v71.NV.NumberValue = (double)(v40 & 0xFFFFFF);
    v41 = &v71;
    v42 = v35 | 0x800;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v41 = v43;
    v42 = v35 | 0x1000;
  }
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "color");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v44,
    v41,
    &v73);
  v45 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v45->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( _bittest(&v42, 0xCu) )
  {
    v42 &= 0xFFFFEFFF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( _bittest(&v42, 0xBu) )
  {
    v42 &= 0xFFFFF7FF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( (LOBYTE(v3->PresentMask) >> 1) & 1 )
  {
    v46 = v3->LetterSpacing;
    v71.T.Type = 3;
    v71.NV.NumberValue = (float)(v46 * 0.050000001);
    v47 = &v71;
    v48 = v42 | 0x2000;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v47 = v49;
    v48 = v42 | 0x4000;
  }
  v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "letterSpacing");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v50,
    v47,
    &v73);
  v51 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v51->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( _bittest(&v48, 0xEu) )
  {
    v48 &= 0xFFFFBFFF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( _bittest(&v48, 0xDu) )
  {
    v48 &= 0xFFFFDFFF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( SLOBYTE(v3->PresentMask) >= 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v53 = v55;
    v54 = v48 | 0x10000;
  }
  else
  {
    v52 = ((unsigned __int8)v3->FormatFlags >> 3) & 1;
    v71.T.Type = 2;
    v71.V.BooleanValue = v52;
    v53 = &v71;
    v54 = v48 | 0x8000;
  }
  v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "kerning");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v56,
    v53,
    &v73);
  v57 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v57->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( _bittest(&v54, 0x10u) )
  {
    v54 &= 0xFFFEFFFF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( _bittest(&v54, 0xFu) )
  {
    v54 &= 0xFFFF7FFF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( v3->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v3->Url.0) )
  {
    v58 = Scaleform::GFx::AS2::ASStringContext::CreateString(v4, &v75, (Scaleform::String *)&v3->Url.0);
    v71.T.Type = 5;
    v71.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v58->pNode;
    ++v71.V.pStringNode->RefCount;
    v59 = &v71;
    v60 = v54 | 0x60000;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
    v59 = v61;
    v60 = v54 | 0x80000;
  }
  v62 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "url");
  v73 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
    v10,
    v4,
    v62,
    v59,
    &v73);
  v63 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v63->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  if ( _bittest(&v60, 0x13u) )
  {
    v60 &= 0xFFF7FFFF;
    if ( v72.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v72);
  }
  if ( _bittest(&v60, 0x12u) )
  {
    v60 &= 0xFFFBFFFF;
    if ( v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( _bittest(&v60, 0x11u) )
  {
    v60 &= 0xFFFDFFFF;
    v64 = v75.pNode;
    v13 = v75.pNode->RefCount == 1;
    --v64->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  }
  if ( v4->pContext->GFxExtensions.Value == 1 )
  {
    if ( v3->PresentMask & 1 )
    {
      v71.T.Type = 3;
      v71.NV.NumberValue = (double)HIBYTE(v3->ColorV) * 100.0 * 0.00392156862745098;
      v65 = &v71;
      v66 = v60 | 0x100000;
    }
    else
    {
      Scaleform::GFx::AS2::Value::Value(&v72, &v, (__int64)v3);
      v65 = v67;
      v66 = v60 | 0x200000;
    }
    v68 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "alpha");
    v73 = 0;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v10 + 80i64))(
      v10,
      v4,
      v68,
      v65,
      &v73);
    v69 = result.pNode;
    v13 = result.pNode->RefCount == 1;
    --v69->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v69);
    if ( _bittest(&v66, 0x15u) )
    {
      v66 &= 0xFFDFFFFF;
      if ( v72.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v72);
    }
    if ( _bittest(&v66, 0x14u) && v71.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v71);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}

// File Line: 395
// RVA: 0x71A2E0
void __fastcall Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(Scaleform::GFx::AS2::TextFormatObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rsi
  Scaleform::GFx::AS2::ASStringContext *v4; // r14
  Scaleform::GFx::AS2::TextFormatObject *v5; // r15
  unsigned int v6; // edi
  const char *v7; // r8
  signed __int64 v8; // r15
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  unsigned __int16 v14; // cx
  Scaleform::GFx::AS2::Value *v15; // r12
  signed int v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  signed int v20; // eax
  Scaleform::GFx::AS2::Value *v21; // r12
  int v22; // ebx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  signed int v26; // eax
  Scaleform::GFx::AS2::Value *v27; // r12
  int v28; // ebx
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  signed int v32; // eax
  Scaleform::GFx::AS2::Value *v33; // r12
  int v34; // ebx
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  signed int v38; // eax
  Scaleform::GFx::AS2::Value *v39; // r12
  int v40; // ebx
  Scaleform::GFx::AS2::Value *v41; // rax
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  signed int v44; // eax
  Scaleform::GFx::AS2::Value *v45; // r12
  int v46; // ebx
  Scaleform::GFx::AS2::Value *v47; // rax
  Scaleform::GFx::ASString *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  const unsigned int *v50; // rbx
  Scaleform::MemoryHeap *v51; // rcx
  Scaleform::GFx::ASStringNode *v52; // rax
  Scaleform::GFx::AS2::ArrayObject *v53; // rax
  Scaleform::GFx::AS2::ArrayObject *v54; // rsi
  signed int v55; // ecx
  __int64 v56; // rax
  __int64 v57; // rbx
  Scaleform::GFx::ASString *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  unsigned int v60; // eax
  Scaleform::GFx::ASString *v61; // rax
  Scaleform::GFx::ASStringNode *v62; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::Value v64; // [rsp+58h] [rbp-31h]
  Scaleform::GFx::AS2::Value v; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::AS2::ArrayObject *v66; // [rsp+98h] [rbp+Fh]
  __int64 v67; // [rsp+A0h] [rbp+17h]
  Scaleform::MemoryHeap *v68; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASString v69; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::ASString result; // [rsp+108h] [rbp+7Fh]

  v67 = -2i64;
  v3 = paraFmt;
  v4 = psc;
  v5 = this;
  v6 = 0;
  Scaleform::Render::Text::ParagraphFormat::operator=(&this->mParagraphFormat, paraFmt);
  v.T.Type = 1;
  if ( v3->PresentMask & 1 )
  {
    v7 = "left";
    switch ( ((unsigned int)v3->PresentMask >> 9) & 3 )
    {
      case 1u:
        v7 = "right";
        break;
      case 2u:
        v7 = "justify";
        break;
      case 3u:
        v7 = "center";
        break;
    }
    val.T.Type = 5;
    val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::ASStringContext::CreateString(v4, &result, v7)->pNode;
    ++val.V.pStringNode->RefCount;
    v8 = (signed __int64)&v5->vfptr;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "align");
    LOBYTE(v68) = 0;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
      v8,
      v4,
      v9,
      &val,
      &v68);
    v10 = v69.pNode;
    v11 = v69.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    v12 = result.pNode;
  }
  else
  {
    v8 = (signed __int64)&v5->vfptr;
    v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "align");
    LOBYTE(v68) = 0;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
      v8,
      v4,
      v13,
      &v,
      &v68);
    v12 = v69.pNode;
  }
  v11 = v12->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v14 = v3->PresentMask;
  if ( (v14 & 0x80u) == 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v15 = v17;
    v16 = 2;
  }
  else
  {
    val.T.Type = 2;
    val.V.BooleanValue = (unsigned int)v14 >> 15;
    v15 = &val;
    v16 = 1;
  }
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "bullet");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v18,
    v15,
    &v68);
  v19 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v16 & 2 )
  {
    v16 &= 0xFFFFFFFD;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( v16 & 1 )
  {
    v16 &= 0xFFFFFFFE;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (LOBYTE(v3->PresentMask) >> 1) & 1 )
  {
    v20 = v3->BlockIndent;
    val.T.Type = 3;
    val.NV.NumberValue = (double)v20;
    v21 = &val;
    v22 = v16 | 4;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v21 = v23;
    v22 = v16 | 8;
  }
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "blockIndent");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v24,
    v21,
    &v68);
  v25 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v22 & 8 )
  {
    v22 &= 0xFFFFFFF7;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( v22 & 4 )
  {
    v22 &= 0xFFFFFFFB;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (LOBYTE(v3->PresentMask) >> 2) & 1 )
  {
    v26 = v3->Indent;
    val.T.Type = 3;
    val.NV.NumberValue = (double)v26;
    v27 = &val;
    v28 = v22 | 0x10;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v27 = v29;
    v28 = v22 | 0x20;
  }
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "indent");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v30,
    v27,
    &v68);
  v31 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v31->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v28 & 0x20 )
  {
    v28 &= 0xFFFFFFDF;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( v28 & 0x10 )
  {
    v28 &= 0xFFFFFFEF;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (LOBYTE(v3->PresentMask) >> 3) & 1 )
  {
    v32 = v3->Leading;
    val.T.Type = 3;
    val.NV.NumberValue = (double)v32;
    v33 = &val;
    v34 = v28 | 0x40;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v33 = v35;
    v34 = v28 | 0x80;
  }
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "leading");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v36,
    v33,
    &v68);
  v37 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v37->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( (v34 & 0x80u) != 0 )
  {
    v34 &= 0xFFFFFF7F;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( v34 & 0x40 )
  {
    v34 &= 0xFFFFFFBF;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (LOBYTE(v3->PresentMask) >> 4) & 1 )
  {
    v38 = v3->LeftMargin;
    val.T.Type = 3;
    val.NV.NumberValue = (double)v38;
    v39 = &val;
    v40 = v34 | 0x100;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v39 = v41;
    v40 = v34 | 0x200;
  }
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "leftMargin");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v42,
    v39,
    &v68);
  v43 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v43->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( _bittest(&v40, 9u) )
  {
    v40 &= 0xFFFFFDFF;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( _bittest(&v40, 8u) )
  {
    v40 &= 0xFFFFFEFF;
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( (LOBYTE(v3->PresentMask) >> 5) & 1 )
  {
    v44 = v3->RightMargin;
    val.T.Type = 3;
    val.NV.NumberValue = (double)v44;
    v45 = &val;
    v46 = v40 | 0x400;
  }
  else
  {
    Scaleform::GFx::AS2::Value::Value(&v64, &v, 0i64);
    v45 = v47;
    v46 = v40 | 0x800;
  }
  v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "rightMargin");
  LOBYTE(v68) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
    v8,
    v4,
    v48,
    v45,
    &v68);
  v49 = v69.pNode;
  v11 = v69.pNode->RefCount == 1;
  --v49->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( _bittest(&v46, 0xBu) )
  {
    v46 &= 0xFFFFF7FF;
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
  }
  if ( _bittest(&v46, 0xAu) && val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( (LOBYTE(v3->PresentMask) >> 6) & 1 )
  {
    LODWORD(v69.pNode) = 0;
    v50 = Scaleform::Render::Text::ParagraphFormat::GetTabStops(v3, (unsigned int *)&v69);
    v68 = v4->pContext->pHeap;
    v52 = (Scaleform::GFx::ASStringNode *)v68->vfptr->Alloc(v51, 144ui64, 0i64);
    result.pNode = v52;
    if ( v52 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v52, v4);
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
        v55 = v50[v6];
        val.T.Type = 3;
        val.NV.NumberValue = (double)v55;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v54, v6, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        ++v6;
      }
      while ( v6 < LODWORD(v69.pNode) );
    }
    Scaleform::GFx::AS2::Value::Value(&v64, (Scaleform::GFx::AS2::Object *)&v54->vfptr);
    v57 = v56;
    v58 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "tabStops");
    LOBYTE(v68) = 0;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
      v8,
      v4,
      v58,
      v57,
      &v68);
    v59 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v59->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v59);
    if ( v64.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v64);
    if ( v54 )
    {
      v60 = v54->RefCount;
      if ( v60 & 0x3FFFFFF )
      {
        v54->RefCount = v60 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v54->vfptr);
      }
    }
  }
  else
  {
    v61 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &v69, "tabStops");
    LOBYTE(v68) = 0;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)v8 + 80i64))(
      v8,
      v4,
      v61,
      &v,
      &v68);
    v62 = v69.pNode;
    v11 = v69.pNode->RefCount == 1;
    --v62->RefCount;
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
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  __int64 v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  signed __int64 v6; // r12
  Scaleform::RefCountNTSImpl *v7; // r15
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // r13
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Value *v13; // r10
  __int64 v14; // rcx
  Scaleform::Render::Text::DocView *v15; // r14
  Scaleform::GFx::MovieImpl *v16; // rbx
  Scaleform::Render::Text::FontManagerBase *v17; // rdi
  Scaleform::Render::Text::Allocator *v18; // rax
  __int64 v19; // rax
  __int64 v20; // r14
  Scaleform::GFx::AS2::Environment *v21; // rbx
  Scaleform::GFx::AS2::Value *v22; // rax
  double v23; // xmm6_8
  float v24; // xmm1_4
  Scaleform::Render::Text::TextFormat *v25; // rax
  Scaleform::Render::Text::ParagraphFormat *v26; // rax
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  char v31; // di
  char v32; // bl
  Scaleform::StringDH *v33; // rax
  __int64 v34; // r9
  __int64 v35; // rax
  Scaleform::Render::RenderBuffer *v36; // rbx
  double v37; // xmm2_8
  __int64 v38; // rcx
  double v39; // xmm3_8
  double v40; // xmm1_8
  Scaleform::GFx::ASStringNode *v41; // rcx
  bool v42; // zf
  unsigned int v43; // eax
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Text::TextFormat v46; // [rsp+78h] [rbp-88h]
  __int64 v47; // [rsp+C8h] [rbp-38h]
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+180h] [rbp+80h]
  Scaleform::RefCountNTSImpl *v50; // [rsp+188h] [rbp+88h]
  void *v51; // [rsp+190h] [rbp+90h]
  __int64 v52; // [rsp+198h] [rbp+98h]

  v47 = -2i64;
  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs )
  {
    v3 = v1->ThisPtr;
    if ( v3 && (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() == 30 )
    {
      v5 = v1->ThisPtr;
      v6 = (signed __int64)&v5[-2];
      if ( !v5 )
        v6 = 0i64;
      v7 = (Scaleform::RefCountNTSImpl *)&v1->Env->Target->vfptr;
      if ( v7 )
        ++v7->RefCount;
      v50 = v7;
      if ( v7 )
      {
        v51 = v1->Env->StringContext.pContext->pHeap;
        v8 = (Scaleform::GFx::AS2::Object *)(*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v51 + 80i64))(
                                              v4,
                                              96i64);
        v52 = (__int64)v8;
        if ( v8 )
        {
          Scaleform::GFx::AS2::Object::Object(v8, v1->Env);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        v51 = v10;
        v11 = v1->FirstArgBottomIndex;
        v12 = v1->Env;
        v13 = 0i64;
        if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
          v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v13, &result, v12, -1);
        v52 = (__int64)v1->Env->StringContext.pContext->pHeap;
        v15 = (Scaleform::Render::Text::DocView *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v52 + 80i64))(
                                                    v14,
                                                    352i64,
                                                    0i64);
        *(_QWORD *)&rect.x1 = v15;
        if ( v15 )
        {
          v16 = v1->Env->Target->pASRoot->pMovieImpl;
          v17 = (Scaleform::Render::Text::FontManagerBase *)((__int64 (__fastcall *)(Scaleform::RefCountNTSImpl *))v7->vfptr[67].__vecDelDtor)(v7);
          v18 = Scaleform::GFx::MovieImpl::GetTextAllocator(v16);
          Scaleform::Render::Text::DocView::DocView(v15, v18, v17, 0i64);
          v20 = v19;
        }
        else
        {
          v20 = 0i64;
        }
        v52 = v20;
        *(_BYTE *)(*(_QWORD *)(v20 + 16) + 64i64) |= 2u;
        Scaleform::Render::Text::DocView::SetAutoSizeX((Scaleform::Render::Text::DocView *)v20);
        Scaleform::Render::Text::DocView::SetAutoSizeY((Scaleform::Render::Text::DocView *)v20);
        v21 = v1->Env;
        if ( v21->StringContext.SWFVersion >= 7u && v1->NArgs >= 2 )
        {
          v22 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v23 = Scaleform::GFx::AS2::Value::ToNumber(v22, v21);
          *(_BYTE *)(v20 + 344) &= 0xFEu;
          Scaleform::Render::Text::DocView::SetWordWrap((Scaleform::Render::Text::DocView *)v20);
          v24 = v23;
          *(_QWORD *)&rect.x1 = 0i64;
          rect.x2 = v24 * 20.0;
          rect.y2 = 0.0;
          Scaleform::Render::Text::DocView::SetViewRect((Scaleform::Render::Text::DocView *)v20, &rect, UseExternally);
        }
        *(_BYTE *)(v20 + 344) |= 4u;
        Scaleform::Render::Text::TextFormat::TextFormat(&defaultTextFmt, v1->Env->StringContext.pContext->pHeap);
        defaultParagraphFmt.pAllocator = 0i64;
        defaultParagraphFmt.RefCount = 1;
        defaultParagraphFmt.pTabStops = 0i64;
        *(_QWORD *)&defaultParagraphFmt.BlockIndent = 0i64;
        *(_DWORD *)&defaultParagraphFmt.RightMargin = 0;
        Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
        Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&defaultParagraphFmt);
        v25 = Scaleform::Render::Text::TextFormat::Merge(
                &defaultTextFmt,
                &v46,
                (Scaleform::Render::Text::TextFormat *)(v6 + 96));
        Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v25);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v46);
        v26 = Scaleform::Render::Text::ParagraphFormat::Merge(
                &defaultParagraphFmt,
                (Scaleform::Render::Text::ParagraphFormat *)&v46,
                (Scaleform::Render::Text::ParagraphFormat *)(v6 + 176));
        Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, v26);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v46);
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
          *(Scaleform::Render::Text::StyledText **)(v20 + 16),
          &defaultTextFmt);
        Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
          *(Scaleform::Render::Text::StyledText **)(v20 + 16),
          &defaultParagraphFmt);
        Scaleform::Render::Text::DocView::SetText(
          (Scaleform::Render::Text::DocView *)v20,
          result.pNode->pData,
          0xFFFFFFFFFFFFFFFFui64);
        Scaleform::Render::Text::DocView::Format((Scaleform::Render::Text::DocView *)v20);
        v27 = Scaleform::Render::Text::DocView::GetTextWidth((Scaleform::Render::Text::DocView *)v20);
        LOBYTE(rect.x1) = 3;
        *(double *)&rect.x2 = (v27 + 80.0) * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "textFieldWidth",
          (Scaleform::GFx::AS2::Value *)&rect);
        if ( LOBYTE(rect.x1) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
        v28 = Scaleform::Render::Text::DocView::GetTextHeight((Scaleform::Render::Text::DocView *)v20);
        LOBYTE(rect.x1) = 3;
        *(double *)&rect.x2 = (v28 + 80.0) * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "textFieldHeight",
          (Scaleform::GFx::AS2::Value *)&rect);
        if ( LOBYTE(rect.x1) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
        v29 = Scaleform::Render::Text::DocView::GetTextWidth((Scaleform::Render::Text::DocView *)v20);
        LOBYTE(rect.x1) = 3;
        *(double *)&rect.x2 = v29 * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "width",
          (Scaleform::GFx::AS2::Value *)&rect);
        if ( LOBYTE(rect.x1) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
        v30 = Scaleform::Render::Text::DocView::GetTextHeight((Scaleform::Render::Text::DocView *)v20);
        LOBYTE(rect.x1) = 3;
        *(double *)&rect.x2 = v30 * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "height",
          (Scaleform::GFx::AS2::Value *)&rect);
        if ( LOBYTE(rect.x1) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
        v31 = (unsigned __int8)defaultTextFmt.FormatFlags >> 1;
        v32 = defaultTextFmt.FormatFlags & 1;
        v33 = Scaleform::Render::Text::TextFormat::GetFontList(&defaultTextFmt);
        LOBYTE(v34) = 1;
        v35 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, _QWORD, __int64, _QWORD))(**(_QWORD **)(v20 + 24)
                                                                                           + 8i64))(
                *(_QWORD *)(v20 + 24),
                (v33->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                ((v31 & 1) != 0) | (v32 != 0 ? 2 : 0) | 0x10u,
                v34,
                0i64);
        v36 = (Scaleform::Render::RenderBuffer *)v35;
        *(_QWORD *)&rect.x1 = v35;
        v37 = 0.0;
        if ( !v35 || (v38 = *(_QWORD *)(v35 + 48), v39 = *(float *)(v38 + 16), v37 = *(float *)(v38 + 20), v39 == 0.0) )
          v39 = DOUBLE_960_0;
        if ( v37 == 0.0 )
          v37 = 1024.0 - v39;
        v40 = (float)((float)defaultTextFmt.FontSize * 0.050000001) * 20.0 * 0.0009765625;
        LOBYTE(v46.pAllocator) = 3;
        *(double *)&v46.RefCount = (double)(signed int)(v40 * v39 * 0.05);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "ascent",
          (Scaleform::GFx::AS2::Value *)&v46);
        if ( LOBYTE(v46.pAllocator) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v46);
        LOBYTE(v46.pAllocator) = 3;
        *(double *)&v46.RefCount = (double)(signed int)(v40 * v37 * 0.05);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
          &v1->Env->StringContext,
          "descent",
          (Scaleform::GFx::AS2::Value *)&v46);
        if ( LOBYTE(v46.pAllocator) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v46);
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v10);
        if ( v36 )
          Scaleform::RefCountImpl::Release(v36);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&defaultParagraphFmt);
        Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v20);
        v41 = result.pNode;
        v42 = result.pNode->RefCount == 1;
        --v41->RefCount;
        if ( v42 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v41);
        if ( v10 )
        {
          v43 = v10->RefCount;
          if ( v43 & 0x3FFFFFF )
          {
            v10->RefCount = v43 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
          }
        }
      }
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "TextFormat");
    }
  }
}

// File Line: 535
// RVA: 0x6FA320
void __fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r14
  signed __int64 v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::ASStringContext *v8; // r12
  Scaleform::GFx::ASString *v9; // r11
  unsigned int v10; // er8
  Scaleform::GFx::AS2::Environment *v11; // r10
  signed __int64 v12; // r9
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASString *v15; // r11
  unsigned int v16; // er8
  Scaleform::GFx::AS2::Environment *v17; // r10
  signed __int64 v18; // r9
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString *v20; // r11
  unsigned int v21; // er8
  Scaleform::GFx::AS2::Environment *v22; // r10
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v25; // rdi
  Scaleform::GFx::AS2::Value *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v29; // rdi
  Scaleform::GFx::AS2::Value *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *v32; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v33; // rdi
  Scaleform::GFx::AS2::Value *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v37; // rdi
  Scaleform::GFx::AS2::Value *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASString *v40; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v41; // rdi
  Scaleform::GFx::AS2::Value *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASString *v44; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v45; // rdi
  Scaleform::GFx::AS2::Value *v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASString *v48; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v49; // rdi
  Scaleform::GFx::AS2::Value *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASString *v52; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v53; // rdi
  Scaleform::GFx::AS2::Value *v54; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASString *v56; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v57; // rdi
  Scaleform::GFx::AS2::Value *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASString *v60; // rsi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v61; // rdi
  Scaleform::GFx::AS2::Value *v62; // rax
  Scaleform::GFx::ASStringNode *v63; // rcx
  unsigned int v64; // eax
  Scaleform::MemoryHeap *v65; // [rsp+80h] [rbp+40h]
  Scaleform::GFx::AS2::Object *v66; // [rsp+88h] [rbp+48h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+50h]

  v1 = fn;
  v2 = 0i64;
  v66 = 0i64;
  v3 = fn->ThisPtr;
  if ( !v3
    || (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 30
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v65 = v1->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::ASStringNode *)v65->vfptr->Alloc((Scaleform::MemoryHeap *)v3, 216ui64, 0i64);
    result.pNode = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject((Scaleform::GFx::AS2::TextFormatObject *)v6, v1->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v4 = v1->ThisPtr;
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
  v66 = v5;
  if ( v1->NArgs >= 1 )
  {
    v8 = &v1->Env->StringContext;
    v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "font");
    LOBYTE(v65) = 0;
    v10 = v1->FirstArgBottomIndex;
    v11 = v1->Env;
    v12 = 0i64;
    if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
      v12 = (signed __int64)&v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
    v5->vfptr->SetMember(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v11,
      v9,
      (Scaleform::GFx::AS2::Value *)v12,
      (Scaleform::GFx::AS2::PropFlags *)&v65);
    v13 = result.pNode;
    v14 = result.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( v1->NArgs >= 2 )
    {
      v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "size");
      LOBYTE(v65) = 0;
      v16 = v1->FirstArgBottomIndex - 1;
      v17 = v1->Env;
      v18 = 0i64;
      if ( v16 <= 32 * ((unsigned int)v17->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v17->Stack.pCurrent - (char *)v17->Stack.pPageStart) >> 5) )
        v18 = (signed __int64)&v17->Stack.Pages.Data.Data[v16 >> 5]->Values[v16 & 0x1F];
      v5->vfptr->SetMember(
        (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
        v17,
        v15,
        (Scaleform::GFx::AS2::Value *)v18,
        (Scaleform::GFx::AS2::PropFlags *)&v65);
      v19 = result.pNode;
      v14 = result.pNode->RefCount == 1;
      --v19->RefCount;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( v1->NArgs >= 3 )
      {
        v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "color");
        LOBYTE(v65) = 0;
        v21 = v1->FirstArgBottomIndex - 2;
        v22 = v1->Env;
        if ( v21 <= 32 * ((unsigned int)v22->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v22->Stack.pCurrent - (char *)v22->Stack.pPageStart) >> 5) )
          v2 = (signed __int64)&v22->Stack.Pages.Data.Data[v21 >> 5]->Values[v21 & 0x1F];
        v5->vfptr->SetMember(
          (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
          v22,
          v20,
          (Scaleform::GFx::AS2::Value *)v2,
          (Scaleform::GFx::AS2::PropFlags *)&v65);
        v23 = result.pNode;
        v14 = result.pNode->RefCount == 1;
        --v23->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        if ( v1->NArgs >= 4 )
        {
          v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "bold");
          LOBYTE(v65) = 0;
          v25 = v5->vfptr;
          v26 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          v25->SetMember(
            (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
            v1->Env,
            v24,
            v26,
            (Scaleform::GFx::AS2::PropFlags *)&v65);
          v27 = result.pNode;
          v14 = result.pNode->RefCount == 1;
          --v27->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
          if ( v1->NArgs >= 5 )
          {
            v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "italic");
            LOBYTE(v65) = 0;
            v29 = v5->vfptr;
            v30 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
            v29->SetMember(
              (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
              v1->Env,
              v28,
              v30,
              (Scaleform::GFx::AS2::PropFlags *)&v65);
            v31 = result.pNode;
            v14 = result.pNode->RefCount == 1;
            --v31->RefCount;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
            if ( v1->NArgs >= 6 )
            {
              v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "underline");
              LOBYTE(v65) = 0;
              v33 = v5->vfptr;
              v34 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
              v33->SetMember(
                (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                v1->Env,
                v32,
                v34,
                (Scaleform::GFx::AS2::PropFlags *)&v65);
              v35 = result.pNode;
              v14 = result.pNode->RefCount == 1;
              --v35->RefCount;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v35);
              if ( v1->NArgs >= 7 )
              {
                v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "url");
                LOBYTE(v65) = 0;
                v37 = v5->vfptr;
                v38 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
                v37->SetMember(
                  (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                  v1->Env,
                  v36,
                  v38,
                  (Scaleform::GFx::AS2::PropFlags *)&v65);
                v39 = result.pNode;
                v14 = result.pNode->RefCount == 1;
                --v39->RefCount;
                if ( v14 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v39);
                if ( v1->NArgs >= 8 )
                {
                  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "target");
                  LOBYTE(v65) = 0;
                  v41 = v5->vfptr;
                  v42 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                  v41->SetMember(
                    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                    v1->Env,
                    v40,
                    v42,
                    (Scaleform::GFx::AS2::PropFlags *)&v65);
                  v43 = result.pNode;
                  v14 = result.pNode->RefCount == 1;
                  --v43->RefCount;
                  if ( v14 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
                  if ( v1->NArgs >= 9 )
                  {
                    v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "align");
                    LOBYTE(v65) = 0;
                    v45 = v5->vfptr;
                    v46 = Scaleform::GFx::AS2::FnCall::Arg(v1, 8);
                    v45->SetMember(
                      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                      v1->Env,
                      v44,
                      v46,
                      (Scaleform::GFx::AS2::PropFlags *)&v65);
                    v47 = result.pNode;
                    v14 = result.pNode->RefCount == 1;
                    --v47->RefCount;
                    if ( v14 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v47);
                    if ( v1->NArgs >= 10 )
                    {
                      v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "leftMargin");
                      LOBYTE(v65) = 0;
                      v49 = v5->vfptr;
                      v50 = Scaleform::GFx::AS2::FnCall::Arg(v1, 9);
                      v49->SetMember(
                        (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                        v1->Env,
                        v48,
                        v50,
                        (Scaleform::GFx::AS2::PropFlags *)&v65);
                      v51 = result.pNode;
                      v14 = result.pNode->RefCount == 1;
                      --v51->RefCount;
                      if ( v14 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v51);
                      if ( v1->NArgs >= 11 )
                      {
                        v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "rightMargin");
                        LOBYTE(v65) = 0;
                        v53 = v5->vfptr;
                        v54 = Scaleform::GFx::AS2::FnCall::Arg(v1, 10);
                        v53->SetMember(
                          (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                          v1->Env,
                          v52,
                          v54,
                          (Scaleform::GFx::AS2::PropFlags *)&v65);
                        v55 = result.pNode;
                        v14 = result.pNode->RefCount == 1;
                        --v55->RefCount;
                        if ( v14 )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v55);
                        if ( v1->NArgs >= 12 )
                        {
                          v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "indent");
                          LOBYTE(v65) = 0;
                          v57 = v5->vfptr;
                          v58 = Scaleform::GFx::AS2::FnCall::Arg(v1, 11);
                          v57->SetMember(
                            (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                            v1->Env,
                            v56,
                            v58,
                            (Scaleform::GFx::AS2::PropFlags *)&v65);
                          v59 = result.pNode;
                          v14 = result.pNode->RefCount == 1;
                          --v59->RefCount;
                          if ( v14 )
                            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
                          if ( v1->NArgs >= 13 )
                          {
                            v60 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, &result, "leading");
                            LOBYTE(v65) = 0;
                            v61 = v5->vfptr;
                            v62 = Scaleform::GFx::AS2::FnCall::Arg(v1, 12);
                            v61->SetMember(
                              (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
                              v1->Env,
                              v60,
                              v62,
                              (Scaleform::GFx::AS2::PropFlags *)&v65);
                            v63 = result.pNode;
                            v14 = result.pNode->RefCount == 1;
                            --v63->RefCount;
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
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
  if ( v5 )
  {
    v64 = v5->RefCount;
    if ( v64 & 0x3FFFFFF )
    {
      v5->RefCount = v64 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 599
// RVA: 0x6E0910
void __fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::CreateNewObject(Scaleform::GFx::AS2::TextFormatCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::TextFormatObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::TextFormatObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                                  (Scaleform::MemoryHeap *)this,
                                                  216ui64,
                                                  0i64);
  if ( v3 )
    Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v3, v2);
}

// File Line: 604
// RVA: 0x70F280
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::TextFormatCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::MemoryHeap *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::AS2::LocalFrame *v16; // rdx
  int v17; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v20; // [rsp+58h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h]
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v23; // [rsp+D8h] [rbp+58h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc((Scaleform::MemoryHeap *)result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::TextFormatCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v20.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->pProto.pObject->vfptr;
    if ( v5 )
    {
      v8 = v5->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v5->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v6->pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFormatCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFormatCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v2->pHeap;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))v23->pObject->pWatchpoints)(
         v5,
         280i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
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
      v20.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v9 + 32) + 80i64))(
        v9 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        &objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v11 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v9 + 40);
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    *(_QWORD *)(v9 + 40) = v10;
    v13 = (Scaleform::MemoryHeap *)(v9 + 216);
    flags = v13;
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v13->SelfSize) = 0;
    v13->pPrev = 0i64;
    v13->pNext = 0i64;
    *(_BYTE *)(v9 + 264) = 0;
    *(_QWORD *)(v9 + 248) = 0i64;
    *(_QWORD *)(v9 + 256) = 0i64;
    *(_QWORD *)(v9 + 272) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 216),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      v3);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::TextFormatProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::TextFormatProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::TextFormatProto::`vftable;
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
  v23 = &objproto;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_TextFormat,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v14 = v2->pGlobal.pObject;
  v20.T.Type = 8;
  v20.V.FunctionValue.Flags = 0;
  v15 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v20.V.pStringNode = v15;
  if ( v15 )
  {
    ++v15->RefCount;
    v15->RefCount &= 0x8FFFFFFF;
  }
  v20.V.FunctionValue.pLocalFrame = 0i64;
  v16 = v3->pLocalFrame;
  if ( v16 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v20.NV.8,
      v16,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v14->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v14->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[14].RefCount,
    &v20,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  if ( v9 )
  {
    v17 = *(_DWORD *)(v9 + 24);
    if ( v17 & 0x3FFFFFF )
    {
      *(_DWORD *)(v9 + 24) = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
    }
  }
  return v3;
}

