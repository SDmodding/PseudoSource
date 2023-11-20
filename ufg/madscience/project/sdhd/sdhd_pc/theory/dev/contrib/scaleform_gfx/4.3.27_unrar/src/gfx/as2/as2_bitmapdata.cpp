// File Line: 29
// RVA: 0x6C79F0
void __fastcall Scaleform::GFx::AS2::BitmapData::BitmapData(Scaleform::GFx::AS2::BitmapData *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::BitmapData *v3; // rdi

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->pImageRes.pObject = 0i64;
  v3->pMovieDef.pObject = 0i64;
  Scaleform::GFx::AS2::BitmapData::commonInit(v3, v2);
}

// File Line: 34
// RVA: 0x724F50
void __fastcall Scaleform::GFx::AS2::BitmapData::commonInit(Scaleform::GFx::AS2::BitmapData *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rsi
  Scaleform::GFx::AS2::BitmapData *v3; // rbx
  Scaleform::GFx::AS2::Object *v4; // rax
  signed __int64 v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-30h]
  char v12; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+10h]

  v2 = penv;
  v3 = this;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_BitmapData);
  v5 = (signed __int64)&v3->vfptr;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(*(_QWORD *)v5 + 104i64))(
    v5,
    &v2->StringContext,
    v4);
  v12 = 4;
  v11.T.Type = 10;
  v6 = Scaleform::GFx::AS2::Environment::CreateConstString(v2, &result, "width");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    &v2->StringContext,
    v6,
    &v11,
    &v12);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v12 = 4;
  v11.T.Type = 10;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v2, &result, "height");
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v5 + 80i64))(
    v5,
    &v2->StringContext,
    v9,
    &v11,
    &v12);
  v10 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 44
// RVA: 0x6C12F0
Scaleform::GFx::AS2::BitmapData *__fastcall Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *linkageId)
{
  Scaleform::GFx::ASString *v2; // r14
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // rcx
  const char *v5; // rbx
  Scaleform::GFx::MovieImpl *v6; // rdi
  Scaleform::GFx::MovieDefImpl *v7; // rax
  Scaleform::GFx::AS2::BitmapData *v8; // rbx
  Scaleform::GFx::Resource *v9; // rax
  __int64 v10; // rcx
  Scaleform::GFx::MovieDef *v11; // rdi
  Scaleform::GFx::AS2::BitmapData *v12; // rax
  Scaleform::GFx::AS2::BitmapData *v13; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageResource> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::MovieDef *v16; // [rsp+68h] [rbp+10h]
  Scaleform::MemoryHeap *v17; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::AS2::BitmapData *v18; // [rsp+78h] [rbp+20h]

  v2 = linkageId;
  v3 = penv;
  v4 = penv->Target;
  v5 = linkageId->pNode->pData;
  v6 = v4->pASRoot->pMovieImpl;
  v7 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[66].__vecDelDtor)(v4);
  Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(v6, &result, v7, v5);
  if ( result.pObject )
  {
    v9 = (Scaleform::GFx::Resource *)((__int64 (*)(void))v3->Target->vfptr[66].__vecDelDtor)();
    v11 = (Scaleform::GFx::MovieDef *)v9;
    if ( v9 )
      Scaleform::Render::RenderBuffer::AddRef(v9);
    v16 = v11;
    if ( v11 )
    {
      v17 = v3->StringContext.pContext->pHeap;
      v12 = (Scaleform::GFx::AS2::BitmapData *)((__int64 (__fastcall *)(__int64, signed __int64))v17->vfptr->Alloc)(
                                                 v10,
                                                 112i64);
      v18 = v12;
      if ( v12 )
      {
        Scaleform::GFx::AS2::BitmapData::BitmapData(v12, v3);
        v8 = v13;
      }
      else
      {
        v8 = 0i64;
      }
      Scaleform::GFx::AS2::BitmapData::SetImage(v8, v3, result.pObject, v11);
    }
    else
    {
      v8 = 0i64;
    }
    if ( v11 )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v11->vfptr);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      v3,
      "BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"",
      v2->pNode->pData);
    v8 = 0i64;
  }
  if ( result.pObject )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&result.pObject->vfptr);
  return v8;
}

// File Line: 70
// RVA: 0x7148E0
void __fastcall Scaleform::GFx::AS2::BitmapData::SetImage(Scaleform::GFx::AS2::BitmapData *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ImageResource *pimg, Scaleform::GFx::MovieDef *pmovieDef)
{
  Scaleform::GFx::MovieDef *v4; // rdi
  Scaleform::GFx::ImageResource *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::GFx::AS2::BitmapData *v7; // rsi
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::GFx::Resource *v9; // rcx
  Scaleform::GFx::AS2::RectangleObject *v10; // r14
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-99h]
  int v18; // [rsp+50h] [rbp-79h]
  int v19; // [rsp+54h] [rbp-75h]
  int v20; // [rsp+58h] [rbp-71h]
  int v21; // [rsp+5Ch] [rbp-6Dh]
  __int64 v22; // [rsp+60h] [rbp-69h]
  char ptr; // [rsp+70h] [rbp-59h]
  Scaleform::GFx::AS2::Value v24; // [rsp+90h] [rbp-39h]
  Scaleform::GFx::AS2::Value v25; // [rsp+B0h] [rbp-19h]
  Scaleform::GFx::AS2::Value v26; // [rsp+D0h] [rbp+7h]
  char v27; // [rsp+130h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh]
  __int64 v29; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::AS2::RectangleObject *v30; // [rsp+148h] [rbp+7Fh]

  v22 = -2i64;
  v4 = pmovieDef;
  v5 = pimg;
  v6 = penv;
  v7 = this;
  if ( pimg )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&pimg->vfptr);
  v8 = (Scaleform::GFx::Resource *)&v7->pImageRes.pObject->vfptr;
  if ( v8 )
    Scaleform::GFx::Resource::Release(v8);
  v7->pImageRes.pObject = v5;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v4->vfptr);
  v9 = (Scaleform::GFx::Resource *)&v7->pMovieDef.pObject->vfptr;
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
  v7->pMovieDef.pObject = v4;
  v29 = 0i64;
  v5->pImage->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->pImage->vfptr, (unsigned int)&v18);
  `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&ptr, &v, 0i64);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=(&v24, &v, 0i64);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = (float)(v20 - v18);
  Scaleform::GFx::AS2::Value::operator=(&v25, &v, 0i64);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = (float)(v21 - v19);
  Scaleform::GFx::AS2::Value::operator=(&v26, &v, 0i64);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v10 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                  v6,
                                                  v6->StringContext.pContext->FlashGeomPackage,
                                                  (Scaleform::GFx::ASString *)&v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
                                                  0,
                                                  -1);
  v30 = v10;
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v10, &v6->StringContext, (Scaleform::GFx::AS2::Value *)&ptr);
  v27 = 4;
  Scaleform::GFx::AS2::Value::Value(&v, (Scaleform::GFx::AS2::Object *)&v10->vfptr);
  v12 = v11;
  v13 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &result, "rectangle");
  v7->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v7->vfptr,
    &v6->StringContext,
    v13,
    v12,
    (Scaleform::GFx::AS2::PropFlags *)&v27);
  v14 = result.pNode;
  v15 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v10 )
  {
    v16 = v10->RefCount;
    if ( v16 & 0x3FFFFFF )
    {
      v10->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}

// File Line: 100
// RVA: 0x7172E0
bool __fastcall Scaleform::GFx::AS2::BitmapData::SetMember(Scaleform::GFx::AS2::BitmapData *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::BitmapData *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx
  const char *v7; // r11
  __int64 v8; // rax
  __int64 v9; // r10
  char v10; // r9
  char v12; // cl

  v5 = this;
  v6 = val;
  v7 = name->pNode->pData;
  v8 = 0i64;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = v7[v9++];
    if ( v10 != aWidth_2[v9 - 1] )
      break;
    if ( v9 == 6 )
      return 1;
  }
  while ( 1 )
  {
    v12 = v7[v8++];
    if ( v12 != aHeight_0[v8 - 1] )
      break;
    if ( v8 == 7 )
      return 1;
  }
  return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v5->vfptr, penv, name, v6, flags);
}

// File Line: 107
// RVA: 0x6F1870
char __fastcall Scaleform::GFx::AS2::BitmapData::GetMember(Scaleform::GFx::AS2::BitmapData *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame *v4; // r11
  Scaleform::GFx::AS2::Value *v5; // rbx
  Scaleform::GFx::AS2::BitmapData *v6; // rsi
  signed int v7; // edi
  const char *v8; // r9
  __int64 v9; // r10
  char v10; // al
  __int64 v11; // rcx
  char result; // al
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rcx
  char v16; // [rsp+30h] [rbp+8h]

  v4 = this->ResolveHandler.pLocalFrame;
  v5 = val;
  v6 = this;
  if ( v4 )
  {
    v7 = 0;
    v8 = name->pNode->pData;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = v8[v9++];
      if ( v10 != aWidth_2[v9 - 1] )
        break;
      if ( v9 == 6 )
      {
        v11 = *(_QWORD *)&v4->RefCount;
        if ( v11 )
          v7 = *(_DWORD *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 40i64))(v11, &v16);
        if ( v5->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v5);
LABEL_9:
        v5->T.Type = 3;
        result = 1;
        v5->NV.NumberValue = (double)v7;
        return result;
      }
    }
    v13 = 0i64;
    while ( 1 )
    {
      v14 = v8[v13++];
      if ( v14 != aHeight_0[v13 - 1] )
        break;
      if ( v13 == 7 )
      {
        v15 = *(_QWORD *)&v4->RefCount;
        if ( v15 )
          v7 = *(_DWORD *)((*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v15 + 40i64))(v15, &v16) + 4);
        if ( v5->T.Type >= 5u )
        {
          Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->T.Type = 3;
          result = 1;
          v5->NV.NumberValue = (double)v7;
          return result;
        }
        goto LABEL_9;
      }
    }
  }
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::BitmapData *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v6->vfptr[3].~RefCountBaseGC<323>)(
           v6,
           &penv->StringContext,
           name,
           v5);
}

// File Line: 127
// RVA: 0x6B8770
void __fastcall Scaleform::GFx::AS2::GFx_StageFuncStub(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
}

// File Line: 159
// RVA: 0x6F8D80
void __fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Object *v2; // rax
  Scaleform::GFx::AS2::BitmapData *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  unsigned int v5; // eax

  v1 = fn;
  v2 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        fn,
                                        112i64);
  v3 = (Scaleform::GFx::AS2::BitmapData *)v2;
  if ( v2 )
  {
    v4 = v1->Env;
    Scaleform::GFx::AS2::Object::Object(v2, v1->Env);
    v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v3->pImageRes.pObject = 0i64;
    v3->pMovieDef.pObject = 0i64;
    Scaleform::GFx::AS2::BitmapData::commonInit(v3, v4);
  }
  else
  {
    v3 = 0i64;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v3->vfptr);
  if ( v3 )
  {
    v5 = v3->RefCount;
    if ( v5 & 0x3FFFFFF )
    {
      v3->RefCount = v5 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->vfptr);
    }
  }
}

// File Line: 165
// RVA: 0x6BC2B0
void __fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::LoadBitmapA(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::AS2::BitmapData *v6; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  unsigned int v8; // eax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS2::BitmapData *v12; // [rsp+48h] [rbp+10h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 1;
  if ( v1->NArgs >= 1 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    v6 = Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(v1->Env, &result);
    v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr;
    v12 = v6;
    if ( v6 )
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v6->vfptr);
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
    v9 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
}

// File Line: 179
// RVA: 0x70C6D0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  __int64 v10; // rdi
  Scaleform::GFx::AS2::Object *v11; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  unsigned int v13; // eax
  Scaleform::MemoryHeap *v14; // rbx
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
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)v4;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[6].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)Scaleform::GFx::AS2::BitmapDataCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6[2].pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v20.T.Type = 10;
      v6[2].vfptr->SetMemberRaw(
        v6 + 2,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6[2].pProto.pObject->vfptr;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v6[2].pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapDataCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapDataCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      v6 + 2,
      &psc,
      Scaleform::GFx::AS2::BitmapDataCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  v3->pLocalFrame = 0i64;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v2->pHeap;
  v10 = ((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v23->pObject->pWatchpoints)(v5, 176i64, 0i64);
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v10, &psc);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 96) = 0i64;
    *(_QWORD *)(v10 + 104) = 0i64;
    if ( !*(_QWORD *)(v10 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v20.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v10 + 32) + 80i64))(
        v10 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        &objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v12 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v10 + 40);
    if ( v12 )
    {
      v13 = v12->RefCount;
      if ( v13 & 0x3FFFFFF )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
      }
    }
    *(_QWORD *)(v10 + 40) = v11;
    v14 = (Scaleform::MemoryHeap *)(v10 + 112);
    flags = v14;
    v14->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v14->SelfSize) = 0;
    v14->pPrev = 0i64;
    v14->pNext = 0i64;
    *(_BYTE *)(v10 + 160) = 0;
    *(_QWORD *)(v10 + 144) = 0i64;
    *(_QWORD *)(v10 + 152) = 0i64;
    *(_QWORD *)(v10 + 168) = 0i64;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v14->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 112),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      v3);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::BitmapDataProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::BitmapDataProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v14->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::BitmapDataProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 112),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      GFx_BitmapDataFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v10 = 0i64;
  }
  flags = (Scaleform::MemoryHeap *)v10;
  v23 = &objproto;
  if ( v10 )
    *(_DWORD *)(v10 + 24) = (*(_DWORD *)(v10 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_BitmapData,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
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
  v2->FlashDisplayPackage->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v2->FlashDisplayPackage->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[13].AVMVersion,
    &v20,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  if ( v10 )
  {
    v17 = *(_DWORD *)(v10 + 24);
    if ( v17 & 0x3FFFFFF )
    {
      *(_DWORD *)(v10 + 24) = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  return v3;
}

