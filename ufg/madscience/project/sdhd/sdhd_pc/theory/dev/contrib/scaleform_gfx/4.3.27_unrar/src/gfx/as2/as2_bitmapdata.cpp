// File Line: 29
// RVA: 0x6C79F0
void __fastcall Scaleform::GFx::AS2::BitmapData::BitmapData(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pImageRes.pObject = 0i64;
  this->pMovieDef.pObject = 0i64;
  Scaleform::GFx::AS2::BitmapData::commonInit(this, penv);
}

// File Line: 34
// RVA: 0x724F50
void __fastcall Scaleform::GFx::AS2::BitmapData::commonInit(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-30h] BYREF
  char v12; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+10h] BYREF

  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_BitmapData);
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v5->vfptr->Set__proto__(v5, &penv->StringContext, Prototype);
  v12 = 4;
  v11.T.Type = 10;
  v6 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "width");
  v5->vfptr->SetMemberRaw(v5, &penv->StringContext, v6, &v11, (Scaleform::GFx::AS2::PropFlags *)&v12);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v12 = 4;
  v11.T.Type = 10;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "height");
  v5->vfptr->SetMemberRaw(v5, &penv->StringContext, v9, &v11, (Scaleform::GFx::AS2::PropFlags *)&v12);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 44
// RVA: 0x6C12F0
Scaleform::GFx::AS2::BitmapData *__fastcall Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *linkageId)
{
  Scaleform::GFx::InteractiveObject *Target; // rcx
  const char *pData; // rbx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  Scaleform::GFx::MovieDefImpl *v7; // rax
  Scaleform::GFx::AS2::BitmapData *v8; // rbx
  Scaleform::GFx::Resource *v9; // rax
  __int64 v10; // rcx
  Scaleform::GFx::MovieDef *v11; // rdi
  Scaleform::GFx::AS2::BitmapData *v12; // rax
  Scaleform::GFx::AS2::BitmapData *v13; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageResource> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::MovieDef *v16; // [rsp+68h] [rbp+10h]
  Scaleform::MemoryHeap *pHeap; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::AS2::BitmapData *v18; // [rsp+78h] [rbp+20h]

  Target = penv->Target;
  pData = linkageId->pNode->pData;
  pMovieImpl = Target->pASRoot->pMovieImpl;
  v7 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(Target);
  Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(pMovieImpl, &result, v7, pData);
  if ( result.pObject )
  {
    v9 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))penv->Target->vfptr[66].__vecDelDtor)(penv->Target);
    v11 = (Scaleform::GFx::MovieDef *)v9;
    if ( v9 )
      Scaleform::Render::RenderBuffer::AddRef(v9);
    v16 = v11;
    if ( v11 )
    {
      pHeap = penv->StringContext.pContext->pHeap;
      v12 = (Scaleform::GFx::AS2::BitmapData *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(
                                                 v10,
                                                 112i64);
      v18 = v12;
      if ( v12 )
      {
        Scaleform::GFx::AS2::BitmapData::BitmapData(v12, penv);
        v8 = v13;
      }
      else
      {
        v8 = 0i64;
      }
      Scaleform::GFx::AS2::BitmapData::SetImage(v8, penv, result.pObject, v11);
    }
    else
    {
      v8 = 0i64;
    }
    if ( v11 )
      Scaleform::GFx::Resource::Release(v11);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      penv,
      "BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"",
      linkageId->pNode->pData);
    v8 = 0i64;
  }
  if ( result.pObject )
    Scaleform::GFx::Resource::Release(result.pObject);
  return v8;
}

// File Line: 70
// RVA: 0x7148E0
void __fastcall Scaleform::GFx::AS2::BitmapData::SetImage(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ImageResource *pimg,
        Scaleform::GFx::MovieDef *pmovieDef)
{
  Scaleform::GFx::ImageResource *pObject; // rcx
  Scaleform::GFx::MovieDef *v9; // rcx
  Scaleform::GFx::AS2::RectangleObject *v10; // r14
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-99h] BYREF
  int v18[4]; // [rsp+50h] [rbp-79h] BYREF
  __int64 v19; // [rsp+60h] [rbp-69h]
  Scaleform::GFx::AS2::Value ptr; // [rsp+70h] [rbp-59h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+90h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+B0h] [rbp-19h] BYREF
  Scaleform::GFx::AS2::Value v23; // [rsp+D0h] [rbp+7h] BYREF
  char v24; // [rsp+130h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh] BYREF
  __int64 v26; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::AS2::RectangleObject *v27; // [rsp+148h] [rbp+7Fh]

  v19 = -2i64;
  if ( pimg )
    Scaleform::Render::RenderBuffer::AddRef(pimg);
  pObject = this->pImageRes.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImageRes.pObject = pimg;
  if ( pmovieDef )
    Scaleform::Render::RenderBuffer::AddRef(pmovieDef);
  v9 = this->pMovieDef.pObject;
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
  this->pMovieDef.pObject = pmovieDef;
  v26 = 0i64;
  pimg->pImage->vfptr[6].__vecDelDtor(pimg->pImage, (unsigned int)v18);
  `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=(&ptr, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=(&v21, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = (float)(v18[2] - v18[0]);
  Scaleform::GFx::AS2::Value::operator=(&v22, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = (float)(v18[3] - v18[1]);
  Scaleform::GFx::AS2::Value::operator=(&v23, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v10 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                  penv,
                                                  penv->StringContext.pContext->FlashGeomPackage,
                                                  (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
                                                  0,
                                                  -1);
  v27 = v10;
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v10, &penv->StringContext, &ptr);
  v24 = 4;
  Scaleform::GFx::AS2::Value::Value(&v, (Scaleform::GFx::ASStringNode *)v10);
  v12 = v11;
  v13 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "rectangle");
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v13,
    v12,
    (Scaleform::GFx::AS2::PropFlags *)&v24);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v10 )
  {
    RefCount = v10->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}erator(&ptr, 0x20ui64, 4, (void 

// File Line: 100
// RVA: 0x7172E0
bool __fastcall Scaleform::GFx::AS2::BitmapData::SetMember(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  const char *pData; // r11
  __int64 v8; // rax
  __int64 v9; // r10
  char v10; // r9
  char v12; // cl

  pData = name->pNode->pData;
  v8 = 0i64;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = pData[v9++];
    if ( v10 != aWidth_2[v9 - 1] )
      break;
    if ( v9 == 6 )
      return 1;
  }
  while ( 1 )
  {
    v12 = pData[v8++];
    if ( v12 != aHeight_0[v8 - 1] )
      break;
    if ( v8 == 7 )
      return 1;
  }
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}

// File Line: 107
// RVA: 0x6F1870
char __fastcall Scaleform::GFx::AS2::BitmapData::GetMember(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // r11
  int v7; // edi
  const char *pData; // r9
  __int64 v9; // r10
  char v10; // al
  __int64 v11; // rcx
  char result; // al
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rcx
  char v16; // [rsp+30h] [rbp+8h] BYREF

  pLocalFrame = this->ResolveHandler.pLocalFrame;
  if ( pLocalFrame )
  {
    v7 = 0;
    pData = name->pNode->pData;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = pData[v9++];
      if ( v10 != aWidth_2[v9 - 1] )
        break;
      if ( v9 == 6 )
      {
        v11 = *(_QWORD *)&pLocalFrame->RefCount;
        if ( v11 )
          v7 = *(_DWORD *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 40i64))(v11, &v16);
        if ( val->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(val);
LABEL_9:
        val->T.Type = 3;
        result = 1;
        val->NV.NumberValue = (double)v7;
        return result;
      }
    }
    v13 = 0i64;
    while ( 1 )
    {
      v14 = pData[v13++];
      if ( v14 != aHeight_0[v13 - 1] )
        break;
      if ( v13 == 7 )
      {
        v15 = *(_QWORD *)&pLocalFrame->RefCount;
        if ( v15 )
          v7 = *(_DWORD *)((*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v15 + 40i64))(v15, &v16) + 4);
        if ( val->T.Type >= 5u )
        {
          Scaleform::GFx::AS2::Value::DropRefs(val);
          val->T.Type = 3;
          result = 1;
          val->NV.NumberValue = (double)v7;
          return result;
        }
        goto LABEL_9;
      }
    }
  }
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::BitmapData *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
           this,
           &penv->StringContext,
           name,
           val);
}

// File Line: 127
// RVA: 0x6B8770
void __fastcall Scaleform::GFx::AS2::GFx_StageFuncStub(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
}

// File Line: 159
// RVA: 0x6F8D80
void __fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Object *v2; // rax
  Scaleform::GFx::AS2::BitmapData *v3; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rbx
  unsigned int RefCount; // eax

  v2 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        fn,
                                        112i64);
  v3 = (Scaleform::GFx::AS2::BitmapData *)v2;
  if ( v2 )
  {
    Env = fn->Env;
    Scaleform::GFx::AS2::Object::Object(v2, Env);
    v3->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v3->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v3->pImageRes.pObject = 0i64;
    v3->pMovieDef.pObject = 0i64;
    Scaleform::GFx::AS2::BitmapData::commonInit(v3, Env);
  }
  else
  {
    v3 = 0i64;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
  if ( v3 )
  {
    RefCount = v3->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
}

// File Line: 165
// RVA: 0x6BC2B0
void __fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::LoadBitmapA(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::AS2::BitmapData *v6; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::BitmapData *v12; // [rsp+48h] [rbp+10h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 1;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    v6 = Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(fn->Env, &result);
    v7 = v6;
    v12 = v6;
    if ( v6 )
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
    if ( v7 )
    {
      RefCount = v7->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v7->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 179
// RVA: 0x70C6D0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::BitmapDataCtorFunction::Register(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  __int64 v10; // rdi
  Scaleform::GFx::AS2::Object *v11; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  unsigned int v13; // eax
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::BitmapDataCtorFunction::GlobalCtor;
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BitmapDataCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BitmapDataCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &psc,
      Scaleform::GFx::AS2::BitmapDataCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  LOBYTE(result->pNext) = 0;
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v6;
  result->pPrev = 0i64;
  pHeap = pgc->pHeap;
  v10 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(v5, 176i64, 0i64);
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v10, &psc);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::BitmapData::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 96) = 0i64;
    *(_QWORD *)(v10 + 104) = 0i64;
    if ( !*(_QWORD *)(v10 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v10 + 32) + 80i64))(
        v10 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        &objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v12 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v10 + 40);
    if ( v12 )
    {
      v13 = v12->RefCount;
      if ( (v13 & 0x3FFFFFF) != 0 )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
      }
    }
    *(_QWORD *)(v10 + 40) = v11;
    flags = (Scaleform::MemoryHeap *)(v10 + 112);
    *(_QWORD *)(v10 + 112) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v10 + 136) = 0;
    *(_QWORD *)(v10 + 120) = 0i64;
    *(_QWORD *)(v10 + 128) = 0i64;
    *(_BYTE *)(v10 + 160) = 0;
    *(_QWORD *)(v10 + 144) = 0i64;
    *(_QWORD *)(v10 + 152) = 0i64;
    *(_QWORD *)(v10 + 168) = 0i64;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 112) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v10 + 112),
      (Scaleform::GFx::AS2::Object *)v10,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::BitmapDataProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v10 + 32) = &Scaleform::GFx::AS2::BitmapDataProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v10 + 112) = &Scaleform::GFx::AS2::BitmapDataProto::`vftable;
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
  pHeap = &objproto;
  if ( v10 )
    *(_DWORD *)(v10 + 24) = (*(_DWORD *)(v10 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_BitmapData,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
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
  pgc->FlashDisplayPackage->vfptr->SetMemberRaw(
    &pgc->FlashDisplayPackage->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[13].AVMVersion,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v10 )
  {
    v16 = *(_DWORD *)(v10 + 24);
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v10 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  return result;
}

