// File Line: 30
// RVA: 0x77AC50
void __fastcall Scaleform::GFx::AS3::AvmBitmap::AvmBitmap(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::CharacterCreateInfo *ccinfo, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::CharacterCreateInfo *v5; // rbp
  Scaleform::GFx::AS3::AvmBitmap *v6; // rdi
  unsigned int *v7; // rsi
  Scaleform::GFx::MovieDefImpl *v8; // rbx
  Scaleform::GFx::Resource *v9; // rbx
  Scaleform::GFx::MovieDataDef *v10; // rcx
  Scaleform::GFx::Resource *v11; // rcx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-20h]

  v5 = ccinfo;
  v6 = this;
  v7 = *(unsigned int **)&id.Id;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObject::DisplayObject(
    (Scaleform::GFx::DisplayObject *)&this->vfptr,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&v6->vfptr,
    (Scaleform::GFx::DisplayObject *)&v6->vfptr);
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v6->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable;
  v8 = v5->pBindDefImpl;
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v5->pBindDefImpl->vfptr);
  v6->pDefImpl.pObject = v8;
  v6->pImage.pObject = 0i64;
  v9 = v5->pResource;
  if ( *v7 != 0x40000 )
  {
    phandle.HType = 0;
    phandle.pResource = 0i64;
    v10 = v6->pDefImpl.pObject->pBindData.pObject->pDataDef.pObject;
    id.Id = *v7;
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           v10->pData.pObject,
           &phandle,
           (Scaleform::GFx::ResourceId)&id) )
    {
      v9 = Scaleform::GFx::ResourceHandle::GetResource(
             &phandle,
             &v6->pDefImpl.pObject->pBindData.pObject->ResourceBinding);
    }
    if ( phandle.HType == RH_Pointer && phandle.pResource )
      Scaleform::GFx::Resource::Release(phandle.pResource);
  }
  if ( v9 && (v9->vfptr->GetResourceTypeCode(v9) & 0xFF00) == 256 )
  {
    Scaleform::Render::RenderBuffer::AddRef(v9);
    v11 = (Scaleform::GFx::Resource *)&v6->pImage.pObject->vfptr;
    if ( v11 )
      Scaleform::GFx::Resource::Release(v11);
    v6->pImage.pObject = (Scaleform::GFx::ImageResource *)v9;
  }
}

// File Line: 50
// RVA: 0x7897C0
void __fastcall Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::AvmBitmap *v1; // rbx
  Scaleform::GFx::MovieDefImpl *v2; // rdx
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::GFx::Resource *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable;
  v2 = this->pDefImpl.pObject;
  if ( v2 )
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(this->pASRoot->pMovieImpl, v2);
  v1->AvmObjOffset = 0;
  v3 = (Scaleform::GFx::Resource *)&v1->pImage.pObject->vfptr;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  v4 = (Scaleform::GFx::Resource *)&v1->pDefImpl.pObject->vfptr;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj((Scaleform::GFx::AS3::AvmDisplayObj *)&v1->vfptr);
  Scaleform::GFx::DisplayObject::~DisplayObject((Scaleform::GFx::DisplayObject *)&v1->vfptr);
}

// File Line: 64
// RVA: 0x7BB0B0
__int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::CreateASInstance(Scaleform::GFx::AS3::AvmBitmap *this, bool execute)
{
  bool v2; // r12
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // r14
  unsigned int v4; // er15
  Scaleform::WeakPtrProxy *v5; // rcx
  char *v6; // rax
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v7; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // rcx
  unsigned int v10; // ebx
  bool v11; // zf
  unsigned int v12; // ebx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v13; // rbx
  unsigned int *v14; // rcx
  Scaleform::GFx::MovieDefImpl *v15; // rax
  Scaleform::String *v16; // rax
  Scaleform::GFx::AS3::VM *v17; // rsi
  Scaleform::GFx::ASMovieRootBase *v18; // r8
  int v19; // edx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v20; // rcx
  Scaleform::GFx::ImageResource *v21; // rsi
  Scaleform::GFx::MovieDefImpl *v22; // rax
  unsigned int v23; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-41h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+70h] [rbp-19h]
  Scaleform::GFx::AS3::Value v27; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::ResourceId rid; // [rsp+F0h] [rbp+67h]
  int v29; // [rsp+F4h] [rbp+6Bh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+100h] [rbp+77h]

  v2 = execute;
  v3 = (Scaleform::GFx::AS3::AvmDisplayObj *)this;
  v4 = 0;
  v5 = this->pWeakProxy;
  v6 = (char *)v5;
  if ( !v5 )
    v6 = (char *)v3->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v6 & 1 )
    --v6;
  if ( !v6 && !v5 && !v3->pAS3CollectiblePtr.pObject && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v3) )
    v4 = (unsigned __int64)Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v3, v2);
  v7 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v3->pAS3RawPtr;
  v8 = v3->pAS3RawPtr;
  if ( !v7 )
    v8 = v3->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v8 & 1 )
    v8 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v8 - 1);
  if ( v8 )
  {
    if ( !v7 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v3->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v7 & 1 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)((char *)v7 - 1);
    if ( !v7->pBitmapData.pObject && ((__int64 (*)(void))v3->pDispObj->vfptr[66].__vecDelDtor)() )
    {
      ptr.Flags = 4;
      ptr.Bonus.pWeakProxy = 0i64;
      ptr.value.VNumber = 0.0;
      v27.Flags = 4;
      v27.Bonus.pWeakProxy = 0i64;
      v27.value.VNumber = 0.0;
      v9 = v3[1].pAS3CollectiblePtr.pObject;
      if ( v9 && v9->pPrev )
      {
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, Scaleform::GFx::ResourceId *))v9->pPrev->vfptr[1].Finalize_GC)(
          v9->pPrev,
          &rid);
        other.Flags = 3;
        other.Bonus.pWeakProxy = 0i64;
        LODWORD(other.value.VNumber) = rid;
        Scaleform::GFx::AS3::Value::Assign(&ptr, &other);
        v10 = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags >> 9) & 1 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags = v10 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
        other.Flags = 3;
        other.Bonus.pWeakProxy = 0i64;
        other.value.VS._1.VInt = v29;
        Scaleform::GFx::AS3::Value::Assign(&v27, &other);
        v12 = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags >> 9) & 1 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags = v12 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
      }
      v13 = 0i64;
      pobj.pObject = 0i64;
      v14 = (unsigned int *)v3->pDispObj;
      rid.Id = v14[10];
      v15 = (Scaleform::GFx::MovieDefImpl *)(*(__int64 (**)(void))(*(_QWORD *)v14 + 528i64))();
      v16 = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v15, (Scaleform::GFx::ResourceId)&rid);
      if ( v16 )
      {
        v17 = (Scaleform::GFx::AS3::VM *)v3->pDispObj->pASRoot[2].vfptr;
        other.Flags = 0;
        other.Bonus.pWeakProxy = 0i64;
        if ( (unsigned __int8)Scaleform::GFx::AS3::VM::Construct(
                                v17,
                                (const char *)((v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                                v3->AppDomain,
                                &other,
                                2u,
                                &ptr,
                                1) )
        {
          if ( v2 )
            Scaleform::GFx::AS3::VM::ExecuteCode(v17, 1u);
          else
            ++v4;
        }
        v18 = v3->pDispObj->pASRoot;
        if ( !LOBYTE(v18[2].vfptr[21].__vecDelDtor)
          && (v19 = other.Flags & 0x1F) != 0
          && ((v20 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)other.value.VS._1.VStr,
               (unsigned int)(v19 - 12) > 3)
           && v19 != 10
           || *(_QWORD *)&other.value.VNumber) )
        {
          if ( *(_QWORD *)&other.value.VNumber )
          {
            ++*(_DWORD *)(*(_QWORD *)&other.value.VNumber + 32i64);
            v20->RefCount &= 0x8FBFFFFF;
            v13 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v20;
            pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v20;
          }
        }
        else if ( LOBYTE(v18[2].vfptr[21].__vecDelDtor) )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException((Scaleform::GFx::AS3::VM *)v18[2].vfptr);
        }
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags >> 9) & 1 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
          (Scaleform::GFx::AS3::VM *)v3->pDispObj->pASRoot[2].vfptr,
          (Scaleform::GFx::AS3::CheckResult *)&rid,
          &pobj,
          "flash.display.BitmapData",
          2u,
          &ptr);
        v13 = pobj.pObject;
      }
      if ( v13 )
      {
        v21 = (Scaleform::GFx::ImageResource *)v3[1].pAS3CollectiblePtr.pObject;
        v22 = (Scaleform::GFx::MovieDefImpl *)((__int64 (*)(void))v3->pDispObj->vfptr[66].__vecDelDtor)();
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v13,
          v21,
          v22);
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(
          v7,
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v13);
      }
      if ( v13 )
      {
        if ( (unsigned __int8)v13 & 1 )
        {
          pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v13 - 1);
        }
        else
        {
          v23 = v13->RefCount;
          if ( v23 & 0x3FFFFF )
          {
            v13->RefCount = v23 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
          }
        }
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
  }
  return v4;
}

// File Line: 134
// RVA: 0x7F08D0
signed __int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::GetTopMostMouseEntity(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rdi
  Scaleform::Render::Point<float> *v4; // rsi
  Scaleform::GFx::AS3::AvmBitmap *v5; // rbx
  Scaleform::GFx::ImageResource *v6; // rax
  __int64 *v7; // rax
  __int64 v8; // r8
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-50h]
  int v11; // [rsp+40h] [rbp-40h]
  int v12; // [rsp+44h] [rbp-3Ch]
  int v13; // [rsp+48h] [rbp-38h]
  int v14; // [rsp+4Ch] [rbp-34h]
  Scaleform::Render::Rect<float> r; // [rsp+50h] [rbp-30h]
  Scaleform::Render::Matrix2x4<float> v16; // [rsp+60h] [rbp-20h]
  Scaleform::Render::Point<float> p; // [rsp+90h] [rbp+10h]

  v3 = pdescr;
  v4 = pt;
  v5 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)() || !v5->pImage.pObject )
    return 2i64;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
    (Scaleform::GFx::DisplayObjectBase *)&v5->vfptr,
    &p,
    v4,
    1,
    0i64);
  v5->pImage.pObject->pImage->vfptr[6].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v5->pImage.pObject->pImage->vfptr,
    (unsigned int)&v11);
  *(_QWORD *)&pr.x1 = 0i64;
  v6 = v5->pImage.pObject;
  pr.x2 = (float)(v13 - v11) * 20.0;
  pr.y2 = (float)(v14 - v12) * 20.0;
  v7 = (__int64 *)((__int64 (*)(void))v6->pImage->vfptr[9].__vecDelDtor)();
  if ( v7 )
  {
    v8 = *v7;
    *(_OWORD *)&v16.M[0][0] = _xmm;
    *(__m128 *)&v16.M[1][0] = _xmm;
    (*(void (__fastcall **)(__int64 *, Scaleform::Render::Matrix2x4<float> *))(v8 + 112))(v7, &v16);
    r = pr;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v16, &pr, &r);
  }
  if ( p.x > pr.x2 || p.x < pr.x1 || p.y > pr.y2 || p.y < pr.y1 )
    return 2i64;
  v3->pResult = v5->pParent;
  return 1i64;
}

// File Line: 165
// RVA: 0x8074B0
bool __fastcall Scaleform::GFx::AS3::AvmBitmap::PointTestLocal(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::Render::Point<float> *pt, __int64 hitTestMask)
{
  Scaleform::GFx::ImageResource *v3; // rcx
  Scaleform::Render::Point<float> *v4; // rbx
  float v5; // xmm0_4
  bool result; // al
  int v7; // [rsp+20h] [rbp-18h]
  int v8; // [rsp+24h] [rbp-14h]
  int v9; // [rsp+28h] [rbp-10h]
  int v10; // [rsp+2Ch] [rbp-Ch]

  v3 = this->pImage.pObject;
  v4 = pt;
  result = 0;
  if ( v3 )
  {
    ((void (__fastcall *)(Scaleform::Render::ImageBase *, int *, __int64))v3->pImage->vfptr[6].__vecDelDtor)(
      v3->pImage,
      &v7,
      hitTestMask);
    if ( v4->x <= (float)((float)(v9 - v7) * 20.0) && v4->x >= 0.0 )
    {
      v5 = v4->y;
      if ( v5 <= (float)((float)(v10 - v8) * 20.0) && v5 >= 0.0 )
        result = 1;
    }
  }
  return result;
}

// File Line: 184
// RVA: 0x7E6530
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetBounds(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::AS3::AvmBitmap *v3; // rbx
  Scaleform::GFx::ImageResource *v4; // rcx
  Scaleform::Render::Matrix2x4<float> *v5; // rsi
  Scaleform::Render::Rect<float> *v6; // rdi
  Scaleform::GFx::ImageResource *v7; // rax
  __int64 v8; // rax
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-50h]
  int v11; // [rsp+30h] [rbp-40h]
  int v12; // [rsp+34h] [rbp-3Ch]
  int v13; // [rsp+38h] [rbp-38h]
  int v14; // [rsp+3Ch] [rbp-34h]
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-30h]
  Scaleform::Render::Matrix2x4<float> v16; // [rsp+50h] [rbp-20h]

  v3 = this;
  v4 = this->pImage.pObject;
  v5 = transform;
  v6 = result;
  pr = 0i64;
  if ( v4 )
  {
    v4->pImage->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->pImage->vfptr, (unsigned int)&v11);
    v7 = v3->pImage.pObject;
    *(_OWORD *)&v16.M[0][0] = _xmm;
    *(__m128 *)&v16.M[1][0] = _xmm;
    v8 = ((__int64 (*)(void))v7->pImage->vfptr[9].__vecDelDtor)();
    if ( v8 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v8 + 112i64))(v8, &v16);
      r.x1 = (float)(20 * v11);
      r.y1 = (float)(20 * v12);
      r.x2 = (float)(20 * v13);
      r.y2 = (float)(20 * v14);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v16, &pr, &r);
    }
    else
    {
      pr.x1 = (float)(20 * v11);
      pr.y1 = (float)(20 * v12);
      pr.x2 = (float)(20 * v13);
      pr.y2 = (float)(20 * v14);
    }
  }
  *(_QWORD *)&r.x1 = 0i64;
  r.x2 = pr.x2 - pr.x1;
  r.y2 = pr.y2 - pr.y1;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v5, v6, &r);
  return v6;
}

// File Line: 225
// RVA: 0x80F460
Scaleform::Render::TreeNode *__fastcall Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::AvmBitmap *v1; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::TreeContainer *v4; // r14
  Scaleform::Render::TreeNode *v5; // rbp
  unsigned __int64 v6; // r9
  _QWORD *v7; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v8; // rcx
  Scaleform::GFx::ImageResource *v9; // rax
  Scaleform::GFx::ImageResource *v10; // rbx
  Scaleform::GFx::Resource *v11; // rcx
  Scaleform::Render::TreeNode *result; // rax
  Scaleform::Render::TreeNode *v13; // rbx
  __int64 v14; // r15
  Scaleform::Render::ContextImpl::Entry *v15; // rcx
  bool v16; // zf
  Scaleform::Render::ContextImpl::Entry *v17; // rcx
  Scaleform::Render::TreeNode *v18; // rcx
  Scaleform::Render::ContextImpl::Entry *v19; // [rsp+60h] [rbp+8h]
  Scaleform::Render::TreeNode *v20; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = this->pAS3RawPtr;
  if ( !v2 )
    v2 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v2 & 1 )
    v2 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
  v3 = 0xFFFFFFFFi64;
  v4 = 0i64;
  v5 = this->pRenNode.pObject;
  if ( v2 )
  {
    if ( v5 && v5->pParent )
    {
      if ( !((*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                   + 8
                                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1] - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                                             - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                   + 40)
                       + 10i64) >> 5) & 1) )
        v4 = (Scaleform::Render::TreeContainer *)v5->pParent;
      v3 = 0i64;
      v6 = Scaleform::Render::TreeContainer::GetSize(v4);
      if ( v6 )
      {
        do
        {
          v7 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                                              - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40)
                        + 144i64);
          if ( *(_BYTE *)v7 & 1 )
            v7 = (_QWORD *)((*v7 & 0xFFFFFFFFFFFFFFFEui64) + 16);
          if ( (Scaleform::Render::TreeNode *)v7[v3] == v5 )
            break;
          ++v3;
        }
        while ( v3 < v6 );
      }
      Scaleform::Render::TreeContainer::Remove(v4, v3, 1ui64);
    }
    v8 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v2[1].vfptr;
    if ( v8 )
    {
      v9 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(v8);
      v10 = v9;
      if ( v9 )
      {
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v9->vfptr);
        v11 = (Scaleform::GFx::Resource *)&v1->pImage.pObject->vfptr;
        if ( v11 )
          Scaleform::GFx::Resource::Release(v11);
        v1->pImage.pObject = v10;
      }
    }
  }
  result = v1->pRenNode.pObject;
  if ( v5 != 0i64 )
  {
    if ( result )
      ++result->RefCount;
    v13 = v1->pRenNode.pObject;
    v20 = v1->pRenNode.pObject;
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *, Scaleform::Render::ContextImpl::Entry **, Scaleform::Render::ContextImpl::Context *))v1->vfptr[1].__vecDelDtor)(
            v1,
            &v19,
            &v1->pASRoot->pMovieImpl->RenderContext);
    if ( *(_QWORD *)v14 )
      ++*(_QWORD *)(*(_QWORD *)v14 + 8i64);
    v15 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenNode.pObject->0;
    if ( v15 )
    {
      v16 = v15->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v15);
    }
    v1->pRenNode.pObject = *(Scaleform::Render::TreeNode **)v14;
    v17 = v19;
    if ( v19 )
    {
      v16 = v19->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v17);
    }
    v18 = v1->pRenNode.pObject;
    if ( v18 )
    {
      if ( v13 )
        Scaleform::Render::TreeNode::CopyGeomData(v18, v13);
      else
        Scaleform::Render::TreeNode::SetVisible(v18, (v1->Flags >> 14) & 1);
      if ( v4 )
        Scaleform::Render::TreeContainer::Insert(v4, v3, v1->pRenNode.pObject);
    }
    if ( v13 )
    {
      v16 = v13->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v13->0);
    }
    result = v1->pRenNode.pObject;
  }
  return result;
}

// File Line: 280
// RVA: 0x7BE7C0
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS3::AvmBitmap::CreateRenderNode(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v3; // rdi
  Scaleform::GFx::AS3::AvmBitmap *v4; // rbx
  Scaleform::Render::ContextImpl::Entry *v5; // rsi
  Scaleform::Render::ContextImpl::Entry *v6; // rcx
  bool v7; // zf
  Scaleform::Render::ContextImpl::Entry *v8; // rcx
  Scaleform::Render::TreeNode *v9; // rax

  v3 = result;
  v4 = this;
  v5 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(context);
  v6 = (Scaleform::Render::ContextImpl::Entry *)&v4->pRenNode.pObject->0;
  if ( v6 )
  {
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
  }
  v4->pRenNode.pObject = (Scaleform::Render::TreeNode *)v5;
  if ( (unsigned __int8)Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(v4) )
  {
    v9 = v4->pRenNode.pObject;
    if ( v9 )
      ++v9->RefCount;
    v3->pObject = (Scaleform::Render::TreeNode *)v4->pRenNode;
  }
  else
  {
    v8 = (Scaleform::Render::ContextImpl::Entry *)&v4->pRenNode.pObject->0;
    if ( v8 )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
    }
    v4->pRenNode.pObject = 0i64;
    v3->pObject = 0i64;
  }
  return v3;
}

// File Line: 291
// RVA: 0x7BB9F0
__int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::AvmBitmap *v1; // rdi
  Scaleform::Render::TreeShape *v2; // r13
  Scaleform::MemoryHeap *v3; // rax
  Scaleform::MemoryHeap *v4; // r12
  Scaleform::Render::ShapeDataFloat *v5; // rax
  Scaleform::Render::ShapeMeshProvider *v6; // r14
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v7; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v8; // r15
  __int64 v9; // rsi
  __int64 v10; // rbx
  Scaleform::GFx::ImageCreator *v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rcx
  const char *v14; // rdx
  __int64 *v15; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v16; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // rcx
  signed __int64 v18; // rcx
  signed __int64 v19; // rdi
  bool v20; // zf
  __int64 v21; // rdi
  float v22; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v23; // rax
  Scaleform::Render::ShapeMeshProvider *v24; // rax
  Scaleform::Render::MeshProviderVtbl *v25; // rax
  signed __int64 v26; // rcx
  unsigned __int8 v27; // bl
  float v28; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v29; // rax
  Scaleform::Render::ShapeMeshProvider *v30; // rax
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-E0h]
  int v33; // [rsp+30h] [rbp-D0h]
  int v34; // [rsp+34h] [rbp-CCh]
  int v35; // [rsp+38h] [rbp-C8h]
  int v36; // [rsp+3Ch] [rbp-C4h]
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-C0h]
  int v38; // [rsp+50h] [rbp-B0h]
  __int64 v39; // [rsp+58h] [rbp-A8h]
  int v40; // [rsp+60h] [rbp-A0h]
  __int64 v41; // [rsp+68h] [rbp-98h]
  int v42; // [rsp+70h] [rbp-90h]
  int v43; // [rsp+74h] [rbp-8Ch]
  __int64 v44; // [rsp+78h] [rbp-88h]
  __int64 v45; // [rsp+80h] [rbp-80h]
  __int64 v46; // [rsp+88h] [rbp-78h]
  __int64 v47; // [rsp+90h] [rbp-70h]
  Scaleform::Render::ShapeMeshProvider *v48; // [rsp+98h] [rbp-68h]
  __int64 v49; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::ShapeMeshProvider *v50; // [rsp+A8h] [rbp-58h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v51; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::Matrix2x4<float> v52; // [rsp+C0h] [rbp-40h]
  Scaleform::MemoryHeap *v53; // [rsp+E0h] [rbp-20h]
  __int64 v54; // [rsp+E8h] [rbp-18h]
  __int64 v55; // [rsp+150h] [rbp+50h]
  __int64 id; // [rsp+158h] [rbp+58h]
  __int64 v57; // [rsp+160h] [rbp+60h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+168h] [rbp+68h]

  v54 = -2i64;
  v1 = this;
  v2 = (Scaleform::Render::TreeShape *)this->pRenNode.pObject;
  v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v2);
  v4 = v3;
  v53 = v3;
  v5 = (Scaleform::Render::ShapeDataFloat *)v3->vfptr->Alloc(v3, 128ui64, 0i64);
  v55 = (__int64)v5;
  v6 = 0i64;
  if ( v5 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v5);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v51 = v8;
  v39 = 0i64;
  v38 = 0;
  v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(v4, 80i64);
  v49 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)v9 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v9 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v9 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v9 = &Scaleform::Render::ComplexFill::`vftable;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)(v9 + 24) = 0i64;
    *(_QWORD *)(v9 + 32) = 1065353216i64;
    *(_QWORD *)(v9 + 40) = 0i64;
    *(_DWORD *)(v9 + 48) = 0;
    *(_QWORD *)(v9 + 52) = 1065353216i64;
    *(_DWORD *)(v9 + 60) = 0;
    *(_BYTE *)(v9 + 64) = 0;
    *(_DWORD *)(v9 + 68) = -1;
  }
  else
  {
    v9 = 0i64;
  }
  v39 = v9;
  if ( v1->pImage.pObject )
  {
    v57 = 0i64;
    if ( ((unsigned int (*)(void))v1->pImage.pObject->pImage->vfptr[3].__vecDelDtor)() )
    {
      v10 = (__int64)v1->pImage.pObject->pImage;
      if ( v10 )
        (*(void (__fastcall **)(Scaleform::Render::ImageBase *))(*(_QWORD *)v10 + 8i64))(v1->pImage.pObject->pImage);
      v57 = v10;
    }
    else
    {
      v11 = Scaleform::GFx::StateBag::GetImageCreator(
              (Scaleform::GFx::StateBag *)&v1->pASRoot->pMovieImpl->vfptr,
              &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( !v11 )
      {
        LODWORD(id) = 135168;
        v14 = "Image is not created: cant find ImageCreator.";
        v15 = &id;
        goto LABEL_44;
      }
      v12 = (__int64)v1->pASRoot->pMovieImpl->pHeap;
      v40 = 3;
      v41 = v12;
      v42 = 1;
      v43 = 1;
      v44 = 0i64;
      v45 = 0i64;
      v46 = 0i64;
      v47 = 0i64;
      v10 = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v11->vfptr[4].__vecDelDtor)(
              v11,
              &v40,
              v1->pImage.pObject->pImage);
      v57 = v10;
    }
    if ( v10 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 8i64))(v10);
    v13 = *(_QWORD *)(v9 + 16);
    if ( v13 )
      (*(void (**)(void))(*(_QWORD *)v13 + 16i64))();
    *(_QWORD *)(v9 + 16) = v10;
    if ( !v10 )
    {
      LODWORD(v55) = 135168;
      v14 = "Image is not created.";
      v15 = &v55;
LABEL_44:
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)v15, v14);
      v27 = 0;
      goto LABEL_54;
    }
    *(_QWORD *)(v9 + 32) = 1028443341i64;
    *(_QWORD *)(v9 + 40) = 0i64;
    *(_DWORD *)(v9 + 48) = 0;
    *(_QWORD *)(v9 + 52) = 1028443341i64;
    *(_DWORD *)(v9 + 60) = 0;
    *(_BYTE *)(v9 + 64) = 1;
    v16 = v1->pAS3RawPtr;
    v17 = v1->pAS3RawPtr;
    if ( !v16 )
      v17 = v1->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v17 & 1 )
      v17 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
    if ( !v17 )
      goto LABEL_61;
    if ( !v16 )
      v16 = v1->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v16 & 1 )
      v16 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v16 - 1);
    if ( BYTE4(v16[1].pRCCRaw) )
LABEL_61:
      *(_BYTE *)(v9 + 64) = 3;
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v10 + 48i64))(v10, &v33);
    *(_OWORD *)&v52.M[0][0] = _xmm;
    *(__m128 *)&v52.M[1][0] = _xmm;
    (*(void (__fastcall **)(__int64, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v10 + 112i64))(v10, &v52);
    pr = 0i64;
    r.x1 = (float)v33;
    r.y1 = (float)v34;
    r.x2 = (float)v35;
    r.y2 = (float)v36;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v52, &pr, &r);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *)&v8->Fills.Data.Data,
      &v8->Fills,
      v8->Fills.Data.Size + 1);
    v18 = 16 * v8->Fills.Data.Size;
    v19 = (signed __int64)&v8->Fills.Data.Data[-1];
    v20 = v18 + v19 == 0;
    v21 = v18 + v19;
    v55 = v21;
    id = v21;
    if ( !v20 )
    {
      *(_DWORD *)v21 = 0;
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v9);
      *(_QWORD *)(v21 + 8) = v9;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v8,
      1u,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v8,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v8,
      (float)(pr.x2 - pr.x1) * 20.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v8,
      (float)(pr.x2 - pr.x1) * 20.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v8,
      0.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    v22 = v8->StartX;
    if ( v22 != v8->LastX || v8->StartY != v8->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v8,
        v22,
        v8->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v8);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v8);
    v23 = (Scaleform::Render::ShapeMeshProvider *)v4->vfptr->Alloc(v4, 144ui64, 0i64);
    v55 = (__int64)v23;
    if ( v23 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        v23,
        (Scaleform::Render::ShapeDataInterface *)&v8->vfptr,
        0i64);
      v6 = v24;
    }
    v50 = v6;
    Scaleform::Render::TreeShape::SetShape(v2, v6);
    if ( v6 )
      ((void (*)(void))v6->vfptr->Release)();
    v25 = *(Scaleform::Render::MeshProviderVtbl **)v10;
    v26 = v10;
  }
  else
  {
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v8,
      0,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v8,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v8,
      1.0,
      1.0);
    v28 = v8->StartX;
    if ( v28 != v8->LastX || v8->StartY != v8->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v8,
        v28,
        v8->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v8);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v8);
    v29 = (Scaleform::Render::ShapeMeshProvider *)v4->vfptr->Alloc(v4, 144ui64, 0i64);
    v55 = (__int64)v29;
    if ( v29 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        v29,
        (Scaleform::Render::ShapeDataInterface *)&v8->vfptr,
        0i64);
      v6 = v30;
    }
    v48 = v6;
    Scaleform::Render::TreeShape::SetShape(v2, v6);
    if ( !v6 )
      goto LABEL_53;
    v26 = (signed __int64)&v6->vfptr;
    v25 = v6->vfptr;
  }
  v25->Release((Scaleform::Render::MeshProvider *)v26);
LABEL_53:
  v27 = 1;
LABEL_54:
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
  return v27;
}

// File Line: 371
// RVA: 0x7D75B0
void __fastcall Scaleform::GFx::AS3::AvmBitmap::ForceShutdown(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v2; // rcx
  unsigned int v3; // eax
  unsigned int v4; // eax

  v1 = this->pAS3RawPtr;
  if ( !v1 )
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return;
    v1 = this->pAS3CollectiblePtr.pObject;
  }
  if ( (unsigned __int8)v1 & 1 )
    v1 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v1 - 1);
  if ( v1 )
    v1->RefCount = (v1->RefCount + 1) & 0x8FBFFFFF;
  v2 = v1->pLoaderInfo.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pLoaderInfo.pObject = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)v2 - 1);
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
    v1->pLoaderInfo.pObject = 0i64;
  }
  if ( !((unsigned __int8)v1 & 1) )
  {
    v4 = v1->RefCount;
    if ( v4 & 0x3FFFFF )
    {
      v1->RefCount = v4 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v1->vfptr);
    }
  }
}

// File Line: 379
// RVA: 0x81D470
void __fastcall Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::GFx::MovieDefImpl *md)
{
  Scaleform::GFx::MovieDefImpl *v2; // rbx
  Scaleform::GFx::AS3::AvmBitmap *v3; // rdi
  Scaleform::GFx::Resource *v4; // rcx

  v2 = md;
  v3 = this;
  if ( md )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&md->vfptr);
  v4 = (Scaleform::GFx::Resource *)&v3->pDefImpl.pObject->vfptr;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v3->pDefImpl.pObject = v2;
}

