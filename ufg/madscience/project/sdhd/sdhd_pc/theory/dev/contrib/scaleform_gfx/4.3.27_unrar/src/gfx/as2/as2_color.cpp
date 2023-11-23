// File Line: 29
// RVA: 0x6AA870
void __fastcall Scaleform::GFx::AS2::ColorProto::SetTransform(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  Scaleform::GFx::ASString *ConstString; // rax
  char v9; // r15
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  float v12; // xmm1_4
  Scaleform::GFx::ASString *v13; // rax
  bool v14; // r15
  Scaleform::GFx::ASStringNode *v15; // rcx
  float v16; // xmm1_4
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // r15
  Scaleform::GFx::ASStringNode *v19; // rcx
  float v20; // xmm1_4
  Scaleform::GFx::ASString *v21; // rax
  bool v22; // r15
  Scaleform::GFx::ASStringNode *v23; // rcx
  float v24; // xmm1_4
  Scaleform::GFx::ASString *v25; // rax
  bool v26; // r15
  Scaleform::GFx::ASStringNode *v27; // rcx
  float v28; // xmm1_4
  Scaleform::GFx::ASString *v29; // rax
  bool v30; // r15
  Scaleform::GFx::ASStringNode *v31; // rcx
  float v32; // xmm1_4
  Scaleform::GFx::ASString *v33; // rax
  bool v34; // r15
  Scaleform::GFx::ASStringNode *v35; // rcx
  float v36; // xmm1_4
  Scaleform::GFx::ASString *v37; // rax
  bool v38; // si
  Scaleform::GFx::ASStringNode *v39; // rcx
  float v40; // xmm1_4
  Scaleform::GFx::AS2::Value v41; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::Render::Cxform v42; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+B0h] [rbp+30h] BYREF
  Scaleform::GFx::Sprite *v44; // [rsp+B8h] [rbp+38h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 21 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      pObject = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        pObject = result.pObject;
      }
      v44 = pObject;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( fn->NArgs >= 1 )
      {
        if ( pObject )
        {
          v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, fn->Env);
          if ( v6 )
          {
            v42 = *Scaleform::GFx::DisplayObjectBase::GetCxform(pObject);
            v41.T.Type = 0;
            p_StringContext = &fn->Env->StringContext;
            ConstString = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                            p_StringContext,
                            (Scaleform::GFx::ASString *)&result,
                            "ba");
            v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v6->vfptr->GetMemberRaw)(
                   v6,
                   p_StringContext,
                   ConstString,
                   &v41,
                   -2i64);
            v10 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v10);
            if ( v9 )
            {
              v12 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[0][2] = v12 * 0.0099999998;
            }
            v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "ga");
            v14 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v13, &v41);
            v15 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v15);
            if ( v14 )
            {
              v16 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[0][1] = v16 * 0.0099999998;
            }
            v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "ra");
            v18 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v17, &v41);
            v19 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            if ( v18 )
            {
              v20 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[0][0] = v20 * 0.0099999998;
            }
            v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "aa");
            v22 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v21, &v41);
            v23 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v23);
            if ( v22 )
            {
              v24 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[0][3] = v24 * 0.0099999998;
            }
            v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "bb");
            v26 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v25, &v41);
            v27 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v27);
            if ( v26 )
            {
              v28 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[1][2] = v28 * 0.0039215689;
            }
            v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "gb");
            v30 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v29, &v41);
            v31 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
            if ( v30 )
            {
              v32 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[1][1] = v32 * 0.0039215689;
            }
            v33 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "rb");
            v34 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v33, &v41);
            v35 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v35);
            if ( v34 )
            {
              v36 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[1][0] = v36 * 0.0039215689;
            }
            v37 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(
                    p_StringContext,
                    (Scaleform::GFx::ASString *)&result,
                    "ab");
            v38 = v6->vfptr->GetMemberRaw(v6, p_StringContext, v37, &v41);
            v39 = (Scaleform::GFx::ASStringNode *)result.pObject;
            v11 = LODWORD(result.pObject->vfptr)-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v39);
            if ( v38 )
            {
              v40 = Scaleform::GFx::AS2::Value::ToNumber(&v41, fn->Env);
              v42.M[1][3] = v40 * 0.0039215689;
            }
            Scaleform::GFx::DisplayObjectBase::SetCxform(pObject, &v42);
            pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
              pObject,
              0);
            if ( v41.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v41);
          }
        }
      }
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 73
// RVA: 0x6AACC0
void __fastcall Scaleform::GFx::AS2::ColorProto::GetTransform(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::RefCountNTSImplCore *v5; // rcx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int RefCount; // eax
  Scaleform::Render::Cxform v28; // [rsp+40h] [rbp-29h]
  Scaleform::GFx::AS2::Value v29; // [rsp+60h] [rbp-9h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v31; // [rsp+D8h] [rbp+6Fh] BYREF
  Scaleform::GFx::Sprite *v32; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::AS2::Object *v33; // [rsp+E8h] [rbp+7Fh]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 21 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      pObject = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        pObject = result.pObject;
      }
      v32 = pObject;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( pObject )
      {
        v28 = *Scaleform::GFx::DisplayObjectBase::GetCxform(pObject);
        result.pObject = (Scaleform::GFx::Sprite *)fn->Env->StringContext.pContext->pHeap;
        v6 = (Scaleform::GFx::ASStringNode *)result.pObject->vfptr[10].__vecDelDtor(v5, 96i64);
        v31.pNode = v6;
        if ( v6 )
        {
          Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v6, fn->Env);
          v8 = v7;
        }
        else
        {
          v8 = 0i64;
        }
        v33 = v8;
        p_StringContext = &fn->Env->StringContext;
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[0][2] * 100.0);
        v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "ba");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v10,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        pNode = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[0][1] * 100.0);
        v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "ga");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v13,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v14 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[0][0] * 100.0);
        v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "ra");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v15,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v16 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[0][3] * 100.0);
        v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "aa");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v17,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v18 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[1][2] * 255.0);
        v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "bb");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v19,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v20 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[1][1] * 255.0);
        v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "gb");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v21,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v22 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[1][0] * 255.0);
        v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "rb");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v23,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v24 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        v29.T.Type = 3;
        v29.NV.NumberValue = (float)(v28.M[1][3] * 255.0);
        v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v31, "ab");
        LOBYTE(result.pObject) = 0;
        v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          v25,
          &v29,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        v26 = v31.pNode;
        v12 = v31.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v8);
        RefCount = v8->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 102
// RVA: 0x6AB190
void __fastcall Scaleform::GFx::AS2::ColorProto::SetRGB(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  int v6; // edi
  Scaleform::Render::Cxform *Cxform; // rax
  Scaleform::Render::Cxform v8; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v10; // [rsp+68h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 21 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      pObject = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        pObject = result.pObject;
      }
      v10 = pObject;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( fn->NArgs >= 1 && pObject )
      {
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v5, fn->Env);
        Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(pObject);
        *(_OWORD *)&v8.M[0][0] = *(_OWORD *)&Cxform->M[0][0];
        LODWORD(v8.M[1][3]) = HIDWORD(*(_OWORD *)&Cxform->M[1][0]);
        *(_QWORD *)&v8.M[0][1] = 0i64;
        v8.M[0][0] = 0.0;
        v8.M[1][0] = (float)BYTE2(v6);
        v8.M[1][1] = (float)BYTE1(v6);
        v8.M[1][2] = (float)(unsigned __int8)v6;
        Scaleform::Render::Cxform::Normalize(&v8);
        Scaleform::GFx::DisplayObjectBase::SetCxform(pObject, &v8);
        pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
          pObject,
          0);
      }
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 127
// RVA: 0x6AB300
void __fastcall Scaleform::GFx::AS2::ColorProto::GetRGB(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::Sprite *pObject; // rbx
  __m128 v5; // xmm1
  int v6; // esi
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v9; // [rsp+68h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 21 )
  {
    v3 = fn->ThisPtr;
    if ( v3 && v3 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3[4],
        &result);
      pObject = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        pObject = result.pObject;
      }
      v9 = pObject;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( pObject )
      {
        v5 = *(__m128 *)&Scaleform::GFx::DisplayObjectBase::GetCxform(pObject)->M[1][0];
        v6 = (unsigned __int16)(-256 * (int)_mm_shuffle_ps(v5, v5, 85).m128_f32[0]) | (-65536 * (int)v5.m128_f32[0]) & 0xFF0000 | (unsigned __int8)-(int)_mm_shuffle_ps(v5, v5, 170).m128_f32[0];
        v7 = fn->Result;
        if ( v7->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v7);
        v7->T.Type = 4;
        v7->NV.Int32Value = v6;
      }
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Color");
  }
}

// File Line: 164
// RVA: 0x6F8FE0
void __fastcall Scaleform::GFx::AS2::ColorCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ColorObject *v2; // rbx
  Scaleform::GFx::InteractiveObject *TargetByValue; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rcx
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::ColorObject *v9; // rax
  Scaleform::GFx::AS2::ColorObject *v10; // rax
  unsigned int RefCount; // eax

  v2 = 0i64;
  TargetByValue = 0i64;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(Env, v6);
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 21 )
  {
    v8 = fn->ThisPtr;
    if ( v8 )
    {
      v2 = (Scaleform::GFx::AS2::ColorObject *)&v8[-2];
      if ( v8 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
        v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    }
    Scaleform::GFx::AS2::ColorObject::SetTarget(v2, TargetByValue);
  }
  else
  {
    v9 = (Scaleform::GFx::AS2::ColorObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               ThisPtr,
                                               104i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::ColorObject::ColorObject(v9, fn->Env, TargetByValue);
      v2 = v10;
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v2);
  if ( v2 )
  {
    RefCount = v2->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
}

// File Line: 181
// RVA: 0x6E03F0
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::ColorCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ColorCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::Object *Prototype; // rax

  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ColorCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        104i64);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  Scaleform::GFx::AS2::Object::Object(v3, penv);
  v4->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = 0i64;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Color);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&v4->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  return v4;
}

// File Line: 186
// RVA: 0x70D020
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::ColorCtorFunction::Register(
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ColorCtorFunction::GlobalCtor;
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
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
         168i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v9, &psc);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    objproto.pObject = (Scaleform::GFx::AS2::Object *)(v9 + 96);
    *(_QWORD *)(v9 + 96) = 0i64;
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
    flags = (Scaleform::MemoryHeap *)(v9 + 104);
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v9 + 128) = 0;
    *(_QWORD *)(v9 + 112) = 0i64;
    *(_QWORD *)(v9 + 120) = 0i64;
    *(_BYTE *)(v9 + 152) = 0;
    *(_QWORD *)(v9 + 136) = 0i64;
    *(_QWORD *)(v9 + 144) = 0i64;
    *(_QWORD *)(v9 + 160) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::ColorProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::ColorProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::ColorProto::`vftable;
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
  pHeap = &objproto;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Color,
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
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[10],
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

