// File Line: 29
// RVA: 0x6AA870
void __fastcall Scaleform::GFx::AS2::ColorProto::SetTransform(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  Scaleform::Render::Cxform *v7; // rax
  Scaleform::GFx::AS2::ASStringContext *v8; // r14
  Scaleform::GFx::ASString *v9; // rax
  __int64 v10; // r15
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  float v13; // xmm1_4
  Scaleform::GFx::ASString *v14; // rax
  _BOOL8 v15; // r15
  Scaleform::GFx::ASStringNode *v16; // rcx
  float v17; // xmm1_4
  Scaleform::GFx::ASString *v18; // rax
  _BOOL8 v19; // r15
  Scaleform::GFx::ASStringNode *v20; // rcx
  float v21; // xmm1_4
  Scaleform::GFx::ASString *v22; // rax
  _BOOL8 v23; // r15
  Scaleform::GFx::ASStringNode *v24; // rcx
  float v25; // xmm1_4
  Scaleform::GFx::ASString *v26; // rax
  _BOOL8 v27; // r15
  Scaleform::GFx::ASStringNode *v28; // rcx
  float v29; // xmm1_4
  Scaleform::GFx::ASString *v30; // rax
  _BOOL8 v31; // r15
  Scaleform::GFx::ASStringNode *v32; // rcx
  float v33; // xmm1_4
  Scaleform::GFx::ASString *v34; // rax
  _BOOL8 v35; // r15
  Scaleform::GFx::ASStringNode *v36; // rcx
  float v37; // xmm1_4
  Scaleform::GFx::ASString *v38; // rax
  _BOOL8 v39; // rsi
  Scaleform::GFx::ASStringNode *v40; // rcx
  float v41; // xmm1_4
  Scaleform::GFx::AS2::Value v42; // [rsp+28h] [rbp-58h]
  Scaleform::Render::Cxform v43; // [rsp+50h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+B0h] [rbp+30h]
  Scaleform::GFx::Sprite *v45; // [rsp+B8h] [rbp+38h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 21 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      v4 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v4 = result.pObject;
      }
      v45 = v4;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v1->NArgs >= 1 )
      {
        if ( v4 )
        {
          v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, v1->Env);
          if ( v6 )
          {
            v7 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr);
            *(_OWORD *)&v43.M[0][0] = *(_OWORD *)&v7->M[0][0];
            *(_OWORD *)&v43.M[1][0] = *(_OWORD *)&v7->M[1][0];
            v42.T.Type = 0;
            v8 = &v1->Env->StringContext;
            v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "ba");
            v10 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v6->vfptr->GetMemberRaw)(
                    v6,
                    v8,
                    v9,
                    &v42,
                    -2i64);
            v11 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v11->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v11);
            if ( (_BYTE)v10 )
            {
              v13 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[0][2] = v13 * 0.0099999998;
            }
            v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "ga");
            v15 = v6->vfptr->GetMemberRaw(v6, v8, v14, &v42);
            v16 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v16->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v16);
            if ( (_BYTE)v15 )
            {
              v17 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[0][1] = v17 * 0.0099999998;
            }
            v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "ra");
            v19 = v6->vfptr->GetMemberRaw(v6, v8, v18, &v42);
            v20 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v20->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v20);
            if ( (_BYTE)v19 )
            {
              v21 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[0][0] = v21 * 0.0099999998;
            }
            v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "aa");
            v23 = v6->vfptr->GetMemberRaw(v6, v8, v22, &v42);
            v24 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v24->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v24);
            if ( (_BYTE)v23 )
            {
              v25 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[0][3] = v25 * 0.0099999998;
            }
            v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "bb");
            v27 = v6->vfptr->GetMemberRaw(v6, v8, v26, &v42);
            v28 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v28->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v28);
            if ( (_BYTE)v27 )
            {
              v29 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[1][2] = v29 * 0.0039215689;
            }
            v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "gb");
            v31 = v6->vfptr->GetMemberRaw(v6, v8, v30, &v42);
            v32 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v32->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            if ( (_BYTE)v31 )
            {
              v33 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[1][1] = v33 * 0.0039215689;
            }
            v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "rb");
            v35 = v6->vfptr->GetMemberRaw(v6, v8, v34, &v42);
            v36 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v36->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v36);
            if ( (_BYTE)v35 )
            {
              v37 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[1][0] = v37 * 0.0039215689;
            }
            v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v8, (Scaleform::GFx::ASString *)&result, "ab");
            v39 = v6->vfptr->GetMemberRaw(v6, v8, v38, &v42);
            v40 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v12 = LODWORD(result.pObject->vfptr) == 1;
            --v40->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v40);
            if ( (_BYTE)v39 )
            {
              v41 = Scaleform::GFx::AS2::Value::ToNumber(&v42, v1->Env);
              v43.M[1][3] = v41 * 0.0039215689;
            }
            Scaleform::GFx::DisplayObjectBase::SetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &v43);
            v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
            if ( v42.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v42);
          }
        }
      }
      if ( v4 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 73
// RVA: 0x6AACC0
void __fastcall Scaleform::GFx::AS2::ColorProto::GetTransform(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::Render::Cxform *v5; // rax
  Scaleform::RefCountNTSImplCore *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rsi
  Scaleform::GFx::AS2::ASStringContext *v10; // r14
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
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
  unsigned int v28; // eax
  __int128 v29; // [rsp+40h] [rbp-29h]
  __int128 v30; // [rsp+50h] [rbp-19h]
  Scaleform::GFx::AS2::Value v31; // [rsp+60h] [rbp-9h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::ASString v33; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::Sprite *v34; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::AS2::Object *v35; // [rsp+E8h] [rbp+7Fh]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 21 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      v4 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v4 = result.pObject;
      }
      v34 = v4;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v4 )
      {
        v5 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr);
        v29 = *(_OWORD *)&v5->M[0][0];
        v30 = *(_OWORD *)&v5->M[1][0];
        result.pObject = (Scaleform::GFx::Sprite *)v1->Env->StringContext.pContext->pHeap;
        v7 = (Scaleform::GFx::ASStringNode *)result.pObject->vfptr[10].__vecDelDtor(v6, 96u);
        v33.pNode = v7;
        if ( v7 )
        {
          Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, v1->Env);
          v9 = v8;
        }
        else
        {
          v9 = 0i64;
        }
        v35 = v9;
        v10 = &v1->Env->StringContext;
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v29 + 2) * 100.0);
        v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "ba");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v11,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v12 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v12->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v29 + 1) * 100.0);
        v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "ga");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v14,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v15 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v15->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*(float *)&v29 * 100.0);
        v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "ra");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v16,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v17 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v29 + 3) * 100.0);
        v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "aa");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v18,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v19 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v19->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v30 + 2) * 255.0);
        v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "bb");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v20,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v21 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v21->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v30 + 1) * 255.0);
        v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "gb");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v22,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v23 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v23->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*(float *)&v30 * 255.0);
        v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "rb");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v24,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v25 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v25->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v31.T.Type = 3;
        v31.NV.NumberValue = (float)(*((float *)&v30 + 3) * 255.0);
        v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &v33, "ab");
        LOBYTE(result.pObject) = 0;
        v9->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          v10,
          v26,
          &v31,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v27 = v33.pNode;
        v13 = v33.pNode->RefCount == 1;
        --v27->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v9);
        v28 = v9->RefCount;
        if ( v28 & 0x3FFFFFF )
        {
          v9->RefCount = v28 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
        }
      }
      if ( v4 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 102
// RVA: 0x6AB190
void __fastcall Scaleform::GFx::AS2::ColorProto::SetRGB(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  signed int v6; // edi
  Scaleform::Render::Cxform *v7; // rax
  Scaleform::Render::Cxform v8; // [rsp+30h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::Sprite *v10; // [rsp+68h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 21 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      v4 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v4 = result.pObject;
      }
      v10 = v4;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v1->NArgs >= 1 && v4 )
      {
        v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v6 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v1->Env);
        v7 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr);
        *(_OWORD *)&v8.M[0][0] = *(_OWORD *)&v7->M[0][0];
        *(_OWORD *)&v8.M[1][0] = *(_OWORD *)&v7->M[1][0];
        *(_QWORD *)&v8.M[0][1] = 0i64;
        v8.M[0][0] = 0.0;
        v8.M[1][0] = (float)BYTE2(v6);
        v8.M[1][1] = (float)BYTE1(v6);
        v8.M[1][2] = (float)(unsigned __int8)v6;
        Scaleform::Render::Cxform::Normalize(&v8);
        Scaleform::GFx::DisplayObjectBase::SetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &v8);
        v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
      }
      if ( v4 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 127
// RVA: 0x6AB300
void __fastcall Scaleform::GFx::AS2::ColorProto::GetRGB(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::Render::Cxform *v5; // rax
  __int128 v6; // ST30_16
  __m128 v7; // xmm1
  int v8; // esi
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::Sprite *v11; // [rsp+68h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 21 )
  {
    v3 = v1->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      v4 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v4 = result.pObject;
      }
      v11 = v4;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v4 )
      {
        v5 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr);
        v6 = *(_OWORD *)&v5->M[0][0];
        v7 = *(__m128 *)&v5->M[1][0];
        v8 = (unsigned __int16)(-256 * (signed int)COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) & 0xFF00) | -65536 * (signed int)v7.m128_f32[0] & 0xFF0000 | (unsigned __int8)-(signed int)COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170));
        v9 = v1->Result;
        if ( v9->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v9);
        v9->T.Type = 4;
        v9->NV.Int32Value = v8;
      }
      if ( v4 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 164
// RVA: 0x6F8FE0
void __fastcall Scaleform::GFx::AS2::ColorCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ColorObject *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rsi
  unsigned int v4; // er10
  Scaleform::GFx::AS2::Environment *v5; // rcx
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::ColorObject *v9; // rax
  Scaleform::GFx::AS2::ColorObject *v10; // rax
  unsigned int v11; // eax

  v1 = fn;
  v2 = 0i64;
  v3 = 0i64;
  if ( fn->NArgs >= 1 )
  {
    v4 = fn->FirstArgBottomIndex;
    v5 = fn->Env;
    v6 = 0i64;
    if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    v3 = Scaleform::GFx::AS2::Environment::FindTargetByValue(v5, v6);
  }
  v7 = v1->ThisPtr;
  if ( v7 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->vfptr->gap8[8])(v7) == 21 )
  {
    v8 = v1->ThisPtr;
    if ( v8 )
    {
      v2 = (Scaleform::GFx::AS2::ColorObject *)&v8[-2];
      if ( v8 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
        v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    }
    Scaleform::GFx::AS2::ColorObject::SetTarget(v2, v3);
  }
  else
  {
    v9 = (Scaleform::GFx::AS2::ColorObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               v7,
                                               104i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::ColorObject::ColorObject(v9, v1->Env, v3);
      v2 = v10;
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v2->vfptr);
  if ( v2 )
  {
    v11 = v2->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v2->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
    }
  }
}

// File Line: 181
// RVA: 0x6E03F0
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::ColorCtorFunction::CreateNewObject(Scaleform::GFx::AS2::ColorCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::Object *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::Object *v5; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ColorCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        104i64);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  Scaleform::GFx::AS2::Object::Object(v3, v2);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4[1].vfptr = 0i64;
  v5 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Color);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)((char *)v4 + 32), &v2->StringContext, v5);
  return v4;
}

// File Line: 186
// RVA: 0x70D020
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ColorCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
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
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ColorCtorFunction::GlobalCtor;
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
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
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
         168i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v9, &psc);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    objproto.pObject = (Scaleform::GFx::AS2::Object *)(v9 + 96);
    *(_QWORD *)(v9 + 96) = 0i64;
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
    v13 = (Scaleform::MemoryHeap *)(v9 + 104);
    flags = v13;
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    LOBYTE(v13->SelfSize) = 0;
    v13->pPrev = 0i64;
    v13->pNext = 0i64;
    *(_BYTE *)(v9 + 152) = 0;
    *(_QWORD *)(v9 + 136) = 0i64;
    *(_QWORD *)(v9 + 144) = 0i64;
    *(_QWORD *)(v9 + 160) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      v3);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::ColorProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::ColorProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::ColorProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      GAS_ColorFunctionTable,
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
    ASBuiltin_Color,
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
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[10],
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

